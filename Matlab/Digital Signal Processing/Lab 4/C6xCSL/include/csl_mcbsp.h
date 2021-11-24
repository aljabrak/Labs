/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_mcbsp.h
* DATE CREATED.. 06/11/1999 
* LAST MODIFIED. 09/26/2005 Changed the MCBSP_SRGR_DEFAULT_DELAY macro value 
*							to 0xFFFF.
*				 09/24/2001
*                      - MCBSP_read32 / MCBSP_write32
\******************************************************************************/
#ifndef _CSL_MCBSP_H_
#define _CSL_MCBSP_H_

#include <csl_chip.h>
#include <csl_irq.h>
#include <csl_mcbsphal.h>


#if (MCBSP_SUPPORT)
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

#ifdef  _MCBSP_MOD_
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

/* MCBSP_open() flags */
#define MCBSP_OPEN_RESET     (0x00000001)

/* Renaming MCBSP_read/write  */
#define MCBSP_read32 MCBSP_read 
#define MCBSP_write32 MCBSP_write 


/* pin identifiers used with MCBSP_getPins() and MCBSP_setPins() */
#define MCBSP_PIN_CLKX       _MCBSP_PCR_CLKXP_MASK
#define MCBSP_PIN_FSX        _MCBSP_PCR_FSXP_MASK
#define MCBSP_PIN_DX         _MCBSP_PCR_DXSTAT_MASK
#define MCBSP_PIN_CLKR       _MCBSP_PCR_CLKRP_MASK
#define MCBSP_PIN_FSR        _MCBSP_PCR_FSRP_MASK
#define MCBSP_PIN_DR         _MCBSP_PCR_DRSTAT_MASK
#define MCBSP_PIN_CLKS       _MCBSP_PCR_CLKSSTAT_MASK

/* device identifiers for MCBSP_open() */
#define MCBSP_DEV0    (0)
#define MCBSP_DEV1    (1)
#if (_MCBSP_PORT_CNT == 3)
  #define MCBSP_DEV2  (2)
#endif

/* device identifiers for MCBSP_open() */
#define MCBSP_PORT0    MCBSP_DEV0
#define MCBSP_PORT1    MCBSP_DEV1
#if (_MCBSP_PORT_CNT == 3)
  #define MCBSP_PORT2  MCBSP_DEV2
#endif

/* Constants for MCBSP_start */
#define MCBSP_RCV_START       (1u)
#define MCBSP_XMIT_START      (2u)
#define MCBSP_SRGR_START      (4u)
#define MCBSP_SRGR_FRAMESYNC  (8u)
#define MCBSP_SRGR_DEFAULT_DELAY  (0xFFFFu) /* default delay value*/

/******************************************************************************\
* global typedef declarations
\******************************************************************************/

/* device handle object */
typedef struct {
  Uint32 allocated;
  Uint32 xmtEventId;
  Uint32 rcvEventId;
  volatile Uint32 *baseAddr;
  Uint32 drrAddr;
  Uint32 dxrAddr;
} MCBSP_Obj, *MCBSP_Handle;

/* device configuration structure */
#if (!C64_SUPPORT)
typedef struct {
  Uint32 spcr;
  Uint32 rcr;
  Uint32 xcr;
  Uint32 srgr;
  Uint32 mcr;
  Uint32 rcer; 
  Uint32 xcer;
  Uint32 pcr;
} MCBSP_Config;
#else
typedef struct {
  Uint32 spcr;
  Uint32 rcr;
  Uint32 xcr;
  Uint32 srgr;
  Uint32 mcr;
  Uint32 rcere0;
  Uint32 rcere1;
  Uint32 rcere2;
  Uint32 rcere3;
  Uint32 xcere0;
  Uint32 xcere1;
  Uint32 xcere2;
  Uint32 xcere3;
  Uint32 pcr;
} MCBSP_Config;
#endif

/******************************************************************************\
* global variable declarations
\******************************************************************************/

