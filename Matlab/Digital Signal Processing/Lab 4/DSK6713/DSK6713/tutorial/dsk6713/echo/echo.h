/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.90.270 01-08-04 (bios,dsk6713-c04)" */
/*
 *  ======== echo.h ========
 */

#ifndef ECHO_
#define ECHO_

#define ECHOFRAMELEN    20                  /* 2.5 ms @ 8000 Hz */
#define AUDIOFRAMELEN   9 * ECHOFRAMELEN    /* 22.5 ms @ 8000 Hz */
#define CODEFRAMELEN    AUDIOFRAMELEN / 2   /* 2:1 compression */

#define CODEBUFLEN      2 * CODEFRAMELEN    /* double buffer input/output */
#define AUDIOBUFLEN     2 * AUDIOFRAMELEN   /* double buffer input/output */

#endif	/* ECHO_ */
