/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_timerhal.h
* DATE CREATED.. 08/14/2000
* LAST MODIFIED. 08/02/2004 - Adding support for C6418
*                09/30/2003  Added SPND field description macros for CTL reg.
*                10/03/2000
*------------------------------------------------------------------------------
* REGISTERS
*
* CTL0  - timer control register 0
* CTL1  - timer control register 1
* CTL2  - timer control register 2 (1)
* PRD0  - timer period register 0
* PRD1  - timer period register 1
* PRD2  - timer period register 2 (1)
* CNT0  - timer count register 0
* CNT1  - timer count register 1
* CNT2  - timer count register 2 (1)
*
* (1) - only supported on C64x devices
*
\******************************************************************************/
#ifndef _CSL_TIMERHAL_H_
#define _CSL_TIMERHAL_H_

#include <csl_stdinc.h>
#include <csl_chip.h>

#if (TIMER_SUPPORT)
/******************************************************************************\
* MISC section
\******************************************************************************/

#if (CHIP_6414 | CHIP_6415 | CHIP_6416 | CHIP_DM642 | CHIP_DM641 | CHIP_DM640 | CHIP_6412 | CHIP_6411 | CHIP_6410 | CHIP_6413 | CHIP_6418)
  #define TIMER_DEVICE_CNT  3
  #define _TIMER_BASE_DEV0  0x01940000u
  #define _TIMER_BASE_DEV1  0x01980000u
  #define _TIMER_BASE_DEV2  0x01AC0000u
#else
  #define TIMER_DEVICE_CNT  2
  #define _TIMER_BASE_DEV0  0x01940000u
  #define _TIMER_BASE_DEV1  0x01980000u
#endif


