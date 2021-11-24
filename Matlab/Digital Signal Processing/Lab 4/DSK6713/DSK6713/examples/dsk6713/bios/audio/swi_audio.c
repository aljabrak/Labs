/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.90.270 01-08-04 (bios,dsk6713-c04)" */

/* 
 *  ======== swi_audio.c ========
 * 
 *  This example demonstrates the use of IOM drivers with SIOs and SWIs by
 *  using the DIO class driver with a user defined device mini-driver 
 *  called "codec". This is a loopback application where audio is read 
 *  from an input SIO, then sent back via an output SIO. 
 *
 *  The following objects need to be created in the DSP/BIOS
 *  configuration for this application:
 *
 *  * A UDEV object, which links in a user device driver. In this
 *    case the UDEV object is a codec based IOM device driver.
 *  * A DIO object, which links the UDEV object.
 *  * A SWI object, with the function to run set to the function echo
 *    defined in this file.
 *  * A LOG named trace for debug and status output.
 */

#include <std.h>

#include <dev.h>
#include <log.h>
#include <sys.h>
#include <mem.h>
#include <sio.h>
#include <swi.h>

#ifdef _6x_
extern far LOG_Obj trace;
extern far SWI_Obj swiEcho;
/*
 * Buffers placed in external memory ar aligned on a 128 bytes boundary. 
 * In addition, the buffer should be of a size multiple of 128 bytes for the 
 * cache work optimally on the C6x. 
 */
#define BUFLEN 128      /* number of samples in a frame */
#define BUFALIGN 128    /* alignment of buffer to allow use of L2 cache */
#else
extern LOG_Obj trace;
extern SWI_Obj swiEcho;
#define BUFLEN 128      /* number of samples in a frame */
#define BUFALIGN 1
#endif

#define BUFSIZE (BUFLEN * sizeof(MdUns))

/* inStream and outStream are SIO handles created in main */
SIO_Handle inStream, outStream;

/* Function prototype */
static Void createStreams();
static Void prime();

/*
 *  ======== main ========
 */
Void main()
{
    /* Call createStreams function to create I/O streams */
    createStreams();

    /* Call prime function to do buffer priming */
    prime();

    LOG_printf(&trace, "swi_audio started");
}

/* 
 * ======== createStreams ========
 *
 * This function creates the SIO streams to be used by the application 
 */
static Void createStreams()
{
    SIO_Attrs attrs;
    DEV_Callback callback;    /* callback used because SWIs cannot block */
    
    callback.fxn = (Fxn)SWI_andnHook;
    callback.arg0 = (Arg)&swiEcho;
    callback.arg1 = (Arg)0x1; /* This sets the IOM_INPUT mode */

    /* Align the buffer to allow it to be used with L2 cache */
    attrs = SIO_ATTRS;
    attrs.align = BUFALIGN;
    attrs.model = SIO_ISSUERECLAIM;
    attrs.callback = (DEV_Callback *)&callback;

    /* Create the I/O streams */
    inStream = SIO_create("/dioCodec", SIO_INPUT, BUFSIZE, &attrs);
    if (inStream == NULL) {
        SYS_abort("Create input stream  FAILED.");
    }

    callback.arg1 = (Arg)0x2; /* This sets the IOM_OUTPUT mode */
    outStream = SIO_create("/dioCodec", SIO_OUTPUT, BUFSIZE, &attrs);
    if (outStream == NULL) {
        SYS_abort("Create output stream FAILED.");
    }
}

/* 
 * ======== prime ========
 *
 * This function primes the streams with empty buffers so that the 
 * issue/reclaim loop can start in the application's processing thread.
 */
static Void prime()
{
    Ptr buf0, buf1, buf2, buf3;

    LOG_printf(&trace, "Allocate buffers started");

    /* Allocate buffers for the SIO buffer exchanges */
    buf0 = (Ptr)MEM_calloc(0, BUFSIZE, BUFALIGN);
    buf1 = (Ptr)MEM_calloc(0, BUFSIZE, BUFALIGN);
    buf2 = (Ptr)MEM_calloc(0, BUFSIZE, BUFALIGN);
    buf3 = (Ptr)MEM_calloc(0, BUFSIZE, BUFALIGN);
    if (buf0 == NULL || buf1 == NULL || buf2 == NULL || buf3 == NULL) {
        SYS_abort("MEM_calloc failed.");
    } 
    
    /* Issue the first & second empty buffers to the input stream */
    if (SIO_issue(inStream, buf0, SIO_bufsize(inStream), NULL) != SYS_OK) {
        SYS_abort("Error issuing buffer");
    }
    if (SIO_issue(inStream, buf1, SIO_bufsize(inStream), NULL) != SYS_OK) {
        SYS_abort("Error issuing buffer");
    }

    /* Issue the first & second empty buffers to the output stream */
    if (SIO_issue(outStream, buf2, SIO_bufsize(outStream), NULL) != SYS_OK) {
        SYS_abort("Error issuing buffer");
    }
    if (SIO_issue(outStream, buf3, SIO_bufsize(outStream), NULL) != SYS_OK) {
        SYS_abort("Error issuing buffer");
    }
}

/*
 * ======== echo ========
 * This function copies from the input SIO to the output SIO. You could 
 * easily replace the copy function with a signal processing algorithm. 
 */
Void echo()
{
    unsigned short *inbuf, *outbuf;
    Int nbytes, i;
        
    /* Reclaim full buffer from the input stream */
    if ((nbytes = SIO_reclaim(inStream, (Ptr *)&inbuf, NULL)) < 0) {
        SYS_abort("Error reclaiming full buffer from the input stream");
    }

    /* Reclaim empty buffer from the output stream to be reused */
    if (SIO_reclaim(outStream, (Ptr *)&outbuf, NULL) < 0) {
        SYS_abort("Error reclaiming empty buffer from the output stream");
    }
 
    /* Do the data move. */
    for (i = 0; i < (nbytes / sizeof(short)); i++) {
        outbuf[i] = inbuf[i];
    }     
        
    /* Issue full buffer to output stream */
    if (SIO_issue(outStream, outbuf, nbytes, NULL) != SYS_OK) {
        SYS_abort("Error issuing full buffer to output stream");
    }           
     
    /* Issue empty buffer to input stream */
    if (SIO_issue(inStream, inbuf, SIO_bufsize(inStream), NULL) != SYS_OK) {
        SYS_abort("Error issuing empty buffer to input stream");
    }
}      

