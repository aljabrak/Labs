/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.90.270 01-08-04 (bios,dsk6713-c04)" */
/*
 *  ======== dgn_print.c ========
 *
 */

#include <std.h>

#include <log.h>

/*
 *  ======== DGN_print2log ========
 *  User function for the DGN user device printData. It takes as an argument
 *  the address of the LOG object where the data stream should be printed.
 */
Void DGN_print2log(Arg arg, Ptr addr, Uns nbytes)
{
    Int      i;
#if _FLOAT_
    Float     *buf = (Float *)addr;
#else
    Int      *buf = (Int *)addr;
#endif

    for (i = 0; i < nbytes / sizeof(Int); i++) {
        LOG_printf((LOG_Obj *)arg, "%d", (Int)buf[i]);
    }
}
