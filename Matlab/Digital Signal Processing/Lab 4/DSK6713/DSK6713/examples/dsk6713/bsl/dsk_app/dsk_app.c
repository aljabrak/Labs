/*
 *  Copyright 2003 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk_app.c ========
 *
 *  Version 1.00
 *
 *  This example digitally processes audio data from the line input on the
 *  AIC23 codec and plays the result on the line output.  It uses the McBSP
 *  and EDMA to efficiently handle the data transfer without intervention from
 *  the DSP.
 *
 *  Data transfer
 *
 *  Audio data is transferred back and forth from the codec through McBSP2,
 *  a bidirectional serial port.  The EDMA is configured to take every 16-bit
 *  signed audio sample arriving on McBSP1 and store it in a buffer in memory
 *  until it can be processed.  Once it has been processed, the EDMA
 *  controller sends the data back to McBSP1 for transmission.
 *
 *  A second serial port, McBSP0 is used to control/configure the AIC23.  The
 *  codec receives serial commands through McBSP0 that set configuration
 *  parameters such as volume, sample rate and data format.
 *
 *  In addition to basic EDMA transfers, this example uses 2 special
 *  techniques to make audio processing more convenient and efficient:
 *
 *  1)  Ping-pong data buffering in memory
 *  2)  Linked EDMA transfers
 *
 *  Applications with single buffers for receive and transmit data are
 *  very tricky and timing dependent because new data constantly overwrites
 *  the data being transmitted.  Ping-pong buffering is a technique where two
 *  buffers (referred to as the PING buffer and the PONG buffer) are used for
 *  a data transfer instead of only one.  The EDMA is configured to fill the
 *  PING buffer first, then the PONG buffer.  While the PONG buffer is being
 *  filled, the PING buffer can be processed with the knowledge that the
 *  current EDMA transfer won't overwrite it.  This example uses ping-pong
 *  buffers on both transmit and receive ends for a total of four buffers.
 *
 *  The EDMA controller must be configured slightly differently for each
 *  buffer.  When a buffer is filled, the EDMA controller generates an
 *  interrupt.  The interrupt handler must reload the configuration
 *  for the next buffer before the next audio sample arrives.  An EDMA
 *  feature called linked transfers is used to make this event less time
 *  critical.  Each configuration is created in advance and the EDMA
 *  controller automatically links to the next configuration when the
 *  current configuration is finished.  An interrupt is still generated,
 *  but it serves only to signal the DSP that it can process the data.
 *  The only time constraint is that all the audio data must be processed
 *  before the the active buffer fills up, which is much longer than the
 *  time between audio samples.  It is much easier to satisfy real-time
 *  constraints with this implementation.
 *
 *  Program flow
 *
 *  When the program is run, the individual DSP/BIOS modules are initialized
 *  as configured in dsk_app.cdb with the DSP/BIOS configuration tool.  The
 *  main() function is then called as the main user thread.  In this example
 *  main() performs application initialization and starts the EDMA data
 *  transfers.  When main exits, control passes back entirely to DSP/BIOS
 *  which services any interrupts or threads on an as-needed basis.
 *
 *  The edmaHwi() interrupt service routine is called when a buffer has been
 *  filled.  It contains a state variable named pingOrPong that indicates
 *  whether the buffer is a PING or PONG buffer.  dmaHwi switches the buffer
 *  state to the opposite buffer and calls the SWI thread processBuffer to
 *  process the audio data.
 *
 *  Other Functions
 *
 *  The example includes a few other functions that are executed in the
 *  background as examples of the multitasking that DSP/BIOS is capable of:
 *
 *  1)  blinkLED() toggles LED #0 every 500ms if DIP switch #0 is depressed.
 *      It is a periodic thread with a period of 500 ticks.
 *
 *  2)  load() simulates a 20-25% dummy load if DIP switch #1 is depressed.
 *      It represents other computation that may need to be done.  It is a
 *      periodic thread with a period of 10ms.
 *
 *  Please see the 6713 DSK help file under Software/Examples for more
 *  detailed information on this example.
 */

