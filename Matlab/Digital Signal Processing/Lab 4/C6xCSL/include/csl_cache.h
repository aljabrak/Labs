/******************************************************************************\
*           Copyright (C) 1999-2001 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_cache.h
* DATE CREATED.. 06/11/1999
* LAST MODIFIED. 10/01/2001 - Addition of 192K L2 SRAM for 6713
*                04/16/2004 - Modified CACHE_ROUND_TO_LINESIZE implementation
\******************************************************************************/
#ifndef _CSL_CACHE_H_
#define _CSL_CACHE_H_

#include <csl_chip.h>
#include <csl_irq.h>
#include <csl_cachehal.h>


#if (CACHE_SUPPORT)
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

#ifdef  _CACHE_MOD_
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
#if (!C64_SUPPORT)
  #define CACHE_CE00   CACHE_ADDR(MAR0)
  #define CACHE_CE01   CACHE_ADDR(MAR1)
  #define CACHE_CE02   CACHE_ADDR(MAR2)
  #define CACHE_CE03   CACHE_ADDR(MAR3)
  #define CACHE_CE10   CACHE_ADDR(MAR4)
  #define CACHE_CE11   CACHE_ADDR(MAR5)
  #define CACHE_CE12   CACHE_ADDR(MAR6)
  #define CACHE_CE13   CACHE_ADDR(MAR7)
  #define CACHE_CE20   CACHE_ADDR(MAR8)
  #define CACHE_CE21   CACHE_ADDR(MAR9)
  #define CACHE_CE22   CACHE_ADDR(MAR10)
  #define CACHE_CE23   CACHE_ADDR(MAR11)
  #define CACHE_CE30   CACHE_ADDR(MAR12)
  #define CACHE_CE31   CACHE_ADDR(MAR13)
  #define CACHE_CE32   CACHE_ADDR(MAR14)
  #define CACHE_CE33   CACHE_ADDR(MAR15)
