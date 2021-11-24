/******************************************************************************\
*           Copyright (C) 1999-2001 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_mcbsphal.h
* DATE CREATED.. 06/12/1999
* LAST MODIFIED. 08/02/2004 - Adding support for C6418
*                10/02/2001
*                          - 6713 device addition
*                04/21/2004 - Fixed XCR0 bad address
*------------------------------------------------------------------------------
* REGISTERS
*
* DRR0  - serial port 0 data receive register
* DRR1  - serial port 1 data receive register
* DRR2  - serial port 2 data receive register (1)
* DXR0  - serial port 0 data transmit register
* DXR1  - serial port 1 data transmit register
* DXR2  - serial port 2 data transmit register (1)
* SPCR0 - serial port 0 control register
* SPCR1 - serial port 1 control register
* SPCR2 - serial port 2 control register (1)
* RCR0  - serial port 0 receive control register
* RCR1  - serial port 1 receive control register
* RCR2  - serial port 2 receive control register (1)
* XCR0  - serial port 0 transmit control register
* XCR1  - serial port 1 transmit control register
* XCR2  - serial port 2 transmit control register (1)
* SRGR0 - serial port 0 sample rate generator register
* SRGR1 - serial port 1 sample rate generator register
* SRGR2 - serial port 2 sample rate generator register (1)
* MCR0  - serial port 0 multichannel control register
* MCR1  - serial port 1 multichannel control register
* MCR2  - serial port 2 multichannel control register (1)
* RCER0 - serial port 0 receive channel enable register
* RCER1 - serial port 1 receive channel enable register
* RCER2 - serial port 2 receive channel enable register (1)
* XCER0 - serial port 0 transmit channel enable register
* XCER1 - serial port 1 transmit channel enable register
* XCER2 - serial port 2 transmit channel enable register (1)
* RCERE00 - serial port 0 Enhanced receive channel enable register 0 (2)
* RCERE01 - serial port 1 Enhanced receive channel enable register 0 (2)
* RCERE02 - serial port 2 Enhanced receive channel enable register 0 (2)
* RCERE10 - serial port 0 Enhanced receive channel enable register 1 (2)
* RCERE11 - serial port 1 Enhanced receive channel enable register 1 (2)
* RCERE12 - serial port 2 Enhanced receive channel enable register 1 (2)
* RCERE20 - serial port 0 Enhanced receive channel enable register 2 (2)
* RCERE21 - serial port 1 Enhanced receive channel enable register 2 (2)
* RCERE22 - serial port 2 Enhanced receive channel enable register 2 (2)
* RCERE30 - serial port 0 Enhanced receive channel enable register 3 (2)
* RCERE31 - serial port 1 Enhanced receive channel enable register 3 (2)
* RCERE32 - serial port 2 Enhanced receive channel enable register 3 (2)
* XCERE00 - serial port 0 Enhanced transmit channel enable register 0 (2)
* XCERE01 - serial port 1 Enhanced transmit channel enable register 0 (2)
* XCERE02 - serial port 2 Enhanced transmit channel enable register 0 (2)
* XCERE10 - serial port 0 Enhanced transmit channel enable register 1 (2)
* XCERE11 - serial port 1 Enhanced transmit channel enable register 1 (2)
* XCERE12 - serial port 2 Enhanced transmit channel enable register 1 (2)
* XCERE20 - serial port 0 Enhanced transmit channel enable register 2 (2)
* XCERE21 - serial port 1 Enhanced transmit channel enable register 2 (2)
* XCERE22 - serial port 2 Enhanced transmit channel enable register 2 (2)
* XCERE30 - serial port 0 Enhanced transmit channel enable register 3 (2)
* XCERE31 - serial port 1 Enhanced transmit channel enable register 3 (2)
* XCERE32 - serial port 2 Enhanced transmit channel enable register 3 (2)
* PCR0  - serial port 0 pin control register
* PCR1  - serial port 1 pin control register
* PCR2  - serial port 2 pin control register (1)
*
* (1) only supported on devices with three serial ports
* (2) supported by C64x devices (RCERx replaced by RCERE0x, XCERx replaced by XCERE0x)
*
\******************************************************************************/
#ifndef _CSL_MCBSPHAL_H_
#define _CSL_MCBSPHAL_H_

#include <csl_stdinc.h>
#include <csl_chip.h>

#if (MCBSP_SUPPORT)
/******************************************************************************\
* MISC section
\******************************************************************************/

#if (CHIP_6202|CHIP_6203|CHIP_6414|CHIP_6415|CHIP_6416)
  #define _MCBSP_PORT_CNT        3
  #define _MCBSP_BASE_PORT0      0x018C0000u
  #define _MCBSP_BASE_PORT1      0x01900000u
  #define _MCBSP_BASE_PORT2      0x01A40000u
#else
  #define _MCBSP_PORT_CNT        2
  #define _MCBSP_BASE_PORT0      0x018C0000u
  #define _MCBSP_BASE_PORT1      0x01900000u
#endif


