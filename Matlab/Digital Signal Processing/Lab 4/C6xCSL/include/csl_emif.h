/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_emif.h
* DATE CREATED.. 06/11/1999 
* LAST MODIFIED. 01/31/2002 -SDCTL reg. setting after SDEXT reg. setting
\******************************************************************************/
#ifndef _CSL_EMIF_H_
#define _CSL_EMIF_H_

#include <csl_chip.h>
#include <csl_irq.h>
#include <csl_emifhal.h>


#if (EMIF_SUPPORT)
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

#ifdef  _EMIF_MOD_
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
  #if (C11_SUPPORT)
    Uint32 sdext;
  #endif
} EMIF_Config;


/******************************************************************************\
* global variable declarations
\******************************************************************************/


/******************************************************************************\
* global function declarations
\******************************************************************************/


/******************************************************************************\
* inline function declarations
\******************************************************************************/
IDECL void EMIF_config(EMIF_Config *config);

#if (C11_SUPPORT)
  IDECL void EMIF_configArgs(Uint32 gblctl, Uint32 cectl0, Uint32 cectl1,
    Uint32 cectl2, Uint32 cectl3, Uint32 sdctl, Uint32 sdtim, Uint32 sdext);
#else
  IDECL void EMIF_configArgs(Uint32 gblctl, Uint32 cectl0, Uint32 cectl1,
    Uint32 cectl2, Uint32 cectl3, Uint32 sdctl, Uint32 sdtim);
#endif

IDECL void EMIF_getConfig(EMIF_Config *config);


/******************************************************************************\
* inline function definitions
\******************************************************************************/
#ifdef USEDEFS
/*----------------------------------------------------------------------------*/
IDEF void EMIF_config(EMIF_Config *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)_EMIF_BASE_GLOBAL;
  register int x0,x1,x2,x3,x4,x5,x6;
  #if (C11_SUPPORT)
    register int x7;
  #endif

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together raher than intermixed   */
  x0 = config->gblctl;
  x1 = config->cectl0;
  x2 = config->cectl1;
  x3 = config->cectl2;
  x4 = config->cectl3;
  x5 = config->sdctl;
  x6 = config->sdtim;
  #if (C11_SUPPORT)
    x7 = config->sdext;
  #endif

  base[_EMIF_GBLCTL_OFFSET] = x0;
  base[_EMIF_CECTL0_OFFSET] = x1;
  base[_EMIF_CECTL1_OFFSET] = x2;
  base[_EMIF_CECTL2_OFFSET] = x3;
  base[_EMIF_CECTL3_OFFSET] = x4;
  base[_EMIF_SDTIM_OFFSET]  = x6;
  #if (C11_SUPPORT)
    base[_EMIF_SDEXT_OFFSET]  = x7;
  #endif
  base[_EMIF_SDCTL_OFFSET]  = x5;

  IRQ_globalRestore(gie);
}

/*----------------------------------------------------------------------------*/
#if (C11_SUPPORT)

IDEF void EMIF_configArgs(Uint32 gblctl, Uint32 cectl0, Uint32 cectl1,
  Uint32 cectl2, Uint32 cectl3, Uint32 sdctl, Uint32 sdtim, Uint32 sdext) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)_EMIF_BASE_GLOBAL;

  gie = IRQ_globalDisable();

  base[_EMIF_GBLCTL_OFFSET] = gblctl;
  base[_EMIF_CECTL0_OFFSET] = cectl0;
  base[_EMIF_CECTL1_OFFSET] = cectl1;
  base[_EMIF_CECTL2_OFFSET] = cectl2;
  base[_EMIF_CECTL3_OFFSET] = cectl3;  
  base[_EMIF_SDTIM_OFFSET]  = sdtim;
  base[_EMIF_SDEXT_OFFSET]  = sdext;
  base[_EMIF_SDCTL_OFFSET]  = sdctl;

  IRQ_globalRestore(gie);
}

#else

IDEF void EMIF_configArgs(Uint32 gblctl, Uint32 cectl0, Uint32 cectl1,
  Uint32 cectl2, Uint32 cectl3, Uint32 sdctl, Uint32 sdtim) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)_EMIF_BASE_GLOBAL;

  gie = IRQ_globalDisable();

  base[_EMIF_GBLCTL_OFFSET] = gblctl;
  base[_EMIF_CECTL0_OFFSET] = cectl0;
  base[_EMIF_CECTL1_OFFSET] = cectl1;
  base[_EMIF_CECTL2_OFFSET] = cectl2;
  base[_EMIF_CECTL3_OFFSET] = cectl3;
  base[_EMIF_SDTIM_OFFSET]  = sdtim;
  base[_EMIF_SDCTL_OFFSET]  = sdctl;

  IRQ_globalRestore(gie);
}

#endif /* (C11_SUPPORT) */

/*----------------------------------------------------------------------------*/
IDEF void EMIF_getConfig(EMIF_Config *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)_EMIF_BASE_GLOBAL;
  volatile EMIF_Config* cfg = (volatile EMIF_Config*)config;
  register int x0,x1,x2,x3,x4,x5,x6;
  #if (C11_SUPPORT)
    register int x7;
  #endif

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together raher than intermixed   */

  x0 = base[_EMIF_GBLCTL_OFFSET];
  x1 = base[_EMIF_CECTL0_OFFSET];
  x2 = base[_EMIF_CECTL1_OFFSET];
  x3 = base[_EMIF_CECTL2_OFFSET];
  x4 = base[_EMIF_CECTL3_OFFSET];
  x5 = base[_EMIF_SDCTL_OFFSET];
  x6 = base[_EMIF_SDTIM_OFFSET];
  #if (C11_SUPPORT)
    x7 = base[_EMIF_SDEXT_OFFSET];
  #endif

  cfg->gblctl = x0;
  cfg->cectl0 = x1;
  cfg->cectl1 = x2;
  cfg->cectl2 = x3;
  cfg->cectl3 = x4;
  cfg->sdctl  = x5;
  cfg->sdtim  = x6;
  #if (C11_SUPPORT)
    cfg->sdext  = x7;
  #endif

  IRQ_globalRestore(gie);
}

/*----------------------------------------------------------------------------*/
#endif /* USEDEFS */


#endif /* EMIF_SUPPORT */
#endif /* _CSL_EMIF_H_ */
/******************************************************************************\
* End of csl_emif.h
\******************************************************************************/

