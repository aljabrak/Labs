/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_tcphal.h
* DATE CREATED.. 02/21/2001 
* LAST MODIFIED. 08/02/2004 - Adding support for C6418
*                04/20/2001
*------------------------------------------------------------------------------
* REGISTERS
*
* IC0   - TCP input configuration register  0
* IC1   - TCP input configuration register  1
* IC2   - TCP input configuration register  2
* IC3   - TCP input configuration register  3
* IC4   - TCP input configuration register  4
* IC5   - TCP input configuration register  5
* IC6   - TCP input configuration register  6
* IC7   - TCP input configuration register  7
* IC8   - TCP input configuration register  8
* IC9   - TCP input configuration register  9
* IC10  - TCP input configuration register 10
* IC11  - TCP input configuration register 11
* OUT   - TCP output parameters register
* EXE   - TCP execution register 
* END   - TCP endian mode register
* ERR   - TCP error register
* STAT  - TCP status register
*
*------------------------------------------------------------------------------
* MEMORY REGIONS
*
* ICMEM - TCP interrupt configuration register space
* OPMEM - TCP output parameter register space
* SPMEM - TCP systematics and parities memory
* EXMEM - TCP extrinsics memory
* APMEM - TCP apriori memory
* ILMEM - TCP interleaver memory
* HDMEM - TCP hard decisions memory
*
\******************************************************************************/
#ifndef _CSL_TCPHAL_H_
#define _CSL_TCPHAL_H_

#include <csl_stdinc.h>
#include <csl_chip.h>

#if (TCP_SUPPORT)

/******************************************************************************\
* Memory section
\******************************************************************************/

  #define _TCP_BASE_IC               0x01BA0000u
  #define  TCP_ICMEM_ADDR            0x58000000u
  #define  TCP_OPMEM_ADDR            0x58000030u
  #define  TCP_SPMEM_ADDR            0x58020000u
  #define  TCP_EXMEM_ADDR            0x58040000u
  #define  TCP_APMEM_ADDR            0x58060000u
  #define  TCP_ILMEM_ADDR            0x58080000u
  #define  TCP_HDMEM_ADDR            0x580A0000u


