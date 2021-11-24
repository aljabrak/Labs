/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_emifhal.h
* DATE CREATED.. 06/12/1999 
* LAST MODIFIED. 06/17/2003  Added CHIP_6712C
*                05/28/2003  Added CHIP_6711C
*                10/03/2000
*------------------------------------------------------------------------------
* REGISTERS
*
* GBLCTL  - global control register
* CECTL0  - CE space control register 0
* CECTL1  - CE space control register 1
* CECTL2  - CE space control register 2
* CECTL3  - CE space control register 3
* SDCTL   - SDRAM control regsiter
* SDTIM   - SDRAM timing register
* SDEXT   - SDRAM extension register (1)
*
* (1) - only supported on 6211,6711,6712,6713,6711C,6712C
* 
\******************************************************************************/
#ifndef _CSL_EMIFHAL_H_
#define _CSL_EMIFHAL_H_

#include <csl_stdinc.h>
#include <csl_chip.h>

#if (EMIF_SUPPORT)
/******************************************************************************\
* MISC section
\******************************************************************************/
#define _EMIF_BASE_GLOBAL   0x01800000u


/******************************************************************************\
* module level register/field access macros
\******************************************************************************/

  /* ----------------- */
  /* FIELD MAKE MACROS */
  /* ----------------- */

  #define EMIF_FMK(REG,FIELD,x)\
    _PER_FMK(EMIF,##REG,##FIELD,x)

  #define EMIF_FMKS(REG,FIELD,SYM)\
    _PER_FMKS(EMIF,##REG,##FIELD,##SYM)
 
 
  /* -------------------------------- */
  /* RAW REGISTER/FIELD ACCESS MACROS */
  /* -------------------------------- */

  #define EMIF_ADDR(REG)\
    _EMIF_##REG##_ADDR

  #define EMIF_RGET(REG)\
    _PER_RGET(_EMIF_##REG##_ADDR,EMIF,##REG)

  #define EMIF_RSET(REG,x)\
    _PER_RSET(_EMIF_##REG##_ADDR,EMIF,##REG,x)

  #define EMIF_FGET(REG,FIELD)\
    _EMIF_##REG##_FGET(##FIELD)

  #define EMIF_FSET(REG,FIELD,x)\
    _EMIF_##REG##_FSET(##FIELD,##x)

  #define EMIF_FSETS(REG,FIELD,SYM)\
    _EMIF_##REG##_FSETS(##FIELD,##SYM)
 
 
  /* ------------------------------------------ */
  /* ADDRESS BASED REGISTER/FIELD ACCESS MACROS */
  /* ------------------------------------------ */

  #define EMIF_RGETA(addr,REG)\
    _PER_RGET(addr,EMIF,##REG)

  #define EMIF_RSETA(addr,REG,x)\
    _PER_RSET(addr,EMIF,##REG,x)

  #define EMIF_FGETA(addr,REG,FIELD)\
    _PER_FGET(addr,EMIF,##REG,##FIELD)

  #define EMIF_FSETA(addr,REG,FIELD,x)\
    _PER_FSET(addr,EMIF,##REG,##FIELD,x)

  #define EMIF_FSETSA(addr,REG,FIELD,SYM)\
    _PER_FSETS(addr,EMIF,##REG,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  G B L C T L      |
* |___________________|
*
* GBLCTL  - global control register
*
* FIELDS (msb -> lsb)
* (r)  BUSREQ  (1)
* (r)  ARDY
* (r)  HOLD
* (r)  HOLDA
* (rw) NOHOLD
* (rw) SDCEN   (2)
* (rw) SSCEN   (2)
* (rw) EKEN    (4)
* (rw) CLK1EN
* (rw) CLK2EN  (3)
* (rw) SSCRT   (2)(3)
* (rw) RBTR8   (2)
* (r)  MAP     (2)
*
* (1) - Field only exists for C11_SUPPORT
* (2) - Field does not exist for C11_SUPPORT
* (3) - Field does not exist for 6202/6203/6204/6205 
* (4) - Field only exixts for C6713, DA610, 6711C, 6712C
*
\******************************************************************************/
  #define _EMIF_GBLCTL_OFFSET          0

  #define _EMIF_GBLCTL_ADDR            0x01800000u

#if (C11_SUPPORT)
  #define _EMIF_GBLCTL_BUSREQ_MASK     0x00000800u
  #define _EMIF_GBLCTL_BUSREQ_SHIFT    0x0000000Bu
  #define  EMIF_GBLCTL_BUSREQ_DEFAULT  0x00000000u
  #define  EMIF_GBLCTL_BUSREQ_OF(x)    _VALUEOF(x)
  #define  EMIF_GBLCTL_BUSREQ_LOW      0x00000000u
  #define  EMIF_GBLCTL_BUSREQ_HIGH     0x00000001u
#endif

  #define _EMIF_GBLCTL_ARDY_MASK       0x00000400u
  #define _EMIF_GBLCTL_ARDY_SHIFT      0x0000000Au
  #define  EMIF_GBLCTL_ARDY_DEFAULT    0x00000000u
  #define  EMIF_GBLCTL_ARDY_OF(x)      _VALUEOF(x)
  #define  EMIF_GBLCTL_ARDY_LOW        0x00000000u
  #define  EMIF_GBLCTL_ARDY_HIGH       0x00000001u

  #define _EMIF_GBLCTL_HOLD_MASK       0x00000200u
  #define _EMIF_GBLCTL_HOLD_SHIFT      0x00000009u
  #define  EMIF_GBLCTL_HOLD_DEFAULT    0x00000000u
  #define  EMIF_GBLCTL_HOLD_OF(x)      _VALUEOF(x)
  #define  EMIF_GBLCTL_HOLD_LOW        0x00000000u
  #define  EMIF_GBLCTL_HOLD_HIGH       0x00000001u

  #define _EMIF_GBLCTL_HOLDA_MASK      0x00000100u
  #define _EMIF_GBLCTL_HOLDA_SHIFT     0x00000008u
  #define  EMIF_GBLCTL_HOLDA_DEFAULT   0x00000000u
  #define  EMIF_GBLCTL_HOLDA_OF(x)     _VALUEOF(x)
  #define  EMIF_GBLCTL_HOLDA_LOW       0x00000000u
  #define  EMIF_GBLCTL_HOLDA_HIGH      0x00000001u

  #define _EMIF_GBLCTL_NOHOLD_MASK     0x00000080u
  #define _EMIF_GBLCTL_NOHOLD_SHIFT    0x00000007u
  #define  EMIF_GBLCTL_NOHOLD_DEFAULT  0x00000000u
  #define  EMIF_GBLCTL_NOHOLD_OF(x)    _VALUEOF(x)
  #define  EMIF_GBLCTL_NOHOLD_DISABLE  0x00000000u
  #define  EMIF_GBLCTL_NOHOLD_ENABLE   0x00000001u

#if (CHIP_6201 | CHIP_6202 | CHIP_6203 | CHIP_6204 | CHIP_6205 | CHIP_6701)
  #define _EMIF_GBLCTL_SDCEN_MASK      0x00000040u
  #define _EMIF_GBLCTL_SDCEN_SHIFT     0x00000006u
  #define  EMIF_GBLCTL_SDCEN_DEFAULT   0x00000001u
  #define  EMIF_GBLCTL_SDCEN_OF(x)     _VALUEOF(x)
  #define  EMIF_GBLCTL_SDCEN_DISABLE   0x00000000u
  #define  EMIF_GBLCTL_SDCEN_ENABLE    0x00000001u
#endif

#if (CHIP_6201 | CHIP_6202 | CHIP_6203 | CHIP_6204 | CHIP_6205 | CHIP_6701)
  #define _EMIF_GBLCTL_SSCEN_MASK      0x00000020u
  #define _EMIF_GBLCTL_SSCEN_SHIFT     0x00000005u
  #define  EMIF_GBLCTL_SSCEN_DEFAULT   0x00000001u
  #define  EMIF_GBLCTL_SSCEN_OF(x)     _VALUEOF(x)
  #define  EMIF_GBLCTL_SSCEN_DISABLE   0x00000000u
  #define  EMIF_GBLCTL_SSCEN_ENABLE    0x00000001u
#endif

#if (CHIP_6713 || CHIP_DA610 || CHIP_6711C || CHIP_6712C)
  #define _EMIF_GBLCTL_EKEN_MASK       0x00000020u
  #define _EMIF_GBLCTL_EKEN_SHIFT      0x00000005u
  #define  EMIF_GBLCTL_EKEN_DEFAULT    0x00000001u
  #define  EMIF_GBLCTL_EKEN_OF(x)      _VALUEOF(x)
  #define  EMIF_GBLCTL_EKEN_DISABLE    0x00000000u
  #define  EMIF_GBLCTL_EKEN_ENABLE     0x00000001u
#endif

  #define _EMIF_GBLCTL_CLK1EN_MASK     0x00000010u
  #define _EMIF_GBLCTL_CLK1EN_SHIFT    0x00000004u

#if (CHIP_6713 || CHIP_DA610)
  #define  EMIF_GBLCTL_CLK1EN_DEFAULT  0x00000000u
#else
  #define  EMIF_GBLCTL_CLK1EN_DEFAULT  0x00000001u
#endif

  #define  EMIF_GBLCTL_CLK1EN_OF(x)    _VALUEOF(x)
  #define  EMIF_GBLCTL_CLK1EN_DISABLE  0x00000000u
  #define  EMIF_GBLCTL_CLK1EN_ENABLE   0x00000001u

#if (!(CHIP_6202|CHIP_6203|CHIP_6204|CHIP_6205))
  #define _EMIF_GBLCTL_CLK2EN_MASK     0x00000008u
  #define _EMIF_GBLCTL_CLK2EN_SHIFT    0x00000003u
  #define  EMIF_GBLCTL_CLK2EN_DEFAULT  0x00000001u
  #define  EMIF_GBLCTL_CLK2EN_OF(x)    _VALUEOF(x)
  #define  EMIF_GBLCTL_CLK2EN_DISABLE  0x00000000u
  #define  EMIF_GBLCTL_CLK2EN_ENABLE   0x00000001u
#endif

#if (CHIP_6201|CHIP_6701)
  #define _EMIF_GBLCTL_SSCRT_MASK      0x00000004u
  #define _EMIF_GBLCTL_SSCRT_SHIFT     0x00000002u
  #define  EMIF_GBLCTL_SSCRT_DEFAULT   0x00000000u
  #define  EMIF_GBLCTL_SSCRT_OF(x)     _VALUEOF(x)
  #define  EMIF_GBLCTL_SSCRT_CPUOVR2   0x00000000u
  #define  EMIF_GBLCTL_SSCRT_CPU       0x00000001u
#endif

#if (!C11_SUPPORT)
  #define _EMIF_GBLCTL_RBTR8_MASK      0x00000002u
  #define _EMIF_GBLCTL_RBTR8_SHIFT     0x00000001u
  #define  EMIF_GBLCTL_RBTR8_DEFAULT   0x00000000u
  #define  EMIF_GBLCTL_RBTR8_OF(x)     _VALUEOF(x)
  #define  EMIF_GBLCTL_RBTR8_HPRI      0x00000000u
  #define  EMIF_GBLCTL_RBTR8_8ACC      0x00000001u
#endif

#if (!C11_SUPPORT)
  #define _EMIF_GBLCTL_MAP_MASK        0x00000001u
  #define _EMIF_GBLCTL_MAP_SHIFT       0x00000000u
  #define  EMIF_GBLCTL_MAP_MAP1        0x00000000u
  #define  EMIF_GBLCTL_MAP_MAP0        0x00000001u
  #define  EMIF_GBLCTL_MAP_DEFAULT     0x00000000u
  #define  EMIF_GBLCTL_MAP_OF(x)       _VALUEOF(x)
#endif

  #define  EMIF_GBLCTL_OF(x)           _VALUEOF(x)

#if (CHIP_6201|CHIP_6701)
  #define EMIF_GBLCTL_DEFAULT (Uint32)( \
    0x00003000\
    |_PER_FDEFAULT(EMIF,GBLCTL,ARDY)\
    |_PER_FDEFAULT(EMIF,GBLCTL,HOLD)\
    |_PER_FDEFAULT(EMIF,GBLCTL,HOLDA)\
    |_PER_FDEFAULT(EMIF,GBLCTL,NOHOLD)\
    |_PER_FDEFAULT(EMIF,GBLCTL,SDCEN)\
    |_PER_FDEFAULT(EMIF,GBLCTL,SSCEN)\
    |_PER_FDEFAULT(EMIF,GBLCTL,CLK1EN)\
    |_PER_FDEFAULT(EMIF,GBLCTL,CLK2EN)\
    |_PER_FDEFAULT(EMIF,GBLCTL,SSCRT)\
    |_PER_FDEFAULT(EMIF,GBLCTL,RBTR8)\
    |_PER_FDEFAULT(EMIF,GBLCTL,MAP)\
  )

  #define EMIF_GBLCTL_RMK(nohold,sdcen,sscen,clk1en,clk2en,sscrt,rbtr8) \
    (Uint32)( \
     _PER_FMK(EMIF,GBLCTL,NOHOLD,nohold)\
    |_PER_FMK(EMIF,GBLCTL,SDCEN,sdcen)\
    |_PER_FMK(EMIF,GBLCTL,SSCEN,sscen)\
    |_PER_FMK(EMIF,GBLCTL,CLK1EN,clk1en)\
    |_PER_FMK(EMIF,GBLCTL,CLK2EN,clk2en)\
    |_PER_FMK(EMIF,GBLCTL,SSCRT,sscrt)\
    |_PER_FMK(EMIF,GBLCTL,RBTR8,rbtr8)\
  )
#endif

#if (CHIP_6211|CHIP_6711)
  #define EMIF_GBLCTL_DEFAULT (Uint32)( \
    0x00003000\
    |_PER_FDEFAULT(EMIF,GBLCTL,BUSREQ)\
    |_PER_FDEFAULT(EMIF,GBLCTL,ARDY)\
    |_PER_FDEFAULT(EMIF,GBLCTL,HOLD)\
    |_PER_FDEFAULT(EMIF,GBLCTL,HOLDA)\
    |_PER_FDEFAULT(EMIF,GBLCTL,NOHOLD)\
    |_PER_FDEFAULT(EMIF,GBLCTL,CLK1EN)\
    |_PER_FDEFAULT(EMIF,GBLCTL,CLK2EN)\
  )

  #define EMIF_GBLCTL_RMK(nohold,clk1en,clk2en) (Uint32)( \
     _PER_FMK(EMIF,GBLCTL,NOHOLD,nohold)\
    |_PER_FMK(EMIF,GBLCTL,CLK1EN,clk1en)\
    |_PER_FMK(EMIF,GBLCTL,CLK2EN,clk2en)\
  )
#endif

#if (CHIP_6202|CHIP_6203|CHIP_6204|CHIP_6205)
  #define EMIF_GBLCTL_DEFAULT (Uint32)( \
    0x00003008\
    |_PER_FDEFAULT(EMIF,GBLCTL,ARDY)\
    |_PER_FDEFAULT(EMIF,GBLCTL,HOLD)\
    |_PER_FDEFAULT(EMIF,GBLCTL,HOLDA)\
    |_PER_FDEFAULT(EMIF,GBLCTL,NOHOLD)\
    |_PER_FDEFAULT(EMIF,GBLCTL,SDCEN)\
    |_PER_FDEFAULT(EMIF,GBLCTL,SSCEN)\
    |_PER_FDEFAULT(EMIF,GBLCTL,CLK1EN)\
    |_PER_FDEFAULT(EMIF,GBLCTL,RBTR8)\
    |_PER_FDEFAULT(EMIF,GBLCTL,MAP)\
  )

  #define EMIF_GBLCTL_RMK(nohold,sdcen,sscen,clk1en,rbtr8) (Uint32)( \
     _PER_FMK(EMIF,GBLCTL,NOHOLD,nohold)\
    |_PER_FMK(EMIF,GBLCTL,SDCEN,sdcen)\
    |_PER_FMK(EMIF,GBLCTL,SSCEN,sscen)\
    |_PER_FMK(EMIF,GBLCTL,CLK1EN,clk1en)\
    |_PER_FMK(EMIF,GBLCTL,RBTR8,rbtr8)\
  )
#endif

#if (CHIP_6713 || CHIP_DA610 || CHIP_6711C || CHIP_6712C)
  #define EMIF_GBLCTL_DEFAULT (Uint32)( \
    0x00003000\
    |_PER_FDEFAULT(EMIF,GBLCTL,BUSREQ)\
    |_PER_FDEFAULT(EMIF,GBLCTL,ARDY)\
    |_PER_FDEFAULT(EMIF,GBLCTL,HOLD)\
    |_PER_FDEFAULT(EMIF,GBLCTL,HOLDA)\
    |_PER_FDEFAULT(EMIF,GBLCTL,NOHOLD)\
    |_PER_FDEFAULT(EMIF,GBLCTL,EKEN)\
    |_PER_FDEFAULT(EMIF,GBLCTL,CLK1EN)\
    |_PER_FDEFAULT(EMIF,GBLCTL,CLK2EN)\
  )

  #define EMIF_GBLCTL_RMK(nohold,eken,clk1en,clk2en) (Uint32)( \
     _PER_FMK(EMIF,GBLCTL,NOHOLD,nohold)\
    |_PER_FMK(EMIF,GBLCTL,EKEN,eken)\
    |_PER_FMK(EMIF,GBLCTL,CLK1EN,clk1en)\
    |_PER_FMK(EMIF,GBLCTL,CLK2EN,clk2en)\
  )
#endif

  #define _EMIF_GBLCTL_FGET(FIELD)\
    _PER_FGET(_EMIF_GBLCTL_ADDR,EMIF,GBLCTL,##FIELD)

  #define _EMIF_GBLCTL_FSET(FIELD,field)\
    _PER_FSET(_EMIF_GBLCTL_ADDR,EMIF,GBLCTL,##FIELD,field)

  #define _EMIF_GBLCTL_FSETS(FIELD,SYM)\
    _PER_FSETS(_EMIF_GBLCTL_ADDR,EMIF,GBLCTL,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  C E C T L        |
* |___________________|
*
* CECTL0 - CE space control register 0
* CECTL1 - CE space control register 1
* CECTL2 - CE space control register 2
* CECTL3 - CE space control register 3
*
* FIELDS (msb -> lsb)
* (rw) WRSETUP
* (rw) WRSTRB
* (rw) WRHLD
* (rw) RDSETUP
* (rw) TA       (1) 
* (rw) RDSTRB
* (rw) MTYPE
* (rw) WRHLDMSB 
* (rw) RDHLD
*
* (1) - Field only exists for C11_SUPPORT
* 
*
\******************************************************************************/
  #define _EMIF_CECTL0_OFFSET          2
  #define _EMIF_CECTL1_OFFSET          1
  #define _EMIF_CECTL2_OFFSET          4
  #define _EMIF_CECTL3_OFFSET          5

  #define _EMIF_CECTL0_ADDR            0x01800008u
  #define _EMIF_CECTL1_ADDR            0x01800004u
  #define _EMIF_CECTL2_ADDR            0x01800010u
  #define _EMIF_CECTL3_ADDR            0x01800014u

  #define _EMIF_CECTL_WRSETUP_MASK     0xF0000000u
  #define _EMIF_CECTL_WRSETUP_SHIFT    0x0000001Cu
  #define  EMIF_CECTL_WRSETUP_DEFAULT  0x0000000Fu
  #define  EMIF_CECTL_WRSETUP_OF(x)    _VALUEOF(x)

  #define _EMIF_CECTL_WRSTRB_MASK      0x0FC00000u
  #define _EMIF_CECTL_WRSTRB_SHIFT     0x00000016u
  #define  EMIF_CECTL_WRSTRB_DEFAULT   0x0000003Fu
  #define  EMIF_CECTL_WRSTRB_OF(x)     _VALUEOF(x)

  #define _EMIF_CECTL_WRHLD_MASK       0x00300000u
  #define _EMIF_CECTL_WRHLD_SHIFT      0x00000014u
  #define  EMIF_CECTL_WRHLD_DEFAULT    0x00000003u
  #define  EMIF_CECTL_WRHLD_OF(x)      _VALUEOF(x)
  
  #define _EMIF_CECTL_RDSETUP_MASK     0x000F0000u
  #define _EMIF_CECTL_RDSETUP_SHIFT    0x00000010u
  #define  EMIF_CECTL_RDSETUP_DEFAULT  0x0000000Fu
  #define  EMIF_CECTL_RDSETUP_OF(x)    _VALUEOF(x)

#if (C11_SUPPORT)
  #define _EMIF_CECTL_TA_MASK          0x0000C000u
  #define _EMIF_CECTL_TA_SHIFT         0x0000000Eu
  #define  EMIF_CECTL_TA_DEFAULT       0x00000003u
  #define  EMIF_CECTL_TA_OF(x)         _VALUEOF(x)
#endif

  #define _EMIF_CECTL_RDSTRB_MASK      0x00003F00u
  #define _EMIF_CECTL_RDSTRB_SHIFT     0x00000008u
  #define  EMIF_CECTL_RDSTRB_DEFAULT   0x0000003Fu
  #define  EMIF_CECTL_RDSTRB_OF(x)     _VALUEOF(x)
  
#if (C11_SUPPORT)
  #define _EMIF_CECTL_MTYPE_MASK       0x000000F0u
  #define _EMIF_CECTL_MTYPE_SHIFT      0x00000004u
  #define  EMIF_CECTL_MTYPE_DEFAULT    0x00000002u
  #define  EMIF_CECTL_MTYPE_OF(x)      _VALUEOF(x)
  #if (CHIP_6712 || CHIP_6712C)  /* 16-bit EMIF */ 
  #define  EMIFB_CECTL_MTYPE_ASYNC8     0x00000000u 
  #define  EMIFB_CECTL_MTYPE_ASYNC16    0x00000001u 
  #define  EMIFB_CECTL_MTYPE_SDRAM8     0x00000008u 
  #define  EMIFB_CECTL_MTYPE_SDRAM16    0x00000009u 
  #define  EMIFB_CECTL_MTYPE_SYNC8      0x0000000Au 
  #define  EMIFB_CECTL_MTYPE_SYNC16     0x0000000Bu 
  #else /* CHIP_6211/C6711/6711C 32-bit EMIF */
  #define  EMIF_CECTL_MTYPE_ASYNC8     0x00000000u
  #define  EMIF_CECTL_MTYPE_ASYNC16    0x00000001u
  #define  EMIF_CECTL_MTYPE_ASYNC32    0x00000002u
  #define  EMIF_CECTL_MTYPE_SDRAM32    0x00000003u
  #define  EMIF_CECTL_MTYPE_SBSRAM32   0x00000004u
  #define  EMIF_CECTL_MTYPE_SDRAM8     0x00000008u
  #define  EMIF_CECTL_MTYPE_SDRAM16    0x00000009u
  #define  EMIF_CECTL_MTYPE_SBSRAM8    0x0000000Au
  #define  EMIF_CECTL_MTYPE_SBSRAM16   0x0000000Bu
  #endif
 
#else
  #define _EMIF_CECTL_MTYPE_MASK       0x00000070u
  #define _EMIF_CECTL_MTYPE_SHIFT      0x00000004u
  #define  EMIF_CECTL_MTYPE_DEFAULT    0x00000002u
  #define  EMIF_CECTL_MTYPE_OF(x)      _VALUEOF(x)
  #define  EMIF_CECTL_MTYPE_ASYNC8     0x00000000u
  #define  EMIF_CECTL_MTYPE_ASYNC16    0x00000001u
  #define  EMIF_CECTL_MTYPE_ASYNC32    0x00000002u
  #define  EMIF_CECTL_MTYPE_SDRAM32    0x00000003u
  #define  EMIF_CECTL_MTYPE_SBSRAM32   0x00000004u
#endif


#if (C11_SUPPORT )
  #define _EMIF_CECTL_RDHLD_MASK       0x00000007u
  #define _EMIF_CECTL_RDHLD_SHIFT      0x00000000u
  #define  EMIF_CECTL_RDHLD_DEFAULT    0x00000003u
  #define  EMIF_CECTL_RDHLD_OF(x)      _VALUEOF(x)
#else
  #define _EMIF_CECTL_RDHLD_MASK       0x00000003u
  #define _EMIF_CECTL_RDHLD_SHIFT      0x00000000u
  #define  EMIF_CECTL_RDHLD_DEFAULT    0x00000003u
  #define  EMIF_CECTL_RDHLD_OF(x)      _VALUEOF(x)
#endif

  #define  EMIF_CECTL_OF(x)            _VALUEOF(x)

#if (C11_SUPPORT)
  #define EMIF_CECTL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(EMIF,CECTL,WRSETUP)\
    |_PER_FDEFAULT(EMIF,CECTL,WRSTRB)\
    |_PER_FDEFAULT(EMIF,CECTL,WRHLD)\
    |_PER_FDEFAULT(EMIF,CECTL,RDSETUP)\
    |_PER_FDEFAULT(EMIF,CECTL,TA)\
    |_PER_FDEFAULT(EMIF,CECTL,RDSTRB)\
    |_PER_FDEFAULT(EMIF,CECTL,MTYPE)\
    |_PER_FDEFAULT(EMIF,CECTL,RDHLD)\
  )

  #define EMIF_CECTL_RMK(wrsetup,wrstrb,wrhld,rdsetup,ta,rdstrb,mtype,\
    rdhld) (Uint32)( \
     _PER_FMK(EMIF,CECTL,WRSETUP,wrsetup)\
    |_PER_FMK(EMIF,CECTL,WRSTRB,wrstrb)\
    |_PER_FMK(EMIF,CECTL,WRHLD,wrhld)\
    |_PER_FMK(EMIF,CECTL,RDSETUP,rdsetup)\
    |_PER_FMK(EMIF,CECTL,TA,ta)\
    |_PER_FMK(EMIF,CECTL,RDSTRB,rdstrb)\
    |_PER_FMK(EMIF,CECTL,MTYPE,mtype)\
    |_PER_FMK(EMIF,CECTL,RDHLD,rdhld)\
  )
#endif



#if (!C11_SUPPORT)
  #define EMIF_CECTL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(EMIF,CECTL,WRSETUP)\
    |_PER_FDEFAULT(EMIF,CECTL,WRSTRB)\
    |_PER_FDEFAULT(EMIF,CECTL,WRHLD)\
    |_PER_FDEFAULT(EMIF,CECTL,RDSETUP)\
    |_PER_FDEFAULT(EMIF,CECTL,RDSTRB)\
    |_PER_FDEFAULT(EMIF,CECTL,MTYPE)\
    |_PER_FDEFAULT(EMIF,CECTL,RDHLD)\
  )

  #define EMIF_CECTL_RMK(wrsetup,wrstrb,wrhld,rdsetup,rdstrb,mtype,\
    rdhld) (Uint32)( \
     _PER_FMK(EMIF,CECTL,WRSETUP,wrsetup)\
    |_PER_FMK(EMIF,CECTL,WRSTRB,wrstrb)\
    |_PER_FMK(EMIF,CECTL,WRHLD,wrhld)\
    |_PER_FMK(EMIF,CECTL,RDSETUP,rdsetup)\
    |_PER_FMK(EMIF,CECTL,RDSTRB,rdstrb)\
    |_PER_FMK(EMIF,CECTL,MTYPE,mtype)\
    |_PER_FMK(EMIF,CECTL,RDHLD,rdhld)\
  )
#endif

  #define _EMIF_CECTL_FGET(N,FIELD)\
    _PER_FGET(_EMIF_CECTL##N##_ADDR,EMIF,CECTL,##FIELD)

  #define _EMIF_CECTL_FSET(N,FIELD,f)\
    _PER_FSET(_EMIF_CECTL##N##_ADDR,EMIF,CECTL,##FIELD,f)

  #define _EMIF_CECTL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_EMIF_CECTL##N##_ADDR,EMIF,CECTL,##FIELD,##SYM)

  #define _EMIF_CECTL0_FGET(FIELD) _EMIF_CECTL_FGET(0,##FIELD)
  #define _EMIF_CECTL1_FGET(FIELD) _EMIF_CECTL_FGET(1,##FIELD)
  #define _EMIF_CECTL2_FGET(FIELD) _EMIF_CECTL_FGET(2,##FIELD)
  #define _EMIF_CECTL3_FGET(FIELD) _EMIF_CECTL_FGET(3,##FIELD)

  #define _EMIF_CECTL0_FSET(FIELD,f) _EMIF_CECTL_FSET(0,##FIELD,f)
  #define _EMIF_CECTL1_FSET(FIELD,f) _EMIF_CECTL_FSET(1,##FIELD,f)
  #define _EMIF_CECTL2_FSET(FIELD,f) _EMIF_CECTL_FSET(2,##FIELD,f)
  #define _EMIF_CECTL3_FSET(FIELD,f) _EMIF_CECTL_FSET(3,##FIELD,f)

  #define _EMIF_CECTL0_FSETS(FIELD,SYM) _EMIF_CECTL_FSETS(0,##FIELD,##SYM)
  #define _EMIF_CECTL1_FSETS(FIELD,SYM) _EMIF_CECTL_FSETS(1,##FIELD,##SYM)
  #define _EMIF_CECTL2_FSETS(FIELD,SYM) _EMIF_CECTL_FSETS(2,##FIELD,##SYM)
  #define _EMIF_CECTL3_FSETS(FIELD,SYM) _EMIF_CECTL_FSETS(3,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  S D C T L        |
* |___________________|
*
* SDCTL   - SDRAM control regsiter
*
* FIELDS (msb -> lsb)
* (rw) SDBSZ (2)
* (rw) SDRSZ (2)
* (rw) SDCSZ (2)
* (rw) SDWID (1)
* (rw) RFEN
* (r)  INIT
* (rw) TRCD
* (rw) TRP
* (rw) TRC
*
* (1) - Field only exists for C01_SUPPORT
* (2) - Field only exists for C11_SUPPORT 
*
\******************************************************************************/
  #define _EMIF_SDCTL_OFFSET           6

  #define _EMIF_SDCTL_ADDR             0x01800018u

#if (C11_SUPPORT)
  #define _EMIF_SDCTL_SDBSZ_MASK       0x40000000u
  #define _EMIF_SDCTL_SDBSZ_SHIFT      0x0000001Eu
  #define  EMIF_SDCTL_SDBSZ_DEFAULT    0x00000000u
  #define  EMIF_SDCTL_SDBSZ_OF(x)      _VALUEOF(x)
  #define  EMIF_SDCTL_SDBSZ_2BANKS     0x00000000u
  #define  EMIF_SDCTL_SDBSZ_4BANKS     0x00000001u
#endif
  
#if (C11_SUPPORT)
  #define _EMIF_SDCTL_SDRSZ_MASK       0x30000000u
  #define _EMIF_SDCTL_SDRSZ_SHIFT      0x0000001Cu
  #define  EMIF_SDCTL_SDRSZ_DEFAULT    0x00000000u
  #define  EMIF_SDCTL_SDRSZ_OF(x)      _VALUEOF(x)
  #define  EMIF_SDCTL_SDRSZ_11ROW      0x00000000u
  #define  EMIF_SDCTL_SDRSZ_12ROW      0x00000001u
  #define  EMIF_SDCTL_SDRSZ_13ROW      0x00000002u
#endif
  
#if (C11_SUPPORT)
  #define _EMIF_SDCTL_SDCSZ_MASK       0x0C000000u
  #define _EMIF_SDCTL_SDCSZ_SHIFT      0x0000001Au
  #define  EMIF_SDCTL_SDCSZ_DEFAULT    0x00000000u
  #define  EMIF_SDCTL_SDCSZ_OF(x)      _VALUEOF(x)
  #define  EMIF_SDCTL_SDCSZ_9COL       0x00000000u
  #define  EMIF_SDCTL_SDCSZ_8COL       0x00000001u
  #define  EMIF_SDCTL_SDCSZ_10COL      0x00000002u
#endif
  
#if !(C11_SUPPORT) 
  #define _EMIF_SDCTL_SDWID_MASK       0x04000000u
  #define _EMIF_SDCTL_SDWID_SHIFT      0x0000001Au
  #define  EMIF_SDCTL_SDWID_DEFAULT    0x00000000u
  #define  EMIF_SDCTL_SDWID_OF(x)      _VALUEOF(x)
  #define  EMIF_SDCTL_SDWID_4X8BIT     0x00000000u
  #define  EMIF_SDCTL_SDWID_2X16BIT    0x00000001u
#endif
  
  #define _EMIF_SDCTL_RFEN_MASK        0x02000000u
  #define _EMIF_SDCTL_RFEN_SHIFT       0x00000019u
  #define  EMIF_SDCTL_RFEN_DEFAULT     0x00000001u
  #define  EMIF_SDCTL_RFEN_OF(x)       _VALUEOF(x)
  #define  EMIF_SDCTL_RFEN_DISABLE     0x00000000u
  #define  EMIF_SDCTL_RFEN_ENABLE      0x00000001u

  #define _EMIF_SDCTL_INIT_MASK        0x01000000u
  #define _EMIF_SDCTL_INIT_SHIFT       0x00000018u
  #define  EMIF_SDCTL_INIT_DEFAULT     0x00000001u
  #define  EMIF_SDCTL_INIT_OF(x)       _VALUEOF(x)
  #define  EMIF_SDCTL_INIT_NO          0x00000000u
  #define  EMIF_SDCTL_INIT_YES         0x00000001u

#if (C11_SUPPORT)
  #define _EMIF_SDCTL_TRCD_MASK        0x00F00000u
  #define _EMIF_SDCTL_TRCD_SHIFT       0x00000014u
  #define  EMIF_SDCTL_TRCD_DEFAULT     0x00000004u
  #define  EMIF_SDCTL_TRCD_OF(x)       _VALUEOF(x)
#else
  #define _EMIF_SDCTL_TRCD_MASK        0x00F00000u
  #define _EMIF_SDCTL_TRCD_SHIFT       0x00000014u
  #define  EMIF_SDCTL_TRCD_DEFAULT     0x00000008u
  #define  EMIF_SDCTL_TRCD_OF(x)       _VALUEOF(x)
#endif

  #define _EMIF_SDCTL_TRP_MASK         0x000F0000u
  #define _EMIF_SDCTL_TRP_SHIFT        0x00000010u
  #define  EMIF_SDCTL_TRP_DEFAULT      0x00000008u
  #define  EMIF_SDCTL_TRP_OF(x)        _VALUEOF(x)

  #define _EMIF_SDCTL_TRC_MASK         0x0000F000u
  #define _EMIF_SDCTL_TRC_SHIFT        0x0000000Cu
  #define  EMIF_SDCTL_TRC_DEFAULT      0x0000000Fu
  #define  EMIF_SDCTL_TRC_OF(x)        _VALUEOF(x)

  #define  EMIF_SDCTL_OF(x)            _VALUEOF(x)

#if (C11_SUPPORT)
  #define EMIF_SDCTL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(EMIF,SDCTL,SDBSZ)\
    |_PER_FDEFAULT(EMIF,SDCTL,SDRSZ)\
    |_PER_FDEFAULT(EMIF,SDCTL,SDCSZ)\
    |_PER_FDEFAULT(EMIF,SDCTL,RFEN)\
    |_PER_FDEFAULT(EMIF,SDCTL,INIT)\
    |_PER_FDEFAULT(EMIF,SDCTL,TRCD)\
    |_PER_FDEFAULT(EMIF,SDCTL,TRP)\
    |_PER_FDEFAULT(EMIF,SDCTL,TRC)\
  )

  #define EMIF_SDCTL_RMK(sdbsz,sdrsz,sdcsz,rfen,init,trcd,trp,trc) (Uint32)(\
     _PER_FMK(EMIF,SDCTL,SDBSZ,sdbsz)\
    |_PER_FMK(EMIF,SDCTL,SDRSZ,sdrsz)\
    |_PER_FMK(EMIF,SDCTL,SDCSZ,sdcsz)\
    |_PER_FMK(EMIF,SDCTL,RFEN,rfen)\
    |_PER_FMK(EMIF,SDCTL,INIT,init)\
    |_PER_FMK(EMIF,SDCTL,TRCD,trcd)\
    |_PER_FMK(EMIF,SDCTL,TRP,trp)\
    |_PER_FMK(EMIF,SDCTL,TRC,trc)\
  )
#endif

#if !(C11_SUPPORT)
  #define EMIF_SDCTL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(EMIF,SDCTL,SDWID)\
    |_PER_FDEFAULT(EMIF,SDCTL,RFEN)\
    |_PER_FDEFAULT(EMIF,SDCTL,INIT)\
    |_PER_FDEFAULT(EMIF,SDCTL,TRCD)\
    |_PER_FDEFAULT(EMIF,SDCTL,TRP)\
    |_PER_FDEFAULT(EMIF,SDCTL,TRC)\
  )

  #define EMIF_SDCTL_RMK(sdwid,rfen,init,trcd,trp,trc) (Uint32)(\
     _PER_FMK(EMIF,SDCTL,SDWID,sdwid)\
    |_PER_FMK(EMIF,SDCTL,RFEN,rfen)\
    |_PER_FMK(EMIF,SDCTL,INIT,init)\
    |_PER_FMK(EMIF,SDCTL,TRCD,trcd)\
    |_PER_FMK(EMIF,SDCTL,TRP,trp)\
    |_PER_FMK(EMIF,SDCTL,TRC,trc)\
  )
