/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_dma.h
* DATE CREATED.. 06/11/1999 
* LAST MODIFIED. 09/20/2000
*
\******************************************************************************/
#ifndef _CSL_DMA_H_
#define _CSL_DMA_H_

#include <csl_chip.h>
#include <csl_dmahal.h>
#include <csl_irq.h>


#if (DMA_SUPPORT)
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

#ifdef  _DMA_MOD_
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
#define DMA_CHA_CNT        4

/* DMA_open() flags */
#define DMA_OPEN_RESET     0x00000001u

/* channel identifiers for DMA_open() */
#define DMA_CHAANY  (-1)
#define DMA_CHA0    (0)
#define DMA_CHA1    (1)
#define DMA_CHA2    (2)
#define DMA_CHA3    (3)

/* DMA status state */
#define DMA_STATUS_STOPPED      DMA_PRICTL_STATUS_STOPPED
#define DMA_STATUS_RUNNING      DMA_PRICTL_STATUS_RUNNING
#define DMA_STATUS_PAUSED       DMA_PRICTL_STATUS_PAUSED
#define DMA_STATUS_AUTORUNNING  DMA_PRICTL_STATUS_AUTORUNNING

/* predefined global register IDs */
#define DMA_GBL_ADDRRLDB    0x00000001u
#define DMA_GBL_ADDRRLDC    0x00000002u
#define DMA_GBL_ADDRRLDD    0x00000003u
#define DMA_GBL_INDEXA      0x00000004u
#define DMA_GBL_INDEXB      0x00000005u
#define DMA_GBL_CNTRLDA     0x00000008u
#define DMA_GBL_CNTRLDB     0x00000009u
#define DMA_GBL_SPLITA      0x0000000Du
#define DMA_GBL_SPLITB      0x0000000Eu
#define DMA_GBL_SPLITC      0x0000000Fu

#define DMA_GBLADDRA        0x00000001u
#define DMA_GBLADDRB        0x00000002u
#define DMA_GBLADDRC        0x00000004u
#define DMA_GBLADDRD        0x00000008u
#define DMA_GBLIDXA         0x00000010u
#define DMA_GBLIDXB         0x00000020u
#define DMA_GBLCNTA         0x00000040u
#define DMA_GBLCNTB         0x00000080u

#define _DMA_GBLREG_CNT     16
#define _DMA_GBLREG_MASK    (_DMA_GBLREG_CNT-1)

/****************************************************************/
/* The two following macros are used to get/clear the condition */
/* flags of the DMA SECCTL register in a safe manner.           */
/*                                                              */
/* The X argument MUST be one of the following:                 */
/*   DMA_SECCTL_SXCOND                                          */
/*   DMA_SECCTL_FRAMECOND                                       */
/*   DMA_SECCTL_LASTCOND                                        */
/*   DMA_SECCTL_BLOCKCOND                                       */
/*   DMA_SECCTL_RDROPCOND                                       */
/*   DMA_SECCTL_WDROPCOND                                       */
/****************************************************************/

