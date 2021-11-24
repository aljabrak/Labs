/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_utophal.h
* DATE CREATED.. 07/19/2000 
* LAST MODIFIED. 09/21/2001 
*------------------------------------------------------------------------------
* REGISTERS
*
* UCR   - Utopia Control Register
* UIER  - Utopia Interrupt Enable Register
* UIPR  - Utopia Interrupt Pending Register
* CDR   - Clock Detect Register
* EIER  - Error Interrupt Enable Register
* EIPR  - Error Interrupt Pending Register
*
\******************************************************************************/
#ifndef _CSL_UTOPHAL_H_
#define _CSL_UTOPHAL_H_

#include <csl_stdinc.h>
#include <csl_chip.h>

#if (UTOP_SUPPORT)
/******************************************************************************\
* MISC section
\******************************************************************************/
  #define _UTOP_BASE_GLOBAL      0x01B40000u
  #define _UTOP_BASE_RQUEUE      0x3C000000u
  #define _UTOP_BASE_XQUEUE      0x3D000000u

/******************************************************************************\
* module level register/field access macros
\******************************************************************************/

  /* ----------------- */
  /* FIELD MAKE MACROS */
  /* ----------------- */

  #define UTOP_FMK(REG,FIELD,x)\
    _PER_FMK(UTOP,##REG,##FIELD,x)

  #define UTOP_FMKS(REG,FIELD,SYM)\
    _PER_FMKS(UTOP,##REG,##FIELD,##SYM)


  /* -------------------------------- */
  /* RAW REGISTER/FIELD ACCESS MACROS */
  /* -------------------------------- */

  #define UTOP_ADDR(REG)\
    _UTOP_##REG##_ADDR

  #define UTOP_RGET(REG)\
    _PER_RGET(_UTOP_##REG##_ADDR,UTOP,##REG)

  #define UTOP_RSET(REG,x)\
    _PER_RSET(_UTOP_##REG##_ADDR,UTOP,##REG,x)

  #define UTOP_FGET(REG,FIELD)\
    _UTOP_##REG##_FGET(##FIELD)

  #define UTOP_FSET(REG,FIELD,x)\
    _UTOP_##REG##_FSET(##FIELD,##x)

  #define UTOP_FSETS(REG,FIELD,SYM)\
    _UTOP_##REG##_FSETS(##FIELD,##SYM)


  /* ------------------------------------------ */
  /* ADDRESS BASED REGISTER/FIELD ACCESS MACROS */
  /* ------------------------------------------ */

  #define UTOP_RGETA(addr,REG)\
    _PER_RGET(addr,UTOP,##REG)

  #define UTOP_RSETA(addr,REG,x)\
    _PER_RSET(addr,UTOP,##REG,x)

  #define UTOP_FGETA(addr,REG,FIELD)\
    _PER_FGET(addr,UTOP,##REG,##FIELD)

  #define UTOP_FSETA(addr,REG,FIELD,x)\
    _PER_FSET(addr,UTOP,##REG,##FIELD,x)

  #define UTOP_FSETSA(addr,REG,FIELD,SYM)\
    _PER_FSETS(addr,UTOP,##REG,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  U C R            |
* |___________________|
*
* UCR   - Utopia Control Register
*
* Fields (msb --> lsb):
* (rw) BEND
* (rw) SLIDSLEND
* (rw) XUDC
* (rw) UXEN
* (rw) MPHY
* (rw) RUDC
* (rw) UREN

\******************************************************************************/
  #define _UTOP_UCR_OFFSET            0

  #define _UTOP_UCR_ADDR              0x01B40000u

  #define _UTOP_UCR_BEND_MASK         0x80000000u
  #define _UTOP_UCR_BEND_SHIFT        0x0000001Fu
  #define  UTOP_UCR_BEND_DEFAULT      0x00000000u
  #define  UTOP_UCR_BEND_OF(x)        _VALUEOF(x)
  #define  UTOP_UCR_BEND_LITTLE       0x00000000u
  #define  UTOP_UCR_BEND_BIG          0x00000001u

  #define _UTOP_UCR_SLID_MASK    0x1F000000u
  #define _UTOP_UCR_SLID_SHIFT   0x00000018u
  #define  UTOP_UCR_SLID_DEFAULT 0x00000000u
  #define  UTOP_UCR_SLID_OF(x)   _VALUEOF(x)
  #define  UTOP_UCR_SLID_NULL    0x0000001Fu

  #define _UTOP_UCR_XUDC_MASK         0x003C0000u
  #define _UTOP_UCR_XUDC_SHIFT        0x00000012u
  #define  UTOP_UCR_XUDC_DEFAULT      0x00000000u
  #define  UTOP_UCR_XUDC_OF(x)        _VALUEOF(x)

  #define _UTOP_UCR_UXEN_MASK         0x00010000u
  #define _UTOP_UCR_UXEN_SHIFT        0x00000010u
  #define  UTOP_UCR_UXEN_DEFAULT      0x00000000u
  #define  UTOP_UCR_UXEN_OF(x)        _VALUEOF(x)
  #define  UTOP_UCR_UXEN_DISABLE      0x00000000u
  #define  UTOP_UCR_UXEN_ENABLE       0x00000001u

  #define _UTOP_UCR_MPHY_MASK         0x00004000u
  #define _UTOP_UCR_MPHY_SHIFT        0x0000000Eu
  #define  UTOP_UCR_MPHY_DEFAULT      0x00000000u
  #define  UTOP_UCR_MPHY_OF(x)        _VALUEOF(x)
  #define  UTOP_UCR_MPHY_SINGLE       0x00000000u
  #define  UTOP_UCR_MPHY_MULTI        0x00000001u
 
  #define _UTOP_UCR_RUDC_MASK         0x0000003Cu
  #define _UTOP_UCR_RUDC_SHIFT        0x00000002u
  #define  UTOP_UCR_RUDC_DEFAULT      0x00000000u
  #define  UTOP_UCR_RUDC_OF(x)        _VALUEOF(x)

  #define _UTOP_UCR_UREN_MASK         0x00000001u
  #define _UTOP_UCR_UREN_SHIFT        0x00000000u
  #define  UTOP_UCR_UREN_DEFAULT      0x00000000u
  #define  UTOP_UCR_UREN_OF(x)        _VALUEOF(x)
  #define  UTOP_UCR_UREN_ENABLE       0x00000001u
  #define  UTOP_UCR_UREN_DISABLE      0x00000000u

  #define  UTOP_UCR_OF(x)             _VALUEOF(x)

  #define UTOP_UCR_DEFAULT (Uint32)(\
     _PER_FDEFAULT(UTOP,UCR,BEND)\
    |_PER_FDEFAULT(UTOP,UCR,SLID)\
    |_PER_FDEFAULT(UTOP,UCR,XUDC)\
    |_PER_FDEFAULT(UTOP,UCR,UXEN)\
    |_PER_FDEFAULT(UTOP,UCR,MPHY)\
    |_PER_FDEFAULT(UTOP,UCR,RUDC)\
    |_PER_FDEFAULT(UTOP,UCR,UREN)\
  )

  #define UTOP_UCR_RMK(bend,slid,xudc,uxen,\
    mphy,rudc,uren) (Uint32)(\
     _PER_FMK(UTOP,UCR,BEND,bend)\
    |_PER_FMK(UTOP,UCR,SLID,slid)\
    |_PER_FMK(UTOP,UCR,XUDC,xudc)\
    |_PER_FMK(UTOP,UCR,UXEN,uxen)\
    |_PER_FMK(UTOP,UCR,MPHY,mphy)\
    |_PER_FMK(UTOP,UCR,RUDC,rudc)\
    |_PER_FMK(UTOP,UCR,UREN,uren)\
  )

  #define _UTOP_UCR_FGET(FIELD)\
    _PER_FGET(_UTOP_UCR_ADDR,UTOP,UCR,##FIELD)

  #define _UTOP_UCR_FSET(FIELD,field)\
    _PER_FSET(_UTOP_UCR_ADDR,UTOP,UCR,##FIELD,field)

  #define _UTOP_UCR_FSETS(FIELD,SYM)\
    _PER_FSETS(_UTOP_UCR_ADDR,UTOP,UCR,##FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  U I E R          |
* |___________________|
*
* UIER  - Utopia Interrupt Enable Register
*
* Fields (msb --> lsb):
* (rw) RQIE
* (rw) XQIE
*
\******************************************************************************/
  #define _UTOP_UIER_OFFSET           3

  #define _UTOP_UIER_ADDR             0x01B4000Cu
  
  #define _UTOP_UIER_RQIE_MASK        0x00010000u
  #define _UTOP_UIER_RQIE_SHIFT       0x00000010u
  #define  UTOP_UIER_RQIE_DEFAULT     0x00000000u
  #define  UTOP_UIER_RQIE_OF(x)       _VALUEOF(x)

  #define _UTOP_UIER_XQIE_MASK        0x00000001u
  #define _UTOP_UIER_XQIE_SHIFT       0x00000000u
  #define  UTOP_UIER_XQIE_DEFAULT     0x00000000u
  #define  UTOP_UIER_XQIE_OF(x)       _VALUEOF(x)

  #define  UTOP_UIER_OF(x)            _VALUEOF(x)

  #define UTOP_UIER_DEFAULT (Uint32)(\
     _PER_FDEFAULT(UTOP,UIER,RQIE)\
    |_PER_FDEFAULT(UTOP,UIER,XQIE)\
  )

  #define UTOP_UIER_RMK(rqie,xqie) (Uint32)(\
     _PER_FMK(UTOP,UIER,RQIE,rqie)\
    |_PER_FMK(UTOP,UIER,XQIE,xqie)\
  )

  #define _UTOP_UIER_FGET(FIELD)\
    _PER_FGET(_UTOP_UIER_ADDR,UTOP,UIER,##FIELD)

  #define _UTOP_UIER_FSET(FIELD,field)\
    _PER_FSET(_UTOP_UIER_ADDR,UTOP,UIER,##FIELD,field)

  #define _UTOP_UIER_FSETS(FIELD,SYM)\
    _PER_FSETS(_UTOP_UIER_ADDR,UTOP,UIER,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  U I P R          |
* |___________________|
*
* UIPR  - Utopia Interrupt Pending Register
*
* Fields (msb --> lsb):
* (rw) RQIP
* (rw) XQIP
*
\******************************************************************************/
  #define _UTOP_UIPR_OFFSET           4

  #define _UTOP_UIPR_ADDR             0x01B40010u

  #define _UTOP_UIPR_RQIP_MASK        0x00010000u
  #define _UTOP_UIPR_RQIP_SHIFT       0x00000010u
  #define  UTOP_UIPR_RQIP_DEFAULT     0x00000000u
  #define  UTOP_UIPR_RQIP_OF(x)       _VALUEOF(x)
  #define  UTOP_UIPR_RQIP_CLEAR       0x00000001u
 
  #define _UTOP_UIPR_XQIP_MASK        0x00000001u
  #define _UTOP_UIPR_XQIP_SHIFT       0x00000000u
  #define  UTOP_UIPR_XQIP_DEFAULT     0x00000000u
  #define  UTOP_UIPR_XQIP_OF(x)       _VALUEOF(x)
  #define  UTOP_UIPR_XQIP_CLEAR       0x00000001u

  #define  UTOP_UIPR_OF(x)            _VALUEOF(x)

  #define UTOP_UIPR_DEFAULT (Uint32)(\
     _PER_FDEFAULT(UTOP,UIPR,RQIP)\
    |_PER_FDEFAULT(UTOP,UIPR,XQIP)\
  )

  #define UTOP_UIPR_RMK(rqip,xqip) (Uint32)(\
     _PER_FMK(UTOP,UIPR,RQIP,rqip)\
    |_PER_FMK(UTOP,UIPR,XQIP,xqip)\
  )

  #define _UTOP_UIPR_FGET(FIELD)\
    _PER_FGET(_UTOP_UIPR_ADDR,UTOP,UIPR,##FIELD)

  #define _UTOP_UIPR_FSET(FIELD,field)\
    _PER_FSET(_UTOP_UIPR_ADDR,UTOP,UIPR,##FIELD,field)

  #define _UTOP_UIPR_FSETS(FIELD,SYM)\
    _PER_FSETS(_UTOP_UIPR_ADDR,UTOP,UIPR,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  C D R            |
* |___________________|
*
* CDR   - Clock Detect Register
*
* Fields (msb --> lsb):
* (rw) XCCNT
* (rw) RCCNT
*
\******************************************************************************/
  #define _UTOP_CDR_OFFSET            5

  #define _UTOP_CDR_ADDR              0x01B40014u

  #define _UTOP_CDR_XCCNT_MASK        0x00FF0000u
  #define _UTOP_CDR_XCCNT_SHIFT       0x00000010u
  #define  UTOP_CDR_XCCNT_DEFAULT     0x000000FFu
  #define  UTOP_CDR_XCCNT_OF(x)       _VALUEOF(x)

  #define _UTOP_CDR_RCCNT_MASK        0x000000FFu
  #define _UTOP_CDR_RCCNT_SHIFT       0x00000000u
  #define  UTOP_CDR_RCCNT_DEFAULT     0x000000FFu
  #define  UTOP_CDR_RCCNT_OF(x)       _VALUEOF(x)

  #define  UTOP_CDR_OF(x)             _VALUEOF(x)

  #define UTOP_CDR_DEFAULT (Uint32)(\
     _PER_FDEFAULT(UTOP,CDR,XCCNT)\
    |_PER_FDEFAULT(UTOP,CDR,RCCNT)\
  )

  #define UTOP_CDR_RMK(xccnt,rccnt) (Uint32)(\
     _PER_FMK(UTOP,CDR,XCCNT,xccnt)\
    |_PER_FMK(UTOP,CDR,RCCNT,rccnt)\
  )

  #define _UTOP_CDR_FGET(FIELD)\
    _PER_FGET(_UTOP_CDR_ADDR,UTOP,CDR,##FIELD)

  #define _UTOP_CDR_FSET(FIELD,field)\
    _PER_FSET(_UTOP_CDR_ADDR,UTOP,CDR,##FIELD,field)

  #define _UTOP_CDR_FSETS(FIELD,SYM)\
    _PER_FSETS(_UTOP_CDR_ADDR,UTOP,CDR,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  E I E R          |
* |___________________|
*
* EIER  - Error Interrupt Enable Register
*
* Fields (msb --> lsb):
* (rw) XCPE
* (rw) XCFE
* (rw) XQSE
* (rw) RCPE
* (rw) RCFE
* (rw) RQSE
*
\******************************************************************************/
  #define _UTOP_EIER_OFFSET           6

  #define _UTOP_EIER_ADDR             0x01B40018u
  
  #define _UTOP_EIER_XCPE_MASK        0x00040000u
  #define _UTOP_EIER_XCPE_SHIFT       0x00000012u
  #define  UTOP_EIER_XCPE_DEFAULT     0x00000000u
  #define  UTOP_EIER_XCPE_OF(x)       _VALUEOF(x)
  #define  UTOP_EIER_XCPE_DISABLE     0x00000000u
  #define  UTOP_EIER_XCPE_ENABLE      0x00000001u

  #define _UTOP_EIER_XCFE_MASK        0x00020000u
  #define _UTOP_EIER_XCFE_SHIFT       0x00000011u
  #define  UTOP_EIER_XCFE_DEFAULT     0x00000000u
  #define  UTOP_EIER_XCFE_OF(x)       _VALUEOF(x)
  #define  UTOP_EIER_XCFE_DISABLE     0x00000000u
  #define  UTOP_EIER_XCFE_ENABLE      0x00000001u

  #define _UTOP_EIER_XQSE_MASK        0x00010000u
  #define _UTOP_EIER_XQSE_SHIFT       0x00000010u
  #define  UTOP_EIER_XQSE_DEFAULT     0x00000000u
  #define  UTOP_EIER_XQSE_OF(x)       _VALUEOF(x)
  #define  UTOP_EIER_XQSE_DISABLE     0x00000000u
  #define  UTOP_EIER_XQSE_ENABLE      0x00000001u

  #define _UTOP_EIER_RCPE_MASK        0x00000004u
  #define _UTOP_EIER_RCPE_SHIFT       0x00000002u
  #define  UTOP_EIER_RCPE_DEFAULT     0x00000000u
  #define  UTOP_EIER_RCPE_OF(x)       _VALUEOF(x)
  #define  UTOP_EIER_RCPE_DISABLE     0x00000000u
  #define  UTOP_EIER_RCPE_ENABLE      0x00000001u

  #define _UTOP_EIER_RCFE_MASK        0x00000002u
  #define _UTOP_EIER_RCFE_SHIFT       0x00000001u
  #define  UTOP_EIER_RCFE_DEFAULT     0x00000000u
  #define  UTOP_EIER_RCFE_OF(x)       _VALUEOF(x)
  #define  UTOP_EIER_RCFE_DISABLE     0x00000000u
  #define  UTOP_EIER_RCFE_ENABLE      0x00000001u

  #define _UTOP_EIER_RQSE_MASK        0x00000001u
  #define _UTOP_EIER_RQSE_SHIFT       0x00000000u
  #define  UTOP_EIER_RQSE_DEFAULT     0x00000000u
  #define  UTOP_EIER_RQSE_OF(x)       _VALUEOF(x)
  #define  UTOP_EIER_RQSE_DISABLE     0x00000000u
  #define  UTOP_EIER_RQSE_ENABLE      0x00000001u

  #define  UTOP_EIER_OF(x)            _VALUEOF(x)

  #define UTOP_EIER_DEFAULT (Uint32)(\
     _PER_FDEFAULT(UTOP,EIER,XCPE)\
    |_PER_FDEFAULT(UTOP,EIER,XCFE)\
    |_PER_FDEFAULT(UTOP,EIER,XQSE)\
    |_PER_FDEFAULT(UTOP,EIER,RCPE)\
    |_PER_FDEFAULT(UTOP,EIER,RCFE)\
    |_PER_FDEFAULT(UTOP,EIER,RQSE)\
  )

  #define UTOP_EIER_RMK(xcpe,xcfe,xqse,rcpe,rcfe,rqse) (Uint32)(\
     _PER_FMK(UTOP,EIER,XCPE,xcpe)\
    |_PER_FMK(UTOP,EIER,XCFE,xcfe)\
	|_PER_FMK(UTOP,EIER,XQSE,xqse)\
    |_PER_FMK(UTOP,EIER,RCPE,rcpe)\
    |_PER_FMK(UTOP,EIER,RCFE,rcfe)\
	|_PER_FMK(UTOP,EIER,RQSE,rqse)\
  )

  #define _UTOP_EIER_FGET(FIELD)\
    _PER_FGET(_UTOP_EIER_ADDR,UTOP,EIER,##FIELD)

  #define _UTOP_EIER_FSET(FIELD,field)\
    _PER_FSET(_UTOP_EIER_ADDR,UTOP,EIER,##FIELD,field)

  #define _UTOP_EIER_FSETS(FIELD,SYM)\
    _PER_FSETS(_UTOP_EIER_ADDR,UTOP,EIER,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  E I P R          |
* |___________________|
*
* EIPR  - Error Interrupt Enable Register
*
* Fields (msb --> lsb):
* (rw) XCPP
* (rw) XCFP
* (r)  XQSP
* (rw) RCPP
* (rw) RCFP
* (r)  RQSP
*
\******************************************************************************/
  #define _UTOP_EIPR_OFFSET           7

  #define _UTOP_EIPR_ADDR             0x01B4001Cu
  
  #define _UTOP_EIPR_XCPP_MASK        0x00040000u
  #define _UTOP_EIPR_XCPP_SHIFT       0x00000012u
  #define  UTOP_EIPR_XCPP_DEFAULT     0x00000000u
  #define  UTOP_EIPR_XCPP_OF(x)       _VALUEOF(x)
  #define  UTOP_EIPR_XCPP_CLEAR       0x00000001u

  #define _UTOP_EIPR_XCFP_MASK        0x00020000u
  #define _UTOP_EIPR_XCFP_SHIFT       0x00000011u
  #define  UTOP_EIPR_XCFP_DEFAULT     0x00000000u
  #define  UTOP_EIPR_XCFP_OF(x)       _VALUEOF(x)
  #define  UTOP_EIPR_XCFP_CLEAR       0x00000001u

  #define _UTOP_EIPR_XQSP_MASK        0x00010000u
  #define _UTOP_EIPR_XQSP_SHIFT       0x00000010u
  #define  UTOP_EIPR_XQSP_DEFAULT     0x00000000u
  #define  UTOP_EIPR_XQSP_OF(x)       _VALUEOF(x)

  #define _UTOP_EIPR_RCPP_MASK        0x00000004u
  #define _UTOP_EIPR_RCPP_SHIFT       0x00000002u
  #define  UTOP_EIPR_RCPP_DEFAULT     0x00000000u
  #define  UTOP_EIPR_RCPP_OF(x)       _VALUEOF(x)
  #define  UTOP_EIPR_RCPP_CLEAR       0x00000001u

  #define _UTOP_EIPR_RCFP_MASK        0x00000002u
  #define _UTOP_EIPR_RCFP_SHIFT       0x00000001u
  #define  UTOP_EIPR_RCFP_DEFAULT     0x00000000u
  #define  UTOP_EIPR_RCFP_OF(x)       _VALUEOF(x)
  #define  UTOP_EIPR_RCFP_CLEAR       0x00000001u

  #define _UTOP_EIPR_RQSP_MASK        0x00000001u
  #define _UTOP_EIPR_RQSP_SHIFT       0x00000000u
  #define  UTOP_EIPR_RQSP_DEFAULT     0x00000000u
  #define  UTOP_EIPR_RQSP_OF(x)       _VALUEOF(x)

  #define  UTOP_EIPR_OF(x)            _VALUEOF(x)

  #define UTOP_EIPR_DEFAULT (Uint32)(\
     _PER_FDEFAULT(UTOP,EIPR,XCPP)\
    |_PER_FDEFAULT(UTOP,EIPR,XCFP)\
    |_PER_FDEFAULT(UTOP,EIPR,XQSP)\
    |_PER_FDEFAULT(UTOP,EIPR,RCPP)\
    |_PER_FDEFAULT(UTOP,EIPR,RCFP)\
    |_PER_FDEFAULT(UTOP,EIPR,RQSP)\
  )

  #define UTOP_EIPR_RMK(xcpp,xcfp,rcpp,rcfp) (Uint32)(\
     _PER_FMK(UTOP,EIPR,XCPP,xcpp)\
    |_PER_FMK(UTOP,EIPR,XCFP,xcfp)\
    |_PER_FMK(UTOP,EIPR,RCPP,rcpp)\
    |_PER_FMK(UTOP,EIPR,RCFP,rcfp)\
  )

  #define _UTOP_EIPR_FGET(FIELD)\
    _PER_FGET(_UTOP_EIPR_ADDR,UTOP,EIPR,##FIELD)

  #define _UTOP_EIPR_FSET(FIELD,field)\
    _PER_FSET(_UTOP_EIPR_ADDR,UTOP,EIPR,##FIELD,field)

  #define _UTOP_EIPR_FSETS(FIELD,SYM)\
    _PER_FSETS(_UTOP_EIPR_ADDR,UTOP,EIPR,##FIELD,##SYM)


/*----------------------------------------------------------------------------*/

#endif /* UTOP_SUPPORT */
#endif /* _CSL_UTOPHAL_H_ */
/******************************************************************************\
* End of csl_utophal.h
\******************************************************************************/

