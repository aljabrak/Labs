/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_vcp.h
* DATE CREATED.. 04/09/2001 
* LAST MODIFIED. 05/30/2001 
*
\******************************************************************************/
#ifndef _CSL_VCP_H_
#define _CSL_VCP_H_

#include <csl_chip.h>   
#include <csl_stdinc.h>
#include <csl_irq.h>
#include "csl_vcphal.h"

#if (VCP_SUPPORT)
/****************************************\
* VCP scope and inline control macros
\****************************************/
#ifdef __cplusplus
#define CSLAPI extern "C" far
#else
#define CSLAPI extern far
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _VCP_MOD_
  #define IDECL extern far
  #define USEDEFS
  #define IDEF
#else
  #ifdef  _INLINE
    #define IDECL static inline
    #define USEDEFS
    #define IDEF  static inline
  #else
    #define IDECL extern far
  #endif
#endif

/****************************************\
* VCP global macro declarations
\****************************************/

/****************************************\
* VCP global typedef declarations
\****************************************/
typedef Uint32 VCP_Standard;
typedef Uint32 VCP_Mode;
typedef Uint32 VCP_Map;
typedef Uint32 VCP_Rate;
typedef Uint8  VCP_UserData;
typedef Uint8  VCP_ExtrinsicData;

typedef struct {
   Uint32 ic0;
   Uint32 ic1;
   Uint32 ic2;
   Uint32 ic3;
   Uint32 ic4;
   Uint32 ic5;
} VCP_ConfigIc;

typedef struct {
   VCP_Rate     rate;
   Uint8        constLen;
   Uint8        poly0;
   Uint8        poly1;
   Uint8        poly2;
   Uint8        poly3;
   Uint16       yamTh;
   Uint16       frameLen;
   Uint16       relLen;
   Uint16       convDist;
   Uint16       maxSm;
   Uint16       minSm;
   Uint8        stateNum;
   Uint8        bmBuffLen;
   Uint8        decBuffLen;
   Uint8        traceBack;
   Uint8        readFlag;
   Uint8        decision;
   Uint16       numBranchMetrics;
   Uint16       numDecisions;
   Uint16       numBmFrames;
   Uint16       numDecFrames;
} VCP_Params;
typedef struct {
   VCP_Rate     rate;
   Uint8        constLen;
   Uint16       frameLen;
   Uint16       yamTh;
   Uint8        stateNum;
   Uint8        decision;
   Uint8        readFlag;
} VCP_BaseParams;

/****************************************\
* VCP global ants declarations
\****************************************/
#define VCP_RATE_1_2              2
#define VCP_RATE_1_3              3
#define VCP_RATE_1_4              4
#define VCP_DECISION_HARD         0
#define VCP_DECISION_SOFT         1
#define VCP_TRACEBACK_NONE        0
#define VCP_TRACEBACK_TAILED      1
#define VCP_TRACEBACK_CONVERGENT  2
#define VCP_TRACEBACK_MIXED       3
#define VCP_END_PACKED32          0
#define VCP_END_NATIVE            1
#define VCP_NUM_IC                6
#define VCP_NUM_OP                2

/****************************************\
* VCP global function declarations
\****************************************/
/* Set all icx registers :                                                    */ 
/* Establish all IC register values in the configIc struct based on the       */
/* parameters defined in configParms.                                         */
CSLAPI void VCP_genIc(VCP_Params *restrict configParms,
                      VCP_ConfigIc *restrict configIc);

/* Fill out the necessary TCP parameters.                                     */
CSLAPI void VCP_genParams(VCP_BaseParams *configBase,
                      VCP_Params *configParms);


/****************************************\
* VCP inline function declarations
\****************************************/

/* Master transfer functions */
IDECL void   VCP_start();
IDECL void   VCP_pause();
IDECL void   VCP_unpause();
IDECL void   VCP_stop();
IDECL void   VCP_reset();

IDECL Uint32 VCP_getMinSm();
IDECL Uint32 VCP_getMaxSm();
IDECL Uint32 VCP_getYamBit();
IDECL Uint32 VCP_getIndexState();