#else

  #if (CHIP_6414 | CHIP_6415 | CHIP_6416)
    
     #define CACHE_EMIFB_CE00   CACHE_ADDR(MAR96)
     #define CACHE_EMIFB_CE01   CACHE_ADDR(MAR97)
     #define CACHE_EMIFB_CE02   CACHE_ADDR(MAR98)
     #define CACHE_EMIFB_CE03   CACHE_ADDR(MAR99)
     #define CACHE_EMIFB_CE10   CACHE_ADDR(MAR100)
     #define CACHE_EMIFB_CE11   CACHE_ADDR(MAR101)
     #define CACHE_EMIFB_CE12   CACHE_ADDR(MAR102)
     #define CACHE_EMIFB_CE13   CACHE_ADDR(MAR103)
     #define CACHE_EMIFB_CE20   CACHE_ADDR(MAR104)
     #define CACHE_EMIFB_CE21   CACHE_ADDR(MAR105)
     #define CACHE_EMIFB_CE22   CACHE_ADDR(MAR106)
     #define CACHE_EMIFB_CE23   CACHE_ADDR(MAR107)
     #define CACHE_EMIFB_CE30   CACHE_ADDR(MAR108)
     #define CACHE_EMIFB_CE31   CACHE_ADDR(MAR109)
     #define CACHE_EMIFB_CE32   CACHE_ADDR(MAR110)
     #define CACHE_EMIFB_CE33   CACHE_ADDR(MAR111)

  #endif

  #define CACHE_EMIFA_CE00    CACHE_ADDR(MAR128)
  #define CACHE_EMIFA_CE01    CACHE_ADDR(MAR129)
  #define CACHE_EMIFA_CE02    CACHE_ADDR(MAR130)
  #define CACHE_EMIFA_CE03    CACHE_ADDR(MAR131)
  #define CACHE_EMIFA_CE04    CACHE_ADDR(MAR132)
  #define CACHE_EMIFA_CE05    CACHE_ADDR(MAR133)
  #define CACHE_EMIFA_CE06    CACHE_ADDR(MAR134)
  #define CACHE_EMIFA_CE07    CACHE_ADDR(MAR135)
  #define CACHE_EMIFA_CE08    CACHE_ADDR(MAR136)
  #define CACHE_EMIFA_CE09    CACHE_ADDR(MAR137)
  #define CACHE_EMIFA_CE010   CACHE_ADDR(MAR138)
  #define CACHE_EMIFA_CE011   CACHE_ADDR(MAR139)
  #define CACHE_EMIFA_CE012   CACHE_ADDR(MAR140)
  #define CACHE_EMIFA_CE013   CACHE_ADDR(MAR141)
  #define CACHE_EMIFA_CE014   CACHE_ADDR(MAR142)
  #define CACHE_EMIFA_CE015   CACHE_ADDR(MAR143)

  #define CACHE_EMIFA_CE10    CACHE_ADDR(MAR144)
  #define CACHE_EMIFA_CE11    CACHE_ADDR(MAR145)
  #define CACHE_EMIFA_CE12    CACHE_ADDR(MAR146)
  #define CACHE_EMIFA_CE13    CACHE_ADDR(MAR147)
  #define CACHE_EMIFA_CE14    CACHE_ADDR(MAR148)
  #define CACHE_EMIFA_CE15    CACHE_ADDR(MAR149)
  #define CACHE_EMIFA_CE16    CACHE_ADDR(MAR150)
  #define CACHE_EMIFA_CE17    CACHE_ADDR(MAR151)
  #define CACHE_EMIFA_CE18    CACHE_ADDR(MAR152)
  #define CACHE_EMIFA_CE19    CACHE_ADDR(MAR153)
  #define CACHE_EMIFA_CE110   CACHE_ADDR(MAR154)
  #define CACHE_EMIFA_CE111   CACHE_ADDR(MAR155)
  #define CACHE_EMIFA_CE112   CACHE_ADDR(MAR156)
  #define CACHE_EMIFA_CE113   CACHE_ADDR(MAR157)
  #define CACHE_EMIFA_CE114   CACHE_ADDR(MAR158)
  #define CACHE_EMIFA_CE115   CACHE_ADDR(MAR159)

  #define CACHE_EMIFA_CE20    CACHE_ADDR(MAR160)
  #define CACHE_EMIFA_CE21    CACHE_ADDR(MAR161)
  #define CACHE_EMIFA_CE22    CACHE_ADDR(MAR162)
  #define CACHE_EMIFA_CE23    CACHE_ADDR(MAR163)
  #define CACHE_EMIFA_CE24    CACHE_ADDR(MAR164)
  #define CACHE_EMIFA_CE25    CACHE_ADDR(MAR165)
  #define CACHE_EMIFA_CE26    CACHE_ADDR(MAR166)
  #define CACHE_EMIFA_CE27    CACHE_ADDR(MAR167)
  #define CACHE_EMIFA_CE28    CACHE_ADDR(MAR168)
  #define CACHE_EMIFA_CE29    CACHE_ADDR(MAR169)
  #define CACHE_EMIFA_CE210   CACHE_ADDR(MAR170)
  #define CACHE_EMIFA_CE211   CACHE_ADDR(MAR171)
  #define CACHE_EMIFA_CE212   CACHE_ADDR(MAR172)
  #define CACHE_EMIFA_CE213   CACHE_ADDR(MAR173)
  #define CACHE_EMIFA_CE214   CACHE_ADDR(MAR174)
  #define CACHE_EMIFA_CE215   CACHE_ADDR(MAR175)

  #define CACHE_EMIFA_CE30    CACHE_ADDR(MAR176)
  #define CACHE_EMIFA_CE31    CACHE_ADDR(MAR177)
  #define CACHE_EMIFA_CE32    CACHE_ADDR(MAR178)
  #define CACHE_EMIFA_CE33    CACHE_ADDR(MAR179)
  #define CACHE_EMIFA_CE34    CACHE_ADDR(MAR180)
  #define CACHE_EMIFA_CE35    CACHE_ADDR(MAR181)
  #define CACHE_EMIFA_CE36    CACHE_ADDR(MAR182)
  #define CACHE_EMIFA_CE37    CACHE_ADDR(MAR183)
  #define CACHE_EMIFA_CE38    CACHE_ADDR(MAR184)
  #define CACHE_EMIFA_CE39    CACHE_ADDR(MAR185)
  #define CACHE_EMIFA_CE310   CACHE_ADDR(MAR186)
  #define CACHE_EMIFA_CE311   CACHE_ADDR(MAR187)
  #define CACHE_EMIFA_CE312   CACHE_ADDR(MAR188)
  #define CACHE_EMIFA_CE313   CACHE_ADDR(MAR189)
  #define CACHE_EMIFA_CE314   CACHE_ADDR(MAR190)
  #define CACHE_EMIFA_CE315   CACHE_ADDR(MAR191)