/*
 *  DSP/BIOS is configured using the DSP/BIOS configuration tool.  Settings
 *  for this example are stored in a configuration file called dsk_app.cdb.
 *  At compile time, Code Composer will auto-generate DSP/BIOS related files
 *  based on these settings.  A header file called dsk_appcfg.h contains the
 *  results of the autogeneration and must be included for proper operation.
 *  The name of the file is taken from dsk_app.cdb and adding cfg.h.
 */
#include "dsk_appcfg.h"

/*
 *  These are include files that support interfaces to BIOS and CSL modules
 *  used by the program.
 */
#include <std.h>
#include <swi.h>
#include <log.h>
#include <c6x.h>
#include <csl.h>
#include <csl_edma.h>
#include <csl_irq.h>
#include <csl_mcbsp.h>

/*
 *  The 6713 DSK Board Support Library is divided into several modules, each
 *  of which has its own include file.  The file dsk6713.h must be included
 *  in every program that uses the BSL.  This example also uses the
 *  DIP, LED and AIC23 modules.
 */
#include "dsk6713.h"
#include "dsk6713_led.h"
#include "dsk6713_dip.h"
#include "dsk6713_aic23.h"

/* Function prototypes */
void initIrq(void);
void initMcbsp(void);
void initEdma(void);
void copyData(Int16 *inbuf, Int16 *outbuf, Int16 length);
void processBuffer(void);
void edmaHwi(void);

/* Constants for the buffered ping-pong transfer */
#define BUFFSIZE 1000
#define PING 0
#define PONG 1

/*
 * Data buffer declarations - the program uses four logical buffers of size
 * BUFFSIZE, one ping and one pong buffer on both receive and transmit sides.
 */
Int16 gBufferXmtPing[BUFFSIZE];  // Transmit PING buffer
Int16 gBufferXmtPong[BUFFSIZE];  // Transmit PONG buffer

Int16 gBufferRcvPing[BUFFSIZE];  // Receive PING buffer
Int16 gBufferRcvPong[BUFFSIZE];  // Receive PONG buffer

EDMA_Handle hEdmaXmt;            // EDMA channel handles
EDMA_Handle hEdmaReloadXmtPing;
EDMA_Handle hEdmaReloadXmtPong;
EDMA_Handle hEdmaRcv;
EDMA_Handle hEdmaReloadRcvPing;
EDMA_Handle hEdmaReloadRcvPong;

MCBSP_Handle hMcbsp1;                 // McBSP1 (codec data) handle

Int16 gXmtChan;                       // TCC codes (see initEDMA())
Int16 gRcvChan;


/*
 *  EDMA Config data structure
 */

/* Transmit side EDMA configuration */
EDMA_Config gEdmaConfigXmt = {
    EDMA_FMKS(OPT, PRI, HIGH)          |  // Priority
    EDMA_FMKS(OPT, ESIZE, 16BIT)       |  // Element size
    EDMA_FMKS(OPT, 2DS, NO)            |  // 2 dimensional source?
    EDMA_FMKS(OPT, SUM, INC)           |  // Src update mode
    EDMA_FMKS(OPT, 2DD, NO)            |  // 2 dimensional dest
    EDMA_FMKS(OPT, DUM, NONE)          |  // Dest update mode
    EDMA_FMKS(OPT, TCINT, YES)         |  // Cause EDMA interrupt?
    EDMA_FMKS(OPT, TCC, OF(0))         |  // Transfer complete code
    EDMA_FMKS(OPT, LINK, YES)          |  // Enable link parameters?
    EDMA_FMKS(OPT, FS, NO),               // Use frame sync?

    (Uint32)&gBufferXmtPing,              // Src address

    EDMA_FMK (CNT, FRMCNT, NULL)       |  // Frame count
    EDMA_FMK (CNT, ELECNT, BUFFSIZE),     // Element count

    EDMA_FMKS(DST, DST, OF(0)),           // Dest address

    EDMA_FMKS(IDX, FRMIDX, DEFAULT)    |  // Frame index value
    EDMA_FMKS(IDX, ELEIDX, DEFAULT),      // Element index value

    EDMA_FMK (RLD, ELERLD, NULL)       |  // Reload element
    EDMA_FMK (RLD, LINK, NULL)            // Reload link
};

