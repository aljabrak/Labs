/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.90.270 01-08-04 (bios,dsk6713-c04)" */
/*
 *  ======== copy.c ========
 */

#include <std.h>

#include <hst.h>
#include <pip.h>
#include <swi.h>
#include <log.h>

#include "copycfg.h"

Void inputReady(Void);
Void outputReady(Void);

static Void error(Void);    /* called if an error occurs */

/*
 *  ======== main ========
 */
Void main(Int argc, String argv[])
{

    LOG_printf(&trace, "Copy example started.");

    /* fall into BIOS idle loop */
    return;                 
}

/*
 *  ======== copy ========
 */
Void copy(HST_Obj *input, HST_Obj *output)
{
    PIP_Obj     *in, *out;
    Uns         *src, *dst;
    Uns         size;
    
    in = HST_getpipe(input);
    out = HST_getpipe(output);

    if (PIP_getReaderNumFrames(in) == 0 || PIP_getWriterNumFrames(out) == 0) {
        error();
    }

    /* get input data and allocate output buffer */
    PIP_get(in);
    PIP_alloc(out);

    /* copy input data to output buffer */
    src = PIP_getReaderAddr(in);
    dst = PIP_getWriterAddr(out);

    size = PIP_getReaderSize(in);
    PIP_setWriterSize(out, size);

    for (; size > 0; size--) {
        *dst++ = *src++;
    }

    /* output copied data and free input buffer */
    PIP_put(out);
    PIP_free(in);
}

/*
 *  ======== error ========
 */
static Void error(Void)
{
    LOG_printf(&trace, "Error: copy signal falsely triggered!");
    
    for (;;) {
        ;       /* loop for ever */
    }
}

/*
 * ======== inputReady ========
 */
Void inputReady(Void)
{

     SWI_andn(&copySwi, 1); /* clear swi mbx bit position 0 */

}

/*
 * ======== outputReady ========
 */
Void outputReady(Void)
{

     SWI_andn(&copySwi, 2); /* clear swi mbx bit position 1 */

}

