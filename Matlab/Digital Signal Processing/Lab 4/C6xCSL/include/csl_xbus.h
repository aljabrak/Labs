/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_xbus.h
* DATE CREATED.. 06/12/2000 
* LAST MODIFIED. 10/03/2000 
\******************************************************************************/
#ifndef _CSL_XBUS_H_
#define _CSL_XBUS_H_

#include <csl_chip.h>
#include <csl_irq.h>
#include <csl_xbushal.h>


#if (XBUS_SUPPORT)
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

#ifdef  _XBUS_MOD_
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
  Uint32 xbgc;
  Uint32 xcectl0;
  Uint32 xcectl1;
  Uint32 xcectl2;
  Uint32 xcectl3;
  Uint32 xbhc;
  Uint32 xbima;
  Uint32 xbea;
} XBUS_Config;


/******************************************************************************\
* global variable declarations
\******************************************************************************/


/******************************************************************************\
* global function declarations
\******************************************************************************/


/******************************************************************************\
* inline function declarations
\******************************************************************************/

IDECL void XBUS_config(XBUS_Config *config);
IDECL void XBUS_configArgs(Uint32 xbgc, Uint32 xcectl0, Uint32 xcectl1,
  Uint32 xcectl2, Uint32 xcectl3, Uint32 xbhc, Uint32 xbima, Uint32 xbea);
IDECL void XBUS_getConfig(XBUS_Config *config);


/******************************************************************************\
* inline function definitions
\******************************************************************************/
#ifdef USEDEFS
/*----------------------------------------------------------------------------*/
IDEF void XBUS_config(XBUS_Config *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)_XBUS_BASE_GLOBAL;
  register int x0,x1,x2,x3,x4,x5,x6,x7;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together raher than intermixed   */
  x0 = config->xbgc;
  x1 = config->xcectl0;
  x2 = config->xcectl1;
  x3 = config->xcectl2;
  x4 = config->xcectl3;
  x5 = config->xbhc;
  x6 = config->xbima;
  x7 = config->xbea;

  base[_XBUS_XBGC_OFFSET]    = x0;
  base[_XBUS_XCECTL0_OFFSET] = x1;
  base[_XBUS_XCECTL1_OFFSET] = x2;
  base[_XBUS_XCECTL2_OFFSET] = x3;
  base[_XBUS_XCECTL3_OFFSET] = x4;
  base[_XBUS_XBHC_OFFSET]    = x5;
  base[_XBUS_XBIMA_OFFSET]   = x6;
  base[_XBUS_XBEA_OFFSET]    = x7;

  IRQ_globalRestore(gie);
}

/*----------------------------------------------------------------------------*/
IDEF void XBUS_configArgs(Uint32 xbgc, Uint32 xcectl0, Uint32 xcectl1,
  Uint32 xcectl2, Uint32 xcectl3, Uint32 xbhc, Uint32 xbima, Uint32 xbea) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)_XBUS_BASE_GLOBAL;

  gie = IRQ_globalDisable();

  base[_XBUS_XBGC_OFFSET]    = xbgc;
  base[_XBUS_XCECTL0_OFFSET] = xcectl0;
  base[_XBUS_XCECTL1_OFFSET] = xcectl1;
  base[_XBUS_XCECTL2_OFFSET] = xcectl2;
  base[_XBUS_XCECTL3_OFFSET] = xcectl3;
  base[_XBUS_XBHC_OFFSET]    = xbhc;
  base[_XBUS_XBIMA_OFFSET]   = xbima;
  base[_XBUS_XBEA_OFFSET]    = xbea;

  IRQ_globalRestore(gie);
}

/*----------------------------------------------------------------------------*/
IDEF void XBUS_getConfig(XBUS_Config *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)_XBUS_BASE_GLOBAL;
  volatile XBUS_Config* cfg = (volatile XBUS_Config*)config;
  register int x0,x1,x2,x3,x4,x5,x6,x7;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together raher than intermixed   */

  x0 = base[_XBUS_XBGC_OFFSET];
  x1 = base[_XBUS_XCECTL0_OFFSET];
  x2 = base[_XBUS_XCECTL1_OFFSET];
  x3 = base[_XBUS_XCECTL2_OFFSET];
  x4 = base[_XBUS_XCECTL3_OFFSET];
  x5 = base[_XBUS_XBHC_OFFSET];
  x6 = base[_XBUS_XBIMA_OFFSET];  
  x7 = base[_XBUS_XBEA_OFFSET];

  cfg->xbgc    = x0;
  cfg->xcectl0 = x1;
  cfg->xcectl1 = x2;
  cfg->xcectl2 = x3;
  cfg->xcectl3 = x4;
  cfg->xbhc    = x5;
  cfg->xbima   = x6;
  cfg->xbea    = x7;

  IRQ_globalRestore(gie);
}

/*----------------------------------------------------------------------------*/
#endif /* USEDEFS */


#endif /* XBUS_SUPPORT */
#endif /* _CSL_XBUS_H_ */
/******************************************************************************\
* End of csl_xbus.h
\******************************************************************************/

