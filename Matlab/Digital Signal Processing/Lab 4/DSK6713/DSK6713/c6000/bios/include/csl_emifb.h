/******************************************************************************\
*           Copyright (C) 2001 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_emifb.h
* DATE CREATED.. 03/27/2001 
* LAST MODIFIED. 01/31/2002 SDCTL reg. setting after SDEXT reg.setting
\******************************************************************************/
#ifndef _CSL_EMIFB_H_
#define _CSL_EMIFB_H_

#include <csl_chip.h>
#include <csl_irq.h>
#include <csl_emifbhal.h>


#if (EMIFB_SUPPORT)
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

#ifdef  _EMIFB_MOD_
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

/* device configuration structure */
typedef struct {
  Uint32 gblctl;
  Uint32 cectl0;
  Uint32 cectl1;
  Uint32 cectl2;
  Uint32 cectl3;
  Uint32 sdctl;
  Uint32 sdtim;
  Uint32 sdext;
  Uint32 cesec0;
  Uint32 cesec1;
  Uint32 cesec2;
  Uint32 cesec3;
} EMIFB_Config;


/******************************************************************************\
* global variable declarations
\******************************************************************************/


/******************************************************************************\
* global function declarations
\******************************************************************************/


/******************************************************************************\
* inline function declarations
\******************************************************************************/
#if (CHIP_6414 | CHIP_6415 | CHIP_6416 ) 
IDECL void EMIFB_config(EMIFB_Config *config);
IDECL void EMIFB_configArgs(Uint32 gblctl, Uint32 cectl0, Uint32 cectl1,
    Uint32 cectl2, Uint32 cectl3, Uint32 sdctl, Uint32 sdtim, Uint32 sdext, Uint32 cesec0,
    Uint32 cesec1, Uint32 cesec2, Uint32 cesec3);
IDECL void EMIFB_getConfig(EMIFB_Config *config);
#endif

/******************************************************************************\
* inline function definitions
\******************************************************************************/
#ifdef USEDEFS
/*----------------------------------------------------------------------------*/
#if (CHIP_6414 | CHIP_6415 | CHIP_6416 ) 
IDEF void EMIFB_config(EMIFB_Config *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)_EMIFB_BASE_GLOBAL;
  register int x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together raher than intermixed   */
  x0  = config->gblctl;
  x1  = config->cectl0;
  x2  = config->cectl1;
  x3  = config->cectl2;
  x4  = config->cectl3;
  x5  = config->sdctl;
  x6  = config->sdtim;
  x7  = config->sdext;
  x8  = config->cesec0;
  x9  = config->cesec1;
  x10 = config->cesec2;
  x11 = config->cesec3;

  base[_EMIFB_GBLCTL_OFFSET]  = x0;
  base[_EMIFB_CECTL0_OFFSET]  = x1;
  base[_EMIFB_CECTL1_OFFSET]  = x2;
  base[_EMIFB_CECTL2_OFFSET]  = x3;
  base[_EMIFB_CECTL3_OFFSET]  = x4;
  base[_EMIFB_SDTIM_OFFSET]   = x6;
  base[_EMIFB_SDEXT_OFFSET]   = x7;
  base[_EMIFB_CESEC0_OFFSET]  = x8;
  base[_EMIFB_CESEC1_OFFSET]  = x9;
  base[_EMIFB_CESEC2_OFFSET]  = x10;
  base[_EMIFB_CESEC3_OFFSET]  = x11;

  base[_EMIFB_SDCTL_OFFSET]   = x5;


  IRQ_globalRestore(gie);
}
#endif /* C64_SUPPORT */
/*----------------------------------------------------------------------------*/
#if (CHIP_6414 | CHIP_6415 | CHIP_6416 ) 
IDEF void EMIFB_configArgs(Uint32 gblctl, Uint32 cectl0, Uint32 cectl1,
  Uint32 cectl2, Uint32 cectl3, Uint32 sdctl, Uint32 sdtim, Uint32 sdext,
  Uint32 cesec0, Uint32 cesec1, Uint32 cesec2, Uint32 cesec3) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)_EMIFB_BASE_GLOBAL;

  gie = IRQ_globalDisable();

  base[_EMIFB_GBLCTL_OFFSET]  = gblctl;
  base[_EMIFB_CECTL0_OFFSET]  = cectl0;
  base[_EMIFB_CECTL1_OFFSET]  = cectl1;
  base[_EMIFB_CECTL2_OFFSET]  = cectl2;
  base[_EMIFB_CECTL3_OFFSET]  = cectl3;
  base[_EMIFB_SDTIM_OFFSET]   = sdtim;
  base[_EMIFB_SDEXT_OFFSET]   = sdext;
  base[_EMIFB_CESEC0_OFFSET]  = cesec0;
  base[_EMIFB_CESEC1_OFFSET]  = cesec1;
  base[_EMIFB_CESEC2_OFFSET]  = cesec2;
  base[_EMIFB_CESEC3_OFFSET]  = cesec3;

  base[_EMIFB_SDCTL_OFFSET]   = sdctl;

  IRQ_globalRestore(gie);
}

#endif 
/*----------------------------------------------------------------------------*/
#if (CHIP_6414 | CHIP_6415 | CHIP_6416 ) 
IDEF void EMIFB_getConfig(EMIFB_Config *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)_EMIFB_BASE_GLOBAL;
  volatile EMIFB_Config* cfg = (volatile EMIFB_Config*)config;
  register int x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together raher than intermixed   */

  x0  = base[_EMIFB_GBLCTL_OFFSET];
  x1  = base[_EMIFB_CECTL0_OFFSET];
  x2  = base[_EMIFB_CECTL1_OFFSET];
  x3  = base[_EMIFB_CECTL2_OFFSET];
  x4  = base[_EMIFB_CECTL3_OFFSET];
  x5  = base[_EMIFB_SDCTL_OFFSET];
  x6  = base[_EMIFB_SDTIM_OFFSET];
  x7  = base[_EMIFB_SDEXT_OFFSET];
  x8  = base[_EMIFB_CESEC0_OFFSET];
  x9  = base[_EMIFB_CESEC1_OFFSET];
  x10 = base[_EMIFB_CESEC2_OFFSET];
  x11 = base[_EMIFB_CESEC3_OFFSET];

  cfg->gblctl  = x0;
  cfg->cectl0  = x1;
  cfg->cectl1  = x2;
  cfg->cectl2  = x3;
  cfg->cectl3  = x4;
  cfg->sdctl   = x5;
  cfg->sdtim   = x6;
  cfg->sdext   = x7;
  cfg->cesec0  = x8;
  cfg->cesec1  = x9;
  cfg->cesec2  = x10;
  cfg->cesec3  = x11;

  IRQ_globalRestore(gie);
}
#endif /* C64_SUPPORT */
/*----------------------------------------------------------------------------*/
#endif /* USEDEFS */


#endif /* EMIFB_SUPPORT */
#endif /* _CSL_EMIFB_H_ */
/******************************************************************************\
* End of csl_emifb.h
\******************************************************************************/