IDECL Uint32 VCP_statPause();
IDECL Uint32 VCP_statRun();
IDECL Uint32 VCP_statError();
IDECL Uint32 VCP_statWaitIc();
IDECL Uint32 VCP_statInFifo();
IDECL Uint32 VCP_statOutFifo();

IDECL Uint32 VCP_statSymProc();
IDECL Uint32 VCP_getNumOutFifo();
IDECL Uint32 VCP_getNumInFifo();

IDECL Uint32 VCP_errTest();

IDECL Uint32 VCP_getBmEndian();
IDECL Uint32 VCP_getSdEndian();

IDECL void   VCP_setNativeEndian();
IDECL void   VCP_setPacked32Endian();
IDECL void   VCP_setBmEndian(Uint32 bmEnd);
IDECL void   VCP_setSdEndian(Uint32 sdEnd);

IDECL void VCP_icConfig(VCP_ConfigIc *config);
IDECL void VCP_icConfigArgs(Uint32 ic0, Uint32 ic1, Uint32 ic2,  Uint32 ic3,
                            Uint32 ic4, Uint32 ic5);
IDECL void VCP_getIcConfig(VCP_ConfigIc *config);

/* Ceiling functions */
IDECL Uint32 VCP_ceil(Uint32 a, Uint32 b);

IDECL Uint32 VCP_normalCeil(Uint32 a, Uint32 b);

