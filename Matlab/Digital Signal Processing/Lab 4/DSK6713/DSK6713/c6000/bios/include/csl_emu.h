/**************************************************************************\
*              Copyright (C) 2002 Texas Instruments Incorporated.
*                             All Rights Reserved
*--------------------------------------------------------------------------
* MODULE NAME... EMU
* FILENAME...... csl_emu.h
* DATE CREATED.. 05/12/2003
* LAST MODIFIED. 05/20/2003
* PROJECT....... Chip Support Library
* COMPONENT..... Service Layer
* PREREQUISITES.
\**************************************************************************/
/**************************************************************************\
* Private Macros - Include files - EMU_SUPPORT
\**************************************************************************/
#ifndef _CSL_EMU_H_
#define _CSL_EMU_H_

#include <csl_stdinc.h>
#include <csl_emuhal.h>

#if (EMU_SUPPORT)

/**************************************************************************\
* EMU scope and inline control macros
\**************************************************************************/

#ifdef __cplusplus
#   define CSLAPI extern "C" far
#else
#   define CSLAPI extern far
#endif

#undef USEDEFS
#undef IDECL
#undef IDEF

#ifdef      _EMU_MOD_
#   define  IDECL CSLAPI
#   define  USEDEFS
#   define  IDEF
#else
#   ifdef   _INLINE
#       define  IDECL           static inline
#       define  USEDEFS
#       define  IDEF            static inline
#   else
#       define  IDECL           CSLAPI
#   endif
#endif

/**************************************************************************\
* EMU global macro declarations
\**************************************************************************/

#define EMU_DEVICE_CNT            (1)        /* The number of EMU devices */

#define EMU_SUCCESS               (1)

#define EMU_FAILURE               (0)

/**************************************************************************\
* EMU global typedef declarations
\**************************************************************************/
/**************************************************************************\
* EMU global function declarations
\**************************************************************************/

CSLAPI Uint32  EMU_setDBGM(
    void
);


CSLAPI Uint32  EMU_clrDBGM(
    void
);


CSLAPI Uint32  EMU_getDBGM(
    void
);


CSLAPI void  EMU_setABORTI(
    void
);


CSLAPI void  EMU_clrABORTI(
    void
);


CSLAPI Uint32  EMU_setEALLOW(
    void
);


CSLAPI Uint32  EMU_clrEALLOW(
    void
);


CSLAPI Uint32  EMU_getEALLOW(
    void
);


CSLAPI Uint32  EMU_getDBGSTAT(
    void
);

/**************************************************************************\
* EMU inline function declarations
\**************************************************************************/
/**************************************************************************\
* EMU inline function declarations
\**************************************************************************/

#ifdef USEDEFS

#endif /*USEDEFS */



#endif      /* EMU_SUPPORT  */

#endif      /* _CSL_EMUHAL_H  */

/**************************************************************************\
*                               End of csl_emu.h
\**************************************************************************/
