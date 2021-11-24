/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */

/*
 *  ======== aic23.c ========
 *
 *  AIC23 codec driver implementation specific to the
 *  Spectrum Digital DSK6713 board.
 */
 
#include "dsk_appcfg.h"

#include <aic23.h>

#include <csl.h>
#include <csl_mcbsp.h>

static void aic23Rset(MCBSP_Handle hMcbsp, Uint16 regnum, Uint16 regval);

/* CSL handle to the McBSP0. The McBSP is used as the control channel in SPI*/
static MCBSP_Config mcbspCfg0 = {
        MCBSP_FMKS(SPCR, FREE, NO)              |
        MCBSP_FMKS(SPCR, SOFT, NO)              |
        MCBSP_FMKS(SPCR, FRST, YES)             |
        MCBSP_FMKS(SPCR, GRST, YES)             |
        MCBSP_FMKS(SPCR, XINTM, XRDY)           |
        MCBSP_FMKS(SPCR, XSYNCERR, NO)          |
        MCBSP_FMKS(SPCR, XRST, YES)             |
        MCBSP_FMKS(SPCR, DLB, OFF)              |
        MCBSP_FMKS(SPCR, RJUST, RZF)            |
        MCBSP_FMKS(SPCR, CLKSTP, NODELAY)       |
        MCBSP_FMKS(SPCR, DXENA, OFF)            |
        MCBSP_FMKS(SPCR, RINTM, RRDY)           |
        MCBSP_FMKS(SPCR, RSYNCERR, NO)          |
        MCBSP_FMKS(SPCR, RRST, YES),

        MCBSP_FMKS(RCR, RPHASE, DEFAULT)        |
        MCBSP_FMKS(RCR, RFRLEN2, DEFAULT)       |
        MCBSP_FMKS(RCR, RWDLEN2, DEFAULT)       |
        MCBSP_FMKS(RCR, RCOMPAND, DEFAULT)      |
        MCBSP_FMKS(RCR, RFIG, DEFAULT)          |
        MCBSP_FMKS(RCR, RDATDLY, DEFAULT)       |
        MCBSP_FMKS(RCR, RFRLEN1, DEFAULT)       |
        MCBSP_FMKS(RCR, RWDLEN1, DEFAULT)       |
        MCBSP_FMKS(RCR, RWDREVRS, DEFAULT),

        MCBSP_FMKS(XCR, XPHASE, SINGLE)         |
        MCBSP_FMKS(XCR, XFRLEN2, OF(0))         |
        MCBSP_FMKS(XCR, XWDLEN2, 8BIT)          |
        MCBSP_FMKS(XCR, XCOMPAND, MSB)          |
        MCBSP_FMKS(XCR, XFIG, NO)               |
        MCBSP_FMKS(XCR, XDATDLY, 1BIT)          |
        MCBSP_FMKS(XCR, XFRLEN1, OF(0))         |
        MCBSP_FMKS(XCR, XWDLEN1, 16BIT)         |
        MCBSP_FMKS(XCR, XWDREVRS, DISABLE),
        
        MCBSP_FMKS(SRGR, GSYNC, FREE)           |
        MCBSP_FMKS(SRGR, CLKSP, RISING)         |
        MCBSP_FMKS(SRGR, CLKSM, INTERNAL)       |
        MCBSP_FMKS(SRGR, FSGM, DXR2XSR)         |
        MCBSP_FMKS(SRGR, FPER, OF(0))           |
        MCBSP_FMKS(SRGR, FWID, OF(19))          |
        MCBSP_FMKS(SRGR, CLKGDV, OF(99)),

        MCBSP_MCR_DEFAULT,
        MCBSP_RCER_DEFAULT,
        MCBSP_XCER_DEFAULT,
        
        MCBSP_FMKS(PCR, XIOEN, SP)              |
        MCBSP_FMKS(PCR, RIOEN, SP)              |
        MCBSP_FMKS(PCR, FSXM, INTERNAL)         |
        MCBSP_FMKS(PCR, FSRM, EXTERNAL)         |
        MCBSP_FMKS(PCR, CLKXM, OUTPUT)          |
        MCBSP_FMKS(PCR, CLKRM, INPUT)           |
        MCBSP_FMKS(PCR, CLKSSTAT, DEFAULT)      |
        MCBSP_FMKS(PCR, DXSTAT, DEFAULT)        |
        MCBSP_FMKS(PCR, FSXP, ACTIVELOW)        |
        MCBSP_FMKS(PCR, FSRP, DEFAULT)          |
        MCBSP_FMKS(PCR, CLKXP, FALLING)         |
        MCBSP_FMKS(PCR, CLKRP, DEFAULT)
};

/*
 *  ======== AIC23_setParams ========
 *
 *  This function takes a pointer to the object of type AIC23_Params,
 *  and writes all 11 control words found in it to the codec. Prior
 *  to that it initializes the codec if this is the first time the
 *  function is ever called.
 *  The 16-bit word is composed of register address in the upper 7 bits
 *  and the 9-bit register value stored in the parameters structure.
 */
Void AIC23_setParams(AIC23_Params *params)
{
    Int i;
    MCBSP_Handle hMcbsp;

    /* open and configure McBSPs */
    hMcbsp = MCBSP_open(MCBSP_PORT0, MCBSP_OPEN_RESET);
    MCBSP_config(hMcbsp, &mcbspCfg0);

    /*
     *  Initialize the AIC23 codec
     */

    /* Start McBSP1 as the codec control channel */
    MCBSP_start(hMcbsp, MCBSP_XMIT_START |
        MCBSP_SRGR_START | MCBSP_SRGR_FRAMESYNC, 100);
    
    /* Reset the AIC23 */
    aic23Rset(hMcbsp, AIC23_RESET, 0);
    
    /* Assign each register */
    for (i = 0; i < AIC23_NUMREGS; i++) {
        aic23Rset(hMcbsp, i, params->regs[i]);
    }
}


/*
 *  ======== aic23Rset ========
 *  Set codec register regnum to value regval
 */
static Void aic23Rset(MCBSP_Handle hMcbsp, Uint16 regnum, Uint16 regval)
{
    /* Mask off lower 9 bits */
    regval &= 0x1ff;
    
    /* Wait for XRDY signal before writing data to DXR */
    while (!MCBSP_xrdy(hMcbsp));
    
    /* Write 16 bit data value to DXR */
    MCBSP_write(hMcbsp, (regnum << 9) | regval);

    /* Wait for XRDY, state machine will not update until next McBSP clock */
    while (MCBSP_xrdy(hMcbsp));
}