#endif


#if (C64_SUPPORT)
    #define CACHE_L2_LINESIZE    128
    #define CACHE_L1D_LINESIZE    64
    #define CACHE_L1P_LINESIZE    32
#else
    #define CACHE_L2_LINESIZE    128
    #define CACHE_L1D_LINESIZE    32
    #define CACHE_L1P_LINESIZE    64
#endif /* C64_SUPPORT */

//#define CACHE_ROUND_TO_LINESIZE(CACHE,ELCNT,ELSIZE)          \
//        ((CACHE_##CACHE##_LINESIZE *                           \
//         (( (((ELCNT)*(ELSIZE)) -1)/CACHE_##CACHE##_LINESIZE ) + 1))/ \
//           (ELSIZE))

#define CACHE_ROUND_TO_LINESIZE(CACHE,ELCNT,ELSIZE)\
( ( ( ( (ELCNT) * (ELSIZE)\
        + CACHE_##CACHE##_LINESIZE - 1\
      ) / CACHE_##CACHE##_LINESIZE\
      * CACHE_##CACHE##_LINESIZE\
    ) + (ELSIZE) - 1\
  ) / (ELSIZE)\
)

/******************************************************************************\
* global typedef declarations
\******************************************************************************/
#if(!C64_SUPPORT && !CHIP_6713 && !CHIP_DA610)
typedef enum {
  CACHE_64KSRAM  = 0,
  CACHE_0KCACHE  = 0,
  CACHE_48KSRAM  = 1,
  CACHE_16KCACHE = 1,
  CACHE_32KSRAM  = 2,
  CACHE_32KCACHE = 2,
  CACHE_16KSRAM  = 3,
  CACHE_48KCACHE = 3,
  CACHE_0KSRAM   = 7,
  CACHE_64KCACHE = 7
} CACHE_L2Mode;
#endif

#if (CHIP_6414 | CHIP_6415 | CHIP_6416)
typedef enum {
  CACHE_1024KSRAM = 0,
  CACHE_0KCACHE   = 0,
  CACHE_992KSRAM  = 1,
  CACHE_32KCACHE  = 1,
  CACHE_960KSRAM  = 2,
  CACHE_64KCACHE  = 2,
  CACHE_896KSRAM  = 3,
  CACHE_128KCACHE = 3,
  CACHE_768KSRAM  = 7,
  CACHE_256KCACHE = 7   /* 4-way cache 128Kbytes max */
} CACHE_L2Mode;
  #endif

#if (CHIP_6713 || CHIP_DA610)
 typedef enum {
  CACHE_256KSRAM = 0,
  CACHE_0KCACHE  = 0,
  CACHE_240KSRAM = 1,
  CACHE_16KCACHE = 1,
  CACHE_224KSRAM = 2,
  CACHE_32KCACHE = 2,
  CACHE_208KSRAM = 3,
  CACHE_48KCACHE = 3,
  CACHE_192KSRAM = 7,
  CACHE_64KCACHE = 7
} CACHE_L2Mode;
 #endif

#if (CHIP_DM642 | CHIP_6412 | CHIP_6411)
  typedef enum {
  CACHE_256KSRAM  = 0,
  CACHE_0KCACHE   = 0,
  CACHE_224KSRAM  = 1,
  CACHE_32KCACHE  = 1,
  CACHE_192KSRAM  = 2,
  CACHE_64KCACHE  = 2,
  CACHE_128KSRAM  = 3,
  CACHE_128KCACHE = 3,
  CACHE_0KSRAM    = 7,
  CACHE_256KCACHE = 7
} CACHE_L2Mode;
#endif

/* Cache sizes for the DRI300 variants
 - 6418 : 512 K 
 - 6413 : 256 K
 - 6410 : 128 K
*/

#if (CHIP_6418)
  typedef enum {
  CACHE_512KSRAM  = 0,
  CACHE_0KCACHE   = 0,
  CACHE_480KSRAM  = 1,
  CACHE_32KCACHE  = 1,
  CACHE_448KSRAM  = 2,
  CACHE_64KCACHE  = 2,
  CACHE_384KSRAM  = 3,
  CACHE_128KCACHE = 3,
  CACHE_256KSRAM  = 7,
  CACHE_256KCACHE = 7
} CACHE_L2Mode; 
#endif

