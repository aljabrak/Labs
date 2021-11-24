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
/*     DSP program receives digital audio data, adjusts its volume,        */
/*     and produces an output stream at the adjusted volume. Input and     */ 
/*     output data are received/sent from/to host files using RTDX         */
/*     channels.  Volume is controlled using an RTDX channel.              */
/*                                                                         */
/***************************************************************************/

#include <std.h>

#include <log.h>
#include <rtdx.h>

#include "hostiocfg.h"

#include "target.h"

#define BUFSIZE 64
#define MINVOLUME 1

typedef Int sample;     /* representation of a data sample from A2D */

/* Global declarations */
sample inp_buffer[BUFSIZE];
sample out_buffer[BUFSIZE];

Int volume = MINVOLUME; /* the scaling factor for volume control */

/* RTDX channels */
RTDX_CreateInputChannel(control_channel);
RTDX_CreateInputChannel(A2D_channel);
RTDX_CreateOutputChannel(D2A_channel);


/*
 * ======== main ========
 */
Void main()
{
    sample *input = inp_buffer;
    sample *output = out_buffer;
    Uns size = BUFSIZE;      
    
    TARGET_INITIALIZE();        /* Enable RTDX interrupt */
    
    LOG_printf(&trace,"hostio example started");
    
    /* enable volume control input channel */
    RTDX_enableInput(&control_channel); 

    while (TRUE) {
        /* Read a new volume when the hosts send it */
        if (!RTDX_channelBusy(&control_channel)) {
            RTDX_readNB(&control_channel, &volume, sizeof(volume));
        }

        while (!RTDX_isInputEnabled(&A2D_channel)){
#if     RTDX_POLLING_IMPLEMENTATION
            RTDX_Poll();        /* poll comm channel for input*/
#endif
        }

        /*
         *  A2D: get digitized input (get signal from the host through RTDX).
         *  If A2D_channel is enabled, read data from the host.
         */
        RTDX_read(&A2D_channel, input, size*sizeof(sample));

        /*
         *  Vector Scale: Scale the input signal by the volume factor to
         *  produce the output signal.
         */
        while(size--){
            *output++ = *input++ * volume;
        }
        size = BUFSIZE;
        input = inp_buffer;
        output = out_buffer;

        /*
         *  D2A: produce analog output (send signal to the host through RTDX).
         *  If D2A_channel is enabled, write data to the host.
         */
        RTDX_write(&D2A_channel, output, size*sizeof(sample));


        while(RTDX_writing){
#if     RTDX_POLLING_IMPLEMENTATION
            RTDX_Poll();        /* poll comm channel for output */
#endif
        }

    }
}