/******************************************************************************\
* module level register/field access macros
\******************************************************************************/

  /* ----------------- */
  /* FIELD MAKE MACROS */
  /* ----------------- */

  #define TCP_FMK(REG,FIELD,x)\
    _PER_FMK(TCP,##REG,##FIELD,x)

  #define TCP_FMKS(REG,FIELD,SYM)\
    _PER_FMKS(TCP,##REG,##FIELD,##SYM)


  /* -------------------------------- */
  /* RAW REGISTER/FIELD ACCESS MACROS */
  /* -------------------------------- */

  #define TCP_ADDR(REG)\
    _TCP_##REG##_ADDR

  #define TCP_RGET(REG)\
    _PER_RGET(_TCP_##REG##_ADDR,TCP,##REG)

  #define TCP_RSET(REG,x)\
    _PER_RSET(_TCP_##REG##_ADDR,TCP,##REG,x)

  #define TCP_FGET(REG,FIELD)\
    _TCP_##REG##_FGET(##FIELD)

  #define TCP_FSET(REG,FIELD,x)\
    _TCP_##REG##_FSET(##FIELD,##x)

  #define TCP_FSETS(REG,FIELD,SYM)\
    _TCP_##REG##_FSETS(##FIELD,##SYM)


  /* ------------------------------------------ */
  /* ADDRESS BASED REGISTER/FIELD ACCESS MACROS */
  /* ------------------------------------------ */

  #define TCP_RGETA(addr,REG)\
    _PER_RGET(addr,TCP,##REG)

  #define TCP_RSETA(addr,REG,x)\
    _PER_RSET(addr,TCP,##REG,x)

  #define TCP_FGETA(addr,REG,FIELD)\
    _PER_FGET(addr,TCP,##REG,##FIELD)

  #define TCP_FSETA(addr,REG,FIELD,x)\
    _PER_FSET(addr,TCP,##REG,##FIELD,x)

  #define TCP_FSETSA(addr,REG,FIELD,SYM)\
    _PER_FSETS(addr,TCP,##REG,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  I C 0            |
* |___________________|
*
* TCP input configuration register  0
*
* FIELDS (msb -> lsb)
* (rw) FL
* (rw) OUTF
* (rw) INTER
* (rw) RATE
* (rw) OPMOD
* 
*
\******************************************************************************/
  #define _TCP_IC0_OFFSET            0

    #define _TCP_IC0_ADDR              0x01BA0000u
 // #define _TCP_IC0_ADDR              0x58000000u

  #define _TCP_IC0_FL_MASK           0xFFFF0000u
  #define _TCP_IC0_FL_SHIFT          0x00000010u
  #define  TCP_IC0_FL_DEFAULT        0x00000000u
  #define  TCP_IC0_FL_OF(x)          _VALUEOF(x)

  #define _TCP_IC0_OUTF_MASK         0x00002000u // error doc
  #define _TCP_IC0_OUTF_SHIFT        0x0000000Du
  #define  TCP_IC0_OUTF_DEFAULT      0x00000000u
  #define  TCP_IC0_OUTF_OF(x)        _VALUEOF(x)
  #define  TCP_IC0_OUTF_NO           0x00000000u
  #define  TCP_IC0_OUTF_YES          0x00000001u

  #define _TCP_IC0_INTER_MASK          0x00001000u
  #define _TCP_IC0_INTER_SHIFT         0x0000000Cu
  #define  TCP_IC0_INTER_DEFAULT       0x00000000u
  #define  TCP_IC0_INTER_OF(x)         _VALUEOF(x)
  #define  TCP_IC0_INTER_NO            0x00000000u
  #define  TCP_IC0_INTER_YES           0x00000001u

  #define _TCP_IC0_RATE_MASK         0x00000300u
  #define _TCP_IC0_RATE_SHIFT        0x00000008u
  #define  TCP_IC0_RATE_DEFAULT      0x00000000u
  #define  TCP_IC0_RATE_OF(x)        _VALUEOF(x)
  #define  TCP_IC0_RATE_1_2          0x00000001u
  #define  TCP_IC0_RATE_1_3          0x00000002u
  #define  TCP_IC0_RATE_1_4          0x00000003u

  #define _TCP_IC0_OPMOD_MASK        0x0000000Eu
  #define _TCP_IC0_OPMOD_SHIFT       0x00000001u
  #define  TCP_IC0_OPMOD_DEFAULT     0x00000000u
  #define  TCP_IC0_OPMOD_OF(x)       _VALUEOF(x)
  #define  TCP_IC0_OPMOD_SA          0x00000000u
  #define  TCP_IC0_OPMOD_MAP1A       0x00000004u
  #define  TCP_IC0_OPMOD_MAP1B       0x00000005u
  #define  TCP_IC0_OPMOD_MAP2        0x00000007u

 
  #define  TCP_IC0_OF(x)             _VALUEOF(x)

  #define TCP_IC0_DEFAULT (Uint32)(\
    _PER_FDEFAULT(TCP,IC0,FL)\
   |_PER_FDEFAULT(TCP,IC0,OUTF)\
   |_PER_FDEFAULT(TCP,IC0,INTER)\
   |_PER_FDEFAULT(TCP,IC0,RATE)\
   |_PER_FDEFAULT(TCP,IC0,OPMOD)\
  )

  #define TCP_IC0_RMK(fl,outf,inter,rate,opmod) (Uint32)(\
     _PER_FMK(TCP,IC0,FL,fl)\
    |_PER_FMK(TCP,IC0,OUTF,outf)\
    |_PER_FMK(TCP,IC0,INTER,inter)\
    |_PER_FMK(TCP,IC0,RATE,rate)\
    |_PER_FMK(TCP,IC0,OPMOD,opmod)\
  )

  #define _TCP_IC0_FGET(FIELD)\
    _PER_FGET(_TCP_IC0_ADDR,TCP,IC0,##FIELD)

  #define _TCP_IC0_FSET(FIELD,field)\
    _PER_FSET(_TCP_IC0_ADDR,TCP,IC0,##FIELD,field)

  #define _TCP_IC0_FSETS(FIELD,SYM)\
    _PER_FSETS(_TCP_IC0_ADDR,TCP,IC0,FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  I C 1            |
* |___________________|
*
* TCP input configuration register  1
*
* FIELDS (msb -> lsb)
* (rw) LASTR
* (rw) R
* (rw) SFL
*
\******************************************************************************/
  #define _TCP_IC1_OFFSET            1

    #define _TCP_IC1_ADDR              0x01BA0004u   
//  #define _TCP_IC1_ADDR              0x580000004u
 
 #define _TCP_IC1_LASTR_MASK        0x7F000000u
  #define _TCP_IC1_LASTR_SHIFT       0x00000018u
  #define  TCP_IC1_LASTR_DEFAULT     0x00000000u
  #define  TCP_IC1_LASTR_OF(x)       _VALUEOF(x)

  #define _TCP_IC1_R_MASK           0x007F0000u
  #define _TCP_IC1_R_SHIFT          0x00000010u
  #define  TCP_IC1_R_DEFAULT        0x00000000u
  #define  TCP_IC1_R_OF(x)          _VALUEOF(x)

  #define _TCP_IC1_SFL_MASK          0x0000FFFFu
  #define _TCP_IC1_SFL_SHIFT         0x00000000u
  #define  TCP_IC1_SFL_DEFAULT       0x00000000u
  #define  TCP_IC1_SFL_OF(x)         _VALUEOF(x)

  #define  TCP_IC1_OF(x)             _VALUEOF(x)

  #define TCP_IC1_DEFAULT (Uint32)(\
    _PER_FDEFAULT(TCP,IC1,LASTR)\
   |_PER_FDEFAULT(TCP,IC1,R)\
   |_PER_FDEFAULT(TCP,IC1,SFL)\
  )

  #define TCP_IC1_RMK(lastr,r,sfl) (Uint32)(\
     _PER_FMK(TCP,IC1,LASTR,lastr)\
    |_PER_FMK(TCP,IC1,R,r)\
    |_PER_FMK(TCP,IC1,SFL,sfl)\
  )

  #define _TCP_IC1_FGET(FIELD)\
    _PER_FGET(_TCP_IC1_ADDR,TCP,IC1,##FIELD)

  #define _TCP_IC1_FSET(FIELD,field)\
    _PER_FSET(_TCP_IC1_ADDR,TCP,IC1,##FIELD,field)

  #define _TCP_IC1_FSETS(FIELD,SYM)\
    _PER_FSETS(_TCP_IC1_ADDR,TCP,IC1,FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  I C 2            |
* |___________________|
*
* TCP input configuration register  2
*
* FIELDS (msb -> lsb)
* (rw) SNR
* (rw) MAXIT
* (rw) LASTNSB
* (rw) NSB
* (rw) PS
*
\******************************************************************************/
  #define _TCP_IC2_OFFSET            2

  #define _TCP_IC2_ADDR              0x01BA0008u
  // #define _TCP_IC2_ADDR              0x58000008u

  #define _TCP_IC2_SNR_MASK          0xFF000000u
  #define _TCP_IC2_SNR_SHIFT         0x00000018u
  #define  TCP_IC2_SNR_DEFAULT       0x00000000u
  #define  TCP_IC2_SNR_OF(x)         _VALUEOF(x)
  #define  TCP_IC2_SNR_NONE          0x00000000u

  #define _TCP_IC2_MAXIT_MASK        0x001F0000u
  #define _TCP_IC2_MAXIT_SHIFT       0x00000010u
  #define  TCP_IC2_MAXIT_DEFAULT     0x00000000u
  #define  TCP_IC2_MAXIT_OF(x)       _VALUEOF(x)

  #define _TCP_IC2_LASTNSB_MASK      0x0000F000u
  #define _TCP_IC2_LASTNSB_SHIFT     0x0000000Cu
  #define  TCP_IC2_LASTNSB_DEFAULT   0x00000000u
  #define  TCP_IC2_LASTNSB_OF(x)     _VALUEOF(x)

  #define _TCP_IC2_NSB_MASK          0x00000F00u
  #define _TCP_IC2_NSB_SHIFT         0x00000008u
  #define  TCP_IC2_NSB_DEFAULT       0x00000000u
  #define  TCP_IC2_NSB_OF(x)         _VALUEOF(x)

  #define _TCP_IC2_P_MASK           0x0000003Fu
  #define _TCP_IC2_P_SHIFT          0x00000000u
  #define  TCP_IC2_P_DEFAULT        0x00000000u
  #define  TCP_IC2_P_OF(x)          _VALUEOF(x)

  #define  TCP_IC2_OF(x)             _VALUEOF(x)

  #define TCP_IC2_DEFAULT (Uint32)(\
    _PER_FDEFAULT(TCP,IC2,SNR)\
   |_PER_FDEFAULT(TCP,IC2,MAXIT)\
   |_PER_FDEFAULT(TCP,IC2,LASTNSB)\
   |_PER_FDEFAULT(TCP,IC2,NSB)\
   |_PER_FDEFAULT(TCP,IC2,P)\
  )

  #define TCP_IC2_RMK(snr,maxit,lastnsb,nsb,p) (Uint32)(\
     _PER_FMK(TCP,IC2,SNR,snr)\
    |_PER_FMK(TCP,IC2,MAXIT,maxit)\
    |_PER_FMK(TCP,IC2,LASTNSB,lastnsb)\
    |_PER_FMK(TCP,IC2,NSB,nsb)\
    |_PER_FMK(TCP,IC2,P,p)\
  )

  #define _TCP_IC2_FGET(FIELD)\
    _PER_FGET(_TCP_IC2_ADDR,TCP,IC2,##FIELD)

  #define _TCP_IC2_FSET(FIELD,field)\
    _PER_FSET(_TCP_IC2_ADDR,TCP,IC2,##FIELD,field)

  #define _TCP_IC2_FSETS(FIELD,SYM)\
    _PER_FSETS(_TCP_IC2_ADDR,TCP,IC2,FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  I C 3            |
* |___________________|
*
* TCP input configuration register  3
*
* FIELDS (msb -> lsb)
* (rw) NWDSYPAR
* (rw) NWDINTER
*
\******************************************************************************/
  #define _TCP_IC3_OFFSET            3

  #define _TCP_IC3_ADDR              0x01BA000Cu
 
 // #define _TCP_IC3_ADDR                0x5800000Cu

  #define _TCP_IC3_NWDSYPAR_MASK      0xFFFF0000u
  #define _TCP_IC3_NWDSYPAR_SHIFT     0x00000010u
  #define  TCP_IC3_NWDSYPAR_DEFAULT   0x00000000u
  #define  TCP_IC3_NWDSYPAR_OF(x)     _VALUEOF(x)

  #define _TCP_IC3_NWDINTER_MASK       0x0000FFFFu
  #define _TCP_IC3_NWDINTER_SHIFT      0x00000000u
  #define  TCP_IC3_NWDINTER_DEFAULT    0x00000000u
  #define  TCP_IC3_NWDINTER_OF(x)      _VALUEOF(x)

  #define  TCP_IC3_OF(x)             _VALUEOF(x)

  #define TCP_IC3_DEFAULT (Uint32)(\
    _PER_FDEFAULT(TCP,IC3,NWDSYPAR)\
   |_PER_FDEFAULT(TCP,IC3,NWDINTER)\
  )

  #define TCP_IC3_RMK(nwdsypar,nwdinter) (Uint32)(\
     _PER_FMK(TCP,IC3,NWDSYPAR,nwdsypar)\
    |_PER_FMK(TCP,IC3,NWDINTER,nwdinter)\
  )

  #define _TCP_IC3_FGET(FIELD)\
    _PER_FGET(_TCP_IC3_ADDR,TCP,IC3,##FIELD)

  #define _TCP_IC3_FSET(FIELD,field)\
    _PER_FSET(_TCP_IC3_ADDR,TCP,IC3,##FIELD,field)

  #define _TCP_IC3_FSETS(FIELD,SYM)\
    _PER_FSETS(_TCP_IC3_ADDR,TCP,IC3,FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  I C 4            |
* |___________________|
*
* TCP input configuration register  4
*
* FIELDS (msb -> lsb)
* (rw) NWDEXT
* (rw) NWDAP
*
\******************************************************************************/
  #define _TCP_IC4_OFFSET            4

  #define _TCP_IC4_ADDR              0x01BA0010u
 //#define _TCP_IC4_ADDR              0x58000010u

  #define _TCP_IC4_NWDEXT_MASK         0xFFFF0000u
  #define _TCP_IC4_NWDEXT_SHIFT        0x00000010u
  #define  TCP_IC4_NWDEXT_DEFAULT      0x00000000u
  #define  TCP_IC4_NWDEXT_OF(x)        _VALUEOF(x)

  #define _TCP_IC4_NWDAP_MASK          0x0000FFFFu
  #define _TCP_IC4_NWDAP_SHIFT         0x00000000u
  #define  TCP_IC4_NWDAP_DEFAULT       0x00000000u
  #define  TCP_IC4_NWDAP_OF(x)         _VALUEOF(x)

  #define  TCP_IC4_OF(x)             _VALUEOF(x)

  #define TCP_IC4_DEFAULT (Uint32)(\
    _PER_FDEFAULT(TCP,IC4,NWDEXT)\
   |_PER_FDEFAULT(TCP,IC4,NWDAP)\
  )

  #define TCP_IC4_RMK(nwdext,nwdap) (Uint32)(\
     _PER_FMK(TCP,IC4,NWDEXT,nwdext)\
    |_PER_FMK(TCP,IC4,NWDAP,nwdap)\
  )

  #define _TCP_IC4_FGET(FIELD)\
    _PER_FGET(_TCP_IC4_ADDR,TCP,IC4,##FIELD)

  #define _TCP_IC4_FSET(FIELD,field)\
    _PER_FSET(_TCP_IC4_ADDR,TCP,IC4,##FIELD,field)

  #define _TCP_IC4_FSETS(FIELD,SYM)\
    _PER_FSETS(_TCP_IC4_ADDR,TCP,IC4,FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  I C 5            |
* |___________________|
*
* TCP input configuration register  5
*
* FIELDS (msb -> lsb)
* (rw) NWDHD
*
\******************************************************************************/
  #define _TCP_IC5_OFFSET            5

  #define _TCP_IC5_ADDR              0x01BA0014u
  //#define _TCP_IC5_ADDR              0x58000014u

  #define _TCP_IC5_NWDHD_MASK          0x0000FFFFu
  #define _TCP_IC5_NWDHD_SHIFT         0x00000000u
  #define  TCP_IC5_NWDHD_DEFAULT       0x00000000u
  #define  TCP_IC5_NWDHD_OF(x)         _VALUEOF(x)

  #define  TCP_IC5_OF(x)             _VALUEOF(x)

  #define TCP_IC5_DEFAULT (Uint32)(\
     _PER_FDEFAULT(TCP,IC5,NWDHD)\
  )

  #define TCP_IC5_RMK(nwdhd) (Uint32)(\
     _PER_FMK(TCP,IC5,NWDHD,nwdhd)\
  )

  #define _TCP_IC5_FGET(FIELD)\
    _PER_FGET(_TCP_IC5_ADDR,TCP,IC5,##FIELD)

  #define _TCP_IC5_FSET(FIELD,field)\
    _PER_FSET(_TCP_IC5_ADDR,TCP,IC5,##FIELD,field)

  #define _TCP_IC5_FSETS(FIELD,SYM)\
    _PER_FSETS(_TCP_IC5_ADDR,TCP,IC5,FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  I C 6            |
* |___________________|
*
* TCP input configuration register  6
*
* FIELDS (msb -> lsb)
* (rw) TAIL1
*
\******************************************************************************/
  #define _TCP_IC6_OFFSET            6

    #define _TCP_IC6_ADDR              0x01BA0018u
 // #define _TCP_IC6_ADDR              0x58000018u
  
  #define _TCP_IC6_TAIL1_MASK        0xFFFFFFFFu
  #define _TCP_IC6_TAIL1_SHIFT       0x00000000u
  #define  TCP_IC6_TAIL1_DEFAULT     0x00000000u
  #define  TCP_IC6_TAIL1_OF(x)       _VALUEOF(x)

  #define  TCP_IC6_OF(x)             _VALUEOF(x)

  #define TCP_IC6_DEFAULT (Uint32)(\
     _PER_FDEFAULT(TCP,IC6,TAIL1)\
  )

  #define TCP_IC6_RMK(tail1) (Uint32)(\
     _PER_FMK(TCP,IC6,TAIL1,tail1)\
  )

  #define _TCP_IC6_FGET(FIELD)\
    _PER_FGET(_TCP_IC6_ADDR,TCP,IC6,##FIELD)

  #define _TCP_IC6_FSET(FIELD,field)\
    _PER_FSET(_TCP_IC6_ADDR,TCP,IC6,##FIELD,field)

  #define _TCP_IC6_FSETS(FIELD,SYM)\
    _PER_FSETS(_TCP_IC6_ADDR,TCP,IC6,FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  I C 7            |
* |___________________|
*
* TCP input configuration register  7
*
* FIELDS (msb -> lsb)
* (rw) TAIL2
*
\******************************************************************************/
  #define _TCP_IC7_OFFSET            7

   #define _TCP_IC7_ADDR              0x01BA001Cu
  // #define _TCP_IC7_ADDR              0x5800001Cu

  #define _TCP_IC7_TAIL2_MASK        0xFFFFFFFFu
  #define _TCP_IC7_TAIL2_SHIFT       0x00000000u
  #define  TCP_IC7_TAIL2_DEFAULT     0x00000000u
  #define  TCP_IC7_TAIL2_OF(x)       _VALUEOF(x)

  #define  TCP_IC7_OF(x)             _VALUEOF(x)

  #define TCP_IC7_DEFAULT (Uint32)(\
     _PER_FDEFAULT(TCP,IC7,TAIL2)\
  )

  #define TCP_IC7_RMK(tail2) (Uint32)(\
     _PER_FMK(TCP,IC7,TAIL2,tail2)\
  )

  #define _TCP_IC7_FGET(FIELD)\
    _PER_FGET(_TCP_IC7_ADDR,TCP,IC7,##FIELD)

  #define _TCP_IC7_FSET(FIELD,field)\
    _PER_FSET(_TCP_IC7_ADDR,TCP,IC7,##FIELD,field)

  #define _TCP_IC7_FSETS(FIELD,SYM)\
    _PER_FSETS(_TCP_IC7_ADDR,TCP,IC7,FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  I C 8            |
* |___________________|
*
* TCP input configuration register  8
*
* FIELDS (msb -> lsb)
* (rw) TAIL3
*
\******************************************************************************/
  #define _TCP_IC8_OFFSET            8

     #define _TCP_IC8_ADDR              0x01BA0020u
  // #define _TCP_IC8_ADDR              0x58000020u

  #define _TCP_IC8_TAIL3_MASK        0xFFFFFFFFu
  #define _TCP_IC8_TAIL3_SHIFT       0x00000000u
  #define  TCP_IC8_TAIL3_DEFAULT     0x00000000u
  #define  TCP_IC8_TAIL3_OF(x)       _VALUEOF(x)

  #define  TCP_IC8_OF(x)             _VALUEOF(x)

  #define TCP_IC8_DEFAULT (Uint32)(\
     _PER_FDEFAULT(TCP,IC8,TAIL3)\
  )

  #define TCP_IC8_RMK(tail3) (Uint32)(\
     _PER_FMK(TCP,IC8,TAIL3,tail3)\
  )

  #define _TCP_IC8_FGET(FIELD)\
    _PER_FGET(_TCP_IC8_ADDR,TCP,IC8,##FIELD)

  #define _TCP_IC8_FSET(FIELD,field)\
    _PER_FSET(_TCP_IC8_ADDR,TCP,IC8,##FIELD,field)

  #define _TCP_IC8_FSETS(FIELD,SYM)\
    _PER_FSETS(_TCP_IC8_ADDR,TCP,IC8,FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  I C 9            |
* |___________________|
*
* TCP input configuration register  9
*
* FIELDS (msb -> lsb)
* (rw) TAIL4
*
\******************************************************************************/
  #define _TCP_IC9_OFFSET            9

    #define _TCP_IC9_ADDR              0x01BA0024u
  //#define _TCP_IC9_ADDR              0x58000024u

  #define _TCP_IC9_TAIL4_MASK        0xFFFFFFFFu
  #define _TCP_IC9_TAIL4_SHIFT       0x00000000u
  #define  TCP_IC9_TAIL4_DEFAULT     0x00000000u
  #define  TCP_IC9_TAIL4_OF(x)       _VALUEOF(x)

  #define  TCP_IC9_OF(x)             _VALUEOF(x)

  #define TCP_IC9_DEFAULT (Uint32)(\
     _PER_FDEFAULT(TCP,IC9,TAIL4)\
  )

  #define TCP_IC9_RMK(tail4) (Uint32)(\
     _PER_FMK(TCP,IC9,TAIL4,tail4)\
  )

  #define _TCP_IC9_FGET(FIELD)\
    _PER_FGET(_TCP_IC9_ADDR,TCP,IC9,##FIELD)

  #define _TCP_IC9_FSET(FIELD,field)\
    _PER_FSET(_TCP_IC9_ADDR,TCP,IC9,##FIELD,field)

  #define _TCP_IC9_FSETS(FIELD,SYM)\
    _PER_FSETS(_TCP_IC9_ADDR,TCP,IC9,FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  I C 1 0          |
* |___________________|
*
* TCP input configuration register 10
*
* FIELDS (msb -> lsb)
* (rw) TAIL5
*
\******************************************************************************/
  #define _TCP_IC10_OFFSET           10

  #define _TCP_IC10_ADDR             0x01BA0028u
 // #define _TCP_IC10_ADDR              0x58000028u

  #define _TCP_IC10_TAIL5_MASK       0xFFFFFFFFu
  #define _TCP_IC10_TAIL5_SHIFT      0x00000000u
  #define  TCP_IC10_TAIL5_DEFAULT    0x00000000u
  #define  TCP_IC10_TAIL5_OF(x)      _VALUEOF(x)

  #define  TCP_IC10_OF(x)            _VALUEOF(x)

  #define TCP_IC10_DEFAULT (Uint32)(\
     _PER_FDEFAULT(TCP,IC10,TAIL5)\
  )

  #define TCP_IC10_RMK(tail5) (Uint32)(\
     _PER_FMK(TCP,IC10,TAIL5,tail5)\
  )

  #define _TCP_IC10_FGET(FIELD)\
    _PER_FGET(_TCP_IC10_ADDR,TCP,IC10,##FIELD)

  #define _TCP_IC10_FSET(FIELD,field)\
    _PER_FSET(_TCP_IC10_ADDR,TCP,IC10,##FIELD,field)

  #define _TCP_IC10_FSETS(FIELD,SYM)\
    _PER_FSETS(_TCP_IC10_ADDR,TCP,IC10,FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  I C 1 1          |
* |___________________|
*
* TCP input configuration register 11
*
* FIELDS (msb -> lsb)
* (rw) TAIL6
*
\******************************************************************************/
  #define _TCP_IC11_OFFSET           11

  #define _TCP_IC11_ADDR             0x01BA002Cu
 // #define _TCP_IC11_ADDR              0x5800002Cu

  #define _TCP_IC11_TAIL6_MASK       0xFFFFFFFFu
  #define _TCP_IC11_TAIL6_SHIFT      0x00000000u
  #define  TCP_IC11_TAIL6_DEFAULT    0x00000000u
  #define  TCP_IC11_TAIL6_OF(x)      _VALUEOF(x)

  #define  TCP_IC11_OF(x)            _VALUEOF(x)

  #define TCP_IC11_DEFAULT (Uint32)(\
     _PER_FDEFAULT(TCP,IC11,TAIL6)\
  )

  #define TCP_IC11_RMK(tail6) (Uint32)(\
     _PER_FMK(TCP,IC11,TAIL6,tail6)\
  )

  #define _TCP_IC11_FGET(FIELD)\
    _PER_FGET(_TCP_IC11_ADDR,TCP,IC11,##FIELD)

  #define _TCP_IC11_FSET(FIELD,field)\
    _PER_FSET(_TCP_IC11_ADDR,TCP,IC11,##FIELD,field)

  #define _TCP_IC11_FSETS(FIELD,SYM)\
    _PER_FSETS(_TCP_IC11_ADDR,TCP,IC11,FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  O U T            |
* |___________________|
*
* TCP output parameters register
*
* FIELDS (msb -> lsb)
* (rw) NIT
*
\******************************************************************************/
  #define _TCP_OUT_OFFSET            12

  #define _TCP_OUT_ADDR              0x01BA0030u

  #define _TCP_OUT_NIT_MASK          0xFFFF0000u
  #define _TCP_OUT_NIT_SHIFT         0x00000010u
  #define  TCP_OUT_NIT_DEFAULT       0x00000000u
  #define  TCP_OUT_NIT_OF(x)         _VALUEOF(x)

  #define  TCP_OUT_OF(x)             _VALUEOF(x)

  #define TCP_OUT_DEFAULT (Uint32)(\
     _PER_FDEFAULT(TCP,OUT,NIT)\
  )

  #define TCP_OUT_RMK(nit) (Uint32)(\
     _PER_FMK(TCP,OUT,NIT,nit)\
  )

  #define _TCP_OUT_FGET(FIELD)\
    _PER_FGET(_TCP_OUT_ADDR,TCP,OUT,##FIELD)

  #define _TCP_OUT_FSET(FIELD,field)\
    _PER_FSET(_TCP_OUT_ADDR,TCP,OUT,##FIELD,field)

  #define _TCP_OUT_FSETS(FIELD,SYM)\
    _PER_FSETS(_TCP_OUT_ADDR,TCP,OUT,##FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  E X E            |
* |___________________|
*
* TCP execution register
*
* FIELDS (msb -> lsb)
* (rw) UNPAUSE
* (rw) PAUSE
* (rw) START
*
\******************************************************************************/
  #define _TCP_EXE_OFFSET            14

  #define _TCP_EXE_ADDR              0x01BA0038u

  #define _TCP_EXE_UNPAUSE_MASK      0x00000004u //0x7F000000u
  #define _TCP_EXE_UNPAUSE_SHIFT     0x00000002u //0x00000018u
  #define  TCP_EXE_UNPAUSE_DEFAULT   0x00000000u
  #define  TCP_EXE_UNPAUSE_OF(x)     _VALUEOF(x)
  #define  TCP_EXE_UNPAUSE_UNPAUSE   0x00000001u

  #define _TCP_EXE_PAUSE_MASK        0x00000002u //0x007F0000u
  #define _TCP_EXE_PAUSE_SHIFT       0x00000001u
  #define  TCP_EXE_PAUSE_DEFAULT     0x00000000u
  #define  TCP_EXE_PAUSE_OF(x)       _VALUEOF(x)
  #define  TCP_EXE_PAUSE_PAUSE       0x00000001u

  #define _TCP_EXE_START_MASK        0x00000001u //0x0000FFFFu
  #define _TCP_EXE_START_SHIFT       0x00000000u
  #define  TCP_EXE_START_DEFAULT     0x00000000u
  #define  TCP_EXE_START_OF(x)       _VALUEOF(x)
  #define  TCP_EXE_START_START       0x00000001u

  #define  TCP_EXE_OF(x)             _VALUEOF(x)

  #define TCP_EXE_DEFAULT (Uint32)(\
    _PER_FDEFAULT(TCP,EXE,UNPAUSE)\
   |_PER_FDEFAULT(TCP,EXE,PAUSE)\
   |_PER_FDEFAULT(TCP,EXE,START)\
  )

  #define TCP_EXE_RMK(unpause,pause,start) (Uint32)(\
     _PER_FMK(TCP,EXE,UNPAUSE,unpause)\
    |_PER_FMK(TCP,EXE,PAUSE,pause)\
    |_PER_FMK(TCP,EXE,START,start)\
  )

  #define _TCP_EXE_FGET(FIELD)\
    _PER_FGET(_TCP_EXE_ADDR,TCP,EXE,##FIELD)

  #define _TCP_EXE_FSET(FIELD,field)\
    _PER_FSET(_TCP_EXE_ADDR,TCP,EXE,##FIELD,field)

  #define _TCP_EXE_FSETS(FIELD,SYM)\
    _PER_FSETS(_TCP_EXE_ADDR,TCP,EXE,##FIELD,##SYM)

    
/******************************************************************************\
* _____________________
* |                   |
* |  E N D            |
* |___________________|
*
* TCP endian mode register
*
* FIELDS (msb -> lsb)
* (rw) EXF
* (rw) AP
* (rw) INTER
* (rw) SYSPAR
*
\******************************************************************************/
  #define _TCP_END_OFFSET            16

  #define _TCP_END_ADDR              0x01BA0040u

  #define _TCP_END_EXT_MASK          0x00000008u
  #define _TCP_END_EXT_SHIFT         0x00000003u
  #define  TCP_END_EXT_DEFAULT       0x00000000u
  #define  TCP_END_EXT_OF(x)         _VALUEOF(x)
  #define  TCP_END_EXT_32BIT         0x00000000u
  #define  TCP_END_EXT_NATIVE        0x00000001u

  #define _TCP_END_AP_MASK          0x00000004u
  #define _TCP_END_AP_SHIFT         0x00000002u
  #define  TCP_END_AP_DEFAULT       0x00000000u
  #define  TCP_END_AP_OF(x)         _VALUEOF(x)
  #define  TCP_END_AP_32BIT         0x00000000u
  #define  TCP_END_AP_NATIVE        0x00000001u

  #define _TCP_END_INTER_MASK         0x00000002u
  #define _TCP_END_INTER_SHIFT        0x00000001u
  #define  TCP_END_INTER_DEFAULT      0x00000000u
  #define  TCP_END_INTER_OF(x)        _VALUEOF(x)
  #define  TCP_END_INTER_32BIT        0x00000000u
  #define  TCP_END_INTER_NATIVE       0x00000001u

  #define _TCP_END_SYSPAR_MASK        0x00000001u
  #define _TCP_END_SYSPAR_SHIFT       0x00000000u
  #define  TCP_END_SYSPAR_DEFAULT     0x00000000u
  #define  TCP_END_SYSPAR_OF(x)       _VALUEOF(x)
  #define  TCP_END_SYSPAR_32BIT       0x00000000u
  #define  TCP_END_SYSPAR_NATIVE      0x00000001u

  #define  TCP_END_OF(x)             _VALUEOF(x)

  #define TCP_END_DEFAULT (Uint32)(\
    _PER_FDEFAULT(TCP,END,EXT)\
   |_PER_FDEFAULT(TCP,END,AP)\
   |_PER_FDEFAULT(TCP,END,INTER)\
   |_PER_FDEFAULT(TCP,END,SYSPAR)\
  )

  #define TCP_END_RMK(ext,ap,inter,syspar) (Uint32)(\
     _PER_FMK(TCP,END,EXT,ext)\
    |_PER_FMK(TCP,END,AP,ap)\
    |_PER_FMK(TCP,END,INTER,inter)\
    |_PER_FMK(TCP,END,SYSPAR,syspar)\
  )

  #define _TCP_END_FGET(FIELD)\
    _PER_FGET(_TCP_END_ADDR,TCP,END,##FIELD)

  #define _TCP_END_FSET(FIELD,field)\
    _PER_FSET(_TCP_END_ADDR,TCP,END,##FIELD,field)

  #define _TCP_END_FSETS(FIELD,SYM)\
    _PER_FSETS(_TCP_END_ADDR,TCP,END,##FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  E R R            |
* |___________________|
*
* TCP error register
*
* FIELDS (msb -> lsb)
* (r) ACC
* (r) OP
* (r) INT
* (r) LR
* (r) R
* (r) MODE
* (r) SF
* (r) RATE
* (r) P
* (r) F
* (r) ERR
*
\******************************************************************************/
  #define _TCP_ERR_OFFSET          20

  #define _TCP_ERR_ADDR            0x01BA0050u

  #define _TCP_ERR_ACC_MASK      0x00000800u
  #define _TCP_ERR_ACC_SHIFT     0x0000000Bu
  #define  TCP_ERR_ACC_DEFAULT   0x00000000u
  #define  TCP_ERR_ACC_OF(x)     _VALUEOF(x)
  #define  TCP_ERR_ACC_NO        0x00000000u
  #define  TCP_ERR_ACC_YES       0x00000001u

  #define _TCP_ERR_OP_MASK      0x00000400u
  #define _TCP_ERR_OP_SHIFT     0x0000000Au
  #define  TCP_ERR_OP_DEFAULT   0x00000000u
  #define  TCP_ERR_OP_OF(x)     _VALUEOF(x)
  #define  TCP_ERR_OP_NO        0x00000000u
  #define  TCP_ERR_OP_YES       0x00000001u

  #define _TCP_ERR_INT_MASK      0x00000200u
  #define _TCP_ERR_INT_SHIFT     0x00000009u
  #define  TCP_ERR_INT_DEFAULT   0x00000000u
  #define  TCP_ERR_INT_OF(x)     _VALUEOF(x)
  #define  TCP_ERR_INT_NO        0x00000000u
  #define  TCP_ERR_INT_YES       0x00000001u

  #define _TCP_ERR_LR_MASK     0x00000100u
  #define _TCP_ERR_LR_SHIFT    0x00000008u
  #define  TCP_ERR_LR_DEFAULT  0x00000000u
  #define  TCP_ERR_LR_OF(x)    _VALUEOF(x)
  #define  TCP_ERR_LR_NO       0x00000000u
  #define  TCP_ERR_LR_YES      0x00000001u

  #define _TCP_ERR_R_MASK      0x00000080u
  #define _TCP_ERR_R_SHIFT     0x00000007u
  #define  TCP_ERR_R_DEFAULT   0x00000000u
  #define  TCP_ERR_R_OF(x)     _VALUEOF(x)
  #define  TCP_ERR_R_NO        0x00000000u
  #define  TCP_ERR_R_YES       0x00000001u

  #define _TCP_ERR_MODE_MASK      0x00000040u
  #define _TCP_ERR_MODE_SHIFT     0x00000006u
  #define  TCP_ERR_MODE_DEFAULT   0x00000000u
  #define  TCP_ERR_MODE_OF(x)     _VALUEOF(x)
  #define  TCP_ERR_MODE_NO        0x00000000u
  #define  TCP_ERR_MODE_YES       0x00000001u

  #define _TCP_ERR_SF_MASK     0x00000010u
  #define _TCP_ERR_SF_SHIFT    0x00000004u
  #define  TCP_ERR_SF_DEFAULT  0x00000000u
  #define  TCP_ERR_SF_OF(x)    _VALUEOF(x)
  #define  TCP_ERR_SF_NO       0x00000000u
  #define  TCP_ERR_SF_YES      0x00000001u

  #define _TCP_ERR_RATE_MASK       0x00000008u
  #define _TCP_ERR_RATE_SHIFT      0x00000003u
  #define  TCP_ERR_RATE_DEFAULT    0x00000000u
  #define  TCP_ERR_RATE_OF(x)      _VALUEOF(x)
  #define  TCP_ERR_RATE_NO         0x00000000u
  #define  TCP_ERR_RATE_YES        0x00000001u

  #define _TCP_ERR_P_MASK          0x00000004u
  #define _TCP_ERR_P_SHIFT         0x00000002u
  #define  TCP_ERR_P_DEFAULT       0x00000000u
  #define  TCP_ERR_P_OF(x)         _VALUEOF(x)
  #define  TCP_ERR_P_NO            0x00000000u
  #define  TCP_ERR_P_YES           0x00000001u

  #define _TCP_ERR_F_MASK          0x00000002u
  #define _TCP_ERR_F_SHIFT         0x00000001u
  #define  TCP_ERR_F_DEFAULT       0x00000000u
  #define  TCP_ERR_F_OF(x)         _VALUEOF(x)
  #define  TCP_ERR_F_NO            0x00000000u
  #define  TCP_ERR_F_YES           0x00000001u

  #define _TCP_ERR_ERR_MASK        0x00000001u
  #define _TCP_ERR_ERR_SHIFT       0x00000000u
  #define  TCP_ERR_ERR_DEFAULT     0x00000000u
  #define  TCP_ERR_ERR_OF(x)       _VALUEOF(x)
  #define  TCP_ERR_ERR_NO          0x00000000u
  #define  TCP_ERR_ERR_YES         0x00000001u

  #define  TCP_ERR_OF(x)           _VALUEOF(x)

  #define TCP_ERR_DEFAULT (Uint32)(\
    _PER_FDEFAULT(TCP,ERR,ACC)\
   |_PER_FDEFAULT(TCP,ERR,OP)\
   |_PER_FDEFAULT(TCP,ERR,INT)\
   |_PER_FDEFAULT(TCP,ERR,LR)\
   |_PER_FDEFAULT(TCP,ERR,R)\
   |_PER_FDEFAULT(TCP,ERR,MODE)\
   |_PER_FDEFAULT(TCP,ERR,SF)\
   |_PER_FDEFAULT(TCP,ERR,RATE)\
   |_PER_FDEFAULT(TCP,ERR,P)\
   |_PER_FDEFAULT(TCP,ERR,F)\
   |_PER_FDEFAULT(TCP,ERR,ERR)\
  )
#if (!(CHIP_6413 | CHIP_6418 | CHIP_6410))
  #define TCP_ERR_RMK(acc,op,inter,lr,r,mode, \
		      sf,rate,p,f,err) (Uint32)(\
       _PER_FMK(TCP,ERR,ACC,acc)\
      |_PER_FMK(TCP,ERR,OP,op)\
      |_PER_FMK(TCP,ERR,INT,inter)\
      |_PER_FMK(TCP,ERR,LR,lr)\
      |_PER_FMK(TCP,ERR,R,r)\
      |_PER_FMK(TCP,ERR,MODE,mode)\
      |_PER_FMK(TCP,ERR,SF,sf)\
      |_PER_FMK(TCP,ERR,RATE,rate)\
      |_PER_FMK(TCP,ERR,P,p)\
      |_PER_FMK(TCP,ERR,F,f)\
      |_PER_FMK(TCP,ERR,ERR,err)\
  )      
#endif			
  #define _TCP_ERR_FGET(FIELD)\
    _PER_FGET(_TCP_ERR_ADDR,TCP,ERR,##FIELD)

/******************************************************************************\
* _____________________
* |                   |
* |  S T A T          |
* |___________________|
*
* TCP status register
*
* FIELDS (msb -> lsb)
* (r) ROP
* (r) RHD
* (r) REXT
* (r) WAP
* (r) WSP
* (r) WINT
* (r) WIC
* (r) ERR
* (r) RUN
* (r) PAUS
*
\******************************************************************************/
  #define _TCP_STAT_OFFSET         22

  #define _TCP_STAT_ADDR           0x01BA0058u

  #define _TCP_STAT_ROP_MASK       0x00000200u
  #define _TCP_STAT_ROP_SHIFT      0x00000009u
  #define  TCP_STAT_ROP_DEFAULT    0x00000000u
  #define  TCP_STAT_ROP_OF(x)      _VALUEOF(x)
  #define  TCP_STAT_ROP_NREADY     0x00000000u
  #define  TCP_STAT_ROP_READY      0x00000001u

  #define _TCP_STAT_RHD_MASK       0x00000100u
  #define _TCP_STAT_RHD_SHIFT      0x00000008u
  #define  TCP_STAT_RHD_DEFAULT    0x00000000u
  #define  TCP_STAT_RHD_OF(x)      _VALUEOF(x)
  #define  TCP_STAT_RHD_NREADY     0x00000000u
  #define  TCP_STAT_RHD_READY      0x00000001u

  #define _TCP_STAT_REXT_MASK       0x00000080u
  #define _TCP_STAT_REXT_SHIFT      0x00000007u
  #define  TCP_STAT_REXT_DEFAULT    0x00000000u
  #define  TCP_STAT_REXT_OF(x)      _VALUEOF(x)
  #define  TCP_STAT_REXT_NREADY     0x00000000u
  #define  TCP_STAT_REXT_READY      0x00000001u

  #define _TCP_STAT_WAP_MASK       0x00000040u
  #define _TCP_STAT_WAP_SHIFT      0x00000006u
  #define  TCP_STAT_WAP_DEFAULT    0x00000000u
  #define  TCP_STAT_WAP_OF(x)      _VALUEOF(x)
  #define  TCP_STAT_WAP_NREADY     0x00000000u
  #define  TCP_STAT_WAP_READY      0x00000001u

  #define _TCP_STAT_WSP_MASK       0x00000020u
  #define _TCP_STAT_WSP_SHIFT      0x00000005u
  #define  TCP_STAT_WSP_DEFAULT    0x00000000u
  #define  TCP_STAT_WSP_OF(x)      _VALUEOF(x)
  #define  TCP_STAT_WSP_NREADY     0x00000000u
  #define  TCP_STAT_WSP_READY      0x00000001u

  #define _TCP_STAT_WINT_MASK       0x00000010u
  #define _TCP_STAT_WINT_SHIFT      0x00000004u
  #define  TCP_STAT_WINT_DEFAULT    0x00000000u
  #define  TCP_STAT_WINT_OF(x)      _VALUEOF(x)
  #define  TCP_STAT_WINT_NREADY     0x00000000u
  #define  TCP_STAT_WINT_READY      0x00000001u

  #define _TCP_STAT_WIC_MASK       0x00000008u
  #define _TCP_STAT_WIC_SHIFT      0x00000003u
  #define  TCP_STAT_WIC_DEFAULT    0x00000000u
  #define  TCP_STAT_WIC_OF(x)      _VALUEOF(x)
  #define  TCP_STAT_WIC_NREADY     0x00000000u
  #define  TCP_STAT_WIC_READY      0x00000001u

  #define _TCP_STAT_ERR_MASK       0x00000004u
  #define _TCP_STAT_ERR_SHIFT      0x00000002u
  #define  TCP_STAT_ERR_DEFAULT    0x00000000u
  #define  TCP_STAT_ERR_OF(x)      _VALUEOF(x)
  #define  TCP_STAT_ERR_NO         0x00000000u
  #define  TCP_STAT_ERR_YES        0x00000001u

  #define _TCP_STAT_RUN_MASK       0x00000002u
  #define _TCP_STAT_RUN_SHIFT      0x00000001u
  #define  TCP_STAT_RUN_DEFAULT    0x00000000u
  #define  TCP_STAT_RUN_OF(x)      _VALUEOF(x)
  #define  TCP_STAT_RUN_NO         0x00000000u
  #define  TCP_STAT_RUN_YES        0x00000001u

  #define _TCP_STAT_PAUS_MASK     0x00000001u
  #define _TCP_STAT_PAUS_SHIFT    0x00000000u
  #define  TCP_STAT_PAUS_DEFAULT  0x00000000u
  #define  TCP_STAT_PAUS_OF(x)    _VALUEOF(x)
  #define  TCP_STAT_PAUS_NO       0x00000000u
  #define  TCP_STAT_PAUS_YES      0x00000001u

  #define  TCP_STAT_OF(x)          _VALUEOF(x)

  #define TCP_STAT_DEFAULT (Uint32)(\
    _PER_FDEFAULT(TCP,STAT,ROP)\
   |_PER_FDEFAULT(TCP,STAT,RHD)\
   |_PER_FDEFAULT(TCP,STAT,REX)\
   |_PER_FDEFAULT(TCP,STAT,WAP)\
   |_PER_FDEFAULT(TCP,STAT,WSP)\
   |_PER_FDEFAULT(TCP,STAT,WINT)\
   |_PER_FDEFAULT(TCP,STAT,WIC)\
   |_PER_FDEFAULT(TCP,STAT,ERR)\
   |_PER_FDEFAULT(TCP,STAT,RUN)\
   |_PER_FDEFAULT(TCP,STAT,PAUS)\
  )
  #define TCP_STAT_RMK(rop,rhd,rex,wap,wsp,wint,wic,err,run,paus) (Uint32)(\
       _PER_FMK(TCP,STAT,ROP,rop)\
      |_PER_FMK(TCP,STAT,RHD,rhd)\
      |_PER_FMK(TCP,STAT,REX,rex)\
      |_PER_FMK(TCP,STAT,WAP,wap)\
      |_PER_FMK(TCP,STAT,WSP,wsp)\
      |_PER_FMK(TCP,STAT,WINT,wint)\
      |_PER_FMK(TCP,STAT,WIC,wic)\
      |_PER_FMK(TCP,STAT,ERR,err)\
      |_PER_FMK(TCP,STAT,RUN,run)\
      |_PER_FMK(TCP,STAT,PAUS,paus)\
   )      
  #define _TCP_STAT_FGET(FIELD)\
    _PER_FGET(_TCP_STAT_ADDR,TCP,STAT,##FIELD)



/*----------------------------------------------------------------------------*/

#endif /* TCP_SUPPORT */
#endif /* _CSL_TCPHAL_H_ */
/******************************************************************************\
* End of csl_tcphal.h
\******************************************************************************/