#if (CHIP_6413)
  typedef enum {
  CACHE_256KSRAM  = 0,
  CACHE_0KCACHE   = 0,
  CACHE_224KSRAM  = 1,
  CACHE_32KCACHE  = 1,
  CACHE_192KSRAM  = 2,
  CACHE_64KCACHE  = 2,
  CACHE_128KSRAM  = 3,
  CACHE_128KCACHE = 3,
  CACHE_256KCACHE = 7
} CACHE_L2Mode; 
#endif

#if (CHIP_6410 | CHIP_DM641 | CHIP_DM640)
  typedef enum {
  CACHE_128KSRAM  = 0,
  CACHE_0KCACHE   = 0,
  CACHE_96KSRAM   = 1,
  CACHE_32KCACHE  = 1,
  CACHE_64KSRAM   = 2,
  CACHE_64KCACHE  = 2,
  CACHE_128KCACHE = 3 /* All other modes are invalid */
} CACHE_L2Mode; 
#endif

typedef enum {
  CACHE_L2,
  CACHE_L2ALL,
  CACHE_L1P,
  CACHE_L1PALL,
  CACHE_L1D,
  CACHE_L1DALL
} CACHE_Region;

typedef enum {
  CACHE_PCC_MAPPED = 0,
  CACHE_PCC_ENABLE = 2,
  CACHE_PCC_FREEZE = 3,
  CACHE_PCC_BYPASS = 4
} CACHE_Pcc;

/* Define macros for L2 priority Level */
#define CACHE_L2PRIURG           0
#define CACHE_L2PRIHIGH          1
#define CACHE_L2PRIMED           2
#define CACHE_L2PRILOW           3

/* Define macros for L2 Queues  */
#define CACHE_L2Q0              0
#define CACHE_L2Q1              1
#define CACHE_L2Q2              2
#define CACHE_L2Q3              3

/* Define CACHE wait flag */
typedef enum {
  CACHE_NOWAIT = 0,
  CACHE_WAIT   = 1
} CACHE_Wait;

#define CACHE_WAIT_L2WB         0x00000001
#define CACHE_WAIT_L2INV        0x00000002
#define CACHE_WAIT_L2WBINV      0x00000004
#define CACHE_WAIT_L2WBALL      0x00000008
#define CACHE_WAIT_L2WBINVALL   0x00000010
#define CACHE_WAIT_L1DINV       0x00000020
#define CACHE_WAIT_L1DWBINV     0x00000040
#define CACHE_WAIT_L1PINV       0x00000080

/*  Renaming Function  */

#define CACHE_resetEMIFA  CACHE_resetEmifa

#if (CHIP_6414 | CHIP_6415 | CHIP_6416)
  #define CACHE_resetEMIFB  CACHE_resetEmifb
#endif

/******************************************************************************\
* global variable declarations
\******************************************************************************/


/******************************************************************************\
* global function declarations
\******************************************************************************/
CSLAPI void CACHE_reset();
CSLAPI void CACHE_resetEmifa();

#if (CHIP_6414 | CHIP_6415 | CHIP_6416)
  CSLAPI void CACHE_resetEmifb();
#endif

CSLAPI CACHE_L2Mode CACHE_setL2Mode(CACHE_L2Mode newMode);
CSLAPI CACHE_L2Mode CACHE_getL2Mode();
CSLAPI CACHE_Pcc CACHE_setPccMode(CACHE_Pcc newMode);
CSLAPI void CACHE_flush(CACHE_Region region,void *addr,Uint32 wordCnt);
CSLAPI void CACHE_clean(CACHE_Region region,void *addr,Uint32 wordCnt);
CSLAPI void CACHE_invalidate(CACHE_Region region,void *addr,Uint32 wordCnt);
CSLAPI Uint32 CACHE_getL2SramSize();

