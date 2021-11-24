/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.90.270 01-08-04 (bios,dsk6713-c04)" */
/*
 *  ======== siotest3.c ========
 *  In this program a task takes data from a DGN sine device and writes it
 *  to a DGN user device called printData, whose user function is included
 *  at the end of this file. The data exchange between the task and the
 *  devices is done in a device independent fashion using the SIO module APIs.
 *
 *  The streams in this example follow the SIO_ISSUERECLAIM streaming model and
 *  are created using the DSP/BIOS Configuration Tool.
 *
 */

#include <std.h>

#include <log.h>
#include <mem.h>
#include <sio.h>
#include <sys.h>
#include <tsk.h>

#include "siotest3cfg.h"

SIO_Handle input = &inputStream;    /* input stream handle */
SIO_Handle output = &outputStream;  /* output stream handle */
Void doIRstreaming(Arg nloops_arg);         /* function body for streamTask above */

/*
 *  ======== main ========
 */
Void main()
{
    LOG_printf(&trace, "Start SIO example #3");
}

/*
 *  ======== doIRstreaming ========
 */
Void doIRstreaming(Arg nloops_arg)
{
    Ptr    buf, buf0;
    Arg    arg;
    Int    i, nbytes;
    Int    nloops = ArgToInt (nloops_arg);

    if (SIO_staticbuf(input, &buf0) == 0) {
        SYS_abort("Error reading buffer");
    }   

    if (SIO_staticbuf(input, &buf) == 0) {
        SYS_abort("Error reading buffer");
    }   

    /* Issue an empty buffer to the input stream */
    if (SIO_issue(input, buf0, SIO_bufsize(input), NULL) < 0) {
        SYS_abort("Error issuing buffer ");
    }

    for (i = 0; i < nloops; i++) {
        /* Issue an empty buffer to the input stream */
        if (SIO_issue(input, buf, SIO_bufsize(input), NULL) < 0) {
           SYS_abort("Error issuing buffer %d", i);
        }

        /* Reclaim full buffer from the input stream */
        if ((nbytes = SIO_reclaim(input, &buf, &arg)) < 0) {
            SYS_abort("Error reclaiming buffer %d", i);
        }
        /* Issue full buffer to the output stream */    
        if (SIO_issue(output, buf, nbytes, NULL) < 0) {
            SYS_abort("Error issuing buffer %d", i);
        }

        /* Reclaim empty buffer from the output stream to be reused */
        if (SIO_reclaim(output, &buf, &arg) < 0) {
            SYS_abort("Error reclaiming buffer %d", i);
        }       
    }

    if ((nbytes = SIO_reclaim(input, &buf, &arg)) < 0) {
        SYS_abort("Error reclaiming buffer %d", i);
    }
    if (SIO_issue(output, buf, nbytes, NULL) < 0) {
        SYS_abort("Error issuing buffer %d", i);
        }
    if (SIO_reclaim(output, &buf, &arg) < 0) {
        SYS_abort("Error reclaiming buffer %d", i);
    }   
    
    LOG_printf(&trace, "End SIO example #3");
}
