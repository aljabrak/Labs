/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_chiphal.h
* DATE CREATED.. 14 Aug 2000
* LAST MODIFIED. 14 Jan 2004 Adding support for DRI300 versions (6410, 6413)
*                05 Aug 2003 Removing external control cregisters EM,ER,IN,OUT and DIER.
*                26 Jun 2003 Added support for 6411
*                17 Jun 2003 Added support for 6712C
*                28 May 2003 Added support for 6711C
*                05 Nov 2001 DM642 , 6411 remove 6400
*                03 Oct 2001 - CHIP_6713 - MCASP_SUPPORT - IIC_SUPPORT
*                           - DEVCFG register
*                           - redefinition of CHIP_RSET() / CHIP_RGET()
*                           - new CHIP_CRSET() / CHIP_CRGET() => modification of csl_irq.h
*                04 Apr 2004-  Removing external control cregisters EM,ER,IN,OUT and DIER.
*------------------------------------------------------------------------------
* REGISTERS
*
* CSR    - control/status register
* IFR    - interrupt flag register
* ISR    - interrupt set register
* ICR    - interrupt clear register
* IER    - interrupt enable register
* ISTP   - interrupt service table pointer register
* IRP    - interrupt return pointer
* NRP    - non-maskable interrupt return pointer
* AMR    - addressing mode reister
* FADCR  - floating point adder configuration register  (2)
* FAUCR  - floating point auxiliary control register  (2)
* FMCR   - floating point multiplier configuration register  (2)
* GFPGFR - Galois field polynomial generator function register  (3)
* DEVCFG - Device Configuration register  (4)
* DEVSTAT - Device Status Register (5)
* JTAGID - JTAG ID register (5)
*
* (1) only supported on 67xx
* (2) only supported on floating point devices
* (3) only supported on 6411/14/15/16 devices
* (4) only supported on 6713/DA610/DM642/6412/6711C/6712C devices
* (5) only supported on DM642/6412/6410/6413 devices
*
\******************************************************************************/
#ifndef _CSL_CHIPHAL_H_
#define _CSL_CHIPHAL_H_

#include <csl_stdinc.h>


/******************************************************************************\
* CHIP identification section
\******************************************************************************/
#ifdef CHIP_BASELINE
  #undef CHIP_BASELINE
  #define CHIP_BASELINE 1
#else
  #define CHIP_BASELINE 0
#endif

#if (CHIP_BASELINE)
  #define CHIP_6201 1
#endif

#ifdef CHIP_6201
  #undef CHIP_6201
  #define CHIP_6201 1
#else
  #define CHIP_6201 0
#endif

#ifdef CHIP_6202
  #undef CHIP_6202
  #define CHIP_6202 1
#else
  #define CHIP_6202 0
#endif

#ifdef CHIP_6203
  #undef CHIP_6203
  #define CHIP_6203 1
#else
  #define CHIP_6203 0
#endif

#ifdef CHIP_6204
  #undef CHIP_6204
  #define CHIP_6204 1
#else
  #define CHIP_6204 0
#endif

#ifdef CHIP_6205
  #undef CHIP_6205
  #define CHIP_6205 1
#else
  #define CHIP_6205 0
#endif

#ifdef CHIP_6211
  #undef CHIP_6211
  #define CHIP_6211 1
#else
  #define CHIP_6211 0
#endif

#ifdef CHIP_6701
  #undef CHIP_6701
  #define CHIP_6701 1
#else
  #define CHIP_6701 0
#endif

#ifdef CHIP_6711
  #undef CHIP_6711
  #define CHIP_6711 1
#else
  #define CHIP_6711 0
#endif

#ifdef CHIP_6712
  #undef CHIP_6712
  #define CHIP_6712 1
#else
  #define CHIP_6712 0
#endif


#ifdef CHIP_6713
  #undef CHIP_6713
  #define CHIP_6713 1
#else
  #define CHIP_6713 0
#endif

#ifdef CHIP_DA610
  #undef CHIP_DA610
  #define CHIP_DA610 1
#else
  #define CHIP_DA610 0
#endif

#ifdef CHIP_DM642
  #undef CHIP_DM642
  #define CHIP_DM642 1
#else
  #define CHIP_DM642 0
#endif

#ifdef CHIP_DM641
  #undef CHIP_DM641
  #define CHIP_DM641 1
#else
  #define CHIP_DM641 0
#endif

#ifdef CHIP_DM640
  #undef CHIP_DM640
  #define CHIP_DM640 1
#else
  #define CHIP_DM640 0
#endif

#ifdef CHIP_6412
  #undef CHIP_6412
  #define CHIP_6412 1
#else
  #define CHIP_6412 0
#endif

#ifdef CHIP_6414
  #undef CHIP_6414
  #define CHIP_6414 1
#else
  #define CHIP_6414 0
#endif

#ifdef CHIP_6415
  #undef CHIP_6415
  #define CHIP_6415 1
#else
  #define CHIP_6415 0
#endif

#ifdef CHIP_6416
  #undef CHIP_6416
  #define CHIP_6416 1
#else
  #define CHIP_6416 0
#endif

#ifdef CHIP_6711C
  #undef CHIP_6711C
  #define CHIP_6711C 1
#else
  #define CHIP_6711C 0
#endif

#ifdef CHIP_6712C
  #undef CHIP_6712C
  #define CHIP_6712C 1
#else
  #define CHIP_6712C 0
#endif

#ifdef CHIP_6411
  #undef CHIP_6411
  #define CHIP_6411 1
#else
  #define CHIP_6411 0
#endif

/* next two are DRI300 versions */
#ifdef CHIP_6410
  #undef CHIP_6410
  #define CHIP_6410 1
#else
  #define CHIP_6410 0
#endif

#ifdef CHIP_6413
  #undef CHIP_6413
  #define CHIP_6413 1
#else
  #define CHIP_6413 0
#endif

#ifdef CHIP_6418
  #undef CHIP_6418
  #define CHIP_6418 1
#else
  #define CHIP_6418 0
#endif

#define CHIP_OROFALL (\
  CHIP_6201 | \
  CHIP_6202 | \
  CHIP_6203 | \
  CHIP_6204 | \
  CHIP_6205 | \
  CHIP_6211 | \
  CHIP_6701 | \
  CHIP_6711 | \
  CHIP_6712 | \
  CHIP_6713 | \
  CHIP_DA610 | \
  CHIP_DM642 | \
  CHIP_DM641 | \
  CHIP_DM640 | \
  CHIP_6412 | \
  CHIP_6414 | \
  CHIP_6415 | \
  CHIP_6416 |  \
  CHIP_6711C | \
  CHIP_6712C | \
  CHIP_6411 |\
  CHIP_6410 |\
  CHIP_6413 |\
  CHIP_6418 \
)

#if (CHIP_OROFALL==0)
  #error NO CHIP DEFINED (use -dCHIP_XXXX where XXXX is chip number, i.e. 6201)
#endif

#define CHIP_NONE 0

#define CHIP_SUPPORT(c0,c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13,c14,c15,c16,c17,c18,c19,c20,c21,c22,c23,c24) ( \
  ( c0*CHIP_6201)  | \
  ( c1*CHIP_6202)  | \
  ( c2*CHIP_6203)  | \
  ( c3*CHIP_6204)  | \
  ( c4*CHIP_6205)  | \
  ( c5*CHIP_6211)  | \
  ( c6*CHIP_6701)  | \
  ( c7*CHIP_6711)  | \
  ( c8*CHIP_6712)  | \
  ( c9*CHIP_6713)  | \
  ( c10*CHIP_DA610)| \
  ( c11*CHIP_DM642)| \
  ( c12*CHIP_DM641)| \
  ( c13*CHIP_DM640)| \
  ( c14*CHIP_6412) | \
  ( c15*CHIP_6414) | \
  ( c16*CHIP_6415) | \
  ( c17*CHIP_6416) | \
  ( c18*CHIP_6711C) | \
  ( c19*CHIP_6712C) | \
  ( c20*CHIP_6411) | \
  ( c21*CHIP_6410) | \
  ( c22*CHIP_6413) | \
  ( c23*CHIP_6418) | \
  ( c24*CHIP_NONE)   \
 )

/*---------------------------------------------------------------------------------------*/
/*                                     6 6 6 6 6 6 6 6 6 6 D D D D 6 6 6 6 6 6 6 6 6 6 N */
/*                                     2 2 2 2 2 2 7 7 7 7 A M M M 4 4 4 4 7 7 4 4 4 4 O */
/*                                     0 0 0 0 0 1 0 1 1 1 6 6 6 6 1 1 1 1 1 1 1 1 1 1 N */
/*                                     1 2 3 4 5 1 1 1 2 3 1 4 4 4 2 4 5 6 1 2 1 0 3 8 E */
/*                                                         0 2 1 0         C C           */
/*---------------------------------------------------------------------------------------*/
#define CACHE_SUPPORT     CHIP_SUPPORT(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0)
#define DMA_SUPPORT       CHIP_SUPPORT(1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0)
#define EDMA_SUPPORT      CHIP_SUPPORT(0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0)
#define EMIF_SUPPORT      CHIP_SUPPORT(1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0)
#define EMIFA_SUPPORT     CHIP_SUPPORT(0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,0)
#define EMIFB_SUPPORT     CHIP_SUPPORT(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0)
#define GPIO_SUPPORT      CHIP_SUPPORT(0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0)
#define HPI_SUPPORT       CHIP_SUPPORT(1,0,0,0,0,1,1,1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,0)
#define I2C_SUPPORT       CHIP_SUPPORT(0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,0)
#define IRQ_SUPPORT       CHIP_SUPPORT(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0)
#define MCASP_SUPPORT     CHIP_SUPPORT(0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,0)
#define MCBSP_SUPPORT     CHIP_SUPPORT(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0)
#define PLL_SUPPORT       CHIP_SUPPORT(0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,1,1,0,0,0,0,0)
#define TIMER_SUPPORT     CHIP_SUPPORT(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0)
#define XBUS_SUPPORT      CHIP_SUPPORT(0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0)
#define PCI_SUPPORT       CHIP_SUPPORT(0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,1,1,0,0,1,0,0,0,0)
/*---------------------------------------------------------------------------------------*/
/*                                     6 6 6 6 6 6 6 6 6 6 D D D D 6 6 6 6 6 6 6 6 6 6 N */
/*                                     2 2 2 2 2 2 7 7 7 7 A M M M 4 4 4 4 7 7 4 4 4 4 O */
/*                                     0 0 0 0 0 1 0 1 1 1 6 6 6 6 1 1 1 1 1 1 1 1 1 1 N */
/*                                     1 2 3 4 5 1 1 1 2 3 1 4 4 4 2 4 5 6 1 2 1 0 3 8 E */
/*                                                         0 2 1 0         C C           */
/*---------------------------------------------------------------------------------------*/
#define VP_SUPPORT        CHIP_SUPPORT(0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0)
#define VIC_SUPPORT       CHIP_SUPPORT(0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0)
#define DAT_SUPPORT       CHIP_SUPPORT(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0)
#define PWR_SUPPORT       CHIP_SUPPORT(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0)
#define UTOP_SUPPORT      CHIP_SUPPORT(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0)
#define TCP_SUPPORT       CHIP_SUPPORT(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0)
#define VCP_SUPPORT       CHIP_SUPPORT(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0)
#define EMAC_SUPPORT      CHIP_SUPPORT(0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0)
#define MDIO_SUPPORT      CHIP_SUPPORT(0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0)
#define EMU_SUPPORT	  CHIP_SUPPORT(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0)
                                                                                       
#define L2CACHE_SUPPORT   CHIP_SUPPORT(0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0)
#define TC_SUPPORT        CHIP_SUPPORT(0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0)
#define FPU_SUPPORT       CHIP_SUPPORT(0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0)
#define C01_SUPPORT       CHIP_SUPPORT(1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0)
#define C11_SUPPORT       CHIP_SUPPORT(0,0,0,0,0,1,0,1,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0)
#define C64_SUPPORT       CHIP_SUPPORT(0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,0)
#define ATL_SUPPORT       CHIP_SUPPORT(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0)

#define CACHE_L2_SUPPORT  L2CACHE_SUPPORT
/*----------------------------------------------------------------------*/


