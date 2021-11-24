/******************************************************************************\
*           Copyright (C) 1999-2001 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_chip.h
* DATE CREATED.. 08/19/1999 
* LAST MODIFIED. 08/02/2004 - Adding support for C6418
*                06/17/2003   - Added support for 6712C
*                06/09/2003   - Added support for 6711C
*                12/03/2001   - CHIP_configArgs
*                11/08/2001   - CHIP_getSiliconRevId()
*                             - CHIP_config() / CHIP_getConfig  DM642
\******************************************************************************/
#ifndef _CSL_CHIP_H_
#define _CSL_CHIP_H_

#include <csl_stdinc.h>

#include <csl_chiphal.h>
#include <csl_emifhal.h>

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

#ifdef  _CHIP_MOD_
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
#define CHIP_ENDIAN_BIG    0
#define CHIP_ENDIAN_LITTLE 1

#define CHIP_MAP_0         0
#define CHIP_MAP_1         1

/* Selected devices masks*/
#if (CHIP_6713 || CHIP_DA610 || CHIP_6711C || CHIP_6712C)
#define CHIP_EKSRC_SYSCLK3  0x00000000u
#define CHIP_EKSRC_ECLKIN   0x00000010u
#endif

#if (CHIP_6713 || CHIP_DA610)
#define CHIP_TOUT1          0x00000000u
#define CHIP_AXR04_AXR111   0x00000008u

#define CHIP_TOUT0          0x00000000u
#define CHIP_AXR02_AXR113   0x00000004u

#define CHIP_MCASP0         0x00000002u
#define CHIP_MCBSP0         0x00000000u

#define CHIP_I2C1           0x00000001u
#define CHIP_MCBSP1         0x00000000u
/* Full mask value */
#define _CHIP_DEVCFG_MASK  0x0000001Fu
#endif

#if CHIP_DM642
#define CHIP_VP2            0x00000040u
#define CHIP_VP1            0x00000020u
#define CHIP_VP0            0x00000010u
#define CHIP_I2C            0x00000008u
#define CHIP_MCBSP1         0x00000004u
#define CHIP_MCBSP0         0x00000002u
#define CHIP_MCASP0         0x00000001u

#define _CHIP_PERCFG_MASK   0x0000007Fu
#endif

#if CHIP_DM641
#define CHIP_VP1            0x00000020u
#define CHIP_VP0            0x00000010u
#define CHIP_I2C            0x00000008u
#define CHIP_MCBSP1         0x00000004u
#define CHIP_MCBSP0         0x00000002u
#define CHIP_MCASP0         0x00000001u

#define _CHIP_PERCFG_MASK   0x0000003Fu
#endif

#if CHIP_DM640
#define CHIP_VP0            0x00000010u
#define CHIP_I2C            0x00000008u
#define CHIP_MCBSP1         0x00000004u
#define CHIP_MCBSP0         0x00000002u
#define CHIP_MCASP0         0x00000001u

#define _CHIP_PERCFG_MASK   0x0000001Fu
#endif

#if CHIP_6412
#define CHIP_I2C            0x00000008u
#define CHIP_MCBSP1         0x00000004u
#define CHIP_MCBSP0         0x00000002u
#define _CHIP_PERCFG_MASK   0x0000000Eu
#endif

#if (CHIP_6410 || CHIP_6413 || CHIP_6418)
#define CHIP_AFCMUX         0x00000600u
#define CHIP_MCASP1         0x00000100u
#define CHIP_I2C1           0x00000080u
#define CHIP_I2C0           0x00000008u
#define CHIP_MCBSP1         0x00000004u
#define CHIP_MCBSP0         0x00000002u
#define CHIP_MCASP0         0x00000001u

#define _CHIP_PERCFG_MASK   0x0000078Fu
#endif

/******************************************************************************\
* global typedef declarations
\******************************************************************************/
#if( CHIP_6711C || CHIP_6712C || CHIP_DA610 || CHIP_6713 )
typedef struct{
   Uint32 devcfg;
} CHIP_Config;
#elif (CHIP_DM642 || CHIP_DM641 || CHIP_DM640  || CHIP_6412 || CHIP_6410 || CHIP_6413 || CHIP_6418)
typedef struct{
   Uint32 percfg;
} CHIP_Config; 
#endif
/******************************************************************************\
* global variable declarations
\******************************************************************************/


/******************************************************************************\
* global function declarations
\******************************************************************************/


/******************************************************************************\
* inline function declarations
\******************************************************************************/
IDECL Uint32 CHIP_getCpuId();
IDECL Uint32 CHIP_getRevId();
IDECL Uint32 CHIP_getSiliconRevId();
IDECL int    CHIP_getEndian();
IDECL int    CHIP_getMapMode();

#if (CHIP_DM642 || CHIP_DM641 || CHIP_DM640  || CHIP_6412 || CHIP_6410 || CHIP_6413 || CHIP_6418) 
IDECL void   CHIP_config(CHIP_Config *config);
IDECL void   CHIP_configArgs(Uint32 percfg);
IDECL void   CHIP_getConfig(CHIP_Config *config); 
#elif ( CHIP_6711C || CHIP_6712C || CHIP_DA610 || CHIP_6713 )
IDECL void   CHIP_config(CHIP_Config *config);
IDECL void   CHIP_configArgs(Uint32 devcfg);
IDECL void   CHIP_getConfig(CHIP_Config *config); 
#endif

