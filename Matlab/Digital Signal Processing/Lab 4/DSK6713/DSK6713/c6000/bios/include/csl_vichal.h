/******************************************************************************\
*           Copyright (C) 1999-2001 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_vichal.h
* DATE CREATED.. 02/06/2002 
* LAST MODIFIED. 02/06/2002 Initial Draft
*------------------------------------------------------------------------------
* REGISTERS
*
* VICCTL - VIC Control register
* VICIN  - VIC Input register 
* VICDIV - VIC Clock Dividor registrer
*
\******************************************************************************/
#ifndef _CSL_VICHAL_H_
#define _CSL_VICHAL_H_

#include <csl_stdinc.h>
#include <csl_chip.h>

#if (VIC_SUPPORT)
/******************************************************************************\
* MISC section
\******************************************************************************/

#define _VIC_BASE_ADDR         0x01C4C000u 

/******************************************************************************\
* module level register/field access macros
\******************************************************************************/

  /* ----------------- */
  /* FIELD MAKE MACROS */
  /* ----------------- */

  #define VIC_FMK(REG,FIELD,x)\
    _PER_FMK(VIC,##REG,##FIELD,x)

  #define VIC_FMKS(REG,FIELD,SYM)\
    _PER_FMKS(VIC,##REG,##FIELD,##SYM)
 
 
  /* -------------------------------- */
  /* RAW REGISTER/FIELD ACCESS MACROS */
  /* -------------------------------- */

  #define VIC_ADDR(REG)\
    _VIC_##REG##_ADDR

  #define VIC_RGET(REG)\
    _PER_RGET(_VIC_##REG##_ADDR,VIC,##REG)

  #define VIC_RSET(REG,x)\
    _PER_RSET(_VIC_##REG##_ADDR,VIC,##REG,x)

  #define VIC_FGET(REG,FIELD)\
    _VIC_##REG##_FGET(##FIELD)

  #define VIC_FSET(REG,FIELD,x)\
    _VIC_##REG##_FSET(##FIELD,x)

  #define VIC_FSETS(REG,FIELD,SYM)\
    _VIC_##REG##_FSETS(##FIELD,##SYM)
 
 
  /* ------------------------------------------ */
  /* ADDRESS BASED REGISTER/FIELD ACCESS MACROS */
  /* ------------------------------------------ */

  #define VIC_RGETA(addr,REG)\
    _PER_RGET(addr,VIC,##REG)

  #define VIC_RSETA(addr,REG,x)\
    _PER_RSET(addr,VIC,##REG,x)

  #define VIC_FGETA(addr,REG,FIELD)\
    _PER_FGET(addr,VIC,##REG,##FIELD)

  #define VIC_FSETA(addr,REG,FIELD,x)\
    _PER_FSET(addr,VIC,##REG,##FIELD,x)

  #define VIC_FSETSA(addr,REG,FIELD,SYM)\
    _PER_FSETS(addr,VIC,##REG,##FIELD,##SYM)



/******************************************************************************\
* _____________________
* |                   |
* |  V I C C T L      |
* |___________________|
*
* VCICTL - VIC control register
*
* FIELDS (msb -> lsb)
* (rw)  PRECISION
* (rw)  GO
*
\******************************************************************************/
  #define _VIC_VICCTL_OFFSET             0
  #define _VIC_VICCTL_ADDR               (_VIC_BASE_ADDR + 4*_VIC_VICCTL_OFFSET) 

  #define _VIC_VICCTL_PRECISION_MASK         0x0000000Eu
  #define _VIC_VICCTL_PRECISION_SHIFT        0x00000001u
  #define  VIC_VICCTL_PRECISION_DEFAULT      0x00000000u
  #define  VIC_VICCTL_PRECISION_OF(x)        _VALUEOF(x)
  #define  VIC_VICCTL_PRECISION_16BITS       0x00000000u
  #define  VIC_VICCTL_PRECISION_15BITS       0x00000001u
  #define  VIC_VICCTL_PRECISION_14BITS       0x00000002u
  #define  VIC_VICCTL_PRECISION_13BITS       0x00000003u
  #define  VIC_VICCTL_PRECISION_12BITS       0x00000004u
  #define  VIC_VICCTL_PRECISION_11BITS       0x00000005u
  #define  VIC_VICCTL_PRECISION_10BITS       0x00000006u
  #define  VIC_VICCTL_PRECISION_9BITS        0x00000007u

  #define _VIC_VICCTL_GO_MASK                0x00000001u
  #define _VIC_VICCTL_GO_SHIFT               0x00000000u
  #define  VIC_VICCTL_GO_DEFAULT             0x00000000u
  #define  VIC_VICCTL_GO_OF(x)               _VALUEOF(x)
  #define  VIC_VICCTL_GO_0                   0x00000000u
  #define  VIC_VICCTL_GO_1                   0x00000001u

  #define  VIC_VICCTL_OF(x)              _VALUEOF(x)

  #define VIC_VICCTL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(VIC,VICCTL,PRECISION) \
    |_PER_FDEFAULT(VIC,VICCTL,GO) \
  )

  #define VIC_VICCTL_RMK(precision,go) (Uint32)( \
     _PER_FMK(VIC,VICCTL,PRECISION,precision) \
    |_PER_FMK(VIC,VICCTL,GO,go) \
   )

  #define _VIC_VICCTL_FGET(FIELD)\
    _PER_FGET(_VIC_VICCTL_ADDR,VIC,VICCTL,##FIELD)

  #define _VIC_VICCTL_FSET(FIELD,field)\
    _PER_FSET(_VIC_VICCTL_ADDR,VIC,VICCTL,##FIELD,field)

  #define _VIC_VICCTL_FSETS(FIELD,SYM)\
    _PER_FSETS(_VIC_VICCTL_ADDR,VIC,VICCTL,##FIELD,##SYM)
/******************************************************************************\
* _____________________
* |                   |
* |  V I C I N        |
* |___________________|
*
* VICIN - VIC Input Register
*
* FIELDS (msb -> lsb)
* (rw)  VICINBITS
*
\******************************************************************************/

  #define _VIC_VICIN_OFFSET             1
  #define _VIC_VICIN_ADDR               (_VIC_BASE_ADDR + 4*_VIC_VICIN_OFFSET) 

  #define _VIC_VICIN_VICINBITS_MASK         0x0000FFFFu
  #define _VIC_VICIN_VICINBITS_SHIFT        0x00000000u
  #define  VIC_VICIN_VICINBITS_DEFAULT      0x00000000u
  #define  VIC_VICIN_VICINBITS_OF(x)        _VALUEOF(x)

  #define VIC_VICIN_DEFAULT (Uint32)( \
     _PER_FDEFAULT(VIC,VICIN,VICINBITS) \
  )

  #define VIC_VICIN_RMK(vicinbits) (Uint32)( \
     _PER_FMK(VIC,VICIN,VICINBITS,vicinbits) \
   )

  #define _VIC_VICIN_FGET(FIELD)\
    _PER_FGET(_VIC_VICIN_ADDR,VIC,VICIN,##FIELD)

  #define _VIC_VICIN_FSET(FIELD,field)\
    _PER_FSET(_VIC_VICIN_ADDR,VIC,VICIN,##FIELD,field)

  #define _VIC_VICIN_FSETS(FIELD,SYM)\
    _PER_FSETS(_VIC_VICIN_ADDR,VIC,VICIN,##FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  V I C D I V      |
* |___________________|
*
* VICIN - VIC Clock Divider Register
*
* FIELDS (msb -> lsb)
* (rw)  VICCLKDIV
*
\******************************************************************************/

  #define _VIC_VICDIV_OFFSET             2
  #define _VIC_VICDIV_ADDR               (_VIC_BASE_ADDR + 4*_VIC_VICDIV_OFFSET)

  #define _VIC_VICDIV_VICCLKDIV_MASK         0x0000FFFFu
  #define _VIC_VICDIV_VICCLKDIV_SHIFT        0x00000000u
  #define  VIC_VICDIV_VICCLKDIV_DEFAULT      0x00000001u
  #define  VIC_VICDIV_VICCLKDIV_OF(x)        _VALUEOF(x)

  #define VIC_VICDIV_DEFAULT (Uint32)( \
     _PER_FDEFAULT(VIC,VICDIV,VICCLKDIV) \
  )

  #define VIC_VICDIV_RMK(vicclkdiv) (Uint32)( \
     _PER_FMK(VIC,VICDIV,VICCLKDIV,vicclkdiv) \
   )

  #define _VIC_VICDIV_FGET(FIELD)\
    _PER_FGET(_VIC_VICDIV_ADDR,VIC,VICDIV,##FIELD)

  #define _VIC_VICDIV_FSET(FIELD,field)\
    _PER_FSET(_VIC_VICDIV_ADDR,VIC,VICDIV,##FIELD,field)

  #define _VIC_VICDIV_FSETS(FIELD,SYM)\
    _PER_FSETS(_VIC_VICDIV_ADDR,VIC,VICDIV,##FIELD,##SYM)

/*----------------------------------------------------------------------------*/

#endif /* VIC_SUPPORT */
#endif /* _CSL_VICHAL_H_ */
/******************************************************************************\
* End of csl_vichal.h
\******************************************************************************/

