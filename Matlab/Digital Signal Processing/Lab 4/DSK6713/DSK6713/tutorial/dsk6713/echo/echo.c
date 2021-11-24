/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.90.270 01-08-04 (bios,dsk6713-c04)" */
/*
 *  ======== echo.c ========
 */

#include <std.h>

#include <log.h>
#include <swi.h>

#include "echocfg.h"

#include "echo.h"

/* Global declarations */
int cancelerLoad = 0;
int decoderLoad = 0;
int encoderLoad = 0;

int echoInFrame  = 0;           /* current input echo frame number */
int echoOutFrame = 2;           /* current output echo frame number */
int encoderFrame  = 0;          /* current input audio frame number */
int decoderFrame  = 0;          /* current output audio frame number */

int audioInBuf[AUDIOBUFLEN];    /* audio input data */
int audioOutBuf[AUDIOBUFLEN];   /* audio output data */
int codeInBuf[CODEBUFLEN];      /* encoded input data */
int codeOutBuf[CODEBUFLEN];     /* encoded output data */

/* Functions */
extern Void ECHO_load(int load);

static Void cancelerAlg(int *input, int *output);
static Void decoderAlg(int *input, int *output);
static Void encoderAlg(int *input, int *output);

/*
 *  ======== main ========
 */
Void main(int argc, char *argv[])
{
    /* Does Nothing */
}

/*
 *  ======== canceler ========
 *  Modify the audio output data based on the most recent input audio
 *  data to eliminate echo feedback.
 */
Void canceler(Void)
{
    int *src, *dst;
    
    /* get last 2.5 ms of input audio data and next 2.5 ms of output data */
    src = audioInBuf + (echoInFrame * ECHOFRAMELEN);
    dst = audioOutBuf + (echoOutFrame * ECHOFRAMELEN);
    
    /* suppress output as necessary to prevent echo feedback */
    cancelerAlg(src, dst);

    /* update echoInFrame and echoOutFrame index */
    if (++echoInFrame >= (AUDIOBUFLEN / ECHOFRAMELEN)) {
        echoInFrame = 0;
    }
    if (++echoOutFrame >= (AUDIOBUFLEN / ECHOFRAMELEN)) {
        echoOutFrame = 0;
    }
}

/*
 *  ======== decoder ========
 *  Convert encoded data into output PCM audio data; i.e., transform 
 *  codeInBuf[] into audioOutBuf[].
 */
Void decoder(Void)
{
    int *src, *dst;

    /* get pointers to next frames of input coded data and output audio */
    src = codeInBuf + (decoderFrame * CODEFRAMELEN);
    dst = audioOutBuf + (decoderFrame * AUDIOFRAMELEN);

    /* decoder data in src and put resulting audio data in dst */
    decoderAlg(src, dst);

    /* update decoderFrame index */
    if (++decoderFrame >= (AUDIOBUFLEN / AUDIOFRAMELEN)) {
        decoderFrame = 0;
    }
}

/*
 *  ======== encoder ========
 *  Convert input audio data to encoded (i.e., compressed) data; i.e., 
 *  transform audioInBuf[] into codeOutBuf[].
 */
Void encoder(Void)
{
    int *src, *dst;
    
    /* get next N ms of input audio data and write next N ms of coded data */
    src = audioInBuf + (encoderFrame * AUDIOFRAMELEN);
    dst = codeOutBuf + (encoderFrame * CODEFRAMELEN);

    /* encoder input audio data in src and put result in dst */
    encoderAlg(src, dst);

    /* update encoderFrame index */
    if (++encoderFrame >= (AUDIOBUFLEN / AUDIOFRAMELEN)) {
        encoderFrame = 0;
    }
}

/*
 *  ======== cancelerAlg ========
 */
static Void cancelerAlg(int *input, int *output)
{
    static int oldLoad = 0;
    
    /* display confirmation of load change */
    if (oldLoad != cancelerLoad) {
        oldLoad = cancelerLoad;
        LOG_printf(&trace,
            "Cancel: new load = %d000 instructions every 2.5 ms", cancelerLoad);
    }
    
    if (cancelerLoad) {
        ECHO_load(cancelerLoad);
    }
}

/*
 *  ======== decoderAlg ========
 */
static Void decoderAlg(int *input, int *output)
{
    static int oldLoad = 0;
    
    /* display confirmation of load change */
    if (oldLoad != decoderLoad) {
        oldLoad = decoderLoad;
        LOG_printf(&trace,
            "Decode: new load = %d000 instructions every 22.5 ms", decoderLoad);
    }
    
    if (decoderLoad) {
        ECHO_load(decoderLoad);
    }
}

/*
 *  ======== encoderAlg ========
 */
static Void encoderAlg(int *input, int *output)
{
    static int oldLoad = 0;
    
    /* display confirmation of load change */
    if (oldLoad != encoderLoad) {
        oldLoad = encoderLoad;
        LOG_printf(&trace,
            "Encode: new load = %d000 instructions every 22.5 ms", encoderLoad);
    }
    
    if (encoderLoad) {
        ECHO_load(encoderLoad);
    }
}
