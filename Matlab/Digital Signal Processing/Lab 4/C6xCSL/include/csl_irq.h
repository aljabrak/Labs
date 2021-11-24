/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_irq.h
* DATE CREATED.. 06/09/1999 
* LAST MODIFIED. 08/02/2004 - Adding support for C6418
*                07/24/2004 - Re-introducing BIOS components from CSL due to compatibility issues.
*                02/05/2004 Removed bios related components 
*                10/03/2001
*                - CHIP_RSET()/CHIP_RGET() replaced by CHIP_CRSET()/CHIP_CRGET()
\******************************************************************************/
#ifndef _CSL_IRQ_H_
#define _CSL_IRQ_H_

#include <csl_stdinc.h>
#include <csl_chip.h>
#include <csl_irqhal.h>


#if (IRQ_SUPPORT)
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

#ifdef  _IRQ_MOD_
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

/* misc global settings */
#define IRQ_INT_CNT     16
#define IRQ_EVENT_CNT   32

#define IRQ_EVT_NA         IRQ_EVENT_CNT

/* event id definitions */
#if (CHIP_6410 | CHIP_6413 | CHIP_6418)
  
    #define IRQ_EVT_DSPINT     0
    #define IRQ_EVT_TINT0      1
    #define IRQ_EVT_TINT1      2
    #define IRQ_EVT_SDINTA     3
    #define IRQ_EVT_EXTINT4    4
    #define IRQ_EVT_GPINT4     4
    #define IRQ_EVT_EXTINT5    5
    #define IRQ_EVT_GPINT5     5
    #define IRQ_EVT_EXTINT6    6
    #define IRQ_EVT_GPINT6     6
    #define IRQ_EVT_EXTINT7    7
    #define IRQ_EVT_GPINT7     7
    #define IRQ_EVT_EDMAINT    8
    #define IRQ_EVT_EMUDTDMA   9
    #define IRQ_EVT_EMURTDXRX  10
    #define IRQ_EVT_EMURTDXTX  11
    #define IRQ_EVT_XINT0      12
    #define IRQ_EVT_RINT0      13
    #define IRQ_EVT_XINT1      14
    #define IRQ_EVT_RINT1      15
    #define IRQ_EVT_GPINT0     16
    #define IRQ_EVT_TINT2      19
    #define IRQ_EVT_I2CINT0    22
    #define IRQ_EVT_I2CINT1    23
    #define IRQ_EVT_AXINT1     24
    #define IRQ_EVT_ARINT1     25
    #define IRQ_EVT_AXINT0     28
    #define IRQ_EVT_ARINT0     29

  #if (CHIP_6418)
    #define IRQ_EVT_VCPINT     30
  #endif

