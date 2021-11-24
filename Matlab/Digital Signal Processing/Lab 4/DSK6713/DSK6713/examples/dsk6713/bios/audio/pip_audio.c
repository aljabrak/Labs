/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.90.270 01-08-04 (bios,dsk6713-c04)" */
/*
 *  ======== pip_audio.c ========
 *
 *  This example demonstrates the use of IOM drivers with PIPs using 
 *  the PIO adapter with a user defined device mini-driver called
 *  "udevCodec". The application performs a loopback.  That is, audio data is
 *  read from one PIP connected to an input IOM channel, and the data is 
 *  written back out on a PIP connected to an output IOM channel.
 *
 *  The following objects need to be created in the DSP/BIOS
 *  configuration for this application:
 *
 *  * A UDEV object, which links in a user device driver. In this case
 *    the UDEV is a codec based IOM device driver. 
 *
 *  * A SWI object named swiEcho. Configure the function as _echo,
 *    and the mailbox value as 3.
 *
 *  * 2 PIP objects, one named pipTx, the other pipRx. The length of the
 *    buffers should be the same and can be any size. See the comments
 *    by the declarations below of pipTx and pipRx for the writer and
 *    reader notify function settings.
 *
 *  * A LOG object named trace, used for status and debug output. Can be
 *    any size and can be circular or fixed.
 */

#include <std.h>

#include <log.h>
#include <pip.h>
#include <swi.h>
#include <sys.h>

#include <iom.h>
#include <pio.h>

#ifdef _6x_
extern far LOG_Obj trace;
extern far PIP_Obj pipRx; 
extern far PIP_Obj pipTx;
extern far SWI_Obj swiEcho;
#else
extern LOG_Obj trace; 
extern PIP_Obj pipRx;
extern PIP_Obj pipTx;
extern SWI_Obj swiEcho;
#endif

/*
 *  'pioRx' and 'pioTx' objects will be initialized by PIO_new(). 
 */
PIO_Obj pioRx, pioTx;

/*
 *  ======== main ========
 *
 *  Application startup funtion called by DSP/BIOS. Initialize the
 *  PIO adapter then return back into DSP/BIOS.
 */
main()
{
    /*
     * Initialize PIO module
     */
    PIO_init();

    /* Bind the PIPs to the channels using the PIO class drivers */
    PIO_new(&pioRx, &pipRx, "/udevCodec", IOM_INPUT, NULL);
    PIO_new(&pioTx, &pipTx, "/udevCodec", IOM_OUTPUT, NULL);

    /*
     * Prime the transmit side with buffers of silence.
     * The transmitter should be started before the receiver.
     * This results in input-to-output latency being one full
     * buffer period if the pipes is configured for 2 frames.
     */
    PIO_txStart(&pioTx, PIP_getWriterNumFrames(&pipTx), 0);

    /* Prime the receive side with empty buffers to be filled. */
    PIO_rxStart(&pioRx, PIP_getWriterNumFrames(&pipRx));

    LOG_printf(&trace, "pip_audio started");   
}


/*
 *  ======== echo ========
 *
 *  This function is called by the swiEcho DSP/BIOS SWI thread created
 *  statically with the DSP/BIOS configuration tool. The PIO adapter
 *  posts the swi when an the input PIP has a buffer of data and the
 *  output PIP has an empty buffer to put new data into. This function
 *  copies from the input PIP to the output PIP. You could easily
 *  replace the copy function with a signal processing algorithm.
 */
Void echo(Void)
{
    Int i, size;
    unsigned short *src, *dst;

    /*
     * Check that the precondions are met, that is pipRx has a buffer of
     * data and pipTx has a free buffer.
     */
    if (PIP_getReaderNumFrames(&pipRx) <= 0) {
        LOG_error("echo: No reader frame!", 0);
        return;
    }
    if (PIP_getWriterNumFrames(&pipTx) <= 0) {
        LOG_error("echo: No writer frame!", 0);
        return;
    }

    /* get the full buffer from the receive PIP */
    PIP_get(&pipRx);
    src = PIP_getReaderAddr(&pipRx);
    size = PIP_getReaderSize(&pipRx) * sizeof(short);

    /* get the empty buffer from the transmit PIP */
    PIP_alloc(&pipTx);
    dst = PIP_getWriterAddr(&pipTx);

     
    /* Do the data move. */
    for (i = 0; i < size; i++) {
        *dst++ = *src++;
    }     

    /* Record the amount of actual data being sent */
    PIP_setWriterSize(&pipTx, PIP_getReaderSize(&pipRx));

    /* Free the receive buffer, put the transmit buffer */
    PIP_put(&pipTx);
    PIP_free(&pipRx);
}

