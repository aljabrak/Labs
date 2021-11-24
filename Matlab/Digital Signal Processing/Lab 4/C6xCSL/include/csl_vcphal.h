/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_vcphal.h
* DATE CREATED.. 02/21/2001 
* LAST MODIFIED. 08/02/2004 - Adding support for C6418
*                04/17/2003
*------------------------------------------------------------------------------
* REGISTERS
*
* IC0   - VCP input configuration register  0
* IC1   - VCP input configuration register  1
* IC2   - VCP input configuration register  2
* IC3   - VCP input configuration register  3
* IC4   - VCP input configuration register  4
* IC5   - VCP input configuration register  5
* EXE   - VCP execution register 
* END   - VCP endian mode register
* OUT0   - VCP output parameters register   0
* OUT1   - VCP output parameters register   1
* STAT0  - VCP status register 0
* STAT1  - VCP status register 1
* ERR   - VCP error register
*
*------------------------------------------------------------------------------
* MEMORY REGIONS
*
* ICMEM - VCP interrupt configuration register space
* OPMEM - VCP output parameter register space
* BMMEM - VCP systematics and parities memory
* HDMEM - VCP hard decisions memory
*
******************************************************************************
*Corrections Made 04/17/2003
*#define  VCP_OPMEM_ADDR           0x50000048u	VCPOUT0	VCP Output Register 0 //Correction was 0x50000024u
*#define _VCP_IC4_IMINS_MASK       0x0FFF0000u	//Correction was 0x00FF0000u
*#define _VCP_IC4_IMAXS_MASK       0x00000FFFu	//Correction was 0x000000FFu
*#define  VCP_IC5_SDHD_SOFT        0x00000001u	//Correction was 0
*#define  VCP_IC5_SDHD_HARD        0x00000000u	//Correction was 1
*#define _VCP_OUT0_ADDR            0x01B80048u	//Correction was 0x01B80024u
*#define _VCP_OUT0_FMINS_MASK      0x0FFF0000u	//Correction was 0x00FF0000u
*#define _VCP_OUT0_FMAXS_MASK      0x00000FFFu	//Correction was 0x00000FFFu
*#define _VCP_ERR_ERROR_MASK       0x00000007u	//Correction was 0x00000400u
*#define _VCP_ERR_ERROR_SHIFT      0x00000000u	//Correction was 0x0000000Au
*#define _VCP_STAT0_NSYM_MASK      0xFFFF0000u
*#define _VCP_STAT0_NSYM_SHIFT     0x00000010u
*#define _VCP_OUT1_FMAXI_MASK      0x00000FFFu	//Correction was 0x00000FFFu
*#define _VCP_OUT1_ADDR            0x01B8004Cu	//Correction was 0x01B80028
\*******************************************************************************/
#ifndef _CSL_VCPHAL_H_
#define _CSL_VCPHAL_H_

#include <csl_stdinc.h>
#include <csl_chip.h>

#if (VCP_SUPPORT)
/******************************************************************************\
* Memory section
\******************************************************************************/

  #define _VCP_BASE_IC               0x01B80000u	/*VCPIC0	VCP Input Configuration Reg 0 Config bus*/
  #define  VCP_ICMEM_ADDR            0x50000000u	/*VCPIC0	VCP Input Configuration Reg 0 EDMA bus*/
  #define  VCP_OPMEM_ADDR            0x50000048u	/*VCPOUT0	VCP Output Register 0 Correction*/
  #define  VCP_BMMEM_ADDR            0x50000080u	/*VCPWBM	VCP Branch Metrics Write Register*/
  #define  VCP_HDMEM_ADDR            0x50000088u	/*VCPRDECS	VCP Decisions Read Register*/


