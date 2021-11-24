/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_hpi.h
* DATE CREATED.. 09/01/1999 
* LAST MODIFIED. 04/20/2001 (C64x compatibility)
\******************************************************************************/
#ifndef _CSL_HPI_H_
#define _CSL_HPI_H_

#include <csl_chip.h>
#include <csl_irq.h>
#include <csl_hpihal.h>


#if (HPI_SUPPORT)
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

#ifdef  _HPI_MOD_
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
IDECL Uint32 HPI_getEventId();
IDECL Uint32 HPI_getHwob();
IDECL Uint32 HPI_getDspint();
IDECL Uint32 HPI_getHint();
IDECL Uint32 HPI_getHrdy();
IDECL Uint32 HPI_getFetch();
IDECL void   HPI_setDspint(Uint32 val);
IDECL void   HPI_setHint(Uint32 val);

#if (C64_SUPPORT)
IDECL void   HPI_setWriteAddr(Uint32 address);
IDECL Uint32 HPI_getWriteAddr();
IDECL void   HPI_setReadAddr(Uint32 address);
IDECL Uint32 HPI_getReadAddr();
#endif /* C64_SUPPORT */

/******************************************************************************\
* inline function definitions
\******************************************************************************/
#ifdef USEDEFS
/*----------------------------------------------------------------------------*/
IDEF Uint32 HPI_getEventId() {
  return (Uint32)IRQ_EVT_DSPINT;
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 HPI_getHwob() {
  return HPI_FGET(HPIC,HWOB);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 HPI_getDspint() {
  return HPI_FGET(HPIC,DSPINT);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 HPI_getHint() {
  return HPI_FGET(HPIC,HINT);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 HPI_getHrdy() {
  return HPI_FGET(HPIC,HRDY);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 HPI_getFetch() {
  return HPI_FGET(HPIC,FETCH);
}
/*----------------------------------------------------------------------------*/
IDEF void HPI_setDspint(Uint32 val) {
  HPI_FSET(HPIC,DSPINT,val);
}
/*----------------------------------------------------------------------------*/
IDEF void HPI_setHint(Uint32 val) {
  HPI_FSET(HPIC,HINT,val);
}
/*----------------------------------------------------------------------------*/
#if (C64_SUPPORT)

IDEF void   HPI_setWriteAddr(Uint32 address) {
  HPI_FSET(HPIAW,HPIAW,address);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 HPI_getWriteAddr(){
  return ( HPI_FGET(HPIAW,HPIAW));
}
/*----------------------------------------------------------------------------*/
IDEF void   HPI_setReadAddr(Uint32 address) {
  HPI_FSET(HPIAR,HPIAR,address);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 HPI_getReadAddr(){
  return ( HPI_FGET(HPIAR,HPIAR));
}
/*----------------------------------------------------------------------------*/
#endif /* C64_SUPPORT */

#endif /* USEDEFS */


#endif /* HPI_SUPPORT */
#endif /* _CSL_HPI_H_ */
/******************************************************************************\
* End of csl_hpi.h
\******************************************************************************/

