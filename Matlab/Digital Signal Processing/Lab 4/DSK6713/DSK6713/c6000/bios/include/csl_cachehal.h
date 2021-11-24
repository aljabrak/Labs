/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_cachehal.h
* DATE CREATED.. 06/12/1999 
* LAST MODIFIED. 04/13/2001
*------------------------------------------------------------------------------
* REGISTERS
*
* CCFG     - cache configuration register
* L2FBAR   - L2 flush base address register
* L2FWC    - L2 flush word count register
* L2CBAR   - L2 clean base register
* L2CWC    - L2 clean word count register
* L1PFBAR  - L1P flush base address register
* L1PFWC   - L1P flush word count register
* L1DFBAR  - L1D flush base address register
* L1DFWC   - L1D flush word count register
* L2FLUSH  - L2 flush register
* L2CLEAN  - L2 clean register
*
*
*
*
*
* New Register Names based on SPRU609 for C621x/C671x
* and
* New Register Names based on SPRU610 for C64x
*
*
* L2WBAR   - L2 writeback base address register
* L2WWC    - L2 writeback word count register
* L2WIBAR  - L2 writeback-invalidate base address register
* L2WIWC   - L2 writeback-invalidate word count register
* L2IBAR   - L2 invalidate base address register(2)
* L2IWC    - L2 invalidate word count register(2)
* L1PIBAR  - L1P invalidate base address register
* L1PIWC   - L1P invalidate word count register
* L1DWIBAR - L1D writeback-invalidate base address register
* L1DWIWC  - L1D writeback-invalidate word count register
* L1DIBAR  - L1D invalidate base address register(2)
* L1DIWC   - L1D invalidate word count register(2)
* L2WB     - L2 writeback all register
* L2WBINV  - L2 writeback-invalidate all register
*
* MAR0     - memory attribute register 0
* MAR1     - memory attribute register 1
* ...      - ...
* MARn     - memory attribute register n (1)
* L2ALLOC0 - L2 Allocation register 0    (2)
* L2ALLOC1 - L2 Allocation register 1    (2)
* L2ALLOC2 - L2 Allocation register 2    (2)
* L2ALLOC3 - L2 Allocation register 3    (2)
*
* (1) n is different between C6x1x and C64x
* (2) C64x devices only
*
\******************************************************************************/
#ifndef _CSL_CACHEHAL_H_
#define _CSL_CACHEHAL_H_

#include <csl_stdinc.h>
#include <csl_chip.h>

#if (CACHE_SUPPORT)
/******************************************************************************\
* MISC section
\******************************************************************************/
#define _CACHE_BASE_GLOBAL  0x01840000u
#define CACHE_L2_SUPPORT L2CACHE_SUPPORT 