/******************************************************************************\
* module level register/field access macros
\******************************************************************************/

  /* ----------------- */
  /* FIELD MAKE MACROS */
  /* ----------------- */

  #define TIMER_FMK(REG,FIELD,x)\
    _PER_FMK(TIMER,##REG,##FIELD,x)

  #define TIMER_FMKS(REG,FIELD,SYM)\
    _PER_FMKS(TIMER,##REG,##FIELD,##SYM)


  /* -------------------------------- */
  /* RAW REGISTER/FIELD ACCESS MACROS */
  /* -------------------------------- */

  #define TIMER_ADDR(REG)\
    _TIMER_##REG##_ADDR

  #define TIMER_RGET(REG)\
    _PER_RGET(_TIMER_##REG##_ADDR,TIMER,##REG)

  #define TIMER_RSET(REG,x)\
    _PER_RSET(_TIMER_##REG##_ADDR,TIMER,##REG,x)

  #define TIMER_FGET(REG,FIELD)\
    _TIMER_##REG##_FGET(##FIELD)

  #define TIMER_FSET(REG,FIELD,x)\
    _TIMER_##REG##_FSET(##FIELD,##x)

  #define TIMER_FSETS(REG,FIELD,SYM)\
    _TIMER_##REG##_FSETS(##FIELD,##SYM)


  /* ------------------------------------------ */
  /* ADDRESS BASED REGISTER/FIELD ACCESS MACROS */
  /* ------------------------------------------ */

  #define TIMER_RGETA(addr,REG)\
    _PER_RGET(addr,TIMER,##REG)

  #define TIMER_RSETA(addr,REG,x)\
    _PER_RSET(addr,TIMER,##REG,x)

  #define TIMER_FGETA(addr,REG,FIELD)\
    _PER_FGET(addr,TIMER,##REG,##FIELD)

  #define TIMER_FSETA(addr,REG,FIELD,x)\
    _PER_FSET(addr,TIMER,##REG,##FIELD,x)

  #define TIMER_FSETSA(addr,REG,FIELD,SYM)\
    _PER_FSETS(addr,TIMER,##REG,##FIELD,##SYM)


  /* ----------------------------------------- */
  /* HANDLE BASED REGISTER/FIELD ACCESS MACROS */
  /* ----------------------------------------- */

  #define TIMER_ADDRH(h,REG)\
    (Uint32)(&((h)->baseAddr[_TIMER_##REG##_OFFSET]))

  #define TIMER_RGETH(h,REG)\
    TIMER_RGETA(TIMER_ADDRH(h,##REG),##REG)


  #define TIMER_RSETH(h,REG,x)\
    TIMER_RSETA(TIMER_ADDRH(h,##REG),##REG,x)


  #define TIMER_FGETH(h,REG,FIELD)\
    TIMER_FGETA(TIMER_ADDRH(h,##REG),##REG,##FIELD)


  #define TIMER_FSETH(h,REG,FIELD,x)\
    TIMER_FSETA(TIMER_ADDRH(h,##REG),##REG,##FIELD,x)


  #define TIMER_FSETSH(h,REG,FIELD,SYM)\
    TIMER_FSETSA(TIMER_ADDRH(h,##REG),##REG,##FIELD,##SYM)



/******************************************************************************\
* _____________________
* |                   |
* |  C T L            |
* |___________________|
*
* CTL0  - timer control register 0
* CTL1  - timer control register 1
* CTL2  - timer control register 2 (1)
*
* FIELDS (msb -> lsb)
* (rw) SPND   (1)
* (r)  TSTAT
* (rw) INVINP
* (rw) CLKSRC
* (rw) CP
* (rw) HLD
* (rw) GO
* (rw) PWID
* (r)  DATIN
* (rw) DATOUT
* (rw) INVOUT
* (rw) FUNC
*
* (1) - only supported on C64x devices
\******************************************************************************/
  #define _TIMER_CTL_OFFSET            0

  #define _TIMER_CTL0_ADDR             0x01940000u
  #define _TIMER_CTL1_ADDR             0x01980000u
  #if (TIMER_DEVICE_CNT == 3)
    #define _TIMER_CTL2_ADDR           0x01AC0000u
  #endif

  #if (C64_SUPPORT)	
	#define _TIMER_CTL_SPND_MASK         0x00008000u
	#define _TIMER_CTL_SPND_SHIFT        0x0000000Fu
	#define TIMER_CTL_SPND_DEFAULT       0x00000000u
	#define TIMER_CTL_SPND_OF(x)         _VALUEOF(x)
	#define TIMER_CTL_SPND_EMUSTOP       0x00000001u
	#define TIMER_CTL_SPND_EMURUN        0x00000000u	
  #endif
	
  #define _TIMER_CTL_TSTAT_MASK        0x00000800u
  #define _TIMER_CTL_TSTAT_SHIFT       0x0000000Bu
  #define  TIMER_CTL_TSTAT_DEFAULT     0x00000000u
  #define  TIMER_CTL_TSTAT_OF(x)       _VALUEOF(x)
  #define  TIMER_CTL_TSTAT_0           0x00000000u
  #define  TIMER_CTL_TSTAT_1           0x00000001u

  #define _TIMER_CTL_INVINP_MASK       0x00000400u
  #define _TIMER_CTL_INVINP_SHIFT      0x0000000Au
  #define  TIMER_CTL_INVINP_DEFAULT    0x00000000u
  #define  TIMER_CTL_INVINP_OF(x)      _VALUEOF(x)
  #define  TIMER_CTL_INVINP_NO         0x00000000u
  #define  TIMER_CTL_INVINP_YES        0x00000001u

  #define _TIMER_CTL_CLKSRC_MASK       0x00000200u
  #define _TIMER_CTL_CLKSRC_SHIFT      0x00000009u
  #define  TIMER_CTL_CLKSRC_DEFAULT    0x00000000u
  #define  TIMER_CTL_CLKSRC_OF(x)      _VALUEOF(x)
  #define  TIMER_CTL_CLKSRC_EXTERNAL   0x00000000u
  #if (C64_SUPPORT)
    #define  TIMER_CTL_CLKSRC_CPUOVR8    0x00000001u
  #else
    #define  TIMER_CTL_CLKSRC_CPUOVR4    0x00000001u
  #endif

  #define _TIMER_CTL_CP_MASK           0x00000100u
  #define _TIMER_CTL_CP_SHIFT          0x00000008u
  #define  TIMER_CTL_CP_DEFAULT        0x00000000u
  #define  TIMER_CTL_CP_OF(x)          _VALUEOF(x)
  #define  TIMER_CTL_CP_PULSE          0x00000000u
  #define  TIMER_CTL_CP_CLOCK          0x00000001u

  #define _TIMER_CTL_HLD_MASK          0x00000080u
  #define _TIMER_CTL_HLD_SHIFT         0x00000007u
  #define  TIMER_CTL_HLD_DEFAULT       0x00000000u
  #define  TIMER_CTL_HLD_OF(x)         _VALUEOF(x)
  #define  TIMER_CTL_HLD_YES           0x00000000u
  #define  TIMER_CTL_HLD_NO            0x00000001u

  #define _TIMER_CTL_GO_MASK           0x00000040u
  #define _TIMER_CTL_GO_SHIFT          0x00000006u
  #define  TIMER_CTL_GO_DEFAULT        0x00000000u
  #define  TIMER_CTL_GO_OF(x)          _VALUEOF(x)
  #define  TIMER_CTL_GO_NO             0x00000000u
  #define  TIMER_CTL_GO_YES            0x00000001u

  #define _TIMER_CTL_PWID_MASK         0x00000010u
  #define _TIMER_CTL_PWID_SHIFT        0x00000004u
  #define  TIMER_CTL_PWID_DEFAULT      0x00000000u
  #define  TIMER_CTL_PWID_OF(x)        _VALUEOF(x)
  #define  TIMER_CTL_PWID_ONE          0x00000000u
  #define  TIMER_CTL_PWID_TWO          0x00000001u

  #define _TIMER_CTL_DATIN_MASK        0x00000008u
  #define _TIMER_CTL_DATIN_SHIFT       0x00000003u
  #define  TIMER_CTL_DATIN_DEFAULT     0x00000000u
  #define  TIMER_CTL_DATIN_OF(x)       _VALUEOF(x)
  #define  TIMER_CTL_DATIN_0           0x00000000u
  #define  TIMER_CTL_DATIN_1           0x00000001u

  #define _TIMER_CTL_DATOUT_MASK       0x00000004u
  #define _TIMER_CTL_DATOUT_SHIFT      0x00000002u
  #define  TIMER_CTL_DATOUT_DEFAULT    0x00000000u
  #define  TIMER_CTL_DATOUT_OF(x)      _VALUEOF(x)
  #define  TIMER_CTL_DATOUT_0          0x00000000u
  #define  TIMER_CTL_DATOUT_1          0x00000001u

  #define _TIMER_CTL_INVOUT_MASK       0x00000002u
  #define _TIMER_CTL_INVOUT_SHIFT      0x00000001u
  #define  TIMER_CTL_INVOUT_DEFAULT    0x00000000u
  #define  TIMER_CTL_INVOUT_OF(x)      _VALUEOF(x)
  #define  TIMER_CTL_INVOUT_NO         0x00000000u
  #define  TIMER_CTL_INVOUT_YES        0x00000001u

  #define _TIMER_CTL_FUNC_MASK         0x00000001u
  #define _TIMER_CTL_FUNC_SHIFT        0x00000000u
  #define  TIMER_CTL_FUNC_DEFAULT      0x00000000u
  #define  TIMER_CTL_FUNC_OF(x)        _VALUEOF(x)
  #define  TIMER_CTL_FUNC_GPIO         0x00000000u
  #define  TIMER_CTL_FUNC_TOUT         0x00000001u

  #define  TIMER_CTL_OF(x)             _VALUEOF(x)

  #if (C64_SUPPORT)
	#define TIMER_CTL_DEFAULT (Uint32)( \
		_PER_FDEFAULT(TIMER,CTL,SPND) \
		|_PER_FDEFAULT(TIMER,CTL,TSTAT) \
		|_PER_FDEFAULT(TIMER,CTL,INVINP) \
		|_PER_FDEFAULT(TIMER,CTL,CLKSRC) \
		|_PER_FDEFAULT(TIMER,CTL,CP) \
		|_PER_FDEFAULT(TIMER,CTL,HLD) \
		|_PER_FDEFAULT(TIMER,CTL,GO) \
		|_PER_FDEFAULT(TIMER,CTL,PWID) \
		|_PER_FDEFAULT(TIMER,CTL,DATIN) \
		|_PER_FDEFAULT(TIMER,CTL,DATOUT) \
		|_PER_FDEFAULT(TIMER,CTL,INVOUT) \
		|_PER_FDEFAULT(TIMER,CTL,FUNC) \
	)
  #else
	#define TIMER_CTL_DEFAULT (Uint32)( \
		_PER_FDEFAULT(TIMER,CTL,TSTAT) \
		|_PER_FDEFAULT(TIMER,CTL,INVINP) \
		|_PER_FDEFAULT(TIMER,CTL,CLKSRC) \
		|_PER_FDEFAULT(TIMER,CTL,CP) \
		|_PER_FDEFAULT(TIMER,CTL,HLD) \
		|_PER_FDEFAULT(TIMER,CTL,GO) \
		|_PER_FDEFAULT(TIMER,CTL,PWID) \
		|_PER_FDEFAULT(TIMER,CTL,DATIN) \
		|_PER_FDEFAULT(TIMER,CTL,DATOUT) \
		|_PER_FDEFAULT(TIMER,CTL,INVOUT) \
		|_PER_FDEFAULT(TIMER,CTL,FUNC) \
	)
  #endif
  
  #if (C64_SUPPORT)
	#define TIMER_CTL_RMK(spnd,invinp,clksrc,cp,hld,go,pwid,datout,invout,func) \
		(Uint32)( \
		_PER_FMK(TIMER,CTL,SPND,spnd) \
		|_PER_FMK(TIMER,CTL,INVINP,invinp) \
		|_PER_FMK(TIMER,CTL,CLKSRC,clksrc) \
		|_PER_FMK(TIMER,CTL,CP,cp) \
		|_PER_FMK(TIMER,CTL,HLD,hld) \
		|_PER_FMK(TIMER,CTL,GO,go) \
		|_PER_FMK(TIMER,CTL,PWID,pwid) \
		|_PER_FMK(TIMER,CTL,DATOUT,datout) \
		|_PER_FMK(TIMER,CTL,INVOUT,invout) \
		|_PER_FMK(TIMER,CTL,FUNC,func) \
	)
  #else
	#define TIMER_CTL_RMK(invinp,clksrc,cp,hld,go,pwid,datout,invout,func) \
		(Uint32)( \
		_PER_FMK(TIMER,CTL,INVINP,invinp) \
		|_PER_FMK(TIMER,CTL,CLKSRC,clksrc) \
		|_PER_FMK(TIMER,CTL,CP,cp) \
		|_PER_FMK(TIMER,CTL,HLD,hld) \
		|_PER_FMK(TIMER,CTL,GO,go) \
		|_PER_FMK(TIMER,CTL,PWID,pwid) \
		|_PER_FMK(TIMER,CTL,DATOUT,datout) \
		|_PER_FMK(TIMER,CTL,INVOUT,invout) \
		|_PER_FMK(TIMER,CTL,FUNC,func) \
	)
  #endif
		
		
  #define _TIMER_CTL_FGET(N,FIELD)\
    _PER_FGET(_TIMER_CTL##N##_ADDR,TIMER,CTL,##FIELD)

  #define _TIMER_CTL_FSET(N,FIELD,f)\
    _PER_FSET(_TIMER_CTL##N##_ADDR,TIMER,CTL,##FIELD,f)

  #define _TIMER_CTL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_TIMER_CTL##N##_ADDR,TIMER,CTL,##FIELD,##SYM)

  #define _TIMER_CTL0_FGET(FIELD) _TIMER_CTL_FGET(0,##FIELD)
  #define _TIMER_CTL1_FGET(FIELD) _TIMER_CTL_FGET(1,##FIELD)
  #if  TIMER_DEVICE_CNT == 3
    #define _TIMER_CTL2_FGET(FIELD) _TIMER_CTL_FGET(2,##FIELD)
  #endif

  #define _TIMER_CTL0_FSET(FIELD,f) _TIMER_CTL_FSET(0,##FIELD,f)
  #define _TIMER_CTL1_FSET(FIELD,f) _TIMER_CTL_FSET(1,##FIELD,f)
  #if  TIMER_DEVICE_CNT == 3
    #define _TIMER_CTL2_FSET(FIELD,f) _TIMER_CTL_FSET(2,##FIELD,f)
  #endif

  #define _TIMER_CTL0_FSETS(FIELD,SYM) _TIMER_CTL_FSETS(0,##FIELD,##SYM)
  #define _TIMER_CTL1_FSETS(FIELD,SYM) _TIMER_CTL_FSETS(1,##FIELD,##SYM)
  #if  TIMER_DEVICE_CNT == 3
    #define _TIMER_CTL2_FSETS(FIELD,SYM) _TIMER_CTL_FSETS(2,##FIELD,##SYM)
  #endif


/******************************************************************************\
* _____________________
* |                   |
* |  P R D            |
* |___________________|
*
* PRD0  - timer period register 0
* PRD1  - timer period register 1
* PRD2  - timer period register 2 (1)
*
* (1) - only supported on C64x devices
*
* FIELDS (msb -> lsb)
* (rw) PRD
*
\******************************************************************************/
  #define _TIMER_PRD_OFFSET            1

  #define _TIMER_PRD0_ADDR             0x01940004u
  #define _TIMER_PRD1_ADDR             0x01980004u
  #if  TIMER_DEVICE_CNT == 3
    #define _TIMER_PRD2_ADDR           0x01AC0004u
  #endif

  #define _TIMER_PRD_PRD_MASK          0xFFFFFFFFu
  #define _TIMER_PRD_PRD_SHIFT         0x00000000u
  #define  TIMER_PRD_PRD_DEFAULT       0x00000000u
  #define  TIMER_PRD_PRD_OF(x)         _VALUEOF(x)

  #define  TIMER_PRD_OF(x)             _VALUEOF(x)

  #define TIMER_PRD_DEFAULT (Uint32)( \
     _PER_FDEFAULT(TIMER,PRD,PRD) \
  )

  #define TIMER_PRD_RMK(prd) (Uint32)( \
     _PER_FMK(TIMER,PRD,PRD,prd) \
  )

  #define _TIMER_PRD_FGET(N,FIELD)\
    _PER_FGET(_TIMER_PRD##N##_ADDR,TIMER,PRD,##FIELD)

  #define _TIMER_PRD_FSET(N,FIELD,f)\
    _PER_FSET(_TIMER_PRD##N##_ADDR,TIMER,PRD,##FIELD,f)

  #define _TIMER_PRD_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_TIMER_PRD##N##_ADDR,TIMER,PRD,##FIELD,##SYM)

  #define _TIMER_PRD0_FGET(FIELD) _TIMER_PRD_FGET(0,##FIELD)
  #define _TIMER_PRD1_FGET(FIELD) _TIMER_PRD_FGET(1,##FIELD)
  #if  TIMER_DEVICE_CNT == 3
    #define _TIMER_PRD2_FGET(FIELD) _TIMER_PRD_FGET(2,##FIELD)
  #endif

  #define _TIMER_PRD0_FSET(FIELD,f) _TIMER_PRD_FSET(0,##FIELD,f)
  #define _TIMER_PRD1_FSET(FIELD,f) _TIMER_PRD_FSET(1,##FIELD,f)
  #if  TIMER_DEVICE_CNT == 3
    #define _TIMER_PRD2_FSET(FIELD,f) _TIMER_PRD_FSET(2,##FIELD,f)
  #endif

  #define _TIMER_PRD0_FSETS(FIELD,SYM) _TIMER_PRD_FSETS(0,##FIELD,##SYM)
  #define _TIMER_PRD1_FSETS(FIELD,SYM) _TIMER_PRD_FSETS(1,##FIELD,##SYM)
  #if  TIMER_DEVICE_CNT == 3
    #define _TIMER_PRD2_FSETS(FIELD,SYM) _TIMER_PRD_FSETS(2,##FIELD,##SYM)
  #endif


/******************************************************************************\
* _____________________
* |                   |
* |  C N T            |
* |___________________|
*
* CNT0  - timer count register 0
* CNT1  - timer count register 1
* CNT2  - timer count register 2 (1)
*
* (1) - only supported on C64x devices
*
* FIELDS (msb -> lsb)
* (rw) CNT
*
\******************************************************************************/
  #define _TIMER_CNT_OFFSET            2

  #define _TIMER_CNT0_ADDR             0x01940008u
  #define _TIMER_CNT1_ADDR             0x01980008u
  #if  TIMER_DEVICE_CNT == 3
    #define _TIMER_CNT2_ADDR           0x01AC0008u
  #endif

  #define _TIMER_CNT_CNT_MASK          0xFFFFFFFFu
  #define _TIMER_CNT_CNT_MASK          0xFFFFFFFFu
  #define _TIMER_CNT_CNT_SHIFT         0x00000000u
  #define  TIMER_CNT_CNT_DEFAULT       0x00000000u
  #define  TIMER_CNT_CNT_OF(x)         _VALUEOF(x)

  #define  TIMER_CNT_OF(x)             _VALUEOF(x)

  #define TIMER_CNT_DEFAULT (Uint32)( \
     _PER_FDEFAULT(TIMER,CNT,CNT) \
  )

  #define TIMER_CNT_RMK(cnt) (Uint32)( \
     _PER_FMK(TIMER,CNT,CNT,cnt) \
  )

  #define _TIMER_CNT_FGET(N,FIELD)\
    _PER_FGET(_TIMER_CNT##N##_ADDR,TIMER,CNT,##FIELD)

  #define _TIMER_CNT_FSET(N,FIELD,f)\
    _PER_FSET(_TIMER_CNT##N##_ADDR,TIMER,CNT,##FIELD,f)

  #define _TIMER_CNT_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_TIMER_CNT##N##_ADDR,TIMER,CNT,##FIELD,##SYM)

  #define _TIMER_CNT0_FGET(FIELD) _TIMER_CNT_FGET(0,##FIELD)
  #define _TIMER_CNT1_FGET(FIELD) _TIMER_CNT_FGET(1,##FIELD)
  #if  TIMER_DEVICE_CNT == 3
    #define _TIMER_CNT2_FGET(FIELD) _TIMER_CNT_FGET(2,##FIELD)
  #endif

  #define _TIMER_CNT0_FSET(FIELD,f) _TIMER_CNT_FSET(0,##FIELD,f)
  #define _TIMER_CNT1_FSET(FIELD,f) _TIMER_CNT_FSET(1,##FIELD,f)
  #if  TIMER_DEVICE_CNT == 3
    #define _TIMER_CNT2_FSET(FIELD,f) _TIMER_CNT_FSET(2,##FIELD,f)
  #endif

  #define _TIMER_CNT0_FSETS(FIELD,SYM) _TIMER_CNT_FSETS(0,##FIELD,##SYM)
  #define _TIMER_CNT1_FSETS(FIELD,SYM) _TIMER_CNT_FSETS(1,##FIELD,##SYM)
  #if  TIMER_DEVICE_CNT == 3
    #define _TIMER_CNT2_FSETS(FIELD,SYM) _TIMER_CNT_FSETS(2,##FIELD,##SYM)
  #endif


/*----------------------------------------------------------------------------*/

#endif /* (TIMER_SUPPORT) */
#endif /* _CSL_TIMERHAL_H_ */
/******************************************************************************\
* End of csl_timerhal.h
\******************************************************************************/

