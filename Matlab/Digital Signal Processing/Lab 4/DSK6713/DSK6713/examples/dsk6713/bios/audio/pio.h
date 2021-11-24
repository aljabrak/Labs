/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DDK 1.11.00.00 11-04-03 (ddk-b13)" */

/*
 *  ======== pio.h ========
 * 
 *  Header file for pio.c, which allows a PIP to interface to an
 *  IOM. As implemented only one IOM driver may be used, and may only be
 *  used with a single input and single output channel. You may modify
 *  this code to enable more channels and drivers.
 *
 *  See the comments below for how to configure a DSP/BIOS application
 *  which uses this code.
 */

#ifndef PIO_
#define PIO_

#include <pip.h>
#include <que.h>

#include <iom.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PIO_MAXPACKETS  2

typedef struct PIO_Attrs {
    Ptr openArgs;
} PIO_Attrs;

extern PIO_Attrs PIO_ATTRS;     // default PIO_Attrs structure

typedef struct PIO_Obj
{
    Uns         submitCount;    // keep track of frames submitted

    IOM_Fxns    *fxns;          // pointer to mini-driver function table
    Uns         mode;           // IOM_INPUT, IOM_OUTPUT or IOM_INOUT

    PIP_Curdesc *curdesc;       // used to access pipe on submit side
    PIP_Handle  pip;            // pointer to associated pipe

    Ptr         mdChan;         // pointer to mini-driver state object

    QUE_Obj     freeList;       
    IOM_Packet  packet[PIO_MAXPACKETS]; // available frames for I/O operations

} PIO_Obj, *PIO_Handle;

/*
 * PIO_ctrl() passes parameters straight through to the mini-driver
 */
#define PIO_ctrl(pio, cmd, args) \
        (pio)->fxns->mdControlChan((pio)->mdChan, cmd, args)
/*
 *  PIO module initialization   
 */
extern Void PIO_init(Void);

/*
 * PIO_new() must be called to initialize the I/O prior to any
 * transfers occuring. Pass in the pointer to the PIO object and pointer
 * to PIP object to associate with that channel. The last argument is for
 * various attributes including a generic argument to be passed to IOM 
 * create, it may be NULL. You would typically call PIO_new() from main.
 */
extern Void PIO_new(PIO_Handle pio, PIP_Handle pip, String name, Int mode,
                        PIO_Attrs *attrs);

/*
 *  PIO_txPrime should be configured as the reader notify
 *  function for output pipes.
 *  PIO_rxPrime should be configured as the writer notify
 *  function of input pipes.
 */
extern Void PIO_rxPrime(PIO_Handle pio);
extern Void PIO_rxStart (PIO_Handle pio, Uns frameCount);
extern Void PIO_txPrime(PIO_Handle pio);
extern Void PIO_txStart (PIO_Handle pio, Uns frameCount, Uns initialValue);

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* PIO_ */

