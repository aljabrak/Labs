/******************************************************************************\
*           Copyright (C) 1999-2001 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_hpihal.h
* DATE CREATED.. 06/20/1999
* LAST MODIFIED. 04/20/2001 (C64x compatibility)
*				 06/09/2003 TRCTL bug
*                04/16/2004  Fixed TRCTL bad adress
*				 12/09/2005 Changed the HPIAW/HPIAR shift macro from 0x00000002
*						    to 0x00000000 to make it byte addressable. 
*------------------------------------------------------------------------------
* REGISTERS
*
* HPIC - HPI control register
* HPIAW - HPI Address Write register (1)
* HPIAR - HPI Address Read registrer (1)
* TRCTL - TR Control register (1)
*
* (1) supported by C64x devices only
\******************************************************************************/
#ifndef _CSL_HPIHAL_H_
#define _CSL_HPIHAL_H_

#include <csl_chip.h>

#if (HPI_SUPPORT)
/******************************************************************************\
* MISC section
\******************************************************************************/
#define _HPI_BASE_ADDR         0x01880000u


/******************************************************************************\
* module level register/field access macros
\******************************************************************************/

  /* ----------------- */
  /* FIELD MAKE MACROS */
  /* ----------------- */

  #define HPI_FMK(REG,FIELD,x)\
    _PER_FMK(HPI,##REG,##FIELD,x)

  #define HPI_FMKS(REG,FIELD,SYM)\
    _PER_FMKS(HPI,##REG,##FIELD,##SYM)


  /* -------------------------------- */
  /* RAW REGISTER/FIELD ACCESS MACROS */
  /* -------------------------------- */

  #define HPI_ADDR(REG)\
    _HPI_##REG##_ADDR

  #define HPI_RGET(REG)\
    _PER_RGET(_HPI_##REG##_ADDR,HPI,##REG)

  #define HPI_RSET(REG,x)\
    _PER_RSET(_HPI_##REG##_ADDR,HPI,##REG,x)

  #define HPI_FGET(REG,FIELD)\
    _HPI_##REG##_FGET(##FIELD)

  #define HPI_FSET(REG,FIELD,x)\
    _HPI_##REG##_FSET(##FIELD,##x)

  #define HPI_FSETS(REG,FIELD,SYM)\
    _HPI_##REG##_FSETS(##FIELD,##SYM)


  /* ------------------------------------------ */
  /* ADDRESS BASED REGISTER/FIELD ACCESS MACROS */
  /* ------------------------------------------ */

  #define HPI_RGETA(addr,REG)\
    _PER_RGET(addr,HPI,##REG)

  #define HPI_RSETA(addr,REG,x)\
    _PER_RSET(addr,HPI,##REG,x)

  #define HPI_FGETA(addr,REG,FIELD)\
    _PER_FGET(addr,HPI,##REG,##FIELD)

  #define HPI_FSETA(addr,REG,FIELD,x)\
    _PER_FSET(addr,HPI,##REG,##FIELD,x)

  #define HPI_FSETSA(addr,REG,FIELD,SYM)\
    _PER_FSETS(addr,HPI,##REG,##FIELD,##SYM)



/******************************************************************************\
* _____________________
* |                   |
* |  H P I C          |
* |___________________|
*
* HPI - HPI control register
*
* FIELDS (msb -> lsb)
* (r)  FETCH
* (r)  HRDY
* (rw) HINT
* (rw) DSPINT
* (r)  HWOB
*
\******************************************************************************/
  #define _HPI_HPIC_OFFSET             0
  #define _HPI_HPIC_ADDR               0x01880000u

  #define _HPI_HPIC_FETCH_MASK         0x00000010u
  #define _HPI_HPIC_FETCH_SHIFT        0x00000004u
  #define  HPI_HPIC_FETCH_DEFAULT      0x00000000u
  #define  HPI_HPIC_FETCH_OF(x)        _VALUEOF(x)
  #define  HPI_HPIC_FETCH_0            0x00000000u
  #define  HPI_HPIC_FETCH_1            0x00000001u

  #define _HPI_HPIC_HRDY_MASK          0x00000008u
  #define _HPI_HPIC_HRDY_SHIFT         0x00000003u
  #define  HPI_HPIC_HRDY_DEFAULT       0x00000001u
  #define  HPI_HPIC_HRDY_OF(x)         _VALUEOF(x)
  #define  HPI_HPIC_HRDY_0             0x00000000u
  #define  HPI_HPIC_HRDY_1             0x00000001u

  #define _HPI_HPIC_HINT_MASK          0x00000004u
  #define _HPI_HPIC_HINT_SHIFT         0x00000002u
  #define  HPI_HPIC_HINT_DEFAULT       0x00000000u
  #define  HPI_HPIC_HINT_OF(x)         _VALUEOF(x)
  #define  HPI_HPIC_HINT_0             0x00000000u
  #define  HPI_HPIC_HINT_1             0x00000001u

  #define _HPI_HPIC_DSPINT_MASK        0x00000002u
  #define _HPI_HPIC_DSPINT_SHIFT       0x00000001u
  #define  HPI_HPIC_DSPINT_DEFAULT     0x00000000u
  #define  HPI_HPIC_DSPINT_OF(x)       _VALUEOF(x)
  #define  HPI_HPIC_DSPINT_0           0x00000000u
  #define  HPI_HPIC_DSPINT_1           0x00000001u

  #define _HPI_HPIC_HWOB_MASK          0x00000001u
  #define _HPI_HPIC_HWOB_SHIFT         0x00000000u
  #define  HPI_HPIC_HWOB_DEFAULT       0x00000000u
  #define  HPI_HPIC_HWOB_OF(x)         _VALUEOF(x)
  #define  HPI_HPIC_HWOB_0             0x00000000u
  #define  HPI_HPIC_HWOB_1             0x00000001u

  #define  HPI_HPIC_OF(x)              _VALUEOF(x)

  #define HPI_HPIC_DEFAULT (Uint32)( \
     _PER_FDEFAULT(HPI,HPIC,FETCH) \
    |_PER_FDEFAULT(HPI,HPIC,HRDY) \
    |_PER_FDEFAULT(HPI,HPIC,HINT) \
    |_PER_FDEFAULT(HPI,HPIC,DSPINT) \
    |_PER_FDEFAULT(HPI,HPIC,HWOB) \
  )

  #define HPI_HPIC_RMK(hint,dspint) (Uint32)( \
     _PER_FMK(HPI,HPIC,HINT,hint) \
    |_PER_FMK(HPI,HPIC,DSPINT,dspint) \
   )

  #define _HPI_HPIC_FGET(FIELD)\
    _PER_FGET(_HPI_HPIC_ADDR,HPI,HPIC,##FIELD)

  #define _HPI_HPIC_FSET(FIELD,field)\
    _PER_FSET(_HPI_HPIC_ADDR,HPI,HPIC,##FIELD,field)

  #define _HPI_HPIC_FSETS(FIELD,SYM)\
    _PER_FSETS(_HPI_HPIC_ADDR,HPI,HPIC,##FIELD,##SYM)
/******************************************************************************\
* _____________________
* |                   |
* |  H P I A W        |
* |___________________|
*
* HPIAW - HPI Address Write register
*
* FIELDS (msb -> lsb)
* (rw)  HPIAW
*
\******************************************************************************/
 #if (C64_SUPPORT)
  #define _HPI_HPIAW_OFFSET             1
  #define _HPI_HPIAW_ADDR               0x01880004u

  #define _HPI_HPIAW_HPIAW_MASK         0xFFFFFFFCu
  #define _HPI_HPIAW_HPIAW_SHIFT        0x00000000u
  #define  HPI_HPIAW_HPIAW_DEFAULT      0x00000000u
  #define  HPI_HPIAW_HPIAW_OF(x)        _VALUEOF(x)

  #define HPI_HPIAW_DEFAULT (Uint32)( \
     _PER_FDEFAULT(HPI,HPIAW,HPIAW) \
  )

  #define HPI_HPIAW_RMK(hpiaw) (Uint32)( \
     _PER_FMK(HPI,HPIAW,HPIAW,hpiaw) \
   )

  #define _HPI_HPIAW_FGET(FIELD)\
    _PER_FGET(_HPI_HPIAW_ADDR,HPI,HPIAW,##FIELD)

  #define _HPI_HPIAW_FSET(FIELD,field)\
    _PER_FSET(_HPI_HPIAW_ADDR,HPI,HPIAW,##FIELD,field)

  #define _HPI_HPIAW_FSETS(FIELD,SYM)\
    _PER_FSETS(_HPI_HPIAW_ADDR,HPI,HPIAW,##FIELD,##SYM)

#endif /* C64_SUPPORT */
/******************************************************************************\
* _____________________
* |                   |
* |  H P I A R        |
* |___________________|
*
* HPIAR - HPI Address Read register
*
* FIELDS (msb -> lsb)
* (rw)  HPIAR
*
\******************************************************************************/
 #if (C64_SUPPORT)
  #define _HPI_HPIAR_OFFSET             2
  #define _HPI_HPIAR_ADDR               0x01880008u

  #define _HPI_HPIAR_HPIAR_MASK         0xFFFFFFFCu
  #define _HPI_HPIAR_HPIAR_SHIFT        0x00000000u
  #define  HPI_HPIAR_HPIAR_DEFAULT      0x00000000u
  #define  HPI_HPIAR_HPIAR_OF(x)        _VALUEOF(x)

  #define HPI_HPIAR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(HPI,HPIAR,HPIAR) \
  )

  #define HPI_HPIAR_RMK(hpiar) (Uint32)( \
     _PER_FMK(HPI,HPIAR,HPIAR,hpiar) \
   )

  #define _HPI_HPIAR_FGET(FIELD)\
    _PER_FGET(_HPI_HPIAR_ADDR,HPI,HPIAR,##FIELD)

  #define _HPI_HPIAR_FSET(FIELD,field)\
    _PER_FSET(_HPI_HPIAR_ADDR,HPI,HPIAR,##FIELD,field)

  #define _HPI_HPIAR_FSETS(FIELD,SYM)\
    _PER_FSETS(_HPI_HPIAR_ADDR,HPI,HPIAR,##FIELD,##SYM)

#endif /* C64_SUPPORT */

/******************************************************************************\
* _____________________
* |                   |
* |  T R C T L        |
* |___________________|
*
* TRCTL - TR Control register
*
* FIELDS (msb -> lsb)
* (rw)  TRSTALL
* (rw)  PRI
* (rw)  PALLOC
*
\******************************************************************************/
 #if (C64_SUPPORT)
  #define _HPI_TRCTL_OFFSET             16384
  #define _HPI_TRCTL_ADDR               0x018A0000u

  #define _HPI_TRCTL_TRSTALL_MASK         0x00000100u
  #define _HPI_TRCTL_TRSTALL_SHIFT        0x00000008u
  #define  HPI_TRCTL_TRSTALL_DEFAULT      0x00000000u
  #define  HPI_TRCTL_TRSTALL_OF(x)        _VALUEOF(x)

  #define _HPI_TRCTL_PRI_MASK         0x00000030u
  #define _HPI_TRCTL_PRI_SHIFT        0x00000004u
  #define  HPI_TRCTL_PRI_DEFAULT      0x00000002u
  #define  HPI_TRCTL_PRI_OF(x)        _VALUEOF(x)

  #define _HPI_TRCTL_PALLOC_MASK         0x0000000Fu
  #define _HPI_TRCTL_PALLOC_SHIFT        0x00000000u
  #define  HPI_TRCTL_PALLOC_DEFAULT      0x00000004u
  #define  HPI_TRCTL_PALLOC_OF(x)        _VALUEOF(x)

  #define HPI_TRCTL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(HPI,TRCTL,TRSTALL) \
    |_PER_FDEFAULT(HPI,TRCTL,PRI) \
    |_PER_FDEFAULT(HPI,TRCTL,PALLOC) \
  )

  #define HPI_TRCTL_RMK(trstall,pri,palloc) (Uint32)( \
     _PER_FMK(HPI,TRCTL,TRSTALL,trstall) \
    |_PER_FMK(HPI,TRCTL,PRI,pri) \
    |_PER_FMK(HPI,TRCTL,PALLOC,palloc) \
   )

  #define _HPI_TRCTL_FGET(FIELD)\
    _PER_FGET(_HPI_TRCTL_ADDR,HPI,TRCTL,##FIELD)

  #define _HPI_TRCTL_FSET(FIELD,field)\
    _PER_FSET(_HPI_TRCTL_ADDR,HPI,TRCTL,##FIELD,field)

  #define _HPI_TRCTL_FSETS(FIELD,SYM)\
    _PER_FSETS(_HPI_TRCTL_ADDR,HPI,TRCTL,##FIELD,##SYM)

#endif /* C64_SUPPORT */



/*----------------------------------------------------------------------------*/

#endif /* HPI_SUPPORT */
#endif /* _CSL_HPIHAL_H_ */
/******************************************************************************\
* End of csl_hpihal.h
\******************************************************************************/

