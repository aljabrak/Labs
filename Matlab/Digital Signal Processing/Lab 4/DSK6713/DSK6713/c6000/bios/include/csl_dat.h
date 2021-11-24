/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_dat.h
* DATE CREATED.. 11/11/1999 
* LAST MODIFIED. 10/03/2000
\******************************************************************************/
#ifndef _CSL_DAT_H_
#define _CSL_DAT_H_

#include <csl_chip.h>
#include <csl_irq.h>
#include <csl_dma.h>
#include <csl_edma.h>


#if (DAT_SUPPORT)
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

#ifdef  _DAT_MOD_
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
#if (DMA_SUPPORT)
  #define DAT_CHAANY    DMA_CHAANY
  #define DAT_CHA0      DMA_CHA0
  #define DAT_CHA1      DMA_CHA1
  #define DAT_CHA2      DMA_CHA2
  #define DAT_CHA3      DMA_CHA3
  #define DAT_PRI_LOW   DMA_PRICTL_PRI_CPU
  #define DAT_PRI_HIGH  DMA_PRICTL_PRI_DMA

  #define DAT_1D2D      0x000000D0
  #define DAT_2D1D      0x00000070
  #define DAT_2D2D      0x000000F0

#elif (EDMA_SUPPORT)
  #define DAT_CHAANY    0
  #define DAT_CHA0      0
  #define DAT_CHA1      0
  #define DAT_CHA2      0
  #define DAT_CHA3      0
  #define DAT_PRI_LOW   EDMA_OPT_PRI_LOW
  #define DAT_PRI_HIGH  EDMA_OPT_PRI_HIGH

  #define DAT_1D2D      0x01A00001
  #define DAT_2D1D      0x05200001
  #define DAT_2D2D      0x05A00001
#endif

/* open flags */
#define DAT_OPEN_2D    1

/* special magic transfer IDs */
#define DAT_XFRID_WAITALL   0xFFFFFFFF
#define DAT_XFRID_WAITNONE  0xFFFF0010


/******************************************************************************\
* global typedef declarations
\******************************************************************************/
#if (DMA_SUPPORT)
  typedef struct {
    Uint32 useMask;
    Uint32 baseAddr;
    Uint32 gblcntAddr;
    Uint32 gblidxAddr;
    Uint32 initPrictl;
  } _DAT_StateStruct;
#endif

#if (EDMA_SUPPORT)
  typedef struct {
    Uint32 useMask;
    Uint32 baseAddr;
    Uint32 initOpt;
  } _DAT_StateStruct;
#endif


/******************************************************************************\
* global variable declarations
\******************************************************************************/
extern far _DAT_StateStruct _DAT_stateStruct;


/******************************************************************************\
* global function declarations
\******************************************************************************/
CSLAPI int DAT_open(int chaNum, int priority, Uint32 flags);
CSLAPI void DAT_close();

CSLAPI Uint32 DAT_copy(void *src , void *dst , Uint16 byteCnt);
CSLAPI Uint32 DAT_fill(void *dst , Uint16 byteCnt, Uint32 *value);
CSLAPI void   DAT_wait(Uint32 id);
CSLAPI int    DAT_busy(Uint32 id);

CSLAPI Uint32 DAT_copy2d(Uint32 type, void *src, void *dst, Uint16 lineLen, Uint16 lineCnt, Uint16 linePitch);


/******************************************************************************\
* inline function declarations
\******************************************************************************/
IDECL void DAT_setPriority(int priority);


/******************************************************************************\
* inline function definitions
\******************************************************************************/
#ifdef USEDEFS
/*----------------------------------------------------------------------------*/
IDEF void DAT_setPriority(int priority) {
  #if (DMA_SUPPORT)
    DMA_FSETA(&(_DAT_stateStruct.initPrictl), PRICTL, PRI, priority);
  #endif

  #if (EDMA_SUPPORT)
    EDMA_FSETA(&(_DAT_stateStruct.initOpt), OPT, PRI, priority);
  #endif 
}
/*----------------------------------------------------------------------------*/
#endif /* USEDEFS */


#endif /* DAT_SUPPORT */
#endif /* _CSL_DAT_H_ */
/******************************************************************************\
* End of csl_dat.h
\******************************************************************************/

