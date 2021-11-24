/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.90.270 01-08-04 (bios,dsk6713-c04)" */
#ifndef __TARGET_H
#define __TARGET_H

#ifdef _62_
extern cregister volatile unsigned int IER;
extern cregister volatile unsigned int ISR;
extern cregister volatile unsigned int CSR;

#define NMIE_BIT    0x00000002
#define TARGET_INITIALIZE() \
    IER |= 0x00000001 | NMIE_BIT; \
    CSR |= 0x00000001;
#endif // _62_

#ifdef _64_
#define IER_NMIE	0x00000002
#define CSR_GIE     0x00000001
#define TARGET_INITIALIZE() \
	IER |= 0x00000001 | IER_NMIE; \
	CSR |= CSR_GIE;
#endif // _64_

#ifdef _67_
extern cregister volatile unsigned int IER;
extern cregister volatile unsigned int ISR;
extern cregister volatile unsigned int CSR;

#define NMIE_BIT    0x00000002
#define TARGET_INITIALIZE() \
    IER |= 0x00000001 | NMIE_BIT; \
    CSR |= 0x00000001;
#endif // _67_


#ifdef _54_
#define TARGET_INITIALIZE()
#endif // _54_

#ifdef _55_
#define TARGET_INITIALIZE() \
    asm("    .if(.MNEMONIC)"); \
    asm("        BCLR   ST1_INTM,ST1_55"); \
    asm("    .else"); \
    asm("        BIT (ST1, #ST1_INTM) = #0"); \
    asm("    .endif"); 
#endif // _55_

#endif // __TARGET_H
