/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_dmahal.h
* DATE CREATED.. 03/12/1999 
* LAST MODIFIED. 02/05/2002 added 6204/6205 to DMA_COND1
*------------------------------------------------------------------------------
* REGISTERS
*
* AUXCTL   - auxiliary control register 
* PRICTL0  - channel primary control register 0
* PRICTL1  - channel primary control register 1
* PRICTL2  - channel primary control register 2
* PRICTL3  - channel primary control register 3
* SECCTL0  - channel seccondary control register 0
* SECCTL1  - channel seccondary control register 1
* SECCTL2  - channel seccondary control register 2
* SECCTL3  - channel seccondary control register 3
* SRC0     - channel src address register 0
* SRC1     - channel src address register 1
* SRC2     - channel src address register 2
* SRC3     - channel src address register 3
* DST0     - channel destination address register 0
* DST1     - channel destination address register 1
* DST2     - channel destination address register 2
* DST3     - channel destination address register 3
* XFRCNT0  - channel transfer count register 0
* XFRCNT1  - channel transfer count register 1
* XFRCNT2  - channel transfer count register 2
* XFRCNT3  - channel transfer count register 3
* GBLCNTA  - global count reload register A
* GBLCNTB  - global count reload register B
* GBLIDXA  - global index register A
* GBLIDXB  - global index register B
* GBLADDRA - global address reload register A
* GBLADDRB - global address reload register B
* GBLADDRC - global address reload register C
* GBLADDRD - global address reload register D
*
\******************************************************************************/
#ifndef _CSL_DMAHAL_H_
#define _CSL_DMAHAL_H_

#include <csl_stdinc.h>
#include <csl_chip.h>

#if (DMA_SUPPORT)
/******************************************************************************\
* MISC section
\******************************************************************************/

  #define _DMA_COND1   (CHIP_6202|CHIP_6203|CHIP_6204|CHIP_6205)

  #define _DMA_BASE_CHA0    0x01840000u
  #define _DMA_BASE_CHA1    0x01840040u
  #define _DMA_BASE_CHA2    0x01840004u
  #define _DMA_BASE_CHA3    0x01840044u


