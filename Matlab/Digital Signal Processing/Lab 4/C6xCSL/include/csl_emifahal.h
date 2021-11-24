/******************************************************************************\
*           Copyright (C) 2001 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_emifahal.h
* DATE CREATED.. 03/27/2001 
* LAST MODIFIED. 08/02/2004 - Adding support for C6418
*                03/27/2001
*                04/16/2004 Added PDTCTL register support 
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
* SDEXT   - SDRAM extension register 
* CESEC0  - EMIFA CE0 secondary control 
* CESEC1  - EMIFA CE1 secondary control 
* CESEC2  - EMIFA CE2 secondary control 
* CESEC3  - EMIFA CE3 secondary control 
* PDTCTL  - Peripheral device transfer control 
*
\******************************************************************************/
#ifndef _CSL_EMIFAHAL_H_
#define _CSL_EMIFAHAL_H_


#include <csl_stdinc.h>
#include <csl_chip.h>

#if (EMIFA_SUPPORT)
/******************************************************************************\
* MISC section
\******************************************************************************/
#define _EMIFA_BASE_GLOBAL   0x01800000u

/******************************************************************************\
* module level register/field access macros
\******************************************************************************/

  /* ----------------- */
  /* FIELD MAKE MACROS */
  /* ----------------- */

  #define EMIFA_FMK(REG,FIELD,x)\
    _PER_FMK(EMIFA,##REG,##FIELD,x)

  #define EMIFA_FMKS(REG,FIELD,SYM)\
    _PER_FMKS(EMIFA,##REG,##FIELD,##SYM)
 
 
  /* -------------------------------- */
  /* RAW REGISTER/FIELD ACCESS MACROS */
  /* -------------------------------- */

  #define EMIFA_ADDR(REG)\
    _EMIFA_##REG##_ADDR

  #define EMIFA_RGET(REG)\
    _PER_RGET(_EMIFA_##REG##_ADDR,EMIFA,##REG)

  #define EMIFA_RSET(REG,x)\
    _PER_RSET(_EMIFA_##REG##_ADDR,EMIFA,##REG,x)

  #define EMIFA_FGET(REG,FIELD)\
    _EMIFA_##REG##_FGET(##FIELD)

  #define EMIFA_FSET(REG,FIELD,x)\
    _EMIFA_##REG##_FSET(##FIELD,##x)

  #define EMIFA_FSETS(REG,FIELD,SYM)\
    _EMIFA_##REG##_FSETS(##FIELD,##SYM)
 
 
  /* ------------------------------------------ */
  /* ADDRESS BASED REGISTER/FIELD ACCESS MACROS */
  /* ------------------------------------------ */

  #define EMIFA_RGETA(addr,REG)\
    _PER_RGET(addr,EMIFA,##REG)

  #define EMIFA_RSETA(addr,REG,x)\
    _PER_RSET(addr,EMIFA,##REG,x)

  #define EMIFA_FGETA(addr,REG,FIELD)\
    _PER_FGET(addr,EMIFA,##REG,##FIELD)

  #define EMIFA_FSETA(addr,REG,FIELD,x)\
    _PER_FSET(addr,EMIFA,##REG,##FIELD,x)

  #define EMIFA_FSETSA(addr,REG,FIELD,SYM)\
    _PER_FSETS(addr,EMIFA,##REG,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  G B L C T L      |
* |___________________|
*
* GBLCTL  - global control register
*
* FIELDS (msb -> lsb)
* (rw) EK2RATE
* (rw) EK2HZ
* (rw) EK2EN
* (rw) BRMODE
* (r)  BUSREQ
* (r)  ARDY
* (r)  HOLD
* (r)  HOLDA
* (rw) NOHOLD
* (rw) EK1HZ
* (rw) EK1EN
* (rw) CLK4EN
* (rw) CLK6EN
*
\******************************************************************************/
  #define _EMIFA_GBLCTL_OFFSET          0

  #define _EMIFA_GBLCTL_ADDR            0x01800000u

  #define _EMIFA_GBLCTL_EK2RATE_MASK     0x000C0000u
  #define _EMIFA_GBLCTL_EK2RATE_SHIFT    0x00000012u
  #define  EMIFA_GBLCTL_EK2RATE_DEFAULT  0x00000002u
  #define  EMIFA_GBLCTL_EK2RATE_OF(x)    _VALUEOF(x)
  #define  EMIFA_GBLCTL_EK2RATE_FULLCLK  0x00000000u 
  #define  EMIFA_GBLCTL_EK2RATE_HALFCLK  0x00000001u 
  #define  EMIFA_GBLCTL_EK2RATE_QUARCLK  0x00000002u 

  #define _EMIFA_GBLCTL_EK2HZ_MASK       0x00020000u
  #define _EMIFA_GBLCTL_EK2HZ_SHIFT      0x00000011u
  #define  EMIFA_GBLCTL_EK2HZ_DEFAULT    0x00000000u
  #define  EMIFA_GBLCTL_EK2HZ_OF(x)      _VALUEOF(x)
  #define  EMIFA_GBLCTL_EK2HZ_CLK        0x00000000u 
  #define  EMIFA_GBLCTL_EK2HZ_HIGHZ      0x00000001u 

  #define _EMIFA_GBLCTL_EK2EN_MASK       0x00010000u
  #define _EMIFA_GBLCTL_EK2EN_SHIFT      0x00000010u
  #define  EMIFA_GBLCTL_EK2EN_DEFAULT    0x00000001u
  #define  EMIFA_GBLCTL_EK2EN_OF(x)      _VALUEOF(x)
  #define  EMIFA_GBLCTL_EK2EN_DISABLE    0x00000000u 
  #define  EMIFA_GBLCTL_EK2EN_ENABLE     0x00000001u 

  #define _EMIFA_GBLCTL_BRMODE_MASK     0x00002000u
  #define _EMIFA_GBLCTL_BRMODE_SHIFT    0x0000000Du
  #define  EMIFA_GBLCTL_BRMODE_DEFAULT  0x00000001u
  #define  EMIFA_GBLCTL_BRMODE_OF(x)    _VALUEOF(x)
  #define  EMIFA_GBLCTL_BRMODE_MSTATUS  0x00000000u 
  #define  EMIFA_GBLCTL_BRMODE_MRSTATUS 0x00000001u 

  #define _EMIFA_GBLCTL_BUSREQ_MASK     0x00000800u
  #define _EMIFA_GBLCTL_BUSREQ_SHIFT    0x0000000Bu
  #define  EMIFA_GBLCTL_BUSREQ_DEFAULT  0x00000000u
  #define  EMIFA_GBLCTL_BUSREQ_OF(x)    _VALUEOF(x)
  #define  EMIFA_GBLCTL_BUSREQ_LOW      0x00000000u
  #define  EMIFA_GBLCTL_BUSREQ_HIGH     0x00000001u

  #define _EMIFA_GBLCTL_ARDY_MASK       0x00000400u
  #define _EMIFA_GBLCTL_ARDY_SHIFT      0x0000000Au
  #define  EMIFA_GBLCTL_ARDY_DEFAULT    0x00000000u
  #define  EMIFA_GBLCTL_ARDY_OF(x)      _VALUEOF(x)
  #define  EMIFA_GBLCTL_ARDY_LOW        0x00000000u
  #define  EMIFA_GBLCTL_ARDY_HIGH       0x00000001u

  #define _EMIFA_GBLCTL_HOLD_MASK       0x00000200u
  #define _EMIFA_GBLCTL_HOLD_SHIFT      0x00000009u
  #define  EMIFA_GBLCTL_HOLD_DEFAULT    0x00000000u
  #define  EMIFA_GBLCTL_HOLD_OF(x)      _VALUEOF(x)
  #define  EMIFA_GBLCTL_HOLD_LOW        0x00000000u
  #define  EMIFA_GBLCTL_HOLD_HIGH       0x00000001u

  #define _EMIFA_GBLCTL_HOLDA_MASK      0x00000100u
  #define _EMIFA_GBLCTL_HOLDA_SHIFT     0x00000008u
  #define  EMIFA_GBLCTL_HOLDA_DEFAULT   0x00000000u
  #define  EMIFA_GBLCTL_HOLDA_OF(x)     _VALUEOF(x)
  #define  EMIFA_GBLCTL_HOLDA_LOW       0x00000000u
  #define  EMIFA_GBLCTL_HOLDA_HIGH      0x00000001u

  #define _EMIFA_GBLCTL_NOHOLD_MASK     0x00000080u
  #define _EMIFA_GBLCTL_NOHOLD_SHIFT    0x00000007u
  #define  EMIFA_GBLCTL_NOHOLD_DEFAULT  0x00000000u
  #define  EMIFA_GBLCTL_NOHOLD_OF(x)    _VALUEOF(x)
  #define  EMIFA_GBLCTL_NOHOLD_DISABLE  0x00000000u
  #define  EMIFA_GBLCTL_NOHOLD_ENABLE   0x00000001u

  #define _EMIFA_GBLCTL_EK1HZ_MASK      0x00000040u
  #define _EMIFA_GBLCTL_EK1HZ_SHIFT     0x00000006u
  #define  EMIFA_GBLCTL_EK1HZ_DEFAULT   0x00000001u
  #define  EMIFA_GBLCTL_EK1HZ_OF(x)     _VALUEOF(x)
  #define  EMIFA_GBLCTL_EK1HZ_CLK       0x00000000u 
  #define  EMIFA_GBLCTL_EK1HZ_HIGHZ     0x00000001u 

  #define _EMIFA_GBLCTL_EK1EN_MASK      0x00000020u
  #define _EMIFA_GBLCTL_EK1EN_SHIFT     0x00000005u
  #define  EMIFA_GBLCTL_EK1EN_DEFAULT   0x00000001u
  #define  EMIFA_GBLCTL_EK1EN_OF(x)     _VALUEOF(x)
  #define  EMIFA_GBLCTL_EK1EN_DISABLE   0x00000000u
  #define  EMIFA_GBLCTL_EK1EN_ENABLE    0x00000001u

  #define _EMIFA_GBLCTL_CLK4EN_MASK     0x00000010u
  #define _EMIFA_GBLCTL_CLK4EN_SHIFT    0x00000004u
  #define  EMIFA_GBLCTL_CLK4EN_DEFAULT  0x00000001u
  #define  EMIFA_GBLCTL_CLK4EN_OF(x)    _VALUEOF(x)
  #define  EMIFA_GBLCTL_CLK4EN_DISABLE  0x00000000u
  #define  EMIFA_GBLCTL_CLK4EN_ENABLE   0x00000001u

  #define _EMIFA_GBLCTL_CLK6EN_MASK     0x00000008u
  #define _EMIFA_GBLCTL_CLK6EN_SHIFT    0x00000003u
  #define  EMIFA_GBLCTL_CLK6EN_DEFAULT  0x00000001u
  #define  EMIFA_GBLCTL_CLK6EN_OF(x)    _VALUEOF(x)
  #define  EMIFA_GBLCTL_CLK6EN_DISABLE  0x00000000u
  #define  EMIFA_GBLCTL_CLK6EN_ENABLE   0x00000001u

  #define  EMIFA_GBLCTL_OF(x)           _VALUEOF(x)

  #define EMIFA_GBLCTL_DEFAULT (Uint32)( \
    0x00000004\
    |_PER_FDEFAULT(EMIFA,GBLCTL,EK2RATE)\
    |_PER_FDEFAULT(EMIFA,GBLCTL,EK2HZ)\
    |_PER_FDEFAULT(EMIFA,GBLCTL,EK2EN)\
    |_PER_FDEFAULT(EMIFA,GBLCTL,BRMODE)\
    |_PER_FDEFAULT(EMIFA,GBLCTL,BUSREQ)\
    |_PER_FDEFAULT(EMIFA,GBLCTL,ARDY)\
    |_PER_FDEFAULT(EMIFA,GBLCTL,HOLD)\
    |_PER_FDEFAULT(EMIFA,GBLCTL,HOLDA)\
    |_PER_FDEFAULT(EMIFA,GBLCTL,NOHOLD)\
    |_PER_FDEFAULT(EMIFA,GBLCTL,EK1HZ)\
    |_PER_FDEFAULT(EMIFA,GBLCTL,EK1EN)\
    |_PER_FDEFAULT(EMIFA,GBLCTL,CLK4EN)\
    |_PER_FDEFAULT(EMIFA,GBLCTL,CLK6EN)\
  )

  #define EMIFA_GBLCTL_RMK(ek2rate,ek2hz,ek2en,brmode,nohold,ek1hz,ek1en,clk4en,clk6en) \
    (Uint32)( \
     _PER_FMK(EMIFA,GBLCTL,EK2RATE,ek2rate)\
    |_PER_FMK(EMIFA,GBLCTL,EK2HZ,ek2hz)\
    |_PER_FMK(EMIFA,GBLCTL,EK2EN,ek2en)\
    |_PER_FMK(EMIFA,GBLCTL,BRMODE,brmode)\
    |_PER_FMK(EMIFA,GBLCTL,NOHOLD,nohold)\
    |_PER_FMK(EMIFA,GBLCTL,EK1HZ,ek1hz)\
    |_PER_FMK(EMIFA,GBLCTL,EK1EN,ek1en)\
    |_PER_FMK(EMIFA,GBLCTL,CLK4EN,clk4en)\
    |_PER_FMK(EMIFA,GBLCTL,CLK6EN,clk6en)\
  )

  #define _EMIFA_GBLCTL_FGET(FIELD)\
    _PER_FGET(_EMIFA_GBLCTL_ADDR,EMIFA,GBLCTL,##FIELD)

  #define _EMIFA_GBLCTL_FSET(FIELD,field)\
    _PER_FSET(_EMIFA_GBLCTL_ADDR,EMIFA,GBLCTL,##FIELD,field)

  #define _EMIFA_GBLCTL_FSETS(FIELD,SYM)\
    _PER_FSETS(_EMIFA_GBLCTL_ADDR,EMIFA,GBLCTL,##FIELD,##SYM)


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
* (rw) TA
* (rw) RDSTRB
* (rw) MTYPE
* (rw) RDHLD
*
\******************************************************************************/
  #define _EMIFA_CECTL0_OFFSET          2
  #define _EMIFA_CECTL1_OFFSET          1
  #define _EMIFA_CECTL2_OFFSET          4
  #define _EMIFA_CECTL3_OFFSET          5

  #define _EMIFA_CECTL0_ADDR            0x01800008u
  #define _EMIFA_CECTL1_ADDR            0x01800004u
  #define _EMIFA_CECTL2_ADDR            0x01800010u
  #define _EMIFA_CECTL3_ADDR            0x01800014u

  #define _EMIFA_CECTL_WRSETUP_MASK     0xF0000000u
  #define _EMIFA_CECTL_WRSETUP_SHIFT    0x0000001Cu
  #define  EMIFA_CECTL_WRSETUP_DEFAULT  0x0000000Fu
  #define  EMIFA_CECTL_WRSETUP_OF(x)    _VALUEOF(x)

  #define _EMIFA_CECTL_WRSTRB_MASK      0x0FC00000u
  #define _EMIFA_CECTL_WRSTRB_SHIFT     0x00000016u
  #define  EMIFA_CECTL_WRSTRB_DEFAULT   0x0000003Fu
  #define  EMIFA_CECTL_WRSTRB_OF(x)     _VALUEOF(x)

  #define _EMIFA_CECTL_WRHLD_MASK       0x00300000u
  #define _EMIFA_CECTL_WRHLD_SHIFT      0x00000014u
  #define  EMIFA_CECTL_WRHLD_DEFAULT    0x00000003u
  #define  EMIFA_CECTL_WRHLD_OF(x)      _VALUEOF(x)
  
  #define _EMIFA_CECTL_RDSETUP_MASK     0x000F0000u
  #define _EMIFA_CECTL_RDSETUP_SHIFT    0x00000010u
  #define  EMIFA_CECTL_RDSETUP_DEFAULT  0x0000000Fu
  #define  EMIFA_CECTL_RDSETUP_OF(x)    _VALUEOF(x)

  #define _EMIFA_CECTL_TA_MASK          0x0000C000u
  #define _EMIFA_CECTL_TA_SHIFT         0x0000000Eu
  #define  EMIFA_CECTL_TA_DEFAULT       0x00000003u
  #define  EMIFA_CECTL_TA_OF(x)         _VALUEOF(x)

  #define _EMIFA_CECTL_RDSTRB_MASK      0x00003F00u
  #define _EMIFA_CECTL_RDSTRB_SHIFT     0x00000008u
  #define  EMIFA_CECTL_RDSTRB_DEFAULT   0x0000003Fu
  #define  EMIFA_CECTL_RDSTRB_OF(x)     _VALUEOF(x)
  
  #define _EMIFA_CECTL_MTYPE_MASK       0x000000F0u
  #define _EMIFA_CECTL_MTYPE_SHIFT      0x00000004u
  #define  EMIFA_CECTL_MTYPE_DEFAULT    0x00000000u
  #define  EMIFA_CECTL_MTYPE_OF(x)      _VALUEOF(x)
  #define  EMIFA_CECTL_MTYPE_ASYNC8     0x00000000u
  #define  EMIFA_CECTL_MTYPE_ASYNC16    0x00000001u
  #define  EMIFA_CECTL_MTYPE_ASYNC32    0x00000002u
  #define  EMIFA_CECTL_MTYPE_SDRAM32    0x00000003u
  #define  EMIFA_CECTL_MTYPE_SYNC32     0x00000004u
  #define  EMIFA_CECTL_MTYPE_SDRAM8     0x00000008u
  #define  EMIFA_CECTL_MTYPE_SDRAM16    0x00000009u
  #define  EMIFA_CECTL_MTYPE_SYNC8      0x0000000Au
  #define  EMIFA_CECTL_MTYPE_SYNC16     0x0000000Bu
#if (!(CHIP_6410 || CHIP_6413 || CHIP_6418 ))
  #define  EMIFA_CECTL_MTYPE_ASYNC64    0x0000000Cu
  #define  EMIFA_CECTL_MTYPE_SDRAM64    0x0000000Du
  #define  EMIFA_CECTL_MTYPE_SYNC64     0x0000000Eu
#endif
  #define _EMIFA_CECTL_WRHLDMSB_MASK    0x00000008u
  #define _EMIFA_CECTL_WRHLDMSB_SHIFT   0x00000003u
  #define  EMIFA_CECTL_WRHLDMSB_DEFAULT 0x00000000u
  #define  EMIFA_CECTL_WRHLDMSB_OF(x)   _VALUEOF(x)

  #define _EMIFA_CECTL_RDHLD_MASK       0x00000007u
  #define _EMIFA_CECTL_RDHLD_SHIFT      0x00000000u
  #define  EMIFA_CECTL_RDHLD_DEFAULT    0x00000003u
  #define  EMIFA_CECTL_RDHLD_OF(x)      _VALUEOF(x)

  #define  EMIFA_CECTL_OF(x)            _VALUEOF(x)

  #define EMIFA_CECTL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(EMIFA,CECTL,WRSETUP)\
    |_PER_FDEFAULT(EMIFA,CECTL,WRSTRB)\
    |_PER_FDEFAULT(EMIFA,CECTL,WRHLD)\
    |_PER_FDEFAULT(EMIFA,CECTL,RDSETUP)\
    |_PER_FDEFAULT(EMIFA,CECTL,TA)\
    |_PER_FDEFAULT(EMIFA,CECTL,RDSTRB)\
    |_PER_FDEFAULT(EMIFA,CECTL,MTYPE)\
    |_PER_FDEFAULT(EMIFA,CECTL,WRHLDMSB)\
    |_PER_FDEFAULT(EMIFA,CECTL,RDHLD)\
  )
#if (CHIP_6413 || CHIP_6418 || CHIP_6410)
  /*Read only field TA has a value of 0x3 */
  #define EMIFA_CECTL_RMK(wrsetup,wrstrb,wrhld,rdsetup,rdstrb,mtype,\
    wrhldmsb,rdhld) (Uint32)( \
     _PER_FMK(EMIFA,CECTL,WRSETUP,wrsetup)\
    |_PER_FMK(EMIFA,CECTL,WRSTRB,wrstrb)\
    |_PER_FMK(EMIFA,CECTL,WRHLD,wrhld)\
    |_PER_FMK(EMIFA,CECTL,TA,0x3)\
    |_PER_FMK(EMIFA,CECTL,RDSETUP,rdsetup)\
    |_PER_FMK(EMIFA,CECTL,RDSTRB,rdstrb)\
    |_PER_FMK(EMIFA,CECTL,MTYPE,mtype)\
    |_PER_FMK(EMIFA,CECTL,WRHLDMSB,wrhldmsb)\
    |_PER_FMK(EMIFA,CECTL,RDHLD,rdhld)\
  )
#else
   #define EMIFA_CECTL_RMK(wrsetup,wrstrb,wrhld,ta,rdsetup,rdstrb,mtype,\
    wrhldmsb,rdhld) (Uint32)( \
     _PER_FMK(EMIFA,CECTL,WRSETUP,wrsetup)\
    |_PER_FMK(EMIFA,CECTL,WRSTRB,wrstrb)\
    |_PER_FMK(EMIFA,CECTL,WRHLD,wrhld)\
    |_PER_FMK(EMIFA,CECTL,TA,ta)\
    |_PER_FMK(EMIFA,CECTL,RDSETUP,rdsetup)\
    |_PER_FMK(EMIFA,CECTL,RDSTRB,rdstrb)\
    |_PER_FMK(EMIFA,CECTL,MTYPE,mtype)\
    |_PER_FMK(EMIFA,CECTL,WRHLDMSB,wrhldmsb)\
    |_PER_FMK(EMIFA,CECTL,RDHLD,rdhld)\
  )  
#endif    
  #define _EMIFA_CECTL_FGET(N,FIELD)\
    _PER_FGET(_EMIFA_CECTL##N##_ADDR,EMIFA,CECTL,##FIELD)

  #define _EMIFA_CECTL_FSET(N,FIELD,f)\
    _PER_FSET(_EMIFA_CECTL##N##_ADDR,EMIFA,CECTL,##FIELD,f)

  #define _EMIFA_CECTL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_EMIFA_CECTL##N##_ADDR,EMIFA,CECTL,##FIELD,##SYM)

  #define _EMIFA_CECTL0_FGET(FIELD) _EMIFA_CECTL_FGET(0,##FIELD)
  #define _EMIFA_CECTL1_FGET(FIELD) _EMIFA_CECTL_FGET(1,##FIELD)
  #define _EMIFA_CECTL2_FGET(FIELD) _EMIFA_CECTL_FGET(2,##FIELD)
  #define _EMIFA_CECTL3_FGET(FIELD) _EMIFA_CECTL_FGET(3,##FIELD)

  #define _EMIFA_CECTL0_FSET(FIELD,f) _EMIFA_CECTL_FSET(0,##FIELD,f)
  #define _EMIFA_CECTL1_FSET(FIELD,f) _EMIFA_CECTL_FSET(1,##FIELD,f)
  #define _EMIFA_CECTL2_FSET(FIELD,f) _EMIFA_CECTL_FSET(2,##FIELD,f)
  #define _EMIFA_CECTL3_FSET(FIELD,f) _EMIFA_CECTL_FSET(3,##FIELD,f)

  #define _EMIFA_CECTL0_FSETS(FIELD,SYM) _EMIFA_CECTL_FSETS(0,##FIELD,##SYM)
  #define _EMIFA_CECTL1_FSETS(FIELD,SYM) _EMIFA_CECTL_FSETS(1,##FIELD,##SYM)
  #define _EMIFA_CECTL2_FSETS(FIELD,SYM) _EMIFA_CECTL_FSETS(2,##FIELD,##SYM)
  #define _EMIFA_CECTL3_FSETS(FIELD,SYM) _EMIFA_CECTL_FSETS(3,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  S D C T L        |
* |___________________|
*
* SDCTL   - SDRAM control regsiter
*
* FIELDS (msb -> lsb)
* (rw) SDBSZ 
* (rw) SDRSZ 
* (rw) SDCSZ 
* (rw) RFEN
* (w)  INIT
* (rw) TRCD
* (rw) TRP
* (rw) TRC
* (rw) SLFRFR
*
\******************************************************************************/
  #define _EMIFA_SDCTL_OFFSET           6

  #define _EMIFA_SDCTL_ADDR             0x01800018u

  #define _EMIFA_SDCTL_SDBSZ_MASK       0x40000000u
  #define _EMIFA_SDCTL_SDBSZ_SHIFT      0x0000001Eu
  #define  EMIFA_SDCTL_SDBSZ_DEFAULT    0x00000000u
  #define  EMIFA_SDCTL_SDBSZ_OF(x)      _VALUEOF(x)
  #define  EMIFA_SDCTL_SDBSZ_2BANKS     0x00000000u
  #define  EMIFA_SDCTL_SDBSZ_4BANKS     0x00000001u
  
  #define _EMIFA_SDCTL_SDRSZ_MASK       0x30000000u
  #define _EMIFA_SDCTL_SDRSZ_SHIFT      0x0000001Cu
  #define  EMIFA_SDCTL_SDRSZ_DEFAULT    0x00000000u
  #define  EMIFA_SDCTL_SDRSZ_OF(x)      _VALUEOF(x)
  #define  EMIFA_SDCTL_SDRSZ_11ROW      0x00000000u
  #define  EMIFA_SDCTL_SDRSZ_12ROW      0x00000001u
  #define  EMIFA_SDCTL_SDRSZ_13ROW      0x00000002u
  
  #define _EMIFA_SDCTL_SDCSZ_MASK       0x0C000000u
  #define _EMIFA_SDCTL_SDCSZ_SHIFT      0x0000001Au
  #define  EMIFA_SDCTL_SDCSZ_DEFAULT    0x00000000u
  #define  EMIFA_SDCTL_SDCSZ_OF(x)      _VALUEOF(x)
  #define  EMIFA_SDCTL_SDCSZ_9COL       0x00000000u
  #define  EMIFA_SDCTL_SDCSZ_8COL       0x00000001u
  #define  EMIFA_SDCTL_SDCSZ_10COL      0x00000002u
  
  #define _EMIFA_SDCTL_RFEN_MASK        0x02000000u
  #define _EMIFA_SDCTL_RFEN_SHIFT       0x00000019u
  #define  EMIFA_SDCTL_RFEN_DEFAULT     0x00000001u
  #define  EMIFA_SDCTL_RFEN_OF(x)       _VALUEOF(x)
  #define  EMIFA_SDCTL_RFEN_DISABLE     0x00000000u
  #define  EMIFA_SDCTL_RFEN_ENABLE      0x00000001u

  #define _EMIFA_SDCTL_INIT_MASK        0x01000000u
  #define _EMIFA_SDCTL_INIT_SHIFT       0x00000018u
  #define  EMIFA_SDCTL_INIT_DEFAULT     0x00000001u
  #define  EMIFA_SDCTL_INIT_OF(x)       _VALUEOF(x)
  #define  EMIFA_SDCTL_INIT_NO          0x00000000u
  #define  EMIFA_SDCTL_INIT_YES         0x00000001u

  #define _EMIFA_SDCTL_TRCD_MASK        0x00F00000u
  #define _EMIFA_SDCTL_TRCD_SHIFT       0x00000014u
  #define  EMIFA_SDCTL_TRCD_DEFAULT     0x00000004u
  #define  EMIFA_SDCTL_TRCD_OF(x)       _VALUEOF(x)

  #define _EMIFA_SDCTL_TRP_MASK         0x000F0000u
  #define _EMIFA_SDCTL_TRP_SHIFT        0x00000010u
  #define  EMIFA_SDCTL_TRP_DEFAULT      0x00000008u
  #define  EMIFA_SDCTL_TRP_OF(x)        _VALUEOF(x)

  #define _EMIFA_SDCTL_TRC_MASK         0x0000F000u
  #define _EMIFA_SDCTL_TRC_SHIFT        0x0000000Cu
  #define  EMIFA_SDCTL_TRC_DEFAULT      0x0000000Fu
  #define  EMIFA_SDCTL_TRC_OF(x)        _VALUEOF(x)

  #define _EMIFA_SDCTL_SLFRFR_MASK      0x00000001u
  #define _EMIFA_SDCTL_SLFRFR_SHIFT     0x00000000u
  #define  EMIFA_SDCTL_SLFRFR_DEFAULT   0x00000000u
  #define  EMIFA_SDCTL_SLFRFR_OF(x)     _VALUEOF(x)
  #define  EMIFA_SDCTL_SLFRFR_DISABLE   0x00000000u
  #define  EMIFA_SDCTL_SLFRFR_ENABLE    0x00000001u

  #define  EMIFA_SDCTL_OF(x)            _VALUEOF(x)

  #define EMIFA_SDCTL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(EMIFA,SDCTL,SDBSZ)\
    |_PER_FDEFAULT(EMIFA,SDCTL,SDRSZ)\
    |_PER_FDEFAULT(EMIFA,SDCTL,SDCSZ)\
    |_PER_FDEFAULT(EMIFA,SDCTL,RFEN)\
    |_PER_FDEFAULT(EMIFA,SDCTL,INIT)\
    |_PER_FDEFAULT(EMIFA,SDCTL,TRCD)\
    |_PER_FDEFAULT(EMIFA,SDCTL,TRP)\
    |_PER_FDEFAULT(EMIFA,SDCTL,TRC)\
    |_PER_FDEFAULT(EMIFA,SDCTL,SLFRFR)\
  )

  #define EMIFA_SDCTL_RMK(sdbsz,sdrsz,sdcsz,rfen,init,trcd,trp,trc,slfrfr) (Uint32)(\
     _PER_FMK(EMIFA,SDCTL,SDBSZ,sdbsz)\
    |_PER_FMK(EMIFA,SDCTL,SDRSZ,sdrsz)\
    |_PER_FMK(EMIFA,SDCTL,SDCSZ,sdcsz)\
    |_PER_FMK(EMIFA,SDCTL,RFEN,rfen)\
    |_PER_FMK(EMIFA,SDCTL,INIT,init)\
    |_PER_FMK(EMIFA,SDCTL,TRCD,trcd)\
    |_PER_FMK(EMIFA,SDCTL,TRP,trp)\
    |_PER_FMK(EMIFA,SDCTL,TRC,trc)\
    |_PER_FMK(EMIFA,SDCTL,SLFRFR,slfrfr)\
  )

  #define _EMIFA_SDCTL_FGET(FIELD)\
    _PER_FGET(_EMIFA_SDCTL_ADDR,EMIFA,SDCTL,##FIELD)

  #define _EMIFA_SDCTL_FSET(FIELD,field)\
    _PER_FSET(_EMIFA_SDCTL_ADDR,EMIFA,SDCTL,##FIELD,field)

  #define _EMIFA_SDCTL_FSETS(FIELD,SYM)\
    _PER_FSETS(_EMIFA_SDCTL_ADDR,EMIFA,SDCTL,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  S D T I M        |
* |___________________|
*
* SDTIM   - SDRAM timing register
*
* FIELDS (msb -> lsb)
* (rw) XRFR
* (r)  CNTR
* (rw) PERIOD
*
\******************************************************************************/
  #define _EMIFA_SDTIM_OFFSET           7

  #define _EMIFA_SDTIM_ADDR             0x0180001Cu

  #define _EMIFA_SDTIM_XRFR_MASK        0x03000000u
  #define _EMIFA_SDTIM_XRFR_SHIFT       0x00000018u
  #define  EMIFA_SDTIM_XRFR_DEFAULT     0x00000000u
  #define  EMIFA_SDTIM_XRFR_OF(x)       _VALUEOF(x)

  #define _EMIFA_SDTIM_CNTR_MASK        0x00FFF000u
  #define _EMIFA_SDTIM_CNTR_SHIFT       0x0000000Cu
  #define  EMIFA_SDTIM_CNTR_DEFAULT     0x000005DCu
  #define  EMIFA_SDTIM_CNTR_OF(x)       _VALUEOF(x)
  
  #define _EMIFA_SDTIM_PERIOD_MASK      0x00000FFFu
  #define _EMIFA_SDTIM_PERIOD_SHIFT     0x00000000u
  #define  EMIFA_SDTIM_PERIOD_DEFAULT   0x000005DCu
  #define  EMIFA_SDTIM_PERIOD_OF(x)     _VALUEOF(x)

  #define  EMIFA_SDTIM_OF(x)            _VALUEOF(x)

  #define EMIFA_SDTIM_DEFAULT (Uint32)( \
     _PER_FDEFAULT(EMIFA,SDTIM,XRFR)\
    |_PER_FDEFAULT(EMIFA,SDTIM,CNTR)\
    |_PER_FDEFAULT(EMIFA,SDTIM,PERIOD)\
  )

  #define EMIFA_SDTIM_RMK(xrfr,period) (Uint32)(\
     _PER_FMK(EMIFA,SDTIM,XRFR,xrfr)\
    |_PER_FMK(EMIFA,SDTIM,PERIOD,period)\
  )

  #define _EMIFA_SDTIM_FGET(FIELD)\
    _PER_FGET(_EMIFA_SDTIM_ADDR,EMIFA,SDTIM,##FIELD)

  #define _EMIFA_SDTIM_FSET(FIELD,field)\
    _PER_FSET(_EMIFA_SDTIM_ADDR,EMIFA,SDTIM,##FIELD,field)

  #define _EMIFA_SDTIM_FSETS(FIELD,SYM)\
    _PER_FSETS(_EMIFA_SDTIM_ADDR,EMIFA,SDTIM,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  S D E X T        |
* |___________________|
*
* SDEXT   - SDRAM extension register
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
  #define _EMIFA_SDEXT_OFFSET           8

  #define _EMIFA_SDEXT_ADDR             0x01800020u

  #define _EMIFA_SDEXT_WR2RD_MASK       0x00100000u
  #define _EMIFA_SDEXT_WR2RD_SHIFT      0x00000014u
  #define  EMIFA_SDEXT_WR2RD_DEFAULT    0x00000001u
  #define  EMIFA_SDEXT_WR2RD_OF(x)      _VALUEOF(x)

  #define _EMIFA_SDEXT_WR2DEAC_MASK     0x000C0000u
  #define _EMIFA_SDEXT_WR2DEAC_SHIFT    0x00000012u
  #define  EMIFA_SDEXT_WR2DEAC_DEFAULT  0x00000001u
  #define  EMIFA_SDEXT_WR2DEAC_OF(x)    _VALUEOF(x)

  #define _EMIFA_SDEXT_WR2WR_MASK       0x00020000u
  #define _EMIFA_SDEXT_WR2WR_SHIFT      0x00000011u
  #define  EMIFA_SDEXT_WR2WR_DEFAULT    0x00000001u
  #define  EMIFA_SDEXT_WR2WR_OF(x)      _VALUEOF(x)

  #define _EMIFA_SDEXT_R2WDQM_MASK      0x00018000u
  #define _EMIFA_SDEXT_R2WDQM_SHIFT     0x0000000Fu
  #define  EMIFA_SDEXT_R2WDQM_DEFAULT   0x00000002u
  #define  EMIFA_SDEXT_R2WDQM_OF(x)     _VALUEOF(x)

  #define _EMIFA_SDEXT_RD2WR_MASK       0x00007000u
  #define _EMIFA_SDEXT_RD2WR_SHIFT      0x0000000Cu
  #define  EMIFA_SDEXT_RD2WR_DEFAULT    0x00000005u
  #define  EMIFA_SDEXT_RD2WR_OF(x)      _VALUEOF(x)

  #define _EMIFA_SDEXT_RD2DEAC_MASK     0x00000C00u
  #define _EMIFA_SDEXT_RD2DEAC_SHIFT    0x0000000Au
  #define  EMIFA_SDEXT_RD2DEAC_DEFAULT  0x00000003u
  #define  EMIFA_SDEXT_RD2DEAC_OF(x)    _VALUEOF(x)

  #define _EMIFA_SDEXT_RD2RD_MASK       0x00000200u
  #define _EMIFA_SDEXT_RD2RD_SHIFT      0x00000009u
  #define  EMIFA_SDEXT_RD2RD_DEFAULT    0x00000001u
  #define  EMIFA_SDEXT_RD2RD_OF(x)      _VALUEOF(x)

  #define _EMIFA_SDEXT_THZP_MASK        0x00000180u
  #define _EMIFA_SDEXT_THZP_SHIFT       0x00000007u
  #define  EMIFA_SDEXT_THZP_DEFAULT     0x00000002u
  #define  EMIFA_SDEXT_THZP_OF(x)       _VALUEOF(x)

  #define _EMIFA_SDEXT_TWR_MASK         0x00000060u
  #define _EMIFA_SDEXT_TWR_SHIFT        0x00000005u
  #define  EMIFA_SDEXT_TWR_DEFAULT      0x00000001u
  #define  EMIFA_SDEXT_TWR_OF(x)        _VALUEOF(x)

  #define _EMIFA_SDEXT_TRRD_MASK        0x00000010u
  #define _EMIFA_SDEXT_TRRD_SHIFT       0x00000004u
  #define  EMIFA_SDEXT_TRRD_DEFAULT     0x00000001u
  #define  EMIFA_SDEXT_TRRD_OF(x)       _VALUEOF(x)

  #define _EMIFA_SDEXT_TRAS_MASK        0x0000000Eu
  #define _EMIFA_SDEXT_TRAS_SHIFT       0x00000001u
  #define  EMIFA_SDEXT_TRAS_DEFAULT     0x00000007u
  #define  EMIFA_SDEXT_TRAS_OF(x)       _VALUEOF(x)

  #define _EMIFA_SDEXT_TCL_MASK         0x00000001u
  #define _EMIFA_SDEXT_TCL_SHIFT        0x00000000u
  #define  EMIFA_SDEXT_TCL_DEFAULT      0x00000001u
  #define  EMIFA_SDEXT_TCL_OF(x)        _VALUEOF(x)

  #define  EMIFA_SDEXT_OF(x)            _VALUEOF(x)

  #define EMIFA_SDEXT_DEFAULT (Uint32)( \
     _PER_FDEFAULT(EMIFA,SDEXT,WR2RD)\
    |_PER_FDEFAULT(EMIFA,SDEXT,WR2DEAC)\
    |_PER_FDEFAULT(EMIFA,SDEXT,WR2WR)\
    |_PER_FDEFAULT(EMIFA,SDEXT,R2WDQM)\
    |_PER_FDEFAULT(EMIFA,SDEXT,RD2WR)\
    |_PER_FDEFAULT(EMIFA,SDEXT,RD2DEAC)\
    |_PER_FDEFAULT(EMIFA,SDEXT,RD2RD)\
    |_PER_FDEFAULT(EMIFA,SDEXT,THZP)\
    |_PER_FDEFAULT(EMIFA,SDEXT,TWR)\
    |_PER_FDEFAULT(EMIFA,SDEXT,TRRD)\
    |_PER_FDEFAULT(EMIFA,SDEXT,TRAS)\
    |_PER_FDEFAULT(EMIFA,SDEXT,TCL)\
  )

  #define EMIFA_SDEXT_RMK(wr2rd,wr2deac,wr2wr,r2wdqm,rd2wr,rd2deac,\
    rd2rd,thzp,twr,trrd,tras,tcl) (Uint32)( \
     _PER_FMK(EMIFA,SDEXT,WR2RD,wr2rd)\
    |_PER_FMK(EMIFA,SDEXT,WR2DEAC,wr2deac)\
    |_PER_FMK(EMIFA,SDEXT,WR2WR,wr2wr)\
    |_PER_FMK(EMIFA,SDEXT,R2WDQM,r2wdqm)\
    |_PER_FMK(EMIFA,SDEXT,RD2WR,rd2wr)\
    |_PER_FMK(EMIFA,SDEXT,RD2DEAC,rd2deac)\
    |_PER_FMK(EMIFA,SDEXT,RD2RD,rd2rd)\
    |_PER_FMK(EMIFA,SDEXT,THZP,thzp)\
    |_PER_FMK(EMIFA,SDEXT,TWR,twr)\
    |_PER_FMK(EMIFA,SDEXT,TRRD,trrd)\
    |_PER_FMK(EMIFA,SDEXT,TRAS,tras)\
    |_PER_FMK(EMIFA,SDEXT,TCL,tcl)\
  )

  #define _EMIFA_SDEXT_FGET(FIELD)\
    _PER_FGET(_EMIFA_SDEXT_ADDR,EMIFA,SDEXT,##FIELD)

  #define _EMIFA_SDEXT_FSET(FIELD,field)\
    _PER_FSET(_EMIFA_SDEXT_ADDR,EMIFA,SDEXT,##FIELD,field)

  #define _EMIFA_SDEXT_FSETS(FIELD,SYM)\
    _PER_FSETS(_EMIFA_SDEXT_ADDR,EMIFA,SDEXT,##FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  C E x S E C      |
* |___________________|
*
* CESEC0 - CE space secondary control register 0
* CESEC1 - CE space secondary control register 1
* CESEC2 - CE space secondary control register 2
* CESEC3 - CE space secondary control register 3
*
* FIELDS (msb -> lsb)
* (rw) SNCCLK
* (rw) RENEN
* (rw) CEEXT
* (rw) SYNCWL
* (rw) SYNCRL
*
\******************************************************************************/
  #define _EMIFA_CESEC0_OFFSET          18
  #define _EMIFA_CESEC1_OFFSET          17
  #define _EMIFA_CESEC2_OFFSET          20
  #define _EMIFA_CESEC3_OFFSET          21

  #define _EMIFA_CESEC0_ADDR            0x01800048u
  #define _EMIFA_CESEC1_ADDR            0x01800044u
  #define _EMIFA_CESEC2_ADDR            0x01800050u
  #define _EMIFA_CESEC3_ADDR            0x01800054u

  #define _EMIFA_CESEC_SNCCLK_MASK      0x00000040u
  #define _EMIFA_CESEC_SNCCLK_SHIFT     0x00000006u
  #define  EMIFA_CESEC_SNCCLK_DEFAULT   0x00000000u
  #define  EMIFA_CESEC_SNCCLK_OF(x)     _VALUEOF(x)
  #define  EMIFA_CESEC_SNCCLK_ECLKOUT1  0x00000000u
  #define  EMIFA_CESEC_SNCCLK_ECLKOUT2  0x00000001u

  #define _EMIFA_CESEC_RENEN_MASK      0x00000020u
  #define _EMIFA_CESEC_RENEN_SHIFT     0x00000005u
  #define  EMIFA_CESEC_RENEN_DEFAULT   0x00000000u
  #define  EMIFA_CESEC_RENEN_OF(x)     _VALUEOF(x)
  #define  EMIFA_CESEC_RENEN_ADS       0x00000000u
  #define  EMIFA_CESEC_RENEN_READ      0x00000001u

  #define _EMIFA_CESEC_CEEXT_MASK      0x00000010u
  #define _EMIFA_CESEC_CEEXT_SHIFT     0x00000004u
  #define  EMIFA_CESEC_CEEXT_DEFAULT   0x00000000u
  #define  EMIFA_CESEC_CEEXT_OF(x)     _VALUEOF(x)
  #define  EMIFA_CESEC_CEEXT_INACTIVE  0x00000000u
  #define  EMIFA_CESEC_CEEXT_ACTIVE    0x00000001u

  #define _EMIFA_CESEC_SYNCWL_MASK      0x0000000Cu
  #define _EMIFA_CESEC_SYNCWL_SHIFT     0x00000002u
  #define  EMIFA_CESEC_SYNCWL_DEFAULT   0x00000000u
  #define  EMIFA_CESEC_SYNCWL_OF(x)     _VALUEOF(x)
  #define  EMIFA_CESEC_SYNCWL_0CYCLE    0x00000000u
  #define  EMIFA_CESEC_SYNCWL_1CYCLE    0x00000001u
  #define  EMIFA_CESEC_SYNCWL_2CYCLE    0x00000002u
  #define  EMIFA_CESEC_SYNCWL_3CYCLE    0x00000003u

  #define _EMIFA_CESEC_SYNCRL_MASK      0x00000003u
  #define _EMIFA_CESEC_SYNCRL_SHIFT     0x00000000u
  #define  EMIFA_CESEC_SYNCRL_DEFAULT   0x00000002u
  #define  EMIFA_CESEC_SYNCRL_OF(x)     _VALUEOF(x)
  #define  EMIFA_CESEC_SYNCRL_0CYCLE    0x00000000u
  #define  EMIFA_CESEC_SYNCRL_1CYCLE    0x00000001u
  #define  EMIFA_CESEC_SYNCRL_2CYCLE    0x00000002u
  #define  EMIFA_CESEC_SYNCRL_3CYCLE    0x00000003u

  #define  EMIFA_CESEC_OF(x)            _VALUEOF(x)

  #define EMIFA_CESEC_DEFAULT (Uint32)( \
     _PER_FDEFAULT(EMIFA,CESEC,SNCCLK)\
    |_PER_FDEFAULT(EMIFA,CESEC,RENEN)\
    |_PER_FDEFAULT(EMIFA,CESEC,CEEXT)\
    |_PER_FDEFAULT(EMIFA,CESEC,SYNCWL)\
    |_PER_FDEFAULT(EMIFA,CESEC,SYNCRL)\
  )

  #define EMIFA_CESEC_RMK(sncclk,renen,ceext,syncwl,syncrl)\
    (Uint32)( \
     _PER_FMK(EMIFA,CESEC,SNCCLK,sncclk)\
    |_PER_FMK(EMIFA,CESEC,RENEN,renen)\
    |_PER_FMK(EMIFA,CESEC,CEEXT,ceext)\
    |_PER_FMK(EMIFA,CESEC,SYNCWL,syncwl)\
    |_PER_FMK(EMIFA,CESEC,SYNCRL,syncrl)\
  )

  #define _EMIFA_CESEC_FGET(N,FIELD)\
    _PER_FGET(_EMIFA_CESEC##N##_ADDR,EMIFA,CESEC,##FIELD)

  #define _EMIFA_CESEC_FSET(N,FIELD,f)\
    _PER_FSET(_EMIFA_CESEC##N##_ADDR,EMIFA,CESEC,##FIELD,f)

  #define _EMIFA_CESEC_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_EMIFA_CESEC##N##_ADDR,EMIFA,CESEC,##FIELD,##SYM)

  #define _EMIFA_CESEC0_FGET(FIELD) _EMIFA_CESEC_FGET(0,##FIELD)
  #define _EMIFA_CESEC1_FGET(FIELD) _EMIFA_CESEC_FGET(1,##FIELD)
  #define _EMIFA_CESEC2_FGET(FIELD) _EMIFA_CESEC_FGET(2,##FIELD)
  #define _EMIFA_CESEC3_FGET(FIELD) _EMIFA_CESEC_FGET(3,##FIELD)

  #define _EMIFA_CESEC0_FSET(FIELD,f) _EMIFA_CESEC_FSET(0,##FIELD,f)
  #define _EMIFA_CESEC1_FSET(FIELD,f) _EMIFA_CESEC_FSET(1,##FIELD,f)
  #define _EMIFA_CESEC2_FSET(FIELD,f) _EMIFA_CESEC_FSET(2,##FIELD,f)
  #define _EMIFA_CESEC3_FSET(FIELD,f) _EMIFA_CESEC_FSET(3,##FIELD,f)

  #define _EMIFA_CESEC0_FSETS(FIELD,SYM) _EMIFA_CESEC_FSETS(0,##FIELD,##SYM)
  #define _EMIFA_CESEC1_FSETS(FIELD,SYM) _EMIFA_CESEC_FSETS(1,##FIELD,##SYM)
  #define _EMIFA_CESEC2_FSETS(FIELD,SYM) _EMIFA_CESEC_FSETS(2,##FIELD,##SYM)
  #define _EMIFA_CESEC3_FSETS(FIELD,SYM) _EMIFA_CESEC_FSETS(3,##FIELD,##SYM)

   
/******************************************************************************\
* _____________________
* |                   |
* |  P D T C T L      |
* |___________________|
*
* PDTCTL   - Peripheral device transfer (PDT) control
*
* FIELDS (msb -> lsb)
* (rw) PDTWL
* (rw) PDTRL
*
\******************************************************************************/
  #define _EMIFA_PDTCTL_OFFSET          16 

  #define _EMIFA_PDTCTL_ADDR            0x01800040u

  #define _EMIFA_PDTCTL_PDTWL_MASK      0x0000000Cu
  #define _EMIFA_PDTCTL_PDTWL_SHIFT     0x00000002u
  #define  EMIFA_PDTCTL_PDTWL_DEFAULT   0x00000000u
  #define  EMIFA_PDTCTL_PDTWL_OF(x)     _VALUEOF(x)
  #define  EMIFA_PDTCTL_PDTWL_0CYCLE    0x00000000u
  #define  EMIFA_PDTCTL_PDTWL_1CYCLE    0x00000001u
  #define  EMIFA_PDTCTL_PDTWL_2CYCLE    0x00000002u
  #define  EMIFA_PDTCTL_PDTWL_3CYCLE    0x00000003u

  #define _EMIFA_PDTCTL_PDTRL_MASK      0x000C0003u
  #define _EMIFA_PDTCTL_PDTRL_SHIFT     0x00000000u
  #define  EMIFA_PDTCTL_PDTRL_DEFAULT   0x00000000u
  #define  EMIFA_PDTCTL_PDTRL_OF(x)     _VALUEOF(x)
  #define  EMIFA_PDTCTL_PDTRL_0CYCLE    0x00000000u
  #define  EMIFA_PDTCTL_PDTRL_1CYCLE    0x00000001u
  #define  EMIFA_PDTCTL_PDTRL_2CYCLE    0x00000002u
  #define  EMIFA_PDTCTL_PDTRL_3CYCLE    0x00000003u


  #define EMIFA_PDTCTL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(EMIFA,PDTCTL,PDTWL)\
    |_PER_FDEFAULT(EMIFA,PDTCTL,PDTRL)\
  )

  #define EMIFA_PDTCTL_RMK(pdtwl,pdtrl) (Uint32)( \
     _PER_FMK(EMIFA,PDTCTL,PDTWL,pdtwl)\
    |_PER_FMK(EMIFA,PDTCTL,PDTRL,pdtrl)\
  )

  #define _EMIFA_PDTCTL_FGET(FIELD)\
    _PER_FGET(_EMIFA_PDTCTL_ADDR,EMIFA,PDTCTL,##FIELD)

  #define _EMIFA_PDTCTL_FSET(FIELD,field)\
    _PER_FSET(_EMIFA_PDTCTL_ADDR,EMIFA,PDTCTL,##FIELD,field)

  #define _EMIFA_PDTCTL_FSETS(FIELD,SYM)\
    _PER_FSETS(_EMIFA_PDTCTL_ADDR,EMIFA,PDTCTL,##FIELD,##SYM)

#endif /* EMIFA_SUPPORT */

#endif /* _CSL_EMIFHAL_H_ */
/******************************************************************************\
* End of csl_emifahal.h
\******************************************************************************/

