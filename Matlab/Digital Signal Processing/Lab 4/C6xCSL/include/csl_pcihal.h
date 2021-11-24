/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_pcihal.h
* DATE CREATED.. 10/02/2000
* LAST MODIFIED. 26/07/2005 - Changed the field value from DMA to PCI in _PER_FMK
*                             and _PER_FMKS macro.
*                08/02/2004 - Adding support for C6418
*                06/09/2003
*------------------------------------------------------------------------------
* REGISTERS
*
*   RSTSRC   - Reset Source/Status register
*   PMDCSR   - Power Management DSP Control/Status register
*   PCIIS    - PCI Interrupt Source register
*   PCIIEN   - PCI Interrupt Enable register
*   DSPMA    - DSP Master Address register
*   PCIMA    - PCI Master Address register
*   PCIMC    - PCI Master Control register
*   CDSPA    - Current DSP Address register
*   CPCIA    - Current PCI Address regsiter
*   CCNT     - Current Byte Count register
*   HALT     - PCI Transfer Halt register (1)
*   EEADD    - EEPROM Address register
*   EEDAT    - EEPROM Date register
*   EECTL    - EEPROM Control register
*   TRCTL    - Transfer request control register(C64x Only)
*
*   (1) not supported by C64x devices
\******************************************************************************/
#ifndef _CSL_PCIHAL_H_
#define _CSL_PCIHAL_H_

#include <csl_stdinc.h>


#if (PCI_SUPPORT)
/******************************************************************************\
* MISC section
\******************************************************************************/
#if (C64_SUPPORT)
  #define _PCI_BASE1_GLOBAL             0x01C00000u
  #define _PCI_BASE2_GLOBAL             0x01C20000u
  #define _PCI_BASE3_GLOBAL             0x01C30000u
#else
  #define _PCI_BASE1_GLOBAL             0x01A40000u
  #define _PCI_BASE2_GLOBAL             0x01A80000u
#endif

