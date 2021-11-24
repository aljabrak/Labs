/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.90.270 01-08-04 (bios,dsk6713-c04)" */
/* 
 *  ======== tsk_audio.c ========
 * 
 *  This example demonstrates the use of IOM drivers with SIOs and tasks by 
 *  using the DIO class driver with a user defined device mini-driver 
 *  called "codec" and a class driver DIO instance called "dio_codec". This is 
 *  the loopback application where audio is read from an input SIO, then sent 
 *  back via an output SIO.

 *  The following objects need to be created in the DSP/BIOS
 *  configuration for this application:
 *
 *  * A UDEV object, which links in a user device driver. In this
 *    case the UDEV is a codec based IOM device driver.
 *  * A DIO object, which links the UDEV object.
 *  * A TSK object, with the function to run set to the function echo
 *    defined in this file.
 *  * A LOG named trace for debug and status output.
 */

#include <std.h>

#include <log.h>
#include <sys.h>
#include <mem.h>
#include <sio.h>

#ifdef _6x_
extern far LOG_Obj trace;

/* 
 * Buffers placed in external memory are aligned on a 128 bytes boundary.
 * In addition, the buffer should be of a size multiple of 128 bytes for 
 * the cache work optimally on the C6x.
 */
#define BUFLEN 128      /* number of samples in the frame */
#define BUFALIGN 128    /* alignment of buffer to allow use of L2 cache */
#else
extern LOG_Obj trace;
#define BUFLEN 128      /* number of samples in the frame */
#define BUFALIGN 1
#endif

#define BUFSIZE (BUFLEN * sizeof(MdUns)) 

/* inStream and outStream are SIO handles created in main */
SIO_Handle inStream, outStream;

/* Function prototype */
static Void createStreams();
static Void prime();

/*
 * ======== main ========
 */
Void main()
{
    LOG_printf(&trace, "tsk_audio started");
}

/*
 * ======== createStreams ========
 */
static Void createStreams()
{
    SIO_Attrs attrs;
    
    /* align the buffer to allow it to be used with L2 cache */
    attrs = SIO_ATTRS;
    attrs.align = BUFALIGN;
    attrs.model = SIO_ISSUERECLAIM;

    /* open the I/O streams */
    inStream = SIO_create("/dioCodec", SIO_INPUT, BUFSIZE, &attrs);
    if (inStream == NULL) {
        SYS_abort("Create input stream FAILED.");
    }

    outStream = SIO_create("/dioCodec", SIO_OUTPUT, BUFSIZE, &attrs);
    if (outStream == NULL) {
        SYS_abort("Create output stream FAILED.");
    }
}

/*
 * ======== prime ========
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
        SYS_abort("Error issuing buffer to the input stream");
    }
    if (SIO_issue(inStream, buf1, SIO_bufsize(inStream), NULL) != SYS_OK) {
        SYS_abort("Error issuing buffer to the input stream");
    }

    /* Issue the first & second empty buffers to the output stream */
    if (SIO_issue(outStream, buf2, SIO_bufsize(outStream), NULL) != SYS_OK) {
        SYS_abort("Error issuing buffer to the output stream");
    }
    if (SIO_issue(outStream, buf3, SIO_bufsize(outStream), NULL) != SYS_OK) {
        SYS_abort("Error issuing buffer to the output stream");
    }
}

/*
 * ======== echo ========
 * This function copies from the input SIO to the output SIO. You could
 * easily replace the copy function with a signal processing algorithm. 
 */
Void echo()
{
    Int i;
    Int nmadus;         /* number of minimal addressable units */
    MdUns *inbuf, *outbuf;

    /* Call createStream function to create I/O streams */
    createStreams();
    
    /* Call prime function to do priming */
    prime();

    /* Loop forever looping back buffers */
    for (;;) {
        /* Reclaim full buffer from the input stream */
        if ((nmadus = SIO_reclaim(inStream, (Ptr *)&inbuf, NULL)) < 0) {
            SYS_abort("Error reclaiming full buffer from the input stream");
        }

        /* Reclaim empty buffer from the output stream to be reused */
        if (SIO_reclaim(outStream, (Ptr *)&outbuf, NULL) < 0) {
            SYS_abort("Error reclaiming empty buffer from the output stream");
        }

        /* Do the data move. */
        for (i = 0; i < (nmadus / sizeof(short)); i++) {
            outbuf[i] = inbuf[i];
        }

        /* Issue full buffer to the output stream */
        if (SIO_issue(outStream, outbuf, nmadus, NULL) != SYS_OK) {
            SYS_abort("Error issuing full buffer to the output stream");
        }

        /* Issue an empty buffer to the input stream */
        if (SIO_issue(inStream, inbuf, SIO_bufsize(inStream), NULL) != SYS_OK) {
            SYS_abort("Error issuing empty buffer to the input stream");
        }
    }
}

/*
 *  ======== prd10secs ========
 *  prd10secs is configured to be called every 10 seconds
 */
Void prd10secs()
{
    static Int seconds = 0;
    static Int minutes = 0;
    static Int hours = 0;

    seconds += 10;

    if (seconds == 60) {
        seconds = 0;
        minutes++;
        if (minutes == 60) {
            minutes = 0;
            hours++;
        }
        LOG_printf(&trace, "%d hours and %d minutes", hours, minutes);
    }
    else {
        LOG_printf(&trace, "%d seconds", seconds);
    }
}