#define DMA_GET_CONDITION(hDma,X) \
  ((DMA_RGETH(hDma,SECCTL)&_##X##_MASK)>>_##X##_SHIFT)

#define DMA_CLEAR_CONDITION(hDma,X) \
  _PER_RAOI(DMA_ADDRH(hDma,SECCTL),DMA,SECCTL,\
    (0xFFFF0AAA&~_##X##_MASK),\
    (0x00000555&~_##X##_MASK),\
    0x00000000\
  )


/******************************************************************************\
* global typedef declarations
\******************************************************************************/

/* private object, not to be used by application code */
typedef struct {
  Uint32           allocated;
  Uint32           eventId;
  Uint32 volatile *baseAddr;
} DMA_Obj,*DMA_Handle;

/* channel configuration structure */
typedef struct {
  Uint32 prictl;
  Uint32 secctl;
  Uint32 src;
  Uint32 dst;
  Uint32 xfrcnt;
} DMA_Config;

typedef enum {
  DMA_GBL_ADDRRLD = 0x00,
  DMA_GBL_INDEX   = 0x04,
  DMA_GBL_CNTRLD  = 0x08,
  DMA_GBL_SPLIT   = 0x0C
} DMA_Gbl;

typedef struct {
  Uint32 addrA;
  Uint32 addrB;
  Uint32 addrC;
  Uint32 addrD;
  Uint32 idxA;
  Uint32 idxB;
  Uint32 cntA;
  Uint32 cntB;
} DMA_GlobalConfig;


/******************************************************************************\
* global variable declarations
\******************************************************************************/
extern far Uint32 _DMA_gblRegTbl[_DMA_GBLREG_CNT];

/* Predefined channel handles, these are only here for legacy    */
/* purposes and should not be used.                              */
extern far DMA_Handle _DMA_hCha0;
extern far DMA_Handle _DMA_hCha1;
extern far DMA_Handle _DMA_hCha2;
extern far DMA_Handle _DMA_hCha3;


/******************************************************************************\
* global function declarations
\******************************************************************************/
CSLAPI void DMA_reset(DMA_Handle hDma);

CSLAPI DMA_Handle DMA_open(int chaNum, Uint32 flags);
CSLAPI void DMA_close(DMA_Handle hDma);

CSLAPI Uint32 DMA_allocGlobalReg(DMA_Gbl regType, Uint32 initVal);
CSLAPI void   DMA_freeGlobalReg(Uint32 regId);  

CSLAPI Uint32 DMA_globalAlloc(Uint32 regs);
CSLAPI void   DMA_globalFree(Uint32 regs);


/******************************************************************************\
* inline function declarations
\******************************************************************************/
IDECL Uint32 DMA_getEventId(DMA_Handle hDma);
IDECL Uint32 DMA_getStatus(DMA_Handle hDma);
IDECL void DMA_restoreStatus(DMA_Handle hDma,Uint32 status); 

IDECL void   DMA_start(DMA_Handle hDma);
IDECL void   DMA_stop(DMA_Handle hDma);
IDECL void   DMA_pause(DMA_Handle hDma);
IDECL void   DMA_autoStart(DMA_Handle hDma);
IDECL void   DMA_wait(DMA_Handle hDma);

IDECL void   DMA_setAuxCtl(Uint32 auxCtl);

IDECL Uint32 DMA_getGlobalRegAddr(Uint32 regId);
IDECL Uint32 DMA_getGlobalReg(Uint32 regId);
IDECL void   DMA_setGlobalReg(Uint32 regId, Uint32 val);

IDECL void DMA_config(DMA_Handle hDma, DMA_Config *config);
IDECL void DMA_configArgs(DMA_Handle hDma, Uint32 prictl, Uint32 secctl, 
  Uint32 src, Uint32 dst, Uint32 xfrcnt);
IDECL void DMA_getConfig(DMA_Handle hDma, DMA_Config *config);
  
IDECL void   DMA_globalConfig(Uint32 regs, DMA_GlobalConfig *cfg); 
IDECL void   DMA_globalConfigArgs(Uint32 regs, Uint32 addrA, Uint32 addrB,
  Uint32 addrC,Uint32 addrD,Uint32 idxA,Uint32 idxB,Uint32 cntA,Uint32 cntB);
IDECL void   DMA_globalGetConfig(Uint32 regs, DMA_GlobalConfig *cfg); 


/******************************************************************************\
* inline function definitions
\******************************************************************************/
#ifdef USEDEFS
/*----------------------------------------------------------------------------*/
IDEF Uint32 DMA_getEventId(DMA_Handle hDma) {
  return (Uint32)(hDma->eventId);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 DMA_getStatus(DMA_Handle hDma) {
  return (Uint32)DMA_FGETH(hDma,PRICTL,STATUS);
}
/*----------------------------------------------------------------------------*/
IDEF void DMA_restoreStatus(DMA_Handle hDma,Uint32 status) {
   DMA_FSETH(hDma,PRICTL,START,status);
}
/*----------------------------------------------------------------------------*/
IDEF void DMA_start(DMA_Handle hDma) {
  DMA_FSETSH(hDma,PRICTL,START,NORMAL);
}
/*----------------------------------------------------------------------------*/
IDEF void DMA_stop(DMA_Handle hDma) {
  DMA_FSETSH(hDma,PRICTL,START,STOP);
}
/*----------------------------------------------------------------------------*/
IDEF void DMA_pause(DMA_Handle hDma) {
  DMA_FSETSH(hDma,PRICTL,START,PAUSE);
}
/*----------------------------------------------------------------------------*/
IDEF void DMA_autoStart(DMA_Handle hDma) {
  DMA_FSETSH(hDma,PRICTL,START,AUTOINIT);
}
/*----------------------------------------------------------------------------*/
IDEF void DMA_wait(DMA_Handle hDma) {
  while (DMA_getStatus(hDma) & DMA_STATUS_RUNNING);
}
/*----------------------------------------------------------------------------*/
IDEF void DMA_setAuxCtl(Uint32 auxCtl) {
  DMA_RSET(AUXCTL,auxCtl);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 DMA_getGlobalRegAddr(Uint32 regId) {
  return _DMA_gblRegTbl[regId&_DMA_GBLREG_MASK];
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 DMA_getGlobalReg(Uint32 regId) {
  return DMA_RGETA(_DMA_gblRegTbl[regId&_DMA_GBLREG_MASK],REG);
}
/*----------------------------------------------------------------------------*/
IDEF void DMA_setGlobalReg(Uint32 regId, Uint32 val) {
  DMA_RSETA(_DMA_gblRegTbl[regId&_DMA_GBLREG_MASK],REG,val);
}
/*----------------------------------------------------------------------------*/
IDEF void DMA_config(DMA_Handle hDma, DMA_Config *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hDma->baseAddr);
  register int prictl,secctl,src,dst,xfrcnt;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */
  prictl = config->prictl;
  secctl = config->secctl;
  src    = config->src;
  dst    = config->dst;
  xfrcnt = config->xfrcnt;

  base[_DMA_PRICTL_OFFSET] = 0x00000000;
  base[_DMA_SECCTL_OFFSET] = secctl;
  base[_DMA_SRC_OFFSET]    = src;
  base[_DMA_DST_OFFSET]    = dst;
  base[_DMA_XFRCNT_OFFSET] = xfrcnt;
  base[_DMA_PRICTL_OFFSET] = prictl;

  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void DMA_configArgs(DMA_Handle hDma, Uint32 prictl, Uint32 secctl, 
  Uint32 src, Uint32 dst, Uint32 xfrcnt) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hDma->baseAddr);

  gie = IRQ_globalDisable();
  base[_DMA_PRICTL_OFFSET] = 0x00000000;
  base[_DMA_SECCTL_OFFSET] = secctl;
  base[_DMA_SRC_OFFSET]    = src;
  base[_DMA_DST_OFFSET]    = dst;
  base[_DMA_XFRCNT_OFFSET] = xfrcnt;
  base[_DMA_PRICTL_OFFSET] = prictl;
  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void DMA_getConfig(DMA_Handle hDma, DMA_Config *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hDma->baseAddr);
  volatile DMA_Config*cfg = (volatile DMA_Config*)config;
  register int prictl,secctl,src,dst,xfrcnt;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */
  prictl = base[_DMA_PRICTL_OFFSET];
  secctl = base[_DMA_SECCTL_OFFSET];
  src    = base[_DMA_SRC_OFFSET];
  dst    = base[_DMA_DST_OFFSET];
  xfrcnt = base[_DMA_XFRCNT_OFFSET];

  cfg->prictl = prictl;
  cfg->secctl = secctl;
  cfg->src    = src;
  cfg->dst    = dst;
  cfg->xfrcnt = xfrcnt;

  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void DMA_globalConfig(Uint32 regs, DMA_GlobalConfig *cfg) {

  Uint32 gie;
  gie = IRQ_globalDisable();
  if (regs & DMA_GBLADDRA) DMA_RSET(GBLADDRA,cfg->addrA);
  if (regs & DMA_GBLADDRB) DMA_RSET(GBLADDRB,cfg->addrB);
  if (regs & DMA_GBLADDRC) DMA_RSET(GBLADDRC,cfg->addrC);
  if (regs & DMA_GBLADDRD) DMA_RSET(GBLADDRD,cfg->addrD);
  if (regs & DMA_GBLIDXA)  DMA_RSET(GBLIDXA,cfg->idxA);
  if (regs & DMA_GBLIDXB)  DMA_RSET(GBLIDXB,cfg->idxB);
  if (regs & DMA_GBLCNTA)  DMA_RSET(GBLCNTA,cfg->cntA);
  if (regs & DMA_GBLCNTB)  DMA_RSET(GBLCNTB,cfg->cntB);
  IRQ_globalRestore(gie);
}

/*----------------------------------------------------------------------------*/
IDEF void DMA_globalConfigArgs(Uint32 regs, Uint32 addrA, Uint32 addrB,
  Uint32 addrC,Uint32 addrD,Uint32 idxA,Uint32 idxB,Uint32 cntA,Uint32 cntB) {

  Uint32 gie;
  gie = IRQ_globalDisable();
  if (regs & DMA_GBLADDRA) DMA_RSET(GBLADDRA,addrA);
  if (regs & DMA_GBLADDRB) DMA_RSET(GBLADDRB,addrB);
  if (regs & DMA_GBLADDRC) DMA_RSET(GBLADDRC,addrC);
  if (regs & DMA_GBLADDRD) DMA_RSET(GBLADDRD,addrD);
  if (regs & DMA_GBLIDXA)  DMA_RSET(GBLIDXA,idxA);
  if (regs & DMA_GBLIDXB)  DMA_RSET(GBLIDXB,idxB);
  if (regs & DMA_GBLCNTA)  DMA_RSET(GBLCNTA,cntA);
  if (regs & DMA_GBLCNTB)  DMA_RSET(GBLCNTB,cntB);
  IRQ_globalRestore(gie);
}

/*----------------------------------------------------------------------------*/
IDEF void DMA_globalGetConfig(Uint32 regs, DMA_GlobalConfig *config) {

  Uint32 gie;
  volatile DMA_GlobalConfig* cfg = (volatile DMA_GlobalConfig*)config;

  gie = IRQ_globalDisable();
  if (regs & DMA_GBLADDRA) cfg->addrA = DMA_RGET(GBLADDRA);
  if (regs & DMA_GBLADDRB) cfg->addrB = DMA_RGET(GBLADDRB);
  if (regs & DMA_GBLADDRC) cfg->addrC = DMA_RGET(GBLADDRC);
  if (regs & DMA_GBLADDRD) cfg->addrD = DMA_RGET(GBLADDRD);
  if (regs & DMA_GBLIDXA)  cfg->idxA  = DMA_RGET(GBLIDXA);
  if (regs & DMA_GBLIDXB)  cfg->idxB  = DMA_RGET(GBLIDXB);
  if (regs & DMA_GBLCNTA)  cfg->cntA  = DMA_RGET(GBLCNTA);
  if (regs & DMA_GBLCNTB)  cfg->cntB  = DMA_RGET(GBLCNTB);
  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
#endif /* USEDEFS */


#endif /* DMA_SUPPORT */
#endif /* _CSL_DMA_H_ */
/******************************************************************************\
* End of csl_dma.h
\******************************************************************************/

