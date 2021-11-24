/*
 * Copyright (c) 2000 Texas Instruments Incorporated
 */

/*
 * $Log: target.h,v $
 * Revision 1.2  2000/12/08 18:37:51  heeschen
 * v0.00002 of FBTC62
 * Updated as a result of code review 12/05/00 on the
 * FBTC54 program. Mainly changed Comm. Protocol
 * and RSX messaging. Also taking posession of type.h
 * and intvecs.asm.
 *
 */

/* This is taken directly from the RTDX tutorials.
 */

#ifndef __TARGET_H
#define __TARGET_H

extern cregister volatile unsigned int IER;
extern cregister volatile unsigned int ISR;
extern cregister volatile unsigned int CSR;

#define NMIE_BIT	0x00000002
#define TARGET_INITIALIZE() \
	IER |= 0x00000001 | NMIE_BIT; \
	CSR |= 0x00000001;

#endif // __TARGET_H
