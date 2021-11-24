/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_vic.h
* DATE CREATED.. 02/21/2002 
* LAST MODIFIED. 
\******************************************************************************/
#ifndef _CSL_VIC_H_
#define _CSL_VIC_H_

#include <csl_chip.h>
#include <csl_vichal.h>


#if (VIC_SUPPORT)
/******************************************************************************\
* scope and inline control macros
\******************************************************************************/
#ifdef __cplusplus
#define CSLAPI extern "C" far
#else
#define CSLAPI extern far
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _VIC_MOD_
  #define IDECL CSLAPI
  #define USEDEFS
  #define IDEF
#else
  #ifdef  _INLINE
    #define IDECL static inline
    #define USEDEFS
    #define IDEF  static inline
  #else
    #define IDECL CSLAPI
  #endif
#endif


/******************************************************************************\
* global macro declarations
\******************************************************************************/


/******************************************************************************\
* global typedef declarations
\******************************************************************************/


/******************************************************************************\
* global variable declarations
\******************************************************************************/


/******************************************************************************\
* global function declarations
\******************************************************************************/


/******************************************************************************\
* inline function declarations
\******************************************************************************/
IDECL Uint32 VIC_getPrecision();
IDECL Uint32 VIC_getGo();
IDECL Uint32 VIC_getInputBits();
IDECL Uint32 VIC_getClkDivider();
IDECL void VIC_setPrecision(Uint32 val);
IDECL void VIC_setGo(Uint32 val);
IDECL void VIC_setInputBits(Uint32 val);
IDECL void VIC_setClkDivider(Uint32 val);

/******************************************************************************\
* inline function definitions
\******************************************************************************/
#ifdef USEDEFS
/*----------------------------------------------------------------------------*/
IDEF Uint32 VIC_getPrecision() {
  return VIC_FGET(VICCTL,PRECISION);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 VIC_getGo() {
  return VIC_FGET(VICCTL,GO);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 VIC_getInputBits() {
  return VIC_FGET(VICIN,VICINBITS);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 VIC_getClkDivider() {
  return VIC_FGET(VICDIV,VICCLKDIV);
}
/*----------------------------------------------------------------------------*/
IDEF void VIC_setPrecision(Uint32 val) {
  VIC_FSET(VICCTL,PRECISION,val);
}
/*----------------------------------------------------------------------------*/
IDEF void VIC_setGo(Uint32 val) {
  VIC_FSET(VICCTL,GO,val);
}
/*----------------------------------------------------------------------------*/
IDEF void VIC_setInputBits(Uint32 val) {
  VIC_FSET(VICIN,VICINBITS,val);
}
/*----------------------------------------------------------------------------*/
IDEF void VIC_setClkDivider(Uint32 val) {
  VIC_FSET(VICDIV,VICCLKDIV,val);
}
/*----------------------------------------------------------------------------*/
#endif /* USEDEFS */


#endif /* VIC_SUPPORT */
#endif /* _CSL_VIC_H_ */
/******************************************************************************\
* End of csl_vic.h
\******************************************************************************/