/******************************************************************************\
* module level register/field access macros
\******************************************************************************/

  /* ----------------- */
  /* FIELD MAKE MACROS */
  /* ----------------- */

  #define CACHE_FMK(REG,FIELD,x)\
    _PER_FMK(CACHE,##REG,##FIELD,x)

  #define CACHE_FMKS(REG,FIELD,SYM)\
    _PER_FMKS(CACHE,##REG,##FIELD,##SYM)
 
 
  /* -------------------------------- */
  /* RAW REGISTER/FIELD ACCESS MACROS */
  /* -------------------------------- */

  #define CACHE_ADDR(REG)\
    _CACHE_##REG##_ADDR

  #define CACHE_RGET(REG)\
    _PER_RGET(_CACHE_##REG##_ADDR,CACHE,##REG)

  #define CACHE_RSET(REG,x)\
    _PER_RSET(_CACHE_##REG##_ADDR,CACHE,##REG,x)

  #define CACHE_FGET(REG,FIELD)\
    _CACHE_##REG##_FGET(##FIELD)

  #define CACHE_FSET(REG,FIELD,x)\
    _CACHE_##REG##_FSET(##FIELD,x)

  #define CACHE_FSETS(REG,FIELD,SYM)\
    _CACHE_##REG##_FSETS(##FIELD,##SYM)
 
 
  /* ------------------------------------------ */
  /* ADDRESS BASED REGISTER/FIELD ACCESS MACROS */
  /* ------------------------------------------ */

  #define CACHE_RGETA(addr,REG)\
    _PER_RGET(addr,CACHE,##REG)

  #define CACHE_RSETA(addr,REG,x)\
    _PER_RSET(addr,CACHE,##REG,x)

  #define CACHE_FGETA(addr,REG,FIELD)\
    _PER_FGET(addr,CACHE,##REG,##FIELD)

  #define CACHE_FSETA(addr,REG,FIELD,x)\
    _PER_FSET(addr,CACHE,##REG,##FIELD,x)

  #define CACHE_FSETSA(addr,REG,FIELD,SYM)\
    _PER_FSETS(addr,CACHE,##REG,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  C C F G          |
* |___________________|
*
* CCFG - cache configuration register
*
* FIELDS (msb -> lsb)
* (rw) P (1)
* (w)  IP
* (w)  ID
* (rw) L2MODE
*
* (1) only supported for C64x devices
*
\******************************************************************************/
#if (L2CACHE_SUPPORT)
  #define _CACHE_CCFG_ADDR             0x01840000u

#if (C64_SUPPORT)
  #define _CACHE_CCFG_P_MASK           0xE0000000u
  #define _CACHE_CCFG_P_SHIFT          0x0000001Du
  #define  CACHE_CCFG_P_DEFAULT        0x00000000u
  #define  CACHE_CCFG_P_OF(x)          _VALUEOF(x)
  #define  CACHE_CCFG_P_URGENT         0x00000000u
  #define  CACHE_CCFG_P_HIGH           0x00000001u
  #define  CACHE_CCFG_P_MEDIUM         0x00000002u
  #define  CACHE_CCFG_P_LOW            0x00000003u
#endif

  #define _CACHE_CCFG_IP_MASK          0x00000200u
  #define _CACHE_CCFG_IP_SHIFT         0x00000009u
  #define  CACHE_CCFG_IP_DEFAULT       0x00000000u
  #define  CACHE_CCFG_IP_OF(x)         _VALUEOF(x)
  #define  CACHE_CCFG_IP_NORMAL        0x00000000u
  #define  CACHE_CCFG_IP_INVALIDATE    0x00000001u

  #define _CACHE_CCFG_ID_MASK          0x00000100u
  #define _CACHE_CCFG_ID_SHIFT         0x00000008u
  #define  CACHE_CCFG_ID_DEFAULT       0x00000000u
  #define  CACHE_CCFG_ID_OF(x)         _VALUEOF(x)
  #define  CACHE_CCFG_ID_NORMAL        0x00000000u
  #define  CACHE_CCFG_ID_INVALIDATE    0x00000001u

#if (!C64_SUPPORT)
  #define _CACHE_CCFG_L2MODE_MASK      0x00000007u
  #define _CACHE_CCFG_L2MODE_SHIFT     0x00000000u
  #define  CACHE_CCFG_L2MODE_DEFAULT   0x00000000u
  #define  CACHE_CCFG_L2MODE_OF(x)     _VALUEOF(x)
  #define  CACHE_CCFG_L2MODE_0KC       0x00000000u
  #define  CACHE_CCFG_L2MODE_16KC      0x00000001u
  #define  CACHE_CCFG_L2MODE_32KC      0x00000002u
  #define  CACHE_CCFG_L2MODE_48KC      0x00000003u
  #define  CACHE_CCFG_L2MODE_64KC      0x00000007u
#else 
  #define _CACHE_CCFG_L2MODE_MASK      0x00000007u
  #define _CACHE_CCFG_L2MODE_SHIFT     0x00000000u
  #define  CACHE_CCFG_L2MODE_DEFAULT   0x00000000u
  #define  CACHE_CCFG_L2MODE_OF(x)     _VALUEOF(x)
  #define  CACHE_CCFG_L2MODE_0KC       0x00000000u
  #define  CACHE_CCFG_L2MODE_32KC      0x00000001u
  #define  CACHE_CCFG_L2MODE_64KC      0x00000002u
  #define  CACHE_CCFG_L2MODE_128KC     0x00000003u

  #if (!(CHIP_6410 | CHIP_DM641 | CHIP_DM640))
      #define  CACHE_CCFG_L2MODE_256KC     0x00000007u /* This is an invalid mode for C6410,DM641,DM640 */
  #endif

#endif

  #define  CACHE_CCFG_OF(x)            _VALUEOF(x)

#if (!C64_SUPPORT)
  #define CACHE_CCFG_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,CCFG,IP) \
    |_PER_FDEFAULT(CACHE,CCFG,ID) \
    |_PER_FDEFAULT(CACHE,CCFG,L2MODE) \
  )

  #define CACHE_CCFG_RMK(ip,id,l2mode) (Uint32)( \
     _PER_FMK(CACHE,CCFG,IP,ip) \
    |_PER_FMK(CACHE,CCFG,ID,id) \
    |_PER_FMK(CACHE,CCFG,L2MODE,l2mode) \
  )
#else 
  #define CACHE_CCFG_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,CCFG,P) \
    |_PER_FDEFAULT(CACHE,CCFG,IP) \
    |_PER_FDEFAULT(CACHE,CCFG,ID) \
    |_PER_FDEFAULT(CACHE,CCFG,L2MODE) \
  )

  #define CACHE_CCFG_RMK(p,ip,id,l2mode) (Uint32)( \
     _PER_FMK(CACHE,CCFG,P,p) \
    |_PER_FMK(CACHE,CCFG,IP,ip) \
    |_PER_FMK(CACHE,CCFG,ID,id) \
    |_PER_FMK(CACHE,CCFG,L2MODE,l2mode) \
  )
#endif

  #define _CACHE_CCFG_FGET(FIELD)\
    _PER_FGET(_CACHE_CCFG_ADDR,CACHE,CCFG,##FIELD)

  #define _CACHE_CCFG_FSET(FIELD,field)\
    _PER_FSET(_CACHE_CCFG_ADDR,CACHE,CCFG,##FIELD,field)

  #define _CACHE_CCFG_FSETS(FIELD,SYM)\
    _PER_FSETS(_CACHE_CCFG_ADDR,CACHE,CCFG,##FIELD,##SYM)

#endif /* L2CACHE_SUPPORT */


/******************************************************************************\
* _____________________
* |                   |
* |  L 2 F B A R      |
* |___________________|
*
* L2FBAR - L2 flush base address register
*
* Fields:
* (rw) L2FBAR
*
\******************************************************************************/
#if (L2CACHE_SUPPORT)
  #define _CACHE_L2FBAR_ADDR           0x01844000u

  #define _CACHE_L2FBAR_L2FBAR_MASK    0xFFFFFFFFu
  #define _CACHE_L2FBAR_L2FBAR_SHIFT   0x00000000u
  #define  CACHE_L2FBAR_L2FBAR_DEFAULT 0x00000000u
  #define  CACHE_L2FBAR_L2FBAR_OF(x)   _VALUEOF(x)

  #define  CACHE_L2FBAR_OF(x)          _VALUEOF(x)

  #define CACHE_L2FBAR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,L2FBAR,L2FBAR) \
  )

  #define CACHE_L2FBAR_RMK(l2fbar) (Uint32)( \
     _PER_FMK(CACHE,L2FBAR,L2FBAR,l2fbar) \
  )

  #define _CACHE_L2FBAR_FGET(FIELD)\
    _PER_FGET(_CACHE_L2FBAR_ADDR,CACHE,L2FBAR,##FIELD)

  #define _CACHE_L2FBAR_FSET(FIELD,field)\
    _PER_FSET(_CACHE_L2FBAR_ADDR,CACHE,L2FBAR,##FIELD,field)

  #define _CACHE_L2FBAR_FSETS(FIELD,SYM)\
    _PER_FSETS(_CACHE_L2FBAR_ADDR,CACHE,L2FBAR,##FIELD,##SYM)
#endif


/******************************************************************************\
* _____________________
* |                   |
* |  L 2 F W C        |
* |___________________|
*
* L2FWC - L2 flush word count register
*
* Fields:
* (rw) L2FWC
*
\******************************************************************************/
#if (L2CACHE_SUPPORT)
  #define _CACHE_L2FWC_ADDR           0x01844004u

  #define _CACHE_L2FWC_L2FWC_MASK     0x0000FFFFu
  #define _CACHE_L2FWC_L2FWC_SHIFT    0x00000000u
  #define  CACHE_L2FWC_L2FWC_DEFAULT  0x00000000u
  #define  CACHE_L2FWC_L2FWC_OF(x)    _VALUEOF(x)

  #define  CACHE_L2FWC_OF(x)          _VALUEOF(x)

  #define CACHE_L2FWC_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,L2FWC,L2FWC) \
  )

  #define CACHE_L2FWC_RMK(l2fwc) (Uint32)( \
     _PER_FMK(CACHE,L2FWC,L2FWC,l2fwc) \
  )

  #define _CACHE_L2FWC_FGET(FIELD)\
    _PER_FGET(_CACHE_L2FWC_ADDR,CACHE,L2FWC,##FIELD)

  #define _CACHE_L2FWC_FSET(FIELD,field)\
    _PER_FSET(_CACHE_L2FWC_ADDR,CACHE,L2FWC,##FIELD,field)

  #define _CACHE_L2FWC_FSETS(FIELD,SYM)\
    _PER_FSETS(_CACHE_L2FWC_ADDR,CACHE,L2FWC,##FIELD,##SYM)
#endif


/******************************************************************************\
* _____________________
* |                   |
* |  L 2 C B A R      |
* |___________________|
*
* L2CBAR - L2 clean base address register
*
* Fields:
* (rw) L2CBAR
*
\******************************************************************************/
#if (L2CACHE_SUPPORT)
  #define _CACHE_L2CBAR_ADDR           0x01844010u

  #define _CACHE_L2CBAR_L2CBAR_MASK    0xFFFFFFFFu
  #define _CACHE_L2CBAR_L2CBAR_SHIFT   0x00000000u
  #define  CACHE_L2CBAR_L2CBAR_DEFAULT 0x00000000u
  #define  CACHE_L2CBAR_L2CBAR_OF(x)   _VALUEOF(x)

  #define  CACHE_L2CBAR_OF(x)          _VALUEOF(x)

  #define CACHE_L2CBAR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,L2CBAR,L2CBAR) \
  )

  #define CACHE_L2CBAR_RMK(l2cbar) (Uint32)( \
     _PER_FMK(CACHE,L2CBAR,L2CBAR,l2cbar) \
  )

  #define _CACHE_L2CBAR_FGET(FIELD)\
    _PER_FGET(_CACHE_L2CBAR_ADDR,CACHE,L2CBAR,##FIELD)

  #define _CACHE_L2CBAR_FSET(FIELD,field)\
    _PER_FSET(_CACHE_L2CBAR_ADDR,CACHE,L2CBAR,##FIELD,field)

  #define _CACHE_L2CBAR_FSETS(FIELD,SYM)\
    _PER_FSETS(_CACHE_L2CBAR_ADDR,CACHE,L2CBAR,##FIELD,##SYM)
#endif


/******************************************************************************\
* _____________________
* |                   |
* |  L 2 C W C        |
* |___________________|
*
* L2CWC - L2 clean word count register
*
* Fields:
* (rw) L2CWC
*
\******************************************************************************/
#if (L2CACHE_SUPPORT)
  #define _CACHE_L2CWC_ADDR           0x01844014u

  #define _CACHE_L2CWC_L2CWC_MASK     0x0000FFFFu
  #define _CACHE_L2CWC_L2CWC_SHIFT    0x00000000u
  #define  CACHE_L2CWC_L2CWC_DEFAULT  0x00000000u
  #define  CACHE_L2CWC_L2CWC_OF(x)    _VALUEOF(x)

  #define  CACHE_L2CWC_OF(x)          _VALUEOF(x)

  #define CACHE_L2CWC_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,L2CWC,L2CWC) \
  )

  #define CACHE_L2CWC_RMK(l2cwc) (Uint32)( \
     _PER_FMK(CACHE,L2CWC,L2CWC,l2cwc) \
  )

  #define _CACHE_L2CWC_FGET(FIELD)\
    _PER_FGET(_CACHE_L2CWC_ADDR,CACHE,L2CWC,##FIELD)

  #define _CACHE_L2CWC_FSET(FIELD,field)\
    _PER_FSET(_CACHE_L2CWC_ADDR,CACHE,L2CWC,##FIELD,field)

  #define _CACHE_L2CWC_FSETS(FIELD,SYM)\
    _PER_FSETS(_CACHE_L2CWC_ADDR,CACHE,L2CWC,##FIELD,##SYM)
#endif


/******************************************************************************\
* _____________________
* |                   |
* |  L 1 P F B A R    |
* |___________________|
*
* L1PFBAR - L1P flush base address register
*
* Fields:
* (rw) L1PFBAR
*
\******************************************************************************/
#if (L2CACHE_SUPPORT)
   #define _CACHE_L1PFBAR_ADDR            0x01844020u

  #define _CACHE_L1PFBAR_L1PFBAR_MASK    0xFFFFFFFFu
  #define _CACHE_L1PFBAR_L1PFBAR_SHIFT   0x00000000u
  #define  CACHE_L1PFBAR_L1PFBAR_DEFAULT 0x00000000u
  #define  CACHE_L1PFBAR_L1PFBAR_OF(x)   _VALUEOF(x)

  #define  CACHE_L1PFBAR_OF(x)           _VALUEOF(x)

  #define CACHE_L1PFBAR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,L1PFBAR,L1PFBAR) \
  )

  #define _CACHE_L1PFBAR_FGET(FIELD)\
    _PER_FGET(_CACHE_L1PFBAR_ADDR,CACHE,L1PFBAR,##FIELD)

  #define _CACHE_L1PFBAR_FSET(FIELD,field)\
    _PER_FSET(_CACHE_L1PFBAR_ADDR,CACHE,L1PFBAR,##FIELD,field)

  #define _CACHE_L1PFBAR_FSETS(FIELD,SYM)\
    _PER_FSETS(_CACHE_L1PFBAR_ADDR,CACHE,L1PFBAR,##FIELD,##SYM)
#endif


/******************************************************************************\
* _____________________
* |                   |
* |  L 1 P F W C      |
* |___________________|
*
* L1PFWC - L1P flush word count register
*
* Fields:
* (rw) L1PFWC
*
\******************************************************************************/
#if (L2CACHE_SUPPORT)
  #define _CACHE_L1PFWC_ADDR            0x01844024u

  #define _CACHE_L1PFWC_L1PFWC_MASK     0x0000FFFFu
  #define _CACHE_L1PFWC_L1PFWC_SHIFT    0x00000000u
  #define  CACHE_L1PFWC_L1PFWC_DEFAULT  0x00000000u
  #define  CACHE_L1PFWC_L1PFWC_OF(x)    _VALUEOF(x)

  #define  CACHE_L1PFWC_OF(x)           _VALUEOF(x)

  #define CACHE_L1PFWC_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,L1PFWC,L1PFWC) \
  )

  #define CACHE_L1PFWC_RMK(l1pfwc) (Uint32)( \
     _PER_FMK(CACHE,L1PFWC,L1PFWC,l1pfwc) \
  )

  #define _CACHE_L1PFWC_FGET(FIELD)\
    _PER_FGET(_CACHE_L1PFWC_ADDR,CACHE,L1PFWC,##FIELD)

  #define _CACHE_L1PFWC_FSET(FIELD,field)\
    _PER_FSET(_CACHE_L1PFWC_ADDR,CACHE,L1PFWC,##FIELD,field)

  #define _CACHE_L1PFWC_FSETS(FIELD,SYM)\
    _PER_FSETS(_CACHE_L1PFWC_ADDR,CACHE,L1PFWC,##FIELD,##SYM)
#endif


/******************************************************************************\
* _____________________
* |                   |
* |  L 1 D F B A R    |
* |___________________|
*
* L1DFBAR - L1D flush base address register
*
* Fields:
* (rw) L1DFBAR
*
\******************************************************************************/
#if (L2CACHE_SUPPORT)
  #define _CACHE_L1DFBAR_ADDR            0x01844030u

  #define _CACHE_L1DFBAR_L1DFBAR_MASK    0xFFFFFFFFu
  #define _CACHE_L1DFBAR_L1DFBAR_SHIFT   0x00000000u
  #define  CACHE_L1DFBAR_L1DFBAR_DEFAULT 0x00000000u
  #define  CACHE_L1DFBAR_L1DFBAR_OF(x)   _VALUEOF(x)

  #define  CACHE_L1DFBAR_OF(x)           _VALUEOF(x)

  #define CACHE_L1DFBAR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,L1DFBAR,L1DFBAR) \
  )

  #define CACHE_L1DFBAR_RMK(l1dfbar) (Uint32)( \
     _PER_FMK(CACHE,L1DFBAR,L1DFBAR,l1dfbar) \
  )

  #define _CACHE_L1DFBAR_FGET(FIELD)\
    _PER_FGET(_CACHE_L1DFBAR_ADDR,CACHE,L1DFBAR,##FIELD)

  #define _CACHE_L1DFBAR_FSET(FIELD,field)\
    _PER_FSET(_CACHE_L1DFBAR_ADDR,CACHE,L1DFBAR,##FIELD,field)

  #define _CACHE_L1DFBAR_FSETS(FIELD,SYM)\
    _PER_FSETS(_CACHE_L1DFBAR_ADDR,CACHE,L1DFBAR,##FIELD,##SYM)
#endif


/******************************************************************************\
* _____________________
* |                   |
* |  L 1 D F W C      |
* |___________________|
*
* L1DFWC - L1D flush word count register
*
* Fields:
* (rw) L1DFWC
*
\******************************************************************************/
#if (L2CACHE_SUPPORT)
  #define _CACHE_L1DFWC_ADDR            0x01844034u

  #define _CACHE_L1DFWC_L1DFWC_MASK     0x0000FFFFu
  #define _CACHE_L1DFWC_L1DFWC_SHIFT    0x00000000u
  #define  CACHE_L1DFWC_L1DFWC_DEFAULT  0x00000000u
  #define  CACHE_L1DFWC_L1DFWC_OF(x)    _VALUEOF(x)

  #define  CACHE_L1DFWC_OF(x)           _VALUEOF(x)

  #define CACHE_L1DFWC_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,L1DFWC,L1DFWC) \
  )

  #define CACHE_L1DFWC_RMK(l1dfwc) (Uint32)( \
     _PER_FMK(CACHE,L1DFWC,L1DFWC,l1dfwc) \
  )

  #define _CACHE_L1DFWC_FGET(FIELD)\
    _PER_FGET(_CACHE_L1DFWC_ADDR,CACHE,L1DFWC,##FIELD)

  #define _CACHE_L1DFWC_FSET(FIELD,field)\
    _PER_FSET(_CACHE_L1DFWC_ADDR,CACHE,L1DFWC,##FIELD,field)

  #define _CACHE_L1DFWC_FSETS(FIELD,SYM)\
    _PER_FSETS(_CACHE_L1DFWC_ADDR,CACHE,L1DFWC,##FIELD,##SYM)
#endif


/******************************************************************************\
* _____________________
* |                   |
* |  L 2 F L U S H    |
* |___________________|
*
* L2FLUSH - L2 flush register
*
* Fields:
* (rw) F
*
\******************************************************************************/
#if (L2CACHE_SUPPORT)
  #define _CACHE_L2FLUSH_ADDR      0x01845000u

  #define _CACHE_L2FLUSH_F_MASK    0x00000001u
  #define _CACHE_L2FLUSH_F_SHIFT   0x00000000u
  #define  CACHE_L2FLUSH_F_DEFAULT 0x00000000u
  #define  CACHE_L2FLUSH_F_OF(x)   _VALUEOF(x)
  #define  CACHE_L2FLUSH_F_NORMAL  0x00000000u
  #define  CACHE_L2FLUSH_F_FLUSH   0x00000001u

  #define  CACHE_L2FLUSH_OF(x)     _VALUEOF(x)

  #define CACHE_L2FLUSH_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,L2FLUSH,F) \
  )

  #define CACHE_L2FLUSH_RMK(f) (Uint32)( \
     _PER_FMK(CACHE,L2FLUSH,F,f) \
  )

  #define _CACHE_L2FLUSH_FGET(FIELD)\
    _PER_FGET(_CACHE_L2FLUSH_ADDR,CACHE,L2FLUSH,##FIELD)

  #define _CACHE_L2FLUSH_FSET(FIELD,field)\
    _PER_FSET(_CACHE_L2FLUSH_ADDR,CACHE,L2FLUSH,##FIELD,field)

  #define _CACHE_L2FLUSH_FSETS(FIELD,SYM)\
    _PER_FSETS(_CACHE_L2FLUSH_ADDR,CACHE,L2FLUSH,##FIELD,##SYM)
#endif


/******************************************************************************\
* _____________________
* |                   |
* |  L 2 C L E A N    |
* |___________________|
*
* L2CLEAN - L2 clean register
*
* Fields:
* (rw) C
*
\******************************************************************************/
#if (L2CACHE_SUPPORT)
  #define _CACHE_L2CLEAN_ADDR       0x01845004u

  #define _CACHE_L2CLEAN_C_MASK     0x00000001u
  #define _CACHE_L2CLEAN_C_SHIFT    0x00000000u
  #define  CACHE_L2CLEAN_C_DEFAULT  0x00000000u
  #define  CACHE_L2CLEAN_C_OF(x)    _VALUEOF(x)
  #define  CACHE_L2CLEAN_C_NORMAL   0x00000000u
  #define  CACHE_L2CLEAN_C_CLEAN    0x00000001u

  #define  CACHE_L2CLEAN_OF(x)      _VALUEOF(x)

  #define CACHE_L2CLEAN_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,L2CLEAN,C) \
  )

  #define CACHE_L2CLEAN_RMK(c) (Uint32)( \
     _PER_FMK(CACHE,L2CLEAN,C,c) \
  )

  #define _CACHE_L2CLEAN_FGET(FIELD)\
    _PER_FGET(_CACHE_L2CLEAN_ADDR,CACHE,L2CLEAN,##FIELD)

  #define _CACHE_L2CLEAN_FSET(FIELD,field)\
    _PER_FSET(_CACHE_L2CLEAN_ADDR,CACHE,L2CLEAN,##FIELD,field)

  #define _CACHE_L2CLEAN_FSETS(FIELD,SYM)\
    _PER_FSETS(_CACHE_L2CLEAN_ADDR,CACHE,L2CLEAN,##FIELD,##SYM)
#endif

/******************************************************************************\
* _____________________
* |                   |
* |  L 2 A L L O C 0  |
* |___________________|
*
* L2ALLOC0 - L2 allocation register 0 (1)
*
* Fields:
* (rw) Q0CNT (2) (3)
*
* (1) only supported for C6400
* (2) default value is different from L2ALLOC1, L2ALLOC2, L2ALLOC3
* (3) Rename bit filed based on spru610
*
\******************************************************************************/
#if (L2CACHE_SUPPORT && C64_SUPPORT)
  #define _CACHE_L2ALLOC0_ADDR               0x01842000u

  #define _CACHE_L2ALLOC0_Q0CNT_MASK       0x00000007u
  #define _CACHE_L2ALLOC0_Q0CNT_SHIFT      0x00000000u
  #define  CACHE_L2ALLOC0_Q0CNT_DEFAULT    0x00000006u
  #define  CACHE_L2ALLOC0_Q0CNT_OF(x)      _VALUEOF(x)

  #define _CACHE_L2ALLOC0_L2ALLOC_MASK       _CACHE_L2ALLOC0_Q0CNT_MASK   
  #define _CACHE_L2ALLOC0_L2ALLOC_SHIFT      _CACHE_L2ALLOC0_Q0CNT_SHIFT  
  #define  CACHE_L2ALLOC0_L2ALLOC_DEFAULT     CACHE_L2ALLOC0_Q0CNT_DEFAULT
  #define  CACHE_L2ALLOC0_L2ALLOC_OF(x)       CACHE_L2ALLOC0_Q0CNT_OF(x)  

  #define  CACHE_L2ALLOC0_OF(x)            _VALUEOF(x)

  #define CACHE_L2ALLOC0_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,L2ALLOC0,Q0CNT) \
  )

  #define CACHE_L2ALLOC0_RMK(q0cnt)(Uint32)( \
     _PER_FMK(CACHE,L2ALLOC0,Q0CNT,q0cnt) \
  )

  #define _CACHE_L2ALLOC0_FGET(FIELD)\
    _PER_FGET(_CACHE_L2ALLOC0_ADDR,CACHE,L2ALLOC0,##FIELD)

  #define _CACHE_L2ALLOC0_FSET(FIELD,field)\
    _PER_FSET(_CACHE_L2ALLOC0_ADDR,CACHE,L2ALLOC0,##FIELD,field)

  #define _CACHE_L2ALLOC0_FSETS(FIELD,SYM)\
    _PER_FSETS(_CACHE_L2ALLOC0_ADDR,CACHE,L2ALLOC0,##FIELD,##SYM)

#endif

/******************************************************************************\
* _____________________
* |                   |
* |  L 2 A L L O C 1  |
* |___________________|
*
* L2ALLOC1 - L2 allocation register 1 (1)
*
* Fields:
* (rw) Q1CNT (2)
*
* (1) only supported for C6400
* (2) Rename bit filed based on spru610
*
\******************************************************************************/
#if (L2CACHE_SUPPORT && C64_SUPPORT)
  #define _CACHE_L2ALLOC1_ADDR             0x01842004u

  #define _CACHE_L2ALLOC1_Q1CNT_MASK       0x00000007u
  #define _CACHE_L2ALLOC1_Q1CNT_SHIFT      0x00000000u
  #define  CACHE_L2ALLOC1_Q1CNT_DEFAULT    0x00000002u
  #define  CACHE_L2ALLOC1_Q1CNT_OF(x)      _VALUEOF(x)

  #define _CACHE_L2ALLOC1_L2ALLOC_MASK     _CACHE_L2ALLOC1_Q1CNT_MASK   
  #define _CACHE_L2ALLOC1_L2ALLOC_SHIFT    _CACHE_L2ALLOC1_Q1CNT_SHIFT  
  #define  CACHE_L2ALLOC1_L2ALLOC_DEFAULT   CACHE_L2ALLOC1_Q1CNT_DEFAULT
  #define  CACHE_L2ALLOC1_L2ALLOC_OF(x)     CACHE_L2ALLOC1_Q1CNT_OF(x)  

  #define  CACHE_L2ALLOC1_OF(x)            _VALUEOF(x)

  #define CACHE_L2ALLOC1_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,L2ALLOC1,Q1CNT) \
  )

  #define CACHE_L2ALLOC1_RMK(q1cnt) (Uint32)( \
     _PER_FMK(CACHE,L2ALLOC1,Q1CNT,q1cnt) \
  )

  #define _CACHE_L2ALLOC1_FGET(FIELD)\
    _PER_FGET(_CACHE_L2ALLOC1_ADDR,CACHE,L2ALLOC1,##FIELD)

  #define _CACHE_L2ALLOC1_FSET(FIELD,field)\
    _PER_FSET(_CACHE_L2ALLOC1_ADDR,CACHE,L2ALLOC1,##FIELD,field)

  #define _CACHE_L2ALLOC1_FSETS(FIELD,SYM)\
    _PER_FSETS(_CACHE_L2ALLOC1_ADDR,CACHE,L2ALLOC1,##FIELD,##SYM)

#endif

/******************************************************************************\
* _____________________
* |                   |
* |  L 2 A L L O C 2  |
* |___________________|
*
* L2ALLOC2 - L2 allocation register 2 (1)
*
* Fields:
* (rw) Q2CNT (2)
*
* (1) only supported for C6400
* (2) Rename bit filed based on spru610
*
\******************************************************************************/
#if (L2CACHE_SUPPORT && C64_SUPPORT)
  #define _CACHE_L2ALLOC2_ADDR               0x01842008u

  #define _CACHE_L2ALLOC2_Q2CNT_MASK       0x00000007u
  #define _CACHE_L2ALLOC2_Q2CNT_SHIFT      0x00000000u
  #define  CACHE_L2ALLOC2_Q2CNT_DEFAULT    0x00000002u
  #define  CACHE_L2ALLOC2_Q2CNT_OF(x)      _VALUEOF(x)

  #define _CACHE_L2ALLOC2_L2ALLOC_MASK       _CACHE_L2ALLOC2_Q2CNT_MASK   
  #define _CACHE_L2ALLOC2_L2ALLOC_SHIFT      _CACHE_L2ALLOC2_Q2CNT_SHIFT  
  #define  CACHE_L2ALLOC2_L2ALLOC_DEFAULT     CACHE_L2ALLOC2_Q2CNT_DEFAULT
  #define  CACHE_L2ALLOC2_L2ALLOC_OF(x)       CACHE_L2ALLOC2_Q2CNT_OF(x)  

  #define  CACHE_L2ALLOC2_OF(x)            _VALUEOF(x)

  #define CACHE_L2ALLOC2_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,L2ALLOC2,Q2CNT) \
  )

  #define CACHE_L2ALLOC2_RMK(q2cnt) (Uint32)( \
     _PER_FMK(CACHE,L2ALLOC2,Q2CNT,q2cnt) \
  )

  #define _CACHE_L2ALLOC2_FGET(FIELD)\
    _PER_FGET(_CACHE_L2ALLOC2_ADDR,CACHE,L2ALLOC2,##FIELD)

  #define _CACHE_L2ALLOC2_FSET(FIELD,field)\
    _PER_FSET(_CACHE_L2ALLOC2_ADDR,CACHE,L2ALLOC2,##FIELD,field)

  #define _CACHE_L2ALLOC2_FSETS(FIELD,SYM)\
    _PER_FSETS(_CACHE_L2ALLOC2_ADDR,CACHE,L2ALLOC2,##FIELD,##SYM)

#endif

/******************************************************************************\
* _____________________
* |                   |
* |  L 2 A L L O C 3  |
* |___________________|
*
* L2ALLOC3 - L2 allocation register 3 (1)
*
* Fields:
* (rw) Q2CNT (2)
*
* (1) only supported for C6400
* (2) Rename bit filed based on spru610
*
\******************************************************************************/
#if (L2CACHE_SUPPORT && C64_SUPPORT)
  #define _CACHE_L2ALLOC3_ADDR               0x0184200Cu

  #define _CACHE_L2ALLOC3_Q3CNT_MASK       0x00000007u
  #define _CACHE_L2ALLOC3_Q3CNT_SHIFT      0x00000000u
  #define  CACHE_L2ALLOC3_Q3CNT_DEFAULT    0x00000002u
  #define  CACHE_L2ALLOC3_Q3CNT_OF(x)      _VALUEOF(x)

  #define _CACHE_L2ALLOC3_L2ALLOC_MASK       _CACHE_L2ALLOC3_Q3CNT_MASK    
  #define _CACHE_L2ALLOC3_L2ALLOC_SHIFT      _CACHE_L2ALLOC3_Q3CNT_SHIFT   
  #define  CACHE_L2ALLOC3_L2ALLOC_DEFAULT     CACHE_L2ALLOC3_Q3CNT_DEFAULT 
  #define  CACHE_L2ALLOC3_L2ALLOC_OF(x)       CACHE_L2ALLOC3_Q3CNT_OF(x)   

  #define  CACHE_L2ALLOC3_OF(x)            _VALUEOF(x)

  #define CACHE_L2ALLOC3_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,L2ALLOC3,Q3CNT) \
  )

  #define CACHE_L2ALLOC3_RMK(q3cnt) (Uint32)( \
     _PER_FMK(CACHE,L2ALLOC3,Q3CNT,q3cnt) \
  )

  #define _CACHE_L2ALLOC3_FGET(FIELD)\
    _PER_FGET(_CACHE_L2ALLOC3_ADDR,CACHE,L2ALLOC3,##FIELD)

  #define _CACHE_L2ALLOC3_FSET(FIELD,field)\
    _PER_FSET(_CACHE_L2ALLOC3_ADDR,CACHE,L2ALLOC3,##FIELD,field)

  #define _CACHE_L2ALLOC3_FSETS(FIELD,SYM)\
    _PER_FSETS(_CACHE_L2ALLOC3_ADDR,CACHE,L2ALLOC3,##FIELD,##SYM)

#endif

/******************************************************************************\
* _____________________
* |                   |
* |  M A R            |
* |___________________|
*
* MAR0   - memory attribute register 0 (1)
* MAR1   - memory attribute register 1 (1)
* MAR2   - memory attribute register 2 (1)
* ...    - ...
* MARn   - memory attribute register n (2)
*
* Fields:
* (rw) NR (3)
* (rw) NW (3)
* (rw) PE (3)
* (rw) CE (4)
*
* (1) register values are read only for C6400 
* (2) n = 15 for C6211/C6711, n = 255 for C6400
* (3) only supported for C6400
* (4) only supported for C6211/C6711
* (5) MARn range for C6211/C6711 are from MAR0 ~ MAR15,
*     MARn range for C6400 are:
*     MAR0   ~ MAR2   : register values read only
*     MAR48  ~ MAR51  : McBSP0 
*     MAR52  ~ MAR55  : McBSP1 
*     MAR56  ~ MAR59  : McBSP2 
*     MAR60  ~ MAR63  : UTOPIAII 
*     MAR64  ~ MAR79  : HPI/PCI 
*     MAR96  ~ MAR111 : EMIFB (1)
*     MAR128 ~ MAR191 : EMIFA 
*
* (1) only in C6414, C6415, C6416 variants
\******************************************************************************/
#if (L2CACHE_SUPPORT && !C64_SUPPORT)
  #define _CACHE_MAR0_ADDR             _CACHE_MAR128_ADDR 
  #define _CACHE_MAR1_ADDR             _CACHE_MAR129_ADDR 
  #define _CACHE_MAR2_ADDR             _CACHE_MAR130_ADDR 
  #define _CACHE_MAR3_ADDR             _CACHE_MAR131_ADDR 
  #define _CACHE_MAR4_ADDR             _CACHE_MAR144_ADDR 
  #define _CACHE_MAR5_ADDR             _CACHE_MAR145_ADDR 
  #define _CACHE_MAR6_ADDR             _CACHE_MAR146_ADDR 
  #define _CACHE_MAR7_ADDR             _CACHE_MAR147_ADDR 
  #define _CACHE_MAR8_ADDR             _CACHE_MAR160_ADDR 
  #define _CACHE_MAR9_ADDR             _CACHE_MAR161_ADDR 
  #define _CACHE_MAR10_ADDR            _CACHE_MAR162_ADDR
  #define _CACHE_MAR11_ADDR            _CACHE_MAR163_ADDR
  #define _CACHE_MAR12_ADDR            _CACHE_MAR176_ADDR
  #define _CACHE_MAR13_ADDR            _CACHE_MAR177_ADDR
  #define _CACHE_MAR14_ADDR            _CACHE_MAR178_ADDR
  #define _CACHE_MAR15_ADDR            _CACHE_MAR179_ADDR

  #define _CACHE_MAR128_ADDR            0x01848200u
  #define _CACHE_MAR129_ADDR            0x01848204u
  #define _CACHE_MAR130_ADDR            0x01848208u
  #define _CACHE_MAR131_ADDR            0x0184820Cu
  #define _CACHE_MAR144_ADDR            0x01848240u
  #define _CACHE_MAR145_ADDR            0x01848244u
  #define _CACHE_MAR146_ADDR            0x01848248u
  #define _CACHE_MAR147_ADDR            0x0184824Cu
  #define _CACHE_MAR160_ADDR            0x01848280u
  #define _CACHE_MAR161_ADDR            0x01848284u
  #define _CACHE_MAR162_ADDR            0x01848288u
  #define _CACHE_MAR163_ADDR            0x0184828Cu
  #define _CACHE_MAR176_ADDR            0x018482C0u
  #define _CACHE_MAR177_ADDR            0x018482C4u
  #define _CACHE_MAR178_ADDR            0x018482C8u
  #define _CACHE_MAR179_ADDR            0x018482CCu

  #define _CACHE_MAR_CE_MASK           0x00000001u
  #define _CACHE_MAR_CE_SHIFT          0x00000000u
  #define  CACHE_MAR_CE_DEFAULT        0x00000000u
  #define  CACHE_MAR_CE_OF(x)          _VALUEOF(x)
  #define  CACHE_MAR_CE_DISABLE        0x00000000u
  #define  CACHE_MAR_CE_ENABLE         0x00000001u

  #define  CACHE_MAR_OF(x)             _VALUEOF(x)

  #define CACHE_MAR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,MAR,CE) \
  )

  #define CACHE_MAR_RMK(ce) (Uint32)( \
     _PER_FMK(CACHE,MAR,CE,ce) \
  )

  #define _CACHE_MAR_FGET(N,FIELD)\
    _PER_FGET(_CACHE_MAR##N##_ADDR,CACHE,MAR,##FIELD)

  #define _CACHE_MAR_FSET(N,FIELD,field)\
    _PER_FSET(_CACHE_MAR##N##_ADDR,CACHE,MAR,##FIELD,field)

  #define _CACHE_MAR_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_CACHE_MAR##N##_ADDR,CACHE,MAR,##FIELD,##SYM)

  #define _CACHE_MAR0_FGET(FIELD)  _CACHE_MAR_FGET(128,##FIELD)
  #define _CACHE_MAR1_FGET(FIELD)  _CACHE_MAR_FGET(129,##FIELD)
  #define _CACHE_MAR2_FGET(FIELD)  _CACHE_MAR_FGET(130,##FIELD)
  #define _CACHE_MAR3_FGET(FIELD)  _CACHE_MAR_FGET(131,##FIELD)
  #define _CACHE_MAR4_FGET(FIELD)  _CACHE_MAR_FGET(144,##FIELD)
  #define _CACHE_MAR5_FGET(FIELD)  _CACHE_MAR_FGET(145,##FIELD)
  #define _CACHE_MAR6_FGET(FIELD)  _CACHE_MAR_FGET(146,##FIELD)
  #define _CACHE_MAR7_FGET(FIELD)  _CACHE_MAR_FGET(147,##FIELD)
  #define _CACHE_MAR8_FGET(FIELD)  _CACHE_MAR_FGET(160,##FIELD)
  #define _CACHE_MAR9_FGET(FIELD)  _CACHE_MAR_FGET(161,##FIELD)
  #define _CACHE_MAR10_FGET(FIELD) _CACHE_MAR_FGET(162,##FIELD)
  #define _CACHE_MAR11_FGET(FIELD) _CACHE_MAR_FGET(163,##FIELD)
  #define _CACHE_MAR12_FGET(FIELD) _CACHE_MAR_FGET(176,##FIELD)
  #define _CACHE_MAR13_FGET(FIELD) _CACHE_MAR_FGET(177,##FIELD)
  #define _CACHE_MAR14_FGET(FIELD) _CACHE_MAR_FGET(178,##FIELD)
  #define _CACHE_MAR15_FGET(FIELD) _CACHE_MAR_FGET(179,##FIELD)

  #define _CACHE_MAR0_FSET(FIELD,f)  _CACHE_MAR_FSET(128,##FIELD,f)
  #define _CACHE_MAR1_FSET(FIELD,f)  _CACHE_MAR_FSET(129,##FIELD,f)
  #define _CACHE_MAR2_FSET(FIELD,f)  _CACHE_MAR_FSET(130,##FIELD,f)
  #define _CACHE_MAR3_FSET(FIELD,f)  _CACHE_MAR_FSET(131,##FIELD,f)
  #define _CACHE_MAR4_FSET(FIELD,f)  _CACHE_MAR_FSET(144,##FIELD,f)
  #define _CACHE_MAR5_FSET(FIELD,f)  _CACHE_MAR_FSET(145,##FIELD,f)
  #define _CACHE_MAR6_FSET(FIELD,f)  _CACHE_MAR_FSET(146,##FIELD,f)
  #define _CACHE_MAR7_FSET(FIELD,f)  _CACHE_MAR_FSET(147,##FIELD,f)
  #define _CACHE_MAR8_FSET(FIELD,f)  _CACHE_MAR_FSET(160,##FIELD,f)
  #define _CACHE_MAR9_FSET(FIELD,f)  _CACHE_MAR_FSET(161,##FIELD,f)
  #define _CACHE_MAR10_FSET(FIELD,f) _CACHE_MAR_FSET(162,##FIELD,f)
  #define _CACHE_MAR11_FSET(FIELD,f) _CACHE_MAR_FSET(163,##FIELD,f)
  #define _CACHE_MAR12_FSET(FIELD,f) _CACHE_MAR_FSET(176,##FIELD,f)
  #define _CACHE_MAR13_FSET(FIELD,f) _CACHE_MAR_FSET(177,##FIELD,f)
  #define _CACHE_MAR14_FSET(FIELD,f) _CACHE_MAR_FSET(178,##FIELD,f)
  #define _CACHE_MAR15_FSET(FIELD,f) _CACHE_MAR_FSET(179,##FIELD,f)

  #define _CACHE_MAR0_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(128,##FIELD,##SYM)
  #define _CACHE_MAR1_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(129,##FIELD,##SYM)
  #define _CACHE_MAR2_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(130,##FIELD,##SYM)
  #define _CACHE_MAR3_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(131,##FIELD,##SYM)
  #define _CACHE_MAR4_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(144,##FIELD,##SYM)
  #define _CACHE_MAR5_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(145,##FIELD,##SYM)
  #define _CACHE_MAR6_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(146,##FIELD,##SYM)
  #define _CACHE_MAR7_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(147,##FIELD,##SYM)
  #define _CACHE_MAR8_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(160,##FIELD,##SYM)
  #define _CACHE_MAR9_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(161,##FIELD,##SYM)
  #define _CACHE_MAR10_FSETS(FIELD,SYM) _CACHE_MAR_FSETS(162,##FIELD,##SYM)
  #define _CACHE_MAR11_FSETS(FIELD,SYM) _CACHE_MAR_FSETS(163,##FIELD,##SYM)
  #define _CACHE_MAR12_FSETS(FIELD,SYM) _CACHE_MAR_FSETS(176,##FIELD,##SYM)
  #define _CACHE_MAR13_FSETS(FIELD,SYM) _CACHE_MAR_FSETS(177,##FIELD,##SYM)
  #define _CACHE_MAR14_FSETS(FIELD,SYM) _CACHE_MAR_FSETS(178,##FIELD,##SYM)
  #define _CACHE_MAR15_FSETS(FIELD,SYM) _CACHE_MAR_FSETS(179,##FIELD,##SYM)

  #define _CACHE_MAR128_FGET(FIELD)  _CACHE_MAR_FGET(128,##FIELD)
  #define _CACHE_MAR129_FGET(FIELD)  _CACHE_MAR_FGET(129,##FIELD)
  #define _CACHE_MAR130_FGET(FIELD)  _CACHE_MAR_FGET(130,##FIELD)
  #define _CACHE_MAR131_FGET(FIELD)  _CACHE_MAR_FGET(131,##FIELD)
  #define _CACHE_MAR144_FGET(FIELD)  _CACHE_MAR_FGET(144,##FIELD)
  #define _CACHE_MAR145_FGET(FIELD)  _CACHE_MAR_FGET(145,##FIELD)
  #define _CACHE_MAR146_FGET(FIELD)  _CACHE_MAR_FGET(146,##FIELD)
  #define _CACHE_MAR147_FGET(FIELD)  _CACHE_MAR_FGET(147,##FIELD)
  #define _CACHE_MAR160_FGET(FIELD)  _CACHE_MAR_FGET(160,##FIELD)
  #define _CACHE_MAR161_FGET(FIELD)  _CACHE_MAR_FGET(161,##FIELD)
  #define _CACHE_MAR162_FGET(FIELD)  _CACHE_MAR_FGET(162,##FIELD)
  #define _CACHE_MAR163_FGET(FIELD)  _CACHE_MAR_FGET(163,##FIELD)
  #define _CACHE_MAR176_FGET(FIELD)  _CACHE_MAR_FGET(176,##FIELD)
  #define _CACHE_MAR177_FGET(FIELD)  _CACHE_MAR_FGET(177,##FIELD)
  #define _CACHE_MAR178_FGET(FIELD)  _CACHE_MAR_FGET(178,##FIELD)
  #define _CACHE_MAR179_FGET(FIELD)  _CACHE_MAR_FGET(179,##FIELD)

  #define _CACHE_MAR128_FSET(FIELD,f)  _CACHE_MAR_FSET(128,##FIELD,f)
  #define _CACHE_MAR129_FSET(FIELD,f)  _CACHE_MAR_FSET(129,##FIELD,f)
  #define _CACHE_MAR130_FSET(FIELD,f)  _CACHE_MAR_FSET(130,##FIELD,f)
  #define _CACHE_MAR131_FSET(FIELD,f)  _CACHE_MAR_FSET(131,##FIELD,f)
  #define _CACHE_MAR144_FSET(FIELD,f)  _CACHE_MAR_FSET(144,##FIELD,f)
  #define _CACHE_MAR145_FSET(FIELD,f)  _CACHE_MAR_FSET(145,##FIELD,f)
  #define _CACHE_MAR146_FSET(FIELD,f)  _CACHE_MAR_FSET(146,##FIELD,f)
  #define _CACHE_MAR147_FSET(FIELD,f)  _CACHE_MAR_FSET(147,##FIELD,f)
  #define _CACHE_MAR160_FSET(FIELD,f)  _CACHE_MAR_FSET(160,##FIELD,f)
  #define _CACHE_MAR161_FSET(FIELD,f)  _CACHE_MAR_FSET(161,##FIELD,f)
  #define _CACHE_MAR162_FSET(FIELD,f)  _CACHE_MAR_FSET(162,##FIELD,f)
  #define _CACHE_MAR163_FSET(FIELD,f)  _CACHE_MAR_FSET(163,##FIELD,f)
  #define _CACHE_MAR176_FSET(FIELD,f)  _CACHE_MAR_FSET(176,##FIELD,f)
  #define _CACHE_MAR177_FSET(FIELD,f)  _CACHE_MAR_FSET(177,##FIELD,f)
  #define _CACHE_MAR178_FSET(FIELD,f)  _CACHE_MAR_FSET(178,##FIELD,f)
  #define _CACHE_MAR179_FSET(FIELD,f)  _CACHE_MAR_FSET(179,##FIELD,f)

  #define _CACHE_MAR128_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(128,##FIELD,##SYM)
  #define _CACHE_MAR129_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(129,##FIELD,##SYM)
  #define _CACHE_MAR130_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(130,##FIELD,##SYM)
  #define _CACHE_MAR131_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(131,##FIELD,##SYM)
  #define _CACHE_MAR144_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(144,##FIELD,##SYM)
  #define _CACHE_MAR145_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(145,##FIELD,##SYM)
  #define _CACHE_MAR146_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(146,##FIELD,##SYM)
  #define _CACHE_MAR147_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(147,##FIELD,##SYM)
  #define _CACHE_MAR160_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(160,##FIELD,##SYM)
  #define _CACHE_MAR161_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(161,##FIELD,##SYM)
  #define _CACHE_MAR162_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(162,##FIELD,##SYM)
  #define _CACHE_MAR163_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(163,##FIELD,##SYM)
  #define _CACHE_MAR176_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(176,##FIELD,##SYM)
  #define _CACHE_MAR177_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(177,##FIELD,##SYM)
  #define _CACHE_MAR178_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(178,##FIELD,##SYM)
  #define _CACHE_MAR179_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(179,##FIELD,##SYM)

#else 

  /* MAR96 to MAR111 are associated with EMIFB memory space. This is supported only in  
   * the C6414, C6415 and C6416 chips                                                  */
    
  #if (CHIP_6414 | CHIP_6415 | CHIP_6416)
    #define _CACHE_MAR96_ADDR            0x01848180u
    #define _CACHE_MAR97_ADDR            0x01848184u
    #define _CACHE_MAR98_ADDR            0x01848188u
    #define _CACHE_MAR99_ADDR            0x0184818Cu
    #define _CACHE_MAR100_ADDR           0x01848190u
    #define _CACHE_MAR101_ADDR           0x01848194u
    #define _CACHE_MAR102_ADDR           0x01848198u
    #define _CACHE_MAR103_ADDR           0x0184819Cu
    #define _CACHE_MAR104_ADDR           0x018481A0u
    #define _CACHE_MAR105_ADDR           0x018481A4u
    #define _CACHE_MAR106_ADDR           0x018481A8u
    #define _CACHE_MAR107_ADDR           0x018481ACu
    #define _CACHE_MAR108_ADDR           0x018481B0u
    #define _CACHE_MAR109_ADDR           0x018481B4u
    #define _CACHE_MAR110_ADDR           0x018481B8u
    #define _CACHE_MAR111_ADDR           0x018481BCu
  #endif

  #define _CACHE_MAR128_ADDR           0x01848200u
  #define _CACHE_MAR129_ADDR           0x01848204u
  #define _CACHE_MAR130_ADDR           0x01848208u
  #define _CACHE_MAR131_ADDR           0x0184820Cu
  #define _CACHE_MAR132_ADDR           0x01848210u
  #define _CACHE_MAR133_ADDR           0x01848214u
  #define _CACHE_MAR134_ADDR           0x01848218u
  #define _CACHE_MAR135_ADDR           0x0184821Cu
  #define _CACHE_MAR136_ADDR           0x01848220u
  #define _CACHE_MAR137_ADDR           0x01848224u
  #define _CACHE_MAR138_ADDR           0x01848228u
  #define _CACHE_MAR139_ADDR           0x0184822Cu
  #define _CACHE_MAR140_ADDR           0x01848230u
  #define _CACHE_MAR141_ADDR           0x01848234u
  #define _CACHE_MAR142_ADDR           0x01848238u
  #define _CACHE_MAR143_ADDR           0x0184823Cu
  #define _CACHE_MAR144_ADDR           0x01848240u
  #define _CACHE_MAR145_ADDR           0x01848244u
  #define _CACHE_MAR146_ADDR           0x01848248u
  #define _CACHE_MAR147_ADDR           0x0184824Cu
  #define _CACHE_MAR148_ADDR           0x01848250u
  #define _CACHE_MAR149_ADDR           0x01848254u
  #define _CACHE_MAR150_ADDR           0x01848258u
  #define _CACHE_MAR151_ADDR           0x0184825Cu
  #define _CACHE_MAR152_ADDR           0x01848260u
  #define _CACHE_MAR153_ADDR           0x01848264u
  #define _CACHE_MAR154_ADDR           0x01848268u
  #define _CACHE_MAR155_ADDR           0x0184826Cu
  #define _CACHE_MAR156_ADDR           0x01848270u
  #define _CACHE_MAR157_ADDR           0x01848274u
  #define _CACHE_MAR158_ADDR           0x01848278u
  #define _CACHE_MAR159_ADDR           0x0184827Cu
  #define _CACHE_MAR160_ADDR           0x01848280u
  #define _CACHE_MAR161_ADDR           0x01848284u
  #define _CACHE_MAR162_ADDR           0x01848288u
  #define _CACHE_MAR163_ADDR           0x0184828Cu
  #define _CACHE_MAR164_ADDR           0x01848290u
  #define _CACHE_MAR165_ADDR           0x01848294u
  #define _CACHE_MAR166_ADDR           0x01848298u
  #define _CACHE_MAR167_ADDR           0x0184829Cu
  #define _CACHE_MAR168_ADDR           0x018482A0u
  #define _CACHE_MAR169_ADDR           0x018482A4u
  #define _CACHE_MAR170_ADDR           0x018482A8u
  #define _CACHE_MAR171_ADDR           0x018482ACu
  #define _CACHE_MAR172_ADDR           0x018482B0u
  #define _CACHE_MAR173_ADDR           0x018482B4u
  #define _CACHE_MAR174_ADDR           0x018482B8u
  #define _CACHE_MAR175_ADDR           0x018482BCu
  #define _CACHE_MAR176_ADDR           0x018482C0u
  #define _CACHE_MAR177_ADDR           0x018482C4u
  #define _CACHE_MAR178_ADDR           0x018482C8u
  #define _CACHE_MAR179_ADDR           0x018482CCu
  #define _CACHE_MAR180_ADDR           0x018482D0u
  #define _CACHE_MAR181_ADDR           0x018482D4u
  #define _CACHE_MAR182_ADDR           0x018482D8u
  #define _CACHE_MAR183_ADDR           0x018482DCu
  #define _CACHE_MAR184_ADDR           0x018482E0u
  #define _CACHE_MAR185_ADDR           0x018482E4u
  #define _CACHE_MAR186_ADDR           0x018482E8u
  #define _CACHE_MAR187_ADDR           0x018482ECu
  #define _CACHE_MAR188_ADDR           0x018482F0u
  #define _CACHE_MAR189_ADDR           0x018482F4u
  #define _CACHE_MAR190_ADDR           0x018482F8u
  #define _CACHE_MAR191_ADDR           0x018482FCu

  #define _CACHE_MAR_CE_MASK           0x00000001u
  #define _CACHE_MAR_CE_SHIFT          0x00000000u
  #define  CACHE_MAR_CE_DEFAULT        0x00000000u
  #define  CACHE_MAR_CE_OF(x)          _VALUEOF(x)
  #define  CACHE_MAR_CE_DISABLE        0x00000000u
  #define  CACHE_MAR_CE_ENABLE         0x00000001u

  #define  CACHE_MAR_OF(x)             _VALUEOF(x)

  #define CACHE_MAR_DEFAULT (Uint32)( \
    _PER_FDEFAULT(CACHE,MAR,CE) \
  )

  #define CACHE_MAR_RMK(ce) (Uint32)( \
    _PER_FMK(CACHE,MAR,CE,ce) \
  )

  #define _CACHE_MAR_FGET(N,FIELD)\
    _PER_FGET(_CACHE_MAR##N##_ADDR,CACHE,MAR,##FIELD)

  #define _CACHE_MAR_FSET(N,FIELD,field)\
    _PER_FSET(_CACHE_MAR##N##_ADDR,CACHE,MAR,##FIELD,field)

  #define _CACHE_MAR_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_CACHE_MAR##N##_ADDR,CACHE,MAR,##FIELD,##SYM)

  #if (CHIP_6414 | CHIP_6415 | CHIP_6416)
    #define _CACHE_MAR96_FGET(FIELD)   _CACHE_MAR_FGET(96,##FIELD)
    #define _CACHE_MAR97_FGET(FIELD)   _CACHE_MAR_FGET(97,##FIELD)
    #define _CACHE_MAR98_FGET(FIELD)   _CACHE_MAR_FGET(98,##FIELD)
    #define _CACHE_MAR99_FGET(FIELD)   _CACHE_MAR_FGET(99,##FIELD)
    #define _CACHE_MAR100_FGET(FIELD)  _CACHE_MAR_FGET(100,##FIELD)
    #define _CACHE_MAR101_FGET(FIELD)  _CACHE_MAR_FGET(101,##FIELD)
    #define _CACHE_MAR102_FGET(FIELD)  _CACHE_MAR_FGET(102,##FIELD)
    #define _CACHE_MAR103_FGET(FIELD)  _CACHE_MAR_FGET(103,##FIELD)
    #define _CACHE_MAR104_FGET(FIELD)  _CACHE_MAR_FGET(104,##FIELD)
    #define _CACHE_MAR105_FGET(FIELD)  _CACHE_MAR_FGET(105,##FIELD)
    #define _CACHE_MAR106_FGET(FIELD)  _CACHE_MAR_FGET(106,##FIELD)
    #define _CACHE_MAR107_FGET(FIELD)  _CACHE_MAR_FGET(107,##FIELD)
    #define _CACHE_MAR108_FGET(FIELD)  _CACHE_MAR_FGET(108,##FIELD)
    #define _CACHE_MAR109_FGET(FIELD)  _CACHE_MAR_FGET(109,##FIELD)
    #define _CACHE_MAR110_FGET(FIELD)  _CACHE_MAR_FGET(110,##FIELD)
    #define _CACHE_MAR111_FGET(FIELD)  _CACHE_MAR_FGET(111,##FIELD)
  #endif

  #define _CACHE_MAR128_FGET(FIELD)  _CACHE_MAR_FGET(128,##FIELD)
  #define _CACHE_MAR129_FGET(FIELD)  _CACHE_MAR_FGET(129,##FIELD)
  #define _CACHE_MAR130_FGET(FIELD)  _CACHE_MAR_FGET(130,##FIELD)
  #define _CACHE_MAR131_FGET(FIELD)  _CACHE_MAR_FGET(131,##FIELD)
  #define _CACHE_MAR132_FGET(FIELD)  _CACHE_MAR_FGET(132,##FIELD)
  #define _CACHE_MAR133_FGET(FIELD)  _CACHE_MAR_FGET(133,##FIELD)
  #define _CACHE_MAR134_FGET(FIELD)  _CACHE_MAR_FGET(134,##FIELD)
  #define _CACHE_MAR135_FGET(FIELD)  _CACHE_MAR_FGET(135,##FIELD)
  #define _CACHE_MAR136_FGET(FIELD)  _CACHE_MAR_FGET(136,##FIELD)
  #define _CACHE_MAR137_FGET(FIELD)  _CACHE_MAR_FGET(137,##FIELD)
  #define _CACHE_MAR138_FGET(FIELD)  _CACHE_MAR_FGET(138,##FIELD)
  #define _CACHE_MAR139_FGET(FIELD)  _CACHE_MAR_FGET(139,##FIELD)
  #define _CACHE_MAR140_FGET(FIELD)  _CACHE_MAR_FGET(140,##FIELD)
  #define _CACHE_MAR141_FGET(FIELD)  _CACHE_MAR_FGET(141,##FIELD)
  #define _CACHE_MAR142_FGET(FIELD)  _CACHE_MAR_FGET(142,##FIELD)
  #define _CACHE_MAR143_FGET(FIELD)  _CACHE_MAR_FGET(143,##FIELD)
  #define _CACHE_MAR144_FGET(FIELD)  _CACHE_MAR_FGET(144,##FIELD)
  #define _CACHE_MAR145_FGET(FIELD)  _CACHE_MAR_FGET(145,##FIELD)
  #define _CACHE_MAR146_FGET(FIELD)  _CACHE_MAR_FGET(146,##FIELD)
  #define _CACHE_MAR147_FGET(FIELD)  _CACHE_MAR_FGET(147,##FIELD)
  #define _CACHE_MAR148_FGET(FIELD)  _CACHE_MAR_FGET(148,##FIELD)
  #define _CACHE_MAR149_FGET(FIELD)  _CACHE_MAR_FGET(149,##FIELD)
  #define _CACHE_MAR150_FGET(FIELD)  _CACHE_MAR_FGET(150,##FIELD)
  #define _CACHE_MAR151_FGET(FIELD)  _CACHE_MAR_FGET(151,##FIELD)
  #define _CACHE_MAR152_FGET(FIELD)  _CACHE_MAR_FGET(152,##FIELD)
  #define _CACHE_MAR153_FGET(FIELD)  _CACHE_MAR_FGET(153,##FIELD)
  #define _CACHE_MAR154_FGET(FIELD)  _CACHE_MAR_FGET(154,##FIELD)
  #define _CACHE_MAR155_FGET(FIELD)  _CACHE_MAR_FGET(155,##FIELD)
  #define _CACHE_MAR156_FGET(FIELD)  _CACHE_MAR_FGET(156,##FIELD)
  #define _CACHE_MAR157_FGET(FIELD)  _CACHE_MAR_FGET(157,##FIELD)
  #define _CACHE_MAR158_FGET(FIELD)  _CACHE_MAR_FGET(158,##FIELD)
  #define _CACHE_MAR159_FGET(FIELD)  _CACHE_MAR_FGET(159,##FIELD)
  #define _CACHE_MAR160_FGET(FIELD)  _CACHE_MAR_FGET(160,##FIELD)
  #define _CACHE_MAR161_FGET(FIELD)  _CACHE_MAR_FGET(161,##FIELD)
  #define _CACHE_MAR162_FGET(FIELD)  _CACHE_MAR_FGET(162,##FIELD)
  #define _CACHE_MAR163_FGET(FIELD)  _CACHE_MAR_FGET(163,##FIELD)
  #define _CACHE_MAR164_FGET(FIELD)  _CACHE_MAR_FGET(164,##FIELD)
  #define _CACHE_MAR165_FGET(FIELD)  _CACHE_MAR_FGET(165,##FIELD)
  #define _CACHE_MAR166_FGET(FIELD)  _CACHE_MAR_FGET(166,##FIELD)
  #define _CACHE_MAR167_FGET(FIELD)  _CACHE_MAR_FGET(167,##FIELD)
  #define _CACHE_MAR168_FGET(FIELD)  _CACHE_MAR_FGET(168,##FIELD)
  #define _CACHE_MAR169_FGET(FIELD)  _CACHE_MAR_FGET(169,##FIELD)
  #define _CACHE_MAR170_FGET(FIELD)  _CACHE_MAR_FGET(170,##FIELD)
  #define _CACHE_MAR171_FGET(FIELD)  _CACHE_MAR_FGET(171,##FIELD)
  #define _CACHE_MAR172_FGET(FIELD)  _CACHE_MAR_FGET(172,##FIELD)
  #define _CACHE_MAR173_FGET(FIELD)  _CACHE_MAR_FGET(173,##FIELD)
  #define _CACHE_MAR174_FGET(FIELD)  _CACHE_MAR_FGET(174,##FIELD)
  #define _CACHE_MAR175_FGET(FIELD)  _CACHE_MAR_FGET(175,##FIELD)
  #define _CACHE_MAR176_FGET(FIELD)  _CACHE_MAR_FGET(176,##FIELD)
  #define _CACHE_MAR177_FGET(FIELD)  _CACHE_MAR_FGET(177,##FIELD)
  #define _CACHE_MAR178_FGET(FIELD)  _CACHE_MAR_FGET(178,##FIELD)
  #define _CACHE_MAR179_FGET(FIELD)  _CACHE_MAR_FGET(179,##FIELD)
  #define _CACHE_MAR180_FGET(FIELD)  _CACHE_MAR_FGET(180,##FIELD)
  #define _CACHE_MAR181_FGET(FIELD)  _CACHE_MAR_FGET(181,##FIELD)
  #define _CACHE_MAR182_FGET(FIELD)  _CACHE_MAR_FGET(182,##FIELD)
  #define _CACHE_MAR183_FGET(FIELD)  _CACHE_MAR_FGET(183,##FIELD)
  #define _CACHE_MAR184_FGET(FIELD)  _CACHE_MAR_FGET(184,##FIELD)
  #define _CACHE_MAR185_FGET(FIELD)  _CACHE_MAR_FGET(185,##FIELD)
  #define _CACHE_MAR186_FGET(FIELD)  _CACHE_MAR_FGET(186,##FIELD)
  #define _CACHE_MAR187_FGET(FIELD)  _CACHE_MAR_FGET(187,##FIELD)
  #define _CACHE_MAR188_FGET(FIELD)  _CACHE_MAR_FGET(188,##FIELD)
  #define _CACHE_MAR189_FGET(FIELD)  _CACHE_MAR_FGET(189,##FIELD)
  #define _CACHE_MAR190_FGET(FIELD)  _CACHE_MAR_FGET(190,##FIELD)
  #define _CACHE_MAR191_FGET(FIELD)  _CACHE_MAR_FGET(191,##FIELD)

  #if (CHIP_6414 | CHIP_6415 | CHIP_6416)
    #define _CACHE_MAR96_FSET(FIELD,f)   _CACHE_MAR_FSET(96,##FIELD,f)
    #define _CACHE_MAR97_FSET(FIELD,f)   _CACHE_MAR_FSET(97,##FIELD,f)
    #define _CACHE_MAR98_FSET(FIELD,f)   _CACHE_MAR_FSET(98,##FIELD,f)
    #define _CACHE_MAR99_FSET(FIELD,f)   _CACHE_MAR_FSET(99,##FIELD,f)
    #define _CACHE_MAR100_FSET(FIELD,f)  _CACHE_MAR_FSET(100,##FIELD,f)
    #define _CACHE_MAR101_FSET(FIELD,f)  _CACHE_MAR_FSET(101,##FIELD,f)
    #define _CACHE_MAR102_FSET(FIELD,f)  _CACHE_MAR_FSET(102,##FIELD,f)
    #define _CACHE_MAR103_FSET(FIELD,f)  _CACHE_MAR_FSET(103,##FIELD,f)
    #define _CACHE_MAR104_FSET(FIELD,f)  _CACHE_MAR_FSET(104,##FIELD,f)
    #define _CACHE_MAR105_FSET(FIELD,f)  _CACHE_MAR_FSET(105,##FIELD,f)
    #define _CACHE_MAR106_FSET(FIELD,f)  _CACHE_MAR_FSET(106,##FIELD,f)
    #define _CACHE_MAR107_FSET(FIELD,f)  _CACHE_MAR_FSET(107,##FIELD,f)
    #define _CACHE_MAR108_FSET(FIELD,f)  _CACHE_MAR_FSET(108,##FIELD,f)
    #define _CACHE_MAR109_FSET(FIELD,f)  _CACHE_MAR_FSET(109,##FIELD,f)
    #define _CACHE_MAR110_FSET(FIELD,f)  _CACHE_MAR_FSET(110,##FIELD,f)
    #define _CACHE_MAR111_FSET(FIELD,f)  _CACHE_MAR_FSET(111,##FIELD,f)
  #endif

  #define _CACHE_MAR128_FSET(FIELD,f)  _CACHE_MAR_FSET(128,##FIELD,f)
  #define _CACHE_MAR129_FSET(FIELD,f)  _CACHE_MAR_FSET(129,##FIELD,f)
  #define _CACHE_MAR130_FSET(FIELD,f)  _CACHE_MAR_FSET(130,##FIELD,f)
  #define _CACHE_MAR131_FSET(FIELD,f)  _CACHE_MAR_FSET(131,##FIELD,f)
  #define _CACHE_MAR132_FSET(FIELD,f)  _CACHE_MAR_FSET(132,##FIELD,f)
  #define _CACHE_MAR133_FSET(FIELD,f)  _CACHE_MAR_FSET(133,##FIELD,f)
  #define _CACHE_MAR134_FSET(FIELD,f)  _CACHE_MAR_FSET(134,##FIELD,f)
  #define _CACHE_MAR135_FSET(FIELD,f)  _CACHE_MAR_FSET(135,##FIELD,f)
  #define _CACHE_MAR136_FSET(FIELD,f)  _CACHE_MAR_FSET(136,##FIELD,f)
  #define _CACHE_MAR137_FSET(FIELD,f)  _CACHE_MAR_FSET(137,##FIELD,f)
  #define _CACHE_MAR138_FSET(FIELD,f)  _CACHE_MAR_FSET(138,##FIELD,f)
  #define _CACHE_MAR139_FSET(FIELD,f)  _CACHE_MAR_FSET(139,##FIELD,f)
  #define _CACHE_MAR140_FSET(FIELD,f)  _CACHE_MAR_FSET(140,##FIELD,f)
  #define _CACHE_MAR141_FSET(FIELD,f)  _CACHE_MAR_FSET(141,##FIELD,f)
  #define _CACHE_MAR142_FSET(FIELD,f)  _CACHE_MAR_FSET(142,##FIELD,f)
  #define _CACHE_MAR143_FSET(FIELD,f)  _CACHE_MAR_FSET(143,##FIELD,f)
  #define _CACHE_MAR144_FSET(FIELD,f)  _CACHE_MAR_FSET(144,##FIELD,f)
  #define _CACHE_MAR145_FSET(FIELD,f)  _CACHE_MAR_FSET(145,##FIELD,f)
  #define _CACHE_MAR146_FSET(FIELD,f)  _CACHE_MAR_FSET(146,##FIELD,f)
  #define _CACHE_MAR147_FSET(FIELD,f)  _CACHE_MAR_FSET(147,##FIELD,f)
  #define _CACHE_MAR148_FSET(FIELD,f)  _CACHE_MAR_FSET(148,##FIELD,f)
  #define _CACHE_MAR149_FSET(FIELD,f)  _CACHE_MAR_FSET(149,##FIELD,f)
  #define _CACHE_MAR150_FSET(FIELD,f)  _CACHE_MAR_FSET(150,##FIELD,f)
  #define _CACHE_MAR151_FSET(FIELD,f)  _CACHE_MAR_FSET(151,##FIELD,f)
  #define _CACHE_MAR152_FSET(FIELD,f)  _CACHE_MAR_FSET(152,##FIELD,f)
  #define _CACHE_MAR153_FSET(FIELD,f)  _CACHE_MAR_FSET(153,##FIELD,f)
  #define _CACHE_MAR154_FSET(FIELD,f)  _CACHE_MAR_FSET(154,##FIELD,f)
  #define _CACHE_MAR155_FSET(FIELD,f)  _CACHE_MAR_FSET(155,##FIELD,f)
  #define _CACHE_MAR156_FSET(FIELD,f)  _CACHE_MAR_FSET(156,##FIELD,f)
  #define _CACHE_MAR157_FSET(FIELD,f)  _CACHE_MAR_FSET(157,##FIELD,f)
  #define _CACHE_MAR158_FSET(FIELD,f)  _CACHE_MAR_FSET(158,##FIELD,f)
  #define _CACHE_MAR159_FSET(FIELD,f)  _CACHE_MAR_FSET(159,##FIELD,f)
  #define _CACHE_MAR160_FSET(FIELD,f)  _CACHE_MAR_FSET(160,##FIELD,f)
  #define _CACHE_MAR161_FSET(FIELD,f)  _CACHE_MAR_FSET(161,##FIELD,f)
  #define _CACHE_MAR162_FSET(FIELD,f)  _CACHE_MAR_FSET(162,##FIELD,f)
  #define _CACHE_MAR163_FSET(FIELD,f)  _CACHE_MAR_FSET(163,##FIELD,f)
  #define _CACHE_MAR164_FSET(FIELD,f)  _CACHE_MAR_FSET(164,##FIELD,f)
  #define _CACHE_MAR165_FSET(FIELD,f)  _CACHE_MAR_FSET(165,##FIELD,f)
  #define _CACHE_MAR166_FSET(FIELD,f)  _CACHE_MAR_FSET(166,##FIELD,f)
  #define _CACHE_MAR167_FSET(FIELD,f)  _CACHE_MAR_FSET(167,##FIELD,f)
  #define _CACHE_MAR168_FSET(FIELD,f)  _CACHE_MAR_FSET(168,##FIELD,f)
  #define _CACHE_MAR169_FSET(FIELD,f)  _CACHE_MAR_FSET(169,##FIELD,f)
  #define _CACHE_MAR170_FSET(FIELD,f)  _CACHE_MAR_FSET(170,##FIELD,f)
  #define _CACHE_MAR171_FSET(FIELD,f)  _CACHE_MAR_FSET(171,##FIELD,f)
  #define _CACHE_MAR172_FSET(FIELD,f)  _CACHE_MAR_FSET(172,##FIELD,f)
  #define _CACHE_MAR173_FSET(FIELD,f)  _CACHE_MAR_FSET(173,##FIELD,f)
  #define _CACHE_MAR174_FSET(FIELD,f)  _CACHE_MAR_FSET(174,##FIELD,f)
  #define _CACHE_MAR175_FSET(FIELD,f)  _CACHE_MAR_FSET(175,##FIELD,f)
  #define _CACHE_MAR176_FSET(FIELD,f)  _CACHE_MAR_FSET(176,##FIELD,f)
  #define _CACHE_MAR177_FSET(FIELD,f)  _CACHE_MAR_FSET(177,##FIELD,f)
  #define _CACHE_MAR178_FSET(FIELD,f)  _CACHE_MAR_FSET(178,##FIELD,f)
  #define _CACHE_MAR179_FSET(FIELD,f)  _CACHE_MAR_FSET(179,##FIELD,f)
  #define _CACHE_MAR180_FSET(FIELD,f)  _CACHE_MAR_FSET(180,##FIELD,f)
  #define _CACHE_MAR181_FSET(FIELD,f)  _CACHE_MAR_FSET(181,##FIELD,f)
  #define _CACHE_MAR182_FSET(FIELD,f)  _CACHE_MAR_FSET(182,##FIELD,f)
  #define _CACHE_MAR183_FSET(FIELD,f)  _CACHE_MAR_FSET(183,##FIELD,f)
  #define _CACHE_MAR184_FSET(FIELD,f)  _CACHE_MAR_FSET(184,##FIELD,f)
  #define _CACHE_MAR185_FSET(FIELD,f)  _CACHE_MAR_FSET(185,##FIELD,f)
  #define _CACHE_MAR186_FSET(FIELD,f)  _CACHE_MAR_FSET(186,##FIELD,f)
  #define _CACHE_MAR187_FSET(FIELD,f)  _CACHE_MAR_FSET(187,##FIELD,f)
  #define _CACHE_MAR188_FSET(FIELD,f)  _CACHE_MAR_FSET(188,##FIELD,f)
  #define _CACHE_MAR189_FSET(FIELD,f)  _CACHE_MAR_FSET(189,##FIELD,f)
  #define _CACHE_MAR190_FSET(FIELD,f)  _CACHE_MAR_FSET(190,##FIELD,f)
  #define _CACHE_MAR191_FSET(FIELD,f)  _CACHE_MAR_FSET(191,##FIELD,f)

  #if (CHIP_6414 | CHIP_6415 | CHIP_6416)
    #define _CACHE_MAR96_FSETS(FIELD,SYM)   _CACHE_MAR_FSETS(96,##FIELD,##SYM)
    #define _CACHE_MAR97_FSETS(FIELD,SYM)   _CACHE_MAR_FSETS(97,##FIELD,##SYM)
    #define _CACHE_MAR98_FSETS(FIELD,SYM)   _CACHE_MAR_FSETS(98,##FIELD,##SYM)
    #define _CACHE_MAR99_FSETS(FIELD,SYM)   _CACHE_MAR_FSETS(99,##FIELD,##SYM)
    #define _CACHE_MAR100_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(100,##FIELD,##SYM)
    #define _CACHE_MAR101_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(101,##FIELD,##SYM)
    #define _CACHE_MAR102_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(102,##FIELD,##SYM)
    #define _CACHE_MAR103_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(103,##FIELD,##SYM)
    #define _CACHE_MAR104_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(104,##FIELD,##SYM)
    #define _CACHE_MAR105_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(105,##FIELD,##SYM)
    #define _CACHE_MAR106_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(106,##FIELD,##SYM)
    #define _CACHE_MAR107_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(107,##FIELD,##SYM)
    #define _CACHE_MAR108_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(108,##FIELD,##SYM)
    #define _CACHE_MAR109_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(109,##FIELD,##SYM)
    #define _CACHE_MAR110_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(110,##FIELD,##SYM)
    #define _CACHE_MAR111_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(111,##FIELD,##SYM)
  #endif

  #define _CACHE_MAR128_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(128,##FIELD,##SYM)
  #define _CACHE_MAR129_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(129,##FIELD,##SYM)
  #define _CACHE_MAR130_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(130,##FIELD,##SYM)
  #define _CACHE_MAR131_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(131,##FIELD,##SYM)
  #define _CACHE_MAR132_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(132,##FIELD,##SYM)
  #define _CACHE_MAR133_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(133,##FIELD,##SYM)
  #define _CACHE_MAR134_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(134,##FIELD,##SYM)
  #define _CACHE_MAR135_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(135,##FIELD,##SYM)
  #define _CACHE_MAR136_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(136,##FIELD,##SYM)
  #define _CACHE_MAR137_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(137,##FIELD,##SYM)
  #define _CACHE_MAR138_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(138,##FIELD,##SYM)
  #define _CACHE_MAR139_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(139,##FIELD,##SYM)
  #define _CACHE_MAR140_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(140,##FIELD,##SYM)
  #define _CACHE_MAR141_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(141,##FIELD,##SYM)
  #define _CACHE_MAR142_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(142,##FIELD,##SYM)
  #define _CACHE_MAR143_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(143,##FIELD,##SYM)
  #define _CACHE_MAR144_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(144,##FIELD,##SYM)
  #define _CACHE_MAR145_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(145,##FIELD,##SYM)
  #define _CACHE_MAR146_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(146,##FIELD,##SYM)
  #define _CACHE_MAR147_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(147,##FIELD,##SYM)
  #define _CACHE_MAR148_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(148,##FIELD,##SYM)
  #define _CACHE_MAR149_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(149,##FIELD,##SYM)
  #define _CACHE_MAR150_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(150,##FIELD,##SYM)
  #define _CACHE_MAR151_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(151,##FIELD,##SYM)
  #define _CACHE_MAR152_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(152,##FIELD,##SYM)
  #define _CACHE_MAR153_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(153,##FIELD,##SYM)
  #define _CACHE_MAR154_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(154,##FIELD,##SYM)
  #define _CACHE_MAR155_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(155,##FIELD,##SYM)
  #define _CACHE_MAR156_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(156,##FIELD,##SYM)
  #define _CACHE_MAR157_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(157,##FIELD,##SYM)
  #define _CACHE_MAR158_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(158,##FIELD,##SYM)
  #define _CACHE_MAR159_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(159,##FIELD,##SYM)
  #define _CACHE_MAR160_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(160,##FIELD,##SYM)
  #define _CACHE_MAR161_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(161,##FIELD,##SYM)
  #define _CACHE_MAR162_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(162,##FIELD,##SYM)
  #define _CACHE_MAR163_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(163,##FIELD,##SYM)
  #define _CACHE_MAR164_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(164,##FIELD,##SYM)
  #define _CACHE_MAR165_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(165,##FIELD,##SYM)
  #define _CACHE_MAR166_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(166,##FIELD,##SYM)
  #define _CACHE_MAR167_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(167,##FIELD,##SYM)
  #define _CACHE_MAR168_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(168,##FIELD,##SYM)
  #define _CACHE_MAR169_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(169,##FIELD,##SYM)
  #define _CACHE_MAR170_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(170,##FIELD,##SYM)
  #define _CACHE_MAR171_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(171,##FIELD,##SYM)
  #define _CACHE_MAR172_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(172,##FIELD,##SYM)
  #define _CACHE_MAR173_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(173,##FIELD,##SYM)
  #define _CACHE_MAR174_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(174,##FIELD,##SYM)
  #define _CACHE_MAR175_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(175,##FIELD,##SYM)
  #define _CACHE_MAR176_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(176,##FIELD,##SYM)
  #define _CACHE_MAR177_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(177,##FIELD,##SYM)
  #define _CACHE_MAR178_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(178,##FIELD,##SYM)
  #define _CACHE_MAR179_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(179,##FIELD,##SYM)
  #define _CACHE_MAR180_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(180,##FIELD,##SYM)
  #define _CACHE_MAR181_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(181,##FIELD,##SYM)
  #define _CACHE_MAR182_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(182,##FIELD,##SYM)
  #define _CACHE_MAR183_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(183,##FIELD,##SYM)
  #define _CACHE_MAR184_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(184,##FIELD,##SYM)
  #define _CACHE_MAR185_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(185,##FIELD,##SYM)
  #define _CACHE_MAR186_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(186,##FIELD,##SYM)
  #define _CACHE_MAR187_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(187,##FIELD,##SYM)
  #define _CACHE_MAR188_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(188,##FIELD,##SYM)
  #define _CACHE_MAR189_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(189,##FIELD,##SYM)
  #define _CACHE_MAR190_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(190,##FIELD,##SYM)
  #define _CACHE_MAR191_FSETS(FIELD,SYM)  _CACHE_MAR_FSETS(191,##FIELD,##SYM)
#endif

/******************************************************************************\
* _____________________
* |                   |
* |  L 2 W B A R      |
* |___________________|
*
* L2WBAR   - L2 writeback base address register
*
* Fields:
* (rw) L2WBAR
*
\******************************************************************************/
#if (L2CACHE_SUPPORT)
  #define _CACHE_L2WBAR_ADDR           0x01844000u

  #define _CACHE_L2WBAR_L2WBAR_MASK    0xFFFFFFFFu
  #define _CACHE_L2WBAR_L2WBAR_SHIFT   0x00000000u
  #define  CACHE_L2WBAR_L2WBAR_DEFAULT 0x00000000u
  #define  CACHE_L2WBAR_L2WBAR_OF(x)   _VALUEOF(x)

  #define  CACHE_L2WBAR_OF(x)          _VALUEOF(x)

  #define CACHE_L2WBAR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,L2WBAR,L2WBAR) \
  )

  #define CACHE_L2WBAR_RMK(l2wbar) (Uint32)( \
     _PER_FMK(CACHE,L2WBAR,L2WBAR,l2wbar) \
  )

  #define _CACHE_L2WBAR_FGET(FIELD)\
    _PER_FGET(_CACHE_L2WBAR_ADDR,CACHE,L2WBAR,##FIELD)

  #define _CACHE_L2WBAR_FSET(FIELD,field)\
    _PER_FSET(_CACHE_L2WBAR_ADDR,CACHE,L2WBAR,##FIELD,field)

  #define _CACHE_L2WBAR_FSETS(FIELD,SYM)\
    _PER_FSETS(_CACHE_L2WBAR_ADDR,CACHE,L2WBAR,##FIELD,##SYM)
#endif


/******************************************************************************\
* _____________________
* |                   |
* |  L 2 W W C        |
* |___________________|
*
* L2WWC    - L2 writeback word count register
*
* Fields:
* (rw) L2WWC
*
\******************************************************************************/
#if (L2CACHE_SUPPORT)
  #define _CACHE_L2WWC_ADDR           0x01844004u

  #define _CACHE_L2WWC_L2WWC_MASK     0x0000FFFFu
  #define _CACHE_L2WWC_L2WWC_SHIFT    0x00000000u
  #define  CACHE_L2WWC_L2WWC_DEFAULT  0x00000000u
  #define  CACHE_L2WWC_L2WWC_OF(x)    _VALUEOF(x)

  #define  CACHE_L2WWC_OF(x)          _VALUEOF(x)

  #define CACHE_L2WWC_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,L2WWC,L2WWC) \
  )

  #define CACHE_L2WWC_RMK(l2wwc) (Uint32)( \
     _PER_FMK(CACHE,L2WWC,L2WWC,l2wwc) \
  )

  #define _CACHE_L2WWC_FGET(FIELD)\
    _PER_FGET(_CACHE_L2WWC_ADDR,CACHE,L2WWC,##FIELD)

  #define _CACHE_L2WWC_FSET(FIELD,field)\
    _PER_FSET(_CACHE_L2WWC_ADDR,CACHE,L2WWC,##FIELD,field)

  #define _CACHE_L2WWC_FSETS(FIELD,SYM)\
    _PER_FSETS(_CACHE_L2WWC_ADDR,CACHE,L2WWC,##FIELD,##SYM)
#endif

/******************************************************************************\
* _____________________
* |                   |
* |  L 2 W I B A R    |
* |___________________|
*
* L2WIBAR  - L2 writeback-invalidate base address register
*
* Fields:
* (rw) L2WIBAR
*
\******************************************************************************/
#if (L2CACHE_SUPPORT)
  #define _CACHE_L2WIBAR_ADDR           0x01844010u

  #define _CACHE_L2WIBAR_L2WIBAR_MASK    0xFFFFFFFFu
  #define _CACHE_L2WIBAR_L2WIBAR_SHIFT   0x00000000u
  #define  CACHE_L2WIBAR_L2WIBAR_DEFAULT 0x00000000u
  #define  CACHE_L2WIBAR_L2WIBAR_OF(x)   _VALUEOF(x)

  #define  CACHE_L2WIBAR_OF(x)          _VALUEOF(x)

  #define CACHE_L2WIBAR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,L2WIBAR,L2WIBAR) \
  )

  #define CACHE_L2WIBAR_RMK(l2wibar) (Uint32)( \
     _PER_FMK(CACHE,L2WIBAR,L2WIBAR,l2wibar) \
  )

  #define _CACHE_L2WIBAR_FGET(FIELD)\
    _PER_FGET(_CACHE_L2WIBAR_ADDR,CACHE,L2WIBAR,##FIELD)

  #define _CACHE_L2WIBAR_FSET(FIELD,field)\
    _PER_FSET(_CACHE_L2WIBAR_ADDR,CACHE,L2WIBAR,##FIELD,field)

  #define _CACHE_L2WIBAR_FSETS(FIELD,SYM)\
    _PER_FSETS(_CACHE_L2WIBAR_ADDR,CACHE,L2WIBAR,##FIELD,##SYM)
#endif

/******************************************************************************\
* _____________________
* |                   |
* |  L 2 W I W C      |
* |___________________|
*
* L2WIWC   - L2 writeback-invalidate word count register
*
* Fields:
* (rw) L2WIWC
*
\******************************************************************************/
#if (L2CACHE_SUPPORT)
  #define _CACHE_L2WIWC_ADDR           0x01844014u

  #define _CACHE_L2WIWC_L2WIWC_MASK     0x0000FFFFu
  #define _CACHE_L2WIWC_L2WIWC_SHIFT    0x00000000u
  #define  CACHE_L2WIWC_L2WIWC_DEFAULT  0x00000000u
  #define  CACHE_L2WIWC_L2WIWC_OF(x)    _VALUEOF(x)

  #define  CACHE_L2WIWC_OF(x)          _VALUEOF(x)

  #define CACHE_L2WIWC_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,L2WIWC,L2WIWC) \
  )

  #define CACHE_L2WIWC_RMK(l2wiwc) (Uint32)( \
     _PER_FMK(CACHE,L2WIWC,L2WIWC,l2wiwc) \
  )

  #define _CACHE_L2WIWC_FGET(FIELD)\
    _PER_FGET(_CACHE_L2WIWC_ADDR,CACHE,L2WIWC,##FIELD)

  #define _CACHE_L2WIWC_FSET(FIELD,field)\
    _PER_FSET(_CACHE_L2WIWC_ADDR,CACHE,L2WIWC,##FIELD,field)

  #define _CACHE_L2WIWC_FSETS(FIELD,SYM)\
    _PER_FSETS(_CACHE_L2WIWC_ADDR,CACHE,L2WIWC,##FIELD,##SYM)
#endif

/******************************************************************************\
* ___________________
* |                 |
* |  L 2 I B A R    |
* |_________________|
*
* L2IBAR  - L2 invalidate base address register
*
* Fields:
* (rw) L2IBAR
*
\******************************************************************************/
#if (L2CACHE_SUPPORT && C64_SUPPORT)
  #define _CACHE_L2IBAR_ADDR           0x01844018u

  #define _CACHE_L2IBAR_L2IBAR_MASK    0xFFFFFFFFu
  #define _CACHE_L2IBAR_L2IBAR_SHIFT   0x00000000u
  #define  CACHE_L2IBAR_L2IBAR_DEFAULT 0x00000000u
  #define  CACHE_L2IBAR_L2IBAR_OF(x)   _VALUEOF(x)

  #define  CACHE_L2IBAR_OF(x)          _VALUEOF(x)

  #define CACHE_L2IBAR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,L2IBAR,L2IBAR) \
  )

  #define CACHE_L2IBAR_RMK(l2ibar) (Uint32)( \
     _PER_FMK(CACHE,L2IBAR,L2IBAR,l2ibar) \
  )

  #define _CACHE_L2IBAR_FGET(FIELD)\
    _PER_FGET(_CACHE_L2IBAR_ADDR,CACHE,L2IBAR,##FIELD)

  #define _CACHE_L2IBAR_FSET(FIELD,field)\
    _PER_FSET(_CACHE_L2IBAR_ADDR,CACHE,L2IBAR,##FIELD,field)

  #define _CACHE_L2IBAR_FSETS(FIELD,SYM)\
    _PER_FSETS(_CACHE_L2IBAR_ADDR,CACHE,L2IBAR,##FIELD,##SYM)
#endif

/******************************************************************************\
* ___________________
* |                 |
* |  L 2 I W C      |
* |_________________|
*
* L2IWC   - L2 invalidate word count register
*
* Fields:
* (rw) L2IWC
*
\******************************************************************************/
#if (L2CACHE_SUPPORT && C64_SUPPORT)
  #define _CACHE_L2IWC_ADDR           0x0184401Cu

  #define _CACHE_L2IWC_L2IWC_MASK     0x0000FFFFu
  #define _CACHE_L2IWC_L2IWC_SHIFT    0x00000000u
  #define  CACHE_L2IWC_L2IWC_DEFAULT  0x00000000u
  #define  CACHE_L2IWC_L2IWC_OF(x)    _VALUEOF(x)

  #define  CACHE_L2IWC_OF(x)          _VALUEOF(x)

  #define CACHE_L2IWC_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,L2IWC,L2IWC) \
  )

  #define CACHE_L2IWC_RMK(l2iwc) (Uint32)( \
     _PER_FMK(CACHE,L2IWC,L2IWC,l2iwc) \
  )

  #define _CACHE_L2IWC_FGET(FIELD)\
    _PER_FGET(_CACHE_L2IWC_ADDR,CACHE,L2IWC,##FIELD)

  #define _CACHE_L2IWC_FSET(FIELD,field)\
    _PER_FSET(_CACHE_L2IWC_ADDR,CACHE,L2IWC,##FIELD,field)

  #define _CACHE_L2IWC_FSETS(FIELD,SYM)\
    _PER_FSETS(_CACHE_L2IWC_ADDR,CACHE,L2IWC,##FIELD,##SYM)
#endif

/******************************************************************************\
* _____________________
* |                   |
* |  L 1 P I B A R    |
* |___________________|
*
* L1PIBAR  - L1P invalidate base address register
*
* Fields:
* (rw) L1PIBAR
*
\******************************************************************************/
#if (L2CACHE_SUPPORT)
  #define _CACHE_L1PIBAR_ADDR            0x01844020u

  #define _CACHE_L1PIBAR_L1PIBAR_MASK    0xFFFFFFFFu
  #define _CACHE_L1PIBAR_L1PIBAR_SHIFT   0x00000000u
  #define  CACHE_L1PIBAR_L1PIBAR_DEFAULT 0x00000000u
  #define  CACHE_L1PIBAR_L1PIBAR_OF(x)   _VALUEOF(x)

  #define  CACHE_L1PIBAR_OF(x)           _VALUEOF(x)

  #define CACHE_L1PIBAR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,L1PIBAR,L1PIBAR) \
  )

  #define CACHE_L1PIBAR_RMK(l1pibar) (Uint32)( \
     _PER_FMK(CACHE,L1PIBAR,L1PIBAR,l1pibar) \
  )

  #define _CACHE_L1PIBAR_FGET(FIELD)\
    _PER_FGET(_CACHE_L1PIBAR_ADDR,CACHE,L1PIBAR,##FIELD)

  #define _CACHE_L1PIBAR_FSET(FIELD,field)\
    _PER_FSET(_CACHE_L1PIBAR_ADDR,CACHE,L1PIBAR,##FIELD,field)

  #define _CACHE_L1PIBAR_FSETS(FIELD,SYM)\
    _PER_FSETS(_CACHE_L1PIBAR_ADDR,CACHE,L1PIBAR,##FIELD,##SYM)
#endif

/******************************************************************************\
* _____________________
* |                   |
* |  L 1 P I W C      |
* |___________________|
*
* L1PIWC   - L1P invalidate word count register
*
* Fields:
* (rw) L1PFWC
*
\******************************************************************************/
#if (L2CACHE_SUPPORT)
  #define _CACHE_L1PIWC_ADDR            0x01844024u

  #define _CACHE_L1PIWC_L1PIWC_MASK     0x0000FFFFu
  #define _CACHE_L1PIWC_L1PIWC_SHIFT    0x00000000u
  #define  CACHE_L1PIWC_L1PIWC_DEFAULT  0x00000000u
  #define  CACHE_L1PIWC_L1PIWC_OF(x)    _VALUEOF(x)

  #define  CACHE_L1PIWC_OF(x)           _VALUEOF(x)

  #define CACHE_L1PIWC_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,L1PIWC,L1PIWC) \
  )

  #define CACHE_L1PIWC_RMK(l1piwc) (Uint32)( \
     _PER_FMK(CACHE,L1PIWC,L1PIWC,l1piwc) \
  )

  #define _CACHE_L1PIWC_FGET(FIELD)\
    _PER_FGET(_CACHE_L1PIWC_ADDR,CACHE,L1PIWC,##FIELD)

  #define _CACHE_L1PIWC_FSET(FIELD,field)\
    _PER_FSET(_CACHE_L1PIWC_ADDR,CACHE,L1PIWC,##FIELD,field)

  #define _CACHE_L1PIWC_FSETS(FIELD,SYM)\
    _PER_FSETS(_CACHE_L1PIWC_ADDR,CACHE,L1PIWC,##FIELD,##SYM)
#endif

/******************************************************************************\
* _____________________
* |                   |
* |  L 1 D W I B A R  |
* |___________________|
*
* L1DWIBAR - L1D writeback-invalidate base address register
*
* Fields:
* (rw) L1DWIBAR
*
\******************************************************************************/
#if (L2CACHE_SUPPORT)
  #define _CACHE_L1DWIBAR_ADDR            0x01844030u

  #define _CACHE_L1DWIBAR_L1DWIBAR_MASK    0xFFFFFFFFu
  #define _CACHE_L1DWIBAR_L1DWIBAR_SHIFT   0x00000000u
  #define  CACHE_L1DWIBAR_L1DWIBAR_DEFAULT 0x00000000u
  #define  CACHE_L1DWIBAR_L1DWIBAR_OF(x)   _VALUEOF(x)

  #define  CACHE_L1DWIBAR_OF(x)           _VALUEOF(x)

  #define CACHE_L1DWIBAR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,L1DWIBAR,L1DWIBAR) \
  )

  #define CACHE_L1DWIBAR_RMK(l1dwibar) (Uint32)( \
     _PER_FMK(CACHE,L1DWIBAR,L1DWIBAR,l1dwibar) \
  )

  #define _CACHE_L1DWIBAR_FGET(FIELD)\
    _PER_FGET(_CACHE_L1DWIBAR_ADDR,CACHE,L1DWIBAR,##FIELD)

  #define _CACHE_L1DWIBAR_FSET(FIELD,field)\
    _PER_FSET(_CACHE_L1DWIBAR_ADDR,CACHE,L1DWIBAR,##FIELD,field)

  #define _CACHE_L1DWIBAR_FSETS(FIELD,SYM)\
    _PER_FSETS(_CACHE_L1DWIBAR_ADDR,CACHE,L1DWIBAR,##FIELD,##SYM)
#endif

/******************************************************************************\
* _____________________
* |                   |
* |  L 1 D W I W C    |
* |___________________|
*
* L1DWIWC  - L1D writeback-invalidate word count register
*
* Fields:
* (rw) L1DWIWC
*
\******************************************************************************/
#if (L2CACHE_SUPPORT)
  #define _CACHE_L1DWIWC_ADDR            0x01844034u

  #define _CACHE_L1DWIWC_L1DWIWC_MASK     0x0000FFFFu
  #define _CACHE_L1DWIWC_L1DWIWC_SHIFT    0x00000000u
  #define  CACHE_L1DWIWC_L1DWIWC_DEFAULT  0x00000000u
  #define  CACHE_L1DWIWC_L1DWIWC_OF(x)    _VALUEOF(x)

  #define  CACHE_L1DWIWC_OF(x)           _VALUEOF(x)

  #define CACHE_L1DWIWC_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,L1DWIWC,L1DWIWC) \
  )

  #define CACHE_L1DWIWC_RMK(l1dwiwc) (Uint32)( \
     _PER_FMK(CACHE,L1DWIWC,L1DWIWC,l1dwiwc) \
  )

  #define _CACHE_L1DWIWC_FGET(FIELD)\
    _PER_FGET(_CACHE_L1DWIWC_ADDR,CACHE,L1DWIWC,##FIELD)

  #define _CACHE_L1DWIWC_FSET(FIELD,field)\
    _PER_FSET(_CACHE_L1DWIWC_ADDR,CACHE,L1DWIWC,##FIELD,field)

  #define _CACHE_L1DWIWC_FSETS(FIELD,SYM)\
    _PER_FSETS(_CACHE_L1DWIWC_ADDR,CACHE,L1DWIWC,##FIELD,##SYM)
#endif

/******************************************************************************\
* ___________________
* |                 |
* |  L 1 D I B A R  |
* |_________________|
*
* L1DIBAR - L1D invalidate base address register
*
* Fields:
* (rw) L1DIBAR
*
\******************************************************************************/
#if (L2CACHE_SUPPORT && C64_SUPPORT)
  #define _CACHE_L1DIBAR_ADDR            0x01844048u

  #define _CACHE_L1DIBAR_L1DIBAR_MASK    0xFFFFFFFFu
  #define _CACHE_L1DIBAR_L1DIBAR_SHIFT   0x00000000u
  #define  CACHE_L1DIBAR_L1DIBAR_DEFAULT 0x00000000u
  #define  CACHE_L1DIBAR_L1DIBAR_OF(x)   _VALUEOF(x)

  #define  CACHE_L1DIBAR_OF(x)           _VALUEOF(x)

  #define CACHE_L1DIBAR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,L1DIBAR,L1DIBAR) \
  )

  #define CACHE_L1DIBAR_RMK(l1dibar) (Uint32)( \
     _PER_FMK(CACHE,L1DIBAR,L1DIBAR,l1dibar) \
  )

  #define _CACHE_L1DIBAR_FGET(FIELD)\
    _PER_FGET(_CACHE_L1DIBAR_ADDR,CACHE,L1DIBAR,##FIELD)

  #define _CACHE_L1DIBAR_FSET(FIELD,field)\
    _PER_FSET(_CACHE_L1DIBAR_ADDR,CACHE,L1DIBAR,##FIELD,field)

  #define _CACHE_L1DIBAR_FSETS(FIELD,SYM)\
    _PER_FSETS(_CACHE_L1DIBAR_ADDR,CACHE,L1DIBAR,##FIELD,##SYM)
#endif

/******************************************************************************\
* ___________________
* |                 |
* |  L 1 D I W C    |
* |_________________|
*
* L1DIWC  - L1D invalidate word count register
*
* Fields:
* (rw) L1DIWC
*
\******************************************************************************/
#if (L2CACHE_SUPPORT && C64_SUPPORT)
  #define _CACHE_L1DIWC_ADDR            0x0184404Cu

  #define _CACHE_L1DIWC_L1DIWC_MASK     0x0000FFFFu
  #define _CACHE_L1DIWC_L1DIWC_SHIFT    0x00000000u
  #define  CACHE_L1DIWC_L1DIWC_DEFAULT  0x00000000u
  #define  CACHE_L1DIWC_L1DIWC_OF(x)    _VALUEOF(x)

  #define  CACHE_L1DIWC_OF(x)           _VALUEOF(x)

  #define CACHE_L1DIWC_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,L1DIWC,L1DIWC) \
  )

  #define CACHE_L1DIWC_RMK(l1diwc) (Uint32)( \
     _PER_FMK(CACHE,L1DIWC,L1DIWC,l1diwc) \
  )

  #define _CACHE_L1DIWC_FGET(FIELD)\
    _PER_FGET(_CACHE_L1DIWC_ADDR,CACHE,L1DIWC,##FIELD)

  #define _CACHE_L1DIWC_FSET(FIELD,field)\
    _PER_FSET(_CACHE_L1DIWC_ADDR,CACHE,L1DIWC,##FIELD,field)

  #define _CACHE_L1DIWC_FSETS(FIELD,SYM)\
    _PER_FSETS(_CACHE_L1DIWC_ADDR,CACHE,L1DIWC,##FIELD,##SYM)
#endif

/******************************************************************************\
* _______________
* |             |
* |  L 2 W B    |
* |_____________|
*
* L2WB     - L2 writeback all register
*
* Fields:
* (rw) L2WB
*
\******************************************************************************/
#if (L2CACHE_SUPPORT)
  #define _CACHE_L2WB_ADDR      0x01845000u

  #define _CACHE_L2WB_C_MASK    0x00000001u
  #define _CACHE_L2WB_C_SHIFT   0x00000000u
  #define  CACHE_L2WB_C_DEFAULT 0x00000000u
  #define  CACHE_L2WB_C_OF(x)   _VALUEOF(x)
  #define  CACHE_L2WB_C_NORMAL  0x00000000u
  #define  CACHE_L2WB_C_FLUSH   0x00000001u

  #define  CACHE_L2WB_OF(x)     _VALUEOF(x)

  #define CACHE_L2WB_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,L2WB,C) \
  )

  #define CACHE_L2WB_RMK(c) (Uint32)( \
     _PER_FMK(CACHE,L2WB,C,c) \
  )

  #define _CACHE_L2WB_FGET(FIELD)\
    _PER_FGET(_CACHE_L2WB_ADDR,CACHE,L2WB,##FIELD)

  #define _CACHE_L2WB_FSET(FIELD,field)\
    _PER_FSET(_CACHE_L2WB_ADDR,CACHE,L2WB,##FIELD,field)

  #define _CACHE_L2WB_FSETS(FIELD,SYM)\
    _PER_FSETS(_CACHE_L2WB_ADDR,CACHE,L2WB,##FIELD,##SYM)
#endif

/******************************************************************************\
* _____________________
* |                   |
* |  L 2 W B I N V    |
* |___________________|
*
* L2WBINV  - L2 writeback-invalidate all register
*
* Fields:
* (rw) C
*
\******************************************************************************/
#if (L2CACHE_SUPPORT)
  #define _CACHE_L2WBINV_ADDR       0x01845004u

  #define _CACHE_L2WBINV_C_MASK     0x00000001u
  #define _CACHE_L2WBINV_C_SHIFT    0x00000000u
  #define  CACHE_L2WBINV_C_DEFAULT  0x00000000u
  #define  CACHE_L2WBINV_C_OF(x)    _VALUEOF(x)
  #define  CACHE_L2WBINV_C_NORMAL   0x00000000u
  #define  CACHE_L2WBINV_C_CLEAN    0x00000001u

  #define  CACHE_L2WBINV_OF(x)      _VALUEOF(x)

  #define CACHE_L2WBINV_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CACHE,L2WBINV,C) \
  )

  #define CACHE_L2WBINV_RMK(c) (Uint32)( \
     _PER_FMK(CACHE,L2WBINV,C,c) \
  )

  #define _CACHE_L2WBINV_FGET(FIELD)\
    _PER_FGET(_CACHE_L2WBINV_ADDR,CACHE,L2WBINV,##FIELD)

  #define _CACHE_L2WBINV_FSET(FIELD,field)\
    _PER_FSET(_CACHE_L2WBINV_ADDR,CACHE,L2WBINV,##FIELD,field)

  #define _CACHE_L2WBINV_FSETS(FIELD,SYM)\
    _PER_FSETS(_CACHE_L2WBINV_ADDR,CACHE,L2WBINV,##FIELD,##SYM)
#endif

/*----------------------------------------------------------------------------*/

#endif /* CACHE_SUPPORT */
#endif /* _CSL_CACHEHAL_H_ */
/******************************************************************************\
* End of csl_cachehal.h
\******************************************************************************/