/******************************************************************************\
* module level register/field access macros
\******************************************************************************/

  /* ----------------- */
  /* FIELD MAKE MACROS */
  /* ----------------- */

  #define DMA_FMK(REG,FIELD,x)\
    _PER_FMK(DMA,##REG,##FIELD,x)

  #define DMA_FMKS(REG,FIELD,SYM)\
    _PER_FMKS(DMA,##REG,##FIELD,##SYM)


  /* -------------------------------- */
  /* RAW REGISTER/FIELD ACCESS MACROS */
  /* -------------------------------- */

  #define DMA_ADDR(REG)\
    _DMA_##REG##_ADDR

  #define DMA_RGET(REG)\
    _PER_RGET(_DMA_##REG##_ADDR,DMA,##REG)

  #define DMA_RSET(REG,x)\
    _PER_RSET(_DMA_##REG##_ADDR,DMA,##REG,x)

  #define DMA_FGET(REG,FIELD)\
    _DMA_##REG##_FGET(##FIELD)

  #define DMA_FSET(REG,FIELD,x)\
    _DMA_##REG##_FSET(##FIELD,##x)

  #define DMA_FSETS(REG,FIELD,SYM)\
    _DMA_##REG##_FSETS(##FIELD,##SYM)


  /* ------------------------------------------ */
  /* ADDRESS BASED REGISTER/FIELD ACCESS MACROS */
  /* ------------------------------------------ */

  #define DMA_RGETA(addr,REG)\
    _PER_RGET(addr,DMA,##REG)

  #define DMA_RSETA(addr,REG,x)\
    _PER_RSET(addr,DMA,##REG,x)

  #define DMA_FGETA(addr,REG,FIELD)\
    _PER_FGET(addr,DMA,##REG,##FIELD)

  #define DMA_FSETA(addr,REG,FIELD,x)\
    _PER_FSET(addr,DMA,##REG,##FIELD,x)

  #define DMA_FSETSA(addr,REG,FIELD,SYM)\
    _PER_FSETS(addr,DMA,##REG,##FIELD,##SYM)


  /* ----------------------------------------- */
  /* HANDLE BASED REGISTER/FIELD ACCESS MACROS */
  /* ----------------------------------------- */

  #define DMA_ADDRH(h,REG)\
    (Uint32)(&((h)->baseAddr[_DMA_##REG##_OFFSET]))

  #define DMA_RGETH(h,REG)\
    DMA_RGETA(DMA_ADDRH(h,##REG),##REG)


  #define DMA_RSETH(h,REG,x)\
    DMA_RSETA(DMA_ADDRH(h,##REG),##REG,x)


  #define DMA_FGETH(h,REG,FIELD)\
    DMA_FGETA(DMA_ADDRH(h,##REG),##REG,##FIELD)


  #define DMA_FSETH(h,REG,FIELD,x)\
    DMA_FSETA(DMA_ADDRH(h,##REG),##REG,##FIELD,x)


  #define DMA_FSETSH(h,REG,FIELD,SYM)\
    DMA_FSETSA(DMA_ADDRH(h,##REG),##REG,##FIELD,##SYM)



/******************************************************************************\
* _____________________
* |                   |
* |  A U X C T L      |
* |___________________|
*
* AUXCTL   - auxiliary control register
*
* FIELDS (msb -> lsb)
* (rw) AUXPRI
* (rw) CHPRI
*
\******************************************************************************/
  #define _DMA_AUXCTL_ADDR              0x01840070u

  #define _DMA_AUXCTL_AUXPRI_MASK       0x00000010u
  #define _DMA_AUXCTL_AUXPRI_SHIFT      0x00000004u
  #define  DMA_AUXCTL_AUXPRI_DEFAULT    0x00000000u
  #define  DMA_AUXCTL_AUXPRI_OF(x)      _VALUEOF(x)
  #define  DMA_AUXCTL_AUXPRI_CPU        0x00000000u
  #define  DMA_AUXCTL_AUXPRI_DMA        0x00000001u

  #define _DMA_AUXCTL_CHPRI_MASK        0x0000000Fu
  #define _DMA_AUXCTL_CHPRI_SHIFT       0x00000000u
  #define  DMA_AUXCTL_CHPRI_DEFAULT     0x00000000u
  #define  DMA_AUXCTL_CHPRI_OF(x)       _VALUEOF(x)
  #define  DMA_AUXCTL_CHPRI_HIGHEST     0x00000000u
  #define  DMA_AUXCTL_CHPRI_2ND         0x00000001u
  #define  DMA_AUXCTL_CHPRI_3RD         0x00000002u
  #define  DMA_AUXCTL_CHPRI_4TH         0x00000003u
  #define  DMA_AUXCTL_CHPRI_LOWEST      0x00000004u

  #define  DMA_AUXCTL_OF(x)             _VALUEOF(x)

  #define DMA_AUXCTL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(DMA,AUXCTL,AUXPRI) \
    |_PER_FDEFAULT(DMA,AUXCTL,CHPRI) \
  )

  #define DMA_AUXCTL_RMK(auxpri,chpri) (Uint32)( \
     _PER_FMK(DMA,AUXCTL,AUXPRI,auxpri) \
    |_PER_FMK(DMA,AUXCTL,CHPRI,chpri) \
  )

  #define _DMA_AUXCTL_FGET(FIELD)\
    _PER_FGET(_DMA_AUXCTL_ADDR,DMA,AUXCTL,##FIELD)

  #define _DMA_AUXCTL_FSET(FIELD,field)\
    _PER_FSET(_DMA_AUXCTL_ADDR,DMA,AUXCTL,##FIELD,field)

  #define _DMA_AUXCTL_FSETS(FIELD,SYM)\
    _PER_FSETS(_DMA_AUXCTL_ADDR,DMA,AUXCTL,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  P R I C T L      |
* |___________________|
*
* PRICTL0  - channel primary control register 0
* PRICTL1  - channel primary control register 1
* PRICTL2  - channel primary control register 2
* PRICTL3  - channel primary control register 3
*
* FIELDS (msb -> lsb)
* (rw) DSTRLD
* (rw) SRCRLD
* (rw) EMOD
* (rw) FS
* (rw) TCINT
* (rw) PRI
* (rw) WSYNC
* (rw) RSYNC
* (rw) INDEX
* (rw) CNTRLD
* (rw) SPLIT
* (rw) ESIZE
* (rw) DSTDIR
* (rw) SRCDIR
* (r)  STATUS
* (rw) START
*
\******************************************************************************/
  #define _DMA_PRICTL_OFFSET            0

  #define _DMA_PRICTL0_ADDR             0x01840000u
  #define _DMA_PRICTL1_ADDR             0x01840040u
  #define _DMA_PRICTL2_ADDR             0x01840004u
  #define _DMA_PRICTL3_ADDR             0x01840044u

  #define _DMA_PRICTL_DSTRLD_MASK       0xC0000000u
  #define _DMA_PRICTL_DSTRLD_SHIFT      0x0000001Eu
  #define  DMA_PRICTL_DSTRLD_DEFAULT    0x00000000u
  #define  DMA_PRICTL_DSTRLD_OF(x)      _VALUEOF(x)
  #define  DMA_PRICTL_DSTRLD_NONE       0x00000000u
  #define  DMA_PRICTL_DSTRLD_B          0x00000001u
  #define  DMA_PRICTL_DSTRLD_C          0x00000002u
  #define  DMA_PRICTL_DSTRLD_D          0x00000003u

  #define _DMA_PRICTL_SRCRLD_MASK       0x30000000u
  #define _DMA_PRICTL_SRCRLD_SHIFT      0x0000001Cu
  #define  DMA_PRICTL_SRCRLD_DEFAULT    0x00000000u
  #define  DMA_PRICTL_SRCRLD_OF(x)      _VALUEOF(x)
  #define  DMA_PRICTL_SRCRLD_NONE       0x00000000u
  #define  DMA_PRICTL_SRCRLD_B          0x00000001u
  #define  DMA_PRICTL_SRCRLD_C          0x00000002u
  #define  DMA_PRICTL_SRCRLD_D          0x00000003u

  #define _DMA_PRICTL_EMOD_MASK         0x08000000u
  #define _DMA_PRICTL_EMOD_SHIFT        0x0000001Bu
  #define  DMA_PRICTL_EMOD_DEFAULT      0x00000000u
  #define  DMA_PRICTL_EMOD_OF(x)        _VALUEOF(x)
  #define  DMA_PRICTL_EMOD_NOHALT       0x00000000u
  #define  DMA_PRICTL_EMOD_HALT         0x00000001u

  #define _DMA_PRICTL_FS_MASK           0x04000000u
  #define _DMA_PRICTL_FS_SHIFT          0x0000001Au
  #define  DMA_PRICTL_FS_DEFAULT        0x00000000u
  #define  DMA_PRICTL_FS_OF(x)          _VALUEOF(x)
  #define  DMA_PRICTL_FS_DISABLE        0x00000000u
  #define  DMA_PRICTL_FS_RSYNC          0x00000001u

  #define _DMA_PRICTL_TCINT_MASK        0x02000000u
  #define _DMA_PRICTL_TCINT_SHIFT       0x00000019u
  #define  DMA_PRICTL_TCINT_DEFAULT     0x00000000u
  #define  DMA_PRICTL_TCINT_OF(x)       _VALUEOF(x)
  #define  DMA_PRICTL_TCINT_DISABLE     0x00000000u
  #define  DMA_PRICTL_TCINT_ENABLE      0x00000001u

  #define _DMA_PRICTL_PRI_MASK          0x01000000u
  #define _DMA_PRICTL_PRI_SHIFT         0x00000018u
  #define  DMA_PRICTL_PRI_DEFAULT       0x00000000u
  #define  DMA_PRICTL_PRI_OF(x)         _VALUEOF(x)
  #define  DMA_PRICTL_PRI_CPU           0x00000000u
  #define  DMA_PRICTL_PRI_DMA           0x00000001u

  #define _DMA_PRICTL_WSYNC_MASK        0x00F80000u
  #define _DMA_PRICTL_WSYNC_SHIFT       0x00000013u
  #define  DMA_PRICTL_WSYNC_DEFAULT     0x00000000u
  #define  DMA_PRICTL_WSYNC_OF(x)       _VALUEOF(x)
  #define  DMA_PRICTL_WSYNC_NONE        0x00000000u
  #define  DMA_PRICTL_WSYNC_TINT0       0x00000001u
  #define  DMA_PRICTL_WSYNC_TINT1       0x00000002u
  #define  DMA_PRICTL_WSYNC_SDINT       0x00000003u
  #define  DMA_PRICTL_WSYNC_EXTINT4     0x00000004u
  #define  DMA_PRICTL_WSYNC_EXTINT5     0x00000005u
  #define  DMA_PRICTL_WSYNC_EXTINT6     0x00000006u
  #define  DMA_PRICTL_WSYNC_EXTINT7     0x00000007u
  #define  DMA_PRICTL_WSYNC_DMAINT0     0x00000008u
  #define  DMA_PRICTL_WSYNC_DMAINT1     0x00000009u
  #define  DMA_PRICTL_WSYNC_DMAINT2     0x0000000Au
  #define  DMA_PRICTL_WSYNC_DMAINT3     0x0000000Bu
  #define  DMA_PRICTL_WSYNC_XEVT0       0x0000000Cu
  #define  DMA_PRICTL_WSYNC_REVT0       0x0000000Du
  #define  DMA_PRICTL_WSYNC_XEVT1       0x0000000Eu
  #define  DMA_PRICTL_WSYNC_REVT1       0x0000000Fu
  #define  DMA_PRICTL_WSYNC_DSPINT      0x00000010u
  #define  DMA_PRICTL_WSYNC_XEVT2       0x00000011u
  #define  DMA_PRICTL_WSYNC_REVT2       0x00000012u

  #define _DMA_PRICTL_RSYNC_MASK        0x0007C000u
  #define _DMA_PRICTL_RSYNC_SHIFT       0x0000000Eu
  #define  DMA_PRICTL_RSYNC_DEFAULT     0x00000000u
  #define  DMA_PRICTL_RSYNC_OF(x)       _VALUEOF(x)
  #define  DMA_PRICTL_RSYNC_NONE        0x00000000u
  #define  DMA_PRICTL_RSYNC_TINT0       0x00000001u
  #define  DMA_PRICTL_RSYNC_TINT1       0x00000002u
  #define  DMA_PRICTL_RSYNC_SDINT       0x00000003u
  #define  DMA_PRICTL_RSYNC_EXTINT4     0x00000004u
  #define  DMA_PRICTL_RSYNC_EXTINT5     0x00000005u
  #define  DMA_PRICTL_RSYNC_EXTINT6     0x00000006u
  #define  DMA_PRICTL_RSYNC_EXTINT7     0x00000007u
  #define  DMA_PRICTL_RSYNC_DMAINT0     0x00000008u
  #define  DMA_PRICTL_RSYNC_DMAINT1     0x00000009u
  #define  DMA_PRICTL_RSYNC_DMAINT2     0x0000000Au
  #define  DMA_PRICTL_RSYNC_DMAINT3     0x0000000Bu
  #define  DMA_PRICTL_RSYNC_XEVT0       0x0000000Cu
  #define  DMA_PRICTL_RSYNC_REVT0       0x0000000Du
  #define  DMA_PRICTL_RSYNC_XEVT1       0x0000000Eu
  #define  DMA_PRICTL_RSYNC_REVT1       0x0000000Fu
  #define  DMA_PRICTL_RSYNC_DSPINT      0x00000010u
  #define  DMA_PRICTL_RSYNC_XEVT2       0x00000011u
  #define  DMA_PRICTL_RSYNC_REVT2       0x00000012u

  #define _DMA_PRICTL_INDEX_MASK        0x00002000u
  #define _DMA_PRICTL_INDEX_SHIFT       0x0000000Du
  #define  DMA_PRICTL_INDEX_DEFAULT     0x00000000u
  #define  DMA_PRICTL_INDEX_OF(x)       _VALUEOF(x)
  #define  DMA_PRICTL_INDEX_NA          0x00000000u
  #define  DMA_PRICTL_INDEX_A           0x00000000u
  #define  DMA_PRICTL_INDEX_B           0x00000001u

  #define _DMA_PRICTL_CNTRLD_MASK       0x00001000u
  #define _DMA_PRICTL_CNTRLD_SHIFT      0x0000000Cu
  #define  DMA_PRICTL_CNTRLD_DEFAULT    0x00000000u
  #define  DMA_PRICTL_CNTRLD_OF(x)      _VALUEOF(x)
  #define  DMA_PRICTL_CNTRLD_NA         0x00000000u
  #define  DMA_PRICTL_CNTRLD_A          0x00000000u
  #define  DMA_PRICTL_CNTRLD_B          0x00000001u

  #define _DMA_PRICTL_SPLIT_MASK        0x00000C00u
  #define _DMA_PRICTL_SPLIT_SHIFT       0x0000000Au
  #define  DMA_PRICTL_SPLIT_DEFAULT     0x00000000u
  #define  DMA_PRICTL_SPLIT_OF(x)       _VALUEOF(x)
  #define  DMA_PRICTL_SPLIT_DISABLE     0x00000000u
  #define  DMA_PRICTL_SPLIT_A           0x00000001u
  #define  DMA_PRICTL_SPLIT_B           0x00000002u
  #define  DMA_PRICTL_SPLIT_C           0x00000003u

  #define _DMA_PRICTL_ESIZE_MASK        0x00000300u
  #define _DMA_PRICTL_ESIZE_SHIFT       0x00000008u
  #define  DMA_PRICTL_ESIZE_DEFAULT     0x00000000u
  #define  DMA_PRICTL_ESIZE_OF(x)       _VALUEOF(x)
  #define  DMA_PRICTL_ESIZE_32BIT       0x00000000u
  #define  DMA_PRICTL_ESIZE_16BIT       0x00000001u
  #define  DMA_PRICTL_ESIZE_8BIT        0x00000002u

  #define _DMA_PRICTL_DSTDIR_MASK       0x000000C0u
  #define _DMA_PRICTL_DSTDIR_SHIFT      0x00000006u
  #define  DMA_PRICTL_DSTDIR_DEFAULT    0x00000000u
  #define  DMA_PRICTL_DSTDIR_OF(x)      _VALUEOF(x)
  #define  DMA_PRICTL_DSTDIR_NONE       0x00000000u
  #define  DMA_PRICTL_DSTDIR_INC        0x00000001u
  #define  DMA_PRICTL_DSTDIR_DEC        0x00000002u
  #define  DMA_PRICTL_DSTDIR_IDX        0x00000003u

  #define _DMA_PRICTL_SRCDIR_MASK       0x00000030u
  #define _DMA_PRICTL_SRCDIR_SHIFT      0x00000004u
  #define  DMA_PRICTL_SRCDIR_DEFAULT    0x00000000u
  #define  DMA_PRICTL_SRCDIR_OF(x)      _VALUEOF(x)
  #define  DMA_PRICTL_SRCDIR_NONE       0x00000000u
  #define  DMA_PRICTL_SRCDIR_INC        0x00000001u
  #define  DMA_PRICTL_SRCDIR_DEC        0x00000002u
  #define  DMA_PRICTL_SRCDIR_IDX        0x00000003u

  #define _DMA_PRICTL_STATUS_MASK       0x0000000Cu
  #define _DMA_PRICTL_STATUS_SHIFT      0x00000002u
  #define  DMA_PRICTL_STATUS_DEFAULT    0x00000000u
  #define  DMA_PRICTL_STATUS_OF(x)      _VALUEOF(x)
  #define  DMA_PRICTL_STATUS_STOPPED    0x00000000u
  #define  DMA_PRICTL_STATUS_RUNNING    0x00000001u
  #define  DMA_PRICTL_STATUS_PAUSED     0x00000002u
  #define  DMA_PRICTL_STATUS_AUTORUNNING 0x00000003u

  #define _DMA_PRICTL_START_MASK        0x00000003u
  #define _DMA_PRICTL_START_SHIFT       0x00000000u
  #define  DMA_PRICTL_START_DEFAULT     0x00000000u
  #define  DMA_PRICTL_START_OF(x)       _VALUEOF(x)
  #define  DMA_PRICTL_START_STOP        0x00000000u
  #define  DMA_PRICTL_START_NORMAL      0x00000001u
  #define  DMA_PRICTL_START_PAUSE       0x00000002u
  #define  DMA_PRICTL_START_AUTOINIT    0x00000003u

  #define  DMA_PRICTL_OF(x)             _VALUEOF(x)

  #define DMA_PRICTL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(DMA,PRICTL,DSTRLD)\
    |_PER_FDEFAULT(DMA,PRICTL,SRCRLD)\
    |_PER_FDEFAULT(DMA,PRICTL,EMOD)\
    |_PER_FDEFAULT(DMA,PRICTL,FS)\
    |_PER_FDEFAULT(DMA,PRICTL,TCINT)\
    |_PER_FDEFAULT(DMA,PRICTL,PRI)\
    |_PER_FDEFAULT(DMA,PRICTL,WSYNC)\
    |_PER_FDEFAULT(DMA,PRICTL,RSYNC)\
    |_PER_FDEFAULT(DMA,PRICTL,INDEX)\
    |_PER_FDEFAULT(DMA,PRICTL,CNTRLD)\
    |_PER_FDEFAULT(DMA,PRICTL,SPLIT)\
    |_PER_FDEFAULT(DMA,PRICTL,ESIZE)\
    |_PER_FDEFAULT(DMA,PRICTL,DSTDIR)\
    |_PER_FDEFAULT(DMA,PRICTL,SRCDIR)\
    |_PER_FDEFAULT(DMA,PRICTL,STATUS)\
    |_PER_FDEFAULT(DMA,PRICTL,START)\
  )

  #define DMA_PRICTL_RMK(dstrld,srcrld,emod,fs,tcint,pri,wsync,rsync,index,\
    cntrld,split,esize,dstdir,srcdir,start) (Uint32)( \
     _PER_FMK(DMA,PRICTL,DSTRLD,dstrld)\
    |_PER_FMK(DMA,PRICTL,SRCRLD,srcrld)\
    |_PER_FMK(DMA,PRICTL,EMOD,emod)\
    |_PER_FMK(DMA,PRICTL,FS,fs)\
    |_PER_FMK(DMA,PRICTL,TCINT,tcint)\
    |_PER_FMK(DMA,PRICTL,PRI,pri)\
    |_PER_FMK(DMA,PRICTL,WSYNC,wsync)\
    |_PER_FMK(DMA,PRICTL,RSYNC,rsync)\
    |_PER_FMK(DMA,PRICTL,INDEX,index)\
    |_PER_FMK(DMA,PRICTL,CNTRLD,cntrld)\
    |_PER_FMK(DMA,PRICTL,SPLIT,split)\
    |_PER_FMK(DMA,PRICTL,ESIZE,esize)\
    |_PER_FMK(DMA,PRICTL,DSTDIR,dstdir)\
    |_PER_FMK(DMA,PRICTL,SRCDIR,srcdir)\
    |_PER_FMK(DMA,PRICTL,START,start)\
  )

  #define _DMA_PRICTL_FGET(N,FIELD)\
    _PER_FGET(_DMA_PRICTL##N##_ADDR,DMA,PRICTL,##FIELD)

  #define _DMA_PRICTL_FSET(N,FIELD,field)\
    _PER_FSET(_DMA_PRICTL##N##_ADDR,DMA,PRICTL,##FIELD,field)

  #define _DMA_PRICTL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_DMA_PRICTL##N##_ADDR,DMA,PRICTL,##FIELD,##SYM)

  #define _DMA_PRICTL0_FGET(FIELD) _DMA_PRICTL_FGET(0,##FIELD)
  #define _DMA_PRICTL1_FGET(FIELD) _DMA_PRICTL_FGET(1,##FIELD)
  #define _DMA_PRICTL2_FGET(FIELD) _DMA_PRICTL_FGET(2,##FIELD)
  #define _DMA_PRICTL3_FGET(FIELD) _DMA_PRICTL_FGET(3,##FIELD)

  #define _DMA_PRICTL0_FSET(FIELD,f) _DMA_PRICTL_FSET(0,##FIELD,f)
  #define _DMA_PRICTL1_FSET(FIELD,f) _DMA_PRICTL_FSET(1,##FIELD,f)
  #define _DMA_PRICTL2_FSET(FIELD,f) _DMA_PRICTL_FSET(2,##FIELD,f)
  #define _DMA_PRICTL3_FSET(FIELD,f) _DMA_PRICTL_FSET(3,##FIELD,f)

  #define _DMA_PRICTL0_FSETS(FIELD,SYM) _DMA_PRICTL_FSETS(0,##FIELD,##SYM)
  #define _DMA_PRICTL1_FSETS(FIELD,SYM) _DMA_PRICTL_FSETS(1,##FIELD,##SYM)
  #define _DMA_PRICTL2_FSETS(FIELD,SYM) _DMA_PRICTL_FSETS(2,##FIELD,##SYM)
  #define _DMA_PRICTL3_FSETS(FIELD,SYM) _DMA_PRICTL_FSETS(3,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  S E C C T L      |
* |___________________|
*
* SECCTL0  - channel seccondary control register 0
* SECCTL1  - channel seccondary control register 1
* SECCTL2  - channel seccondary control register 2
* SECCTL3  - channel seccondary control register 3
*
* FIELDS (msb -> lsb)
* (rw) WSPOL (1)
* (rw) RSPOL (1)
* (rw) FSIG  (1)
* (rw) DMACEN
* (rw) WSYNCCLR
* (rw) WSYNCSTAT
* (rw) RSYNCCLR
* (rw) RSYNCSTAT
* (rw) WDROPIE
* (rw) WDROPCOND
* (rw) RDROPIE
* (rw) RDROPCOND
* (rw) BLOCKIE
* (rw) BLOCKCOND
* (rw) LASTIE
* (rw) LASTCOND
* (rw) FRAMEIE
* (rw) FRAMECOND
* (rw) SXIE
* (rw) SXCOND
*
* (1) only on 6202 / 6203 /6204 /6205 devices
*
\******************************************************************************/
  #define _DMA_SECCTL_OFFSET            2

  #define _DMA_SECCTL0_ADDR             0x01840008u
  #define _DMA_SECCTL1_ADDR             0x01840048u
  #define _DMA_SECCTL2_ADDR             0x0184000Cu
  #define _DMA_SECCTL3_ADDR             0x0184004Cu

#if (_DMA_COND1)
  #define _DMA_SECCTL_WSPOL_MASK        0x00200000u
  #define _DMA_SECCTL_WSPOL_SHIFT       0x00000015u
  #define  DMA_SECCTL_WSPOL_DEFAULT     0x00000000u
  #define  DMA_SECCTL_WSPOL_OF(x)       _VALUEOF(x)
  #define  DMA_SECCTL_WSPOL_NA          0x00000000u
  #define  DMA_SECCTL_WSPOL_ACTIVEHIGH  0x00000000u
  #define  DMA_SECCTL_WSPOL_ACTIVELOW   0x00000001u

  #define _DMA_SECCTL_RSPOL_MASK        0x00100000u
  #define _DMA_SECCTL_RSPOL_SHIFT       0x00000014u
  #define  DMA_SECCTL_RSPOL_DEFAULT     0x00000000u
  #define  DMA_SECCTL_RSPOL_OF(x)       _VALUEOF(x)
  #define  DMA_SECCTL_RSPOL_NA          0x00000000u
  #define  DMA_SECCTL_RSPOL_ACTIVEHIGH  0x00000000u
  #define  DMA_SECCTL_RSPOL_ACTIVELOW   0x00000001u

  #define _DMA_SECCTL_FSIG_MASK         0x00080000u
  #define _DMA_SECCTL_FSIG_SHIFT        0x00000013u
  #define  DMA_SECCTL_FSIG_DEFAULT      0x00000000u
  #define  DMA_SECCTL_FSIG_OF(x)        _VALUEOF(x)
  #define  DMA_SECCTL_FSIG_NA           0x00000000u
  #define  DMA_SECCTL_FSIG_NORMAL       0x00000000u
  #define  DMA_SECCTL_FSIG_IGNORE       0x00000001u
#endif

  #define _DMA_SECCTL_DMACEN_MASK       0x00070000u
  #define _DMA_SECCTL_DMACEN_SHIFT      0x00000010u
  #define  DMA_SECCTL_DMACEN_DEFAULT    0x00000000u
  #define  DMA_SECCTL_DMACEN_OF(x)      _VALUEOF(x)
  #define  DMA_SECCTL_DMACEN_LOW        0x00000000u
  #define  DMA_SECCTL_DMACEN_HIGH       0x00000001u
  #define  DMA_SECCTL_DMACEN_RSYNCSTAT  0x00000002u
  #define  DMA_SECCTL_DMACEN_WSYNCSTAT  0x00000003u
  #define  DMA_SECCTL_DMACEN_FRAMECOND  0x00000004u
  #define  DMA_SECCTL_DMACEN_BLOCKCOND  0x00000005u

  #define _DMA_SECCTL_WSYNCCLR_MASK     0x00008000u
  #define _DMA_SECCTL_WSYNCCLR_SHIFT    0x0000000Fu
  #define  DMA_SECCTL_WSYNCCLR_DEFAULT  0x00000000u
  #define  DMA_SECCTL_WSYNCCLR_OF(x)    _VALUEOF(x)
  #define  DMA_SECCTL_WSYNCCLR_NOTHING  0x00000000u
  #define  DMA_SECCTL_WSYNCCLR_CLEAR    0x00000001u

  #define _DMA_SECCTL_WSYNCSTAT_MASK    0x00004000u
  #define _DMA_SECCTL_WSYNCSTAT_SHIFT   0x0000000Eu
  #define  DMA_SECCTL_WSYNCSTAT_DEFAULT 0x00000000u
  #define  DMA_SECCTL_WSYNCSTAT_OF(x)   _VALUEOF(x)
  #define  DMA_SECCTL_WSYNCSTAT_CLEAR   0x00000000u
  #define  DMA_SECCTL_WSYNCSTAT_SET     0x00000001u

  #define _DMA_SECCTL_RSYNCCLR_MASK     0x00002000u
  #define _DMA_SECCTL_RSYNCCLR_SHIFT    0x0000000Du
  #define  DMA_SECCTL_RSYNCCLR_DEFAULT  0x00000000u
  #define  DMA_SECCTL_RSYNCCLR_OF(x)    _VALUEOF(x)
  #define  DMA_SECCTL_RSYNCCLR_NOTHING  0x00000000u
  #define  DMA_SECCTL_RSYNCCLR_CLEAR    0x00000001u

  #define _DMA_SECCTL_RSYNCSTAT_MASK    0x00001000u
  #define _DMA_SECCTL_RSYNCSTAT_SHIFT   0x0000000Cu
  #define  DMA_SECCTL_RSYNCSTAT_DEFAULT 0x00000000u
  #define  DMA_SECCTL_RSYNCSTAT_OF(x)   _VALUEOF(x)
  #define  DMA_SECCTL_RSYNCSTAT_CLEAR   0x00000000u
  #define  DMA_SECCTL_RSYNCSTAT_SET     0x00000001u

  #define _DMA_SECCTL_WDROPIE_MASK      0x00000800u
  #define _DMA_SECCTL_WDROPIE_SHIFT     0x0000000Bu
  #define  DMA_SECCTL_WDROPIE_DEFAULT   0x00000000u
  #define  DMA_SECCTL_WDROPIE_OF(x)     _VALUEOF(x)
  #define  DMA_SECCTL_WDROPIE_DISABLE   0x00000000u
  #define  DMA_SECCTL_WDROPIE_ENABLE    0x00000001u

  #define _DMA_SECCTL_WDROPCOND_MASK    0x00000400u
  #define _DMA_SECCTL_WDROPCOND_SHIFT   0x0000000Au
  #define  DMA_SECCTL_WDROPCOND_DEFAULT 0x00000000u
  #define  DMA_SECCTL_WDROPCOND_OF(x)   _VALUEOF(x)
  #define  DMA_SECCTL_WDROPCOND_CLEAR   0x00000000u
  #define  DMA_SECCTL_WDROPCOND_SET     0x00000001u

  #define _DMA_SECCTL_RDROPIE_MASK      0x00000200u
  #define _DMA_SECCTL_RDROPIE_SHIFT     0x00000009u
  #define  DMA_SECCTL_RDROPIE_DEFAULT   0x00000000u
  #define  DMA_SECCTL_RDROPIE_OF(x)     _VALUEOF(x)
  #define  DMA_SECCTL_RDROPIE_DISABLE   0x00000000u
  #define  DMA_SECCTL_RDROPIE_ENABLE    0x00000001u

  #define _DMA_SECCTL_RDROPCOND_MASK    0x00000100u
  #define _DMA_SECCTL_RDROPCOND_SHIFT   0x00000008u
  #define  DMA_SECCTL_RDROPCOND_DEFAULT 0x00000000u
  #define  DMA_SECCTL_RDROPCOND_OF(x)   _VALUEOF(x)
  #define  DMA_SECCTL_RDROPCOND_CLEAR   0x00000000u
  #define  DMA_SECCTL_RDROPCOND_SET     0x00000001u

  #define _DMA_SECCTL_BLOCKIE_MASK      0x00000080u
  #define _DMA_SECCTL_BLOCKIE_SHIFT     0x00000007u
  #define  DMA_SECCTL_BLOCKIE_DEFAULT   0x00000001u
  #define  DMA_SECCTL_BLOCKIE_OF(x)     _VALUEOF(x)
  #define  DMA_SECCTL_BLOCKIE_DISABLE   0x00000000u
  #define  DMA_SECCTL_BLOCKIE_ENABLE    0x00000001u

  #define _DMA_SECCTL_BLOCKCOND_MASK    0x00000040u
  #define _DMA_SECCTL_BLOCKCOND_SHIFT   0x00000006u
  #define  DMA_SECCTL_BLOCKCOND_DEFAULT 0x00000000u
  #define  DMA_SECCTL_BLOCKCOND_OF(x)   _VALUEOF(x)
  #define  DMA_SECCTL_BLOCKCOND_CLEAR   0x00000000u
  #define  DMA_SECCTL_BLOCKCOND_SET     0x00000001u

  #define _DMA_SECCTL_LASTIE_MASK       0x00000020u
  #define _DMA_SECCTL_LASTIE_SHIFT      0x00000005u
  #define  DMA_SECCTL_LASTIE_DEFAULT    0x00000000u
  #define  DMA_SECCTL_LASTIE_OF(x)      _VALUEOF(x)
  #define  DMA_SECCTL_LASTIE_DISABLE    0x00000000u
  #define  DMA_SECCTL_LASTIE_ENABLE     0x00000001u

  #define _DMA_SECCTL_LASTCOND_MASK     0x00000010u
  #define _DMA_SECCTL_LASTCOND_SHIFT    0x00000004u
  #define  DMA_SECCTL_LASTCOND_DEFAULT  0x00000000u
  #define  DMA_SECCTL_LASTCOND_OF(x)    _VALUEOF(x)
  #define  DMA_SECCTL_LASTCOND_CLEAR    0x00000000u
  #define  DMA_SECCTL_LASTCOND_SET      0x00000001u

  #define _DMA_SECCTL_FRAMEIE_MASK      0x00000008u
  #define _DMA_SECCTL_FRAMEIE_SHIFT     0x00000003u
  #define  DMA_SECCTL_FRAMEIE_DEFAULT   0x00000000u
  #define  DMA_SECCTL_FRAMEIE_OF(x)     _VALUEOF(x)
  #define  DMA_SECCTL_FRAMEIE_DISABLE   0x00000000u
  #define  DMA_SECCTL_FRAMEIE_ENABLE    0x00000001u

  #define _DMA_SECCTL_FRAMECOND_MASK    0x00000004u
  #define _DMA_SECCTL_FRAMECOND_SHIFT   0x00000002u
  #define  DMA_SECCTL_FRAMECOND_DEFAULT 0x00000000u
  #define  DMA_SECCTL_FRAMECOND_OF(x)   _VALUEOF(x)
  #define  DMA_SECCTL_FRAMECOND_CLEAR   0x00000000u
  #define  DMA_SECCTL_FRAMECOND_SET     0x00000001u

  #define _DMA_SECCTL_SXIE_MASK         0x00000002u
  #define _DMA_SECCTL_SXIE_SHIFT        0x00000001u
  #define  DMA_SECCTL_SXIE_DEFAULT      0x00000000u
  #define  DMA_SECCTL_SXIE_OF(x)        _VALUEOF(x)
  #define  DMA_SECCTL_SXIE_DISABLE      0x00000000u
  #define  DMA_SECCTL_SXIE_ENABLE       0x00000001u

  #define _DMA_SECCTL_SXCOND_MASK       0x00000001u
  #define _DMA_SECCTL_SXCOND_SHIFT      0x00000000u
  #define  DMA_SECCTL_SXCOND_DEFAULT    0x00000000u
  #define  DMA_SECCTL_SXCOND_OF(x)      _VALUEOF(x)
  #define  DMA_SECCTL_SXCOND_CLEAR      0x00000000u
  #define  DMA_SECCTL_SXCOND_SET        0x00000001u

  #define  DMA_SECCTL_OF(x)             _VALUEOF(x)

#if (_DMA_COND1)
  #define DMA_SECCTL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(DMA,SECCTL,WSPOL)\
    |_PER_FDEFAULT(DMA,SECCTL,RSPOL)\
    |_PER_FDEFAULT(DMA,SECCTL,FSIG)\
    |_PER_FDEFAULT(DMA,SECCTL,DMACEN)\
    |_PER_FDEFAULT(DMA,SECCTL,WSYNCCLR)\
    |_PER_FDEFAULT(DMA,SECCTL,WSYNCSTAT)\
    |_PER_FDEFAULT(DMA,SECCTL,RSYNCCLR)\
    |_PER_FDEFAULT(DMA,SECCTL,RSYNCSTAT)\
    |_PER_FDEFAULT(DMA,SECCTL,WDROPIE)\
    |_PER_FDEFAULT(DMA,SECCTL,WDROPCOND)\
    |_PER_FDEFAULT(DMA,SECCTL,RDROPIE)\
    |_PER_FDEFAULT(DMA,SECCTL,RDROPCOND)\
    |_PER_FDEFAULT(DMA,SECCTL,BLOCKIE)\
    |_PER_FDEFAULT(DMA,SECCTL,BLOCKCOND)\
    |_PER_FDEFAULT(DMA,SECCTL,LASTIE)\
    |_PER_FDEFAULT(DMA,SECCTL,LASTCOND)\
    |_PER_FDEFAULT(DMA,SECCTL,FRAMEIE)\
    |_PER_FDEFAULT(DMA,SECCTL,FRAMECOND)\
    |_PER_FDEFAULT(DMA,SECCTL,SXIE)\
    |_PER_FDEFAULT(DMA,SECCTL,SXCOND)\
  )

  #define DMA_SECCTL_RMK(wspol,rspol,fsig,dmacen,wsyncclr,wsyncstat,rsyncclr,\
    rsyncstat,wdropie,wdropcond,rdropie,rdropcond,blockie,blockcond,\
    lastie,lastcond,frameie,framecond,sxie,sxcond) (Uint32)( \
     _PER_FMK(DMA,SECCTL,WSPOL,wspol)\
    |_PER_FMK(DMA,SECCTL,RSPOL,rspol)\
    |_PER_FMK(DMA,SECCTL,FSIG,fsig)\
    |_PER_FMK(DMA,SECCTL,DMACEN,dmacen)\
    |_PER_FMK(DMA,SECCTL,WSYNCCLR,wsyncclr)\
    |_PER_FMK(DMA,SECCTL,WSYNCSTAT,wsyncstat)\
    |_PER_FMK(DMA,SECCTL,RSYNCCLR,rsyncclr)\
    |_PER_FMK(DMA,SECCTL,RSYNCSTAT,rsyncstat)\
    |_PER_FMK(DMA,SECCTL,WDROPIE,wdropie)\
    |_PER_FMK(DMA,SECCTL,WDROPCOND,wdropcond)\
    |_PER_FMK(DMA,SECCTL,RDROPIE,rdropie)\
    |_PER_FMK(DMA,SECCTL,RDROPCOND,rdropcond)\
    |_PER_FMK(DMA,SECCTL,BLOCKIE,blockie)\
    |_PER_FMK(DMA,SECCTL,BLOCKCOND,blockcond)\
    |_PER_FMK(DMA,SECCTL,LASTIE,lastie)\
    |_PER_FMK(DMA,SECCTL,LASTCOND,lastcond)\
    |_PER_FMK(DMA,SECCTL,FRAMEIE,frameie)\
    |_PER_FMK(DMA,SECCTL,FRAMECOND,framecond)\
    |_PER_FMK(DMA,SECCTL,SXIE,sxie)\
    |_PER_FMK(DMA,SECCTL,SXCOND,sxcond)\
  )
#endif

#if (!_DMA_COND1)
  #define DMA_SECCTL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(DMA,SECCTL,DMACEN)\
    |_PER_FDEFAULT(DMA,SECCTL,WSYNCCLR)\
    |_PER_FDEFAULT(DMA,SECCTL,WSYNCSTAT)\
    |_PER_FDEFAULT(DMA,SECCTL,RSYNCCLR)\
    |_PER_FDEFAULT(DMA,SECCTL,RSYNCSTAT)\
    |_PER_FDEFAULT(DMA,SECCTL,WDROPIE)\
    |_PER_FDEFAULT(DMA,SECCTL,WDROPCOND)\
    |_PER_FDEFAULT(DMA,SECCTL,RDROPIE)\
    |_PER_FDEFAULT(DMA,SECCTL,RDROPCOND)\
    |_PER_FDEFAULT(DMA,SECCTL,BLOCKIE)\
    |_PER_FDEFAULT(DMA,SECCTL,BLOCKCOND)\
    |_PER_FDEFAULT(DMA,SECCTL,LASTIE)\
    |_PER_FDEFAULT(DMA,SECCTL,LASTCOND)\
    |_PER_FDEFAULT(DMA,SECCTL,FRAMEIE)\
    |_PER_FDEFAULT(DMA,SECCTL,FRAMECOND)\
    |_PER_FDEFAULT(DMA,SECCTL,SXIE)\
    |_PER_FDEFAULT(DMA,SECCTL,SXCOND)\
  )

  #define DMA_SECCTL_RMK(dmacen,wsyncclr,wsyncstat,rsyncclr,\
    rsyncstat,wdropie,wdropcond,rdropie,rdropcond,blockie,blockcond,\
    lastie,lastcond,frameie,framecond,sxie,sxcond) (Uint32)( \
     _PER_FMK(DMA,SECCTL,DMACEN,dmacen)\
    |_PER_FMK(DMA,SECCTL,WSYNCCLR,wsyncclr)\
    |_PER_FMK(DMA,SECCTL,WSYNCSTAT,wsyncstat)\
    |_PER_FMK(DMA,SECCTL,RSYNCCLR,rsyncclr)\
    |_PER_FMK(DMA,SECCTL,RSYNCSTAT,rsyncstat)\
    |_PER_FMK(DMA,SECCTL,WDROPIE,wdropie)\
    |_PER_FMK(DMA,SECCTL,WDROPCOND,wdropcond)\
    |_PER_FMK(DMA,SECCTL,RDROPIE,rdropie)\
    |_PER_FMK(DMA,SECCTL,RDROPCOND,rdropcond)\
    |_PER_FMK(DMA,SECCTL,BLOCKIE,blockie)\
    |_PER_FMK(DMA,SECCTL,BLOCKCOND,blockcond)\
    |_PER_FMK(DMA,SECCTL,LASTIE,lastie)\
    |_PER_FMK(DMA,SECCTL,LASTCOND,lastcond)\
    |_PER_FMK(DMA,SECCTL,FRAMEIE,frameie)\
    |_PER_FMK(DMA,SECCTL,FRAMECOND,framecond)\
    |_PER_FMK(DMA,SECCTL,SXIE,sxie)\
    |_PER_FMK(DMA,SECCTL,SXCOND,sxcond)\
  )
#endif

  #define _DMA_SECCTL_COND_MASK (\
     _DMA_SECCTL_WDROPCOND_MASK\
    |_DMA_SECCTL_RDROPCOND_MASK\
    |_DMA_SECCTL_BLOCKCOND_MASK\
    |_DMA_SECCTL_LASTCOND_MASK\
    |_DMA_SECCTL_FRAMECOND_MASK\
    |_DMA_SECCTL_SXCOND_MASK\
  )

  #define _DMA_SECCTL_IE_MASK (\
     _DMA_SECCTL_WDROPIE_MASK\
    |_DMA_SECCTL_RDROPIE_MASK\
    |_DMA_SECCTL_BLOCKIE_MASK\
    |_DMA_SECCTL_LASTIE_MASK\
    |_DMA_SECCTL_FRAMEIE_MASK\
    |_DMA_SECCTL_SXIE_MASK\
  )

  #define _DMA_SECCTL_STAT_MASK (\
     _DMA_SECCTL_WSYNCSTAT_MASK\
    |_DMA_SECCTL_RSYNCSTAT_MASK\
  )

  #define _DMA_SECCTL_CLR_MASK (\
     _DMA_SECCTL_WSYNCCLR_MASK\
    |_DMA_SECCTL_RSYNCCLR_MASK\
  )

  #define _DMA_SECCTL_FGET(N,FIELD)\
    _PER_FGET(_DMA_SECCTL##N##_ADDR,DMA,SECCTL,##FIELD)

  #define _DMA_SECCTL_FSET(N,FIELD,field)\
    _PER_RAOI(_DMA_SECCTL##N##_ADDR,DMA,SECCTL,\
      (0xFFFF0AAA&~_DMA_SECCTL_##FIELD##_MASK),\
      (0x00000555&~_DMA_SECCTL_##FIELD##_MASK)\
      |_PER_FMK(DMA,SECCTL,##FIELD,field),\
      0x00000000\
    )

  #define _DMA_SECCTL_FSETS(N,FIELD,SYM)\
    _PER_RAOI(_DMA_SECCTL##N##_ADDR,DMA,SECCTL,\
      (0xFFFF0AAA&~_DMA_SECCTL_##FIELD##_MASK),\
      (0x00000555&~_DMA_SECCTL_##FIELD##_MASK)\
      |_PER_FMKS(DMA,SECCTL,##FIELD,##SYM),\
      0x00000000\
    )

  #define _DMA_SECCTL0_FGET(FIELD) _DMA_SECCTL_FGET(0,##FIELD)
  #define _DMA_SECCTL1_FGET(FIELD) _DMA_SECCTL_FGET(1,##FIELD)
  #define _DMA_SECCTL2_FGET(FIELD) _DMA_SECCTL_FGET(2,##FIELD)
  #define _DMA_SECCTL3_FGET(FIELD) _DMA_SECCTL_FGET(3,##FIELD)

  #define _DMA_SECCTL0_FSET(FIELD,f) _DMA_SECCTL_FSET(0,##FIELD,f)
  #define _DMA_SECCTL1_FSET(FIELD,f) _DMA_SECCTL_FSET(1,##FIELD,f)
  #define _DMA_SECCTL2_FSET(FIELD,f) _DMA_SECCTL_FSET(2,##FIELD,f)
  #define _DMA_SECCTL3_FSET(FIELD,f) _DMA_SECCTL_FSET(3,##FIELD,f)

  #define _DMA_SECCTL0_FSETS(FIELD,SYM) _DMA_SECCTL_FSETS(0,##FIELD,##SYM)
  #define _DMA_SECCTL1_FSETS(FIELD,SYM) _DMA_SECCTL_FSETS(1,##FIELD,##SYM)
  #define _DMA_SECCTL2_FSETS(FIELD,SYM) _DMA_SECCTL_FSETS(2,##FIELD,##SYM)
  #define _DMA_SECCTL3_FSETS(FIELD,SYM) _DMA_SECCTL_FSETS(3,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  S R C            |
* |___________________|
*
* SRC0     - channel src address register 0
* SRC1     - channel src address register 1
* SRC2     - channel src address register 2
* SRC3     - channel src address register 3
*
* FIELDS (msb -> lsb)
* (rw) SRC
*
\******************************************************************************/
  #define _DMA_SRC_OFFSET               4

  #define _DMA_SRC0_ADDR                0x01840010u
  #define _DMA_SRC1_ADDR                0x01840050u
  #define _DMA_SRC2_ADDR                0x01840014u
  #define _DMA_SRC3_ADDR                0x01840054u

  #define _DMA_SRC_SRC_MASK             0xFFFFFFFFu
  #define _DMA_SRC_SRC_SHIFT            0x00000000u
  #define  DMA_SRC_SRC_DEFAULT          0x00000000u
  #define  DMA_SRC_SRC_OF(x)            _VALUEOF(x)

  #define  DMA_SRC_OF(x)                _VALUEOF(x)

  #define DMA_SRC_DEFAULT (Uint32)( \
     _PER_FDEFAULT(DMA,SRC,SRC) \
  )

  #define DMA_SRC_RMK(src) (Uint32)( \
     _PER_FMK(DMA,SRC,SRC,src) \
  )

  #define _DMA_SRC_FGET(N,FIELD)\
    _PER_FGET(_DMA_SRC##N##_ADDR,DMA,SRC,##FIELD)

  #define _DMA_SRC_FSET(N,FIELD,field)\
    _PER_FSET(_DMA_SRC##N##_ADDR,DMA,SRC,##FIELD,field)

  #define _DMA_SRC_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_DMA_SRC##N##_ADDR,DMA,SRC,##FIELD,##SYM)

  #define _DMA_SRC0_FGET(FIELD) _DMA_SRC_FGET(0,##FIELD)
  #define _DMA_SRC1_FGET(FIELD) _DMA_SRC_FGET(1,##FIELD)
  #define _DMA_SRC2_FGET(FIELD) _DMA_SRC_FGET(2,##FIELD)
  #define _DMA_SRC3_FGET(FIELD) _DMA_SRC_FGET(3,##FIELD)

  #define _DMA_SRC0_FSET(FIELD,f) _DMA_SRC_FSET(0,##FIELD,f)
  #define _DMA_SRC1_FSET(FIELD,f) _DMA_SRC_FSET(1,##FIELD,f)
  #define _DMA_SRC2_FSET(FIELD,f) _DMA_SRC_FSET(2,##FIELD,f)
  #define _DMA_SRC3_FSET(FIELD,f) _DMA_SRC_FSET(3,##FIELD,f)

  #define _DMA_SRC0_FSETS(FIELD,SYM) _DMA_SRC_FSETS(0,##FIELD,##SYM)
  #define _DMA_SRC1_FSETS(FIELD,SYM) _DMA_SRC_FSETS(1,##FIELD,##SYM)
  #define _DMA_SRC2_FSETS(FIELD,SYM) _DMA_SRC_FSETS(2,##FIELD,##SYM)
  #define _DMA_SRC3_FSETS(FIELD,SYM) _DMA_SRC_FSETS(3,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  D S T            |
* |___________________|
*
* DST0     - channel destination address register 0
* DST1     - channel destination address register 1
* DST2     - channel destination address register 2
* DST3     - channel destination address register 3
*
* * - handle based
*
* FIELDS (msb -> lsb)
* (rw) DST
*
\******************************************************************************/
  #define _DMA_DST_OFFSET               6

  #define _DMA_DST0_ADDR                0x01840018u
  #define _DMA_DST1_ADDR                0x01840058u
  #define _DMA_DST2_ADDR                0x0184001Cu
  #define _DMA_DST3_ADDR                0x0184005Cu

  #define _DMA_DST_DST_MASK             0xFFFFFFFFu
  #define _DMA_DST_DST_SHIFT            0x00000000u
  #define  DMA_DST_DST_DEFAULT          0x00000000u
  #define  DMA_DST_DST_OF(x)            _VALUEOF(x)

  #define  DMA_DST_OF(x)                _VALUEOF(x)

  #define DMA_DST_DEFAULT (Uint32)( \
     _PER_FDEFAULT(DMA,DST,DST) \
  )

  #define DMA_DST_RMK(dst) (Uint32)( \
     _PER_FMK(DMA,DST,DST,dst) \
  )

  #define _DMA_DST_FGET(N,FIELD)\
    _PER_FGET(_DMA_DST##N##_ADDR,DMA,DST,##FIELD)

  #define _DMA_DST_FSET(N,FIELD,field)\
    _PER_FSET(_DMA_DST##N##_ADDR,DMA,DST,##FIELD,field)

  #define _DMA_DST_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_DMA_DST##N##_ADDR,DMA,DST,##FIELD,##SYM)

  #define _DMA_DST0_FGET(FIELD) _DMA_DST_FGET(0,##FIELD)
  #define _DMA_DST1_FGET(FIELD) _DMA_DST_FGET(1,##FIELD)
  #define _DMA_DST2_FGET(FIELD) _DMA_DST_FGET(2,##FIELD)
  #define _DMA_DST3_FGET(FIELD) _DMA_DST_FGET(3,##FIELD)

  #define _DMA_DST0_FSET(FIELD,f) _DMA_DST_FSET(0,##FIELD,f)
  #define _DMA_DST1_FSET(FIELD,f) _DMA_DST_FSET(1,##FIELD,f)
  #define _DMA_DST2_FSET(FIELD,f) _DMA_DST_FSET(2,##FIELD,f)
  #define _DMA_DST3_FSET(FIELD,f) _DMA_DST_FSET(3,##FIELD,f)

  #define _DMA_DST0_FSETS(FIELD,SYM) _DMA_DST_FSETS(0,##FIELD,##SYM)
  #define _DMA_DST1_FSETS(FIELD,SYM) _DMA_DST_FSETS(1,##FIELD,##SYM)
  #define _DMA_DST2_FSETS(FIELD,SYM) _DMA_DST_FSETS(2,##FIELD,##SYM)
  #define _DMA_DST3_FSETS(FIELD,SYM) _DMA_DST_FSETS(3,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  X F R C N T      |
* |___________________|
*
* XFRCNT0  - channel transfer count register 0
* XFRCNT1  - channel transfer count register 1
* XFRCNT2  - channel transfer count register 2
* XFRCNT3  - channel transfer count register 3
*
* * - handle based
*
* FIELDS (msb -> lsb)
* (rw) FRMCNT
* (rw) ELECNT
*
\******************************************************************************/
  #define _DMA_XFRCNT_OFFSET            8

  #define _DMA_XFRCNT0_ADDR             0x01840020u
  #define _DMA_XFRCNT1_ADDR             0x01840060u
  #define _DMA_XFRCNT2_ADDR             0x01840024u
  #define _DMA_XFRCNT3_ADDR             0x01840064u

  #define _DMA_XFRCNT_FRMCNT_MASK       0xFFFF0000u
  #define _DMA_XFRCNT_FRMCNT_SHIFT      0x00000010u
  #define  DMA_XFRCNT_FRMCNT_DEFAULT    0x00000000u
  #define  DMA_XFRCNT_FRMCNT_OF(x)      _VALUEOF(x)

  #define _DMA_XFRCNT_ELECNT_MASK       0x0000FFFFu
  #define _DMA_XFRCNT_ELECNT_SHIFT      0x00000000u
  #define  DMA_XFRCNT_ELECNT_DEFAULT    0x00000000u
  #define  DMA_XFRCNT_ELECNT_OF(x)      _VALUEOF(x)

  #define  DMA_XFRCNT_OF(x)             _VALUEOF(x)

  #define DMA_XFRCNT_DEFAULT (Uint32)( \
     _PER_FDEFAULT(DMA,XFRCNT,FRMCNT) \
    |_PER_FDEFAULT(DMA,XFRCNT,ELECNT) \
  )

  #define DMA_XFRCNT_RMK(frmcnt,elecnt) (Uint32)( \
     _PER_FMK(DMA,XFRCNT,FRMCNT,frmcnt) \
    |_PER_FMK(DMA,XFRCNT,ELECNT,elecnt) \
  )

  #define _DMA_XFRCNT_FGET(N,FIELD)\
    _PER_FGET(_DMA_XFRCNT##N##_ADDR,DMA,XFRCNT,##FIELD)

  #define _DMA_XFRCNT_FSET(N,FIELD,field)\
    _PER_FSET(_DMA_XFRCNT##N##_ADDR,DMA,XFRCNT,##FIELD,field)

  #define _DMA_XFRCNT_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_DMA_XFRCNT##N##_ADDR,DMA,XFRCNT,##FIELD,##SYM)

  #define _DMA_XFRCNT0_FGET(FIELD) _DMA_XFRCNT_FGET(0,##FIELD)
  #define _DMA_XFRCNT1_FGET(FIELD) _DMA_XFRCNT_FGET(1,##FIELD)
  #define _DMA_XFRCNT2_FGET(FIELD) _DMA_XFRCNT_FGET(2,##FIELD)
  #define _DMA_XFRCNT3_FGET(FIELD) _DMA_XFRCNT_FGET(3,##FIELD)

  #define _DMA_XFRCNT0_FSET(FIELD,f) _DMA_XFRCNT_FSET(0,##FIELD,f)
  #define _DMA_XFRCNT1_FSET(FIELD,f) _DMA_XFRCNT_FSET(1,##FIELD,f)
  #define _DMA_XFRCNT2_FSET(FIELD,f) _DMA_XFRCNT_FSET(2,##FIELD,f)
  #define _DMA_XFRCNT3_FSET(FIELD,f) _DMA_XFRCNT_FSET(3,##FIELD,f)

  #define _DMA_XFRCNT0_FSETS(FIELD,SYM) _DMA_XFRCNT_FSETS(0,##FIELD,##SYM)
  #define _DMA_XFRCNT1_FSETS(FIELD,SYM) _DMA_XFRCNT_FSETS(1,##FIELD,##SYM)
  #define _DMA_XFRCNT2_FSETS(FIELD,SYM) _DMA_XFRCNT_FSETS(2,##FIELD,##SYM)
  #define _DMA_XFRCNT3_FSETS(FIELD,SYM) _DMA_XFRCNT_FSETS(3,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  G B L C N T      |
* |___________________|
*
* GBLCNTA  - global count reload register A
* GBLCNTB  - global count reload register B
*
* FIELDS (msb -> lsb)
* (rw) FRMCNT
* (rw) ELECNT
*
\******************************************************************************/
  #define _DMA_GBLCNTA_ADDR             0x01840028u
  #define _DMA_GBLCNTB_ADDR             0x0184002Cu

  #define _DMA_GBLCNT_FRMCNT_MASK       0xFFFF0000u
  #define _DMA_GBLCNT_FRMCNT_SHIFT      0x00000010u
  #define  DMA_GBLCNT_FRMCNT_DEFAULT    0x00000000u
  #define  DMA_GBLCNT_FRMCNT_OF(x)      _VALUEOF(x)

  #define _DMA_GBLCNT_ELECNT_MASK       0x0000FFFFu
  #define _DMA_GBLCNT_ELECNT_SHIFT      0x00000000u
  #define  DMA_GBLCNT_ELECNT_DEFAULT    0x00000000u
  #define  DMA_GBLCNT_ELECNT_OF(x)      _VALUEOF(x)

  #define  DMA_GBLCNT_OF(x)             _VALUEOF(x)

  #define DMA_GBLCNT_DEFAULT (Uint32)( \
     _PER_FDEFAULT(DMA,GBLCNT,FRMCNT) \
    |_PER_FDEFAULT(DMA,GBLCNT,ELECNT) \
  )

  #define DMA_GBLCNT_RMK(frmcnt,elecnt) (Uint32)( \
     _PER_FMK(DMA,GBLCNT,FRMCNT,frmcnt) \
    |_PER_FMK(DMA,GBLCNT,ELECNT,elecnt) \
  )

  #define _DMA_GBLCNT_FGET(N,FIELD)\
    _PER_FGET(_DMA_GBLCNT##N##_ADDR,DMA,GBLCNT,##FIELD)

  #define _DMA_GBLCNT_FSET(N,FIELD,field)\
    _PER_FSET(_DMA_GBLCNT##N##_ADDR,DMA,GBLCNT,##FIELD,field)

  #define _DMA_GBLCNT_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_DMA_GBLCNT##N##_ADDR,DMA,GBLCNT,##FIELD,##SYM)

  #define _DMA_GBLCNTA_FGET(FIELD) _DMA_GBLCNT_FGET(A,FIELD)
  #define _DMA_GBLCNTB_FGET(FIELD) _DMA_GBLCNT_FGET(B,FIELD)

  #define _DMA_GBLCNTA_FSET(FIELD,f) _DMA_GBLCNT_FSET(A,FIELD,f)
  #define _DMA_GBLCNTB_FSET(FIELD,f) _DMA_GBLCNT_FSET(B,FIELD,f)

  #define _DMA_GBLCNTA_FSETS(FIELD,SYM) _DMA_GBLCNT_FSETS(A,FIELD,SYM)
  #define _DMA_GBLCNTB_FSETS(FIELD,SYM) _DMA_GBLCNT_FSETS(B,FIELD,SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  G B L I D X      |
* |___________________|
*
* GBLIDXA  - global index register A
* GBLIDXB  - global index register B
*
* FIELDS (msb -> lsb)
* (rw) FRMIDX
* (rw) ELEIDX
*
\******************************************************************************/
  #define _DMA_GBLIDXA_ADDR             0x01840030u
  #define _DMA_GBLIDXB_ADDR             0x01840034u

  #define _DMA_GBLIDX_FRMIDX_MASK       0xFFFF0000u
  #define _DMA_GBLIDX_FRMIDX_SHIFT      0x00000010u
  #define  DMA_GBLIDX_FRMIDX_DEFAULT    0x00000000u
  #define  DMA_GBLIDX_FRMIDX_OF(x)      _VALUEOF(x)

  #define _DMA_GBLIDX_ELEIDX_MASK       0x0000FFFFu
  #define _DMA_GBLIDX_ELEIDX_SHIFT      0x00000000u
  #define  DMA_GBLIDX_ELEIDX_DEFAULT    0x00000000u
  #define  DMA_GBLIDX_ELEIDX_OF(x)      _VALUEOF(x)

  #define  DMA_GBLIDX_OF(x)             _VALUEOF(x)

  #define DMA_GBLIDX_DEFAULT (Uint32)( \
     _PER_FDEFAULT(DMA,GBLIDX,FRMIDX) \
    |_PER_FDEFAULT(DMA,GBLIDX,ELEIDX) \
  )

  #define DMA_GBLIDX_RMK(frmidx,eleidx) (Uint32)( \
     _PER_FMK(DMA,GBLIDX,FRMIDX,frmidx) \
    |_PER_FMK(DMA,GBLIDX,ELEIDX,eleidx) \
  )

  #define _DMA_GBLIDX_FGET(N,FIELD)\
    _PER_FGET(_DMA_GBLIDX##N##_ADDR,DMA,GBLIDX,##FIELD)

  #define _DMA_GBLIDX_FSET(N,FIELD,field)\
    _PER_FSET(_DMA_GBLIDX##N##_ADDR,DMA,GBLIDX,##FIELD,field)

  #define _DMA_GBLIDX_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_DMA_GBLIDX##N##_ADDR,DMA,GBLIDX,##FIELD,##SYM)

  #define _DMA_GBLIDXA_FGET(FIELD) _DMA_GBLIDX_FGET(A,FIELD)
  #define _DMA_GBLIDXB_FGET(FIELD) _DMA_GBLIDX_FGET(B,FIELD)

  #define _DMA_GBLIDXA_FSET(FIELD,f) _DMA_GBLIDX_FSET(A,FIELD,f)
  #define _DMA_GBLIDXB_FSET(FIELD,f) _DMA_GBLIDX_FSET(B,FIELD,f)

  #define _DMA_GBLIDXA_FSETS(FIELD,SYM) _DMA_GBLIDX_FSETS(A,FIELD,SYM)
  #define _DMA_GBLIDXB_FSETS(FIELD,SYM) _DMA_GBLIDX_FSETS(B,FIELD,SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  G B L A D D R    |
* |___________________|
*
* GBLADDRA - global address reload register A
* GBLADDRB - global address reload register B
* GBLADDRC - global address reload register C
* GBLADDRD - global address reload register D
*
* FIELDS (msb -> lsb)
* (rw) GBLADDR
*
\******************************************************************************/
  #define _DMA_GBLADDRA_ADDR              0x01840038u
  #define _DMA_GBLADDRB_ADDR              0x0184003Cu
  #define _DMA_GBLADDRC_ADDR              0x01840068u
  #define _DMA_GBLADDRD_ADDR              0x0184006Cu

  #define _DMA_GBLADDR_GBLADDR_MASK       0xFFFFFFFFu
  #define _DMA_GBLADDR_GBLADDR_SHIFT      0x00000000u
  #define  DMA_GBLADDR_GBLADDR_DEFAULT    0x00000000u
  #define  DMA_GBLADDR_GBLADDR_OF(x)      _VALUEOF(x)

  #define  DMA_GBLADDR_OF(x)              _VALUEOF(x)

  #define DMA_GBLADDR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(DMA,GBLADDR,GBLADDR) \
  )

  #define DMA_GBLADDR_RMK(gbladdr) (Uint32)( \
     _PER_FMK(DMA,GBLADDR,GBLADDR,gbladdr) \
  )

  #define _DMA_GBLADDR_FGET(N,FIELD)\
    _PER_FGET(_DMA_GBLADDR##N##_ADDR,DMA,GBLADDR,##FIELD)

  #define _DMA_GBLADDR_FSET(N,FIELD,field)\
    _PER_FSET(_DMA_GBLADDR##N##_ADDR,DMA,GBLADDR,##FIELD,field)

  #define _DMA_GBLADDR_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_DMA_GBLADDR##N##_ADDR,DMA,GBLADDR,##FIELD,##SYM)

  #define _DMA_GBLADDRA_FGET(FIELD) _DMA_GBLADDR_FGET(A,FIELD)
  #define _DMA_GBLADDRB_FGET(FIELD) _DMA_GBLADDR_FGET(B,FIELD)
  #define _DMA_GBLADDRC_FGET(FIELD) _DMA_GBLADDR_FGET(C,FIELD)
  #define _DMA_GBLADDRD_FGET(FIELD) _DMA_GBLADDR_FGET(D,FIELD)

  #define _DMA_GBLADDRA_FSET(FIELD,f) _DMA_GBLADDR_FSET(A,FIELD,f)
  #define _DMA_GBLADDRB_FSET(FIELD,f) _DMA_GBLADDR_FSET(B,FIELD,f)
  #define _DMA_GBLADDRC_FSET(FIELD,f) _DMA_GBLADDR_FSET(C,FIELD,f)
  #define _DMA_GBLADDRD_FSET(FIELD,f) _DMA_GBLADDR_FSET(D,FIELD,f)

  #define _DMA_GBLADDRA_FSETS(FIELD,SYM) _DMA_GBLADDR_FSETS(A,FIELD,SYM)
  #define _DMA_GBLADDRB_FSETS(FIELD,SYM) _DMA_GBLADDR_FSETS(B,FIELD,SYM)
  #define _DMA_GBLADDRC_FSETS(FIELD,SYM) _DMA_GBLADDR_FSETS(C,FIELD,SYM)
  #define _DMA_GBLADDRD_FSETS(FIELD,SYM) _DMA_GBLADDR_FSETS(D,FIELD,SYM)


/*----------------------------------------------------------------------------*/

#endif /* DMA_SUPPORT */
#endif /* _CSL_DMAHAL_H_ */
/******************************************************************************\
* End of csl_dmahal.h
\******************************************************************************/
