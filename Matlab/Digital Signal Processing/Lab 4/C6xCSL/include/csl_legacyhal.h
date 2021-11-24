/*
 *  Copyright 2001 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.60.22 12-07-01 (barracuda-j15)" */
/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_legacyhal.h
* DATE CREATED.. 09/01/2000
* LAST MODIFIED. 03/08/2002
\******************************************************************************/
#ifndef _CSL_LEGACYHAL_H_
#define _CSL_LEGACYHAL_H_

#include "csl_stdinc.h"
#include "csl_chiphal.h"

/*----------------------------------------------------------------------------*/
/* Legacy HAL support macro definitions                                       */
/*----------------------------------------------------------------------------*/
  #define _VALUEOF(x) ((Uint32)(x))

#ifndef UNREFERENCED_PARAMETER
  #define UNREFERENCED_PARAMETER(P)    ((P)=(P))
#endif

#ifndef REG32
  #define REG32(addr) (*(volatile unsigned int*)(addr))
  #define REG16(addr) (*(volatile unsigned short*)(addr))
  #define REG8(addr) (*(volatile unsigned char*)(addr))
#endif

/* memory mapped register macros */
#define HFIELD_GET(RegAddr,FIELD) (Uint32)( \
  (REG32(RegAddr)&##FIELD##_MASK)>>##FIELD##_SHIFT \
)

#define HFIELD_SET(RegAddr,FIELD,Val) REG32(RegAddr)=(Uint32)( \
  (REG32(RegAddr)&~##FIELD##_MASK)| \
  (((Uint32)(Val)<<##FIELD##_SHIFT)&##FIELD##_MASK) \
)

#define HFIELD_SHIFT(FIELD,Val) \
  (((Uint32)(Val)<<##FIELD##_SHIFT)&##FIELD##_MASK)

#define HREG32_GET(RegAddr) \
  (Uint32)REG32(RegAddr)

#define HREG32_SET(RegAddr,Val) \
  REG32(RegAddr)=(Uint32)(Val)

/* control register macros */
#define HCRFIELD_GET(CRREG,FIELD) (Uint32)( \
  (((CRREG)&##FIELD##_MASK)>>##FIELD##_SHIFT) \
)



#define HCRFIELD_SET(CRREG,FIELD,Val) CRREG = (Uint32)( \
  ((CRREG)&~##FIELD##_MASK)| \
  (((Uint32)(Val)<<##FIELD##_SHIFT)&##FIELD##_MASK) \
)

#define HCRFIELD_SHIFT(FIELD,Val) \
  (((Uint32)(Val)<<##FIELD##_SHIFT)&##FIELD##_MASK)

#define HCRREG32_GET(CRREG) \
  (Uint32)(CRREG)

#define HCRREG32_SET(CRREG,Val) \
  (CRREG)=(Uint32)(Val)


/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... chiphal.h
* DATE CREATED.. 08/19/1999 
* LAST MODIFIED. 03/08/2000
*   
*------------------------------------------------------------------------------
* DESCRIPTION:  (HAL interface file for the CHIP module)
* 
* CHIP Control Registers Covered
*   HCHIP_CSR    - control status register
*   HCHIP_IFR    - interrupt flag register
*   HCHIP_ISR    - interrupt set register
*   HCHIP_ICR    - interrupt clear register
*   HCHIP_IER    - interrupt enable register
*   HCHIP_ISTP   - interrupt service table pointer
*   HCHIP_IRP    - interrrupt return pointer
*   HCHIP_NRP    - nonmaskable interrupt return pointer
*   HCHIP_AMR    - addressing mode register
*   HCHIP_FADCR  - floating-point adder config register (1)
*   HCHIP_FAUCR  - floating-point auxiliary config register (1)
*   HCHIP_FMCR   - floating-point multiplier config register (1)
*
*   (1) only on devices with an FPU
*
\******************************************************************************/
#ifndef _CHIPHAL_H_
#define _CHIPHAL_H_

/*----------------------------------------------------------------*/

#define HCHIP_PERBASE_ADDR   (0x01800000)

/******************************************************************************\
* HCHIP_NULL - dummy register
*
\******************************************************************************/
  #define HCHIP_NULL_ADDR                       ((UINT32)(0x01840074))
  #define HCHIP_NULL                            REG32(HCHIP_NULL_ADDR)

/******************************************************************************\
* HCHIP_CSR - control status register
*
* Fields:
*   (RW) HCHIP_CSR_GIE
*   (RW) HCHIP_CSR_PGIE
*   (RW) HCHIP_CSR_DCC
*   (RW) HCHIP_CSR_PCC
*   (R)  HCHIP_CSR_EN
*   (RC) HCHIP_CSR_SAT
*   (RW) HCHIP_CSR_PWRD
*   (R)  HCHIP_CSR_REVID
*   (R)  HCHIP_CSR_CPUID
*
\******************************************************************************/
  extern far cregister volatile unsigned int CSR;
  #define HCHIP_CSR CSR
  
/*----------------------------------------------------------------------------*\
* (RW) HCHIP_CSR_GIE
\*----------------------------------------------------------------------------*/ 
  #define HCHIP_CSR_GIE_MASK                     (0x00000001)
  #define HCHIP_CSR_GIE_SHIFT                    (0x00000000)
  
  #define HCHIP_CSR_GIE_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_CSR_GIE)

  #define HCHIP_CSR_GIE_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_CSR_GIE,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_CSR_PGIE
\*----------------------------------------------------------------------------*/
  #define HCHIP_CSR_PGIE_MASK                    (0x00000002)
  #define HCHIP_CSR_PGIE_SHIFT                   (0x00000001) 

  #define HCHIP_CSR_PGIE_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_CSR_PGIE)

  #define HCHIP_CSR_PGIE_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_CSR_PGIE,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_CSR_DCC
\*----------------------------------------------------------------------------*/
  #define HCHIP_CSR_DCC_MASK                     (0x0000001C)
  #define HCHIP_CSR_DCC_SHIFT                    (0x00000002)

  #define HCHIP_CSR_DCC_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_CSR_DCC)

  #define HCHIP_CSR_DCC_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_CSR_DCC,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_CSR_PCC
\*----------------------------------------------------------------------------*/
  #define HCHIP_CSR_PCC_MASK                     (0x000000E0)
  #define HCHIP_CSR_PCC_SHIFT                    (0x00000005)

  #define HCHIP_CSR_PCC_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_CSR_PCC)

  #define HCHIP_CSR_PCC_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_CSR_PCC,Val)

/*----------------------------------------------------------------------------*\
* (R) HCHIP_CSR_EN
\*----------------------------------------------------------------------------*/
  #define HCHIP_CSR_EN_MASK                      (0x00000100)
  #define HCHIP_CSR_EN_SHIFT                     (0x00000008)
  
  #define HCHIP_CSR_EN_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_CSR_EN)

/*----------------------------------------------------------------------------*\
* (RC) HCHIP_CSR_SAT
\*----------------------------------------------------------------------------*/
  #define HCHIP_CSR_SAT_MASK                     (0x00000200)
  #define HCHIP_CSR_SAT_SHIFT                    (0x00000009)

  #define HCHIP_CSR_SAT_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_CSR_SAT)

  #define HCHIP_CSR_SAT_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_CSR_SAT,Val)

/*----------------------------------------------------------------------------*\
* (W) HCHIP_CSR_PWRD
\*----------------------------------------------------------------------------*/
  #define HCHIP_CSR_PWRD_MASK                    (0x0000FC00)
  #define HCHIP_CSR_PWRD_SHIFT                   (0x0000000A)

  #define HCHIP_CSR_PWRD_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_CSR_PWRD,Val)

/*----------------------------------------------------------------------------*\
* (R) HCHIP_CSR_REVID
\*----------------------------------------------------------------------------*/
  #define HCHIP_CSR_REVID_MASK                   (0x00FF0000)
  #define HCHIP_CSR_REVID_SHIFT                  (0x00000010) 
  
  #define HCHIP_CSR_REVID_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_CSR_REVID)

/*----------------------------------------------------------------------------*\
* (R) HCHIP_CSR_CPUID
\*----------------------------------------------------------------------------*/
  #define HCHIP_CSR_CPUID_MASK                   (0xFF000000)
  #define HCHIP_CSR_CPUID_SHIFT                  (0x00000018)

  #define HCHIP_CSR_CPUID_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_CSR_CPUID)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_CSR
\*----------------------------------------------------------------------------*/
  #define HCHIP_CSR_GET(CrReg) HCRREG32_GET(CrReg)

  #define HCHIP_CSR_SET(CrReg,Val) HCRREG32_SET(CrReg,Val)

  #define HCHIP_CSR_CFG(CrReg,gie,pgie,dcc,pcc,pwrd) CrReg=(UINT32)( \
    HCRFIELD_SHIFT(HCHIP_CSR_GIE, gie) |\
    HCRFIELD_SHIFT(HCHIP_CSR_PGIE,pgie)|\
    HCRFIELD_SHIFT(HCHIP_CSR_DCC, dcc) |\
    HCRFIELD_SHIFT(HCHIP_CSR_PCC, pcc) |\
    HCRFIELD_SHIFT(HCHIP_CSR_PWRD,pwrd) \
  )

/******************************************************************************\
* HCHIP_IFR - interrupt flag register
*
* Fields:
*   (R)  HCHIP_IFR_NMIF
*   (R)  HCHIP_IFR_IF4
*   (R)  HCHIP_IFR_IF5
*   (R)  HCHIP_IFR_IF6
*   (R)  HCHIP_IFR_IF7
*   (R)  HCHIP_IFR_IF8
*   (R)  HCHIP_IFR_IF9
*   (R)  HCHIP_IFR_IF10
*   (R)  HCHIP_IFR_IF11
*   (R)  HCHIP_IFR_IF12
*   (R)  HCHIP_IFR_IF13
*   (R)  HCHIP_IFR_IF14
*   (R)  HCHIP_IFR_IF15
*
\******************************************************************************/
  extern far cregister volatile unsigned int IFR;
  #define HCHIP_IFR IFR

/*----------------------------------------------------------------------------*\
* (R) HCHIP_IFR_NMIF
\*----------------------------------------------------------------------------*/
  #define HCHIP_IFR_NMIF_MASK                    (0x00000002)
  #define HCHIP_IFR_NMIF_SHIFT                   (0x00000001)

  #define HCHIP_IFR_NMIF_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_IFR_NMIF)

/*----------------------------------------------------------------------------*\
* (R) HCHIP_IFR_IF4
\*----------------------------------------------------------------------------*/
  #define HCHIP_IFR_IF4_MASK                     (0x00000010)
  #define HCHIP_IFR_IF4_SHIFT                    (0x00000004)

  #define HCHIP_IFR_IF4_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_IFR_IF4)

/*----------------------------------------------------------------------------*\
* (R) HCHIP_IFR_IF5
\*----------------------------------------------------------------------------*/
  #define HCHIP_IFR_IF5_MASK                     (0x00000020)
  #define HCHIP_IFR_IF5_SHIFT                    (0x00000005)

  #define HCHIP_IFR_IF5_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_IFR_IF5)

/*----------------------------------------------------------------------------*\
* (R) HCHIP_IFR_IF6
\*----------------------------------------------------------------------------*/
  #define HCHIP_IFR_IF6_MASK                     (0x00000040)
  #define HCHIP_IFR_IF6_SHIFT                    (0x00000006)

  #define HCHIP_IFR_IF6_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_IFR_IF6)

/*----------------------------------------------------------------------------*\
* (R) HCHIP_IFR_IF7
\*----------------------------------------------------------------------------*/
  #define HCHIP_IFR_IF7_MASK                     (0x00000080)
  #define HCHIP_IFR_IF7_SHIFT                    (0x00000007)

  #define HCHIP_IFR_IF7_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_IFR_IF7)

/*----------------------------------------------------------------------------*\
* (R) HCHIP_IFR_IF8
\*----------------------------------------------------------------------------*/
  #define HCHIP_IFR_IF8_MASK                     (0x00000100)
  #define HCHIP_IFR_IF8_SHIFT                    (0x00000008)

  #define HCHIP_IFR_IF8_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_IFR_IF8)

/*----------------------------------------------------------------------------*\
* (R) HCHIP_IFR_IF9
\*----------------------------------------------------------------------------*/
  #define HCHIP_IFR_IF9_MASK                     (0x00000200)
  #define HCHIP_IFR_IF9_SHIFT                    (0x00000009)

  #define HCHIP_IFR_IF9_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_IFR_IF9)

/*----------------------------------------------------------------------------*\
* (R) HCHIP_IFR_IF10
\*----------------------------------------------------------------------------*/
  #define HCHIP_IFR_IF10_MASK                    (0x00000400)
  #define HCHIP_IFR_IF10_SHIFT                   (0x0000000A)

  #define HCHIP_IFR_IF10_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_IFR_IF10)

/*----------------------------------------------------------------------------*\
* (R) HCHIP_IFR_IF11
\*----------------------------------------------------------------------------*/
  #define HCHIP_IFR_IF11_MASK                    (0x00000800)
  #define HCHIP_IFR_IF11_SHIFT                   (0x0000000B)

  #define HCHIP_IFR_IF11_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_IFR_IF11)

/*----------------------------------------------------------------------------*\
* (R) HCHIP_IFR_IF12
\*----------------------------------------------------------------------------*/
  #define HCHIP_IFR_IF12_MASK                    (0x00001000)
  #define HCHIP_IFR_IF12_SHIFT                   (0x0000000C)

  #define HCHIP_IFR_IF12_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_IFR_IF12)

/*----------------------------------------------------------------------------*\
* (R) HCHIP_IFR_IF13
\*----------------------------------------------------------------------------*/
  #define HCHIP_IFR_IF13_MASK                    (0x00002000)
  #define HCHIP_IFR_IF13_SHIFT                   (0x0000000D)

  #define HCHIP_IFR_IF13_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_IFR_IF13)

/*----------------------------------------------------------------------------*\
* (R) HCHIP_IFR_IF14
\*----------------------------------------------------------------------------*/
  #define HCHIP_IFR_IF14_MASK                    (0x00004000)
  #define HCHIP_IFR_IF14_SHIFT                   (0x0000000E)

  #define HCHIP_IFR_IF14_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_IFR_IF14)

/*----------------------------------------------------------------------------*\
* (R) HCHIP_IFR_IF15
\*----------------------------------------------------------------------------*/
  #define HCHIP_IFR_IF15_MASK                    (0x00008000)
  #define HCHIP_IFR_IF15_SHIFT                   (0x0000000F)

  #define HCHIP_IFR_IF15_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_IFR_IF15)

/*----------------------------------------------------------------------------*\
* (R) HCHIP_IFR
\*----------------------------------------------------------------------------*/
  #define HCHIP_IFR_GET(CrReg) HCRREG32_GET(CrReg)

/******************************************************************************\
* HCHIP_ISR - interrupt set register
*
* Fields:
*   (W)  HCHIP_ISR_IS4
*   (W)  HCHIP_ISR_IS5
*   (W)  HCHIP_ISR_IS6
*   (W)  HCHIP_ISR_IS7
*   (W)  HCHIP_ISR_IS8
*   (W)  HCHIP_ISR_IS9
*   (W)  HCHIP_ISR_IS10
*   (W)  HCHIP_ISR_IS11
*   (W)  HCHIP_ISR_IS12
*   (W)  HCHIP_ISR_IS13
*   (W)  HCHIP_ISR_IS14
*   (W)  HCHIP_ISR_IS15
*
\******************************************************************************/
  extern far cregister volatile unsigned int ISR;
  #define HCHIP_ISR ISR

/*----------------------------------------------------------------------------*\
* (W) HCHIP_ISR_IS4
\*----------------------------------------------------------------------------*/
  #define HCHIP_ISR_IS4_MASK                     (0x00000010)
  #define HCHIP_ISR_IS4_SHIFT                    (0x00000004)

  #define HCHIP_ISR_IS4_SET(CrReg,Val) \
    HCRREG32_SET(CrReg,HFIELD_SHIFT(HCHIP_ISR_IS4,Val))

/*----------------------------------------------------------------------------*\
* (W) HCHIP_ISR_IS5
\*----------------------------------------------------------------------------*/
  #define HCHIP_ISR_IS5_MASK                     (0x00000020)
  #define HCHIP_ISR_IS5_SHIFT                    (0x00000005)

  #define HCHIP_ISR_IS5_SET(CrReg,Val) \
    HCRREG32_SET(CrReg,HFIELD_SHIFT(HCHIP_ISR_IS5,Val))
    
/*----------------------------------------------------------------------------*\
* (W) HCHIP_ISR_IS6
\*----------------------------------------------------------------------------*/
  #define HCHIP_ISR_IS6_MASK                     (0x00000040)
  #define HCHIP_ISR_IS6_SHIFT                    (0x00000006)

  #define HCHIP_ISR_IS6_SET(CrReg,Val) \
    HCRREG32_SET(CrReg,HFIELD_SHIFT(HCHIP_ISR_IS6,Val))

/*----------------------------------------------------------------------------*\
* (W) HCHIP_ISR_IS7
\*----------------------------------------------------------------------------*/
  #define HCHIP_ISR_IS7_MASK                     (0x00000080)
  #define HCHIP_ISR_IS7_SHIFT                    (0x00000007)

  #define HCHIP_ISR_IS7_SET(CrReg,Val) \
    HCRREG32_SET(CrReg,HFIELD_SHIFT(HCHIP_ISR_IS7,Val))

/*----------------------------------------------------------------------------*\
* (W) HCHIP_ISR_IS8
\*----------------------------------------------------------------------------*/
  #define HCHIP_ISR_IS8_MASK                     (0x00000100)
  #define HCHIP_ISR_IS8_SHIFT                    (0x00000008)

  #define HCHIP_ISR_IS8_SET(CrReg,Val) \
    HCRREG32_SET(CrReg,HFIELD_SHIFT(HCHIP_ISR_IS8,Val))

/*----------------------------------------------------------------------------*\
* (W) HCHIP_ISR_IS9
\*----------------------------------------------------------------------------*/
  #define HCHIP_ISR_IS9_MASK                     (0x00000200)
  #define HCHIP_ISR_IS9_SHIFT                    (0x00000009)

  #define HCHIP_ISR_IS9_SET(CrReg,Val) \
    HCRREG32_SET(CrReg,HFIELD_SHIFT(HCHIP_ISR_IS9,Val))

/*----------------------------------------------------------------------------*\
* (W) HCHIP_ISR_IS10
\*----------------------------------------------------------------------------*/
  #define HCHIP_ISR_IS10_MASK                    (0x00000400)
  #define HCHIP_ISR_IS10_SHIFT                   (0x0000000A)

  #define HCHIP_ISR_IS10_SET(CrReg,Val) \
    HCRREG32_SET(CrReg,HFIELD_SHIFT(HCHIP_ISR_IS10,Val))

/*----------------------------------------------------------------------------*\
* (W) HCHIP_ISR_IS11
\*----------------------------------------------------------------------------*/
  #define HCHIP_ISR_IS11_MASK                    (0x00000800)
  #define HCHIP_ISR_IS11_SHIFT                   (0x0000000B)

  #define HCHIP_ISR_IS11_SET(CrReg,Val) \
    HCRREG32_SET(CrReg,HFIELD_SHIFT(HCHIP_ISR_IS11,Val))
/*----------------------------------------------------------------------------*\
* (W) HCHIP_ISR_IS12
\*----------------------------------------------------------------------------*/
  #define HCHIP_ISR_IS12_MASK                    (0x00001000)
  #define HCHIP_ISR_IS12_SHIFT                   (0x0000000C)

  #define HCHIP_ISR_IS12_SET(CrReg,Val) \
    HCRREG32_SET(CrReg,HFIELD_SHIFT(HCHIP_ISR_IS12,Val))

/*----------------------------------------------------------------------------*\
* (W) HCHIP_ISR_IS13
\*----------------------------------------------------------------------------*/
  #define HCHIP_ISR_IS13_MASK                    (0x00002000)
  #define HCHIP_ISR_IS13_SHIFT                   (0x0000000D)

  #define HCHIP_ISR_IS13_SET(CrReg,Val) \
    HCRREG32_SET(CrReg,HFIELD_SHIFT(HCHIP_ISR_IS13,Val))

/*----------------------------------------------------------------------------*\
* (W) HCHIP_ISR_IS14
\*----------------------------------------------------------------------------*/
  #define HCHIP_ISR_IS14_MASK                    (0x00004000)
  #define HCHIP_ISR_IS14_SHIFT                   (0x0000000E)

  #define HCHIP_ISR_IS14_SET(CrReg,Val) \
    HCRREG32_SET(CrReg,HFIELD_SHIFT(HCHIP_ISR_IS14,Val))

/*----------------------------------------------------------------------------*\
* (W) HCHIP_ISR_IS15
\*----------------------------------------------------------------------------*/
  #define HCHIP_ISR_IS15_MASK                    (0x00008000)
  #define HCHIP_ISR_IS15_SHIFT                   (0x0000000F)

  #define HCHIP_ISR_IS15_SET(CrReg,Val) \
    HCRREG32_SET(CrReg,HFIELD_SHIFT(HCHIP_ISR_IS15,Val))

/*----------------------------------------------------------------------------*\
* (W) HCHIP_ISR
\*----------------------------------------------------------------------------*/
  #define HCHIP_ISR_SET(CrReg,Val) HCRREG32_SET(CrReg,Val)

  #define HCHIP_ISR_CFG(CrReg,is4,is5,is6,is7,is8,is9,is10,is11,is12,is13,is14,\
  is15) CrReg=(UINT32)( \
      HCRFIELD_SHIFT(HCHIP_ISR_IS4, is4) |\
      HCRFIELD_SHIFT(HCHIP_ISR_IS5, is5) |\
      HCRFIELD_SHIFT(HCHIP_ISR_IS6, is6) |\
      HCRFIELD_SHIFT(HCHIP_ISR_IS7, is7) |\
      HCRFIELD_SHIFT(HCHIP_ISR_IS8, is8) |\
      HCRFIELD_SHIFT(HCHIP_ISR_IS9, is9) |\
      HCRFIELD_SHIFT(HCHIP_ISR_IS10,is10)|\
      HCRFIELD_SHIFT(HCHIP_ISR_IS11,is11)|\
      HCRFIELD_SHIFT(HCHIP_ISR_IS12,is12)|\
      HCRFIELD_SHIFT(HCHIP_ISR_IS13,is13)|\
      HCRFIELD_SHIFT(HCHIP_ISR_IS14,is14)|\
      HCRFIELD_SHIFT(HCHIP_ISR_IS15,is15) \
    )   

/******************************************************************************\
* HCHIP_ICR - interrupt clear register
*
* Fields:
*   (W)  HCHIP_ICR_IC4
*   (W)  HCHIP_ICR_IC5
*   (W)  HCHIP_ICR_IC6
*   (W)  HCHIP_ICR_IC7
*   (W)  HCHIP_ICR_IC8
*   (W)  HCHIP_ICR_IC9
*   (W)  HCHIP_ICR_IC10
*   (W)  HCHIP_ICR_IC11
*   (W)  HCHIP_ICR_IC12
*   (W)  HCHIP_ICR_IC13
*   (W)  HCHIP_ICR_IC14
*   (W)  HCHIP_ICR_IC15
*
\******************************************************************************/
  extern far cregister volatile unsigned int ICR;
  #define HCHIP_ICR ICR

/*----------------------------------------------------------------------------*\
* (W) HCHIP_ICR_IC4
\*----------------------------------------------------------------------------*/
  #define HCHIP_ICR_IC4_MASK                     (0x00000010)
  #define HCHIP_ICR_IC4_SHIFT                    (0x00000004)

  #define HCHIP_ICR_IC4_SET(CrReg,Val) \
  HCRREG32_SET(CrReg,HFIELD_SHIFT(HCHIP_ICR_IC4,Val))

/*----------------------------------------------------------------------------*\
* (W) HCHIP_ICR_IC5
\*----------------------------------------------------------------------------*/
  #define HCHIP_ICR_IC5_MASK                     (0x00000020)
  #define HCHIP_ICR_IC5_SHIFT                    (0x00000005)

  #define HCHIP_ICR_IC5_SET(CrReg,Val) \
  HCRREG32_SET(CrReg,HFIELD_SHIFT(HCHIP_ICR_IC5,Val))
    

/*----------------------------------------------------------------------------*\
* (W) HCHIP_ICR_IC6
\*----------------------------------------------------------------------------*/
  #define HCHIP_ICR_IC6_MASK                     (0x00000040)
  #define HCHIP_ICR_IC6_SHIFT                    (0x00000006)
  
  #define HCHIP_ICR_IC6_SET(CrReg,Val) \
   HCRREG32_SET(CrReg,HFIELD_SHIFT(HCHIP_ICR_IC6,Val))

/*----------------------------------------------------------------------------*\
* (W) HCHIP_ICR_IC7
\*----------------------------------------------------------------------------*/
  #define HCHIP_ICR_IC7_MASK                     (0x00000080)
  #define HCHIP_ICR_IC7_SHIFT                    (0x00000007)

  #define HCHIP_ICR_IC7_SET(CrReg,Val) \
    HCRREG32_SET(CrReg,HFIELD_SHIFT(HCHIP_ICR_IC7,Val))

/*----------------------------------------------------------------------------*\
* (W) HCHIP_ICR_IC8
\*----------------------------------------------------------------------------*/
  #define HCHIP_ICR_IC8_MASK                     (0x00000100)
  #define HCHIP_ICR_IC8_SHIFT                    (0x00000008)

  #define HCHIP_ICR_IC8_SET(CrReg,Val) \
    HCRREG32_SET(CrReg,HFIELD_SHIFT(HCHIP_ICR_IC8,Val))

/*----------------------------------------------------------------------------*\
* (W) HCHIP_ICR_IC9
\*----------------------------------------------------------------------------*/
  #define HCHIP_ICR_IC9_MASK                     (0x00000200)
  #define HCHIP_ICR_IC9_SHIFT                    (0x00000009)

  #define HCHIP_ICR_IC9_SET(CrReg,Val) \
    HCRREG32_SET(CrReg,HFIELD_SHIFT(HCHIP_ICR_IC9,Val))

/*----------------------------------------------------------------------------*\
* (W) HCHIP_ICR_IC10
\*----------------------------------------------------------------------------*/
  #define HCHIP_ICR_IC10_MASK                    (0x00000400)
  #define HCHIP_ICR_IC10_SHIFT                   (0x0000000A)

  #define HCHIP_ICR_IC10_SET(CrReg,Val) \
  HCRREG32_SET(CrReg,HFIELD_SHIFT(HCHIP_ICR_IC10,Val))
  
/*----------------------------------------------------------------------------*\
* (W) HCHIP_ICR_IC11
\*----------------------------------------------------------------------------*/
  #define HCHIP_ICR_IC11_MASK                    (0x00000800)
  #define HCHIP_ICR_IC11_SHIFT                   (0x0000000B)

  #define HCHIP_ICR_IC11_SET(CrReg,Val) \
   HCRREG32_SET(CrReg,HFIELD_SHIFT(HCHIP_ICR_IC11,Val))
/*----------------------------------------------------------------------------*\
* (W) HCHIP_ICR_IC12
\*----------------------------------------------------------------------------*/
  #define HCHIP_ICR_IC12_MASK                    (0x00001000)
  #define HCHIP_ICR_IC12_SHIFT                   (0x0000000C)

  #define HCHIP_ICR_IC12_SET(CrReg,Val) \
   HCRREG32_SET(CrReg,HFIELD_SHIFT(HCHIP_ICR_IC12,Val))
   
/*----------------------------------------------------------------------------*\
* (W) HCHIP_ICR_IC13
\*----------------------------------------------------------------------------*/
  #define HCHIP_ICR_IC13_MASK                    (0x00002000)
  #define HCHIP_ICR_IC13_SHIFT                   (0x0000000D)

  #define HCHIP_ICR_IC13_SET(CrReg,Val) \
    HCRREG32_SET(CrReg,HFIELD_SHIFT(HCHIP_ICR_IC13,Val))
    
/*----------------------------------------------------------------------------*\
* (W) HCHIP_ICR_IC14
\*----------------------------------------------------------------------------*/
  #define HCHIP_ICR_IC14_MASK                    (0x00004000)
  #define HCHIP_ICR_IC14_SHIFT                   (0x0000000E)

  #define HCHIP_ICR_IC14_SET(CrReg,Val) \
    HCRREG32_SET(CrReg,HFIELD_SHIFT(HCHIP_ICR_IC14,Val))

/*----------------------------------------------------------------------------*\
* (W) HCHIP_ICR_IC15
\*----------------------------------------------------------------------------*/
  #define HCHIP_ICR_IC15_MASK                    (0x00008000)
  #define HCHIP_ICR_IC15_SHIFT                   (0x0000000F)

  #define HCHIP_ICR_IC15_SET(CrReg,Val) \
    HCRREG32_SET(CrReg,HFIELD_SHIFT(HCHIP_ICR_IC15,Val))

/*----------------------------------------------------------------------------*\
* (W) HCHIP_ICR
\*----------------------------------------------------------------------------*/
  #define HCHIP_ICR_SET(CrReg,Val) HCRREG32_SET(CrReg,Val)

  #define HCHIP_ICR_CFG(CrReg,ic4,ic5,ic6,ic7,ic8,ic9,ic10,ic11,ic12,ic13,ic14,\
  ic15) CrReg=(UINT32)( \
    HCRFIELD_SHIFT(HCHIP_ICR_IC4, ic4) |\
    HCRFIELD_SHIFT(HCHIP_ICR_IC5, ic5) |\
    HCRFIELD_SHIFT(HCHIP_ICR_IC6, ic6) |\
    HCRFIELD_SHIFT(HCHIP_ICR_IC7, ic7) |\
    HCRFIELD_SHIFT(HCHIP_ICR_IC8, ic8) |\
    HCRFIELD_SHIFT(HCHIP_ICR_IC9, ic9) |\
    HCRFIELD_SHIFT(HCHIP_ICR_IC10,ic10)|\
    HCRFIELD_SHIFT(HCHIP_ICR_IC11,ic11)|\
    HCRFIELD_SHIFT(HCHIP_ICR_IC12,ic12)|\
    HCRFIELD_SHIFT(HCHIP_ICR_IC13,ic13)|\
    HCRFIELD_SHIFT(HCHIP_ICR_IC14,ic14)|\
    HCRFIELD_SHIFT(HCHIP_ICR_IC15,ic15) \
  )

/******************************************************************************\
* HCHIP_IER - interrupt enable register
*
* Fields: 
*   (RW)  HCHIP_IER_NMIE
*   (RW)  HCHIP_IER_IE4
*   (RW)  HCHIP_IER_IE5
*   (RW)  HCHIP_IER_IE6
*   (RW)  HCHIP_IER_IE7
*   (RW)  HCHIP_IER_IE8
*   (RW)  HCHIP_IER_IE9
*   (RW)  HCHIP_IER_IE10
*   (RW)  HCHIP_IER_IE11
*   (RW)  HCHIP_IER_IE12
*   (RW)  HCHIP_IER_IE13
*   (RW)  HCHIP_IER_IE14
*   (RW)  HCHIP_IER_IE15
*
\******************************************************************************/
  extern far cregister volatile unsigned int IER;
  #define HCHIP_IER IER

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_IER_NMIE
\*----------------------------------------------------------------------------*/
  #define HCHIP_IER_NMIE_MASK                    (0x00000002)
  #define HCHIP_IER_NMIE_SHIFT                   (0x00000001)
  
  #define HCHIP_IER_NMIE_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_IER_NMIE)

  #define HCHIP_IER_NMIE_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_IER_NMIE,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_IER_IE4
\*----------------------------------------------------------------------------*/
  #define HCHIP_IER_IE4_MASK                     (0x00000010)
  #define HCHIP_IER_IE4_SHIFT                    (0x00000004)
  
  #define HCHIP_IER_IE4_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_IER_IE4)

  #define HCHIP_IER_IE4_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_IER_IE4,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_IER_IE5
\*----------------------------------------------------------------------------*/
  #define HCHIP_IER_IE5_MASK                     (0x00000020)
  #define HCHIP_IER_IE5_SHIFT                    (0x00000005)
  
  #define HCHIP_IER_IE5_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_IER_IE5)

  #define HCHIP_IER_IE5_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_IER_IE5,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_IER_IE6
\*----------------------------------------------------------------------------*/
  #define HCHIP_IER_IE6_MASK                     (0x00000040)
  #define HCHIP_IER_IE6_SHIFT                    (0x00000006)
  
  #define HCHIP_IER_IE6_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_IER_IE6)

  #define HCHIP_IER_IE6_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_IER_IE6,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_IER_IE7
\*----------------------------------------------------------------------------*/
  #define HCHIP_IER_IE7_MASK                     (0x00000080)
  #define HCHIP_IER_IE7_SHIFT                    (0x00000007)
  
  #define HCHIP_IER_IE7_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_IER_IE7)

  #define HCHIP_IER_IE7_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_IER_IE7,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_IER_IE8
\*----------------------------------------------------------------------------*/
  #define HCHIP_IER_IE8_MASK                     (0x00000100)
  #define HCHIP_IER_IE8_SHIFT                    (0x00000008)
  
  #define HCHIP_IER_IE8_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_IER_IE8)

  #define HCHIP_IER_IE8_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_IER_IE8,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_IER_IE9
\*----------------------------------------------------------------------------*/
  #define HCHIP_IER_IE9_MASK                     (0x00000200)
  #define HCHIP_IER_IE9_SHIFT                    (0x00000009)
  
  #define HCHIP_IER_IE9_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_IER_IE9)

  #define HCHIP_IER_IE9_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_IER_IE9,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_IER_IE10
\*----------------------------------------------------------------------------*/
  #define HCHIP_IER_IE10_MASK                    (0x00000400)
  #define HCHIP_IER_IE10_SHIFT                   (0x0000000A)
  
  #define HCHIP_IER_IE10_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_IER_IE10)

  #define HCHIP_IER_IE10_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_IER_IE10,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_IER_IE11
\*----------------------------------------------------------------------------*/
  #define HCHIP_IER_IE11_MASK                    (0x00000800)
  #define HCHIP_IER_IE11_SHIFT                   (0x0000000B)
  
  #define HCHIP_IER_IE11_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_IER_IE11)

  #define HCHIP_IER_IE11_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_IER_IE11,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_IER_IE12
\*----------------------------------------------------------------------------*/
  #define HCHIP_IER_IE12_MASK                    (0x00001000)
  #define HCHIP_IER_IE12_SHIFT                   (0x0000000C)
  
  #define HCHIP_IER_IE12_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_IER_IE12)

  #define HCHIP_IER_IE12_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_IER_IE12,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_IER_IE13
\*----------------------------------------------------------------------------*/
  #define HCHIP_IER_IE13_MASK                    (0x00002000)
  #define HCHIP_IER_IE13_SHIFT                   (0x0000000D)
  
  #define HCHIP_IER_IE13_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_IER_IE13)

  #define HCHIP_IER_IE13_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_IER_IE13,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_IER_IE14
\*----------------------------------------------------------------------------*/
  #define HCHIP_IER_IE14_MASK                    (0x00004000)
  #define HCHIP_IER_IE14_SHIFT                   (0x0000000E)
  
  #define HCHIP_IER_IE14_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_IER_IE14)

  #define HCHIP_IER_IE14_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_IER_IE14,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_IER_IE15
\*----------------------------------------------------------------------------*/
  #define HCHIP_IER_IE15_MASK                    (0x00008000)
  #define HCHIP_IER_IE15_SHIFT                   (0x0000000F)
  
  #define HCHIP_IER_IE15_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_IER_IE15)

  #define HCHIP_IER_IE15_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_IER_IE15,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_IER
\*----------------------------------------------------------------------------*/
  #define HCHIP_IER_GET(CrReg) HCRREG32_GET(CrReg)

  #define HCHIP_IER_SET(CrReg,Val) HCRREG32_SET(CrReg,Val)

  #define HCHIP_IER_CFG(CrReg,nmie,ie4,ie5,ie6,ie7,ie8,ie9,ie10,ie11,ie12,ie13,\
  ie14,ie15) CrReg=(UINT32)( \
      HCRFIELD_SHIFT(HCHIP_IER_NMIE,nmie)|\
      HCRFIELD_SHIFT(HCHIP_IER_IE4, ie4) |\
      HCRFIELD_SHIFT(HCHIP_IER_IE5, ie5) |\
      HCRFIELD_SHIFT(HCHIP_IER_IE6, ie6) |\
      HCRFIELD_SHIFT(HCHIP_IER_IE7, ie7) |\
      HCRFIELD_SHIFT(HCHIP_IER_IE8, ie8) |\
      HCRFIELD_SHIFT(HCHIP_IER_IE9, ie9) |\
      HCRFIELD_SHIFT(HCHIP_IER_IE10,ie10)|\
      HCRFIELD_SHIFT(HCHIP_IER_IE11,ie11)|\
      HCRFIELD_SHIFT(HCHIP_IER_IE12,ie12)|\
      HCRFIELD_SHIFT(HCHIP_IER_IE13,ie13)|\
      HCRFIELD_SHIFT(HCHIP_IER_IE14,ie14)|\
      HCRFIELD_SHIFT(HCHIP_IER_IE15,ie15) \
    )

/******************************************************************************\
* HCHIP_ISTP - interrupt service table pointer
*
* Fields: 
*   (R)   HCHIP_ISTP_HPEINT
*   (RW)  HCHIP_ISTP_ISTB
*
\******************************************************************************/
  extern far cregister volatile unsigned int ISTP;
  #define HCHIP_ISTP ISTP

/*----------------------------------------------------------------------------*\
* (R) HCHIP_ISTP_HPEINT
\*----------------------------------------------------------------------------*/ 
  #define HCHIP_ISTP_HPEINT_MASK                 (0x000003E0)
  #define HCHIP_ISTP_HPEINT_SHIFT                (0x00000005)
  
  #define HCHIP_ISTP_HPEINT_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_ISTP_HPEINT)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_ISTP_ISTB
\*----------------------------------------------------------------------------*/
  #define HCHIP_ISTP_ISTB_MASK                   (0xFFFFFC00)
  #define HCHIP_ISTP_ISTB_SHIFT                  (0x0000000A)

  #define HCHIP_ISTP_ISTB_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_ISTP_ISTB)

  #define HCHIP_ISTP_ISTB_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_ISTP_ISTB,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_ISTP
\*----------------------------------------------------------------------------*/
  #define HCHIP_ISTP_GET(CrReg) HCRREG32_GET(CrReg)

  #define HCHIP_ISTP_SET(CrReg,Val) HCRREG32_SET(CrReg,Val)

  #define HCHIP_ISTP_CFG(CrReg,istb) CrReg=(UINT32)(\
    HCRFIELD_SHIFT(HCHIP_ISTP_ISTB,istb) \
  )

/******************************************************************************\
* HCHIP_IRP - interrrupt return pointer
*
* Fields: 
*   (RW) HCHIP_IRP_IRP
*
\******************************************************************************/
  extern far cregister volatile unsigned int IRP;
  #define HCHIP_IRP IRP

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_IRP_IRP
\*----------------------------------------------------------------------------*/
  #define HCHIP_IRP_IRP_MASK                     (0xFFFFFFFF)
  #define HCHIP_IRP_IRP_SHIFT                    (0x00000000)

  #define HCHIP_IRP_IRP_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_IRP_IRP)

  #define HCHIP_IRP_IRP_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_IRP_IRP,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_IRP
\*----------------------------------------------------------------------------*/
  #define HCHIP_IRP_GET(CrReg) HCRREG32_GET(CrReg)

  #define HCHIP_IRP_SET(CrReg,Val) HCRREG32_SET(CrReg,Val)

  #define HCHIP_IRP_CFG(CrReg,irp) CrReg=(UINT32)( \
    HCRFIELD_SHIFT(HCHIP_IRP_IRP,irp) \
  )

/******************************************************************************\
* HCHIP_NRP - nonmaskable interrupt return pointer
*
* Fields: 
*   (RW) HCHIP_NRP_NRP
*
\******************************************************************************/
  extern far cregister volatile unsigned int NRP;
  #define HCHIP_NRP NRP

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_NRP_NRP
\*----------------------------------------------------------------------------*/
  #define HCHIP_NRP_NRP_MASK                     (0xFFFFFFFF)
  #define HCHIP_NRP_NRP_SHIFT                    (0x00000000)

  #define HCHIP_NRP_NRP_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_NRP_NRP)

  #define HCHIP_NRP_NRP_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_NRP_NRP,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_NRP
\*----------------------------------------------------------------------------*/
  #define HCHIP_NRP_GET(CrReg) HCRREG32_GET(CrReg)

  #define HCHIP_NRP_SET(CrReg,Val) HCRREG32_SET(CrReg,Val)

  #define HCHIP_NRP_CFG(CrReg,nrp) CrReg=(UINT32)( \
    HCRFIELD_SHIFT(HCHIP_NRP_NRP,nrp) \
  )

/******************************************************************************\
* HCHIP_AMR - addressing mode register
*
* Fields: 
*   (RW) HCHIP_AMR_A4MODE
*   (RW) HCHIP_AMR_A5MODE
*   (RW) HCHIP_AMR_A6MODE
*   (RW) HCHIP_AMR_A7MODE
*   (RW) HCHIP_AMR_B4MODE
*   (RW) HCHIP_AMR_B5MODE
*   (RW) HCHIP_AMR_B6MODE
*   (RW) HCHIP_AMR_B7MODE
*   (RW) HCHIP_AMR_BK0
*   (RW) HCHIP_AMR_BK1
*
\******************************************************************************/
  extern far cregister volatile unsigned int AMR;
  #define HCHIP_AMR AMR

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_AMR_A4MODE
\*----------------------------------------------------------------------------*/
  #define HCHIP_AMR_A4MODE_MASK                  (0x00000003)
  #define HCHIP_AMR_A4MODE_SHIFT                 (0x00000000)

  #define HCHIP_AMR_A4MODE_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_AMR_A4MODE)

  #define HCHIP_AMR_A4MODE_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_AMR_A4MODE,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_AMR_A5MODE
\*----------------------------------------------------------------------------*/
  #define HCHIP_AMR_A5MODE_MASK                  (0x0000000C)
  #define HCHIP_AMR_A5MODE_SHIFT                 (0x00000002)

  #define HCHIP_AMR_A5MODE_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_AMR_A5MODE)

  #define HCHIP_AMR_A5MODE_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_AMR_A5MODE,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_AMR_A6MODE
\*----------------------------------------------------------------------------*/
  #define HCHIP_AMR_A6MODE_MASK                  (0x00000030)
  #define HCHIP_AMR_A6MODE_SHIFT                 (0x00000004)

  #define HCHIP_AMR_A6MODE_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_AMR_A6MODE)

  #define HCHIP_AMR_A6MODE_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_AMR_A6MODE,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_AMR_A7MODE
\*----------------------------------------------------------------------------*/
  #define HCHIP_AMR_A7MODE_MASK                  (0x000000C0)
  #define HCHIP_AMR_A7MODE_SHIFT                 (0x00000006)

  #define HCHIP_AMR_A7MODE_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_AMR_A7MODE)

  #define HCHIP_AMR_A7MODE_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_AMR_A7MODE,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_AMR_B4MODE
\*----------------------------------------------------------------------------*/
  #define HCHIP_AMR_B4MODE_MASK                  (0x00000300)
  #define HCHIP_AMR_B4MODE_SHIFT                 (0x00000008)

  #define HCHIP_AMR_B4MODE_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_AMR_B4MODE)

  #define HCHIP_AMR_B4MODE_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_AMR_B4MODE,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_AMR_B5MODE
\*----------------------------------------------------------------------------*/
  #define HCHIP_AMR_B5MODE_MASK                  (0x00000C00)
  #define HCHIP_AMR_B5MODE_SHIFT                 (0x0000000A)

  #define HCHIP_AMR_B5MODE_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_AMR_B5MODE)

  #define HCHIP_AMR_B5MODE_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_AMR_B5MODE,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_AMR_B6MODE
\*----------------------------------------------------------------------------*/
  #define HCHIP_AMR_B6MODE_MASK                  (0x00003000)
  #define HCHIP_AMR_B6MODE_SHIFT                 (0x0000000C)

  #define HCHIP_AMR_B6MODE_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_AMR_B6MODE)

  #define HCHIP_AMR_B6MODE_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_AMR_B6MODE,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_AMR_B7MODE
\*----------------------------------------------------------------------------*/
  #define HCHIP_AMR_B7MODE_MASK                  (0x0000C000)
  #define HCHIP_AMR_B7MODE_SHIFT                 (0x0000000E)

  #define HCHIP_AMR_B7MODE_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_AMR_B7MODE)

  #define HCHIP_AMR_B7MODE_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_AMR_B7MODE,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_AMR_BK0
\*----------------------------------------------------------------------------*/
  #define HCHIP_AMR_BK0_MASK                     (0x001F0000)
  #define HCHIP_AMR_BK0_SHIFT                    (0x00000010)

  #define HCHIP_AMR_BK0_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_AMR_BK0)

  #define HCHIP_AMR_BK0_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_AMR_BK0,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_AMR_BK1
\*----------------------------------------------------------------------------*/
  #define HCHIP_AMR_BK1_MASK                     (0x001F0000)
  #define HCHIP_AMR_BK1_SHIFT                    (0x00000010)

  #define HCHIP_AMR_BK1_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_AMR_BK1)

  #define HCHIP_AMR_BK1_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_AMR_BK1,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_AMR
\*----------------------------------------------------------------------------*/
  #define HCHIP_AMR_GET(CrReg) HCRREG32_GET(CrReg)

  #define HCHIP_AMR_SET(CrReg,Val) HCRREG32_SET(CrReg,Val)

  #define HCHIP_AMR_CFG(CrReg,a4mode,a5mode,a6mode,a7mode,b4mode,b5mode,b6mode,\
  b7mode,bk0,bk1) CrReg=(UINT32)( \
    HCRFIELD_SHIFT(HCHIP_AMR_A4MODE,a4mode)| \
    HCRFIELD_SHIFT(HCHIP_AMR_A5MODE,a5mode)| \
    HCRFIELD_SHIFT(HCHIP_AMR_A6MODE,a6mode)| \
    HCRFIELD_SHIFT(HCHIP_AMR_A7MODE,a7mode)| \
    HCRFIELD_SHIFT(HCHIP_AMR_B4MODE,b4mode)| \
    HCRFIELD_SHIFT(HCHIP_AMR_B5MODE,b5mode)| \
    HCRFIELD_SHIFT(HCHIP_AMR_B6MODE,b6mode)| \
    HCRFIELD_SHIFT(HCHIP_AMR_B7MODE,b7mode)| \
    HCRFIELD_SHIFT(HCHIP_AMR_BK0,bk0)| \
    HCRFIELD_SHIFT(HCHIP_AMR_BK1,bk1) \
  )

#if (FPU_SUPPORT)
/******************************************************************************\
* HCHIP_FADCR - floating-point adder config register (1)
*
* (1) only supported on devices with floating point unit
*
* Fields: 
*   (RW) HCHIP_FADCR_L1NAN1
*   (RW) HCHIP_FADCR_L1NAN2
*   (RW) HCHIP_FADCR_L1DEN1
*   (RW) HCHIP_FADCR_L1DEN2
*   (RW) HCHIP_FADCR_L1INVAL
*   (RW) HCHIP_FADCR_L1INFO
*   (RW) HCHIP_FADCR_L1OVER
*   (RW) HCHIP_FADCR_L1INEX
*   (RW) HCHIP_FADCR_L1UNDER
*   (RW) HCHIP_FADCR_L1RMODE
*   (RW) HCHIP_FADCR_L2NAN1
*   (RW) HCHIP_FADCR_L2NAN2
*   (RW) HCHIP_FADCR_L2DEN1
*   (RW) HCHIP_FADCR_L2DEN2
*   (RW) HCHIP_FADCR_L2INVAL
*   (RW) HCHIP_FADCR_L2INFO
*   (RW) HCHIP_FADCR_L2OVER
*   (RW) HCHIP_FADCR_L2INEX
*   (RW) HCHIP_FADCR_L2UNDER
*   (RW) HCHIP_FADCR_L2RMODE
*
\******************************************************************************/
  extern far cregister volatile unsigned int FADCR;
  #define HCHIP_FADCR FADCR

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FADCR_L1NAN1
\*----------------------------------------------------------------------------*/
  #define HCHIP_FADCR_L1NAN1_MASK               (0x00000001)
  #define HCHIP_FADCR_L1NAN1_SHIFT              (0x00000000)

  #define HCHIP_FADCR_L1NAN1_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FADCR_L1NAN1)

  #define HCHIP_FADCR_L1NAN1_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FADCR_L1NAN1,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FADCR_L1NAN2
\*----------------------------------------------------------------------------*/
  #define HCHIP_FADCR_L1NAN2_MASK               (0x00000002)
  #define HCHIP_FADCR_L1NAN2_SHIFT              (0x00000001)

  #define HCHIP_FADCR_L1NAN2_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FADCR_L1NAN2)

  #define HCHIP_FADCR_L1NAN2_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FADCR_L1NAN2,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FADCR_L1DEN1
\*----------------------------------------------------------------------------*/
  #define HCHIP_FADCR_L1DEN1_MASK               (0x00000004)
  #define HCHIP_FADCR_L1DEN1_SHIFT              (0x00000002)

  #define HCHIP_FADCR_L1DEN1_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FADCR_L1DEN1)

  #define HCHIP_FADCR_L1DEN1_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FADCR_L1DEN1,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FADCR_L1DEN2
\*----------------------------------------------------------------------------*/
  #define HCHIP_FADCR_L1DEN2_MASK               (0x00000008)
  #define HCHIP_FADCR_L1DEN2_SHIFT              (0x00000003)

  #define HCHIP_FADCR_L1DEN2_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FADCR_L1DEN2)

  #define HCHIP_FADCR_L1DEN2_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FADCR_L1DEN2,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FADCR_L1INVAL
\*----------------------------------------------------------------------------*/
  #define HCHIP_FADCR_L1INVAL_MASK              (0x00000010)
  #define HCHIP_FADCR_L1INVAL_SHIFT             (0x00000004)

  #define HCHIP_FADCR_L1INVAL_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FADCR_L1INVAL)

  #define HCHIP_FADCR_L1INVAL_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FADCR_L1INVAL,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FADCR_L1INFO
\*----------------------------------------------------------------------------*/
  #define HCHIP_FADCR_L1INFO_MASK               (0x00000020)
  #define HCHIP_FADCR_L1INFO_SHIFT              (0x00000005)

  #define HCHIP_FADCR_L1INFO_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FADCR_L1INFO)

  #define HCHIP_FADCR_L1INFO_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FADCR_L1INFO,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FADCR_L1OVER
\*----------------------------------------------------------------------------*/
  #define HCHIP_FADCR_L1OVER_MASK               (0x00000040)
  #define HCHIP_FADCR_L1OVER_SHIFT              (0x00000006)

  #define HCHIP_FADCR_L1OVER_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FADCR_L1OVER)

  #define HCHIP_FADCR_L1OVER_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FADCR_L1OVER,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FADCR_L1INEX
\*----------------------------------------------------------------------------*/
  #define HCHIP_FADCR_L1INEX_MASK               (0x00000080)
  #define HCHIP_FADCR_L1INEX_SHIFT              (0x00000007)

  #define HCHIP_FADCR_L1INEX_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FADCR_L1INEX)

  #define HCHIP_FADCR_L1INEX_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FADCR_L1INEX,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FADCR_L1UNDER
\*----------------------------------------------------------------------------*/
  #define HCHIP_FADCR_L1UNDER_MASK              (0x00000100)
  #define HCHIP_FADCR_L1UNDER_SHIFT             (0x00000008)

  #define HCHIP_FADCR_L1UNDER_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FADCR_L1UNDER)

  #define HCHIP_FADCR_L1UNDER_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FADCR_L1UNDER,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FADCR_L1RMODE
\*----------------------------------------------------------------------------*/
  #define HCHIP_FADCR_L1RMODE_MASK              (0x00000600)
  #define HCHIP_FADCR_L1RMODE_SHIFT             (0x00000009)

  #define HCHIP_FADCR_L1RMODE_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FADCR_L1RMODE)

  #define HCHIP_FADCR_L1RMODE_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FADCR_L1RMODE,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FADCR_L2NAN1
\*----------------------------------------------------------------------------*/
  #define HCHIP_FADCR_L2NAN1_MASK               (0x00010000)
  #define HCHIP_FADCR_L2NAN1_SHIFT              (0x00000010)

  #define HCHIP_FADCR_L2NAN1_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FADCR_L2NAN1)

  #define HCHIP_FADCR_L2NAN1_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FADCR_L2NAN1,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FADCR_L2NAN2
\*----------------------------------------------------------------------------*/
  #define HCHIP_FADCR_L2NAN2_MASK               (0x00020000)
  #define HCHIP_FADCR_L2NAN2_SHIFT              (0x00000011)

  #define HCHIP_FADCR_L2NAN2_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FADCR_L2NAN2)

  #define HCHIP_FADCR_L2NAN2_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FADCR_L2NAN2,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FADCR_L2DEN1
\*----------------------------------------------------------------------------*/
  #define HCHIP_FADCR_L2DEN1_MASK               (0x00040000)
  #define HCHIP_FADCR_L2DEN1_SHIFT              (0x00000012)

  #define HCHIP_FADCR_L2DEN1_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FADCR_L2DEN1)

  #define HCHIP_FADCR_L2DEN1_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FADCR_L2DEN1,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FADCR_L2DEN2
\*----------------------------------------------------------------------------*/
  #define HCHIP_FADCR_L2DEN2_MASK               (0x00080000)
  #define HCHIP_FADCR_L2DEN2_SHIFT              (0x00000013)

  #define HCHIP_FADCR_L2DEN2_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FADCR_L2DEN2)

  #define HCHIP_FADCR_L2DEN2_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FADCR_L2DEN2,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FADCR_L2INVAL
\*----------------------------------------------------------------------------*/
  #define HCHIP_FADCR_L2INVAL_MASK              (0x00100000)
  #define HCHIP_FADCR_L2INVAL_SHIFT             (0x00000014)

  #define HCHIP_FADCR_L2INVAL_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FADCR_L2INVAL)

  #define HCHIP_FADCR_L2INVAL_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FADCR_L2INVAL,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FADCR_L2INFO
\*----------------------------------------------------------------------------*/
  #define HCHIP_FADCR_L2INFO_MASK               (0x00200000)
  #define HCHIP_FADCR_L2INFO_SHIFT              (0x00000015)

  #define HCHIP_FADCR_L2INFO_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FADCR_L2INFO)

  #define HCHIP_FADCR_L2INFO_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FADCR_L2INFO,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FADCR_L2OVER
\*----------------------------------------------------------------------------*/
  #define HCHIP_FADCR_L2OVER_MASK               (0x00400000)
  #define HCHIP_FADCR_L2OVER_SHIFT              (0x00000016)

  #define HCHIP_FADCR_L2OVER_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FADCR_L2OVER)

  #define HCHIP_FADCR_L2OVER_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FADCR_L2OVER,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FADCR_L2INEX
\*----------------------------------------------------------------------------*/
  #define HCHIP_FADCR_L2INEX_MASK               (0x00800000)
  #define HCHIP_FADCR_L2INEX_SHIFT              (0x00000017)

  #define HCHIP_FADCR_L2INEX_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FADCR_L2INEX)

  #define HCHIP_FADCR_L2INEX_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FADCR_L2INEX,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FADCR_L2UNDER
\*----------------------------------------------------------------------------*/
  #define HCHIP_FADCR_L2UNDER_MASK              (0x01000000)
  #define HCHIP_FADCR_L2UNDER_SHIFT             (0x00000018)

  #define HCHIP_FADCR_L2UNDER_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FADCR_L2UNDER)

  #define HCHIP_FADCR_L2UNDER_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FADCR_L2UNDER,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FADCR_L2RMODE
\*----------------------------------------------------------------------------*/
  #define HCHIP_FADCR_L2RMODE_MASK              (0x06000000)
  #define HCHIP_FADCR_L2RMODE_SHIFT             (0x00000019)

  #define HCHIP_FADCR_L2RMODE_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FADCR_L2RMODE)

  #define HCHIP_FADCR_L2RMODE_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FADCR_L2RMODE,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FADCR
\*----------------------------------------------------------------------------*/
  #define HCHIP_FADCR_GET(CrReg) HCRREG32_GET(CrReg)

  #define HCHIP_FADCR_SET(CrReg,Val) HCRREG32_SET(CrReg,Val)

  #define HCHIP_FADCR_CFG(CrReg,l1nan1,l1nan2,l1den1,l1den2,l1inval,l1info,\
  l1over,l1inex,l1under,l1rmode,l2nan1,l2nan2,l2den1,l2den2,l2inval,l2info,\
  l2over,l2inex,l2under,l2rmode) CrReg=(UINT32)( \
    HCRFIELD_SHIFT(HCHIP_FADCR_L1NAN1, l1nan1) |\
    HCRFIELD_SHIFT(HCHIP_FADCR_L1NAN2, l1nan2) |\
    HCRFIELD_SHIFT(HCHIP_FADCR_L1DEN1, l1den1) |\
    HCRFIELD_SHIFT(HCHIP_FADCR_L1DEN2, l1den2) |\
    HCRFIELD_SHIFT(HCHIP_FADCR_L1INVAL,l1inval)|\
    HCRFIELD_SHIFT(HCHIP_FADCR_L1INFO, l1info) |\
    HCRFIELD_SHIFT(HCHIP_FADCR_L1OVER, l1over) |\
    HCRFIELD_SHIFT(HCHIP_FADCR_L1INEX, l1inex) |\
    HCRFIELD_SHIFT(HCHIP_FADCR_L1UNDER,l1under)|\
    HCRFIELD_SHIFT(HCHIP_FADCR_L1RMODE,l1rmode)|\
    HCRFIELD_SHIFT(HCHIP_FADCR_L2NAN1, l2nan1) |\
    HCRFIELD_SHIFT(HCHIP_FADCR_L2NAN2, l2nan2) |\
    HCRFIELD_SHIFT(HCHIP_FADCR_L2DEN1, l2den1) |\
    HCRFIELD_SHIFT(HCHIP_FADCR_L2DEN2, l2den2) |\
    HCRFIELD_SHIFT(HCHIP_FADCR_L2INVAL,l2inval)|\
    HCRFIELD_SHIFT(HCHIP_FADCR_L2INFO, l2info) |\
    HCRFIELD_SHIFT(HCHIP_FADCR_L2OVER, l2over) |\
    HCRFIELD_SHIFT(HCHIP_FADCR_L2INEX, l2inex) |\
    HCRFIELD_SHIFT(HCHIP_FADCR_L2UNDER,l2under)|\
    HCRFIELD_SHIFT(HCHIP_FADCR_L2RMODE,l2rmode) \
  )
#endif /* FPU_SUPPORT */

#if (FPU_SUPPORT)
/******************************************************************************\
* HCHIP_FAUCR - floating-point auxiliary config register (1)
*
* (1) only supported on devices with floating point unit
*
* Fields: 
*   (RW) HCHIP_FAUCR_S1NAN1
*   (RW) HCHIP_FAUCR_S1NAN2
*   (RW) HCHIP_FAUCR_S1DEN1
*   (RW) HCHIP_FAUCR_S1DEN2
*   (RW) HCHIP_FAUCR_S1INVAL
*   (RW) HCHIP_FAUCR_S1INFO
*   (RW) HCHIP_FAUCR_S1OVER
*   (RW) HCHIP_FAUCR_S1INEX
*   (RW) HCHIP_FAUCR_S1UNDER
*   (RW) HCHIP_FAUCR_S1UNORD
*   (RW) HCHIP_FAUCR_S1DIV0
*   (RW) HCHIP_FAUCR_S2NAN1
*   (RW) HCHIP_FAUCR_S2NAN2
*   (RW) HCHIP_FAUCR_S2DEN1
*   (RW) HCHIP_FAUCR_S2DEN2
*   (RW) HCHIP_FAUCR_S2INVAL
*   (RW) HCHIP_FAUCR_S2INFO
*   (RW) HCHIP_FAUCR_S2OVER
*   (RW) HCHIP_FAUCR_S2INEX
*   (RW) HCHIP_FAUCR_S2UNDER
*   (RW) HCHIP_FAUCR_S2UNORD
*   (RW) HCHIP_FAUCR_S2DIV0
*
\******************************************************************************/
  extern far cregister volatile unsigned int FAUCR;
  #define HCHIP_FAUCR FAUCR
  
/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FAUCR_S1NAN1
\*----------------------------------------------------------------------------*/
  #define HCHIP_FAUCR_S1NAN1_MASK               (0x00000001)
  #define HCHIP_FAUCR_S1NAN1_SHIFT              (0x00000000)

  #define HCHIP_FAUCR_S1NAN1_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FAUCR_S1NAN1)

  #define HCHIP_FAUCR_S1NAN1_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FAUCR_S1NAN1,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FAUCR_S1NAN2
\*----------------------------------------------------------------------------*/
  #define HCHIP_FAUCR_S1NAN2_MASK               (0x00000002)
  #define HCHIP_FAUCR_S1NAN2_SHIFT              (0x00000001)

  #define HCHIP_FAUCR_S1NAN2_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FAUCR_S1NAN2)

  #define HCHIP_FAUCR_S1NAN2_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FAUCR_S1NAN2,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FAUCR_S1DEN1
\*----------------------------------------------------------------------------*/
  #define HCHIP_FAUCR_S1DEN1_MASK               (0x00000004)
  #define HCHIP_FAUCR_S1DEN1_SHIFT              (0x00000002)

  #define HCHIP_FAUCR_S1DEN1_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FAUCR_S1DEN1)

  #define HCHIP_FAUCR_S1DEN1_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FAUCR_S1DEN1,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FAUCR_S1DEN2
\*----------------------------------------------------------------------------*/
  #define HCHIP_FAUCR_S1DEN2_MASK               (0x00000008)
  #define HCHIP_FAUCR_S1DEN2_SHIFT              (0x00000003)

  #define HCHIP_FAUCR_S1DEN2_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FAUCR_S1DEN2)

  #define HCHIP_FAUCR_S1DEN2_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FAUCR_S1DEN2,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FAUCR_S1INVAL
\*----------------------------------------------------------------------------*/
  #define HCHIP_FAUCR_S1INVAL_MASK              (0x00000010)
  #define HCHIP_FAUCR_S1INVAL_SHIFT             (0x00000004)

  #define HCHIP_FAUCR_S1INVAL_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FAUCR_S1INVAL)

  #define HCHIP_FAUCR_S1INVAL_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FAUCR_S1INVAL,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FAUCR_S1INFO
\*----------------------------------------------------------------------------*/
  #define HCHIP_FAUCR_S1INFO_MASK               (0x00000020)
  #define HCHIP_FAUCR_S1INFO_SHIFT              (0x00000005)

  #define HCHIP_FAUCR_S1INFO_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FAUCR_S1INFO)

  #define HCHIP_FAUCR_S1INFO_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FAUCR_S1INFO,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FAUCR_S1OVER
\*----------------------------------------------------------------------------*/
  #define HCHIP_FAUCR_S1OVER_MASK               (0x00000040)
  #define HCHIP_FAUCR_S1OVER_SHIFT              (0x00000006)

  #define HCHIP_FAUCR_S1OVER_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FAUCR_S1OVER)

  #define HCHIP_FAUCR_S1OVER_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FAUCR_S1OVER,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FAUCR_S1INEX
\*----------------------------------------------------------------------------*/
  #define HCHIP_FAUCR_S1INEX_MASK               (0x00000080)
  #define HCHIP_FAUCR_S1INEX_SHIFT              (0x00000007)

  #define HCHIP_FAUCR_S1INEX_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FAUCR_S1INEX)

  #define HCHIP_FAUCR_S1INEX_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FAUCR_S1INEX,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FAUCR_S1UNDER
\*----------------------------------------------------------------------------*/
  #define HCHIP_FAUCR_S1UNDER_MASK              (0x00000100)
  #define HCHIP_FAUCR_S1UNDER_SHIFT             (0x00000008)

  #define HCHIP_FAUCR_S1UNDER_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FAUCR_S1UNDER)

  #define HCHIP_FAUCR_S1UNDER_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FAUCR_S1UNDER,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FAUCR_S1UNORD
\*----------------------------------------------------------------------------*/
  #define HCHIP_FAUCR_S1UNORD_MASK              (0x00000200)
  #define HCHIP_FAUCR_S1UNORD_SHIFT             (0x00000009)

  #define HCHIP_FAUCR_S1UNORD_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FAUCR_S1UNORD)

  #define HCHIP_FAUCR_S1UNORD_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FAUCR_S1UNORD,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FAUCR_S1DIV0
\*----------------------------------------------------------------------------*/
  #define HCHIP_FAUCR_S1DIV0_MASK               (0x00000400)
  #define HCHIP_FAUCR_S1DIV0_SHIFT              (0x0000000A)

  #define HCHIP_FAUCR_S1DIV0_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FAUCR_S1DIV0)

  #define HCHIP_FAUCR_S1DIV0_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FAUCR_S1DIV0,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FAUCR_S2NAN1
\*----------------------------------------------------------------------------*/
  #define HCHIP_FAUCR_S2NAN1_MASK               (0x00010000)
  #define HCHIP_FAUCR_S2NAN1_SHIFT              (0x00000010)

  #define HCHIP_FAUCR_S2NAN1_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FAUCR_S2NAN1)

  #define HCHIP_FAUCR_S2NAN1_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FAUCR_S2NAN1,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FAUCR_S2NAN2
\*----------------------------------------------------------------------------*/
  #define HCHIP_FAUCR_S2NAN2_MASK               (0x00020000)
  #define HCHIP_FAUCR_S2NAN2_SHIFT              (0x00000011)

  #define HCHIP_FAUCR_S2NAN2_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FAUCR_S2NAN2)

  #define HCHIP_FAUCR_S2NAN2_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FAUCR_S2NAN2,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FAUCR_S2DEN1
\*----------------------------------------------------------------------------*/
  #define HCHIP_FAUCR_S2DEN1_MASK               (0x00040000)
  #define HCHIP_FAUCR_S2DEN1_SHIFT              (0x00000012)

  #define HCHIP_FAUCR_S2DEN1_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FAUCR_S2DEN1)

  #define HCHIP_FAUCR_S2DEN1_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FAUCR_S2DEN1,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FAUCR_S2DEN2
\*----------------------------------------------------------------------------*/
  #define HCHIP_FAUCR_S2DEN2_MASK               (0x00080000)
  #define HCHIP_FAUCR_S2DEN2_SHIFT              (0x00000013)

  #define HCHIP_FAUCR_S2DEN2_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FAUCR_S2DEN2)

  #define HCHIP_FAUCR_S2DEN2_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FAUCR_S2DEN2,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FAUCR_S2INVAL
\*----------------------------------------------------------------------------*/
  #define HCHIP_FAUCR_S2INVAL_MASK              (0x00100000)
  #define HCHIP_FAUCR_S2INVAL_SHIFT             (0x00000014)

  #define HCHIP_FAUCR_S2INVAL_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FAUCR_S2INVAL)

  #define HCHIP_FAUCR_S2INVAL_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FAUCR_S2INVAL,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FAUCR_S2INFO
\*----------------------------------------------------------------------------*/
  #define HCHIP_FAUCR_S2INFO_MASK               (0x00200000)
  #define HCHIP_FAUCR_S2INFO_SHIFT              (0x00000015)

  #define HCHIP_FAUCR_S2INFO_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FAUCR_S2INFO)

  #define HCHIP_FAUCR_S2INFO_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FAUCR_S2INFO,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FAUCR_S2OVER
\*----------------------------------------------------------------------------*/
  #define HCHIP_FAUCR_S2OVER_MASK               (0x00400000)
  #define HCHIP_FAUCR_S2OVER_SHIFT              (0x00000016)

  #define HCHIP_FAUCR_S2OVER_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FAUCR_S2OVER)

  #define HCHIP_FAUCR_S2OVER_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FAUCR_S2OVER,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FAUCR_S2INEX
\*----------------------------------------------------------------------------*/
  #define HCHIP_FAUCR_S2INEX_MASK               (0x00800000)
  #define HCHIP_FAUCR_S2INEX_SHIFT              (0x00000017)

  #define HCHIP_FAUCR_S2INEX_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FAUCR_S2INEX)

  #define HCHIP_FAUCR_S2INEX_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FAUCR_S2INEX,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FAUCR_S2UNDER
\*----------------------------------------------------------------------------*/
  #define HCHIP_FAUCR_S2UNDER_MASK              (0x01000000)
  #define HCHIP_FAUCR_S2UNDER_SHIFT             (0x00000018)

  #define HCHIP_FAUCR_S2UNDER_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FAUCR_S2UNDER)

  #define HCHIP_FAUCR_S2UNDER_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FAUCR_S2UNDER,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FAUCR_S2UNORD
\*----------------------------------------------------------------------------*/
  #define HCHIP_FAUCR_S2UNORD_MASK              (0x02000000)
  #define HCHIP_FAUCR_S2UNORD_SHIFT             (0x00000019)

  #define HCHIP_FAUCR_S2UNORD_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FAUCR_S2UNORD)

  #define HCHIP_FAUCR_S2UNORD_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FAUCR_S2UNORD,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FAUCR_S2DIV0
\*----------------------------------------------------------------------------*/
  #define HCHIP_FAUCR_S2DIV0_MASK               (0x04000000)
  #define HCHIP_FAUCR_S2DIV0_SHIFT              (0x0000001A)

  #define HCHIP_FAUCR_S2DIV0_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FAUCR_S2DIV0)

  #define HCHIP_FAUCR_S2DIV0_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FAUCR_S2DIV0,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FADCR
\*----------------------------------------------------------------------------*/
  #define HCHIP_FAUCR_GET(CrReg) HCRREG32_GET(CrReg)

  #define HCHIP_FAUCR_SET(CrReg,Val) HCRREG32_SET(CrReg,Val)

  #define HCHIP_FAUCR_CFG(CrReg,s1nan1,s1nan2,s1den1,s1den2,s1inval,s1info,\
  s1over,s1inex,s1under,s1unord,s1div0,s2nan1,s2nan2,s2den1,s2den2,s2inval,\
  s2info,s2over,s2inex,s2under,s2unord,s2div0) CrReg=(UINT32)( \
    HCRFIELD_SHIFT(HCHIP_FAUCR_S1NAN1, s1nan1) |\
    HCRFIELD_SHIFT(HCHIP_FAUCR_S1NAN2, s1nan2) |\
    HCRFIELD_SHIFT(HCHIP_FAUCR_S1DEN1, s1den1) |\
    HCRFIELD_SHIFT(HCHIP_FAUCR_S1DEN2, s1den2) |\
    HCRFIELD_SHIFT(HCHIP_FAUCR_S1INVAL,s1inval)|\
    HCRFIELD_SHIFT(HCHIP_FAUCR_S1INFO, s1info) |\
    HCRFIELD_SHIFT(HCHIP_FAUCR_S1OVER, s1over) |\
    HCRFIELD_SHIFT(HCHIP_FAUCR_S1INEX, s1inex) |\
    HCRFIELD_SHIFT(HCHIP_FAUCR_S1UNDER,s1under)|\
    HCRFIELD_SHIFT(HCHIP_FAUCR_S1UNORD,s1unord)|\
    HCRFIELD_SHIFT(HCHIP_FAUCR_S1DIV0, s1div0) |\
    HCRFIELD_SHIFT(HCHIP_FAUCR_S2NAN1, s2nan1) |\
    HCRFIELD_SHIFT(HCHIP_FAUCR_S2NAN2, s2nan2) |\
    HCRFIELD_SHIFT(HCHIP_FAUCR_S2DEN1, s2den1) |\
    HCRFIELD_SHIFT(HCHIP_FAUCR_S2DEN2, s2den2) |\
    HCRFIELD_SHIFT(HCHIP_FAUCR_S2INVAL,s2inval)|\
    HCRFIELD_SHIFT(HCHIP_FAUCR_S2INFO, s2info) |\
    HCRFIELD_SHIFT(HCHIP_FAUCR_S2OVER, s2over) |\
    HCRFIELD_SHIFT(HCHIP_FAUCR_S2INEX, s2inex) |\
    HCRFIELD_SHIFT(HCHIP_FAUCR_S2UNDER,s2under)|\
    HCRFIELD_SHIFT(HCHIP_FAUCR_S2UNORD,s2unord)|\
    HCRFIELD_SHIFT(HCHIP_FAUCR_S2DIV0, s2div0)  \
  )
#endif /* FPU_SUPPORT */

#if (FPU_SUPPORT)
/******************************************************************************\
* HCHIP_FMCR - floating-point multiplier config register (1)
*
* (1) only supported on devices with floating point unit
*
* Fields: 
*   (RW) HCHIP_FMCR_M1NAN1
*   (RW) HCHIP_FMCR_M1NAN2
*   (RW) HCHIP_FMCR_M1DEN1
*   (RW) HCHIP_FMCR_M1DEN2
*   (RW) HCHIP_FMCR_M1INVAL
*   (RW) HCHIP_FMCR_M1INFO
*   (RW) HCHIP_FMCR_M1OVER
*   (RW) HCHIP_FMCR_M1INEX
*   (RW) HCHIP_FMCR_M1UNDER
*   (RW) HCHIP_FMCR_M1RMODE
*   (RW) HCHIP_FMCR_M2NAN1
*   (RW) HCHIP_FMCR_M2NAN2
*   (RW) HCHIP_FMCR_M2DEN1
*   (RW) HCHIP_FMCR_M2DEN2
*   (RW) HCHIP_FMCR_M2INVAL
*   (RW) HCHIP_FMCR_M2INFO
*   (RW) HCHIP_FMCR_M2OVER
*   (RW) HCHIP_FMCR_M2INEX
*   (RW) HCHIP_FMCR_M2UNDER
*   (RW) HCHIP_FMCR_M2RMODE
*
\******************************************************************************/
  extern far cregister volatile unsigned int FMCR;
  #define HCHIP_FMCR FMCR
  
/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FMCR_M1NAN1
\*----------------------------------------------------------------------------*/
  #define HCHIP_FMCR_M1NAN1_MASK                (0x00000001)
  #define HCHIP_FMCR_M1NAN1_SHIFT               (0x00000000)

  #define HCHIP_FMCR_M1NAN1_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FMCR_M1NAN1)

  #define HCHIP_FMCR_M1NAN1_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FMCR_M1NAN1,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FMCR_M1NAN2
\*----------------------------------------------------------------------------*/
  #define HCHIP_FMCR_M1NAN2_MASK                (0x00000002)
  #define HCHIP_FMCR_M1NAN2_SHIFT               (0x00000001)

  #define HCHIP_FMCR_M1NAN2_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FMCR_M1NAN2)

  #define HCHIP_FMCR_M1NAN2_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FMCR_M1NAN2,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FMCR_M1DEN1
\*----------------------------------------------------------------------------*/
  #define HCHIP_FMCR_M1DEN1_MASK                (0x00000004)
  #define HCHIP_FMCR_M1DEN1_SHIFT               (0x00000002)

  #define HCHIP_FMCR_M1DEN1_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FMCR_M1DEN1)

  #define HCHIP_FMCR_M1DEN1_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FMCR_M1DEN1,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FMCR_M1DEN2
\*----------------------------------------------------------------------------*/
  #define HCHIP_FMCR_M1DEN2_MASK                (0x00000008)
  #define HCHIP_FMCR_M1DEN2_SHIFT               (0x00000003)

  #define HCHIP_FMCR_M1DEN2_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FMCR_M1DEN2)

  #define HCHIP_FMCR_M1DEN2_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FMCR_M1DEN2,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FMCR_M1INVAL
\*----------------------------------------------------------------------------*/
  #define HCHIP_FMCR_M1INVAL_MASK               (0x00000010)
  #define HCHIP_FMCR_M1INVAL_SHIFT              (0x00000004)

  #define HCHIP_FMCR_M1INVAL_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FMCR_M1INVAL)

  #define HCHIP_FMCR_M1INVAL_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FMCR_M1INVAL,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FMCR_M1INFO
\*----------------------------------------------------------------------------*/
  #define HCHIP_FMCR_M1INFO_MASK                (0x00000020)
  #define HCHIP_FMCR_M1INFO_SHIFT               (0x00000005)

  #define HCHIP_FMCR_M1INFO_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FMCR_M1INFO)

  #define HCHIP_FMCR_M1INFO_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FMCR_M1INFO,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FMCR_M1OVER
\*----------------------------------------------------------------------------*/
  #define HCHIP_FMCR_M1OVER_MASK                (0x00000040)
  #define HCHIP_FMCR_M1OVER_SHIFT               (0x00000006)

  #define HCHIP_FMCR_M1OVER_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FMCR_M1OVER)

  #define HCHIP_FMCR_M1OVER_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FMCR_M1OVER,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FMCR_M1INEX
\*----------------------------------------------------------------------------*/
  #define HCHIP_FMCR_M1INEX_MASK                (0x00000080)
  #define HCHIP_FMCR_M1INEX_SHIFT               (0x00000007)

  #define HCHIP_FMCR_M1INEX_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FMCR_M1INEX)

  #define HCHIP_FMCR_M1INEX_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FMCR_M1INEX,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FMCR_M1UNDER
\*----------------------------------------------------------------------------*/
  #define HCHIP_FMCR_M1UNDER_MASK               (0x00000100)
  #define HCHIP_FMCR_M1UNDER_SHIFT              (0x00000008)

  #define HCHIP_FMCR_M1UNDER_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FMCR_M1UNDER)

  #define HCHIP_FMCR_M1UNDER_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FMCR_M1UNDER,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FMCR_M1RMODE
\*----------------------------------------------------------------------------*/
  #define HCHIP_FMCR_M1RMODE_MASK               (0x00000600)
  #define HCHIP_FMCR_M1RMODE_SHIFT              (0x00000009)

  #define HCHIP_FMCR_M1RMODE_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FMCR_M1RMODE)

  #define HCHIP_FMCR_M1RMODE_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FMCR_M1RMODE,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FMCR_M2NAN1
\*----------------------------------------------------------------------------*/
  #define HCHIP_FMCR_M2NAN1_MASK                (0x00010000)
  #define HCHIP_FMCR_M2NAN1_SHIFT               (0x00000010)

  #define HCHIP_FMCR_M2NAN1_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FMCR_M2NAN1)

  #define HCHIP_FMCR_M2NAN1_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FMCR_M2NAN1,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FMCR_M2NAN2
\*----------------------------------------------------------------------------*/
  #define HCHIP_FMCR_M2NAN2_MASK                (0x00020000)
  #define HCHIP_FMCR_M2NAN2_SHIFT               (0x00000011)

  #define HCHIP_FMCR_M2NAN2_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FMCR_M2NAN2)

  #define HCHIP_FMCR_M2NAN2_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FMCR_M2NAN2,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FMCR_M2DEN1
\*----------------------------------------------------------------------------*/
  #define HCHIP_FMCR_M2DEN1_MASK                (0x00040000)
  #define HCHIP_FMCR_M2DEN1_SHIFT               (0x00000012)

  #define HCHIP_FMCR_M2DEN1_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FMCR_M2DEN1)

  #define HCHIP_FMCR_M2DEN1_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FMCR_M2DEN1,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FMCR_M2DEN2
\*----------------------------------------------------------------------------*/
  #define HCHIP_FMCR_M2DEN2_MASK                (0x00080000)
  #define HCHIP_FMCR_M2DEN2_SHIFT               (0x00000013)

  #define HCHIP_FMCR_M2DEN2_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FMCR_M2DEN2)

  #define HCHIP_FMCR_M2DEN2_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FMCR_M2DEN2,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FMCR_M2INVAL
\*----------------------------------------------------------------------------*/
  #define HCHIP_FMCR_M2INVAL_MASK               (0x00100000)
  #define HCHIP_FMCR_M2INVAL_SHIFT              (0x00000014)

  #define HCHIP_FMCR_M2INVAL_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FMCR_M2INVAL)

  #define HCHIP_FMCR_M2INVAL_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FMCR_M2INVAL,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FMCR_M2INFO
\*----------------------------------------------------------------------------*/
  #define HCHIP_FMCR_M2INFO_MASK                (0x00200000)
  #define HCHIP_FMCR_M2INFO_SHIFT               (0x00000015)

  #define HCHIP_FMCR_M2INFO_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FMCR_M2INFO)

  #define HCHIP_FMCR_M2INFO_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FMCR_M2INFO,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FMCR_M2OVER
\*----------------------------------------------------------------------------*/
  #define HCHIP_FMCR_M2OVER_MASK                (0x00400000)
  #define HCHIP_FMCR_M2OVER_SHIFT               (0x00000016)

  #define HCHIP_FMCR_M2OVER_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FMCR_M2OVER)

  #define HCHIP_FMCR_M2OVER_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FMCR_M2OVER,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FMCR_M2INEX
\*----------------------------------------------------------------------------*/
  #define HCHIP_FMCR_M2INEX_MASK                (0x00800000)
  #define HCHIP_FMCR_M2INEX_SHIFT               (0x00000017)

  #define HCHIP_FMCR_M2INEX_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FMCR_M2INEX)

  #define HCHIP_FMCR_M2INEX_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FMCR_M2INEX,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FMCR_M2UNDER
\*----------------------------------------------------------------------------*/
  #define HCHIP_FMCR_M2UNDER_MASK               (0x01000000)
  #define HCHIP_FMCR_M2UNDER_SHIFT              (0x00000018)

  #define HCHIP_FMCR_M2UNDER_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FMCR_M2UNDER)

  #define HCHIP_FMCR_M2UNDER_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FMCR_M2UNDER,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FMCR_M2RMODE
\*----------------------------------------------------------------------------*/
  #define HCHIP_FMCR_M2RMODE_MASK               (0x06000000)
  #define HCHIP_FMCR_M2RMODE_SHIFT              (0x00000019)

  #define HCHIP_FMCR_M2RMODE_GET(CrReg) \
    HCRFIELD_GET(CrReg,HCHIP_FMCR_M2RMODE)

  #define HCHIP_FMCR_M2RMODE_SET(CrReg,Val) \
    HCRFIELD_SET(CrReg,HCHIP_FMCR_M2RMODE,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCHIP_FMCR
\*----------------------------------------------------------------------------*/
  #define HCHIP_FMCR_GET(CrReg) HCRREG32_GET(CrReg)

  #define HCHIP_FMCR_SET(CrReg,Val) HCRREG32_SET(CrReg,Val)

  #define HCHIP_FMCR_CFG(CrReg,m1nan1,m1nan2,m1den1,m1den2,m1inval,m1info,\
  m1over,m1inex,m1under,m1rmode,m2nan1,m2nan2,m2den1,m2den2,m2inval,m2info,\
  m2over,m2inex,m2under,m2rmode) CrReg=(UINT32)( \
    HSHIFT_FDIELD(HCHIP_FMCR_M1NAN1, m1nan1) |\
    HSHIFT_FDIELD(HCHIP_FMCR_M1NAN2, m1nan2) |\
    HSHIFT_FDIELD(HCHIP_FMCR_M1DEN1, m1den1) |\
    HSHIFT_FDIELD(HCHIP_FMCR_M1DEN2, m1den2) |\
    HSHIFT_FDIELD(HCHIP_FMCR_M1INVAL,m1inval)|\
    HSHIFT_FDIELD(HCHIP_FMCR_M1INFO, m1info) |\
    HSHIFT_FDIELD(HCHIP_FMCR_M1OVER, m1over) |\
    HSHIFT_FDIELD(HCHIP_FMCR_M1INEX, m1inex) |\
    HSHIFT_FDIELD(HCHIP_FMCR_M1UNDER,m1under)|\
    HSHIFT_FDIELD(HCHIP_FMCR_M1RMODE,m1rmode)|\
    HSHIFT_FDIELD(HCHIP_FMCR_M2NAN1, m2nan1) |\
    HSHIFT_FDIELD(HCHIP_FMCR_M2NAN2, m2nan2) |\
    HSHIFT_FDIELD(HCHIP_FMCR_M2DEN1, m2den1) |\
    HSHIFT_FDIELD(HCHIP_FMCR_M2DEN2, m2den2) |\
    HSHIFT_FDIELD(HCHIP_FMCR_M2INVAL,m2inval)|\
    HSHIFT_FDIELD(HCHIP_FMCR_M2INFO, m2info) |\
    HSHIFT_FDIELD(HCHIP_FMCR_M2OVER, m2over) |\
    HSHIFT_FDIELD(HCHIP_FMCR_M2INEX, m2inex) |\
    HSHIFT_FDIELD(HCHIP_FMCR_M2UNDER,m2under)|\
    HSHIFT_FDIELD(HCHIP_FMCR_M2RMODE,m2rmode) \
  )
#endif /* FPU_SUPPORT */

/******************************************************************************/

#endif /* _CHIPHAL_H_ */
/******************************************************************************\
* End of chiphal.h
\******************************************************************************/



/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... cachehal.h
* DATE CREATED.. 06/12/1999 
* LAST MODIFIED. 03/08/2000
*   
*------------------------------------------------------------------------------
* DESCRIPTION:  (HAL interface file for the CACHE module)
*
* Registers Covered:
*   HCACHE_CCFG     - cache configuration register
*   HCACHE_L2FBAR   - L2 flush base address register
*   HCACHE_L2FWC    - L2 flush word count register
*   HCACHE_L2CBAR   - L2 clean base register
*   HCACHE_L2CWC    - L2 clean word count register
*   HCACHE_L1PFBAR  - L1P flush base address register
*   HCACHE_L1PFWC   - L1P flush word count register
*   HCACHE_L1DFBAR  - L1D flush base address register
*   HCACHE_L1DFWC   - L1D flush word count register
*   HCACHE_L2FLUSH  - L2 flush register
*   HCACHE_L2CLEAN  - L2 clean register
*   HCACHE_MAR0     - memory attribute register, region 0
*   HCACHE_MAR1     - memory attribute register, region 1
*   HCACHE_MAR2     - memory attribute register, region 2
*   HCACHE_MAR3     - memory attribute register, region 3
*   HCACHE_MAR4     - memory attribute register, region 4
*   HCACHE_MAR5     - memory attribute register, region 5
*   HCACHE_MAR6     - memory attribute register, region 6
*   HCACHE_MAR7     - memory attribute register, region 7
*   HCACHE_MAR8     - memory attribute register, region 8
*   HCACHE_MAR9     - memory attribute register, region 9
*   HCACHE_MAR10    - memory attribute register, region 10
*   HCACHE_MAR11    - memory attribute register, region 11
*   HCACHE_MAR12    - memory attribute register, region 12
*   HCACHE_MAR13    - memory attribute register, region 13
*   HCACHE_MAR14    - memory attribute register, region 14
*   HCACHE_MAR15    - memory attribute register, region 15
*
\******************************************************************************/
#ifndef _CACHEHAL_H_
#define _CACHEHAL_H_

#if (CACHE_SUPPORT)
/*============================================================================*\
* misc declarations
\*============================================================================*/
  #define HCACHE_BASE_ADDR        (HCHIP_PERBASE_ADDR+0x00040000)

/******************************************************************************\
* HCACHE_CCFG - cache configuration register
*
* Fields:
* (RW) HCACHE_CCFG_L2MODE
* (RW) HCACHE_CCFG_ID
* (RW) HCACHE_CCFG_IP
* (RW) HCACHE_CCFG_P
*
\******************************************************************************/
  #define HCACHE_CCFG_ADDR                     (HCACHE_BASE_ADDR+0x0000)
  #define HCACHE_CCFG                          REG32(HCACHE_CCFG_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HCACHE_CCFG_L2MODE
\*----------------------------------------------------------------------------*/
  #define HCACHE_CCFG_L2MODE_MASK              (0x00000007)
  #define HCACHE_CCFG_L2MODE_SHIFT             (0x00000000)

  #define HCACHE_CCFG_L2MODE_GET(RegAddr) \
    HFIELD_GET(RegAddr,HCACHE_CCFG_L2MODE)

  #define HCACHE_CCFG_L2MODE_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HCACHE_CCFG_L2MODE,Val)
  
/*----------------------------------------------------------------------------*\
* (RW) HCACHE_CCFG_ID
\*----------------------------------------------------------------------------*/
  #define HCACHE_CCFG_ID_MASK                  (0x00000100)
  #define HCACHE_CCFG_ID_SHIFT                 (0x00000008)

  #define HCACHE_CCFG_ID_GET(RegAddr) \
    HFIELD_GET(RegAddr,HCACHE_CCFG_ID)

  #define HCACHE_CCFG_ID_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HCACHE_CCFG_ID,Val)
  
/*----------------------------------------------------------------------------*\
* (RW) HCACHE_CCFG_IP
\*----------------------------------------------------------------------------*/
  #define HCACHE_CCFG_IP_MASK                  (0x00000200)
  #define HCACHE_CCFG_IP_SHIFT                 (0x00000009)

  #define HCACHE_CCFG_IP_GET(RegAddr) \
    HFIELD_GET(RegAddr,HCACHE_CCFG_IP)

  #define HCACHE_CCFG_IP_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HCACHE_CCFG_IP,Val)
  
/*----------------------------------------------------------------------------*\
* (RW) HCACHE_CCFG_P
\*----------------------------------------------------------------------------*/
  #define HCACHE_CCFG_P_MASK                   (0x80000000)
  #define HCACHE_CCFG_P_SHIFT                  (0x0000001F)

  #define HCACHE_CCFG_P_GET(RegAddr) \
    HFIELD_GET(RegAddr,HCACHE_CCFG_P)

  #define HCACHE_CCFG_P_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HCACHE_CCFG_P,Val)
  
/*----------------------------------------------------------------------------*\
* (RW) HCACHE_CCFG
\*----------------------------------------------------------------------------*/
  #define HCACHE_CCFG_GET(RegAddr) HREG32_GET(RegAddr)
  #define HCACHE_CCFG_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HCACHE_CCFG_CFG(RegAddr,l2mode,id,ip,p) REG32(RegAddr) = (UINT32)( \
    HFIELD_SHIFT(HCACHE_CCFG_L2MODE,l2mode)| \
    HFIELD_SHIFT(HCACHE_CCFG_ID,id)| \
    HFIELD_SHIFT(HCACHE_CCFG_IP,ip)| \
    HFIELD_SHIFT(HCACHE_CCFG_P,p) \
  )

/******************************************************************************\
* HCACHE_L2FBAR - L2 flush base address register
*
* Fields:
*   (RW) HCACHE_L2FBAR_L2FBAR
*
\******************************************************************************/
  #define HCACHE_L2FBAR_ADDR                   (HCACHE_BASE_ADDR+0x4000)
  #define HCACHE_L2FBAR                        REG32(HCACHE_L2FBAR_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HCACHE_L2FBAR_L2FBAR
\*----------------------------------------------------------------------------*/
  #define HCACHE_L2FBAR_L2FBAR_MASK            (0xFFFFFFFF)
  #define HCACHE_L2FBAR_L2FBAR_SHIFT           (0x00000000)

  #define HCACHE_L2FBAR_L2FBAR_GET(RegAddr) \
    HFIELD_GET(RegAddr,HCACHE_L2FBAR_L2FBAR)

  #define HCACHE_L2FBAR_L2FBAR_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HCACHE_L2FBAR_L2FBAR,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCACHE_L2FBAR
\*----------------------------------------------------------------------------*/
  #define HCACHE_L2FBAR_GET(RegAddr) HREG32_GET(RegAddr)
  #define HCACHE_L2FBAR_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HCACHE_L2FBAR_CFG(RegAddr,l2fbar) REG32(RegAddr) = (UINT32)( \
    HFIELD_SHIFT(HCACHE_L2FBAR_L2FBAR,l2fbar) \
  )

/******************************************************************************\
* HCACHE_L2FWC - L2 flush word count register
*
* Fields:
*   (RW) HCACHE_L2FWC_L2FWC
*
\******************************************************************************/
  #define HCACHE_L2FWC_ADDR                    (HCACHE_BASE_ADDR+0x4004)
  #define HCACHE_L2FWC                         REG32(HCACHE_L2FWC_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HCACHE_L2FWC_L2FWC
\*----------------------------------------------------------------------------*/
  #define HCACHE_L2FWC_L2FWC_MASK              (0x0000FFFF)
  #define HCACHE_L2FWC_L2FWC_SHIFT             (0x00000000)

  #define HCACHE_L2FWC_L2FWC_GET(RegAddr) \
    HFIELD_GET(RegAddr,HCACHE_L2FWC_L2FWC)

  #define HCACHE_L2FWC_L2FWC_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HCACHE_L2FWC_L2FWC,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCACHE_L2FWC
\*----------------------------------------------------------------------------*/
  #define HCACHE_L2FWC_GET(RegAddr) HREG32_GET(RegAddr)
  #define HCACHE_L2FWC_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HCACHE_L2FWC_CFG(RegAddr,l2fwc) REG32(RegAddr) = (UINT32)( \
    HFIELD_SHIFT(HCACHE_L2FWC_L2FWC,l2fwc) \
  )

/******************************************************************************\
* HCACHE_L2CBAR - L2 clean base register
*
* Fields:
*   (RW) HCACHE_L2CBAR_L2CBAR
*
\******************************************************************************/
  #define HCACHE_L2CBAR_ADDR                   (HCACHE_BASE_ADDR+0x4010)
  #define HCACHE_L2CBAR                        REG32(HCACHE_L2CBAR_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HCACHE_L2CBAR_L2CBAR
\*----------------------------------------------------------------------------*/
  #define HCACHE_L2CBAR_L2CBAR_MASK            (0xFFFFFFFF)
  #define HCACHE_L2CBAR_L2CBAR_SHIFT           (0x00000000)

  #define HCACHE_L2CBAR_L2CBAR_GET(RegAddr) \
    HFIELD_GET(RegAddr,HCACHE_L2CBAR_L2CBAR)

  #define HCACHE_L2CBAR_L2CBAR_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HCACHE_L2CBAR_L2CBAR,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCACHE_L2CBAR
\*----------------------------------------------------------------------------*/
  #define HCACHE_L2CBAR_GET(RegAddr) HREG32_GET(RegAddr)
  #define HCACHE_L2CBAR_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HCACHE_L2CBAR_CFG(RegAddr,l2cbar) REG32(RegAddr) = (UINT32)( \
    HFIELD_SHIFT(HCACHE_L2CBAR_L2CBAR,l2cbar) \
  )

/******************************************************************************\
* HCACHE_L2CWC - L2 clean word count register
*
* Fields:
*   (RW) HCACHE_L2CWC_L2CWC
*
\******************************************************************************/
  #define HCACHE_L2CWC_ADDR                    (HCACHE_BASE_ADDR+0x4014)
  #define HCACHE_L2CWC                         REG32(HCACHE_L2CWC_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HCACHE_L2CWC_L2CWC
\*----------------------------------------------------------------------------*/
  #define HCACHE_L2CWC_L2CWC_MASK              (0x0000FFFF)
  #define HCACHE_L2CWC_L2CWC_SHIFT             (0x00000000)

  #define HCACHE_L2CWC_L2CWC_GET(RegAddr) \
    HFIELD_GET(RegAddr,HCACHE_L2CWC_L2CWC)

  #define HCACHE_L2CWC_L2CWC_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HCACHE_L2CWC_L2CWC,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCACHE_L2CWC
\*----------------------------------------------------------------------------*/
  #define HCACHE_L2CWC_GET(RegAddr) HREG32_GET(RegAddr)
  #define HCACHE_L2CWC_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HCACHE_L2CWC_CFG(RegAddr,l2cwc) REG32(RegAddr) = (UINT32)( \
    HFIELD_SHIFT(HCACHE_L2CWC_L2CWC,l2cwc) \
  )

/******************************************************************************\
* HCACHE_L1PFBAR - L1P flush base address register
*
* Fields:
*   (RW) HCACHE_L1PFBAR_L1PFBAR
*
\******************************************************************************/
  #define HCACHE_L1PFBAR_ADDR                  (HCACHE_BASE_ADDR+0x4020)
  #define HCACHE_L1PFBAR                       REG32(HCACHE_L1PFBAR_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HCACHE_L1PFBAR_L1PFBAR
\*----------------------------------------------------------------------------*/
  #define HCACHE_L1PFBAR_L1PFBAR_MASK          (0xFFFFFFFF)
  #define HCACHE_L1PFBAR_L1PFBAR_SHIFT         (0x00000000)

  #define HCACHE_L1PFBAR_L1PFBAR_GET(RegAddr) \
    HFIELD_GET(RegAddr,HCACHE_L1PFBAR_L1PFBAR)

  #define HCACHE_L1PFBAR_L1PFBAR_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HCACHE_L1PFBAR_L1PFBAR,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCACHE_L1PFBAR
\*----------------------------------------------------------------------------*/
  #define HCACHE_L1PFBAR_GET(RegAddr) HREG32_GET(RegAddr)
  #define HCACHE_L1PFBAR_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HCACHE_L1PFBAR_CFG(RegAddr,l1pfbar) REG32(RegAddr) = (UINT32)( \
    HFIELD_SHIFT(HCACHE_L1PFBAR_L1PFBAR,l1pfbar) \
  )

/******************************************************************************\
* HCACHE_L1PFWC - L1P flush word count register
*
* Fields:
*   (RW) HCACHE_L1PFWC_L1PFWC
*
\******************************************************************************/
  #define HCACHE_L1PFWC_ADDR                   (HCACHE_BASE_ADDR+0x4024)
  #define HCACHE_L1PFWC                        REG32(HCACHE_L1PFWC_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HCACHE_L1PFWC_L1PFWC
\*----------------------------------------------------------------------------*/
  #define HCACHE_L1PFWC_L1PFWC_MASK            (0x0000FFFF)
  #define HCACHE_L1PFWC_L1PFWC_SHIFT           (0x00000000)

  #define HCACHE_L1PFWC_L1PFWC_GET(RegAddr) \
    HFIELD_GET(RegAddr,HCACHE_L1PFWC_L1PFWC)

  #define HCACHE_L1PFWC_L1PFWC_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HCACHE_L1PFWC_L1PFWC,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCACHE_L1PFWC
\*----------------------------------------------------------------------------*/
  #define HCACHE_L1PFWC_GET(RegAddr) HREG32_GET(RegAddr)
  #define HCACHE_L1PFWC_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HCACHE_L1PFWC_CFG(RegAddr,l1pfwc) REG32(RegAddr) = (UINT32)( \
    HFIELD_SHIFT(HCACHE_L1PFWC_L1PFWC,l1pfwc) \
  )

/******************************************************************************\
* HCACHE_L1DFBAR - L1D flush base address register
*
* Fields:
*   (RW) HCACHE_L1DFBAR_L1DFBAR
*
\******************************************************************************/
  #define HCACHE_L1DFBAR_ADDR                  (HCACHE_BASE_ADDR+0x4030)
  #define HCACHE_L1DFBAR                       REG32(HCACHE_L1DFBAR_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HCACHE_L1DFBAR_L1DFBAR
\*----------------------------------------------------------------------------*/
  #define HCACHE_L1DFBAR_L1DFBAR_MASK          (0xFFFFFFFF)
  #define HCACHE_L1DFBAR_L1DFBAR_SHIFT         (0x00000000)

  #define HCACHE_L1DFBAR_L1DFBAR_GET(RegAddr) \
    HFIELD_GET(RegAddr,HCACHE_L1DFBAR_L1DFBAR)

  #define HCACHE_L1DFBAR_L1DFBAR_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HCACHE_L1DFBAR_L1DFBAR,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCACHE_L1DFBAR
\*----------------------------------------------------------------------------*/
  #define HCACHE_L1DFBAR_GET(RegAddr) HREG32_GET(RegAddr)
  #define HCACHE_L1DFBAR_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HCACHE_L1DFBAR_CFG(RegAddr,l1dfbar) REG32(RegAddr) = (UINT32)( \
    HFIELD_SHIFT(HCACHE_L1DFBAR_L1DFBAR,l1dfbar) \
  )

/******************************************************************************\
* HCACHE_L1DFWC - L1D flush word count register
*
* Fields:
*   (RW) HCACHE_L1DFWC_L1DFWC
*
\******************************************************************************/
  #define HCACHE_L1DFWC_ADDR                   (HCACHE_BASE_ADDR+0x4034)
  #define HCACHE_L1DFWC                        REG32(HCACHE_L1DFWC_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HCACHE_L1DFWC_L1DFWC
\*----------------------------------------------------------------------------*/
  #define HCACHE_L1DFWC_L1DFWC_MASK            (0x0000FFFF)
  #define HCACHE_L1DFWC_L1DFWC_SHIFT           (0x00000000)

  #define HCACHE_L1DFWC_L1DFWC_GET(RegAddr) \
    HFIELD_GET(RegAddr,HCACHE_L1DFWC_L1DFWC)

  #define HCACHE_L1DFWC_L1DFWC_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HCACHE_L1DFWC_L1DFWC,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCACHE_L1DFWC
\*----------------------------------------------------------------------------*/
  #define HCACHE_L1DFWC_GET(RegAddr) HREG32_GET(RegAddr)
  #define HCACHE_L1DFWC_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)
    
  #define HCACHE_L1DFWC_CFG(RegAddr,l1dfwc) REG32(RegAddr) = (UINT32)( \
    HFIELD_SHIFT(HCACHE_L1DFWC_L1DFWC,l1dfwc) \
  )

/******************************************************************************\
* HCACHE_L2FLUSH - L2 flush register
*
* Fields:
*   (RW) HCACHE_L2FLUSH_F
*
\******************************************************************************/
  #define HCACHE_L2FLUSH_ADDR                  (HCACHE_BASE_ADDR+0x5000)
  #define HCACHE_L2FLUSH                       REG32(HCACHE_L2FLUSH_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HCACHE_L2FLUSH_F
\*----------------------------------------------------------------------------*/
  #define HCACHE_L2FLUSH_F_MASK                (0x00000001)
  #define HCACHE_L2FLUSH_F_SHIFT               (0x00000000)

  #define HCACHE_L2FLUSH_F_GET(RegAddr) \
    HFIELD_GET(RegAddr,HCACHE_L2FLUSH_F)

  #define HCACHE_L2FLUSH_F_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HCACHE_L2FLUSH_F,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCACHE_L2FLUSH
\*----------------------------------------------------------------------------*/
  #define HCACHE_L2FLUSH_GET(RegAddr) HREG32_GET(RegAddr)
  #define HCACHE_L2FLUSH_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HCACHE_L2FLUSH_CFG(RegAddr,f) REG32(RegAddr) = (UINT32)( \
    HFIELD_SHIFT(HCACHE_L2FLUSH_F,f) \
  )

/******************************************************************************\
* HCACHE_L2CLEAN - L2 clean register
*
* Fields:
*   (RW) HCACHE_L2CLEAN_C
*
\******************************************************************************/
  #define HCACHE_L2CLEAN_ADDR                  (HCACHE_BASE_ADDR+0x5004)
  #define HCACHE_L2CLEAN                       REG32(HCACHE_L2CLEAN_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HCACHE_L2CLEAN_C
\*----------------------------------------------------------------------------*/
  #define HCACHE_L2CLEAN_C_MASK                (0x00000001)
  #define HCACHE_L2CLEAN_C_SHIFT               (0x00000000)

  #define HCACHE_L2CLEAN_C_GET(RegAddr) \
    HFIELD_GET(RegAddr,HCACHE_L2CLEAN_C)

  #define HCACHE_L2CLEAN_C_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HCACHE_L2CLEAN_C,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCACHE_L2CLEAN
\*----------------------------------------------------------------------------*/
  #define HCACHE_L2CLEAN_GET(RegAddr) HREG32_GET(RegAddr)
  #define HCACHE_L2CLEAN_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HCACHE_L2CLEAN_CFG(RegAddr,c) REG32(RegAddr) = (UINT32)( \
    HFIELD_SHIFT(HCACHE_L2CLEAN_C,c) \
  )

/******************************************************************************\
* HCACHE_MAR0  - memory attribute register 0  (16M) 0x80000000->0x80FFFFFF
* HCACHE_MAR1  - memory attribute register 1  (16M) 0x81000000->0x81FFFFFF
* HCACHE_MAR2  - memory attribute register 2  (16M) 0x82000000->0x82FFFFFF
* HCACHE_MAR3  - memory attribute register 3  (16M) 0x83000000->0x83FFFFFF
* HCACHE_MAR4  - memory attribute register 4  (16M) 0x90000000->0x90FFFFFF
* HCACHE_MAR5  - memory attribute register 5  (16M) 0x91000000->0x91FFFFFF
* HCACHE_MAR6  - memory attribute register 6  (16M) 0x92000000->0x92FFFFFF
* HCACHE_MAR7  - memory attribute register 7  (16M) 0x93000000->0x93FFFFFF
* HCACHE_MAR8  - memory attribute register 8  (16M) 0xA0000000->0xA0FFFFFF
* HCACHE_MAR9  - memory attribute register 9  (16M) 0xA1000000->0xA1FFFFFF
* HCACHE_MAR10 - memory attribute register 10 (16M) 0xA2000000->0xA2FFFFFF
* HCACHE_MAR11 - memory attribute register 11 (16M) 0xA3000000->0xA3FFFFFF
* HCACHE_MAR12 - memory attribute register 12 (16M) 0xB0000000->0xB0FFFFFF
* HCACHE_MAR13 - memory attribute register 13 (16M) 0xB1000000->0xB1FFFFFF
* HCACHE_MAR14 - memory attribute register 14 (16M) 0xB2000000->0xB2FFFFFF
* HCACHE_MAR15 - memory attribute register 15 (16M) 0xB3000000->0xB3FFFFFF
*
* Fields:
*   (RW) HCACHE_MAR_CE
*
\******************************************************************************/
  #define HCACHE_MAR0_ADDR                     (HCACHE_BASE_ADDR+0x8200)
  #define HCACHE_MAR1_ADDR                     (HCACHE_BASE_ADDR+0x8204)
  #define HCACHE_MAR2_ADDR                     (HCACHE_BASE_ADDR+0x8208)
  #define HCACHE_MAR3_ADDR                     (HCACHE_BASE_ADDR+0x820C)
  #define HCACHE_MAR4_ADDR                     (HCACHE_BASE_ADDR+0x8240)
  #define HCACHE_MAR5_ADDR                     (HCACHE_BASE_ADDR+0x8244)
  #define HCACHE_MAR6_ADDR                     (HCACHE_BASE_ADDR+0x8248)
  #define HCACHE_MAR7_ADDR                     (HCACHE_BASE_ADDR+0x824C)
  #define HCACHE_MAR8_ADDR                     (HCACHE_BASE_ADDR+0x8280)
  #define HCACHE_MAR9_ADDR                     (HCACHE_BASE_ADDR+0x8284)
  #define HCACHE_MAR10_ADDR                    (HCACHE_BASE_ADDR+0x8288)
  #define HCACHE_MAR11_ADDR                    (HCACHE_BASE_ADDR+0x828C)
  #define HCACHE_MAR12_ADDR                    (HCACHE_BASE_ADDR+0x82C0)
  #define HCACHE_MAR13_ADDR                    (HCACHE_BASE_ADDR+0x82C4)
  #define HCACHE_MAR14_ADDR                    (HCACHE_BASE_ADDR+0x82C8)
  #define HCACHE_MAR15_ADDR                    (HCACHE_BASE_ADDR+0x82CC)
  
  #define HCACHE_MAR0                          REG32(HCACHE_MAR0_ADDR)
  #define HCACHE_MAR1                          REG32(HCACHE_MAR1_ADDR)
  #define HCACHE_MAR2                          REG32(HCACHE_MAR2_ADDR)
  #define HCACHE_MAR3                          REG32(HCACHE_MAR3_ADDR)
  #define HCACHE_MAR4                          REG32(HCACHE_MAR4_ADDR)
  #define HCACHE_MAR5                          REG32(HCACHE_MAR5_ADDR)
  #define HCACHE_MAR6                          REG32(HCACHE_MAR6_ADDR)
  #define HCACHE_MAR7                          REG32(HCACHE_MAR7_ADDR)
  #define HCACHE_MAR8                          REG32(HCACHE_MAR8_ADDR)
  #define HCACHE_MAR9                          REG32(HCACHE_MAR9_ADDR)
  #define HCACHE_MAR10                         REG32(HCACHE_MAR10_ADDR)
  #define HCACHE_MAR11                         REG32(HCACHE_MAR11_ADDR)
  #define HCACHE_MAR12                         REG32(HCACHE_MAR12_ADDR)
  #define HCACHE_MAR13                         REG32(HCACHE_MAR13_ADDR)
  #define HCACHE_MAR14                         REG32(HCACHE_MAR14_ADDR)
  #define HCACHE_MAR15                         REG32(HCACHE_MAR15_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HCACHE_MAR_CE
\*----------------------------------------------------------------------------*/
  #define HCACHE_MAR_CE_MASK                   (0x00000001)
  #define HCACHE_MAR_CE_SHIFT                  (0x00000000) 

  #define HCACHE_MAR_CE_GET(RegAddr) \
    HFIELD_GET(RegAddr,HCACHE_MAR_CE)

  #define HCACHE_MAR_CE_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HCACHE_MAR_CE,Val)

/*----------------------------------------------------------------------------*\
* (RW) HCACHE_MAR
\*----------------------------------------------------------------------------*/
  #define HCACHE_MAR_GET(RegAddr) HREG32_GET(RegAddr)
  #define HCACHE_MAR_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HCACHE_MAR_CFG(RegAddr,ce) REG32(RegAddr) = (UINT32)( \
    HFIELD_SHIFT(HCACHE_MAR_CE,ce) \
  )

/******************************************************************************/

#endif /* CACHE_SUPPORT */
#endif /* _CACHEHAL_H_ */
/******************************************************************************\
* End of cachehal.h
\******************************************************************************/

/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... dmahal.h
* DATE CREATED.. 03/12/1999 
* LAST MODIFIED. 03/08/2000
*   
*------------------------------------------------------------------------------
* DESCRIPTION:  (HAL interface file for the DMA module)
*
* Registers Covered:
*   HDMA_AUXCTL_ADDR   - auxiliary control register
*   HDMA_PRICTL0_ADDR  - primary control register
*   HDMA_PRICTL1_ADDR  - primary control register
*   HDMA_PRICTL2_ADDR  - primary control register
*   HDMA_PRICTL3_ADDR  - primary control register
*   HDMA_SECCTL0_ADDR  - seconday control register
*   HDMA_SECCTL1_ADDR  - seconday control register
*   HDMA_SECCTL2_ADDR  - seconday control register
*   HDMA_SECCTL3_ADDR  - seconday control register
*   HDMA_SRC0_ADDR     - source address register
*   HDMA_SRC1_ADDR     - source address register
*   HDMA_SRC2_ADDR     - source address register
*   HDMA_SRC3_ADDR     - source address register
*   HDMA_DST0_ADDR     - destination address register
*   HDMA_DST1_ADDR     - destination address register
*   HDMA_DST2_ADDR     - destination address register
*   HDMA_DST3_ADDR     - destination address register
*   HDMA_XFRCNT0_ADDR  - transfer count register
*   HDMA_XFRCNT1_ADDR  - transfer count register
*   HDMA_XFRCNT2_ADDR  - transfer count register
*   HDMA_XFRCNT3_ADDR  - transfer count register
*   HDMA_GBLCNTA_ADDR  - global count reload register
*   HDMA_GBLCNTB_ADDR  - global count reload register
*   HDMA_GBLIDXA_ADDR  - global index register
*   HDMA_GBLIDXB_ADDR  - global index register
*   HDMA_GBLADDRA_ADDR - global address register
*   HDMA_GBLADDRB_ADDR - global address register
*   HDMA_GBLADDRC_ADDR - global address register
*   HDMA_GBLADDRD_ADDR - global address register
*
*
\******************************************************************************/
#ifndef _DMAHAL_H_
#define _DMAHAL_H_

#if (DMA_SUPPORT)
/*============================================================================*\
* misc declarations
\*============================================================================*/
  #define HDMA_BASE_ADDR              (HCHIP_PERBASE_ADDR+0x00040000)

  #define HDMA_CHA_CNT                (4)
  #define HDMA_GBLADDR_CNT            (4)
  #define HDMA_GBLIDX_CNT             (2)
  #define HDMA_GBLCNT_CNT             (2)

/******************************************************************************\
* HDMA_AUXCTL_ADDR   - auxiliary control register
*
* Fields:
*   (RW) HDMA_AUXCTL_CHPRI
*   (RW) HDMA_AUXCTL_AUXPRI
*
\******************************************************************************/
  #define HDMA_AUXCTL_ADDR                      (HDMA_BASE_ADDR+0x0070)
  #define HDMA_AUXCTL                           REG32(HDMA_AUXCTL_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_AUXCTL_CHPRI
\*----------------------------------------------------------------------------*/
  #define HDMA_AUXCTL_CHPRI_MASK                (0x0000000F)
  #define HDMA_AUXCTL_CHPRI_SHIFT               (0x00000000)

  #define HDMA_AUXCTL_CHPRI_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_AUXCTL_CHPRI)

  #define HDMA_AUXCTL_CHPRI_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_AUXCTL_CHPRI,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_AUXCTL_AUXPRI
\*----------------------------------------------------------------------------*/
  #define HDMA_AUXCTL_AUXPRI_MASK               (0x00000010)
  #define HDMA_AUXCTL_AUXPRI_SHIFT              (0x00000004)

  #define HDMA_AUXCTL_AUXPRI_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_AUXCTL_AUXPRI)

  #define HDMA_AUXCTL_AUXPRI_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_AUXCTL_AUXPRI,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_AUXCTL
\*----------------------------------------------------------------------------*/
  #define HDMA_AUXCTL_GET(RegAddr) HREG32_GET(RegAddr)
  #define HDMA_AUXCTL_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HDMA_AUXCTL_CFG(RegAddr,chpri,auxpri) REG32(RegAddr)=(UINT32)(\
    HFIELD_SHIFT(HDMA_AUXCTL_CHPRI,chpri)|\
    HFIELD_SHIFT(HDMA_AUXCTL_AUXPRI,auxpri)\
  )

/******************************************************************************\
* HDMA_PRICTL0_ADDR  - primary control register
* HDMA_PRICTL1_ADDR  - primary control register
* HDMA_PRICTL2_ADDR  - primary control register
* HDMA_PRICTL3_ADDR  - primary control register
*
* Fields:
*   (RW) HDMA_PRICTL_START
*   (R)  HDMA_PRICTL_STATUS
*   (RW) HDMA_PRICTL_SRCDIR
*   (RW) HDMA_PRICTL_DSTDIR
*   (RW) HDMA_PRICTL_ESIZE
*   (RW) HDMA_PRICTL_SPLIT
*   (RW) HDMA_PRICTL_CNTRLD
*   (RW) HDMA_PRICTL_INDEX
*   (RW) HDMA_PRICTL_RSYNC
*   (RW) HDMA_PRICTL_WSYNC
*   (RW) HDMA_PRICTL_PRI
*   (RW) HDMA_PRICTL_TCINT
*   (RW) HDMA_PRICTL_FS
*   (RW) HDMA_PRICTL_EMOD
*   (RW) HDMA_PRICTL_SRCRLD
*   (RW) HDMA_PRICTL_DSTRLD
*
\******************************************************************************/
  #define HDMA_PRICTL0_ADDR                     (HDMA_BASE_ADDR+0x0000)
  #define HDMA_PRICTL1_ADDR                     (HDMA_BASE_ADDR+0x0040)
  #define HDMA_PRICTL2_ADDR                     (HDMA_BASE_ADDR+0x0004)
  #define HDMA_PRICTL3_ADDR                     (HDMA_BASE_ADDR+0x0044)

  #define HDMA_PRICTL0                          REG32(HDMA_PRICTL0_ADDR)
  #define HDMA_PRICTL1                          REG32(HDMA_PRICTL1_ADDR)
  #define HDMA_PRICTL2                          REG32(HDMA_PRICTL2_ADDR)
  #define HDMA_PRICTL3                          REG32(HDMA_PRICTL3_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_PRICTL_START
\*----------------------------------------------------------------------------*/
  #define HDMA_PRICTL_START_MASK                (0x00000003)
  #define HDMA_PRICTL_START_SHIFT               (0x00000000)

  #define HDMA_PRICTL_START_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_PRICTL_START)

  #define HDMA_PRICTL_START_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_PRICTL_START,Val)

/*----------------------------------------------------------------------------*\
* (R) HDMA_PRICTL_STATUS
\*----------------------------------------------------------------------------*/
  #define HDMA_PRICTL_STATUS_MASK               (0x0000000C)
  #define HDMA_PRICTL_STATUS_SHIFT              (0x00000002)

  #define HDMA_PRICTL_STATUS_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_PRICTL_STATUS)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_PRICTL_SRCDIR
\*----------------------------------------------------------------------------*/
  #define HDMA_PRICTL_SRCDIR_MASK               (0x00000030)
  #define HDMA_PRICTL_SRCDIR_SHIFT              (0x00000004)

  #define HDMA_PRICTL_SRCDIR_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_PRICTL_SRCDIR)

  #define HDMA_PRICTL_SRCDIR_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_PRICTL_SRCDIR,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_PRICTL_DSTDIR
\*----------------------------------------------------------------------------*/
  #define HDMA_PRICTL_DSTDIR_MASK               (0x000000C0)
  #define HDMA_PRICTL_DSTDIR_SHIFT              (0x00000006)

  #define HDMA_PRICTL_DSTDIR_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_PRICTL_DSTDIR)

  #define HDMA_PRICTL_DSTDIR_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_PRICTL_DSTDIR,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_PRICTL_ESIZE
\*----------------------------------------------------------------------------*/
  #define HDMA_PRICTL_ESIZE_MASK                (0x00000300)
  #define HDMA_PRICTL_ESIZE_SHIFT               (0x00000008)

  #define HDMA_PRICTL_ESIZE_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_PRICTL_ESIZE)

  #define HDMA_PRICTL_ESIZE_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_PRICTL_ESIZE,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_PRICTL_SPLIT
\*----------------------------------------------------------------------------*/
  #define HDMA_PRICTL_SPLIT_MASK                (0x00000C00)
  #define HDMA_PRICTL_SPLIT_SHIFT               (0x0000000A)

  #define HDMA_PRICTL_SPLIT_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_PRICTL_SPLIT)

  #define HDMA_PRICTL_SPLIT_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_PRICTL_SPLIT,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_PRICTL_CNTRLD
\*----------------------------------------------------------------------------*/
  #define HDMA_PRICTL_CNTRLD_MASK               (0x00001000)
  #define HDMA_PRICTL_CNTRLD_SHIFT              (0x0000000C)

  #define HDMA_PRICTL_CNTRLD_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_PRICTL_CNTRLD)

  #define HDMA_PRICTL_CNTRLD_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_PRICTL_CNTRLD,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_PRICTL_INDEX
\*----------------------------------------------------------------------------*/
  #define HDMA_PRICTL_INDEX_MASK                (0x00002000)
  #define HDMA_PRICTL_INDEX_SHIFT               (0x0000000D)

  #define HDMA_PRICTL_INDEX_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_PRICTL_INDEX)

  #define HDMA_PRICTL_INDEX_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_PRICTL_INDEX,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_PRICTL_RSYNC
\*----------------------------------------------------------------------------*/
  #define HDMA_PRICTL_RSYNC_MASK                (0x0007C000)
  #define HDMA_PRICTL_RSYNC_SHIFT               (0x0000000E)

  #define HDMA_PRICTL_RSYNC_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_PRICTL_RSYNC)

  #define HDMA_PRICTL_RSYNC_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_PRICTL_RSYNC,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_PRICTL_WSYNC
\*----------------------------------------------------------------------------*/
  #define HDMA_PRICTL_WSYNC_MASK                (0x00F10000)
  #define HDMA_PRICTL_WSYNC_SHIFT               (0x00000013)

  #define HDMA_PRICTL_WSYNC_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_PRICTL_WSYNC)

  #define HDMA_PRICTL_WSYNC_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_PRICTL_WSYNC,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_PRICTL_PRI
\*----------------------------------------------------------------------------*/
  #define HDMA_PRICTL_PRI_MASK                  (0x01000000)
  #define HDMA_PRICTL_PRI_SHIFT                 (0x00000018)

  #define HDMA_PRICTL_PRI_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_PRICTL_PRI)

  #define HDMA_PRICTL_PRI_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_PRICTL_PRI,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_PRICTL_TCINT
\*----------------------------------------------------------------------------*/
  #define HDMA_PRICTL_TCINT_MASK                (0x02000000)
  #define HDMA_PRICTL_TCINT_SHIFT               (0x00000019)

  #define HDMA_PRICTL_TCINT_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_PRICTL_TCINT)

  #define HDMA_PRICTL_TCINT_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_PRICTL_TCINT,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_PRICTL_FS
\*----------------------------------------------------------------------------*/
  #define HDMA_PRICTL_FS_MASK                   (0x04000000)
  #define HDMA_PRICTL_FS_SHIFT                  (0x0000001A)

  #define HDMA_PRICTL_FS_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_PRICTL_FS)

  #define HDMA_PRICTL_FS_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_PRICTL_FS,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_PRICTL_EMOD
\*----------------------------------------------------------------------------*/
  #define HDMA_PRICTL_EMOD_MASK                 (0x08000000)
  #define HDMA_PRICTL_EMOD_SHIFT                (0x0000001B)

  #define HDMA_PRICTL_EMOD_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_PRICTL_EMOD)

  #define HDMA_PRICTL_EMOD_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_PRICTL_EMOD,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_PRICTL_SRCRLD
\*----------------------------------------------------------------------------*/
  #define HDMA_PRICTL_SRCRLD_MASK               (0x30000000)
  #define HDMA_PRICTL_SRCRLD_SHIFT              (0x0000001C)

  #define HDMA_PRICTL_SRCRLD_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_PRICTL_SRCRLD)

  #define HDMA_PRICTL_SRCRLD_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_PRICTL_SRCRLD,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_PRICTL_DSTRLD
\*----------------------------------------------------------------------------*/
  #define HDMA_PRICTL_DSTRLD_MASK               (0xC0000000)
  #define HDMA_PRICTL_DSTRLD_SHIFT              (0x0000001E)

  #define HDMA_PRICTL_DSTRLD_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_PRICTL_DSTRLD)

  #define HDMA_PRICTL_DSTRLD_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_PRICTL_DSTRLD,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_PRICTL
\*----------------------------------------------------------------------------*/
  #define HDMA_PRICTL_GET(RegAddr) HREG32_GET(RegAddr)
  #define HDMA_PRICTL_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HDMA_PRICTL_CFG(RegAddr,start,srcdir,dstdir,esize,split,cntrld,\
  index,rsync,wsync,pri,tcint,fs,emod,srcrld,dstrld) \
  REG32(RegAddr)=(UINT32)(\
    HFIELD_SHIFT(HDMA_PRICTL_START,start)|\
    HFIELD_SHIFT(HDMA_PRICTL_SRCDIR,srcdir)|\
    HFIELD_SHIFT(HDMA_PRICTL_DSTDIR,dstdir)|\
    HFIELD_SHIFT(HDMA_PRICTL_ESIZE,esize)|\
    HFIELD_SHIFT(HDMA_PRICTL_SPLIT,split)|\
    HFIELD_SHIFT(HDMA_PRICTL_CNTRLD,cntrld)|\
    HFIELD_SHIFT(HDMA_PRICTL_INDEX,index)|\
    HFIELD_SHIFT(HDMA_PRICTL_RSYNC,rsync)|\
    HFIELD_SHIFT(HDMA_PRICTL_WSYNC,wsync)|\
    HFIELD_SHIFT(HDMA_PRICTL_PRI,pri)|\
    HFIELD_SHIFT(HDMA_PRICTL_TCINT,tcint)|\
    HFIELD_SHIFT(HDMA_PRICTL_FS,fs)|\
    HFIELD_SHIFT(HDMA_PRICTL_EMOD,emod)|\
    HFIELD_SHIFT(HDMA_PRICTL_SRCRLD,srcrld)|\
    HFIELD_SHIFT(HDMA_PRICTL_DSTRLD,dstrld)\
  )

/******************************************************************************\
* HDMA_SECCTL0_ADDR  - seconday control register
* HDMA_SECCTL1_ADDR  - seconday control register
* HDMA_SECCTL2_ADDR  - seconday control register
* HDMA_SECCTL3_ADDR  - seconday control register
*
* Fields:
*   (RW) HDMA_SECCTL_SXCOND
*   (RW) HDMA_SECCTL_SXIE
*   (RW) HDMA_SECCTL_FRAMECOND
*   (RW) HDMA_SECCTL_FRAMEIE
*   (RW) HDMA_SECCTL_LASTCOND
*   (RW) HDMA_SECCTL_LASTIE
*   (RW) HDMA_SECCTL_BLOCKCOND
*   (RW) HDMA_SECCTL_BLOCKIE
*   (RW) HDMA_SECCTL_RDROPCOND
*   (RW) HDMA_SECCTL_RDROPIE
*   (RW) HDMA_SECCTL_WDROPCOND
*   (RW) HDMA_SECCTL_WDROPIE
*   (RW) HDMA_SECCTL_RSYNCSTAT
*   (RW) HDMA_SECCTL_RSYNCCLR
*   (RW) HDMA_SECCTL_WSYNCSTAT
*   (RW) HDMA_SECCTL_WSYNCCLR
*   (RW) HDMA_SECCTL_DMACEN
*   (RW) HDMA_SECCTL_FSIG (1)
*   (RW) HDMA_SECCTL_RSPOL (1)
*   (RW) HDMA_SECCTL_WSPOL (1)
*
*   (1) only on 6202 or 6203 devices
*
\******************************************************************************/
  #define HDMA_SECCTL0_ADDR                     (HDMA_BASE_ADDR+0x0008)
  #define HDMA_SECCTL1_ADDR                     (HDMA_BASE_ADDR+0x0048)
  #define HDMA_SECCTL2_ADDR                     (HDMA_BASE_ADDR+0x000C)
  #define HDMA_SECCTL3_ADDR                     (HDMA_BASE_ADDR+0x004C)

  #define HDMA_SECCTL0                          REG32(HDMA_SECCTL0_ADDR)
  #define HDMA_SECCTL1                          REG32(HDMA_SECCTL1_ADDR)
  #define HDMA_SECCTL2                          REG32(HDMA_SECCTL2_ADDR)
  #define HDMA_SECCTL3                          REG32(HDMA_SECCTL3_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_SECCTL_SXCOND
\*----------------------------------------------------------------------------*/
  #define HDMA_SECCTL_SXCOND_MASK               (0x00000001)
  #define HDMA_SECCTL_SXCOND_SHIFT              (0x00000000)

  #define HDMA_SECCTL_SXCOND_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_SECCTL_SXCOND)

  #define HDMA_SECCTL_SXCOND_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_SECCTL_SXCOND,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_SECCTL_SXIE
\*----------------------------------------------------------------------------*/
  #define HDMA_SECCTL_SXIE_MASK                 (0x00000002)
  #define HDMA_SECCTL_SXIE_SHIFT                (0x00000001)

  #define HDMA_SECCTL_SXIE_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_SECCTL_SXIE)

  #define HDMA_SECCTL_SXIE_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_SECCTL_SXIE,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_SECCTL_FRAMECOND
\*----------------------------------------------------------------------------*/
  #define HDMA_SECCTL_FRAMECOND_MASK            (0x00000004)
  #define HDMA_SECCTL_FRAMECOND_SHIFT           (0x00000002)

  #define HDMA_SECCTL_FRAMECOND_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_SECCTL_FRAMECOND)

  #define HDMA_SECCTL_FRAMECOND_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_SECCTL_FRAMECOND,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_SECCTL_FRAMEIE
\*----------------------------------------------------------------------------*/
  #define HDMA_SECCTL_FRAMEIE_MASK              (0x00000008)
  #define HDMA_SECCTL_FRAMEIE_SHIFT             (0x00000003)

  #define HDMA_SECCTL_FRAMEIE_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_SECCTL_FRAMEIE)

  #define HDMA_SECCTL_FRAMEIE_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_SECCTL_FRAMEIE,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_SECCTL_LASTCOND
\*----------------------------------------------------------------------------*/
  #define HDMA_SECCTL_LASTCOND_MASK             (0x00000010)
  #define HDMA_SECCTL_LASTCOND_SHIFT            (0x00000004)

  #define HDMA_SECCTL_LASTCOND_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_SECCTL_LASTCOND)

  #define HDMA_SECCTL_LASTCOND_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_SECCTL_LASTCOND,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_SECCTL_LASTIE
\*----------------------------------------------------------------------------*/
  #define HDMA_SECCTL_LASTIE_MASK               (0x00000020)
  #define HDMA_SECCTL_LASTIE_SHIFT              (0x00000005)

  #define HDMA_SECCTL_LASTIE_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_SECCTL_LASTIE)

  #define HDMA_SECCTL_LASTIE_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_SECCTL_LASTIE,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_SECCTL_BLOCKCOND
\*----------------------------------------------------------------------------*/
  #define HDMA_SECCTL_BLOCKCOND_MASK            (0x00000040)
  #define HDMA_SECCTL_BLOCKCOND_SHIFT           (0x00000006)

  #define HDMA_SECCTL_BLOCKCOND_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_SECCTL_BLOCKCOND)

  #define HDMA_SECCTL_BLOCKCOND_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_SECCTL_BLOCKCOND,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_SECCTL_BLOCKIE
\*----------------------------------------------------------------------------*/
  #define HDMA_SECCTL_BLOCKIE_MASK              (0x00000080)
  #define HDMA_SECCTL_BLOCKIE_SHIFT             (0x00000007)

  #define HDMA_SECCTL_BLOCKIE_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_SECCTL_BLOCKIE)

  #define HDMA_SECCTL_BLOCKIE_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_SECCTL_BLOCKIE,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_SECCTL_RDROPCOND
\*----------------------------------------------------------------------------*/
  #define HDMA_SECCTL_RDROPCOND_MASK            (0x00000100)
  #define HDMA_SECCTL_RDROPCOND_SHIFT           (0x00000008)

  #define HDMA_SECCTL_RDROPCOND_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_SECCTL_RDROPCOND)

  #define HDMA_SECCTL_RDROPCOND_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_SECCTL_RDROPCOND,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_SECCTL_RDROPIE
\*----------------------------------------------------------------------------*/
  #define HDMA_SECCTL_RDROPIE_MASK              (0x00000200)
  #define HDMA_SECCTL_RDROPIE_SHIFT             (0x00000009)

  #define HDMA_SECCTL_RDROPIE_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_SECCTL_RDROPIE)

  #define HDMA_SECCTL_RDROPIE_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_SECCTL_RDROPIE,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_SECCTL_WDROPCOND
\*----------------------------------------------------------------------------*/
  #define HDMA_SECCTL_WDROPCOND_MASK            (0x00000400)
  #define HDMA_SECCTL_WDROPCOND_SHIFT           (0x0000000A)

  #define HDMA_SECCTL_WDROPCOND_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_SECCTL_WDROPCOND)

  #define HDMA_SECCTL_WDROPCOND_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_SECCTL_WDROPCOND,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_SECCTL_WDROPIE
\*----------------------------------------------------------------------------*/
  #define HDMA_SECCTL_WDROPIE_MASK              (0x00000800)
  #define HDMA_SECCTL_WDROPIE_SHIFT             (0x0000000B)

  #define HDMA_SECCTL_WDROPIE_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_SECCTL_WDROPIE)

  #define HDMA_SECCTL_WDROPIE_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_SECCTL_WDROPIE,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_SECCTL_RSYNCSTAT
\*----------------------------------------------------------------------------*/
  #define HDMA_SECCTL_RSYNCSTAT_MASK            (0x00001000)
  #define HDMA_SECCTL_RSYNCSTAT_SHIFT           (0x0000000C)

  #define HDMA_SECCTL_RSYNCSTAT_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_SECCTL_RSYNCSTAT)

  #define HDMA_SECCTL_RSYNCSTAT_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_SECCTL_RSYNCSTAT,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_SECCTL_RSYNCCLR
\*----------------------------------------------------------------------------*/
  #define HDMA_SECCTL_RSYNCCLR_MASK             (0x00002000)
  #define HDMA_SECCTL_RSYNCCLR_SHIFT            (0x0000000D)

  #define HDMA_SECCTL_RSYNCCLR_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_SECCTL_RSYNCCLR)

  #define HDMA_SECCTL_RSYNCCLR_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_SECCTL_RSYNCCLR,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_SECCTL_WSYNCSTAT
\*----------------------------------------------------------------------------*/
  #define HDMA_SECCTL_WSYNCSTAT_MASK            (0x00004000)
  #define HDMA_SECCTL_WSYNCSTAT_SHIFT           (0x0000000E)

  #define HDMA_SECCTL_WSYNCSTAT_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_SECCTL_WSYNCSTAT)

  #define HDMA_SECCTL_WSYNCSTAT_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_SECCTL_WSYNCSTAT,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_SECCTL_WSYNCCLR
\*----------------------------------------------------------------------------*/
  #define HDMA_SECCTL_WSYNCCLR_MASK             (0x00008000)
  #define HDMA_SECCTL_WSYNCCLR_SHIFT            (0x0000000F)

  #define HDMA_SECCTL_WSYNCCLR_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_SECCTL_WSYNCCLR)

  #define HDMA_SECCTL_WSYNCCLR_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_SECCTL_WSYNCCLR,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_SECCTL_DMACEN
\*----------------------------------------------------------------------------*/
  #define HDMA_SECCTL_DMACEN_MASK               (0x00070000)
  #define HDMA_SECCTL_DMACEN_SHIFT              (0x00000010)

  #define HDMA_SECCTL_DMACEN_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_SECCTL_DMACEN)

  #define HDMA_SECCTL_DMACEN_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_SECCTL_DMACEN,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_SECCTL_FSIG
\*----------------------------------------------------------------------------*/
#if (CHIP_6201|CHIP_6203)
  #define HDMA_SECCTL_FSIG_MASK                 (0x00080000)
  #define HDMA_SECCTL_FSIG_SHIFT                (0x00000013)
#else
  #define HDMA_SECCTL_FSIG_MASK                 (0x00000000)
  #define HDMA_SECCTL_FSIG_SHIFT                (0x00000000)
#endif

  #define HDMA_SECCTL_FSIG_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_SECCTL_FSIG)

  #define HDMA_SECCTL_FSIG_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_SECCTL_FSIG,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_SECCTL_RSPOL
\*----------------------------------------------------------------------------*/
#if (CHIP_6201|CHIP_6203)
  #define HDMA_SECCTL_RSPOL_MASK                (0x00100000)
  #define HDMA_SECCTL_RSPOL_SHIFT               (0x00000014)
#else
  #define HDMA_SECCTL_RSPOL_MASK                (0x00000000)
  #define HDMA_SECCTL_RSPOL_SHIFT               (0x00000000)
#endif

  #define HDMA_SECCTL_RSPOL_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_SECCTL_RSPOL)

  #define HDMA_SECCTL_RSPOL_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_SECCTL_RSPOL,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_SECCTL_WSPOL
\*----------------------------------------------------------------------------*/
#if (CHIP_6201|CHIP_6203)
  #define HDMA_SECCTL_WSPOL_MASK                (0x00200000)
  #define HDMA_SECCTL_WSPOL_SHIFT               (0x00000015)
#else
  #define HDMA_SECCTL_WSPOL_MASK                (0x00000000)
  #define HDMA_SECCTL_WSPOL_SHIFT               (0x00000000)
#endif

  #define HDMA_SECCTL_WSPOL_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_SECCTL_WSPOL)

  #define HDMA_SECCTL_WSPOL_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_SECCTL_WSPOL,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_SECCTL
\*----------------------------------------------------------------------------*/
  #define HDMA_SECCTL_GET(RegAddr) HREG32_GET(RegAddr)
  #define HDMA_SECCTL_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HDMA_SECCTL_CFG(RegAddr,sxcond,sxie,framecond,frameie,lastcond,\
  lastie,blockcond,blockie,rdropcond,rdropie,wdropcond,wdropie,rsyncstat,\
  rsyncclr,wsyncstat,wsyncclr,dmacen,fsig,rspol,wspol) \
  REG32(RegAddr)=(UINT32)(\
    HFIELD_SHIFT(HDMA_SECCTL_SXCOND,sxcond)|\
    HFIELD_SHIFT(HDMA_SECCTL_SXIE,sxie)|\
    HFIELD_SHIFT(HDMA_SECCTL_FRAMECOND,framecond)|\
    HFIELD_SHIFT(HDMA_SECCTL_FRAMEIE,frameie)|\
    HFIELD_SHIFT(HDMA_SECCTL_LASTCOND,lastcond)|\
    HFIELD_SHIFT(HDMA_SECCTL_LASTIE,lastie)|\
    HFIELD_SHIFT(HDMA_SECCTL_BLOCKCOND,blockcond)|\
    HFIELD_SHIFT(HDMA_SECCTL_BLOCKIE,blockie)|\
    HFIELD_SHIFT(HDMA_SECCTL_RDROPCOND,rdropcond)|\
    HFIELD_SHIFT(HDMA_SECCTL_RDROPIE,rdropie)|\
    HFIELD_SHIFT(HDMA_SECCTL_WDROPCOND,wdropcond)|\
    HFIELD_SHIFT(HDMA_SECCTL_WDROPIE,wdropie)|\
    HFIELD_SHIFT(HDMA_SECCTL_RSYNCSTAT,rsyncstat)|\
    HFIELD_SHIFT(HDMA_SECCTL_RSYNCCLR,rsyncclr)|\
    HFIELD_SHIFT(HDMA_SECCTL_WSYNCSTAT,wsyncstat)|\
    HFIELD_SHIFT(HDMA_SECCTL_WSYNCCLR,wsyncclr)|\
    HFIELD_SHIFT(HDMA_SECCTL_DMACEN,dmacen)|\
    HFIELD_SHIFT(HDMA_SECCTL_FSIG,fsig)|\
    HFIELD_SHIFT(HDMA_SECCTL_RSPOL,rspol)|\
    HFIELD_SHIFT(HDMA_SECCTL_WSPOL,wspol)\
  )

/******************************************************************************\
* HDMA_SRC0_ADDR     - source address register
* HDMA_SRC1_ADDR     - source address register
* HDMA_SRC2_ADDR     - source address register
* HDMA_SRC3_ADDR     - source address register
*
* Fields:
*   (RW) HDMA_SRC_SRC
*
\******************************************************************************/
  #define HDMA_SRC0_ADDR                        (HDMA_BASE_ADDR+0x0010)
  #define HDMA_SRC1_ADDR                        (HDMA_BASE_ADDR+0x0050)
  #define HDMA_SRC2_ADDR                        (HDMA_BASE_ADDR+0x0014)
  #define HDMA_SRC3_ADDR                        (HDMA_BASE_ADDR+0x0054)

  #define HDMA_SRC0                             REG32(HDMA_SRC0_ADDR)
  #define HDMA_SRC1                             REG32(HDMA_SRC1_ADDR)
  #define HDMA_SRC2                             REG32(HDMA_SRC2_ADDR)
  #define HDMA_SRC3                             REG32(HDMA_SRC3_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_SRC_SRC
\*----------------------------------------------------------------------------*/
  #define HDMA_SRC_SRC_MASK                     (0xFFFFFFFF)
  #define HDMA_SRC_SRC_SHIFT                    (0x00000000)

  #define HDMA_SRC_SRC_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_SRC_SRC)

  #define HDMA_SRC_SRC_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_SRC_SRC,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_SRC
\*----------------------------------------------------------------------------*/
  #define HDMA_SRC_GET(RegAddr) HREG32_GET(RegAddr)
  #define HDMA_SRC_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HDMA_SRC_CFG(RegAddr,src) \
  REG32(RegAddr)=(UINT32)(\
    HFIELD_SHIFT(HDMA_SRC_SRC,src)\
  )

/******************************************************************************\
* HDMA_DST0_ADDR     - destination address register
* HDMA_DST1_ADDR     - destination address register
* HDMA_DST2_ADDR     - destination address register
* HDMA_DST3_ADDR     - destination address register
*
* Fields:
*   (RW) HDMA_DST_DST
*
\******************************************************************************/
  #define HDMA_DST0_ADDR                        (HDMA_BASE_ADDR+0x0018)
  #define HDMA_DST1_ADDR                        (HDMA_BASE_ADDR+0x0058)
  #define HDMA_DST2_ADDR                        (HDMA_BASE_ADDR+0x001C)
  #define HDMA_DST3_ADDR                        (HDMA_BASE_ADDR+0x005C)

  #define HDMA_DST0                             REG32(HDMA_DST0_ADDR)
  #define HDMA_DST1                             REG32(HDMA_DST1_ADDR)
  #define HDMA_DST2                             REG32(HDMA_DST2_ADDR)
  #define HDMA_DST3                             REG32(HDMA_DST3_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_DST_DST
\*----------------------------------------------------------------------------*/
  #define HDMA_DST_DST_MASK                     (0xFFFFFFFF)
  #define HDMA_DST_DST_SHIFT                    (0x00000000)

  #define HDMA_DST_DST_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_DST_DST)

  #define HDMA_DST_DST_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_DST_DST,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_DST
\*----------------------------------------------------------------------------*/
  #define HDMA_DST_GET(RegAddr) HREG32_GET(RegAddr)
  #define HDMA_DST_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HDMA_DST_CFG(RegAddr,dst) \
  REG32(RegAddr)=(UINT32)(\
    HFIELD_SHIFT(HDMA_DST_DST,dst)\
  )

/******************************************************************************\
* HDMA_XFRCNT0_ADDR  - transfer count register
* HDMA_XFRCNT1_ADDR  - transfer count register
* HDMA_XFRCNT2_ADDR  - transfer count register
* HDMA_XFRCNT3_ADDR  - transfer count register
*
* Fields:
*   (RW) HDMA_XFRCNT_ELECNT
*   (RW) HDMA_XFRCNT_FRMCNT
*
\******************************************************************************/
  #define HDMA_XFRCNT0_ADDR                     (HDMA_BASE_ADDR+0x0020)
  #define HDMA_XFRCNT1_ADDR                     (HDMA_BASE_ADDR+0x0060)
  #define HDMA_XFRCNT2_ADDR                     (HDMA_BASE_ADDR+0x0024)
  #define HDMA_XFRCNT3_ADDR                     (HDMA_BASE_ADDR+0x0064)

  #define HDMA_XFRCNT0                          REG32(HDMA_XFRCNT0_ADDR)
  #define HDMA_XFRCNT1                          REG32(HDMA_XFRCNT1_ADDR)
  #define HDMA_XFRCNT2                          REG32(HDMA_XFRCNT2_ADDR)
  #define HDMA_XFRCNT3                          REG32(HDMA_XFRCNT3_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_XFRCNT_ELECNT
\*----------------------------------------------------------------------------*/
  #define HDMA_XFRCNT_ELECNT_MASK               (0x0000FFFF)
  #define HDMA_XFRCNT_ELECNT_SHIFT              (0x00000000)

  #define HDMA_XFRCNT_ELECNT_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_XFRCNT_ELECNT)

  #define HDMA_XFRCNT_ELECNT_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_XFRCNT_ELECNT,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_XFRCNT_FRMCNT
\*----------------------------------------------------------------------------*/
  #define HDMA_XFRCNT_FRMCNT_MASK               (0xFFFF0000)
  #define HDMA_XFRCNT_FRMCNT_SHIFT              (0x00000010)

  #define HDMA_XFRCNT_FRMCNT_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_XFRCNT_FRMCNT)

  #define HDMA_XFRCNT_FRMCNT_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_XFRCNT_FRMCNT,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_XFRCNT
\*----------------------------------------------------------------------------*/
  #define HDMA_XFRCNT_GET(RegAddr) HREG32_GET(RegAddr)
  #define HDMA_XFRCNT_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HDMA_XFRCNT_CFG(RegAddr,elecnt,frmcnt) \
  REG32(RegAddr)=(UINT32)(\
    HFIELD_SHIFT(HDMA_XFRCNT_ELECNT,elecnt)|\
    HFIELD_SHIFT(HDMA_XFRCNT_FRMCNT,frmcnt)\
  )

/******************************************************************************\
* HDMA_GBLCNTA_ADDR  - global count reload register
* HDMA_GBLCNTB_ADDR  - global count reload register
*
* Fields:
*   (RW) HDMA_GBLCNT_ELECNT
*   (RW) HDMA_GBLCNT_FRMCNT
*
\******************************************************************************/
  #define HDMA_GBLCNTA_ADDR                     (HDMA_BASE_ADDR+0x0028)
  #define HDMA_GBLCNTB_ADDR                     (HDMA_BASE_ADDR+0x002C)

  #define HDMA_GBLCNTA                          REG32(HDMA_GBLCNTA_ADDR)
  #define HDMA_GBLCNTB                          REG32(HDMA_GBLCNTB_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_GBLCNT_ELECNT
\*----------------------------------------------------------------------------*/
  #define HDMA_GBLCNT_ELECNT_MASK               (0x0000FFFF)
  #define HDMA_GBLCNT_ELECNT_SHIFT              (0x00000000)

  #define HDMA_GBLCNT_ELECNT_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_GBLCNT_ELECNT)

  #define HDMA_GBLCNT_ELECNT_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_GBLCNT_ELECNT,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_GBLCNT_FRMCNT
\*----------------------------------------------------------------------------*/
  #define HDMA_GBLCNT_FRMCNT_MASK               (0xFFFF0000)
  #define HDMA_GBLCNT_FRMCNT_SHIFT              (0x00000010)

  #define HDMA_GBLCNT_FRMCNT_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_GBLCNT_FRMCNT)

  #define HDMA_GBLCNT_FRMCNT_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_GBLCNT_FRMCNT,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_GBLCNT
\*----------------------------------------------------------------------------*/
  #define HDMA_GBLCNT_GET(RegAddr) HREG32_GET(RegAddr)
  #define HDMA_GBLCNT_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HDMA_GBLCNT_CFG(RegAddr,elecnt,frmcnt) \
  REG32(RegAddr)=(UINT32)(\
    HFIELD_SHIFT(HDMA_GBLCNT_ELECNT,elecnt)|\
    HFIELD_SHIFT(HDMA_GBLCNT_FRMCNT,frmcnt)\
  )

/******************************************************************************\
* HDMA_GBLIDXA_ADDR  - global index register
* HDMA_GBLIDXB_ADDR  - global index register
*
* Fields:
*   (RW) HDMA_GBLIDX_ELEIDX
*   (RW) HDMA_GBLIDX_FRMIDX
*
\******************************************************************************/
  #define HDMA_GBLIDXA_ADDR                     (HDMA_BASE_ADDR+0x0030)
  #define HDMA_GBLIDXB_ADDR                     (HDMA_BASE_ADDR+0x0034)

  #define HDMA_GBLIDXA                          REG32(HDMA_GBLIDXA_ADDR)
  #define HDMA_GBLIDXB                          REG32(HDMA_GBLIDXB_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_GBLIDX_ELEIDX
\*----------------------------------------------------------------------------*/
  #define HDMA_GBLIDX_ELEIDX_MASK               (0x0000FFFF)
  #define HDMA_GBLIDX_ELEIDX_SHIFT              (0x00000000)

  #define HDMA_GBLIDX_ELEIDX_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_GBLIDX_ELEIDX)

  #define HDMA_GBLIDX_ELEIDX_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_GBLIDX_ELEIDX,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_GBLIDX_FRMIDX
\*----------------------------------------------------------------------------*/
  #define HDMA_GBLIDX_FRMIDX_MASK               (0xFFFF0000)
  #define HDMA_GBLIDX_FRMIDX_SHIFT              (0x00000010)

  #define HDMA_GBLIDX_FRMIDX_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_GBLIDX_FRMIDX)

  #define HDMA_GBLIDX_FRMIDX_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_GBLIDX_FRMIDX,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_GBLIDX
\*----------------------------------------------------------------------------*/
  #define HDMA_GBLIDX_GET(RegAddr) HREG32_GET(RegAddr)
  #define HDMA_GBLIDX_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HDMA_GBLIDX_CFG(RegAddr,eleidx, frmidx) \
  REG32(RegAddr)=(UINT32)(\
    HFIELD_SHIFT(HDMA_GBLIDX_ELEIDX,eleidx)|\
    HFIELD_SHIFT(HDMA_GBLIDX_FRMIDX,frmidx)\
  )

/******************************************************************************\
* HDMA_GBLADDRA_ADDR - global address register
* HDMA_GBLADDRB_ADDR - global address register
* HDMA_GBLADDRC_ADDR - global address register
* HDMA_GBLADDRD_ADDR - global address register
*
* Fields:
*   (RW) HDMA_GBLADDR_GBLADDR
*
\******************************************************************************/
  #define HDMA_GBLADDRA_ADDR                    (HDMA_BASE_ADDR+0x0038)
  #define HDMA_GBLADDRB_ADDR                    (HDMA_BASE_ADDR+0x003C)
  #define HDMA_GBLADDRC_ADDR                    (HDMA_BASE_ADDR+0x0068)
  #define HDMA_GBLADDRD_ADDR                    (HDMA_BASE_ADDR+0x006C)

  #define HDMA_GBLADDRA                         REG32(HDMA_GBLADDRA_ADDR)
  #define HDMA_GBLADDRB                         REG32(HDMA_GBLADDRB_ADDR)
  #define HDMA_GBLADDRC                         REG32(HDMA_GBLADDRC_ADDR)
  #define HDMA_GBLADDRD                         REG32(HDMA_GBLADDRD_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_GBLADDR_GBLADDR
\*----------------------------------------------------------------------------*/
  #define HDMA_GBLADDR_ADDR_MASK                (0xFFFFFFFF)
  #define HDMA_GBLADDR_ADDR_SHIFT               (0x00000000)

  #define HDMA_GBLADDR_GBLADDR_GET(RegAddr) \
    HFIELD_GET(RegAddr,HDMA_GBLADDR_GBLADDR)

  #define HDMA_GBLADDR_GBLADDR_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HDMA_GBLADDR_GBLADDR,Val)

/*----------------------------------------------------------------------------*\
* (RW) HDMA_GBLADDR
\*----------------------------------------------------------------------------*/
  #define HDMA_GBLADDR_GET(RegAddr) HREG32_GET(RegAddr)
  #define HDMA_GBLADDR_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HDMA_GBLADDR_CFG(RegAddr,gbladdr) \
  REG32(RegAddr)=(UINT32)(\
    HFIELD_SHIFT(HDMA_GBLADDR_GBLADDR,gbladdr)\
  )

/******************************************************************************/

#endif /* DMA_SUPPORT */
#endif /* _DMAHAL_H_ */
/******************************************************************************\
* End of dmahal.h
\******************************************************************************/
/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... edmahal.h
* DATE CREATED.. 06/12/1999 
* LAST MODIFIED. 03/08/2000
*   
*------------------------------------------------------------------------------
* DESCRIPTION:  (HAL interface file for the EDMA module)
*
* Registers Covered:
*   HEDMA_OPT  - options (for both QDMA and PRAM entries)
*   HEDMA_SRC  - source address (for both QDMA and PRAM entries)
*   HEDMA_CNT  - transfer count (for both QDMA and PRAM entries)
*   HEDMA_DST  - destination address (for both QDMA and PRAM entries)
*   HEDMA_IDX  - index (for both QDMA and PRAM entries)
*   HEDMA_RLD  - reload/link (for PRAM entries)
*   HEDMA_PQSR - priority queue status register
*   HEDMA_CIPR - channel interrupt pending register
*   HEDMA_CIER - channel interrupt enable register
*   HEDMA_CCER - channel chain enable register
*   HEDMA_ER   - event register
*   HEDMA_EER  - event enable register
*   HEDMA_ECR  - event clear register
*   HEDMA_ESR  - event set register
*
\******************************************************************************/
#ifndef _EDMAHAL_H_
#define _EDMAHAL_H_

#if (EDMA_SUPPORT)
/*============================================================================*\
*  misc declarations
\*============================================================================*/
  #define HEDMA_BASE0_ADDR            (HCHIP_PERBASE_ADDR+0x00200000)
  #define HEDMA_BASE1_ADDR            (HCHIP_PERBASE_ADDR+0x00800000)

  #define HEDMA_CHA_CNT               (16)

  #define HEDMA_PRAM_START            (HEDMA_BASE0_ADDR)
  #define HEDMA_PRAM_SIZE             (0x00000800) 
  #define HEDMA_PRAM_END              (HEDMA_PRAM_START+HEDMA_PRAM_SIZE-1)
  #define HEDMA_ENTRY_SIZE            (24)
  #define HEDMA_ENTRY_CNT             (HEDMA_PRAM_SIZE / HEDMA_ENTRY_SIZE)
  
  #define HEDMA_MK_ENTRY_ADDR(cha)    (HEDMA_PRAM_START+(cha)*HEDMA_ENTRY_SIZE)

  #define HEDMA_ENTRY0_ADDR           HEDMA_MK_ENTRY_ADDR(0)
  #define HEDMA_ENTRY1_ADDR           HEDMA_MK_ENTRY_ADDR(1)
  #define HEDMA_ENTRY2_ADDR           HEDMA_MK_ENTRY_ADDR(2)
  #define HEDMA_ENTRY3_ADDR           HEDMA_MK_ENTRY_ADDR(3)
  #define HEDMA_ENTRY4_ADDR           HEDMA_MK_ENTRY_ADDR(4)
  #define HEDMA_ENTRY5_ADDR           HEDMA_MK_ENTRY_ADDR(5)
  #define HEDMA_ENTRY6_ADDR           HEDMA_MK_ENTRY_ADDR(6)
  #define HEDMA_ENTRY7_ADDR           HEDMA_MK_ENTRY_ADDR(7)
  #define HEDMA_ENTRY8_ADDR           HEDMA_MK_ENTRY_ADDR(8)
  #define HEDMA_ENTRY9_ADDR           HEDMA_MK_ENTRY_ADDR(9)
  #define HEDMA_ENTRY10_ADDR          HEDMA_MK_ENTRY_ADDR(10)
  #define HEDMA_ENTRY11_ADDR          HEDMA_MK_ENTRY_ADDR(11)
  #define HEDMA_ENTRY12_ADDR          HEDMA_MK_ENTRY_ADDR(12)
  #define HEDMA_ENTRY13_ADDR          HEDMA_MK_ENTRY_ADDR(13)
  #define HEDMA_ENTRY14_ADDR          HEDMA_MK_ENTRY_ADDR(14)
  #define HEDMA_ENTRY15_ADDR          HEDMA_MK_ENTRY_ADDR(15)

  #define HEDMA_LINK_START            HEDMA_MK_ENTRY_ADDR(16)

  #define HEDMA_LINK_CNT              ((HEDMA_PRAM_END-HEDMA_LINK_START+1)\
                                        /HEDMA_ENTRY_SIZE)
                                        
  #define HEDMA_MK_LINK_ADDR(l)       (HEDMA_LINK_START+(l)*HEDMA_ENTRY_SIZE)

  #define HEDMA_SCRATCH_START         (HEDMA_LINK_START+\
                                        (HEDMA_ENTRY_SIZE*HEDMA_LINK_CNT))
                                      
  #define HEDMA_SCRATCH_SIZE          (HEDMA_PRAM_END-HEDMA_SCRATCH_START+1)                              


  #define HEDMA_OPT_OFFSET            (0x00000000)
  #define HEDMA_SRC_OFFSET            (0x00000004)
  #define HEDMA_CNT_OFFSET            (0x00000008)
  #define HEDMA_DST_OFFSET            (0x0000000C)
  #define HEDMA_IDX_OFFSET            (0x00000010)
  #define HEDMA_RLD_OFFSET            (0x00000014)

/******************************************************************************\
* HEDMA_OPT - transfer options
*
* Fields:
*   (RW) HEDMA_OPT_FS
*   (RW) HEDMA_OPT_LINK
*   (RW) HEDMA_OPT_TCC
*   (RW) HEDMA_OPT_TCINT
*   (RW) HEDMA_OPT_DUM
*   (RW) HEDMA_OPT_2DD
*   (RW) HEDMA_OPT_SUM
*   (RW) HEDMA_OPT_2DS
*   (RW) HEDMA_OPT_ESIZE
*   (RW) HEDMA_OPT_PRI
*
\******************************************************************************/
  #define HEDMA_QOPT_ADDR              (HEDMA_BASE1_ADDR+0x0000)
  #define HEDMA_QSOPT_ADDR             (HEDMA_BASE1_ADDR+0x0020)
  #define HEDMA_QOPT                   REG32(HEDMA_QOPT_ADDR)
  #define HEDMA_QSOPT                  REG32(HEDMA_QSOPT_ADDR)

  #define HEDMA_OPT0_ADDR              (HEDMA_ENTRY0_ADDR+HEDMA_OPT_OFFSET)
  #define HEDMA_OPT1_ADDR              (HEDMA_ENTRY1_ADDR+HEDMA_OPT_OFFSET)
  #define HEDMA_OPT2_ADDR              (HEDMA_ENTRY2_ADDR+HEDMA_OPT_OFFSET)
  #define HEDMA_OPT3_ADDR              (HEDMA_ENTRY3_ADDR+HEDMA_OPT_OFFSET)
  #define HEDMA_OPT4_ADDR              (HEDMA_ENTRY4_ADDR+HEDMA_OPT_OFFSET)
  #define HEDMA_OPT5_ADDR              (HEDMA_ENTRY5_ADDR+HEDMA_OPT_OFFSET)
  #define HEDMA_OPT6_ADDR              (HEDMA_ENTRY6_ADDR+HEDMA_OPT_OFFSET)
  #define HEDMA_OPT7_ADDR              (HEDMA_ENTRY7_ADDR+HEDMA_OPT_OFFSET)
  #define HEDMA_OPT8_ADDR              (HEDMA_ENTRY8_ADDR+HEDMA_OPT_OFFSET)
  #define HEDMA_OPT9_ADDR              (HEDMA_ENTRY9_ADDR+HEDMA_OPT_OFFSET)
  #define HEDMA_OPT10_ADDR             (HEDMA_ENTRY10_ADDR+HEDMA_OPT_OFFSET)
  #define HEDMA_OPT11_ADDR             (HEDMA_ENTRY11_ADDR+HEDMA_OPT_OFFSET)
  #define HEDMA_OPT12_ADDR             (HEDMA_ENTRY12_ADDR+HEDMA_OPT_OFFSET)
  #define HEDMA_OPT13_ADDR             (HEDMA_ENTRY13_ADDR+HEDMA_OPT_OFFSET)
  #define HEDMA_OPT14_ADDR             (HEDMA_ENTRY14_ADDR+HEDMA_OPT_OFFSET)
  #define HEDMA_OPT15_ADDR             (HEDMA_ENTRY15_ADDR+HEDMA_OPT_OFFSET)

  #define HEDMA_OPT0                   REG32(HEDMA_OPT0_ADDR)
  #define HEDMA_OPT1                   REG32(HEDMA_OPT1_ADDR)
  #define HEDMA_OPT2                   REG32(HEDMA_OPT2_ADDR)
  #define HEDMA_OPT3                   REG32(HEDMA_OPT3_ADDR)
  #define HEDMA_OPT4                   REG32(HEDMA_OPT4_ADDR)
  #define HEDMA_OPT5                   REG32(HEDMA_OPT5_ADDR)
  #define HEDMA_OPT6                   REG32(HEDMA_OPT6_ADDR)
  #define HEDMA_OPT7                   REG32(HEDMA_OPT7_ADDR)
  #define HEDMA_OPT8                   REG32(HEDMA_OPT8_ADDR)
  #define HEDMA_OPT9                   REG32(HEDMA_OPT9_ADDR)
  #define HEDMA_OPT10                  REG32(HEDMA_OPT10_ADDR)
  #define HEDMA_OPT11                  REG32(HEDMA_OPT11_ADDR)
  #define HEDMA_OPT12                  REG32(HEDMA_OPT12_ADDR)
  #define HEDMA_OPT13                  REG32(HEDMA_OPT13_ADDR)
  #define HEDMA_OPT14                  REG32(HEDMA_OPT14_ADDR)
  #define HEDMA_OPT15                  REG32(HEDMA_OPT15_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_OPT_FS
\*----------------------------------------------------------------------------*/
  #define HEDMA_OPT_FS_MASK                    (0x00000001)
  #define HEDMA_OPT_FS_SHIFT                   (0x00000000)

  #define HEDMA_OPT_FS_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_OPT_FS)

  #define HEDMA_OPT_FS_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_OPT_FS,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_OPT_LINK
\*----------------------------------------------------------------------------*/
  #define HEDMA_OPT_LINK_MASK                  (0x00000002)
  #define HEDMA_OPT_LINK_SHIFT                 (0x00000001)

  #define HEDMA_OPT_LINK_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_OPT_LINK)

  #define HEDMA_OPT_LINK_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_OPT_LINK,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_OPT_TCC
\*----------------------------------------------------------------------------*/
  #define HEDMA_OPT_TCC_MASK                   (0x000F0000)
  #define HEDMA_OPT_TCC_SHIFT                  (0x00000010)

  #define HEDMA_OPT_TCC_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_OPT_TCC)

  #define HEDMA_OPT_TCC_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_OPT_TCC,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_OPT_TCINT
\*----------------------------------------------------------------------------*/
  #define HEDMA_OPT_TCINT_MASK                 (0x00100000)
  #define HEDMA_OPT_TCINT_SHIFT                (0x00000014)

  #define HEDMA_OPT_TCINT_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_OPT_TCINT)

  #define HEDMA_OPT_TCINT_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_OPT_TCINT,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_OPT_DUM
\*----------------------------------------------------------------------------*/
  #define HEDMA_OPT_DUM_MASK                   (0x00600000)
  #define HEDMA_OPT_DUM_SHIFT                  (0x00000015)

  #define HEDMA_OPT_DUM_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_OPT_DUM)

  #define HEDMA_OPT_DUM_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_OPT_DUM,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_OPT_2DD
\*----------------------------------------------------------------------------*/
  #define HEDMA_OPT_2DD_MASK                   (0x00800000)
  #define HEDMA_OPT_2DD_SHIFT                  (0x00000017)

  #define HEDMA_OPT_2DD_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_OPT_2DD)

  #define HEDMA_OPT_2DD_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_OPT_2DD,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_OPT_SUM
\*----------------------------------------------------------------------------*/
  #define HEDMA_OPT_SUM_MASK                   (0x03000000)
  #define HEDMA_OPT_SUM_SHIFT                  (0x00000018)

  #define HEDMA_OPT_SUM_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_OPT_SUM)

  #define HEDMA_OPT_SUM_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_OPT_SUM,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_OPT_2DS
\*----------------------------------------------------------------------------*/
  #define HEDMA_OPT_2DS_MASK                   (0x04000000)
  #define HEDMA_OPT_2DS_SHIFT                  (0x0000001A)

  #define HEDMA_OPT_2DS_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_OPT_2DS)

  #define HEDMA_OPT_2DS_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_OPT_2DS,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_OPT_ESIZE
\*----------------------------------------------------------------------------*/
  #define HEDMA_OPT_ESIZE_MASK                 (0x18000000)
  #define HEDMA_OPT_ESIZE_SHIFT                (0x0000001B)

  #define HEDMA_OPT_ESIZE_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_OPT_ESIZE)

  #define HEDMA_OPT_ESIZE_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_OPT_ESIZE,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_OPT_PRI
\*----------------------------------------------------------------------------*/
  #define HEDMA_OPT_PRI_MASK                   (0xE0000000)
  #define HEDMA_OPT_PRI_SHIFT                  (0x0000001D)

  #define HEDMA_OPT_PRI_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_OPT_PRI)

  #define HEDMA_OPT_PRI_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_OPT_PRI,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_OPT
\*----------------------------------------------------------------------------*/
  #define HEDMA_OPT_GET(RegAddr) HREG32_GET(RegAddr)
  #define HEDMA_OPT_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HEDMA_OPT_CFG(RegAddr,fs,link,tcc,tcint,dum,d2d,sum,s2d,esize,pri)\
  REG32(RegAddr)=(UINT32)(\
    HFIELD_SHIFT(HEDMA_OPT_FS,fs)|\
    HFIELD_SHIFT(HEDMA_OPT_LINK,link)|\
    HFIELD_SHIFT(HEDMA_OPT_TCC,tcc)|\
    HFIELD_SHIFT(HEDMA_OPT_TCINT,tcint)|\
    HFIELD_SHIFT(HEDMA_OPT_DUM,dum)|\
    HFIELD_SHIFT(HEDMA_OPT_2DD,d2d)|\
    HFIELD_SHIFT(HEDMA_OPT_SUM,sum)|\
    HFIELD_SHIFT(HEDMA_OPT_2DS,s2d)|\
    HFIELD_SHIFT(HEDMA_OPT_ESIZE,esize)|\
    HFIELD_SHIFT(HEDMA_OPT_PRI,pri)\
  )

/******************************************************************************\
* HEDMA_SRC - source address
*
* Fields:
*   (RW) HEDMA_SRC_SRC
*
\******************************************************************************/
  #define HEDMA_QSRC_ADDR              (HEDMA_BASE1_ADDR+0x0004)
  #define HEDMA_QSSRC_ADDR             (HEDMA_BASE1_ADDR+0x0024)
  #define HEDMA_QSRC                   REG32(HEDMA_QSRC_ADDR)
  #define HEDMA_QSSRC                  REG32(HEDMA_QSSRC_ADDR)

  #define HEDMA_SRC0_ADDR              (HEDMA_ENTRY0_ADDR+HEDMA_SRC_OFFSET)
  #define HEDMA_SRC1_ADDR              (HEDMA_ENTRY1_ADDR+HEDMA_SRC_OFFSET)
  #define HEDMA_SRC2_ADDR              (HEDMA_ENTRY2_ADDR+HEDMA_SRC_OFFSET)
  #define HEDMA_SRC3_ADDR              (HEDMA_ENTRY3_ADDR+HEDMA_SRC_OFFSET)
  #define HEDMA_SRC4_ADDR              (HEDMA_ENTRY4_ADDR+HEDMA_SRC_OFFSET)
  #define HEDMA_SRC5_ADDR              (HEDMA_ENTRY5_ADDR+HEDMA_SRC_OFFSET)
  #define HEDMA_SRC6_ADDR              (HEDMA_ENTRY6_ADDR+HEDMA_SRC_OFFSET)
  #define HEDMA_SRC7_ADDR              (HEDMA_ENTRY7_ADDR+HEDMA_SRC_OFFSET)
  #define HEDMA_SRC8_ADDR              (HEDMA_ENTRY8_ADDR+HEDMA_SRC_OFFSET)
  #define HEDMA_SRC9_ADDR              (HEDMA_ENTRY9_ADDR+HEDMA_SRC_OFFSET)
  #define HEDMA_SRC10_ADDR             (HEDMA_ENTRY10_ADDR+HEDMA_SRC_OFFSET)
  #define HEDMA_SRC11_ADDR             (HEDMA_ENTRY11_ADDR+HEDMA_SRC_OFFSET)
  #define HEDMA_SRC12_ADDR             (HEDMA_ENTRY12_ADDR+HEDMA_SRC_OFFSET)
  #define HEDMA_SRC13_ADDR             (HEDMA_ENTRY13_ADDR+HEDMA_SRC_OFFSET)
  #define HEDMA_SRC14_ADDR             (HEDMA_ENTRY14_ADDR+HEDMA_SRC_OFFSET)
  #define HEDMA_SRC15_ADDR             (HEDMA_ENTRY15_ADDR+HEDMA_SRC_OFFSET)

  #define HEDMA_SRC0                   REG32(HEDMA_SRC0_ADDR)
  #define HEDMA_SRC1                   REG32(HEDMA_SRC1_ADDR)
  #define HEDMA_SRC2                   REG32(HEDMA_SRC2_ADDR)
  #define HEDMA_SRC3                   REG32(HEDMA_SRC3_ADDR)
  #define HEDMA_SRC4                   REG32(HEDMA_SRC4_ADDR)
  #define HEDMA_SRC5                   REG32(HEDMA_SRC5_ADDR)
  #define HEDMA_SRC6                   REG32(HEDMA_SRC6_ADDR)
  #define HEDMA_SRC7                   REG32(HEDMA_SRC7_ADDR)
  #define HEDMA_SRC8                   REG32(HEDMA_SRC8_ADDR)
  #define HEDMA_SRC9                   REG32(HEDMA_SRC9_ADDR)
  #define HEDMA_SRC10                  REG32(HEDMA_SRC10_ADDR)
  #define HEDMA_SRC11                  REG32(HEDMA_SRC11_ADDR)
  #define HEDMA_SRC12                  REG32(HEDMA_SRC12_ADDR)
  #define HEDMA_SRC13                  REG32(HEDMA_SRC13_ADDR)
  #define HEDMA_SRC14                  REG32(HEDMA_SRC14_ADDR)
  #define HEDMA_SRC15                  REG32(HEDMA_SRC15_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_SRC_SRC
\*----------------------------------------------------------------------------*/
  #define HEDMA_SRC_SRC_MASK                   (0xFFFFFFFF)
  #define HEDMA_SRC_SRC_SHIFT                  (0x00000000)
                                      
  #define HEDMA_SRC_SRC_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_SRC_SRC)

  #define HEDMA_SRC_SRC_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_SRC_SRC,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_SRC
\*----------------------------------------------------------------------------*/
  #define HEDMA_SRC_GET(RegAddr) HREG32_GET(RegAddr)
  #define HEDMA_SRC_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HEDMA_SRC_CFG(RegAddr,src)\
  REG32(RegAddr)=(UINT32)(\
    HFIELD_SHIFT(HEDMA_SRC_SRC,src)\
  )

/******************************************************************************\
* HEDMA_CNT - transfer count
*
* Fields:
*   (RW) HEDMA_CNT_ELECNT
*   (RW) HEDMA_CNT_FRMCNT
*
\******************************************************************************/
  #define HEDMA_QCNT_ADDR              (HEDMA_BASE1_ADDR+0x0008)
  #define HEDMA_QSCNT_ADDR             (HEDMA_BASE1_ADDR+0x0028) 
  #define HEDMA_QCNT                   REG32(HEDMA_QCNT_ADDR)
  #define HEDMA_QSCNT                  REG32(HEDMA_QSCNT_ADDR)
  
  #define HEDMA_CNT0_ADDR              (HEDMA_ENTRY0_ADDR+HEDMA_CNT_OFFSET)
  #define HEDMA_CNT1_ADDR              (HEDMA_ENTRY1_ADDR+HEDMA_CNT_OFFSET)
  #define HEDMA_CNT2_ADDR              (HEDMA_ENTRY2_ADDR+HEDMA_CNT_OFFSET)
  #define HEDMA_CNT3_ADDR              (HEDMA_ENTRY3_ADDR+HEDMA_CNT_OFFSET)
  #define HEDMA_CNT4_ADDR              (HEDMA_ENTRY4_ADDR+HEDMA_CNT_OFFSET)
  #define HEDMA_CNT5_ADDR              (HEDMA_ENTRY5_ADDR+HEDMA_CNT_OFFSET)
  #define HEDMA_CNT6_ADDR              (HEDMA_ENTRY6_ADDR+HEDMA_CNT_OFFSET)
  #define HEDMA_CNT7_ADDR              (HEDMA_ENTRY7_ADDR+HEDMA_CNT_OFFSET)
  #define HEDMA_CNT8_ADDR              (HEDMA_ENTRY8_ADDR+HEDMA_CNT_OFFSET)
  #define HEDMA_CNT9_ADDR              (HEDMA_ENTRY9_ADDR+HEDMA_CNT_OFFSET)
  #define HEDMA_CNT10_ADDR             (HEDMA_ENTRY10_ADDR+HEDMA_CNT_OFFSET)
  #define HEDMA_CNT11_ADDR             (HEDMA_ENTRY11_ADDR+HEDMA_CNT_OFFSET)
  #define HEDMA_CNT12_ADDR             (HEDMA_ENTRY12_ADDR+HEDMA_CNT_OFFSET)
  #define HEDMA_CNT13_ADDR             (HEDMA_ENTRY13_ADDR+HEDMA_CNT_OFFSET)
  #define HEDMA_CNT14_ADDR             (HEDMA_ENTRY14_ADDR+HEDMA_CNT_OFFSET)
  #define HEDMA_CNT15_ADDR             (HEDMA_ENTRY15_ADDR+HEDMA_CNT_OFFSET)

  #define HEDMA_CNT0                   REG32(HEDMA_CNT0_ADDR)
  #define HEDMA_CNT1                   REG32(HEDMA_CNT1_ADDR)
  #define HEDMA_CNT2                   REG32(HEDMA_CNT2_ADDR)
  #define HEDMA_CNT3                   REG32(HEDMA_CNT3_ADDR)
  #define HEDMA_CNT4                   REG32(HEDMA_CNT4_ADDR)
  #define HEDMA_CNT5                   REG32(HEDMA_CNT5_ADDR)
  #define HEDMA_CNT6                   REG32(HEDMA_CNT6_ADDR)
  #define HEDMA_CNT7                   REG32(HEDMA_CNT7_ADDR)
  #define HEDMA_CNT8                   REG32(HEDMA_CNT8_ADDR)
  #define HEDMA_CNT9                   REG32(HEDMA_CNT9_ADDR)
  #define HEDMA_CNT10                  REG32(HEDMA_CNT10_ADDR)
  #define HEDMA_CNT11                  REG32(HEDMA_CNT11_ADDR)
  #define HEDMA_CNT12                  REG32(HEDMA_CNT12_ADDR)
  #define HEDMA_CNT13                  REG32(HEDMA_CNT13_ADDR)
  #define HEDMA_CNT14                  REG32(HEDMA_CNT14_ADDR)
  #define HEDMA_CNT15                  REG32(HEDMA_CNT15_ADDR)
  
/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CNT_ELECNT
\*----------------------------------------------------------------------------*/
  #define HEDMA_CNT_ELECNT_MASK                (0x0000FFFF)
  #define HEDMA_CNT_ELECNT_SHIFT               (0x00000000)
  
  #define HEDMA_CNT_ELECNT_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CNT_ELECNT)

  #define HEDMA_CNT_ELECNT_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CNT_ELECNT,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CNT_FRMCNT
\*----------------------------------------------------------------------------*/
  #define HEDMA_CNT_FRMCNT_MASK                (0xFFFF0000)
  #define HEDMA_CNT_FRMCNT_SHIFT               (0x00000010)
                                      
  #define HEDMA_CNT_FRMCNT_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CNT_FRMCNT)

  #define HEDMA_CNT_FRMCNT_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CNT_FRMCNT,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CNT
\*----------------------------------------------------------------------------*/
  #define HEDMA_CNT_GET(RegAddr) HREG32_GET(RegAddr)
  #define HEDMA_CNT_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HEDMA_CNT_CFG(RegAddr,elecnt,frmcnt)\
  REG32(RegAddr)=(UINT32)(\
    HFIELD_SHIFT(HEDMA_CNT_ELECNT,elecnt)|\
    HFIELD_SHIFT(HEDMA_CNT_FRMCNT,frmcnt)\
  )

/******************************************************************************\
* HEDMA_DST - destination address
*
* Fields:
*   (RW) HEDMA_DST_DST
*
\******************************************************************************/
  #define HEDMA_QDST_ADDR              (HEDMA_BASE1_ADDR+0x000C)
  #define HEDMA_QSDST_ADDR             (HEDMA_BASE1_ADDR+0x002C)
  #define HEDMA_QDST                   REG32(HEDMA_QDST_ADDR)
  #define HEDMA_QSDST                  REG32(HEDMA_QSDST_ADDR)

  #define HEDMA_DST0_ADDR              (HEDMA_ENTRY0_ADDR+HEDMA_DST_OFFSET)
  #define HEDMA_DST1_ADDR              (HEDMA_ENTRY1_ADDR+HEDMA_DST_OFFSET)
  #define HEDMA_DST2_ADDR              (HEDMA_ENTRY2_ADDR+HEDMA_DST_OFFSET)
  #define HEDMA_DST3_ADDR              (HEDMA_ENTRY3_ADDR+HEDMA_DST_OFFSET)
  #define HEDMA_DST4_ADDR              (HEDMA_ENTRY4_ADDR+HEDMA_DST_OFFSET)
  #define HEDMA_DST5_ADDR              (HEDMA_ENTRY5_ADDR+HEDMA_DST_OFFSET)
  #define HEDMA_DST6_ADDR              (HEDMA_ENTRY6_ADDR+HEDMA_DST_OFFSET)
  #define HEDMA_DST7_ADDR              (HEDMA_ENTRY7_ADDR+HEDMA_DST_OFFSET)
  #define HEDMA_DST8_ADDR              (HEDMA_ENTRY8_ADDR+HEDMA_DST_OFFSET)
  #define HEDMA_DST9_ADDR              (HEDMA_ENTRY9_ADDR+HEDMA_DST_OFFSET)
  #define HEDMA_DST10_ADDR             (HEDMA_ENTRY10_ADDR+HEDMA_DST_OFFSET)
  #define HEDMA_DST11_ADDR             (HEDMA_ENTRY11_ADDR+HEDMA_DST_OFFSET)
  #define HEDMA_DST12_ADDR             (HEDMA_ENTRY12_ADDR+HEDMA_DST_OFFSET)
  #define HEDMA_DST13_ADDR             (HEDMA_ENTRY13_ADDR+HEDMA_DST_OFFSET)
  #define HEDMA_DST14_ADDR             (HEDMA_ENTRY14_ADDR+HEDMA_DST_OFFSET)
  #define HEDMA_DST15_ADDR             (HEDMA_ENTRY15_ADDR+HEDMA_DST_OFFSET)

  #define HEDMA_DST0                   REG32(HEDMA_DST0_ADDR)
  #define HEDMA_DST1                   REG32(HEDMA_DST1_ADDR)
  #define HEDMA_DST2                   REG32(HEDMA_DST2_ADDR)
  #define HEDMA_DST3                   REG32(HEDMA_DST3_ADDR)
  #define HEDMA_DST4                   REG32(HEDMA_DST4_ADDR)
  #define HEDMA_DST5                   REG32(HEDMA_DST5_ADDR)
  #define HEDMA_DST6                   REG32(HEDMA_DST6_ADDR)
  #define HEDMA_DST7                   REG32(HEDMA_DST7_ADDR)
  #define HEDMA_DST8                   REG32(HEDMA_DST8_ADDR)
  #define HEDMA_DST9                   REG32(HEDMA_DST9_ADDR)
  #define HEDMA_DST10                  REG32(HEDMA_DST10_ADDR)
  #define HEDMA_DST11                  REG32(HEDMA_DST11_ADDR)
  #define HEDMA_DST12                  REG32(HEDMA_DST12_ADDR)
  #define HEDMA_DST13                  REG32(HEDMA_DST13_ADDR)
  #define HEDMA_DST14                  REG32(HEDMA_DST14_ADDR)
  #define HEDMA_DST15                  REG32(HEDMA_DST15_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_DST_DST
\*----------------------------------------------------------------------------*/
  #define HEDMA_DST_DST_MASK                   (0xFFFFFFFF)
  #define HEDMA_DST_DST_SHIFT                  (0x00000000)
                                      
  #define HEDMA_DST_DST_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_DST_DST)

  #define HEDMA_DST_DST_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_DST_DST,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_DST
\*----------------------------------------------------------------------------*/
  #define HEDMA_DST_GET(RegAddr) HREG32_GET(RegAddr)
  #define HEDMA_DST_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HEDMA_DST_CFG(RegAddr,src)\
  REG32(RegAddr)=(UINT32)(\
    HFIELD_SHIFT(HEDMA_DST_DST,src)\
  )

/******************************************************************************\
* HEDMA_IDX - transfer count
*
* Fields:
*   (RW) HEDMA_IDX_ELEIDX
*   (RW) HEDMA_IDX_FRMIDX
*
\******************************************************************************/
  #define HEDMA_QIDX_ADDR              (HEDMA_BASE1_ADDR+0x0010)
  #define HEDMA_QSIDX_ADDR             (HEDMA_BASE1_ADDR+0x0030)
  #define HEDMA_QIDX                   REG32(HEDMA_QIDX_ADDR)
  #define HEDMA_QSIDX                  REG32(HEDMA_QSIDX_ADDR)
  
  #define HEDMA_IDX0_ADDR              (HEDMA_ENTRY0_ADDR+HEDMA_IDX_OFFSET)
  #define HEDMA_IDX1_ADDR              (HEDMA_ENTRY1_ADDR+HEDMA_IDX_OFFSET)
  #define HEDMA_IDX2_ADDR              (HEDMA_ENTRY2_ADDR+HEDMA_IDX_OFFSET)
  #define HEDMA_IDX3_ADDR              (HEDMA_ENTRY3_ADDR+HEDMA_IDX_OFFSET)
  #define HEDMA_IDX4_ADDR              (HEDMA_ENTRY4_ADDR+HEDMA_IDX_OFFSET)
  #define HEDMA_IDX5_ADDR              (HEDMA_ENTRY5_ADDR+HEDMA_IDX_OFFSET)
  #define HEDMA_IDX6_ADDR              (HEDMA_ENTRY6_ADDR+HEDMA_IDX_OFFSET)
  #define HEDMA_IDX7_ADDR              (HEDMA_ENTRY7_ADDR+HEDMA_IDX_OFFSET)
  #define HEDMA_IDX8_ADDR              (HEDMA_ENTRY8_ADDR+HEDMA_IDX_OFFSET)
  #define HEDMA_IDX9_ADDR              (HEDMA_ENTRY9_ADDR+HEDMA_IDX_OFFSET)
  #define HEDMA_IDX10_ADDR             (HEDMA_ENTRY10_ADDR+HEDMA_IDX_OFFSET)
  #define HEDMA_IDX11_ADDR             (HEDMA_ENTRY11_ADDR+HEDMA_IDX_OFFSET)
  #define HEDMA_IDX12_ADDR             (HEDMA_ENTRY12_ADDR+HEDMA_IDX_OFFSET)
  #define HEDMA_IDX13_ADDR             (HEDMA_ENTRY13_ADDR+HEDMA_IDX_OFFSET)
  #define HEDMA_IDX14_ADDR             (HEDMA_ENTRY14_ADDR+HEDMA_IDX_OFFSET)
  #define HEDMA_IDX15_ADDR             (HEDMA_ENTRY15_ADDR+HEDMA_IDX_OFFSET)

  #define HEDMA_IDX0                   REG32(HEDMA_IDX0_ADDR)
  #define HEDMA_IDX1                   REG32(HEDMA_IDX1_ADDR)
  #define HEDMA_IDX2                   REG32(HEDMA_IDX2_ADDR)
  #define HEDMA_IDX3                   REG32(HEDMA_IDX3_ADDR)
  #define HEDMA_IDX4                   REG32(HEDMA_IDX4_ADDR)
  #define HEDMA_IDX5                   REG32(HEDMA_IDX5_ADDR)
  #define HEDMA_IDX6                   REG32(HEDMA_IDX6_ADDR)
  #define HEDMA_IDX7                   REG32(HEDMA_IDX7_ADDR)
  #define HEDMA_IDX8                   REG32(HEDMA_IDX8_ADDR)
  #define HEDMA_IDX9                   REG32(HEDMA_IDX9_ADDR)
  #define HEDMA_IDX10                  REG32(HEDMA_IDX10_ADDR)
  #define HEDMA_IDX11                  REG32(HEDMA_IDX11_ADDR)
  #define HEDMA_IDX12                  REG32(HEDMA_IDX12_ADDR)
  #define HEDMA_IDX13                  REG32(HEDMA_IDX13_ADDR)
  #define HEDMA_IDX14                  REG32(HEDMA_IDX14_ADDR)
  #define HEDMA_IDX15                  REG32(HEDMA_IDX15_ADDR)
  
/*----------------------------------------------------------------------------*\
* (RW) HEDMA_IDX_ELEIDX
\*----------------------------------------------------------------------------*/
  #define HEDMA_IDX_ELEIDX_MASK                (0x0000FFFF)
  #define HEDMA_IDX_ELEIDX_SHIFT               (0x00000000)
  
  #define HEDMA_IDX_ELEIDX_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_IDX_ELEIDX)

  #define HEDMA_IDX_ELEIDX_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_IDX_ELEIDX,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_IDX_FRMIDX
\*----------------------------------------------------------------------------*/
  #define HEDMA_IDX_FRMIDX_MASK                (0xFFFF0000)
  #define HEDMA_IDX_FRMIDX_SHIFT               (0x00000010)
                                      
  #define HEDMA_IDX_FRMIDX_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_IDX_FRMIDX)

  #define HEDMA_IDX_FRMIDX_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_IDX_FRMIDX,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_IDX
\*----------------------------------------------------------------------------*/
  #define HEDMA_IDX_GET(RegAddr) HREG32_GET(RegAddr)
  #define HEDMA_IDX_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HEDMA_IDX_CFG(RegAddr,eleidx,frmidx)\
  REG32(RegAddr)=(UINT32)(\
    HFIELD_SHIFT(HEDMA_IDX_ELEIDX,eleidx)|\
    HFIELD_SHIFT(HEDMA_IDX_FRMIDX,frmidx)\
  )

/******************************************************************************\
* HEDMA_RLD - element reload/link address
*
* Fields:
*   (RW) HEDMA_RLD_LINK
*   (RW) HEDMA_RLD_ELERLD
*
\******************************************************************************/
  #define HEDMA_RLD0_ADDR              (HEDMA_ENTRY0_ADDR+HEDMA_RLD_OFFSET)
  #define HEDMA_RLD1_ADDR              (HEDMA_ENTRY1_ADDR+HEDMA_RLD_OFFSET)
  #define HEDMA_RLD2_ADDR              (HEDMA_ENTRY2_ADDR+HEDMA_RLD_OFFSET)
  #define HEDMA_RLD3_ADDR              (HEDMA_ENTRY3_ADDR+HEDMA_RLD_OFFSET)
  #define HEDMA_RLD4_ADDR              (HEDMA_ENTRY4_ADDR+HEDMA_RLD_OFFSET)
  #define HEDMA_RLD5_ADDR              (HEDMA_ENTRY5_ADDR+HEDMA_RLD_OFFSET)
  #define HEDMA_RLD6_ADDR              (HEDMA_ENTRY6_ADDR+HEDMA_RLD_OFFSET)
  #define HEDMA_RLD7_ADDR              (HEDMA_ENTRY7_ADDR+HEDMA_RLD_OFFSET)
  #define HEDMA_RLD8_ADDR              (HEDMA_ENTRY8_ADDR+HEDMA_RLD_OFFSET)
  #define HEDMA_RLD9_ADDR              (HEDMA_ENTRY9_ADDR+HEDMA_RLD_OFFSET)
  #define HEDMA_RLD10_ADDR             (HEDMA_ENTRY10_ADDR+HEDMA_RLD_OFFSET)
  #define HEDMA_RLD11_ADDR             (HEDMA_ENTRY11_ADDR+HEDMA_RLD_OFFSET)
  #define HEDMA_RLD12_ADDR             (HEDMA_ENTRY12_ADDR+HEDMA_RLD_OFFSET)
  #define HEDMA_RLD13_ADDR             (HEDMA_ENTRY13_ADDR+HEDMA_RLD_OFFSET)
  #define HEDMA_RLD14_ADDR             (HEDMA_ENTRY14_ADDR+HEDMA_RLD_OFFSET)
  #define HEDMA_RLD15_ADDR             (HEDMA_ENTRY15_ADDR+HEDMA_RLD_OFFSET)

  #define HEDMA_RLD0                   REG32(HEDMA_RLD0_ADDR)
  #define HEDMA_RLD1                   REG32(HEDMA_RLD1_ADDR)
  #define HEDMA_RLD2                   REG32(HEDMA_RLD2_ADDR)
  #define HEDMA_RLD3                   REG32(HEDMA_RLD3_ADDR)
  #define HEDMA_RLD4                   REG32(HEDMA_RLD4_ADDR)
  #define HEDMA_RLD5                   REG32(HEDMA_RLD5_ADDR)
  #define HEDMA_RLD6                   REG32(HEDMA_RLD6_ADDR)
  #define HEDMA_RLD7                   REG32(HEDMA_RLD7_ADDR)
  #define HEDMA_RLD8                   REG32(HEDMA_RLD8_ADDR)
  #define HEDMA_RLD9                   REG32(HEDMA_RLD9_ADDR)
  #define HEDMA_RLD10                  REG32(HEDMA_RLD10_ADDR)
  #define HEDMA_RLD11                  REG32(HEDMA_RLD11_ADDR)
  #define HEDMA_RLD12                  REG32(HEDMA_RLD12_ADDR)
  #define HEDMA_RLD13                  REG32(HEDMA_RLD13_ADDR)
  #define HEDMA_RLD14                  REG32(HEDMA_RLD14_ADDR)
  #define HEDMA_RLD15                  REG32(HEDMA_RLD15_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_RLD_LINK
\*----------------------------------------------------------------------------*/
  #define HEDMA_RLD_LINK_MASK                  (0x0000FFFF)
  #define HEDMA_RLD_LINK_SHIFT                 (0x00000000)
  
  #define HEDMA_RLD_LINK_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_RLD_LINK)

  #define HEDMA_RLD_LINK_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_RLD_LINK,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_RLD_ELERLD
\*----------------------------------------------------------------------------*/
  #define HEDMA_RLD_ELERLD_MASK                (0xFFFF0000)
  #define HEDMA_RLD_ELERLD_SHIFT               (0x00000010)
                                      
  #define HEDMA_RLD_ELERLD_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_RLD_ELERLD)

  #define HEDMA_RLD_ELERLD_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_RLD_ELERLD,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_RLD
\*----------------------------------------------------------------------------*/
  #define HEDMA_RLD_GET(RegAddr) HREG32_GET(RegAddr)
  #define HEDMA_RLD_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HEDMA_RLD_CFG(RegAddr,link,elerld)\
  REG32(RegAddr)=(UINT32)(\
    HFIELD_SHIFT(HEDMA_RLD_LINK,link)|\
    HFIELD_SHIFT(HEDMA_RLD_ELERLD,elerld)\
  )

/******************************************************************************\
* HEDMA_PQSR - priority queue status register
*
* Fields:
*   (R) HEDMA_PQSR_PQ0
*   (R) HEDMA_PQSR_PQ1
*   (R) HEDMA_PQSR_PQ2
*
\******************************************************************************/
  #define HEDMA_PQSR_ADDR                      (HEDMA_BASE0_ADDR+0xFFE0)
  #define HEDMA_PQSR                           REG32(HEDMA_PQSR_ADDR)

/*----------------------------------------------------------------------------*\
* (R) HEDMA_PQSR_PQ0
\*----------------------------------------------------------------------------*/
  #define HEDMA_PQSR_PQ0_MASK                  (0x00000001)
  #define HEDMA_PQSR_PQ0_SHIFT                 (0x00000000)
  
  #define HEDMA_PQSR_PQ0_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_PQSR_PQ0)

/*----------------------------------------------------------------------------*\
* (R) HEDMA_PQSR_PQ1
\*----------------------------------------------------------------------------*/
  #define HEDMA_PQSR_PQ1_MASK                  (0x00000002)
  #define HEDMA_PQSR_PQ1_SHIFT                 (0x00000001)
  
  #define HEDMA_PQSR_PQ1_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_PQSR_PQ1)

/*----------------------------------------------------------------------------*\
* (R) HEDMA_PQSR_PQ2
\*----------------------------------------------------------------------------*/
  #define HEDMA_PQSR_PQ2_MASK                  (0x00000004)
  #define HEDMA_PQSR_PQ2_SHIFT                 (0x00000002)

  #define HEDMA_PQSR_PQ2_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_PQSR_PQ2)

/*----------------------------------------------------------------------------*\
* (R) HEDMA_PQSR
\*----------------------------------------------------------------------------*/
  #define HEDMA_PQSR_GET(RegAddr) HREG32_GET(RegAddr)

/******************************************************************************\
* HEDMA_CIPR - channel interrupt pending register
*
* Fields:
*   (RW) HEDMA_CIPR_CIP0
*   (RW) HEDMA_CIPR_CIP1
*   (RW) HEDMA_CIPR_CIP2
*   (RW) HEDMA_CIPR_CIP3
*   (RW) HEDMA_CIPR_CIP4
*   (RW) HEDMA_CIPR_CIP5
*   (RW) HEDMA_CIPR_CIP6
*   (RW) HEDMA_CIPR_CIP7
*   (RW) HEDMA_CIPR_CIP8
*   (RW) HEDMA_CIPR_CIP9
*   (RW) HEDMA_CIPR_CIP10
*   (RW) HEDMA_CIPR_CIP11
*   (RW) HEDMA_CIPR_CIP12
*   (RW) HEDMA_CIPR_CIP13
*   (RW) HEDMA_CIPR_CIP14
*   (RW) HEDMA_CIPR_CIP15
*
\******************************************************************************/
  #define HEDMA_CIPR_ADDR                      (HEDMA_BASE0_ADDR+0xFFE4)
  #define HEDMA_CIPR                           REG32(HEDMA_CIPR_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIPR_CIP0
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIPR_CIP0_MASK                 (0x00000001)
  #define HEDMA_CIPR_CIP0_SHIFT                (0x00000000)
  
  #define HEDMA_CIPR_CIP0_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIPR_CIP0)

  #define HEDMA_CIPR_CIP0_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIPR_CIP0,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIPR_CIP1
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIPR_CIP1_MASK                 (0x00000002)
  #define HEDMA_CIPR_CIP1_SHIFT                (0x00000001)
  
  #define HEDMA_CIPR_CIP1_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIPR_CIP1)

  #define HEDMA_CIPR_CIP1_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIPR_CIP1,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIPR_CIP2
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIPR_CIP2_MASK                 (0x00000004)
  #define HEDMA_CIPR_CIP2_SHIFT                (0x00000002)
  
  #define HEDMA_CIPR_CIP2_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIPR_CIP2)

  #define HEDMA_CIPR_CIP2_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIPR_CIP2,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIPR_CIP3
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIPR_CIP3_MASK                 (0x00000008)
  #define HEDMA_CIPR_CIP3_SHIFT                (0x00000003)
  
  #define HEDMA_CIPR_CIP3_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIPR_CIP3)

  #define HEDMA_CIPR_CIP3_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIPR_CIP3,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIPR_CIP4
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIPR_CIP4_MASK                 (0x00000010)
  #define HEDMA_CIPR_CIP4_SHIFT                (0x00000004)
  
  #define HEDMA_CIPR_CIP4_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIPR_CIP4)

  #define HEDMA_CIPR_CIP4_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIPR_CIP4,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIPR_CIP5
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIPR_CIP5_MASK                 (0x00000020)
  #define HEDMA_CIPR_CIP5_SHIFT                (0x00000005)
  
  #define HEDMA_CIPR_CIP5_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIPR_CIP5)

  #define HEDMA_CIPR_CIP5_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIPR_CIP5,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIPR_CIP6
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIPR_CIP6_MASK                 (0x00000040)
  #define HEDMA_CIPR_CIP6_SHIFT                (0x00000006)
  
  #define HEDMA_CIPR_CIP6_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIPR_CIP6)

  #define HEDMA_CIPR_CIP6_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIPR_CIP6,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIPR_CIP7
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIPR_CIP7_MASK                 (0x00000080)
  #define HEDMA_CIPR_CIP7_SHIFT                (0x00000007)
  
  #define HEDMA_CIPR_CIP7_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIPR_CIP7)

  #define HEDMA_CIPR_CIP7_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIPR_CIP7,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIPR_CIP8
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIPR_CIP8_MASK                 (0x00000100)
  #define HEDMA_CIPR_CIP8_SHIFT                (0x00000008)
  
  #define HEDMA_CIPR_CIP8_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIPR_CIP8)

  #define HEDMA_CIPR_CIP8_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIPR_CIP8,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIPR_CIP9
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIPR_CIP9_MASK                 (0x00000200)
  #define HEDMA_CIPR_CIP9_SHIFT                (0x00000009)
  
  #define HEDMA_CIPR_CIP9_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIPR_CIP9)

  #define HEDMA_CIPR_CIP9_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIPR_CIP9,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIPR_CIP10
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIPR_CIP10_MASK                (0x00000400)
  #define HEDMA_CIPR_CIP10_SHIFT               (0x0000000A)
  
  #define HEDMA_CIPR_CIP10_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIPR_CIP10)

  #define HEDMA_CIPR_CIP10_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIPR_CIP10,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIPR_CIP11
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIPR_CIP11_MASK                (0x00000800)
  #define HEDMA_CIPR_CIP11_SHIFT               (0x0000000B)
  
  #define HEDMA_CIPR_CIP11_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIPR_CIP11)

  #define HEDMA_CIPR_CIP11_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIPR_CIP11,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIPR_CIP12
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIPR_CIP12_MASK                (0x00001000)
  #define HEDMA_CIPR_CIP12_SHIFT               (0x0000000C)
  
  #define HEDMA_CIPR_CIP12_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIPR_CIP12)

  #define HEDMA_CIPR_CIP12_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIPR_CIP12,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIPR_CIP13
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIPR_CIP13_MASK                (0x00002000)
  #define HEDMA_CIPR_CIP13_SHIFT               (0x0000000D)
  
  #define HEDMA_CIPR_CIP13_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIPR_CIP13)

  #define HEDMA_CIPR_CIP13_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIPR_CIP13,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIPR_CIP14
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIPR_CIP14_MASK                (0x00004000)
  #define HEDMA_CIPR_CIP14_SHIFT               (0x0000000E)
  
  #define HEDMA_CIPR_CIP14_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIPR_CIP14)

  #define HEDMA_CIPR_CIP14_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIPR_CIP14,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIPR_CIP15
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIPR_CIP15_MASK                (0x00008000)
  #define HEDMA_CIPR_CIP15_SHIFT               (0x0000000F)
  
  #define HEDMA_CIPR_CIP15_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIPR_CIP15)

  #define HEDMA_CIPR_CIP15_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIPR_CIP15,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIPR
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIPR_GET(RegAddr) HREG32_GET(RegAddr)
  #define HEDMA_CIPR_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HEDMA_CIPR_CFG(RegAddr,cip0,cip1,cip2,cip3,cip4,cip5,cip6,cip7,\
  cip8,cip9,cip10,cip11,cip12,cip13,cip14,cip15) REG32(RegAddr)=(UINT32)(\
    HFIELD_SHIFT(HEDMA_CIPR_CIP0,cip0)|\
    HFIELD_SHIFT(HEDMA_CIPR_CIP1,cip1)|\
    HFIELD_SHIFT(HEDMA_CIPR_CIP2,cip2)|\
    HFIELD_SHIFT(HEDMA_CIPR_CIP3,cip3)|\
    HFIELD_SHIFT(HEDMA_CIPR_CIP4,cip4)|\
    HFIELD_SHIFT(HEDMA_CIPR_CIP5,cip5)|\
    HFIELD_SHIFT(HEDMA_CIPR_CIP6,cip6)|\
    HFIELD_SHIFT(HEDMA_CIPR_CIP7,cip7)|\
    HFIELD_SHIFT(HEDMA_CIPR_CIP8,cip8)|\
    HFIELD_SHIFT(HEDMA_CIPR_CIP9,cip9)|\
    HFIELD_SHIFT(HEDMA_CIPR_CIP10,cip10)|\
    HFIELD_SHIFT(HEDMA_CIPR_CIP11,cip11)|\
    HFIELD_SHIFT(HEDMA_CIPR_CIP12,cip12)|\
    HFIELD_SHIFT(HEDMA_CIPR_CIP13,cip13)|\
    HFIELD_SHIFT(HEDMA_CIPR_CIP14,cip14)|\
    HFIELD_SHIFT(HEDMA_CIPR_CIP15,cip15)\
  )

/******************************************************************************\
* HEDMA_CIER - channel interrupt enable register
*
* Fields:
*   (RW) HEDMA_CIER_CIE0
*   (RW) HEDMA_CIER_CIE1
*   (RW) HEDMA_CIER_CIE2
*   (RW) HEDMA_CIER_CIE3
*   (RW) HEDMA_CIER_CIE4
*   (RW) HEDMA_CIER_CIE5
*   (RW) HEDMA_CIER_CIE6
*   (RW) HEDMA_CIER_CIE7
*   (RW) HEDMA_CIER_CIE8
*   (RW) HEDMA_CIER_CIE9
*   (RW) HEDMA_CIER_CIE10
*   (RW) HEDMA_CIER_CIE11
*   (RW) HEDMA_CIER_CIE12
*   (RW) HEDMA_CIER_CIE13
*   (RW) HEDMA_CIER_CIE14
*   (RW) HEDMA_CIER_CIE15
*
\******************************************************************************/
  #define HEDMA_CIER_ADDR                      (HEDMA_BASE0_ADDR+0xFFE8)
  #define HEDMA_CIER                           REG32(HEDMA_CIER_ADDR)
  
/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIER_CIE0
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIER_CIE0_MASK                 (0x00000001)
  #define HEDMA_CIER_CIE0_SHIFT                (0x00000000)
  
  #define HEDMA_CIER_CIE0_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIER_CIE0)

  #define HEDMA_CIER_CIE0_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIER_CIE0,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIER_CIE1
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIER_CIE1_MASK                 (0x00000002)
  #define HEDMA_CIER_CIE1_SHIFT                (0x00000001)
  
  #define HEDMA_CIER_CIE1_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIER_CIE1)

  #define HEDMA_CIER_CIE1_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIER_CIE1,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIER_CIE2
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIER_CIE2_MASK                 (0x00000004)
  #define HEDMA_CIER_CIE2_SHIFT                (0x00000002)
  
  #define HEDMA_CIER_CIE2_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIER_CIE2)

  #define HEDMA_CIER_CIE2_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIER_CIE2,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIER_CIE3
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIER_CIE3_MASK                 (0x00000008)
  #define HEDMA_CIER_CIE3_SHIFT                (0x00000003)
  
  #define HEDMA_CIER_CIE3_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIER_CIE3)

  #define HEDMA_CIER_CIE3_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIER_CIE3,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIER_CIE4
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIER_CIE4_MASK                 (0x00000010)
  #define HEDMA_CIER_CIE4_SHIFT                (0x00000004)
  
  #define HEDMA_CIER_CIE4_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIER_CIE4)

  #define HEDMA_CIER_CIE4_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIER_CIE4,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIER_CIE5
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIER_CIE5_MASK                 (0x00000020)
  #define HEDMA_CIER_CIE5_SHIFT                (0x00000005)
  
  #define HEDMA_CIER_CIE5_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIER_CIE5)

  #define HEDMA_CIER_CIE5_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIER_CIE5,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIER_CIE6
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIER_CIE6_MASK                 (0x00000040)
  #define HEDMA_CIER_CIE6_SHIFT                (0x00000006)
  
  #define HEDMA_CIER_CIE6_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIER_CIE6)

  #define HEDMA_CIER_CIE6_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIER_CIE6,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIER_CIE7
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIER_CIE7_MASK                 (0x00000080)
  #define HEDMA_CIER_CIE7_SHIFT                (0x00000007)
  
  #define HEDMA_CIER_CIE7_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIER_CIE7)

  #define HEDMA_CIER_CIE7_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIER_CIE7,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIER_CIE8
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIER_CIE8_MASK                 (0x00000100)
  #define HEDMA_CIER_CIE8_SHIFT                (0x00000008)
  
  #define HEDMA_CIER_CIE8_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIER_CIE8)

  #define HEDMA_CIER_CIE8_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIER_CIE8,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIER_CIE9
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIER_CIE9_MASK                 (0x00000200)
  #define HEDMA_CIER_CIE9_SHIFT                (0x00000009)
  
  #define HEDMA_CIER_CIE9_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIER_CIE9)

  #define HEDMA_CIER_CIE9_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIER_CIE9,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIER_CIE10
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIER_CIE10_MASK                (0x00000400)
  #define HEDMA_CIER_CIE10_SHIFT               (0x0000000A)
  
  #define HEDMA_CIER_CIE10_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIER_CIE10)

  #define HEDMA_CIER_CIE10_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIER_CIE10,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIER_CIE11
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIER_CIE11_MASK                (0x00000800)
  #define HEDMA_CIER_CIE11_SHIFT               (0x0000000B)
  
  #define HEDMA_CIER_CIE11_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIER_CIE11)

  #define HEDMA_CIER_CIE11_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIER_CIE11,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIER_CIE12
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIER_CIE12_MASK                (0x00001000)
  #define HEDMA_CIER_CIE12_SHIFT               (0x0000000C)
  
  #define HEDMA_CIER_CIE12_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIER_CIE12)

  #define HEDMA_CIER_CIE12_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIER_CIE12,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIER_CIE13
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIER_CIE13_MASK                (0x00002000)
  #define HEDMA_CIER_CIE13_SHIFT               (0x0000000D)
  
  #define HEDMA_CIER_CIE13_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIER_CIE13)

  #define HEDMA_CIER_CIE13_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIER_CIE13,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIER_CIE14
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIER_CIE14_MASK                (0x00004000)
  #define HEDMA_CIER_CIE14_SHIFT               (0x0000000E)
  
  #define HEDMA_CIER_CIE14_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIER_CIE14)

  #define HEDMA_CIER_CIE14_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIER_CIE14,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIER_CIE15
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIER_CIE15_MASK                (0x00008000)
  #define HEDMA_CIER_CIE15_SHIFT               (0x0000000F)
  
  #define HEDMA_CIER_CIE15_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CIER_CIE15)

  #define HEDMA_CIER_CIE15_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CIER_CIE15,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CIER
\*----------------------------------------------------------------------------*/
  #define HEDMA_CIER_GET(RegAddr) HREG32_GET(RegAddr)
  #define HEDMA_CIER_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HEDMA_CIER_CFG(RegAddr,cie0,cie1,cie2,cie3,cie4,cie5,cie6,cie7,\
  cie8,cie9,cie10,cie11,cie12,cie13,cie14,cie15) REG32(RegAddr)=(UINT32)(\
    HFIELD_SHIFT(HEDMA_CIER_CIE0,cie0)|\
    HFIELD_SHIFT(HEDMA_CIER_CIE1,cie1)|\
    HFIELD_SHIFT(HEDMA_CIER_CIE2,cie2)|\
    HFIELD_SHIFT(HEDMA_CIER_CIE3,cie3)|\
    HFIELD_SHIFT(HEDMA_CIER_CIE4,cie4)|\
    HFIELD_SHIFT(HEDMA_CIER_CIE5,cie5)|\
    HFIELD_SHIFT(HEDMA_CIER_CIE6,cie6)|\
    HFIELD_SHIFT(HEDMA_CIER_CIE7,cie7)|\
    HFIELD_SHIFT(HEDMA_CIER_CIE8,cie8)|\
    HFIELD_SHIFT(HEDMA_CIER_CIE9,cie9)|\
    HFIELD_SHIFT(HEDMA_CIER_CIE10,cie10)|\
    HFIELD_SHIFT(HEDMA_CIER_CIE11,cie11)|\
    HFIELD_SHIFT(HEDMA_CIER_CIE12,cie12)|\
    HFIELD_SHIFT(HEDMA_CIER_CIE13,cie13)|\
    HFIELD_SHIFT(HEDMA_CIER_CIE14,cie14)|\
    HFIELD_SHIFT(HEDMA_CIER_CIE15,cie15)\
  )

/******************************************************************************\
* HEDMA_CCER - channel chain enable register
*
* Fields:
*   (RW) HEDMA_CCER_CCE8
*   (RW) HEDMA_CCER_CCE9
*   (RW) HEDMA_CCER_CCE10
*   (RW) HEDMA_CCER_CCE11
*
\******************************************************************************/
  #define HEDMA_CCER_ADDR                      (HEDMA_BASE0_ADDR+0xFFEC)
  #define HEDMA_CCER                           REG32(HEDMA_CCER_ADDR)
  
/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CCER_CCE8
\*----------------------------------------------------------------------------*/
  #define HEDMA_CCER_CCE8_MASK                 (0x00000100)
  #define HEDMA_CCER_CCE8_SHIFT                (0x00000008)
  
  #define HEDMA_CCER_CCE8_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CCER_CCE8)

  #define HEDMA_CCER_CCE8_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CCER_CCE8,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CCER_CCE9
\*----------------------------------------------------------------------------*/
  #define HEDMA_CCER_CCE9_MASK                 (0x00000200)
  #define HEDMA_CCER_CCE9_SHIFT                (0x00000009)
  
  #define HEDMA_CCER_CCE9_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CCER_CCE9)

  #define HEDMA_CCER_CCE9_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CCER_CCE9,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CCER_CCE10
\*----------------------------------------------------------------------------*/
  #define HEDMA_CCER_CCE10_MASK                (0x00000400)
  #define HEDMA_CCER_CCE10_SHIFT               (0x0000000A)
  
  #define HEDMA_CCER_CCE10_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CCER_CCE10)

  #define HEDMA_CCER_CCE10_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CCER_CCE10,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CCER_CCE11
\*----------------------------------------------------------------------------*/
  #define HEDMA_CCER_CCE11_MASK                (0x00000800)
  #define HEDMA_CCER_CCE11_SHIFT               (0x0000000B)
  
  #define HEDMA_CCER_CCE11_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_CCER_CCE11)

  #define HEDMA_CCER_CCE11_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_CCER_CCE11,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_CCER
\*----------------------------------------------------------------------------*/
  #define HEDMA_CCER_GET(RegAddr) HREG32_GET(RegAddr)
  #define HEDMA_CCER_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HEDMA_CCER_CFG(RegAddr,cce8,cce9,cce10,cce11)\
  REG32(RegAddr)=(UINT32)(\
    HFIELD_SHIFT(HEDMA_CCER_CCE8,cce8)|\
    HFIELD_SHIFT(HEDMA_CCER_CCE9,cce9)|\
    HFIELD_SHIFT(HEDMA_CCER_CCE10,cce10)|\
    HFIELD_SHIFT(HEDMA_CCER_CCE11,cce11)\
  )

/******************************************************************************\
* HEDMA_ER   - event register
*
* Fields:
*   (R) HEDMA_ER_EVT0
*   (R) HEDMA_ER_EVT1
*   (R) HEDMA_ER_EVT2
*   (R) HEDMA_ER_EVT3
*   (R) HEDMA_ER_EVT4
*   (R) HEDMA_ER_EVT5
*   (R) HEDMA_ER_EVT6
*   (R) HEDMA_ER_EVT7
*   (R) HEDMA_ER_EVT8
*   (R) HEDMA_ER_EVT9
*   (R) HEDMA_ER_EVT10
*   (R) HEDMA_ER_EVT11
*   (R) HEDMA_ER_EVT12
*   (R) HEDMA_ER_EVT13
*   (R) HEDMA_ER_EVT14
*   (R) HEDMA_ER_EVT15
*
\******************************************************************************/
  #define HEDMA_ER_ADDR                        (HEDMA_BASE0_ADDR+0xFFF0)
  #define HEDMA_ER                             REG32(HEDMA_ER_ADDR)
  
/*----------------------------------------------------------------------------*\
* (R) HEDMA_ER_EVT0
\*----------------------------------------------------------------------------*/
  #define HEDMA_ER_EVT0_MASK                 (0x00000001)
  #define HEDMA_ER_EVT0_SHIFT                (0x00000000)
  
  #define HEDMA_ER_EVT0_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ER_EVT0)

/*----------------------------------------------------------------------------*\
* (R) HEDMA_ER_EVT1
\*----------------------------------------------------------------------------*/
  #define HEDMA_ER_EVT1_MASK                 (0x00000002)
  #define HEDMA_ER_EVT1_SHIFT                (0x00000001)
  
  #define HEDMA_ER_EVT1_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ER_EVT1)

/*----------------------------------------------------------------------------*\
* (R) HEDMA_ER_EVT2
\*----------------------------------------------------------------------------*/
  #define HEDMA_ER_EVT2_MASK                 (0x00000004)
  #define HEDMA_ER_EVT2_SHIFT                (0x00000002)
  
  #define HEDMA_ER_EVT2_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ER_EVT2)

/*----------------------------------------------------------------------------*\
* (R) HEDMA_ER_EVT3
\*----------------------------------------------------------------------------*/
  #define HEDMA_ER_EVT3_MASK                 (0x00000008)
  #define HEDMA_ER_EVT3_SHIFT                (0x00000003)
  
  #define HEDMA_ER_EVT3_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ER_EVT3)

/*----------------------------------------------------------------------------*\
* (R) HEDMA_ER_EVT4
\*----------------------------------------------------------------------------*/
  #define HEDMA_ER_EVT4_MASK                 (0x00000010)
  #define HEDMA_ER_EVT4_SHIFT                (0x00000004)
  
  #define HEDMA_ER_EVT4_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ER_EVT4)

/*----------------------------------------------------------------------------*\
* (R) HEDMA_ER_EVT5
\*----------------------------------------------------------------------------*/
  #define HEDMA_ER_EVT5_MASK                 (0x00000020)
  #define HEDMA_ER_EVT5_SHIFT                (0x00000005)
  
  #define HEDMA_ER_EVT5_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ER_EVT5)

/*----------------------------------------------------------------------------*\
* (R) HEDMA_ER_EVT6
\*----------------------------------------------------------------------------*/
  #define HEDMA_ER_EVT6_MASK                 (0x00000040)
  #define HEDMA_ER_EVT6_SHIFT                (0x00000006)
  
  #define HEDMA_ER_EVT6_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ER_EVT6)

/*----------------------------------------------------------------------------*\
* (R) HEDMA_ER_EVT7
\*----------------------------------------------------------------------------*/
  #define HEDMA_ER_EVT7_MASK                 (0x00000080)
  #define HEDMA_ER_EVT7_SHIFT                (0x00000007)
  
  #define HEDMA_ER_EVT7_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ER_EVT7)

/*----------------------------------------------------------------------------*\
* (R) HEDMA_ER_EVT8
\*----------------------------------------------------------------------------*/
  #define HEDMA_ER_EVT8_MASK                 (0x00000100)
  #define HEDMA_ER_EVT8_SHIFT                (0x00000008)
  
  #define HEDMA_ER_EVT8_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ER_EVT8)

/*----------------------------------------------------------------------------*\
* (R) HEDMA_ER_EVT9
\*----------------------------------------------------------------------------*/
  #define HEDMA_ER_EVT9_MASK                 (0x00000200)
  #define HEDMA_ER_EVT9_SHIFT                (0x00000009)
  
  #define HEDMA_ER_EVT9_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ER_EVT9)

/*----------------------------------------------------------------------------*\
* (R) HEDMA_ER_EVT10
\*----------------------------------------------------------------------------*/
  #define HEDMA_ER_EVT10_MASK                (0x00000400)
  #define HEDMA_ER_EVT10_SHIFT               (0x0000000A)
  
  #define HEDMA_ER_EVT10_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ER_EVT10)

/*----------------------------------------------------------------------------*\
* (R) HEDMA_ER_EVT11
\*----------------------------------------------------------------------------*/
  #define HEDMA_ER_EVT11_MASK                (0x00000800)
  #define HEDMA_ER_EVT11_SHIFT               (0x0000000B)
  
  #define HEDMA_ER_EVT11_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ER_EVT11)

/*----------------------------------------------------------------------------*\
* (R) HEDMA_ER_EVT12
\*----------------------------------------------------------------------------*/
  #define HEDMA_ER_EVT12_MASK                (0x00001000)
  #define HEDMA_ER_EVT12_SHIFT               (0x0000000C)
  
  #define HEDMA_ER_EVT12_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ER_EVT12)

/*----------------------------------------------------------------------------*\
* (R) HEDMA_ER_EVT13
\*----------------------------------------------------------------------------*/
  #define HEDMA_ER_EVT13_MASK                (0x00002000)
  #define HEDMA_ER_EVT13_SHIFT               (0x0000000D)
  
  #define HEDMA_ER_EVT13_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ER_EVT13)

/*----------------------------------------------------------------------------*\
* (R) HEDMA_ER_EVT14
\*----------------------------------------------------------------------------*/
  #define HEDMA_ER_EVT14_MASK                (0x00004000)
  #define HEDMA_ER_EVT14_SHIFT               (0x0000000E)
  
  #define HEDMA_ER_EVT14_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ER_EVT14)

/*----------------------------------------------------------------------------*\
* (R) HEDMA_ER_EVT15
\*----------------------------------------------------------------------------*/
  #define HEDMA_ER_EVT15_MASK                (0x00008000)
  #define HEDMA_ER_EVT15_SHIFT               (0x0000000F)
  
  #define HEDMA_ER_EVT15_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ER_EVT15)

/*----------------------------------------------------------------------------*\
* (R) HEDMA_ER
\*----------------------------------------------------------------------------*/
  #define HEDMA_ER_GET(RegAddr) HREG32_GET(RegAddr)

/******************************************************************************\
* HEDMA_EER  - event enable register
*
* Fields:
*   (RW) HEDMA_EER_EE0
*   (RW) HEDMA_EER_EE1
*   (RW) HEDMA_EER_EE2
*   (RW) HEDMA_EER_EE3
*   (RW) HEDMA_EER_EE4
*   (RW) HEDMA_EER_EE5
*   (RW) HEDMA_EER_EE6
*   (RW) HEDMA_EER_EE7
*   (RW) HEDMA_EER_EE8
*   (RW) HEDMA_EER_EE9
*   (RW) HEDMA_EER_EE10
*   (RW) HEDMA_EER_EE11
*   (RW) HEDMA_EER_EE12
*   (RW) HEDMA_EER_EE13
*   (RW) HEDMA_EER_EE14
*   (RW) HEDMA_EER_EE15
*
\******************************************************************************/
  #define HEDMA_EER_ADDR                       (HEDMA_BASE0_ADDR+0xFFF4)
  #define HEDMA_EER                            REG32(HEDMA_EER_ADDR)
  
/*----------------------------------------------------------------------------*\
* (RW) HEDMA_EER_EE0
\*----------------------------------------------------------------------------*/
  #define HEDMA_EER_EE0_MASK                 (0x00000001)
  #define HEDMA_EER_EE0_SHIFT                (0x00000000)
  
  #define HEDMA_EER_EE0_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_EER_EE0)

  #define HEDMA_EER_EE0_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_EER_EE0,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_EER_EE1
\*----------------------------------------------------------------------------*/
  #define HEDMA_EER_EE1_MASK                 (0x00000002)
  #define HEDMA_EER_EE1_SHIFT                (0x00000001)
  
  #define HEDMA_EER_EE1_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_EER_EE1)

  #define HEDMA_EER_EE1_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_EER_EE1,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_EER_EE2
\*----------------------------------------------------------------------------*/
  #define HEDMA_EER_EE2_MASK                 (0x00000004)
  #define HEDMA_EER_EE2_SHIFT                (0x00000002)
  
  #define HEDMA_EER_EE2_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_EER_EE2)

  #define HEDMA_EER_EE2_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_EER_EE2,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_EER_EE3
\*----------------------------------------------------------------------------*/
  #define HEDMA_EER_EE3_MASK                 (0x00000008)
  #define HEDMA_EER_EE3_SHIFT                (0x00000003)
  
  #define HEDMA_EER_EE3_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_EER_EE3)

  #define HEDMA_EER_EE3_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_EER_EE3,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_EER_EE4
\*----------------------------------------------------------------------------*/
  #define HEDMA_EER_EE4_MASK                 (0x00000010)
  #define HEDMA_EER_EE4_SHIFT                (0x00000004)
  
  #define HEDMA_EER_EE4_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_EER_EE4)

  #define HEDMA_EER_EE4_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_EER_EE4,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_EER_EE5
\*----------------------------------------------------------------------------*/
  #define HEDMA_EER_EE5_MASK                 (0x00000020)
  #define HEDMA_EER_EE5_SHIFT                (0x00000005)
  
  #define HEDMA_EER_EE5_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_EER_EE5)

  #define HEDMA_EER_EE5_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_EER_EE5,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_EER_EE6
\*----------------------------------------------------------------------------*/
  #define HEDMA_EER_EE6_MASK                 (0x00000040)
  #define HEDMA_EER_EE6_SHIFT                (0x00000006)
  
  #define HEDMA_EER_EE6_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_EER_EE6)

  #define HEDMA_EER_EE6_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_EER_EE6,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_EER_EE7
\*----------------------------------------------------------------------------*/
  #define HEDMA_EER_EE7_MASK                 (0x00000080)
  #define HEDMA_EER_EE7_SHIFT                (0x00000007)
  
  #define HEDMA_EER_EE7_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_EER_EE7)

  #define HEDMA_EER_EE7_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_EER_EE7,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_EER_EE8
\*----------------------------------------------------------------------------*/
  #define HEDMA_EER_EE8_MASK                 (0x00000100)
  #define HEDMA_EER_EE8_SHIFT                (0x00000008)
  
  #define HEDMA_EER_EE8_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_EER_EE8)

  #define HEDMA_EER_EE8_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_EER_EE8,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_EER_EE9
\*----------------------------------------------------------------------------*/
  #define HEDMA_EER_EE9_MASK                 (0x00000200)
  #define HEDMA_EER_EE9_SHIFT                (0x00000009)
  
  #define HEDMA_EER_EE9_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_EER_EE9)

  #define HEDMA_EER_EE9_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_EER_EE9,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_EER_EE10
\*----------------------------------------------------------------------------*/
  #define HEDMA_EER_EE10_MASK                (0x00000400)
  #define HEDMA_EER_EE10_SHIFT               (0x0000000A)
  
  #define HEDMA_EER_EE10_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_EER_EE10)

  #define HEDMA_EER_EE10_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_EER_EE10,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_EER_EE11
\*----------------------------------------------------------------------------*/
  #define HEDMA_EER_EE11_MASK                (0x00000800)
  #define HEDMA_EER_EE11_SHIFT               (0x0000000B)
  
  #define HEDMA_EER_EE11_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_EER_EE11)

  #define HEDMA_EER_EE11_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_EER_EE11,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_EER_EE12
\*----------------------------------------------------------------------------*/
  #define HEDMA_EER_EE12_MASK                (0x00001000)
  #define HEDMA_EER_EE12_SHIFT               (0x0000000C)
  
  #define HEDMA_EER_EE12_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_EER_EE12)

  #define HEDMA_EER_EE12_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_EER_EE12,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_EER_EE13
\*----------------------------------------------------------------------------*/
  #define HEDMA_EER_EE13_MASK                (0x00002000)
  #define HEDMA_EER_EE13_SHIFT               (0x0000000D)
  
  #define HEDMA_EER_EE13_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_EER_EE13)

  #define HEDMA_EER_EE13_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_EER_EE13,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_EER_EE14
\*----------------------------------------------------------------------------*/
  #define HEDMA_EER_EE14_MASK                (0x00004000)
  #define HEDMA_EER_EE14_SHIFT               (0x0000000E)
  
  #define HEDMA_EER_EE14_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_EER_EE14)

  #define HEDMA_EER_EE14_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_EER_EE14,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_EER_EE15
\*----------------------------------------------------------------------------*/
  #define HEDMA_EER_EE15_MASK                (0x00008000)
  #define HEDMA_EER_EE15_SHIFT               (0x0000000F)
  
  #define HEDMA_EER_EE15_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_EER_EE15)

  #define HEDMA_EER_EE15_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_EER_EE15,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_EER
\*----------------------------------------------------------------------------*/
  #define HEDMA_EER_GET(RegAddr) HREG32_GET(RegAddr)
  #define HEDMA_EER_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HEDMA_EER_CFG(RegAddr,ee0,ee1,ee2,ee3,ee4,ee5,ee6,ee7,\
  ee8,ee9,ee10,ee11,ee12,ee13,ee14,ee15) REG32(RegAddr)=(UINT32)(\
    HFIELD_SHIFT(HEDMA_EER_EE0,ee0)|\
    HFIELD_SHIFT(HEDMA_EER_EE1,ee1)|\
    HFIELD_SHIFT(HEDMA_EER_EE2,ee2)|\
    HFIELD_SHIFT(HEDMA_EER_EE3,ee3)|\
    HFIELD_SHIFT(HEDMA_EER_EE4,ee4)|\
    HFIELD_SHIFT(HEDMA_EER_EE5,ee5)|\
    HFIELD_SHIFT(HEDMA_EER_EE6,ee6)|\
    HFIELD_SHIFT(HEDMA_EER_EE7,ee7)|\
    HFIELD_SHIFT(HEDMA_EER_EE8,ee8)|\
    HFIELD_SHIFT(HEDMA_EER_EE9,ee9)|\
    HFIELD_SHIFT(HEDMA_EER_EE10,ee10)|\
    HFIELD_SHIFT(HEDMA_EER_EE11,ee11)|\
    HFIELD_SHIFT(HEDMA_EER_EE12,ee12)|\
    HFIELD_SHIFT(HEDMA_EER_EE13,ee13)|\
    HFIELD_SHIFT(HEDMA_EER_EE14,ee14)|\
    HFIELD_SHIFT(HEDMA_EER_EE15,ee15)\
  )

/******************************************************************************\
* HEDMA_ECR  - event clear register
*
* Fields:
*   (RW) HEDMA_ECR_EC0
*   (RW) HEDMA_ECR_EC1
*   (RW) HEDMA_ECR_EC2
*   (RW) HEDMA_ECR_EC3
*   (RW) HEDMA_ECR_EC4
*   (RW) HEDMA_ECR_EC5
*   (RW) HEDMA_ECR_EC6
*   (RW) HEDMA_ECR_EC7
*   (RW) HEDMA_ECR_EC8
*   (RW) HEDMA_ECR_EC9
*   (RW) HEDMA_ECR_EC10
*   (RW) HEDMA_ECR_EC11
*   (RW) HEDMA_ECR_EC12
*   (RW) HEDMA_ECR_EC13
*   (RW) HEDMA_ECR_EC14
*   (RW) HEDMA_ECR_EC15
*
\******************************************************************************/
  #define HEDMA_ECR_ADDR                       (HEDMA_BASE0_ADDR+0xFFF8)
  #define HEDMA_ECR                            REG32(HEDMA_ECR_ADDR)
  
/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ECR_EC0
\*----------------------------------------------------------------------------*/
  #define HEDMA_ECR_EC0_MASK                 (0x00000001)
  #define HEDMA_ECR_EC0_SHIFT                (0x00000000)
  
  #define HEDMA_ECR_EC0_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ECR_EC0)

  #define HEDMA_ECR_EC0_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ECR_EC0,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ECR_EC1
\*----------------------------------------------------------------------------*/
  #define HEDMA_ECR_EC1_MASK                 (0x00000002)
  #define HEDMA_ECR_EC1_SHIFT                (0x00000001)
  
  #define HEDMA_ECR_EC1_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ECR_EC1)

  #define HEDMA_ECR_EC1_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ECR_EC1,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ECR_EC2
\*----------------------------------------------------------------------------*/
  #define HEDMA_ECR_EC2_MASK                 (0x00000004)
  #define HEDMA_ECR_EC2_SHIFT                (0x00000002)
  
  #define HEDMA_ECR_EC2_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ECR_EC2)

  #define HEDMA_ECR_EC2_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ECR_EC2,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ECR_EC3
\*----------------------------------------------------------------------------*/
  #define HEDMA_ECR_EC3_MASK                 (0x00000008)
  #define HEDMA_ECR_EC3_SHIFT                (0x00000003)
  
  #define HEDMA_ECR_EC3_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ECR_EC3)

  #define HEDMA_ECR_EC3_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ECR_EC3,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ECR_EC4
\*----------------------------------------------------------------------------*/
  #define HEDMA_ECR_EC4_MASK                 (0x00000010)
  #define HEDMA_ECR_EC4_SHIFT                (0x00000004)
  
  #define HEDMA_ECR_EC4_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ECR_EC4)

  #define HEDMA_ECR_EC4_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ECR_EC4,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ECR_EC5
\*----------------------------------------------------------------------------*/
  #define HEDMA_ECR_EC5_MASK                 (0x00000020)
  #define HEDMA_ECR_EC5_SHIFT                (0x00000005)
  
  #define HEDMA_ECR_EC5_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ECR_EC5)

  #define HEDMA_ECR_EC5_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ECR_EC5,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ECR_EC6
\*----------------------------------------------------------------------------*/
  #define HEDMA_ECR_EC6_MASK                 (0x00000040)
  #define HEDMA_ECR_EC6_SHIFT                (0x00000006)
  
  #define HEDMA_ECR_EC6_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ECR_EC6)

  #define HEDMA_ECR_EC6_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ECR_EC6,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ECR_EC7
\*----------------------------------------------------------------------------*/
  #define HEDMA_ECR_EC7_MASK                 (0x00000080)
  #define HEDMA_ECR_EC7_SHIFT                (0x00000007)
  
  #define HEDMA_ECR_EC7_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ECR_EC7)

  #define HEDMA_ECR_EC7_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ECR_EC7,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ECR_EC8
\*----------------------------------------------------------------------------*/
  #define HEDMA_ECR_EC8_MASK                 (0x00000100)
  #define HEDMA_ECR_EC8_SHIFT                (0x00000008)
  
  #define HEDMA_ECR_EC8_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ECR_EC8)

  #define HEDMA_ECR_EC8_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ECR_EC8,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ECR_EC9
\*----------------------------------------------------------------------------*/
  #define HEDMA_ECR_EC9_MASK                 (0x00000200)
  #define HEDMA_ECR_EC9_SHIFT                (0x00000009)
  
  #define HEDMA_ECR_EC9_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ECR_EC9)

  #define HEDMA_ECR_EC9_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ECR_EC9,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ECR_EC10
\*----------------------------------------------------------------------------*/
  #define HEDMA_ECR_EC10_MASK                (0x00000400)
  #define HEDMA_ECR_EC10_SHIFT               (0x0000000A)
  
  #define HEDMA_ECR_EC10_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ECR_EC10)

  #define HEDMA_ECR_EC10_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ECR_EC10,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ECR_EC11
\*----------------------------------------------------------------------------*/
  #define HEDMA_ECR_EC11_MASK                (0x00000800)
  #define HEDMA_ECR_EC11_SHIFT               (0x0000000B)
  
  #define HEDMA_ECR_EC11_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ECR_EC11)

  #define HEDMA_ECR_EC11_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ECR_EC11,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ECR_EC12
\*----------------------------------------------------------------------------*/
  #define HEDMA_ECR_EC12_MASK                (0x00001000)
  #define HEDMA_ECR_EC12_SHIFT               (0x0000000C)
  
  #define HEDMA_ECR_EC12_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ECR_EC12)

  #define HEDMA_ECR_EC12_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ECR_EC12,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ECR_EC13
\*----------------------------------------------------------------------------*/
  #define HEDMA_ECR_EC13_MASK                (0x00002000)
  #define HEDMA_ECR_EC13_SHIFT               (0x0000000D)
  
  #define HEDMA_ECR_EC13_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ECR_EC13)

  #define HEDMA_ECR_EC13_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ECR_EC13,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ECR_EC14
\*----------------------------------------------------------------------------*/
  #define HEDMA_ECR_EC14_MASK                (0x00004000)
  #define HEDMA_ECR_EC14_SHIFT               (0x0000000E)
  
  #define HEDMA_ECR_EC14_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ECR_EC14)

  #define HEDMA_ECR_EC14_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ECR_EC14,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ECR_EC15
\*----------------------------------------------------------------------------*/
  #define HEDMA_ECR_EC15_MASK                (0x00008000)
  #define HEDMA_ECR_EC15_SHIFT               (0x0000000F)
  
  #define HEDMA_ECR_EC15_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ECR_EC15)

  #define HEDMA_ECR_EC15_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ECR_EC15,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ECR
\*----------------------------------------------------------------------------*/
  #define HEDMA_ECR_GET(RegAddr) HREG32_GET(RegAddr)
  #define HEDMA_ECR_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HEDMA_ECR_CFG(RegAddr,ec0,ec1,ec2,ec3,ec4,ec5,ec6,ec7,\
  ec8,ec9,ec10,ec11,ec12,ec13,ec14,ec15) REG32(RegAddr)=(UINT32)(\
    HFIELD_SHIFT(HEDMA_ECR_EC0,ec0)|\
    HFIELD_SHIFT(HEDMA_ECR_EC1,ec1)|\
    HFIELD_SHIFT(HEDMA_ECR_EC2,ec2)|\
    HFIELD_SHIFT(HEDMA_ECR_EC3,ec3)|\
    HFIELD_SHIFT(HEDMA_ECR_EC4,ec4)|\
    HFIELD_SHIFT(HEDMA_ECR_EC5,ec5)|\
    HFIELD_SHIFT(HEDMA_ECR_EC6,ec6)|\
    HFIELD_SHIFT(HEDMA_ECR_EC7,ec7)|\
    HFIELD_SHIFT(HEDMA_ECR_EC8,ec8)|\
    HFIELD_SHIFT(HEDMA_ECR_EC9,ec9)|\
    HFIELD_SHIFT(HEDMA_ECR_EC10,ec10)|\
    HFIELD_SHIFT(HEDMA_ECR_EC11,ec11)|\
    HFIELD_SHIFT(HEDMA_ECR_EC12,ec12)|\
    HFIELD_SHIFT(HEDMA_ECR_EC13,ec13)|\
    HFIELD_SHIFT(HEDMA_ECR_EC14,ec14)|\
    HFIELD_SHIFT(HEDMA_ECR_EC15,ec15)\
  )
                     
/******************************************************************************\
* HEDMA_ESR  - event set register
*
* Fields:
*   (RW) HEDMA_ESR_ES0
*   (RW) HEDMA_ESR_ES1
*   (RW) HEDMA_ESR_ES2
*   (RW) HEDMA_ESR_ES3
*   (RW) HEDMA_ESR_ES4
*   (RW) HEDMA_ESR_ES5
*   (RW) HEDMA_ESR_ES6
*   (RW) HEDMA_ESR_ES7
*   (RW) HEDMA_ESR_ES8
*   (RW) HEDMA_ESR_ES9
*   (RW) HEDMA_ESR_ES10
*   (RW) HEDMA_ESR_ES11
*   (RW) HEDMA_ESR_ES12
*   (RW) HEDMA_ESR_ES13
*   (RW) HEDMA_ESR_ES14
*   (RW) HEDMA_ESR_ES15
*
\******************************************************************************/
  #define HEDMA_ESR_ADDR                       (HEDMA_BASE0_ADDR+0xFFFC)
  #define HEDMA_ESR                            REG32(HEDMA_ESR_ADDR)
  
/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ESR_ES0
\*----------------------------------------------------------------------------*/
  #define HEDMA_ESR_ES0_MASK                 (0x00000001)
  #define HEDMA_ESR_ES0_SHIFT                (0x00000000)
  
  #define HEDMA_ESR_ES0_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ESR_ES0)

  #define HEDMA_ESR_ES0_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ESR_ES0,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ESR_ES1
\*----------------------------------------------------------------------------*/
  #define HEDMA_ESR_ES1_MASK                 (0x00000002)
  #define HEDMA_ESR_ES1_SHIFT                (0x00000001)
  
  #define HEDMA_ESR_ES1_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ESR_ES1)

  #define HEDMA_ESR_ES1_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ESR_ES1,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ESR_ES2
\*----------------------------------------------------------------------------*/
  #define HEDMA_ESR_ES2_MASK                 (0x00000004)
  #define HEDMA_ESR_ES2_SHIFT                (0x00000002)
  
  #define HEDMA_ESR_ES2_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ESR_ES2)

  #define HEDMA_ESR_ES2_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ESR_ES2,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ESR_ES3
\*----------------------------------------------------------------------------*/
  #define HEDMA_ESR_ES3_MASK                 (0x00000008)
  #define HEDMA_ESR_ES3_SHIFT                (0x00000003)
  
  #define HEDMA_ESR_ES3_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ESR_ES3)

  #define HEDMA_ESR_ES3_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ESR_ES3,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ESR_ES4
\*----------------------------------------------------------------------------*/
  #define HEDMA_ESR_ES4_MASK                 (0x00000010)
  #define HEDMA_ESR_ES4_SHIFT                (0x00000004)
  
  #define HEDMA_ESR_ES4_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ESR_ES4)

  #define HEDMA_ESR_ES4_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ESR_ES4,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ESR_ES5
\*----------------------------------------------------------------------------*/
  #define HEDMA_ESR_ES5_MASK                 (0x00000020)
  #define HEDMA_ESR_ES5_SHIFT                (0x00000005)
  
  #define HEDMA_ESR_ES5_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ESR_ES5)

  #define HEDMA_ESR_ES5_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ESR_ES5,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ESR_ES6
\*----------------------------------------------------------------------------*/
  #define HEDMA_ESR_ES6_MASK                 (0x00000040)
  #define HEDMA_ESR_ES6_SHIFT                (0x00000006)
  
  #define HEDMA_ESR_ES6_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ESR_ES6)

  #define HEDMA_ESR_ES6_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ESR_ES6,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ESR_ES7
\*----------------------------------------------------------------------------*/
  #define HEDMA_ESR_ES7_MASK                 (0x00000080)
  #define HEDMA_ESR_ES7_SHIFT                (0x00000007)
  
  #define HEDMA_ESR_ES7_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ESR_ES7)

  #define HEDMA_ESR_ES7_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ESR_ES7,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ESR_ES8
\*----------------------------------------------------------------------------*/
  #define HEDMA_ESR_ES8_MASK                 (0x00000100)
  #define HEDMA_ESR_ES8_SHIFT                (0x00000008)
  
  #define HEDMA_ESR_ES8_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ESR_ES8)

  #define HEDMA_ESR_ES8_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ESR_ES8,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ESR_ES9
\*----------------------------------------------------------------------------*/
  #define HEDMA_ESR_ES9_MASK                 (0x00000200)
  #define HEDMA_ESR_ES9_SHIFT                (0x00000009)
  
  #define HEDMA_ESR_ES9_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ESR_ES9)

  #define HEDMA_ESR_ES9_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ESR_ES9,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ESR_ES10
\*----------------------------------------------------------------------------*/
  #define HEDMA_ESR_ES10_MASK                (0x00000400)
  #define HEDMA_ESR_ES10_SHIFT               (0x0000000A)
  
  #define HEDMA_ESR_ES10_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ESR_ES10)

  #define HEDMA_ESR_ES10_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ESR_ES10,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ESR_ES11
\*----------------------------------------------------------------------------*/
  #define HEDMA_ESR_ES11_MASK                (0x00000800)
  #define HEDMA_ESR_ES11_SHIFT               (0x0000000B)
  
  #define HEDMA_ESR_ES11_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ESR_ES11)

  #define HEDMA_ESR_ES11_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ESR_ES11,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ESR_ES12
\*----------------------------------------------------------------------------*/
  #define HEDMA_ESR_ES12_MASK                (0x00001000)
  #define HEDMA_ESR_ES12_SHIFT               (0x0000000C)
  
  #define HEDMA_ESR_ES12_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ESR_ES12)

  #define HEDMA_ESR_ES12_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ESR_ES12,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ESR_ES13
\*----------------------------------------------------------------------------*/
  #define HEDMA_ESR_ES13_MASK                (0x00002000)
  #define HEDMA_ESR_ES13_SHIFT               (0x0000000D)
  
  #define HEDMA_ESR_ES13_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ESR_ES13)

  #define HEDMA_ESR_ES13_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ESR_ES13,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ESR_ES14
\*----------------------------------------------------------------------------*/
  #define HEDMA_ESR_ES14_MASK                (0x00004000)
  #define HEDMA_ESR_ES14_SHIFT               (0x0000000E)
  
  #define HEDMA_ESR_ES14_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ESR_ES14)

  #define HEDMA_ESR_ES14_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ESR_ES14,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ESR_ES15
\*----------------------------------------------------------------------------*/
  #define HEDMA_ESR_ES15_MASK                (0x00008000)
  #define HEDMA_ESR_ES15_SHIFT               (0x0000000F)
  
  #define HEDMA_ESR_ES15_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEDMA_ESR_ES15)

  #define HEDMA_ESR_ES15_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEDMA_ESR_ES15,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEDMA_ESR
\*----------------------------------------------------------------------------*/
  #define HEDMA_ESR_GET(RegAddr) HREG32_GET(RegAddr)
  #define HEDMA_ESR_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HEDMA_ESR_CFG(RegAddr,es0,es1,es2,es3,es4,es5,es6,es7,\
  es8,es9,es10,es11,es12,es13,es14,es15) REG32(RegAddr)=(UINT32)(\
    HFIELD_SHIFT(HEDMA_ESR_ES0,es0)|\
    HFIELD_SHIFT(HEDMA_ESR_ES1,es1)|\
    HFIELD_SHIFT(HEDMA_ESR_ES2,es2)|\
    HFIELD_SHIFT(HEDMA_ESR_ES3,es3)|\
    HFIELD_SHIFT(HEDMA_ESR_ES4,es4)|\
    HFIELD_SHIFT(HEDMA_ESR_ES5,es5)|\
    HFIELD_SHIFT(HEDMA_ESR_ES6,es6)|\
    HFIELD_SHIFT(HEDMA_ESR_ES7,es7)|\
    HFIELD_SHIFT(HEDMA_ESR_ES8,es8)|\
    HFIELD_SHIFT(HEDMA_ESR_ES9,es9)|\
    HFIELD_SHIFT(HEDMA_ESR_ES10,es10)|\
    HFIELD_SHIFT(HEDMA_ESR_ES11,es11)|\
    HFIELD_SHIFT(HEDMA_ESR_ES12,es12)|\
    HFIELD_SHIFT(HEDMA_ESR_ES13,es13)|\
    HFIELD_SHIFT(HEDMA_ESR_ES14,es14)|\
    HFIELD_SHIFT(HEDMA_ESR_ES15,es15)\
  )

/*----------------------------------------------------------------------------*/

#endif /* EDMA_SUPPORT */
#endif /* _EDMAHAL_H_ */
/******************************************************************************\
* End of edmahal.h
\******************************************************************************/
/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... emifhal.h
* DATE CREATED.. 06/12/1999 
* LAST MODIFIED. 03/08/2000
*   
*------------------------------------------------------------------------------
* DESCRIPTION:  (HAL interface file for the EMIF module)
*
* Registers Covered:
*   (RW) HEMIF_GBLCTL - global control register
*   (RW) HEMIF_CE0CTL - chip-enable space 0 control register
*   (RW) HEMIF_CE1CTL - chip-enable space 1 control register
*   (RW) HEMIF_CE2CTL - chip-enable space 2 control register
*   (RW) HEMIF_CE3CTL - chip-enable space 3 control register
*   (RW) HEMIF_SDCTL  - SDRAM control register
*   (RW) HEMIF_SDTIM  - SDRAM timing register
*   (RW) HEMIF_SDEXT  - SDRAM extension register (1)
*
*   (1) Only available for C11_SUPPORT
*
\******************************************************************************/
#ifndef _EMIFHAL_H_
#define _EMIFHAL_H_

#if (EMIF_SUPPORT)
#define HEMIF_BASE_ADDR      (HCHIP_PERBASE_ADDR+0x00000000)

/******************************************************************************\
* HEMIF_GBLCTL - global control register
*
* Fields:
*   (R)  HEMIF_GBLCTL_MAP     (2)
*   (RW) HEMIF_GBLCTL_RBTR8   (2)
*   (RW) HEMIF_GBLCTL_SSCRT   (2)(3)
*   (RW) HEMIF_GBLCTL_CLK2EN  (3)
*   (RW) HEMIF_GBLCTL_CLK1EN
*   (RW) HEMIF_GBLCTL_SSCEN   (2)
*   (RW) HEMIF_GBLCTL_SDCEN   (2)
*   (RW) HEMIF_GBLCTL_NOHOLD
*   (R)  HEMIF_GBLCTL_HOLDA
*   (R)  HEMIF_GBLCTL_HOLD
*   (R)  HEMIF_GBLCTL_ARDY
*   (R)  HEMIF_GBLCTL_BUSREQ  (1)
*
*   (1) Field only exists for C11_SUPPORT
*   (2) Field does not exist for C11_SUPPORT
*   (3) Field does not exist for CHIP_6202, CHIP_6203
*
\******************************************************************************/
  #define HEMIF_GBLCTL_ADDR                    (HEMIF_BASE_ADDR+0x0000)
  #define HEMIF_GBLCTL                         REG32(HEMIF_GBLCTL_ADDR)

/*----------------------------------------------------------------------------*\
* (R) HEMIF_GBLCTL_MAP
\*----------------------------------------------------------------------------*/
#if !(C11_SUPPORT)
  #define HEMIF_GBLCTL_MAP_MASK                (0x00000001)
  #define HEMIF_GBLCTL_MAP_SHIFT               (0x00000000) 
#else
  #define HEMIF_GBLCTL_MAP_MASK                (0x00000000)
  #define HEMIF_GBLCTL_MAP_SHIFT               (0x00000000) 
#endif

  #define HEMIF_GBLCTL_MAP_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_GBLCTL_MAP)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_GBLCTL_RBTR8
\*----------------------------------------------------------------------------*/
#if !(C11_SUPPORT)
  #define HEMIF_GBLCTL_RBTR8_MASK              (0x00000002)
  #define HEMIF_GBLCTL_RBTR8_SHIFT             (0x00000001) 
#else
  #define HEMIF_GBLCTL_RBTR8_MASK              (0x00000000)
  #define HEMIF_GBLCTL_RBTR8_SHIFT             (0x00000000) 
#endif

  #define HEMIF_GBLCTL_RBTR8_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_GBLCTL_RBTR8)

  #define HEMIF_GBLCTL_RBTR8_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_GBLCTL_RBTR8,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_GBLCTL_SSCRT
\*----------------------------------------------------------------------------*/
#if !(CHIP_6202|CHIP_6203|C11_SUPPORT)
  #define HEMIF_GBLCTL_SSCRT_MASK              (0x00000004)
  #define HEMIF_GBLCTL_SSCRT_SHIFT             (0x00000002)
#else
  #define HEMIF_GBLCTL_SSCRT_MASK              (0x00000000)
  #define HEMIF_GBLCTL_SSCRT_SHIFT             (0x00000000)
#endif

  #define HEMIF_GBLCTL_SSCRT_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_GBLCTL_SSCRT)

  #define HEMIF_GBLCTL_SSCRT_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_GBLCTL_SSCRT,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_GBLCTL_CLK2EN
\*----------------------------------------------------------------------------*/
#if !(CHIP_6202|CHIP_6203)
  #define HEMIF_GBLCTL_CLK2EN_MASK             (0x00000008)
  #define HEMIF_GBLCTL_CLK2EN_SHIFT            (0x00000003)
#else
  #define HEMIF_GBLCTL_CLK2EN_MASK             (0x00000000)
  #define HEMIF_GBLCTL_CLK2EN_SHIFT            (0x00000000)
#endif

  #define HEMIF_GBLCTL_CLK2EN_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_GBLCTL_CLK2EN)

  #define HEMIF_GBLCTL_CLK2EN_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_GBLCTL_CLK2EN,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_GBLCTL_CLK1EN
\*----------------------------------------------------------------------------*/
  #define HEMIF_GBLCTL_CLK1EN_MASK             (0x00000010)
  #define HEMIF_GBLCTL_CLK1EN_SHIFT            (0x00000004)

  #define HEMIF_GBLCTL_CLK1EN_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_GBLCTL_CLK1EN)

  #define HEMIF_GBLCTL_CLK1EN_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_GBLCTL_CLK1EN,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_GBLCTL_SSCEN
\*----------------------------------------------------------------------------*/
#if !(C11_SUPPORT)
  #define HEMIF_GBLCTL_SSCEN_MASK              (0x00000020)
  #define HEMIF_GBLCTL_SSCEN_SHIFT             (0x00000005)
#else
  #define HEMIF_GBLCTL_SSCEN_MASK              (0x00000000)
  #define HEMIF_GBLCTL_SSCEN_SHIFT             (0x00000000)
#endif

  #define HEMIF_GBLCTL_SSCEN_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_GBLCTL_SSCEN)

  #define HEMIF_GBLCTL_SSCEN_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_GBLCTL_SSCEN,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_GBLCTL_SDCEN
\*----------------------------------------------------------------------------*/
#if !(C11_SUPPORT)
  #define HEMIF_GBLCTL_SDCEN_MASK              (0x00000040)
  #define HEMIF_GBLCTL_SDCEN_SHIFT             (0x00000006)
#else
  #define HEMIF_GBLCTL_SDCEN_MASK              (0x00000000)
  #define HEMIF_GBLCTL_SDCEN_SHIFT             (0x00000000)
#endif

  #define HEMIF_GBLCTL_SDCEN_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_GBLCTL_SDCEN)

  #define HEMIF_GBLCTL_SDCEN_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_GBLCTL_SDCEN,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_GBLCTL_NOHOLD
\*----------------------------------------------------------------------------*/
  #define HEMIF_GBLCTL_NOHOLD_MASK             (0x00000080)
  #define HEMIF_GBLCTL_NOHOLD_SHIFT            (0x00000007)

  #define HEMIF_GBLCTL_NOHOLD_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_GBLCTL_NOHOLD)

  #define HEMIF_GBLCTL_NOHOLD_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_GBLCTL_NOHOLD,Val)

/*----------------------------------------------------------------------------*\
* (R) HEMIF_GBLCTL_HOLDA
\*----------------------------------------------------------------------------*/
  #define HEMIF_GBLCTL_HOLDA_MASK              (0x00000100)
  #define HEMIF_GBLCTL_HOLDA_SHIFT             (0x00000008)
  
  #define HEMIF_GBLCTL_HOLDA_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_GBLCTL_HOLDA)

/*----------------------------------------------------------------------------*\
* (R) HEMIF_GBLCTL_HOLD
\*----------------------------------------------------------------------------*/
  #define HEMIF_GBLCTL_HOLD_MASK               (0x00000200)
  #define HEMIF_GBLCTL_HOLD_SHIFT              (0x00000009)
  
  #define HEMIF_GBLCTL_HOLD_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_GBLCTL_HOLD)

/*----------------------------------------------------------------------------*\
* (R) HEMIF_GBLCTL_ARDY
\*----------------------------------------------------------------------------*/
  #define HEMIF_GBLCTL_ARDY_MASK               (0x00000400)
  #define HEMIF_GBLCTL_ARDY_SHIFT              (0x0000000A)
  
  #define HEMIF_GBLCTL_ARDY_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_GBLCTL_ARDY)

/*----------------------------------------------------------------------------*\
* (R) HEMIF_GBLCTL_BUSREQ
\*----------------------------------------------------------------------------*/
#if (C11_SUPPORT)
  #define HEMIF_GBLCTL_BUSREQ_MASK             (0x00000800)
  #define HEMIF_GBLCTL_BUSREQ_SHIFT            (0x0000000B)
#else
  #define HEMIF_GBLCTL_BUSREQ_MASK             (0x00000000)
  #define HEMIF_GBLCTL_BUSREQ_SHIFT            (0x00000000)
#endif

  #define HEMIF_GBLCTL_BUSREQ_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_GBLCTL_BUSREQ)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_GBLCTL
\*----------------------------------------------------------------------------*/
  #define HEMIF_GBLCTL_GET(RegAddr) HREG32_GET(RegAddr)
  #define HEMIF_GBLCTL_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)
  
  #define HEMIF_GBLCTL_CFG(RegAddr,rbtr8,sscrt,clk2en,clk1en,sscen,sdcen,\
  nohold) REG32(RegAddr) = (UINT32)( \
    HFIELD_SHIFT(HEMIF_GBLCTL_RBTR8,rbtr8)|\
    HFIELD_SHIFT(HEMIF_GBLCTL_SSCRT,sscrt)|\
    HFIELD_SHIFT(HEMIF_GBLCTL_CLK2EN,clk2en)|\
    HFIELD_SHIFT(HEMIF_GBLCTL_CLK1EN,clk1en)|\
    HFIELD_SHIFT(HEMIF_GBLCTL_SSCEN,sscen)|\
    HFIELD_SHIFT(HEMIF_GBLCTL_SDCEN,sdcen)|\
    HFIELD_SHIFT(HEMIF_GBLCTL_NOHOLD,nohold)|\
    0x00003000 \
  )

/*----------------------------------------------------------------------------*/

/******************************************************************************\
* HEMIF_CE0CTL - chip-enable space 0 control register
* HEMIF_CE1CTL - chip-enable space 1 control register
* HEMIF_CE2CTL - chip-enable space 2 control register
* HEMIF_CE3CTL - chip-enable space 3 control register
*
* Fields:
*   (RW) HEMIF_CECTL_RDHLD
*   (RW) HEMIF_CECTL_WRHLDMSB (1)
*   (RW) HEMIF_CECTL_MTYPE
*   (RW) HEMIF_CECTL_RDSTRB
*   (RW) HEMIF_CECTL_TA       (1)
*   (RW) HEMIF_CECTL_RDSETUP
*   (RW) HEMIF_CECTL_WRHLD
*   (RW) HEMIF_CECTL_WRSTRB
*   (RW) HEMIF_CECTL_WRSETUP
*
*   (1) Field only exists for C11_SUPPORT
*
\******************************************************************************/
  #define HEMIF_CE0CTL_ADDR                    (HEMIF_BASE_ADDR+0x0008)
  #define HEMIF_CE1CTL_ADDR                    (HEMIF_BASE_ADDR+0x0004)
  #define HEMIF_CE2CTL_ADDR                    (HEMIF_BASE_ADDR+0x0010)
  #define HEMIF_CE3CTL_ADDR                    (HEMIF_BASE_ADDR+0x0014)

  #define HEMIF_CE0CTL                         REG32(HEMIF_CE0CTL_ADDR)
  #define HEMIF_CE1CTL                         REG32(HEMIF_CE1CTL_ADDR)
  #define HEMIF_CE2CTL                         REG32(HEMIF_CE2CTL_ADDR)
  #define HEMIF_CE3CTL                         REG32(HEMIF_CE3CTL_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_CECTL_RDHLD
\*----------------------------------------------------------------------------*/
#if (C11_SUPPORT)
  #define HEMIF_CECTL_RDHLD_MASK               (0x00000007)
  #define HEMIF_CECTL_RDHLD_SHIFT              (0x00000000)
#elif (C01_SUPPORT)
  #define HEMIF_CECTL_RDHLD_MASK               (0x00000003)
  #define HEMIF_CECTL_RDHLD_SHIFT              (0x00000000)
#endif

  #define HEMIF_CECTL_RDHLD_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_CECTL_RDHLD)

  #define HEMIF_CECTL_RDHLD_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_CECTL_RDHLD,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_CECTL_WRHLDMSB
\*----------------------------------------------------------------------------*/
#if (C11_SUPPORT)  
  #define HEMIF_CECTL_WRHLDMSB_MASK            (0x00000008)
  #define HEMIF_CECTL_WRHLDMSB_SHIFT           (0x00000003)
#else
  #define HEMIF_CECTL_WRHLDMSB_MASK            (0x00000000)
  #define HEMIF_CECTL_WRHLDMSB_SHIFT           (0x00000000)
#endif

  #define HEMIF_CECTL_WRHLDMSB_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_CECTL_WRHLDMSB)

  #define HEMIF_CECTL_WRHLDMSB_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_CECTL_WRHLDMSB,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_CECTL_MTYPE
\*----------------------------------------------------------------------------*/
#if (C11_SUPPORT)
  #define HEMIF_CECTL_MTYPE_MASK               (0x000000F0)
  #define HEMIF_CECTL_MTYPE_SHIFT              (0x00000004)
#elif (C01_SUPPORT)
  #define HEMIF_CECTL_MTYPE_MASK               (0x00000070)
  #define HEMIF_CECTL_MTYPE_SHIFT              (0x00000004)
#else
  #define HEMIF_CECTL_MTYPE_MASK               (0x00000000)
  #define HEMIF_CECTL_MTYPE_SHIFT              (0x00000000)
#endif

  #define HEMIF_CECTL_MTYPE_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_CECTL_MTYPE)

  #define HEMIF_CECTL_MTYPE_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_CECTL_MTYPE,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_CECTL_RDSTRB
\*----------------------------------------------------------------------------*/
  #define HEMIF_CECTL_RDSTRB_MASK              (0x00003F00)
  #define HEMIF_CECTL_RDSTRB_SHIFT             (0x00000008)
  
  #define HEMIF_CECTL_RDSTRB_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_CECTL_RDSTRB)

  #define HEMIF_CECTL_RDSTRB_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_CECTL_RDSTRB,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_CECTL_TA
\*----------------------------------------------------------------------------*/
#if (C11_SUPPORT)
  #define HEMIF_CECTL_TA_MASK                  (0x0000C000)
  #define HEMIF_CECTL_TA_SHIFT                 (0x0000000E)
#else
  #define HEMIF_CECTL_TA_MASK                  (0x00000000)
  #define HEMIF_CECTL_TA_SHIFT                 (0x00000000)
#endif

  #define HEMIF_CECTL_TA_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_CECTL_TA)

  #define HEMIF_CECTL_TA_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_CECTL_TA,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_CECTL_RDSETUP
\*----------------------------------------------------------------------------*/
  #define HEMIF_CECTL_RDSETUP_MASK             (0x000F0000)
  #define HEMIF_CECTL_RDSETUP_SHIFT            (0x00000010)

  #define HEMIF_CECTL_RDSETUP_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_CECTL_RDSETUP)

  #define HEMIF_CECTL_RDSETUP_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_CECTL_RDSETUP,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_CECTL_WRHLD
\*----------------------------------------------------------------------------*/
  #define HEMIF_CECTL_WRHLD_MASK               (0x00300000)
  #define HEMIF_CECTL_WRHLD_SHIFT              (0x00000014)
  
  #define HEMIF_CECTL_WRHLD_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_CECTL_WRHLD)

  #define HEMIF_CECTL_WRHLD_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_CECTL_WRHLD,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_CECTL_WRSTRB
\*----------------------------------------------------------------------------*/
  #define HEMIF_CECTL_WRSTRB_MASK              (0x0FC00000)
  #define HEMIF_CECTL_WRSTRB_SHIFT             (0x00000016)

  #define HEMIF_CECTL_WRSTRB_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_CECTL_WRSTRB)

  #define HEMIF_CECTL_WRSTRB_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_CECTL_WRSTRB,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_CECTL_WRSETUP
\*----------------------------------------------------------------------------*/
  #define HEMIF_CECTL_WRSETUP_MASK             (0xF0000000)
  #define HEMIF_CECTL_WRSETUP_SHIFT            (0x0000001C)

  #define HEMIF_CECTL_WRSETUP_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_CECTL_WRSETUP)

  #define HEMIF_CECTL_WRSETUP_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_CECTL_WRSETUP,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_CECTL
\*----------------------------------------------------------------------------*/
  #define HEMIF_CECTL_GET(RegAddr) HREG32_GET(RegAddr)
  #define HEMIF_CECTL_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)
  
  #define HEMIF_CECTL_CFG(RegAddr,rdhld,wrhldmsb,mtype,rdstrb,ta,\
  rdsetup,wrhld,wrstrb,wrsetup) REG32(RegAddr) = (UINT32)( \
    HFIELD_SHIFT(HEMIF_CECTL_RDHLD,rdhld)|\
    HFIELD_SHIFT(HEMIF_CECTL_WRHLDMSB,wrhldmsb)|\
    HFIELD_SHIFT(HEMIF_CECTL_MTYPE,mtype)|\
    HFIELD_SHIFT(HEMIF_CECTL_RDSTRB,rdstrb)|\
    HFIELD_SHIFT(HEMIF_CECTL_TA,ta)|\
    HFIELD_SHIFT(HEMIF_CECTL_RDSETUP,rdsetup)|\
    HFIELD_SHIFT(HEMIF_CECTL_WRHLD,wrhld)|\
    HFIELD_SHIFT(HEMIF_CECTL_WRSTRB,wrstrb)|\
    HFIELD_SHIFT(HEMIF_CECTL_WRSETUP,wrsetup)\
  )

/******************************************************************************\
* HEMIF_SDCTL - SDRAM control register
*
* Fields:
*   (RW) HEMIF_SDCTL_TRC
*   (RW) HEMIF_SDCTL_TRP
*   (RW) HEMIF_SDCTL_TRCD
*   (W)  HEMIF_SDCTL_INIT
*   (RW) HEMIF_SDCTL_RFEN
*   (RW) HEMIF_SDCTL_SDWID (1)
*   (RW) HEMIF_SDCTL_SDCSZ (2)
*   (RW) HEMIF_SDCTL_SDRSZ (2)
*   (RW) HEMIF_SDCTL_SDBSZ (2)
*
*   (1) Field only exists for C01_SUPPORT
*   (2) Field only exists for C11_SUPPORT
*
\******************************************************************************/
  #define HEMIF_SDCTL_ADDR                     (HEMIF_BASE_ADDR+0x0018)
  #define HEMIF_SDCTL                          REG32(HEMIF_SDCTL_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_SDCTL_TRC
\*----------------------------------------------------------------------------*/
  #define HEMIF_SDCTL_TRC_MASK                 (0x0000F000)
  #define HEMIF_SDCTL_TRC_SHIFT                (0x0000000C)
  
  #define HEMIF_SDCTL_TRC_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_SDCTL_TRC)

  #define HEMIF_SDCTL_TRC_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_SDCTL_TRC,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_SDCTL_TRP
\*----------------------------------------------------------------------------*/
  #define HEMIF_SDCTL_TRP_MASK                 (0x000F0000)
  #define HEMIF_SDCTL_TRP_SHIFT                (0x00000010)

  #define HEMIF_SDCTL_TRP_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_SDCTL_TRP)

  #define HEMIF_SDCTL_TRP_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_SDCTL_TRP,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_SDCTL_TRCD
\*----------------------------------------------------------------------------*/
  #define HEMIF_SDCTL_TRCD_MASK                (0x00F00000)
  #define HEMIF_SDCTL_TRCD_SHIFT               (0x00000014)

  #define HEMIF_SDCTL_TRCD_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_SDCTL_TRCD)

  #define HEMIF_SDCTL_TRCD_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_SDCTL_TRCD,Val)

/*----------------------------------------------------------------------------*\
* (W) HEMIF_SDCTL_INIT
\*----------------------------------------------------------------------------*/
  #define HEMIF_SDCTL_INIT_MASK                (0x01000000)
  #define HEMIF_SDCTL_INIT_SHIFT               (0x00000018)

  #define HEMIF_SDCTL_INIT_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_SDCTL_INIT,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_SDCTL_RFEN
\*----------------------------------------------------------------------------*/
  #define HEMIF_SDCTL_RFEN_MASK                (0x02000000)
  #define HEMIF_SDCTL_RFEN_SHIFT               (0x00000019) 

  #define HEMIF_SDCTL_RFEN_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_SDCTL_RFEN)

  #define HEMIF_SDCTL_RFEN_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_SDCTL_RFEN,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_SDCTL_SDWID
\*----------------------------------------------------------------------------*/
#if (C01_SUPPORT)
  #define HEMIF_SDCTL_SDWID_MASK               (0x04000000)
  #define HEMIF_SDCTL_SDWID_SHIFT              (0x0000001A)
#else
  #define HEMIF_SDCTL_SDWID_MASK               (0x00000000)
  #define HEMIF_SDCTL_SDWID_SHIFT              (0x00000000)
#endif
  
  #define HEMIF_SDCTL_SDWID_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_SDCTL_SDWID)

  #define HEMIF_SDCTL_SDWID_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_SDCTL_SDWID,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_SDCTL_SDCSZ
\*----------------------------------------------------------------------------*/
#if (C11_SUPPORT)
  #define HEMIF_SDCTL_SDCSZ_MASK               (0x0C000000)
  #define HEMIF_SDCTL_SDCSZ_SHIFT              (0x0000001A)
#else
  #define HEMIF_SDCTL_SDCSZ_MASK               (0x00000000)
  #define HEMIF_SDCTL_SDCSZ_SHIFT              (0x00000000)
#endif
  
  #define HEMIF_SDCTL_SDCSZ_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_SDCTL_SDCSZ)

  #define HEMIF_SDCTL_SDCSZ_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_SDCTL_SDCSZ,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_SDCTL_SDRSZ
\*----------------------------------------------------------------------------*/
#if (C11_SUPPORT)
  #define HEMIF_SDCTL_SDRSZ_MASK               (0x30000000)
  #define HEMIF_SDCTL_SDRSZ_SHIFT              (0x0000001C)
#else
  #define HEMIF_SDCTL_SDRSZ_MASK               (0x00000000)
  #define HEMIF_SDCTL_SDRSZ_SHIFT              (0x00000000)
#endif
  
  #define HEMIF_SDCTL_SDRSZ_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_SDCTL_SDRSZ)

  #define HEMIF_SDCTL_SDRSZ_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_SDCTL_SDRSZ,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_SDCTL_SDBSZ
\*----------------------------------------------------------------------------*/
#if (C11_SUPPORT)
  #define HEMIF_SDCTL_SDBSZ_MASK               (0x40000000)
  #define HEMIF_SDCTL_SDBSZ_SHIFT              (0x0000001E)
#else
  #define HEMIF_SDCTL_SDBSZ_MASK               (0x00000000)
  #define HEMIF_SDCTL_SDBSZ_SHIFT              (0x00000000)
#endif
  
  #define HEMIF_SDCTL_SDBSZ_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_SDCTL_SDBSZ)

  #define HEMIF_SDCTL_SDBSZ_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_SDCTL_SDBSZ,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_SDCTL
\*----------------------------------------------------------------------------*/
  #define HEMIF_SDCTL_GET(RegAddr) HREG32_GET(RegAddr)
  #define HEMIF_SDCTL_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)
  
  #define HEMIF_SDCTL_CFG(RegAddr,trc,trp,trcd,init,rfen,sdwid,\
  sdcsz,sdrsz,sdbsz) REG32(RegAddr) = (UINT32)( \
    HFIELD_SHIFT(HEMIF_SDCTL_TRC,trc)|\
    HFIELD_SHIFT(HEMIF_SDCTL_TRP,trp)|\
    HFIELD_SHIFT(HEMIF_SDCTL_TRCD,trcd)|\
    HFIELD_SHIFT(HEMIF_SDCTL_INIT,init)|\
    HFIELD_SHIFT(HEMIF_SDCTL_RFEN,rfen)|\
    HFIELD_SHIFT(HEMIF_SDCTL_SDWID,sdwid)|\
    HFIELD_SHIFT(HEMIF_SDCTL_SDCSZ,sdcsz)|\
    HFIELD_SHIFT(HEMIF_SDCTL_SDRSZ,sdrsz)|\
    HFIELD_SHIFT(HEMIF_SDCTL_SDBSZ,sdbsz)\
  )

/******************************************************************************\
* HEMIF_SDTIM - SDRAM timing register
*
* Fields:
*   (RW) HEMIF_SDTIM_PERIOD
*   (R)  HEMIF_SDTIM_CNTR
*   (RW) HEMIF_SDTIM_XRFR   (1)
*
*   (1) Field only exists for C11_SUPPORT
*
\******************************************************************************/
  #define HEMIF_SDTIM_ADDR                     (HEMIF_BASE_ADDR+0x001C)
  #define HEMIF_SDTIM                          REG32(HEMIF_SDTIM_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_SDTIM_PERIOD
\*----------------------------------------------------------------------------*/
  #define HEMIF_SDTIM_PERIOD_MASK              (0x00000FFF)
  #define HEMIF_SDTIM_PERIOD_SHIFT             (0x00000000) 
  
  #define HEMIF_SDTIM_PERIOD_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_SDTIM_PERIOD)

  #define HEMIF_SDTIM_PERIOD_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_SDTIM_PERIOD,Val)

/*----------------------------------------------------------------------------*\
* (R) HEMIF_SDTIM_CNTR
\*----------------------------------------------------------------------------*/
  #define HEMIF_SDTIM_CNTR_MASK                (0x00FFF000)
  #define HEMIF_SDTIM_CNTR_SHIFT               (0x0000000C)
  
  #define HEMIF_SDTIM_CNTR_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_SDTIM_CNTR)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_SDTIM_XRFR
\*----------------------------------------------------------------------------*/
#if (C11_SUPPORT)
  #define HEMIF_SDTIM_XRFR_MASK                (0x03000000)
  #define HEMIF_SDTIM_XRFR_SHIFT               (0x00000018)
#else
  #define HEMIF_SDTIM_XRFR_MASK                (0x00000000)
  #define HEMIF_SDTIM_XRFR_SHIFT               (0x00000000)
#endif

  #define HEMIF_SDTIM_XRFR_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_SDTIM_XRFR)

  #define HEMIF_SDTIM_XRFR_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_SDTIM_XRFR,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_SDTIM
\*----------------------------------------------------------------------------*/
  #define HEMIF_SDTIM_GET(RegAddr) HREG32_GET(RegAddr)
  #define HEMIF_SDTIM_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HEMIF_SDTIM_CFG(RegAddr,period,xrfr) REG32(RegAddr)=(UINT32)(\
    HFIELD_SHIFT(HEMIF_SDTIM_PERIOD,period)|\
    HFIELD_SHIFT(HEMIF_SDTIM_XRFR,xrfr)\
  )

/******************************************************************************\
* HEMIF_SDEXT - SDRAM extension register (1)
* (1) Only available for C11_SUPPORT
*
* Fields:
*   (RW) HEMIF_SDEXT_TCL
*   (RW) HEMIF_SDEXT_TRAS
*   (RW) HEMIF_SDEXT_TRRD
*   (RW) HEMIF_SDEXT_TWR
*   (RW) HEMIF_SDEXT_THZP
*   (RW) HEMIF_SDEXT_RD2RD
*   (RW) HEMIF_SDEXT_RD2DEAC
*   (RW) HEMIF_SDEXT_RD2WR
*   (RW) HEMIF_SDEXT_R2WDQM
*   (RW) HEMIF_SDEXT_WR2WR
*   (RW) HEMIF_SDEXT_WR2DEAC
*   (RW) HEMIF_SDEXT_WR2RD
*
\******************************************************************************/
#if (C11_SUPPORT)
  #define HEMIF_SDEXT_ADDR                     (HEMIF_BASE_ADDR+0x0020)
  #define HEMIF_SDEXT                          REG32(HEMIF_SDEXT_ADDR)
#else
  #define HEMIF_SDEXT_ADDR                     HCHIP_NULL_ADDR
  #define HEMIF_SDEXT                          REG32(HEMIF_SDEXT_ADDR)
#endif

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_SDEXT_TCL
\*----------------------------------------------------------------------------*/
#if (C11_SUPPORT)
  #define HEMIF_SDEXT_TCL_MASK                 (0x00000001)
  #define HEMIF_SDEXT_TCL_SHIFT                (0x00000000)
#else
  #define HEMIF_SDEXT_TCL_MASK                 (0x00000000)
  #define HEMIF_SDEXT_TCL_SHIFT                (0x00000000)
#endif

  #define HEMIF_SDEXT_TCL_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_SDEXT_TCL)

  #define HEMIF_SDEXT_TCL_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_SDEXT_TCL,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_SDEXT_TRAS
\*----------------------------------------------------------------------------*/
#if (C11_SUPPORT)
  #define HEMIF_SDEXT_TRAS_MASK                (0x0000000D)
  #define HEMIF_SDEXT_TRAS_SHIFT               (0x00000001)
#else
  #define HEMIF_SDEXT_TRAS_MASK                (0x00000000)
  #define HEMIF_SDEXT_TRAS_SHIFT               (0x00000000)
#endif

  #define HEMIF_SDEXT_TRAS_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_SDEXT_TRAS)

  #define HEMIF_SDEXT_TRAS_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_SDEXT_TRAS,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_SDEXT_TRRD
\*----------------------------------------------------------------------------*/
#if (C11_SUPPORT)
  #define HEMIF_SDEXT_TRRD_MASK                (0x00000010)
  #define HEMIF_SDEXT_TRRD_SHIFT               (0x00000004)
#else
  #define HEMIF_SDEXT_TRRD_MASK                (0x00000000)
  #define HEMIF_SDEXT_TRRD_SHIFT               (0x00000000)
#endif

  #define HEMIF_SDEXT_TRRD_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_SDEXT_TRRD)

  #define HEMIF_SDEXT_TRRD_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_SDEXT_TRRD,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_SDEXT_TWR
\*----------------------------------------------------------------------------*/
#if (C11_SUPPORT)
  #define HEMIF_SDEXT_TWR_MASK                 (0x00000060)
  #define HEMIF_SDEXT_TWR_SHIFT                (0x00000005)
#else
  #define HEMIF_SDEXT_TWR_MASK                 (0x00000000)
  #define HEMIF_SDEXT_TWR_SHIFT                (0x00000000)
#endif

  #define HEMIF_SDEXT_TWR_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_SDEXT_TWR)

  #define HEMIF_SDEXT_TWR_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_SDEXT_TWR,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_SDEXT_THZP
\*----------------------------------------------------------------------------*/
#if (C11_SUPPORT)
  #define HEMIF_SDEXT_THZP_MASK                (0x00000180)
  #define HEMIF_SDEXT_THZP_SHIFT               (0x00000007)
#else
  #define HEMIF_SDEXT_THZP_MASK                (0x00000000)
  #define HEMIF_SDEXT_THZP_SHIFT               (0x00000000)
#endif

  #define HEMIF_SDEXT_THZP_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_SDEXT_THZP)

  #define HEMIF_SDEXT_THZP_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_SDEXT_THZP,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_SDEXT_RD2RD
\*----------------------------------------------------------------------------*/
#if (C11_SUPPORT)
  #define HEMIF_SDEXT_RD2RD_MASK               (0x00000200)
  #define HEMIF_SDEXT_RD2RD_SHIFT              (0x00000009)
#else
  #define HEMIF_SDEXT_RD2RD_MASK               (0x00000000)
  #define HEMIF_SDEXT_RD2RD_SHIFT              (0x00000000)
#endif

  #define HEMIF_SDEXT_RD2RD_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_SDEXT_RD2RD)

  #define HEMIF_SDEXT_RD2RD_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_SDEXT_RD2RD,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_SDEXT_RD2DEAC
\*----------------------------------------------------------------------------*/
#if (C11_SUPPORT)
  #define HEMIF_SDEXT_RD2DEAC_MASK             (0x00000C00)
  #define HEMIF_SDEXT_RD2DEAC_SHIFT            (0x0000000A)
#else
  #define HEMIF_SDEXT_RD2DEAC_MASK             (0x00000000)
  #define HEMIF_SDEXT_RD2DEAC_SHIFT            (0x00000000)
#endif

  #define HEMIF_SDEXT_RD2DEAC_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_SDEXT_RD2DEAC)

  #define HEMIF_SDEXT_RD2DEAC_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_SDEXT_RD2DEAC,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_SDEXT_RD2WR
\*----------------------------------------------------------------------------*/
#if (C11_SUPPORT)
  #define HEMIF_SDEXT_RD2WR_MASK               (0x00007000)
  #define HEMIF_SDEXT_RD2WR_SHIFT              (0x0000000C)
#else
  #define HEMIF_SDEXT_RD2WR_MASK               (0x00000000)
  #define HEMIF_SDEXT_RD2WR_SHIFT              (0x00000000)
#endif

  #define HEMIF_SDEXT_RD2WR_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_SDEXT_RD2WR)

  #define HEMIF_SDEXT_RD2WR_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_SDEXT_RD2WR,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_SDEXT_R2WDQM
\*----------------------------------------------------------------------------*/
#if (C11_SUPPORT)
  #define HEMIF_SDEXT_R2WDQM_MASK              (0x00018000)
  #define HEMIF_SDEXT_R2WDQM_SHIFT             (0x0000000F)
#else
  #define HEMIF_SDEXT_R2WDQM_MASK              (0x00000000)
  #define HEMIF_SDEXT_R2WDQM_SHIFT             (0x00000000)
#endif

  #define HEMIF_SDEXT_R2WDQM_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_SDEXT_R2WDQM)

  #define HEMIF_SDEXT_R2WDQM_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_SDEXT_R2WDQM,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_SDEXT_WR2WR
\*----------------------------------------------------------------------------*/
#if (C11_SUPPORT)
  #define HEMIF_SDEXT_WR2WR_MASK               (0x00020000)
  #define HEMIF_SDEXT_WR2WR_SHIFT              (0x00000011)
#else
  #define HEMIF_SDEXT_WR2WR_MASK               (0x00000000)
  #define HEMIF_SDEXT_WR2WR_SHIFT              (0x00000000)
#endif

  #define HEMIF_SDEXT_WR2WR_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_SDEXT_WR2WR)

  #define HEMIF_SDEXT_WR2WR_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_SDEXT_WR2WR,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_SDEXT_WR2DEAC
\*----------------------------------------------------------------------------*/
#if (C11_SUPPORT)
  #define HEMIF_SDEXT_WR2DEAC_MASK             (0x000C0000)
  #define HEMIF_SDEXT_WR2DEAC_SHIFT            (0x00000012)
#else
  #define HEMIF_SDEXT_WR2DEAC_MASK             (0x00000000)
  #define HEMIF_SDEXT_WR2DEAC_SHIFT            (0x00000000)
#endif

  #define HEMIF_SDEXT_WR2DEAC_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_SDEXT_WR2DEAC)

  #define HEMIF_SDEXT_WR2DEAC_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_SDEXT_WR2DEAC,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_SDEXT_WR2RD
\*----------------------------------------------------------------------------*/
#if (C11_SUPPORT)
  #define HEMIF_SDEXT_WR2RD_MASK               (0x00100000)
  #define HEMIF_SDEXT_WR2RD_SHIFT              (0x00000014)
#else
  #define HEMIF_SDEXT_WR2RD_MASK               (0x00000000)
  #define HEMIF_SDEXT_WR2RD_SHIFT              (0x00000000)
#endif

  #define HEMIF_SDEXT_WR2RD_GET(RegAddr) \
    HFIELD_GET(RegAddr,HEMIF_SDEXT_WR2RD)

  #define HEMIF_SDEXT_WR2RD_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HEMIF_SDEXT_WR2RD,Val)

/*----------------------------------------------------------------------------*\
* (RW) HEMIF_SDEXT
\*----------------------------------------------------------------------------*/
  #define HEMIF_SDEXT_GET(RegAddr) HREG32_GET(RegAddr)
  #define HEMIF_SDEXT_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HEMIF_SDEXT_CFG(RegAddr,tcl,tras,trrd,twr,thzp,rd2rd,rd2deac,\
  rd2wr,r2wdqm,wr2wr,wr2deac,wr2rd) REG32(RagAddr)=(UINT32)(\
    HFIELD_SHIFT(HEMIF_SDEXT_TCL,tcl)|\
    HFIELD_SHIFT(HEMIF_SDEXT_TRAS,tras)|\
    HFIELD_SHIFT(HEMIF_SDEXT_TRRD,trrd)|\
    HFIELD_SHIFT(HEMIF_SDEXT_TWR,twr)|\
    HFIELD_SHIFT(HEMIF_SDEXT_THZP,thzp)|\
    HFIELD_SHIFT(HEMIF_SDEXT_RD2RD,rd2rd)|\
    HFIELD_SHIFT(HEMIF_SDEXT_RD2DEAC,rd2deac)|\
    HFIELD_SHIFT(HEMIF_SDEXT_RD2WR,rd2wr)|\
    HFIELD_SHIFT(HEMIF_SDEXT_R2WDQM,r2wdqm)|\
    HFIELD_SHIFT(HEMIF_SDEXT_WR2WR,wr2wr)|\
    HFIELD_SHIFT(HEMIF_SDEXT_WR2DEAC,wr2deac)|\
    HFIELD_SHIFT(HEMIF_SDEXT_WR2RD,wr2rd)\
  )  

/******************************************************************************/

#endif /* EMIF_SUPPORT */
#endif /* _EMIFHAL_H_ */
/******************************************************************************\
* End of emifhal.h
\******************************************************************************/

/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... hpihal.h
* DATE CREATED.. 06/20/1999 
* LAST MODIFIED. 03/08/2000
*   
*------------------------------------------------------------------------------
* DESCRIPTION:  (HAL interface file for the HPI module)
*
* Registers Covered:
*   (RW) HHPI_HPIC - HPI control register
*
\******************************************************************************/
#ifndef _HPIHAL_H_
#define _HPIHAL_H_

#if (HPI_SUPPORT)
#define HHPI_BASE_ADDR       (HCHIP_PERBASE_ADDR+0x00080000)

/******************************************************************************\
* HHPI_HPIC - HPI control register
*
* Fields:
*   (R)  HHPI_HPIC_HWOB
*   (RW) HHPI_HPIC_DSPINT
*   (RW) HHPI_HPIC_HINT
*   (R)  HHPI_HPIC_HRDY
*   (R)  HHPI_HPIC_FETCH
*
\******************************************************************************/
  #define HHPI_HPIC_ADDR                       (HHPI_BASE_ADDR+0x0000)
  #define HHPI_HPIC                            REG32(HHPI_HPIC_ADDR)
  
/*----------------------------------------------------------------------------*\
* (R) HHPI_HPIC_HWOB
\*----------------------------------------------------------------------------*/
  #define HHPI_HPIC_HWOB_MASK                  (0x00000001)
  #define HHPI_HPIC_HWOB_SHIFT                 (0x00000000)
  
  #define HHPI_HPIC_HWOB_GET(RegAddr) \
    HFIELD_GET(RegAddr,HHPI_HPIC_HWOB)

/*----------------------------------------------------------------------------*\
* (RW) HHPI_HPIC_DSPINT
\*----------------------------------------------------------------------------*/
  #define HHPI_HPIC_DSPINT_MASK                (0x00000002)
  #define HHPI_HPIC_DSPINT_SHIFT               (0x00000001)

  #define HHPI_HPIC_DSPINT_GET(RegAddr) \
    HFIELD_GET(RegAddr,HHPI_HPIC_DSPINT)

  #define HHPI_HPIC_DSPINT_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HHPI_HPIC_DSPINT,Val)

/*----------------------------------------------------------------------------*\
* (RW) HHPI_HPIC_HINT
\*----------------------------------------------------------------------------*/
  #define HHPI_HPIC_HINT_MASK                  (0x00000004)
  #define HHPI_HPIC_HINT_SHIFT                 (0x00000002)

  #define HHPI_HPIC_HINT_GET(RegAddr) \
    HFIELD_GET(RegAddr,HHPI_HPIC_HINT)

  #define HHPI_HPIC_HINT_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HHPI_HPIC_HINT,Val)

/*----------------------------------------------------------------------------*\
* (R) HHPI_HPIC_HRDY
\*----------------------------------------------------------------------------*/
  #define HHPI_HPIC_HRDY_MASK                  (0x00000008)
  #define HHPI_HPIC_HRDY_SHIFT                 (0x00000003)

  #define HHPI_HPIC_HRDY_GET(RegAddr) \
    HFIELD_GET(RegAddr,HHPI_HPIC_HRDY)

/*----------------------------------------------------------------------------*\
* (R) HHPI_HPIC_FETCH
\*----------------------------------------------------------------------------*/
  #define HHPI_HPIC_FETCH_MASK                 (0x00000010)
  #define HHPI_HPIC_FETCH_SHIFT                (0x00000004)

  #define HHPI_HPIC_FETCH_GET(RegAddr) \
    HFIELD_GET(RegAddr,HHPI_HPIC_FETCH)

/*----------------------------------------------------------------------------*\
* (RW) HHPI_HPIC
\*----------------------------------------------------------------------------*/
  #define HHPI_HPIC_GET(RegAddr) HREG32_GET(RegAddr)
  #define HHPI_HPIC_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)
    
  #define HHPI_HPIC_CFG(RegAddr,dspint,hint)\
  REG32(RegAddr) = (\
    HFIELD_SHIFT(HHPI_HPIC_DSPINT, dspint)|\
    HFIELD_SHIFT(HHPI_HPIC_HINT, hint)\
  )

/*----------------------------------------------------------------------------*/

#endif /* HPI_SUPPORT */
#endif /* _HPIHAL_H_ */
/******************************************************************************\
* End of hpihal.h
\******************************************************************************/

/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... irqhal.h
* DATE CREATED.. 06/20/1999 
* LAST MODIFIED. 03/08/2000
*   
*------------------------------------------------------------------------------
* DESCRIPTION:  (HAL interface file for the IRQ module)
*
* Registers Covered:
*   (RW) HIRQ_MUXL   - interrupt multiplexer low register
*   (RW) HIRQ_MUXH   - interrupt multiplexer high register
*   (RW) HIRQ_EXTPOL - external interrupt polarity register
*
\******************************************************************************/
#ifndef _IRQHAL_H_
#define _IRQHAL_H_

#if (IRQ_SUPPORT)
/*============================================================================*\
* misc declarations
\*============================================================================*/
#define HIRQ_BASE_ADDR     (HCHIP_PERBASE_ADDR+0x001C0000)

#define HIRQ_INT_CNT     (16)   /* number of interrupts */
#define HIRQ_EVENT_CNT   (19)   /* number of mappable events */

/******************************************************************************\
* HIRQ_MUXL - interrupt multiplexer low register
*
* Fields:
*   (RW) HIRQ_MUXL_INTSEL4
*   (RW) HIRQ_MUXL_INTSEL5
*   (RW) HIRQ_MUXL_INTSEL6
*   (RW) HIRQ_MUXL_INTSEL7
*   (RW) HIRQ_MUXL_INTSEL8
*   (RW) HIRQ_MUXL_INTSEL9
*
\******************************************************************************/
  #define HIRQ_MUXL_ADDR                       (HIRQ_BASE_ADDR+0x0004)
  #define HIRQ_MUXL                            REG32(HIRQ_MUXL_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HIRQ_MUXL_INTSEL4
\*----------------------------------------------------------------------------*/
  #define HIRQ_MUXL_INTSEL4_MASK               (0x0000001F)
  #define HIRQ_MUXL_INTSEL4_SHIFT              (0x00000000)
  
  #define HIRQ_MUXL_INTSEL4_GET(RegAddr) \
    HFIELD_GET(RegAddr,HIRQ_MUXL_INTSEL4)

  #define HIRQ_MUXL_INTSEL4_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HIRQ_MUXL_INTSEL4,Val)

/*----------------------------------------------------------------------------*\
* (RW) HIRQ_MUXL_INTSEL5
\*----------------------------------------------------------------------------*/
  #define HIRQ_MUXL_INTSEL5_MASK               (0x000003E0)
  #define HIRQ_MUXL_INTSEL5_SHIFT              (0x00000005)

  #define HIRQ_MUXL_INTSEL5_GET(RegAddr) \
    HFIELD_GET(RegAddr,HIRQ_MUXL_INTSEL5)

  #define HIRQ_MUXL_INTSEL5_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HIRQ_MUXL_INTSEL5,Val)

/*----------------------------------------------------------------------------*\
* (RW) HIRQ_MUXL_INTSEL6
\*----------------------------------------------------------------------------*/
  #define HIRQ_MUXL_INTSEL6_MASK               (0x00007C00)
  #define HIRQ_MUXL_INTSEL6_SHIFT              (0x0000000A)

  #define HIRQ_MUXL_INTSEL6_GET(RegAddr) \
    HFIELD_GET(RegAddr,HIRQ_MUXL_INTSEL6)

  #define HIRQ_MUXL_INTSEL6_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HIRQ_MUXL_INTSEL6,Val)

/*----------------------------------------------------------------------------*\
* (RW) HIRQ_MUXL_INTSEL7
\*----------------------------------------------------------------------------*/
  #define HIRQ_MUXL_INTSEL7_MASK               (0x001F0000)
  #define HIRQ_MUXL_INTSEL7_SHIFT              (0x00000010)

  #define HIRQ_MUXL_INTSEL7_GET(RegAddr) \
    HFIELD_GET(RegAddr,HIRQ_MUXL_INTSEL7)

  #define HIRQ_MUXL_INTSEL7_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HIRQ_MUXL_INTSEL7,Val)

/*----------------------------------------------------------------------------*\
* (RW) HIRQ_MUXL_INTSEL8
\*----------------------------------------------------------------------------*/
  #define HIRQ_MUXL_INTSEL8_MASK               (0x03E00000)
  #define HIRQ_MUXL_INTSEL8_SHIFT              (0x00000015)

  #define HIRQ_MUXL_INTSEL8_GET(RegAddr) \
    HFIELD_GET(RegAddr,HIRQ_MUXL_INTSEL8)

  #define HIRQ_MUXL_INTSEL8_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HIRQ_MUXL_INTSEL8,Val)

/*----------------------------------------------------------------------------*\
* (RW) HIRQ_MUXL_INTSEL9
\*----------------------------------------------------------------------------*/
  #define HIRQ_MUXL_INTSEL9_MASK               (0x7C000000)
  #define HIRQ_MUXL_INTSEL9_SHIFT              (0x0000001A)

  #define HIRQ_MUXL_INTSEL9_GET(RegAddr) \
    HFIELD_GET(RegAddr,HIRQ_MUXL_INTSEL9)

  #define HIRQ_MUXL_INTSEL9_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HIRQ_MUXL_INTSEL9,Val)

/*----------------------------------------------------------------------------*\
* (RW) HIRQ_MUXL
\*----------------------------------------------------------------------------*/
  #define HIRQ_MUXL_GET(RegAddr) HREG32_GET(RegAddr)
  #define HIRQ_MUXL_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)
    
  #define HIRQ_MUXL_CFG(RegAddr,intsel4,intsel5,intsel6,intsel7,intsel8,\
  intsel9) REG32(RegAddr) = (\
    HFIELD_SHIFT(HIRQ_MUXL_INTSEL4, intsel4)|\
    HFIELD_SHIFT(HIRQ_MUXL_INTSEL5, intsel5)|\
    HFIELD_SHIFT(HIRQ_MUXL_INTSEL6, intsel6)|\
    HFIELD_SHIFT(HIRQ_MUXL_INTSEL7, intsel7)|\
    HFIELD_SHIFT(HIRQ_MUXL_INTSEL8, intsel8)|\
    HFIELD_SHIFT(HIRQ_MUXL_INTSEL9, intsel9)\
  )

/******************************************************************************\
* HIRQ_MUXH - interrupt multiplexer high register
*
* Fields:
*   (RW) HIRQ_MUXH_INTSEL10
*   (RW) HIRQ_MUXH_INTSEL11
*   (RW) HIRQ_MUXH_INTSEL12
*   (RW) HIRQ_MUXH_INTSEL13
*   (RW) HIRQ_MUXH_INTSEL14
*   (RW) HIRQ_MUXH_INTSEL15
*
\******************************************************************************/
  #define HIRQ_MUXH_ADDR                       (HIRQ_BASE_ADDR+0x0000)
  #define HIRQ_MUXH                            REG32(HIRQ_MUXH_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HIRQ_MUXH_INTSEL10
\*----------------------------------------------------------------------------*/
  #define HIRQ_MUXH_INTSEL10_MASK              (0x0000001F)
  #define HIRQ_MUXH_INTSEL10_SHIFT             (0x00000000)
  
  #define HIRQ_MUXH_INTSEL10_GET(RegAddr) \
    HFIELD_GET(RegAddr,HIRQ_MUXH_INTSEL10)

  #define HIRQ_MUXH_INTSEL10_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HIRQ_MUXH_INTSEL10,Val)

/*----------------------------------------------------------------------------*\
* (RW) HIRQ_MUXH_INTSEL11
\*----------------------------------------------------------------------------*/
  #define HIRQ_MUXH_INTSEL11_MASK              (0x000003E0)
  #define HIRQ_MUXH_INTSEL11_SHIFT             (0x00000005)

  #define HIRQ_MUXH_INTSEL11_GET(RegAddr) \
    HFIELD_GET(RegAddr,HIRQ_MUXH_INTSEL11)

  #define HIRQ_MUXH_INTSEL11_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HIRQ_MUXH_INTSEL11,Val)

/*----------------------------------------------------------------------------*\
* (RW) HIRQ_MUXH_INTSEL12
\*----------------------------------------------------------------------------*/
  #define HIRQ_MUXH_INTSEL12_MASK              (0x00007C00)
  #define HIRQ_MUXH_INTSEL12_SHIFT             (0x0000000A)

  #define HIRQ_MUXH_INTSEL12_GET(RegAddr) \
    HFIELD_GET(RegAddr,HIRQ_MUXH_INTSEL12)

  #define HIRQ_MUXH_INTSEL12_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HIRQ_MUXH_INTSEL12,Val)

/*----------------------------------------------------------------------------*\
* (RW) HIRQ_MUXH_INTSEL13
\*----------------------------------------------------------------------------*/
  #define HIRQ_MUXH_INTSEL13_MASK              (0x001F0000)
  #define HIRQ_MUXH_INTSEL13_SHIFT             (0x00000010)

  #define HIRQ_MUXH_INTSEL13_GET(RegAddr) \
    HFIELD_GET(RegAddr,HIRQ_MUXH_INTSEL13)

  #define HIRQ_MUXH_INTSEL13_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HIRQ_MUXH_INTSEL13,Val)

/*----------------------------------------------------------------------------*\
* (RW) HIRQ_MUXH_INTSEL14
\*----------------------------------------------------------------------------*/
  #define HIRQ_MUXH_INTSEL14_MASK              (0x03E00000)
  #define HIRQ_MUXH_INTSEL14_SHIFT             (0x00000015)

  #define HIRQ_MUXH_INTSEL14_GET(RegAddr) \
    HFIELD_GET(RegAddr,HIRQ_MUXH_INTSEL14)

  #define HIRQ_MUXH_INTSEL14_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HIRQ_MUXH_INTSEL14,Val)

/*----------------------------------------------------------------------------*\
* (RW) HIRQ_MUXH_INTSEL15
\*----------------------------------------------------------------------------*/
  #define HIRQ_MUXH_INTSEL15_MASK              (0x7C000000)
  #define HIRQ_MUXH_INTSEL15_SHIFT             (0x0000001A)

  #define HIRQ_MUXH_INTSEL15_GET(RegAddr) \
    HFIELD_GET(RegAddr,HIRQ_MUXH_INTSEL15)

  #define HIRQ_MUXH_INTSEL15_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HIRQ_MUXH_INTSEL15,Val)

/*----------------------------------------------------------------------------*\
* (RW) HIRQ_MUXH
\*----------------------------------------------------------------------------*/
  #define HIRQ_MUXH_GET(RegAddr) HREG32_GET(RegAddr)
  #define HIRQ_MUXH_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)
    
  #define HIRQ_MUXH_CFG(RegAddr,intsel10,intsel11,intsel12,intsel13,intsel14,\
  intsel15) REG32(RegAddr) = (\
    HFIELD_SHIFT(HIRQ_MUXH_INTSEL10, intsel10)|\
    HFIELD_SHIFT(HIRQ_MUXH_INTSEL11, intsel11)|\
    HFIELD_SHIFT(HIRQ_MUXH_INTSEL12, intsel12)|\
    HFIELD_SHIFT(HIRQ_MUXH_INTSEL13, intsel13)|\
    HFIELD_SHIFT(HIRQ_MUXH_INTSEL14, intsel14)|\
    HFIELD_SHIFT(HIRQ_MUXH_INTSEL15, intsel15)\
  )

/******************************************************************************\
* HIRQ_EXTPOL - external interrupt polarity register
*
* Fields:
*   (RW) HIRQ_EXTPOL_XIP4
*   (RW) HIRQ_EXTPOL_XIP5
*   (RW) HIRQ_EXTPOL_XIP6
*   (RW) HIRQ_EXTPOL_XIP7
*
\******************************************************************************/
  #define HIRQ_EXTPOL_ADDR                     (HIRQ_BASE_ADDR+0x0008)
  #define HIRQ_EXTPOL                          REG32(HIRQ_EXTPOL_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) HIRQ_EXTPOL_XIP4
\*----------------------------------------------------------------------------*/
  #define HIRQ_EXTPOL_XIP4_MASK                (0x00000001)
  #define HIRQ_EXTPOL_XIP4_SHIFT               (0x00000000)
  
  #define HIRQ_EXTPOL_XIP4_GET(RegAddr) \
    HFIELD_GET(RegAddr,HIRQ_EXTPOL_XIP4)

  #define HIRQ_EXTPOL_XIP4_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HIRQ_EXTPOL_XIP4,Val)

/*----------------------------------------------------------------------------*\
* (RW) HIRQ_EXTPOL_XIP5
\*----------------------------------------------------------------------------*/
  #define HIRQ_EXTPOL_XIP5_MASK                (0x00000002)
  #define HIRQ_EXTPOL_XIP5_SHIFT               (0x00000001)
  
  #define HIRQ_EXTPOL_XIP5_GET(RegAddr) \
    HFIELD_GET(RegAddr,HIRQ_EXTPOL_XIP5)

  #define HIRQ_EXTPOL_XIP5_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HIRQ_EXTPOL_XIP5,Val)

/*----------------------------------------------------------------------------*\
* (RW) HIRQ_EXTPOL_XIP6
\*----------------------------------------------------------------------------*/
  #define HIRQ_EXTPOL_XIP6_MASK                (0x00000004)
  #define HIRQ_EXTPOL_XIP6_SHIFT               (0x00000002)
  
  #define HIRQ_EXTPOL_XIP6_GET(RegAddr) \
    HFIELD_GET(RegAddr,HIRQ_EXTPOL_XIP6)

  #define HIRQ_EXTPOL_XIP6_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HIRQ_EXTPOL_XIP6,Val)

/*----------------------------------------------------------------------------*\
* (RW) HIRQ_EXTPOL_XIP7
\*----------------------------------------------------------------------------*/
  #define HIRQ_EXTPOL_XIP7_MASK                (0x00000008)
  #define HIRQ_EXTPOL_XIP7_SHIFT               (0x00000003)
  
  #define HIRQ_EXTPOL_XIP7_GET(RegAddr) \
    HFIELD_GET(RegAddr,HIRQ_EXTPOL_XIP7)

  #define HIRQ_EXTPOL_XIP7_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HIRQ_EXTPOL_XIP7,Val)

/*----------------------------------------------------------------------------*\
* (RW) HIRQ_EXTPOL
\*----------------------------------------------------------------------------*/
  #define HIRQ_EXTPOL_GET(RegAddr) HREG32_GET(RegAddr)
  #define HIRQ_EXTPOL_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)
    
  #define HIRQ_EXTPOL_CFG(RegAddr,xip4,xip5,xip6,xip7)\
  REG32(RegAddr) = (\
    HFIELD_SHIFT(HIRQ_EXTPOL_XIP4, xip4)|\
    HFIELD_SHIFT(HIRQ_EXTPOL_XIP5, xip5)|\
    HFIELD_SHIFT(HIRQ_EXTPOL_XIP6, xip6)|\
    HFIELD_SHIFT(HIRQ_EXTPOL_XIP7, xip7)\
  )

/*----------------------------------------------------------------------------*/

#endif /* IRQ_SUPPORT */
#endif /* _IRQHAL_H_ */
/******************************************************************************\
* End of irqhal.h
\******************************************************************************/

/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... mcbsphal.h
* DATE CREATED.. 06/12/1999 
* LAST MODIFIED. 03/08/2000
*
*------------------------------------------------------------------------------
* DESCRIPTION:  (HAL interface file for the MCBSP module)
*
* Registers Covered:
*   HMCBSP_DRR0  - serial port 0 data receive register
*   HMCBSP_DXR0  - serial port 0 data transmit register
*   HMCBSP_SPCR0 - serial port 0 control register
*   HMCBSP_RCR0  - serial port 0 receive control register
*   HMCBSP_XCR0  - serial port 0 transmit control register
*   HMCBSP_SRGR0 - serial port 0 sample rate generator register
*   HMCBSP_MCR0  - serial port 0 multichannel control register
*   HMCBSP_RCER0 - serial port 0 receive channel enable register
*   HMCBSP_XCER0 - serial port 0 transmit channel enable register
*   HMCBSP_PCR0  - serial port 0 pin control register
*
*   HMCBSP_DRR1  - serial port 1 data receive register
*   HMCBSP_DXR1  - serial port 1 data transmit register
*   HMCBSP_SPCR1 - serial port 1 control register
*   HMCBSP_RCR1  - serial port 1 receive control register
*   HMCBSP_XCR1  - serial port 1 transmit control register
*   HMCBSP_SRGR1 - serial port 1 sample rate generator register
*   HMCBSP_MCR1  - serial port 1 multichannel control register
*   HMCBSP_RCER1 - serial port 1 receive channel enable register
*   HMCBSP_XCER1 - serial port 1 transmit channel enable register
*   HMCBSP_PCR1  - serial port 1 pin control register
*
*   HMCBSP_DRR2  - serial port 2 data receive register (1)
*   HMCBSP_DXR2  - serial port 2 data transmit register (1)
*   HMCBSP_SPCR2 - serial port 2 control register (1)
*   HMCBSP_RCR2  - serial port 2 receive control register (1)
*   HMCBSP_XCR2  - serial port 2 transmit control register (1)
*   HMCBSP_SRGR2 - serial port 2 sample rate generator register (1)
*   HMCBSP_MCR2  - serial port 2 multichannel control register (1)
*   HMCBSP_RCER2 - serial port 2 receive channel enable register (1)
*   HMCBSP_XCER2 - serial port 2 transmit channel enable register (1)
*   HMCBSP_PCR2  - serial port 2 pin control register (1)
*
*   (1) only on devices with three serial ports
*
\******************************************************************************/
#ifndef _MCBSPHAL_H_
#define _MCBSPHAL_H_

#if (MCBSP_SUPPORT)
/*============================================================================*\
*  misc declarations
\*============================================================================*/
#define HMCBSP_BASE0_ADDR              (HCHIP_PERBASE_ADDR+0x000C0000)
#define HMCBSP_BASE1_ADDR              (HCHIP_PERBASE_ADDR+0x00100000)
#define HMCBSP_BASE2_ADDR              (HCHIP_PERBASE_ADDR+0x00240000)

#if (CHIP_6202 | CHIP_6203)
  #define HMCBSP_PORT_CNT              (3)
#else
  #define HMCBSP_PORT_CNT              (2)
#endif

/******************************************************************************\
* HMCBSP_DRR0 - serial port 0 data receive register
* HMCBSP_DRR1 - serial port 1 data receive register
* HMCBSP_DRR2 - serial port 2 data receive register (1)
*
* (1) only on devices with three serial ports
*
* Fields:
*   (R) HMCBSP_DRR_DRR
*
\******************************************************************************/
#if (C11_SUPPORT & 0)
  #define HMCBSP_DRR0_ADDR                     (0x30000000)
  #define HMCBSP_DRR1_ADDR                     (0x34000000)
#else
  #define HMCBSP_DRR0_ADDR                     (HMCBSP_BASE0_ADDR+0x0000)
  #define HMCBSP_DRR1_ADDR                     (HMCBSP_BASE1_ADDR+0x0000)
#endif  
  #define HMCBSP_DRR0                          REG32(HMCBSP_DRR0_ADDR)
  #define HMCBSP_DRR1                          REG32(HMCBSP_DRR1_ADDR)

#if (HMCBSP_PORT_CNT==3)
  #define HMCBSP_DRR2_ADDR                     (HMCBSP_BASE2_ADDR+0x0000)
  #define HMCBSP_DRR2                          REG32(HMCBSP_DRR2_ADDR)
#endif

/*----------------------------------------------------------------------------*\
* (R) HMCBSP_DRR_DRR
\*----------------------------------------------------------------------------*/
  #define HMCBSP_DRR_DRR_MASK                  (0xFFFFFFFF)
  #define HMCBSP_DRR_DRR_SHIFT                 (0x00000000)

  #define HMCBSP_DRR_DRR_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_DRR_DRR)

/*----------------------------------------------------------------------------*\
* (R) HMCBSP_DRR
\*----------------------------------------------------------------------------*/
  #define HMCBSP_DRR_GET(RegAddr) HREG32_GET(RegAddr)

/******************************************************************************\
* HMCBSP_DXR0  - serial port 0 data transmit register
* HMCBSP_DXR1  - serial port 1 data transmit register
* HMCBSP_DXR2  - serial port 2 data transmit register (1)
*
* (1) only on devices with three serial ports
*
* Fields:
*   (W) HMCBSP_DXR_DXR
*
\******************************************************************************/
#if (C11_SUPPORT & 0)
  #define HMCBSP_DXR0_ADDR                     (0x30000000)
  #define HMCBSP_DXR1_ADDR                     (0x34000000)
#else
  #define HMCBSP_DXR0_ADDR                     (HMCBSP_BASE0_ADDR+0x0004)
  #define HMCBSP_DXR1_ADDR                     (HMCBSP_BASE1_ADDR+0x0004)
#endif  
  #define HMCBSP_DXR0                          REG32(HMCBSP_DXR0_ADDR)
  #define HMCBSP_DXR1                          REG32(HMCBSP_DXR1_ADDR)

#if (HMCBSP_PORT_CNT==3)
  #define HMCBSP_DXR2_ADDR                     (HMCBSP_BASE2_ADDR+0x0004)
  #define HMCBSP_DXR2                          REG32(HMCBSP_DXR2_ADDR)
#endif

/*----------------------------------------------------------------------------*\
* (W) HMCBSP_DXR_DXR
\*----------------------------------------------------------------------------*/
  #define HMCBSP_DXR_DXR_MASK                  (0xFFFFFFFF)
  #define HMCBSP_DXR_DXR_SHIFT                 (0x00000000)
  
  #define HMCBSP_DXR_DXR_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_DXR_DXR,Val)

/*----------------------------------------------------------------------------*\
* (W) HMCBSP_DXR
\*----------------------------------------------------------------------------*/ 
  #define HMCBSP_DXR_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HMCBSP_DXR_CFG(RegAddr,dxr) REG32(RegAddr)=(UINT32)( \
    HFIELD_SHIFT(HMCBSP_DXR_DXR,dxr) \
  )
  
/******************************************************************************\
* HMCBSP_SPCR0 - serial port 0 control register
* HMCBSP_SPCR1 - serial port 1 control register
* HMCBSP_SPCR2 - serial port 2 control register (1)
*
* (1) only on devices with three serial ports
*
* Fields:
*   (RW) HMCBSP_SPCR_RRST
*   (R)  HMCBSP_SPCR_RRDY
*   (R)  HMCBSP_SPCR_FULL
*   (RW) HMCBSP_SPCR_RSYNCERR
*   (RW) HMCBSP_SPCR_RINTM
*   (RW) HMCBSP_SPCR_DXENA
*   (RW) HMCBSP_SPCR_CLKSTP
*   (RW) HMCBSP_SPCR_RJUST
*   (RW) HMCBSP_SPCR_DLB
*   (RW) HMCBSP_SPCR_XRST
*   (R)  HMCBSP_SPCR_XRDY
*   (R)  HMCBSP_SPCR_XEMPTY
*   (RW) HMCBSP_SPCR_XSYNCERR
*   (RW) HMCBSP_SPCR_XINTM
*   (RW) HMCBSP_SPCR_GRST
*   (RW) HMCBSP_SPCR_FRST
*
\******************************************************************************/
  #define HMCBSP_SPCR0_ADDR                    (HMCBSP_BASE0_ADDR+0x0008)
  #define HMCBSP_SPCR1_ADDR                    (HMCBSP_BASE1_ADDR+0x0008)
  #define HMCBSP_SPCR0                         REG32(HMCBSP_SPCR0_ADDR)
  #define HMCBSP_SPCR1                         REG32(HMCBSP_SPCR1_ADDR)

#if (HMCBSP_PORT_CNT==3)
  #define HMCBSP_SPCR2_ADDR                    (HMCBSP_BASE2_ADDR+0x0008)
  #define HMCBSP_SPCR2                         REG32(HMCBSP_SPCR2_ADDR)
#endif

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_SPCR_RRST
\*----------------------------------------------------------------------------*/
  #define HMCBSP_SPCR_RRST_MASK                (0x00000001)
  #define HMCBSP_SPCR_RRST_SHIFT               (0x00000000) 
  
  #define HMCBSP_SPCR_RRST_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_SPCR_RRST)

  #define HMCBSP_SPCR_RRST_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_SPCR_RRST,Val)

/*----------------------------------------------------------------------------*\
* (R) HMCBSP_SPCR_RRDY
\*----------------------------------------------------------------------------*/
  #define HMCBSP_SPCR_RRDY_MASK                (0x00000002)
  #define HMCBSP_SPCR_RRDY_SHIFT               (0x00000001)

  #define HMCBSP_SPCR_RRDY_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_SPCR_RRDY)

/*----------------------------------------------------------------------------*\
* (R) HMCBSP_SPCR_RFULL
\*----------------------------------------------------------------------------*/
  #define HMCBSP_SPCR_RFULL_MASK               (0x00000004)
  #define HMCBSP_SPCR_RFULL_SHIFT              (0x00000002)

  #define HMCBSP_SPCR_RFULL_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_SPCR_RFULL)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_SPCR_RSYNCERR
\*----------------------------------------------------------------------------*/
  #define HMCBSP_SPCR_RSYNCERR_MASK            (0x00000008)
  #define HMCBSP_SPCR_RSYNCERR_SHIFT           (0x00000003)

  #define HMCBSP_SPCR_RSYNCERR_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_SPCR_RSYNCERR)

  #define HMCBSP_SPCR_RSYNCERR_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_SPCR_RSYNCERR,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_SPCR_RINTM
\*----------------------------------------------------------------------------*/
  #define HMCBSP_SPCR_RINTM_MASK               (0x00000030)
  #define HMCBSP_SPCR_RINTM_SHIFT              (0x00000004)

  #define HMCBSP_SPCR_RINTM_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_SPCR_RINTM)

  #define HMCBSP_SPCR_RINTM_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_SPCR_RINTM,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_SPCR_DXENA
\*----------------------------------------------------------------------------*/
#if (C11_SUPPORT)    
  #define HMCBSP_SPCR_DXENA_MASK               (0x00000080)
  #define HMCBSP_SPCR_DXENA_SHIFT              (0x00000007)
#else
  #define HMCBSP_SPCR_DXENA_MASK               (0x00000000)
  #define HMCBSP_SPCR_DXENA_SHIFT              (0x00000000)
#endif  

  #define HMCBSP_SPCR_DXENA_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_SPCR_DXENA)

  #define HMCBSP_SPCR_DXENA_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_SPCR_DXENA,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_SPCR_CLKSTP
\*----------------------------------------------------------------------------*/
  #define HMCBSP_SPCR_CLKSTP_MASK              (0x00001800)
  #define HMCBSP_SPCR_CLKSTP_SHIFT             (0x0000000B)

  #define HMCBSP_SPCR_CLKSTP_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_SPCR_CLKSTP)

  #define HMCBSP_SPCR_CLKSTP_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_SPCR_CLKSTP,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_SPCR_RJUST
\*----------------------------------------------------------------------------*/
  #define HMCBSP_SPCR_RJUST_MASK               (0x00006000)
  #define HMCBSP_SPCR_RJUST_SHIFT              (0x0000000D)

  #define HMCBSP_SPCR_RJUST_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_SPCR_RJUST)

  #define HMCBSP_SPCR_RJUST_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_SPCR_RJUST,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_SPCR_DLB
\*----------------------------------------------------------------------------*/
  #define HMCBSP_SPCR_DLB_MASK                 (0x00008000)
  #define HMCBSP_SPCR_DLB_SHIFT                (0x0000000F)

  #define HMCBSP_SPCR_DLB_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_SPCR_DLB)

  #define HMCBSP_SPCR_DLB_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_SPCR_DLB,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_SPCR_XRST
\*----------------------------------------------------------------------------*/
  #define HMCBSP_SPCR_XRST_MASK                (0x00010000)
  #define HMCBSP_SPCR_XRST_SHIFT               (0x00000010)

  #define HMCBSP_SPCR_XRST_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_SPCR_XRST)

  #define HMCBSP_SPCR_XRST_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_SPCR_XRST,Val)

/*----------------------------------------------------------------------------*\
* (R) HMCBSP_SPCR_XRDY
\*----------------------------------------------------------------------------*/
  #define HMCBSP_SPCR_XRDY_MASK                (0x00020000)
  #define HMCBSP_SPCR_XRDY_SHIFT               (0x00000011)

  #define HMCBSP_SPCR_XRDY_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_SPCR_XRDY)

  #define HMCBSP_SPCR_XRDY_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_SPCR_XRDY,Val)

/*----------------------------------------------------------------------------*\
* (R) HMCBSP_SPCR_XEMPTY
\*----------------------------------------------------------------------------*/
  #define HMCBSP_SPCR_XEMPTY_MASK              (0x00040000)
  #define HMCBSP_SPCR_XEMPTY_SHIFT             (0x00000012)

  #define HMCBSP_SPCR_XEMPTY_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_SPCR_XEMPTY)

  #define HMCBSP_SPCR_XEMPTY_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_SPCR_XEMPTY,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_SPCR_XSYNCERR
\*----------------------------------------------------------------------------*/
  #define HMCBSP_SPCR_XSYNCERR_MASK            (0x00080000)
  #define HMCBSP_SPCR_XSYNCERR_SHIFT           (0x00000013)

  #define HMCBSP_SPCR_XSYNCERR_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_SPCR_XSYNCERR)

  #define HMCBSP_SPCR_XSYNCERR_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_SPCR_XSYNCERR,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_SPCR_XINTM
\*----------------------------------------------------------------------------*/
  #define HMCBSP_SPCR_XINTM_MASK               (0x00300000)
  #define HMCBSP_SPCR_XINTM_SHIFT              (0x00000014)

  #define HMCBSP_SPCR_XINTM_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_SPCR_XINTM)

  #define HMCBSP_SPCR_XINTM_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_SPCR_XINTM,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_SPCR_GRST
\*----------------------------------------------------------------------------*/
  #define HMCBSP_SPCR_GRST_MASK                (0x00400000)
  #define HMCBSP_SPCR_GRST_SHIFT               (0x00000016)

  #define HMCBSP_SPCR_GRST_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_SPCR_GRST)

  #define HMCBSP_SPCR_GRST_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_SPCR_GRST,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_SPCR_FRST
\*----------------------------------------------------------------------------*/
  #define HMCBSP_SPCR_FRST_MASK                (0x00800000)
  #define HMCBSP_SPCR_FRST_SHIFT               (0x00000017)

  #define HMCBSP_SPCR_FRST_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_SPCR_FRST)

  #define HMCBSP_SPCR_FRST_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_SPCR_FRST,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_SPCR
\*----------------------------------------------------------------------------*/
  #define HMCBSP_SPCR_GET(RegAddr) HREG32_GET(RegAddr)
  #define HMCBSP_SPCR_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HMCBSP_SPCR_CFG(RegAddr,rrst,rsyncerr,rintm,dxena,clkstp,rjust,dlb,\
  xrst,xsyncerr,xintm,grst,frst) REG32(RegAddr)=(UINT32)(\
    HFIELD_SHIFT(HMCBSP_SPCR_RRST,    rrst)    |\
    HFIELD_SHIFT(HMCBSP_SPCR_RSYNCERR,rsyncerr)|\
    HFIELD_SHIFT(HMCBSP_SPCR_RINTM,   rintm)   |\
    HFIELD_SHIFT(HMCBSP_SPCR_DXENA,   dxena)   |\
    HFIELD_SHIFT(HMCBSP_SPCR_CLKSTP,  clkstp)  |\
    HFIELD_SHIFT(HMCBSP_SPCR_RJUST,   rjust)   |\
    HFIELD_SHIFT(HMCBSP_SPCR_DLB,     dlb)     |\
    HFIELD_SHIFT(HMCBSP_SPCR_XRST,    xrst)    |\
    HFIELD_SHIFT(HMCBSP_SPCR_XSYNCERR,xsyncerr)|\
    HFIELD_SHIFT(HMCBSP_SPCR_XINTM,   xintm)   |\
    HFIELD_SHIFT(HMCBSP_SPCR_GRST,    grst)    |\
    HFIELD_SHIFT(HMCBSP_SPCR_FRST,    frst)     \
  )

/******************************************************************************\
* HMCBSP_RCR0  - serial port 0 receive control register
* HMCBSP_RCR1  - serial port 1 receive control register
* HMCBSP_RCR2  - serial port 2 receive control register (1)
*
* (1) only on devices with three serial ports
*
* Fields:
*   (RW) HMCBSP_RCR_RWDREVRS (2)
*   (RW) HMCBSP_RCR_RWDLEN1
*   (RW) HMCBSP_RCR_RFRLEN1
*   (RW) HMCBSP_RCR_RPHASE2 (2)
*   (RW) HMCBSP_RCR_RDATDLY
*   (RW) HMCBSP_RCR_RFIG
*   (RW) HMCBSP_RCR_RCOMPAND
*   (RW) HMCBSP_RCR_RWDLEN2
*   (RW) HMCBSP_RCR_RFRLEN2
*   (RW) HMCBSP_RCR_RPHASE 
*
* (2) - C11_SUPPORT only
*
\******************************************************************************/
  #define HMCBSP_RCR0_ADDR                     (HMCBSP_BASE0_ADDR+0x000C)
  #define HMCBSP_RCR1_ADDR                     (HMCBSP_BASE1_ADDR+0x000C)
  #define HMCBSP_RCR0                          REG32(HMCBSP_RCR0_ADDR)
  #define HMCBSP_RCR1                          REG32(HMCBSP_RCR1_ADDR)

#if (HMCBSP_PORT_CNT==3)
  #define HMCBSP_RCR2_ADDR                     (HMCBSP_BASE2_ADDR+0x000C)
  #define HMCBSP_RCR2                          REG32(HMCBSP_RCR2_ADDR)
#endif

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCR_RWDREVRS
\*----------------------------------------------------------------------------*/
#if (C11_SUPPORT)
  #define HMCBSP_RCR_RWDREVRS_MASK             (0x00000010)
  #define HMCBSP_RCR_RWDREVRS_SHIFT            (0x00000004)
#else
  #define HMCBSP_RCR_RWDREVRS_MASK             (0x00000000)
  #define HMCBSP_RCR_RWDREVRS_SHIFT            (0x00000000)
#endif      

  #define HMCBSP_RCR_RWDREVRS_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCR_RWDREVRS)

  #define HMCBSP_RCR_RWDREVRS_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCR_RWDREVRS,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCR_RWDLEN1
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCR_RWDLEN1_MASK              (0x000000E0)
  #define HMCBSP_RCR_RWDLEN1_SHIFT             (0x00000005)

  #define HMCBSP_RCR_RWDLEN1_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCR_RWDLEN1)

  #define HMCBSP_RCR_RWDLEN1_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCR_RWDLEN1,Val)
/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCR_RFRLEN1
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCR_RFRLEN1_MASK              (0x00007F00)
  #define HMCBSP_RCR_RFRLEN1_SHIFT             (0x00000008)

  #define HMCBSP_RCR_RFRLEN1_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCR_RFRLEN1)

  #define HMCBSP_RCR_RFRLEN1_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCR_RFRLEN1,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCR_RPHASE2
\*----------------------------------------------------------------------------*/
#if (C11_SUPPORT)
  #define HMCBSP_RCR_RPHASE2_MASK              (0x00008000)
  #define HMCBSP_RCR_RPHASE2_SHIFT             (0x0000000F)
#else
  #define HMCBSP_RCR_RPHASE2_MASK              (0x00000000)
  #define HMCBSP_RCR_RPHASE2_SHIFT             (0x00000000)
#endif

  #define HMCBSP_RCR_RPHASE2_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCR_RPHASE2)

  #define HMCBSP_RCR_RPHASE2_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCR_RPHASE2,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCR_RDATDLY
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCR_RDATDLY_MASK              (0x00030000)
  #define HMCBSP_RCR_RDATDLY_SHIFT             (0x00000010)

  #define HMCBSP_RCR_RDATDLY_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCR_RDATDLY)

  #define HMCBSP_RCR_RDATDLY_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCR_RDATDLY,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCR_RFIG
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCR_RFIG_MASK                 (0x00040000)
  #define HMCBSP_RCR_RFIG_SHIFT                (0x00000012)

  #define HMCBSP_RCR_RFIG_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCR_RFIG)

  #define HMCBSP_RCR_RFIG_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCR_RFIG,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCR_RCOMPAND
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCR_RCOMPAND_MASK             (0x00180000)
  #define HMCBSP_RCR_RCOMPAND_SHIFT            (0x00000013)

  #define HMCBSP_RCR_RCOMPAND_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCR_RCOMPAND)

  #define HMCBSP_RCR_RCOMPAND_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCR_RCOMPAND,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCR_RWDLEN2
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCR_RWDLEN2_MASK              (0x00E00000)
  #define HMCBSP_RCR_RWDLEN2_SHIFT             (0x00000015)

  #define HMCBSP_RCR_RWDLEN2_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCR_RWDLEN2)

  #define HMCBSP_RCR_RWDLEN2_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCR_RWDLEN2,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCR_RFRLEN2
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCR_RFRLEN2_MASK              (0x7F000000)
  #define HMCBSP_RCR_RFRLEN2_SHIFT             (0x00000018)

  #define HMCBSP_RCR_FRFLEN2_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCR_FRFLEN2)

  #define HMCBSP_RCR_FRFLEN2_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCR_FRFLEN2,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCR_RPHASE
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCR_RPHASE_MASK               (0x80000000)
  #define HMCBSP_RCR_RPHASE_SHIFT              (0x0000001F)
  
  #define HMCBSP_RCR_RPHASE_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCR_RPHASE)

  #define HMCBSP_RCR_RPHASE_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCR_RPHASE,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCR
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCR_GET(RegAddr) HREG32_GET(RegAddr)
  #define HMCBSP_RCR_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HMCBSP_RCR_CFG(RegAddr,rwdrevrs,rwdlen1,rfrlen1,rphase2,rdatdly,\
  rfig,rcompand,rwdlen2,rfrlen2,rphase) REG32(RegAddr)=(UINT32)(\
    HFIELD_SHIFT(HMCBSP_RCR_RWDREVRS,rwdrevrs)|\
    HFIELD_SHIFT(HMCBSP_RCR_RWDLEN1, rwdlen1) |\
    HFIELD_SHIFT(HMCBSP_RCR_RFRLEN1, rfrlen1) |\
    HFIELD_SHIFT(HMCBSP_RCR_RPHASE2, rphase2) |\
    HFIELD_SHIFT(HMCBSP_RCR_RDATDLY, rdatdly) |\
    HFIELD_SHIFT(HMCBSP_RCR_RFIG,    rfig)    |\
    HFIELD_SHIFT(HMCBSP_RCR_RCOMPAND,rcompand)|\
    HFIELD_SHIFT(HMCBSP_RCR_RWDLEN2, rwdlen2) |\
    HFIELD_SHIFT(HMCBSP_RCR_RFRLEN2, rfrlen2) |\
    HFIELD_SHIFT(HMCBSP_RCR_RPHASE,  rphase)   \
  )

/******************************************************************************\
* HMCBSP_XCR0  - serial port 0 transmit control register
* HMCBSP_XCR1  - serial port 1 transmit control register
* HMCBSP_XCR2  - serial port 2 transmit control register (1)
*
* (1) only on devices with three serial ports
*
* Fields:
*   (RW) HMCBSP_XCR_XWDREVRS (2)
*   (RW) HMCBSP_XCR_XWDLEN1
*   (RW) HMCBSP_XCR_XFRLEN1
*   (RW) HMCBSP_XCR_XPHASE2 (2)
*   (RW) HMCBSP_XCR_XDATDLY
*   (RW) HMCBSP_XCR_XFIG
*   (RW) HMCBSP_XCR_XCOMPAND
*   (RW) HMCBSP_XCR_XWDLEN2
*   (RW) HMCBSP_XCR_XFRLEN2
*   (RW) HMCBSP_XCR_XPHASE 
*
* (2) - C11_SUPPORT only
*
\******************************************************************************/
  #define HMCBSP_XCR0_ADDR                     (HMCBSP_BASE0_ADDR+0x0010)
  #define HMCBSP_XCR1_ADDR                     (HMCBSP_BASE1_ADDR+0x0010)
  #define HMCBSP_XCR0                          REG32(HMCBSP_XCR0_ADDR)
  #define HMCBSP_XCR1                          REG32(HMCBSP_XCR1_ADDR)

#if (HMCBSP_PORT_CNT==3)
  #define HMCBSP_XCR2_ADDR                     (HMCBSP_BASE2_ADDR+0x0010)
  #define HMCBSP_XCR2                          REG32(HMCBSP_XCR2_ADDR)
#endif

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCR_RWDREVRS
\*----------------------------------------------------------------------------*/
#if (C11_SUPPORT)
  #define HMCBSP_XCR_XWDREVRS_MASK             (0x00000010)
  #define HMCBSP_XCR_XWDREVRS_SHIFT            (0x00000004)
#else
  #define HMCBSP_XCR_XWDREVRS_MASK             (0x00000000)
  #define HMCBSP_XCR_XWDREVRS_SHIFT            (0x00000000)
#endif      

  #define HMCBSP_XCR_XWDREVRS_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCR_XWDREVRS)

  #define HMCBSP_XCR_XWDREVRS_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCR_XWDREVRS,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCR_XWDLEN1
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCR_XWDLEN1_MASK              (0x000000E0)
  #define HMCBSP_XCR_XWDLEN1_SHIFT             (0x00000005)
  
  #define HMCBSP_XCR_XWDLEN1_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCR_XWDLEN1)

  #define HMCBSP_XCR_XWDLEN1_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCR_XWDLEN1,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCR_XFRLEN1
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCR_XFRLEN1_MASK              (0x00007F00)
  #define HMCBSP_XCR_XFRLEN1_SHIFT             (0x00000008)

  #define HMCBSP_XCR_XFRLEN1_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCR_XFRLEN1)

  #define HMCBSP_XCR_XFRLEN1_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCR_XFRLEN1,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCR_XPHASE2
\*----------------------------------------------------------------------------*/
#if (C11_SUPPORT)
  #define HMCBSP_XCR_XPHASE2_MASK              (0x00008000)
  #define HMCBSP_XCR_XPHASE2_SHIFT             (0x0000000F)
#else
  #define HMCBSP_XCR_XPHASE2_MASK              (0x00000000)
  #define HMCBSP_XCR_XPHASE2_SHIFT             (0x00000000)
#endif

  #define HMCBSP_XCR_XPHASE2_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCR_XPHASE2)

  #define HMCBSP_XCR_XPHASE2_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCR_XPHASE2,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCR_XDATDLY
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCR_XDATDLY_MASK              (0x00030000)
  #define HMCBSP_XCR_XDATDLY_SHIFT             (0x00000010)

  #define HMCBSP_XCR_XDATDLY_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCR_XDATDLY)

  #define HMCBSP_XCR_XDATDLY_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCR_XDATDLY,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCR_XFIG
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCR_XFIG_MASK                 (0x00040000)
  #define HMCBSP_XCR_XFIG_SHIFT                (0x00000012)

  #define HMCBSP_XCR_XFIG_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCR_XFIG)

  #define HMCBSP_XCR_XFIG_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCR_XFIG,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCR_XCOMPAND
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCR_XCOMPAND_MASK             (0x00180000)
  #define HMCBSP_XCR_XCOMPAND_SHIFT            (0x00000013)

  #define HMCBSP_XCR_XCOMPAND_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCR_XCOMPAND)

  #define HMCBSP_XCR_XCOMPAND_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCR_XCOMPAND,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCR_XWDLEN2
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCR_XWDLEN2_MASK              (0x00E00000)
  #define HMCBSP_XCR_XWDLEN2_SHIFT             (0x00000015)

  #define HMCBSP_XCR_XWDLEN2_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCR_XWDLEN2)

  #define HMCBSP_XCR_XWDLEN2_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCR_XWDLEN2,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCR_XFRLEN2
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCR_XFRLEN2_MASK              (0x7F000000)
  #define HMCBSP_XCR_XFRLEN2_SHIFT             (0x00000018)

  #define HMCBSP_XCR_XFRLEN2_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCR_XFRLEN2)

  #define HMCBSP_XCR_XFRLEN2_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCR_XFRLEN2,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCR_XPHASE
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCR_XPHASE_MASK               (0x80000000)
  #define HMCBSP_XCR_XPHASE_SHIFT              (0x0000001F)

  #define HMCBSP_XCR_XPHASE_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCR_XPHASE)

  #define HMCBSP_XCR_XPHASE_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCR_XPHASE,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCR
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCR_GET(RegAddr) HREG32_GET(RegAddr)
  #define HMCBSP_XCR_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HMCBSP_XCR_CFG(RegAddr,xwdrevrs,xwdlen1,xfrlen1,xphase2,xdatdly,\
  xfig,xcompand,xwdlen2,xfrlen2,xphase) (REG32(RegAddr)=(UINT32)(\
    HFIELD_SHIFT(HMCBSP_XCR_XWDREVRS,xwdrevrs)|\
    HFIELD_SHIFT(HMCBSP_XCR_XWDLEN1, xwdlen1) |\
    HFIELD_SHIFT(HMCBSP_XCR_XFRLEN1, xfrlen1) |\
    HFIELD_SHIFT(HMCBSP_XCR_XPHASE2, xphase2) |\
    HFIELD_SHIFT(HMCBSP_XCR_XDATDLY, xdatdly) |\
    HFIELD_SHIFT(HMCBSP_XCR_XFIG,    xfig)    |\
    HFIELD_SHIFT(HMCBSP_XCR_XCOMPAND,xcompand)|\
    HFIELD_SHIFT(HMCBSP_XCR_XWDLEN2, xwdlen2) |\
    HFIELD_SHIFT(HMCBSP_XCR_XFRLEN2, xfrlen2) |\
    HFIELD_SHIFT(HMCBSP_XCR_XPHASE,  xphase)   \
  )

/******************************************************************************\
* HMCBSP_SRGR0 - serial port 0 sample rate generator register
* HMCBSP_SRGR1 - serial port 1 sample rate generator register
* HMCBSP_SRGR2 - serial port 2 sample rate generator register (1)
*
* (1) only on devices with three serial ports
*
* Fields:
*   (RW) HMCBSP_SRGR_CLKGDV
*   (RW) HMCBSP_SRGR_FWID
*   (RW) HMCBSP_SRGR_FPER
*   (RW) HMCBSP_SRGR_FSGM
*   (RW) HMCBSP_SRGR_CLKSM
*   (RW) HMCBSP_SRGR_CLKSP
*   (RW) HMCBSP_SRGR_GSYNC
*
\******************************************************************************/
  #define HMCBSP_SRGR0_ADDR                    (HMCBSP_BASE0_ADDR+0x0014)
  #define HMCBSP_SRGR1_ADDR                    (HMCBSP_BASE1_ADDR+0x0014)
  #define HMCBSP_SRGR0                         REG32(HMCBSP_SRGR0_ADDR)
  #define HMCBSP_SRGR1                         REG32(HMCBSP_SRGR1_ADDR)

#if (HMCBSP_PORT_CNT==3)
  #define HMCBSP_SRGR2_ADDR                    (HMCBSP_BASE2_ADDR+0x0014)
  #define HMCBSP_SRGR2                         REG32(HMCBSP_SRGR2_ADDR)
#endif

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_SRGR_CLKGDV
\*----------------------------------------------------------------------------*/
  #define HMCBSP_SRGR_CLKGDV_MASK              (0x000000FF)
  #define HMCBSP_SRGR_CLKGDV_SHIFT             (0x00000000)
  
  #define HMCBSP_SRGR_CLKGDV_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_SRGR_CLKGDV)

  #define HMCBSP_SRGR_CLKGDV_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_SRGR_CLKGDV,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_SRGR_FWID
\*----------------------------------------------------------------------------*/
  #define HMCBSP_SRGR_FWID_MASK                (0x0000FF00)
  #define HMCBSP_SRGR_FWID_SHIFT               (0x00000008)

  #define HMCBSP_SRGR_FWID_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_SRGR_FWID)

  #define HMCBSP_SRGR_FWID_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_SRGR_FWID,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_SRGR_FPER
\*----------------------------------------------------------------------------*/
  #define HMCBSP_SRGR_FPER_MASK                (0x0FFF0000)
  #define HMCBSP_SRGR_FPER_SHIFT               (0x00000010)

  #define HMCBSP_SRGR_FPER_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_SRGR_FPER)

  #define HMCBSP_SRGR_FPER_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_SRGR_FPER,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_SRGR_FSGM
\*----------------------------------------------------------------------------*/
  #define HMCBSP_SRGR_FSGM_MASK                (0x10000000)
  #define HMCBSP_SRGR_FSGM_SHIFT               (0x0000001C)

  #define HMCBSP_SRGR_FSGM_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_SRGR_FSGM)

  #define HMCBSP_SRGR_FSGM_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_SRGR_FSGM,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_SRGR_CLKSM
\*----------------------------------------------------------------------------*/
  #define HMCBSP_SRGR_CLKSM_MASK               (0x20000000)
  #define HMCBSP_SRGR_CLKSM_SHIFT              (0x0000001D)

  #define HMCBSP_SRGR_CLKSM_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_SRGR_CLKSM)

  #define HMCBSP_SRGR_CLKSM_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_SRGR_CLKSM,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_SRGR_CLKSP
\*----------------------------------------------------------------------------*/
  #define HMCBSP_SRGR_CLKSP_MASK               (0x40000000)
  #define HMCBSP_SRGR_CLKSP_SHIFT              (0x0000001E)

  #define HMCBSP_SRGR_CLKSP_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_SRGR_CLKSP)

  #define HMCBSP_SRGR_CLKSP_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_SRGR_CLKSP,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_SRGR_GSYNC
\*----------------------------------------------------------------------------*/
  #define HMCBSP_SRGR_GSYNC_MASK               (0x80000000)
  #define HMCBSP_SRGR_GSYNC_SHIFT              (0x0000001F)

  #define HMCBSP_SRGR_GSYNC_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_SRGR_GSYNC)

  #define HMCBSP_SRGR_GSYNC_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_SRGR_GSYNC,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_SRGR
\*----------------------------------------------------------------------------*/
  #define HMCBSP_SRGR_GET(RegAddr) HREG32_GET(RegAddr)
  #define HMCBSP_SRGR_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HMCBSP_SRGR_CFG(RegAddr,clkgdv,fwid,fper,fsgm,clksm,clksp,gsync) \
  REG32(RegAddr)=(UINT32)( \
    HFIELD_SHIFT(HMCBSP_SRGR_CLKGDV ,  clkgdv )|\
    HFIELD_SHIFT(HMCBSP_SRGR_FWID   ,  fwid   )|\
    HFIELD_SHIFT(HMCBSP_SRGR_FPER   ,  fper   )|\
    HFIELD_SHIFT(HMCBSP_SRGR_FSGM   ,  fsgm   )|\
    HFIELD_SHIFT(HMCBSP_SRGR_CLKSM  ,  clksm  )|\
    HFIELD_SHIFT(HMCBSP_SRGR_CLKSP  ,  clksp  )|\
    HFIELD_SHIFT(HMCBSP_SRGR_GSYNC  ,  gsync  ) \
  )

/******************************************************************************\
* HMCBSP_MCR0  - serial port 0 multichannel control register
* HMCBSP_MCR1  - serial port 1 multichannel control register
* HMCBSP_MCR2  - serial port 2 multichannel control register (1)
*
* (1) only on devices with three serial ports
*
* Fields:
*   (RW) HMCBSP_MCR_RMCM
*   (R)  HMCBSP_MCR_RCBLK
*   (RW) HMCBSP_MCR_RPABLK
*   (RW) HMCBSP_MCR_RPBBLK
*   (RW) HMCBSP_MCR_XMCM
*   (R)  HMCBSP_MCR_XCBLK
*   (RW) HMCBSP_MCR_XPABLK
*   (RW) HMCBSP_MCR_XPBBLK
*
\******************************************************************************/
  #define HMCBSP_MCR0_ADDR                     (HMCBSP_BASE0_ADDR+0x0018)
  #define HMCBSP_MCR1_ADDR                     (HMCBSP_BASE1_ADDR+0x0018)
  #define HMCBSP_MCR0                          REG32(HMCBSP_MCR0_ADDR)
  #define HMCBSP_MCR1                          REG32(HMCBSP_MCR1_ADDR)

#if (HMCBSP_PORT_CNT==3)
  #define HMCBSP_MCR2_ADDR                     (HMCBSP_BASE2_ADDR+0x0018)
  #define HMCBSP_MCR2                          REG32(HMCBSP_MCR2_ADDR)
#endif

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_MCR_RMCM
\*----------------------------------------------------------------------------*/
  #define HMCBSP_MCR_RMCM_MASK                 (0x00000001)
  #define HMCBSP_MCR_RMCM_SHIFT                (0x00000000)

  #define HMCBSP_MCR_RMCM_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_MCR_RMCM)

  #define HMCBSP_MCR_RMCM_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_MCR_RMCM,Val)

/*----------------------------------------------------------------------------*\
* (R) HMCBSP_MCR_RCBLK
\*----------------------------------------------------------------------------*/
  #define HMCBSP_MCR_RCBLK_MASK                (0x0000001C)
  #define HMCBSP_MCR_RCBLK_SHIFT               (0x00000002)

  #define HMCBSP_MCR_RCBLK_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_MCR_RCBLK)

  #define HMCBSP_MCR_RCBLK_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_MCR_RCBLK,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_MCR_RPABLK
\*----------------------------------------------------------------------------*/
  #define HMCBSP_MCR_RPABLK_MASK               (0x00000060)
  #define HMCBSP_MCR_RPABLK_SHIFT              (0x00000005)

  #define HMCBSP_MCR_RPABLK_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_MCR_RPABLK)

  #define HMCBSP_MCR_RPABLK_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_MCR_RPABLK,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_MCR_RPBBLK
\*----------------------------------------------------------------------------*/
  #define HMCBSP_MCR_RPBBLK_MASK               (0x00000180)
  #define HMCBSP_MCR_RPBBLK_SHIFT              (0x00000007)

  #define HMCBSP_MCR_RPBBLK_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_MCR_RPBBLK)

  #define HMCBSP_MCR_RPBBLK_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_MCR_RPBBLK,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_MCR_XMCM
\*----------------------------------------------------------------------------*/
  #define HMCBSP_MCR_XMCM_MASK                 (0x00030000)
  #define HMCBSP_MCR_XMCM_SHIFT                (0x00000010)

  #define HMCBSP_MCR_XMCM_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_MCR_XMCM)

  #define HMCBSP_MCR_XMCM_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_MCR_XMCM,Val)

/*----------------------------------------------------------------------------*\
* (R) HMCBSP_MCR_XCBLK
\*----------------------------------------------------------------------------*/
  #define HMCBSP_MCR_XCBLK_MASK                (0x001C0000)
  #define HMCBSP_MCR_XCBLK_SHIFT               (0x00000012)

  #define HMCBSP_MCR_XCBLK_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_MCR_XCBLK)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_MCR_XPABLK
\*----------------------------------------------------------------------------*/
  #define HMCBSP_MCR_XPABLK_MASK               (0x00600000)
  #define HMCBSP_MCR_XPABLK_SHIFT              (0x00000015)

  #define HMCBSP_MCR_XPABLK_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_MCR_XPABLK)

  #define HMCBSP_MCR_XPABLK_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_MCR_XPABLK,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_MCR_XPBBLK
\*----------------------------------------------------------------------------*/
  #define HMCBSP_MCR_XPBBLK_MASK               (0x01800000)
  #define HMCBSP_MCR_XPBBLK_SHIFT              (0x00000017)

  #define HMCBSP_MCR_XPBBLK_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_MCR_XPBBLK)

  #define HMCBSP_MCR_XPBBLK_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_MCR_XPBBLK,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_MCR
\*----------------------------------------------------------------------------*/
  #define HMCBSP_MCR_GET(RegAddr) HREG32_GET(RegAddr)
  #define HMCBSP_MCR_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HMCBSP_MCR_CFG(RegAddr,rmcm,rpablk,rpbblk,xmcm,xpablk,xpbblk) \
  REG32(RegAddr)=(UINT32)( \
    HFIELD_SHIFT(HMCBSP_MCR_RMCM  ,rmcm  )|\
    HFIELD_SHIFT(HMCBSP_MCR_RPABLK,rpablk)|\
    HFIELD_SHIFT(HMCBSP_MCR_RPBBLK,rpbblk)|\
    HFIELD_SHIFT(HMCBSP_MCR_XMCM  ,xmcm  )|\
    HFIELD_SHIFT(HMCBSP_MCR_XPABLK,xpablk)|\
    HFIELD_SHIFT(HMCBSP_MCR_XPBBLK,xpbblk) \
  )

/******************************************************************************\
* HMCBSP_RCER0 - serial port 0 receive channel enable register
* HMCBSP_RCER1 - serial port 1 receive channel enable register
* HMCBSP_RCER2 - serial port 2 receive channel enable register (1)
*
* (1) only on devices with three serial ports
*
* Fields:
*
\******************************************************************************/
  #define HMCBSP_RCER0_ADDR                    (HMCBSP_BASE0_ADDR+0x001C)
  #define HMCBSP_RCER1_ADDR                    (HMCBSP_BASE1_ADDR+0x001C)
  #define HMCBSP_RCER0                         REG32(HMCBSP_RCER0_ADDR)
  #define HMCBSP_RCER1                         REG32(HMCBSP_RCER1_ADDR)

#if (HMCBSP_PORT_CNT==3)
  #define HMCBSP_RCER2_ADDR                    (HMCBSP_BASE2_ADDR+0x001C)
  #define HMCBSP_RCER2                         REG32(HMCBSP_RCER2_ADDR)
#endif

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEA0
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEA0_MASK               (0x00000001)
  #define HMCBSP_RCER_RCEA0_SHIFT              (0x00000000)

  #define HMCBSP_RCER_RCEA0_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEA0)

  #define HMCBSP_RCER_RCEA0_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEA0,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEA1
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEA1_MASK               (0x00000002)
  #define HMCBSP_RCER_RCEA1_SHIFT              (0x00000001)

  #define HMCBSP_RCER_RCEA1_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEA1)

  #define HMCBSP_RCER_RCEA1_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEA1,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEA2
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEA2_MASK               (0x00000004)
  #define HMCBSP_RCER_RCEA2_SHIFT              (0x00000002)

  #define HMCBSP_RCER_RCEA2_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEA2)

  #define HMCBSP_RCER_RCEA2_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEA2,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEA3
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEA3_MASK               (0x00000008)
  #define HMCBSP_RCER_RCEA3_SHIFT              (0x00000003)

  #define HMCBSP_RCER_RCEA3_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEA3)

  #define HMCBSP_RCER_RCEA3_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEA3,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEA4
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEA4_MASK               (0x00000010)
  #define HMCBSP_RCER_RCEA4_SHIFT              (0x00000004)

  #define HMCBSP_RCER_RCEA4_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEA4)

  #define HMCBSP_RCER_RCEA4_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEA4,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEA5
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEA5_MASK               (0x00000020)
  #define HMCBSP_RCER_RCEA5_SHIFT              (0x00000005)

  #define HMCBSP_RCER_RCEA5_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEA5)

  #define HMCBSP_RCER_RCEA5_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEA5,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEA6
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEA6_MASK               (0x00000040)
  #define HMCBSP_RCER_RCEA6_SHIFT              (0x00000006)

  #define HMCBSP_RCER_RCEA6_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEA6)

  #define HMCBSP_RCER_RCEA6_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEA6,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEA7
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEA7_MASK               (0x00000080)
  #define HMCBSP_RCER_RCEA7_SHIFT              (0x00000007)

  #define HMCBSP_RCER_RCEA7_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEA7)

  #define HMCBSP_RCER_RCEA7_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEA7,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEA8
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEA8_MASK               (0x00000100)
  #define HMCBSP_RCER_RCEA8_SHIFT              (0x00000008)

  #define HMCBSP_RCER_RCEA8_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEA8)

  #define HMCBSP_RCER_RCEA8_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEA8,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEA9
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEA9_MASK               (0x00000200)
  #define HMCBSP_RCER_RCEA9_SHIFT              (0x00000009)

  #define HMCBSP_RCER_RCEA9_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEA9)

  #define HMCBSP_RCER_RCEA9_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEA9,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEA10
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEA10_MASK              (0x00000400)
  #define HMCBSP_RCER_RCEA10_SHIFT             (0x0000000A)

  #define HMCBSP_RCER_RCEA10_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEA10)

  #define HMCBSP_RCER_RCEA10_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEA10,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEA11
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEA11_MASK              (0x00000800)
  #define HMCBSP_RCER_RCEA11_SHIFT             (0x0000000B)

  #define HMCBSP_RCER_RCEA11_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEA11)

  #define HMCBSP_RCER_RCEA11_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEA11,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEA12
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEA12_MASK              (0x00001000)
  #define HMCBSP_RCER_RCEA12_SHIFT             (0x0000000C)

  #define HMCBSP_RCER_RCEA12_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEA12)

  #define HMCBSP_RCER_RCEA12_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEA12,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEA13
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEA13_MASK              (0x00002000)
  #define HMCBSP_RCER_RCEA13_SHIFT             (0x0000000D)

  #define HMCBSP_RCER_RCEA13_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEA13)

  #define HMCBSP_RCER_RCEA13_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEA13,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEA14
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEA14_MASK              (0x00004000)
  #define HMCBSP_RCER_RCEA14_SHIFT             (0x0000000E)

  #define HMCBSP_RCER_RCEA14_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEA14)

  #define HMCBSP_RCER_RCEA14_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEA14,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEA15
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEA15_MASK              (0x00008000)
  #define HMCBSP_RCER_RCEA15_SHIFT             (0x0000000F)

  #define HMCBSP_RCER_RCEA15_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEA15)

  #define HMCBSP_RCER_RCEA15_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEA15,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEB0
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEB0_MASK               (0x00010000)
  #define HMCBSP_RCER_RCEB0_SHIFT              (0x00000010)
  
  #define HMCBSP_RCER_RCEB0_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEB0)

  #define HMCBSP_RCER_RCEB0_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEB0,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEB1
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEB1_MASK               (0x00020000)
  #define HMCBSP_RCER_RCEB1_SHIFT              (0x00000011)
  
  #define HMCBSP_RCER_RCEB1_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEB1)

  #define HMCBSP_RCER_RCEB1_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEB1,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEB2
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEB2_MASK               (0x00040000)
  #define HMCBSP_RCER_RCEB2_SHIFT              (0x00000012)
  
  #define HMCBSP_RCER_RCEB2_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEB2)

  #define HMCBSP_RCER_RCEB2_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEB2,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEB3
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEB3_MASK               (0x00080000)
  #define HMCBSP_RCER_RCEB3_SHIFT              (0x00000013)
  
  #define HMCBSP_RCER_RCEB3_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEB3)

  #define HMCBSP_RCER_RCEB3_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEB3,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEB4
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEB4_MASK               (0x00100000)
  #define HMCBSP_RCER_RCEB4_SHIFT              (0x00000014)
  
  #define HMCBSP_RCER_RCEB4_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEB4)

  #define HMCBSP_RCER_RCEB4_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEB4,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEB5
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEB5_MASK               (0x00200000)
  #define HMCBSP_RCER_RCEB5_SHIFT              (0x00000015)
  
  #define HMCBSP_RCER_RCEB5_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEB5)

  #define HMCBSP_RCER_RCEB5_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEB5,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEB6
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEB6_MASK               (0x00400000)
  #define HMCBSP_RCER_RCEB6_SHIFT              (0x00000016)
  
  #define HMCBSP_RCER_RCEB6_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEB6)

  #define HMCBSP_RCER_RCEB6_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEB6,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEB7
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEB7_MASK               (0x00800000)
  #define HMCBSP_RCER_RCEB7_SHIFT              (0x00000017)
  
  #define HMCBSP_RCER_RCEB7_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEB7)

  #define HMCBSP_RCER_RCEB7_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEB7,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEB8
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEB8_MASK               (0x01000000)
  #define HMCBSP_RCER_RCEB8_SHIFT              (0x00000018)
  
  #define HMCBSP_RCER_RCEB8_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEB8)

  #define HMCBSP_RCER_RCEB8_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEB8,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEB9
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEB9_MASK               (0x02000000)
  #define HMCBSP_RCER_RCEB9_SHIFT              (0x00000019)
  
  #define HMCBSP_RCER_RCEB9_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEB9)

  #define HMCBSP_RCER_RCEB9_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEB9,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEB10
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEB10_MASK              (0x04000000)
  #define HMCBSP_RCER_RCEB10_SHIFT             (0x0000001A)
  
  #define HMCBSP_RCER_RCEB10_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEB10)

  #define HMCBSP_RCER_RCEB10_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEB10,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEB11
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEB11_MASK              (0x08000000)
  #define HMCBSP_RCER_RCEB11_SHIFT             (0x0000001B)
  
  #define HMCBSP_RCER_RCEB11_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEB11)

  #define HMCBSP_RCER_RCEB11_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEB11,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEB12
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEB12_MASK              (0x10000000)
  #define HMCBSP_RCER_RCEB12_SHIFT             (0x0000001C)
  
  #define HMCBSP_RCER_RCEB12_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEB12)

  #define HMCBSP_RCER_RCEB12_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEB12,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEB13
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEB13_MASK              (0x20000000)
  #define HMCBSP_RCER_RCEB13_SHIFT             (0x0000001D)
  
  #define HMCBSP_RCER_RCEB13_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEB13)

  #define HMCBSP_RCER_RCEB13_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEB13,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEB14
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEB14_MASK              (0x40000000)
  #define HMCBSP_RCER_RCEB14_SHIFT             (0x0000001E)
  
  #define HMCBSP_RCER_RCEB14_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEB14)

  #define HMCBSP_RCER_RCEB14_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEB14,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER_RCEB15
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_RCEB15_MASK              (0x80000000)
  #define HMCBSP_RCER_RCEB15_SHIFT             (0x0000001F)
  
  #define HMCBSP_RCER_RCEB15_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_RCER_RCEB15)

  #define HMCBSP_RCER_RCEB15_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_RCER_RCEB15,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_RCER
\*----------------------------------------------------------------------------*/
  #define HMCBSP_RCER_GET(RegAddr) HREG32_GET(RegAddr)
  #define HMCBSP_RCER_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HMCBSP_RCER_CFG(RegAddr,rcea0,rcea1,rcea2,rcea3,rcea4,rcea5,rcea6,\
  rcea7,rcea8,rcea9,rcea10,rcea11,rcea12,rcea13,rcea14,rcea15,rceb0,rceb1,\
  rceb2,rceb3,rceb4,rceb5,rceb6,rceb7,rceb8,rceb9,rceb10,rceb11,rceb12,rceb13,\
  rceb14,rceb15) REG32(RegAddr)=(UINT32)(\
    HFIELD_SHIFT(HMCBSP_RCER_RCEA0, rcea0 )|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEA1, rcea1 )|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEA2, rcea2 )|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEA3, rcea3 )|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEA4, rcea4 )|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEA5, rcea5 )|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEA6, rcea6 )|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEA7, rcea7 )|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEA8, rcea8 )|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEA9, rcea9 )|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEA10,rcea10)|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEA11,rcea11)|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEA12,rcea12)|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEA13,rcea13)|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEA14,rcea14)|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEA15,rcea15)|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEB0, rceb0 )|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEB1, rceb1 )|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEB2, rceb2 )|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEB3, rceb3 )|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEB4, rceb4 )|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEB5, rceb5 )|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEB6, rceb6 )|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEB7, rceb7 )|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEB8, rceb8 )|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEB9, rceb9 )|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEB10,rceb10)|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEB11,rceb11)|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEB12,rceb12)|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEB13,rceb13)|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEB14,rceb14)|\
    HFIELD_SHIFT(HMCBSP_RCER_RCEB15,rceb15) \
  )

/******************************************************************************\
* HMCBSP_XCER0 - serial port 0 transmit channel enable register
* HMCBSP_XCER1 - serial port 1 transmit channel enable register
* HMCBSP_XCER2 - serial port 2 transmit channel enable register (1)
*
* (1) only on devices with three serial ports
*
* Fields:
*
\******************************************************************************/
  #define HMCBSP_XCER0_ADDR                    (HMCBSP_BASE0_ADDR+0x0020)
  #define HMCBSP_XCER1_ADDR                    (HMCBSP_BASE1_ADDR+0x0020)
  #define HMCBSP_XCER0                         REG32(HMCBSP_XCER0_ADDR)
  #define HMCBSP_XCER1                         REG32(HMCBSP_XCER1_ADDR)

#if (HMCBSP_PORT_CNT==3)
  #define HMCBSP_XCER2_ADDR                    (HMCBSP_BASE2_ADDR+0x0020)
  #define HMCBSP_XCER2                         REG32(HMCBSP_XCER2_ADDR)
#endif

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEA0
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEA0_MASK               (0x00000001)
  #define HMCBSP_XCER_XCEA0_SHIFT              (0x00000000)

  #define HMCBSP_XCER_XCEA0_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEA0)

  #define HMCBSP_XCER_XCEA0_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEA0,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEA1
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEA1_MASK               (0x00000002)
  #define HMCBSP_XCER_XCEA1_SHIFT              (0x00000001)

  #define HMCBSP_XCER_XCEA1_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEA1)

  #define HMCBSP_XCER_XCEA1_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEA1,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEA2
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEA2_MASK               (0x00000004)
  #define HMCBSP_XCER_XCEA2_SHIFT              (0x00000002)

  #define HMCBSP_XCER_XCEA2_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEA2)

  #define HMCBSP_XCER_XCEA2_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEA2,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEA3
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEA3_MASK               (0x00000008)
  #define HMCBSP_XCER_XCEA3_SHIFT              (0x00000003)

  #define HMCBSP_XCER_XCEA3_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEA3)

  #define HMCBSP_XCER_XCEA3_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEA3,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEA4
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEA4_MASK               (0x00000010)
  #define HMCBSP_XCER_XCEA4_SHIFT              (0x00000004)

  #define HMCBSP_XCER_XCEA4_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEA4)

  #define HMCBSP_XCER_XCEA4_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEA4,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEA5
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEA5_MASK               (0x00000020)
  #define HMCBSP_XCER_XCEA5_SHIFT              (0x00000005)

  #define HMCBSP_XCER_XCEA5_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEA5)

  #define HMCBSP_XCER_XCEA5_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEA5,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEA6
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEA6_MASK               (0x00000040)
  #define HMCBSP_XCER_XCEA6_SHIFT              (0x00000006)

  #define HMCBSP_XCER_XCEA6_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEA6)

  #define HMCBSP_XCER_XCEA6_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEA6,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEA7
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEA7_MASK               (0x00000080)
  #define HMCBSP_XCER_XCEA7_SHIFT              (0x00000007)

  #define HMCBSP_XCER_XCEA7_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEA7)

  #define HMCBSP_XCER_XCEA7_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEA7,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEA8
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEA8_MASK               (0x00000100)
  #define HMCBSP_XCER_XCEA8_SHIFT              (0x00000008)

  #define HMCBSP_XCER_XCEA8_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEA8)

  #define HMCBSP_XCER_XCEA8_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEA8,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEA9
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEA9_MASK               (0x00000200)
  #define HMCBSP_XCER_XCEA9_SHIFT              (0x00000009)

  #define HMCBSP_XCER_XCEA9_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEA9)

  #define HMCBSP_XCER_XCEA9_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEA9,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEA10
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEA10_MASK              (0x00000400)
  #define HMCBSP_XCER_XCEA10_SHIFT             (0x0000000A)

  #define HMCBSP_XCER_XCEA10_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEA10)

  #define HMCBSP_XCER_XCEA10_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEA10,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEA11
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEA11_MASK              (0x00000800)
  #define HMCBSP_XCER_XCEA11_SHIFT             (0x0000000B)

  #define HMCBSP_XCER_XCEA11_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEA11)

  #define HMCBSP_XCER_XCEA11_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEA11,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEA12
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEA12_MASK              (0x00001000)
  #define HMCBSP_XCER_XCEA12_SHIFT             (0x0000000C)

  #define HMCBSP_XCER_XCEA12_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEA12)

  #define HMCBSP_XCER_XCEA12_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEA12,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEA13
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEA13_MASK              (0x00002000)
  #define HMCBSP_XCER_XCEA13_SHIFT             (0x0000000D)

  #define HMCBSP_XCER_XCEA13_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEA13)

  #define HMCBSP_XCER_XCEA13_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEA13,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEA14
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEA14_MASK              (0x00004000)
  #define HMCBSP_XCER_XCEA14_SHIFT             (0x0000000E)

  #define HMCBSP_XCER_XCEA14_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEA14)

  #define HMCBSP_XCER_XCEA14_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEA14,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEA15
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEA15_MASK              (0x00008000)
  #define HMCBSP_XCER_XCEA15_SHIFT             (0x0000000F)

  #define HMCBSP_XCER_XCEA15_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEA15)

  #define HMCBSP_XCER_XCEA15_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEA15,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEB0
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEB0_MASK               (0x00010000)
  #define HMCBSP_XCER_XCEB0_SHIFT              (0x00000010)
  
  #define HMCBSP_XCER_XCEB0_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEB0)

  #define HMCBSP_XCER_XCEB0_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEB0,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEB1
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEB1_MASK               (0x00020000)
  #define HMCBSP_XCER_XCEB1_SHIFT              (0x00000011)
  
  #define HMCBSP_XCER_XCEB1_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEB1)

  #define HMCBSP_XCER_XCEB1_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEB1,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEB2
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEB2_MASK               (0x00040000)
  #define HMCBSP_XCER_XCEB2_SHIFT              (0x00000012)
  
  #define HMCBSP_XCER_XCEB2_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEB2)

  #define HMCBSP_XCER_XCEB2_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEB2,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEB3
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEB3_MASK               (0x00080000)
  #define HMCBSP_XCER_XCEB3_SHIFT              (0x00000013)
  
  #define HMCBSP_XCER_XCEB3_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEB3)

  #define HMCBSP_XCER_XCEB3_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEB3,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEB4
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEB4_MASK               (0x00100000)
  #define HMCBSP_XCER_XCEB4_SHIFT              (0x00000014)
  
  #define HMCBSP_XCER_XCEB4_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEB4)

  #define HMCBSP_XCER_XCEB4_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEB4,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEB5
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEB5_MASK               (0x00200000)
  #define HMCBSP_XCER_XCEB5_SHIFT              (0x00000015)
  
  #define HMCBSP_XCER_XCEB5_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEB5)

  #define HMCBSP_XCER_XCEB5_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEB5,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEB6
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEB6_MASK               (0x00400000)
  #define HMCBSP_XCER_XCEB6_SHIFT              (0x00000016)
  
  #define HMCBSP_XCER_XCEB6_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEB6)

  #define HMCBSP_XCER_XCEB6_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEB6,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEB7
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEB7_MASK               (0x00800000)
  #define HMCBSP_XCER_XCEB7_SHIFT              (0x00000017)
  
  #define HMCBSP_XCER_XCEB7_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEB7)

  #define HMCBSP_XCER_XCEB7_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEB7,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEB8
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEB8_MASK               (0x01000000)
  #define HMCBSP_XCER_XCEB8_SHIFT              (0x00000018)
  
  #define HMCBSP_XCER_XCEB8_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEB8)

  #define HMCBSP_XCER_XCEB8_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEB8,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEB9
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEB9_MASK               (0x02000000)
  #define HMCBSP_XCER_XCEB9_SHIFT              (0x00000019)
  
  #define HMCBSP_XCER_XCEB9_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEB9)

  #define HMCBSP_XCER_XCEB9_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEB9,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEB10
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEB10_MASK              (0x04000000)
  #define HMCBSP_XCER_XCEB10_SHIFT             (0x0000001A)
  
  #define HMCBSP_XCER_XCEB10_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEB10)

  #define HMCBSP_XCER_XCEB10_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEB10,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEB11
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEB11_MASK              (0x08000000)
  #define HMCBSP_XCER_XCEB11_SHIFT             (0x0000001B)
  
  #define HMCBSP_XCER_XCEB11_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEB11)

  #define HMCBSP_XCER_XCEB11_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEB11,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEB12
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEB12_MASK              (0x10000000)
  #define HMCBSP_XCER_XCEB12_SHIFT             (0x0000001C)
  
  #define HMCBSP_XCER_XCEB12_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEB12)

  #define HMCBSP_XCER_XCEB12_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEB12,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEB13
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEB13_MASK              (0x20000000)
  #define HMCBSP_XCER_XCEB13_SHIFT             (0x0000001D)
  
  #define HMCBSP_XCER_XCEB13_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEB13)

  #define HMCBSP_XCER_XCEB13_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEB13,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEB14
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEB14_MASK              (0x40000000)
  #define HMCBSP_XCER_XCEB14_SHIFT             (0x0000001E)
  
  #define HMCBSP_XCER_XCEB14_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEB14)

  #define HMCBSP_XCER_XCEB14_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEB14,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER_XCEB15
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_XCEB15_MASK              (0x80000000)
  #define HMCBSP_XCER_XCEB15_SHIFT             (0x0000001F)
  
  #define HMCBSP_XCER_XCEB15_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_XCER_XCEB15)

  #define HMCBSP_XCER_XCEB15_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_XCER_XCEB15,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_XCER
\*----------------------------------------------------------------------------*/
  #define HMCBSP_XCER_GET(RegAddr) HREG32_GET(RegAddr)
  #define HMCBSP_XCER_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HMCBSP_XCER_CFG(RegAddr,xcea0,xcea1,xcea2,xcea3,xcea4,xcea5,xcea6,\
  xcea7,xcea8,xcea9,xcea10,xcea11,xcea12,xcea13,xcea14,xcea15,xceb0,xceb1,\
  xceb2,xceb3,xceb4,xceb5,xceb6,xceb7,xceb8,xceb9,xceb10,xceb11,xceb12,xceb13,\
  xceb14,xceb15) REG32(RegAddr)=(UINT32)(\
    HFIELD_SHIFT(HMCBSP_XCER_XCEA0, xcea0 )|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEA1, xcea1 )|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEA2, xcea2 )|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEA3, xcea3 )|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEA4, xcea4 )|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEA5, xcea5 )|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEA6, xcea6 )|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEA7, xcea7 )|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEA8, xcea8 )|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEA9, xcea9 )|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEA10,xcea10)|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEA11,xcea11)|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEA12,xcea12)|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEA13,xcea13)|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEA14,xcea14)|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEA15,xcea15)|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEB0, xceb0 )|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEB1, xceb1 )|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEB2, xceb2 )|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEB3, xceb3 )|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEB4, xceb4 )|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEB5, xceb5 )|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEB6, xceb6 )|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEB7, xceb7 )|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEB8, xceb8 )|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEB9, xceb9 )|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEB10,xceb10)|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEB11,xceb11)|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEB12,xceb12)|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEB13,xceb13)|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEB14,xceb14)|\
    HFIELD_SHIFT(HMCBSP_XCER_XCEB15,xceb15) \
  )

/******************************************************************************\
* HMCBSP_PCR0  - serial port 0 pin control register
* HMCBSP_PCR1  - serial port 1 pin control register
* HMCBSP_PCR2  - serial port 2 pin control register (1)
*
* (1) only on devices with three serial ports
*
* Fields:
*   (RW) HMCBSP_PCR_CLKRP
*   (RW) HMCBSP_PCR_CLKXP
*   (RW) HMCBSP_PCR_FSRP
*   (RW) HMCBSP_PCR_FSXP
*   (R)  HMCBSP_PCR_DRSTAT
*   (RW) HMCBSP_PCR_DXSTAT
*   (RW) HMCBSP_PCR_CLKSSTAT
*   (RW) HMCBSP_PCR_CLKRM
*   (RW) HMCBSP_PCR_CLKXM
*   (RW) HMCBSP_PCR_FSRM
*   (RW) HMCBSP_PCR_FSXM
*   (RW) HMCBSP_PCR_RIOEN
*   (RW) HMCBSP_PCR_XIOEN
*
\******************************************************************************/
  #define HMCBSP_PCR0_ADDR                     (HMCBSP_BASE0_ADDR+0x0024)
  #define HMCBSP_PCR1_ADDR                     (HMCBSP_BASE1_ADDR+0x0024)
  #define HMCBSP_PCR0                          REG32(HMCBSP_PCR0_ADDR)
  #define HMCBSP_PCR1                          REG32(HMCBSP_PCR1_ADDR)

#if (HMCBSP_PORT_CNT==3)
  #define HMCBSP_PCR2_ADDR                     (HMCBSP_BASE2_ADDR+0x0024)
  #define HMCBSP_PCR2                          REG32(HMCBSP_PCR2_ADDR)
#endif

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_PCR_CLKRP
\*----------------------------------------------------------------------------*/
  #define HMCBSP_PCR_CLKRP_MASK                (0x00000001)
  #define HMCBSP_PCR_CLKRP_SHIFT               (0x00000000)

  #define HMCBSP_PCR_CLKRP_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_PCR_CLKRP)

  #define HMCBSP_PCR_CLKRP_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_PCR_CLKRP,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_PCR_CLKXP
\*----------------------------------------------------------------------------*/
  #define HMCBSP_PCR_CLKXP_MASK                (0x00000002)
  #define HMCBSP_PCR_CLKXP_SHIFT               (0x00000001)

  #define HMCBSP_PCR_CLKXP_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_PCR_CLKXP)

  #define HMCBSP_PCR_CLKXP_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_PCR_CLKXP,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_PCR_FSRP
\*----------------------------------------------------------------------------*/
  #define HMCBSP_PCR_FSRP_MASK                 (0x00000004)
  #define HMCBSP_PCR_FSRP_SHIFT                (0x00000002)

  #define HMCBSP_PCR_FSRP_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_PCR_FSRP)

  #define HMCBSP_PCR_FSRP_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_PCR_FSRP,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_PCR_FSXP
\*----------------------------------------------------------------------------*/
  #define HMCBSP_PCR_FSXP_MASK                 (0x00000008)
  #define HMCBSP_PCR_FSXP_SHIFT                (0x00000003)

  #define HMCBSP_PCR_FSXP_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_PCR_FSXP)

  #define HMCBSP_PCR_FSXP_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_PCR_FSXP,Val)

/*----------------------------------------------------------------------------*\
* (R) HMCBSP_PCR_DTSTAT
\*----------------------------------------------------------------------------*/
  #define HMCBSP_PCR_DRSTAT_MASK               (0x00000010)
  #define HMCBSP_PCR_DRSTAT_SHIFT              (0x00000004)

  #define HMCBSP_PCR_DRSTAT_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_PCR_DRSTAT)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_PCR_DXSTAT
\*----------------------------------------------------------------------------*/
  #define HMCBSP_PCR_DXSTAT_MASK               (0x00000020)
  #define HMCBSP_PCR_DXSTAT_SHIFT              (0x00000005)

  #define HMCBSP_PCR_DXSTAT_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_PCR_DXSTAT)

  #define HMCBSP_PCR_DXSTAT_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_PCR_DXSTAT,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_PCR_CLKSSTAT
\*----------------------------------------------------------------------------*/
  #define HMCBSP_PCR_CLKSSTAT_MASK             (0x00000040)
  #define HMCBSP_PCR_CLKSSTAT_SHIFT            (0x00000006)

  #define HMCBSP_PCR_CLKSSTAT_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_PCR_CLKSSTAT)

  #define HMCBSP_PCR_CLKSSTAT_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_PCR_CLKSSTAT,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_PCR_CLKRM
\*----------------------------------------------------------------------------*/
  #define HMCBSP_PCR_CLKRM_MASK                (0x00000100)
  #define HMCBSP_PCR_CLKRM_SHIFT               (0x00000008)

  #define HMCBSP_PCR_CLKRM_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_PCR_CLKRM)

  #define HMCBSP_PCR_CLKRM_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_PCR_CLKRM,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_PCR_CLKXM
\*----------------------------------------------------------------------------*/
  #define HMCBSP_PCR_CLKXM_MASK                (0x00000200)
  #define HMCBSP_PCR_CLKXM_SHIFT               (0x00000009)

  #define HMCBSP_PCR_CLKXM_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_PCR_CLKXM)

  #define HMCBSP_PCR_CLKXM_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_PCR_CLKXM,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_PCR_FSRM
\*----------------------------------------------------------------------------*/
  #define HMCBSP_PCR_FSRM_MASK                 (0x00000400)
  #define HMCBSP_PCR_FSRM_SHIFT                (0x0000000A)

  #define HMCBSP_PCR_FSRM_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_PCR_FSRM)

  #define HMCBSP_PCR_FSRM_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_PCR_FSRM,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_PCR_FSXM
\*----------------------------------------------------------------------------*/
  #define HMCBSP_PCR_FSXM_MASK                 (0x00000800)
  #define HMCBSP_PCR_FSXM_SHIFT                (0x0000000B)

  #define HMCBSP_PCR_FSXM_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_PCR_FSXM)

  #define HMCBSP_PCR_FSXM_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_PCR_FSXM,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_PCR_RIOEN
\*----------------------------------------------------------------------------*/
  #define HMCBSP_PCR_RIOEN_MASK                (0x00001000)
  #define HMCBSP_PCR_RIOEN_SHIFT               (0x0000000C)

  #define HMCBSP_PCR_RIOEN_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_PCR_RIOEN)

  #define HMCBSP_PCR_RIOEN_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_PCR_RIOEN,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_PCR_XIOEN
\*----------------------------------------------------------------------------*/
  #define HMCBSP_PCR_XIOEN_MASK                (0x00002000)
  #define HMCBSP_PCR_XIOEN_SHIFT               (0x0000000D)

  #define HMCBSP_PCR_XIOEN_GET(RegAddr) \
    HFIELD_GET(RegAddr,HMCBSP_PCR_XIOEN)

  #define HMCBSP_PCR_XIOEN_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HMCBSP_PCR_XIOEN,Val)

/*----------------------------------------------------------------------------*\
* (RW) HMCBSP_PCR
\*----------------------------------------------------------------------------*/
  #define HMCBSP_PCR_GET(RegAddr) HREG32_GET(RegAddr)
  #define HMCBSP_PCR_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)

  #define HMCBSP_PCR_CFG(RegAddr,clkrp,clkxp,fsrp,fsxp,dxstat,clksstat,clkrm,\
  clkxm,fsrm,fsxm,rioen,xioen) REG32(RegAddr)=(UINT32)(\
    HFIELD_SHIFT(HMCBSP_PCR_CLKRP   , clkrp   )|\
    HFIELD_SHIFT(HMCBSP_PCR_CLKXP   , clkxp   )|\
    HFIELD_SHIFT(HMCBSP_PCR_FSRP    , fsrp    )|\
    HFIELD_SHIFT(HMCBSP_PCR_FSXP    , fsxp    )|\
    HFIELD_SHIFT(HMCBSP_PCR_DXSTAT  , dxstat  )|\
    HFIELD_SHIFT(HMCBSP_PCR_CLKSSTAT, clksstat)|\
    HFIELD_SHIFT(HMCBSP_PCR_CLKRM   , clkrm   )|\
    HFIELD_SHIFT(HMCBSP_PCR_CLKXM   , clkxm   )|\
    HFIELD_SHIFT(HMCBSP_PCR_FSRM    , fsrm    )|\
    HFIELD_SHIFT(HMCBSP_PCR_FSXM    , fsxm    )|\
    HFIELD_SHIFT(HMCBSP_PCR_RIOEN   , rioen   )|\
    HFIELD_SHIFT(HMCBSP_PCR_XIOEN   , xioen   ) \
  )

/******************************************************************************/

#endif /* MCBSP_SUPPORT */
#endif /* _MCBSPHAL_H_ */
/******************************************************************************\
* End of mcbsphal.h
\******************************************************************************/

/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... pwrhal.h
* DATE CREATED.. 11/11/1999 
* LAST MODIFIED. 03/08/2000
*
*------------------------------------------------------------------------------
* DESCRIPTION:  (HAL interface file for the PWR module)
*
* Registers Covered:
*   (RW) HPWR_PDCTL - power down control register (1)

*   (1) only on CHIP_6202, CHIP_6203
*
\******************************************************************************/
#ifndef _PWRHAL_H_
#define _PWRHAL_H_

#if (PWR_SUPPORT)
  #define HPWR_BASE_ADDR        (HCHIP_PERBASE_ADDR+0x001C0000)

/******************************************************************************\
* HPWR_PDCTL - power down control register (1)
*
* Fields:
*   (RW) HPWR_PDCTL_DMA
*   (RW) HPWR_PDCTL_EMIF
*   (RW) HPWR_PDCTL_MCBSP0
*   (RW) HPWR_PDCTL_MCBSP1
*   (RW) HPWR_PDCTL_MCBSP2
*
\******************************************************************************/
#if (CHIP_6202)
  #define HPWR_PDCTL_ADDR                      (HPWR_BASE_ADDR+0x0200)
  #define HPWR_PDCTL                           REG32(HPWR_PDCTL_ADDR)
#else
  #define HPWR_PDCTL_ADDR                      (HCHIP_NULL_ADDR)
  #define HPWR_PDCTL                           REG32(HPWR_PDCTL_ADDR)
#endif
  
/*----------------------------------------------------------------------------*\
* (RW) HPWR_PDCTL_DMA
\*----------------------------------------------------------------------------*/
  #define HPWR_PDCTL_DMA_MASK                  (0x00000001)
  #define HPWR_PDCTL_DMA_SHIFT                 (0x00000000)

  #define HPWR_PDCTL_DMA_GET(RegAddr) \
    HFIELD_GET(RegAddr,HPWR_PDCTL_DMA)

  #define HPWR_PDCTL_DMA_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HPWR_PDCTL_DMA,Val)

/*----------------------------------------------------------------------------*\
* (RW) HPWR_PDCTL_EMIF
\*----------------------------------------------------------------------------*/
  #define HPWR_PDCTL_EMIF_MASK                 (0x00000002)
  #define HPWR_PDCTL_EMIF_SHIFT                (0x00000001)

  #define HPWR_PDCTL_EMIF_GET(RegAddr) \
    HFIELD_GET(RegAddr,HPWR_PDCTL_EMIF)

  #define HPWR_PDCTL_EMIF_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HPWR_PDCTL_EMIF,Val)

/*----------------------------------------------------------------------------*\
* (RW) HPWR_PDCTL_MCBSP0
\*----------------------------------------------------------------------------*/
  #define HPWR_PDCTL_MCBSP0_MASK               (0x00000004)
  #define HPWR_PDCTL_MCBSP0_SHIFT              (0x00000002)
  
  #define HPWR_PDCTL_MCBSP0_GET(RegAddr) \
    HFIELD_GET(RegAddr,HPWR_PDCTL_MCBSP0)

  #define HPWR_PDCTL_MCBSP0_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HPWR_PDCTL_MCBSP0,Val)

/*----------------------------------------------------------------------------*\
* (RW) HPWR_PDCTL_MCBSP1
\*----------------------------------------------------------------------------*/
  #define HPWR_PDCTL_MCBSP1_MASK               (0x00000008)
  #define HPWR_PDCTL_MCBSP1_SHIFT              (0x00000003)
  
  #define HPWR_PDCTL_MCBSP1_GET(RegAddr) \
    HFIELD_GET(RegAddr,HPWR_PDCTL_MCBSP1)

  #define HPWR_PDCTL_MCBSP1_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HPWR_PDCTL_MCBSP1,Val)

/*----------------------------------------------------------------------------*\
* (RW) HPWR_PDCTL_MCBSP2
\*----------------------------------------------------------------------------*/
  #define HPWR_PDCTL_MCBSP2_MASK               (0x00000010)
  #define HPWR_PDCTL_MCBSP2_SHIFT              (0x00000004)
  
  #define HPWR_PDCTL_MCBSP2_GET(RegAddr) \
    HFIELD_GET(RegAddr,HPWR_PDCTL_MCBSP2)

  #define HPWR_PDCTL_MCBSP2_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HPWR_PDCTL_MCBSP2,Val)

/*----------------------------------------------------------------------------*\
* (RW) HPWR_PDCTL
\*----------------------------------------------------------------------------*/
  #define HPWR_PDCTL_GET(RegAddr) HREG32_GET(RegAddr)
  #define HPWR_PDCTL_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)
    
  #define HPWR_PDCTL_CFG(RegAddr,dma,emif,mcbsp0,mcbsp1,mcbsp2)\
  REG32(RegAddr) = (\
    HFIELD_SHIFT(HPWR_PDCTL_DMA,dma)|\
    HFIELD_SHIFT(HPWR_PDCTL_EMIF,emif)|\
    HFIELD_SHIFT(HPWR_PDCTL_MCBSP0,mcbsp0)|\
    HFIELD_SHIFT(HPWR_PDCTL_MCBSP1,mcbsp1)|\
    HFIELD_SHIFT(HPWR_PDCTL_MCBSP2,mcbsp2)\
  )

/*----------------------------------------------------------------------------*/

#endif /* PWR_SUPPORT */
#endif /* _PWRHAL_H_ */
/******************************************************************************\
* End of pwrhal.h
\******************************************************************************/

/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... timerhal.h
* DATE CREATED.. 06/20/1999 
* LAST MODIFIED. 03/08/2000
*   
*------------------------------------------------------------------------------
* DESCRIPTION:  (HAL interface file for the TIMER module)
*
* Registers Covered:
*   (RW) HTIMER_CTL0 - timer 0 control register
*   (RW) HTIMER_CTL1 - timer 1 control register
*   (RW) HTIMER_PRD0 - timer 0 period register
*   (RW) HTIMER_PRD1 - timer 1 perid register
*   (RW) HTIMER_CNT0 - timer 0 count register
*   (RW) HTIMER_CNT1 - timer 1 count register
*
\******************************************************************************/
#ifndef _TIMERHAL_H_
#define _TIMERHAL_H_

#if (TIMER_SUPPORT)
/*============================================================================*\
* misc declarations
\*============================================================================*/
#define HTIMER_BASE0_ADDR  (HCHIP_PERBASE_ADDR+0x00140000)
#define HTIMER_BASE1_ADDR  (HCHIP_PERBASE_ADDR+0x00180000)

#define HTIMER_DEVICE_CNT  (2)

/******************************************************************************\
* HTIMER_CTL0 - timer 0 control register
* HTIMER_CTL1 - timer 1 control register
*
* Fields:
*   (RW) HTIMER_CTL_FUNC
*   (RW) HTIMER_CTL_INVOUT
*   (RW) HTIMER_CTL_DATOUT
*   (RW) HTIMER_CTL_DATIN
*   (RW) HTIMER_CTL_PWID
*   (RW) HTIMER_CTL_GO
*   (RW) HTIMER_CTL_HLD
*   (RW) HTIMER_CTL_CP
*   (RW) HTIMER_CTL_CLKSRC
*   (RW) HTIMER_CTL_INVINP
*   (R)  HTIMER_CTL_TSTAT
*
\******************************************************************************/
  #define HTIMER_CTL0_ADDR                     (HTIMER_BASE0_ADDR+0x0000)
  #define HTIMER_CTL1_ADDR                     (HTIMER_BASE1_ADDR+0x0000)

  #define HTIMER_CTL0                          REG32(HTIMER_CTL0_ADDR)
  #define HTIMER_CTL1                          REG32(HTIMER_CTL1_ADDR)
  
/*----------------------------------------------------------------------------*\
* (RW) TIMER_CTL_FUNC
\*----------------------------------------------------------------------------*/
  #define HTIMER_CTL_FUNC_MASK                 (0x00000001)
  #define HTIMER_CTL_FUNC_SHIFT                (0x00000000)
  
  #define HTIMER_CTL_FUNC_GET(RegAddr) \
    HFIELD_GET(RegAddr,HTIMER_CTL_FUNC)

  #define HTIMER_CTL_FUNC_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HTIMER_CTL_FUNC,Val)

/*----------------------------------------------------------------------------*\
* (RW) TIMER_CTL_INVOUT
\*----------------------------------------------------------------------------*/
  #define HTIMER_CTL_INVOUT_MASK               (0x00000002)
  #define HTIMER_CTL_INVOUT_SHIFT              (0x00000001)

  #define HTIMER_CTL_INVOUT_GET(RegAddr) \
    HFIELD_GET(RegAddr,HTIMER_CTL_INVOUT)

  #define HTIMER_CTL_INVOUT_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HTIMER_CTL_INVOUT,Val)

/*----------------------------------------------------------------------------*\
* (RW) TIMER_CTL_DATOUT
\*----------------------------------------------------------------------------*/
  #define HTIMER_CTL_DATOUT_MASK               (0x00000004)
  #define HTIMER_CTL_DATOUT_SHIFT              (0x00000002)

  #define HTIMER_CTL_DATOUT_GET(RegAddr) \
    HFIELD_GET(RegAddr,HTIMER_CTL_DATOUT)

  #define HTIMER_CTL_DATOUT_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HTIMER_CTL_DATOUT,Val)

/*----------------------------------------------------------------------------*\
* (RW) TIMER_CTL_DATIN
\*----------------------------------------------------------------------------*/
  #define HTIMER_CTL_DATIN_MASK                (0x00000008)
  #define HTIMER_CTL_DATIN_SHIFT               (0x00000003)

  #define HTIMER_CTL_DATIN_GET(RegAddr) \
    HFIELD_GET(RegAddr,HTIMER_CTL_DATIN)

  #define HTIMER_CTL_DATIN_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HTIMER_CTL_DATIN,Val)

/*----------------------------------------------------------------------------*\
* (RW) TIMER_CTL_PWID
\*----------------------------------------------------------------------------*/
  #define HTIMER_CTL_PWID_MASK                 (0x00000010)
  #define HTIMER_CTL_PWID_SHIFT                (0x00000004)

  #define HTIMER_CTL_PWID_GET(RegAddr) \
    HFIELD_GET(RegAddr,HTIMER_CTL_PWID)

  #define HTIMER_CTL_PWID_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HTIMER_CTL_PWID,Val)

/*----------------------------------------------------------------------------*\
* (RW) TIMER_CTL_GO
\*----------------------------------------------------------------------------*/
  #define HTIMER_CTL_GO_MASK                   (0x00000040)
  #define HTIMER_CTL_GO_SHIFT                  (0x00000006)

  #define HTIMER_CTL_GO_GET(RegAddr) \
    HFIELD_GET(RegAddr,HTIMER_CTL_GO)

  #define HTIMER_CTL_GO_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HTIMER_CTL_GO,Val)

/*----------------------------------------------------------------------------*\
* (RW) TIMER_CTL_HLD
\*----------------------------------------------------------------------------*/
  #define HTIMER_CTL_HLD_MASK                  (0x00000080)
  #define HTIMER_CTL_HLD_SHIFT                 (0x00000007)

  #define HTIMER_CTL_HLD_GET(RegAddr) \
    HFIELD_GET(RegAddr,HTIMER_CTL_HLD)

  #define HTIMER_CTL_HLD_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HTIMER_CTL_HLD,Val)

/*----------------------------------------------------------------------------*\
* (RW) TIMER_CTL_CP
\*----------------------------------------------------------------------------*/
  #define HTIMER_CTL_CP_MASK                   (0x00000100)
  #define HTIMER_CTL_CP_SHIFT                  (0x00000008)

  #define HTIMER_CTL_CP_GET(RegAddr) \
    HFIELD_GET(RegAddr,HTIMER_CTL_CP)

  #define HTIMER_CTL_CP_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HTIMER_CTL_CP,Val)

/*----------------------------------------------------------------------------*\
* (RW) TIMER_CTL_CLKSRC
\*----------------------------------------------------------------------------*/
  #define HTIMER_CTL_CLKSRC_MASK               (0x00000200)
  #define HTIMER_CTL_CLKSRC_SHIFT              (0x00000009)

  #define HTIMER_CTL_CLKSRC_GET(RegAddr) \
    HFIELD_GET(RegAddr,HTIMER_CTL_CLKSRC)

  #define HTIMER_CTL_CLKSRC_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HTIMER_CTL_CLKSRC,Val)

/*----------------------------------------------------------------------------*\
* (RW) TIMER_CTL_INVINP
\*----------------------------------------------------------------------------*/
  #define HTIMER_CTL_INVINP_MASK               (0x00000400)
  #define HTIMER_CTL_INVINP_SHIFT              (0x0000000A)

  #define HTIMER_CTL_INVINP_GET(RegAddr) \
    HFIELD_GET(RegAddr,HTIMER_CTL_INVINP)

  #define HTIMER_CTL_INVINP_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HTIMER_CTL_INVINP,Val)

/*----------------------------------------------------------------------------*\
* (R) TIMER_CTL_TSTAT
\*----------------------------------------------------------------------------*/
  #define HTIMER_CTL_TSTAT_MASK                (0x00000800)
  #define HTIMER_CTL_TSTAT_SHIFT               (0x0000000B)

  #define HTIMER_CTL_TSTAT_GET(RegAddr) \
    HFIELD_GET(RegAddr,HTIMER_CTL_TSTAT)

/*----------------------------------------------------------------------------*\
* (RW) TIMER_CTL
\*----------------------------------------------------------------------------*/
  #define HTIMER_CTL_GET(RegAddr) HREG32_GET(RegAddr)

  #define HTIMER_CTL_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)
    
  #define HTIMER_CTL_CFG(RegAddr,func,invout,datout,datin,pwid,go,hld,cp,\
  clksrc,invinp) REG32(RegAddr) = (\
    HFIELD_SHIFT(HTIMER_CTL_FUNC,   func)   |\
    HFIELD_SHIFT(HTIMER_CTL_DATOUT, datout) |\
    HFIELD_SHIFT(HTIMER_CTL_DATIN,  datin)  |\
    HFIELD_SHIFT(HTIMER_CTL_GO,     go)     |\
    HFIELD_SHIFT(HTIMER_CTL_HLD,    hld)    |\
    HFIELD_SHIFT(HTIMER_CTL_CP,     cp)     |\
    HFIELD_SHIFT(HTIMER_CTL_PWID,   pwid)   |\
    HFIELD_SHIFT(HTIMER_CTL_CLKSRC, clksrc) |\
    HFIELD_SHIFT(HTIMER_CTL_INVINP, invinp) |\
    HFIELD_SHIFT(HTIMER_CTL_INVOUT, invout)  \
  )

/******************************************************************************\
* HTIMER_PRD0 - timer 0 period register
* HTIMER_PRD1 - timer 1 period register
*
* Fields:
*   (RW) PRD
*
\******************************************************************************/
  #define HTIMER_PRD0_ADDR                     (HTIMER_BASE0_ADDR+0x0004)
  #define HTIMER_PRD1_ADDR                     (HTIMER_BASE1_ADDR+0x0004)

  #define HTIMER_PRD0                          REG32(HTIMER_PRD0_ADDR)
  #define HTIMER_PRD1                          REG32(HTIMER_PRD1_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) TIMER_PRD_PRD
\*----------------------------------------------------------------------------*/
  #define HTIMER_PRD_PRD_MASK                  (0xFFFFFFFF)
  #define HTIMER_PRD_PRD_SHIFT                 (0x00000000)
  
  #define HTIMER_PRD_PRD_GET(RegAddr) \
    HFIELD_GET(RegAddr,HTIMER_PRD_PRD)

  #define HTIMER_PRD_PRD_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HTIMER_PRD_PRD,Val)

/*----------------------------------------------------------------------------*\
* (RW) TIMER_PRD
\*----------------------------------------------------------------------------*/
  #define HTIMER_PRD_GET(RegAddr) HREG32_GET(RegAddr)

  #define HTIMER_PRD_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)
    
  #define HTIMER_PRD_CFG(RegAddr,Prd) REG32(RegAddr) = (UINT32)( \
    HFIELD_SHIFT(HTIMER_PRD_RRD,prd) \
  )

/******************************************************************************\
* HTIMER_CNT0 - timer 0 count register
* HTIMER_CNT1 - timer 1 count register
*
* Fields:
*   (RW) CNT
*
\******************************************************************************/
  #define HTIMER_CNT0_ADDR                     (HTIMER_BASE0_ADDR+0x0008)
  #define HTIMER_CNT1_ADDR                     (HTIMER_BASE1_ADDR+0x0008)

  #define HTIMER_CNT0                          REG32(HTIMER_CNT0_ADDR)
  #define HTIMER_CNT1                          REG32(HTIMER_CNT1_ADDR)

/*----------------------------------------------------------------------------*\
* (RW) TIMER_CNT_CNT
\*----------------------------------------------------------------------------*/
  #define HTIMER_CNT_CNT_MASK                  (0xFFFFFFFF)
  #define HTIMER_CNT_CNT_SHIFT                 (0x00000000)

  #define HTIMER_CNT_CNT_GET(RegAddr) \
    HFIELD_GET(RegAddr,HTIMER_CNT_CNT)

  #define HTIMER_CNT_CNT_SET(RegAddr,Val) \
    HFIELD_SET(RegAddr,HTIMER_CNT_CNT,Val)

/*----------------------------------------------------------------------------*\
* (RW) TIMER_CNT
\*----------------------------------------------------------------------------*/
  #define HTIMER_CNT_GET(RegAddr) HREG32_GET(RegAddr)

  #define HTIMER_CNT_SET(RegAddr,Val) HREG32_SET(RegAddr,Val)
    
  #define HTIMER_CNT_CFG(RegAddr,Cnt) REG32(RegAddr) = (UINT32)( \
    HFIELD_SHIFT(HTIMER_CNT_CNT,cnt) \
  )

/*----------------------------------------------------------------------------*/

#endif /* TIMER_SUPPORT */
#endif /* _TIMERHAL_H_ */
/******************************************************************************\
* End of timerhal.h
\******************************************************************************/



#endif /* _CSL_LEGACYHAL_H_ */
/******************************************************************************\
* End of csl_legacyhal.h
\******************************************************************************/

