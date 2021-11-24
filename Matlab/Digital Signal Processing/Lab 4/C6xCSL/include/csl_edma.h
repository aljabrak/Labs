/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_edma.h
* DATE CREATED.. 06/11/1999
* LAST MODIFIED. 14/9/2005  Modified EDMA_getChannel and EDMA_setEvtPolarity to return 
*							proper values and can set polarities properly respectively. 
*				 08/13/2004 Modified tccAllocTable type from static to global fn.
*                08/02/2004 - Adding support for C6418
*                04/16/2004 Modified tccAllocTable[0] entry to 0.
*                02/09/2004 Removed volatile variable type from EDMA_chain inline fn.
*                06/17/2003 added support for 6712C
*                05/28/2003 added support for 6711C
*                02/15/2002 added EDMA channel events 6713/DM642 - EDMA_map()
*                04/16/2001
\******************************************************************************/
#ifndef _CSL_EDMA_H_
#define _CSL_EDMA_H_

#include <csl_chip.h>
#include <csl_irq.h>
#include <csl_edmahal.h>


#if (EDMA_SUPPORT)
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

#ifdef  _EDMA_MOD_
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
#define EDMA_CHA_CNT              (_EDMA_CHA_CNT)
#define EDMA_TABLE_CNT            (_EDMA_LINK_CNT)
#define EDMA_ALLOC_ANY            (-1)

#define EDMA_OPEN_RESET           (0x00000001)
#define EDMA_OPEN_ENABLE          (0x00000002)


#if(CHIP_6201|CHIP_6202|CHIP_6203|CHIP_6204|CHIP_6205|CHIP_6701|C11_SUPPORT)
  #define EDMA_CHA_ANY      -1
  #define EDMA_CHA_DSPINT   0
  #define EDMA_CHA_TINT0    1
  #define EDMA_CHA_TINT1    2
  #define EDMA_CHA_SDINT    3
  #define EDMA_CHA_EXTINT4  4
  #define EDMA_CHA_EXTINT5  5
  #define EDMA_CHA_EXTINT6  6
  #define EDMA_CHA_EXTINT7  7
  #define EDMA_CHA_TCC8     8
  #define EDMA_CHA_TCC9     9
  #define EDMA_CHA_TCC10    10
  #define EDMA_CHA_TCC11    11
  #define EDMA_CHA_XEVT0    12
  #define EDMA_CHA_REVT0    13
  #define EDMA_CHA_XEVT1    14
  #define EDMA_CHA_REVT1    15
#endif
#if (CHIP_6711C || CHIP_6712C)
  #define EDMA_CHA_GPINT4    4
  #define EDMA_CHA_GPINT5    5
  #define EDMA_CHA_GPINT6    6
  #define EDMA_CHA_GPINT7    7
  #define EDMA_CHA_GPINT2   10
#endif

#if (CHIP_6713 | CHIP_DA610 | CHIP_6414 | CHIP_6415 | CHIP_6416 | \
     CHIP_6411 | CHIP_6410 | CHIP_6413 | CHIP_6418)
  #define EDMA_CHA_ANY      -1
  #define EDMA_CHA_DSPINT    0
  #define EDMA_CHA_TINT0     1
  #define EDMA_CHA_TINT1     2
  #define EDMA_CHA_SDINT     3
  #define EDMA_CHA_EXTINT4   4
  #define EDMA_CHA_GPINT4    4
  #define EDMA_CHA_EXTINT5   5
  #define EDMA_CHA_GPINT5    5
  #define EDMA_CHA_EXTINT6   6
  #define EDMA_CHA_GPINT6    6
  #define EDMA_CHA_EXTINT7   7
  #define EDMA_CHA_GPINT7    7
  #define EDMA_CHA_TCC8      8
  #define EDMA_CHA_GPINT0    8
  #define EDMA_CHA_TCC9      9
  #define EDMA_CHA_GPINT1    9
  #define EDMA_CHA_TCC10    10
  #define EDMA_CHA_GPINT2   10
  #define EDMA_CHA_TCC11    11
  #define EDMA_CHA_GPINT3   11
  #define EDMA_CHA_XEVT0    12
  #define EDMA_CHA_REVT0    13
  #define EDMA_CHA_XEVT1    14
  #define EDMA_CHA_REVT1    15

