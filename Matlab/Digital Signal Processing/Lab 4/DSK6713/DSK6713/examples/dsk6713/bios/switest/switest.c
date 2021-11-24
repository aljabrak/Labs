/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.90.270 01-08-04 (bios,dsk6713-c04)" */
/*
 *  ======== switest.c =======
 *
 */

#include <std.h>

#include <log.h>
#include <swi.h>
#include <sys.h>

#include "switestcfg.h"

Void swiFxn0(Void);
Void swiFxn1(Void);

/*
 *  ======== main ========
 */
Void main(Int argc, Char *argv[])
{
    LOG_printf(&trace,"switest started!\n");    
    LOG_printf(&trace,"Main posts SWI0\n");
    SWI_post(&SWI0);
        LOG_printf(&trace,"Main done!\n");
}

/*
 *  ======== swiFxn0 ========
 */
Void swiFxn0(Void)
{
    LOG_printf(&trace,"swiFxn0 posts SWI1\n");  
        SWI_post(&SWI1);
        LOG_printf(&trace,"SWI0 done!\n");
}

/*
 *  ======== swiFxn1 ========
 */
Void swiFxn1(Void)
{
        LOG_printf(&trace,"SWI1 done!\n");
}

