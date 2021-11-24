/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.90.270 01-08-04 (bios,dsk6713-c04)" */
/***************************************************************************/
/*                                                                         */
/*     V O L U M E . C                                                     */
/*                                                                         */
/*     Audio gain processing using CLK ISR as data source, and a software  */
/*     interrupt for processing routine.                                   */
/*                                                                         */
/***************************************************************************/

#include <std.h>

#include <log.h>
#include <swi.h>

#include "volumecfg.h"

#include "volume.h"

/* Global declarations */
Int inp_buffer[BUFSIZE];       /* processing data buffers */
Int out_buffer[BUFSIZE];

Int gain = MINGAIN;             /* volume control variable */
Uns processingLoad = BASELOAD;  /* processing routine load value */

/* Functions */
extern Void load(Uns loadValue);

Int processing(Int *input, Int *output);
Void dataIO(Void);


/*
 * ======== main ========
 */
Void main()
{
    LOG_printf(&trace,"volume example started\n");

    /* fall into DSP/BIOS idle loop */
    return;
}

/*
 *  ======== processing ========
 *
 * FUNCTION: Called from processing_SWI to apply signal processing
 *           transform to input signal.
 *
 * PARAMETERS: address of input and output buffers.
 *
 * RETURN VALUE: TRUE.
 */
Int processing(Int *input, Int *output)
{
    Int size = BUFSIZE;

    while(size--){
        *output++ = *input++ * gain;
    }

    /* additional processing load */
    load(processingLoad);
    
    return(TRUE);
}

/*
 *  ======== dataIO ========
 *
 * FUNCTION: Called from timer ISR to fake a periodic hardware interrupt that
 *           reads in the input signal and outputs the processed signal.
 *
 * PARAMETERS: none.
 *
 * RETURN VALUE: none.
 */
Void dataIO()
{
    /* do data I/O */
    
    SWI_dec(&processing_SWI);   /* post processing_SWI software interrupt */   
}