/* Individual mappings for next few events are specified under #ifdefs below. */

  #define EDMA_CHA_GPINT8   48
  #define EDMA_CHA_GPINT9   49
  #define EDMA_CHA_GPINT10  50
  #define EDMA_CHA_GPINT11  51
  #define EDMA_CHA_GPINT12  52
  #define EDMA_CHA_GPINT13  53
  #define EDMA_CHA_GPINT14  54
  #define EDMA_CHA_GPINT15  55
#endif


/* 3rd MCBSP/ PCI / UTOPIA / VCP / TCP channel numbers for EDMA_open() */
#if (CHIP_6414 || CHIP_6415 || CHIP_6416 )
  #define EDMA_CHA_XEVT2    17
  #define EDMA_CHA_REVT2    18
  #define EDMA_CHA_TINT2    19
  #define EDMA_CHA_SDINTB   20
  #define EDMA_CHA_PCI      21
  #define EDMA_CHA_VCPREVT  28
  #define EDMA_CHA_VCPXEVT  29
  #define EDMA_CHA_TCPREVT  30
  #define EDMA_CHA_TCPXEVT  31
  #define EDMA_CHA_UREVT    32
  #define EDMA_CHA_UREVT0   32
  #define EDMA_CHA_UREVT1   33
  #define EDMA_CHA_UREVT2   34
  #define EDMA_CHA_UREVT3   35
  #define EDMA_CHA_UREVT4   36
  #define EDMA_CHA_UREVT5   37
  #define EDMA_CHA_UREVT6   38
  #define EDMA_CHA_UREVT7   39
  #define EDMA_CHA_UXEVT    40
  #define EDMA_CHA_UXEVT0   40
  #define EDMA_CHA_UXEVT1   41
  #define EDMA_CHA_UXEVT2   42
  #define EDMA_CHA_UXEVT3   43
  #define EDMA_CHA_UXEVT4   44
  #define EDMA_CHA_UXEVT5   45
  #define EDMA_CHA_UXEVT6   46
  #define EDMA_CHA_UXEVT7   47
#endif

/* 2 MCASPs - 2 I2Cs channels */
#if (CHIP_6713 || CHIP_DA610)
  #define EDMA_CHA_AXEVTE0  32
  #define EDMA_CHA_AXEVTO0  33
  #define EDMA_CHA_AXEVT0   34
  #define EDMA_CHA_AREVTE0  35
  #define EDMA_CHA_AREVTO0  36
  #define EDMA_CHA_AREVT0   37
  #define EDMA_CHA_AXEVTE1  38
  #define EDMA_CHA_AXEVTO1  39
  #define EDMA_CHA_AXEVT1   40
  #define EDMA_CHA_AREVTE1  41
  #define EDMA_CHA_AREVTO1  42
  #define EDMA_CHA_AREVT1   43
  #define EDMA_CHA_ICREVT0  44
  #define EDMA_CHA_ICXEVT0  45
  #define EDMA_CHA_ICREVT1  46
  #define EDMA_CHA_ICXEVT1  47
#endif

#if (CHIP_6410 || CHIP_6413| CHIP_6418)
  #define EDMA_CHA_TINT2    19

 #if (CHIP_6418)
  #define EDMA_CHA_VCPREVT0 28  
  #define EDMA_CHA_VCPXEVT0 29  
 #endif

  #define EDMA_CHA_AXEVTE0  32  
  #define EDMA_CHA_AXEVTO0  33  
  #define EDMA_CHA_AXEVT0   34  
  #define EDMA_CHA_AREVTE0  35  
  #define EDMA_CHA_AREVTO0  36  
  #define EDMA_CHA_AREVT0   37  
  #define EDMA_CHA_AXEVTE1  38  
  #define EDMA_CHA_AXEVTO1  39  
  #define EDMA_CHA_AXEVT1   40  
  #define EDMA_CHA_AREVTE1  41  
  #define EDMA_CHA_AREVTO1  42  
  #define EDMA_CHA_AREVT1   43  
  #define EDMA_CHA_ICREVT0  44  
  #define EDMA_CHA_ICXEVT0  45  
  #define EDMA_CHA_ICREVT1  46  
  #define EDMA_CHA_ICXEVT1  47  
#endif

