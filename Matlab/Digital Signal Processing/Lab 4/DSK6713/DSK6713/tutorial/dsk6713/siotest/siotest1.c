/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.90.270 01-08-04 (bios,dsk6713-c04)" */
/*
 *  ======== siotest1.c ========
 *  In this program a task reads data from a DGN sine device and prints the
 *  contents of the data buffers to a log buffer. The data exchange between
 *  the task and the device is done in a device independent fashion using the
 *  SIO module APIs.
 *
 *  The stream in this example follows the SIO_STANDARD streaming model and is
 *  created using the DSP/BIOS Configuration Tool.
 *
 */

#include <std.h>

#include <log.h>
#include <sio.h>
#include <sys.h>
#include <tsk.h>

#include "siotest1cfg.h"


SIO_Handle input = &inputStream;    /* SIO handle used in the example below */

Void doStreaming(Arg nloops_arg);           /* function for streamTask thread */

/*
 *  ======== main ========
 */
Void main()
{
    LOG_printf(&trace, "Start SIO example #1");
}

/*
 *  ======== doStreaming ========
 *  This function is the body of the pre-created TSK thread
 *  streamTask.
 */
Void doStreaming(Arg nloops_arg)
{
    Int i, j, nbytes;
    Int nloops = ArgToInt (nloops_arg);
#if _FLOAT_
    Float *buf;
#else
    Int *buf;
#endif

    if ( SIO_staticbuf(input, (Ptr *)&buf) == 0) {
        SYS_abort("Error reading buffer ");
    }
    
    for (i = 0; i < nloops; i++) {
        if ((nbytes = SIO_get(input, (Ptr *)&buf)) < 0) {
            SYS_abort("Error reading buffer %d", i);
        }
#ifdef _28_
        LOG_printf(&trace, "Read %d bytes\nBuffer %d data:", (Arg)nbytes, (Arg)i);
#else
        LOG_printf(&trace, "Read %d bytes\nBuffer %d data:", nbytes, i);
#endif
        for (j = 0; j < nbytes / sizeof(Int); j++) {
#ifdef _28_    
            LOG_printf(&trace, "%d", (Arg)buf[j]);
#else
            LOG_printf(&trace, "%d", (Int)buf[j]);
#endif
        }
    }   
    LOG_printf(&trace, "End SIO example #1");
}
