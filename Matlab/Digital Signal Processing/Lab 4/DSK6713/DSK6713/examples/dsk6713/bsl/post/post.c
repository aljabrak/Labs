/*
 *  Copyright 2003 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== post.c ========
 *
 *  The Power On Self Test (POST) is a small program that uses the 6713 DSK
 *  Board Support Library to perform basic tests on the DSP and board
 *  peripherals.  It is typically programmed into the Flash memory so it
 *  runs on boot.  The following tests are perfored:
 *
 *  Index    Description
 *    1      Internal memory
 *    2      External memory typical (SDRAM)
 *    3      External memory special (Flash)
 *    4      McBSP0 in loopback mode
 *    5      McBSP1 in loopback mode
 *    6      Internal DMA transfer
 *    7      Codec test
 *    8      LED and timer test
 *
 *  The POST displays the index of the test being run on the LEDs.  If an
 *  error is detected while running the test, the test index will blink
 *  continuously.  If all tests complete successfully, all 4 LEDs will blink
 *  three times and stop will all LEDs on.
 *
 *  This code will only work when built with the large memory model because
 *  of the need to access the external SDRAM.
 *
 *  Please see the 6713 DSK help file under Software/Examples for more
 *  detailed information.
 */

/*
 *  DSP/BIOS is configured using the DSP/BIOS configuration tool.  Settings
 *  for this example are stored in a configuration file called post.cdb.  At
 *  compile time, Code Composer will auto-generate DSP/BIOS related files
 *  based on these settings.  A header file called postcfg.h contains the
 *  results of the autogeneration and must be included for proper operation.
 *  The name of the file is taken from post.cdb and adding cfg.h.
 */
#include "postcfg.h"

/*
 *  The POST uses the Chip Support Library for basic definitions as well as
 *  McBSP manipulation.  Programs that use the CSL must include the
 *  appropriate header files.
 */
#include <csl.h>
#include <csl_mcbsp.h>
#include <csl_timer.h>
#include <csl_edma.h>

/*
 *  The 6713 DSK Board Support Library is divided into several modules, each
 *  of which has its own include file.  The file dsk6713.h must be included
 *  in every program that uses the BSL.  This example also includes
 *  dsk6713_aic23.h, dsk6713_led.h and dsk6713_flash.h because it uses
 *  their respective BSL modules.
 */
#include "dsk6713.h"
#include "dsk6713_led.h"
#include "dsk6713_aic23.h"
#include "dsk6713_flash.h"

/* Length of sine wave table */
#define SINE_TABLE_SIZE  48

/* Number of elements for DMA and McBSP loopback tests */
#define N                16

/* Pre-generated sine wave data, 16-bit signed samples */
int sinetable[SINE_TABLE_SIZE] = {
    0x0000, 0x10b4, 0x2120, 0x30fb, 0x3fff, 0x4dea, 0x5a81, 0x658b,
    0x6ed8, 0x763f, 0x7ba1, 0x7ee5, 0x7ffd, 0x7ee5, 0x7ba1, 0x76ef,
    0x6ed8, 0x658b, 0x5a81, 0x4dea, 0x3fff, 0x30fb, 0x2120, 0x10b4,
    0x0000, 0xef4c, 0xdee0, 0xcf06, 0xc002, 0xb216, 0xa57f, 0x9a75,
    0x9128, 0x89c1, 0x845f, 0x811b, 0x8002, 0x811b, 0x845f, 0x89c1,
    0x9128, 0x9a76, 0xa57f, 0xb216, 0xc002, 0xcf06, 0xdee0, 0xef4c
};

/* Codec configuration settings */
DSK6713_AIC23_Config config = { \
    0x0017,  /* 0 DSK6713_AIC23_LEFTINVOL  Left line input channel volume */ \
    0x0017,  /* 1 DSK6713_AIC23_RIGHTINVOL Right line input channel volume */\
    0x00d8,  /* 2 DSK6713_AIC23_LEFTHPVOL  Left channel headphone volume */  \
    0x00d8,  /* 3 DSK6713_AIC23_RIGHTHPVOL Right channel headphone volume */ \
    0x0011,  /* 4 DSK6713_AIC23_ANAPATH    Analog audio path control */      \
    0x0000,  /* 5 DSK6713_AIC23_DIGPATH    Digital audio path control */     \
    0x0000,  /* 6 DSK6713_AIC23_POWERDOWN  Power down control */             \
    0x0043,  /* 7 DSK6713_AIC23_DIGIF      Digital audio interface format */ \
    0x0081,  /* 8 DSK6713_AIC23_SAMPLERATE Sample rate control */            \
    0x0001   /* 9 DSK6713_AIC23_DIGACT     Digital interface activation */   \
};