#endif

  #define _EMIF_SDCTL_FGET(FIELD)\
    _PER_FGET(_EMIF_SDCTL_ADDR,EMIF,SDCTL,##FIELD)

  #define _EMIF_SDCTL_FSET(FIELD,field)\
    _PER_FSET(_EMIF_SDCTL_ADDR,EMIF,SDCTL,##FIELD,field)

  #define _EMIF_SDCTL_FSETS(FIELD,SYM)\
    _PER_FSETS(_EMIF_SDCTL_ADDR,EMIF,SDCTL,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  S D T I M        |
* |___________________|
*
* SDTIM   - SDRAM timing register
*
* FIELDS (msb -> lsb)
* (rw) XRFR   (1)
* (r)  CNTR
* (rw) PERIOD
*
* (1) - Field only exists for C11_SUPPORT
*
\******************************************************************************/
  #define _EMIF_SDTIM_OFFSET           7

  #define _EMIF_SDTIM_ADDR             0x0180001Cu

#if (C11_SUPPORT)
  #define _EMIF_SDTIM_XRFR_MASK        0x03000000u
  #define _EMIF_SDTIM_XRFR_SHIFT       0x00000018u
  #define  EMIF_SDTIM_XRFR_DEFAULT     0x00000000u
  #define  EMIF_SDTIM_XRFR_OF(x)       _VALUEOF(x)
#endif

#if (C11_SUPPORT)
  #define _EMIF_SDTIM_CNTR_MASK        0x00FFF000u
  #define _EMIF_SDTIM_CNTR_SHIFT       0x0000000Cu
  #define  EMIF_SDTIM_CNTR_DEFAULT     0x000005DCu
  #define  EMIF_SDTIM_CNTR_OF(x)       _VALUEOF(x)
#else
  #define _EMIF_SDTIM_CNTR_MASK        0x00FFF000u
  #define _EMIF_SDTIM_CNTR_SHIFT       0x0000000Cu
  #define  EMIF_SDTIM_CNTR_DEFAULT     0x00000040u
  #define  EMIF_SDTIM_CNTR_OF(x)       _VALUEOF(x)
#endif
  
#if (C11_SUPPORT)
  #define _EMIF_SDTIM_PERIOD_MASK      0x00000FFFu
  #define _EMIF_SDTIM_PERIOD_SHIFT     0x00000000u
  #define  EMIF_SDTIM_PERIOD_DEFAULT   0x000005DCu
  #define  EMIF_SDTIM_PERIOD_OF(x)     _VALUEOF(x)
#else
  #define _EMIF_SDTIM_PERIOD_MASK      0x00000FFFu
  #define _EMIF_SDTIM_PERIOD_SHIFT     0x00000000u
  #define  EMIF_SDTIM_PERIOD_DEFAULT   0x00000040u
  #define  EMIF_SDTIM_PERIOD_OF(x)     _VALUEOF(x)
#endif

  #define  EMIF_SDTIM_OF(x)            _VALUEOF(x)

#if (C11_SUPPORT)
  #define EMIF_SDTIM_DEFAULT (Uint32)( \
     _PER_FDEFAULT(EMIF,SDTIM,XRFR)\
    |_PER_FDEFAULT(EMIF,SDTIM,CNTR)\
    |_PER_FDEFAULT(EMIF,SDTIM,PERIOD)\
  )

  #define EMIF_SDTIM_RMK(xrfr,period) (Uint32)(\
     _PER_FMK(EMIF,SDTIM,XRFR,xrfr)\
    |_PER_FMK(EMIF,SDTIM,PERIOD,period)\
  )
#endif

#if !(C11_SUPPORT)
  #define EMIF_SDTIM_DEFAULT (Uint32)( \
     _PER_FDEFAULT(EMIF,SDTIM,CNTR)\
    |_PER_FDEFAULT(EMIF,SDTIM,PERIOD)\
  )

  #define EMIF_SDTIM_RMK(period) (Uint32)(\
     _PER_FMK(EMIF,SDTIM,PERIOD,period)\
  )