/* Receive side EDMA configuration */
EDMA_Config gEdmaConfigRcv = {
    EDMA_FMKS(OPT, PRI, HIGH)          |  // Priority
    EDMA_FMKS(OPT, ESIZE, 16BIT)       |  // Element size
    EDMA_FMKS(OPT, 2DS, NO)            |  // 2 dimensional source?
    EDMA_FMKS(OPT, SUM, NONE)          |  // Src update mode
    EDMA_FMKS(OPT, 2DD, NO)            |  // 2 dimensional dest
    EDMA_FMKS(OPT, DUM, INC)           |  // Dest update mode
    EDMA_FMKS(OPT, TCINT, YES)         |  // Cause EDMA interrupt?
    EDMA_FMKS(OPT, TCC, OF(0))         |  // Transfer complete code
    EDMA_FMKS(OPT, LINK, YES)          |  // Enable link parameters?
    EDMA_FMKS(OPT, FS, NO),               // Use frame sync?

    EDMA_FMKS(SRC, SRC, OF(0)),           // Src address

    EDMA_FMK (CNT, FRMCNT, NULL)       |  // Frame count
    EDMA_FMK (CNT, ELECNT, BUFFSIZE),     // Element count

    (Uint32)&gBufferRcvPing,              // Dest address

    EDMA_FMKS(IDX, FRMIDX, DEFAULT)    |  // Frame index value
    EDMA_FMKS(IDX, ELEIDX, DEFAULT),      // Element index value

    EDMA_FMK (RLD, ELERLD, NULL)       |  // Reload element
    EDMA_FMK (RLD, LINK, NULL)            // Reload link
};

/* McBSP codec data channel configuration */
static MCBSP_Config mcbspCfg1 = {
        MCBSP_FMKS(SPCR, FREE, NO)              |
        MCBSP_FMKS(SPCR, SOFT, NO)              |
        MCBSP_FMKS(SPCR, FRST, YES)             |
        MCBSP_FMKS(SPCR, GRST, YES)             |
        MCBSP_FMKS(SPCR, XINTM, XRDY)           |
        MCBSP_FMKS(SPCR, XSYNCERR, NO)          |
        MCBSP_FMKS(SPCR, XRST, YES)             |
        MCBSP_FMKS(SPCR, DLB, OFF)              |
        MCBSP_FMKS(SPCR, RJUST, RZF)            |
        MCBSP_FMKS(SPCR, CLKSTP, DISABLE)       |
        MCBSP_FMKS(SPCR, DXENA, OFF)            |
        MCBSP_FMKS(SPCR, RINTM, RRDY)           |
        MCBSP_FMKS(SPCR, RSYNCERR, NO)          |
        MCBSP_FMKS(SPCR, RRST, YES),

        MCBSP_FMKS(RCR, RPHASE, SINGLE)         |
        MCBSP_FMKS(RCR, RFRLEN2, DEFAULT)       |
        MCBSP_FMKS(RCR, RWDLEN2, DEFAULT)       |
        MCBSP_FMKS(RCR, RCOMPAND, MSB)          |
        MCBSP_FMKS(RCR, RFIG, NO)               |
        MCBSP_FMKS(RCR, RDATDLY, 0BIT)          |
        MCBSP_FMKS(RCR, RFRLEN1, OF(1))         |
        MCBSP_FMKS(RCR, RWDLEN1, 16BIT)         |
        MCBSP_FMKS(RCR, RWDREVRS, DISABLE),

        MCBSP_FMKS(XCR, XPHASE, SINGLE)         |
        MCBSP_FMKS(XCR, XFRLEN2, DEFAULT)       |
        MCBSP_FMKS(XCR, XWDLEN2, DEFAULT)       |
        MCBSP_FMKS(XCR, XCOMPAND, MSB)          |
        MCBSP_FMKS(XCR, XFIG, NO)               |
        MCBSP_FMKS(XCR, XDATDLY, 0BIT)          |
        MCBSP_FMKS(XCR, XFRLEN1, OF(1))         |
        MCBSP_FMKS(XCR, XWDLEN1, 16BIT)         |
        MCBSP_FMKS(XCR, XWDREVRS, DISABLE),

        MCBSP_FMKS(SRGR, GSYNC, DEFAULT)        |
        MCBSP_FMKS(SRGR, CLKSP, DEFAULT)        |
        MCBSP_FMKS(SRGR, CLKSM, DEFAULT)        |
        MCBSP_FMKS(SRGR, FSGM, DEFAULT)         |
        MCBSP_FMKS(SRGR, FPER, DEFAULT)         |
        MCBSP_FMKS(SRGR, FWID, DEFAULT)         |
        MCBSP_FMKS(SRGR, CLKGDV, DEFAULT),

        MCBSP_MCR_DEFAULT,
        MCBSP_RCER_DEFAULT,
        MCBSP_XCER_DEFAULT,

        MCBSP_FMKS(PCR, XIOEN, SP)              |
        MCBSP_FMKS(PCR, RIOEN, SP)              |
        MCBSP_FMKS(PCR, FSXM, EXTERNAL)         |
        MCBSP_FMKS(PCR, FSRM, EXTERNAL)         |
        MCBSP_FMKS(PCR, CLKXM, INPUT)           |
        MCBSP_FMKS(PCR, CLKRM, INPUT)           |
        MCBSP_FMKS(PCR, CLKSSTAT, DEFAULT)      |
        MCBSP_FMKS(PCR, DXSTAT, DEFAULT)        |
        MCBSP_FMKS(PCR, FSXP, ACTIVEHIGH)       |
        MCBSP_FMKS(PCR, FSRP, ACTIVEHIGH)       |
        MCBSP_FMKS(PCR, CLKXP, FALLING)         |
        MCBSP_FMKS(PCR, CLKRP, RISING)
};