#if (CHIP_DM642 || CHIP_DM641 || CHIP_DM640 || CHIP_6412)
  #define EDMA_CHA_ANY      -1

 #if !(CHIP_DM640)
  #define EDMA_CHA_DSPINT   0
 #endif

  #define EDMA_CHA_TINT0    1
  #define EDMA_CHA_TINT1    2
  #define EDMA_CHA_SDINT    3
  #define EDMA_CHA_EXTINT4  4
  #define EDMA_CHA_GPINT4   4
  #define EDMA_CHA_EXTINT5  5
  #define EDMA_CHA_GPINT5   5
  #define EDMA_CHA_EXTINT6  6
  #define EDMA_CHA_GPINT6   6
  #define EDMA_CHA_EXTINT7  7
  #define EDMA_CHA_GPINT7   7
  #define EDMA_CHA_GPINT0   8
  #define EDMA_CHA_TCC8     8
  #define EDMA_CHA_GPINT1   9
  #define EDMA_CHA_TCC9     9
  #define EDMA_CHA_GPINT2   10
  #define EDMA_CHA_TCC10    10
  #define EDMA_CHA_GPINT3   11
  #define EDMA_CHA_TCC11    11
  #define EDMA_CHA_XEVT0    12
  #define EDMA_CHA_REVT0    13
  #define EDMA_CHA_XEVT1    14
  #define EDMA_CHA_REVT1    15

/* Note: EDMA_CHA_TCC8, EDMA_CHA_TCC9, EDMA_CHA_TCC10 and EDMA_CHA_TCC11 are 
   NOT defined here, but they are included here for C64x consistency purposes */

 #if (CHIP_DM642 | CHIP_DM641 | CHIP_DM640)
  #define EDMA_CHA_VP0EVTYA 16
  #define EDMA_CHA_VP0EVTUA 17
  #define EDMA_CHA_VP0EVTVA 18
 #endif

  #define EDMA_CHA_TINT2    19

 #if (CHIP_DM642)
  #define EDMA_CHA_VP0EVTYB 24
  #define EDMA_CHA_VP0EVTUB 25
  #define EDMA_CHA_VP0EVTVB 26
 #endif

 #if !(CHIP_6412)
  #define EDMA_CHA_AXEVTE0  32
  #define EDMA_CHA_AXEVTO0  33
  #define EDMA_CHA_AXEVT0   34
  #define EDMA_CHA_AREVTE0  35
  #define EDMA_CHA_AREVTO0  36
  #define EDMA_CHA_AREVT0   37
 #endif

 #if (CHIP_DM642)
  #define EDMA_CHA_VP1EVTYB 38
  #define EDMA_CHA_VP1EVTUB 39
  #define EDMA_CHA_VP1EVTVB 40
  #define EDMA_CHA_VP2EVTYB 41
  #define EDMA_CHA_VP2EVTUB 42
  #define EDMA_CHA_VP2EVTVB 43
 #endif
 
  #define EDMA_CHA_ICREVT0  44
  #define EDMA_CHA_ICXEVT0  45

  #define EDMA_CHA_GPINT8   48
  #define EDMA_CHA_GPINT9   49
  #define EDMA_CHA_GPINT10  50
  #define EDMA_CHA_GPINT11  51
  #define EDMA_CHA_GPINT12  52
  #define EDMA_CHA_GPINT13  53
  #define EDMA_CHA_GPINT14  54
  #define EDMA_CHA_GPINT15  55


 #if (CHIP_DM642 | CHIP_DM641)
  #define EDMA_CHA_VP1EVTYA 56
  #define EDMA_CHA_VP1EVTUA 57
  #define EDMA_CHA_VP1EVTVA 58
 #endif

 #if (CHIP_DM642)
  #define EDMA_CHA_VP2EVTYA 59
  #define EDMA_CHA_VP2EVTUA 60
  #define EDMA_CHA_VP2EVTVA 61
 #endif

#endif

#define _EDMA_TYPE_C   (0x80000000)
#define _EDMA_TYPE_T   (0x40000000)
#define _EDMA_TYPE_Q   (0x20000000)
#define _EDMA_TYPE_S   (0x10000000)


#define _EDMA_MK_HANDLE(base,index,flags) (EDMA_Handle)(\
  ((base)&0x0000FFFF)|(((index)<<16)&0x00FF0000)|((flags)&0xFF000000)\
)

#define EDMA_HQDMA    _EDMA_MK_HANDLE(0x00000000,0,_EDMA_TYPE_Q)
#define EDMA_HQSDMA   _EDMA_MK_HANDLE(0x00000000,0,_EDMA_TYPE_S)
#define EDMA_HINV     _EDMA_MK_HANDLE(0x00000000,0,0)

#define EDMA_HNULL    _EDMA_MK_HANDLE(_EDMA_NULL_PARAM,0,_EDMA_TYPE_T)
#define NULL_FUNC     0

