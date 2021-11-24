/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_stdinc.h
* DATE CREATED.. 03/11/1999 
* LAST MODIFIED. 10/03/2000
\******************************************************************************/
#ifndef _CSL_STDINC_H_
#define _CSL_STDINC_H_

#include <csl_stdinchal.h>


/******************************************************************************\
* macro declarations
\******************************************************************************/

/* a few standard constants */
#ifndef TRUE
  #define TRUE   1
#endif
#ifndef FALSE
  #define FALSE  0
#endif

/* Invalid Pointer                                               */
/* In many instances, it is better to use INV as opposed to NULL */
/* because 0 may actually be a valid pointer                     */
#ifndef INV
  #define INV    ((void*)(-1))
#endif

#ifndef UNREFERENCED_PARAMETER
  #define UNREFERENCED_PARAMETER(P)    ((P)=(P))
#endif

#ifndef REG32
  #define REG32(addr) (*(volatile unsigned int*)(addr))
  #define REG16(addr) (*(volatile unsigned short*)(addr))
  #define REG8(addr)  (*(volatile unsigned char*)(addr))
#endif

/******************************************************************************\
* typedef declarations
\******************************************************************************/
typedef unsigned char    Uint8;
typedef unsigned short   Uint16;
typedef unsigned int     Uint32;
typedef unsigned long    Uint40;
typedef char             Int8;
typedef short            Int16;
typedef int              Int32;
typedef long             Int40;

/******************************************************************************\
* variable declarations
\******************************************************************************/


/******************************************************************************\
* function declarations
\******************************************************************************/


#endif /* _CSL_STDINC_H_ */
/******************************************************************************\
* End of csl_stdinc.h
\******************************************************************************/

