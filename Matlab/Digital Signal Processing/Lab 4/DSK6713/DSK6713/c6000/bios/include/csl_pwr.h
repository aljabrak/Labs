/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_pwr.h
* DATE CREATED.. 11/11/1999 
* LAST MODIFIED. 10/03/2000
\******************************************************************************/
#ifndef _CSL_PWR_H_
#define _CSL_PWR_H_

#include <csl_stdinc.h>
#include <csl_chip.h>
#include <csl_pwrhal.h>


#if (PWR_SUPPORT)
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

#ifdef  _PWR_MOD_
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
typedef enum {
  PWR_NONE = 0x00,
  PWR_PD1A = 0x09,
  PWR_PD1B = 0x11, 
  PWR_PD2  = 0x1A,
  PWR_PD3  = 0x1C,
  PWR_IDLE = 0xFF
} PWR_Mode;

#if (_PWR_COND1)
  typedef struct {
    Uint32 pdctl;
  } PWR_Config;
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
IDECL void PWR_powerDown(PWR_Mode mode);
#if (_PWR_COND1)
  IDECL void PWR_config(PWR_Config *config);
  IDECL void PWR_configArgs(Uint32 pdctl);
  IDECL void PWR_getConfig(PWR_Config *config);
#endif


/******************************************************************************\
* inline function definitions
\******************************************************************************/
#ifdef USEDEFS
/*----------------------------------------------------------------------------*/
IDEF void PWR_powerDown(PWR_Mode mode) {
  if (mode == PWR_IDLE) {
    asm(" IDLE");
  } else {
    CHIP_FSET(CSR,PWRD,(Uint32)mode);
  }
}
/*----------------------------------------------------------------------------*/
#if (_PWR_COND1)
  IDEF void PWR_config(PWR_Config *config) {
    PWR_RSET(PDCTL,config->pdctl);
  }
#endif
/*----------------------------------------------------------------------------*/
#if (_PWR_COND1)
  IDEF void PWR_configArgs(Uint32 pdctl) {
    PWR_RSET(PDCTL,pdctl);
  }
#endif
/*----------------------------------------------------------------------------*/
#if (_PWR_COND1)
  IDEF void PWR_getConfig(PWR_Config *config) {
    volatile PWR_Config* cfg = (volatile PWR_Config*)config;
    cfg->pdctl = PWR_RGET(PDCTL);
  }
#endif
/*----------------------------------------------------------------------------*/
#endif /* USEDEFS */


#endif /* PWR_SUPPORT */
#endif /* _CSL_PWR_H_ */
/******************************************************************************\
* End of csl_pwr.h
\******************************************************************************/