/* Define source and destination arrays for DMA and loopback tests */
Uint16 src[N], dst[N];

/* Variables used by the TEST_sleep() funciton */
Uint16 eventId1;
volatile Uint16 sleepCount = 0;


/*
 *  Interrupt Service Routines
 */

void sleepIsr()
{
    sleepCount++;
}

/*
 *  Accessory functions
 */

void TEST_sleep(Int16 sleeptime)
{
    TIMER_Handle hTimer1;
    TIMER_Config timerCfg1 = {
        TIMER_FMKS(CTL, INVINP, NO)             |
        TIMER_FMKS(CTL, CLKSRC, CPUOVR4)        |
        TIMER_FMKS(CTL, CP, PULSE)              |
        TIMER_FMKS(CTL, HLD, YES)               |
        TIMER_FMKS(CTL, GO, NO)                 |
        TIMER_FMKS(CTL, PWID, ONE)              |
        TIMER_FMKS(CTL, DATOUT, 0)              |
        TIMER_FMKS(CTL, INVOUT, NO)             |
        TIMER_FMKS(CTL, FUNC, TOUT),

        TIMER_FMKS(PRD, PRD, OF(75000)),
        TIMER_FMKS(CNT, CNT, OF(0))
    };

    /* Open the timer */
    hTimer1 = TIMER_open(TIMER_DEV1, TIMER_OPEN_RESET);

    /* Configure the timer in one-shot mode */
    TIMER_config(hTimer1, &timerCfg1);

    /* Get Event Id associated with Timer 1, for use with */
    /* CSL interrupt enable functions.                    */
    eventId1 = TIMER_getEventId(hTimer1);

    /* Map the logical event to a physical interrupt */
    IRQ_map(eventId1, 15);

    /* Clear any pending Timer interrupts */
    IRQ_clear(eventId1);

    /* Enable timer interrupt */
    IRQ_enable(eventId1);

    /* Make sure global interrupts are enabled */
    IRQ_globalEnable();

    /* Clear sleep count */
    sleepCount = 0;

    /* Start timer 1 */
    TIMER_start(hTimer1);

    while(sleepCount < sleeptime);

    /* Disable timer interrupt */
    IRQ_disable(eventId1);

    TIMER_close(hTimer1);
}

void LED_binary(Int16 ledmask)
{
    Int16 i, bit;

    /* Walk through the bits in num setting corresponding LEDs */
    bit = 1;
    for (i = 0; i < 4; i++)
    {
        if (ledmask & bit)
            DSK6713_LED_on(i);
        else
            DSK6713_LED_off(i);
        bit = bit << 1;
    }

}

void LED_blink(Int16 ledmask, Int16 count)
{
    while (count > 0)
    {
        LED_binary(ledmask);
        TEST_sleep(100);
        LED_binary(0);
        TEST_sleep(150);
        count--;
    }
}

void LED_error(Int16 ledmask)
{
    while(1)
        LED_blink(ledmask, 1);
}

/*
 *  Memory functions
 */

Int16 MEM_fill(Uint32 start, Uint32 len, Uint32 val)
{
    Uint32 i, end;

    /* Calculate end of range */
    end = start + len;

    /* Fill a range with a value */
    for (i = start; i < end; i+=4)
    {
        *((Uint32 *)i) = val;
    }

    /* Verify the data */
    for (i = start; i < end; i+=4)
    {
        if (*((Uint32 *)i) != val)
            return 1;
    }

    return 0;
}

Int16 MEM_addr(Uint32 start, Uint32 len)
{
    Uint32 i, end;

    /* Calculate end of range */
    end = start + len;

    /* Fill the range with its address */
    for (i = start; i < end; i+=4)
    {
        *((Uint32 *)i) = i;
    }

    /* Verify the data */
    for (i = start; i < end; i+=4)
        if (*((Uint32 *)i) != i)
        {
            return 1;
        }

    return 0;
}