/******************************************************************************\
* inline function definitions
\******************************************************************************/
#ifdef USEDEFS
/*----------------------------------------------------------------------------*/
IDEF Uint32 CHIP_getCpuId() {
  return CHIP_FGET(CSR,CPUID);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 CHIP_getRevId() {
  return CHIP_FGET(CSR,REVID);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 CHIP_getSiliconRevId() {
  return (( 0x000F0000 & REG32(0x01B00200))>>16);
}
/*----------------------------------------------------------------------------*/
IDEF int CHIP_getEndian() {
  return CHIP_FGET(CSR,EN);
}
/*----------------------------------------------------------------------------*/
IDEF int CHIP_getMapMode() {
  int mapmode = 0;
  #if (!C11_SUPPORT && !C64_SUPPORT)
    mapmode = EMIF_FGET(GBLCTL,MAP);
  #endif
  return mapmode;
}
/*----------------------------------------------------------------------------*/
#if (CHIP_6713 || CHIP_DM642 || CHIP_DM641 || CHIP_DM640 || CHIP_DA610 || CHIP_6412 || CHIP_6711C || CHIP_6712C || CHIP_6410 || CHIP_6413 || CHIP_6418)
IDEF void   CHIP_config(CHIP_Config *config) {
  Uint32 gie = CHIP_FGET(CSR,GIE);
  
#if( CHIP_6711C || CHIP_6712C || CHIP_DA610 || CHIP_6713 ) 
    volatile Uint32 *base = (volatile Uint32 *)(_CHIP_DEVCFG_ADDR);
    register int x0;
    CHIP_FSET(CSR,GIE,0);
    x0 = config->devcfg;
    base[_CHIP_DEVCFG_OFFSET] = x0;
    CHIP_FSET(CSR,GIE,gie);
    
#else 
  volatile Uint32 *base = (volatile Uint32 *)(_CHIP_PERCFG_ADDR);
  register int x0;
  CHIP_FSET(CSR,GIE,0);
  CHIP_FSETS(PCFGLOCK,LOCK,UNLOCK);
  x0 = config->percfg;
  base[_CHIP_PERCFG_OFFSET] = x0;
  CHIP_FSET(CSR,GIE,gie);
  
#endif
}      
#endif
/*----------------------------------------------------------------------------*/
#if (CHIP_6713 || CHIP_DM642 || CHIP_DM641 || CHIP_DM640 || CHIP_DA610 || CHIP_6412 || CHIP_6711C || CHIP_6712C || CHIP_6410 || CHIP_6413 || CHIP_6418)
IDEF void   CHIP_getConfig(CHIP_Config *config) {
   Uint32 gie = CHIP_FGET(CSR,GIE);
   
#if( CHIP_6711C || CHIP_6712C || CHIP_DA610 || CHIP_6713 ) 
   volatile Uint32 *base = (volatile Uint32 *)(_CHIP_DEVCFG_ADDR);
   register int x0;

   CHIP_FSET(CSR,GIE,0);

   x0 = base[_CHIP_DEVCFG_OFFSET]; 
   config->devcfg=x0;

   CHIP_FSET(CSR,GIE,gie);
   
#else
   volatile Uint32 *base = (volatile Uint32 *)(_CHIP_PERCFG_ADDR);
   register int x0;

   CHIP_FSET(CSR,GIE,0);

   x0 = base[_CHIP_PERCFG_OFFSET]; 
   config->percfg=x0;

   CHIP_FSET(CSR,GIE,gie);
   
#endif
}      
#endif
/*----------------------------------------------------------------------------*/
   
#if( CHIP_6711C || CHIP_6712C || CHIP_DA610 || CHIP_6713 )
   IDEF void   CHIP_configArgs(Uint32 devcfg) {
   Uint32 gie = CHIP_FGET(CSR,GIE);
   volatile Uint32 *base = (volatile Uint32 *)(_CHIP_DEVCFG_ADDR);
   CHIP_FSET(CSR,GIE,0);
   base[_CHIP_DEVCFG_OFFSET]= devcfg; 
   CHIP_FSET(CSR,GIE,gie);
}   
#elif (CHIP_DM642 || CHIP_DM641 || CHIP_DM640  || CHIP_6412 || CHIP_6410 || CHIP_6413 || CHIP_6418)
   IDEF void   CHIP_configArgs(Uint32 percfg) {
   Uint32 gie = CHIP_FGET(CSR,GIE);
   volatile Uint32 *base = (volatile Uint32 *)(_CHIP_PERCFG_ADDR);

   CHIP_FSET(CSR,GIE,0);

#if(CHIP_DM642 || CHIP_6412)
   CHIP_FSETS(PCFGLOCK,LOCK,UNLOCK);
#endif

   base[_CHIP_PERCFG_OFFSET]= percfg; 

   CHIP_FSET(CSR,GIE,gie);
}   
#endif


/*----------------------------------------------------------------------------*/
#endif /* USEDEFS */


#endif /* _CSL_CHIP_H_ */
/******************************************************************************\
* End of csl_chip.h
\******************************************************************************/