/* predefined deviced handles for legacy - should not be used*/
extern far MCBSP_Handle _MCBSP_hDev0;
extern far MCBSP_Handle _MCBSP_hDev1;
#if (_MCBSP_PORT_CNT == 3)
  extern far MCBSP_Handle _MCBSP_hDev2;
#endif



/******************************************************************************\
* global function declarations
\******************************************************************************/
CSLAPI void MCBSP_reset(MCBSP_Handle hMcbsp);
CSLAPI void MCBSP_resetAll();
CSLAPI void MCBSP_start(MCBSP_Handle hMcbsp, Uint32 startMask, Uint32 sampleratedelay); 

CSLAPI MCBSP_Handle MCBSP_open(int devNum, Uint32 flags);
CSLAPI void MCBSP_close(MCBSP_Handle hMcbsp);

CSLAPI Uint32 MCBSP_getPins(MCBSP_Handle hMcbsp);
CSLAPI void MCBSP_setPins(MCBSP_Handle hMcbsp, Uint32 pins);


/******************************************************************************\
* inline function declarations
\******************************************************************************/
IDECL Uint32 MCBSP_getXmtAddr(MCBSP_Handle hMcbsp);
IDECL Uint32 MCBSP_getRcvAddr(MCBSP_Handle hMcbsp);
IDECL Uint32 MCBSP_getXmtEventId(MCBSP_Handle hMcbsp);
IDECL Uint32 MCBSP_getRcvEventId(MCBSP_Handle hMcbsp);

IDECL Uint32 MCBSP_read(MCBSP_Handle hMcbsp);
IDECL void   MCBSP_write(MCBSP_Handle hMcbsp, Uint32 val);

IDECL void   MCBSP_enableXmt(MCBSP_Handle hMcbsp);
IDECL void   MCBSP_enableRcv(MCBSP_Handle hMcbsp);
IDECL void   MCBSP_enableFsync(MCBSP_Handle hMcbsp);
IDECL void   MCBSP_enableSrgr(MCBSP_Handle hMcbsp);

IDECL Uint32 MCBSP_xrdy(MCBSP_Handle hMcbsp);
IDECL Uint32 MCBSP_rrdy(MCBSP_Handle hMcbsp);
IDECL Uint32 MCBSP_xempty(MCBSP_Handle hMcbsp);
IDECL Uint32 MCBSP_rfull(MCBSP_Handle hMcbsp);
IDECL Uint32 MCBSP_xsyncerr(MCBSP_Handle hMcbsp);
IDECL Uint32 MCBSP_rsyncerr(MCBSP_Handle hMcbsp);

IDECL void MCBSP_config(MCBSP_Handle hMcbsp, MCBSP_Config *config);

#if (!C64_SUPPORT) /* ?? added C64_SUPPORT */
IDECL void MCBSP_configArgs(MCBSP_Handle hMcbsp, Uint32 spcr, Uint32 rcr, 
  Uint32 xcr, Uint32 srgr, Uint32 mcr, Uint32 rcer, Uint32 xcer, Uint32 pcr);
#else /* (C64_SUPPORT) */
IDECL void MCBSP_configArgs(MCBSP_Handle hMcbsp, Uint32 spcr, Uint32 rcr, 
  Uint32 xcr, Uint32 srgr, Uint32 mcr, Uint32 rcere0, Uint32 rcere1, 
  Uint32 rcere2, Uint32 rcere3, Uint32 xcere0, Uint32 xcere1, Uint32 xcere2, 
  Uint32 xcere3, Uint32 pcr);
#endif

IDECL void MCBSP_getConfig(MCBSP_Handle hMcbsp, MCBSP_Config *config);


