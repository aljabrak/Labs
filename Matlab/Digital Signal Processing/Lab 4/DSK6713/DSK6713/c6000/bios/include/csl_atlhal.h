/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_atlhal.h
* DATE CREATED.. 07/01/2003 
* .............. 07/02/2003    first draft completed
* LAST MODIFIED.
*               
*------------------------------------------------------------------------------
* REGISTERS
*
* ATLPPMR    - ATL Parts Per Million Register 
* ATLSCNTR   - ATL Sample Count Register
* ATLCR      - ATL Control Register
*
\******************************************************************************/
#ifndef _CSL_ATLHAL_H_
#define _CSL_ATLHAL_H_

#include <csl_stdinc.h>
#include <csl_chip.h>
#if (ATL_SUPPORT)
/******************************************************************************\
* MISC section
\******************************************************************************/
  #define _ATL_BASE_PORT       0x01B7F000u
 

/******************************************************************************\
* module level register/field access macros
\******************************************************************************/

  /* ----------------- */
  /* FIELD MAKE MACROS */
  /* ----------------- */

  #define ATL_FMK(REG,FIELD,x)\
    _PER_FMK(ATL,##REG,##FIELD,x)

  #define ATL_FMKS(REG,FIELD,SYM)\
    _PER_FMKS(ATL,##REG,##FIELD,##SYM)


  /* -------------------------------- */
  /* RAW REGISTER/FIELD ACCESS MACROS */
  /* -------------------------------- */

  #define ATL_ADDR(REG)\
    _ATL_##REG##_ADDR

  #define ATL_RGET(REG)\
    _PER_RGET(_ATL_##REG##_ADDR,ATL,##REG)

  #define ATL_RSET(REG,x)\
    _PER_RSET(_ATL_##REG##_ADDR,ATL,##REG,x)

  #define ATL_FGET(REG,FIELD)\
    _ATL_##REG##_FGET(##FIELD)

  #define ATL_FSET(REG,FIELD,x)\
    _ATL_##REG##_FSET(##FIELD,##x)

  #define ATL_FSETS(REG,FIELD,SYM)\
    _ATL_##REG##_FSETS(##FIELD,##SYM)


  /* ------------------------------------------ */
  /* ADDRESS BASED REGISTER/FIELD ACCESS MACROS */
  /* ------------------------------------------ */

  #define ATL_RGETA(addr,REG)\
    _PER_RGET(addr,ATL,##REG)

  #define ATL_RSETA(addr,REG,x)\
    _PER_RSET(addr,ATL,##REG,x)

  #define ATL_FGETA(addr,REG,FIELD)\
    _PER_FGET(addr,ATL,##REG,##FIELD)

  #define ATL_FSETA(addr,REG,FIELD,x)\
    _PER_FSET(addr,ATL,##REG,##FIELD,x)

  #define ATL_FSETSA(addr,REG,FIELD,SYM)\
    _PER_FSETS(addr,ATL,##REG,##FIELD,##SYM)

/******************************************************************************\
*  ___________________
* |                   |
* |  A T L P P M R    |
* |___________________|
*
* ATLPPMR    - ATL Parts Per Million register
*
* FIELDS (msb -> lsb)
* (rw) PPMSD
* (rw) PPMSET
*
\******************************************************************************/
  #define _ATL_ATLPPMR_OFFSET           0

  #define _ATL_ATLPPMR_ADDR            0x01B7F000

  #define _ATL_ATLPPMR_PPMSD_MASK          0x00008000u
  #define _ATL_ATLPPMR_PPMSD_SHIFT         0x0000000Fu
  #define  ATL_ATLPPMR_PPMSD_DEFAULT       0x00000000u
  #define  ATL_ATLPPMR_PPMSD_OF(x)         _VALUEOF(x)
  #define  ATL_ATLPPMR_PPMSD_SLOWDOWN      0x00000000u
  #define  ATL_ATLPPMR_PPMSD_SPEEDUP       0x00000001u

  #define _ATL_ATLPPMR_PPMSET_MASK          0x000001FFu
  #define _ATL_ATLPPMR_PPMSET_SHIFT         0x00000000u
  #define  ATL_ATLPPMR_PPMSET_DEFAULT       0x00000000u
  #define  ATL_ATLPPMR_PPMSET_OF(x)         _VALUEOF(x)

  #define  ATL_ATLPPMR_OF(x)             _VALUEOF(x)

  #define ATL_ATLPPMR_DEFAULT (Uint32)(\
     _PER_FDEFAULT(ATL,ATLPPMR,PPMSD)\
    |_PER_FDEFAULT(ATL,ATLPPMR,PPMSET)\
  )

  #define ATL_ATLPPMR_RMK(ppmsd,ppmset) (Uint32)(\
     _PER_FMK(ATL,ATLPPMR,PPMSD,ppmsd)\
    |_PER_FMK(ATL,ATLPPMR,PPMSET,ppmset)\
  )
   
  #define _ATL_ATLPPMR_FGET(N,FIELD)\
    _PER_FGET(_ATL_ATLPPMR##N##_ADDR,ATL,ATLPPMR,##FIELD)

  #define _ATL_ATLPPMR_FSET(N,FIELD,field)\
    _PER_FSET(_ATL_ATLPPMR##N##_ADDR,ATL,ATLPPMR,##FIELD,field)

  #define _ATL_ATLPPMR_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_ATL_ATLPPMR##N##_ADDR,ATL,ATLPPMR,##FIELD,##SYM)

/******************************************************************************\
*  ___________________
* |                   |
* |  A T L S C N T R  |
* |___________________|
*
* ATLSCNTR    - ATL Sample Count register
*
* FIELDS (msb -> lsb)
* (r) SCNT
*
\******************************************************************************/
  #define _ATL_ATLSCNTR_OFFSET           1

  #define _ATL_ATLSCNTR_ADDR            0x01B7F004

  #define _ATL_ATLSCNTR_SCNT_MASK          0x0000FFFFu
  #define _ATL_ATLSCNTR_SCNT_SHIFT         0x00000000u
  #define  ATL_ATLSCNTR_SCNT_DEFAULT       0x00000000u
  #define  ATL_ATLSCNTR_SCNT_OF(x)         _VALUEOF(x)

  #define  ATL_ATLSCNTR_OF(x)             _VALUEOF(x)

  #define ATL_ATLSCNTR_DEFAULT (Uint32)(\
     _PER_FDEFAULT(ATL,ATLSCNTR,SCNT)\
  )

  #define ATL_ATLSCNTR_RMK(scnt) (Uint32)(\
     _PER_FMK(ATL,ATLSCNTR,SCNT,scnt)\
  )
   
  #define _ATL_ATLSCNTR_FGET(N,FIELD)\
    _PER_FGET(_ATL_ATLSCNTR##N##_ADDR,ATL,ATLSCNTR,##FIELD)

/******************************************************************************\
*  _______________
* |               |
* |  A T L C R    |
* |_______________|
*
* ATLCR    - ATL Control register
*
* FIELDS (msb -> lsb)
* (rw) MUXCLKSEL
* (rw) MCDSEL
* (rw) ATLIDIV
*
\******************************************************************************/
  #define _ATL_ATLCR_OFFSET           2

  #define _ATL_ATLCR_ADDR            0x01B7F008

  #define _ATL_ATLCR_MUXCLKSEL_MASK          0x00000040u
  #define _ATL_ATLCR_MUXCLKSEL_SHIFT         0x00000006u
  #define  ATL_ATLCR_MUXCLKSEL_DEFAULT       0x00000000u
  #define  ATL_ATLCR_MUXCLKSEL_OF(x)         _VALUEOF(x)
  #define  ATL_ATLCR_MUXCLKSEL_ATLPCLK       0x00000000u
  #define  ATL_ATLCR_MUXCLKSEL_EATCLK        0x00000001u

  #define _ATL_ATLCR_MCDSEL_MASK             0x00000020u
  #define _ATL_ATLCR_MCDSEL_SHIFT            0x00000005u
  #define  ATL_ATLCR_MCDSEL_DEFAULT          0x00000000u
  #define  ATL_ATLCR_MCDSEL_OF(x)            _VALUEOF(x)
  #define  ATL_ATLCR_MCDSEL_BY2P16           0x00000000u
  #define  ATL_ATLCR_MCDSEL_BY2P14           0x00000001u

  #define _ATL_ATLCR_ATLIDIV_MASK            0x0000001Fu
  #define _ATL_ATLCR_ATLIDIV_SHIFT           0x00000000u
  #define  ATL_ATLCR_ATLIDIV_DEFAULT         0x00000018u
  #define  ATL_ATLCR_ATLIDIV_OF(x)           _VALUEOF(x)

  #define  ATL_ATLCR_OF(x)             _VALUEOF(x)

  #define ATL_ATLCR_DEFAULT (Uint32)(\
     _PER_FDEFAULT(ATL,ATLCR,MUXCLKSEL)\
    |_PER_FDEFAULT(ATL,ATLCR,MCDSEL)\
    |_PER_FDEFAULT(ATL,ATLCR,ATLIDIV)\
  )

  #define ATL_ATLCR_RMK(muxclksel,mcdsel,atlidiv) (Uint32)(\
     _PER_FMK(ATL,ATLCR,MUXCLKSEL,muxclksel)\
    |_PER_FMK(ATL,ATLCR,MCDCLK,mcdsel)\
    |_PER_FMK(ATL,ATLCR,ATLIDIV,atlidiv)\
  )
   
  #define _ATL_ATLCR_FGET(N,FIELD)\
    _PER_FGET(_ATL_ATLCR##N##_ADDR,ATL,ATLCR,##FIELD)

  #define _ATL_ATLCR_FSET(N,FIELD,field)\
    _PER_FSET(_ATL_ATLCR##N##_ADDR,ATL,ATLCR,##FIELD,field)

  #define _ATL_ATLCR_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_ATL_ATLCR##N##_ADDR,ATL,ATLCR,##FIELD,##SYM)

#endif /* ATL_SUPPORT */
#endif /* _CSL_ATLHAL_H_ */
/******************************************************************************\
* End of csl_atlhal.h
\******************************************************************************/
