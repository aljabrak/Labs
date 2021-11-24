/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_timer.h
* DATE CREATED.. 06/20/1999 
* LAST MODIFIED. 07/24/2004   Re-introduced BIOS dependency due to compatibilty issues
*                02/09/2004   Removed bios related items 
*                10/03/2000
\******************************************************************************/
#ifndef _CSL_TIMER_H_
#define _CSL_TIMER_H_

#include <csl_chip.h> 
#include <csl_irq.h>
#include <csl_timerhal.h>


#if (TIMER_SUPPORT)
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

#ifdef  _TIMER_MOD_
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

/* TIMER_open() flags */
#define TIMER_OPEN_RESET     (0x00000001)

/* device identifiers for TIMER_open() */
#define TIMER_DEVANY  (-1)
#define TIMER_DEV0    (0)
#define TIMER_DEV1    (1)
#if (TIMER_DEVICE_CNT > 2)
  #define TIMER_DEV2    (2)
#endif


/******************************************************************************\
* global typedef declarations
\******************************************************************************/

/* handle structure */
typedef struct {
  Uint32 allocated;
  Uint32 eventId;
  volatile Uint32 *baseAddr;
} TIMER_Obj, *TIMER_Handle;

/* device configuration structure */
typedef struct {
  Uint32 ctl;
  Uint32 prd;
  Uint32 cnt;
} TIMER_Config;


/******************************************************************************\
* global variable declarations
\******************************************************************************/

/* predefined deviced handles for legacy - should not be used */
extern far TIMER_Handle _TIMER_hDev0;
extern far TIMER_Handle _TIMER_hDev1;
extern far TIMER_Handle _TIMER_hBios;


/******************************************************************************\
* global function declarations
\******************************************************************************/
CSLAPI TIMER_Handle TIMER_getBiosHandle(); 

CSLAPI void TIMER_reset(TIMER_Handle hTimer);
CSLAPI void TIMER_resetAll();

CSLAPI TIMER_Handle TIMER_open(int devNum, Uint32 flags);
CSLAPI void TIMER_close(TIMER_Handle hTimer);


/******************************************************************************\
* inline function declarations
\******************************************************************************/
IDECL Uint32 TIMER_getEventId(TIMER_Handle hTimer);

IDECL void TIMER_start(TIMER_Handle hTimer);
IDECL void TIMER_pause(TIMER_Handle hTimer);
IDECL void TIMER_resume(TIMER_Handle hTimer);

IDECL Uint32 TIMER_getPeriod(TIMER_Handle hTimer);
IDECL void   TIMER_setPeriod(TIMER_Handle hTimer, Uint32 period);
IDECL Uint32 TIMER_getCount(TIMER_Handle hTimer);
IDECL void   TIMER_setCount(TIMER_Handle hTimer, Uint32 count);

IDECL int  TIMER_getDatIn(TIMER_Handle hTimer);
IDECL void TIMER_setDatOut(TIMER_Handle hTimer, int Val);
IDECL int  TIMER_getTstat(TIMER_Handle hTimer);

IDECL void TIMER_config(TIMER_Handle hTimer, TIMER_Config *config);
IDECL void TIMER_configArgs(TIMER_Handle hTimer, Uint32 ctl, Uint32 prd, 
  Uint32 cnt);
IDECL void TIMER_getConfig(TIMER_Handle hTimer, TIMER_Config *config);


/******************************************************************************\
* inline function definitions
\******************************************************************************/
#ifdef USEDEFS
/*----------------------------------------------------------------------------*/
IDEF Uint32 TIMER_getEventId(TIMER_Handle hTimer) {
  return hTimer->eventId;
}
/*----------------------------------------------------------------------------*/
IDEF void TIMER_start(TIMER_Handle hTimer) {
  TIMER_FSETH(hTimer,CTL,HLD,1);
  TIMER_FSETH(hTimer,CTL,GO,1);
}
/*----------------------------------------------------------------------------*/
IDEF void TIMER_pause(TIMER_Handle hTimer) {
  TIMER_FSETH(hTimer,CTL,HLD,0);
}
/*----------------------------------------------------------------------------*/
IDEF void TIMER_resume(TIMER_Handle hTimer) {
  TIMER_FSETH(hTimer,CTL,HLD,1);
}
/*----------------------------------------------------------------------------*/
IDEF int  TIMER_getDatIn(TIMER_Handle hTimer) {
  return TIMER_FGETH(hTimer,CTL,DATIN);
}  
/*----------------------------------------------------------------------------*/
IDEF void TIMER_setDatOut(TIMER_Handle hTimer, int val) {
  TIMER_FSETH(hTimer,CTL,DATOUT,val);
}
/*----------------------------------------------------------------------------*/
IDEF int  TIMER_getTstat(TIMER_Handle hTimer) {
  return TIMER_FGETH(hTimer,CTL,TSTAT);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 TIMER_getPeriod(TIMER_Handle hTimer) {
  return TIMER_RGETH(hTimer,PRD);
}
/*----------------------------------------------------------------------------*/
IDEF void TIMER_setPeriod(TIMER_Handle hTimer, Uint32 period) {
  TIMER_RSETH(hTimer,PRD,period);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 TIMER_getCount(TIMER_Handle hTimer) {
  return TIMER_RGETH(hTimer,CNT);
}
/*----------------------------------------------------------------------------*/
IDEF void TIMER_setCount(TIMER_Handle hTimer, Uint32 count) {
  TIMER_RSETH(hTimer,CNT,count);
}
/*----------------------------------------------------------------------------*/
IDEF void TIMER_config(TIMER_Handle hTimer, TIMER_Config *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hTimer->baseAddr);
  register int x0,x1,x2;

  gie = IRQ_globalDisable();

  x0 = config->ctl;
  x1 = config->prd;
  x2 = config->cnt;

  base[_TIMER_CTL_OFFSET] = 0x00000000;
  base[_TIMER_PRD_OFFSET] = x1;
  base[_TIMER_CNT_OFFSET] = x2;
  base[_TIMER_CTL_OFFSET] = x0;

  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void TIMER_configArgs(TIMER_Handle hTimer, Uint32 ctl, Uint32 prd,
  Uint32 cnt){

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hTimer->baseAddr);

  gie = IRQ_globalDisable();

  base[_TIMER_CTL_OFFSET] = 0x00000000;
  base[_TIMER_PRD_OFFSET] = prd;
  base[_TIMER_CNT_OFFSET] = cnt;
  base[_TIMER_CTL_OFFSET] = ctl;

  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void TIMER_getConfig(TIMER_Handle hTimer, TIMER_Config *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hTimer->baseAddr);
  volatile TIMER_Config* cfg = (volatile TIMER_Config*)config;
  register int x0,x1,x2;

  gie = IRQ_globalDisable();

  x0 = base[_TIMER_CTL_OFFSET];
  x1 = base[_TIMER_PRD_OFFSET];
  x2 = base[_TIMER_CNT_OFFSET];

  cfg->ctl = x0;
  cfg->prd = x1;
  cfg->cnt = x2;

  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
#endif /* USEDEFS */


#endif /* TIMER_SUPPORT */
#endif /* _CSL_TIMER_H_ */
/******************************************************************************\
* End of csl_timer.h
\******************************************************************************/