/******************************************************************************\
* inline function definitions
\******************************************************************************/
#ifdef USEDEFS
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCBSP_getXmtAddr(MCBSP_Handle hMcbsp) {
  return (Uint32)(hMcbsp->dxrAddr);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCBSP_getRcvAddr(MCBSP_Handle hMcbsp) {
  return (Uint32)(hMcbsp->drrAddr);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCBSP_getXmtEventId(MCBSP_Handle hMcbsp) {
  return (hMcbsp->xmtEventId);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCBSP_getRcvEventId(MCBSP_Handle hMcbsp) {
  return (hMcbsp->rcvEventId);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCBSP_read(MCBSP_Handle hMcbsp) {
  return (*(volatile Uint32 *)(hMcbsp->drrAddr));
}
/*----------------------------------------------------------------------------*/
IDEF void MCBSP_write(MCBSP_Handle hMcbsp, Uint32 val) {
  (*(volatile Uint32 *)(hMcbsp->dxrAddr)) = val;
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCBSP_xrdy(MCBSP_Handle hMcbsp) {
  return MCBSP_FGETH(hMcbsp,SPCR,XRDY);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCBSP_rrdy(MCBSP_Handle hMcbsp) {
  return MCBSP_FGETH(hMcbsp,SPCR,RRDY);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCBSP_xempty(MCBSP_Handle hMcbsp) {
  return MCBSP_FGETH(hMcbsp,SPCR,XEMPTY);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCBSP_rfull(MCBSP_Handle hMcbsp) {
  return MCBSP_FGETH(hMcbsp,SPCR,RFULL);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCBSP_xsyncerr(MCBSP_Handle hMcbsp) {
  return MCBSP_FGETH(hMcbsp,SPCR,XSYNCERR);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCBSP_rsyncerr(MCBSP_Handle hMcbsp) {
  return MCBSP_FGETH(hMcbsp,SPCR,RSYNCERR);
}
/*----------------------------------------------------------------------------*/
IDEF void MCBSP_enableXmt(MCBSP_Handle hMcbsp) {
  MCBSP_FSETSH(hMcbsp,SPCR,XRST,NO);
}
/*----------------------------------------------------------------------------*/
IDEF void MCBSP_enableRcv(MCBSP_Handle hMcbsp) {
  MCBSP_FSETSH(hMcbsp,SPCR,RRST,NO);
}
/*----------------------------------------------------------------------------*/
IDEF void MCBSP_enableFsync(MCBSP_Handle hMcbsp) {
  MCBSP_FSETSH(hMcbsp,SPCR,FRST,NO);
}
/*----------------------------------------------------------------------------*/
IDEF void MCBSP_enableSrgr(MCBSP_Handle hMcbsp) {
  MCBSP_FSETSH(hMcbsp,SPCR,GRST,NO);
}
/*----------------------------------------------------------------------------*/
#if(!C64_SUPPORT) /* ?? added C64_SUPPORT */
IDEF void MCBSP_config(MCBSP_Handle hMcbsp, MCBSP_Config *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hMcbsp->baseAddr);
  register int x0,x1,x2,x3,x4,x5,x6,x7;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */
  x0 = config->spcr;
  x1 = config->rcr;
  x2 = config->xcr;
  x3 = config->srgr;
  x4 = config->mcr;
  x5 = config->rcer;
  x6 = config->xcer;
  x7 = config->pcr;

  base[_MCBSP_SPCR_OFFSET] = 0x00000000;
  base[_MCBSP_RCR_OFFSET]  = x1;
  base[_MCBSP_XCR_OFFSET]  = x2;
  base[_MCBSP_SRGR_OFFSET] = x3;
  base[_MCBSP_MCR_OFFSET]  = x4;
  base[_MCBSP_RCER_OFFSET] = x5;
  base[_MCBSP_XCER_OFFSET] = x6;
  base[_MCBSP_PCR_OFFSET]  = x7;
  base[_MCBSP_SPCR_OFFSET] = x0;

  IRQ_globalRestore(gie);
}
#else /* (C64_SUPPORT)*/
IDEF void MCBSP_config(MCBSP_Handle hMcbsp, MCBSP_Config *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hMcbsp->baseAddr);
  register int x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */
  x0  = config->spcr;
  x1  = config->rcr;
  x2  = config->xcr;
  x3  = config->srgr;
  x4  = config->mcr;
  x5  = config->rcere0;
  x6  = config->rcere1;
  x7  = config->rcere2;
  x8  = config->rcere3;
  x9  = config->xcere0;
  x10 = config->xcere1;
  x11 = config->xcere2;
  x12 = config->xcere3;
  x13 = config->pcr;

  base[_MCBSP_SPCR_OFFSET]   = 0x00000000;
  base[_MCBSP_RCR_OFFSET]    = x1;
  base[_MCBSP_XCR_OFFSET]    = x2;
  base[_MCBSP_SRGR_OFFSET]   = x3;
  base[_MCBSP_MCR_OFFSET]    = x4;
  base[_MCBSP_RCERE0_OFFSET] = x5;
  base[_MCBSP_RCERE1_OFFSET] = x6;
  base[_MCBSP_RCERE2_OFFSET] = x7;
  base[_MCBSP_RCERE3_OFFSET] = x8;
  base[_MCBSP_XCERE0_OFFSET] = x9;
  base[_MCBSP_XCERE1_OFFSET] = x10;
  base[_MCBSP_XCERE2_OFFSET] = x11;
  base[_MCBSP_XCERE3_OFFSET] = x12;
  base[_MCBSP_PCR_OFFSET]    = x13;
  base[_MCBSP_SPCR_OFFSET]   = x0;

  IRQ_globalRestore(gie);
}
#endif /* C64_SUPPORT */
/*----------------------------------------------------------------------------*/
#if (!C64_SUPPORT) /* ?? added C64_SUPPORT */
IDEF void MCBSP_configArgs(MCBSP_Handle hMcbsp, Uint32 spcr, Uint32 rcr, 
  Uint32 xcr, Uint32 srgr, Uint32 mcr, Uint32 rcer, Uint32 xcer, Uint32 pcr) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hMcbsp->baseAddr);

  gie = IRQ_globalDisable();

  base[_MCBSP_SPCR_OFFSET] = 0x00000000;
  base[_MCBSP_RCR_OFFSET]  = rcr;
  base[_MCBSP_XCR_OFFSET]  = xcr;
  base[_MCBSP_SRGR_OFFSET] = srgr;
  base[_MCBSP_MCR_OFFSET]  = mcr;
  base[_MCBSP_RCER_OFFSET] = rcer;
  base[_MCBSP_XCER_OFFSET] = xcer;
  base[_MCBSP_PCR_OFFSET]  = pcr;
  base[_MCBSP_SPCR_OFFSET] = spcr;

  IRQ_globalRestore(gie);
}
#else /* (C64_SUPPORT) */
IDEF void MCBSP_configArgs(MCBSP_Handle hMcbsp, Uint32 spcr, Uint32 rcr, 
  Uint32 xcr, Uint32 srgr, Uint32 mcr, Uint32 rcere0, Uint32 rcere1, 
  Uint32 rcere2, Uint32 rcere3, Uint32 xcere0, Uint32 xcere1, Uint32 xcere2, 
  Uint32 xcere3, Uint32 pcr) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hMcbsp->baseAddr);

  gie = IRQ_globalDisable();

  base[_MCBSP_SPCR_OFFSET]   = 0x00000000;
  base[_MCBSP_RCR_OFFSET]    = rcr;
  base[_MCBSP_XCR_OFFSET]    = xcr;
  base[_MCBSP_SRGR_OFFSET]   = srgr;
  base[_MCBSP_MCR_OFFSET]    = mcr;
  base[_MCBSP_RCERE0_OFFSET] = rcere0;
  base[_MCBSP_RCERE1_OFFSET] = rcere1;
  base[_MCBSP_RCERE2_OFFSET] = rcere2;
  base[_MCBSP_RCERE3_OFFSET] = rcere3;
  base[_MCBSP_XCERE0_OFFSET] = xcere0;
  base[_MCBSP_XCERE1_OFFSET] = xcere1;
  base[_MCBSP_XCERE2_OFFSET] = xcere2;
  base[_MCBSP_XCERE3_OFFSET] = xcere3;
  base[_MCBSP_PCR_OFFSET]    = pcr;
  base[_MCBSP_SPCR_OFFSET]   = spcr;

  IRQ_globalRestore(gie);
}
#endif /* C64_SUPPORT */
/*----------------------------------------------------------------------------*/
#if (!C64_SUPPORT) /* ?? added C64_SUPPORT */
IDEF void MCBSP_getConfig(MCBSP_Handle hMcbsp, MCBSP_Config *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hMcbsp->baseAddr);
  volatile MCBSP_Config* cfg = (volatile MCBSP_Config*)config;
  register int x0,x1,x2,x3,x4,x5,x6,x7;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */

  x0 = base[_MCBSP_SPCR_OFFSET];
  x1 = base[_MCBSP_RCR_OFFSET];
  x2 = base[_MCBSP_XCR_OFFSET];
  x3 = base[_MCBSP_SRGR_OFFSET];
  x4 = base[_MCBSP_MCR_OFFSET];
  x5 = base[_MCBSP_RCER_OFFSET];
  x6 = base[_MCBSP_XCER_OFFSET];
  x7 = base[_MCBSP_PCR_OFFSET];

  cfg->spcr = x0;
  cfg->rcr  = x1;
  cfg->xcr  = x2;
  cfg->srgr = x3;
  cfg->mcr  = x4;
  cfg->rcer = x5;
  cfg->xcer = x6;
  cfg->pcr  = x7;

  IRQ_globalRestore(gie);
}
#else /* (C64_SUPPORT) */
IDEF void MCBSP_getConfig(MCBSP_Handle hMcbsp, MCBSP_Config *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hMcbsp->baseAddr);
  volatile MCBSP_Config* cfg = (volatile MCBSP_Config*)config;
  register int x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */

  x0  = base[_MCBSP_SPCR_OFFSET];
  x1  = base[_MCBSP_RCR_OFFSET];
  x2  = base[_MCBSP_XCR_OFFSET];
  x3  = base[_MCBSP_SRGR_OFFSET];
  x4  = base[_MCBSP_MCR_OFFSET];
  x5  = base[_MCBSP_RCERE0_OFFSET];
  x6  = base[_MCBSP_RCERE1_OFFSET];
  x7  = base[_MCBSP_RCERE2_OFFSET];
  x8  = base[_MCBSP_RCERE3_OFFSET];
  x9  = base[_MCBSP_XCERE0_OFFSET];
  x10 = base[_MCBSP_XCERE1_OFFSET];
  x11 = base[_MCBSP_XCERE2_OFFSET];
  x12 = base[_MCBSP_XCERE3_OFFSET];
  x13 = base[_MCBSP_PCR_OFFSET];

  cfg->spcr   = x0;
  cfg->rcr    = x1;
  cfg->xcr    = x2;
  cfg->srgr   = x3;
  cfg->mcr    = x4;
  cfg->rcere0 = x5;
  cfg->rcere1 = x6;
  cfg->rcere2 = x7;
  cfg->rcere3 = x8;
  cfg->xcere0 = x9;
  cfg->xcere1 = x10;
  cfg->xcere2 = x11;
  cfg->xcere3 = x12;
  cfg->pcr    = x13;

  IRQ_globalRestore(gie);
}
#endif /* C64_SUPPORT */
/*----------------------------------------------------------------------------*/
#endif /* USEDEFS */


#endif /* MCBSP_SUPPORT */
#endif /* _CSL_MCBSP_H_ */
/******************************************************************************\
* End of csl_mcbsp.h
\******************************************************************************/

