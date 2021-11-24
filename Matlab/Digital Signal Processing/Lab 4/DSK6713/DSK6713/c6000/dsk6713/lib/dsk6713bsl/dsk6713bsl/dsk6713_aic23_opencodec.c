/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk6713_aic23_openCodec.c ========
 *  DSK6713_AIC23_openCodec() implementation
 */

#include <dsk6713.h>
#include <dsk6713_aic23.h>

/* AIC23 McBSP handles */
MCBSP_Handle DSK6713_AIC23_CONTROLHANDLE;
MCBSP_Handle DSK6713_AIC23_DATAHANDLE;

/*
 *  ======== DSK6713_AIC23_openCodec ========
 *  Open the codec and return a codec handle
 */
DSK6713_AIC23_CodecHandle DSK6713_AIC23_openCodec(int id, DSK6713_AIC23_Config *Config)
{
    MCBSP_Config mcbspCfgControl = {
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

    MCBSP_Config mcbspCfgData = {
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

    /* Open codec control handle */
    DSK6713_AIC23_CONTROLHANDLE = MCBSP_open(MCBSP_DEV0, MCBSP_OPEN_RESET);
    if (DSK6713_AIC23_CONTROLHANDLE == INV)
        return FALSE;

    /* Open codec data handle */
    DSK6713_AIC23_DATAHANDLE = MCBSP_open(MCBSP_DEV1, MCBSP_OPEN_RESET);
    if (DSK6713_AIC23_DATAHANDLE == INV)
        return FALSE;

    /* Configure codec control McBSP */
    MCBSP_config(DSK6713_AIC23_CONTROLHANDLE, &mcbspCfgControl);

    /* Configure codec data McBSP */
    MCBSP_config(DSK6713_AIC23_DATAHANDLE, &mcbspCfgData);

    /* Start McBSP1 as the codec control channel */
    MCBSP_start(DSK6713_AIC23_CONTROLHANDLE, MCBSP_XMIT_START |
        MCBSP_SRGR_START | MCBSP_SRGR_FRAMESYNC, 220);

    /* Reset the AIC23 */
    DSK6713_AIC23_rset(0, DSK6713_AIC23_RESET, 0);

    /* Configure the rest of the AIC23 registers */
    DSK6713_AIC23_config(0, Config);

    /* Clear any garbage from the codec data port */
    if (MCBSP_rrdy(DSK6713_AIC23_DATAHANDLE))
        MCBSP_read(DSK6713_AIC23_DATAHANDLE);

    /* Start McBSP2 as the codec data channel */
    MCBSP_start(DSK6713_AIC23_DATAHANDLE, MCBSP_XMIT_START | MCBSP_RCV_START |
        MCBSP_SRGR_START | MCBSP_SRGR_FRAMESYNC, 220);

    return TRUE;
}