/* Codec configuration settings */
DSK6713_AIC23_Config config = { \
    0x0017,  /* 0 DSK6713_AIC23_LEFTINVOL  Left line input channel volume */ \
    0x0017,  /* 1 DSK6713_AIC23_RIGHTINVOL Right line input channel volume */\
    0x01f9,  /* 2 DSK6713_AIC23_LEFTHPVOL  Left channel headphone volume */  \
    0x01f9,  /* 3 DSK6713_AIC23_RIGHTHPVOL Right channel headphone volume */ \
    0x0011,  /* 4 DSK6713_AIC23_ANAPATH    Analog audio path control */      \
    0x0000,  /* 5 DSK6713_AIC23_DIGPATH    Digital audio path control */     \
    0x0000,  /* 6 DSK6713_AIC23_POWERDOWN  Power down control */             \
    0x0043,  /* 7 DSK6713_AIC23_DIGIF      Digital audio interface format */ \
    0x0001,  /* 8 DSK6713_AIC23_SAMPLERATE Sample rate control */            \
    0x0001   /* 9 DSK6713_AIC23_DIGACT     Digital interface activation */   \
};


/* --------------------------- main() function -------------------------- */
/*
 *  main() - The main user task.  Performs application initialization and
 *           starts the data transfer.
 */
void main()
{
    /* Initialize Board Support Library */
    DSK6713_init();

    /* Initialize LEDs and DIP switches */
    DSK6713_LED_init();
    DSK6713_DIP_init();

    /* Clear buffers */
    memset((void *)gBufferXmtPing, 0, BUFFSIZE * 4 * 2);

    AIC23_setParams(&config);  // Configure the codec

    initMcbsp();               // Initialize McBSP1 for audio transfers

    IRQ_globalDisable();       // Disable global interrupts during setup

    initEdma();                // Initialize the EDMA controller

    initIrq();                 // Initialize interrupts

    IRQ_globalEnable();        // Re-enable global interrupts
}


/* ------------------------Helper Functions ----------------------------- */

/*
 *  initMcbsp() - Initialize the McBSP for codec data transfers using the
 *                configuration define at the top of this file.
 */
void initMcbsp()
{
    /* Open the codec data McBSP */
    hMcbsp1 = MCBSP_open(MCBSP_DEV1, MCBSP_OPEN_RESET);

    /* Configure the codec to match the AIC23 data format */
    MCBSP_config(hMcbsp1, &mcbspCfg1);

    /* Start the McBSP running */
    MCBSP_start(hMcbsp1, MCBSP_XMIT_START | MCBSP_RCV_START |
        MCBSP_SRGR_START | MCBSP_SRGR_FRAMESYNC, 220);
}