#else 

  #if (CHIP_DM642 | CHIP_DM641 | CHIP_DM640 | CHIP_6412)

    #define IRQ_EVT_DSPINT     0
    #define IRQ_EVT_TINT0      1
    #define IRQ_EVT_TINT1      2
    #define IRQ_EVT_SDINTA     3
    #define IRQ_EVT_EXTINT4    4
    #define IRQ_EVT_GPINT4     4
    #define IRQ_EVT_EXTINT5    5
    #define IRQ_EVT_GPINT5     5
    #define IRQ_EVT_EXTINT6    6
    #define IRQ_EVT_GPINT6     6
    #define IRQ_EVT_EXTINT7    7
    #define IRQ_EVT_GPINT7     7
    #define IRQ_EVT_EDMAINT    8
    #define IRQ_EVT_EMUDTDMA   9
    #define IRQ_EVT_EMURTDXRX  10
    #define IRQ_EVT_EMURTDXTX  11
    #define IRQ_EVT_XINT0      12
    #define IRQ_EVT_RINT0      13
    #define IRQ_EVT_XINT1      14
    #define IRQ_EVT_RINT1      15
    #define IRQ_EVT_GPINT0     16
    #define IRQ_EVT_TINT2      19
    #define IRQ_EVT_I2CINT0    22
    #define IRQ_EVT_MACINT     24

   #if !(CHIP_6412)
    #define IRQ_EVT_VINT0      25
    #define IRQ_EVT_VINT1      26
   #endif

   #if (CHIP_DM642)
    #define IRQ_EVT_VINT2      27
   #endif

   #if !(CHIP_6412)
    #define IRQ_EVT_AXINT0     28
    #define IRQ_EVT_ARINT0     29
   #endif

  #else

    #define IRQ_EVT_DSPINT     0
    #define IRQ_EVT_TINT0      1
    #define IRQ_EVT_TINT1      2
    #define IRQ_EVT_SDINT      3
    #define IRQ_EVT_SDINTA     3
    #define IRQ_EVT_EXTINT4    4
    #define IRQ_EVT_GPINT4     4
    #define IRQ_EVT_EXTINT5    5
    #define IRQ_EVT_GPINT5     5
    #define IRQ_EVT_EXTINT6    6
    #define IRQ_EVT_GPINT6     6
    #define IRQ_EVT_EXTINT7    7
    #define IRQ_EVT_GPINT7     7
    #define IRQ_EVT_EDMAINT    8
    #define IRQ_EVT_DMAINT0    8
    #define IRQ_EVT_EMUDTDMA   9
    #define IRQ_EVT_DMAINT1    9
    #define IRQ_EVT_EMURTDXRX  10
    #define IRQ_EVT_DMAINT2    10
    #define IRQ_EVT_EMURTDXTX  11
    #define IRQ_EVT_DMAINT3    11
    #define IRQ_EVT_XINT0      12
    #define IRQ_EVT_RINT0      13
    #define IRQ_EVT_XINT1      14
    #define IRQ_EVT_RINT1      15
    #define IRQ_EVT_GPINT0     16
    #define IRQ_EVT_XINT2      17
    #define IRQ_EVT_RINT2      18
    #define IRQ_EVT_TINT2      19
    #define IRQ_EVT_SDINTB     20
    #define IRQ_EVT_PCIWAKE    21
    #define IRQ_EVT_MDIO       21
    #define IRQ_EVT_QDMAERR    22
    #define IRQ_EVT_I2CINT0    22 /* 6713 */
    #define IRQ_EVT_UINT       23
    #define IRQ_EVT_I2CINT1    23 /* 6713 */
    #define IRQ_EVT_I2CINT2    23 
    #define IRQ_EVT_I2CINT3    22 
    #define IRQ_EVT_I2CINT4    23 

    #define IRQ_EVT_MACINT     24 /* DM642 */
    #define IRQ_EVT_VINT0      25 /* DM642 */
    #define IRQ_EVT_VINT1      26 /* DM642 */
    #define IRQ_EVT_VINT2      27 /* DM642 */
    #define IRQ_EVT_AXINT0     28 /* 6713 / DM642 */
    #define IRQ_EVT_ARINT0     29 /* 6713 / DM642 */
    #define IRQ_EVT_AXINT3     IRQ_EVT_EXTINT4 /* 6713 */
    #define IRQ_EVT_ARINT3     IRQ_EVT_EXTINT5 /* 6713 */
    #define IRQ_EVT_VCPINT     30
    #define IRQ_EVT_AXINT1     30 /* 6713 */

    #define IRQ_EVT_AXINT2     30 /* 6713 */
    #define IRQ_EVT_AXINT4     IRQ_EVT_EXTINT6
    #define IRQ_EVT_TCPINT     31
    #define IRQ_EVT_ARINT1     31 /* 6713 */

    #define IRQ_EVT_ARINT2     31 /* 6713 */
    #define IRQ_EVT_ARINT4     IRQ_EVT_EXTINT7

  #endif

#endif
/* interrupt masks */
#define IRQ_MASK_NA 0x00000000
#define IRQ_MASK_00 0x00000001
#define IRQ_MASK_01 0x00000002
#define IRQ_MASK_02 0x00000004
#define IRQ_MASK_03 0x00000008
#define IRQ_MASK_04 0x00000010
#define IRQ_MASK_05 0x00000020
#define IRQ_MASK_06 0x00000040
#define IRQ_MASK_07 0x00000080
#define IRQ_MASK_08 0x00000100
#define IRQ_MASK_09 0x00000200
#define IRQ_MASK_10 0x00000400
#define IRQ_MASK_11 0x00000800
#define IRQ_MASK_12 0x00001000
#define IRQ_MASK_13 0x00002000
#define IRQ_MASK_14 0x00004000
#define IRQ_MASK_15 0x00008000

/* defines used with the dispatcher functions */
#define IRQ_CCMASK_NONE        0x00000001u
#define IRQ_CCMASK_PCC_MAPPED  0x00000000u
#define IRQ_CCMASK_PCC_ENABLE  0x00000040u
#define IRQ_CCMASK_PCC_FREEZE  0x00000060u
#define IRQ_CCMASK_PCC_BYPASS  0x00000080u
#define IRQ_CCMASK_DCC_MAPPED  0x00000000u
#define IRQ_CCMASK_DCC_ENABLE  0x00000008u
#define IRQ_CCMASK_DCC_FREEZE  0x0000000Cu
#define IRQ_CCMASK_DCC_BYPASS  0x00000010u
#define IRQ_CCMASK_DEFAULT     IRQ_CCMASK_NONE
#define IRQ_IEMASK_SELF        0x80000000u
#define IRQ_IEMASK_ALL         0x0000FFFFu
#define IRQ_IEMASK_DEFAULT     IRQ_IEMASK_SELF


/* private stuff */
#define _IRQ_DISPATCHTABLE_CNT   (IRQ_INT_CNT)
#define _IRQ_EVENT2INTTABLE_CNT  (IRQ_EVENT_CNT+1)
#define _IRQ_INT2EVENTTABLE_CNT  (IRQ_INT_CNT)


/******************************************************************************\
* global typedef declarations
\******************************************************************************/
typedef struct {
  void   *funcAddr;
  Uint32 ieMask;
  Uint32 ccMask;
  Uint32 funcArg;
} _IRQ_Dispatch;

typedef struct {
  void   *funcAddr;
  Uint32 funcArg;
  Uint32 ccMask;
  Uint32 ieMask;
} IRQ_Config;