Int16 MEM_addrInv(Uint32 start, Uint32 len)
{
    Uint32 i, end;

    /* Calculate end of range */
    end = start + len;

    /* Fill the range with its address */
    for (i = start; i < end; i+=4)
    {
        *((Uint32 *)i) = ~i;
    }

    /* Verify the data */
    for (i = start; i < end; i+=4)
        if (*((Uint32 *)i) != (~i))
            return 1;

    return 0;
}

Int16 MEM_walking(Uint32 add)
{
    Int16 i;
    Uint32 mask, *pdata;

    pdata = (Uint32 *)add;

    /* Walking ones and zeros */
    mask = 1;
    for (i = 0; i < 32; i++)
    {
        /* Test one in bit position i */
        *pdata = mask;
        if (*pdata != mask)
            return 1;

        /* Test zero in bit position i */
        *pdata = ~mask;
        if (*pdata != (~mask))
            return 1;

        mask = mask << 1;
    }

    return 0;
}

Int16 MEM_test(Uint32 start, Uint32 len, Int16 patterntype)
{
    Int16 status = 0;

    if (!patterntype)
    {
        /* Run the fill tests */
        status |= MEM_fill(start, len, 0x00000000);
        status |= MEM_fill(start, len, 0x55555555);
        status |= MEM_fill(start, len, 0xAAAAAAAA);
        status |= MEM_fill(start, len, 0xFFFFFFFF);
    } else
    {
        /* Run the address tests */
        status |= MEM_addr(start, len);
        status |= MEM_addrInv(start, len);
    }

    return status;
}


/*
 *  POST tests
 */

Int16 TEST_intMem()
{
    Int16 status = 0;

    /* Check internal memory (byte 0x10000 to byte 0x40000) */
    status |= MEM_test(0x10000, 0x30000, 0);
    status |= MEM_test(0x10000, 0x30000, 1);
    status |= MEM_walking(0x10000);

    return status;
}

Int16 TEST_extMem()
{
    Int16 status = 0;

    /* Check external memory (8 Mb for ver. 1, 16 Mb for ver. 2) */
    if (DSK6713_getVersion() == 1)
    {
        status |= MEM_test(0x80000000, 0x0800000, 0);
        status |= MEM_test(0x80000000, 0x0800000, 1);
    } else
    {
        status |= MEM_test(0x80000000, 0x1000000, 0);
        status |= MEM_test(0x80000000, 0x1000000, 1);
    }
    status |= MEM_walking(0x80000000);

    return status;
}

Int16 TEST_flashID()
{
#if(0)  // Change to 1 to enable Flash ID test
    Uint16 MfgId,DevId;
    Int16 i;

    /* Reset flash */
    *((volatile Uint8 *)DSK6713_FLASH_BASE) = 0xf0;

    /* Configure to read manufacturer ID */
    *((volatile Uint8 *)DSK6713_FLASH_CTL555) = 0xaa;
    *((volatile Uint8 *)DSK6713_FLASH_CTL2AA) = 0x55;
    *((volatile Uint8 *)DSK6713_FLASH_CTL555) = 0x90;

    /* Insert small delay for device to respond */
    for (i = 0; i < 100; i++);

    /* Read IDs */
    MfgId = *((Uint8 *)DSK6713_FLASH_BASE) & 0xff;
    DevId = *((Uint8 *)(DSK6713_FLASH_BASE + 1)) & 0xff;

    /* Reset flash */
    *((Uint16 *)DSK6713_FLASH_BASE) = 0xf0;

    /* Check IDs */
    if ((MfgId != 0x01) || (DevId != 0xb9))
        return 1;
#endif

    /* Test passed */
    return 0;
}