/****************************************\
* VCP inline function definitions
\****************************************/
#ifdef USEDEFS
/*----------------------------------------------------------------------------*/
IDEF void VCP_start(){
   VCP_FSET(EXE,COMMAND,1) ;  
}
/*----------------------------------------------------------------------------*/
IDEF void VCP_pause(){
  VCP_FSET(EXE,COMMAND,2);
}
/*----------------------------------------------------------------------------*/
IDEF void VCP_unpause(){
  VCP_FSET(EXE,COMMAND,4);
}
/*----------------------------------------------------------------------------*/
IDEF void VCP_stop(){
   VCP_FSET(EXE,COMMAND,5) ;  
}
/*----------------------------------------------------------------------------*/
IDEF void VCP_reset(){
  VCP_RSET(IC0,VCP_IC0_DEFAULT);
  VCP_RSET(IC1,VCP_IC1_DEFAULT);
  VCP_RSET(IC2,VCP_IC2_DEFAULT);
  VCP_RSET(IC3,VCP_IC3_DEFAULT);
  VCP_RSET(IC4,VCP_IC4_DEFAULT);
  VCP_RSET(IC5,VCP_IC5_DEFAULT);
  VCP_RSET(EXE,VCP_EXE_DEFAULT);
  VCP_RSET(END,VCP_END_DEFAULT);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 VCP_getMinSm(){
  return VCP_FGET(OUT0,FMINS);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 VCP_getMaxSm(){
  return VCP_FGET(OUT0,FMAXS);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 VCP_getYamBit(){
  return VCP_FGET(OUT1,YAM);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 VCP_getIndexState(){
  return VCP_FGET(OUT1,FMAXI);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 VCP_statPause(){
  return VCP_FGET(STAT0,PAUS);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 VCP_statRun(){
  return VCP_FGET(STAT0,RUN);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 VCP_statError(){
  return VCP_FGET(STAT0,ERR);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 VCP_statWaitIc(){
  return VCP_FGET(STAT0,WIC);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 VCP_statInFifo(){
  return VCP_FGET(STAT0,IFEMP);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 VCP_statOutFifo(){
  return VCP_FGET(STAT0,OFFUL);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 VCP_statSymProc(){
  return VCP_FGET(STAT0,NSYM);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 VCP_getNumOutFifo(){
  return VCP_FGET(STAT1,NSYMOF);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 VCP_getNumInFifo(){
  return VCP_FGET(STAT1,NSYMIF);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 VCP_errTest(){
  return VCP_FGET(ERR,ERROR);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 VCP_getBmEndian(){
  return VCP_FGET(END,BM);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 VCP_getSdEndian(){
  return VCP_FGET(END,SD);
}
/*----------------------------------------------------------------------------*/
IDEF void   VCP_setNativeEndian(){
  VCP_FSET(END,BM,VCP_END_BM_NATIVE);
  VCP_FSET(END,SD,VCP_END_SD_NATIVE);
}
/*----------------------------------------------------------------------------*/
IDEF void   VCP_setPacked32Endian(){
  VCP_FSET(END,BM,VCP_END_BM_32BIT);
  VCP_FSET(END,SD,VCP_END_SD_32BIT);
}
/*----------------------------------------------------------------------------*/
IDEF void   VCP_setBmEndian(Uint32 bmEnd){
  VCP_FSET(END,BM,bmEnd);
}
/*----------------------------------------------------------------------------*/
IDEF void   VCP_setSdEndian(Uint32 sdEnd){
  VCP_FSET(END,SD,sdEnd);
}
/*----------------------------------------------------------------------------*/
IDEF void VCP_icConfig(VCP_ConfigIc *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *) _VCP_BASE_IC;
  register int x0,x1,x2,x3,x4,x5;

  gie = IRQ_globalDisable();

   x0 = config->ic0;
   x1 = config->ic1;
   x2 = config->ic2;
   x3 = config->ic3;
   x4 = config->ic4;
   x5 = config->ic5;
  
  base[_VCP_IC0_OFFSET]  = x0;
  base[_VCP_IC1_OFFSET]  = x1;
  base[_VCP_IC2_OFFSET]  = x2;
  base[_VCP_IC3_OFFSET]  = x3;
  base[_VCP_IC4_OFFSET]  = x4;
  base[_VCP_IC5_OFFSET]  = x5;
  
  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void VCP_icConfigArgs(Uint32 ic0, Uint32 ic1, Uint32 ic2, Uint32 ic3, Uint32 ic4,
                           Uint32 ic5) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *) _VCP_BASE_IC;

  gie = IRQ_globalDisable();
  
  base[_VCP_IC0_OFFSET]  = ic0;
  base[_VCP_IC1_OFFSET]  = ic1;
  base[_VCP_IC2_OFFSET]  = ic2;
  base[_VCP_IC3_OFFSET]  = ic3;
  base[_VCP_IC4_OFFSET]  = ic4;
  base[_VCP_IC5_OFFSET]  = ic5;
  
  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void VCP_getIcConfig(VCP_ConfigIc *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *) _VCP_BASE_IC;
  register int x0,x1,x2,x3,x4,x5;

  gie = IRQ_globalDisable();

   x0 = base[_VCP_IC0_OFFSET];
   x1 = base[_VCP_IC1_OFFSET];
   x2 = base[_VCP_IC2_OFFSET];
   x3 = base[_VCP_IC3_OFFSET];
   x4 = base[_VCP_IC4_OFFSET];
   x5 = base[_VCP_IC5_OFFSET];
  
  config->ic0  =  x0;
  config->ic1  =  x1;
  config->ic2  =  x2;
  config->ic3  =  x3;
  config->ic4  =  x4;
  config->ic5  =  x5;
  
  IRQ_globalRestore(gie);
}

/*----------------------------------------------------------------------------*/

IDEF Uint32 VCP_ceil(Uint32 val, Uint32 pwr2) {
  Uint32 gie;
  Uint32 x;
  
  gie = IRQ_globalDisable();

  /* x^pwr2 = ceil(val, 2^pwr2) */
  /* val is increased (if necessary) to be a multiple of 2^pwr2 */
  x = (((val) - (((val)>>(pwr2)) << (pwr2))) == 0) ?                           \
      ((val)>>(pwr2)):(((val)>>(pwr2))+1);
  
  IRQ_globalRestore(gie);

  return(x);
}

/*----------------------------------------------------------------------------*/

IDEF Uint32 VCP_normalCeil(Uint32 val1, Uint32 val2) {
  Uint32 gie;
  Uint32 x;
  
  gie = IRQ_globalDisable();

  /* x = ceil(val1, val2) */
  /* val is increased (if necessary) to be a multiple of val2 */
  x = ( ((val1)%(val2))!=0  )?( ((val1)/(val2)) + 1 ):((val1)/(val2));
  
  IRQ_globalRestore(gie);

  return(x);
}
/*----------------------------------------------------------------------------*/
#endif /* USEDEFS */

#endif /* VCP_SUPPORT */
#endif /* _CSL_VCP_H_ */
/******************************************************************************\
* End of csl_vcp.h
\******************************************************************************/

