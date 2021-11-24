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
/*     H O S T I O . C                                                     */
/*                                                                         */
/*     DSP system that digitizes an audio signal, adjusts its volume,      */
/*     and produces an analog output at the adjusted volume. Input and     */ 
/*     output data are received/sent from/to host files using HST          */
/*     channels.                                                           */
/*                                                                         */
/***************************************************************************/

#include <std.h>

#include <log.h>
#include <rtdx.h>
#include <hst.h>
#include <pip.h>
#include <swi.h>

#include "hostiocfg.h"

#define MINVOLUME 1


typedef Int sample;     /* representation of a data sample from A2D */

Int volume = MINVOLUME; /* the scaling factor for volume control */

/*
 * RTDX channel
 *
 * NOTE: This is a C macro that initializes an RTDX channel structure.
 */
RTDX_CreateInputChannel(control_channel);

/* Functions */
Void A2DscaleD2A(HST_Obj *inpChannel, HST_Obj *putChannel);
static Void error(Void);


/*
 * ======== main ========
 */
Void main()
{
    LOG_printf(&trace,"hostio example started");
    
    /* enable volume control input channel */
    RTDX_enableInput(&control_channel); 
}

/*
 *  ======== A2DscaleD2A ========
 *
 * FUNCTION: Called from A2DscaleD2A_SWI to get digitized data from
 *           a host file through an HST input channel, scale the data by the
 *           volume factor, and send output data back to the host through an
 *           HST output channel.
 *
 * PARAMETERS: address of input and output HST channels.
 *
 * RETURN VALUE: None.
 */
Void A2DscaleD2A(HST_Obj *inpChannel, HST_Obj *outChannel)
{
    PIP_Obj *inp_PIP;
    PIP_Obj *out_PIP;
    sample *input;
    sample *output;
    Uns size;

    inp_PIP = HST_getpipe(inpChannel);
    out_PIP = HST_getpipe(outChannel);

    if ((PIP_getReaderNumFrames(inp_PIP) <= 0) || (PIP_getWriterNumFrames(out_PIP) <= 0)) {
            /* Software interrupt should not have been triggered!  */
            error();
    }

    /* Read a new volume when the hosts send it */
    if (!RTDX_channelBusy(&control_channel)) {
        RTDX_readNB(&control_channel, &volume, sizeof(volume));
    }

    /*
     *  A2D: get digitized input (get signal from the host through HST).
     *  Obtain input frame and allocate output frame from the host pipes.
     */
    
    PIP_get(inp_PIP);
    PIP_alloc(out_PIP);
    
    input = PIP_getReaderAddr(inp_PIP);
    output = PIP_getWriterAddr(out_PIP);

    size = PIP_getReaderSize(inp_PIP);
    PIP_setWriterSize(out_PIP, size);
    
    /*
     *  Vector Scale: Scale the input signal by the volume factor to
     *  produce the output signal.
     */
    while(size--){
            *output++ = *input++ * volume;
    }
    
    /*
     *  D2A: produce analog output (send signal to the host through HST).
     *  Send output data to the host pipe and free the frame from the input
     *  pipe.
     */
    PIP_put(out_PIP);
    PIP_free(inp_PIP);
}

/*
 *  ======== error ========
 *
 * FUNCTION: Traps processor in loop forever if error condition occurs.
 *
 * PARAMETERS: None.
 *
 * RETURN VALUE: None.
 */
static Void error(Void)
{
    LOG_printf(&trace,"Error condition!");
    for ( ; ; ) {
        ;
    }
}