/*
 *  initIrq() - Initialize and enable the DMA receive interrupt using the CSL.
 *              The interrupt service routine for this interrupt is edmaHwi.
 */
void initIrq(void)
{
    /* Enable EDMA interrupts to the CPU */
    IRQ_clear(IRQ_EVT_EDMAINT);    // Clear any pending EDMA interrupts
    IRQ_enable(IRQ_EVT_EDMAINT);   // Enable EDMA interrupt
}


/*
 *  initEdma() - Initialize the DMA controller.  Use linked transfers to
 *               automatically transition from ping to pong and visa-versa.
 */
void initEdma(void)
{
    /* Configure transmit channel */
    hEdmaXmt = EDMA_open(EDMA_CHA_XEVT1, EDMA_OPEN_RESET);  // get hEdmaXmt handle and reset channel
    hEdmaReloadXmtPing = EDMA_allocTable(-1);               // get hEdmaReloadXmtPing handle
    hEdmaReloadXmtPong = EDMA_allocTable(-1);               // get hEdmaReloadXmtPong handle

    gEdmaConfigXmt.dst = MCBSP_getXmtAddr(hMcbsp1);         // set the desination address to McBSP1 DXR

    gXmtChan = EDMA_intAlloc(-1);                           // get an open TCC
    gEdmaConfigXmt.opt |= EDMA_FMK(OPT,TCC,gXmtChan);       // set TCC to gXmtChan

    EDMA_config(hEdmaXmt, &gEdmaConfigXmt);                 // then configure the registers
    EDMA_config(hEdmaReloadXmtPing, &gEdmaConfigXmt);       // and the reload for Ping

    gEdmaConfigXmt.src = EDMA_SRC_OF(gBufferXmtPong);       // change the structure to have a source of Pong
    EDMA_config(hEdmaReloadXmtPong, &gEdmaConfigXmt);       // and configure the reload for Pong

    EDMA_link(hEdmaXmt,hEdmaReloadXmtPong);                 // link the regs to Pong
    EDMA_link(hEdmaReloadXmtPong,hEdmaReloadXmtPing);       // link Pong to Ping
    EDMA_link(hEdmaReloadXmtPing,hEdmaReloadXmtPong);       // and link Ping to Pong

    /* Configure receive channel */
    hEdmaRcv = EDMA_open(EDMA_CHA_REVT1, EDMA_OPEN_RESET);  // get hEdmaRcv handle and reset channel
    hEdmaReloadRcvPing = EDMA_allocTable(-1);               // get hEdmaReloadRcvPing handle
    hEdmaReloadRcvPong = EDMA_allocTable(-1);               // get hEdmaReloadRcvPong handle

    gEdmaConfigRcv.src = MCBSP_getRcvAddr(hMcbsp1);         // and the desination address to McBSP1 DXR

    gRcvChan = EDMA_intAlloc(-1);                           // get an open TCC
    gEdmaConfigRcv.opt |= EDMA_FMK(OPT,TCC,gRcvChan);       // set TCC to gRcvChan

    EDMA_config(hEdmaRcv, &gEdmaConfigRcv);                 // then configure the registers
    EDMA_config(hEdmaReloadRcvPing, &gEdmaConfigRcv);       // and the reload for Ping

    gEdmaConfigRcv.dst = EDMA_DST_OF(gBufferRcvPong);       // change the structure to have a destination of Pong
    EDMA_config(hEdmaReloadRcvPong, &gEdmaConfigRcv);       // and configure the reload for Pong

    EDMA_link(hEdmaRcv,hEdmaReloadRcvPong);                 // link the regs to Pong
    EDMA_link(hEdmaReloadRcvPong,hEdmaReloadRcvPing);       // link Pong to Ping
    EDMA_link(hEdmaReloadRcvPing,hEdmaReloadRcvPong);       // and link Ping to Pong

    /* Enable interrupts in the EDMA controller */
    EDMA_intClear(gXmtChan);
    EDMA_intClear(gRcvChan);                                // clear any possible spurious interrupts

    EDMA_intEnable(gXmtChan);                               // enable EDMA interrupts (CIER)
    EDMA_intEnable(gRcvChan);                               // enable EDMA interrupts (CIER)

    EDMA_enableChannel(hEdmaXmt);                           // enable EDMA channel
    EDMA_enableChannel(hEdmaRcv);                           // enable EDMA channel

    /* Do a dummy write to generate the first McBSP transmit event */
    MCBSP_write(hMcbsp1, 0);
}


