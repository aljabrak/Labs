/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.90.270 01-08-04 (bios,dsk6713-c04)" */
/*
 *  ======== siotest2.c ========
 *  In this program a task takes data from a DGN sine device and writes it
 *  to a DGN user device called printData, whose user function is included
 *  at the end of this file. The data exchange between the task and the
 *  devices is done in a device independent fashion using the SIO module APIs.
 *
 *  The streams in this example follow the SIO_STANDARD streaming model and
 *  are created using the DSP/BIOS Configuration Tool.
 *
 */

#include <std.h>

#include <log.h>
#include <sio.h>
#include <sys.h>
#include <tsk.h>

#include "siotest2cfg.h"


SIO_Handle input = &inputStream;    /* input stream handle */
SIO_Handle output = &outputStream;  /* output stream handle */
Void doStreaming(Arg nloops_arg);    /* function body for streamTask thread */

/*
 *  ======== main ========
 */
Void main()
{
    LOG_printf(&trace, "Start SIO example #2");
}

/*
 *  ======== doStreaming ========
 *  This function forms the body of the TSK thread streamTask which
 *  is created by the configuration tool.
 */
Void doStreaming(Arg nloops_arg)
{
    Int i, nbytes;
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
        if (SIO_put(output, (Ptr *)&buf, nbytes) < 0) {
            SYS_abort("Error writing buffer %d", i);
        }
    }
    LOG_printf(&trace, "End SIO example #2");
}