/* Priority Queues */
#define EDMA_Q0       0
#define EDMA_Q1       1
#define EDMA_Q2       2
#define EDMA_Q3       3

/* Event Polarity */
#define EDMA_EVT_LOWHIGH   0
#define EDMA_EVT_HIGHLOW   1

/* Chaining Flag */
#define EDMA_TCC_SET       1
#define EDMA_ATCC_SET      1

/******************************************************************************\
* global typedef declarations
\******************************************************************************/
typedef Uint32 EDMA_Handle;

typedef struct {
  Uint32 opt;
  Uint32 src;
  Uint32 cnt;
  Uint32 dst;
  Uint32 idx;
  Uint32 rld;
} EDMA_Config;

typedef void (*EDMA_IntHandler)(int tccNum);

/******************************************************************************\
* global variable declarations
\******************************************************************************/
#define EDMA_hNull EDMA_HNULL

extern far Uint8 tccAllocTable[64];

/******************************************************************************\
* global function declarations
\******************************************************************************/
CSLAPI void EDMA_reset(EDMA_Handle hEdma);
CSLAPI void EDMA_resetAll();

CSLAPI EDMA_Handle EDMA_open(int chaNum, Uint32 flags);
CSLAPI void EDMA_close(EDMA_Handle hEdma);
CSLAPI EDMA_Handle EDMA_allocTable(int tableNum);
CSLAPI void EDMA_freeTable(EDMA_Handle hEdma);

CSLAPI int EDMA_allocTableEx(int cnt, EDMA_Handle *array);
CSLAPI void EDMA_freeTableEx(int cnt, EDMA_Handle *array);

CSLAPI void EDMA_clearPram(Uint32 val);

CSLAPI int EDMA_intAlloc(int tcc);
CSLAPI void EDMA_intFree(int tcc);
/* 6713? */

#if (CHIP_6713 || CHIP_DA610 || CHIP_6711C || CHIP_6712C)
CSLAPI int EDMA_map(int eventNum,int chaNum);
#endif

CSLAPI EDMA_IntHandler EDMA_intHook(int tccNum, EDMA_IntHandler funcAddr);
CSLAPI void EDMA_intDefaultHandler(int tccNum);
CSLAPI void EDMA_intDispatcher();

/******************************************************************************\
* inline function declarations
\******************************************************************************/
IDECL Uint32 EDMA_getScratchAddr();
IDECL Uint32 EDMA_getScratchSize();
IDECL Uint32 EDMA_getPriQStatus();
#if (C64_SUPPORT)
IDECL void   EDMA_setPriQLength(Uint32 priNum, Uint32 length);
IDECL void   EDMA_resetPriQLength(Uint32 priNum);
#endif

IDECL void   EDMA_enableChannel(EDMA_Handle hEdma);
IDECL void   EDMA_disableChannel(EDMA_Handle hEdma);
IDECL void   EDMA_setChannel(EDMA_Handle hEdma);
IDECL Uint32 EDMA_getChannel(EDMA_Handle hEdma);
IDECL void   EDMA_clearChannel(EDMA_Handle hEdma);
#if (C64_SUPPORT)
IDECL void   EDMA_setEvtPolarity(EDMA_Handle hEdma,int polarity);
#endif
IDECL Uint32 EDMA_getTableAddress(EDMA_Handle hEdma);

IDECL void   EDMA_intEnable(Uint32 tccIntNum);
IDECL void   EDMA_intDisable(Uint32 tccIntNum);
IDECL void   EDMA_intClear(Uint32 tccIntNum);
IDECL Uint32 EDMA_intTest(Uint32 tccIntNum);
IDECL void   EDMA_intReset(Uint32 tccIntNum);
IDECL void   EDMA_intResetAll();

IDECL void   EDMA_link(EDMA_Handle parent, EDMA_Handle child);

IDECL void EDMA_config(EDMA_Handle hEdma, EDMA_Config *config);
IDECL void EDMA_configArgs(EDMA_Handle hEdma, Uint32 opt, Uint32 src,
  Uint32 cnt, Uint32 dst, Uint32 idx, Uint32 rld);
IDECL void EDMA_getConfig(EDMA_Handle hEdma, EDMA_Config *config);

IDECL void EDMA_qdmaConfig(EDMA_Config *config);
IDECL void EDMA_qdmaConfigArgs(Uint32 opt, Uint32 src, Uint32 cnt, Uint32 dst,
  Uint32 idx);
IDECL void EDMA_qdmaGetConfig(EDMA_Config *config);

