/*
 *  Copyright 2003 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk6713.c ========
 *  Board Setup initializion implementation.
 */

#include <csl.h>
#include <csl_emif.h>
#include <csl_pll.h>
#include <dsk6713.h>

/*
 *    6713 DSK Version Table
 *
 *    Board Rev  CPLD Rev  Vesion  Features
 *       1          2         1    8 Mb SDRAM
 *       2          2         2    16 Mb SDRAM
 */

Int16 DSK6713_version;

/* Local software delay function */
static void _plldelay( Uint32 Count )
{
    volatile int i = Count;
    while(i--);
}

/* Initialize the board APIs */
void DSK6713_init()
{
    EMIF_Config emifCfg0 = {
        0x60                                  |
        EMIF_FMKS(GBLCTL, NOHOLD, DISABLE)    |
        EMIF_FMKS(GBLCTL, CLK1EN, DISABLE)    |
        EMIF_FMKS(GBLCTL, CLK2EN, ENABLE),

        EMIF_FMKS(CECTL, WRSETUP, DEFAULT)    |
        EMIF_FMKS(CECTL, WRSTRB, DEFAULT)     |
        EMIF_FMKS(CECTL, WRHLD, DEFAULT)      |
        EMIF_FMKS(CECTL, RDSETUP, DEFAULT)    |
        EMIF_FMKS(CECTL, TA, OF(2))           |
        EMIF_FMKS(CECTL, RDSTRB, DEFAULT)     |
        EMIF_FMKS(CECTL, MTYPE, SDRAM32)      |
        EMIF_FMKS(CECTL, RDHLD, DEFAULT),

        EMIF_FMKS(CECTL, WRSETUP, OF(0))      |
        EMIF_FMKS(CECTL, WRSTRB, OF(8))       |
        EMIF_FMKS(CECTL, WRHLD, OF(2))        |
        EMIF_FMKS(CECTL, RDSETUP, OF(0))      |
        EMIF_FMKS(CECTL, TA, OF(2))           |
        EMIF_FMKS(CECTL, RDSTRB, OF(8))       |
        EMIF_FMKS(CECTL, MTYPE, ASYNC8)       |
        EMIF_FMKS(CECTL, RDHLD, OF(2)),

        EMIF_FMKS(CECTL, WRSETUP, OF(2))      |
        EMIF_FMKS(CECTL, WRSTRB, OF(10))      |
        EMIF_FMKS(CECTL, WRHLD, OF(2))        |
        EMIF_FMKS(CECTL, RDSETUP, OF(2))      |
        EMIF_FMKS(CECTL, TA, OF(2))           |
        EMIF_FMKS(CECTL, RDSTRB, OF(10))      |
        EMIF_FMKS(CECTL, MTYPE, ASYNC32)      |
        EMIF_FMKS(CECTL, RDHLD, OF(2)),

        EMIF_FMKS(CECTL, WRSETUP, OF(2))      |
        EMIF_FMKS(CECTL, WRSTRB, OF(10))      |
        EMIF_FMKS(CECTL, WRHLD, OF(2))        |
        EMIF_FMKS(CECTL, RDSETUP, OF(2))      |
        EMIF_FMKS(CECTL, TA, OF(2))           |
        EMIF_FMKS(CECTL, RDSTRB, OF(10))      |
        EMIF_FMKS(CECTL, MTYPE, ASYNC32)      |
        EMIF_FMKS(CECTL, RDHLD, OF(2)),

        EMIF_FMKS(SDCTL, SDBSZ, 4BANKS)       |
        EMIF_FMKS(SDCTL, SDRSZ, 12ROW)        |
        EMIF_FMKS(SDCTL, SDCSZ, 8COL)         |
        EMIF_FMKS(SDCTL, RFEN, ENABLE)        |
        EMIF_FMKS(SDCTL, INIT, YES)           |
        EMIF_FMKS(SDCTL, TRCD, OF(1))         |
        EMIF_FMKS(SDCTL, TRP, OF(1))          |
        EMIF_FMKS(SDCTL, TRC, OF(5)),

        EMIF_FMKS(SDTIM, CNTR, OF(0))         |
        EMIF_FMKS(SDTIM, PERIOD, OF(1400)),

        EMIF_FMKS(SDEXT, WR2RD, OF(0))        |
        EMIF_FMKS(SDEXT, WR2DEAC, OF(2))      |
        EMIF_FMKS(SDEXT, WR2WR, OF(1))        |
        EMIF_FMKS(SDEXT, R2WDQM, OF(1))       |
        EMIF_FMKS(SDEXT, RD2WR, OF(0))        |
        EMIF_FMKS(SDEXT, RD2DEAC, OF(1))      |
        EMIF_FMKS(SDEXT, RD2RD, OF(0))        |
        EMIF_FMKS(SDEXT, THZP, OF(2))         |
        EMIF_FMKS(SDEXT, TWR, OF(1))          |
        EMIF_FMKS(SDEXT, TRRD, OF(0))         |
        EMIF_FMKS(SDEXT, TRAS, OF(4))         |
        EMIF_FMKS(SDEXT, TCL, OF(1))
    };

    /*
     *  NOTE:  If running out of SDRAM make sure the SDRAM refresh counter
     *         is set such that it will not miss refreshes when the new
     *         frequency is adopted.
     */

    /* Put PLL in bypass */
    PLL_bypass();
    _plldelay(20);

    /* Reset the PLL */
    PLL_reset();
    _plldelay(20);

    /* Set main multiplier/divisor */
    PLL_RSET(PLLM, 9);                         // 50MHz  x 9 = 450MHz
    PLL_RSET(PLLDIV0, PLL_PLLDIV0_RMK(1, 0));  // 450MHz / 1 = 450MHz
    PLL_RSET(OSCDIV1, PLL_OSCDIV1_RMK(1, 4));  // 50MHz  / 5 = 10Mhz

    /* Set DSP clock */
    PLL_RSET(PLLDIV1, PLL_PLLDIV1_RMK(1, 1));  // 450MHz / 2 = 225MHz
    _plldelay(20);

    /* Set peripheral clock */
    PLL_RSET(PLLDIV2, PLL_PLLDIV2_RMK(1, 3));  // 450MHz / 4 = 112.5MHz
    _plldelay(20);

    /* Set EMIF clock */
    PLL_RSET(PLLDIV3, PLL_PLLDIV3_RMK(1, 4));  // 450MHz / 5 = 90MHz
    _plldelay(20);

    /* Take PLL out of reset */
    PLL_deassert();
    _plldelay(1500);

    /* Enable PLL */
    PLL_enable();
    _plldelay(20);

    /* Initialize EMIF CE1 first to access CPLD */
    EMIF_RSET(GBLCTL, emifCfg0.gblctl);
    EMIF_RSET(CECTL1, emifCfg0.cectl1);

    /* Configure for 8Mb or 16Mb based on DSK version */
    if (DSK6713_getVersion() == 1)
    {
        /* Set SDRSZ field of SDCTL to binary 00 (11ROW) */
        emifCfg0.sdctl = emifCfg0.sdctl & 0xcfffffff;
    } else
    {
        /* Set SDRSZ field of SDCTL to binary 01 (12ROW) */
        emifCfg0.sdctl = (emifCfg0.sdctl & 0xcfffffff) | 0x10000000;
    }

    /* Initialize all of the EMIF */
    EMIF_config(&emifCfg0);

    /* Set CPLD registers to default state */
    DSK6713_rset(DSK6713_USER_REG, 0);
    DSK6713_rset(DSK6713_DC_REG,   0);
    DSK6713_rset(DSK6713_MISC,     0);
}