/*
 *  copyData() - Copy one buffer with length elements to another.
 */
void copyData(Int16 *inbuf, Int16 *outbuf, Int16 length)
{
    Int16 i = 0;

    for (i = 0; i < length; i++) {
        outbuf[i]  = inbuf[i];
    }
}


/* ---------------------- Interrupt Service Routines -------------------- */

/*
 *  edmaHwi() - Interrupt service routine for the DMA transfer.  It is
 *              triggered when a complete DMA receive frame has been
 *              transferred.   The edmaHwi ISR is inserted into the interrupt
 *              vector table at compile time through a setting in the DSP/BIOS
 *              configuration under Scheduling --> HWI --> HWI_INT8.  edmaHwi
 *              uses the DSP/BIOS Dispatcher to save register state and make
 *              sure the ISR co-exists with other DSP/BIOS functions.
 */
void edmaHwi(void)
{
    static Uint32 pingOrPong = PING;  // Ping-pong state variable
    static Int16 xmtdone = 0, rcvdone = 0;

    /* Check CIPR to see which transfer completed */
    if (EDMA_intTest(gXmtChan))
    {
        EDMA_intClear(gXmtChan);
        xmtdone = 1;
    }
    if (EDMA_intTest(gRcvChan))
    {
        EDMA_intClear(gRcvChan);
        rcvdone = 1;
    }

    /* If both transfers complete, signal processBufferSwi to handle */
    if (xmtdone && rcvdone)
    {
        if (pingOrPong==PING)
        {
            SWI_or(&processBufferSwi, PING);
            pingOrPong = PONG;
        } else
        {
            SWI_or(&processBufferSwi, PONG);
            pingOrPong = PING;
        }
        rcvdone = 0;
        xmtdone = 0;
    }
}


/* ------------------------------- Threads ------------------------------ */

/*
 *  processBuffer() - Process audio data once it has been received.
 */
void processBuffer(void)
{
    Uint32 pingPong;

    /* Get contents of mailbox posted by edmaHwi */
    pingPong =  SWI_getmbox();

    /* Copy data from transmit to receive, could process audio here */
    if (pingPong == PING) {
        /* Toggle LED #3 as a visual cue */
        DSK6713_LED_toggle(3);

        /* Copy receive PING buffer to transmit PING buffer */
        copyData(gBufferRcvPing, gBufferXmtPing, BUFFSIZE);
    } else {
        /* Toggle LED #2 as a visual cue */
        DSK6713_LED_toggle(2);

        /* Copy receive PONG buffer to transmit PONG buffer */
        copyData(gBufferRcvPong, gBufferXmtPong, BUFFSIZE);
    }
}

/*
 *  blinkLED() - Periodic thread (PRD) that toggles LED #0 every 500ms if
 *               DIP switch #0 is depressed.  The thread is configured
 *               in the DSP/BIOS configuration tool under Scheduling -->
 *               PRD --> PRD_blinkLed.  The period is set there at 500
 *               ticks, with each tick corresponding to 1ms in real
 *               time.
 */
void blinkLED(void)
{
    /* Toggle LED #0 if DIP switch #0 is off (depressed) */
    if (!DSK6713_DIP_get(0))
        DSK6713_LED_toggle(0);
}


/*
 *  load() - PRD that simulates a 20-25% dummy load on a 225MHz 6713 if
 *           DIP switch #1 is depressed.  The thread is configured in
 *           the DSP/BIOS configuration tool under Scheduling --> PRD
 *           PRD_load.  The period is set there at 10 ticks, which each tick
 *           corresponding to 1ms in real time.
 */
void load(void)
{
    volatile Uint32 i;

    if (!DSK6713_DIP_get(1))
        for (i = 0; i < 30000; i++);
}
