/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_tcp.h
* DATE CREATED.. 02/22/2001 
* LAST MODIFIED. 09/17/2001 
*
\******************************************************************************/
#ifndef _CSL_TCP_H_
#define _CSL_TCP_H_

#include <csl_chip.h>   
#include <csl_stdinc.h>
#include <csl_irq.h>
#include "csl_tcphal.h"

#if (TCP_SUPPORT)
/****************************************\
* TCP scope and inline control macros
\****************************************/
#ifdef __cplusplus
#define CSLAPI extern "C" far
#else
#define CSLAPI extern far
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _TCP_MOD_
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
* TCP global macro declarations
\****************************************/

/****************************************\
* TCP global typedef declarations
\****************************************/
typedef Uint8  TCP_Standard;
typedef Uint8  TCP_Mode;
typedef Uint8  TCP_Map;
typedef Uint8  TCP_Rate;
typedef Uint8  TCP_UserData;
typedef Uint8  TCP_ExtrinsicData;

typedef struct {
   Uint32 ic0;
   Uint32 ic1;
   Uint32 ic2;
   Uint32 ic3;
   Uint32 ic4;
   Uint32 ic5;
   Uint32 ic6;
   Uint32 ic7;
   Uint32 ic8;
   Uint32 ic9;
   Uint32 ic10;
   Uint32 ic11;
} TCP_ConfigIc;

typedef struct {
   TCP_Standard standard;
   TCP_Mode     mode;
   TCP_Map      map;
   TCP_Rate     rate;
   Uint32       intFlag;
   Uint32       outParmFlag;
   Uint32       frameLen;
   Uint32       subFrameLen;
   Uint32       relLen;
   Uint32       relLenLast;
   Uint32       prologSize;
   Uint32       numSubBlock;
   Uint32       numSubBlockLast;
   Uint32       maxIter;
   Uint32       snr;
   Uint32       numInter;
   Uint32       numSysPar;
   Uint32       numApriori;
   Uint32       numExt;
   Uint32       numHd;
} TCP_Params;

typedef struct {
   TCP_Standard standard;
   TCP_Rate     rate;
   Uint16       frameLen;
   Uint8        prologSize;
   Uint8        maxIter;
   Uint8        snr;
   Uint8        intFlag;
   Uint8        outParmFlag;
} TCP_BaseParams;

/************ New structure for Init ***************/
typedef struct {
   TCP_UserData *restrict xabData;
   TCP_Standard standard;
   TCP_Rate     rate;
   Uint16       frameLen;
   Uint8        prologSize;
   Uint8        maxIter;
   Uint8        snr;
   Uint8        intFlag;
   Uint8        outParmFlag;
} TCP_Init;

/****************************************\
* TCP global ants declarations
\****************************************/
#define TCP_RATE_1_2           2
#define TCP_RATE_1_3           3
#define TCP_RATE_1_4           4
#define TCP_MODE_SA            0
#define TCP_MODE_SP            1
#define TCP_MAP_MAP1A          0
#define TCP_MAP_MAP1B          1
#define TCP_MAP_MAP2           3 
#define TCP_STANDARD_3GPP      0
#define TCP_STANDARD_IS2000    1
#define TCP_RLEN_MAX         128
#define TCP_FLEN_MAX        5114
#define TCP_NUM_IC            12
#define TCP_NUM_OP             2

/****************************************\
* TCP global function declarations
\****************************************/

/* Set the ic6-ic9 registers (tails) based on the user data          */
/* TCP_tailConfig calls TCP_tailConfig3GPP() or TCP_tailConfigIs2000 */
/* based on the "standard" parameter value                           */
CSLAPI void TCP_tailConfig(TCP_Standard standard,
                          TCP_Mode mode,
                          TCP_Map map,
                          TCP_Rate rate,
                          TCP_UserData *restrict xabData,
                          TCP_ConfigIc *restrict configIc);
CSLAPI void TCP_tailConfig3GPP(TCP_Mode mode,
                          TCP_Map map,
                          TCP_UserData *restrict xabData,
                          TCP_ConfigIc *restrict configIc);
CSLAPI void TCP_tailConfigIs2000(TCP_Mode mode,
                          TCP_Map map,
                          TCP_Rate rate,
                          TCP_UserData *restrict xabData,
                          TCP_ConfigIc *restrict configIc);