/******************************************************************************\
* module level register/field access macros
\******************************************************************************/

  /* ----------------- */
  /* FIELD MAKE MACROS */
  /* ----------------- */

  #define CHIP_FMK(REG,FIELD,x)\
    _PER_FMK(CHIP,##REG,##FIELD,x)

  #define CHIP_FMKS(REG,FIELD,SYM)\
    _PER_FMKS(CHIP,##REG,##FIELD,##SYM)


  /* -------------------------------- */
  /* RAW REGISTER/FIELD ACCESS MACROS */
  /* -------------------------------- */

  #define CHIP_CRGET(REG)\
    _PER_CRGET(CHIP,##REG)

  #define CHIP_CRSET(REG,x)\
    _PER_CRSET(CHIP,##REG,x)

  #define CHIP_RGET(REG)\
   _PER_RGET(_CHIP_##REG##_ADDR,CHIP,##REG)

  #define CHIP_RSET(REG,x)\
     _PER_RSET(_CHIP_##REG##_ADDR,CHIP,##REG,x)


  #define CHIP_FGET(REG,FIELD)\
    _CHIP_##REG##_FGET(##FIELD)

  #define CHIP_FSET(REG,FIELD,x)\
    _CHIP_##REG##_FSET(##FIELD,x)

  #define CHIP_FSETS(REG,FIELD,SYM)\
    _CHIP_##REG##_FSETS(##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  C S R            |
* |___________________|
*
* CSR - control/status register
*
* FIELDS (msb -> lsb)
* (r)  CPUID
* (r)  REVID
* (rw) PWRD
* (rc) SAT
* (r)  EN
* (rw) PCC
* (rw) DCC
* (rw) PGIE
* (rw) GIE
*
\******************************************************************************/
  extern far cregister volatile unsigned int CSR;

  #define _CHIP_CSR_CPUID_MASK         0xFF000000u
  #define _CHIP_CSR_CPUID_SHIFT        0x00000018u
  #define  CHIP_CSR_CPUID_DEFAULT      0x00000000u
  #define  CHIP_CSR_CPUID_OF(x)        _VALUEOF(x)
  #define  CHIP_CSR_CPUID_C62X         0x00000000u
  #define  CHIP_CSR_CPUID_C67X         0x00000002u
  #define  CHIP_CSR_CPUID_C64X         0x00000004u

  #define _CHIP_CSR_REVID_MASK         0x00FF0000u
  #define _CHIP_CSR_REVID_SHIFT        0x00000010u
  #define  CHIP_CSR_REVID_DEFAULT      0x00000000u
  #define  CHIP_CSR_REVID_OF(x)        _VALUEOF(x)
  #define  CHIP_CSR_REVID_620120       0x00000001u
  #define  CHIP_CSR_REVID_620121       0x00000001u
  #define  CHIP_CSR_REVID_620130       0x00000002u
  #define  CHIP_CSR_REVID_670100       0x00000201u
  #define  CHIP_CSR_REVID_670110       0x00000202u
  #define  CHIP_CSR_REVID_621110       0x00000002u
  #define  CHIP_CSR_REVID_640010       0x00000801u
  #define  CHIP_CSR_REVID_6202         0x00000002u
  #define  CHIP_CSR_REVID_6202B        0x00000003u
  #define  CHIP_CSR_REVID_6711         0x00000002u
  #define  CHIP_CSR_REVID_6711C        0x00000003u
  #define  CHIP_CSR_REVID_6712         0x00000002u
  #define  CHIP_CSR_REVID_6712C        0x00000003u

  #define _CHIP_CSR_PWRD_MASK          0x0000FC00u
  #define _CHIP_CSR_PWRD_SHIFT         0x0000000Au
  #define  CHIP_CSR_PWRD_DEFAULT       0x00000000u
  #define  CHIP_CSR_PWRD_OF(x)         _VALUEOF(x)
  #define  CHIP_CSR_PWRD_NONE          0x00000000u
  #define  CHIP_CSR_PWRD_PD1A          0x00000009u
  #define  CHIP_CSR_PWRD_PD1B          0x00000011u
  #define  CHIP_CSR_PWRD_PD2           0x0000001Au
  #define  CHIP_CSR_PWRD_PD3           0x0000001Cu

  #define _CHIP_CSR_SAT_MASK           0x00000200u
  #define _CHIP_CSR_SAT_SHIFT          0x00000009u
  #define  CHIP_CSR_SAT_DEFAULT        0x00000000u
  #define  CHIP_CSR_SAT_OF(x)          _VALUEOF(x)
  #define  CHIP_CSR_SAT_0              0x00000000u
  #define  CHIP_CSR_SAT_1              0x00000001u

  #define _CHIP_CSR_EN_MASK            0x00000100u
  #define _CHIP_CSR_EN_SHIFT           0x00000008u
  #define  CHIP_CSR_EN_DEFAULT         0x00000000u
  #define  CHIP_CSR_EN_OF(x)           _VALUEOF(x)
  #define  CHIP_CSR_EN_BIG             0x00000000u
  #define  CHIP_CSR_EN_LITTLE          0x00000001u

  #define _CHIP_CSR_PCC_MASK           0x000000E0u
  #define _CHIP_CSR_PCC_SHIFT          0x00000005u
  #define  CHIP_CSR_PCC_DEFAULT        0x00000000u
  #define  CHIP_CSR_PCC_OF(x)          _VALUEOF(x)
  #define  CHIP_CSR_PCC_MAPPED         0x00000000u
  #define  CHIP_CSR_PCC_ENABLE         0x00000002u
  #define  CHIP_CSR_PCC_FREEZE         0x00000003u
  #define  CHIP_CSR_PCC_BYPASS         0x00000004u

  #define _CHIP_CSR_DCC_MASK           0x0000001Cu
  #define _CHIP_CSR_DCC_SHIFT          0x00000002u
  #define  CHIP_CSR_DCC_DEFAULT        0x00000000u
  #define  CHIP_CSR_DCC_OF(x)          _VALUEOF(x)
  #define  CHIP_CSR_DCC_MAPPED         0x00000000u
  #define  CHIP_CSR_DCC_ENABLE         0x00000002u
  #define  CHIP_CSR_DCC_FREEZE         0x00000003u
  #define  CHIP_CSR_DCC_BYPASS         0x00000004u

  #define _CHIP_CSR_PGIE_MASK          0x00000002u
  #define _CHIP_CSR_PGIE_SHIFT         0x00000001u
  #define  CHIP_CSR_PGIE_DEFAULT       0x00000000u
  #define  CHIP_CSR_PGIE_OF(x)         _VALUEOF(x)
  #define  CHIP_CSR_PGIE_0             0x00000000u
  #define  CHIP_CSR_PGIE_1             0x00000001u

  #define _CHIP_CSR_GIE_MASK           0x00000001u
  #define _CHIP_CSR_GIE_SHIFT          0x00000000u
  #define  CHIP_CSR_GIE_DEFAULT        0x00000000u
  #define  CHIP_CSR_GIE_OF(x)          _VALUEOF(x)
  #define  CHIP_CSR_GIE_0              0x00000000u
  #define  CHIP_CSR_GIE_1              0x00000001u

  #define  CHIP_CSR_OF(x)              _VALUEOF(x)

  #define CHIP_CSR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CHIP,CSR,CPUID) \
    |_PER_FDEFAULT(CHIP,CSR,REVID) \
    |_PER_FDEFAULT(CHIP,CSR,PWRD) \
    |_PER_FDEFAULT(CHIP,CSR,SAT) \
    |_PER_FDEFAULT(CHIP,CSR,EN) \
    |_PER_FDEFAULT(CHIP,CSR,PCC) \
    |_PER_FDEFAULT(CHIP,CSR,DCC) \
    |_PER_FDEFAULT(CHIP,CSR,PGIE) \
    |_PER_FDEFAULT(CHIP,CSR,GIE) \
  )

  #define CHIP_CSR_RMK(pwrd,pcc,dcc,pgie,gie) (Uint32)( \
     _PER_FMK(CHIP,CSR,PWRD,pwrd) \
    |_PER_FMK(CHIP,CSR,PCC,pcc) \
    |_PER_FMK(CHIP,CSR,DCC,dcc) \
    |_PER_FMK(CHIP,CSR,PGIE,pgie) \
    |_PER_FMK(CHIP,CSR,GIE,gie) \
  )

  #define _CHIP_CSR_FGET(FIELD)\
    _PER_CFGET(CHIP,CSR,##FIELD)

  #define _CHIP_CSR_FSET(FIELD,field)\
    _PER_CFSET(CHIP,CSR,##FIELD,field)

  #define _CHIP_CSR_FSETS(FIELD,SYM)\
    _PER_CFSETS(CHIP,CSR,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  I F R            |
* |___________________|
*
* IFR - interruppt flag register
*
* FIELDS (msb -> lsb)
* (rw) IF
*
\******************************************************************************/
  extern far cregister volatile unsigned int IFR;

  #define _CHIP_IFR_IF_MASK          0x0000FFFFu
  #define _CHIP_IFR_IF_SHIFT         0x00000000u
  #define  CHIP_IFR_IF_DEFAULT       0x00000000u
  #define  CHIP_IFR_IF_OF(x)         _VALUEOF(x)

  #define  CHIP_IFR_OF(x)            _VALUEOF(x)

  #define CHIP_IFR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CHIP,IFR,IF)\
  )

  #define CHIP_IFR_RMK(if) (Uint32)( \
     _PER_FMK(CHIP,IFR,IF,if)\
  )

  #define _CHIP_IFR_FGET(FIELD)\
    _PER_CFGET(CHIP,IFR,##FIELD)

  #define _CHIP_IFR_FSET(FIELD,field)\
    _PER_CFSET(CHIP,IFR,##FIELD,field)

  #define _CHIP_IFR_FSETS(FIELD,SYM)\
    _PER_CFSETS(CHIP,IFR,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  I S R            |
* |___________________|
*
* ISR - interruppt set register
*
* FIELDS (msb -> lsb)
* (w) IS
*
\******************************************************************************/
  extern far cregister volatile unsigned int ISR;

  #define _CHIP_ISR_IS_MASK          0x0000FFFFu
  #define _CHIP_ISR_IS_SHIFT         0x00000000u
  #define  CHIP_ISR_IS_DEFAULT       0x00000000u
  #define  CHIP_ISR_IS_OF(x)         _VALUEOF(x)

  #define  CHIP_ISR_OF(x)            _VALUEOF(x)

  #define CHIP_ISR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CHIP,ISR,IS)\
  )

  #define CHIP_ISR_RMK(is) (Uint32)( \
     _PER_FMK(CHIP,ISR,IS,is)\
  )

  #define _CHIP_ISR_FGET(FIELD)\
    _PER_CFGET(CHIP,ISR,##FIELD)

  #define _CHIP_ISR_FSET(FIELD,field)\
    _PER_CFSET(CHIP,ISR,##FIELD,field)

  #define _CHIP_ISR_FSETS(FIELD,SYM)\
    _PER_CFSETS(CHIP,ISR,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  I C R            |
* |___________________|
*
* ICR - interruppt clear register
*
* FIELDS (msb -> lsb)
* (w) IC
*
\******************************************************************************/
  extern far cregister volatile unsigned int ICR;

  #define _CHIP_ICR_IC_MASK          0x0000FFFFu
  #define _CHIP_ICR_IC_SHIFT         0x00000000u
  #define  CHIP_ICR_IC_DEFAULT       0x00000000u
  #define  CHIP_ICR_IC_OF(x)         _VALUEOF(x)

  #define  CHIP_ICR_OF(x)            _VALUEOF(x)

  #define CHIP_ICR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CHIP,ICR,IC)\
  )

  #define CHIP_ICR_RMK(ic) (Uint32)( \
     _PER_FMK(CHIP,ICR,IC,ic)\
  )

  #define _CHIP_ICR_FGET(FIELD)\
    _PER_CFGET(CHIP,ICR,##FIELD)

  #define _CHIP_ICR_FSET(FIELD,field)\
    _PER_CFSET(CHIP,ICR,##FIELD,field)

  #define _CHIP_ICR_FSETS(FIELD,SYM)\
    _PER_CFSETS(CHIP,ICR,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  I E R            |
* |___________________|
*
* IER - interruppt enable register
*
* FIELDS (msb -> lsb)
* (rw) IE
*
\******************************************************************************/
  extern far cregister volatile unsigned int IER;

  #define _CHIP_IER_IE_MASK          0x0000FFFFu
  #define _CHIP_IER_IE_SHIFT         0x00000000u
  #define  CHIP_IER_IE_DEFAULT       0x00000000u
  #define  CHIP_IER_IE_OF(x)         _VALUEOF(x)

  #define  CHIP_IER_OF(x)            _VALUEOF(x)

  #define CHIP_IER_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CHIP,IER,IE)\
  )

  #define CHIP_IER_RMK(ie) (Uint32)( \
     _PER_FMK(CHIP,IER,IE,ie)\
  )

  #define _CHIP_IER_FGET(FIELD)\
    _PER_CFGET(CHIP,IER,##FIELD)

  #define _CHIP_IER_FSET(FIELD,field)\
    _PER_CFSET(CHIP,IER,##FIELD,field)

  #define _CHIP_IER_FSETS(FIELD,SYM)\
    _PER_CFSETS(CHIP,IER,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  I S T P          |
* |___________________|
*
* ISTP - interrupt service table pointer
*
* FIELDS (msb -> lsb)
* (r)   HPEINT
* (rw)  ISTB
*
\******************************************************************************/
  extern far cregister volatile unsigned int ISTP;

  #define _CHIP_ISTP_ISTB_MASK         0xFFFFFC00u
  #define _CHIP_ISTP_ISTB_SHIFT        0x0000000Au
  #define  CHIP_ISTP_ISTB_DEFAULT      0x00000000u
  #define  CHIP_ISTP_ISTB_OF(x)        _VALUEOF(x)

  #define _CHIP_ISTP_HPEINT_MASK       0x000003E0u
  #define _CHIP_ISTP_HPEINT_SHIFT      0x00000005u
  #define  CHIP_ISTP_HPEINT_DEFAULT    0x00000000u
  #define  CHIP_ISTP_HPEINT_OF(x)      _VALUEOF(x)

  #define  CHIP_ISTP_OF(x)             _VALUEOF(x)

  #define CHIP_ISTP_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CHIP,ISTP,ISTB)\
    |_PER_FDEFAULT(CHIP,ISTP,HPEINT)\
  )

  #define CHIP_ISTP_RMK(istb) (Uint32)( \
     _PER_FMK(CHIP,ISTP,ISTB,istb)\
  )

  #define _CHIP_ISTP_FGET(FIELD)\
    _PER_CFGET(CHIP,ISTP,##FIELD)

  #define _CHIP_ISTP_FSET(FIELD,field)\
    _PER_CFSET(CHIP,ISTP,##FIELD,field)

  #define _CHIP_ISTP_FSETS(FIELD,SYM)\
    _PER_CFSETS(CHIP,ISTP,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  I R P            |
* |___________________|
*
* IRP - interrupt return pointer
*
* FIELDS (msb -> lsb)
* (rw) IRP
*
\******************************************************************************/
  extern far cregister volatile unsigned int IRP;

  #define _CHIP_IRP_IRP_MASK           0xFFFFFFFFu
  #define _CHIP_IRP_IRP_SHIFT          0x00000000u
  #define  CHIP_IRP_IRP_DEFAULT        0x00000000u
  #define  CHIP_IRP_IRP_OF(x)          _VALUEOF(x)

  #define  CHIP_IRP_OF(x)              _VALUEOF(x)

  #define CHIP_IRP_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CHIP,IRP,IRP)\
  )

  #define CHIP_IRP_RMK(irp) (Uint32)( \
     _PER_FMK(CHIP,IRP,IRP,irp)\
  )

  #define _CHIP_IRP_FGET(FIELD)\
    _PER_CFGET(CHIP,IRP,##FIELD)

  #define _CHIP_IRP_FSET(FIELD,field)\
    _PER_CFSET(CHIP,IRP,##FIELD,field)

  #define _CHIP_IRP_FSETS(FIELD,SYM)\
    _PER_CFSETS(CHIP,IRP,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  N R P            |
* |___________________|
*
* NRP - non-maskable interrupt return pointer
*
* FIELDS (msb -> lsb)
* (rw) NRP
*
\******************************************************************************/
  extern far cregister volatile unsigned int NRP;

  #define _CHIP_NRP_NRP_MASK           0xFFFFFFFFu
  #define _CHIP_NRP_NRP_SHIFT          0x00000000u
  #define  CHIP_NRP_NRP_DEFAULT        0x00000000u
  #define  CHIP_NRP_NRP_OF(x)          _VALUEOF(x)

  #define  CHIP_NRP_OF(x)              _VALUEOF(x)

  #define CHIP_NRP_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CHIP,NRP,NRP)\
  )

  #define CHIP_NRP_RMK(nrp) (Uint32)( \
     _PER_FMK(CHIP,NRP,NRP,nrp)\
  )

  #define _CHIP_NRP_FGET(FIELD)\
    _PER_CFGET(CHIP,NRP,##FIELD)

  #define _CHIP_NRP_FSET(FIELD,field)\
    _PER_CFSET(CHIP,NRP,##FIELD,field)

  #define _CHIP_NRP_FSETS(FIELD,SYM)\
    _PER_CFSETS(CHIP,NRP,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  A M R            |
* |___________________|
*
* AMR - addressing mode register
*
* FIELDS (msb -> lsb)
* (rw) BK1
* (rw) BK0
* (rw) B7MODE
* (rw) B6MODE
* (rw) B5MODE
* (rw) B4MODE
* (rw) A7MODE
* (rw) A6MODE
* (rw) A5MODE
* (rw) A4MODE
*
\******************************************************************************/
  extern far cregister volatile unsigned int AMR;

  #define _CHIP_AMR_BK1_MASK           0x02E00000u
  #define _CHIP_AMR_BK1_SHIFT          0x00000015u
  #define  CHIP_AMR_BK1_DEFAULT        0x00000000u
  #define  CHIP_AMR_BK1_OF(x)          _VALUEOF(x)
  #define  CHIP_AMR_BK1_2              0x00000000u
  #define  CHIP_AMR_BK1_4              0x00000001u
  #define  CHIP_AMR_BK1_8              0x00000002u
  #define  CHIP_AMR_BK1_16             0x00000003u
  #define  CHIP_AMR_BK1_32             0x00000004u
  #define  CHIP_AMR_BK1_64             0x00000005u
  #define  CHIP_AMR_BK1_128            0x00000006u
  #define  CHIP_AMR_BK1_256            0x00000007u
  #define  CHIP_AMR_BK1_512            0x00000008u
  #define  CHIP_AMR_BK1_1K             0x00000009u
  #define  CHIP_AMR_BK1_2K             0x0000000Au
  #define  CHIP_AMR_BK1_4K             0x0000000Bu
  #define  CHIP_AMR_BK1_8K             0x0000000Cu
  #define  CHIP_AMR_BK1_16K            0x0000000Du
  #define  CHIP_AMR_BK1_32K            0x0000000Eu
  #define  CHIP_AMR_BK1_64K            0x0000000Fu
  #define  CHIP_AMR_BK1_128K           0x00000010u
  #define  CHIP_AMR_BK1_256K           0x00000011u
  #define  CHIP_AMR_BK1_512K           0x00000012u
  #define  CHIP_AMR_BK1_1M             0x00000013u
  #define  CHIP_AMR_BK1_2M             0x00000014u
  #define  CHIP_AMR_BK1_4M             0x00000015u
  #define  CHIP_AMR_BK1_8M             0x00000016u
  #define  CHIP_AMR_BK1_16M            0x00000017u
  #define  CHIP_AMR_BK1_32M            0x00000018u
  #define  CHIP_AMR_BK1_64M            0x00000019u
  #define  CHIP_AMR_BK1_128M           0x0000001Au
  #define  CHIP_AMR_BK1_256M           0x0000001Bu
  #define  CHIP_AMR_BK1_512M           0x0000001Cu
  #define  CHIP_AMR_BK1_1G             0x0000001Du
  #define  CHIP_AMR_BK1_2G             0x0000001Eu
  #define  CHIP_AMR_BK1_4G             0x0000001Fu

  #define _CHIP_AMR_BK0_MASK           0x001F0000u
  #define _CHIP_AMR_BK0_SHIFT          0x00000010u
  #define  CHIP_AMR_BK0_DEFAULT        0x00000000u
  #define  CHIP_AMR_BK0_OF(x)          _VALUEOF(x)
  #define  CHIP_AMR_BK0_2              0x00000000u
  #define  CHIP_AMR_BK0_4              0x00000001u
  #define  CHIP_AMR_BK0_8              0x00000002u
  #define  CHIP_AMR_BK0_16             0x00000003u
  #define  CHIP_AMR_BK0_32             0x00000004u
  #define  CHIP_AMR_BK0_64             0x00000005u
  #define  CHIP_AMR_BK0_128            0x00000006u
  #define  CHIP_AMR_BK0_256            0x00000007u
  #define  CHIP_AMR_BK0_512            0x00000008u
  #define  CHIP_AMR_BK0_1K             0x00000009u
  #define  CHIP_AMR_BK0_2K             0x0000000Au
  #define  CHIP_AMR_BK0_4K             0x0000000Bu
  #define  CHIP_AMR_BK0_8K             0x0000000Cu
  #define  CHIP_AMR_BK0_16K            0x0000000Du
  #define  CHIP_AMR_BK0_32K            0x0000000Eu
  #define  CHIP_AMR_BK0_64K            0x0000000Fu
  #define  CHIP_AMR_BK0_128K           0x00000010u
  #define  CHIP_AMR_BK0_256K           0x00000011u
  #define  CHIP_AMR_BK0_512K           0x00000012u
  #define  CHIP_AMR_BK0_1M             0x00000013u
  #define  CHIP_AMR_BK0_2M             0x00000014u
  #define  CHIP_AMR_BK0_4M             0x00000015u
  #define  CHIP_AMR_BK0_8M             0x00000016u
  #define  CHIP_AMR_BK0_16M            0x00000017u
  #define  CHIP_AMR_BK0_32M            0x00000018u
  #define  CHIP_AMR_BK0_64M            0x00000019u
  #define  CHIP_AMR_BK0_128M           0x0000001Au
  #define  CHIP_AMR_BK0_256M           0x0000001Bu
  #define  CHIP_AMR_BK0_512M           0x0000001Cu
  #define  CHIP_AMR_BK0_1G             0x0000001Du
  #define  CHIP_AMR_BK0_2G             0x0000001Eu
  #define  CHIP_AMR_BK0_4G             0x0000001Fu


  #define _CHIP_AMR_B7MODE_MASK        0x0000C000u
  #define _CHIP_AMR_B7MODE_SHIFT       0x0000000Eu
  #define  CHIP_AMR_B7MODE_DEFAULT     0x00000000u
  #define  CHIP_AMR_B7MODE_OF(x)       _VALUEOF(x)
  #define  CHIP_AMR_B7MODE_LINEAR      0x00000000u
  #define  CHIP_AMR_B7MODE_CIRCULAR0   0x00000001u
  #define  CHIP_AMR_B7MODE_CIRCULAR1   0x00000002u

  #define _CHIP_AMR_B6MODE_MASK        0x00003000u
  #define _CHIP_AMR_B6MODE_SHIFT       0x0000000Cu
  #define  CHIP_AMR_B6MODE_DEFAULT     0x00000000u
  #define  CHIP_AMR_B6MODE_OF(x)       _VALUEOF(x)
  #define  CHIP_AMR_B6MODE_LINEAR      0x00000000u
  #define  CHIP_AMR_B6MODE_CIRCULAR0   0x00000001u
  #define  CHIP_AMR_B6MODE_CIRCULAR1   0x00000002u

  #define _CHIP_AMR_B5MODE_MASK        0x00000C00u
  #define _CHIP_AMR_B5MODE_SHIFT       0x0000000Au
  #define  CHIP_AMR_B5MODE_DEFAULT     0x00000000u
  #define  CHIP_AMR_B5MODE_OF(x)       _VALUEOF(x)
  #define  CHIP_AMR_B5MODE_LINEAR      0x00000000u
  #define  CHIP_AMR_B5MODE_CIRCULAR0   0x00000001u
  #define  CHIP_AMR_B5MODE_CIRCULAR1   0x00000002u

  #define _CHIP_AMR_B4MODE_MASK        0x00000300u
  #define _CHIP_AMR_B4MODE_SHIFT       0x00000008u
  #define  CHIP_AMR_B4MODE_DEFAULT     0x00000000u
  #define  CHIP_AMR_B4MODE_OF(x)       _VALUEOF(x)
  #define  CHIP_AMR_B4MODE_LINEAR      0x00000000u
  #define  CHIP_AMR_B4MODE_CIRCULAR0   0x00000001u
  #define  CHIP_AMR_B4MODE_CIRCULAR1   0x00000002u

  #define _CHIP_AMR_A7MODE_MASK        0x000000C0u
  #define _CHIP_AMR_A7MODE_SHIFT       0x00000006u
  #define  CHIP_AMR_A7MODE_DEFAULT     0x00000000u
  #define  CHIP_AMR_A7MODE_OF(x)       _VALUEOF(x)
  #define  CHIP_AMR_A7MODE_LINEAR      0x00000000u
  #define  CHIP_AMR_A7MODE_CIRCULAR0   0x00000001u
  #define  CHIP_AMR_A7MODE_CIRCULAR1   0x00000002u

  #define _CHIP_AMR_A6MODE_MASK        0x00000030u
  #define _CHIP_AMR_A6MODE_SHIFT       0x00000004u
  #define  CHIP_AMR_A6MODE_DEFAULT     0x00000000u
  #define  CHIP_AMR_A6MODE_OF(x)       _VALUEOF(x)
  #define  CHIP_AMR_A6MODE_LINEAR      0x00000000u
  #define  CHIP_AMR_A6MODE_CIRCULAR0   0x00000001u
  #define  CHIP_AMR_A6MODE_CIRCULAR1   0x00000002u

  #define _CHIP_AMR_A5MODE_MASK        0x0000000Cu
  #define _CHIP_AMR_A5MODE_SHIFT       0x00000002u
  #define  CHIP_AMR_A5MODE_DEFAULT     0x00000000u
  #define  CHIP_AMR_A5MODE_OF(x)       _VALUEOF(x)
  #define  CHIP_AMR_A5MODE_LINEAR      0x00000000u
  #define  CHIP_AMR_A5MODE_CIRCULAR0   0x00000001u
  #define  CHIP_AMR_A5MODE_CIRCULAR1   0x00000002u

  #define _CHIP_AMR_A4MODE_MASK        0x00000003u
  #define _CHIP_AMR_A4MODE_SHIFT       0x00000000u
  #define  CHIP_AMR_A4MODE_DEFAULT     0x00000000u
  #define  CHIP_AMR_A4MODE_OF(x)       _VALUEOF(x)
  #define  CHIP_AMR_A4MODE_LINEAR      0x00000000u
  #define  CHIP_AMR_A4MODE_CIRCULAR0   0x00000001u
  #define  CHIP_AMR_A4MODE_CIRCULAR1   0x00000002u

  #define  CHIP_AMR_OF(x)              _VALUEOF(x)

  #define CHIP_AMR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CHIP,AMR,BK1)\
    |_PER_FDEFAULT(CHIP,AMR,BK0)\
    |_PER_FDEFAULT(CHIP,AMR,B7MODE)\
    |_PER_FDEFAULT(CHIP,AMR,B6MODE)\
    |_PER_FDEFAULT(CHIP,AMR,B5MODE)\
    |_PER_FDEFAULT(CHIP,AMR,B4MODE)\
    |_PER_FDEFAULT(CHIP,AMR,A7MODE)\
    |_PER_FDEFAULT(CHIP,AMR,A6MODE)\
    |_PER_FDEFAULT(CHIP,AMR,A5MODE)\
    |_PER_FDEFAULT(CHIP,AMR,A4MODE)\
  )

  #define CHIP_AMR_RMK(bk1,bk0,b7mode,b6mode,b5mode,b4mode,a7,ode,\
    a6mode,a5mode,a4mode) (Uint32)( \
     _PER_FMK(CHIP,AMR,BK1,bk1)\
    |_PER_FMK(CHIP,AMR,BK0,bk0)\
    |_PER_FMK(CHIP,AMR,B7MODE,b7mode)\
    |_PER_FMK(CHIP,AMR,B6MODE,b6mode)\
    |_PER_FMK(CHIP,AMR,B5MODE,b5mode)\
    |_PER_FMK(CHIP,AMR,B4MODE,b4mode)\
    |_PER_FMK(CHIP,AMR,A7MODE,a7mode)\
    |_PER_FMK(CHIP,AMR,A6MODE,a6mode)\
    |_PER_FMK(CHIP,AMR,A5MODE,a5mode)\
    |_PER_FMK(CHIP,AMR,A4MODE,a4mode)\
  )

  #define _CHIP_AMR_FGET(FIELD)\
    _PER_CFGET(CHIP,AMR,##FIELD)

  #define _CHIP_AMR_FSET(FIELD,field)\
    _PER_CFSET(CHIP,AMR,##FIELD,field)

  #define _CHIP_AMR_FSETS(FIELD,SYM)\
    _PER_CFSETS(CHIP,AMR,##FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  F A D C R        |
* |___________________|
*
* FADCR - floating-point adder config register (1)
*
* FIELDS (msb -> lsb)
* (rw) L2RMODE
* (rw) L2UNDER
* (rw) L2INEX
* (rw) L2OVER
* (rw) L2INFO
* (rw) L2INVAL
* (rw) L2DEN2
* (rw) L2DEN1
* (rw) L2NAN2
* (rw) L2NAN1
* (rw) L1RMODE
* (rw) L1UNDER
* (rw) L1INEX
* (rw) L1OVER
* (rw) L1INFO
* (rw) L1INVAL
* (rw) L1DEN2
* (rw) L1DEN1
* (rw) L1NAN2
* (rw) L1NAN1
*
* (1) only supported on devices with floating point unit
*
\******************************************************************************/
#if (FPU_SUPPORT)
  extern far cregister volatile unsigned int FADCR;

  #define _CHIP_FADCR_L2RMODE_MASK    0x06000000u
  #define _CHIP_FADCR_L2RMODE_SHIFT   0x00000019u
  #define  CHIP_FADCR_L2RMODE_DEFAULT 0x00000000u
  #define  CHIP_FADCR_L2RMODE_OF(x)   _VALUEOF(x)

  #define _CHIP_FADCR_L2UNDER_MASK    0x01000000u
  #define _CHIP_FADCR_L2UNDER_SHIFT   0x00000018u
  #define  CHIP_FADCR_L2UNDER_DEFAULT 0x00000000u
  #define  CHIP_FADCR_L2UNDER_OF(x)   _VALUEOF(x)

  #define _CHIP_FADCR_L2INEX_MASK     0x00800000u
  #define _CHIP_FADCR_L2INEX_SHIFT    0x00000017u
  #define  CHIP_FADCR_L2INEX_DEFAULT  0x00000000u
  #define  CHIP_FADCR_L2INEX_OF(x)    _VALUEOF(x)

  #define _CHIP_FADCR_L2OVER_MASK     0x00400000u
  #define _CHIP_FADCR_L2OVER_SHIFT    0x00000016u
  #define  CHIP_FADCR_L2OVER_DEFAULT  0x00000000u
  #define  CHIP_FADCR_L2OVER_OF(x)    _VALUEOF(x)

  #define _CHIP_FADCR_L2INFO_MASK     0x00200000u
  #define _CHIP_FADCR_L2INFO_SHIFT    0x00000015u
  #define  CHIP_FADCR_L2INFO_DEFAULT  0x00000000u
  #define  CHIP_FADCR_L2INFO_OF(x)    _VALUEOF(x)

  #define _CHIP_FADCR_L2INVAL_MASK    0x00100000u
  #define _CHIP_FADCR_L2INVAL_SHIFT   0x00000014u
  #define  CHIP_FADCR_L2INVAL_DEFAULT 0x00000000u
  #define  CHIP_FADCR_L2INVAL_OF(x)   _VALUEOF(x)

  #define _CHIP_FADCR_L2DEN2_MASK     0x00080000u
  #define _CHIP_FADCR_L2DEN2_SHIFT    0x00000013u
  #define  CHIP_FADCR_L2DEN2_DEFAULT  0x00000000u
  #define  CHIP_FADCR_L2DEN2_OF(x)    _VALUEOF(x)

  #define _CHIP_FADCR_L2DEN1_MASK     0x00040000u
  #define _CHIP_FADCR_L2DEN1_SHIFT    0x00000012u
  #define  CHIP_FADCR_L2DEN1_DEFAULT  0x00000000u
  #define  CHIP_FADCR_L2DEN1_OF(x)    _VALUEOF(x)

  #define _CHIP_FADCR_L2NAN2_MASK     0x00020000u
  #define _CHIP_FADCR_L2NAN2_SHIFT    0x00000011u
  #define  CHIP_FADCR_L2NAN2_DEFAULT  0x00000000u
  #define  CHIP_FADCR_L2NAN2_OF(x)    _VALUEOF(x)

  #define _CHIP_FADCR_L2NAN1_MASK     0x00010000u
  #define _CHIP_FADCR_L2NAN1_SHIFT    0x00000010u
  #define  CHIP_FADCR_L2NAN1_DEFAULT  0x00000000u
  #define  CHIP_FADCR_L2NAN1_OF(x)    _VALUEOF(x)

  #define _CHIP_FADCR_L1RMODE_MASK    0x00000600u
  #define _CHIP_FADCR_L1RMODE_SHIFT   0x00000009u
  #define  CHIP_FADCR_L1RMODE_DEFAULT 0x00000000u
  #define  CHIP_FADCR_L1RMODE_OF(x)   _VALUEOF(x)

  #define _CHIP_FADCR_L1UNDER_MASK    0x00000100u
  #define _CHIP_FADCR_L1UNDER_SHIFT   0x00000008u
  #define  CHIP_FADCR_L1UNDER_DEFAULT 0x00000000u
  #define  CHIP_FADCR_L1UNDER_OF(x)   _VALUEOF(x)

  #define _CHIP_FADCR_L1INEX_MASK     0x00000080u
  #define _CHIP_FADCR_L1INEX_SHIFT    0x00000007u
  #define  CHIP_FADCR_L1INEX_DEFAULT  0x00000000u
  #define  CHIP_FADCR_L1INEX_OF(x)    _VALUEOF(x)

  #define _CHIP_FADCR_L1OVER_MASK     0x00000040u
  #define _CHIP_FADCR_L1OVER_SHIFT    0x00000006u
  #define  CHIP_FADCR_L1OVER_DEFAULT  0x00000000u
  #define  CHIP_FADCR_L1OVER_OF(x)    _VALUEOF(x)

  #define _CHIP_FADCR_L1INFO_MASK     0x00000020u
  #define _CHIP_FADCR_L1INFO_SHIFT    0x00000005u
  #define  CHIP_FADCR_L1INFO_DEFAULT  0x00000000u
  #define  CHIP_FADCR_L1INFO_OF(x)    _VALUEOF(x)

  #define _CHIP_FADCR_L1INVAL_MASK    0x00000010u
  #define _CHIP_FADCR_L1INVAL_SHIFT   0x00000004u
  #define  CHIP_FADCR_L1INVAL_DEFAULT 0x00000000u
  #define  CHIP_FADCR_L1INVAL_OF(x)   _VALUEOF(x)

  #define _CHIP_FADCR_L1DEN2_MASK     0x00000008u
  #define _CHIP_FADCR_L1DEN2_SHIFT    0x00000003u
  #define  CHIP_FADCR_L1DEN2_DEFAULT  0x00000000u
  #define  CHIP_FADCR_L1DEN2_OF(x)    _VALUEOF(x)

  #define _CHIP_FADCR_L1DEN1_MASK     0x00000004u
  #define _CHIP_FADCR_L1DEN1_SHIFT    0x00000002u
  #define  CHIP_FADCR_L1DEN1_DEFAULT  0x00000000u
  #define  CHIP_FADCR_L1DEN1_OF(x)    _VALUEOF(x)

  #define _CHIP_FADCR_L1NAN2_MASK     0x00000002u
  #define _CHIP_FADCR_L1NAN2_SHIFT    0x00000001u
  #define  CHIP_FADCR_L1NAN2_DEFAULT  0x00000000u
  #define  CHIP_FADCR_L1NAN2_OF(x)    _VALUEOF(x)

  #define _CHIP_FADCR_L1NAN1_MASK     0x00000001u
  #define _CHIP_FADCR_L1NAN1_SHIFT    0x00000000u
  #define  CHIP_FADCR_L1NAN1_DEFAULT  0x00000000u
  #define  CHIP_FADCR_L1NAN1_OF(x)    _VALUEOF(x)

  #define  CHIP_FADCR_OF(x)           _VALUEOF(x)

  #define CHIP_FADCR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CHIP,FADCR,L2RMODE)\
    |_PER_FDEFAULT(CHIP,FADCR,L2UNDER)\
    |_PER_FDEFAULT(CHIP,FADCR,L2INEX)\
    |_PER_FDEFAULT(CHIP,FADCR,L2OVER)\
    |_PER_FDEFAULT(CHIP,FADCR,L2INFO)\
    |_PER_FDEFAULT(CHIP,FADCR,L2INVAL)\
    |_PER_FDEFAULT(CHIP,FADCR,L2DEN2)\
    |_PER_FDEFAULT(CHIP,FADCR,L2DEN1)\
    |_PER_FDEFAULT(CHIP,FADCR,L2NAN2)\
    |_PER_FDEFAULT(CHIP,FADCR,L2NAN1)\
    |_PER_FDEFAULT(CHIP,FADCR,L1RMODE)\
    |_PER_FDEFAULT(CHIP,FADCR,L1UNDER)\
    |_PER_FDEFAULT(CHIP,FADCR,L1INEX)\
    |_PER_FDEFAULT(CHIP,FADCR,L1OVER)\
    |_PER_FDEFAULT(CHIP,FADCR,L1INFO)\
    |_PER_FDEFAULT(CHIP,FADCR,L1INVAL)\
    |_PER_FDEFAULT(CHIP,FADCR,L1DEN2)\
    |_PER_FDEFAULT(CHIP,FADCR,L1DEN1)\
    |_PER_FDEFAULT(CHIP,FADCR,L1NAN2)\
    |_PER_FDEFAULT(CHIP,FADCR,L1NAN1)\
  )

  #define CHIP_FADCR_MK(l2rmode,l2under,l2index,l2over,l2info,l2inval,\
    l2den2,l2den1,l2nan2,l2nan1,l1rmode,l1under,l1inex,l1over,l1info,\
    l1inval,l1den2,l1den1,l1nan2,l1nan1) (Uint32)( \
     _PER_FMK(CHIP,FADCR,L2RMODE,l2rmode)\
    |_PER_FMK(CHIP,FADCR,L2UNDER,l2under)\
    |_PER_FMK(CHIP,FADCR,L2INEX,l2inex)\
    |_PER_FMK(CHIP,FADCR,L2OVER,l2over)\
    |_PER_FMK(CHIP,FADCR,L2INFO,l2info)\
    |_PER_FMK(CHIP,FADCR,L2INVAL,l2inval)\
    |_PER_FMK(CHIP,FADCR,L2DEN2,l2den2)\
    |_PER_FMK(CHIP,FADCR,L2DEN1,l2den1)\
    |_PER_FMK(CHIP,FADCR,L2NAN2,l2nan2)\
    |_PER_FMK(CHIP,FADCR,L2NAN1,l2nan1)\
    |_PER_FMK(CHIP,FADCR,L1RMODE,l1rmode)\
    |_PER_FMK(CHIP,FADCR,L1UNDER,l1under)\
    |_PER_FMK(CHIP,FADCR,L1INEX,l1inex)\
    |_PER_FMK(CHIP,FADCR,L1OVER,l1over)\
    |_PER_FMK(CHIP,FADCR,L1INFO,l1info)\
    |_PER_FMK(CHIP,FADCR,L1INVAL,l1inval)\
    |_PER_FMK(CHIP,FADCR,L1DEN2,l1den2)\
    |_PER_FMK(CHIP,FADCR,L1DEN1,l1den1)\
    |_PER_FMK(CHIP,FADCR,L1NAN2,l1nan2)\
    |_PER_FMK(CHIP,FADCR,L1NAN1,l1nan1)\
  )

  #define _CHIP_FADCR_FGET(FIELD)\
    _PER_CFGET(CHIP,FADCR,##FIELD)

  #define _CHIP_FADCR_FSET(FIELD,field)\
    _PER_CFSET(CHIP,FADCR,##FIELD,field)

  #define _CHIP_FADCR_FSETS(FIELD,SYM)\
    _PER_CFSETS(CHIP,FADCR,##FIELD,##SYM)
#endif


/******************************************************************************\
* _____________________
* |                   |
* |  F A U C R        |
* |___________________|
*
* FAUCR - floating-point auxiliary config register (1)
*
* FIELDS (msb -> lsb)
* (rw) S2DIV0
* (rw) S2UNORD
* (rw) S2UND
* (rw) S2INEX
* (rw) S2OVER
* (rw) S2INFO
* (rw) S2INVAL
* (rw) S2DEN2
* (rw) S2DEN1
* (rw) S2NAN2
* (rw) S2NAN1
* (rw) S1DIV0
* (rw) S1UNORD
* (rw) S1UND
* (rw) S1INEX
* (rw) S1OVER
* (rw) S1INFO
* (rw) S1INVAL
* (rw) S1DEN2
* (rw) S1DEN1
* (rw) S1NAN2
* (rw) S1NAN1
*
* (1) only supported on devices with floating point unit
*
\******************************************************************************/
#if (FPU_SUPPORT)
  extern far cregister volatile unsigned int FAUCR;

  #define _CHIP_FAUCR_S2DIV0_MASK     0x04000000u
  #define _CHIP_FAUCR_S2DIV0_SHIFT    0x0000001Au
  #define  CHIP_FAUCR_S2DIV0_DEFAULT  0x00000000u
  #define  CHIP_FAUCR_S2DIV0_OF(x)    _VALUEOF(x)

  #define _CHIP_FAUCR_S2UNORD_MASK    0x02000000u
  #define _CHIP_FAUCR_S2UNORD_SHIFT   0x00000019u
  #define  CHIP_FAUCR_S2UNORD_DEFAULT 0x00000000u
  #define  CHIP_FAUCR_S2UNORD_OF(x)   _VALUEOF(x)

  #define _CHIP_FAUCR_S2UND_MASK      0x01000000u
  #define _CHIP_FAUCR_S2UND_SHIFT     0x00000018u
  #define  CHIP_FAUCR_S2UND_DEFAULT   0x00000000u
  #define  CHIP_FAUCR_S2UND_OF(x)     _VALUEOF(x)

  #define _CHIP_FAUCR_S2INEX_MASK     0x00800000u
  #define _CHIP_FAUCR_S2INEX_SHIFT    0x00000017u
  #define  CHIP_FAUCR_S2INEX_DEFAULT  0x00000000u
  #define  CHIP_FAUCR_S2INEX_OF(x)    _VALUEOF(x)

  #define _CHIP_FAUCR_S2OVER_MASK     0x00400000u
  #define _CHIP_FAUCR_S2OVER_SHIFT    0x00000016u
  #define  CHIP_FAUCR_S2OVER_DEFAULT  0x00000000u
  #define  CHIP_FAUCR_S2OVER_OF(x)    _VALUEOF(x)

  #define _CHIP_FAUCR_S2INFO_MASK     0x00200000u
  #define _CHIP_FAUCR_S2INFO_SHIFT    0x00000015u
  #define  CHIP_FAUCR_S2INFO_DEFAULT  0x00000000u
  #define  CHIP_FAUCR_S2INFO_OF(x)    _VALUEOF(x)

  #define _CHIP_FAUCR_S2INVAL_MASK    0x00100000u
  #define _CHIP_FAUCR_S2INVAL_SHIFT   0x00000014u
  #define  CHIP_FAUCR_S2INVAL_DEFAULT 0x00000000u
  #define  CHIP_FAUCR_S2INVAL_OF(x)   _VALUEOF(x)

  #define _CHIP_FAUCR_S2DEN2_MASK     0x00080000u
  #define _CHIP_FAUCR_S2DEN2_SHIFT    0x00000013u
  #define  CHIP_FAUCR_S2DEN2_DEFAULT  0x00000000u
  #define  CHIP_FAUCR_S2DEN2_OF(x)    _VALUEOF(x)

  #define _CHIP_FAUCR_S2DEN1_MASK     0x00040000u
  #define _CHIP_FAUCR_S2DEN1_SHIFT    0x00000012u
  #define  CHIP_FAUCR_S2DEN1_DEFAULT  0x00000000u
  #define  CHIP_FAUCR_S2DEN1_OF(x)    _VALUEOF(x)

  #define _CHIP_FAUCR_S2NAN2_MASK     0x00020000u
  #define _CHIP_FAUCR_S2NAN2_SHIFT    0x00000011u
  #define  CHIP_FAUCR_S2NAN2_DEFAULT  0x00000000u
  #define  CHIP_FAUCR_S2NAN2_OF(x)    _VALUEOF(x)

  #define _CHIP_FAUCR_S2NAN1_MASK     0x00010000u
  #define _CHIP_FAUCR_S2NAN1_SHIFT    0x00000010u
  #define  CHIP_FAUCR_S2NAN1_DEFAULT  0x00000000u
  #define  CHIP_FAUCR_S2NAN1_OF(x)    _VALUEOF(x)

  #define _CHIP_FAUCR_S1DIV0_MASK     0x00000400u
  #define _CHIP_FAUCR_S1DIV0_SHIFT    0x0000000Au
  #define  CHIP_FAUCR_S1DIV0_DEFAULT  0x00000000u
  #define  CHIP_FAUCR_S1DIV0_OF(x)    _VALUEOF(x)

  #define _CHIP_FAUCR_S1UNORD_MASK    0x00000200u
  #define _CHIP_FAUCR_S1UNORD_SHIFT   0x00000009u
  #define  CHIP_FAUCR_S1UNORD_DEFAULT 0x00000000u
  #define  CHIP_FAUCR_S1UNORD_OF(x)   _VALUEOF(x)

  #define _CHIP_FAUCR_S1UND_MASK      0x00000100u
  #define _CHIP_FAUCR_S1UND_SHIFT     0x00000008u
  #define  CHIP_FAUCR_S1UND_DEFAULT   0x00000000u
  #define  CHIP_FAUCR_S1UND_OF(x)     _VALUEOF(x)

  #define _CHIP_FAUCR_S1INEX_MASK     0x00000080u
  #define _CHIP_FAUCR_S1INEX_SHIFT    0x00000007u
  #define  CHIP_FAUCR_S1INEX_DEFAULT  0x00000000u
  #define  CHIP_FAUCR_S1INEX_OF(x)    _VALUEOF(x)

  #define _CHIP_FAUCR_S1OVER_MASK     0x00000040u
  #define _CHIP_FAUCR_S1OVER_SHIFT    0x00000006u
  #define  CHIP_FAUCR_S1OVER_DEFAULT  0x00000000u
  #define  CHIP_FAUCR_S1OVER_OF(x)    _VALUEOF(x)

  #define _CHIP_FAUCR_S1INFO_MASK     0x00000020u
  #define _CHIP_FAUCR_S1INFO_SHIFT    0x00000005u
  #define  CHIP_FAUCR_S1INFO_DEFAULT  0x00000000u
  #define  CHIP_FAUCR_S1INFO_OF(x)    _VALUEOF(x)

  #define _CHIP_FAUCR_S1INVAL_MASK    0x00000010u
  #define _CHIP_FAUCR_S1INVAL_SHIFT   0x00000004u
  #define  CHIP_FAUCR_S1INVAL_DEFAULT 0x00000000u
  #define  CHIP_FAUCR_S1INVAL_OF(x)   _VALUEOF(x)

  #define _CHIP_FAUCR_S1DEN2_MASK     0x00000008u
  #define _CHIP_FAUCR_S1DEN2_SHIFT    0x00000003u
  #define  CHIP_FAUCR_S1DEN2_DEFAULT  0x00000000u
  #define  CHIP_FAUCR_S1DEN2_OF(x)    _VALUEOF(x)

  #define _CHIP_FAUCR_S1DEN1_MASK     0x00000004u
  #define _CHIP_FAUCR_S1DEN1_SHIFT    0x00000002u
  #define  CHIP_FAUCR_S1DEN1_DEFAULT  0x00000000u
  #define  CHIP_FAUCR_S1DEN1_OF(x)    _VALUEOF(x)

  #define _CHIP_FAUCR_S1NAN2_MASK     0x00000002u
  #define _CHIP_FAUCR_S1NAN2_SHIFT    0x00000001u
  #define  CHIP_FAUCR_S1NAN2_DEFAULT  0x00000000u
  #define  CHIP_FAUCR_S1NAN2_OF(x)    _VALUEOF(x)

  #define _CHIP_FAUCR_S1NAN1_MASK     0x00000001u
  #define _CHIP_FAUCR_S1NAN1_SHIFT    0x00000000u
  #define  CHIP_FAUCR_S1NAN1_DEFAULT  0x00000000u
  #define  CHIP_FAUCR_S1NAN1_OF(x)    _VALUEOF(x)

  #define  CHIP_FAUCR_OF(x)           _VALUEOF(x)

  #define CHIP_FAUCR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CHIP,FAUCR,S2DIV0)\
    |_PER_FDEFAULT(CHIP,FAUCR,S2UNORD)\
    |_PER_FDEFAULT(CHIP,FAUCR,S2UND)\
    |_PER_FDEFAULT(CHIP,FAUCR,S2INEX)\
    |_PER_FDEFAULT(CHIP,FAUCR,S2OVER)\
    |_PER_FDEFAULT(CHIP,FAUCR,S2INFO)\
    |_PER_FDEFAULT(CHIP,FAUCR,S2INVAL)\
    |_PER_FDEFAULT(CHIP,FAUCR,S2DEN2)\
    |_PER_FDEFAULT(CHIP,FAUCR,S2DEN1)\
    |_PER_FDEFAULT(CHIP,FAUCR,S2NAN2)\
    |_PER_FDEFAULT(CHIP,FAUCR,S2NAN1)\
    |_PER_FDEFAULT(CHIP,FAUCR,S1DIV0)\
    |_PER_FDEFAULT(CHIP,FAUCR,S1UNORD)\
    |_PER_FDEFAULT(CHIP,FAUCR,S1UND)\
    |_PER_FDEFAULT(CHIP,FAUCR,S1INEX)\
    |_PER_FDEFAULT(CHIP,FAUCR,S1OVER)\
    |_PER_FDEFAULT(CHIP,FAUCR,S1INFO)\
    |_PER_FDEFAULT(CHIP,FAUCR,S1INVAL)\
    |_PER_FDEFAULT(CHIP,FAUCR,S1DEN2)\
    |_PER_FDEFAULT(CHIP,FAUCR,S1DEN1)\
    |_PER_FDEFAULT(CHIP,FAUCR,S1NAN2)\
    |_PER_FDEFAULT(CHIP,FAUCR,S1NAN1)\
  )

  #define CHIP_FAUCR_MK(s2div0,s2unord,s2und,s2inex,s2over,s2info,s2inval,\
    s2den2,s2den1,s2nan2,s2nan1,s1div0,s1unord,s1und,s1inex,s1over,s1info,\
    s1inval,s1den2,s1den1,s1nan2,s1nan1) (Uint32)( \
     _PER_FMK(CHIP,FAUCR,S2DIV0,s2div)\
    |_PER_FMK(CHIP,FAUCR,S2UNORD,s2unord)\
    |_PER_FMK(CHIP,FAUCR,S2UND,s2und)\
    |_PER_FMK(CHIP,FAUCR,S2INEX,s2inex)\
    |_PER_FMK(CHIP,FAUCR,S2OVER,s2over)\
    |_PER_FMK(CHIP,FAUCR,S2INFO,s2info)\
    |_PER_FMK(CHIP,FAUCR,S2INVAL,s2inval)\
    |_PER_FMK(CHIP,FAUCR,S2DEN2,s2den2)\
    |_PER_FMK(CHIP,FAUCR,S2DEN1,s2den1)\
    |_PER_FMK(CHIP,FAUCR,S2NAN2,s2nan2)\
    |_PER_FMK(CHIP,FAUCR,S2NAN1,s2nan1)\
    |_PER_FMK(CHIP,FAUCR,S1DIV0,s1div0)\
    |_PER_FMK(CHIP,FAUCR,S1UNORD,s1unord)\
    |_PER_FMK(CHIP,FAUCR,S1UND,s1und)\
    |_PER_FMK(CHIP,FAUCR,S1INEX,s1inex)\
    |_PER_FMK(CHIP,FAUCR,S1OVER,s1over)\
    |_PER_FMK(CHIP,FAUCR,S1INFO,s1info)\
    |_PER_FMK(CHIP,FAUCR,S1INVAL,s1inval)\
    |_PER_FMK(CHIP,FAUCR,S1DEN2,s1den2)\
    |_PER_FMK(CHIP,FAUCR,S1DEN1,s1den1)\
    |_PER_FMK(CHIP,FAUCR,S1NAN2,s1nan2)\
    |_PER_FMK(CHIP,FAUCR,S1NAN1,s1nan1)\
  )

  #define _CHIP_FAUCR_FGET(FIELD)\
    _PER_CFGET(CHIP,FAUCR,##FIELD)

  #define _CHIP_FAUCR_FSET(FIELD,field)\
    _PER_CFSET(CHIP,FAUCR,##FIELD,field)

  #define _CHIP_FAUCR_FSETS(FIELD,SYM)\
    _PER_CFSETS(CHIP,FAUCR,##FIELD,##SYM)
#endif


/******************************************************************************\
* _____________________
* |                   |
* |  F M C R          |
* |___________________|
*
* FMCR - floating-point multiplier config register (1)
*
* FIELDS (msb -> lsb)
* (rw) M2RMODE
* (rw) M2UNDER
* (rw) M2INEX
* (rw) M2OVER
* (rw) M2INFO
* (rw) M2INVAL
* (rw) M2DEN2
* (rw) M2DEN1
* (rw) M2NAN2
* (rw) M2NAN1
* (rw) M1RMODE
* (rw) M1UNDER
* (rw) M1INEX
* (rw) M1OVER
* (rw) M1INFO
* (rw) M1INVAL
* (rw) M1DEN2
* (rw) M1DEN1
* (rw) M1NAN2
* (rw) M1NAN1
*
* (1) only supported on devices with floating point unit
*
\******************************************************************************/
#if (FPU_SUPPORT)
  extern far cregister volatile unsigned int FMCR;

  #define _CHIP_FMCR_M2RMODE_MASK     0x06000000u
  #define _CHIP_FMCR_M2RMODE_SHIFT    0x00000019u
  #define  CHIP_FMCR_M2RMODE_DEFAULT  0x00000000u
  #define  CHIP_FMCR_M2RMODE_OF(x)    _VALUEOF(x)

  #define _CHIP_FMCR_M2UNDER_MASK     0x01000000u
  #define _CHIP_FMCR_M2UNDER_SHIFT    0x00000018u
  #define  CHIP_FMCR_M2UNDER_DEFAULT  0x00000000u
  #define  CHIP_FMCR_M2UNDER_OF(x)    _VALUEOF(x)

  #define _CHIP_FMCR_M2INEX_MASK      0x00800000u
  #define _CHIP_FMCR_M2INEX_SHIFT     0x00000017u
  #define  CHIP_FMCR_M2INEX_DEFAULT   0x00000000u
  #define  CHIP_FMCR_M2INEX_OF(x)     _VALUEOF(x)

  #define _CHIP_FMCR_M2OVER_MASK      0x00400000u
  #define _CHIP_FMCR_M2OVER_SHIFT     0x00000016u
  #define  CHIP_FMCR_M2OVER_DEFAULT   0x00000000u
  #define  CHIP_FMCR_M2OVER_OF(x)     _VALUEOF(x)

  #define _CHIP_FMCR_M2INFO_MASK      0x00200000u
  #define _CHIP_FMCR_M2INFO_SHIFT     0x00000015u
  #define  CHIP_FMCR_M2INFO_DEFAULT   0x00000000u
  #define  CHIP_FMCR_M2INFO_OF(x)     _VALUEOF(x)

  #define _CHIP_FMCR_M2INVAL_MASK     0x00100000u
  #define _CHIP_FMCR_M2INVAL_SHIFT    0x00000014u
  #define  CHIP_FMCR_M2INVAL_DEFAULT  0x00000000u
  #define  CHIP_FMCR_M2INVAL_OF(x)    _VALUEOF(x)

  #define _CHIP_FMCR_M2DEN2_MASK      0x00080000u
  #define _CHIP_FMCR_M2DEN2_SHIFT     0x00000013u
  #define  CHIP_FMCR_M2DEN2_DEFAULT   0x00000000u
  #define  CHIP_FMCR_M2DEN2_OF(x)     _VALUEOF(x)

  #define _CHIP_FMCR_M2DEN1_MASK      0x00040000u
  #define _CHIP_FMCR_M2DEN1_SHIFT     0x00000012u
  #define  CHIP_FMCR_M2DEN1_DEFAULT   0x00000000u
  #define  CHIP_FMCR_M2DEN1_OF(x)     _VALUEOF(x)

  #define _CHIP_FMCR_M2NAN2_MASK      0x00020000u
  #define _CHIP_FMCR_M2NAN2_SHIFT     0x00000011u
  #define  CHIP_FMCR_M2NAN2_DEFAULT   0x00000000u
  #define  CHIP_FMCR_M2NAN2_OF(x)     _VALUEOF(x)

  #define _CHIP_FMCR_M2NAN1_MASK      0x00010000u
  #define _CHIP_FMCR_M2NAN1_SHIFT     0x00000010u
  #define  CHIP_FMCR_M2NAN1_DEFAULT   0x00000000u
  #define  CHIP_FMCR_M2NAN1_OF(x)     _VALUEOF(x)

  #define _CHIP_FMCR_M1RMODE_MASK     0x00000600u
  #define _CHIP_FMCR_M1RMODE_SHIFT    0x00000009u
  #define  CHIP_FMCR_M1RMODE_DEFAULT  0x00000000u
  #define  CHIP_FMCR_M1RMODE_OF(x)    _VALUEOF(x)

  #define _CHIP_FMCR_M1UNDER_MASK     0x00000100u
  #define _CHIP_FMCR_M1UNDER_SHIFT    0x00000008u
  #define  CHIP_FMCR_M1UNDER_DEFAULT  0x00000000u
  #define  CHIP_FMCR_M1UNDER_OF(x)    _VALUEOF(x)

  #define _CHIP_FMCR_M1INEX_MASK      0x00000080u
  #define _CHIP_FMCR_M1INEX_SHIFT     0x00000007u
  #define  CHIP_FMCR_M1INEX_DEFAULT   0x00000000u
  #define  CHIP_FMCR_M1INEX_OF(x)     _VALUEOF(x)

  #define _CHIP_FMCR_M1OVER_MASK      0x00000040u
  #define _CHIP_FMCR_M1OVER_SHIFT     0x00000006u
  #define  CHIP_FMCR_M1OVER_DEFAULT   0x00000000u
  #define  CHIP_FMCR_M1OVER_OF(x)     _VALUEOF(x)

  #define _CHIP_FMCR_M1INFO_MASK      0x00000020u
  #define _CHIP_FMCR_M1INFO_SHIFT     0x00000005u
  #define  CHIP_FMCR_M1INFO_DEFAULT   0x00000000u
  #define  CHIP_FMCR_M1INFO_OF(x)     _VALUEOF(x)

  #define _CHIP_FMCR_M1INVAL_MASK     0x00000010u
  #define _CHIP_FMCR_M1INVAL_SHIFT    0x00000004u
  #define  CHIP_FMCR_M1INVAL_DEFAULT  0x00000000u
  #define  CHIP_FMCR_M1INVAL_OF(x)    _VALUEOF(x)

  #define _CHIP_FMCR_M1DEN2_MASK      0x00000008u
  #define _CHIP_FMCR_M1DEN2_SHIFT     0x00000003u
  #define  CHIP_FMCR_M1DEN2_DEFAULT   0x00000000u
  #define  CHIP_FMCR_M1DEN2_OF(x)     _VALUEOF(x)

  #define _CHIP_FMCR_M1DEN1_MASK      0x00000004u
  #define _CHIP_FMCR_M1DEN1_SHIFT     0x00000002u
  #define  CHIP_FMCR_M1DEN1_DEFAULT   0x00000000u
  #define  CHIP_FMCR_M1DEN1_OF(x)     _VALUEOF(x)

  #define _CHIP_FMCR_M1NAN2_MASK      0x00000002u
  #define _CHIP_FMCR_M1NAN2_SHIFT     0x00000001u
  #define  CHIP_FMCR_M1NAN2_DEFAULT   0x00000000u
  #define  CHIP_FMCR_M1NAN2_OF(x)     _VALUEOF(x)

  #define _CHIP_FMCR_M1NAN1_MASK      0x00000001u
  #define _CHIP_FMCR_M1NAN1_SHIFT     0x00000000u
  #define  CHIP_FMCR_M1NAN1_DEFAULT   0x00000000u
  #define  CHIP_FMCR_M1NAN1_OF(x)     _VALUEOF(x)

  #define  CHIP_FMCR_OF(x)            _VALUEOF(x)

  #define CHIP_FMCR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CHIP,FMCR,M2RMODE)\
    |_PER_FDEFAULT(CHIP,FMCR,M2UNDER)\
    |_PER_FDEFAULT(CHIP,FMCR,M2INEX)\
    |_PER_FDEFAULT(CHIP,FMCR,M2OVER)\
    |_PER_FDEFAULT(CHIP,FMCR,M2INFO)\
    |_PER_FDEFAULT(CHIP,FMCR,M2INVAL)\
    |_PER_FDEFAULT(CHIP,FMCR,M2DEN2)\
    |_PER_FDEFAULT(CHIP,FMCR,M2DEN1)\
    |_PER_FDEFAULT(CHIP,FMCR,M2NAN2)\
    |_PER_FDEFAULT(CHIP,FMCR,M2NAN1)\
    |_PER_FDEFAULT(CHIP,FMCR,M1RMODE)\
    |_PER_FDEFAULT(CHIP,FMCR,M1UNDER)\
    |_PER_FDEFAULT(CHIP,FMCR,M1INEX)\
    |_PER_FDEFAULT(CHIP,FMCR,M1OVER)\
    |_PER_FDEFAULT(CHIP,FMCR,M1INFO)\
    |_PER_FDEFAULT(CHIP,FMCR,M1INVAL)\
    |_PER_FDEFAULT(CHIP,FMCR,M1DEN2)\
    |_PER_FDEFAULT(CHIP,FMCR,M1DEN1)\
    |_PER_FDEFAULT(CHIP,FMCR,M1NAN2)\
    |_PER_FDEFAULT(CHIP,FMCR,M1NAN1)\
  )

  #define CHIP_FMCR_MK(m2rmode,m2under,m2index,m2over,m2info,m2inval,\
    m2den2,m2den1,m2nan2,m2nan1,m1rmode,m1under,m1inex,m1over,m1info,\
    m1inval,m1den2,m1den1,m1nan2,m1nan1) (Uint32)( \
     _PER_FMK(CHIP,FMCR,M2RMODE,m2rmode)\
    |_PER_FMK(CHIP,FMCR,M2UNDER,m2under)\
    |_PER_FMK(CHIP,FMCR,M2INEX,m2inex)\
    |_PER_FMK(CHIP,FMCR,M2OVER,m2over)\
    |_PER_FMK(CHIP,FMCR,M2INFO,m2info)\
    |_PER_FMK(CHIP,FMCR,M2INVAL,m2inval)\
    |_PER_FMK(CHIP,FMCR,M2DEN2,m2den2)\
    |_PER_FMK(CHIP,FMCR,M2DEN1,m2den1)\
    |_PER_FMK(CHIP,FMCR,M2NAN2,m2nan2)\
    |_PER_FMK(CHIP,FMCR,M2NAN1,m2nan1)\
    |_PER_FMK(CHIP,FMCR,M1RMODE,m1rmode)\
    |_PER_FMK(CHIP,FMCR,M1UNDER,m1under)\
    |_PER_FMK(CHIP,FMCR,M1INEX,m1inex)\
    |_PER_FMK(CHIP,FMCR,M1OVER,m1over)\
    |_PER_FMK(CHIP,FMCR,M1INFO,m1info)\
    |_PER_FMK(CHIP,FMCR,M1INVAL,m1inval)\
    |_PER_FMK(CHIP,FMCR,M1DEN2,m1den2)\
    |_PER_FMK(CHIP,FMCR,M1DEN1,m1den1)\
    |_PER_FMK(CHIP,FMCR,M1NAN2,m1nan2)\
    |_PER_FMK(CHIP,FMCR,M1NAN1,m1nan1)\
  )

  #define _CHIP_FMCR_FGET(FIELD)\
    _PER_CFGET(CHIP,FMCR,##FIELD)

  #define _CHIP_FMCR_FSET(FIELD,field)\
    _PER_CFSET(CHIP,FMCR,##FIELD,field)

  #define _CHIP_FMCR_FSETS(FIELD,SYM)\
    _PER_CFSETS(CHIP,FMCR,##FIELD,##SYM)
#endif

/******************************************************************************\
* _____________________
* |                   |
* |  G F P G F R      |
* |___________________|
*
* GFPGFR - Galois field polynomial generator function register (1)
*
* FIELDS (msb -> lsb)
* (rw) SIZE
* (rw) POLY
* (1) only supported on C64x family of devices
*
\******************************************************************************/
#if (C64_SUPPORT)
  extern cregister volatile unsigned int GFPGFR;

  #define _CHIP_GFPGFR_POLY_MASK          0x000000FFu
  #define _CHIP_GFPGFR_POLY_SHIFT         0x00000000u
  #define  CHIP_GFPGFR_POLY_DEFAULT       0x0000001Du
  #define  CHIP_GFPGFR_POLY_OF(x)         _VALUEOF(x)

  #define _CHIP_GFPGFR_SIZE_MASK          0x07000000u
  #define _CHIP_GFPGFR_SIZE_SHIFT         0x00000018u
  #define  CHIP_GFPGFR_SIZE_DEFAULT       0x00000007u
  #define  CHIP_GFPGFR_SIZE_OF(x)         _VALUEOF(x)

  #define  CHIP_GFPGFR_OF(x)              _VALUEOF(x)

  #define CHIP_GFPGFR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CHIP,GFPGFR,SIZE) \
    |_PER_FDEFAULT(CHIP,GFPGFR,POLY) \
  )

  #define CHIP_GFPGFR_RMK(size,poly) (Uint32)( \
     _PER_FMK(CHIP,GFPGFR,SIZE,size) \
    |_PER_FMK(CHIP,GFPGFR,POLY,poly) \
  )

  #define _CHIP_GFPGFR_FGET(FIELD)\
    _PER_CFGET(CHIP,GFPGFR,##FIELD)

  #define _CHIP_GFPGFR_FSET(FIELD,field)\
    _PER_CFSET(CHIP,GFPGFR,##FIELD,field)

  #define _CHIP_GFPGFR_FSETS(FIELD,SYM)\
    _PER_CFSETS(CHIP,GFPGFR,##FIELD,##SYM)

#endif

/******************************************************************************\
* _____________________
* |                   |
* |  D E V C F G      |
* |___________________|
*
* DEVCFG - Device Configuration register (1)
*
* FIELDS (msb -> lsb)  CHIP_6713/CHIP_DA610
* (rw) EKSRC
* (rw) TOUT1SEL
* (rw) TOUT0SEL
* (rw) MCBSP0DIS
* (rw) MCBSP1DIS
* (rw) GPIO1EN (only for CHIP_DA610)
*
* FIELDS (msb -> lsb)  CHIP_DM642
* (rw) VP2EN
* (rw) VP1EN
* (rw) VP0EN
* (rw) I2C0EN
* (rw) MCBSP1EN
* (rw) MCBSP0EN
* (rw) MCASP0EN
*
* FIELDS (msb -> lsb)  CHIP_6412
* (rw) I2C0EN
* (rw) MCBSP1EN
* (rw) MCBSP0EN
*
* FIELDS (msb -> lsb)  CHIP_6711C/CHIP_6712C
* (rw) EKSRC
*
* FIELDS (msb -> lsb)  CHIP_6410/CHIP_6413/CHIP_6418
* (rw) ATLEN  
* (rw) ADIV
* (rw) ATLMEN
* (rw) AFCMUX  
* (rw) MCASP1EN
* (rw) I2C1EN
* (rw) I2C0EN
* (rw) MCBSP1EN
* (rw) MCBSP0EN
* (rw) MCASP0EN
*
\******************************************************************************/

#if (CHIP_DA610)

  #define   _CHIP_DEVCFG_ADDR              0x019C0200u
  #define   _CHIP_DEVCFG_OFFSET             0

  #define _CHIP_DEVCFG_GPIO1EN_MASK        0x00010000u
  #define _CHIP_DEVCFG_GPIO1EN_SHIFT       0x0000000Fu
  #define  CHIP_DEVCFG_GPIO1EN_DEFAULT     0x00000000u
  #define  CHIP_DEVCFG_GPIO1EN_OF(x)       _VALUEOF(x)
  #define  CHIP_DEVCFG_GPIO1EN_0           0x00000000u
  #define  CHIP_DEVCFG_GPIO1EN_1           0x00000001u

  #define _CHIP_DEVCFG_EKSRC_MASK          0x00000010u
  #define _CHIP_DEVCFG_EKSRC_SHIFT         0x00000004u
  #define  CHIP_DEVCFG_EKSRC_DEFAULT       0x00000000u
  #define  CHIP_DEVCFG_EKSRC_OF(x)         _VALUEOF(x)
  #define  CHIP_DEVCFG_EKSRC_SYSCLK3       0x00000000u
  #define  CHIP_DEVCFG_EKSRC_ECLKIN        0x00000001u

  #define _CHIP_DEVCFG_TOUT1SEL_MASK       0x00000008u
  #define _CHIP_DEVCFG_TOUT1SEL_SHIFT      0x00000003u
  #define  CHIP_DEVCFG_TOUT1SEL_DEFAULT    0x00000000u
  #define  CHIP_DEVCFG_TOUT1SEL_OF(x)       _VALUEOF(x)
  #define  CHIP_DEVCFG_TOUT1SEL_TOUT1PIN   0x00000000u
  #define  CHIP_DEVCFG_TOUT1SEL_MCASPPIN   0x00000001u

  #define _CHIP_DEVCFG_TOUT0SEL_MASK       0x00000004u
  #define _CHIP_DEVCFG_TOUT0SEL_SHIFT      0x00000002u
  #define  CHIP_DEVCFG_TOUT0SEL_DEFAULT    0x00000000u
  #define  CHIP_DEVCFG_TOUT0SEL_OF(x)       _VALUEOF(x)
  #define  CHIP_DEVCFG_TOUT0SEL_TOUT0PIN   0x00000000u
  #define  CHIP_DEVCFG_TOUT0SEL_MCASPPIN   0x00000001u

  #define _CHIP_DEVCFG_MCBSP0DIS_MASK       0x00000002u
  #define _CHIP_DEVCFG_MCBSP0DIS_SHIFT      0x00000001u
  #define  CHIP_DEVCFG_MCBSP0DIS_DEFAULT    0x00000000u
  #define  CHIP_DEVCFG_MCBSP0DIS_OF(x)       _VALUEOF(x)
  #define  CHIP_DEVCFG_MCBSP0DIS_0          0x00000000u
  #define  CHIP_DEVCFG_MCBSP0DIS_1          0x00000001u

  #define _CHIP_DEVCFG_MCBSP1DIS_MASK         0x00000001u
  #define _CHIP_DEVCFG_MCBSP1DIS_SHIFT        0x00000000u
  #define  CHIP_DEVCFG_MCBSP1DIS_DEFAULT      0x00000000u
  #define  CHIP_DEVCFG_MCBSP1DIS_OF(x)        _VALUEOF(x)
  #define  CHIP_DEVCFG_MCBSP1DIS_0            0x00000000u
  #define  CHIP_DEVCFG_MCBSP1DIS_1            0x00000001u


  #define  CHIP_DEVCFG_OF(x)              _VALUEOF(x)

  #define CHIP_DEVCFG_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CHIP,DEVCFG,EKSRC) \
    |_PER_FDEFAULT(CHIP,DEVCFG,TOUT1SEL) \
    |_PER_FDEFAULT(CHIP,DEVCFG,TOUT0SEL) \
    |_PER_FDEFAULT(CHIP,DEVCFG,MCBSP0DIS) \
    |_PER_FDEFAULT(CHIP,DEVCFG,MCBSP1DIS) \
    |_PER_FDEFAULT(CHIP,DEVCFG,GPIO1EN) \
 )

  #define CHIP_DEVCFG_RMK(eksrc,tout1sel,tout0sel,mcbsp0dis,mcbsp1dis,\
                          gpio1en ) (Uint32)( \
      _PER_FMK(CHIP,DEVCFG,EKSRC,eksrc) \
    |_PER_FMK(CHIP,DEVCFG,TOUT1SEL,tout1sel) \
    |_PER_FMK(CHIP,DEVCFG,TOUT0SEL,tout0sel) \
    |_PER_FMK(CHIP,DEVCFG,MCBSP0DIS,mcbsp0dis) \
    |_PER_FMK(CHIP,DEVCFG,MCBSP1DIS,mcbsp1dis) \
    |_PER_FMK(CHIP,DEVCFG,GPIO1EN,gpio1en) \
)
#elif (CHIP_6713)
  #define   _CHIP_DEVCFG_ADDR              0x019C0200u
  #define   _CHIP_DEVCFG_OFFSET             0

  #define _CHIP_DEVCFG_EKSRC_MASK          0x00000010u
  #define _CHIP_DEVCFG_EKSRC_SHIFT         0x00000004u
  #define  CHIP_DEVCFG_EKSRC_DEFAULT       0x00000000u
  #define  CHIP_DEVCFG_EKSRC_OF(x)         _VALUEOF(x)
  #define  CHIP_DEVCFG_EKSRC_SYSCLK3       0x00000000u
  #define  CHIP_DEVCFG_EKSRC_ECLKIN        0x00000001u

  #define _CHIP_DEVCFG_TOUT1SEL_MASK       0x00000008u
  #define _CHIP_DEVCFG_TOUT1SEL_SHIFT      0x00000003u
  #define  CHIP_DEVCFG_TOUT1SEL_DEFAULT    0x00000000u
  #define  CHIP_DEVCFG_TOUT1SEL_OF(x)       _VALUEOF(x)
  #define  CHIP_DEVCFG_TOUT1SEL_TOUT1PIN   0x00000000u
  #define  CHIP_DEVCFG_TOUT1SEL_MCASPPIN   0x00000001u

  #define _CHIP_DEVCFG_TOUT0SEL_MASK       0x00000004u
  #define _CHIP_DEVCFG_TOUT0SEL_SHIFT      0x00000002u
  #define  CHIP_DEVCFG_TOUT0SEL_DEFAULT    0x00000000u
  #define  CHIP_DEVCFG_TOUT0SEL_OF(x)       _VALUEOF(x)
  #define  CHIP_DEVCFG_TOUT0SEL_TOUT0PIN   0x00000000u
  #define  CHIP_DEVCFG_TOUT0SEL_MCASPPIN   0x00000001u

  #define _CHIP_DEVCFG_MCBSP0DIS_MASK      0x00000002u
  #define _CHIP_DEVCFG_MCBSP0DIS_SHIFT     0x00000001u
  #define  CHIP_DEVCFG_MCBSP0DIS_DEFAULT   0x00000000u
  #define  CHIP_DEVCFG_MCBSP0DIS_OF(x)     _VALUEOF(x)
  #define  CHIP_DEVCFG_MCBSP0DIS_0         0x00000000u
  #define  CHIP_DEVCFG_MCBSP0DIS_1         0x00000001u

  #define _CHIP_DEVCFG_MCBSP1DIS_MASK      0x00000001u
  #define _CHIP_DEVCFG_MCBSP1DIS_SHIFT     0x00000000u
  #define  CHIP_DEVCFG_MCBSP1DIS_DEFAULT   0x00000000u
  #define  CHIP_DEVCFG_MCBSP1DIS_OF(x)     _VALUEOF(x)
  #define  CHIP_DEVCFG_MCBSP1DIS_0         0x00000000u
  #define  CHIP_DEVCFG_MCBSP1DIS_1         0x00000001u


  #define  CHIP_DEVCFG_OF(x)              _VALUEOF(x)

  #define CHIP_DEVCFG_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CHIP,DEVCFG,EKSRC) \
    |_PER_FDEFAULT(CHIP,DEVCFG,TOUT1SEL) \
    |_PER_FDEFAULT(CHIP,DEVCFG,TOUT0SEL) \
    |_PER_FDEFAULT(CHIP,DEVCFG,MCBSP0DIS) \
    |_PER_FDEFAULT(CHIP,DEVCFG,MCBSP1DIS) \
 )

  #define CHIP_DEVCFG_RMK(eksrc,tout1sel,tout0sel,mcbsp0dis,mcbsp1dis\
                          ) (Uint32)( \
      _PER_FMK(CHIP,DEVCFG,EKSRC,eksrc) \
    |_PER_FMK(CHIP,DEVCFG,TOUT1SEL,tout1sel) \
    |_PER_FMK(CHIP,DEVCFG,TOUT0SEL,tout0sel) \
    |_PER_FMK(CHIP,DEVCFG,MCBSP0DIS,mcbsp0dis) \
    |_PER_FMK(CHIP,DEVCFG,MCBSP1DIS,mcbsp1dis) \
)

#endif

#if (CHIP_DM642 || CHIP_DM641 || CHIP_DM640 || CHIP_6412)

  #define   _CHIP_DEVCFG_ADDR                0x01B3F000u
  #define   _CHIP_DEVCFG_OFFSET              0

#if (CHIP_DM642)
  #define _CHIP_DEVCFG_VP2EN_MASK            0x00000040u
  #define _CHIP_DEVCFG_VP2EN_SHIFT           0x00000006u
  #define  CHIP_DEVCFG_VP2EN_DEFAULT         0x00000000u
  #define  CHIP_DEVCFG_VP2EN_OF(x)           _VALUEOF(x)
  #define  CHIP_DEVCFG_VP2EN_DISABLE         0x00000000u
  #define  CHIP_DEVCFG_VP2EN_ENABLE          0x00000001u
#endif

#if (CHIP_DM642 | CHIP_DM641)                          
  #define _CHIP_DEVCFG_VP1EN_MASK            0x00000020u
  #define _CHIP_DEVCFG_VP1EN_SHIFT           0x00000005u
  #define  CHIP_DEVCFG_VP1EN_DEFAULT         0x00000000u
  #define  CHIP_DEVCFG_VP1EN_OF(x)           _VALUEOF(x)
  #define  CHIP_DEVCFG_VP1EN_DISABLE         0x00000000u
  #define  CHIP_DEVCFG_VP1EN_ENABLE          0x00000001u
#endif

#if (CHIP_DM642 | CHIP_DM641 | CHIP_DM640)                          
  #define _CHIP_DEVCFG_VP0EN_MASK            0x00000010u
  #define _CHIP_DEVCFG_VP0EN_SHIFT           0x00000004u
  #define  CHIP_DEVCFG_VP0EN_DEFAULT         0x00000000u
  #define  CHIP_DEVCFG_VP0EN_OF(x)           _VALUEOF(x)
  #define  CHIP_DEVCFG_VP0EN_DISABLE         0x00000000u
  #define  CHIP_DEVCFG_VP0EN_ENABLE          0x00000001u
#endif

  #define _CHIP_DEVCFG_I2C0EN_MASK           0x00000008u
  #define _CHIP_DEVCFG_I2C0EN_SHIFT          0x00000003u
  #define  CHIP_DEVCFG_I2C0EN_DEFAULT        0x00000000u
  #define  CHIP_DEVCFG_I2C0EN_OF(x)          _VALUEOF(x)
  #define  CHIP_DEVCFG_I2C0EN_DISABLE        0x00000000u
  #define  CHIP_DEVCFG_I2C0EN_ENABLE         0x00000001u

  #define _CHIP_DEVCFG_MCBSP1EN_MASK         0x00000004u
  #define _CHIP_DEVCFG_MCBSP1EN_SHIFT        0x00000002u
  #define  CHIP_DEVCFG_MCBSP1EN_DEFAULT      0x00000001u
  #define  CHIP_DEVCFG_MCBSP1EN_OF(x)        _VALUEOF(x)
  #define  CHIP_DEVCFG_MCBSP1EN_DISABLE      0x00000000u
  #define  CHIP_DEVCFG_MCBSP1EN_ENABLE       0x00000001u

  #define _CHIP_DEVCFG_MCBSP0EN_MASK         0x00000002u
  #define _CHIP_DEVCFG_MCBSP0EN_SHIFT        0x00000001u
  #define  CHIP_DEVCFG_MCBSP0EN_DEFAULT      0x00000001u
  #define  CHIP_DEVCFG_MCBSP0EN_OF(x)        _VALUEOF(x)
  #define  CHIP_DEVCFG_MCBSP0EN_DISABLE      0x00000000u
  #define  CHIP_DEVCFG_MCBSP0EN_ENABLE       0x00000001u

#if (CHIP_DM642 | CHIP_DM641 | CHIP_DM640)
  #define _CHIP_DEVCFG_MCASP0EN_MASK         0x00000001u
  #define _CHIP_DEVCFG_MCASP0EN_SHIFT        0x00000000u
  #define  CHIP_DEVCFG_MCASP0EN_DEFAULT      0x00000000u
  #define  CHIP_DEVCFG_MCASP0EN_OF(x)         _VALUEOF(x)
  #define  CHIP_DEVCFG_MCASP0EN_DISABLE      0x00000000u
  #define  CHIP_DEVCFG_MCASP0EN_ENABLE       0x00000001u
#endif


  #define  CHIP_DEVCFG_OF(x)              _VALUEOF(x)

#if (CHIP_DM642)
  #define CHIP_DEVCFG_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CHIP,DEVCFG,VP2EN) \
    |_PER_FDEFAULT(CHIP,DEVCFG,VP1EN) \
    |_PER_FDEFAULT(CHIP,DEVCFG,VP0EN) \
    |_PER_FDEFAULT(CHIP,DEVCFG,I2C0EN) \
    |_PER_FDEFAULT(CHIP,DEVCFG,MCBSP1EN) \
    |_PER_FDEFAULT(CHIP,DEVCFG,MCBSP0EN) \
    |_PER_FDEFAULT(CHIP,DEVCFG,MCASP0EN) \
   )


 #define CHIP_DEVCFG_RMK(vp2en,vp1en,vp0en,i2c0en,mcbsp1en,mcbsp0en,mcasp0en) (Uint32)( \
     _PER_FMK(CHIP,DEVCFG,VP2EN,vp2en) \
    |_PER_FMK(CHIP,DEVCFG,VP1EN,vp1en) \
    |_PER_FMK(CHIP,DEVCFG,VP0EN,vp0en) \
    |_PER_FMK(CHIP,DEVCFG,I2C0EN,i2c0en) \
    |_PER_FMK(CHIP,DEVCFG,MCBSP1EN,mcbsp1en) \
    |_PER_FMK(CHIP,DEVCFG,MCBSP0EN,mcbsp0en) \
    |_PER_FMK(CHIP,DEVCFG,MCASP0EN,mcasp0en) \
  )
#endif

#if (CHIP_DM641)
  #define CHIP_DEVCFG_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CHIP,DEVCFG,VP1EN) \
    |_PER_FDEFAULT(CHIP,DEVCFG,VP0EN) \
    |_PER_FDEFAULT(CHIP,DEVCFG,I2C0EN) \
    |_PER_FDEFAULT(CHIP,DEVCFG,MCBSP1EN) \
    |_PER_FDEFAULT(CHIP,DEVCFG,MCBSP0EN) \
    |_PER_FDEFAULT(CHIP,DEVCFG,MCASP0EN) \
   )


 #define CHIP_DEVCFG_RMK(vp1en,vp0en,i2c0en,mcbsp1en,mcbsp0en,mcasp0en) (Uint32)( \
     _PER_FMK(CHIP,DEVCFG,VP1EN,vp1en) \
    |_PER_FMK(CHIP,DEVCFG,VP0EN,vp0en) \
    |_PER_FMK(CHIP,DEVCFG,I2C0EN,i2c0en) \
    |_PER_FMK(CHIP,DEVCFG,MCBSP1EN,mcbsp1en) \
    |_PER_FMK(CHIP,DEVCFG,MCBSP0EN,mcbsp0en) \
    |_PER_FMK(CHIP,DEVCFG,MCASP0EN,mcasp0en) \
  )
#endif

#if (CHIP_DM640)
  #define CHIP_DEVCFG_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CHIP,DEVCFG,VP0EN) \
    |_PER_FDEFAULT(CHIP,DEVCFG,I2C0EN) \
    |_PER_FDEFAULT(CHIP,DEVCFG,MCBSP1EN) \
    |_PER_FDEFAULT(CHIP,DEVCFG,MCBSP0EN) \
    |_PER_FDEFAULT(CHIP,DEVCFG,MCASP0EN) \
   )


 #define CHIP_DEVCFG_RMK(vp0en,i2c0en,mcbsp1en,mcbsp0en,mcasp0en) (Uint32)( \
     _PER_FMK(CHIP,DEVCFG,VP0EN,vp0en) \
    |_PER_FMK(CHIP,DEVCFG,I2C0EN,i2c0en) \
    |_PER_FMK(CHIP,DEVCFG,MCBSP1EN,mcbsp1en) \
    |_PER_FMK(CHIP,DEVCFG,MCBSP0EN,mcbsp0en) \
    |_PER_FMK(CHIP,DEVCFG,MCASP0EN,mcasp0en) \
  )
#endif

#if (CHIP_6412)
  #define CHIP_DEVCFG_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CHIP,DEVCFG,I2C0EN) \
    |_PER_FDEFAULT(CHIP,DEVCFG,MCBSP1EN) \
    |_PER_FDEFAULT(CHIP,DEVCFG,MCBSP0EN) \
   )


 #define CHIP_DEVCFG_RMK(i2c0en,mcbsp1en,mcbsp0en) (Uint32)( \
    |_PER_FMK(CHIP,DEVCFG,I2C0EN,i2c0en) \
    |_PER_FMK(CHIP,DEVCFG,MCBSP1EN,mcbsp1en) \
    |_PER_FMK(CHIP,DEVCFG,MCBSP0EN,mcbsp0en) \
  )
#endif

#endif /* CHIP_DM642 || CHIP_6412  */

#if (CHIP_6410 || CHIP_6413 || CHIP_6418)

  #define   _CHIP_DEVCFG_ADDR                0x01B3F000u
  #define   _CHIP_DEVCFG_OFFSET              0

  #define _CHIP_DEVCFG_ATLEN_MASK            0x80000000u
  #define _CHIP_DEVCFG_ATLEN_SHIFT           0x0000001Eu
  #define  CHIP_DEVCFG_ATLEN_DEFAULT         0x00000000u
  #define  CHIP_DEVCFG_ATLEN_OF(x)            _VALUEOF(x)
  #define  CHIP_DEVCFG_ATLEN_DISABLE         0x00000000u
  #define  CHIP_DEVCFG_ATLEN_ENABLE          0x00000001u

  #define _CHIP_DEVCFG_ADIV_MASK             0x60000000u
  #define _CHIP_DEVCFG_ADIV_SHIFT            0x0000001Du
  #define  CHIP_DEVCFG_ADIV_DEFAULT          0x00000000u
  #define  CHIP_DEVCFG_ADIV_OF(x)             _VALUEOF(x)
  #define  CHIP_DEVCFG_ADIV_BY4              0x00000000u
  #define  CHIP_DEVCFG_ADIV_BY3HALF          0x00000001u
  #define  CHIP_DEVCFG_ADIV_BY9              0x00000002u
  #define  CHIP_DEVCFG_ADIV_EATCLK           0x00000003u

  #define _CHIP_DEVCFG_ATLMEN_MASK           0x10000000u
  #define _CHIP_DEVCFG_ATLMEN_SHIFT          0x0000001Cu
  #define  CHIP_DEVCFG_ATLMEN_DEFAULT        0x00000000u
  #define  CHIP_DEVCFG_ATLMEN_OF(x)           _VALUEOF(x)
  #define  CHIP_DEVCFG_ATLMEN_DISABLE        0x00000000u
  #define  CHIP_DEVCFG_ATLMEN_ENABLE         0x00000001u

  #define _CHIP_DEVCFG_AFCMUX_MASK           0x00000600u
  #define _CHIP_DEVCFG_AFCMUX_SHIFT          0x00000009u
  #define  CHIP_DEVCFG_AFCMUX_DEFAULT        0x00000000u
  #define  CHIP_DEVCFG_AFCMUX_OF(x)           _VALUEOF(x)
  #define  CHIP_DEVCFG_AFCMUX_PIN0           0x00000000u
  #define  CHIP_DEVCFG_AFCMUX_PIN1           0x00000001u
  #define  CHIP_DEVCFG_AFCMUX_PIN2           0x00000002u
  #define  CHIP_DEVCFG_AFCMUX_PIN3           0x00000003u

  #define _CHIP_DEVCFG_MCASP1EN_MASK         0x00000100u
  #define _CHIP_DEVCFG_MCASP1EN_SHIFT        0x00000008u
  #define  CHIP_DEVCFG_MCASP1EN_DEFAULT      0x00000000u
  #define  CHIP_DEVCFG_MCASP1EN_OF(x)         _VALUEOF(x)
  #define  CHIP_DEVCFG_MCASP1EN_DISABLE      0x00000000u
  #define  CHIP_DEVCFG_MCASP1EN_ENABLE       0x00000001u

  #define _CHIP_DEVCFG_I2C1EN_MASK           0x00000080u
  #define _CHIP_DEVCFG_I2C1EN_SHIFT          0x00000007u
  #define  CHIP_DEVCFG_I2C1EN_DEFAULT        0x00000000u
  #define  CHIP_DEVCFG_I2C1EN_OF(x)          _VALUEOF(x)
  #define  CHIP_DEVCFG_I2C1EN_DISABLE        0x00000000u
  #define  CHIP_DEVCFG_I2C1EN_ENABLE         0x00000001u

  #define _CHIP_DEVCFG_I2C0EN_MASK           0x00000008u
  #define _CHIP_DEVCFG_I2C0EN_SHIFT          0x00000003u
  #define  CHIP_DEVCFG_I2C0EN_DEFAULT        0x00000000u
  #define  CHIP_DEVCFG_I2C0EN_OF(x)          _VALUEOF(x)
  #define  CHIP_DEVCFG_I2C0EN_DISABLE        0x00000000u
  #define  CHIP_DEVCFG_I2C0EN_ENABLE         0x00000001u

  #define _CHIP_DEVCFG_MCBSP1EN_MASK         0x00000004u
  #define _CHIP_DEVCFG_MCBSP1EN_SHIFT        0x00000002u
  #define  CHIP_DEVCFG_MCBSP1EN_DEFAULT      0x00000001u
  #define  CHIP_DEVCFG_MCBSP1EN_OF(x)        _VALUEOF(x)
  #define  CHIP_DEVCFG_MCBSP1EN_DISABLE      0x00000000u
  #define  CHIP_DEVCFG_MCBSP1EN_ENABLE       0x00000001u
 
  #define _CHIP_DEVCFG_MCBSP0EN_MASK         0x00000002u
  #define _CHIP_DEVCFG_MCBSP0EN_SHIFT        0x00000001u
  #define  CHIP_DEVCFG_MCBSP0EN_DEFAULT      0x00000001u
  #define  CHIP_DEVCFG_MCBSP0EN_OF(x)        _VALUEOF(x)
  #define  CHIP_DEVCFG_MCBSP0EN_DISABLE      0x00000000u
  #define  CHIP_DEVCFG_MCBSP0EN_ENABLE       0x00000001u

  #define _CHIP_DEVCFG_MCASP0EN_MASK         0x00000001u
  #define _CHIP_DEVCFG_MCASP0EN_SHIFT        0x00000000u
  #define  CHIP_DEVCFG_MCASP0EN_DEFAULT      0x00000000u
  #define  CHIP_DEVCFG_MCASP0EN_OF(x)         _VALUEOF(x)
  #define  CHIP_DEVCFG_MCASP0EN_DISABLE      0x00000000u
  #define  CHIP_DEVCFG_MCASP0EN_ENABLE       0x00000001u

  #define  CHIP_DEVCFG_OF(x)              _VALUEOF(x)

  #define CHIP_DEVCFG_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CHIP,DEVCFG,ATLEN) \
    |_PER_FDEFAULT(CHIP,DEVCFG,ADIV) \
    |_PER_FDEFAULT(CHIP,DEVCFG,ATLMEN) \
    |_PER_FDEFAULT(CHIP,DEVCFG,AFCMUX) \
    |_PER_FDEFAULT(CHIP,DEVCFG,MCASP1EN) \
    |_PER_FDEFAULT(CHIP,DEVCFG,I2C1EN) \
    |_PER_FDEFAULT(CHIP,DEVCFG,I2C0EN) \
    |_PER_FDEFAULT(CHIP,DEVCFG,MCBSP1EN) \
    |_PER_FDEFAULT(CHIP,DEVCFG,MCBSP0EN) \
    |_PER_FDEFAULT(CHIP,DEVCFG,MCASP0EN) \
   )  
  

 #define CHIP_DEVCFG_RMK(atlen,adiv,atlmen,afcmux,mcasp1en,i2c1en,i2c0en,mcbsp1en,mcbsp0en,mcasp0en) (Uint32)( \
     _PER_FMK(CHIP,DEVCFG,ATLEN,atlen) \
    |_PER_FMK(CHIP,DEVCFG,ADIV,adiv) \
    |_PER_FMK(CHIP,DEVCFG,ATLMEN,atlmen) \
    |_PER_FMK(CHIP,DEVCFG,AFCMUX,afcmux) \
    |_PER_FMK(CHIP,DEVCFG,MCASP1EN,mcasp1en) \
    |_PER_FMK(CHIP,DEVCFG,I2C1EN,i2c1en) \
    |_PER_FMK(CHIP,DEVCFG,I2C0EN,i2c0en) \
    |_PER_FMK(CHIP,DEVCFG,MCBSP1EN,mcbsp1en) \
    |_PER_FMK(CHIP,DEVCFG,MCBSP0EN,mcbsp0en) \
    |_PER_FMK(CHIP,DEVCFG,MCASP0EN,mcasp0en) \
  )  

#endif /* CHIP_6410 || CHIP_6413 || CHIP_6418 */

#if (CHIP_6711C || CHIP_6712C)
  #define   _CHIP_DEVCFG_ADDR              0x019C0200u
  #define   _CHIP_DEVCFG_OFFSET            0

  #define _CHIP_DEVCFG_EKSRC_MASK          0x00000010u
  #define _CHIP_DEVCFG_EKSRC_SHIFT         0x00000004u
  #define  CHIP_DEVCFG_EKSRC_DEFAULT       0x00000000u
  #define  CHIP_DEVCFG_EKSRC_OF(x)         _VALUEOF(x)
  #define  CHIP_DEVCFG_EKSRC_SYSCLK3       0x00000000u
  #define  CHIP_DEVCFG_EKSRC_ECLKIN        0x00000001u

  #define  CHIP_DEVCFG_OF(x)              _VALUEOF(x)

  #define CHIP_DEVCFG_DEFAULT (Uint32)( \
     _PER_FDEFAULT(CHIP,DEVCFG,EKSRC) \
 )

  #define CHIP_DEVCFG_RMK(eksrc) (Uint32)( \
      _PER_FMK(CHIP,DEVCFG,EKSRC,eksrc) \
)

#endif /* CHIP_6711C || CHIP_6712C */


  #define _CHIP_DEVCFG_FGET(FIELD)\
    _PER_FGET(_CHIP_DEVCFG_ADDR,CHIP,DEVCFG,##FIELD)

  #define _CHIP_DEVCFG_FSET(FIELD,field)\
    _PER_FSET(_CHIP_DEVCFG_ADDR,CHIP,DEVCFG,##FIELD,field)

  #define _CHIP_DEVCFG_FSETS(FIELD,SYM)\
    _PER_FSETS(_CHIP_DEVCFG_ADDR,CHIP,DEVCFG,##FIELD,##SYM)

/*----------------------------------------------------------------------------*/
/******************************************************************************\
* _____________________
* |                   |
* |  D E V S T A T    |
* |___________________|
*
* DEVSTAT - Device Status Register (1)
*
* FIELDS (msb -> lsb)
* DM642
* (r) MACEN
* (r) HPIWIDTH
* (r) PCIEEAI
* (r) PCIEN
* (r) CLKMODE
* (r) LENDIAN
* (r) BOOTMODE
* (r) AECLKINSEL
*
* DRI300
* (r) PLLM
* (r) OSCEXTRES
* (r) CLKINSEL
* (r) CLKMODE3
* (r) HPIWIDTH
* (r) HPIENZ
* (r) CLKMODE2
* (r) CLKMODE1
* (r) CLKMODE0
* (r) LENDIAN
* (r) BOOTMODE
* (r) AECLKINSEL
*
* 
\******************************************************************************/
#if (CHIP_DM642 | CHIP_DM641 | CHIP_DM640 | CHIP_6412)

  #define   _CHIP_DEVSTAT_ADDR                0x01B3F004u
  #define   _CHIP_DEVSTAT_OFFSET              0

  #define _CHIP_DEVSTAT_MACEN_MASK            0x00000800u
  #define _CHIP_DEVSTAT_MACEN_SHIFT           0x0000000Bu
  #define  CHIP_DEVSTAT_MACEN_DEFAULT         0x00000000u
  #define  CHIP_DEVSTAT_MACEN_OF(x)           _VALUEOF(x)
  #define  CHIP_DEVSTAT_MACEN_DISABLE         0x00000000u
  #define  CHIP_DEVSTAT_MACEN_ENABLE          0x00000001u

 #if !(CHIP_DM640)
  #define _CHIP_DEVSTAT_HPIWIDTH_MASK            0x00000400u
  #define _CHIP_DEVSTAT_HPIWIDTH_SHIFT           0x0000000Au
  #define  CHIP_DEVSTAT_HPIWIDTH_DEFAULT         0x00000000u
  #define  CHIP_DEVSTAT_HPIWIDTH_OF(x)           _VALUEOF(x)
  #define  CHIP_DEVSTAT_HPIWIDTH_16              0x00000000u
  #define  CHIP_DEVSTAT_HPIWIDTH_32              0x00000001u
 #endif

 #if !(CHIP_DM641 | CHIP_DM640)
  #define _CHIP_DEVSTAT_PCIEEAI_MASK            0x00000200u
  #define _CHIP_DEVSTAT_PCIEEAI_SHIFT           0x00000009u
  #define  CHIP_DEVSTAT_PCIEEAI_DEFAULT         0x00000000u
  #define  CHIP_DEVSTAT_PCIEEAI_OF(x)           _VALUEOF(x)
  #define  CHIP_DEVSTAT_PCIEEAI_NONE            0x00000000u
  #define  CHIP_DEVSTAT_PCIEEAI_INIT            0x00000001u

  #define _CHIP_DEVSTAT_PCIEN_MASK           0x00000100u
  #define _CHIP_DEVSTAT_PCIEN_SHIFT          0x00000008u
  #define  CHIP_DEVSTAT_PCIEN_DEFAULT        0x00000000u
  #define  CHIP_DEVSTAT_PCIEN_OF(x)          _VALUEOF(x)
  #define  CHIP_DEVSTAT_PCIEN_DISABLE        0x00000000u
  #define  CHIP_DEVSTAT_PCIEN_ENABLE         0x00000001u
 #endif

  #define _CHIP_DEVSTAT_CLKMODE_MASK         0x00000060u
  #define _CHIP_DEVSTAT_CLKMODE_SHIFT        0x00000005u
  #define  CHIP_DEVSTAT_CLKMODE_DEFAULT      0x00000001u
  #define  CHIP_DEVSTAT_CLKMODE_OF(x)        _VALUEOF(x)
  #define  CHIP_DEVSTAT_CLKMODE_X1           0x00000000u
  #define  CHIP_DEVSTAT_CLKMODE_X6           0x00000001u
  #define  CHIP_DEVSTAT_CLKMODE_X12          0x00000002u
  #define  CHIP_DEVSTAT_CLKMODE_X20          0x00000003u

  #define _CHIP_DEVSTAT_LENDIAN_MASK         0x00000010u
  #define _CHIP_DEVSTAT_LENDIAN_SHIFT        0x00000004u
  #define  CHIP_DEVSTAT_LENDIAN_DEFAULT      0x00000001u
  #define  CHIP_DEVSTAT_LENDIAN_OF(x)        _VALUEOF(x)
  #define  CHIP_DEVSTAT_LENDIAN_BIG          0x00000000u
  #define  CHIP_DEVSTAT_LENDIAN_LITTLE       0x00000001u

  #define _CHIP_DEVSTAT_BOOTMODE_MASK         0x0000000Cu
  #define _CHIP_DEVSTAT_BOOTMODE_SHIFT        0x00000002u
  #define  CHIP_DEVSTAT_BOOTMODE_DEFAULT      0x00000000u
  #define  CHIP_DEVSTAT_BOOTMODE_OF(x)         _VALUEOF(x)
  #define  CHIP_DEVSTAT_BOOTMODE_NONE         0x00000000u
  #define  CHIP_DEVSTAT_BOOTMODE_HPIPCI       0x00000001u
  #define  CHIP_DEVSTAT_BOOTMODE_EMIFA        0x00000003u

  #define _CHIP_DEVSTAT_AECLKINSEL_MASK         0x00000003u
  #define _CHIP_DEVSTAT_AECLKINSEL_SHIFT        0x00000000u
  #define  CHIP_DEVSTAT_AECLKINSEL_DEFAULT      0x00000000u
  #define  CHIP_DEVSTAT_AECLKINSEL_OF(x)         _VALUEOF(x)
  #define  CHIP_DEVSTAT_AECLKINSEL_ECLKIN       0x00000000u
  #define  CHIP_DEVSTAT_AECLKINSEL_CLKOUT4      0x00000001u
  #define  CHIP_DEVSTAT_AECLKINSEL_CLKOUT6      0x00000002u
  #define  CHIP_DEVSTAT_OF(x)              _VALUEOF(x)

  #define  CHIP_DEVSTAT_OF(x)              _VALUEOF(x)

  /* Read only Register */

  #define _CHIP_DEVSTAT_FGET(FIELD)\
    _PER_FGET(_CHIP_DEVSTAT_ADDR,CHIP,DEVSTAT,##FIELD)


#endif /* CHIP_DM642 | CHIP_6412  */

#if (CHIP_6410 || CHIP_6413 || CHIP_6418)

  #define   _CHIP_DEVSTAT_ADDR                 0x01B3F004u
  #define   _CHIP_DEVSTAT_OFFSET               0

  #define _CHIP_DEVSTAT_PLLM_MASK              0x00F10000u
  #define _CHIP_DEVSTAT_PLLM_SHIFT             0x00000013u
  #define  CHIP_DEVSTAT_PLLM_DEFAULT           0x00000000u
  #define  CHIP_DEVSTAT_PLLM_OF(x)             _VALUEOF(x)
  #define  CHIP_DEVSTAT_PLLM_BYPASS            0x00000000u
  #define  CHIP_DEVSTAT_PLLM_5                 0x00000001u
  #define  CHIP_DEVSTAT_PLLM_6                 0x00000002u
  #define  CHIP_DEVSTAT_PLLM_7                 0x00000003u
  #define  CHIP_DEVSTAT_PLLM_8                 0x00000004u
  #define  CHIP_DEVSTAT_PLLM_9                 0x00000005u
  #define  CHIP_DEVSTAT_PLLM_10                0x00000006u
  #define  CHIP_DEVSTAT_PLLM_11                0x00000007u
  #define  CHIP_DEVSTAT_PLLM_12                0x00000008u
  #define  CHIP_DEVSTAT_PLLM_16                0x00000009u
  #define  CHIP_DEVSTAT_PLLM_18                0x0000000Au
  #define  CHIP_DEVSTAT_PLLM_19                0x0000000Bu
  #define  CHIP_DEVSTAT_PLLM_20                0x0000000Cu
  #define  CHIP_DEVSTAT_PLLM_21                0x0000000Du
  #define  CHIP_DEVSTAT_PLLM_22                0x0000000Eu
  #define  CHIP_DEVSTAT_PLLM_24                0x0000000Fu
 
  #define _CHIP_DEVSTAT_OSCEXTRES_MASK         0x00020000u
  #define _CHIP_DEVSTAT_OSCEXTRES_SHIFT        0x00000011u
  #define  CHIP_DEVSTAT_OSCEXTRES_DEFAUL       0x00000001u
  #define  CHIP_DEVSTAT_OSCEXTRES_OF(x)        _VALUEOF(x)
  #define  CHIP_DEVSTAT_OSCEXTRES_DISABL       0x00000000u
  #define  CHIP_DEVSTAT_OSCEXTRES_ENABLE       0x00000001u
 
  #define _CHIP_DEVSTAT_CLKINSEL_MASK          0x00010000u
  #define _CHIP_DEVSTAT_CLKINSEL_SHIFT         0x00000010u
  #define  CHIP_DEVSTAT_CLKINSEL_DEFAULT       0x00000000u
  #define  CHIP_DEVSTAT_CLKINSEL_OF(x)         _VALUEOF(x)
  #define  CHIP_DEVSTAT_CLKINSEL_DISABLE       0x00000000u
  #define  CHIP_DEVSTAT_CLKINSEL_ENABLE        0x00000001u
 
  #define _CHIP_DEVSTAT_HPIWIDTH_MASK          0x00000400u
  #define _CHIP_DEVSTAT_HPIWIDTH_SHIFT         0x0000000Au
  #define  CHIP_DEVSTAT_HPIWIDTH_DEFAUL        0x00000000u
  #define  CHIP_DEVSTAT_HPIWIDTH_OF(x)         _VALUEOF(x)
  #define  CHIP_DEVSTAT_HPIWIDTH_16            0x00000000u
  #define  CHIP_DEVSTAT_HPIWIDTH_32            0x00000001u
 
  #define _CHIP_DEVSTAT_HPIENZ_MASK            0x00000100u
  #define _CHIP_DEVSTAT_HPIENZ_SHIFT           0x00000008u
  #define  CHIP_DEVSTAT_HPIENZ_DEFAULT         0x00000000u
  #define  CHIP_DEVSTAT_HPIENZ_OF(x)           _VALUEOF(x)
  #define  CHIP_DEVSTAT_HPIENZ_ENABLE          0x00000000u
  #define  CHIP_DEVSTAT_HPIENZ_DISABLE         0x00000001u
 
  #define _CHIP_DEVSTAT_CLKMODE_MASK          0x000010E0u
  #define _CHIP_DEVSTAT_CLKMODE_SHIFT         0x00000005u
  #define  CHIP_DEVSTAT_CLKMODE_DEFAULT       0x00000001u
  #define  CHIP_DEVSTAT_CLKMODE_OF(x)         _VALUEOF(x)
  #define  CHIP_DEVSTAT_CLKMODE_0             0x00000000u
  #define  CHIP_DEVSTAT_CLKMODE_1             0x00000001u
  #define  CHIP_DEVSTAT_CLKMODE_2             0x00000002u
  #define  CHIP_DEVSTAT_CLKMODE_3             0x00000003u
  #define  CHIP_DEVSTAT_CLKMODE_4             0x00000004u
  #define  CHIP_DEVSTAT_CLKMODE_5             0x00000005u
  #define  CHIP_DEVSTAT_CLKMODE_6             0x00000006u
  #define  CHIP_DEVSTAT_CLKMODE_7             0x00000007u
  #define  CHIP_DEVSTAT_CLKMODE_8             0x00000080u
  #define  CHIP_DEVSTAT_CLKMODE_9             0x00000081u
  #define  CHIP_DEVSTAT_CLKMODE_10            0x00000082u
  #define  CHIP_DEVSTAT_CLKMODE_11            0x00000083u
  #define  CHIP_DEVSTAT_CLKMODE_12            0x00000084u
  #define  CHIP_DEVSTAT_CLKMODE_13            0x00000085u
  #define  CHIP_DEVSTAT_CLKMODE_14            0x00000086u
  #define  CHIP_DEVSTAT_CLKMODE_15            0x00000087u
 
  #define _CHIP_DEVSTAT_LENDIAN_MASK           0x00000010u
  #define _CHIP_DEVSTAT_LENDIAN_SHIFT          0x00000004u
  #define  CHIP_DEVSTAT_LENDIAN_DEFAULT        0x00000001u
  #define  CHIP_DEVSTAT_LENDIAN_OF(x)          _VALUEOF(x)
  #define  CHIP_DEVSTAT_LENDIAN_BIG            0x00000000u 
  #define  CHIP_DEVSTAT_LENDIAN_LITTLE         0x00000001u
 
  #define _CHIP_DEVSTAT_BOOTMODE_MASK          0x0000000Cu
  #define _CHIP_DEVSTAT_BOOTMODE_SHIFT         0x00000002u
  #define  CHIP_DEVSTAT_BOOTMODE_DEFAULT       0x00000000u
  #define  CHIP_DEVSTAT_BOOTMODE_OF(x)          _VALUEOF(x)
  #define  CHIP_DEVSTAT_BOOTMODE_NONE          0x00000000u
  #define  CHIP_DEVSTAT_BOOTMODE_HPI           0x00000001u
  #define  CHIP_DEVSTAT_BOOTMODE_EMIFA         0x00000003u

  #define _CHIP_DEVSTAT_AECLKINSEL_MASK        0x00000003u
  #define _CHIP_DEVSTAT_AECLKINSEL_SHIFT       0x00000000u
  #define  CHIP_DEVSTAT_AECLKINSEL_DEFAULT     0x00000000u
  #define  CHIP_DEVSTAT_AECLKINSEL_OF(x)       _VALUEOF(x)
  #define  CHIP_DEVSTAT_AECLKINSEL_ECLKIN      0x00000000u
  #define  CHIP_DEVSTAT_AECLKINSEL_CLKOUT4     0x00000001u
  #define  CHIP_DEVSTAT_AECLKINSEL_CLKOUT6     0x00000002u

  #define  CHIP_DEVSTAT_OF(x)              _VALUEOF(x)

  /* Read only Register */

  #define _CHIP_DEVSTAT_FGET(FIELD)\
    _PER_FGET(_CHIP_DEVSTAT_ADDR,CHIP,DEVSTAT,##FIELD)


#endif /* CHIP_6410 || CHIP_6413 || CHIP_6418 */

/******************************************************************************\
* _____________________
* |                   |
* |  J T A G I D      |
* |___________________|
*
* JTAGID - JTAG ID register (1)
*
* FIELDS (msb -> lsb)
* (r) VARIANT
* (r) PART
* (r) MANNUFACTURE
* (r) LSB
*
* (1) Only for DM642
*
\******************************************************************************/


#if (CHIP_DM642 || CHIP_DM641 || CHIP_DM640 || CHIP_6412 )

  #define   _CHIP_JTAGID_ADDR                0x01B3F008u
  #define   _CHIP_JTAGID_OFFSET              0

  #define _CHIP_JTAGID_VARIANT_MASK          0xF0000000u
  #define _CHIP_JTAGID_VARIANT_SHIFT         0x0000001Cu
  #define  CHIP_JTAGID_VARIANT_DEFAULT       0x00000000u
  #define  CHIP_JTAGID_VARIANT_OF(x)         _VALUEOF(x)

  #define _CHIP_JTAGID_PART_MASK             0x0FFFF000u
  #define _CHIP_JTAGID_PART_SHIFT            0x0000000Cu
  #define  CHIP_JTAGID_PART_DEFAULT          0x00000079u
  #define  CHIP_JTAGID_PART_OF(x)            _VALUEOF(x)

  #define _CHIP_JTAGID_MANUFACTURE_MASK      0x00000FFEu
  #define _CHIP_JTAGID_MANUFACTURE_SHIFT     0x00000001u
  #define  CHIP_JTAGID_MANUFACTURE_DEFAULT   0x00000017u
  #define  CHIP_JTAGID_MANUFACTURE_OF(x)     _VALUEOF(x)

  #define _CHIP_JTAGID_LSB_MASK              0x00000001u
  #define _CHIP_JTAGID_LSB_SHIFT             0x00000000u
  #define  CHIP_JTAGID_LSB_DEFAULT           0x00000001u
  #define  CHIP_JTAGID_LSB_OF(x)             _VALUEOF(x)

  #define  CHIP_JTAGID_OF(x)              _VALUEOF(x)

  #define _CHIP_JTAGID_FGET(FIELD)\
    _PER_FGET(_CHIP_JTAGID_ADDR,CHIP,JTAGID,##FIELD)

#endif /* CHIP_DM642 || CHIP_6412  */

/******************************************************************************\
* _____________________
* |                   |
* |  P C F G L O C K  |
* |___________________|
*
* PCFGLOCK - Peripheral Configuration Lock register (1)
*
* FIELDS (msb -> lsb)
* (r) LOCKSTAT
* (w) LOCK
*
* (1) Only for DM642
*
\******************************************************************************/

#if (CHIP_DM642 || CHIP_DM641 || CHIP_DM640 || CHIP_6412 || CHIP_6410 || CHIP_6413 || CHIP_6418)

  #define   _CHIP_PCFGLOCK_ADDR                 0x01B3F018u
  #define   _CHIP_PCFGLOCK_OFFSET               0

  #define _CHIP_PCFGLOCK_LOCKSTAT_MASK          0x00000001u
  #define _CHIP_PCFGLOCK_LOCKSTAT_SHIFT         0x00000000u
  #define  CHIP_PCFGLOCK_LOCKSTAT_DEFAULT       0x00000001u
  #define  CHIP_PCFGLOCK_LOCKSTAT_OF(x)         _VALUEOF(x)
  #define  CHIP_PCFGLOCK_LOCKSTAT_UNLOCK        0x00000000u
  #define  CHIP_PCFGLOCK_LOCKSTAT_LOCK          0x00000001u

  #define _CHIP_PCFGLOCK_LOCK_MASK              0xFFFFFFFFu
  #define _CHIP_PCFGLOCK_LOCK_SHIFT             0x00000000u
  #define  CHIP_PCFGLOCK_LOCK_DEFAULT           0x00000000u
  #define  CHIP_PCFGLOCK_LOCK_OF(x)             _VALUEOF(x)
  #define  CHIP_PCFGLOCK_LOCK_UNLOCK            0x10C0010Cu
  #define  CHIP_PCFGLOCK_LOCK_DISABLE           0x10C0010Cu

  #define  CHIP_PCFGLOCK_OF(x)                  _VALUEOF(x)

  #define _CHIP_PCFGLOCK_FGET(FIELD)\
    _PER_FGET(_CHIP_PCFGLOCK_ADDR,CHIP,PCFGLOCK,##FIELD)

  #define _CHIP_PCFGLOCK_FSET(FIELD,field)\
    _PER_FSET(_CHIP_PCFGLOCK_ADDR,CHIP,PCFGLOCK,##FIELD,field)

  #define _CHIP_PCFGLOCK_FSETS(FIELD,SYM)\
    _PER_FSETS(_CHIP_PCFGLOCK_ADDR,CHIP,PCFGLOCK,##FIELD,##SYM)


#endif /* CHIP_DM642 || CHIP_DM641 || CHIP_DM640 || CHIP_6412 || CHIP_6410 || CHIP_6413 || CHIP_6418*/

/*----------------------------------------------------------------------------*/
#endif /* _CSL_CHIPHAL_H_ */
/******************************************************************************\
* End of csl_chiphal.h
\******************************************************************************/