/* New API base on SPRU609 and SPRU610 */
CSLAPI void CACHE_wbL2(void *blockPtr,Uint32 byteCnt,CACHE_Wait wait);
CSLAPI void CACHE_wbInvL2(void *blockPtr,Uint32 byteCnt,CACHE_Wait wait);
CSLAPI void CACHE_wbAllL2(CACHE_Wait wait);
CSLAPI void CACHE_wbInvAllL2(CACHE_Wait wait);
//CSLAPI void CACHE_invAllL1d();
CSLAPI void CACHE_wbInvL1d(void *blockPtr,Uint32 byteCnt,CACHE_Wait wait);
CSLAPI void CACHE_invL1p(void *blockPtr,Uint32 byteCnt,CACHE_Wait wait);
CSLAPI void CACHE_invAllL1p();
CSLAPI void CACHE_wait();

#if (C64_SUPPORT)
CSLAPI void CACHE_invL2(void *blockPtr,Uint32 byteCnt,CACHE_Wait wait);
CSLAPI void CACHE_invL1d(void *blockPtr,Uint32 byteCnt,CACHE_Wait wait);
#endif

/* new APIs with  user-determined blocksize option */
CSLAPI void CACHE_wbInvL2_blocks(void *blockPtr,Uint32 byteCnt, Uint32 blockSize);
CSLAPI void CACHE_wbL2_blocks(void *blockPtr,Uint32 byteCnt, Uint32 blockSize);


/*#if (C64_SUPPORT)
CSLAPI void CACHE_freezeL1P();
CSLAPI void CACHE_freezeL1D();
#endif */

/******************************************************************************\
* inline function declarations
\******************************************************************************/
IDECL void CACHE_enableCaching(Uint32 block);
#if  (CHIP_6414 | CHIP_6415 | CHIP_6416| CHIP_DM642 | CHIP_DM641 | CHIP_DM640 | CHIP_6412 | CHIP_6411 | CHIP_6410 | CHIP_6413 | CHIP_6418)
IDECL void CACHE_setPriL2Req(Uint32 priority);
IDECL void CACHE_setL2Queue(Uint32 queueNum,Uint32 length);
IDECL void CACHE_resetL2Queue(Uint32 queueNum);
#endif

/******************************************************************************\
* inline function definitions
\******************************************************************************/
#ifdef USEDEFS
/*----------------------------------------------------------------------------*/
IDEF void CACHE_enableCaching(Uint32 block) {

  #if (L2CACHE_SUPPORT)
    CACHE_FSETA(block,MAR,CE,1);
    while (!CACHE_FGETA(block,MAR,CE))
                   ;
  #else
    UNREFERENCED_PARAMETER(block);
  #endif
}

/*----------------------------------------------------------------------------*/
#if (CHIP_6414 | CHIP_6415 | CHIP_6416| CHIP_DM642 | CHIP_DM641 | CHIP_DM640 | CHIP_6412 | CHIP_6411 | CHIP_6410 | CHIP_6413 | CHIP_6418)
IDEF void CACHE_setPriL2Req(Uint32 priority) {
   CACHE_FSET(CCFG,P,priority);
 }
/*----------------------------------------------------------------------------*/
IDEF void CACHE_setL2Queue(Uint32 queueNum,Uint32 length) {
  if (queueNum ==  0 ){
     CACHE_FSET(L2ALLOC0,Q0CNT,length);
  } else {
     if (queueNum ==  1 ){
        CACHE_FSET(L2ALLOC1,Q1CNT,length);
     } else {
        if (queueNum ==  2 ){
           CACHE_FSET(L2ALLOC2,Q2CNT,length);
        } else {
           if (queueNum ==  3 ){
              CACHE_FSET(L2ALLOC3,Q3CNT,length);
           }
        }
     }
  }
}
/*----------------------------------------------------------------------------*/
IDEF void CACHE_resetL2Queue(Uint32 queueNum) {
  if (queueNum ==  0 ) {
    CACHE_FSET(L2ALLOC0,Q0CNT,6);
  } else {
     if (queueNum ==  1 ) { 
        CACHE_FSET(L2ALLOC1,Q1CNT,2);
     } else {
        if (queueNum ==  2 ) {
           CACHE_FSET(L2ALLOC2,Q2CNT,2);
        } else {
           if (queueNum ==  3 ) {
              CACHE_FSET(L2ALLOC3,Q3CNT,2);
           }
        }
     }
  }
}
#endif
/*----------------------------------------------------------------------------*/

#endif /* USEDEFS */

#endif /* CACHE_SUPPORT */
#endif /* _CSL_CACHE_H_ */
/******************************************************************************\
* End of csl_cache.h
\******************************************************************************/