/* Set the Parameters passed via Param structure to ic0-ic5 registers */
/* configIc is the returned config structure of the icx registers */
CSLAPI void TCP_setParams(TCP_Params *restrict configParms,
                          TCP_ConfigIc *restrict configIc);

/* Set all icx registers :                                     */ 
/* configPrams input parameters dedicated to ic0-ic5 registers */
/* xabData input parameters dedicated to set ic6-ic11 registers (tails */
/* configIc is the returned config structure of the icx registers */
CSLAPI void TCP_genIc(TCP_Params *restrict configParms,
                          TCP_UserData *restrict xabData,
                          TCP_ConfigIc *restrict configIc);

/* Divide the data frames into subframes and subblocks.                     */
/* The values calculated in these routines are entered into the configParms */
/* struct and are used in programming the TCP IC values and the EDMA        */
/* parameters. Either TCP_calcSubBlocks3GPP or TCP_calcSubBlocksIs2000 is   */
/* used depending on the standard.                                          */
CSLAPI void TCP_calcSubBlocksSA(TCP_Params *configParms);

CSLAPI Uint32 TCP_calcSubBlocksSP(TCP_Params *configParms);

/* Fill out the necessary TCP parameters.                                   */
CSLAPI Uint32 TCP_genParams(TCP_BaseParams *configBase,
                          TCP_Params *configParms);


/*** Init parameters and set registers **********/
void TCP_init(TCP_Init *Init);
void TCP_tailInit3GPP(TCP_Mode mode, TCP_Map map,TCP_UserData *restrict xabData);
void TCP_tailInitIs2000(TCP_Mode mode,TCP_Map map,TCP_Rate rate,TCP_UserData *restrict xabData);

/* Calculate the count values (number of 32-bit words) required for the     */
/* programming of the EDMA for all data buffers. The counts calculated      */
/* using either TCP_calcCounts3GPP or TCP_calcCountsIs2000 depending on the */
/* standard.                                                                */
CSLAPI void TCP_calcCountsSA(TCP_Params *configParms);

CSLAPI void TCP_calcCountsSP(TCP_Params *configParms);

/* Interleave the extrinsics data to give the apriori data required for the */
/* subsequent MAP decoding. TCP_interleaveExt is performed by the CPU       */
/* following a MAP1 decoding by the TCP. This function is used in shared    */
/* processing mode only.                                                    */
CSLAPI void TCP_interleaveExt(TCP_ExtrinsicData *restrict aprioriMap2, 
                          const TCP_ExtrinsicData *restrict extrinsicsMap1, 
                          const Uint16 *restrict interleaverTable, 
                          Uint32  numExt);

/* De-interleave the extrinsics data to give the apriori data required for  */
/* the subsequent MAP decoding. TCP_deinterleaveExt is performed by the CPU */
/* following a MAP2 decoding by the TCP. This function is used in shared    */
/* processing mode only.                                                    */
CSLAPI void TCP_deinterleaveExt(TCP_ExtrinsicData *restrict aprioriMap1, 
                          const TCP_ExtrinsicData *restrict extrinsicsMap2, 
                          const Uint16 *restrict interleaverTable, 
                          Uint32  numExt);

/* Calculate hard decisions following all MAP decodings in shared processing*/
/* mode.                                                                    */
CSLAPI void TCP_calculateHd(const TCP_ExtrinsicData *restrict extrinsicsMap1, 
                          const TCP_ExtrinsicData *restrict apriori, 
                          const TCP_UserData *restrict channel_data, 
                          Uint32 *restrict hardDecisions,
                          Uint16 numExt,
                          Uint8  rate);

/* Demultiplex the input data into two "working data" buffers. The two new  */
/* data buffers are used separately for MAP 1 and MAP 2 decodings in shared */
/* processing mode.                                                         */
CSLAPI void TCP_demuxInput(Uint32 rate,
                          Uint32 frameLen,
                          const TCP_UserData *restrict input,
                          const Uint16 *restrict interleaver,
                          TCP_ExtrinsicData *restrict nonInterleaved,
                          TCP_ExtrinsicData *restrict interleaved);
                          
/****************************************\
* TCP inline function declarations
\****************************************/