/******************************************************************************\
* module level register/field access macros
\******************************************************************************/

  /* ----------------- */
  /* FIELD MAKE MACROS */
  /* ----------------- */

  #define VCP_FMK(REG,FIELD,x)\
    _PER_FMK(VCP,##REG,##FIELD,x)

  #define VCP_FMKS(REG,FIELD,SYM)\
    _PER_FMKS(VCP,##REG,##FIELD,##SYM)


  /* -------------------------------- */
  /* RAW REGISTER/FIELD ACCESS MACROS */
  /* -------------------------------- */

  #define VCP_ADDR(REG)\
    _VCP_##REG##_ADDR

  #define VCP_RGET(REG)\
    _PER_RGET(_VCP_##REG##_ADDR,VCP,##REG)

  #define VCP_RSET(REG,x)\
    _PER_RSET(_VCP_##REG##_ADDR,VCP,##REG,x)

  #define VCP_FGET(REG,FIELD)\
    _VCP_##REG##_FGET(##FIELD)

  #define VCP_FSET(REG,FIELD,x)\
    _VCP_##REG##_FSET(##FIELD,##x)

  #define VCP_FSETS(REG,FIELD,SYM)\
    _VCP_##REG##_FSETS(##FIELD,##SYM)


  /* ------------------------------------------ */
  /* ADDRESS BASED REGISTER/FIELD ACCESS MACROS */
  /* ------------------------------------------ */

  #define VCP_RGETA(addr,REG)\
    _PER_RGET(addr,VCP,##REG)

  #define VCP_RSETA(addr,REG,x)\
    _PER_RSET(addr,VCP,##REG,x)

  #define VCP_FGETA(addr,REG,FIELD)\
    _PER_FGET(addr,VCP,##REG,##FIELD)

  #define VCP_FSETA(addr,REG,FIELD,x)\
    _PER_FSET(addr,VCP,##REG,##FIELD,x)

  #define VCP_FSETSA(addr,REG,FIELD,SYM)\
    _PER_FSETS(addr,VCP,##REG,##FIELD,##SYM)


  /* ----------------------------------------- */
  /* HANDLE BASED REGISTER/FIELD ACCESS MACROS */
  /* ----------------------------------------- */

  #define VCP_ADDRH(h,REG)\
    (Uint32)(&((h)->baseAddr[_VCP_##REG##_OFFSET]))

  #define VCP_RGETH(h,REG)\
    VCP_RGETA(VCP_ADDRH(h,##REG),##REG)


  #define VCP_RSETH(h,REG,x)\
    VCP_RSETA(VCP_ADDRH(h,##REG),##REG,x)


  #define VCP_FGETH(h,REG,FIELD)\
    VCP_FGETA(VCP_ADDRH(h,##REG),##REG,##FIELD)


  #define VCP_FSETH(h,REG,FIELD,x)\
    VCP_FSETA(VCP_ADDRH(h,##REG),##REG,##FIELD,x)


  #define VCP_FSETSH(h,REG,FIELD,SYM)\
    VCP_FSETSA(VCP_ADDRH(h,##REG),##REG,##FIELD,##SYM)



/******************************************************************************\
* _____________________
* |                   |
* |  I C 0            |
* |___________________|
*
* VCP input configuration register  0
*
* FIELDS (msb -> lsb)
* (rw) POLY3
* (rw) POLY2
* (rw) POLY1
* (rw) POLY0
*
\******************************************************************************/
  #define _VCP_IC0_OFFSET            0

  #define _VCP_IC0_ADDR              0x01B80000u

  #define _VCP_IC0_POLY3_MASK        0xFF000000u
  #define _VCP_IC0_POLY3_SHIFT       0x00000018u
  #define  VCP_IC0_POLY3_DEFAULT     0x00000000u
  #define  VCP_IC0_POLY3_OF(x)       _VALUEOF(x)

  #define _VCP_IC0_POLY2_MASK        0x00FF0000u
  #define _VCP_IC0_POLY2_SHIFT       0x00000010u
  #define  VCP_IC0_POLY2_DEFAULT     0x00000000u
  #define  VCP_IC0_POLY2_OF(x)       _VALUEOF(x)

  #define _VCP_IC0_POLY1_MASK        0x0000FF00u
  #define _VCP_IC0_POLY1_SHIFT       0x00000008u
  #define  VCP_IC0_POLY1_DEFAULT     0x00000000u
  #define  VCP_IC0_POLY1_OF(x)       _VALUEOF(x)

  #define _VCP_IC0_POLY0_MASK        0x000000FFu
  #define _VCP_IC0_POLY0_SHIFT       0x00000000u
  #define  VCP_IC0_POLY0_DEFAULT     0x00000000u
  #define  VCP_IC0_POLY0_OF(x)       _VALUEOF(x)

  #define  VCP_IC0_OF(x)             _VALUEOF(x)

  #define VCP_IC0_DEFAULT (Uint32)(\
    _PER_FDEFAULT(VCP,IC0,POLY3)\
   |_PER_FDEFAULT(VCP,IC0,POLY2)\
   |_PER_FDEFAULT(VCP,IC0,POLY1)\
   |_PER_FDEFAULT(VCP,IC0,POLY0)\
  )

  #define VCP_IC0_RMK(poly3,poly2,poly1,poly0) (Uint32)(\
     _PER_FMK(VCP,IC0,POLY3,poly3)\
    |_PER_FMK(VCP,IC0,POLY2,poly2)\
    |_PER_FMK(VCP,IC0,POLY1,poly1)\
    |_PER_FMK(VCP,IC0,POLY0,poly0)\
  )

  #define _VCP_IC0_FGET(FIELD)\
    _PER_FGET(_VCP_IC0_ADDR,VCP,IC0,##FIELD)

  #define _VCP_IC0_FSET(FIELD,field)\
    _PER_FSET(_VCP_IC0_ADDR,VCP,IC0,##FIELD,field)

  #define _VCP_IC0_FSETS(FIELD,SYM)\
    _PER_FSETS(_VCP_IC0_ADDR,VCP,IC0,FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  I C 1            |
* |___________________|
*
* VCP input configuration register  1
*
* FIELDS (msb -> lsb)
* (rw) YAMEN
* (rw) YAMT
* (rw) ZERO
*
\******************************************************************************/
  #define _VCP_IC1_OFFSET            1

  #define _VCP_IC1_ADDR              0x01B80004u

  #define _VCP_IC1_YAMEN_MASK        0x10000000u
  #define _VCP_IC1_YAMEN_SHIFT       0x0000001Cu
  #define  VCP_IC1_YAMEN_DEFAULT     0x00000000u
  #define  VCP_IC1_YAMEN_OF(x)       _VALUEOF(x)
  #define  VCP_IC1_YAMEN_DISABLE     0x00000000u
  #define  VCP_IC1_YAMEN_ENABLE      0x00000001u

  #define _VCP_IC1_YAMT_MASK        0x0FFF0000u
  #define _VCP_IC1_YAMT_SHIFT       0x00000010u
  #define  VCP_IC1_YAMT_DEFAULT     0x00000000u
  #define  VCP_IC1_YAMT_OF(x)       _VALUEOF(x)

  #define _VCP_IC1_ZERO_MASK         0x0000FFFFu
  #define _VCP_IC1_ZERO_SHIFT        0x00000000u
  #define  VCP_IC1_ZERO_DEFAULT      0x00000000u
  #define  VCP_IC1_ZERO_OF(x)        _VALUEOF(x)
  #define  VCP_IC1_ZERO_ZEROS        0x00000000u

  #define  VCP_IC1_OF(x)             _VALUEOF(x)

  #define VCP_IC1_DEFAULT (Uint32)(\
    _PER_FDEFAULT(VCP,IC1,YAMEN)\
   |_PER_FDEFAULT(VCP,IC1,YAMT)\
   |_PER_FDEFAULT(VCP,IC1,ZERO)\
  )

  #define VCP_IC1_RMK(yamen,yamt,zero) (Uint32)(\
     _PER_FMK(VCP,IC1,YAMEN,yamen)\
    |_PER_FMK(VCP,IC1,YAMT,yamt)\
    |_PER_FMK(VCP,IC1,ZERO,zero)\
  )

  #define _VCP_IC1_FGET(FIELD)\
    _PER_FGET(_VCP_IC1_ADDR,VCP,IC1,##FIELD)

  #define _VCP_IC1_FSET(FIELD,field)\
    _PER_FSET(_VCP_IC1_ADDR,VCP,IC1,##FIELD,field)

  #define _VCP_IC1_FSETS(FIELD,SYM)\
    _PER_FSETS(_VCP_IC1_ADDR,VCP,IC1,FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  I C 2            |
* |___________________|
*
* VCP input configuration register  2
*
* FIELDS (msb -> lsb)
* (rw) R
* (rw) F
*
\******************************************************************************/
  #define _VCP_IC2_OFFSET            2

  #define _VCP_IC2_ADDR              0x01BA0008u

  #define _VCP_IC2_R_MASK        0xFFFF0000u
  #define _VCP_IC2_R_SHIFT       0x00000010u
  #define  VCP_IC2_R_DEFAULT     0x00000000u
  #define  VCP_IC2_R_OF(x)       _VALUEOF(x)

  #define _VCP_IC2_FL_MASK       0x0000FFFFu
  #define _VCP_IC2_FL_SHIFT      0x00000000u
  #define  VCP_IC2_FL_DEFAULT    0x00000000u
  #define  VCP_IC2_FL_OF(x)      _VALUEOF(x)

  #define  VCP_IC2_OF(x)             _VALUEOF(x)

  #define VCP_IC2_DEFAULT (Uint32)(\
    _PER_FDEFAULT(VCP,IC2,R)\
   |_PER_FDEFAULT(VCP,IC2,FL)\
  )

  #define VCP_IC2_RMK(r,fl) (Uint32)(\
     _PER_FMK(VCP,IC2,R,r)\
    |_PER_FMK(VCP,IC2,FL,fl)\
  )

  #define _VCP_IC2_FGET(FIELD)\
    _PER_FGET(_VCP_IC2_ADDR,VCP,IC2,##FIELD)

  #define _VCP_IC2_FSET(FIELD,field)\
    _PER_FSET(_VCP_IC2_ADDR,VCP,IC2,##FIELD,field)

  #define _VCP_IC2_FSETS(FIELD,SYM)\
    _PER_FSETS(_VCP_IC2_ADDR,VCP,IC2,FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  I C 3            |
* |___________________|
*
* VCP input configuration register  3
*
* FIELDS (msb -> lsb)
* (rw) C
*
\******************************************************************************/
  #define _VCP_IC3_OFFSET            3

  #define _VCP_IC3_ADDR              0x01BA000Cu

  #define _VCP_IC3_C_MASK       0x0000FFFFu
  #define _VCP_IC3_C_SHIFT      0x00000000u
  #define  VCP_IC3_C_DEFAULT    0x00000000u
  #define  VCP_IC3_C_OF(x)      _VALUEOF(x)

  #define  VCP_IC3_OF(x)             _VALUEOF(x)

  #define VCP_IC3_DEFAULT (Uint32)(\
    _PER_FDEFAULT(VCP,IC3,C)\
  )

  #define VCP_IC3_RMK(c) (Uint32)(\
     _PER_FMK(VCP,IC3,C,c)\
  )

  #define _VCP_IC3_FGET(FIELD)\
    _PER_FGET(_VCP_IC3_ADDR,VCP,IC3,##FIELD)

  #define _VCP_IC3_FSET(FIELD,field)\
    _PER_FSET(_VCP_IC3_ADDR,VCP,IC3,##FIELD,field)

  #define _VCP_IC3_FSETS(FIELD,SYM)\
    _PER_FSETS(_VCP_IC3_ADDR,VCP,IC3,FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  I C 4            |
* |___________________|
*
* VCP input configuration register  4
*
* FIELDS (msb -> lsb)
* (rw) IMINS
* (rw) IMAXS
*
\******************************************************************************/
  #define _VCP_IC4_OFFSET            4

  #define _VCP_IC4_ADDR              0x01BA0010u

  #define _VCP_IC4_IMINS_MASK         0x0FFF0000u	/*Correction*/
  #define _VCP_IC4_IMINS_SHIFT        0x00000010u
  #define  VCP_IC4_IMINS_DEFAULT      0x00000000u
  #define  VCP_IC4_IMINS_OF(x)        _VALUEOF(x)

  #define _VCP_IC4_IMAXS_MASK          0x00000FFFu	/*Correction*/
  #define _VCP_IC4_IMAXS_SHIFT         0x00000000u
  #define  VCP_IC4_IMAXS_DEFAULT       0x00000000u
  #define  VCP_IC4_IMAXS_OF(x)         _VALUEOF(x)

  #define  VCP_IC4_OF(x)             _VALUEOF(x)

  #define VCP_IC4_DEFAULT (Uint32)(\
    _PER_FDEFAULT(VCP,IC4,IMINS)\
   |_PER_FDEFAULT(VCP,IC4,IMAXS)\
  )

  #define VCP_IC4_RMK(imins,imaxs) (Uint32)(\
     _PER_FMK(VCP,IC4,IMINS,imins)\
    |_PER_FMK(VCP,IC4,IMAXS,imaxs)\
  )

  #define _VCP_IC4_FGET(FIELD)\
    _PER_FGET(_VCP_IC4_ADDR,VCP,IC4,##FIELD)

  #define _VCP_IC4_FSET(FIELD,field)\
    _PER_FSET(_VCP_IC4_ADDR,VCP,IC4,##FIELD,field)

  #define _VCP_IC4_FSETS(FIELD,SYM)\
    _PER_FSETS(_VCP_IC4_ADDR,VCP,IC4,FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  I C 5            |
* |___________________|
*
* VCP input configuration register  5
*
* FIELDS (msb -> lsb)
* (rw) SDHD
* (rw) OUTF
* (rw) TB
* (rw) SYMR
* (rw) SYMX
* (rw) IMAXI
*
\******************************************************************************/
  #define _VCP_IC5_OFFSET            5

  #define _VCP_IC5_ADDR              0x01BA0014u

  #define _VCP_IC5_SDHD_MASK        0x80000000u
  #define _VCP_IC5_SDHD_SHIFT       0x0000001Fu
  #define  VCP_IC5_SDHD_DEFAULT     0x00000000u
  #define  VCP_IC5_SDHD_OF(x)       _VALUEOF(x)
  #define  VCP_IC5_SDHD_SOFT        0x00000001u	/*Correction was 0*/
  #define  VCP_IC5_SDHD_HARD        0x00000000u	/*Correction was 1*/

  #define _VCP_IC5_OUTF_MASK        0x40000000u
  #define _VCP_IC5_OUTF_SHIFT       0x0000001Eu
  #define  VCP_IC5_OUTF_DEFAULT     0x00000000u
  #define  VCP_IC5_OUTF_OF(x)       _VALUEOF(x)
  #define  VCP_IC5_OUTF_NO          0x00000000u
  #define  VCP_IC5_OUTF_YES         0x00000001u

  #define _VCP_IC5_TB_MASK        0x03000000u
  #define _VCP_IC5_TB_SHIFT       0x00000018u
  #define  VCP_IC5_TB_DEFAULT     0x00000000u
  #define  VCP_IC5_TB_OF(x)       _VALUEOF(x)
  #define  VCP_IC5_TB_NO          0x00000000u
  #define  VCP_IC5_TB_TAIL        0x00000001u
  #define  VCP_IC5_TB_CONV        0x00000002u
  #define  VCP_IC5_TB_MIX         0x00000003u

  #define _VCP_IC5_SYMR_MASK        0x00F00000u
  #define _VCP_IC5_SYMR_SHIFT       0x00000014u
  #define  VCP_IC5_SYMR_DEFAULT     0x00000000u
  #define  VCP_IC5_SYMR_OF(x)       _VALUEOF(x)

  #define _VCP_IC5_SYMX_MASK        0x000F0000u
  #define _VCP_IC5_SYMX_SHIFT       0x00000010u
  #define  VCP_IC5_SYMX_DEFAULT     0x00000000u
  #define  VCP_IC5_SYMX_OF(x)       _VALUEOF(x)

  #define _VCP_IC5_IMAXI_MASK        0x000000FFu
  #define _VCP_IC5_IMAXI_SHIFT       0x00000000u
  #define  VCP_IC5_IMAXI_DEFAULT     0x00000000u
  #define  VCP_IC5_IMAXI_OF(x)       _VALUEOF(x)

  #define  VCP_IC5_OF(x)             _VALUEOF(x)

  #define VCP_IC5_DEFAULT (Uint32)(\
    _PER_FDEFAULT(VCP,IC5,SDHD)\
   |_PER_FDEFAULT(VCP,IC5,OUTF)\
   |_PER_FDEFAULT(VCP,IC5,TB)\
   |_PER_FDEFAULT(VCP,IC5,SYMR)\
   |_PER_FDEFAULT(VCP,IC5,SYMX)\
   |_PER_FDEFAULT(VCP,IC5,IMAXI)\
   |_PER_FDEFAULT(VCP,IC5,IMAXI)\
  )

  #define VCP_IC5_RMK(sdhd,outf,tb,symr,symx,imaxi) (Uint32)(\
     _PER_FMK(VCP,IC5,SDHD,sdhd)\
    |_PER_FMK(VCP,IC5,OUTF,outf)\
    |_PER_FMK(VCP,IC5,TB,tb)\
    |_PER_FMK(VCP,IC5,SYMR,symr)\
    |_PER_FMK(VCP,IC5,SYMX,symx)\
    |_PER_FMK(VCP,IC5,IMAXI,imaxi)\
  )

  #define _VCP_IC5_FGET(FIELD)\
    _PER_FGET(_VCP_IC5_ADDR,VCP,IC5,##FIELD)

  #define _VCP_IC5_FSET(FIELD,field)\
    _PER_FSET(_VCP_IC5_ADDR,VCP,IC5,##FIELD,field)

  #define _VCP_IC5_FSETS(FIELD,SYM)\
    _PER_FSETS(_VCP_IC5_ADDR,VCP,IC5,FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  E X E            |
* |___________________|
*
* VCP execution register
*
* FIELDS (msb -> lsb)
* (rw) COMMAND
*
\******************************************************************************/
  #define _VCP_EXE_OFFSET            6

  #define _VCP_EXE_ADDR              0x01B80018u

  #define _VCP_EXE_COMMAND_MASK      0x000000FFu
  #define _VCP_EXE_COMMAND_SHIFT     0x00000000u
  #define  VCP_EXE_COMMAND_DEFAULT   0x00000000u
  #define  VCP_EXE_COMMAND_OF(x)     _VALUEOF(x)
  #define  VCP_EXE_COMMAND_START     0x00000001u
  #define  VCP_EXE_COMMAND_PAUSE     0x00000002u
  #define  VCP_EXE_COMMAND_UNPAUSE   0x00000004u
  #define  VCP_EXE_COMMAND_STOP      0x00000005u

  #define  VCP_EXE_OF(x)             _VALUEOF(x)

  #define VCP_EXE_DEFAULT (Uint32)(\
    _PER_FDEFAULT(VCP,EXE,COMMAND)\
  )

  #define VCP_EXE_RMK(command) (Uint32)(\
     _PER_FMK(VCP,EXE,COMMAND,command)\
  )

  #define _VCP_EXE_FGET(FIELD)\
    _PER_FGET(_VCP_EXE_ADDR,VCP,EXE,##FIELD)

  #define _VCP_EXE_FSET(FIELD,field)\
    _PER_FSET(_VCP_EXE_ADDR,VCP,EXE,##FIELD,field)

  #define _VCP_EXE_FSETS(FIELD,SYM)\
    _PER_FSETS(_VCP_EXE_ADDR,VCP,EXE,##FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  E N D            |
* |___________________|
*
* VCP endian mode register
*
* FIELDS (msb -> lsb)
* (rw) SD
* (rw) BM
*
\******************************************************************************/
  #define _VCP_END_OFFSET            8

  #define _VCP_END_ADDR              0x01B80020u

  #define _VCP_END_SD_MASK          0x00000002u
  #define _VCP_END_SD_SHIFT         0x00000001u
  #define  VCP_END_SD_DEFAULT       0x00000000u
  #define  VCP_END_SD_OF(x)         _VALUEOF(x)
  #define  VCP_END_SD_32BIT         0x00000000u
  #define  VCP_END_SD_NATIVE        0x00000001u

  #define _VCP_END_BM_MASK          0x00000001u
  #define _VCP_END_BM_SHIFT         0x00000000u
  #define  VCP_END_BM_DEFAULT       0x00000000u
  #define  VCP_END_BM_OF(x)         _VALUEOF(x)
  #define  VCP_END_BM_32BIT         0x00000000u
  #define  VCP_END_BM_NATIVE        0x00000001u

 

  #define  VCP_END_OF(x)             _VALUEOF(x)

  #define VCP_END_DEFAULT (Uint32)(\
    _PER_FDEFAULT(VCP,END,SD)\
   |_PER_FDEFAULT(VCP,END,BM)\
  )

  #define VCP_END_RMK(sd,bm) (Uint32)(\
     _PER_FMK(VCP,END,SD,sd)\
    |_PER_FMK(VCP,END,BM,bm)\
  )

  #define _VCP_END_FGET(FIELD)\
    _PER_FGET(_VCP_END_ADDR,VCP,END,##FIELD)

  #define _VCP_END_FSET(FIELD,field)\
    _PER_FSET(_VCP_END_ADDR,VCP,END,##FIELD,field)

  #define _VCP_END_FSETS(FIELD,SYM)\
    _PER_FSETS(_VCP_END_ADDR,VCP,END,##FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  O U T 0          |
* |___________________|
*
* VCP output parameters register 0
*
* FIELDS (msb -> lsb)
* (r) FMINS
* (r) FMAXS
*
\******************************************************************************/
  #define _VCP_OUT0_OFFSET            9

  #define _VCP_OUT0_ADDR              0x01B80048u	/*Correction was 0x01B80024*/

  #define _VCP_OUT0_FMINS_MASK         0x0FFF0000u	/*Correction was 0x00FF0000u*/
  #define _VCP_OUT0_FMINS_SHIFT        0x00000010u
  #define  VCP_OUT0_FMINS_DEFAULT      0x00000000u
  #define  VCP_OUT0_FMINS_OF(x)        _VALUEOF(x)

  #define _VCP_OUT0_FMAXS_MASK          0x00000FFFu	/*Correction was 0x000000FFu*/
  #define _VCP_OUT0_FMAXS_SHIFT         0x00000000u
  #define  VCP_OUT0_FMAXS_DEFAULT       0x00000000u
  #define  VCP_OUT0_FMAXS_OF(x)         _VALUEOF(x)

  #define  VCP_OUT0_OF(x)             _VALUEOF(x)

  #define VCP_OUT0_DEFAULT (Uint32)(\
    _PER_FDEFAULT(VCP,OUT0,FMINS)\
   |_PER_FDEFAULT(VCP,OUT0,FMAXS)\
  )
  #if (!(CHIP_6413 | CHIP_6418 | CHIP_6410))
    #define VCP_OUT0_RMK(fmins,fmaxs)(Uint32)(\
       _PER_FMK(VCP,OUT0,FMINS,fmins)\
      |_PER_FMK(VCP,OUT0,FMAXS,fmaxs)\
    )
  #endif 

  #define _VCP_OUT0_FGET(FIELD)\
    _PER_FGET(_VCP_OUT0_ADDR,VCP,OUT0,##FIELD)

/******************************************************************************\
* _____________________
* |                   |
* |  O U T 1          |
* |___________________|
*
* VCP output parameters register 1
*
* FIELDS (msb -> lsb)
* (r) YAM
* (r) FMAXI
*
\******************************************************************************/
  #define _VCP_OUT1_OFFSET            10

  #define _VCP_OUT1_ADDR              0x01B8004Cu	/*Correction was 0x01B80028*/

  #define _VCP_OUT1_YAM_MASK          0x00010000u
  #define _VCP_OUT1_YAM_SHIFT         0x00000010u
  #define  VCP_OUT1_YAM_DEFAULT       0x00000000u
  #define  VCP_OUT1_YAM_OF(x)         _VALUEOF(x)
  #define  VCP_OUT1_YAM_NO            0x00000000u
  #define  VCP_OUT1_YAM_YES           0x00000001u

  #define _VCP_OUT1_FMAXI_MASK          0x00000FFFu	/*Correction was 0x00000FFFu*/
  #define _VCP_OUT1_FMAXI_SHIFT         0x00000000u
  #define  VCP_OUT1_FMAXI_DEFAULT       0x00000000u
  #define  VCP_OUT1_FMAXI_OF(x)         _VALUEOF(x)

  #define  VCP_OUT1_OF(x)             _VALUEOF(x)

  #define VCP_OUT1_DEFAULT (Uint32)(\
    _PER_FDEFAULT(VCP,OUT1,YAM)\
   |_PER_FDEFAULT(VCP,OUT1,FMAXI)\
  )
#if (!(CHIP_6413 | CHIP_6418 | CHIP_6410))
  #define VCP_OUT1_RMK(yam,fmaxi) (Uint32)(\
     _PER_FMK(VCP,OUT1,YAM,yam)\
    |_PER_FMK(VCP,OUT1,FMAXI,fmaxi)\
  )    
#endif  
  #define _VCP_OUT1_FGET(FIELD)\
    _PER_FGET(_VCP_OUT1_ADDR,VCP,OUT1,##FIELD)

/******************************************************************************\
* _____________________
* |                   |
* |  S T A T 0        |
* |___________________|
*
* VCP status register 0
*
* FIELDS (msb -> lsb)
* (r) NSYM
* (r) OFFUL
* (r) IFEMP
* (r) WIC
* (r) ERR
* (r) RUN
* (r) PAUS
*
\******************************************************************************/
  #define _VCP_STAT0_OFFSET         16

  #define _VCP_STAT0_ADDR           0x01B80040u

  #define _VCP_STAT0_NSYM_MASK      0xFFFF0000u
  #define _VCP_STAT0_NSYM_SHIFT     0x00000010u
  #define  VCP_STAT0_NSYM_DEFAULT   0x00000000u
  #define  VCP_STAT0_NSYM_OF(x)     _VALUEOF(x)

  #define _VCP_STAT0_OFFUL_MASK       0x00000020u
  #define _VCP_STAT0_OFFUL_SHIFT      0x00000005u
  #define  VCP_STAT0_OFFUL_DEFAULT    0x00000000u
  #define  VCP_STAT0_OFFUL_OF(x)      _VALUEOF(x)
  #define  VCP_STAT0_OFFUL_NO         0x00000000u
  #define  VCP_STAT0_OFFUL_YES        0x00000001u

  #define _VCP_STAT0_IFEMP_MASK       0x00000010u
  #define _VCP_STAT0_IFEMP_SHIFT      0x00000004u
  #define  VCP_STAT0_IFEMP_DEFAULT    0x00000000u
  #define  VCP_STAT0_IFEMP_OF(x)      _VALUEOF(x)
  #define  VCP_STAT0_IFEMP_NO         0x00000000u
  #define  VCP_STAT0_IFEMP_YES        0x00000001u

  #define _VCP_STAT0_WIC_MASK       0x00000008u
  #define _VCP_STAT0_WIC_SHIFT      0x00000003u
  #define  VCP_STAT0_WIC_DEFAULT    0x00000000u
  #define  VCP_STAT0_WIC_OF(x)      _VALUEOF(x)
  #define  VCP_STAT0_WIC_NO         0x00000000u
  #define  VCP_STAT0_WIC_YES        0x00000001u

  #define _VCP_STAT0_ERR_MASK       0x00000004u
  #define _VCP_STAT0_ERR_SHIFT      0x00000002u
  #define  VCP_STAT0_ERR_DEFAULT    0x00000000u
  #define  VCP_STAT0_ERR_OF(x)      _VALUEOF(x)
  #define  VCP_STAT0_ERR_NO         0x00000000u
  #define  VCP_STAT0_ERR_YES        0x00000001u

  #define _VCP_STAT0_RUN_MASK       0x00000002u
  #define _VCP_STAT0_RUN_SHIFT      0x00000001u
  #define  VCP_STAT0_RUN_DEFAULT    0x00000000u
  #define  VCP_STAT0_RUN_OF(x)      _VALUEOF(x)
  #define  VCP_STAT0_RUN_NO         0x00000000u
  #define  VCP_STAT0_RUN_YES        0x00000001u

  #define _VCP_STAT0_PAUS_MASK     0x00000001u
  #define _VCP_STAT0_PAUS_SHIFT    0x00000000u
  #define  VCP_STAT0_PAUS_DEFAULT  0x00000000u
  #define  VCP_STAT0_PAUS_OF(x)    _VALUEOF(x)
  #define  VCP_STAT0_PAUS_NO       0x00000000u
  #define  VCP_STAT0_PAUS_YES      0x00000001u

  #define  VCP_STAT0_OF(x)          _VALUEOF(x)

  #define VCP_STAT0_DEFAULT (Uint32)(\
    _PER_FDEFAULT(VCP,STAT0,NSYM)\
   |_PER_FDEFAULT(VCP,STAT0,OFFUL)\
   |_PER_FDEFAULT(VCP,STAT0,IFEMP)\
   |_PER_FDEFAULT(VCP,STAT0,WIC)\
   |_PER_FDEFAULT(VCP,STAT0,ERR)\
   |_PER_FDEFAULT(VCP,STAT0,RUN)\
   |_PER_FDEFAULT(VCP,STAT0,PAUS)\
  )
#if (!(CHIP_6413 | CHIP_6418 | CHIP_6410))
  #define VCP_STAT0_RMK(nsym,offul,ifemp,wic,err,run,paus) (Uint32)(\
     _PER_FMK(VCP,STAT0,NSYM,nsym)\
    |_PER_FMK(VCP,STAT0,OFFUL,offul)\
    |_PER_FMK(VCP,STAT0,IFEMP,ifemp)\
    |_PER_FMK(VCP,STAT0,WIC,wic)\
    |_PER_FMK(VCP,STAT0,ERR,err)\
    |_PER_FMK(VCP,STAT0,RUN,run)\
    |_PER_FMK(VCP,STAT0,PAUS,paus)\
   )  
#endif  
  #define _VCP_STAT0_FGET(FIELD)\
    _PER_FGET(_VCP_STAT0_ADDR,VCP,STAT0,##FIELD)

/******************************************************************************\
* _____________________
* |                   |
* |  S T A T 1        |
* |___________________|
*
* VCP status register 1
*
* FIELDS (msb -> lsb)
* (r) NSYMOF
* (r) NSYMIF
*
\******************************************************************************/
  #define _VCP_STAT1_OFFSET         17

  #define _VCP_STAT1_ADDR           0x01B80044u

  #define _VCP_STAT1_NSYMOF_MASK      0xFFFF0000u
  #define _VCP_STAT1_NSYMOF_SHIFT     0x00000010u
  #define  VCP_STAT1_NSYMOF_DEFAULT   0x00000000u
  #define  VCP_STAT1_NSYMOF_OF(x)     _VALUEOF(x)

  #define _VCP_STAT1_NSYMIF_MASK      0x0000FFFFu
  #define _VCP_STAT1_NSYMIF_SHIFT     0x00000000u
  #define  VCP_STAT1_NSYMIF_DEFAULT   0x00000000u
  #define  VCP_STAT1_NSYMIF_OF(x)     _VALUEOF(x)

  #define  VCP_STAT1_OF(x)          _VALUEOF(x)

  #define VCP_STAT1_DEFAULT (Uint32)(\
    _PER_FDEFAULT(VCP,STAT1,NSYMOF)\
   |_PER_FDEFAULT(VCP,STAT1,NSYMIF)\
  )
#if (!(CHIP_6413 | CHIP_6418 | CHIP_6410))
  #define VCP_STAT1_RMK(nsymof,nsymif) (Uint32)(\
     _PER_FMK(VCP,STAT1,NSYMOF,nsymof)\
    |_PER_FMK(VCP,STAT1,NSYMIF,nsymif)\
  )
#endif  
  #define _VCP_STAT1_FGET(FIELD)\
    _PER_FGET(_VCP_STAT1_ADDR,VCP,STAT1,##FIELD)

/******************************************************************************\
* _____________________
* |                   |
* |  E R R            |
* |___________________|
*
* VCP error register
*
* FIELDS (msb -> lsb)
* (r) ERROR
*
\******************************************************************************/
  #define _VCP_ERR_OFFSET          20

  #define _VCP_ERR_ADDR            0x01B80050u

  #define _VCP_ERR_ERROR_MASK      0x00000007u	/*Correction was 0x00000400u*/
  #define _VCP_ERR_ERROR_SHIFT     0x00000000u	/*Correction was 0x0000000Au*/
  #define  VCP_ERR_ERROR_DEFAULT   0x00000000u
  #define  VCP_ERR_ERROR_OF(x)     _VALUEOF(x)
  #define  VCP_ERR_ERROR_NO        0x00000000u
  #define  VCP_ERR_ERROR_TBNA      0x00000001u
  #define  VCP_ERR_ERROR_FTL       0x00000002u
  #define  VCP_ERR_ERROR_FCTL      0x00000003u

  #define  VCP_ERR_OF(x)           _VALUEOF(x)

  #define VCP_ERR_DEFAULT (Uint32)(\
    _PER_FDEFAULT(VCP,ERR,ERROR)\
  )
#if (!(CHIP_6413 | CHIP_6418 | CHIP_6410))
  #define VCP_ERR_RMK(error) (Uint32)(\
     _PER_FMK(VCP,ERR,ERROR,error)\
  )     
#endif  
  #define _VCP_ERR_FGET(FIELD)\
    _PER_FGET(_VCP_ERR_ADDR,VCP,ERR,##FIELD)

/*----------------------------------------------------------------------------*/
#endif /* VCP_SUPPORT) */
#endif /* _CSL_VCPHAL_H_ */
/******************************************************************************\
* End of csl_vcphal.h
\******************************************************************************/