Int16 TEST_mcbsp(int devid, Int16 delayed)
{
    Int16 i;
    Uint16 receivedata;
    MCBSP_Handle hMcbsp;
    MCBSP_Config mcbspCfg_loopback = {
        MCBSP_FMKS(SPCR, FREE, NO)              |
        MCBSP_FMKS(SPCR, SOFT, NO)              |
        MCBSP_FMKS(SPCR, FRST, YES)             |
        MCBSP_FMKS(SPCR, GRST, YES)             |
        MCBSP_FMKS(SPCR, XINTM, XRDY)           |
        MCBSP_FMKS(SPCR, XSYNCERR, NO)          |
        MCBSP_FMKS(SPCR, XRST, YES)             |
        MCBSP_FMKS(SPCR, DLB, ON)               |
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
        MCBSP_FMKS(RCR, RFRLEN1, OF(0))         |
        MCBSP_FMKS(RCR, RWDLEN1, 16BIT)         |
        MCBSP_FMKS(RCR, RWDREVRS, DISABLE),

        MCBSP_FMKS(XCR, XPHASE, SINGLE)         |
        MCBSP_FMKS(XCR, XFRLEN2, DEFAULT)       |
        MCBSP_FMKS(XCR, XWDLEN2, DEFAULT)       |
        MCBSP_FMKS(XCR, XCOMPAND, MSB)          |
        MCBSP_FMKS(XCR, XFIG, NO)               |
        MCBSP_FMKS(XCR, XDATDLY, 0BIT)          |
        MCBSP_FMKS(XCR, XFRLEN1, OF(0))         |
        MCBSP_FMKS(XCR, XWDLEN1, 16BIT)         |
        MCBSP_FMKS(XCR, XWDREVRS, DISABLE),

        MCBSP_SRGR_DEFAULT,
        MCBSP_MCR_DEFAULT,
        MCBSP_RCER_DEFAULT,
        MCBSP_XCER_DEFAULT,

        MCBSP_FMKS(PCR, XIOEN, DEFAULT)         |
        MCBSP_FMKS(PCR, RIOEN, DEFAULT)         |
        MCBSP_FMKS(PCR, FSXM, INTERNAL)         |
        MCBSP_FMKS(PCR, FSRM, DEFAULT)          |
        MCBSP_FMKS(PCR, CLKXM, OUTPUT)          |
        MCBSP_FMKS(PCR, CLKRM, INPUT)           |
        MCBSP_FMKS(PCR, CLKSSTAT, DEFAULT)      |
        MCBSP_FMKS(PCR, DXSTAT, DEFAULT)        |
        MCBSP_FMKS(PCR, FSXP, DEFAULT)          |
        MCBSP_FMKS(PCR, FSRP, DEFAULT)          |
        MCBSP_FMKS(PCR, CLKXP, DEFAULT)         |
        MCBSP_FMKS(PCR, CLKRP, DEFAULT)
    };

    /* Initialize source data, zero dest */
    for (i = 0; i < N; i++) {
        src[i] = (i << 8) | i + 1;
        dst[i] = 0;
    }

    /* Open the McBSP */
    hMcbsp = MCBSP_open(devid, MCBSP_OPEN_RESET);

    /* Configure the McBSP for loopback mode */
    MCBSP_config(hMcbsp, &mcbspCfg_loopback);

    /* Start the McBSP */
    MCBSP_start(hMcbsp, MCBSP_RCV_START | MCBSP_XMIT_START |
        MCBSP_SRGR_START | MCBSP_SRGR_FRAMESYNC, 220);

    /* Data transfer loop */
    for (i = 0; i < (N + delayed); i++) {
        /* Wait for XRDY signal before writing data to DXR */
        while (!MCBSP_xrdy(hMcbsp));

        /* Write 16 bit data value to DXR */
        MCBSP_write(hMcbsp,src[i]);

        /* Wait for RRDY signal to read data from DRR */
        while (!MCBSP_rrdy(hMcbsp));

        /* Read 16 bit value from DRR */
        receivedata = MCBSP_read(hMcbsp);
        if (i >= delayed)
            dst[i - delayed] = receivedata;
    }

    /* Close the McBSP */
    MCBSP_close(hMcbsp);

    /* Check data to make sure transfer was successful */
    for (i = 0; i < N; i++)
        if (dst[i] != src[i])
            return 1;

    /* Test passed */
    return 0;
}

Int16 TEST_mcbsp0()
{
    /* Do an internal loopback test on McBSP0 */
    return TEST_mcbsp(MCBSP_DEV0, 0);
}

Int16 TEST_mcbsp1()
{
    /* Do an internal loopback test on McBSP1 */
    return TEST_mcbsp(MCBSP_DEV1, 0);
}

