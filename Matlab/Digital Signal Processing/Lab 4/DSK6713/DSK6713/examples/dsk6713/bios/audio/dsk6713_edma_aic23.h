/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DDK 1.11.00.00 11-04-03 (ddk-b13)" */
/* 
 *  ======== dsk6713_edma_aic23.h ========
 */

#ifndef DSK6713_EDMA_AIC23_
#define DSK6713_EDMA_AIC23_

#include <iom.h>

#include <aic23.h>

/* Version number definition */
#define DSK6713_EDMA_AIC23_VERSION_1             0xAB01
#define DSK6713_EDMA_AIC23_INTR_MASK_DEFAULT     1
#define DSK6713_EDMA_AIC23_CACHECALLS_DEFAULT    TRUE
#define DSK6713_EDMA_AIC23_IRQID_DEFAULT         8
#define DSK6713_EDMA_AIC23_TDMCHANNELS           2

/* Driver function table to be used by applications */
extern far IOM_Fxns DSK6713_EDMA_AIC23_FXNS;

/* Device setup parameters */
typedef struct DSK6713_EDMA_AIC23_DevParams {
    Int versionId; /* Set to the version number used by the application */
    Bool cacheCalls;             /* Set to TRUE if buffers are in external memory */
    Int irqId;                   /* IRQ number to use for EDMA interrupt */
    AIC23_Params aic23;          /* AIC23 codec parameters (registers) */
    Uns intrMask; /* Interrupt mask, set while executing EDMA int ISR */
    Int edmaPriority;/* priority of EDMA transfers */
} DSK6713_EDMA_AIC23_DevParams;

#define DSK6713_EDMA_AIC23_DEVPARAMS_DEFAULT {   \
    DSK6713_EDMA_AIC23_VERSION_1,                \
    DSK6713_EDMA_AIC23_CACHECALLS_DEFAULT,       \
    DSK6713_EDMA_AIC23_IRQID_DEFAULT,            \
    AIC23_DEFAULTPARAMS,                         \
    DSK6713_EDMA_AIC23_INTR_MASK_DEFAULT,        \
    EDMA_OPT_PRI_HIGH                            \
}

/* Controller init function -- initializes driver variables, if any */
extern Void DSK6713_EDMA_AIC23_init( Void );

#endif /* DSK6713_EDMA_AIC23_ */