#endif


  #define _EMIF_SDTIM_FGET(FIELD)\
    _PER_FGET(_EMIF_SDTIM_ADDR,EMIF,SDTIM,##FIELD)

  #define _EMIF_SDTIM_FSET(FIELD,field)\
    _PER_FSET(_EMIF_SDTIM_ADDR,EMIF,SDTIM,##FIELD,field)

  #define _EMIF_SDTIM_FSETS(FIELD,SYM)\
    _PER_FSETS(_EMIF_SDTIM_ADDR,EMIF,SDTIM,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  S D E X T        |
* |___________________|
*
* SDEXT   - SDRAM extension register (1)
*
* (1) - only supported on 6211,6711,6713,DA610,6711C,6712C
*
* FIELDS (msb -> lsb)
* (rw) WR2RD
* (rw) WR2DEAC
* (rw) WR2WR
* (rw) R2WDQM
* (rw) RD2WR
* (rw) RD2DEAC
* (rw) RD2RD
* (rw) THZP
* (rw) TWR
* (rw) TRRD
* (rw) TRAS
* (rw) TCL
*
\******************************************************************************/
#if (C11_SUPPORT)
  #define _EMIF_SDEXT_OFFSET           8

  #define _EMIF_SDEXT_ADDR             0x01800020u

  #define _EMIF_SDEXT_WR2RD_MASK       0x00100000u
  #define _EMIF_SDEXT_WR2RD_SHIFT      0x00000014u
  #define  EMIF_SDEXT_WR2RD_DEFAULT    0x00000001u
  #define  EMIF_SDEXT_WR2RD_OF(x)      _VALUEOF(x)

  #define _EMIF_SDEXT_WR2DEAC_MASK     0x000C0000u
  #define _EMIF_SDEXT_WR2DEAC_SHIFT    0x00000012u
  #define  EMIF_SDEXT_WR2DEAC_DEFAULT  0x00000001u
  #define  EMIF_SDEXT_WR2DEAC_OF(x)    _VALUEOF(x)

  #define _EMIF_SDEXT_WR2WR_MASK       0x00020000u
  #define _EMIF_SDEXT_WR2WR_SHIFT      0x00000011u
  #define  EMIF_SDEXT_WR2WR_DEFAULT    0x00000001u
  #define  EMIF_SDEXT_WR2WR_OF(x)      _VALUEOF(x)

  #define _EMIF_SDEXT_R2WDQM_MASK      0x00018000u
  #define _EMIF_SDEXT_R2WDQM_SHIFT     0x0000000Fu
  #define  EMIF_SDEXT_R2WDQM_DEFAULT   0x00000003u
  #define  EMIF_SDEXT_R2WDQM_OF(x)     _VALUEOF(x)

  #define _EMIF_SDEXT_RD2WR_MASK       0x00007000u
  #define _EMIF_SDEXT_RD2WR_SHIFT      0x0000000Cu
  #define  EMIF_SDEXT_RD2WR_DEFAULT    0x00000005u
  #define  EMIF_SDEXT_RD2WR_OF(x)      _VALUEOF(x)

  #define _EMIF_SDEXT_RD2DEAC_MASK     0x00000C00u
  #define _EMIF_SDEXT_RD2DEAC_SHIFT    0x0000000Au
  #define  EMIF_SDEXT_RD2DEAC_DEFAULT  0x00000003u
  #define  EMIF_SDEXT_RD2DEAC_OF(x)    _VALUEOF(x)

  #define _EMIF_SDEXT_RD2RD_MASK       0x00000200u
  #define _EMIF_SDEXT_RD2RD_SHIFT      0x00000009u
  #define  EMIF_SDEXT_RD2RD_DEFAULT    0x00000001u
  #define  EMIF_SDEXT_RD2RD_OF(x)      _VALUEOF(x)

  #define _EMIF_SDEXT_THZP_MASK        0x00000180u
  #define _EMIF_SDEXT_THZP_SHIFT       0x00000007u
  #define  EMIF_SDEXT_THZP_DEFAULT     0x00000002u
  #define  EMIF_SDEXT_THZP_OF(x)       _VALUEOF(x)

  #define _EMIF_SDEXT_TWR_MASK         0x00000060u
  #define _EMIF_SDEXT_TWR_SHIFT        0x00000005u
  #define  EMIF_SDEXT_TWR_DEFAULT      0x00000001u
  #define  EMIF_SDEXT_TWR_OF(x)        _VALUEOF(x)

  #define _EMIF_SDEXT_TRRD_MASK        0x00000010u
  #define _EMIF_SDEXT_TRRD_SHIFT       0x00000004u
  #define  EMIF_SDEXT_TRRD_DEFAULT     0x00000001u
  #define  EMIF_SDEXT_TRRD_OF(x)       _VALUEOF(x)

  #define _EMIF_SDEXT_TRAS_MASK        0x0000000Eu
  #define _EMIF_SDEXT_TRAS_SHIFT       0x00000001u
  #define  EMIF_SDEXT_TRAS_DEFAULT     0x00000007u
  #define  EMIF_SDEXT_TRAS_OF(x)       _VALUEOF(x)

  #define _EMIF_SDEXT_TCL_MASK         0x00000001u
  #define _EMIF_SDEXT_TCL_SHIFT        0x00000000u
  #define  EMIF_SDEXT_TCL_DEFAULT      0x00000001u
  #define  EMIF_SDEXT_TCL_OF(x)        _VALUEOF(x)

  #define  EMIF_SDEXT_OF(x)            _VALUEOF(x)

  #define EMIF_SDEXT_DEFAULT (Uint32)( \
     _PER_FDEFAULT(EMIF,SDEXT,WR2RD)\
    |_PER_FDEFAULT(EMIF,SDEXT,WR2DEAC)\
    |_PER_FDEFAULT(EMIF,SDEXT,WR2WR)\
    |_PER_FDEFAULT(EMIF,SDEXT,R2WDQM)\
    |_PER_FDEFAULT(EMIF,SDEXT,RD2WR)\
    |_PER_FDEFAULT(EMIF,SDEXT,RD2DEAC)\
    |_PER_FDEFAULT(EMIF,SDEXT,RD2RD)\
    |_PER_FDEFAULT(EMIF,SDEXT,THZP)\
    |_PER_FDEFAULT(EMIF,SDEXT,TWR)\
    |_PER_FDEFAULT(EMIF,SDEXT,TRRD)\
    |_PER_FDEFAULT(EMIF,SDEXT,TRAS)\
    |_PER_FDEFAULT(EMIF,SDEXT,TCL)\
  )

  #define EMIF_SDEXT_RMK(wr2rd,wr2deac,wr2wr,r2wdqm,rd2wr,rd2deac,\
    rd2rd,thzp,twr,trrd,tras,tcl) (Uint32)( \
     _PER_FMK(EMIF,SDEXT,WR2RD,wr2rd)\
    |_PER_FMK(EMIF,SDEXT,WR2DEAC,wr2deac)\
    |_PER_FMK(EMIF,SDEXT,WR2WR,wr2wr)\
    |_PER_FMK(EMIF,SDEXT,R2WDQM,r2wdqm)\
    |_PER_FMK(EMIF,SDEXT,RD2WR,rd2wr)\
    |_PER_FMK(EMIF,SDEXT,RD2DEAC,rd2deac)\
    |_PER_FMK(EMIF,SDEXT,RD2RD,rd2rd)\
    |_PER_FMK(EMIF,SDEXT,THZP,thzp)\
    |_PER_FMK(EMIF,SDEXT,TWR,twr)\
    |_PER_FMK(EMIF,SDEXT,TRRD,trrd)\
    |_PER_FMK(EMIF,SDEXT,TRAS,tras)\
    |_PER_FMK(EMIF,SDEXT,TCL,tcl)\
  )

  #define _EMIF_SDEXT_FGET(FIELD)\
    _PER_FGET(_EMIF_SDEXT_ADDR,EMIF,SDEXT,##FIELD)

  #define _EMIF_SDEXT_FSET(FIELD,field)\
    _PER_FSET(_EMIF_SDEXT_ADDR,EMIF,SDEXT,##FIELD,field)

  #define _EMIF_SDEXT_FSETS(FIELD,SYM)\
    _PER_FSETS(_EMIF_SDEXT_ADDR,EMIF,SDEXT,##FIELD,##SYM)

#endif

/*----------------------------------------------------------------------------*/

#endif /* EMIF_SUPPORT */
#endif /* _CSL_EMIFHAL_H_ */
/******************************************************************************\
* End of csl_emifhal.h
\******************************************************************************/

