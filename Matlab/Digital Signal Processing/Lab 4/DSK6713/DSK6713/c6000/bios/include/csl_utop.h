/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_utop.h
* DATE CREATED.. 07/19/2000 
* LAST MODIFIED. 12/22/2000 
\******************************************************************************/
#ifndef _CSL_UTOP_H_
#define _CSL_UTOP_H_

#include <csl_chip.h>
#include <csl_irq.h>
#include <csl_utophal.h>

#if (UTOP_SUPPORT)
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

#ifdef  _UTOP_MOD_
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

/* utopia interrupt numbers */
#define UTOP_INT_XQ     0
#define UTOP_INT_RQ     16

/* utopia error interrupt numbers */
#define UTOP_ERR_RQS    0
#define UTOP_ERR_RCF    1
#define UTOP_ERR_RCP    2
#define UTOP_ERR_XQS    16
#define UTOP_ERR_XCF    17
#define UTOP_ERR_XCP    18

#define UTOP_RCVQ_ADDR  _UTOP_BASE_RQUEUE 
#define UTOP_XMTQ_ADDR  _UTOP_BASE_XQUEUE 


/******************************************************************************\
* global typedef declarations
\******************************************************************************/

/* device configuration structure */
typedef struct {
  Uint32 ucr;
  Uint32 cdr;
} UTOP_Config;

/******************************************************************************\
* global variable declarations
\******************************************************************************/


/******************************************************************************\
* global function declarations
\******************************************************************************/
CSLAPI void UTOP_reset();

/******************************************************************************\
* inline function declarations
\******************************************************************************/
IDECL Uint32 UTOP_getXmtAddr();
IDECL Uint32 UTOP_getRcvAddr();
IDECL Uint32 UTOP_getEventId();

/* UTOP_read/write is for CPU servicing Utopia */
IDECL Uint32 UTOP_read();
IDECL void   UTOP_write(Uint32 val);

IDECL void UTOP_enableXmt();
IDECL void UTOP_enableRcv();

IDECL void   UTOP_intDisable(Uint32 intNum);
IDECL void   UTOP_intEnable(Uint32 intNum);
IDECL void   UTOP_intClear(Uint32 intNum);
IDECL Uint32 UTOP_intTest(Uint32 intNum);
IDECL void   UTOP_intReset(Uint32 intNum);

IDECL void   UTOP_errDisable(Uint32 errNum);
IDECL void   UTOP_errEnable(Uint32 errNum);
IDECL void   UTOP_errClear(Uint32 errNum);
IDECL Uint32 UTOP_errTest(Uint32 errNum);
IDECL void   UTOP_errReset(Uint32 errNum);

IDECL void UTOP_config(UTOP_Config *config);
IDECL void UTOP_configArgs(Uint32 ucr, Uint32 cdr);
IDECL void UTOP_getConfig(UTOP_Config *config);


/******************************************************************************\
* inline function definitions
\******************************************************************************/
#ifdef USEDEFS
/*----------------------------------------------------------------------------*/
IDEF Uint32 UTOP_getXmtAddr() {
  return (Uint32)(_UTOP_BASE_XQUEUE);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 UTOP_getRcvAddr() {
  return (Uint32)(_UTOP_BASE_RQUEUE);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 UTOP_getEventId() {
  return (IRQ_EVT_UINT);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 UTOP_read() {
  return (*(volatile Uint32*)(_UTOP_BASE_RQUEUE));
}
/*----------------------------------------------------------------------------*/
IDEF void UTOP_write(Uint32 val) {
  (*(volatile Uint32*)(_UTOP_BASE_XQUEUE)) = val;
}
/*----------------------------------------------------------------------------*/
IDEF void UTOP_enableXmt() {
  UTOP_FSETS(UCR,UXEN,ENABLE);
}
/*----------------------------------------------------------------------------*/
IDEF void UTOP_enableRcv() {
  UTOP_FSETS(UCR,UREN,ENABLE);
}
/*----------------------------------------------------------------------------*/
IDEF void UTOP_intDisable(Uint32 intNum){
  UTOP_RSET(UIER,UTOP_RGET(UIER)&~(1<<intNum));
}
/*----------------------------------------------------------------------------*/
IDEF void UTOP_intEnable(Uint32 intNum){
  UTOP_RSET(UIER,UTOP_RGET(UIER)|(1<<intNum));
}
/*----------------------------------------------------------------------------*/
IDEF void UTOP_intClear(Uint32 intNum){
  UTOP_RSET(UIPR,1<<intNum);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 UTOP_intTest(Uint32 intNum){
  return ((UTOP_RGET(UIPR) & (1<<intNum)) ? 1 : 0);
}
/*----------------------------------------------------------------------------*/
IDEF void UTOP_intReset(Uint32 intNum){
  UTOP_intDisable(intNum);
  UTOP_intClear(intNum);
}
/*----------------------------------------------------------------------------*/
IDEF void UTOP_errDisable(Uint32 errNum){
  UTOP_RSET(EIER,UTOP_RGET(EIER)&~(1<<errNum));
}
/*----------------------------------------------------------------------------*/
IDEF void UTOP_errEnable(Uint32 errNum){
  UTOP_RSET(EIER,UTOP_RGET(EIER)|(1<<errNum));
}
/*----------------------------------------------------------------------------*/
IDEF void UTOP_errClear(Uint32 errNum){
  UTOP_RSET(EIPR,1<<errNum);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 UTOP_errTest(Uint32 errNum){
  return ((UTOP_RGET(EIPR) & (1<<errNum)) ? 1 : 0);
}
/*----------------------------------------------------------------------------*/
IDEF void UTOP_errReset(Uint32 errNum){
  UTOP_errDisable(errNum);
  UTOP_errClear(errNum);
}
/*----------------------------------------------------------------------------*/
IDEF void UTOP_config(UTOP_Config *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)_UTOP_UCR_ADDR;
  register int x0,x1;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */
  x0 = config->ucr;
  x1 = config->cdr;

  base[_UTOP_UCR_OFFSET]    = 0x00000000u;
  base[_UTOP_CDR_OFFSET]    = x1;
  base[_UTOP_UCR_OFFSET]    = x0; /* Enable interface after everything is set up */

  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void UTOP_configArgs(Uint32 ucr, Uint32 cdr) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)_UTOP_UCR_ADDR;

  gie = IRQ_globalDisable();

  base[_UTOP_UCR_OFFSET]    = 0x00000000u;
  base[_UTOP_CDR_OFFSET]    = cdr;
  base[_UTOP_UCR_OFFSET]    = ucr; /* Enable interface after everything is set up */

  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void UTOP_getConfig(UTOP_Config *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)_UTOP_UCR_ADDR;
  register int x0,x1;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */

  x0 = base[_UTOP_UCR_OFFSET];
  x1 = base[_UTOP_CDR_OFFSET];
  
  config->ucr    = x0;
  config->cdr    = x1;

  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
#endif /* USEDEFS */


#endif /* UTOP_SUPPORT */
#endif /* _CSL_UTOP_H_ */
/******************************************************************************\
* End of csl_utop.h
\******************************************************************************/

