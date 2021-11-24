/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.90.270 01-08-04 (bios,dsk6713-c04)" */
/*
 *  ======== siotest4.c ========
 *  In this program two tasks are created that exchange data through a pipe
 *  device. The source task reads sine wave data from a DGN device through
 *  a DTR device stacked on the sine device, and then writes it to a pipe
 *  device. The sink task reads the data from the pipe device and writes it
 *  to the printData DGN device. The data exchange between the tasks and
 *  the devices is done in a device independent fashion using the SIO module
 *  APIs.
 *
 *  The streams in this example follow the SIO_STANDARD streaming model and
 *  are created dynamically with SIO_create().
 *
 */

#include <std.h>

#include <dtr.h>
#include <log.h>
#include <mem.h>
#include <sio.h>
#include <sys.h>
#include <tsk.h>

#include "siotest4cfg.h"

#ifdef _62_
#define BUFSIZE 128
#endif

#ifdef _67_
#define BUFSIZE 128
#endif

#ifdef _54_
#define BUFSIZE 64 
#endif

#ifdef _55_
#define BUFSIZE 64
#endif

#ifdef _28_
#define BUFSIZE 64
#endif

/* Parameters for the stacking device  "/scale" */
DTR_Params DTR_PRMS = {
    10,   /* Scaling factor */
    NULL,
    NULL
};

Void source(Arg nloops_arg);    /* function body for sourceTask above */
Void sink(Arg nloops_arg);              /* function body for sinkTask above */

static Void doStreaming(SIO_Handle input, SIO_Handle output, Uns nloops);

/*
 *  ======== main ========
 */
Void main()
{
    LOG_printf(&trace, "Start SIO example #4");
}

/*
 *  ======== source ========
 *  This function forms the body of the sourceTask TSK thread.
 */
Void source(Arg nloops_arg)
{
    Int nloops = ArgToInt (nloops_arg);

    SIO_Handle input;
    SIO_Handle output;
    
    input = SIO_create("/scale/sineWave", SIO_INPUT, BUFSIZE, NULL);
    if (input == NULL) {
        SYS_abort("Could not create input stream");
    }

    output = SIO_create("/pipe0", SIO_OUTPUT, BUFSIZE, NULL);
    if (output == NULL) {
        SYS_abort("Could not create output stream");
    }

    /* Do I/O */
    doStreaming(input, output, nloops);
}

/*
 *  ======== sink ========
 *  This function forms the body of the sinkTask TSK thread.
 */
Void sink(Arg nloops_arg)
{
    Int nloops = ArgToInt (nloops_arg);

    SIO_Handle input;
    SIO_Handle output;
    
    input = SIO_create("/pipe0", SIO_INPUT, BUFSIZE, NULL);
    if (input == NULL) {
        SYS_abort("Could not create input stream");
    }

    output = SIO_create("/printData", SIO_OUTPUT, BUFSIZE, NULL);
    if (output == NULL) {
        SYS_abort("Could not create output stream");
    }

    /* Do I/O */
    doStreaming(input, output, nloops);

    LOG_printf(&trace, "End SIO example #4");
}

/*
 *  ======== doStreaming ========
 *  I/O function for the sink and source tasks.
 */
static Void doStreaming(SIO_Handle input, SIO_Handle output, Uns nloops)
{
    Ptr    buf;
    Int    i, nbytes;
    
    buf = MEM_alloc(SIO_segid(input), SIO_bufsize(input), 0);
    if (buf == MEM_ILLEGAL) {
        SYS_abort("Memory allocation error");
    }
    
    for (i = 0; i < nloops; i++) {
        if ((nbytes = SIO_get(input, &buf)) < 0) {
            SYS_abort("Error reading buffer %d", i);
        }
        if (SIO_put(output, &buf, nbytes) < 0) {
            SYS_abort("Error writing buffer %d", i);
        }
    }
    
    MEM_free(SIO_segid(input), buf, SIO_bufsize(input));
}