/******************************************************************************\
* module level register/field access macros
\******************************************************************************/

  /* ----------------- */
  /* FIELD MAKE MACROS */
  /* ----------------- */

  #define PCI_FMK(REG,FIELD,x)\
    _PER_FMK(PCI,##REG,##FIELD,x)

  #define PCI_FMKS(REG,FIELD,SYM)\
    _PER_FMKS(PCI,##REG,##FIELD,##SYM)


  /* -------------------------------- */
  /* RAW REGISTER/FIELD ACCESS MACROS */
  /* -------------------------------- */

  #define PCI_ADDR(REG)\
    _PCI_##REG##_ADDR

  #define PCI_RGET(REG)\
    _PER_RGET(_PCI_##REG##_ADDR,PCI,##REG)

  #define PCI_RSET(REG,x)\
    _PER_RSET(_PCI_##REG##_ADDR,PCI,##REG,x)

  #define PCI_FGET(REG,FIELD)\
    _PCI_##REG##_FGET(##FIELD)

  #define PCI_FSET(REG,FIELD,x)\
    _PCI_##REG##_FSET(##FIELD,##x)

  #define PCI_FSETS(REG,FIELD,SYM)\
    _PCI_##REG##_FSETS(##FIELD,##SYM)


  /* ------------------------------------------ */
  /* ADDRESS BASED REGISTER/FIELD ACCESS MACROS */
  /* ------------------------------------------ */

  #define PCI_RGETA(addr,REG)\
    _PER_RGET(addr,PCI,##REG)

  #define PCI_RSETA(addr,REG,x)\
    _PER_RSET(addr,PCI,##REG,x)

  #define PCI_FGETA(addr,REG,FIELD)\
    _PER_FGET(addr,PCI,##REG,##FIELD)

  #define PCI_FSETA(addr,REG,FIELD,x)\
    _PER_FSET(addr,PCI,##REG,##FIELD,x)

  #define PCI_FSETSA(addr,REG,FIELD,SYM)\
    _PER_FSETS(addr,PCI,##REG,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  R S T S R C      |
* |___________________|
*
* RSTSRC - DSP Reset Source-Status Regsiter
*
* FIELDS (msb -> lsb)
* (r)  CFGERR
* (r)  CFGDONE
* (w)  INTRST
* (w)  INTREQ
* (r)  WARMRST
* (r)  PRST
* (r)  RST
*
\******************************************************************************/
  #define _PCI_RSTSRC_OFFSET      0

  #if (C64_SUPPORT)
  #define _PCI_RSTSRC_ADDR        0x01C00000u
  #else
  #define _PCI_RSTSRC_ADDR        0x01A40000u
  #endif

  #define _PCI_RSTSRC_CFGERR_MASK         0x00000040u
  #define _PCI_RSTSRC_CFGERR_SHIFT        0x00000006u
  #define  PCI_RSTSRC_CFGERR_DEFAULT      0x00000000u
  #define  PCI_RSTSRC_CFGERR_OF(x)        _VALUEOF(x)


  #define _PCI_RSTSRC_CFGDONE_MASK        0x00000020u
  #define _PCI_RSTSRC_CFGDONE_SHIFT       0x00000005u
  #define  PCI_RSTSRC_CFGDONE_DEFAULT     0x00000000u
  #define  PCI_RSTSRC_CFGDONE_OF(x)       _VALUEOF(x)

  #define _PCI_RSTSRC_INTRST_MASK         0x00000010u
  #define _PCI_RSTSRC_INTRST_SHIFT        0x00000004u
  #define  PCI_RSTSRC_INTRST_DEFAULT      0x00000000u
  #define  PCI_RSTSRC_INTRST_OF(x)        _VALUEOF(x)
  #define  PCI_RSTSRC_INTRST_YES          0x00000001u
  #define  PCI_RSTSRC_INTRST_NO           0x00000000u

  #define _PCI_RSTSRC_INTREQ_MASK         0x00000008u
  #define _PCI_RSTSRC_INTREQ_SHIFT        0x00000003u
  #define  PCI_RSTSRC_INTREQ_DEFAULT      0x00000000u
  #define  PCI_RSTSRC_INTREQ_OF(x)        _VALUEOF(x)
  #define  PCI_RSTSRC_INTREQ_YES          0x00000001u
  #define  PCI_RSTSRC_INTREQ_NO           0x00000000u

  #define _PCI_RSTSRC_WARMRST_MASK        0x00000004u
  #define _PCI_RSTSRC_WARMRST_SHIFT       0x00000002u
  #define  PCI_RSTSRC_WARMRST_DEFAULT     0x00000000u
  #define  PCI_RSTSRC_WARMRST_OF(x)        _VALUEOF(x)


  #define _PCI_RSTSRC_PRST_MASK           0x00000002u
  #define _PCI_RSTSRC_PRST_SHIFT          0x00000001u
  #define  PCI_RSTSRC_PRST_DEFAULT        0x00000000u
  #define  PCI_RSTSRC_PRST_OF(x)		_VALUEOF(x)

  #define _PCI_RSTSRC_RST_MASK            0x00000001u
  #define _PCI_RSTSRC_RST_SHIFT        	0x00000000u
  #define  PCI_RSTSRC_RST_DEFAULT       	0x00000001u
  #define  PCI_RSTSRC_RST_OF(x)           _VALUEOF(x)

  #define  PCI_RSTSRC_OF(x)              _VALUEOF(x)


  #define PCI_RSTRC_DEFAULT (Uint32)( \
     _PER_FDEFAULT(PCI,RSTSRC,CFGERR) \
    |_PER_FDEFAULT(PCI,RSTSRC,CFGDONE) \
    |_PER_FDEFAULT(PCI,RSTSRC,INTRST) \
    |_PER_FDEFAULT(PCI,RSTSRC,INTREQ) \
    |_PER_FDEFAULT(PCI,RSTSRC,WARMRST) \
    |_PER_FDEFAULT(PCI,RSTSRC,PRST) \
    |_PER_FDEFAULT(PCI,RSTSRC,RST) \
   )

  #define PCI_RSTSRC_RMK(intrst,intreq) \
    (Uint32)( \
     _PER_FMK(PCI,RSTSRC,INTRST,intrst) \
    |_PER_FMK(PCI,RSTSRC,INTREQ,intreq) \
   )

 #define _PCI_RSTSRC_FGET(FIELD)\
    _PER_FGET(_PCI_RSTSRC_ADDR,PCI,RSTSRC,##FIELD)

 #define _PCI_RSTSRC_FSET(FIELD,field)\
    _PER_FSET(_PCI_RSTSRC_ADDR,PCI,RSTSRC,##FIELD,field)

 #define _PCI_RSTSRC_FSETS(FIELD,SYM)\
    _PER_FSETS(_PCI_RSTSRC_ADDR,PCI,RSTSRC,##FIELD,##SYM)



/******************************************************************************\
* _____________________
* |                   |
* |  P M D C S R      |
* |___________________|
*
* PMDCSR - Power Management DSP Control-Status Register
*
* FIELDS (msb -> lsb)
* (rw) HWPMECTL
* (r)  D3WARMONWKP
* (r)  D2WARMONWKP
* (rw) PMEEN
* (r)  PWRWKP
* (rw) PMESTAT
* (r)  PMEDRVN
* (r)  AUXDETECT
* (rw) CURSTATE
* (r)  REQSTATE
*
\******************************************************************************/
  #define _PCI_PMDCSR_OFFSET      1

 #if (C64_SUPPORT)
  #define _PCI_PMDCSR_ADDR                0x01C00004u
 #else
  #define _PCI_PMDCSR_ADDR                0x01A40004u
 #endif


  #define _PCI_PMDCSR_HWPMECTL_MASK          0x0007F800u
  #define _PCI_PMDCSR_HWPMECTL_SHIFT         0x0000000Bu
  #define  PCI_PMDCSR_HWPMECTL_DEFAULT       0x00000088u
  #define  PCI_PMDCSR_HWPMECTL_OF(x)         _VALUEOF(x)
  #define  PCI_PMDCSR_HWPMECTL_REQD0         0x00000001u
  #define  PCI_PMDCSR_HWPMECTL_REQD1         0x00000002u
  #define  PCI_PMDCSR_HWPMECTL_REQD2         0x00000003u
  #define  PCI_PMDCSR_HWPMECTL_REQD3         0x00000004u

  #define _PCI_PMDCSR_D3WARMONWKP_MASK       0x00000400u
  #define _PCI_PMDCSR_D3WARMONWKP_SHIFT      0x0000000Au
  #define  PCI_PMDCSR_D3WARMONWKP_DEFAULT    0x00000000u
  #define  PCI_PMDCSR_D3WARMONWKP_OF(x)      _VALUEOF(x)

  #define _PCI_PMDCSR_D2WARMONWKP_MASK       0x00000200u
  #define _PCI_PMDCSR_D2WARMONWKP_SHIFT      0x00000009u
  #define  PCI_PMDCSR_D2WARMONWKP_DEFAULT    0x00000000u
  #define  PCI_PMDCSR_D2WARMONWKP_OF(x)     _VALUEOF(x)

  #define _PCI_PMDCSR_PMEEN_MASK            0x00000100u
  #define _PCI_PMDCSR_PMEEN_SHIFT           0x00000008u
  #define  PCI_PMDCSR_PMEEN_DEFAULT         0x00000000u
  #define  PCI_PMDCSR_PMEEN_OF(x)           _VALUEOF(x)
  #define  PCI_PMDCSR_PMEEN_CLR             0x00000001u

  #define _PCI_PMDCSR_PMEWKP_MASK            0x00000080u
  #define _PCI_PMDCSR_PMEWKP_SHIFT           0x00000007u
  #define  PCI_PMDCSR_PMEWKP_DEFAULT         0x00000000u
  #define  PCI_PMDCSR_PMEWKP_OF(x)           _VALUEOF(x)

  #define _PCI_PMDCSR_PMESTAT_MASK           0x00000040u
  #define _PCI_PMDCSR_PMESTAT_SHIFT          0x00000006u
  #define  PCI_PMDCSR_PMESTAT_DEFAULT        0x00000000u
  #define  PCI_PMDCSR_PMESTAT_OF(x)          _VALUEOF(x)
  #define  PCI_PMDCSR_PMESTAT_SET            0x00000001u

  #define _PCI_PMDCSR_PMEDRVN_MASK           0x00000020u
  #define _PCI_PMDCSR_PMEDRVN_SHIFT          0x00000005u
  #define  PCI_PMDCSR_PMEDRVN_DEFAULT        0x00000000u
  #define  PCI_PMDCSR_PMEDRVN_OF(x)          _VALUEOF(x)

  #define _PCI_PMDCSR_AUXDETECT_MASK         0x00000010u
  #define _PCI_PMDCSR_AUXDETECT_SHIFT        0x00000004u
  #define  PCI_PMDCSR_AUXDETECT_DEFAULT      0x00000000u
  #define  PCI_PMDCSR_AUXDETECT_OF(x)          _VALUEOF(x)

  #define _PCI_PMDCSR_CURSTATE_MASK          0x0000000Cu
  #define _PCI_PMDCSR_CURSTATE_SHIFT         0x00000002u
  #define  PCI_PMDCSR_CURSTATE_DEFAULT       0x00000000u
  #define  PCI_PMDCSR_CURSTATE_OF(x)         _VALUEOF(x)
  #define  PCI_PMDCSR_CURSTATE_D0            0x00000000u
  #define  PCI_PMDCSR_CURSTATE_D1	    	   0x00000001u
  #define  PCI_PMDCSR_CURSTATE_D2            0x00000002u
  #define  PCI_PMDCSR_CURSTATE_D3            0x00000003u

  #define _PCI_PMDCSR_REQSTATE_MASK          0x00000003u
  #define _PCI_PMDCSR_REQSTATE_SHIFT         0x00000000u
  #define  PCI_PMDCSR_REQSTATE_DEFAULT       0x00000000u
  #define  PCI_PMDCSR_REQSTATE_OF(x)         _VALUEOF(x)

  #define  PCI_PMDCSR_OF(x)                  _VALUEOF(x)

 #define PCI_PMDCSR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(PCI,PMDCSR,HWPMECTL) \
    |_PER_FMK(PCI,PMDCSR,D3WARMONWKP) \
    |_PER_FMK(PCI,PMDCSR,D2WARMONWKP) \
    |_PER_FDEFAULT(PCI,PMDCSR,PMEEN) \
    |_PER_FDEFAULT(PCI,PMDCSR,PMEWKP) \
    |_PER_FDEFAULT(PCI,PMDCSR,PMESTAT) \
    |_PER_FDEFAULT(PCI,PMDCSR,PMEDRVN) \
    |_PER_FDEFAULT(PCI,PMDCSR,AUXDETECT) \
    |_PER_FDEFAULT(PCI,PMDCSR,CURSTATE) \
    |_PER_FDEFAULT(PCI,PMDCSR,REQSTATE) \
   )

  #define PCI_PMDCSR_RMK(hwpmectl,pmeen,pmestat,curstate) \
    (Uint32)( \
     _PER_FMK(PCI,PMDCSR,HWPMECTL,hwpmectl) \
    |_PER_FMK(PCI,PMDCSR,PMEEN,pmeena) \
    |_PER_FMK(PCI,PMDCSR,PMESTAT,pmestat) \
    |_PER_FMK(PCI,PMDCSR,CURSTATE,curstate) \
   )

 #define _PCI_PMDCSR_FGET(FIELD)\
    _PER_FGET(_PCI_PMDCSR_ADDR,PCI,PMDCSR,##FIELD)

 #define _PCI_PMDCSR_FSET(FIELD,field)\
    _PER_FSET(_PCI_PMDCSR_ADDR,PCI,PMDCSR,##FIELD,field)

 #define _PCI_PMDCSR_FSETS(FIELD,SYM)\
    _PER_FSETS(_PCI_PMDCSR_ADDR,PCI,PMDCSR,##FIELD,##SYM)




/******************************************************************************\
* _____________________
* |                   |
* |  P C I I S        |
* |___________________|
*
* PCIIS - PCI Interrupt Source Register
*
* FIELDS (msb -> lsb)
* (rw) DMAHALTED
* (rw) PRST
* (rw) EERDY
* (rw) CFGERR
* (rw) CFGDONE
* (rw) MASTEROK
* (rw) PWRHL
* (rw) PWRLH
* (rw) HOSTSW
* (rw) PCIMASTER
* (rw) PCITARGET
* (rw) PWRMGMT
*
\******************************************************************************/
  #define _PCI_PCIIS_OFFSET     2

 #if (C64_SUPPORT)
   #define _PCI_PCIIS_ADDR                0x01C00008u
 #else
   #define _PCI_PCIIS_ADDR                0x01A40008u
 #endif


  #define _PCI_PCIIS_DMAHALTED_MASK         0x00001000u
  #define _PCI_PCIIS_DMAHALTED_SHIFT        0x0000000Cu
  #define  PCI_PCIIS_DMAHALTED_DEFAULT      0x00000000u
  #define  PCI_PCIIS_DMAHALTED_OF(x)        _VALUEOF(x)
  #define  PCI_PCIIS_DMAHALTED_CLR          0x00000001u

  #define _PCI_PCIIS_PRST_MASK              0x00000800u
  #define _PCI_PCIIS_PRST_SHIFT             0x0000000Bu
  #define  PCI_PCIIS_PRST_DEFAULT           0x00000000u
  #define  PCI_PCIIS_PRST_OF(x)             _VALUEOF(x)
  #define  PCI_PCIIS_PRST_CHGSTATE          0x00000001u
  #define  PCI_PCIIS_PRST_NOCHG             0x00000000u

  #define _PCI_PCIIS_EERDY_MASK             0x00000200u
  #define _PCI_PCIIS_EERDY_SHIFT            0x00000009u
  #define  PCI_PCIIS_EERDY_DEFAULT          0x00000000u
  #define  PCI_PCIIS_EERDY_OF(x)            _VALUEOF(x)
  #define  PCI_PCIIS_EERDY_CLR              0x00000001u


  #define _PCI_PCIIS_CFGERR_MASK            0x00000100u
  #define _PCI_PCIIS_CFGERR_SHIFT          0x00000008u
  #define  PCI_PCIIS_CFGERR_DEFAULT         0x00000000u
  #define  PCI_PCIIS_CFGERR_OF(x)           _VALUEOF(x)
  #define  PCI_PCIIS_CFGERR_CLR             0x00000001u

  #define _PCI_PCIIS_CFGDONE_MASK           0x00000080u
  #define _PCI_PCIIS_CFGDONE_SHIFT          0x00000007u
  #define  PCI_PCIIS_CFGDONE_DEFAULT        0x00000000u
  #define  PCI_PCIIS_CFGDONE_OF(x)          _VALUEOF(x)
  #define  PCI_PCIIS_CFGDONE_CLR            0x00000001u

  #define _PCI_PCIIS_MASTEROK_MASK          0x00000040u
  #define _PCI_PCIIS_MASTEROK_SHIFT         0x00000006u
  #define  PCI_PCIIS_MASTEROK_DEFAULT       0x00000000u
  #define  PCI_PCIIS_MASTEROK_OF(x)         _VALUEOF(x)
  #define  PCI_PCIIS_MASTEROK_CLR           0x00000001u

  #define _PCI_PCIIS_PWRHL_MASK             0x00000020u
  #define _PCI_PCIIS_PWRHL_SHIFT            0x00000005u
  #define  PCI_PCIIS_PWRHL_DEFAULT          0x00000000u
  #define  PCI_PCIIS_PWRHL_OF(x)            _VALUEOF(x)
  #define  PCI_PCIIS_PWRHL_CLR              0x00000001u

  #define _PCI_PCIIS_PWRLH_MASK             0x00000010u
  #define _PCI_PCIIS_PWRLH_SHIFT            0x00000004u
  #define  PCI_PCIIS_PWRLH_DEFAULT          0x00000000u
  #define  PCI_PCIIS_PWRLH_OF(x)            _VALUEOF(x)
  #define  PCI_PCIIS_PWRLH_CLR              0x00000001u

  #define _PCI_PCIIS_HOSTSW_MASK            0x00000008u
  #define _PCI_PCIIS_HOSTSW_SHIFT           0x00000003u
  #define  PCI_PCIIS_HOSTSW_DEFAULT         0x00000000u
  #define  PCI_PCIIS_HOSTSW_OF(x)           _VALUEOF(x)
  #define  PCI_PCIIS_HOSTSW_CLR             0x00000001u

  #define _PCI_PCIIS_PCIMASTER_MASK         0x00000004u
  #define _PCI_PCIIS_PCIMASTER_SHIFT        0x00000002u
  #define  PCI_PCIIS_PCIMASTER_DEFAULT      0x00000000u
  #define  PCI_PCIIS_PCIMASTER_OF(x)        _VALUEOF(x)
  #define  PCI_PCIIS_PCIMASTER_CLR          0x00000001u

  #define _PCI_PCIIS_PCITARGET_MASK         0x00000002u
  #define _PCI_PCIIS_PCITARGET_SHIFT        0x00000001u
  #define  PCI_PCIIS_PCITARGET_DEFAULT      0x00000000u
  #define  PCI_PCIIS_PCITARGET_OF(x)        _VALUEOF(x)
  #define  PCI_PCIIS_PCITARGET_CLR          0x00000001u

  #define _PCI_PCIIS_PWRMGMT_MASK           0x00000001u
  #define _PCI_PCIIS_PWRMGMT_SHIFT          0x00000000u
  #define  PCI_PCIIS_PWRMGMT_DEFAULT        0x00000000u
  #define  PCI_PCIIS_PWRMGMT_OF(x)          _VALUEOF(x)
  #define  PCI_PCIIS_PWRMGMT_CLR            0x00000001u

  #define  PCI_PCIIS_OF(x)                 _VALUEOF(x)

  #define PCI_PCIIS_DEFAULT (Uint32)( \
     _PER_FDEFAULT(PCI,PCIIS,DMAHALTED) \
    |_PER_FDEFAULT(PCI,PCIIS,PRST) \
    |_PER_FDEFAULT(PCI,PCIIS,EERDY) \
    |_PER_FDEFAULT(PCI,PCIIS,CFGERR) \
    |_PER_FDEFAULT(PCI,PCIIS,CFGDONE) \
    |_PER_FDEFAULT(PCI,PCIIS,MASTEROK) \
    |_PER_FDEFAULT(PCI,PCIIS,PWRHL) \
    |_PER_FDEFAULT(PCI,PCIIS,PWRLH) \
    |_PER_FDEFAULT(PCI,PCIIS,HOSTSW) \
    |_PER_FDEFAULT(PCI,PCIIS,PCIMASTER) \
    |_PER_FDEFAULT(PCI,PCIIS,PCITARGET) \
    |_PER_FDEFAULT(PCI,PCIIS,PWRMGMT) \
   )

 #define PCI_PCIIS_RMK(dmahalted,prst,eerdy,cfgerr,cfgdone,masterok, \
                      pwrhl,pwrlh,hostsw,pcimaster,pcitarget,pwrmgmt)\
   (Uint32)( \
     _PER_FMK(PCI,PCIIS,DMAHALTED,dmahalted) \
    |_PER_FMK(PCI,PCIIS,PRST,prst) \
    |_PER_FMK(PCI,PCIIS,EERDY,eerdy) \
    |_PER_FMK(PCI,PCIIS,CFGERR,cfgerr) \
    |_PER_FMK(PCI,PCIIS,CFGDONE,cfgdone) \
    |_PER_FMK(PCI,PCIIS,MASTEROK,masterok) \
    |_PER_FMK(PCI,PCIIS,PWRHL,pwrhl) \
    |_PER_FMK(PCI,PCIIS,PWRLH,pwrlh) \
    |_PER_FMK(PCI,PCIIS,HOSTSW,hostsw) \
    |_PER_FMK(PCI,PCIIS,PCIMASTER,pcimaster) \
    |_PER_FMK(PCI,PCIIS,PCITARGET,pcitarget) \
    |_PER_FMK(PCI,PCIIS,PWRMGMT,pwrmgmt) \
   )

  #define _PCI_PCIIS_FGET(FIELD)\
    _PER_FGET(_PCI_PCIIS_ADDR,PCI,PCIIS,##FIELD)

 #define _PCI_PCIIS_FSET(FIELD,field)\
    _PER_FSET(_PCI_PCIIS_ADDR,PCI,PCIIS,##FIELD,field)

 #define _PCI_PCIIS_FSETS(FIELD,SYM)\
    _PER_FSETS(_PCI_PCIIS_ADDR,PCI,PCIIS,##FIELD,##SYM)



/******************************************************************************\
* _____________________
* |                   |
* |  P C I I E N      |
* |___________________|
*
* PCIIEN - PCI Interrupt Enable Register
*
* FIELDS (msb -> lsb)
* (rw) PRST
* (rw) EERDY
* (rw) CFGERR
* (rw) CFGDONE
* (rw) MASTEROK
* (rw) PWRHL
* (rw) PWRLH
* (rw) HOSTSW
* (rw) PCIMASTER
* (rw) PCITARGET
* (rw) PWRMGMT
*
\******************************************************************************/
  #define _PCI_PCIIEN_OFFSET     3

  #if (C64_SUPPORT)
   #define _PCI_PCIIEN_ADDR               0x01C0000Cu
 #else
   #define _PCI_PCIIEN_ADDR               0x01A4000Cu
 #endif



  #define _PCI_PCIIEN_PRST_MASK              0x00000800u
  #define _PCI_PCIIEN_PRST_SHIFT             0x0000000Bu
  #define  PCI_PCIIEN_PRST_DEFAULT           0x00000000u
  #define  PCI_PCIIEN_PRST_OF(x)             _VALUEOF(x)
  #define  PCI_PCIIEN_PRST_DISABLE           0x00000000u
  #define  PCI_PCIIEN_PRST_ENABLE            0x00000001u

  #define _PCI_PCIIEN_EERDY_MASK             0x00000200u
  #define _PCI_PCIIEN_EERDY_SHIFT            0x00000009u
  #define  PCI_PCIIEN_EERDY_DEFAULT          0x00000000u
  #define  PCI_PCIIEN_EERDY_OF(x)            _VALUEOF(x)
  #define  PCI_PCIIEN_EERDY_DISABLE          0x00000000u
  #define  PCI_PCIIEN_EERDY_ENABLE           0x00000001u


  #define _PCI_PCIIEN_CFGERR_MASK            0x00000100u
  #define _PCI_PCIIEN_CFGERR_SHIFT           0x00000008u
  #define  PCI_PCIIEN_CFGERR_DEFAULT         0x00000000u
  #define  PCI_PCIIEN_CFGERR_OF(x)           _VALUEOF(x)
  #define  PCI_PCIIEN_CFGERR_DISABLE         0x00000000u
  #define  PCI_PCIIEN_CFGERR_ENABLE          0x00000001u

  #define _PCI_PCIIEN_CFGDONE_MASK           0x00000080u
  #define _PCI_PCIIEN_CFGDONE_SHIFT          0x00000007u
  #define  PCI_PCIIEN_CFGDONE_DEFAULT        0x00000000u
  #define  PCI_PCIIEN_CFGDONE_OF(x)          _VALUEOF(x)
  #define  PCI_PCIIEN_CFGDONE_DISABLE        0x00000000u
  #define  PCI_PCIIEN_CFGDONE_ENABLE         0x00000001u

  #define _PCI_PCIIEN_MASTEROK_MASK          0x00000040u
  #define _PCI_PCIIEN_MASTEROK_SHIFT         0x00000006u
  #define  PCI_PCIIEN_MASTEROK_DEFAULT       0x00000000u
  #define  PCI_PCIIEN_MASTEROK_OF(x)         _VALUEOF(x)
  #define  PCI_PCIIEN_MASTEROK_DISABLE       0x00000000u
  #define  PCI_PCIIEN_MASTEROK_ENABLE        0x00000001u

  #define _PCI_PCIIEN_PWRHL_MASK             0x00000020u
  #define _PCI_PCIIEN_PWRHL_SHIFT            0x00000005u
  #define  PCI_PCIIEN_PWRHL_DEFAULT          0x00000000u
  #define  PCI_PCIIEN_PWRHL_OF(x)            _VALUEOF(x)
  #define  PCI_PCIIEN_PWRHL_DISABLE          0x00000000u
  #define  PCI_PCIIEN_PWRHL_ENABLE           0x00000001u

  #define _PCI_PCIIEN_PWRLH_MASK             0x00000010u
  #define _PCI_PCIIEN_PWRLH_SHIFT            0x00000004u
  #define  PCI_PCIIEN_PWRLH_DEFAULT          0x00000000u
  #define  PCI_PCIIEN_PWRLH_OF(x)            _VALUEOF(x)
  #define  PCI_PCIIEN_PWRLH_DISABLE          0x00000000u
  #define  PCI_PCIIEN_PWRLH_ENABLE           0x00000001u

  #define _PCI_PCIIEN_HOSTSW_MASK            0x00000008u
  #define _PCI_PCIIEN_HOSTSW_SHIFT           0x00000003u
  #define  PCI_PCIIEN_HOSTSW_DEFAULT         0x00000008u
  #define  PCI_PCIIEN_HOSTSW_OF(x)           _VALUEOF(x)
  #define  PCI_PCIIEN_HOSTSW_DISABLE         0x00000000u
  #define  PCI_PCIIEN_HOSTSW_ENABLE          0x00000001u

  #define _PCI_PCIIEN_PCIMASTER_MASK         0x00000004u
  #define _PCI_PCIIEN_PCIMASTER_SHIFT        0x00000002u
  #define  PCI_PCIIEN_PCIMASTER_DEFAULT      0x00000000u
  #define  PCI_PCIIEN_PCIMASTER_OF(x)        _VALUEOF(x)
  #define  PCI_PCIIEN_PCIMASTER_DISABLE      0x00000000u
  #define  PCI_PCIIEN_PCIMASTER_ENABLE       0x00000001u

  #define _PCI_PCIIEN_PCITARGET_MASK         0x00000002u
  #define _PCI_PCIIEN_PCITARGET_SHIFT        0x00000001u
  #define  PCI_PCIIEN_PCITARGET_DEFAULT      0x00000000u
  #define  PCI_PCIIEN_PCITARGET_OF(x)        _VALUEOF(x)
  #define  PCI_PCIIEN_PCITARGET_DISABLE      0x00000000u
  #define  PCI_PCIIEN_PCITARGET_ENABLE       0x00000001u

  #define _PCI_PCIIEN_PWRMGMT_MASK           0x00000001u
  #define _PCI_PCIIEN_PWRMGMT_SHIFT          0x00000000u
  #define  PCI_PCIIEN_PWRMGMT_DEFAULT        0x00000000u
  #define  PCI_PCIIEN_PWRMGMT_OF(x)          _VALUEOF(x)
  #define  PCI_PCIIEN_PWRMGMT_DISABLE        0x00000000u
  #define  PCI_PCIIEN_PWRMGMT_ENABLE         0x00000001u

  #define  PCI_PCIIEN_OF(x)                   _VALUEOF(x)

  #define PCI_PCIIEN_DEFAULT (Uint32)( \
     _PER_FDEFAULT(PCI,PCIIEN,PRST) \
    |_PER_FDEFAULT(PCI,PCIIEN,EERDY) \
    |_PER_FDEFAULT(PCI,PCIIEN,CFGERR) \
    |_PER_FDEFAULT(PCI,PCIIEN,CFGDONE) \
    |_PER_FDEFAULT(PCI,PCIIEN,MASTEROK) \
    |_PER_FDEFAULT(PCI,PCIIEN,PWRHL) \
    |_PER_FDEFAULT(PCI,PCIIEN,PWRLH) \
    |_PER_FDEFAULT(PCI,PCIIEN,HOSTSW) \
    |_PER_FDEFAULT(PCI,PCIIEN,PCIMASTER) \
    |_PER_FDEFAULT(PCI,PCIIEN,PCITARGET) \
    |_PER_FDEFAULT(PCI,PCIIEN,PWRMGMT) \
   )

 #define PCI_PCIIEN_RMK(prst,eerdy,cfgerr,cfgdone,masterok, \
                      pwrhl,pwrlh,hostsw,pcimaster,pcitarget,pwrmgmt)\
   (Uint32)( \
     _PER_FMK(PCI,PCIIEN,PRST,prst) \
    |_PER_FMK(PCI,PCIIEN,EERDY,eerdy) \
    |_PER_FMK(PCI,PCIIEN,CFGERR,cfgerr) \
    |_PER_FMK(PCI,PCIIEN,CFGDONE,cfgdone) \
    |_PER_FMK(PCI,PCIIEN,MASTEROK,masterok) \
    |_PER_FMK(PCI,PCIIEN,PWRHL,pwrhl) \
    |_PER_FMK(PCI,PCIIEN,PWRLH,pwrlh) \
    |_PER_FMK(PCI,PCIIEN,HOSTSW,hostsw) \
    |_PER_FMK(PCI,PCIIEN,PCIMASTER,pcimaster) \
    |_PER_FMK(PCI,PCIIEN,PCITARGET,pcitarget) \
    |_PER_FMK(PCI,PCIIEN,PWRMGMT,pwrmgmt) \
   )

  #define _PCI_PCIIEN_FGET(FIELD)\
    _PER_FGET(_PCI_PCIIEN_ADDR,PCI,PCIIEN,##FIELD)

 #define _PCI_PCIIEN_FSET(FIELD,field)\
    _PER_FSET(_PCI_PCIIEN_ADDR,PCI,PCIIEN,##FIELD,field)

 #define _PCI_PCIIEN_FSETS(FIELD,SYM)\
    _PER_FSETS(_PCI_PCIIEN_ADDR,PCI,PCIIEN,##FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  D S P M A        |
* |___________________|
*
* DSPMA - DSP Master Address Register
*
* FIELDS (msb -> lsb)
* (rw) ADDRMA
* (rw) AINC
*
\******************************************************************************/
  #define _PCI_DSPMA_OFFSET          4


 #if (C64_SUPPORT)
   #define _PCI_DSPMA_ADDR                 0x01C00010u
 #else
   #define _PCI_DSPMA_ADDR                 0x01A40010u
 #endif

  #define _PCI_DSPMA_ADDRMA_MASK           0xFFFFFFFCu
  #define _PCI_DSPMA_ADDRMA_SHIFT          0x00000002u
  #define  PCI_DSPMA_ADDRMA_DEFAULT        0x00000000u
  #define  PCI_DSPMA_ADDRMA_OF(x)          _VALUEOF(x)

  #define _PCI_DSPMA_AINC_MASK              0x00000002u
  #define _PCI_DSPMA_AINC_SHIFT             0x00000001u
  #define  PCI_DSPMA_AINC_DEFAULT           0x00000000u
  #define  PCI_DSPMA_AINC_OF(x)             _VALUEOF(x)
  #define  PCI_DSPMA_AINC_ENABLE            0x00000000u
  #define  PCI_DSPMA_AINC_DISABLE           0x00000001u

  #define  PCI_DSPMA_OF(x)                  _VALUEOF(x)

  #define PCI_DSPMA_DEFAULT  (Uint32)( \
     _PER_FDEFAULT(PCI,DSPMA,ADDRMA) \
    |_PER_FDEFAULT(PCI,DSPMA,AINC) \
   )

 #define PCI_DSPMA_RMK(addrma,ainc)\
 (Uint32)( \
     _PER_FMK(PCI,DSPMA,ADDRMA,addrma) \
    |_PER_FMK(PCI,DSPMA,AINC,ainc) \
   )

 #define _PCI_DSPMA_FGET(FIELD)\
    _PER_FGET(_PCI_DSPMA_ADDR,PCI,DSPMA,##FIELD)

 #define _PCI_DSPMA_FSET(FIELD,field)\
    _PER_FSET(_PCI_DSPMA_ADDR,PCI,DSPMA,##FIELD,field)

 #define _PCI_DSPMA_FSETS(FIELD,SYM)\
    _PER_FSETS(_PCI_DSPMA_ADDR,PCI,DSPMA,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  P C I M A        |
* |___________________|
*
* PCIMA - PCI Master Address Register
*
* FIELDS (msb -> lsb)
* (rw) ADDRMA
*
\******************************************************************************/
  #define _PCI_PCIMA_OFFSET          5

 #if (C64_SUPPORT)
   #define _PCI_PCIMA_ADDR                0x01C00014u
 #else
   #define _PCI_PCIMA_ADDR                0x01A40014u
 #endif

  #define _PCI_PCIMA_ADDRMA_MASK          0xFFFFFFFCu
  #define _PCI_PCIMA_ADDRMA_SHIFT         0x00000002u
  #define  PCI_PCIMA_ADDRMA_DEFAULT       0x00000000u
  #define  PCI_PCIMA_ADDRMA_OF(x)         _VALUEOF(x)

  #define  PCI_PCIMA_OF(x)                _VALUEOF(x)

  #define PCI_PCIMA_DEFAULT (Uint32)( \
     _PER_FDEFAULT(PCI,PCIMA,ADDRMA) \
   )

  #define PCI_PCIMA_RMK(addrma)\
 (Uint32)( \
     _PER_FMK(PCI,PCIMA,ADDRMA,addrma) \
   )

 #define _PCI_PCIMA_FGET(FIELD)\
    _PER_FGET(_PCI_PCIMA_ADDR,PCI,PCIMA,##FIELD)

 #define _PCI_PCIMA_FSET(FIELD,field)\
    _PER_FSET(_PCI_PCIMA_ADDR,PCI,PCIMA,##FIELD,field)

 #define _PCI_PCIMA_FSETS(FIELD,SYM)\
    _PER_FSETS(_PCI_PCIMA_ADDR,PCI,PCIMA,##FIELD,##SYM)




/******************************************************************************\
* _____________________
* |                   |
* |  P C I M C        |
* |___________________|
*
* PCIMC - PCI Master Control Register
*
* FIELDS (msb -> lsb)
* (rw)  CNT
* (rw)  START
*
\******************************************************************************/
  #define _PCI_PCIMC_OFFSET     6

 #if (C64_SUPPORT)
   #define _PCI_PCIMC_ADDR                0x01C00018u
 #else
   #define _PCI_PCIMC_ADDR                0x01A40018u
 #endif

  #define _PCI_PCIMC_CNT_MASK              0xFFFF0000u
  #define _PCI_PCIMC_CNT_SHIFT             0x00000010u
  #define  PCI_PCIMC_CNT_DEFAULT           0x00000000u
  #define  PCI_PCIMC_CNT_OF(x)             _VALUEOF(x)


  #define _PCI_PCIMC_START_MASK             0x00000007u
  #define _PCI_PCIMC_START_SHIFT            0x00000000u
  #define  PCI_PCIMC_START_DEFAULT          0x00000000u
  #define  PCI_PCIMC_START_OF(x)            _VALUEOF(x)
  #define  PCI_PCIMC_START_FLUSH            0x00000000u
  #define  PCI_PCIMC_START_WRITE            0x00000001u
  #define  PCI_PCIMC_START_READPREF         0x00000002u
  #define  PCI_PCIMC_START_READNOPREF       0x00000003u
  #define  PCI_PCIMC_START_CONFIGWRITE      0x00000004u
  #define  PCI_PCIMC_START_CONFIGREAD       0x00000005u
  #define  PCI_PCIMC_START_IOWRITE          0x00000006u
  #define  PCI_PCIMC_START_IOREAD           0x00000007u


  #define  PCI_PCIMC_OF(x)                  _VALUEOF(x)

 #define PCI_PCIMC_DEFAULT (Uint32)( \
     _PER_FDEFAULT(PCI,PCIMC,CNT) \
    |_PER_FDEFAULT(PCI,PCIMC,START) \
   )

 #define PCI_PCIMC_RMK(cnt,start)\
 (Uint32)( \
     _PER_FMK(PCI,PCIMC,CNT,cnt) \
    |_PER_FMK(PCI,PCIMC,START,start) \
   )
 #define _PCI_PCIMC_FGET(FIELD)\
    _PER_FGET(_PCI_PCIMC_ADDR,PCI,PCIMC,##FIELD)

 #define _PCI_PCIMC_FSET(FIELD,field)\
    _PER_FSET(_PCI_PCIMC_ADDR,PCI,PCIMC,##FIELD,field)

 #define _PCI_PCIMC_FSETS(FIELD,SYM)\
    _PER_FSETS(_PCI_PCIMC_ADDR,PCI,PCIMC,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  C D S P A        |
* |___________________|
*
* CDSPA - Current DSP Address Register
*
* FIELDS (msb -> lsb)
* (r) CDSPA
*
\******************************************************************************/
  #define _PCI_CDSPA_OFFSET      7

 #if (C64_SUPPORT)
   #define _PCI_CDSPA_ADDR                 0x01C0001Cu
 #else
   #define _PCI_CDSPA_ADDR                 0x01A4001Cu
 #endif

  #define _PCI_CDSPA_CDSPA_MASK            0xFFFFFFFFu
  #define _PCI_CDSPA_CDSPA_SHIFT           0x00000000u
  #define  PCI_CDSPA_CDSPA_DEFAULT         0x00000000u
  #define  PCI_CDSPA_CDSPA_OF(x)           _VALUEOF(x)

  #define  PCI_CDSPA_OF(x)                 _VALUEOF(x)

  #define PCI_CDSPA_DEFAULT (Uint32)( \
     _PER_FDEFAULT(PCI,CDSPA,CDSPA) \
   )
#if (!(CHIP_6413 | CHIP_6418 | CHIP_6410))
  #define PCI_CDSPA_RMK(cdspa)\
  (Uint32)(\
      _PER_FMK(PCI,CDSPA,CDSPA,cdspa)\
  )      
#endif   
 #define _PCI_CDSPA_FGET(FIELD)\
    _PER_FGET(_PCI_CDSPA_ADDR,PCI,CDSPA,##FIELD)

/******************************************************************************\
* _____________________
* |                   |
* |  C P C I A        |
* |___________________|
*
* CPCIA - Current PCI Address Register
*
* FIELDS (msb -> lsb)
* (r) CPCIA
*
\******************************************************************************/
  #define _PCI_CPCIA_OFFSET      8

 #if (C64_SUPPORT)
   #define _PCI_CPCIA_ADDR                0x01C00020u
 #else
   #define _PCI_CPCIA_ADDR                0x01A40020u
 #endif

  #define _PCI_CPCIA_CPCIA_MASK           0xFFFFFFFFu
  #define _PCI_CPCIA_CPCIA_SHIFT          0x00000000u
  #define  PCI_CPCIA_CPCIA_DEFAULT        0x00000000u
  #define  PCI_CPCIA_CPCIA_OF(x)          _VALUEOF(x)

  #define  PCI_CPCIA_OF(x)                _VALUEOF(x)

  #define PCI_CPCIA_DEFAULT (Uint32)( \
     _PER_FDEFAULT(PCI,CPCIA,CPCIA) \
   )
#if (!(CHIP_6413 | CHIP_6418 | CHIP_6410))
  #define PCI_CPCIA_RMK(cpcia)\
  (Uint32)(\
     _PER_FMK(PCI,CPCIA,CPCIA,cpcia)\
  )     
#endif  
  #define _PCI_CPCIA_FGET(FIELD)\
    _PER_FGET(_PCI_CPCIA_ADDR,PCI,CPCIA,##FIELD)

/******************************************************************************\
* _____________________
* |                   |
* |  C C N T          |
* |___________________|
*
* CCNT - Current Byte Counter Register
*
* FIELDS (msb -> lsb)
* (r)  CCNT
*
\******************************************************************************/
  #define _PCI_CCNT_OFFSET      9

 #if (C64_SUPPORT)
   #define _PCI_CCNT_ADDR                 0x01C00024u
 #else
   #define _PCI_CCNT_ADDR                 0x01A40024u
 #endif

  #define _PCI_CCNT_CCNT_MASK             0x0000FFFFu
  #define _PCI_CCNT_CCNT_SHIFT            0x00000000u
  #define  PCI_CCNT_CCNT_DEFAULT          0x00000000u
  #define  PCI_CCNT_CCNT_OF(x)            _VALUEOF(x)

  #define  PCI_CCNT_OF(x)                 _VALUEOF(x)

  #define PCI_CCNT_DEFAULT (Uint32)( \
     _PER_FDEFAULT(PCI,CCNT,CCNT) \
   )
#if (!(CHIP_6413 | CHIP_6418 | CHIP_6410))
  #define PCI_CCNT_RMK(ccnt) (Uint32)(\
     _PER_FMK(PCI,CCNT,CCNT,ccnt)\
  )     
#endif  
  #define _PCI_CCNT_FGET(FIELD)\
    _PER_FGET(_PCI_CCNT_ADDR,PCI,CCNT,##FIELD)


/****************************************************************************\
* _____________________
* |                   |
* |  H A L T          |
* |___________________|
*
* HALT - PCI Transfer Halt Register
*
* FIELDS (msb -> lsb)
* (rw)  HALT
*
\******************************************************************************/
#define _PCI_HALT_OFFSET     10

 #if (C64_SUPPORT)
  #define _PCI_HALT_ADDR                   0x01C00028u
 #else
  #define _PCI_HALT_ADDR                   0x01A40028u
 #endif

 #if (C64_SUPPORT)
  #define _PCI_HALT_HALT_MASK              0x00000000u
  #define _PCI_HALT_HALT_SHIFT             0x00000000u
  #define  PCI_HALT_HALT_DEFAULT           0x00000000u
  #define  PCI_HALT_HALT_OF(x)             _VALUEOF(x)
#else
  #define _PCI_HALT_HALT_MASK              0x00000001u
  #define _PCI_HALT_HALT_SHIFT             0x00000000u
  #define  PCI_HALT_HALT_DEFAULT           0x00000000u
  #define  PCI_HALT_HALT_DEFAULT           0x00000000u
  #define  PCI_HALT_HALT_OF(x)             _VALUEOF(x)
   #define  PCI_HALT_HALT_SET              0x00000001u
 #endif

  #define  PCI_HALT_OF(x)                  _VALUEOF(x)

  #define PCI_HALT_RMK(halt)\
  (Uint32)( \
     _PER_FMK(PCI,HALT,HALT,halt) \
   )

  #define PCI_HALT_DEFAULT (Uint32)( \
     _PER_FDEFAULT(PCI,HALT,HALT) \
   )

 #define _PCI_HALT_FGET(FIELD)\
    _PER_FGET(_PCI_HALT_ADDR,PCI,HALT,##FIELD)

 #define _PCI_HALT_FSET(FIELD,field)\
    _PER_FSET(_PCI_HALT_ADDR,PCI,HALT,##FIELD,field)

 #define _PCI_HALT_FSETS(FIELD,SYM)\
    _PER_FSETS(_PCI_HALT_ADDR,PCI,HALT,##FIELD,##SYM)

/****************************************************************************\
* _____________________
* |                   |
* |  E E A D D        |
* |___________________|
*
* EEADD - EEPROM Address Register
*
* FIELDS (msb -> lsb)
* (rw) EEADD
*
\******************************************************************************/

  #define _PCI_EEADD_OFFSET          0


 #if (C64_SUPPORT)
  #define _PCI_EEADD_ADDR	  		   0x01C20000u
 #else
   #define _PCI_EEADD_ADDR	  		   0x01A80000u
 #endif

  #define _PCI_EEADD_EEADD_MASK              0x000003FFu
  #define _PCI_EEADD_EEADD_SHIFT             0x00000000u
  #define  PCI_EEADD_EEADD_DEFAULT           0x00000000u
  #define  PCI_EEADD_EEADD_OF(x)             _VALUEOF(x)

  #define  PCI_EEADD_OF(x)                   _VALUEOF(x)

  #define PCI_EEADD_DEFAULT (Uint32)( \
     _PER_FDEFAULT(PCI,EEADD,EEADD) \
   )

  #define PCI_EEADD_RMK(eeadd)  \
  (Uint32)( \
     _PER_FMK(PCI,EEADD,EEADD,eeadd) \
   )

  #define _PCI_EEADD_FGET(FIELD)\
    _PER_FGET(_PCI_EEADD_ADDR,PCI,EEADD,##FIELD)

  #define _PCI_EEADD_FSET(FIELD,field)\
    _PER_FSET(_PCI_EEADD_ADDR,PCI,EEADD,##FIELD,field)

  #define _PCI_EEADD_FSETS(FIELD,SYM)\
    _PER_FSETS(_PCI_EEADD_ADDR,PCI,EEADD,##FIELD,##SYM)

/****************************************************************************\
* _____________________
* |                   |
* |  E E D A T        |
* |___________________|
*
* EEDAT - EEPROM Data Register
*
* FIELDS (msb -> lsb)
* (rw) EEDAT
*
\*****************************************************************************/

  #define _PCI_EEDAT_OFFSET          1


 #if (C64_SUPPORT)
   #define _PCI_EEDAT_ADDR                   0x01C20004u
 #else
   #define _PCI_EEDAT_ADDR                  0x01A80004u
 #endif

  #define _PCI_EEDAT_EEDAT_MASK              0x0000FFFFu
  #define _PCI_EEDAT_EEDAT_SHIFT             0x00000000u
  #define  PCI_EEDAT_EEDAT_DEFAULT           0x00000000u
  #define  PCI_EEDAT_EEDAT_OF(x)             _VALUEOF(x)

  #define  PCI_EEDAT_OF(x)                   _VALUEOF(x)

  #define PCI_EEDAT_DEFAULT (Uint32)( \
     _PER_FDEFAULT(PCI,EEDAT,EEDAT) \
   )

  #define PCI_EEDAT_RMK(eedat) \
  (Uint32)( \
     _PER_FMK(PCI,EEDAT,EEDAT,eedat) \
   )

  #define _PCI_EEDAT_FGET(FIELD)\
    _PER_FGET(_PCI_EEDAT_ADDR,PCI,EEDAT,##FIELD)

  #define _PCI_EEDAT_FSET(FIELD,field)\
    _PER_FSET(_PCI_EEDAT_ADDR,PCI,EEDAT,##FIELD,field)

  #define _PCI_EEDAT_FSETS(FIELD,SYM)\
    _PER_FSETS(_PCI_EEDAT_ADDR,PCI,EEDAT,##FIELD,##SYM)



/****************************************************************************\
* _____________________
* |                   |
* |  E E C T L        |
* |___________________|
*
* EECTL - EEPROM Control Register
*
* FIELDS (msb -> lsb)
* (r)  CFGDONE
* (r)  CFGERR
* (r)  EEAI
* (r)  EESZ
* (r)  READY
* (rw) EECNT
*
\******************************************************************************/
  #define _PCI_EECTL_OFFSET         2


 #if (C64_SUPPORT)
   #define _PCI_EECTL_ADDR                0x01C20008u
 #else
   #define _PCI_EECTL_ADDR                0x01A80008u
 #endif

  #define _PCI_EECTL_CFGDONE_MASK            0x00000100u
  #define _PCI_EECTL_CFGDONE_SHIFT           0x00000008u
  #define  PCI_EECTL_CFGDONE_DEFAULT         0x00000000u
  #define  PCI_EECTL_CFGDONE_OF(x)           _VALUEOF(x)


  #define _PCI_EECTL_CFGERR_MASK             0x00000080u
  #define _PCI_EECTL_CFGERR_SHIFT            0x00000007u
  #define  PCI_EECTL_CFGERR_DEFAULT          0x00000000u
  #define  PCI_EECTL_CFGERR_OF(x)             _VALUEOF(x)


  #define _PCI_EECTL_EEAI_MASK               0x00000040u
  #define _PCI_EECTL_EEAI_SHIFT              0x00000006u
  #define  PCI_EECTL_EEAI_DEFAULT            0x00000000u
  #define  PCI_EECTL_EEAI_OF(x)              _VALUEOF(x)


  #define _PCI_EECTL_EESZ_MASK               0x00000038u
  #define _PCI_EECTL_EESZ_SHIFT              0x00000003u
  #define  PCI_EECTL_EESZ_DEFAULT            0x00000000u
  #define  PCI_EECTL_EESZ_OF(x)              _VALUEOF(x)


  #define _PCI_EECTL_READY_MASK              0x00000004u
  #define _PCI_EECTL_READY_SHIFT             0x00000002u
  #define  PCI_EECTL_READY_DEFAULT           0x00000000u
  #define  PCI_EECTL_READY_OF(x)             _VALUEOF(x)


  #define _PCI_EECTL_EECNT_MASK              0x00000003u
  #define _PCI_EECTL_EECNT_SHIFT             0x00000000u
  #define  PCI_EECTL_EECNT_DEFAULT           0x00000000u
  #define  PCI_EECTL_EECNT_OF(x)             _VALUEOF(x)
  #define  PCI_EECTL_EECNT_EWEN              0x00000000u
  #define  PCI_EECTL_EECNT_ERAL              0x00000000u
  #define  PCI_EECTL_EECNT_WRAL              0x00000000u
  #define  PCI_EECTL_EECNT_EWDS              0x00000000u
  #define  PCI_EECTL_EECNT_WRITE             0x00000001u
  #define  PCI_EECTL_EECNT_READ              0x00000002u
  #define  PCI_EECTL_EECNT_ERASE             0x00000003u

  #define  PCI_EECTL_OF(x)                   _VALUEOF(x)

  #define PCI_EECTL_DEFAULT (Uint32)( \
    _PER_FDEFAULT(PCI,EECTL,CFGDONE) \
   |_PER_FDEFAULT(PCI,EECTL,CFGERR) \
   |_PER_FDEFAULT(PCI,EECTL,EEAI) \
   |_PER_FDEFAULT(PCI,EECTL,EESZ) \
   |_PER_FDEFAULT(PCI,EECTL,READY) \
   |_PER_FDEFAULT(PCI,EECTL,EECNT) \
   )

  #define PCI_EECTL_RMK(eecnt) \
  (Uint32)( \
      _PER_FMK(PCI,EECTL,EECNT,eecnt) \
   )

  #define _PCI_EECTL_FGET(FIELD)\
    _PER_FGET(_PCI_EECTL_ADDR,PCI,EECTL,##FIELD)

  #define _PCI_EECTL_FSET(FIELD,field)\
    _PER_FSET(_PCI_EECTL_ADDR,PCI,EECTL,##FIELD,field)

  #define _PCI_EECTL_FSETS(FIELD,SYM)\
    _PER_FSETS(_PCI_EECTL_ADDR,PCI,EECTL,##FIELD,##SYM)



/****************************************************************************\
* _____________________
* |                   |
* |  T R C T L        |
* |___________________|
*
* TRCTL - TR Control Register
*
* FIELDS (msb -> lsb)
* (rw) TRSTALL
* (rw) PRI
* (rw) PALLOC
*
\*****************************************************************************/
#if (C64_SUPPORT)
  #define _PCI_TRCTL_OFFSET          0



   #define _PCI_TRCTL_ADDR                   0x01C30000u


  #define _PCI_TRCTL_TRSTALL_MASK              0x00000100u
  #define _PCI_TRCTL_TRSTALL_SHIFT             0x00000008u
  #define  PCI_TRCTL_TRSTALL_DEFAULT           0x00000000u
  #define  PCI_TRCTL_TRSTALL_OF(x)             _VALUEOF(x)

  #define _PCI_TRCTL_PRI_MASK    	           0x00000030u
  #define _PCI_TRCTL_PRI_SHIFT   	           0x00000004u
  #define  PCI_TRCTL_PRI_DEFAULT 	           0x00000002u
  #define  PCI_TRCTL_PRI_OF(x)   	           _VALUEOF(x)

  #define _PCI_TRCTL_PALLOC_MASK               0x0000000Fu
  #define _PCI_TRCTL_PALLOC_SHIFT              0x00000000u
  #define  PCI_TRCTL_PALLOC_DEFAULT            0x00000004u
  #define  PCI_TRCTL_PALLOC_OF(x)              _VALUEOF(x)

  #define  PCI_TRCTL_OF(x)                   _VALUEOF(x)

  #define PCI_TRCTL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(PCI,TRCTL,TRSTALL) \
    |_PER_FDEFAULT(PCI,TRCTL,PRI) \
    |_PER_FDEFAULT(PCI,TRCTL,PALLOC) \
   )

  #define PCI_TRCTL_RMK(trstall,pri,palloc) \
  (Uint32)( \
     _PER_FMK(PCI,TRCTL,TRSTALL,trctl) \
    |_PER_FMK(PCI,TRCTL,PRI,pri) \
    |_PER_FMK(PCI,TRCTL,PALLOC,palloc) \
   )

  #define _PCI_TRCTL_FGET(FIELD)\
    _PER_FGET(_PCI_TRCTL_ADDR,PCI,TRCTL,##FIELD)

  #define _PCI_TRCTL_FSET(FIELD,field)\
    _PER_FSET(_PCI_TRCTL_ADDR,PCI,TRCTL,##FIELD,field)

  #define _PCI_TRCTL_FSETS(FIELD,SYM)\
    _PER_FSETS(_PCI_TRCTL_ADDR,PCI,TRCTL,##FIELD,##SYM)

 #endif
/******************************************************************************/

#endif /* PCI_SUPPORT */
#endif /* _CSL_PCIHAL_H_ */
/******************************************************************************\
* End of pcihal.h
\******************************************************************************/