/******************************************************************************\
* module level register/field access macros
\******************************************************************************/

  /* ----------------- */
  /* FIELD MAKE MACROS */
  /* ----------------- */

  #define MCBSP_FMK(REG,FIELD,x)\
    _PER_FMK(MCBSP,##REG,##FIELD,x)

  #define MCBSP_FMKS(REG,FIELD,SYM)\
    _PER_FMKS(MCBSP,##REG,##FIELD,##SYM)


  /* -------------------------------- */
  /* RAW REGISTER/FIELD ACCESS MACROS */
  /* -------------------------------- */

  #define MCBSP_ADDR(REG)\
    _MCBSP_##REG##_ADDR

  #define MCBSP_RGET(REG)\
    _PER_RGET(_MCBSP_##REG##_ADDR,MCBSP,##REG)

  #define MCBSP_RSET(REG,x)\
    _PER_RSET(_MCBSP_##REG##_ADDR,MCBSP,##REG,x)

  #define MCBSP_FGET(REG,FIELD)\
    _MCBSP_##REG##_FGET(##FIELD)

  #define MCBSP_FSET(REG,FIELD,x)\
    _MCBSP_##REG##_FSET(##FIELD,##x)

  #define MCBSP_FSETS(REG,FIELD,SYM)\
    _MCBSP_##REG##_FSETS(##FIELD,##SYM)


  /* ------------------------------------------ */
  /* ADDRESS BASED REGISTER/FIELD ACCESS MACROS */
  /* ------------------------------------------ */

  #define MCBSP_RGETA(addr,REG)\
    _PER_RGET(addr,MCBSP,##REG)

  #define MCBSP_RSETA(addr,REG,x)\
    _PER_RSET(addr,MCBSP,##REG,x)

  #define MCBSP_FGETA(addr,REG,FIELD)\
    _PER_FGET(addr,MCBSP,##REG,##FIELD)

  #define MCBSP_FSETA(addr,REG,FIELD,x)\
    _PER_FSET(addr,MCBSP,##REG,##FIELD,x)

  #define MCBSP_FSETSA(addr,REG,FIELD,SYM)\
    _PER_FSETS(addr,MCBSP,##REG,##FIELD,##SYM)


  /* ----------------------------------------- */
  /* HANDLE BASED REGISTER/FIELD ACCESS MACROS */
  /* ----------------------------------------- */

  #define MCBSP_ADDRH(h,REG)\
    (Uint32)(&((h)->baseAddr[_MCBSP_##REG##_OFFSET]))

  #define MCBSP_RGETH(h,REG)\
    MCBSP_RGETA(MCBSP_ADDRH(h,##REG),##REG)


  #define MCBSP_RSETH(h,REG,x)\
    MCBSP_RSETA(MCBSP_ADDRH(h,##REG),##REG,x)


  #define MCBSP_FGETH(h,REG,FIELD)\
    MCBSP_FGETA(MCBSP_ADDRH(h,##REG),##REG,##FIELD)


  #define MCBSP_FSETH(h,REG,FIELD,x)\
    MCBSP_FSETA(MCBSP_ADDRH(h,##REG),##REG,##FIELD,x)


  #define MCBSP_FSETSH(h,REG,FIELD,SYM)\
    MCBSP_FSETSA(MCBSP_ADDRH(h,##REG),##REG,##FIELD,##SYM)



/******************************************************************************\
* _____________________
* |                   |
* |  D R R            |
* |___________________|
*
* DRR0  - serial port 0 data receive register
* DRR1  - serial port 1 data receive register
* DRR2  - serial port 2 data receive register (1)
*
* (1) only supported on devices with three serial ports
*
* FIELDS (msb -> lsb)
* (r) DR
*
\******************************************************************************/
  #define _MCBSP_DRR_OFFSET            0

#if (C11_SUPPORT | C64_SUPPORT)
  #define _MCBSP_DRR0_ADDR             0x30000000u
  #define _MCBSP_DRR1_ADDR             0x34000000u
#else
  #define _MCBSP_DRR0_ADDR             0x018C0000u
  #define _MCBSP_DRR1_ADDR             0x01900000u
#endif

#if (_MCBSP_PORT_CNT==3 && (CHIP_6202 | CHIP_6203 ) )
  #define _MCBSP_DRR2_ADDR             0x01A40000u
#endif

#if (_MCBSP_PORT_CNT==3 && (CHIP_6414 | CHIP_6415 | CHIP_6416))
  #define _MCBSP_DRR2_ADDR             0x38000000u
#endif

  #define _MCBSP_DRR_DR_MASK           0xFFFFFFFFu
  #define _MCBSP_DRR_DR_SHIFT          0x00000000u
  #define  MCBSP_DRR_DR_DEFAULT        0x00000000u
  #define  MCBSP_DRR_DR_OF(x)          _VALUEOF(x)

  #define  MCBSP_DRR_OF(x)             _VALUEOF(x)

  #define MCBSP_DRR_DEFAULT (Uint32)(\
    _PER_FDEFAULT(MCBSP,DRR,DR)\
  )

 #if (CHIP_6413 | CHIP_6418 | CHIP_6410)
  #define MCBSP_DRR_RMK(dr) (Uint32)(\
    _PER_FMK(MCBSP,DRR,DR,dr)\
  )
 #endif

  #define _MCBSP_DRR_FGET(N,FIELD)\
    _PER_FGET(_MCBSP_DRR##N##_ADDR,MCBSP,DRR,##FIELD)
  #define _MCBSP_DRR_FSET(N,FIELD,field)\
     _PER_FSET(_MCBSP_DRR##N##_ADDR,MCBSP,DRR,##FIELD,field)	
  #define _MCBSP_DRR_FSETS(N,FIELD,SYM)\
     _PER_FSETS(_MCBSP_DRR##N##_ADDR,MCBSP,DRR,##FIELD,##SYM) 	
  #define _MCBSP_DRR0_FGET(FIELD) _MCBSP_DRR_FGET(0,##FIELD)
  #define _MCBSP_DRR1_FGET(FIELD) _MCBSP_DRR_FGET(1,##FIELD)
#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_DRR2_FGET(FIELD) _MCBSP_DRR_FGET(2,##FIELD)
#endif
  #define _MCBSP_DRR0_FSET(FIELD,f) _MCBSP_DRR_FSET(0,##FIELD,f)	
  #define _MCBSP_DRR1_FSET(FIELD,f) _MCBSP_DRR_FSET(1,##FIELD,f)	
#if(_MCBSP_PORT_CNT==3)  	
  #define _MCBSP_DRR2_FSET(FIELD,f) _MCBSP_DRR_FSET(2,##FIELD,f)	
#endif	
  #define _MCBSP_DRR0_FSETS(FIELD,SYM) _MCBSP_DRR_FSETS(0,##FIELD,##SYM)
  #define _MCBSP_DRR1_FSETS(FIELD,SYM) _MCBSP_DRR_FSETS(1,##FIELD,##SYM)
#if(_MCBSP_PORT_CNT==3)	
  #define _MCBSP_DRR2_FSETS(FIELD,SYM) _MCBSP_DRR_FSETS(2,##FIELD,##SYM)	
#endif	
/******************************************************************************\
* _____________________
* |                   |
* |  D X R            |
* |___________________|
*
* DXR0  - serial port 0 data transmit register
* DXR1  - serial port 1 data transmit register
* DXR2  - serial port 2 data transmit register (1)
*
* (1) only supported on devices with three serial ports
*
* FIELDS (msb -> lsb)
* (w) DX
*
\******************************************************************************/
  #define _MCBSP_DXR_OFFSET            1

#if (C11_SUPPORT | C64_SUPPORT)
  #define _MCBSP_DXR0_ADDR             0x30000000u
  #define _MCBSP_DXR1_ADDR             0x34000000u
#else
  #define _MCBSP_DXR0_ADDR             0x018C0004u
  #define _MCBSP_DXR1_ADDR             0x01900004u
#endif

#if (_MCBSP_PORT_CNT==3 && (CHIP_6202 | CHIP_6203) )
  #define _MCBSP_DXR2_ADDR             0x01A40004u
#endif

#if (_MCBSP_PORT_CNT==3 && (CHIP_6414 | CHIP_6415 | CHIP_6416))
  #define _MCBSP_DXR2_ADDR             0x38000000u
#endif

  #define _MCBSP_DXR_DX_MASK           0xFFFFFFFFu
  #define _MCBSP_DXR_DX_SHIFT          0x00000000u
  #define  MCBSP_DXR_DX_DEFAULT        0x00000000u
  #define  MCBSP_DXR_DX_OF(x)          _VALUEOF(x)

  #define  MCBSP_DXR_OF(x)             _VALUEOF(x)

  #define MCBSP_DXR_DEFAULT (Uint32)(\
    _PER_FDEFAULT(MCBSP,DXR,DX)\
  )

  #define MCBSP_DXR_RMK(dr) (Uint32)(\
    _PER_FMK(MCBSP,DXR,DX,dr)\
  )

  #define _MCBSP_DXR_FGET(N,FIELD)\
    _PER_FGET(_MCBSP_DXR##N##_ADDR,MCBSP,DXR,##FIELD)

  #define _MCBSP_DXR_FSET(N,FIELD,field)\
    _PER_FSET(_MCBSP_DXR##N##_ADDR,MCBSP,DXR,##FIELD,field)

  #define _MCBSP_DXR_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCBSP_DXR##N##_ADDR,MCBSP,DXR,##FIELD,##SYM)

  #define _MCBSP_DXR0_FGET(FIELD) _MCBSP_DXR_FGET(0,##FIELD)
  #define _MCBSP_DXR1_FGET(FIELD) _MCBSP_DXR_FGET(1,##FIELD)
#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_DXR2_FGET(FIELD) _MCBSP_DXR_FGET(2,##FIELD)
#endif

  #define _MCBSP_DXR0_FSET(FIELD,f) _MCBSP_DXR_FSET(0,##FIELD,f)
  #define _MCBSP_DXR1_FSET(FIELD,f) _MCBSP_DXR_FSET(1,##FIELD,f)
#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_DXR2_FSET(FIELD,f) _MCBSP_DXR_FSET(2,##FIELD,f)
#endif

  #define _MCBSP_DXR0_FSETS(FIELD,SYM) _MCBSP_DXR_FSETS(0,##FIELD,##SYM)
  #define _MCBSP_DXR1_FSETS(FIELD,SYM) _MCBSP_DXR_FSETS(1,##FIELD,##SYM)
#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_DXR2_FSETS(FIELD,SYM) _MCBSP_DXR_FSETS(2,##FIELD,##SYM)
#endif

/******************************************************************************\
* _____________________
* |                   |
* |  S P C R          |
* |___________________|
*
* SPCR0 - serial port 0 control register
* SPCR1 - serial port 1 control register
* SPCR2 - serial port 2 control register (1)
*
* (1) only supported on devices with three serial ports
*
* FIELDS (msb -> lsb)
* (rw) FREE (2)
* (rw) SOFT (2)
* (rw) FRST
* (rw) GRST
* (rw) XINTM
* (rw) XSYNCERR
* (r)  XEMPTY
* (r)  XRDY
* (rw) XRST
* (rw) DLB
* (rw) RJUST
* (rw) CLKSTP
* (rw) DXENA (2)
* (rw) RINTM
* (rw) RSYNCERR
* (r)  RFULL
* (r)  RRDY
* (rw) RRST
*
* (2) - C11_SUPPORT/C64_SUPPORT only
*
\******************************************************************************/
  #define _MCBSP_SPCR_OFFSET           2

  #define _MCBSP_SPCR0_ADDR            0x018C0008u
  #define _MCBSP_SPCR1_ADDR            0x01900008u

#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_SPCR2_ADDR            0x01A40008u
#endif

#if (C11_SUPPORT | C64_SUPPORT)
  #define _MCBSP_SPCR_FREE_MASK        0x02000000u
  #define _MCBSP_SPCR_FREE_SHIFT       0x00000019u
  #define  MCBSP_SPCR_FREE_DEFAULT     0x00000000u
  #define  MCBSP_SPCR_FREE_OF(x)       _VALUEOF(x)
  #define  MCBSP_SPCR_FREE_NO          0x00000000u
  #define  MCBSP_SPCR_FREE_YES         0x00000001u

  #define _MCBSP_SPCR_SOFT_MASK        0x01000000u
  #define _MCBSP_SPCR_SOFT_SHIFT       0x00000018u
  #define  MCBSP_SPCR_SOFT_DEFAULT     0x00000000u
  #define  MCBSP_SPCR_SOFT_OF(x)       _VALUEOF(x)
  #define  MCBSP_SPCR_SOFT_NO          0x00000000u
  #define  MCBSP_SPCR_SOFT_YES         0x00000001u

#endif

  #define _MCBSP_SPCR_FRST_MASK        0x00800000u
  #define _MCBSP_SPCR_FRST_SHIFT       0x00000017u
  #define  MCBSP_SPCR_FRST_DEFAULT     0x00000000u
  #define  MCBSP_SPCR_FRST_OF(x)       _VALUEOF(x)
  #define  MCBSP_SPCR_FRST_YES         0x00000000u
  #define  MCBSP_SPCR_FRST_0           0x00000000u
  #define  MCBSP_SPCR_FRST_NO          0x00000001u
  #define  MCBSP_SPCR_FRST_1           0x00000001u

  #define _MCBSP_SPCR_GRST_MASK        0x00400000u
  #define _MCBSP_SPCR_GRST_SHIFT       0x00000016u
  #define  MCBSP_SPCR_GRST_DEFAULT     0x00000000u
  #define  MCBSP_SPCR_GRST_OF(x)       _VALUEOF(x)
  #define  MCBSP_SPCR_GRST_YES         0x00000000u
  #define  MCBSP_SPCR_GRST_0           0x00000000u
  #define  MCBSP_SPCR_GRST_NO          0x00000001u
  #define  MCBSP_SPCR_GRST_1           0x00000001u

  #define _MCBSP_SPCR_XINTM_MASK       0x00300000u
  #define _MCBSP_SPCR_XINTM_SHIFT      0x00000014u
  #define  MCBSP_SPCR_XINTM_DEFAULT    0x00000000u
  #define  MCBSP_SPCR_XINTM_OF(x)      _VALUEOF(x)
  #define  MCBSP_SPCR_XINTM_XRDY       0x00000000u
  #define  MCBSP_SPCR_XINTM_EOS        0x00000001u
  #define  MCBSP_SPCR_XINTM_FRM        0x00000002u
  #define  MCBSP_SPCR_XINTM_XSYNCERR   0x00000003u

  #define _MCBSP_SPCR_XSYNCERR_MASK    0x00080000u
  #define _MCBSP_SPCR_XSYNCERR_SHIFT   0x00000013u
  #define  MCBSP_SPCR_XSYNCERR_DEFAULT 0x00000000u
  #define  MCBSP_SPCR_XSYNCERR_OF(x)   _VALUEOF(x)
  #define  MCBSP_SPCR_XSYNCERR_NO      0x00000000u
  #define  MCBSP_SPCR_XSYNCERR_0       0x00000000u
  #define  MCBSP_SPCR_XSYNCERR_YES     0x00000001u
  #define  MCBSP_SPCR_XSYNCERR_1       0x00000001u

  #define _MCBSP_SPCR_XEMPTY_MASK      0x00040000u
  #define _MCBSP_SPCR_XEMPTY_SHIFT     0x00000012u
  #define  MCBSP_SPCR_XEMPTY_DEFAULT   0x00000000u
  #define  MCBSP_SPCR_XEMPTY_OF(x)     _VALUEOF(x)
  #define  MCBSP_SPCR_XEMPTY_YES       0x00000000u
  #define  MCBSP_SPCR_XEMPTY_0        0x00000000u
  #define  MCBSP_SPCR_XEMPTY_NO        0x00000001u
  #define  MCBSP_SPCR_XEMPTY_1         0x00000001u

  #define _MCBSP_SPCR_XRDY_MASK        0x00020000u
  #define _MCBSP_SPCR_XRDY_SHIFT       0x00000011u
  #define  MCBSP_SPCR_XRDY_DEFAULT     0x00000000u
  #define  MCBSP_SPCR_XRDY_OF(x)       _VALUEOF(x)
  #define  MCBSP_SPCR_XRDY_NO          0x00000000u
  #define  MCBSP_SPCR_XRDY_YES         0x00000001u

  #define _MCBSP_SPCR_XRST_MASK        0x00010000u
  #define _MCBSP_SPCR_XRST_SHIFT       0x00000010u
  #define  MCBSP_SPCR_XRST_DEFAULT     0x00000000u
  #define  MCBSP_SPCR_XRST_OF(x)       _VALUEOF(x)
  #define  MCBSP_SPCR_XRST_YES         0x00000000u
  #define  MCBSP_SPCR_XRST_0           0x00000000u
  #define  MCBSP_SPCR_XRST_NO          0x00000001u
  #define  MCBSP_SPCR_XRST_1           0x00000001u

  #define _MCBSP_SPCR_DLB_MASK         0x00008000u
  #define _MCBSP_SPCR_DLB_SHIFT        0x0000000Fu
  #define  MCBSP_SPCR_DLB_DEFAULT      0x00000000u
  #define  MCBSP_SPCR_DLB_OF(x)        _VALUEOF(x)
  #define  MCBSP_SPCR_DLB_OFF          0x00000000u
  #define  MCBSP_SPCR_DLB_ON           0x00000001u

  #define _MCBSP_SPCR_RJUST_MASK       0x00006000u
  #define _MCBSP_SPCR_RJUST_SHIFT      0x0000000Du
  #define  MCBSP_SPCR_RJUST_DEFAULT    0x00000000u
  #define  MCBSP_SPCR_RJUST_OF(x)      _VALUEOF(x)
  #define  MCBSP_SPCR_RJUST_RZF        0x00000000u
  #define  MCBSP_SPCR_RJUST_RSE        0x00000001u
  #define  MCBSP_SPCR_RJUST_LZF        0x00000002u

  #define _MCBSP_SPCR_CLKSTP_MASK      0x00001800u
  #define _MCBSP_SPCR_CLKSTP_SHIFT     0x0000000Bu
  #define  MCBSP_SPCR_CLKSTP_DEFAULT   0x00000000u
  #define  MCBSP_SPCR_CLKSTP_OF(x)     _VALUEOF(x)
  #define  MCBSP_SPCR_CLKSTP_DISABLE   0x00000000u
  #define  MCBSP_SPCR_CLKSTP_NODELAY   0x00000002u
  #define  MCBSP_SPCR_CLKSTP_DELAY     0x00000003u

#if (C11_SUPPORT | C64_SUPPORT)
  #define _MCBSP_SPCR_DXENA_MASK       0x00000080u
  #define _MCBSP_SPCR_DXENA_SHIFT      0x00000007u
  #define  MCBSP_SPCR_DXENA_DEFAULT    0x00000000u
  #define  MCBSP_SPCR_DXENA_OF(x)      _VALUEOF(x)
  #define  MCBSP_SPCR_DXENA_OFF        0x00000000u
  #define  MCBSP_SPCR_DXENA_ON         0x00000001u
#endif

  #define _MCBSP_SPCR_RINTM_MASK       0x00000030u
  #define _MCBSP_SPCR_RINTM_SHIFT      0x00000004u
  #define  MCBSP_SPCR_RINTM_DEFAULT    0x00000000u
  #define  MCBSP_SPCR_RINTM_OF(x)      _VALUEOF(x)
  #define  MCBSP_SPCR_RINTM_RRDY       0x00000000u
  #define  MCBSP_SPCR_RINTM_EOS        0x00000001u
  #define  MCBSP_SPCR_RINTM_FRM        0x00000002u
  #define  MCBSP_SPCR_RINTM_RSYNCERR   0x00000003u

  #define _MCBSP_SPCR_RSYNCERR_MASK    0x00000008u
  #define _MCBSP_SPCR_RSYNCERR_SHIFT   0x00000003u
  #define  MCBSP_SPCR_RSYNCERR_DEFAULT 0x00000000u
  #define  MCBSP_SPCR_RSYNCERR_OF(x)   _VALUEOF(x)
  #define  MCBSP_SPCR_RSYNCERR_NO      0x00000000u
  #define  MCBSP_SPCR_RSYNCERR_0       0x00000000u
  #define  MCBSP_SPCR_RSYNCERR_YES     0x00000001u
  #define  MCBSP_SPCR_RSYNCERR_1       0x00000001u

  #define _MCBSP_SPCR_RFULL_MASK       0x00000004u
  #define _MCBSP_SPCR_RFULL_SHIFT      0x00000002u
  #define  MCBSP_SPCR_RFULL_DEFAULT    0x00000000u
  #define  MCBSP_SPCR_RFULL_OF(x)      _VALUEOF(x)
  #define  MCBSP_SPCR_RFULL_NO         0x00000000u
  #define  MCBSP_SPCR_RFULL_YES        0x00000001u

  #define _MCBSP_SPCR_RRDY_MASK        0x00000002u
  #define _MCBSP_SPCR_RRDY_SHIFT       0x00000001u
  #define  MCBSP_SPCR_RRDY_DEFAULT     0x00000000u
  #define  MCBSP_SPCR_RRDY_OF(x)       _VALUEOF(x)
  #define  MCBSP_SPCR_RRDY_NO          0x00000000u
  #define  MCBSP_SPCR_RRDY_YES         0x00000001u

  #define _MCBSP_SPCR_RRST_MASK        0x00000001u
  #define _MCBSP_SPCR_RRST_SHIFT       0x00000000u
  #define  MCBSP_SPCR_RRST_DEFAULT     0x00000000u
  #define  MCBSP_SPCR_RRST_OF(x)       _VALUEOF(x)
  #define  MCBSP_SPCR_RRST_YES         0x00000000u
  #define  MCBSP_SPCR_RRST_0           0x00000000u
  #define  MCBSP_SPCR_RRST_NO          0x00000001u
  #define  MCBSP_SPCR_RRST_1           0x00000001u

  #define  MCBSP_SPCR_OF(x)            _VALUEOF(x)

#if (C11_SUPPORT | C64_SUPPORT)
  #define MCBSP_SPCR_DEFAULT (Uint32)(\
     _PER_FDEFAULT(MCBSP,SPCR,FREE)\
    |_PER_FDEFAULT(MCBSP,SPCR,SOFT)\
    |_PER_FDEFAULT(MCBSP,SPCR,FRST)\
    |_PER_FDEFAULT(MCBSP,SPCR,GRST)\
    |_PER_FDEFAULT(MCBSP,SPCR,XINTM)\
    |_PER_FDEFAULT(MCBSP,SPCR,XSYNCERR)\
    |_PER_FDEFAULT(MCBSP,SPCR,XEMPTY)\
    |_PER_FDEFAULT(MCBSP,SPCR,XRDY)\
    |_PER_FDEFAULT(MCBSP,SPCR,XRST)\
    |_PER_FDEFAULT(MCBSP,SPCR,DLB)\
    |_PER_FDEFAULT(MCBSP,SPCR,RJUST)\
    |_PER_FDEFAULT(MCBSP,SPCR,CLKSTP)\
    |_PER_FDEFAULT(MCBSP,SPCR,DXENA)\
    |_PER_FDEFAULT(MCBSP,SPCR,RINTM)\
    |_PER_FDEFAULT(MCBSP,SPCR,RSYNCERR)\
    |_PER_FDEFAULT(MCBSP,SPCR,RFULL)\
    |_PER_FDEFAULT(MCBSP,SPCR,RRDY)\
    |_PER_FDEFAULT(MCBSP,SPCR,RRST)\
  )

  #define MCBSP_SPCR_RMK(free,soft,frst,grst,xintm,xsyncerr,xrst,dlb,rjust,\
    clkstp,dxena,rintm,rsyncerr,rrst) (Uint32)(\
     _PER_FMK(MCBSP,SPCR,FREE,free)\
    |_PER_FMK(MCBSP,SPCR,SOFT,soft)\
    |_PER_FMK(MCBSP,SPCR,FRST,frst)\
    |_PER_FMK(MCBSP,SPCR,GRST,grst)\
    |_PER_FMK(MCBSP,SPCR,XINTM,xintm)\
    |_PER_FMK(MCBSP,SPCR,XSYNCERR,xsyncerr)\
    |_PER_FMK(MCBSP,SPCR,XRST,xrst)\
    |_PER_FMK(MCBSP,SPCR,DLB,dlb)\
    |_PER_FMK(MCBSP,SPCR,RJUST,rjust)\
    |_PER_FMK(MCBSP,SPCR,CLKSTP,clkstp)\
    |_PER_FMK(MCBSP,SPCR,DXENA,dxena)\
    |_PER_FMK(MCBSP,SPCR,RINTM,rintm)\
    |_PER_FMK(MCBSP,SPCR,RSYNCERR,rsyncerr)\
    |_PER_FMK(MCBSP,SPCR,RRST,rrst)\
  )
#endif

#if (!C11_SUPPORT && !C64_SUPPORT)
  #define MCBSP_SPCR_DEFAULT (Uint32)(\
     _PER_FDEFAULT(MCBSP,SPCR,FRST)\
    |_PER_FDEFAULT(MCBSP,SPCR,GRST)\
    |_PER_FDEFAULT(MCBSP,SPCR,XINTM)\
    |_PER_FDEFAULT(MCBSP,SPCR,XSYNCERR)\
    |_PER_FDEFAULT(MCBSP,SPCR,XEMPTY)\
    |_PER_FDEFAULT(MCBSP,SPCR,XRDY)\
    |_PER_FDEFAULT(MCBSP,SPCR,XRST)\
    |_PER_FDEFAULT(MCBSP,SPCR,DLB)\
    |_PER_FDEFAULT(MCBSP,SPCR,RJUST)\
    |_PER_FDEFAULT(MCBSP,SPCR,CLKSTP)\
    |_PER_FDEFAULT(MCBSP,SPCR,RINTM)\
    |_PER_FDEFAULT(MCBSP,SPCR,RSYNCERR)\
    |_PER_FDEFAULT(MCBSP,SPCR,RFULL)\
    |_PER_FDEFAULT(MCBSP,SPCR,RRDY)\
    |_PER_FDEFAULT(MCBSP,SPCR,RRST)\
  )

  #define MCBSP_SPCR_RMK(frst,grst,xintm,xsyncerr,xrst,dlb,rjust,\
    clkstp,rintm,rsyncerr,rrst) (Uint32)(\
     _PER_FMK(MCBSP,SPCR,FRST,frst)\
    |_PER_FMK(MCBSP,SPCR,GRST,grst)\
    |_PER_FMK(MCBSP,SPCR,XINTM,xintm)\
    |_PER_FMK(MCBSP,SPCR,XSYNCERR,xsyncerr)\
    |_PER_FMK(MCBSP,SPCR,XRST,xrst)\
    |_PER_FMK(MCBSP,SPCR,DLB,dlb)\
    |_PER_FMK(MCBSP,SPCR,RJUST,rjust)\
    |_PER_FMK(MCBSP,SPCR,CLKSTP,clkstp)\
    |_PER_FMK(MCBSP,SPCR,RINTM,rintm)\
    |_PER_FMK(MCBSP,SPCR,RSYNCERR,rsyncerr)\
    |_PER_FMK(MCBSP,SPCR,RRST,rrst)\
  )
#endif

  #define _MCBSP_SPCR_FGET(N,FIELD)\
    _PER_FGET(_MCBSP_SPCR##N##_ADDR,MCBSP,SPCR,##FIELD)

  #define _MCBSP_SPCR_FSET(N,FIELD,field)\
    _PER_FSET(_MCBSP_SPCR##N##_ADDR,MCBSP,SPCR,##FIELD,field)

  #define _MCBSP_SPCR_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCBSP_SPCR##N##_ADDR,MCBSP,SPCR,##FIELD,##SYM)

  #define _MCBSP_SPCR0_FGET(FIELD) _MCBSP_SPCR_FGET(0,##FIELD)
  #define _MCBSP_SPCR1_FGET(FIELD) _MCBSP_SPCR_FGET(1,##FIELD)
#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_SPCR2_FGET(FIELD) _MCBSP_SPCR_FGET(2,##FIELD)
#endif

  #define _MCBSP_SPCR0_FSET(FIELD,f) _MCBSP_SPCR_FSET(0,##FIELD,f)
  #define _MCBSP_SPCR1_FSET(FIELD,f) _MCBSP_SPCR_FSET(1,##FIELD,f)
#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_SPCR2_FSET(FIELD,f) _MCBSP_SPCR_FSET(2,##FIELD,f)
#endif

  #define _MCBSP_SPCR0_FSETS(FIELD,SYM) _MCBSP_SPCR_FSETS(0,##FIELD,##SYM)
  #define _MCBSP_SPCR1_FSETS(FIELD,SYM) _MCBSP_SPCR_FSETS(1,##FIELD,##SYM)
#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_SPCR2_FSETS(FIELD,SYM) _MCBSP_SPCR_FSETS(2,##FIELD,##SYM)
#endif


/******************************************************************************\
* _____________________
* |                   |
* |  R C R            |
* |___________________|
*
* RCR0  - serial port 0 receive control register
* RCR1  - serial port 1 receive control register
* RCR2  - serial port 2 receive control register (1)
*
* (1) only supported on devices with three serial ports
*
* FIELDS (msb -> lsb)
* (rw) RPHASE
* (rw) RFRLEN2
* (rw) RWDLEN2
* (rw) RCOMPAND
* (rw) RFIG
* (rw) RDATDLY
* (rw) RFRLEN1
* (rw) RWDLEN1
* (rw) RWDREVRS (2)
*
* (2) - C11_SUPPORT / C64_SUPPORT only
*
\******************************************************************************/
  #define _MCBSP_RCR_OFFSET            3

  #define _MCBSP_RCR0_ADDR             0x018C000Cu
  #define _MCBSP_RCR1_ADDR             0x0190000Cu

#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_RCR2_ADDR             0x01A4000Cu
#endif

  #define _MCBSP_RCR_RPHASE_MASK       0x80000000u
  #define _MCBSP_RCR_RPHASE_SHIFT      0x0000001Fu
  #define  MCBSP_RCR_RPHASE_DEFAULT    0x00000000u
  #define  MCBSP_RCR_RPHASE_OF(x)      _VALUEOF(x)
  #define  MCBSP_RCR_RPHASE_SINGLE     0x00000000u
  #define  MCBSP_RCR_RPHASE_DUAL       0x00000001u

  #define _MCBSP_RCR_RFRLEN2_MASK      0x7F000000u
  #define _MCBSP_RCR_RFRLEN2_SHIFT     0x00000018u
  #define  MCBSP_RCR_RFRLEN2_DEFAULT   0x00000000u
  #define  MCBSP_RCR_RFRLEN2_OF(x)     _VALUEOF(x)

  #define _MCBSP_RCR_RWDLEN2_MASK      0x00E00000u
  #define _MCBSP_RCR_RWDLEN2_SHIFT     0x00000015u
  #define  MCBSP_RCR_RWDLEN2_DEFAULT   0x00000000u
  #define  MCBSP_RCR_RWDLEN2_OF(x)     _VALUEOF(x)
  #define  MCBSP_RCR_RWDLEN2_8BIT      0x00000000u
  #define  MCBSP_RCR_RWDLEN2_12BIT     0x00000001u
  #define  MCBSP_RCR_RWDLEN2_16BIT     0x00000002u
  #define  MCBSP_RCR_RWDLEN2_20BIT     0x00000003u
  #define  MCBSP_RCR_RWDLEN2_24BIT     0x00000004u
  #define  MCBSP_RCR_RWDLEN2_32BIT     0x00000005u

  #define _MCBSP_RCR_RCOMPAND_MASK     0x00180000u
  #define _MCBSP_RCR_RCOMPAND_SHIFT    0x00000013u
  #define  MCBSP_RCR_RCOMPAND_DEFAULT  0x00000000u
  #define  MCBSP_RCR_RCOMPAND_OF(x)    _VALUEOF(x)
  #define  MCBSP_RCR_RCOMPAND_MSB      0x00000000u
  #define  MCBSP_RCR_RCOMPAND_8BITLSB  0x00000001u
  #define  MCBSP_RCR_RCOMPAND_ULAW     0x00000002u
  #define  MCBSP_RCR_RCOMPAND_ALAW     0x00000003u

  #define _MCBSP_RCR_RFIG_MASK         0x00040000u
  #define _MCBSP_RCR_RFIG_SHIFT        0x00000012u
  #define  MCBSP_RCR_RFIG_DEFAULT      0x00000000u
  #define  MCBSP_RCR_RFIG_OF(x)        _VALUEOF(x)
  #define  MCBSP_RCR_RFIG_NO           0x00000000u
  #define  MCBSP_RCR_RFIG_YES          0x00000001u

  #define _MCBSP_RCR_RDATDLY_MASK      0x00030000u
  #define _MCBSP_RCR_RDATDLY_SHIFT     0x00000010u
  #define  MCBSP_RCR_RDATDLY_DEFAULT   0x00000000u
  #define  MCBSP_RCR_RDATDLY_OF(x)     _VALUEOF(x)
  #define  MCBSP_RCR_RDATDLY_0BIT      0x00000000u
  #define  MCBSP_RCR_RDATDLY_1BIT      0x00000001u
  #define  MCBSP_RCR_RDATDLY_2BIT      0x00000002u

  #define _MCBSP_RCR_RFRLEN1_MASK      0x00007F00u
  #define _MCBSP_RCR_RFRLEN1_SHIFT     0x00000008u
  #define  MCBSP_RCR_RFRLEN1_DEFAULT   0x00000000u
  #define  MCBSP_RCR_RFRLEN1_OF(x)     _VALUEOF(x)

  #define _MCBSP_RCR_RWDLEN1_MASK      0x000000E0u
  #define _MCBSP_RCR_RWDLEN1_SHIFT     0x00000005u
  #define  MCBSP_RCR_RWDLEN1_DEFAULT   0x00000000u
  #define  MCBSP_RCR_RWDLEN1_OF(x)     _VALUEOF(x)
  #define  MCBSP_RCR_RWDLEN1_8BIT      0x00000000u
  #define  MCBSP_RCR_RWDLEN1_12BIT     0x00000001u
  #define  MCBSP_RCR_RWDLEN1_16BIT     0x00000002u
  #define  MCBSP_RCR_RWDLEN1_20BIT     0x00000003u
  #define  MCBSP_RCR_RWDLEN1_24BIT     0x00000004u
  #define  MCBSP_RCR_RWDLEN1_32BIT     0x00000005u

#if (C11_SUPPORT | C64_SUPPORT)
  #define _MCBSP_RCR_RWDREVRS_MASK     0x00000010u
  #define _MCBSP_RCR_RWDREVRS_SHIFT    0x00000004u
  #define  MCBSP_RCR_RWDREVRS_DEFAULT  0x00000000u
  #define  MCBSP_RCR_RWDREVRS_OF(x)    _VALUEOF(x)
  #define  MCBSP_RCR_RWDREVRS_DISABLE  0x00000000u
  #define  MCBSP_RCR_RWDREVRS_ENABLE   0x00000001u
#endif

  #define  MCBSP_RCR_OF(x)             _VALUEOF(x)

#if (C11_SUPPORT | C64_SUPPORT)
  #define MCBSP_RCR_DEFAULT (Uint32)(\
     _PER_FDEFAULT(MCBSP,RCR,RPHASE)\
    |_PER_FDEFAULT(MCBSP,RCR,RFRLEN2)\
    |_PER_FDEFAULT(MCBSP,RCR,RWDLEN2)\
    |_PER_FDEFAULT(MCBSP,RCR,RCOMPAND)\
    |_PER_FDEFAULT(MCBSP,RCR,RFIG)\
    |_PER_FDEFAULT(MCBSP,RCR,RDATDLY)\
    |_PER_FDEFAULT(MCBSP,RCR,RFRLEN1)\
    |_PER_FDEFAULT(MCBSP,RCR,RWDLEN1)\
    |_PER_FDEFAULT(MCBSP,RCR,RWDREVRS)\
  )

  #define MCBSP_RCR_RMK(rphase,rfrlen2,rwdlen2,rcompand,rfig,\
    rdatdly,rfrlen1,rwdlen1,rwdrevrs) (Uint32)(\
     _PER_FMK(MCBSP,RCR,RPHASE,rphase)\
    |_PER_FMK(MCBSP,RCR,RFRLEN2,rfrlen2)\
    |_PER_FMK(MCBSP,RCR,RWDLEN2,rwdlen2)\
    |_PER_FMK(MCBSP,RCR,RCOMPAND,rcompand)\
    |_PER_FMK(MCBSP,RCR,RFIG,rfig)\
    |_PER_FMK(MCBSP,RCR,RDATDLY,rdatdly)\
    |_PER_FMK(MCBSP,RCR,RFRLEN1,rfrlen1)\
    |_PER_FMK(MCBSP,RCR,RWDLEN1,rwdlen1)\
    |_PER_FMK(MCBSP,RCR,RWDREVRS,rwdrevrs)\
  )
#endif

#if (!C11_SUPPORT && !C64_SUPPORT)
  #define MCBSP_RCR_DEFAULT (Uint32)(\
     _PER_FDEFAULT(MCBSP,RCR,RPHASE)\
    |_PER_FDEFAULT(MCBSP,RCR,RFRLEN2)\
    |_PER_FDEFAULT(MCBSP,RCR,RWDLEN2)\
    |_PER_FDEFAULT(MCBSP,RCR,RCOMPAND)\
    |_PER_FDEFAULT(MCBSP,RCR,RFIG)\
    |_PER_FDEFAULT(MCBSP,RCR,RDATDLY)\
    |_PER_FDEFAULT(MCBSP,RCR,RFRLEN1)\
    |_PER_FDEFAULT(MCBSP,RCR,RWDLEN1)\
  )

  #define MCBSP_RCR_RMK(rphase,rfrlen2,rwdlen2,rcompand,rfig,\
    rdatdly,rfrlen1,rwdlen1) (Uint32)(\
     _PER_FMK(MCBSP,RCR,RPHASE,rphase)\
    |_PER_FMK(MCBSP,RCR,RFRLEN2,rfrlen2)\
    |_PER_FMK(MCBSP,RCR,RWDLEN2,rwdlen2)\
    |_PER_FMK(MCBSP,RCR,RCOMPAND,rcompand)\
    |_PER_FMK(MCBSP,RCR,RFIG,rfig)\
    |_PER_FMK(MCBSP,RCR,RDATDLY,rdatdly)\
    |_PER_FMK(MCBSP,RCR,RFRLEN1,rfrlen1)\
    |_PER_FMK(MCBSP,RCR,RWDLEN1,rwdlen1)\
  )
#endif

  #define _MCBSP_RCR_FGET(N,FIELD)\
    _PER_FGET(_MCBSP_RCR##N##_ADDR,MCBSP,RCR,##FIELD)

  #define _MCBSP_RCR_FSET(N,FIELD,field)\
    _PER_FSET(_MCBSP_RCR##N##_ADDR,MCBSP,RCR,##FIELD,field)

  #define _MCBSP_RCR_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCBSP_RCR##N##_ADDR,MCBSP,RCR,##FIELD,##SYM)

  #define _MCBSP_RCR0_FGET(FIELD) _MCBSP_RCR_FGET(0,##FIELD)
  #define _MCBSP_RCR1_FGET(FIELD) _MCBSP_RCR_FGET(1,##FIELD)
#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_RCR2_FGET(FIELD) _MCBSP_RCR_FGET(2,##FIELD)
#endif

  #define _MCBSP_RCR0_FSET(FIELD,f) _MCBSP_RCR_FSET(0,##FIELD,f)
  #define _MCBSP_RCR1_FSET(FIELD,f) _MCBSP_RCR_FSET(1,##FIELD,f)
#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_RCR2_FSET(FIELD,f) _MCBSP_RCR_FSET(2,##FIELD,f)
#endif

  #define _MCBSP_RCR0_FSETS(FIELD,SYM) _MCBSP_RCR_FSETS(0,##FIELD,##SYM)
  #define _MCBSP_RCR1_FSETS(FIELD,SYM) _MCBSP_RCR_FSETS(1,##FIELD,##SYM)
#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_RCR2_FSETS(FIELD,SYM) _MCBSP_RCR_FSETS(2,##FIELD,##SYM)
#endif


/******************************************************************************\
* _____________________
* |                   |
* |  X C R            |
* |___________________|
*
* XCR0  - serial port 0 transmit control register
* XCR1  - serial port 1 transmit control register
* XCR2  - serial port 2 transmit control register (1)
*
* (1) only supported on devices with three serial ports
*
* FIELDS (msb -> lsb)
* (rw) XPHASE
* (rw) XFRLEN2
* (rw) XWDLEN2
* (rw) XCOMPAND
* (rw) XFIG
* (rw) XDATDLY
* (rw) XFRLEN1
* (rw) XWDLEN1
* (rw) XWDREVRS (2)
*
* (2) - C11_SUPPORT /C64_SUPPORT only
*
\******************************************************************************/
  #define _MCBSP_XCR_OFFSET            4

  #define _MCBSP_XCR0_ADDR             0x018C0010u
  #define _MCBSP_XCR1_ADDR             0x01900010u

#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_XCR2_ADDR             0x01A40010u
#endif

  #define _MCBSP_XCR_XPHASE_MASK       0x80000000u
  #define _MCBSP_XCR_XPHASE_SHIFT      0x0000001Fu
  #define  MCBSP_XCR_XPHASE_DEFAULT    0x00000000u
  #define  MCBSP_XCR_XPHASE_OF(x)      _VALUEOF(x)
  #define  MCBSP_XCR_XPHASE_SINGLE     0x00000000u
  #define  MCBSP_XCR_XPHASE_DUAL       0x00000001u

  #define _MCBSP_XCR_XFRLEN2_MASK      0x7F000000u
  #define _MCBSP_XCR_XFRLEN2_SHIFT     0x00000018u
  #define  MCBSP_XCR_XFRLEN2_DEFAULT   0x00000000u
  #define  MCBSP_XCR_XFRLEN2_OF(x)     _VALUEOF(x)

  #define _MCBSP_XCR_XWDLEN2_MASK      0x00E00000u
  #define _MCBSP_XCR_XWDLEN2_SHIFT     0x00000015u
  #define  MCBSP_XCR_XWDLEN2_DEFAULT   0x00000000u
  #define  MCBSP_XCR_XWDLEN2_OF(x)     _VALUEOF(x)
  #define  MCBSP_XCR_XWDLEN2_8BIT      0x00000000u
  #define  MCBSP_XCR_XWDLEN2_12BIT     0x00000001u
  #define  MCBSP_XCR_XWDLEN2_16BIT     0x00000002u
  #define  MCBSP_XCR_XWDLEN2_20BIT     0x00000003u
  #define  MCBSP_XCR_XWDLEN2_24BIT     0x00000004u
  #define  MCBSP_XCR_XWDLEN2_32BIT     0x00000005u

  #define _MCBSP_XCR_XCOMPAND_MASK     0x00180000u
  #define _MCBSP_XCR_XCOMPAND_SHIFT    0x00000013u
  #define  MCBSP_XCR_XCOMPAND_DEFAULT  0x00000000u
  #define  MCBSP_XCR_XCOMPAND_OF(x)    _VALUEOF(x)
  #define  MCBSP_XCR_XCOMPAND_MSB      0x00000000u
  #define  MCBSP_XCR_XCOMPAND_8BITLSB  0x00000001u
  #define  MCBSP_XCR_XCOMPAND_ULAW     0x00000002u
  #define  MCBSP_XCR_XCOMPAND_ALAW     0x00000003u

  #define _MCBSP_XCR_XFIG_MASK         0x00040000u
  #define _MCBSP_XCR_XFIG_SHIFT        0x00000012u
  #define  MCBSP_XCR_XFIG_DEFAULT      0x00000000u
  #define  MCBSP_XCR_XFIG_OF(x)        _VALUEOF(x)
  #define  MCBSP_XCR_XFIG_NO           0x00000000u
  #define  MCBSP_XCR_XFIG_YES          0x00000001u

  #define _MCBSP_XCR_XDATDLY_MASK      0x00030000u
  #define _MCBSP_XCR_XDATDLY_SHIFT     0x00000010u
  #define  MCBSP_XCR_XDATDLY_DEFAULT   0x00000000u
  #define  MCBSP_XCR_XDATDLY_OF(x)     _VALUEOF(x)
  #define  MCBSP_XCR_XDATDLY_0BIT      0x00000000u
  #define  MCBSP_XCR_XDATDLY_1BIT      0x00000001u
  #define  MCBSP_XCR_XDATDLY_2BIT      0x00000002u

  #define _MCBSP_XCR_XFRLEN1_MASK      0x00007F00u
  #define _MCBSP_XCR_XFRLEN1_SHIFT     0x00000008u
  #define  MCBSP_XCR_XFRLEN1_DEFAULT   0x00000000u
  #define  MCBSP_XCR_XFRLEN1_OF(x)     _VALUEOF(x)

  #define _MCBSP_XCR_XWDLEN1_MASK      0x000000E0u
  #define _MCBSP_XCR_XWDLEN1_SHIFT     0x00000005u
  #define  MCBSP_XCR_XWDLEN1_DEFAULT   0x00000000u
  #define  MCBSP_XCR_XWDLEN1_OF(x)     _VALUEOF(x)
  #define  MCBSP_XCR_XWDLEN1_8BIT      0x00000000u
  #define  MCBSP_XCR_XWDLEN1_12BIT     0x00000001u
  #define  MCBSP_XCR_XWDLEN1_16BIT     0x00000002u
  #define  MCBSP_XCR_XWDLEN1_20BIT     0x00000003u
  #define  MCBSP_XCR_XWDLEN1_24BIT     0x00000004u
  #define  MCBSP_XCR_XWDLEN1_32BIT     0x00000005u

#if (C11_SUPPORT | C64_SUPPORT)
  #define _MCBSP_XCR_XWDREVRS_MASK     0x00000010u
  #define _MCBSP_XCR_XWDREVRS_SHIFT    0x00000004u
  #define  MCBSP_XCR_XWDREVRS_DEFAULT  0x00000000u
  #define  MCBSP_XCR_XWDREVRS_OF(x)    _VALUEOF(x)
  #define  MCBSP_XCR_XWDREVRS_DISABLE  0x00000000u
  #define  MCBSP_XCR_XWDREVRS_ENABLE   0x00000001u
#endif

  #define  MCBSP_XCR_OF(x)             _VALUEOF(x)

#if (C11_SUPPORT | C64_SUPPORT)
  #define MCBSP_XCR_DEFAULT (Uint32)(\
     _PER_FDEFAULT(MCBSP,XCR,XPHASE)\
    |_PER_FDEFAULT(MCBSP,XCR,XFRLEN2)\
    |_PER_FDEFAULT(MCBSP,XCR,XWDLEN2)\
    |_PER_FDEFAULT(MCBSP,XCR,XCOMPAND)\
    |_PER_FDEFAULT(MCBSP,XCR,XFIG)\
    |_PER_FDEFAULT(MCBSP,XCR,XDATDLY)\
    |_PER_FDEFAULT(MCBSP,XCR,XFRLEN1)\
    |_PER_FDEFAULT(MCBSP,XCR,XWDLEN1)\
    |_PER_FDEFAULT(MCBSP,XCR,XWDREVRS)\
  )

  #define MCBSP_XCR_RMK(xphase,xfrlen2,xwdlen2,xcompand,xfig,\
    xdatdly,xfrlen1,xwdlen1,xwdrevrs) (Uint32)(\
     _PER_FMK(MCBSP,XCR,XPHASE,xphase)\
    |_PER_FMK(MCBSP,XCR,XFRLEN2,xfrlen2)\
    |_PER_FMK(MCBSP,XCR,XWDLEN2,xwdlen2)\
    |_PER_FMK(MCBSP,XCR,XCOMPAND,xcompand)\
    |_PER_FMK(MCBSP,XCR,XFIG,xfig)\
    |_PER_FMK(MCBSP,XCR,XDATDLY,xdatdly)\
    |_PER_FMK(MCBSP,XCR,XFRLEN1,xfrlen1)\
    |_PER_FMK(MCBSP,XCR,XWDLEN1,xwdlen1)\
    |_PER_FMK(MCBSP,XCR,XWDREVRS,xwdrevrs)\
  )
#endif

#if (!C11_SUPPORT && !C64_SUPPORT)
  #define MCBSP_XCR_DEFAULT (Uint32)(\
     _PER_FDEFAULT(MCBSP,XCR,XPHASE)\
    |_PER_FDEFAULT(MCBSP,XCR,XFRLEN2)\
    |_PER_FDEFAULT(MCBSP,XCR,XWDLEN2)\
    |_PER_FDEFAULT(MCBSP,XCR,XCOMPAND)\
    |_PER_FDEFAULT(MCBSP,XCR,XFIG)\
    |_PER_FDEFAULT(MCBSP,XCR,XDATDLY)\
    |_PER_FDEFAULT(MCBSP,XCR,XFRLEN1)\
    |_PER_FDEFAULT(MCBSP,XCR,XWDLEN1)\
  )

  #define MCBSP_XCR_RMK(xphase,xfrlen2,xwdlen2,xcompand,xfig,\
    xdatdly,xfrlen1,xwdlen1) (Uint32)(\
     _PER_FMK(MCBSP,XCR,XPHASE,xphase)\
    |_PER_FMK(MCBSP,XCR,XFRLEN2,xfrlen2)\
    |_PER_FMK(MCBSP,XCR,XWDLEN2,xwdlen2)\
    |_PER_FMK(MCBSP,XCR,XCOMPAND,xcompand)\
    |_PER_FMK(MCBSP,XCR,XFIG,xfig)\
    |_PER_FMK(MCBSP,XCR,XDATDLY,xdatdly)\
    |_PER_FMK(MCBSP,XCR,XFRLEN1,xfrlen1)\
    |_PER_FMK(MCBSP,XCR,XWDLEN1,xwdlen1)\
  )
#endif

  #define _MCBSP_XCR_FGET(N,FIELD)\
    _PER_FGET(_MCBSP_XCR##N##_ADDR,MCBSP,XCR,##FIELD)

  #define _MCBSP_XCR_FSET(N,FIELD,field)\
    _PER_FSET(_MCBSP_XCR##N##_ADDR,MCBSP,XCR,##FIELD,field)

  #define _MCBSP_XCR_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCBSP_XCR##N##_ADDR,MCBSP,XCR,##FIELD,##SYM)

  #define _MCBSP_XCR0_FGET(FIELD) _MCBSP_XCR_FGET(0,##FIELD)
  #define _MCBSP_XCR1_FGET(FIELD) _MCBSP_XCR_FGET(1,##FIELD)
#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_XCR2_FGET(FIELD) _MCBSP_XCR_FGET(2,##FIELD)
#endif

  #define _MCBSP_XCR0_FSET(FIELD,f) _MCBSP_XCR_FSET(0,##FIELD,f)
  #define _MCBSP_XCR1_FSET(FIELD,f) _MCBSP_XCR_FSET(1,##FIELD,f)
#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_XCR2_FSET(FIELD,f) _MCBSP_XCR_FSET(2,##FIELD,f)
#endif

  #define _MCBSP_XCR0_FSETS(FIELD,SYM) _MCBSP_XCR_FSETS(0,##FIELD,##SYM)
  #define _MCBSP_XCR1_FSETS(FIELD,SYM) _MCBSP_XCR_FSETS(1,##FIELD,##SYM)
#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_XCR2_FSETS(FIELD,SYM) _MCBSP_XCR_FSETS(2,##FIELD,##SYM)
#endif


/******************************************************************************\
* _____________________
* |                   |
* |  S R G R          |
* |___________________|
*
* SRGR0 - serial port 0 sample rate generator register
* SRGR1 - serial port 1 sample rate generator register
* SRGR2 - serial port 2 sample rate generator register (1)
*
* (1) only supported on devices with three serial ports
*
* FIELDS (msb -> lsb)
* (rw) GSYNC
* (rw) CLKSP
* (rw) CLKSM
* (rw) FSGM
* (rw) FPER
* (rw) FWID
* (rw) CLKGDV
*
\******************************************************************************/
  #define _MCBSP_SRGR_OFFSET           5

  #define _MCBSP_SRGR0_ADDR            0x018C0014u
  #define _MCBSP_SRGR1_ADDR            0x01900014u

#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_SRGR2_ADDR            0x01A40014u
#endif

  #define _MCBSP_SRGR_GSYNC_MASK       0x80000000u
  #define _MCBSP_SRGR_GSYNC_SHIFT      0x0000001Fu
  #define  MCBSP_SRGR_GSYNC_DEFAULT    0x00000000u
  #define  MCBSP_SRGR_GSYNC_OF(x)      _VALUEOF(x)
  #define  MCBSP_SRGR_GSYNC_FREE       0x00000000u
  #define  MCBSP_SRGR_GSYNC_SYNC       0x00000001u

  #define _MCBSP_SRGR_CLKSP_MASK       0x40000000u
  #define _MCBSP_SRGR_CLKSP_SHIFT      0x0000001Eu
  #define  MCBSP_SRGR_CLKSP_DEFAULT    0x00000000u
  #define  MCBSP_SRGR_CLKSP_OF(x)      _VALUEOF(x)
  #define  MCBSP_SRGR_CLKSP_RISING     0x00000000u
  #define  MCBSP_SRGR_CLKSP_FALLING    0x00000001u

  #define _MCBSP_SRGR_CLKSM_MASK       0x20000000u
  #define _MCBSP_SRGR_CLKSM_SHIFT      0x0000001Du
  #define  MCBSP_SRGR_CLKSM_DEFAULT    0x00000001u
  #define  MCBSP_SRGR_CLKSM_OF(x)      _VALUEOF(x)
  #define  MCBSP_SRGR_CLKSM_CLKS       0x00000000u
  #define  MCBSP_SRGR_CLKSM_INTERNAL   0x00000001u

  #define _MCBSP_SRGR_FSGM_MASK        0x10000000u
  #define _MCBSP_SRGR_FSGM_SHIFT       0x0000001Cu
  #define  MCBSP_SRGR_FSGM_DEFAULT     0x00000000u
  #define  MCBSP_SRGR_FSGM_OF(x)       _VALUEOF(x)
  #define  MCBSP_SRGR_FSGM_DXR2XSR     0x00000000u
  #define  MCBSP_SRGR_FSGM_FSG         0x00000001u

  #define _MCBSP_SRGR_FPER_MASK        0x0FFF0000u
  #define _MCBSP_SRGR_FPER_SHIFT       0x00000010u
  #define  MCBSP_SRGR_FPER_DEFAULT     0x00000000u
  #define  MCBSP_SRGR_FPER_OF(x)       _VALUEOF(x)

  #define _MCBSP_SRGR_FWID_MASK        0x0000FF00u
  #define _MCBSP_SRGR_FWID_SHIFT       0x00000008u
  #define  MCBSP_SRGR_FWID_DEFAULT     0x00000000u
  #define  MCBSP_SRGR_FWID_OF(x)       _VALUEOF(x)

  #define _MCBSP_SRGR_CLKGDV_MASK      0x000000FFu
  #define _MCBSP_SRGR_CLKGDV_SHIFT     0x00000000u
  #define  MCBSP_SRGR_CLKGDV_DEFAULT   0x00000001u
  #define  MCBSP_SRGR_CLKGDV_OF(x)     _VALUEOF(x)

  #define  MCBSP_SRGR_OF(x)            _VALUEOF(x)

  #define MCBSP_SRGR_DEFAULT (Uint32)(\
     _PER_FDEFAULT(MCBSP,SRGR,GSYNC)\
    |_PER_FDEFAULT(MCBSP,SRGR,CLKSP)\
    |_PER_FDEFAULT(MCBSP,SRGR,CLKSM)\
    |_PER_FDEFAULT(MCBSP,SRGR,FSGM)\
    |_PER_FDEFAULT(MCBSP,SRGR,FPER)\
    |_PER_FDEFAULT(MCBSP,SRGR,FWID)\
    |_PER_FDEFAULT(MCBSP,SRGR,CLKGDV)\
  )

  #define MCBSP_SRGR_RMK(gsync,clksp,clksm,fsgm,fper,fwid,clkgdv) (Uint32)(\
     _PER_FMK(MCBSP,SRGR,GSYNC,gsync)\
    |_PER_FMK(MCBSP,SRGR,CLKSP,clksp)\
    |_PER_FMK(MCBSP,SRGR,CLKSM,clksm)\
    |_PER_FMK(MCBSP,SRGR,FSGM,fsgm)\
    |_PER_FMK(MCBSP,SRGR,FPER,fper)\
    |_PER_FMK(MCBSP,SRGR,FWID,fwid)\
    |_PER_FMK(MCBSP,SRGR,CLKGDV,clkgdv)\
  )

  #define _MCBSP_SRGR_FGET(N,FIELD)\
    _PER_FGET(_MCBSP_SRGR##N##_ADDR,MCBSP,SRGR,##FIELD)

  #define _MCBSP_SRGR_FSET(N,FIELD,field)\
    _PER_FSET(_MCBSP_SRGR##N##_ADDR,MCBSP,SRGR,##FIELD,field)

  #define _MCBSP_SRGR_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCBSP_SRGR##N##_ADDR,MCBSP,SRGR,##FIELD,##SYM)

  #define _MCBSP_SRGR0_FGET(FIELD) _MCBSP_SRGR_FGET(0,##FIELD)
  #define _MCBSP_SRGR1_FGET(FIELD) _MCBSP_SRGR_FGET(1,##FIELD)
#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_SRGR2_FGET(FIELD) _MCBSP_SRGR_FGET(2,##FIELD)
#endif

  #define _MCBSP_SRGR0_FSET(FIELD,f) _MCBSP_SRGR_FSET(0,##FIELD,f)
  #define _MCBSP_SRGR1_FSET(FIELD,f) _MCBSP_SRGR_FSET(1,##FIELD,f)
#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_SRGR2_FSET(FIELD,f) _MCBSP_SRGR_FSET(2,##FIELD,f)
#endif

  #define _MCBSP_SRGR0_FSETS(FIELD,SYM) _MCBSP_SRGR_FSETS(0,##FIELD,##SYM)
  #define _MCBSP_SRGR1_FSETS(FIELD,SYM) _MCBSP_SRGR_FSETS(1,##FIELD,##SYM)
#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_SRGR2_FSETS(FIELD,SYM) _MCBSP_SRGR_FSETS(2,##FIELD,##SYM)
#endif


/******************************************************************************\
* _____________________
* |                   |
* |  M C R            |
* |___________________|
*
* MCR0  - serial port 0 multichannel control register
* MCR1  - serial port 1 multichannel control register
* MCR2  - serial port 2 multichannel control register (1)
*
* (1) only supported on devices with three serial ports
*
* FIELDS (msb -> lsb)
* (rw) XMCME (1)
* (rw) XPBBLK
* (rw) XPABLK
* (r)  XCBLK
* (rw) XMCM
* (rw) RMCME (1)
* (rw) RPBBLK
* (rw) RPABLK
* (r)  RCBLK
* (rw) RMCM
*
* (1) C64_SUPPORT only
\******************************************************************************/
  #define _MCBSP_MCR_OFFSET            6

  #define _MCBSP_MCR0_ADDR             0x018C0018u
  #define _MCBSP_MCR1_ADDR             0x01900018u

#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_MCR2_ADDR             0x01A40018u
#endif

#if (C64_SUPPORT)
  #define _MCBSP_MCR_XMCME_MASK       0x02000000u
  #define _MCBSP_MCR_XMCME_SHIFT      0x00000019u
  #define  MCBSP_MCR_XMCME_DEFAULT    0x00000000u
  #define  MCBSP_MCR_XMCME_OF(x)      _VALUEOF(x)
  #define  MCBSP_MCR_XMCME_NORMAL     0x00000000u
  #define  MCBSP_MCR_XMCME_ENHANCED   0x00000001u
#endif

  #define _MCBSP_MCR_XPBBLK_MASK       0x01800000u
  #define _MCBSP_MCR_XPBBLK_SHIFT      0x00000017u
  #define  MCBSP_MCR_XPBBLK_DEFAULT    0x00000000u
  #define  MCBSP_MCR_XPBBLK_OF(x)      _VALUEOF(x)
  #define  MCBSP_MCR_XPBBLK_SF1        0x00000000u
  #define  MCBSP_MCR_XPBBLK_SF3        0x00000001u
  #define  MCBSP_MCR_XPBBLK_SF5        0x00000002u
  #define  MCBSP_MCR_XPBBLK_SF7        0x00000003u

  #define _MCBSP_MCR_XPABLK_MASK       0x00600000u
  #define _MCBSP_MCR_XPABLK_SHIFT      0x00000015u
  #define  MCBSP_MCR_XPABLK_DEFAULT    0x00000000u
  #define  MCBSP_MCR_XPABLK_OF(x)      _VALUEOF(x)
  #define  MCBSP_MCR_XPABLK_SF0        0x00000000u
  #define  MCBSP_MCR_XPABLK_SF2        0x00000001u
  #define  MCBSP_MCR_XPABLK_SF4        0x00000002u
  #define  MCBSP_MCR_XPABLK_SF6        0x00000003u

  #define _MCBSP_MCR_XCBLK_MASK        0x001C0000u
  #define _MCBSP_MCR_XCBLK_SHIFT       0x00000012u
  #define  MCBSP_MCR_XCBLK_DEFAULT     0x00000000u
  #define  MCBSP_MCR_XCBLK_OF(x)       _VALUEOF(x)
  #define  MCBSP_MCR_XCBLK_SF0         0x00000000u
  #define  MCBSP_MCR_XCBLK_SF1         0x00000001u
  #define  MCBSP_MCR_XCBLK_SF2         0x00000002u
  #define  MCBSP_MCR_XCBLK_SF3         0x00000003u
  #define  MCBSP_MCR_XCBLK_SF4         0x00000004u
  #define  MCBSP_MCR_XCBLK_SF5         0x00000005u
  #define  MCBSP_MCR_XCBLK_SF6         0x00000006u
  #define  MCBSP_MCR_XCBLK_SF7         0x00000007u

  #define _MCBSP_MCR_XMCM_MASK         0x00030000u
  #define _MCBSP_MCR_XMCM_SHIFT        0x00000010u
  #define  MCBSP_MCR_XMCM_DEFAULT      0x00000000u
  #define  MCBSP_MCR_XMCM_OF(x)        _VALUEOF(x)
  #define  MCBSP_MCR_XMCM_ENNOMASK     0x00000000u
  #define  MCBSP_MCR_XMCM_DISXP        0x00000001u
  #define  MCBSP_MCR_XMCM_ENMASK       0x00000002u
  #define  MCBSP_MCR_XMCM_DISRP        0x00000003u

#if (C64_SUPPORT)
  #define _MCBSP_MCR_RMCME_MASK       0x00000200u
  #define _MCBSP_MCR_RMCME_SHIFT      0x00000009u
  #define  MCBSP_MCR_RMCME_DEFAULT    0x00000000u
  #define  MCBSP_MCR_RMCME_OF(x)      _VALUEOF(x)
  #define  MCBSP_MCR_RMCME_NORMAL     0x00000000u
  #define  MCBSP_MCR_RMCME_ENHANCED   0x00000001u
#endif

  #define _MCBSP_MCR_RPBBLK_MASK       0x00000180u
  #define _MCBSP_MCR_RPBBLK_SHIFT      0x00000007u
  #define  MCBSP_MCR_RPBBLK_DEFAULT    0x00000000u
  #define  MCBSP_MCR_RPBBLK_OF(x)      _VALUEOF(x)
  #define  MCBSP_MCR_RPBBLK_SF1        0x00000000u
  #define  MCBSP_MCR_RPBBLK_SF3        0x00000001u
  #define  MCBSP_MCR_RPBBLK_SF5        0x00000002u
  #define  MCBSP_MCR_RPBBLK_SF7        0x00000003u

  #define _MCBSP_MCR_RPABLK_MASK       0x00000060u
  #define _MCBSP_MCR_RPABLK_SHIFT      0x00000005u
  #define  MCBSP_MCR_RPABLK_DEFAULT    0x00000000u
  #define  MCBSP_MCR_RPABLK_OF(x)      _VALUEOF(x)
  #define  MCBSP_MCR_RPABLK_SF0        0x00000000u
  #define  MCBSP_MCR_RPABLK_SF2        0x00000001u
  #define  MCBSP_MCR_RPABLK_SF4        0x00000002u
  #define  MCBSP_MCR_RPABLK_SF6        0x00000003u

  #define _MCBSP_MCR_RCBLK_MASK        0x0000001Cu
  #define _MCBSP_MCR_RCBLK_SHIFT       0x00000002u
  #define  MCBSP_MCR_RCBLK_DEFAULT     0x00000000u
  #define  MCBSP_MCR_RCBLK_OF(x)       _VALUEOF(x)
  #define  MCBSP_MCR_RCBLK_SF0         0x00000000u
  #define  MCBSP_MCR_RCBLK_SF1         0x00000001u
  #define  MCBSP_MCR_RCBLK_SF2         0x00000002u
  #define  MCBSP_MCR_RCBLK_SF3         0x00000003u
  #define  MCBSP_MCR_RCBLK_SF4         0x00000004u
  #define  MCBSP_MCR_RCBLK_SF5         0x00000005u
  #define  MCBSP_MCR_RCBLK_SF6         0x00000006u
  #define  MCBSP_MCR_RCBLK_SF7         0x00000007u

  #define _MCBSP_MCR_RMCM_MASK         0x00000001u
  #define _MCBSP_MCR_RMCM_SHIFT        0x00000000u
  #define  MCBSP_MCR_RMCM_DEFAULT      0x00000000u
  #define  MCBSP_MCR_RMCM_OF(x)        _VALUEOF(x)
  #define  MCBSP_MCR_RMCM_CHENABLE     0x00000000u
  #define  MCBSP_MCR_RMCM_ELDISABLE    0x00000001u

  #define  MCBSP_MCR_OF(x)             _VALUEOF(x)


#if (!C64_SUPPORT)
  #define MCBSP_MCR_DEFAULT (Uint32)(\
     _PER_FDEFAULT(MCBSP,MCR,XPBBLK)\
    |_PER_FDEFAULT(MCBSP,MCR,XPABLK)\
    |_PER_FDEFAULT(MCBSP,MCR,XCBLK)\
    |_PER_FDEFAULT(MCBSP,MCR,XMCM)\
    |_PER_FDEFAULT(MCBSP,MCR,RPBBLK)\
    |_PER_FDEFAULT(MCBSP,MCR,RPABLK)\
    |_PER_FDEFAULT(MCBSP,MCR,RCBLK)\
    |_PER_FDEFAULT(MCBSP,MCR,RMCM)\
  )

  #define MCBSP_MCR_RMK(xpbblk,xpablk,xmcm,rpbblk,rpablk,rmcm) (Uint32)(\
     _PER_FMK(MCBSP,MCR,XPBBLK,xpbblk)\
    |_PER_FMK(MCBSP,MCR,XPABLK,xpablk)\
    |_PER_FMK(MCBSP,MCR,XMCM,xmcm)\
    |_PER_FMK(MCBSP,MCR,RPBBLK,rpbblk)\
    |_PER_FMK(MCBSP,MCR,RPABLK,rpablk)\
    |_PER_FMK(MCBSP,MCR,RMCM,rmcm)\
  )
#endif

#if (C64_SUPPORT)
  #define MCBSP_MCR_DEFAULT (Uint32)(\
     _PER_FDEFAULT(MCBSP,MCR,XMCME)\
    |_PER_FDEFAULT(MCBSP,MCR,XPBBLK)\
    |_PER_FDEFAULT(MCBSP,MCR,XPABLK)\
    |_PER_FDEFAULT(MCBSP,MCR,XCBLK)\
    |_PER_FDEFAULT(MCBSP,MCR,XMCM)\
    |_PER_FDEFAULT(MCBSP,MCR,RMCME)\
    |_PER_FDEFAULT(MCBSP,MCR,RPBBLK)\
    |_PER_FDEFAULT(MCBSP,MCR,RPABLK)\
    |_PER_FDEFAULT(MCBSP,MCR,RCBLK)\
    |_PER_FDEFAULT(MCBSP,MCR,RMCM)\
  )

  #define MCBSP_MCR_RMK(xmcme,xpbblk,xpablk,xmcm,rmcme,rpbblk,rpablk,rmcm) (Uint32)(\
     _PER_FMK(MCBSP,MCR,XMCME,xmcme)\
    |_PER_FMK(MCBSP,MCR,XPBBLK,xpbblk)\
    |_PER_FMK(MCBSP,MCR,XPABLK,xpablk)\
    |_PER_FMK(MCBSP,MCR,XMCM,xmcm)\
    |_PER_FMK(MCBSP,MCR,RMCME,rmcme)\
    |_PER_FMK(MCBSP,MCR,RPBBLK,rpbblk)\
    |_PER_FMK(MCBSP,MCR,RPABLK,rpablk)\
    |_PER_FMK(MCBSP,MCR,RMCM,rmcm)\
  )
#endif

  #define _MCBSP_MCR_FGET(N,FIELD)\
    _PER_FGET(_MCBSP_MCR##N##_ADDR,MCBSP,MCR,##FIELD)

  #define _MCBSP_MCR_FSET(N,FIELD,field)\
    _PER_FSET(_MCBSP_MCR##N##_ADDR,MCBSP,MCR,##FIELD,field)

  #define _MCBSP_MCR_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCBSP_MCR##N##_ADDR,MCBSP,MCR,##FIELD,##SYM)

  #define _MCBSP_MCR0_FGET(FIELD) _MCBSP_MCR_FGET(0,##FIELD)
  #define _MCBSP_MCR1_FGET(FIELD) _MCBSP_MCR_FGET(1,##FIELD)
#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_MCR2_FGET(FIELD) _MCBSP_MCR_FGET(2,##FIELD)
#endif

  #define _MCBSP_MCR0_FSET(FIELD,f) _MCBSP_MCR_FSET(0,##FIELD,f)
  #define _MCBSP_MCR1_FSET(FIELD,f) _MCBSP_MCR_FSET(1,##FIELD,f)
#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_MCR2_FSET(FIELD,f) _MCBSP_MCR_FSET(2,##FIELD,f)
#endif

  #define _MCBSP_MCR0_FSETS(FIELD,SYM) _MCBSP_MCR_FSETS(0,##FIELD,##SYM)
  #define _MCBSP_MCR1_FSETS(FIELD,SYM) _MCBSP_MCR_FSETS(1,##FIELD,##SYM)
#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_MCR2_FSETS(FIELD,SYM) _MCBSP_MCR_FSETS(2,##FIELD,##SYM)
#endif


/******************************************************************************\
* _____________________
* |                   |
* |  R C E R          |
* |___________________|
*
* RCER0 - serial port 0 receive channel enable register
* RCER1 - serial port 1 receive channel enable register
* RCER2 - serial port 2 receive channel enable register (1)
*
* (1) only supported on devices with three serial ports
*
* FIELDS (msb -> lsb)
* (rw) RCEB
* (rw) RCEA
*
\******************************************************************************/
#if (!C64_SUPPORT)
  #define _MCBSP_RCER_OFFSET           7

  #define _MCBSP_RCER0_ADDR            0x018C001Cu
  #define _MCBSP_RCER1_ADDR            0x0190001Cu

#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_RCER2_ADDR            0x01A4001Cu
#endif

  #define _MCBSP_RCER_RCEB_MASK        0xFFFF0000u
  #define _MCBSP_RCER_RCEB_SHIFT       0x00000010u
  #define  MCBSP_RCER_RCEB_DEFAULT     0x00000000u
  #define  MCBSP_RCER_RCEB_OF(x)       _VALUEOF(x)

  #define _MCBSP_RCER_RCEA_MASK        0x0000FFFFu
  #define _MCBSP_RCER_RCEA_SHIFT       0x00000000u
  #define  MCBSP_RCER_RCEA_DEFAULT     0x00000000u
  #define  MCBSP_RCER_RCEA_OF(x)       _VALUEOF(x)


  #define  MCBSP_RCER_OF(x)            _VALUEOF(x)


  #define MCBSP_RCER_DEFAULT (Uint32)(\
     _PER_FDEFAULT(MCBSP,RCER,RCEB)\
    |_PER_FDEFAULT(MCBSP,RCER,RCEA)\
  )

  #define MCBSP_RCER_RMK(rceb,rcea) (Uint32)(\
     _PER_FMK(MCBSP,RCER,RCEB,rceb)\
    |_PER_FMK(MCBSP,RCER,RCEA,rcea)\
  )


  #define _MCBSP_RCER_FGET(N,FIELD)\
    _PER_FGET(_MCBSP_RCER##N##_ADDR,MCBSP,RCER,##FIELD)

  #define _MCBSP_RCER_FSET(N,FIELD,field)\
    _PER_FSET(_MCBSP_RCER##N##_ADDR,MCBSP,RCER,##FIELD,field)

  #define _MCBSP_RCER_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCBSP_RCER##N##_ADDR,MCBSP,RCER,##FIELD,##SYM)

  #define _MCBSP_RCER0_FGET(FIELD) _MCBSP_RCER_FGET(0,##FIELD)
  #define _MCBSP_RCER1_FGET(FIELD) _MCBSP_RCER_FGET(1,##FIELD)
#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_RCER2_FGET(FIELD) _MCBSP_RCER_FGET(2,##FIELD)
#endif

  #define _MCBSP_RCER0_FSET(FIELD,f) _MCBSP_RCER_FSET(0,##FIELD,f)
  #define _MCBSP_RCER1_FSET(FIELD,f) _MCBSP_RCER_FSET(1,##FIELD,f)
#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_RCER2_FSET(FIELD,f) _MCBSP_RCER_FSET(2,##FIELD,f)
#endif

  #define _MCBSP_RCER0_FSETS(FIELD,SYM) _MCBSP_RCER_FSETS(0,##FIELD,##SYM)
  #define _MCBSP_RCER1_FSETS(FIELD,SYM) _MCBSP_RCER_FSETS(1,##FIELD,##SYM)
#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_RCER2_FSETS(FIELD,SYM) _MCBSP_RCER_FSETS(2,##FIELD,##SYM)
#endif

#endif /* !C64_SUPPORT */

/******************************************************************************\
* _____________________
* |                   |
* |  R C E R E 0      |
* |___________________|
*
* RCERE00 - serial port 0 enhanced receive channel enable register 0
* RCERE01 - serial port 1 enhanced receive channel enable register 0
* RCERE02 - serial port 2 enhanced receive channel enable register 0
*
* FIELDS (msb -> lsb)
* (rw) RCE
*
\******************************************************************************/
#if (C64_SUPPORT)
  #define _MCBSP_RCERE0_OFFSET           7

  #define _MCBSP_RCERE00_ADDR            0x018C001Cu
  #define _MCBSP_RCERE01_ADDR            0x0190001Cu
#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_RCERE02_ADDR            0x01A4001Cu
#endif
  #define _MCBSP_RCERE0_RCE_MASK        0xFFFFFFFFu
  #define _MCBSP_RCERE0_RCE_SHIFT       0x00000000u
  #define  MCBSP_RCERE0_RCE_DEFAULT     0x00000000u
  #define  MCBSP_RCERE0_RCE_OF(x)       _VALUEOF(x)

  #define  MCBSP_RCERE0_OF(x)            _VALUEOF(x)

  #define MCBSP_RCERE0_DEFAULT (Uint32)(\
     _PER_FDEFAULT(MCBSP,RCERE0,RCE)\
  )

  #define MCBSP_RCERE0_RMK(rce) (Uint32)(\
     _PER_FMK(MCBSP,RCERE0,RCE,rce) \
  )

  #define _MCBSP_RCERE0_FGET(N,FIELD)\
    _PER_FGET(_MCBSP_RCERE0##N##_ADDR,MCBSP,RCERE0,FIELD)

  #define _MCBSP_RCERE0_FSET(N,FIELD,field)\
    _PER_FSET(_MCBSP_RCERE0##N##_ADDR,MCBSP,RCERE0,FIELD,field)

  #define _MCBSP_RCERE0_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCBSP_RCERE0##N##_ADDR,MCBSP,RCERE0,FIELD,##SYM)

  #define _MCBSP_RCERE00_FGET(FIELD) _MCBSP_RCERE0_FGET(0,##FIELD)
  #define _MCBSP_RCERE01_FGET(FIELD) _MCBSP_RCERE0_FGET(1,##FIELD)
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_RCERE02_FGET(FIELD) _MCBSP_RCERE0_FGET(2,##FIELD)
 #endif

  #define _MCBSP_RCERE00_FSET(FIELD,f) _MCBSP_RCERE0_FSET(0,##FIELD,f)
  #define _MCBSP_RCERE01_FSET(FIELD,f) _MCBSP_RCERE0_FSET(1,##FIELD,f)
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_RCERE02_FSET(FIELD,f) _MCBSP_RCERE0_FSET(2,##FIELD,f)
 #endif

  #define _MCBSP_RCERE00_FSETS(FIELD,SYM) _MCBSP_RCERE0_FSETS(0,##FIELD,##SYM)
  #define _MCBSP_RCERE01_FSETS(FIELD,SYM) _MCBSP_RCERE0_FSETS(1,##FIELD,##SYM)
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_RCERE02_FSETS(FIELD,SYM) _MCBSP_RCERE0_FSETS(2,##FIELD,##SYM)
 #endif
#endif /* C64_SUPPORT */


/******************************************************************************\
* _____________________
* |                   |
* |  R C E R E 1      |
* |___________________|
*
* RCERE10 - serial port 0 enhanced receive channel enable register 1
* RCERE11 - serial port 1 enhanced receive channel enable register 1
* RCERE12 - serial port 2 enhanced receive channel enable register 1
*
* FIELDS (msb -> lsb)
* (rw) RCE
*
\******************************************************************************/
#if (C64_SUPPORT)
  #define _MCBSP_RCERE1_OFFSET           10

  #define _MCBSP_RCERE10_ADDR            0x018C0028u
  #define _MCBSP_RCERE11_ADDR            0x01900028u
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_RCERE12_ADDR            0x01A40028u
 #endif

  #define _MCBSP_RCERE1_RCE_MASK        0xFFFFFFFFu
  #define _MCBSP_RCERE1_RCE_SHIFT       0x00000000u
  #define  MCBSP_RCERE1_RCE_DEFAULT     0x00000000u
  #define  MCBSP_RCERE1_RCE_OF(x)       _VALUEOF(x)

  #define  MCBSP_RCERE1_OF(x)            _VALUEOF(x)

  #define MCBSP_RCERE1_DEFAULT (Uint32)(\
     _PER_FDEFAULT(MCBSP,RCERE1,RCE)\
  )

  #define MCBSP_RCERE1_RMK(rce) (Uint32)(\
     _PER_FMK(MCBSP,RCERE1,RCE,rce)\
  )

  #define _MCBSP_RCERE1_FGET(N,FIELD)\
    _PER_FGET(_MCBSP_RCERE1##N##_ADDR,MCBSP,RCERE1,FIELD)

  #define _MCBSP_RCERE1_FSET(N,FIELD,field)\
    _PER_FSET(_MCBSP_RCERE1##N##_ADDR,MCBSP,RCERE1,FIELD,field)

  #define _MCBSP_RCERE1_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCBSP_RCERE1##N##_ADDR,MCBSP,RCERE1,FIELD,##SYM)

  #define _MCBSP_RCERE10_FGET(FIELD) _MCBSP_RCERE1_FGET(0,##FIELD)
  #define _MCBSP_RCERE11_FGET(FIELD) _MCBSP_RCERE1_FGET(1,##FIELD)
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_RCERE12_FGET(FIELD) _MCBSP_RCERE1_FGET(2,##FIELD)
 #endif

  #define _MCBSP_RCERE10_FSET(FIELD,f) _MCBSP_RCERE1_FSET(0,##FIELD,f)
  #define _MCBSP_RCERE11_FSET(FIELD,f) _MCBSP_RCERE1_FSET(1,##FIELD,f)
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_RCERE12_FSET(FIELD,f) _MCBSP_RCERE1_FSET(2,##FIELD,f)
 #endif

  #define _MCBSP_RCERE10_FSETS(FIELD,SYM) _MCBSP_RCERE1_FSETS(0,##FIELD,##SYM)
  #define _MCBSP_RCERE11_FSETS(FIELD,SYM) _MCBSP_RCERE1_FSETS(1,##FIELD,##SYM)
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_RCERE12_FSETS(FIELD,SYM) _MCBSP_RCERE1_FSETS(2,##FIELD,##SYM)
 #endif
#endif /* C64_SUPPORT */


/******************************************************************************\
* _____________________
* |                   |
* |  R C E R E 2      |
* |___________________|
*
* RCERE20 - serial port 0 enhanced receive channel enable register 2
* RCERE21 - serial port 1 enhanced receive channel enable register 2
* RCERE22 - serial port 2 enhanced receive channel enable register 2
*
* FIELDS (msb -> lsb)
* (rw) RCE
*
\******************************************************************************/
#if (C64_SUPPORT)
  #define _MCBSP_RCERE2_OFFSET           0xC

  #define _MCBSP_RCERE20_ADDR            0x018C0030u
  #define _MCBSP_RCERE21_ADDR            0x01900030u
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_RCERE22_ADDR            0x01A40030u
 #endif

  #define _MCBSP_RCERE2_RCE_MASK        0xFFFFFFFFu
  #define _MCBSP_RCERE2_RCE_SHIFT       0x00000000u
  #define  MCBSP_RCERE2_RCE_DEFAULT     0x00000000u
  #define  MCBSP_RCERE2_RCE_OF(x)       _VALUEOF(x)

  #define  MCBSP_RCERE2_OF(x)            _VALUEOF(x)

  #define MCBSP_RCERE2_DEFAULT (Uint32)(\
     _PER_FDEFAULT(MCBSP,RCERE2,RCE)\
  )

  #define MCBSP_RCERE2_RMK(rce) (Uint32)(\
     _PER_FMK(MCBSP,RCERE2,RCE,rce) \
  )

  #define _MCBSP_RCERE2_FGET(N,FIELD)\
    _PER_FGET(_MCBSP_RCERE2##N##_ADDR,MCBSP,RCERE2,FIELD)

  #define _MCBSP_RCERE2_FSET(N,FIELD,field)\
    _PER_FSET(_MCBSP_RCERE2##N##_ADDR,MCBSP,RCERE2,FIELD,field)

  #define _MCBSP_RCERE2_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCBSP_RCERE2##N##_ADDR,MCBSP,RCERE2,FIELD,##SYM)

  #define _MCBSP_RCERE20_FGET(FIELD) _MCBSP_RCERE2_FGET(0,##FIELD)
  #define _MCBSP_RCERE21_FGET(FIELD) _MCBSP_RCERE2_FGET(1,##FIELD)
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_RCERE22_FGET(FIELD) _MCBSP_RCERE2_FGET(2,##FIELD)
 #endif

  #define _MCBSP_RCERE20_FSET(FIELD,f) _MCBSP_RCERE2_FSET(0,##FIELD,f)
  #define _MCBSP_RCERE21_FSET(FIELD,f) _MCBSP_RCERE2_FSET(1,##FIELD,f)
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_RCERE22_FSET(FIELD,f) _MCBSP_RCERE2_FSET(2,##FIELD,f)
 #endif

  #define _MCBSP_RCERE20_FSETS(FIELD,SYM) _MCBSP_RCERE2_FSETS(0,##FIELD,##SYM)
  #define _MCBSP_RCERE21_FSETS(FIELD,SYM) _MCBSP_RCERE2_FSETS(1,##FIELD,##SYM)
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_RCERE22_FSETS(FIELD,SYM) _MCBSP_RCERE2_FSETS(2,##FIELD,##SYM)
 #endif
#endif /* C64_SUPPORT */


/******************************************************************************\
* _____________________
* |                   |
* |  R C E R E 3      |
* |___________________|
*
* RCERE30 - serial port 0 enhanced receive channel enable register 3
* RCERE31 - serial port 1 enhanced receive channel enable register 3
* RCERE32 - serial port 2 enhanced receive channel enable register 3
*
* FIELDS (msb -> lsb)
* (rw) RCE
*
\******************************************************************************/
#if (C64_SUPPORT)
  #define _MCBSP_RCERE3_OFFSET           0xE

  #define _MCBSP_RCERE30_ADDR            0x018C0038u
  #define _MCBSP_RCERE31_ADDR            0x01900038u
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_RCERE32_ADDR            0x01A40038u
 #endif

  #define _MCBSP_RCERE3_RCE_MASK        0xFFFFFFFFu
  #define _MCBSP_RCERE3_RCE_SHIFT       0x00000000u
  #define  MCBSP_RCERE3_RCE_DEFAULT     0x00000000u
  #define  MCBSP_RCERE3_RCE_OF(x)       _VALUEOF(x)

  #define  MCBSP_RCERE3_OF(x)            _VALUEOF(x)

  #define MCBSP_RCERE3_DEFAULT (Uint32)(\
     _PER_FDEFAULT(MCBSP,RCERE3,RCE)\
  )

  #define MCBSP_RCERE3_RMK(rce) (Uint32)(\
     _PER_FMK(MCBSP,RCERE3,RCE,rce)\
  )

  #define _MCBSP_RCERE3_FGET(N,FIELD)\
    _PER_FGET(_MCBSP_RCERE3##N##_ADDR,MCBSP,RCERE3,FIELD)

  #define _MCBSP_RCERE3_FSET(N,FIELD,field)\
    _PER_FSET(_MCBSP_RCERE3##N##_ADDR,MCBSP,RCERE3,FIELD,field)

  #define _MCBSP_RCERE3_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCBSP_RCERE3##N##_ADDR,MCBSP,RCERE3,FIELD,##SYM)

  #define _MCBSP_RCERE30_FGET(FIELD) _MCBSP_RCERE3_FGET(0,##FIELD)
  #define _MCBSP_RCERE31_FGET(FIELD) _MCBSP_RCERE3_FGET(1,##FIELD)
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_RCERE32_FGET(FIELD) _MCBSP_RCERE3_FGET(2,##FIELD)
 #endif

  #define _MCBSP_RCERE30_FSET(FIELD,f) _MCBSP_RCERE3_FSET(0,##FIELD,f)
  #define _MCBSP_RCERE31_FSET(FIELD,f) _MCBSP_RCERE3_FSET(1,##FIELD,f)
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_RCERE32_FSET(FIELD,f) _MCBSP_RCERE3_FSET(2,##FIELD,f)
 #endif

  #define _MCBSP_RCERE30_FSETS(FIELD,SYM) _MCBSP_RCERE3_FSETS(0,##FIELD,##SYM)
  #define _MCBSP_RCERE31_FSETS(FIELD,SYM) _MCBSP_RCERE3_FSETS(1,##FIELD,##SYM)
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_RCERE32_FSETS(FIELD,SYM) _MCBSP_RCERE3_FSETS(2,##FIELD,##SYM)
 #endif
#endif /* C64_SUPPORT */

/******************************************************************************\
* _____________________
* |                   |
* |  X C E R          |
* |___________________|
*
* XCER0 - serial port 0 transmit channel enable register
* XCER1 - serial port 1 transmit channel enable register
* XCER2 - serial port 2 transmit channel enable register (1)
*
* (1) only supported on devices with three serial ports
*
* FIELDS (msb -> lsb)
* (rw) XCEB
* (rw) XCEA
*
\******************************************************************************/
 #if (!C64_SUPPORT)
   #define _MCBSP_XCER_OFFSET           8

  #define _MCBSP_XCER0_ADDR            0x018C0020u
  #define _MCBSP_XCER1_ADDR            0x01900020u

#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_XCER2_ADDR            0x01A40020u
#endif


  #define _MCBSP_XCER_XCEB_MASK        0xFFFF0000u
  #define _MCBSP_XCER_XCEB_SHIFT       0x00000010u
  #define  MCBSP_XCER_XCEB_DEFAULT     0x00000000u
  #define  MCBSP_XCER_XCEB_OF(x)       _VALUEOF(x)

  #define _MCBSP_XCER_XCEA_MASK        0x0000FFFFu
  #define _MCBSP_XCER_XCEA_SHIFT       0x00000000u
  #define  MCBSP_XCER_XCEA_DEFAULT     0x00000000u
  #define  MCBSP_XCER_XCEA_OF(x)       _VALUEOF(x)

  #define  MCBSP_XCER_OF(x)            _VALUEOF(x)


  #define MCBSP_XCER_DEFAULT (Uint32)(\
     _PER_FDEFAULT(MCBSP,XCER,XCEB)\
    |_PER_FDEFAULT(MCBSP,XCER,XCEA)\
  )

  #define MCBSP_XCER_RMK(xceb,xcea) (Uint32)(\
     _PER_FMK(MCBSP,XCER,XCEB,xceb)\
    |_PER_FMK(MCBSP,XCER,XCEA,xcea)\
  )

  #define _MCBSP_XCER_FGET(N,FIELD)\
    _PER_FGET(_MCBSP_XCER##N##_ADDR,MCBSP,XCER,##FIELD)

  #define _MCBSP_XCER_FSET(N,FIELD,field)\
    _PER_FSET(_MCBSP_XCER##N##_ADDR,MCBSP,XCER,##FIELD,field)

  #define _MCBSP_XCER_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCBSP_XCER##N##_ADDR,MCBSP,XCER,##FIELD,##SYM)

  #define _MCBSP_XCER0_FGET(FIELD) _MCBSP_XCER_FGET(0,##FIELD)
  #define _MCBSP_XCER1_FGET(FIELD) _MCBSP_XCER_FGET(1,##FIELD)
#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_XCER2_FGET(FIELD) _MCBSP_XCER_FGET(2,##FIELD)
#endif

  #define _MCBSP_XCER0_FSET(FIELD,f) _MCBSP_XCER_FSET(0,##FIELD,f)
  #define _MCBSP_XCER1_FSET(FIELD,f) _MCBSP_XCER_FSET(1,##FIELD,f)
#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_XCER2_FSET(FIELD,f) _MCBSP_XCER_FSET(2,##FIELD,f)
#endif

  #define _MCBSP_XCER0_FSETS(FIELD,SYM) _MCBSP_XCER_FSETS(0,##FIELD,##SYM)
  #define _MCBSP_XCER1_FSETS(FIELD,SYM) _MCBSP_XCER_FSETS(1,##FIELD,##SYM)
#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_XCER2_FSETS(FIELD,SYM) _MCBSP_XCER_FSETS(2,##FIELD,##SYM)
#endif

#endif


/******************************************************************************\
* _____________________
* |                   |
* |  X C E R E 0      |
* |___________________|
*
* XCERE00 - serial port 0 enhanced transmit channel enable register 0
* XCERE01 - serial port 1 enhanced transmit channel enable register 0
* XCERE02 - serial port 2 enhanced transmit channel enable register 0
*
* FIELDS (msb -> lsb)
* (rw) XCE
*
\******************************************************************************/
#if (C64_SUPPORT)
  #define _MCBSP_XCERE0_OFFSET           8

  #define _MCBSP_XCERE00_ADDR            0x018C0020u
  #define _MCBSP_XCERE01_ADDR            0x01900020u
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_XCERE02_ADDR            0x01A40020u
 #endif

  #define _MCBSP_XCERE0_XCE_MASK        0xFFFFFFFFu
  #define _MCBSP_XCERE0_XCE_SHIFT       0x00000000u
  #define  MCBSP_XCERE0_XCE_DEFAULT     0x00000000u
  #define  MCBSP_XCERE0_XCE_OF(x)       _VALUEOF(x)

  #define  MCBSP_XCERE0_OF(x)            _VALUEOF(x)

  #define MCBSP_XCERE0_DEFAULT (Uint32)(\
     _PER_FDEFAULT(MCBSP,XCERE0,XCE)\
  )

  #define MCBSP_XCERE0_RMK(xce) (Uint32)(\
     _PER_FMK(MCBSP,XCERE0,XCE,xce) \
  )

  #define _MCBSP_XCERE0_FGET(N,FIELD)\
    _PER_FGET(_MCBSP_XCERE0##N##_ADDR,MCBSP,XCERE0,FIELD)

  #define _MCBSP_XCERE0_FSET(N,FIELD,field)\
    _PER_FSET(_MCBSP_XCERE0##N##_ADDR,MCBSP,XCERE0,FIELD,field)

  #define _MCBSP_XCERE0_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCBSP_XCERE0##N##_ADDR,MCBSP,XCERE0,FIELD,##SYM)

  #define _MCBSP_XCERE00_FGET(FIELD) _MCBSP_XCERE0_FGET(0,##FIELD)
  #define _MCBSP_XCERE01_FGET(FIELD) _MCBSP_XCERE0_FGET(1,##FIELD)
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_XCERE02_FGET(FIELD) _MCBSP_XCERE0_FGET(2,##FIELD)
 #endif

  #define _MCBSP_XCERE00_FSET(FIELD,f) _MCBSP_XCERE0_FSET(0,##FIELD,f)
  #define _MCBSP_XCERE01_FSET(FIELD,f) _MCBSP_XCERE0_FSET(1,##FIELD,f)
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_XCERE02_FSET(FIELD,f) _MCBSP_XCERE0_FSET(2,##FIELD,f)
 #endif

  #define _MCBSP_XCERE00_FSETS(FIELD,SYM) _MCBSP_XCERE0_FSETS(0,##FIELD,##SYM)
  #define _MCBSP_XCERE01_FSETS(FIELD,SYM) _MCBSP_XCERE0_FSETS(1,##FIELD,##SYM)
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_XCERE02_FSETS(FIELD,SYM) _MCBSP_XCERE0_FSETS(2,##FIELD,##SYM)
 #endif
#endif /* C64_SUPPORT */


/******************************************************************************\
* _____________________
* |                   |
* |  X C E R E 1      |
* |___________________|
*
* XCERE10 - serial port 0 enhanced transmit channel enable register 1
* XCERE11 - serial port 1 enhanced transmit channel enable register 1
* XCERE12 - serial port 2 enhanced transmit channel enable register 1
*
* FIELDS (msb -> lsb)
* (rw) XCE
*
\******************************************************************************/
#if (C64_SUPPORT)
  #define _MCBSP_XCERE1_OFFSET           0xB

  #define _MCBSP_XCERE10_ADDR            0x018C002Cu
  #define _MCBSP_XCERE11_ADDR            0x0190002Cu
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_XCERE12_ADDR            0x01A4002Cu
 #endif

  #define _MCBSP_XCERE1_XCE_MASK        0xFFFFFFFFu
  #define _MCBSP_XCERE1_XCE_SHIFT       0x00000000u
  #define  MCBSP_XCERE1_XCE_DEFAULT     0x00000000u
  #define  MCBSP_XCERE1_XCE_OF(x)       _VALUEOF(x)

  #define  MCBSP_XCERE1_OF(x)            _VALUEOF(x)

  #define MCBSP_XCERE1_DEFAULT (Uint32)(\
     _PER_FDEFAULT(MCBSP,XCERE1,XCE)\
  )

  #define MCBSP_XCERE1_RMK(xce) (Uint32)(\
     _PER_FMK(MCBSP,XCERE1,XCE,xce)\
  )

  #define _MCBSP_XCERE1_FGET(N,FIELD)\
    _PER_FGET(_MCBSP_XCERE1##N##_ADDR,MCBSP,XCERE1,FIELD)

  #define _MCBSP_XCERE1_FSET(N,FIELD,field)\
    _PER_FSET(_MCBSP_XCERE1##N##_ADDR,MCBSP,XCERE1,FIELD,field)

  #define _MCBSP_XCERE1_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCBSP_XCERE1##N##_ADDR,MCBSP,XCERE1,FIELD,##SYM)

  #define _MCBSP_XCERE10_FGET(FIELD) _MCBSP_XCERE1_FGET(0,##FIELD)
  #define _MCBSP_XCERE11_FGET(FIELD) _MCBSP_XCERE1_FGET(1,##FIELD)
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_XCERE12_FGET(FIELD) _MCBSP_XCERE1_FGET(2,##FIELD)
 #endif

  #define _MCBSP_XCERE10_FSET(FIELD,f) _MCBSP_XCERE1_FSET(0,##FIELD,f)
  #define _MCBSP_XCERE11_FSET(FIELD,f) _MCBSP_XCERE1_FSET(1,##FIELD,f)
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_XCERE12_FSET(FIELD,f) _MCBSP_XCERE1_FSET(2,##FIELD,f)
 #endif

  #define _MCBSP_XCERE10_FSETS(FIELD,SYM) _MCBSP_XCERE1_FSETS(0,##FIELD,##SYM)
  #define _MCBSP_XCERE11_FSETS(FIELD,SYM) _MCBSP_XCERE1_FSETS(1,##FIELD,##SYM)
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_XCERE12_FSETS(FIELD,SYM) _MCBSP_XCERE1_FSETS(2,##FIELD,##SYM)
 #endif
#endif /* C64_SUPPORT */


/******************************************************************************\
* _____________________
* |                   |
* |  X C E R E 2      |
* |___________________|
*
* XCERE20 - serial port 0 enhanced transmit channel enable register 2
* XCERE21 - serial port 1 enhanced transmit channel enable register 2
* XCERE22 - serial port 2 enhanced transmit channel enable register 2
*
* FIELDS (msb -> lsb)
* (rw) XCE
*
\******************************************************************************/
#if (C64_SUPPORT)
  #define _MCBSP_XCERE2_OFFSET           0xD

  #define _MCBSP_XCERE20_ADDR            0x018C0034u
  #define _MCBSP_XCERE21_ADDR            0x01900034u
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_XCERE22_ADDR            0x01A40034u
 #endif

  #define _MCBSP_XCERE2_XCE_MASK        0xFFFFFFFFu
  #define _MCBSP_XCERE2_XCE_SHIFT       0x00000000u
  #define  MCBSP_XCERE2_XCE_DEFAULT     0x00000000u
  #define  MCBSP_XCERE2_XCE_OF(x)       _VALUEOF(x)

  #define  MCBSP_XCERE2_OF(x)            _VALUEOF(x)

  #define MCBSP_XCERE2_DEFAULT (Uint32)(\
     _PER_FDEFAULT(MCBSP,XCERE2,XCE)\
  )

  #define MCBSP_XCERE2_RMK(xce) (Uint32)(\
     _PER_FMK(MCBSP,XCERE2,XCE,xce)\
  )

  #define _MCBSP_XCERE2_FGET(N,FIELD)\
    _PER_FGET(_MCBSP_XCERE2##N##_ADDR,MCBSP,XCERE2,FIELD)

  #define _MCBSP_XCERE2_FSET(N,FIELD,field)\
    _PER_FSET(_MCBSP_XCERE2##N##_ADDR,MCBSP,XCERE2,FIELD,field)

  #define _MCBSP_XCERE2_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCBSP_XCERE2##N##_ADDR,MCBSP,XCERE2,FIELD,##SYM)

  #define _MCBSP_XCERE20_FGET(FIELD) _MCBSP_XCERE2_FGET(0,##FIELD)
  #define _MCBSP_XCERE21_FGET(FIELD) _MCBSP_XCERE2_FGET(1,##FIELD)
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_XCERE22_FGET(FIELD) _MCBSP_XCERE2_FGET(2,##FIELD)
 #endif

  #define _MCBSP_XCERE20_FSET(FIELD,f) _MCBSP_XCERE2_FSET(0,##FIELD,f)
  #define _MCBSP_XCERE21_FSET(FIELD,f) _MCBSP_XCERE2_FSET(1,##FIELD,f)
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_XCERE22_FSET(FIELD,f) _MCBSP_XCERE2_FSET(2,##FIELD,f)
 #endif

  #define _MCBSP_XCERE20_FSETS(FIELD,SYM) _MCBSP_XCERE2_FSETS(0,##FIELD,##SYM)
  #define _MCBSP_XCERE21_FSETS(FIELD,SYM) _MCBSP_XCERE2_FSETS(1,##FIELD,##SYM)
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_XCERE22_FSETS(FIELD,SYM) _MCBSP_XCERE2_FSETS(2,##FIELD,##SYM)
 #endif
#endif /* C64_SUPPORT */


/******************************************************************************\
* _____________________
* |                   |
* |  X C E R E 3      |
* |___________________|
*
* XCERE30 - serial port 0 enhanced transmit channel enable register 3
* XCERE31 - serial port 1 enhanced transmit channel enable register 3
* XCERE32 - serial port 2 enhanced transmit channel enable register 3
*
* FIELDS (msb -> lsb)
* (rw) XCE
*
\******************************************************************************/
#if (C64_SUPPORT)
  #define _MCBSP_XCERE3_OFFSET           0xF

  #define _MCBSP_XCERE30_ADDR            0x018C003Cu
  #define _MCBSP_XCERE31_ADDR            0x0190003Cu
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_XCERE32_ADDR            0x01A4003Cu
 #endif

  #define _MCBSP_XCERE3_XCE_MASK        0xFFFFFFFFu
  #define _MCBSP_XCERE3_XCE_SHIFT       0x00000000u
  #define  MCBSP_XCERE3_XCE_DEFAULT     0x00000000u
  #define  MCBSP_XCERE3_XCE_OF(x)       _VALUEOF(x)

  #define  MCBSP_XCERE3_OF(x)            _VALUEOF(x)

  #define MCBSP_XCERE3_DEFAULT (Uint32)(\
     _PER_FDEFAULT(MCBSP,XCERE3,XCE)\
  )

  #define MCBSP_XCERE3_RMK(xce) (Uint32)(\
     _PER_FMK(MCBSP,XCERE3,XCE,xce)\
  )

  #define _MCBSP_XCERE3_FGET(N,FIELD)\
    _PER_FGET(_MCBSP_XCERE3##N##_ADDR,MCBSP,XCERE3,FIELD)

  #define _MCBSP_XCERE3_FSET(N,FIELD,field)\
    _PER_FSET(_MCBSP_XCERE3##N##_ADDR,MCBSP,XCERE3,FIELD,field)

  #define _MCBSP_XCERE3_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCBSP_XCERE3##N##_ADDR,MCBSP,XCERE3,FIELD,##SYM)

  #define _MCBSP_XCERE30_FGET(FIELD) _MCBSP_XCERE3_FGET(0,##FIELD)
  #define _MCBSP_XCERE31_FGET(FIELD) _MCBSP_XCERE3_FGET(1,##FIELD)
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_XCERE32_FGET(FIELD) _MCBSP_XCERE3_FGET(2,##FIELD)
 #endif

  #define _MCBSP_XCERE30_FSET(FIELD,f) _MCBSP_XCERE3_FSET(0,##FIELD,f)
  #define _MCBSP_XCERE31_FSET(FIELD,f) _MCBSP_XCERE3_FSET(1,##FIELD,f)
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_XCERE32_FSET(FIELD,f) _MCBSP_XCERE3_FSET(2,##FIELD,f)
 #endif

  #define _MCBSP_XCERE30_FSETS(FIELD,SYM) _MCBSP_XCERE3_FSETS(0,##FIELD,##SYM)
  #define _MCBSP_XCERE31_FSETS(FIELD,SYM) _MCBSP_XCERE3_FSETS(1,##FIELD,##SYM)
 #if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_XCERE32_FSETS(FIELD,SYM) _MCBSP_XCERE3_FSETS(2,##FIELD,##SYM)
 #endif
#endif /* C64_SUPPORT */

/******************************************************************************\
* _____________________
* |                   |
* |  P C R            |
* |___________________|
*
* PCR0  - serial port 0 pin control register
* PCR1  - serial port 1 pin control register
* PCR2  - serial port 2 pin control register (1)
*
* (1) only supported on devices with three serial ports
*
* FIELDS (msb -> lsb)
* (rw) XIOEN
* (rw) RIOEN
* (rw) FSXM
* (rw) FSRM
* (rw) CLKXM
* (rw) CLKRM
* (r) CLKSSTAT
* (rw) DXSTAT
* (r)  DRSTAT
* (rw) FSXP
* (rw) FSRP
* (rw) CLKXP
* (rw) CLKRP
*
\******************************************************************************/
  #define _MCBSP_PCR_OFFSET            9

  #define _MCBSP_PCR0_ADDR             0x018C0024u
  #define _MCBSP_PCR1_ADDR             0x01900024u

#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_PCR2_ADDR             0x01A40024u
#endif

  #define _MCBSP_PCR_XIOEN_MASK        0x00002000u
  #define _MCBSP_PCR_XIOEN_SHIFT       0x0000000Du
  #define  MCBSP_PCR_XIOEN_DEFAULT     0x00000000u
  #define  MCBSP_PCR_XIOEN_OF(x)       _VALUEOF(x)
  #define  MCBSP_PCR_XIOEN_SP          0x00000000u
  #define  MCBSP_PCR_XIOEN_GPIO        0x00000001u

  #define _MCBSP_PCR_RIOEN_MASK        0x00001000u
  #define _MCBSP_PCR_RIOEN_SHIFT       0x0000000Cu
  #define  MCBSP_PCR_RIOEN_DEFAULT     0x00000000u
  #define  MCBSP_PCR_RIOEN_OF(x)       _VALUEOF(x)
  #define  MCBSP_PCR_RIOEN_SP          0x00000000u
  #define  MCBSP_PCR_RIOEN_GPIO        0x00000001u

  #define _MCBSP_PCR_FSXM_MASK         0x00000800u
  #define _MCBSP_PCR_FSXM_SHIFT        0x0000000Bu
  #define  MCBSP_PCR_FSXM_DEFAULT      0x00000000u
  #define  MCBSP_PCR_FSXM_OF(x)        _VALUEOF(x)
  #define  MCBSP_PCR_FSXM_EXTERNAL     0x00000000u
  #define  MCBSP_PCR_FSXM_INTERNAL     0x00000001u

  #define _MCBSP_PCR_FSRM_MASK         0x00000400u
  #define _MCBSP_PCR_FSRM_SHIFT        0x0000000Au
  #define  MCBSP_PCR_FSRM_DEFAULT      0x00000000u
  #define  MCBSP_PCR_FSRM_OF(x)        _VALUEOF(x)
  #define  MCBSP_PCR_FSRM_EXTERNAL     0x00000000u
  #define  MCBSP_PCR_FSRM_INTERNAL     0x00000001u

  #define _MCBSP_PCR_CLKXM_MASK        0x00000200u
  #define _MCBSP_PCR_CLKXM_SHIFT       0x00000009u
  #define  MCBSP_PCR_CLKXM_DEFAULT     0x00000000u
  #define  MCBSP_PCR_CLKXM_OF(x)       _VALUEOF(x)
  #define  MCBSP_PCR_CLKXM_INPUT       0x00000000u
  #define  MCBSP_PCR_CLKXM_OUTPUT      0x00000001u

  #define _MCBSP_PCR_CLKRM_MASK        0x00000100u
  #define _MCBSP_PCR_CLKRM_SHIFT       0x00000008u
  #define  MCBSP_PCR_CLKRM_DEFAULT     0x00000000u
  #define  MCBSP_PCR_CLKRM_OF(x)       _VALUEOF(x)
  #define  MCBSP_PCR_CLKRM_INPUT       0x00000000u
  #define  MCBSP_PCR_CLKRM_OUTPUT      0x00000001u

  #define _MCBSP_PCR_CLKSSTAT_MASK     0x00000040u
  #define _MCBSP_PCR_CLKSSTAT_SHIFT    0x00000006u
  #define  MCBSP_PCR_CLKSSTAT_DEFAULT  0x00000000u
  #define  MCBSP_PCR_CLKSSTAT_OF(x)    _VALUEOF(x)
  #define  MCBSP_PCR_CLKSSTAT_0        0x00000000u
  #define  MCBSP_PCR_CLKSSTAT_1        0x00000001u

  #define _MCBSP_PCR_DXSTAT_MASK       0x00000020u
  #define _MCBSP_PCR_DXSTAT_SHIFT      0x00000005u
  #define  MCBSP_PCR_DXSTAT_DEFAULT    0x00000000u
  #define  MCBSP_PCR_DXSTAT_OF(x)      _VALUEOF(x)
  #define  MCBSP_PCR_DXSTAT_0          0x00000000u
  #define  MCBSP_PCR_DXSTAT_1          0x00000001u

  #define _MCBSP_PCR_DRSTAT_MASK       0x00000010u
  #define _MCBSP_PCR_DRSTAT_SHIFT      0x00000004u
  #define  MCBSP_PCR_DRSTAT_DEFAULT    0x00000000u
  #define  MCBSP_PCR_DRSTAT_OF(x)      _VALUEOF(x)
  #define  MCBSP_PCR_DRSTAT_0          0x00000000u
  #define  MCBSP_PCR_DRSTAT_1          0x00000001u

  #define _MCBSP_PCR_FSXP_MASK         0x00000008u
  #define _MCBSP_PCR_FSXP_SHIFT        0x00000003u
  #define  MCBSP_PCR_FSXP_DEFAULT      0x00000000u
  #define  MCBSP_PCR_FSXP_OF(x)        _VALUEOF(x)
  #define  MCBSP_PCR_FSXP_ACTIVEHIGH   0x00000000u
  #define  MCBSP_PCR_FSXP_ACTIVELOW    0x00000001u

  #define _MCBSP_PCR_FSRP_MASK         0x00000004u
  #define _MCBSP_PCR_FSRP_SHIFT        0x00000002u
  #define  MCBSP_PCR_FSRP_DEFAULT      0x00000000u
  #define  MCBSP_PCR_FSRP_OF(x)        _VALUEOF(x)
  #define  MCBSP_PCR_FSRP_ACTIVEHIGH   0x00000000u
  #define  MCBSP_PCR_FSRP_ACTIVELOW    0x00000001u

  #define _MCBSP_PCR_CLKXP_MASK        0x00000002u
  #define _MCBSP_PCR_CLKXP_SHIFT       0x00000001u
  #define  MCBSP_PCR_CLKXP_DEFAULT     0x00000000u
  #define  MCBSP_PCR_CLKXP_OF(x)       _VALUEOF(x)
  #define  MCBSP_PCR_CLKXP_RISING      0x00000000u
  #define  MCBSP_PCR_CLKXP_FALLING     0x00000001u

  #define _MCBSP_PCR_CLKRP_MASK        0x00000001u
  #define _MCBSP_PCR_CLKRP_SHIFT       0x00000000u
  #define  MCBSP_PCR_CLKRP_DEFAULT     0x00000000u
  #define  MCBSP_PCR_CLKRP_OF(x)       _VALUEOF(x)
  #define  MCBSP_PCR_CLKRP_FALLING     0x00000000u
  #define  MCBSP_PCR_CLKRP_RISING      0x00000001u

  #define  MCBSP_PCR_OF(x)             _VALUEOF(x)

  #define MCBSP_PCR_DEFAULT (Uint32)(\
     _PER_FDEFAULT(MCBSP,PCR,XIOEN)\
    |_PER_FDEFAULT(MCBSP,PCR,RIOEN)\
    |_PER_FDEFAULT(MCBSP,PCR,FSXM)\
    |_PER_FDEFAULT(MCBSP,PCR,FSRM)\
    |_PER_FDEFAULT(MCBSP,PCR,CLKXM)\
    |_PER_FDEFAULT(MCBSP,PCR,CLKRM)\
    |_PER_FDEFAULT(MCBSP,PCR,CLKSSTAT)\
    |_PER_FDEFAULT(MCBSP,PCR,DXSTAT)\
    |_PER_FDEFAULT(MCBSP,PCR,DRSTAT)\
    |_PER_FDEFAULT(MCBSP,PCR,FSXP)\
    |_PER_FDEFAULT(MCBSP,PCR,FSRP)\
    |_PER_FDEFAULT(MCBSP,PCR,CLKXP)\
    |_PER_FDEFAULT(MCBSP,PCR,CLKRP)\
  )

 #if (CHIP_6410 | CHIP_6413 | CHIP_6418)
  #define MCBSP_PCR_RMK(xioen,rioen,fsxm,fsrm,clkxm,clkrm,\
                        dxstat,fsxp,fsrp,clkxp,clkrp) (Uint32)(\
     _PER_FMK(MCBSP,PCR,XIOEN,xioen)\
    |_PER_FMK(MCBSP,PCR,RIOEN,rioen)\
    |_PER_FMK(MCBSP,PCR,FSXM,fsxm)\
    |_PER_FMK(MCBSP,PCR,FSRM,fsrm)\
    |_PER_FMK(MCBSP,PCR,CLKXM,clkxm)\
    |_PER_FMK(MCBSP,PCR,CLKRM,clkrm)\
    |_PER_FMK(MCBSP,PCR,DXSTAT,dxstat)\
    |_PER_FMK(MCBSP,PCR,FSXP,fsxp)\
    |_PER_FMK(MCBSP,PCR,FSRP,fsrp)\
    |_PER_FMK(MCBSP,PCR,CLKXP,clkxp)\
    |_PER_FMK(MCBSP,PCR,CLKRP,clkrp)\
  )
 #else
  #define MCBSP_PCR_RMK(xioen,rioen,fsxm,fsrm,clkxm,clkrm,clksstat,\
    dxstat,fsxp,fsrp,clkxp,clkrp) (Uint32)(\
     _PER_FMK(MCBSP,PCR,XIOEN,xioen)\
    |_PER_FMK(MCBSP,PCR,RIOEN,rioen)\
    |_PER_FMK(MCBSP,PCR,FSXM,fsxm)\
    |_PER_FMK(MCBSP,PCR,FSRM,fsrm)\
    |_PER_FMK(MCBSP,PCR,CLKXM,clkxm)\
    |_PER_FMK(MCBSP,PCR,CLKRM,clkrm)\
    |_PER_FMK(MCBSP,PCR,CLKSSTAT,clksstat)\
    |_PER_FMK(MCBSP,PCR,DXSTAT,dxstat)\
    |_PER_FMK(MCBSP,PCR,FSXP,fsxp)\
    |_PER_FMK(MCBSP,PCR,FSRP,fsrp)\
    |_PER_FMK(MCBSP,PCR,CLKXP,clkxp)\
    |_PER_FMK(MCBSP,PCR,CLKRP,clkrp)\
  )
 #endif
  #define _MCBSP_PCR_FGET(N,FIELD)\
    _PER_FGET(_MCBSP_PCR##N##_ADDR,MCBSP,PCR,##FIELD)

  #define _MCBSP_PCR_FSET(N,FIELD,field)\
    _PER_FSET(_MCBSP_PCR##N##_ADDR,MCBSP,PCR,##FIELD,field)

  #define _MCBSP_PCR_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCBSP_PCR##N##_ADDR,MCBSP,PCR,##FIELD,##SYM)

  #define _MCBSP_PCR0_FGET(FIELD) _MCBSP_PCR_FGET(0,##FIELD)
  #define _MCBSP_PCR1_FGET(FIELD) _MCBSP_PCR_FGET(1,##FIELD)
#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_PCR2_FGET(FIELD) _MCBSP_PCR_FGET(2,##FIELD)
#endif

  #define _MCBSP_PCR0_FSET(FIELD,f) _MCBSP_PCR_FSET(0,##FIELD,f)
  #define _MCBSP_PCR1_FSET(FIELD,f) _MCBSP_PCR_FSET(1,##FIELD,f)
#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_PCR2_FSET(FIELD,f) _MCBSP_PCR_FSET(2,##FIELD,f)
#endif

  #define _MCBSP_PCR0_FSETS(FIELD,SYM) _MCBSP_PCR_FSETS(0,##FIELD,##SYM)
  #define _MCBSP_PCR1_FSETS(FIELD,SYM) _MCBSP_PCR_FSETS(1,##FIELD,##SYM)
#if (_MCBSP_PORT_CNT==3)
  #define _MCBSP_PCR2_FSETS(FIELD,SYM) _MCBSP_PCR_FSETS(2,##FIELD,##SYM)
#endif


/*----------------------------------------------------------------------------*/

#endif /* MCBSP_SUPPORT */
#endif /* _CSL_MCBSPHAL_H_ */
/******************************************************************************\
* End of csl_mcbsphal.h
\******************************************************************************/

