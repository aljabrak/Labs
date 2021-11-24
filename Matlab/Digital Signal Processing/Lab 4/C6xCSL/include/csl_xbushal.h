/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_xbushal.h
* DATE CREATED.. 06/12/2000 
* LAST MODIFIED. 10/03/2000 
*------------------------------------------------------------------------------
* REGISTERS
*
* XBGC     - global control register
* XCECTL0  - space control register 0
* XCECTL1  - space control register 1
* XCECTL2  - space control register 2
* XCECTL3  - space control register 3
* XBHC     - host port interface control register
* XBIMA    - internal master address register
* XBEA     - external address register
*
\******************************************************************************/
#ifndef _CSL_XBUSHAL_H_
#define _CSL_XBUSHAL_H_

#include <csl_stdinc.h>
#include <csl_chip.h>


#if (XBUS_SUPPORT)
/******************************************************************************\
* MISC section
\******************************************************************************/
#define _XBUS_BASE_GLOBAL   0x01880000u


/******************************************************************************\
* module level register/field access macros
\******************************************************************************/

  /* ----------------- */
  /* FIELD MAKE MACROS */
  /* ----------------- */

  #define XBUS_FMK(REG,FIELD,x)\
    _PER_FMK(XBUS,##REG,##FIELD,x)

  #define XBUS_FMKS(REG,FIELD,SYM)\
    _PER_FMKS(XBUS,##REG,##FIELD,##SYM)


  /* -------------------------------- */
  /* RAW REGISTER/FIELD ACCESS MACROS */
  /* -------------------------------- */

  #define XBUS_ADDR(REG)\
    _XBUS_##REG##_ADDR

  #define XBUS_RGET(REG)\
    _PER_RGET(_XBUS_##REG##_ADDR,XBUS,##REG)

  #define XBUS_RSET(REG,x)\
    _PER_RSET(_XBUS_##REG##_ADDR,XBUS,##REG,x)

  #define XBUS_FGET(REG,FIELD)\
    _XBUS_##REG##_FGET(##FIELD)

  #define XBUS_FSET(REG,FIELD,x)\
    _XBUS_##REG##_FSET(##FIELD,##x)

  #define XBUS_FSETS(REG,FIELD,SYM)\
    _XBUS_##REG##_FSETS(##FIELD,##SYM)


  /* ------------------------------------------ */
  /* ADDRESS BASED REGISTER/FIELD ACCESS MACROS */
  /* ------------------------------------------ */

  #define XBUS_RGETA(addr,REG)\
    _PER_RGET(addr,XBUS,##REG)

  #define XBUS_RSETA(addr,REG,x)\
    _PER_RSET(addr,XBUS,##REG,x)

  #define XBUS_FGETA(addr,REG,FIELD)\
    _PER_FGET(addr,XBUS,##REG,##FIELD)

  #define XBUS_FSETA(addr,REG,FIELD,x)\
    _PER_FSET(addr,XBUS,##REG,##FIELD,x)

  #define XBUS_FSETSA(addr,REG,FIELD,SYM)\
    _PER_FSETS(addr,XBUS,##REG,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  X B G C          |
* |___________________|
*
* XBGC - global control register
*
* FIELDS (msb -> lsb)
* (r)  FMOD
* (rw) XFCEN
* (rw) XFRAT
* (r)  XARB
*
\******************************************************************************/
  #define _XBUS_XBGC_OFFSET                0
  
  #define _XBUS_XBGC_ADDR                  0x01880000u

  #define _XBUS_XBGC_FMOD_MASK             0x00008000u
  #define _XBUS_XBGC_FMOD_SHIFT            0x0000000Fu
  #define  XBUS_XBGC_FMOD_DEFAULT          0x00000000u
  #define  XBUS_XBGC_FMOD_OF(x)            _VALUEOF(x)
  #define  XBUS_XBGC_FMOD_GLUE             0x00000000u
  #define  XBUS_XBGC_FMOD_GLUELESS         0x00000001u

  #define _XBUS_XBGC_XFCEN_MASK            0x00004000u
  #define _XBUS_XBGC_XFCEN_SHIFT           0x0000000Eu
  #define  XBUS_XBGC_XFCEN_DEFAULT         0x00000000u
  #define  XBUS_XBGC_XFCEN_OF(x)           _VALUEOF(x)
  #define  XBUS_XBGC_XFCEN_DISABLE         0x00000000u
  #define  XBUS_XBGC_XFCEN_ENABLE          0x00000001u

  #define _XBUS_XBGC_XFRAT_MASK            0x00003000u
  #define _XBUS_XBGC_XFRAT_SHIFT           0x0000000Cu
  #define  XBUS_XBGC_XFRAT_DEFAULT         0x00000000u
  #define  XBUS_XBGC_XFRAT_OF(x)           _VALUEOF(x)
  #define  XBUS_XBGC_XFRAT_ONEEIGHTH       0x00000000u
  #define  XBUS_XBGC_XFRAT_ONESIXTH        0x00000001u
  #define  XBUS_XBGC_XFRAT_ONEFOURTH       0x00000002u
  #define  XBUS_XBGC_XFRAT_ONEHALF         0x00000003u

  #define _XBUS_XBGC_XARB_MASK             0x00000800u
  #define _XBUS_XBGC_XARB_SHIFT            0x0000000Bu
  #define  XBUS_XBGC_XARB_DEFAULT          0x00000000u
  #define  XBUS_XBGC_XARB_OF(x)            _VALUEOF(x)
  #define  XBUS_XBGC_XARB_DISABLE          0x00000000u
  #define  XBUS_XBGC_XARB_ENABLE           0x00000001u

  #define  XBUS_XBGC_OF(x)                 _VALUEOF(x)

  #define XBUS_XBGC_DEFAULT (Uint32)( \
     _PER_FDEFAULT(XBUS,XBGC,FMOD) \
    |_PER_FDEFAULT(XBUS,XBGC,XFCEN) \
    |_PER_FDEFAULT(XBUS,XBGC,XFRAT) \
    |_PER_FDEFAULT(XBUS,XBGC,XARB) \
  )

  #define XBUS_XBGC_RMK(xfcen,xfrat) (Uint32)( \
     _PER_FMK(XBUS,XBGC,XFCEN,xfcen) \
    |_PER_FMK(XBUS,XBGC,XFRAT,xfrat) \
  )

  #define _XBUS_XBGC_FGET(FIELD)\
    _PER_FGET(_XBUS_XBGC_ADDR,XBUS,XBGC,##FIELD)

  #define _XBUS_XBGC_FSET(FIELD,field)\
    _PER_FSET(_XBUS_XBGC_ADDR,XBUS,XBGC,##FIELD,field)

  #define _XBUS_XBGC_FSETS(FIELD,SYM)\
    _PER_FSETS(_XBUS_XBGC_ADDR,XBUS,XBGC,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  X C E C T L      |
* |___________________|
*
* XCECTL0  - XCE space control register 0
* XCECTL1  - XCE space control register 1
* XCECTL2  - XCE space control register 2
* XCECTL3  - XCE space control register 3
*
* FIELDS (msb -> lsb)
* (rw) WRSETUP
* (rw) WRSTROBE
* (rw) WRHOLD
* (rw) RDSETUP
* (rw) RDSTROBE
* (rw) MTYPE
* (rw) RDHOLD
*
\******************************************************************************/
  #define _XBUS_XCECTL0_OFFSET             2
  #define _XBUS_XCECTL1_OFFSET             1
  #define _XBUS_XCECTL2_OFFSET             4
  #define _XBUS_XCECTL3_OFFSET             5

  #define _XBUS_XCECTL0_ADDR               0x01880008u
  #define _XBUS_XCECTL1_ADDR               0x01880004u
  #define _XBUS_XCECTL2_ADDR               0x01880010u
  #define _XBUS_XCECTL3_ADDR               0x01880014u

  #define _XBUS_XCECTL_WRSETUP_MASK        0xF0000000u
  #define _XBUS_XCECTL_WRSETUP_SHIFT       0x0000001Cu
  #define  XBUS_XCECTL_WRSETUP_DEFAULT     0x0000000Fu
  #define  XBUS_XCECTL_WRSETUP_OF(x)       _VALUEOF(x)

  #define _XBUS_XCECTL_WRSTRB_MASK       0x0FC00000u
  #define _XBUS_XCECTL_WRSTRB_SHIFT      0x00000016u
  #define  XBUS_XCECTL_WRSTRB_DEFAULT    0x0000003Fu
  #define  XBUS_XCECTL_WRSTRB_OF(x)      _VALUEOF(x)

  #define _XBUS_XCECTL_WRHLD_MASK         0x00300000u
  #define _XBUS_XCECTL_WRHLD_SHIFT        0x00000014u
  #define  XBUS_XCECTL_WRHLD_DEFAULT      0x00000003u
  #define  XBUS_XCECTL_WRHLD_OF(x)        _VALUEOF(x)

  #define _XBUS_XCECTL_RDSETUP_MASK        0x000F0000u
  #define _XBUS_XCECTL_RDSETUP_SHIFT       0x00000010u
  #define  XBUS_XCECTL_RDSETUP_DEFAULT     0x0000000Fu
  #define  XBUS_XCECTL_RDSETUP_OF(x)       _VALUEOF(x)

  #define _XBUS_XCECTL_RDSTRB_MASK       0x00003F00u
  #define _XBUS_XCECTL_RDSTRB_SHIFT      0x00000008u
  #define  XBUS_XCECTL_RDSTRB_DEFAULT    0x0000003Fu
  #define  XBUS_XCECTL_RDSTRB_OF(x)      _VALUEOF(x)

  #define _XBUS_XCECTL_MTYPE_MASK          0x00000070u
  #define _XBUS_XCECTL_MTYPE_SHIFT         0x00000004u
  #define  XBUS_XCECTL_MTYPE_DEFAULT       0x00000000u
  #define  XBUS_XCECTL_MTYPE_OF(x)         _VALUEOF(x)
  #define  XBUS_XCECTL_MTYPE_32BITASYN     0x00000020u
  #define  XBUS_XCECTL_MTYPE_32BITFIFO     0x00000050u

  #define _XBUS_XCECTL_RDHLD_MASK         0x00000003u
  #define _XBUS_XCECTL_RDHLD_SHIFT        0x00000000u
  #define  XBUS_XCECTL_RDHLD_DEFAULT      0x00000003u
  #define  XBUS_XCECTL_RDHLD_OF(x)        _VALUEOF(x)

  #define  XBUS_XCECTL_OF(x)               _VALUEOF(x)

  #define XBUS_XCECTL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(XBUS,XCECTL,WRSETUP) \
    |_PER_FDEFAULT(XBUS,XCECTL,WRSTRB) \
    |_PER_FDEFAULT(XBUS,XCECTL,WRHLD) \
    |_PER_FDEFAULT(XBUS,XCECTL,RDSETUP) \
    |_PER_FDEFAULT(XBUS,XCECTL,RDSTRB) \
    |_PER_FDEFAULT(XBUS,XCECTL,MTYPE) \
    |_PER_FDEFAULT(XBUS,XCECTL,RDHLD) \
  )

  #define XBUS_XCECTL_RMK(wrsetup,wrstrb,wrhld,\
    rdsetup,rdstrb,rdhld) (Uint32)( \
     _PER_FMK(XBUS,XCECTL,WRSETUP,wrsetup) \
    |_PER_FMK(XBUS,XCECTL,WRSTRB,wrstrb) \
    |_PER_FMK(XBUS,XCECTL,WRHLD,wrhld) \
    |_PER_FMK(XBUS,XCECTL,RDSETUP,rdsetup) \
    |_PER_FMK(XBUS,XCECTL,RDSTRB,rdstrb) \
    |_PER_FMK(XBUS,XCECTL,RDHLD,rdhld) \
  )

  #define _XBUS_XCECTL_FGET(N,FIELD)\
    _PER_FGET(_XBUS_XCECTL##N##_ADDR,XBUS,XCECTL,##FIELD)

  #define _XBUS_XCECTL_FSET(N,FIELD,field)\
    _PER_FSET(_XBUS_XCECTL##N##_ADDR,XBUS,XCECTL,##FIELD,field)

  #define _XBUS_XCECTL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_XBUS_XCECTL##N##_ADDR,XBUS,XCECTL,##FIELD,##SYM)

  #define _XBUS_XCECTL0_FGET(FIELD) _XBUS_XCECTL_FGET(0,##FIELD)
  #define _XBUS_XCECTL1_FGET(FIELD) _XBUS_XCECTL_FGET(1,##FIELD)
  #define _XBUS_XCECTL2_FGET(FIELD) _XBUS_XCECTL_FGET(2,##FIELD)
  #define _XBUS_XCECTL3_FGET(FIELD) _XBUS_XCECTL_FGET(3,##FIELD)

  #define _XBUS_XCECTL0_FSET(FIELD,f) _XBUS_XCECTL_FSET(0,##FIELD,f)
  #define _XBUS_XCECTL1_FSET(FIELD,f) _XBUS_XCECTL_FSET(1,##FIELD,f)
  #define _XBUS_XCECTL2_FSET(FIELD,f) _XBUS_XCECTL_FSET(2,##FIELD,f)
  #define _XBUS_XCECTL3_FSET(FIELD,f) _XBUS_XCECTL_FSET(3,##FIELD,f)

  #define _XBUS_XCECTL0_FSETS(FIELD,SYM) _XBUS_XCECTL_FSETS(0,##FIELD,##SYM)
  #define _XBUS_XCECTL1_FSETS(FIELD,SYM) _XBUS_XCECTL_FSETS(1,##FIELD,##SYM)
  #define _XBUS_XCECTL2_FSETS(FIELD,SYM) _XBUS_XCECTL_FSETS(2,##FIELD,##SYM)
  #define _XBUS_XCECTL3_FSETS(FIELD,SYM) _XBUS_XCECTL_FSETS(3,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  X B H C          |
* |___________________|
*
* XBHC  - expansion bus host port interface control register
*
* FIELDS (msb -> lsb)
* (rw) XFRCT
* (rw) INTSRC
* (rw) START
* (rw) DSPINT
*
\******************************************************************************/
  #define _XBUS_XBHC_OFFSET                3

  #define _XBUS_XBHC_ADDR                  0x0188000Cu

  #define _XBUS_XBHC_XFRCT_MASK            0xFFFF0000u
  #define _XBUS_XBHC_XFRCT_SHIFT           0x00000010u
  #define  XBUS_XBHC_XFRCT_DEFAULT         0x00000000u
  #define  XBUS_XBHC_XFRCT_OF(x)           _VALUEOF(x)

  #define _XBUS_XBHC_INTSRC_MASK           0x00000020u
  #define _XBUS_XBHC_INTSRC_SHIFT          0x00000005u
  #define  XBUS_XBHC_INTSRC_DEFAULT        0x00000000u
  #define  XBUS_XBHC_INTSRC_OF(x)          _VALUEOF(x)
  #define  XBUS_XBHC_INTSRC_DSPINT         0x00000000u
  #define  XBUS_XBHC_INTSRC_XFRCT          0x00000001u

  #define _XBUS_XBHC_START_MASK            0x00000018u
  #define _XBUS_XBHC_START_SHIFT           0x00000003u
  #define  XBUS_XBHC_START_DEFAULT         0x00000000u
  #define  XBUS_XBHC_START_OF(x)           _VALUEOF(x)
  #define  XBUS_XBHC_START_ABORT           0x00000000u
  #define  XBUS_XBHC_START_WRITE           0x00000001u
  #define  XBUS_XBHC_START_READ            0x00000002u

  #define _XBUS_XBHC_DSPINT_MASK           0x00000002u
  #define _XBUS_XBHC_DSPINT_SHIFT          0x00000001u
  #define  XBUS_XBHC_DSPINT_DEFAULT        0x00000000u
  #define  XBUS_XBHC_DSPINT_OF(x)          _VALUEOF(x)
  #define  XBUS_XBHC_DSPINT_NONE           0x00000000u
  #define  XBUS_XBHC_DSPINT_CLR            0x00000001u

  #define  XBUS_XBHC_OF(x)                 _VALUEOF(x)

  #define XBUS_XBHC_DEFAULT (Uint32)( \
     _PER_FDEFAULT(XBUS,XBHC,XFRCT) \
    |_PER_FDEFAULT(XBUS,XBHC,INTSRC) \
    |_PER_FDEFAULT(XBUS,XBHC,START) \
    |_PER_FDEFAULT(XBUS,XBHC,DSPINT) \
  )

  #define XBUS_XBHC_RMK(xfrct,intsrc,start,dspint) (Uint32)( \
     _PER_FMK(XBUS,XBHC,XFRCT,xfrct) \
    |_PER_FMK(XBUS,XBHC,INTSRC,intsrc) \
    |_PER_FMK(XBUS,XBHC,START,start) \
    |_PER_FMK(XBUS,XBHC,DSPINT,dspint) \
  )

  #define _XBUS_XBHC_FGET(FIELD)\
    _PER_FGET(_XBUS_XBHC_ADDR,XBUS,XBHC,##FIELD)

  #define _XBUS_XBHC_FSET(FIELD,field)\
    _PER_FSET(_XBUS_XBHC_ADDR,XBUS,XBHC,##FIELD,field)

  #define _XBUS_XBHC_FSETS(FIELD,SYM)\
    _PER_FSETS(_XBUS_XBHC_ADDR,XBUS,XBHC,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  X B I M A        |
* |___________________|
*
* XBIMA  - expansion bus internal master address register
*
* FIELDS (msb -> lsb)
* (rw) XBIMA
*
\******************************************************************************/
  #define _XBUS_XBIMA_OFFSET               8

  #define _XBUS_XBIMA_ADDR                 0x01880020u

  #define _XBUS_XBIMA_XBIMA_MASK           0xFFFFFFFFu
  #define _XBUS_XBIMA_XBIMA_SHIFT          0x00000000u
  #define  XBUS_XBIMA_XBIMA_DEFAULT        0x00000000u
  #define  XBUS_XBIMA_XBIMA_OF(x)          _VALUEOF(x)

  #define  XBUS_XBIMA_OF(x)                _VALUEOF(x)

  #define XBUS_XBIMA_DEFAULT (Uint32)( \
     _PER_FDEFAULT(XBUS,XBIMA,XBIMA) \
  )

  #define XBUS_XBIMA_RMK(xbima) (Uint32)( \
     _PER_FMK(XBUS,XBIMA,XBIMA,xbima) \
  )

  #define _XBUS_XBIMA_FGET(FIELD)\
    _PER_FGET(_XBUS_XBIMA_ADDR,XBUS,XBIMA,##FIELD)

  #define _XBUS_XBIMA_FSET(FIELD,field)\
    _PER_FSET(_XBUS_XBIMA_ADDR,XBUS,XBIMA,##FIELD,field)

  #define _XBUS_XBIMA_FSETS(FIELD,SYM)\
    _PER_FSETS(_XBUS_XBIMA_ADDR,XBUS,XBIMA,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  X B E A          |
* |___________________|
*
* XBEA  - expansion bus external address register
*
* FIELDS (msb -> lsb)
* (rw) XBEA
*
\******************************************************************************/
  #define _XBUS_XBEA_OFFSET                9

  #define _XBUS_XBEA_ADDR                  0x01880024u

  #define _XBUS_XBEA_XBEA_MASK             0xFFFFFFFFu
  #define _XBUS_XBEA_XBEA_SHIFT            0x00000000u
  #define  XBUS_XBEA_XBEA_DEFAULT          0x00000000u
  #define  XBUS_XBEA_XBEA_OF(x)            _VALUEOF(x)

  #define  XBUS_XBEA_OF(x)                 _VALUEOF(x)

  #define XBUS_XBEA_DEFAULT (Uint32)( \
     _PER_FDEFAULT(XBUS,XBEA,XBEA) \
  )

  #define XBUS_XBEA_RMK(xbea) (Uint32)( \
     _PER_FMK(XBUS,XBEA,XBEA,xbea) \
  )

  #define _XBUS_XBEA_FGET(FIELD)\
    _PER_FGET(_XBUS_XBEA_ADDR,XBUS,XBEA,##FIELD)

  #define _XBUS_XBEA_FSET(FIELD,field)\
    _PER_FSET(_XBUS_XBEA_ADDR,XBUS,XBEA,##FIELD,field)

  #define _XBUS_XBEA_FSETS(FIELD,SYM)\
    _PER_FSETS(_XBUS_XBEA_ADDR,XBUS,XBEA,##FIELD,##SYM)


/*----------------------------------------------------------------------------*/

#endif /* XBUS_SUPPORT */
#endif /* _CSL_XBUSHAL_H_ */
/******************************************************************************\
* End of csl_xbushal.h
\******************************************************************************/