/* Read an 8-bit value from a CPLD register */
Uint8 DSK6713_rget(Int16 regnum)
{
    Uint8 *pdata;

    /* Return lower 8 bits of register */
    pdata = (Uint8 *)(DSK6713_CPLD_BASE + regnum);
    return (*pdata & 0xff);
}

/* Write an 8-bit value to a CPLD register */
void DSK6713_rset(Int16 regnum, Uint8 regval)
{
    Uint8 *pdata;

    /* Write lower 8 bits of register */
    pdata = (Uint8 *)(DSK6713_CPLD_BASE + regnum);
    *pdata = (regval & 0xff);
}

/* Spin in a delay loop for delay iterations */
void DSK6713_wait(Uint32 delay)
{
    volatile Uint32 i, n;

    n = 0;
    for (i = 0; i < delay; i++)
    {
        n = n + 1;
    }
}

/* Spin in a delay loop for delay microseconds */
void DSK6713_waitusec(Uint32 delay)
{
    DSK6713_wait(delay * 11);
}

/* Get the DSK version */
Int16 DSK6713_getVersion()
{
    DSK6713_version = 1;

    /* Check board revision */
    if ((DSK6713_rget(DSK6713_VERSION) & 0x7) <= 1)
        DSK6713_version = 1;
    else
        DSK6713_version = 2;

    return DSK6713_version;
}