/******************************************************************************\
* global variable declarations
\******************************************************************************/

/* private vars */
extern far Uint32 _IRQ_eventTable[IRQ_EVENT_CNT+1];
extern far Uint32 _IRQ_intTable[IRQ_INT_CNT];
extern far _IRQ_Dispatch _IRQ_internalDispatchTable[_IRQ_DISPATCHTABLE_CNT];
extern far _IRQ_Dispatch *_IRQ_dispatchTable;

/******************************************************************************\
* global function declarations
\******************************************************************************/

/* private functions */
CSLAPI void _IRQ_init(Uint32 biosPresent, _IRQ_Dispatch *dispatchTable);

/* API functions */
CSLAPI void IRQ_map(Uint32 eventId, Uint32 intNumber);
CSLAPI void *IRQ_setVecs(void *vecs);
CSLAPI Uint32 IRQ_biosPresent();
CSLAPI void IRQ_hook(int intNum, void *func);

/* These functions only work with the DSP/BIOS HWI dispatcher */
CSLAPI void IRQ_config(Uint32 eventId, IRQ_Config *config);
CSLAPI void IRQ_configArgs(Uint32 eventId, void *funcAddr, Uint32 funcArg,
  Uint32 ccMask, Uint32 ieMask);
CSLAPI void IRQ_getConfig(Uint32 eventId, IRQ_Config *config);
CSLAPI Uint32 IRQ_getArg(Uint32 eventId);
CSLAPI void IRQ_setArg(Uint32 eventId, Uint32 arg);


/******************************************************************************\
* inline function declarations
\******************************************************************************/
IDECL void IRQ_enable(Uint32 eventId);
IDECL Uint32 IRQ_disable(Uint32 eventId);
IDECL void IRQ_restore(Uint32 eventId, Uint32 ie);
IDECL void IRQ_set(Uint32 eventId);
IDECL void IRQ_clear(Uint32 eventId);
IDECL Uint32 IRQ_test(Uint32 eventId);
IDECL void IRQ_reset(Uint32 eventId);
IDECL void IRQ_resetAll();

IDECL void IRQ_globalEnable();
IDECL Uint32 IRQ_globalDisable();
IDECL void IRQ_globalRestore(Uint32 gie);

IDECL void IRQ_nmiEnable();
IDECL void IRQ_nmiDisable();


/******************************************************************************\
* inline function definitions
\******************************************************************************/
#ifdef USEDEFS
/*----------------------------------------------------------------------------*/
IDEF void IRQ_enable(Uint32 eventId) {
  IER |= _IRQ_eventTable[eventId];
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 IRQ_disable(Uint32 eventId) {
  Uint32 ie = IER & _IRQ_eventTable[eventId];
  IER &= ~_IRQ_eventTable[eventId];
  return ie;
}
/*----------------------------------------------------------------------------*/
IDEF void IRQ_restore(Uint32 eventId, Uint32 ie) {
  if (ie) {
    IER |= _IRQ_eventTable[eventId];
  } else {
    IER &= ~_IRQ_eventTable[eventId];
  }
}
/*----------------------------------------------------------------------------*/
IDEF void IRQ_set(Uint32 eventId) {
  ISR = _IRQ_eventTable[eventId];
}
/*----------------------------------------------------------------------------*/
IDEF void IRQ_clear(Uint32 eventId) {
  ICR = _IRQ_eventTable[eventId];
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 IRQ_test(Uint32 eventId) {
  return (Uint32)((IFR & _IRQ_eventTable[eventId]) ? 1 : 0);
}
/*----------------------------------------------------------------------------*/
IDEF void IRQ_globalEnable() {
  CHIP_FSET(CSR,GIE,1);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 IRQ_globalDisable() {
  Uint32 gie = CHIP_FGET(CSR,GIE);
  CHIP_FSET(CSR,GIE,0);
  return gie;
}
/*----------------------------------------------------------------------------*/
IDEF void IRQ_globalRestore(Uint32 gie) {
  CHIP_FSET(CSR,GIE,gie);
}
/*----------------------------------------------------------------------------*/
IDEF void IRQ_reset(Uint32 eventId) {
  IER &= ~_IRQ_eventTable[eventId];
  ICR = _IRQ_eventTable[eventId];
}
/*----------------------------------------------------------------------------*/
IDEF void IRQ_resetAll() {
  CHIP_FSET(CSR,GIE,0);
  CHIP_CRSET(IER,0x00000000);
  CHIP_CRSET(ICR,0xFFFFFFFF);
}
/*----------------------------------------------------------------------------*/
IDEF void IRQ_nmiEnable() {
  IER |= 0x00000002;
}
/*----------------------------------------------------------------------------*/
IDEF void IRQ_nmiDisable() {
  IER &= ~0x00000002;
}
/*----------------------------------------------------------------------------*/
#endif /* USEDEFS */


#endif /* IRQ_SUPPORT */
#endif /* _CSL_IRQ_H_ */
/******************************************************************************\
* End of csl_irq.h
\******************************************************************************/

