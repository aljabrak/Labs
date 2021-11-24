/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_atl.h
* DATE CREATED.. 07/01/2003 
* LAST MODIFIED. 
\******************************************************************************/
#ifndef _CSL_ATL_H_
#define _CSL_ATL_H_

#include <csl_chip.h>
#include <csl_irq.h>
#include <csl_atlhal.h>


#if (ATL_SUPPORT)
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

#ifdef  _I2C_MOD_
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
	Uint32 atlppmr;
	Uint32 atlcr;
} ATL_Config;

/******************************************************************************\
* global variable declarations
\******************************************************************************/

/******************************************************************************\
* global function declarations
\******************************************************************************/

/******************************************************************************\
* inline function declarations
\******************************************************************************/
IDECL void ATL_config(ATL_Config *config);
IDECL void ATL_configArgs(Uint32 atlppmr, Uint32 atlcr);
IDECL void ATL_getConfig(ATL_Config *config);

/******************************************************************************\
* inline function definitions
\******************************************************************************/
#ifdef USEDEFS
/*----------------------------------------------------------------------------*/
IDEF void ATL_config(ATL_Config *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)_ATL_BASE_PORT;
  register int x0,x1;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together raher than intermixed   */
  x0  = config->atlppmr;
  x1  = config->atlcr;

  base[_ATL_ATLPPMR_OFFSET]  = x0;
  base[_ATL_ATLCR_OFFSET]  = x1;

  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void ATL_configArgs(Uint32 atlppmr, Uint32 atlcr) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)_ATL_BASE_PORT;

  gie = IRQ_globalDisable();

  base[_ATL_ATLPPMR_OFFSET]  = atlppmr;
  base[_ATL_ATLCR_OFFSET]  = atlcr;

  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void ATL_getConfig(ATL_Config *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)_ATL_BASE_PORT;
  volatile ATL_Config* cfg = (volatile ATL_Config*)config;
  register int x0,x1;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together raher than intermixed   */

  x0  = base[_ATL_ATLPPMR_OFFSET];
  x1  = base[_ATL_ATLCR_OFFSET];

  cfg->atlppmr  = x0;
  cfg->atlcr  = x1;

  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
#endif /* USEDEFS */

#endif /* ATL_SUPPORT */

#endif /* _CSL_ATL_H_ */
/******************************************************************************\
* End of csl_atl.h
\******************************************************************************/

