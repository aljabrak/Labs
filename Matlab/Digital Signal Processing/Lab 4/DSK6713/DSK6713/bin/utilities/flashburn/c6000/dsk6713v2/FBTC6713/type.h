/* type.h
 *
 * Copyright (c) 2000 Texas Instruments Incorporated
 *
 *  Originally created by DNA Software,
 *  Modified by Russ Heeschen for the FlashBurn
 *  project.
 */

/*
 * $Log:
 */
 
#if !defined( TYPE__H )
#define       TYPE__H

typedef enum 
{
   FALSE = 0,
   TRUE  = !FALSE
} BOOL;

typedef float f32;

typedef long s32;
typedef unsigned long u32;

typedef short s16;
typedef unsigned short u16;

typedef unsigned char u8;
typedef signed char s8;

#endif