IDECL void EDMA_enableChaining(EDMA_Handle hEdma);
IDECL void EDMA_disableChaining(EDMA_Handle hEdma);
IDECL  void EDMA_chain(EDMA_Handle parent, EDMA_Handle nextChannel,int tccflag, int atccflag);

/******************************************************************************\
* inline function definitions
\******************************************************************************/
#ifdef USEDEFS
/*----------------------------------------------------------------------------*/
IDEF Uint32 EDMA_getScratchAddr() {
  return (Uint32)_EDMA_SCRATCH_START;
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 EDMA_getScratchSize() {
  return (Uint32)_EDMA_SCRATCH_SIZE;
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 EDMA_getPriQStatus() {
  return (Uint32)EDMA_RGET(PQSR);
}
/*----------------------------------------------------------------------------*/
#if (C64_SUPPORT)
IDEF void EDMA_setPriQLength(Uint32 priNum, Uint32 length) {
  if (priNum == 0x0) {
   EDMA_RSET(PQAR0,(0x00000007 & length));
   } else {
          if (priNum == 0x1) {
           EDMA_RSET(PQAR1,(0x00000007 & length));
          }else {
                if (priNum == 0x2) {
                EDMA_RSET(PQAR2,(0x00000007 & length));
                } else {
                       if (priNum == 0x3) {
                       EDMA_RSET(PQAR3,(0x00000007 & length));
                       }
                  }
           }
    }
}
/*----------------------------------------------------------------------------*/

IDEF void EDMA_resetPriQLength(Uint32 priNum) {
 if (priNum == 0x0) {
   EDMA_FSET(PQAR0,PQA,EDMA_PQAR0_PQA_DEFAULT);
   } else {
          if (priNum == 0x1) {
          EDMA_FSET(PQAR1,PQA,EDMA_PQAR1_PQA_DEFAULT);
          } else {
                 if (priNum == 0x2) {
                 EDMA_FSET(PQAR2,PQA,EDMA_PQAR2_PQA_DEFAULT);
                 }else {
                      if (priNum == 0x3) {
                      EDMA_FSET(PQAR3,PQA,EDMA_PQAR3_PQA_DEFAULT);
                       }
                  }
           }
   }
}
#endif
/*----------------------------------------------------------------------------*/
IDEF void EDMA_enableChannel(EDMA_Handle hEdma) {

  int gie;
  int chaNum = (hEdma & 0x00FF0000)>>16;

  gie = IRQ_globalDisable();
  #if (C64_SUPPORT)
    if (chaNum < 32) EDMA_RSET(EERL,EDMA_RGET(EERL) | (1<<chaNum));
    else EDMA_RSET(EERH,EDMA_RGET(EERH) | (1<<(chaNum-32)));
  #else
    EDMA_RSET(EER,EDMA_RGET(EER) | (1<<chaNum));
  #endif
  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void EDMA_enableChaining(EDMA_Handle hEdma) {

  int gie;
  int chaNum = (hEdma & 0x00FF0000)>>16;

  gie = IRQ_globalDisable();
  #if (C64_SUPPORT)
    if (chaNum < 32) EDMA_RSET(CCERL,EDMA_RGET(CCERL) | (1<<chaNum));
    else EDMA_RSET(CCERH,EDMA_RGET(CCERH) | (1<<(chaNum-32)));
  #else

    EDMA_RSET(CCER,EDMA_RGET(CCER) | (1<<chaNum));
  #endif
  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void EDMA_chain(EDMA_Handle parent, EDMA_Handle nextChannel,int tccflag, int atccflag) {
  #if (C64_SUPPORT)
  Uint32 tccm,tcc;
  #endif
  int TccNum = (nextChannel & 0x00FF0000)>>16;
  int gie;

  gie = IRQ_globalDisable();

 if (tccflag) {
  #if (C64_SUPPORT) /* SET TCCM and TCC fields */
   if (TccNum < 16) {  tccm = 0 ; tcc = TccNum;}
   else {
        if ( TccNum  > 15 && TccNum < 32 ) { tccm = 1 ; tcc = TccNum-16;}
         else  {
              if ( TccNum  > 31 && TccNum < 48 ) { tccm = 2 ; tcc = TccNum-32;}
              else {   /* channel > 47 */
                     tccm = 3 ; tcc = TccNum-48;
                   }
         }
    }
      EDMA_FSETH(parent,OPT,TCCM,tccm);
      EDMA_FSETH(parent,OPT,TCC,tcc);
      EDMA_FSETH(parent,OPT,TCINT,1);
  #else
    EDMA_FSETH(parent,OPT,TCC,TccNum);
    EDMA_FSETH(parent,OPT,TCINT,1);
  #endif
}
/* ATCC */
if (atccflag) {
    #if C64_SUPPORT
    EDMA_FSETH(parent,OPT,ATCC,TccNum);
    EDMA_FSETH(parent,OPT,ATCINT,1);
    #endif
}
  tccAllocTable[TccNum] = 1;
  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void EDMA_disableChannel(EDMA_Handle hEdma) {

  int chaNum = (hEdma & 0x00FF0000)>>16;
  int gie;

  gie = IRQ_globalDisable();

  #if (C64_SUPPORT)
    if (chaNum < 32) EDMA_RSET(EERL,EDMA_RGET(EERL) & ~(1<<chaNum));
    else EDMA_RSET(EERH,EDMA_RGET(EERH) & ~(1<<(chaNum-32)));
  #else
    EDMA_RSET(EER,EDMA_RGET(EER) & ~(1<<chaNum));
  #endif
  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void EDMA_disableChaining(EDMA_Handle hEdma) {

 int chaNum = (hEdma & 0x00FF0000)>>16;
 int gie;

  gie = IRQ_globalDisable();
  #if (C64_SUPPORT)
    if (chaNum < 32) EDMA_RSET(CCERL,EDMA_RGET(CCERL) & ~(1<<chaNum));
    else EDMA_RSET(CCERH,EDMA_RGET(CCERH) & ~(1<<(chaNum-32)));
  #else
    EDMA_RSET(CCER,EDMA_RGET(CCER) & ~(1<<chaNum));
  #endif
  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void EDMA_setChannel(EDMA_Handle hEdma) {

  int chaNum = (hEdma & 0x00FF0000)>>16;

  #if (C64_SUPPORT)
    if (chaNum < 32) EDMA_RSET(ESRL,1<<chaNum);
    else EDMA_RSET(ESRH,1<<(chaNum-32));
  #else
    EDMA_RSET(ESR,1<<chaNum);
  #endif
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 EDMA_getChannel(EDMA_Handle hEdma) {

  int chaNum = (hEdma & 0x00FF0000)>>16;

  #if (C64_SUPPORT)
    if (chaNum < 32) return (Uint32)(((EDMA_RGET(ERL) >> chaNum) & 1)==1);
    else return (Uint32)(((EDMA_RGET(ERH) >> (chaNum-32)) & 1)==1);
    
  #else
    return (Uint32)(((EDMA_RGET(ER) >>chaNum) & 1)==1);
  #endif
}
/*----------------------------------------------------------------------------*/
IDEF void EDMA_clearChannel(EDMA_Handle hEdma) {

  int chaNum = (hEdma & 0x00FF0000)>>16;

  #if (C64_SUPPORT)
    if (chaNum < 32) EDMA_RSET(ECRL,1<<chaNum);
    else EDMA_RSET(ECRH,1<<(chaNum-32));
  #else
    EDMA_RSET(ECR,1<<chaNum);
  #endif
}
/*----------------------------------------------------------------------------*/
#if (C64_SUPPORT)
IDEF void   EDMA_setEvtPolarity(EDMA_Handle hEdma,int polarity) {

    int chaNum = (hEdma & 0x00FF0000)>>16;

  #if (C64_SUPPORT)
    if (chaNum < 32) EDMA_RSET(EPRL,(polarity<<chaNum) | EDMA_RGET(EPRL));
    else EDMA_RSET(EPRH,(polarity<<(chaNum-32)) | EDMA_RGET(EPRH));
  #endif
}
#endif
/*----------------------------------------------------------------------------*/
IDEF Uint32 EDMA_getTableAddress(EDMA_Handle hEdma) {

  return (hEdma&0x0000FFFF)+_EDMA_PRAM_START;
}
/*----------------------------------------------------------------------------*/
IDEF void EDMA_intEnable(Uint32 tccIntNum) {
  int gie;

  gie = IRQ_globalDisable();

  #if (C64_SUPPORT)
    if (tccIntNum < 32) EDMA_RSET(CIERL,EDMA_RGET(CIERL) | (1<<tccIntNum));
    else EDMA_RSET(CIERH,EDMA_RGET(CIERH) | (1<<(tccIntNum-32)));
  #else
    EDMA_RSET(CIER,EDMA_RGET(CIER) | (1<<tccIntNum));
  #endif

  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void EDMA_intDisable(Uint32 tccIntNum) {
  int gie;

  gie = IRQ_globalDisable();

  #if (C64_SUPPORT)
    if (tccIntNum < 32) EDMA_RSET(CIERL,EDMA_RGET(CIERL) & ~(1<<tccIntNum));
    else EDMA_RSET(CIERH,EDMA_RGET(CIERH) & ~(1<<(tccIntNum-32)));
  #else
    EDMA_RSET(CIER,EDMA_RGET(CIER) & ~(1<<tccIntNum));
  #endif

  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void EDMA_intClear(Uint32 tccIntNum) {

  #if (C64_SUPPORT)
    if (tccIntNum < 32) EDMA_RSET(CIPRL,1<<tccIntNum);
    else EDMA_RSET(CIPRH,1<<(tccIntNum-32));
  #else
    EDMA_RSET(CIPR,1<<tccIntNum);
  #endif
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 EDMA_intTest(Uint32 tccIntNum) {

  #if (C64_SUPPORT)
    if (tccIntNum < 32) return ((EDMA_RGET(CIPRL) & (1<<tccIntNum)) ? 1 : 0);
    else return ((EDMA_RGET(CIPRH) & (1<<(tccIntNum-32))) ? 1 : 0);
  #else
    return ((EDMA_RGET(CIPR) & (1<<tccIntNum)) ? 1 : 0);
  #endif
}
/*----------------------------------------------------------------------------*/
IDEF void EDMA_intReset(Uint32 tccIntNum) {
  int gie;

  gie = IRQ_globalDisable();

  /* disable then clear interrupt */
  #if (C64_SUPPORT)
    if (tccIntNum < 32) {
      EDMA_RSET(CIERL,EDMA_RGET(CIERL) & ~(1<<tccIntNum));
      EDMA_RSET(CIPRL,1<<tccIntNum);
    } else {
      EDMA_RSET(CIERH,EDMA_RGET(CIERH) & ~(1<<(tccIntNum-32)));
      EDMA_RSET(CIPRH,1<<(tccIntNum-32));
    }
  #else
    EDMA_RSET(CIER,EDMA_RGET(CIER) & ~(1<<tccIntNum));
    EDMA_RSET(CIPR,1<<tccIntNum);
  #endif
  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void EDMA_intResetAll() {

  int gie = IRQ_globalDisable();
  /* disable then clear all interrupts */

  #if (C64_SUPPORT)
    EDMA_RSET(CIERL, 0x00000000);
    EDMA_RSET(CIERH, 0x00000000);
    EDMA_RSET(CIPRL, 0xFFFFFFFF);
    EDMA_RSET(CIPRH, 0xFFFFFFFF);
  #else
    EDMA_RSET(CIER, 0x00000000);
    EDMA_RSET(CIPR, 0xFFFFFFFF);
  #endif

  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void EDMA_link(EDMA_Handle parent, EDMA_Handle child) {
  EDMA_FSETH(parent,RLD,LINK,child);
}
/*----------------------------------------------------------------------------*/
IDEF void EDMA_config(EDMA_Handle hEdma, EDMA_Config *config) {

  Uint32 gie;
  volatile Uint32 *base;
  register Uint32 x0,x1,x2,x3,x4,x5;

/* Test if QDMA handle was passed with CCS 1.2 */
 if ( hEdma == (0x20000000) || hEdma == (0x10000000)) {
        EDMA_qdmaConfig(config);
 }else{

  gie = IRQ_globalDisable();

  x0 = config->opt;
  x1 = config->src;
  x2 = config->cnt;
  x3 = config->dst;
  x4 = config->idx;
  x5 = config->rld;

  base = (volatile Uint32 *)((hEdma&0x0000FFFF)+_EDMA_PRAM_START);
  base[_EDMA_OPT_OFFSET] = 0x00000000;
  base[_EDMA_SRC_OFFSET] = x1;
  base[_EDMA_CNT_OFFSET] = x2;
  base[_EDMA_DST_OFFSET] = x3;
  base[_EDMA_IDX_OFFSET] = x4;
  base[_EDMA_RLD_OFFSET] = x5;
  base[_EDMA_OPT_OFFSET] = x0;
  IRQ_globalRestore(gie);
  }
}
/*----------------------------------------------------------------------------*/
IDEF void EDMA_configArgs(EDMA_Handle hEdma, Uint32 opt, Uint32 src,
  Uint32 cnt, Uint32 dst, Uint32 idx, Uint32 rld) {

  Uint32 gie;
  volatile Uint32 *base;
 /* Test if QDMA handle was passed with CCS 1.2 */
 if ( hEdma == (0x20000000) || hEdma == (0x10000000)) {
        EDMA_qdmaConfigArgs(opt, src, cnt, dst, idx);
 }else{
  gie = IRQ_globalDisable();
  base = (volatile Uint32*)((hEdma&0x0000FFFF)+_EDMA_PRAM_START);
  base[_EDMA_OPT_OFFSET] = 0x00000000;
  base[_EDMA_SRC_OFFSET] = src;
  base[_EDMA_CNT_OFFSET] = cnt;
  base[_EDMA_DST_OFFSET] = dst;
  base[_EDMA_IDX_OFFSET] = idx;
  base[_EDMA_RLD_OFFSET] = rld;
  base[_EDMA_OPT_OFFSET] = opt;
  IRQ_globalRestore(gie);
 }
}
/*----------------------------------------------------------------------------*/
IDEF void EDMA_getConfig(EDMA_Handle hEdma, EDMA_Config *config) {

  Uint32 gie;
  volatile Uint32 *base;
  register Uint32 x0,x1,x2,x3,x4,x5;

  gie = IRQ_globalDisable();

  base = (volatile Uint32 *)((hEdma&0x0000FFFF)+_EDMA_PRAM_START);
  x0 = base[_EDMA_OPT_OFFSET];
  x1 = base[_EDMA_SRC_OFFSET];
  x2 = base[_EDMA_CNT_OFFSET];
  x3 = base[_EDMA_DST_OFFSET];
  x4 = base[_EDMA_IDX_OFFSET];
  x5 = base[_EDMA_RLD_OFFSET];

  config->opt = x0;
  config->src = x1;
  config->cnt = x2;
  config->dst = x3;
  config->idx = x4;
  config->rld = x5;

  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void EDMA_qdmaConfig(EDMA_Config *config) {

  Uint32 gie;
  volatile Uint32 *base;
  register Uint32 x0,x1,x2,x3,x4;

  gie = IRQ_globalDisable();

  x0 = config->opt;
  x1 = config->src;
  x2 = config->cnt;
  x3 = config->dst;
  x4 = config->idx;

  base = (volatile Uint32 *)(_EDMA_QOPT_ADDR);
  base[_EDMA_QSRC_OFFSET]  = x1;
  base[_EDMA_QCNT_OFFSET]  = x2;
  base[_EDMA_QDST_OFFSET]  = x3;
  base[_EDMA_QIDX_OFFSET]  = x4;
  base[_EDMA_QSOPT_OFFSET] = x0;

  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void EDMA_qdmaConfigArgs(Uint32 opt, Uint32 src, Uint32 cnt, Uint32 dst,
  Uint32 idx) {

  Uint32 gie;
  volatile Uint32 *base;

  gie = IRQ_globalDisable();

  base = (volatile Uint32*)(_EDMA_QOPT_ADDR);
  base[_EDMA_QSRC_OFFSET]  = src;
  base[_EDMA_QCNT_OFFSET]  = cnt;
  base[_EDMA_QDST_OFFSET]  = dst;
  base[_EDMA_QIDX_OFFSET]  = idx;
  base[_EDMA_QSOPT_OFFSET] = opt;

  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void EDMA_qdmaGetConfig(EDMA_Config *config) {

  Uint32 gie;
  volatile Uint32 *base;
  volatile EDMA_Config* cfg = (volatile EDMA_Config*)config;
  register Uint32 x0,x1,x2,x3,x4;

  gie = IRQ_globalDisable();

  base = (volatile Uint32 *)(_EDMA_QOPT_ADDR);
  x0 = base[_EDMA_QOPT_OFFSET];
  x1 = base[_EDMA_QSRC_OFFSET];
  x2 = base[_EDMA_QCNT_OFFSET];
  x3 = base[_EDMA_QDST_OFFSET];
  x4 = base[_EDMA_QIDX_OFFSET];

  cfg->opt = x0;
  cfg->src = x1;
  cfg->cnt = x2;
  cfg->dst = x3;
  cfg->idx = x4;
  cfg->rld = 0x00000000;

  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
#endif /* USEDEFS */


#endif /* EDMA_SUPPORT */
#endif /* _CSL_EDMA_H_ */
/******************************************************************************\
* End of csl_edma.h
\******************************************************************************/