/* Master transfer functions */
IDECL void   TCP_start();
IDECL void   TCP_pause();
IDECL void   TCP_unpause();

IDECL Uint32 TCP_getNumIt();
IDECL Uint32 TCP_getSysParEndian();
IDECL Uint32 TCP_getInterEndian();
IDECL Uint32 TCP_getAprioriEndian();
IDECL Uint32 TCP_getExtEndian();

IDECL void   TCP_setNativeEndian();
IDECL void   TCP_setPacked32Endian();
IDECL void   TCP_setSysParEndian(Uint32 sysParEnd);
IDECL void   TCP_setInterEndian(Uint32 interEnd);
IDECL void   TCP_setAprioriEndian(Uint32 aprioriEnd);
IDECL void   TCP_setExtEndian(Uint32 extEnd);

IDECL Uint32 TCP_statPause();
IDECL Uint32 TCP_statRun();
IDECL Uint32 TCP_statError();
IDECL Uint32 TCP_statWaitIc();
IDECL Uint32 TCP_statWaitInter();
IDECL Uint32 TCP_statWaitSysPar();
IDECL Uint32 TCP_statWaitApriori();
IDECL Uint32 TCP_statWaitExt();
IDECL Uint32 TCP_statWaitHardDec();
IDECL Uint32 TCP_statWaitOutParm();

IDECL Uint32 TCP_errTest();
IDECL Uint32 TCP_getFrameLenErr();
IDECL Uint32 TCP_getProlLenErr();
IDECL Uint32 TCP_getRateErr();
IDECL Uint32 TCP_getSubFrameErr();
IDECL Uint32 TCP_getModeErr();
IDECL Uint32 TCP_getRelLenErr();
IDECL Uint32 TCP_getLastRelLenErr();
IDECL Uint32 TCP_getInterleaveErr();
IDECL Uint32 TCP_getOutParmErr();
IDECL Uint32 TCP_getAccessErr();


/* Set all the TCP registers : ic0-ic11 using a configuration structure  */
IDECL void TCP_icConfig(TCP_ConfigIc *config);

/* Set all the TCP registers : ic0-ic11 with register values   */
IDECL void TCP_icConfigArgs(Uint32 ic0, Uint32 ic1, Uint32 ic2,  Uint32 ic3,
                            Uint32 ic4, Uint32 ic5, Uint32 ic6,  Uint32 ic7,
                            Uint32 ic8, Uint32 ic9, Uint32 ic10, Uint32 ic11);
/* Get TCP registers : ic0-ic11 returned into a configuration structure  */
IDECL void TCP_getIcConfig(TCP_ConfigIc *config);

/* Build the tail value */
IDECL Uint32 TCP_makeTailArgs(Uint8 byte31_24, Uint8 byte23_16,
                              Uint8 byte15_8,  Uint8 byte7_0);

/* Ceiling functions */
IDECL Uint32 TCP_ceil(Uint32 a, Uint32 b);

IDECL Uint32 TCP_normalCeil(Uint32 a, Uint32 b);

