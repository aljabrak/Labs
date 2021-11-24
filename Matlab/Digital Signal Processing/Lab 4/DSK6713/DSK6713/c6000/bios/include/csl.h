/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl.h
* DATE CREATED.. 06/13/2000 
* LAST MODIFIED. 08/02/2004 - Adding support for C6418
*                07/24/2004 - Re-introducing BIOS components from CSL due to compatibility issues.
*                06/26/2003  Added CHIP_6411
*                06/17/2003  Added CHIP_6712C
*                05/28/2003  Added CHIP_6711C
*                03/26/2003 -  6412,DM642 check libraries 
*                10/10/2001 -  6712-6713-6414-6416-6415  check libraries
*                11/19/2003 - Removed BIOS components from CSL - _CSL_Config
*
\******************************************************************************/
#ifndef _CSL_H_
#define _CSL_H_

#include <csl_chip.h>
#include <csl_irq.h>
#include <csl_timer.h>


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

#ifdef  _CSL_MOD_
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


/******************************************************************************\
* global typedef declarations
\******************************************************************************/

/* if this structure changes, be sure to also change it in csl_irq_.asm */
typedef union {
  struct {
    Uint32 biosPresent;
    _IRQ_Dispatch *dispatchTable;
    Uint32 timerUsed;
    Uint32 timerNum;
  } args;
  struct {
    TIMER_Handle hTimer;
    Uint32 *event2IntTbl;
    Uint32 *int2EventTbl;
  } ret;
} _CSL_Config;
/******************************************************************************\
* global variable declarations
\******************************************************************************/

/******************************************************************************\
* global function declarations
\******************************************************************************/
CSLAPI void _CSL_init(_CSL_Config *config);

CSLAPI void CSL6201_LIB_();
CSLAPI void CSL6202_LIB_();
CSLAPI void CSL6203_LIB_();
CSLAPI void CSL6204_LIB_();
CSLAPI void CSL6205_LIB_();
CSLAPI void CSL6211_LIB_();
CSLAPI void CSL6701_LIB_();
CSLAPI void CSL6711_LIB_();
CSLAPI void CSL6712_LIB_();
CSLAPI void CSL6713_LIB_();
CSLAPI void CSLDA610_LIB_();
CSLAPI void CSLDM642_LIB_();
CSLAPI void CSLDM640_LIB_();
CSLAPI void CSLDM641_LIB_();
CSLAPI void CSL6412_LIB_();
CSLAPI void CSL6414_LIB_();
CSLAPI void CSL6415_LIB_();
CSLAPI void CSL6416_LIB_();
CSLAPI void CSL6711C_LIB_();
CSLAPI void CSL6712C_LIB_();
CSLAPI void CSL6411_LIB_();
/* next two options are DRI300 versions */
CSLAPI void CSL6410_LIB_();
CSLAPI void CSL6413_LIB_();
CSLAPI void CSL6418_LIB_();

/******************************************************************************\
* inline function declarations
\******************************************************************************/


/******************************************************************************\
* special inline function
\******************************************************************************/

/* This function checks to make sure that the correct library is being */
/* linked in compared to the CHIP_XXXX definition.                     */

static inline void CSL_init() {

  #if (CHIP_6201)
    CSL6201_LIB_();
  #elif (CHIP_6202)
    CSL6202_LIB_();
  #elif (CHIP_6203)
    CSL6203_LIB_();
  #elif (CHIP_6204)
    CSL6204_LIB_();
  #elif (CHIP_6205)
    CSL6205_LIB_();
  #elif (CHIP_6211)
    CSL6211_LIB_();
   #elif (CHIP_6701)
    CSL6701_LIB_();
  #elif (CHIP_6711)
    CSL6711_LIB_();
  #elif (CHIP_6712)
    CSL6712_LIB_();
  #elif (CHIP_6713)
    CSL6713_LIB_();
  #elif (CHIP_DA610)
    CSLDA610_LIB_();
  #elif (CHIP_DM642)
    CSLDM642_LIB_();
  #elif (CHIP_DM640)
    CSLDM640_LIB_();
  #elif (CHIP_DM641)
    CSLDM641_LIB_();
  #elif (CHIP_6412)
    CSL6412_LIB_();
  #elif (CHIP_6414)
    CSL6414_LIB_();
  #elif (CHIP_6415)
    CSL6415_LIB_();
 #elif (CHIP_6416)
    CSL6416_LIB_();
 #elif (CHIP_6711C)
    CSL6711C_LIB_();    
 #elif (CHIP_6712C)
    CSL6712C_LIB_();
 #elif (CHIP_6411)
    CSL6411_LIB_();
/* next three are DRI300 versions */
 #elif (CHIP_6410)
    CSL6410_LIB_();
 #elif (CHIP_6413)
    CSL6413_LIB_();
 #elif (CHIP_6418)
    CSL6418_LIB_();
 #endif

  _CSL_init((_CSL_Config*)INV);
}

/*----------------------------------------------------------------------------*/


/******************************************************************************\
* inline function definitions
\******************************************************************************/
#ifdef USEDEFS
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#endif /* USEDEFS */


#endif /* _CSL_H_ */
/******************************************************************************\
* End of csl.h
\******************************************************************************/