Int16 TEST_dma()
{
    Int16 i;
    EDMA_Handle hEdmaCha8;
    EDMA_Config edmaCfg8 = {
        EDMA_FMKS(OPT, PRI, HIGH)             |
        EDMA_FMKS(OPT, ESIZE, 16BIT)          |
        EDMA_FMKS(OPT, 2DS, NO)               |
        EDMA_FMKS(OPT, SUM, INC)              |
        EDMA_FMKS(OPT, 2DD, NO)               |
        EDMA_FMKS(OPT, DUM, INC)              |
        EDMA_FMKS(OPT, TCINT, YES)            |
        EDMA_FMK (OPT, TCC, 15)               |
        EDMA_FMKS(OPT, LINK, NO)              |
        EDMA_FMKS(OPT, FS, YES),

        (Uint32)src,

        EDMA_FMKS(CNT, FRMCNT, OF(0))         |
        EDMA_FMKS(CNT, ELECNT, OF(16)),

        (Uint32)dst,

        EDMA_FMKS(IDX, FRMIDX, DEFAULT)       |
        EDMA_FMKS(IDX, ELEIDX, DEFAULT),

        EDMA_FMKS(RLD, ELERLD, DEFAULT)       |
        EDMA_FMKS(RLD, LINK, DEFAULT)
    };

    /* Set src values and clear destination */
    for (i = 0; i < N; i++) {
        src[i] = i;
        dst[i] = 0;
    }

    /* Configure EDMA */
    hEdmaCha8 = EDMA_open(8, EDMA_OPEN_RESET);
    EDMA_config(hEdmaCha8, &edmaCfg8);

    /* Start CPU initiated EDMA transfer by setting bit 24 in ESR */
    EDMA_RSET(ESR, 0x00000100);

    /* Poll DMA interrupt too see if its done */
    while (!EDMA_intTest(15))
    {
        ;
    }

    /* We are done, so close DMA channel */
    EDMA_close(hEdmaCha8);

    /* Check data */
    for (i = 0; i < N; i++)
        if (dst[i] != src[i])
            return 1;

    /* Test passed */
    return 0;
}

Int16 TEST_codec()
{
    DSK6713_AIC23_CodecHandle hCodec;
    Int16 i, j;

    /* Start the codec */
    hCodec = DSK6713_AIC23_openCodec(0, &config);

    /* Generate a 1KHz sine wave for 1 second */
    for (i = 0; i < 1000; i++)
    {
        for (j = 0; j < SINE_TABLE_SIZE; j++)
        {
            while (!DSK6713_AIC23_write(hCodec, sinetable[j]));
            while (!DSK6713_AIC23_write(hCodec, sinetable[j]));
        }
    }

    /* Close codec */
    DSK6713_AIC23_closeCodec(hCodec);

    return 0;
}

Int16 TEST_timer()
{
    /* Wait for 100 timer interrupts */
    TEST_sleep(100);

    return 0;
}

Int16 TEST_null()
{
    return 0;
}

void TEST_execute(Int16 (*funchandle)(), Int16 ledmask, Int16 insertdelay)
{
    Int16 status;


    /* Display test ID */
    LED_binary(ledmask);

    /* Call test function */
    status = funchandle();

    /* Pause so LEDs can be read */
    if (insertdelay)
        TEST_sleep(100);

    /* Check for test fail */
    if (status)
        LED_error(ledmask);
}

main()
{
    /* Call BSL init */
    DSK6713_init();

    /* Set initial LED state */
    DSK6713_LED_init();

    /* Run the tests sequentially */
    TEST_execute(TEST_intMem,     1, 1);  /* Internal memory */
    TEST_execute(TEST_extMem,     2, 0);  /* External memory (typical) */
    TEST_execute(TEST_flashID,    3, 1);  /* External memory (flash) */
    TEST_execute(TEST_mcbsp0,     4, 1);  /* McBSP0 loopback */
    TEST_execute(TEST_mcbsp1,     5, 1);  /* McBSP1 loopback */
    TEST_execute(TEST_dma,        6, 1);  /* DMA test */
    TEST_execute(TEST_codec,      7, 0);  /* Codec test */
    TEST_execute(TEST_timer,      8, 0);  /* LED and timer test */

    /* All tests complete, board passes */
    LED_blink(0xf, 3);

    /* Leave all LEDs on */
    LED_binary(0xf);

    /* Disable interrupts */
    IRQ_globalDisable();
}