/****************************************\
* TCP inline function definitions
\****************************************/
#ifdef USEDEFS
/*----------------------------------------------------------------------------*/
IDEF void TCP_start(){
   TCP_FSET(EXE,START,1);  
}
/*----------------------------------------------------------------------------*/
IDEF void TCP_pause(){
  TCP_FSET(EXE,PAUSE,1);
}
/*----------------------------------------------------------------------------*/
IDEF void TCP_unpause(){
  TCP_FSET(EXE,UNPAUSE,1);
}
/*----------------------------------------------------------------------------*/
IDEF void TCP_reset(){
  TCP_RSET(IC0,TCP_IC0_DEFAULT);
  TCP_RSET(IC1,TCP_IC1_DEFAULT);
  TCP_RSET(IC2,TCP_IC2_DEFAULT);
  TCP_RSET(IC3,TCP_IC3_DEFAULT);
  TCP_RSET(IC4,TCP_IC4_DEFAULT);
  TCP_RSET(IC5,TCP_IC5_DEFAULT);
  TCP_RSET(IC6,TCP_IC6_DEFAULT);
  TCP_RSET(IC7,TCP_IC7_DEFAULT);
  TCP_RSET(IC8,TCP_IC8_DEFAULT);
  TCP_RSET(IC9,TCP_IC9_DEFAULT);
  TCP_RSET(IC10,TCP_IC10_DEFAULT);
  TCP_RSET(IC11,TCP_IC11_DEFAULT);
  TCP_RSET(OUT,TCP_OUT_DEFAULT);
  TCP_RSET(EXE,TCP_EXE_DEFAULT);
  TCP_RSET(END,TCP_END_DEFAULT);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 TCP_getNumIt(){
  return TCP_FGET(OUT,NIT);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 TCP_getSysParEndian(){
  return TCP_FGET(END,SYSPAR);
}
/*----------------------------------------------------------------------------*/
IDEF void TCP_setSysParEndian(Uint32 sysParEnd){
 TCP_FSET(END,SYSPAR,sysParEnd);
}

/*----------------------------------------------------------------------------*/
IDEF Uint32 TCP_getInterEndian(){
  return TCP_FGET(END,INTER);
}
/*----------------------------------------------------------------------------*/
IDEF void TCP_setInterEndian(Uint32 interEnd){
  TCP_FSET(END,INTER,interEnd);
}

/*----------------------------------------------------------------------------*/
IDEF Uint32 TCP_getAprioriEndian(){
  return TCP_FGET(END,AP);
}
/*----------------------------------------------------------------------------*/
IDEF void TCP_setAprioriEndian(Uint32 aprioriEnd ){
   TCP_FSET(END,AP,aprioriEnd);
}

/*----------------------------------------------------------------------------*/
IDEF Uint32 TCP_getExtEndian(){
  return TCP_FGET(END,EXT);
}
/*----------------------------------------------------------------------------*/
IDEF void TCP_setExtEndian(Uint32 extEnd){
  TCP_FSET(END,EXT,extEnd);
}
/*----------------------------------------------------------------------------*/
IDEF void   TCP_setNativeEndian(){
    TCP_RSET(END,0xF);
}
/*----------------------------------------------------------------------------*/
IDEF void   TCP_setPacked32Endian(){
    TCP_RSET(END,0x0);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 TCP_statPause(){
  return TCP_FGET(STAT,PAUS);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 TCP_statRun(){
  return TCP_FGET(STAT,RUN);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 TCP_statError(){
  return TCP_FGET(STAT,ERR);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 TCP_statWaitIc(){
  return TCP_FGET(STAT,WIC);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 TCP_statWaitInter(){
  return TCP_FGET(STAT,WINT);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 TCP_statWaitSysPar(){
  return TCP_FGET(STAT,WSP);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 TCP_statWaitApriori(){
  return TCP_FGET(STAT,WAP);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 TCP_statWaitExt(){
  return TCP_FGET(STAT,REXT);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 TCP_statWaitHardDec(){
  return TCP_FGET(STAT,RHD);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 TCP_statWaitOutParm(){
  return TCP_FGET(STAT,ROP);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 TCP_errTest(){
  return TCP_FGET(ERR,ERR);
}

/*----------------------------------------------------------------------------*/
IDEF Uint32 TCP_getFrameLenErr(){
  return TCP_FGET(ERR,F);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 TCP_getProlLenErr(){
  return TCP_FGET(ERR,P);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 TCP_getRateErr(){
  return TCP_FGET(ERR,RATE);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 TCP_getSubFrameErr(){
  return TCP_FGET(ERR,SF);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 TCP_getModeErr(){
  return TCP_FGET(ERR,MODE);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 TCP_getRelLenErr(){
  return TCP_FGET(ERR,R);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 TCP_getLastRelLenErr(){
  return TCP_FGET(ERR,LR);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 TCP_getInterleaveErr(){
  return TCP_FGET(ERR,INT);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 TCP_getOutParmErr(){
  return TCP_FGET(ERR,OP);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 TCP_getAccessErr(){
  return TCP_FGET(ERR,ACC);
}
/*----------------------------------------------------------------------------*/
IDEF void TCP_icConfig(TCP_ConfigIc *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *) _TCP_BASE_IC;
  register int x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11;

  gie = IRQ_globalDisable();

   x0 = config->ic0;
   x1 = config->ic1;
   x2 = config->ic2;
   x3 = config->ic3;
   x4 = config->ic4;
   x5 = config->ic5;
   x6 = config->ic6;
   x7 = config->ic7;
   x8 = config->ic8;
   x9 = config->ic9;
  x10 = config->ic10;
  x11 = config->ic11;
  
  base[_TCP_IC0_OFFSET]  = x0;
  base[_TCP_IC1_OFFSET]  = x1;
  base[_TCP_IC2_OFFSET]  = x2;
  base[_TCP_IC3_OFFSET]  = x3;
  base[_TCP_IC4_OFFSET]  = x4;
  base[_TCP_IC5_OFFSET]  = x5;
  base[_TCP_IC6_OFFSET]  = x6;
  base[_TCP_IC7_OFFSET]  = x7;
  base[_TCP_IC8_OFFSET]  = x8;
  base[_TCP_IC9_OFFSET]  = x9;
  base[_TCP_IC10_OFFSET] = x10;
  base[_TCP_IC11_OFFSET] = x11;
  
  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void TCP_icConfigArgs(Uint32 ic0, Uint32 ic1, Uint32 ic2, Uint32 ic3, Uint32 ic4,
                           Uint32 ic5, Uint32 ic6, Uint32 ic7, Uint32 ic8, Uint32 ic9,
                           Uint32 ic10, Uint32 ic11) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *) _TCP_BASE_IC;

  gie = IRQ_globalDisable();
  
  base[_TCP_IC0_OFFSET]  = ic0;
  base[_TCP_IC1_OFFSET]  = ic1;
  base[_TCP_IC2_OFFSET]  = ic2;
  base[_TCP_IC3_OFFSET]  = ic3;
  base[_TCP_IC4_OFFSET]  = ic4;
  base[_TCP_IC5_OFFSET]  = ic5;
  base[_TCP_IC6_OFFSET]  = ic6;
  base[_TCP_IC7_OFFSET]  = ic7;
  base[_TCP_IC8_OFFSET]  = ic8;
  base[_TCP_IC9_OFFSET]  = ic9;
  base[_TCP_IC10_OFFSET] = ic10;
  base[_TCP_IC11_OFFSET] = ic11;
  
  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void TCP_getIcConfig(TCP_ConfigIc *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *) _TCP_BASE_IC;
  register int x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11;

  gie = IRQ_globalDisable();

   x0 = base[_TCP_IC0_OFFSET];
   x1 = base[_TCP_IC1_OFFSET];
   x2 = base[_TCP_IC2_OFFSET];
   x3 = base[_TCP_IC3_OFFSET];
   x4 = base[_TCP_IC4_OFFSET];
   x5 = base[_TCP_IC5_OFFSET];
   x6 = base[_TCP_IC6_OFFSET];
   x7 = base[_TCP_IC7_OFFSET];
   x8 = base[_TCP_IC8_OFFSET];
   x9 = base[_TCP_IC9_OFFSET];
  x10 = base[_TCP_IC10_OFFSET];
  x11 = base[_TCP_IC11_OFFSET];
  
  config->ic0  =  x0;
  config->ic1  =  x1;
  config->ic2  =  x2;
  config->ic3  =  x3;
  config->ic4  =  x4;
  config->ic5  =  x5;
  config->ic6  =  x6;
  config->ic7  =  x7;
  config->ic8  =  x8;
  config->ic9  =  x9;
  config->ic10 = x10;
  config->ic11 = x11;
  
  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 TCP_makeTailArgs(Uint8 byte31_24, Uint8 byte23_16,
                             Uint8 byte15_8,  Uint8 byte7_0) {

  Uint32 gie;
  Uint32 x;

  gie = IRQ_globalDisable();

  x = (byte31_24 << 24) | (byte23_16 << 16) | (byte15_8 << 8) | byte7_0;
  
  IRQ_globalRestore(gie);

  return(x);
}

/*----------------------------------------------------------------------------*/

IDEF Uint32 TCP_ceil(Uint32 val, Uint32 pwr2) {
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

IDEF Uint32 TCP_normalCeil(Uint32 val1, Uint32 val2) {
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

#endif /* (TCP_SUPPORT) */
#endif /* _CSL_TCP_H_ */
/******************************************************************************\
* End of csl_tcp.h
\******************************************************************************/

