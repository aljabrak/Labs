/******************************************************************************\
* Step 1.     Copyright (C) 2001 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_mcasphal.h
* DATE CREATED.. 06/28/2001 
* LAST MODIFIED. 
*                08/02/2004 - Adding support for C6418
*------------------------------------------------------------------------------
*HISTORY......6/29/01, changed RSLOT to RSLOTCNT, XSLOT to XSLOTCNT
* 7/2/01, XFMT: changed XROT field to 0-2 instead of 0-3
*	also added field XDATDLY in bits 17:16 (made appropriate macro changes)
*	RFMT: same as above (RROT wasn't specified, but made sense)
*	AFSXCTL/AFSRCTL: removed X(R)DATDLY fields and macro entries.
*	ACLKRCTL: changed CLKRDIV field to bits 4:0(was 5:0),CLKRM to bit 5(was 6)
*	HCLKXDIV/HCLKRDIV: changed field HCLKX(R)DIV to bit 11:0 (was 12:0)
*	SCRTL: changed defaults of fields XRDY and RRDY to 0b (was 1b)
*	Added register DLBCTL
*	Added registers X(R)INTCTL
*	8/6/01 fixed MCASP_RFMT_RPAD_RPBIT; was formerly _XPBIT
*	08/13/01  V.G.  Reordered the registers and added OFFSETs
*	08/14/01  V.G.  Corrected syntax errors
*	08/20/01  V.G.	Added addresses for each register
*
*     17/06/04        Adding support for DM640/641
*     11/03/01  F.S   CRFAIL -> RCKFAIL / CXFAIL -> XCKFAIL
*     11/15/01  F.S   PWREMUMGT -> PWRDEMU
*                     PFUNC / PDIR /PDSOUT /PDSET /PDCLR -> fields renaming
*     11/20/01  F.S   GBLCTL / XGBLCTL / RGBLCTL 
*                     RRST -> RSMRST , RGRST -> RCLKRST , HCLKRRST -> RHCLKRST
*                     XRST -> XSMRST , XGRST -> XCLKRST , HCLKXRST -> XHCLKRST
*     10/22/03        Fixed the typos in MCASP_PDOUT_DEFAULT and MCASP_PDOUT_RMK
*                            
*------------------------------------------------------------------------------
* REGISTERS (register list)
*
* PID		- Peripheral Identification Register            
* PWRDEMU	- Power Down and Emulation Management Register  
* PFUNC		- Pin Function / GPIO Enable Register  
* PDIR		- Pin Direction Register 
* PDAT		- Pin Data Register   
* PDIN		- Pin Data Input Register  
* PDOUT		- Pin Data Output Register  
* PDSET		- Pin Data Set Register 
* PDCLR		- Pin Data Clear Register  
* DITCTL    - Transmit DIT Control Register  
* DLBCTL    -  Loop Back Control Mode
* XFMT		- Transmit Bitstream Format Register 
* RFMT		- Receive Bitstream Format Register  
* XMASK
* RMASK		
* AFSXCTL	- Transmit Frame Control Register 
* AFSRCTL	- Receive Frame Control Register 
* ACLKXCTL	- Transmit Clock Control Register 
* ACLKRCTL	- Receive Clock Control Register 
* AHCLKXCTL	- High Frequency Transmit Clock Control Register Description
* AHCLKRCTL	- High Frequency Receive Clock Control Register Description     
* SRCTL0	- Serializer Control Register 0
* SRCTL1	- Serializer Control Register 1
* SRCTL2	- Serializer Control Register 2
* SRCTL3	- Serializer Control Register 3
* SRCTL4	- Serializer Control Register 4
* SRCTL5	- Serializer Control Register 5
* SRCTL6	- Serializer Control Register 6
* SRCTL7	- Serializer Control Register 7
* SRCTL8	- Serializer Control Register 8 (1)
* SRCTL9	- Serializer Control Register 9 (1)
* SRCTL10	- Serializer Control Register 10 (1)
* SRCTL11	- Serializer Control Register 11 (1)
* SRCTL12	- Serializer Control Register 12 (1)
* SRCTL13	- Serializer Control Register 13 (1)
* SRCTL14	- Serializer Control Register 14 (1)
* SRCTL15	- Serializer Control Register 15 (1)
* XTDM		- Transmit TDM Register
* RTDM		- Receive TDM Register          
* GBLCTL	- Global Control Register            
* XGBLCTL	- Global Control Register            
* RGBLCTL	- Global Control Register            
* AMUTE	- Mute Control Register        
* XINTCTL   - Transmitter Interrupt Control Register
* RINTCTL   - Receiver Interrupt Control Register
* RSTAT	- Receiver Status Register 
* XSTAT	- Transmitter Status Register 
* RSLOTCNT	- Receiver TDM Slot Counter
* XSLOTCNT	- Transmitter TDM Slot Counter
* XCLKCHK	- Transmit Clock Check Control Register
* RCLKCHK	- Receive Clock Check Control Register
* XBUF0	- Transmit Buffer for Serializer 0
* XBUF1	- Transmit Buffer for Serializer 1
* XBUF2	- Transmit Buffer for Serializer 2
* XBUF3	- Transmit Buffer for Serializer 3
* XBUF4	- Transmit Buffer for Serializer 4
* XBUF5	- Transmit Buffer for Serializer 5
* XBUF6	- Transmit Buffer for Serializer 6
* XBUF7	- Transmit Buffer for Serializer 7
* XBUF8	- Transmit Buffer for Serializer 8 (1)
* XBUF9	- Transmit Buffer for Serializer 9 (1)
* XBUF10	- Transmit Buffer for Serializer 10 (1)
* XBUF11	- Transmit Buffer for Serializer 11 (1)
* XBUF12	- Transmit Buffer for Serializer 12 (1)
* XBUF13	- Transmit Buffer for Serializer 13 (1)
* XBUF14	- Transmit Buffer for Serializer 14 (1)
* XBUF15	- Transmit Buffer for Serializer 15 (1)
* RBUF0	- Receive Buffer for Serializer 0
* RBUF1	- Receive Buffer for Serializer 1
* RBUF2	- Receive Buffer for Serializer 2
* RBUF3	- Receive Buffer for Serializer 3
* RBUF4	- Receive Buffer for Serializer 4
* RBUF5	- Receive Buffer for Serializer 5
* RBUF6	- Receive Buffer for Serializer 6
* RBUF7	- Receive Buffer for Serializer 7
* RBUF8	- Receive Buffer for Serializer 8 
* RBUF9	- Receive Buffer for Serializer 9 
* RBUF10	- Receive Buffer for Serializer 10
* RBUF11	- Receive Buffer for Serializer 11 
* RBUF12	- Receive Buffer for Serializer 12 
* RBUF13	- Receive Buffer for Serializer 13 
* RBUF14	- Receive Buffer for Serializer 14 
* RBUF15	- Receive Buffer for Serializer 15 
* DITCSRA0n	- Left (even TDM Slot) Channel Status Register File
* DITCSRA1n
* DITCSRA2n
* DITCSRA3n
* DITCSRA4n
* DITCSRA5n
* DITCSRB0n	- Right (even TDM Slot) Channel Status Register File
* DITCSRB1n
* DITCSRB2n
* DITCSRB3n
* DITCSRB4n
* DITCSRB5n
* DITUDRA0n	- Left (even TDM Slot) User Data Register File
* DITUDRA1n
* DITUDRA2n
* DITUDRA3n
* DITUDRA4n
* DITUDRA5n
* DITUDRB0n	- Right (even TDM Slot) User Data Register File
* DITUDRB1n
* DITUDRB2n
* DITUDRB3n
* DITUDRB4n
* DITUDRB5n
* 
*
\******************************************************************************/
/******************************************************************************\
* Step 2. Private Macros and Include files
\******************************************************************************/
#ifndef _CSL_MCASPHAL_H_
#define _CSL_MCASPHAL_H_

#include <csl_stdinc.h>
#include <csl_chip.h>

#if (MCASP_SUPPORT)
/******************************************************************************\
* Step 3. MISC section 
* Example:
* #define _MCASP_BASE_GLOBAL   0xXXXXXXXXu
\******************************************************************************/
#if (CHIP_6713 | CHIP_DA610 | CHIP_6413 | CHIP_6418 | CHIP_6410)
 #define _MCASP_PORT_CNT        2
#endif

#if (CHIP_DM642 | CHIP_DM641 | CHIP_DM640)
 #define _MCASP_PORT_CNT        1
#endif

#if (CHIP_DM641 | CHIP_DM640)
    #define _MCASP_CHANNEL_CNT    4
#endif

#if (CHIP_6413 | CHIP_6418 | CHIP_6410)
    #define _MCASP_CHANNEL_CNT    6
#endif

#if (CHIP_DM642 | CHIP_6713)
    #define _MCASP_CHANNEL_CNT    8
#endif

#if (CHIP_DA610)
    #define _MCASP_CHANNEL_CNT    16
#endif

#define _MCASP_BASE_PORT0      0x01B4C000u
#define _MCASP_BASE_PORT1      0x01B50000u

/******************************************************************************\
* Step 4. Module level register/field access macros
\******************************************************************************/

  /* -------------------------- */
  /* Step 4.1 FIELD MAKE MACROS */
  /* -------------------------- */

  #define MCASP_FMK(REG,FIELD,x)\
    _PER_FMK(MCASP,##REG,##FIELD,x)

  #define MCASP_FMKS(REG,FIELD,SYM)\
    _PER_FMKS(MCASP,##REG,##FIELD,##SYM)
 
 
  /* ----------------------------------------- */
  /* Step 4.2 RAW REGISTER/FIELD ACCESS MACROS */
  /* ----------------------------------------- */

  #define MCASP_ADDR(REG)\
    _MCASP_##REG##_ADDR

  #define MCASP_RGET(REG)\
    _PER_RGET(_MCASP_##REG##_ADDR,MCASP,##REG)

  #define MCASP_RSET(REG,x)\
    _PER_RSET(_MCASP_##REG##_ADDR,MCASP,##REG,x)

  #define MCASP_FGET(REG,FIELD)\
    _MCASP_##REG##_FGET(##FIELD)

  #define MCASP_FSET(REG,FIELD,x)\
    _MCASP_##REG##_FSET(##FIELD,x)

  #define MCASP_FSETS(REG,FIELD,SYM)\
    _MCASP_##REG##_FSETS(##FIELD,##SYM)
 
 
  /* --------------------------------------------------- */
  /* Step 4.3 ADDRESS BASED REGISTER/FIELD ACCESS MACROS */
  /* --------------------------------------------------- */

  #define MCASP_RGETA(addr,REG)\
    _PER_RGET(addr,MCASP,##REG)

  #define MCASP_RSETA(addr,REG,x)\
    _PER_RSET(addr,MCASP,##REG,x)

  #define MCASP_FGETA(addr,REG,FIELD)\
    _PER_FGET(addr,MCASP,##REG,##FIELD)

  #define MCASP_FSETA(addr,REG,FIELD,x)\
    _PER_FSET(addr,MCASP,##REG,##FIELD,x)

  #define MCASP_FSETSA(addr,REG,FIELD,SYM)\
    _PER_FSETS(addr,MCASP,##REG,##FIELD,##SYM)

  /* -------------------------------------------------- */
  /* Step 4.4 HANDLE BASED REGISTER/FIELD ACCESS MACROS */
  /* -------------------------------------------------- */
  
  /* For non-handle based Module : remove the following macros  (remove me)*/
  /* See CDK Chapter 3. Module specification and CSL definitions ( remove me)*/ 
  
   #define MCASP_ADDRH(h,REG)\
    (Uint32)(&((h)->baseAddr[_MCASP_##REG##_OFFSET]))

  #define MCASP_RGETH(h,REG)\
    MCASP_RGETA(MCASP_ADDRH(h,##REG),##REG)

  #define MCASP_RSETH(h,REG,x)\
    MCASP_RSETA(MCASP_ADDRH(h,##REG),##REG,x)

  #define MCASP_FGETH(h,REG,FIELD)\
    MCASP_FGETA(MCASP_ADDRH(h,##REG),##REG,##FIELD)

  #define MCASP_FSETH(h,REG,FIELD,x)\
    MCASP_FSETA(MCASP_ADDRH(h,##REG),##REG,##FIELD,x)

  #define MCASP_FSETSH(h,REG,FIELD,SYM)\
    MCASP_FSETSA(MCASP_ADDRH(h,##REG),##REG,##FIELD,##SYM)



/******************************************************************************\
*  
* _____________________
* |                   |
* |     P  I  D       |
* |___________________|
*
* PID  -  Peripheral Identification Register
*
* FIELDS (msb -> lsb)
* (r)  TYPE
* (r)  CLASS
* (r)  REV
*
\******************************************************************************/

  #define _MCASP_PID_OFFSET		0

  #define _MCASP_PID0_ADDR		(_MCASP_BASE_PORT0 + 4*_MCASP_PID_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PID1_ADDR		(_MCASP_BASE_PORT1 + 4*_MCASP_PID_OFFSET)
#endif

  #define _MCASP_PID_TYPE_MASK		0x00FF0000u
  #define _MCASP_PID_TYPE_SHIFT		0x00000010u
  #define  MCASP_PID_TYPE_DEFAULT	0x00000010u
  #define  MCASP_PID_TYPE_OF(x)		_VALUEOF(x)
  #define  MCASP_PID_TYPE_MCASP		0x00000010u
 

  #define _MCASP_PID_CLASS_MASK		0x0000FF00u
  #define _MCASP_PID_CLASS_SHIFT	0x00000008u
  #define  MCASP_PID_CLASS_DEFAULT	0x00000001u
  #define  MCASP_PID_CLASS_OF(x)	_VALUEOF(x)
  #define  MCASP_PID_CLASS_SERPORT	0x00000001u
  

  #define _MCASP_PID_REV_MASK		0x000000FFu
  #define _MCASP_PID_REV_SHIFT		0x00000000u
  #define  MCASP_PID_REV_DEFAULT	0x00000001u
  #define  MCASP_PID_REV_OF(x)		_VALUEOF(x)
  #define  MCASP_PID_REV_ONE		0x00000001u


  #define  MCASP_PID_OF(x)		_VALUEOF(x)

  #define MCASP_PID_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,PID,TYPE)\
	| _PER_FDEFAULT(MCASP,PID,CLASS)\
	| _PER_FDEFAULT(MCASP,PID,REV)\
  )

     
  #define MCASP_PID_RMK(type, class, rev) (Uint32)( \
     _PER_FMK(MCASP,PID,TYPE,type)\
	| _PER_FMK(MCASP,PID,CLASS,class)\
	| _PER_FMK(MCASP,PID,REV,rev)\
  )

  
  #define _MCASP_PID_FGET(N,FIELD)\
    _PER_FGET(_MCASP_PID##N##_ADDR,MCASP,PID,##FIELD)

  #define _MCASP_PID_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_PID##N##_ADDR,MCASP,PID,##FIELD,field)

  #define _MCASP_PID_FSETS(N,FIELD,SYM)\
  	_PER_FSETS(_MCASP_PID##N##_ADDR,MCASP,PID,##FIELD,##SYM)

  #define _MCASP_PID0_FGET(FIELD) _MCASP_PID_FGET(0,##FIELD)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PID1_FGET(FIELD) _MCASP_PID_FGET(1,##FIELD)
#endif
 
  #define _MCASP_PID0_FSET(FIELD,f) _MCASP_PID_FSET(0,##FIELD,f)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PID1_FSET(FIELD,f) _MCASP_PID_FSET(1,##FIELD,f)
#endif

  #define _MCASP_PID0_FSETS(FIELD,SYM) _MCASP_PID_FSETS(0,##FIELD,##SYM)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PID1_FSETS(FIELD,SYM) _MCASP_PID_FSETS(1,##FIELD,##SYM)
#endif

/******************************************************************************\
* Step 4.5
* _____________________
* |                   |
* |     PWRDEMU       |  
* |___________________|
*
* PWRDEMU  -  Power Down and Emulation Management
*
* FIELDS (msb -> lsb)
* (rw)  FREE  
*
\******************************************************************************/

  #define _MCASP_PWRDEMU_OFFSET                 1

  #define _MCASP_PWRDEMU0_ADDR			(_MCASP_BASE_PORT0+4*_MCASP_PWRDEMU_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PWRDEMU1_ADDR			(_MCASP_BASE_PORT1+4*_MCASP_PWRDEMU_OFFSET)
#endif

  #define _MCASP_PWRDEMU_FREE_MASK              0x00000001u
  #define _MCASP_PWRDEMU_FREE_SHIFT             0x00000000u
  #define  MCASP_PWRDEMU_FREE_DEFAULT           0x00000000u
  #define  MCASP_PWRDEMU_FREE_OF(x)             _VALUEOF(x)
  #define  MCASP_PWRDEMU_FREE_OFF               0x00000000u
  #define  MCASP_PWRDEMU_FREE_ON                0x00000001u

  #define  MCASP_PWRDEMU_OF(x)                _VALUEOF(x)

  #define MCASP_PWRDEMU_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,PWRDEMU,FREE)\
  )

  #define MCASP_PWRDEMU_RMK(free) (Uint32)( \
     _PER_FMK(MCASP,PWRDEMU,FREE,free)\
  )

  #define _MCASP_PWRDEMU_FGET(N,FIELD)\
    _PER_FGET(_MCASP_PWRDEMU##N##_ADDR,MCASP,PWRDEMU,##FIELD)

  #define _MCASP_PWRDEMU_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_PWRDEMU##N##_ADDR,MCASP,PWRDEMU,##FIELD,field)

  #define _MCASP_PWRDEMU_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_PWRDEMU##N##_ADDR,MCASP,PWRDEMU,##FIELD,##SYM)

  #define _MCASP_PWRDEMU0_FGET(FIELD) _MCASP_PWRDEMU_FGET(0,##FIELD)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PWRDEMU1_FGET(FIELD) _MCASP_PWRDEMU_FGET(1,##FIELD)
#endif
 
  #define _MCASP_PWRDEMU0_FSET(FIELD,f) _MCASP_PWRDEMU_FSET(0,##FIELD,f)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PWRDEMU1_FSET(FIELD,f) _MCASP_PWRDEMU_FSET(1,##FIELD,f)
#endif

  #define _MCASP_PWRDEMU0_FSETS(FIELD,SYM) _MCASP_PWRDEMU_FSETS(0,##FIELD,##SYM)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PWRDEMU1_FSETS(FIELD,SYM) _MCASP_PWRDEMU_FSETS(1,##FIELD,##SYM)
#endif


/******************************************************************************\
* Step 4.5
* _____________________
* |                   |
* |     PFUNC         |
* |___________________|
*
* PFUNC		- Pin Function / GPIO Enable Register
*
* FIELDS (msb -> lsb)
* (rw)  AFSR
* (rw)  AHCLKR 
* (rw)  ACLKR 
* (rw)  AFSX
* (rw)  AHCLKX 
* (rw)  ACLKX
* (rw)  AMUTE
* (rw)  AXR0-15 
\******************************************************************************/

  #define _MCASP_PFUNC_OFFSET                   4

  #define _MCASP_PFUNC0_ADDR		        (_MCASP_BASE_PORT0+4*_MCASP_PFUNC_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PFUNC1_ADDR		        (_MCASP_BASE_PORT1+4*_MCASP_PFUNC_OFFSET)
#endif
  #define _MCASP_PFUNC_AXR0_MASK		0x00000001u
  #define _MCASP_PFUNC_AXR0_SHIFT		0x00000000u
  #define  MCASP_PFUNC_AXR0_DEFAULT		0x00000000u
  #define  MCASP_PFUNC_AXR0_OF(x)		_VALUEOF(x)
  #define  MCASP_PFUNC_AXR0_MCASP		0x00000000u
  #define  MCASP_PFUNC_AXR0_GPIO		0x00000001u

  #define _MCASP_PFUNC_AXR1_MASK		0x00000002u
  #define _MCASP_PFUNC_AXR1_SHIFT		0x00000001u
  #define  MCASP_PFUNC_AXR1_DEFAULT		0x00000000u
  #define  MCASP_PFUNC_AXR1_OF(x)		_VALUEOF(x)
  #define  MCASP_PFUNC_AXR1_MCASP		0x00000000u
  #define  MCASP_PFUNC_AXR1_GPIO		0x00000001u

  #define _MCASP_PFUNC_AXR2_MASK		0x00000004u
  #define _MCASP_PFUNC_AXR2_SHIFT		0x00000002u
  #define  MCASP_PFUNC_AXR2_DEFAULT		0x00000000u
  #define  MCASP_PFUNC_AXR2_OF(x)		_VALUEOF(x)
  #define  MCASP_PFUNC_AXR2_MCASP		0x00000000u
  #define  MCASP_PFUNC_AXR2_GPIO		0x00000001u

  #define _MCASP_PFUNC_AXR3_MASK		0x00000008u
  #define _MCASP_PFUNC_AXR3_SHIFT		0x00000003u
  #define  MCASP_PFUNC_AXR3_DEFAULT		0x00000000u
  #define  MCASP_PFUNC_AXR3_OF(x)		_VALUEOF(x)
  #define  MCASP_PFUNC_AXR3_MCASP		0x00000000u
  #define  MCASP_PFUNC_AXR3_GPIO		0x00000001u
 /* Fields for _MCASP_CHANNEL_CNT == 4 end here*/

#if (_MCASP_CHANNEL_CNT > 4)
  #define _MCASP_PFUNC_AXR4_MASK		0x00000010u
  #define _MCASP_PFUNC_AXR4_SHIFT		0x00000004u
  #define  MCASP_PFUNC_AXR4_DEFAULT		0x00000000u
  #define  MCASP_PFUNC_AXR4_OF(x)		_VALUEOF(x)
  #define  MCASP_PFUNC_AXR4_MCASP		0x00000000u
  #define  MCASP_PFUNC_AXR4_GPIO		0x00000001u

  #define _MCASP_PFUNC_AXR5_MASK		0x00000020u
  #define _MCASP_PFUNC_AXR5_SHIFT		0x00000005u
  #define  MCASP_PFUNC_AXR5_DEFAULT		0x00000000u
  #define  MCASP_PFUNC_AXR5_OF(x)		_VALUEOF(x)
  #define  MCASP_PFUNC_AXR5_MCASP		0x00000000u
  #define  MCASP_PFUNC_AXR5_GPIO		0x00000001u
#endif /* _MCASP_CHANNEL_CNT == 6 */

#if (_MCASP_CHANNEL_CNT > 6) /* For channel count 8 and 16 */
  #define _MCASP_PFUNC_AXR6_MASK		0x00000040u
  #define _MCASP_PFUNC_AXR6_SHIFT		0x00000006u
  #define  MCASP_PFUNC_AXR6_DEFAULT		0x00000000u
  #define  MCASP_PFUNC_AXR6_OF(x)		_VALUEOF(x)
  #define  MCASP_PFUNC_AXR6_MCASP		0x00000000u
  #define  MCASP_PFUNC_AXR6_GPIO		0x00000001u

  #define _MCASP_PFUNC_AXR7_MASK		0x00000080u
  #define _MCASP_PFUNC_AXR7_SHIFT		0x00000007u
  #define  MCASP_PFUNC_AXR7_DEFAULT		0x00000000u
  #define  MCASP_PFUNC_AXR7_OF(x)		_VALUEOF(x)
  #define  MCASP_PFUNC_AXR7_MCASP		0x00000000u
  #define  MCASP_PFUNC_AXR7_GPIO		0x00000001u
#endif /* _MCASP_CHANNEL_CNT == 8 */

#if (_MCASP_CHANNEL_CNT == 16)
  #define _MCASP_PFUNC_AXR8_MASK		0x00000100u
  #define _MCASP_PFUNC_AXR8_SHIFT		0x00000008u
  #define  MCASP_PFUNC_AXR8_DEFAULT		0x00000000u
  #define  MCASP_PFUNC_AXR8_OF(x)		_VALUEOF(x)
  #define  MCASP_PFUNC_AXR8_MCASP		0x00000000u
  #define  MCASP_PFUNC_AXR8_GPIO		0x00000001u

  #define _MCASP_PFUNC_AXR9_MASK		0x00000200u
  #define _MCASP_PFUNC_AXR9_SHIFT		0x00000009u
  #define  MCASP_PFUNC_AXR9_DEFAULT		0x00000000u
  #define  MCASP_PFUNC_AXR9_OF(x)		_VALUEOF(x)
  #define  MCASP_PFUNC_AXR9_MCASP		0x00000000u
  #define  MCASP_PFUNC_AXR9_GPIO		0x00000001u

  #define _MCASP_PFUNC_AXR10_MASK		0x00000400u
  #define _MCASP_PFUNC_AXR10_SHIFT		0x0000000Au
  #define  MCASP_PFUNC_AXR10_DEFAULT		0x00000000u
  #define  MCASP_PFUNC_AXR10_OF(x)		_VALUEOF(x)
  #define  MCASP_PFUNC_AXR10_MCASP		0x00000000u
  #define  MCASP_PFUNC_AXR10_GPIO		0x00000001u

  #define _MCASP_PFUNC_AXR11_MASK		0x00000800u
  #define _MCASP_PFUNC_AXR11_SHIFT		0x0000000Bu
  #define  MCASP_PFUNC_AXR11_DEFAULT		0x00000000u
  #define  MCASP_PFUNC_AXR11_OF(x)		_VALUEOF(x)
  #define  MCASP_PFUNC_AXR11_MCASP		0x00000000u
  #define  MCASP_PFUNC_AXR11_GPIO		0x00000001u

  #define _MCASP_PFUNC_AXR12_MASK		0x00001000u
  #define _MCASP_PFUNC_AXR12_SHIFT		0x0000000Cu
  #define  MCASP_PFUNC_AXR12_DEFAULT		0x00000000u
  #define  MCASP_PFUNC_AXR12_OF(x)		_VALUEOF(x)
  #define  MCASP_PFUNC_AXR12_MCASP		0x00000000u
  #define  MCASP_PFUNC_AXR12_GPIO		0x00000001u

  #define _MCASP_PFUNC_AXR13_MASK		0x00002000u
  #define _MCASP_PFUNC_AXR13_SHIFT		0x0000000Du
  #define  MCASP_PFUNC_AXR13_DEFAULT		0x00000000u
  #define  MCASP_PFUNC_AXR13_OF(x)		_VALUEOF(x)
  #define  MCASP_PFUNC_AXR13_MCASP		0x00000000u
  #define  MCASP_PFUNC_AXR13_GPIO		0x00000001u

  #define _MCASP_PFUNC_AXR14_MASK		0x00004000u
  #define _MCASP_PFUNC_AXR14_SHIFT		0x0000000Eu
  #define  MCASP_PFUNC_AXR14_DEFAULT		0x00000000u
  #define  MCASP_PFUNC_AXR14_OF(x)		_VALUEOF(x)
  #define  MCASP_PFUNC_AXR14_MCASP		0x00000000u
  #define  MCASP_PFUNC_AXR14_GPIO		0x00000001u

  #define _MCASP_PFUNC_AXR15_MASK		0x00008000u
  #define _MCASP_PFUNC_AXR15_SHIFT		0x0000000Fu
  #define  MCASP_PFUNC_AXR15_DEFAULT		0x00000000u
  #define  MCASP_PFUNC_AXR15_OF(x)		_VALUEOF(x)
  #define  MCASP_PFUNC_AXR15_MCASP		0x00000000u
  #define  MCASP_PFUNC_AXR15_GPIO		0x00000001u
#endif /* _MCASP_CHANNEL_CNT == 16 */

  #define _MCASP_PFUNC_AMUTE_MASK		0x02000000u
  #define _MCASP_PFUNC_AMUTE_SHIFT		0x00000019u
  #define  MCASP_PFUNC_AMUTE_DEFAULT		0x00000000u
  #define  MCASP_PFUNC_AMUTE_OF(x)		_VALUEOF(x)
  #define  MCASP_PFUNC_AMUTE_MCASP		0x00000000u
  #define  MCASP_PFUNC_AMUTE_GPIO		0x00000001u

  #define _MCASP_PFUNC_ACLKX_MASK		0x04000000u
  #define _MCASP_PFUNC_ACLKX_SHIFT		0x0000001Au
  #define  MCASP_PFUNC_ACLKX_DEFAULT		0x00000000u
  #define  MCASP_PFUNC_ACLKX_OF(x)		_VALUEOF(x)
  #define  MCASP_PFUNC_ACLKX_MCASP		0x00000000u
  #define  MCASP_PFUNC_ACLKX_GPIO		0x00000001u

  #define _MCASP_PFUNC_AHCLKX_MASK		0x08000000u
  #define _MCASP_PFUNC_AHCLKX_SHIFT		0x0000001Bu
  #define  MCASP_PFUNC_AHCLKX_DEFAULT		0x00000000u
  #define  MCASP_PFUNC_AHCLKX_OF(x)		_VALUEOF(x)
  #define  MCASP_PFUNC_AHCLKX_MCASP		0x00000000u
  #define  MCASP_PFUNC_AHCLKX_GPIO		0x00000001u

  #define _MCASP_PFUNC_AFSX_MASK		0x10000000u
  #define _MCASP_PFUNC_AFSX_SHIFT		0x0000001Cu
  #define  MCASP_PFUNC_AFSX_DEFAULT		0x00000000u
  #define  MCASP_PFUNC_AFSX_OF(x)		_VALUEOF(x)
  #define  MCASP_PFUNC_AFSX_MCASP		0x00000000u
  #define  MCASP_PFUNC_AFSX_GPIO		0x00000001u

  #define _MCASP_PFUNC_ACLKR_MASK		0x20000000u
  #define _MCASP_PFUNC_ACLKR_SHIFT		0x0000001Du
  #define  MCASP_PFUNC_ACLKR_DEFAULT		0x00000000u
  #define  MCASP_PFUNC_ACLKR_OF(x)		_VALUEOF(x)
  #define  MCASP_PFUNC_ACLKR_MCASP		0x00000000u
  #define  MCASP_PFUNC_ACLKR_GPIO		0x00000001u

  #define _MCASP_PFUNC_AHCLKR_MASK		0x40000000u
  #define _MCASP_PFUNC_AHCLKR_SHIFT		0x0000001Eu
  #define  MCASP_PFUNC_AHCLKR_DEFAULT		0x00000000u
  #define  MCASP_PFUNC_AHCLKR_OF(x)		_VALUEOF(x)
  #define  MCASP_PFUNC_AHCLKR_MCASP		0x00000000u
  #define  MCASP_PFUNC_AHCLKR_GPIO		0x00000001u

  #define _MCASP_PFUNC_AFSR_MASK		0x80000000u
  #define _MCASP_PFUNC_AFSR_SHIFT		0x0000001Fu
  #define  MCASP_PFUNC_AFSR_DEFAULT		0x00000000u
  #define  MCASP_PFUNC_AFSR_OF(x)		_VALUEOF(x)
  #define  MCASP_PFUNC_AFSR_MCASP		0x00000000u
  #define  MCASP_PFUNC_AFSR_GPIO		0x00000001u


  #define  MCASP_PFUNC_OF(x)                    _VALUEOF(x)

#if (_MCASP_CHANNEL_CNT == 16)
  #define MCASP_PFUNC_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,PFUNC,AXR0)\
    |_PER_FDEFAULT(MCASP,PFUNC,AXR1)\
    |_PER_FDEFAULT(MCASP,PFUNC,AXR2)\
    |_PER_FDEFAULT(MCASP,PFUNC,AXR3)\
    |_PER_FDEFAULT(MCASP,PFUNC,AXR4)\
    |_PER_FDEFAULT(MCASP,PFUNC,AXR5)\
    |_PER_FDEFAULT(MCASP,PFUNC,AXR6)\
    |_PER_FDEFAULT(MCASP,PFUNC,AXR7)\
    |_PER_FDEFAULT(MCASP,PFUNC,AXR8)\
    |_PER_FDEFAULT(MCASP,PFUNC,AXR9)\
    |_PER_FDEFAULT(MCASP,PFUNC,AXR10)\
    |_PER_FDEFAULT(MCASP,PFUNC,AXR11)\
    |_PER_FDEFAULT(MCASP,PFUNC,AXR12)\
    |_PER_FDEFAULT(MCASP,PFUNC,AXR13)\
    |_PER_FDEFAULT(MCASP,PFUNC,AXR14)\
    |_PER_FDEFAULT(MCASP,PFUNC,AXR15)\
    |_PER_FDEFAULT(MCASP,PFUNC,AMUTE)\
    |_PER_FDEFAULT(MCASP,PFUNC,ACLKX)\
    |_PER_FDEFAULT(MCASP,PFUNC,AHCLKX)\
    |_PER_FDEFAULT(MCASP,PFUNC,AFSX)\
    |_PER_FDEFAULT(MCASP,PFUNC,ACLKR)\
    |_PER_FDEFAULT(MCASP,PFUNC,AHCLKR)\
    |_PER_FDEFAULT(MCASP,PFUNC,AFSR)\
  )

  #define MCASP_PFUNC_RMK(afsr,ahclkr,aclkr,afsx,ahclkx,aclkx,amute,  \
    axr15,axr14,axr13,axr12,axr11,axr10,\
    axr9, axr8,axr7,axr6,axr5,axr4,axr3,axr2,axr1, axr0) \
 (Uint32)( \
     _PER_FMK(MCASP,PFUNC,AXR0,axr0)\
    |_PER_FMK(MCASP,PFUNC,AXR1,axr1)\
    |_PER_FMK(MCASP,PFUNC,AXR2,axr2)\
    |_PER_FMK(MCASP,PFUNC,AXR3,axr3)\
    |_PER_FMK(MCASP,PFUNC,AXR4,axr4)\
    |_PER_FMK(MCASP,PFUNC,AXR5,axr5)\
    |_PER_FMK(MCASP,PFUNC,AXR6,axr6)\
    |_PER_FMK(MCASP,PFUNC,AXR7,axr7)\
    |_PER_FMK(MCASP,PFUNC,AXR8,axr8)\
    |_PER_FMK(MCASP,PFUNC,AXR9,axr9)\
    |_PER_FMK(MCASP,PFUNC,AXR10,axr10)\
    |_PER_FMK(MCASP,PFUNC,AXR11,axr11)\
    |_PER_FMK(MCASP,PFUNC,AXR12,axr12)\
    |_PER_FMK(MCASP,PFUNC,AXR13,axr13)\
    |_PER_FMK(MCASP,PFUNC,AXR14,axr14)\
    |_PER_FMK(MCASP,PFUNC,AXR15,axr15)\
    |_PER_FMK(MCASP,PFUNC,AMUTE,amute)\
    |_PER_FMK(MCASP,PFUNC,ACLKX,aclkx)\
    |_PER_FMK(MCASP,PFUNC,AHCLKX,ahclkx)\
    |_PER_FMK(MCASP,PFUNC,AFSX,afsx)\
    |_PER_FMK(MCASP,PFUNC,ACLKR,aclkr)\
    |_PER_FMK(MCASP,PFUNC,AHCLKR,ahclkr)\
    |_PER_FMK(MCASP,PFUNC,AFSR,afsr)\
  )
#endif  /* (_MCASP_CHANNEL_CNT == 16) */

#if (_MCASP_CHANNEL_CNT == 8)
  #define MCASP_PFUNC_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,PFUNC,AXR0)\
    |_PER_FDEFAULT(MCASP,PFUNC,AXR1)\
    |_PER_FDEFAULT(MCASP,PFUNC,AXR2)\
    |_PER_FDEFAULT(MCASP,PFUNC,AXR3)\
    |_PER_FDEFAULT(MCASP,PFUNC,AXR4)\
    |_PER_FDEFAULT(MCASP,PFUNC,AXR5)\
    |_PER_FDEFAULT(MCASP,PFUNC,AXR6)\
    |_PER_FDEFAULT(MCASP,PFUNC,AXR7)\
    |_PER_FDEFAULT(MCASP,PFUNC,AMUTE)\
    |_PER_FDEFAULT(MCASP,PFUNC,ACLKX)\
    |_PER_FDEFAULT(MCASP,PFUNC,AHCLKX)\
    |_PER_FDEFAULT(MCASP,PFUNC,AFSX)\
    |_PER_FDEFAULT(MCASP,PFUNC,ACLKR)\
    |_PER_FDEFAULT(MCASP,PFUNC,AHCLKR)\
    |_PER_FDEFAULT(MCASP,PFUNC,AFSR)\
  )

  #define MCASP_PFUNC_RMK(afsr,ahclkr,aclkr,afsx,ahclkx,aclkx,amute,  \
                          axr7,axr6,axr5,axr4,axr3,axr2,axr1, axr0) \
 (Uint32)( \
     _PER_FMK(MCASP,PFUNC,AXR0,axr0)\
    |_PER_FMK(MCASP,PFUNC,AXR1,axr1)\
    |_PER_FMK(MCASP,PFUNC,AXR2,axr2)\
    |_PER_FMK(MCASP,PFUNC,AXR3,axr3)\
    |_PER_FMK(MCASP,PFUNC,AXR4,axr4)\
    |_PER_FMK(MCASP,PFUNC,AXR5,axr5)\
    |_PER_FMK(MCASP,PFUNC,AXR6,axr6)\
    |_PER_FMK(MCASP,PFUNC,AXR7,axr7)\
    |_PER_FMK(MCASP,PFUNC,AMUTE,amute)\
    |_PER_FMK(MCASP,PFUNC,ACLKX,aclkx)\
    |_PER_FMK(MCASP,PFUNC,AHCLKX,ahclkx)\
    |_PER_FMK(MCASP,PFUNC,AFSX,afsx)\
    |_PER_FMK(MCASP,PFUNC,ACLKR,aclkr)\
    |_PER_FMK(MCASP,PFUNC,AHCLKR,ahclkr)\
    |_PER_FMK(MCASP,PFUNC,AFSR,afsr)\
  )
#endif /* (_MCASP_CHANNEL_CNT == 8) */

#if (_MCASP_CHANNEL_CNT == 6)
  #define MCASP_PFUNC_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,PFUNC,AXR0)\
    |_PER_FDEFAULT(MCASP,PFUNC,AXR1)\
    |_PER_FDEFAULT(MCASP,PFUNC,AXR2)\
    |_PER_FDEFAULT(MCASP,PFUNC,AXR3)\
    |_PER_FDEFAULT(MCASP,PFUNC,AXR4)\
    |_PER_FDEFAULT(MCASP,PFUNC,AXR5)\
    |_PER_FDEFAULT(MCASP,PFUNC,AMUTE)\
    |_PER_FDEFAULT(MCASP,PFUNC,ACLKX)\
    |_PER_FDEFAULT(MCASP,PFUNC,AHCLKX)\
    |_PER_FDEFAULT(MCASP,PFUNC,AFSX)\
    |_PER_FDEFAULT(MCASP,PFUNC,ACLKR)\
    |_PER_FDEFAULT(MCASP,PFUNC,AHCLKR)\
    |_PER_FDEFAULT(MCASP,PFUNC,AFSR)\
  )

  #define MCASP_PFUNC_RMK(afsr,ahclkr,aclkr,afsx,ahclkx,aclkx,amute,  \
                          axr5,axr4,axr3,axr2,axr1, axr0) \
 (Uint32)( \
     _PER_FMK(MCASP,PFUNC,AXR0,axr0)\
    |_PER_FMK(MCASP,PFUNC,AXR1,axr1)\
    |_PER_FMK(MCASP,PFUNC,AXR2,axr2)\
    |_PER_FMK(MCASP,PFUNC,AXR3,axr3)\
    |_PER_FMK(MCASP,PFUNC,AXR4,axr4)\
    |_PER_FMK(MCASP,PFUNC,AXR5,axr5)\
    |_PER_FMK(MCASP,PFUNC,AMUTE,amute)\
    |_PER_FMK(MCASP,PFUNC,ACLKX,aclkx)\
    |_PER_FMK(MCASP,PFUNC,AHCLKX,ahclkx)\
    |_PER_FMK(MCASP,PFUNC,AFSX,afsx)\
    |_PER_FMK(MCASP,PFUNC,ACLKR,aclkr)\
    |_PER_FMK(MCASP,PFUNC,AHCLKR,ahclkr)\
    |_PER_FMK(MCASP,PFUNC,AFSR,afsr)\
  )
#endif /* (_MCASP_CHANNEL_CNT == 6) */

#if (_MCASP_CHANNEL_CNT == 4)
  #define MCASP_PFUNC_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,PFUNC,AXR0)\
    |_PER_FDEFAULT(MCASP,PFUNC,AXR1)\
    |_PER_FDEFAULT(MCASP,PFUNC,AXR2)\
    |_PER_FDEFAULT(MCASP,PFUNC,AXR3)\
    |_PER_FDEFAULT(MCASP,PFUNC,AMUTE)\
    |_PER_FDEFAULT(MCASP,PFUNC,ACLKX)\
    |_PER_FDEFAULT(MCASP,PFUNC,AHCLKX)\
    |_PER_FDEFAULT(MCASP,PFUNC,AFSX)\
    |_PER_FDEFAULT(MCASP,PFUNC,ACLKR)\
    |_PER_FDEFAULT(MCASP,PFUNC,AHCLKR)\
    |_PER_FDEFAULT(MCASP,PFUNC,AFSR)\
  )

  #define MCASP_PFUNC_RMK(afsr,ahclkr,aclkr,afsx,ahclkx,aclkx,amute,  \
                          axr3,axr2,axr1, axr0) \
 (Uint32)( \
     _PER_FMK(MCASP,PFUNC,AXR0,axr0)\
    |_PER_FMK(MCASP,PFUNC,AXR1,axr1)\
    |_PER_FMK(MCASP,PFUNC,AXR2,axr2)\
    |_PER_FMK(MCASP,PFUNC,AXR3,axr3)\
    |_PER_FMK(MCASP,PFUNC,AMUTE,amute)\
    |_PER_FMK(MCASP,PFUNC,ACLKX,aclkx)\
    |_PER_FMK(MCASP,PFUNC,AHCLKX,ahclkx)\
    |_PER_FMK(MCASP,PFUNC,AFSX,afsx)\
    |_PER_FMK(MCASP,PFUNC,ACLKR,aclkr)\
    |_PER_FMK(MCASP,PFUNC,AHCLKR,ahclkr)\
    |_PER_FMK(MCASP,PFUNC,AFSR,afsr)\
  )
#endif /* (_MCASP_CHANNEL_CNT == 4) */


  #define _MCASP_PFUNC_FGET(N,FIELD)\
    _PER_FGET(_MCASP_PFUNC##N##_ADDR,MCASP,PFUNC,##FIELD)

  #define _MCASP_PFUNC_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_PFUNC##N##_ADDR,MCASP,PFUNC,##FIELD,field)

  #define _MCASP_PFUNC_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_PFUNC##N##_ADDR,MCASP,PFUNC,##FIELD,##SYM)

  #define _MCASP_PFUNC0_FGET(FIELD) _MCASP_PFUNC_FGET(0,##FIELD)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PFUNC1_FGET(FIELD) _MCASP_PFUNC_FGET(1,##FIELD)
#endif
 
  #define _MCASP_PFUNC0_FSET(FIELD,f) _MCASP_PFUNC_FSET(0,##FIELD,f)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PFUNC1_FSET(FIELD,f) _MCASP_PFUNC_FSET(1,##FIELD,f)
#endif

  #define _MCASP_PFUNC0_FSETS(FIELD,SYM) _MCASP_PFUNC_FSETS(0,##FIELD,##SYM)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PFUNC1_FSETS(FIELD,SYM) _MCASP_PFUNC_FSETS(1,##FIELD,##SYM)
#endif


/******************************************************************************\
* Step 4.5
* _____________________
* |                   |
* |     PDIR          |
* |___________________|
*
* PDIR		- Pin Direction Register
*
* FIELDS (msb -> lsb)
* (rw)  AFSR
* (rw)  AHCLKR 
* (rw)  ACLKR 
* (rw)  AFSX
* (rw)  AHCLKX 
* (rw)  ACLKX
* (rw)  AMUTE
* (rw)  AXR0-15 
*
\******************************************************************************/

  #define _MCASP_PDIR_OFFSET		5

  #define _MCASP_PDIR0_ADDR		(_MCASP_BASE_PORT0+4*_MCASP_PDIR_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PDIR1_ADDR		(_MCASP_BASE_PORT1+4*_MCASP_PDIR_OFFSET)
#endif

  #define _MCASP_PDIR_AXR0_MASK		0x00000001u
  #define _MCASP_PDIR_AXR0_SHIFT	0x00000000u
  #define  MCASP_PDIR_AXR0_DEFAULT	0x00000000u
  #define  MCASP_PDIR_AXR0_OF(x)	_VALUEOF(x)
  #define  MCASP_PDIR_AXR0_IN		0x00000000u
  #define  MCASP_PDIR_AXR0_OUT		0x00000001u

  #define _MCASP_PDIR_AXR1_MASK		0x00000002u
  #define _MCASP_PDIR_AXR1_SHIFT	0x00000001u
  #define  MCASP_PDIR_AXR1_DEFAULT	0x00000000u
  #define  MCASP_PDIR_AXR1_OF(x)	_VALUEOF(x)
  #define  MCASP_PDIR_AXR1_IN		0x00000000u
  #define  MCASP_PDIR_AXR1_OUT		0x00000001u

  #define _MCASP_PDIR_AXR2_MASK		0x00000004u
  #define _MCASP_PDIR_AXR2_SHIFT	0x00000002u
  #define  MCASP_PDIR_AXR2_DEFAULT	0x00000000u
  #define  MCASP_PDIR_AXR2_OF(x)	_VALUEOF(x)
  #define  MCASP_PDIR_AXR2_IN		0x00000000u
  #define  MCASP_PDIR_AXR2_OUT		0x00000001u

  #define _MCASP_PDIR_AXR3_MASK		0x00000008u
  #define _MCASP_PDIR_AXR3_SHIFT	0x00000003u
  #define  MCASP_PDIR_AXR3_DEFAULT	0x00000000u
  #define  MCASP_PDIR_AXR3_OF(x)	_VALUEOF(x)
  #define  MCASP_PDIR_AXR3_IN		0x00000000u
  #define  MCASP_PDIR_AXR3_OUT		0x00000001u
 /* Fields for _MCASP_CHANNEL_CNT == 4 end here*/

#if (_MCASP_CHANNEL_CNT > 4)
  #define _MCASP_PDIR_AXR4_MASK		0x00000010u
  #define _MCASP_PDIR_AXR4_SHIFT	0x00000004u
  #define  MCASP_PDIR_AXR4_DEFAULT	0x00000000u
  #define  MCASP_PDIR_AXR4_OF(x)	_VALUEOF(x)
  #define  MCASP_PDIR_AXR4_IN		0x00000000u
  #define  MCASP_PDIR_AXR4_OUT		0x00000001u

  #define _MCASP_PDIR_AXR5_MASK		0x00000020u
  #define _MCASP_PDIR_AXR5_SHIFT	0x00000005u
  #define  MCASP_PDIR_AXR5_DEFAULT	0x00000000u
  #define  MCASP_PDIR_AXR5_OF(x)	_VALUEOF(x)
  #define  MCASP_PDIR_AXR5_IN		0x00000000u
  #define  MCASP_PDIR_AXR5_OUT		0x00000001u
#endif /* _MCASP_CHANNEL_CNT == 6 */

#if (_MCASP_CHANNEL_CNT > 6) /* For channel count 8 and 16 */
  #define _MCASP_PDIR_AXR6_MASK		0x00000040u
  #define _MCASP_PDIR_AXR6_SHIFT	0x00000006u
  #define  MCASP_PDIR_AXR6_DEFAULT	0x00000000u
  #define  MCASP_PDIR_AXR6_OF(x)	_VALUEOF(x)
  #define  MCASP_PDIR_AXR6_IN		0x00000000u
  #define  MCASP_PDIR_AXR6_OUT		0x00000001u

  #define _MCASP_PDIR_AXR7_MASK		0x00000080u
  #define _MCASP_PDIR_AXR7_SHIFT	0x00000007u
  #define  MCASP_PDIR_AXR7_DEFAULT	0x00000000u
  #define  MCASP_PDIR_AXR7_OF(x)	_VALUEOF(x)
  #define  MCASP_PDIR_AXR7_IN		0x00000000u
  #define  MCASP_PDIR_AXR7_OUT		0x00000001u
#endif /* _MCASP_CHANNEL_CNT == 8 */

#if (_MCASP_CHANNEL_CNT == 16)
  #define _MCASP_PDIR_AXR8_MASK		0x00000100u
  #define _MCASP_PDIR_AXR8_SHIFT	0x00000008u
  #define  MCASP_PDIR_AXR8_DEFAULT	0x00000000u
  #define  MCASP_PDIR_AXR8_OF(x)	_VALUEOF(x)
  #define  MCASP_PDIR_AXR8_IN		0x00000000u
  #define  MCASP_PDIR_AXR8_OUT		0x00000001u

  #define _MCASP_PDIR_AXR9_MASK		0x00000200u
  #define _MCASP_PDIR_AXR9_SHIFT	0x00000009u
  #define  MCASP_PDIR_AXR9_DEFAULT	0x00000000u
  #define  MCASP_PDIR_AXR9_OF(x)	_VALUEOF(x)
  #define  MCASP_PDIR_AXR9_IN		0x00000000u
  #define  MCASP_PDIR_AXR9_OUT		0x00000001u

  #define _MCASP_PDIR_AXR10_MASK	0x00000400u
  #define _MCASP_PDIR_AXR10_SHIFT	0x0000000Au
  #define  MCASP_PDIR_AXR10_DEFAULT	0x00000000u
  #define  MCASP_PDIR_AXR10_OF(x)	_VALUEOF(x)
  #define  MCASP_PDIR_AXR10_IN		0x00000000u
  #define  MCASP_PDIR_AXR10_OUT		0x00000001u

  #define _MCASP_PDIR_AXR11_MASK	0x00000800u
  #define _MCASP_PDIR_AXR11_SHIFT	0x0000000Bu
  #define  MCASP_PDIR_AXR11_DEFAULT	0x00000000u
  #define  MCASP_PDIR_AXR11_OF(x)	_VALUEOF(x)
  #define  MCASP_PDIR_AXR11_IN		0x00000000u
  #define  MCASP_PDIR_AXR11_OUT		0x00000001u

  #define _MCASP_PDIR_AXR12_MASK	0x00001000u
  #define _MCASP_PDIR_AXR12_SHIFT	0x0000000Cu
  #define  MCASP_PDIR_AXR12_DEFAULT	0x00000000u
  #define  MCASP_PDIR_AXR12_OF(x)	_VALUEOF(x)
  #define  MCASP_PDIR_AXR12_IN		0x00000000u
  #define  MCASP_PDIR_AXR12_OUT		0x00000001u

  #define _MCASP_PDIR_AXR13_MASK	0x00002000u
  #define _MCASP_PDIR_AXR13_SHIFT	0x0000000Du
  #define  MCASP_PDIR_AXR13_DEFAULT	0x00000000u
  #define  MCASP_PDIR_AXR13_OF(x)	_VALUEOF(x)
  #define  MCASP_PDIR_AXR13_IN		0x00000000u
  #define  MCASP_PDIR_AXR13_OUT		0x00000001u

  #define _MCASP_PDIR_AXR14_MASK	0x00004000u
  #define _MCASP_PDIR_AXR14_SHIFT	0x0000000Eu
  #define  MCASP_PDIR_AXR14_DEFAULT	0x00000000u
  #define  MCASP_PDIR_AXR14_OF(x)	_VALUEOF(x)
  #define  MCASP_PDIR_AXR14_IN		0x00000000u
  #define  MCASP_PDIR_AXR14_OUT		0x00000001u

  #define _MCASP_PDIR_AXR15_MASK	0x00008000u
  #define _MCASP_PDIR_AXR15_SHIFT	0x0000000Fu
  #define  MCASP_PDIR_AXR15_DEFAULT	0x00000000u
  #define  MCASP_PDIR_AXR15_OF(x)	_VALUEOF(x)
  #define  MCASP_PDIR_AXR15_IN		0x00000000u
  #define  MCASP_PDIR_AXR15_OUT		0x00000001u
#endif /* _MCASP_CHANNEL_CNT == 16 */

  #define _MCASP_PDIR_AMUTE_MASK	0x02000000u
  #define _MCASP_PDIR_AMUTE_SHIFT	0x00000019u
  #define  MCASP_PDIR_AMUTE_DEFAULT	0x00000000u
  #define  MCASP_PDIR_AMUTE_OF(x)	_VALUEOF(x)
  #define  MCASP_PDIR_AMUTE_IN		0x00000000u
  #define  MCASP_PDIR_AMUTE_OUT		0x00000001u

  #define _MCASP_PDIR_ACLKX_MASK	0x04000000u
  #define _MCASP_PDIR_ACLKX_SHIFT	0x0000001Au
  #define  MCASP_PDIR_ACLKX_DEFAULT	0x00000000u
  #define  MCASP_PDIR_ACLKX_OF(x)	_VALUEOF(x)
  #define  MCASP_PDIR_ACLKX_IN		0x00000000u
  #define  MCASP_PDIR_ACLKX_OUT		0x00000001u

  #define _MCASP_PDIR_AHCLKX_MASK	0x08000000u
  #define _MCASP_PDIR_AHCLKX_SHIFT	0x0000001Bu
  #define  MCASP_PDIR_AHCLKX_DEFAULT	0x00000000u
  #define  MCASP_PDIR_AHCLKX_OF(x)	_VALUEOF(x)
  #define  MCASP_PDIR_AHCLKX_IN		0x00000000u
  #define  MCASP_PDIR_AHCLKX_OUT	0x00000001u

  #define _MCASP_PDIR_AFSX_MASK		0x10000000u
  #define _MCASP_PDIR_AFSX_SHIFT	0x0000001Cu
  #define  MCASP_PDIR_AFSX_DEFAULT	0x00000000u
  #define  MCASP_PDIR_AFSX_OF(x)	_VALUEOF(x)
  #define  MCASP_PDIR_AFSX_IN		0x00000000u
  #define  MCASP_PDIR_AFSX_OUT		0x00000001u

  #define _MCASP_PDIR_ACLKR_MASK	0x20000000u
  #define _MCASP_PDIR_ACLKR_SHIFT	0x0000001Du
  #define  MCASP_PDIR_ACLKR_DEFAULT	0x00000000u
  #define  MCASP_PDIR_ACLKR_OF(x)	_VALUEOF(x)
  #define  MCASP_PDIR_ACLKR_IN		0x00000000u
  #define  MCASP_PDIR_ACLKR_OUT		0x00000001u

  #define _MCASP_PDIR_AHCLKR_MASK	0x40000000u
  #define _MCASP_PDIR_AHCLKR_SHIFT	0x0000001Eu
  #define  MCASP_PDIR_AHCLKR_DEFAULT	0x00000000u
  #define  MCASP_PDIR_AHCLKR_OF(x)	_VALUEOF(x)
  #define  MCASP_PDIR_AHCLKR_IN		0x00000000u
  #define  MCASP_PDIR_AHCLKR_OUT	0x00000001u

  #define _MCASP_PDIR_AFSR_MASK		0x80000000u
  #define _MCASP_PDIR_AFSR_SHIFT	0x0000001Fu
  #define  MCASP_PDIR_AFSR_DEFAULT	0x00000000u
  #define  MCASP_PDIR_AFSR_OF(x)	_VALUEOF(x)
  #define  MCASP_PDIR_AFSR_IN		0x00000000u
  #define  MCASP_PDIR_AFSR_OUT		0x00000001u

  #define  MCASP_PDIR_OF(x)	        _VALUEOF(x)

#if (_MCASP_CHANNEL_CNT == 16)
  #define MCASP_PDIR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,PDIR,AXR0)\
    |_PER_FDEFAULT(MCASP,PDIR,AXR1)\
    |_PER_FDEFAULT(MCASP,PDIR,AXR2)\
    |_PER_FDEFAULT(MCASP,PDIR,AXR3)\
    |_PER_FDEFAULT(MCASP,PDIR,AXR4)\
    |_PER_FDEFAULT(MCASP,PDIR,AXR5)\
    |_PER_FDEFAULT(MCASP,PDIR,AXR6)\
    |_PER_FDEFAULT(MCASP,PDIR,AXR7)\
    |_PER_FDEFAULT(MCASP,PDIR,AXR8)\
    |_PER_FDEFAULT(MCASP,PDIR,AXR9)\
    |_PER_FDEFAULT(MCASP,PDIR,AXR10)\
    |_PER_FDEFAULT(MCASP,PDIR,AXR11)\
    |_PER_FDEFAULT(MCASP,PDIR,AXR12)\
    |_PER_FDEFAULT(MCASP,PDIR,AXR13)\
    |_PER_FDEFAULT(MCASP,PDIR,AXR14)\
    |_PER_FDEFAULT(MCASP,PDIR,AXR15)\
    |_PER_FDEFAULT(MCASP,PDIR,AMUTE)\
    |_PER_FDEFAULT(MCASP,PDIR,ACLKX)\
    |_PER_FDEFAULT(MCASP,PDIR,AHCLKX)\
    |_PER_FDEFAULT(MCASP,PDIR,AFSX)\
    |_PER_FDEFAULT(MCASP,PDIR,ACLKR)\
    |_PER_FDEFAULT(MCASP,PDIR,AHCLKR)\
    |_PER_FDEFAULT(MCASP,PDIR,AFSR)\
  )

  #define MCASP_PDIR_RMK(afsr,ahclkr,aclkr,afsx,ahclkx,aclkx,amute,  \
    axr15,axr14,axr13,axr12,axr11,axr10,\
    axr9, axr8,axr7,axr6,axr5,axr4,axr3,axr2,axr1, axr0) \
   (Uint32)( \
     _PER_FMK(MCASP,PDIR,AXR0,axr0)\
    |_PER_FMK(MCASP,PDIR,AXR1,axr1)\
    |_PER_FMK(MCASP,PDIR,AXR2,axr2)\
    |_PER_FMK(MCASP,PDIR,AXR3,axr3)\
    |_PER_FMK(MCASP,PDIR,AXR4,axr4)\
    |_PER_FMK(MCASP,PDIR,AXR5,axr5)\
    |_PER_FMK(MCASP,PDIR,AXR6,axr6)\
    |_PER_FMK(MCASP,PDIR,AXR7,axr7)\
    |_PER_FMK(MCASP,PDIR,AXR8,axr8)\
    |_PER_FMK(MCASP,PDIR,AXR9,axr9)\
    |_PER_FMK(MCASP,PDIR,AXR10,axr10)\
    |_PER_FMK(MCASP,PDIR,AXR11,axr11)\
    |_PER_FMK(MCASP,PDIR,AXR12,axr12)\
    |_PER_FMK(MCASP,PDIR,AXR13,axr13)\
    |_PER_FMK(MCASP,PDIR,AXR14,axr14)\
    |_PER_FMK(MCASP,PDIR,AXR15,axr15)\
    |_PER_FMK(MCASP,PDIR,AMUTE,amute)\
    |_PER_FMK(MCASP,PDIR,ACLKX,aclkx)\
    |_PER_FMK(MCASP,PDIR,AHCLKX,ahclkx)\
    |_PER_FMK(MCASP,PDIR,AFSX,afsx)\
    |_PER_FMK(MCASP,PDIR,ACLKR,aclkr)\
    |_PER_FMK(MCASP,PDIR,AHCLKR,ahclkr)\
    |_PER_FMK(MCASP,PDIR,AFSR,afsr)\
  )
#endif /* _MCASP_CHANNEL_CNT == 16 */

#if (_MCASP_CHANNEL_CNT == 8)
  #define MCASP_PDIR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,PDIR,AXR0)\
    |_PER_FDEFAULT(MCASP,PDIR,AXR1)\
    |_PER_FDEFAULT(MCASP,PDIR,AXR2)\
    |_PER_FDEFAULT(MCASP,PDIR,AXR3)\
    |_PER_FDEFAULT(MCASP,PDIR,AXR4)\
    |_PER_FDEFAULT(MCASP,PDIR,AXR5)\
    |_PER_FDEFAULT(MCASP,PDIR,AXR6)\
    |_PER_FDEFAULT(MCASP,PDIR,AXR7)\
    |_PER_FDEFAULT(MCASP,PDIR,AMUTE)\
    |_PER_FDEFAULT(MCASP,PDIR,ACLKX)\
    |_PER_FDEFAULT(MCASP,PDIR,AHCLKX)\
    |_PER_FDEFAULT(MCASP,PDIR,AFSX)\
    |_PER_FDEFAULT(MCASP,PDIR,ACLKR)\
    |_PER_FDEFAULT(MCASP,PDIR,AHCLKR)\
    |_PER_FDEFAULT(MCASP,PDIR,AFSR)\
  )

  #define MCASP_PDIR_RMK(afsr,ahclkr,aclkr,afsx,ahclkx,aclkx,amute,  \
                         axr7,axr6,axr5,axr4,axr3,axr2,axr1, axr0) \
   (Uint32)( \
     _PER_FMK(MCASP,PDIR,AXR0,axr0)\
    |_PER_FMK(MCASP,PDIR,AXR1,axr1)\
    |_PER_FMK(MCASP,PDIR,AXR2,axr2)\
    |_PER_FMK(MCASP,PDIR,AXR3,axr3)\
    |_PER_FMK(MCASP,PDIR,AXR4,axr4)\
    |_PER_FMK(MCASP,PDIR,AXR5,axr5)\
    |_PER_FMK(MCASP,PDIR,AXR6,axr6)\
    |_PER_FMK(MCASP,PDIR,AXR7,axr7)\
    |_PER_FMK(MCASP,PDIR,AMUTE,amute)\
    |_PER_FMK(MCASP,PDIR,ACLKX,aclkx)\
    |_PER_FMK(MCASP,PDIR,AHCLKX,ahclkx)\
    |_PER_FMK(MCASP,PDIR,AFSX,afsx)\
    |_PER_FMK(MCASP,PDIR,ACLKR,aclkr)\
    |_PER_FMK(MCASP,PDIR,AHCLKR,ahclkr)\
    |_PER_FMK(MCASP,PDIR,AFSR,afsr)\
  )
#endif /* _MCASP_CHANNEL_CNT == 8 */

#if (_MCASP_CHANNEL_CNT == 6)
  #define MCASP_PDIR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,PDIR,AXR0)\
    |_PER_FDEFAULT(MCASP,PDIR,AXR1)\
    |_PER_FDEFAULT(MCASP,PDIR,AXR2)\
    |_PER_FDEFAULT(MCASP,PDIR,AXR3)\
    |_PER_FDEFAULT(MCASP,PDIR,AXR4)\
    |_PER_FDEFAULT(MCASP,PDIR,AXR5)\
    |_PER_FDEFAULT(MCASP,PDIR,AMUTE)\
    |_PER_FDEFAULT(MCASP,PDIR,ACLKX)\
    |_PER_FDEFAULT(MCASP,PDIR,AHCLKX)\
    |_PER_FDEFAULT(MCASP,PDIR,AFSX)\
    |_PER_FDEFAULT(MCASP,PDIR,ACLKR)\
    |_PER_FDEFAULT(MCASP,PDIR,AHCLKR)\
    |_PER_FDEFAULT(MCASP,PDIR,AFSR)\
  )

  #define MCASP_PDIR_RMK(afsr,ahclkr,aclkr,afsx,ahclkx,aclkx,amute,  \
                         axr5,axr4,axr3,axr2,axr1, axr0) \
   (Uint32)( \
     _PER_FMK(MCASP,PDIR,AXR0,axr0)\
    |_PER_FMK(MCASP,PDIR,AXR1,axr1)\
    |_PER_FMK(MCASP,PDIR,AXR2,axr2)\
    |_PER_FMK(MCASP,PDIR,AXR3,axr3)\
    |_PER_FMK(MCASP,PDIR,AXR4,axr4)\
    |_PER_FMK(MCASP,PDIR,AXR5,axr5)\
    |_PER_FMK(MCASP,PDIR,AMUTE,amute)\
    |_PER_FMK(MCASP,PDIR,ACLKX,aclkx)\
    |_PER_FMK(MCASP,PDIR,AHCLKX,ahclkx)\
    |_PER_FMK(MCASP,PDIR,AFSX,afsx)\
    |_PER_FMK(MCASP,PDIR,ACLKR,aclkr)\
    |_PER_FMK(MCASP,PDIR,AHCLKR,ahclkr)\
    |_PER_FMK(MCASP,PDIR,AFSR,afsr)\
  )
#endif /* _MCASP_CHANNEL_CNT == 6 */

#if (_MCASP_CHANNEL_CNT == 4)
  #define MCASP_PDIR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,PDIR,AXR0)\
    |_PER_FDEFAULT(MCASP,PDIR,AXR1)\
    |_PER_FDEFAULT(MCASP,PDIR,AXR2)\
    |_PER_FDEFAULT(MCASP,PDIR,AXR3)\
    |_PER_FDEFAULT(MCASP,PDIR,AMUTE)\
    |_PER_FDEFAULT(MCASP,PDIR,ACLKX)\
    |_PER_FDEFAULT(MCASP,PDIR,AHCLKX)\
    |_PER_FDEFAULT(MCASP,PDIR,AFSX)\
    |_PER_FDEFAULT(MCASP,PDIR,ACLKR)\
    |_PER_FDEFAULT(MCASP,PDIR,AHCLKR)\
    |_PER_FDEFAULT(MCASP,PDIR,AFSR)\
  )

  #define MCASP_PDIR_RMK(afsr,ahclkr,aclkr,afsx,ahclkx,aclkx,amute,  \
                         axr3,axr2,axr1, axr0) \
   (Uint32)( \
     _PER_FMK(MCASP,PDIR,AXR0,axr0)\
    |_PER_FMK(MCASP,PDIR,AXR1,axr1)\
    |_PER_FMK(MCASP,PDIR,AXR2,axr2)\
    |_PER_FMK(MCASP,PDIR,AXR3,axr3)\
    |_PER_FMK(MCASP,PDIR,AMUTE,amute)\
    |_PER_FMK(MCASP,PDIR,ACLKX,aclkx)\
    |_PER_FMK(MCASP,PDIR,AHCLKX,ahclkx)\
    |_PER_FMK(MCASP,PDIR,AFSX,afsx)\
    |_PER_FMK(MCASP,PDIR,ACLKR,aclkr)\
    |_PER_FMK(MCASP,PDIR,AHCLKR,ahclkr)\
    |_PER_FMK(MCASP,PDIR,AFSR,afsr)\
  )
#endif /* _MCASP_CHANNEL_CNT == 4 */

  #define _MCASP_PDIR_FGET(N,FIELD)\
    _PER_FGET(_MCASP_PDIR##N##_ADDR,MCASP,PDIR,##FIELD)

  #define _MCASP_PDIR_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_PDIR##N##_ADDR,MCASP,PDIR,##FIELD,field)

  #define _MCASP_PDIR_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_PDIR##N##_ADDR,MCASP,PDIR,##FIELD,##SYM)
 
  #define _MCASP_PDIR0_FGET(FIELD) _MCASP_PDIR_FGET(0,##FIELD)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PDIR1_FGET(FIELD) _MCASP_PDIR_FGET(1,##FIELD)
#endif

  #define _MCASP_PDIR0_FSET(FIELD,f) _MCASP_PDIR_FSET(0,##FIELD,f)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PDIR1_FSET(FIELD,f) _MCASP_PDIR_FSET(1,##FIELD,f)
#endif

  #define _MCASP_PDIR0_FSETS(FIELD,SYM) _MCASP_PDIR_FSETS(0,##FIELD,##SYM)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PDIR1_FSETS(FIELD,SYM) _MCASP_PDIR_FSETS(1,##FIELD,##SYM)
#endif


/******************************************************************************\
* 
* _____________________
* |                   |
* |     PDOUT         |
* |___________________|
*
* PDOUT		- Pin Data Output Register
*
* FIELDS (msb -> lsb)
* (rw)  AFSR
* (rw)  AHCLKR 
* (rw)  ACLKR 
* (rw)  AFSX
* (rw)  AHCLKX 
* (rw)  ACLKX
* (rw)  AMUTE
* (rw)  AXR0-15 
*
\******************************************************************************/

  #define _MCASP_PDOUT_OFFSET                   6

  #define _MCASP_PDOUT0_ADDR			(_MCASP_BASE_PORT0+4*_MCASP_PDOUT_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PDOUT1_ADDR			(_MCASP_BASE_PORT1+4*_MCASP_PDOUT_OFFSET)
#endif

  #define _MCASP_PDOUT_AXR0_MASK        	0x00000001u
  #define _MCASP_PDOUT_AXR0_SHIFT       	0x00000000u
  #define  MCASP_PDOUT_AXR0_DEFAULT		0x00000000u
  #define  MCASP_PDOUT_AXR0_OF(x)		_VALUEOF(x)
  #define  MCASP_PDOUT_AXR0_LOW	         	0x00000000u
  #define  MCASP_PDOUT_AXR0_HIGH		0x00000001u

  #define _MCASP_PDOUT_AXR1_MASK        	0x00000002u
  #define _MCASP_PDOUT_AXR1_SHIFT       	0x00000001u
  #define  MCASP_PDOUT_AXR1_DEFAULT		0x00000000u
  #define  MCASP_PDOUT_AXR1_OF(x)		_VALUEOF(x)
  #define  MCASP_PDOUT_AXR1_LOW	         	0x00000000u
  #define  MCASP_PDOUT_AXR1_HIGH		0x00000001u

  #define _MCASP_PDOUT_AXR2_MASK        	0x00000004u
  #define _MCASP_PDOUT_AXR2_SHIFT       	0x00000002u
  #define  MCASP_PDOUT_AXR2_DEFAULT		0x00000000u
  #define  MCASP_PDOUT_AXR2_OF(x)		_VALUEOF(x)
  #define  MCASP_PDOUT_AXR2_LOW	         	0x00000000u
  #define  MCASP_PDOUT_AXR2_HIGH		0x00000001u

  #define _MCASP_PDOUT_AXR3_MASK        	0x00000008u
  #define _MCASP_PDOUT_AXR3_SHIFT       	0x00000003u
  #define  MCASP_PDOUT_AXR3_DEFAULT		0x00000000u
  #define  MCASP_PDOUT_AXR3_OF(x)		_VALUEOF(x)
  #define  MCASP_PDOUT_AXR3_LOW	         	0x00000000u
  #define  MCASP_PDOUT_AXR3_HIGH		0x00000001u
 /* Fields for _MCASP_CHANNEL_CNT == 4 end here*/

#if (_MCASP_CHANNEL_CNT > 4)
  #define _MCASP_PDOUT_AXR4_MASK        	0x00000010u
  #define _MCASP_PDOUT_AXR4_SHIFT       	0x00000004u
  #define  MCASP_PDOUT_AXR4_DEFAULT		0x00000000u
  #define  MCASP_PDOUT_AXR4_OF(x)		_VALUEOF(x)
  #define  MCASP_PDOUT_AXR4_LOW	         	0x00000000u
  #define  MCASP_PDOUT_AXR4_HIGH		0x00000001u

  #define _MCASP_PDOUT_AXR5_MASK        	0x00000020u
  #define _MCASP_PDOUT_AXR5_SHIFT       	0x00000005u
  #define  MCASP_PDOUT_AXR5_DEFAULT		0x00000000u
  #define  MCASP_PDOUT_AXR5_OF(x)		_VALUEOF(x)
  #define  MCASP_PDOUT_AXR5_LOW	         	0x00000000u
  #define  MCASP_PDOUT_AXR5_HIGH		0x00000001u
#endif /* _MCASP_CHANNEL_CNT == 6 */

#if (_MCASP_CHANNEL_CNT > 6) /* For channel count 8 and 16 */
  #define _MCASP_PDOUT_AXR6_MASK        	0x00000040u
  #define _MCASP_PDOUT_AXR6_SHIFT       	0x00000006u
  #define  MCASP_PDOUT_AXR6_DEFAULT		0x00000000u
  #define  MCASP_PDOUT_AXR6_OF(x)		_VALUEOF(x)
  #define  MCASP_PDOUT_AXR6_LOW	         	0x00000000u
  #define  MCASP_PDOUT_AXR6_HIGH		0x00000001u

  #define _MCASP_PDOUT_AXR7_MASK        	0x00000080u
  #define _MCASP_PDOUT_AXR7_SHIFT       	0x00000007u
  #define  MCASP_PDOUT_AXR7_DEFAULT		0x00000000u
  #define  MCASP_PDOUT_AXR7_OF(x)		_VALUEOF(x)
  #define  MCASP_PDOUT_AXR7_LOW	         	0x00000000u
  #define  MCASP_PDOUT_AXR7_HIGH		0x00000001u
#endif /* _MCASP_CHANNEL_CNT == 8 */

#if (_MCASP_CHANNEL_CNT == 16)
  #define _MCASP_PDOUT_AXR8_MASK        	0x00000100u
  #define _MCASP_PDOUT_AXR8_SHIFT       	0x00000008u
  #define  MCASP_PDOUT_AXR8_DEFAULT		0x00000000u
  #define  MCASP_PDOUT_AXR8_OF(x)		_VALUEOF(x)
  #define  MCASP_PDOUT_AXR8_LOW	         	0x00000000u
  #define  MCASP_PDOUT_AXR8_HIGH		0x00000001u

  #define _MCASP_PDOUT_AXR9_MASK        	0x00000200u
  #define _MCASP_PDOUT_AXR9_SHIFT       	0x00000009u
  #define  MCASP_PDOUT_AXR9_DEFAULT		0x00000000u
  #define  MCASP_PDOUT_AXR9_OF(x)		_VALUEOF(x)
  #define  MCASP_PDOUT_AXR9_LOW	         	0x00000000u
  #define  MCASP_PDOUT_AXR9_HIGH		0x00000001u

  #define _MCASP_PDOUT_AXR10_MASK        	0x00000400u
  #define _MCASP_PDOUT_AXR10_SHIFT       	0x0000000Au
  #define  MCASP_PDOUT_AXR10_DEFAULT		0x00000000u
  #define  MCASP_PDOUT_AXR10_OF(x)		_VALUEOF(x)
  #define  MCASP_PDOUT_AXR10_LOW		0x00000000u
  #define  MCASP_PDOUT_AXR10_HIGH		0x00000001u

  #define _MCASP_PDOUT_AXR11_MASK        	0x00000800u
  #define _MCASP_PDOUT_AXR11_SHIFT       	0x0000000Bu
  #define  MCASP_PDOUT_AXR11_DEFAULT		0x00000000u
  #define  MCASP_PDOUT_AXR11_OF(x)		_VALUEOF(x)
  #define  MCASP_PDOUT_AXR11_LOW		0x00000000u
  #define  MCASP_PDOUT_AXR11_HIGH		0x00000001u

  #define _MCASP_PDOUT_AXR12_MASK        	0x00001000u
  #define _MCASP_PDOUT_AXR12_SHIFT       	0x0000000Cu
  #define  MCASP_PDOUT_AXR12_DEFAULT		0x00000000u
  #define  MCASP_PDOUT_AXR12_OF(x)		_VALUEOF(x)
  #define  MCASP_PDOUT_AXR12_LOW		0x00000000u
  #define  MCASP_PDOUT_AXR12_HIGH		0x00000001u

  #define _MCASP_PDOUT_AXR13_MASK        	0x00002000u
  #define _MCASP_PDOUT_AXR13_SHIFT       	0x0000000Du
  #define  MCASP_PDOUT_AXR13_DEFAULT		0x00000000u
  #define  MCASP_PDOUT_AXR13_OF(x)		_VALUEOF(x)
  #define  MCASP_PDOUT_AXR13_LOW		0x00000000u
  #define  MCASP_PDOUT_AXR13_HIGH		0x00000001u

  #define _MCASP_PDOUT_AXR14_MASK        	0x00004000u
  #define _MCASP_PDOUT_AXR14_SHIFT       	0x0000000Eu
  #define  MCASP_PDOUT_AXR14_DEFAULT		0x00000000u
  #define  MCASP_PDOUT_AXR14_OF(x)		_VALUEOF(x)
  #define  MCASP_PDOUT_AXR14_LOW		0x00000000u
  #define  MCASP_PDOUT_AXR14_HIGH		0x00000001u

  #define _MCASP_PDOUT_AXR15_MASK        	0x00008000u
  #define _MCASP_PDOUT_AXR15_SHIFT       	0x0000000Fu
  #define  MCASP_PDOUT_AXR15_DEFAULT		0x00000000u
  #define  MCASP_PDOUT_AXR15_OF(x)		_VALUEOF(x)
  #define  MCASP_PDOUT_AXR15_LOW		0x00000000u
  #define  MCASP_PDOUT_AXR15_HIGH		0x00000001u
#endif /* _MCASP_CHANNEL_CNT == 16 */

  #define _MCASP_PDOUT_AMUTE_MASK        	0x02000000u
  #define _MCASP_PDOUT_AMUTE_SHIFT       	0x00000019u
  #define  MCASP_PDOUT_AMUTE_DEFAULT		0x00000000u
  #define  MCASP_PDOUT_AMUTE_OF(x)		_VALUEOF(x)
  #define  MCASP_PDOUT_AMUTE_LOW		0x00000000u
  #define  MCASP_PDOUT_AMUTE_HIGH		0x00000001u

  #define _MCASP_PDOUT_ACLKX_MASK        	0x04000000u
  #define _MCASP_PDOUT_ACLKX_SHIFT       	0x0000001Au
  #define  MCASP_PDOUT_ACLKX_DEFAULT		0x00000000u
  #define  MCASP_PDOUT_ACLKX_OF(x)		_VALUEOF(x)
  #define  MCASP_PDOUT_ACLKX_LOW		0x00000000u
  #define  MCASP_PDOUT_ACLKX_HIGH		0x00000001u

  #define _MCASP_PDOUT_AHCLKX_MASK              0x08000000u
  #define _MCASP_PDOUT_AHCLKX_SHIFT             0x0000001Bu
  #define  MCASP_PDOUT_AHCLKX_DEFAULT		0x00000000u
  #define  MCASP_PDOUT_AHCLKX_OF(x)		_VALUEOF(x)
  #define  MCASP_PDOUT_AHCLKX_LOW		0x00000000u
  #define  MCASP_PDOUT_AHCLKX_HIGH		0x00000001u

  #define _MCASP_PDOUT_AFSX_MASK        	0x10000000u
  #define _MCASP_PDOUT_AFSX_SHIFT       	0x0000001Cu
  #define  MCASP_PDOUT_AFSX_DEFAULT		0x00000000u
  #define  MCASP_PDOUT_AFSX_OF(x)		_VALUEOF(x)
  #define  MCASP_PDOUT_AFSX_LOW	         	0x00000000u
  #define  MCASP_PDOUT_AFSX_HIGH		0x00000001u

  #define _MCASP_PDOUT_ACLKR_MASK        	0x20000000u
  #define _MCASP_PDOUT_ACLKR_SHIFT       	0x0000001Du
  #define  MCASP_PDOUT_ACLKR_DEFAULT		0x00000000u
  #define  MCASP_PDOUT_ACLKR_OF(x)		_VALUEOF(x)
  #define  MCASP_PDOUT_ACLKR_LOW		0x00000000u
  #define  MCASP_PDOUT_ACLKR_HIGH		0x00000001u

  #define _MCASP_PDOUT_AHCLKR_MASK              0x40000000u
  #define _MCASP_PDOUT_AHCLKR_SHIFT             0x0000001Eu
  #define  MCASP_PDOUT_AHCLKR_DEFAULT		0x00000000u
  #define  MCASP_PDOUT_AHCLKR_OF(x)		_VALUEOF(x)
  #define  MCASP_PDOUT_AHCLKR_LOW		0x00000000u
  #define  MCASP_PDOUT_AHCLKR_HIGH		0x00000001u

  #define _MCASP_PDOUT_AFSR_MASK        	0x80000000u
  #define _MCASP_PDOUT_AFSR_SHIFT       	0x0000001Fu
  #define  MCASP_PDOUT_AFSR_DEFAULT		0x00000000u
  #define  MCASP_PDOUT_AFSR_OF(x)		_VALUEOF(x)
  #define  MCASP_PDOUT_AFSR_LOW	         	0x00000000u
  #define  MCASP_PDOUT_AFSR_HIGH		0x00000001u

  #define  MCASP_PDOUT_OF(x)                    _VALUEOF(x)

#if (_MCASP_CHANNEL_CNT == 16)
  #define MCASP_PDOUT_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,PDOUT,AXR0)\
    |_PER_FDEFAULT(MCASP,PDOUT,AXR1)\
    |_PER_FDEFAULT(MCASP,PDOUT,AXR2)\
    |_PER_FDEFAULT(MCASP,PDOUT,AXR3)\
    |_PER_FDEFAULT(MCASP,PDOUT,AXR4)\
    |_PER_FDEFAULT(MCASP,PDOUT,AXR5)\
    |_PER_FDEFAULT(MCASP,PDOUT,AXR6)\
    |_PER_FDEFAULT(MCASP,PDOUT,AXR7)\
    |_PER_FDEFAULT(MCASP,PDOUT,AXR8)\
    |_PER_FDEFAULT(MCASP,PDOUT,AXR9)\
    |_PER_FDEFAULT(MCASP,PDOUT,AXR10)\
    |_PER_FDEFAULT(MCASP,PDOUT,AXR11)\
    |_PER_FDEFAULT(MCASP,PDOUT,AXR12)\
    |_PER_FDEFAULT(MCASP,PDOUT,AXR13)\
    |_PER_FDEFAULT(MCASP,PDOUT,AXR14)\
    |_PER_FDEFAULT(MCASP,PDOUT,AXR15)\
    |_PER_FDEFAULT(MCASP,PDOUT,AMUTE)\
    |_PER_FDEFAULT(MCASP,PDOUT,ACLKX)\
    |_PER_FDEFAULT(MCASP,PDOUT,AHCLKX)\
    |_PER_FDEFAULT(MCASP,PDOUT,AFSX)\
    |_PER_FDEFAULT(MCASP,PDOUT,ACLKR)\
    |_PER_FDEFAULT(MCASP,PDOUT,AHCLKR)\
    |_PER_FDEFAULT(MCASP,PDOUT,AFSR)\
  )

  #define MCASP_PDOUT_RMK(afsr,ahclkr,aclkr,afsx,ahclkx,aclkx,amute,  \
    axr15,axr14,axr13,axr12,axr11,axr10,\
    axr9, axr8,axr7,axr6,axr5,axr4,axr3,axr2,axr1, axr0) \
  (Uint32)( \
     _PER_FMK(MCASP,PDOUT,AXR0,axr0)\
    |_PER_FMK(MCASP,PDOUT,AXR1,axr1)\
    |_PER_FMK(MCASP,PDOUT,AXR2,axr2)\
    |_PER_FMK(MCASP,PDOUT,AXR3,axr3)\
    |_PER_FMK(MCASP,PDOUT,AXR4,axr4)\
    |_PER_FMK(MCASP,PDOUT,AXR5,axr5)\
    |_PER_FMK(MCASP,PDOUT,AXR6,axr6)\
    |_PER_FMK(MCASP,PDOUT,AXR7,axr7)\
    |_PER_FMK(MCASP,PDOUT,AXR8,axr8)\
    |_PER_FMK(MCASP,PDOUT,AXR9,axr9)\
    |_PER_FMK(MCASP,PDOUT,AXR10,axr10)\
    |_PER_FMK(MCASP,PDOUT,AXR11,axr11)\
    |_PER_FMK(MCASP,PDOUT,AXR12,axr12)\
    |_PER_FMK(MCASP,PDOUT,AXR13,axr13)\
    |_PER_FMK(MCASP,PDOUT,AXR14,axr14)\
    |_PER_FMK(MCASP,PDOUT,AXR15,axr15)\
    |_PER_FMK(MCASP,PDOUT,AMUTE,amute)\
    |_PER_FMK(MCASP,PDOUT,ACLKX,aclkx)\
    |_PER_FMK(MCASP,PDOUT,AHCLKX,ahclkx)\
    |_PER_FMK(MCASP,PDOUT,AFSX,afsx)\
    |_PER_FMK(MCASP,PDOUT,ACLKR,aclkr)\
    |_PER_FMK(MCASP,PDOUT,AHCLKR,ahclkr)\
    |_PER_FMK(MCASP,PDOUT,AFSR,afsr)\
  )
#endif  /* _MCASP_CHANNEL_CNT == 16 */

#if (_MCASP_CHANNEL_CNT == 8)
  #define MCASP_PDOUT_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,PDOUT,AXR0)\
    |_PER_FDEFAULT(MCASP,PDOUT,AXR1)\
    |_PER_FDEFAULT(MCASP,PDOUT,AXR2)\
    |_PER_FDEFAULT(MCASP,PDOUT,AXR3)\
    |_PER_FDEFAULT(MCASP,PDOUT,AXR4)\
    |_PER_FDEFAULT(MCASP,PDOUT,AXR5)\
    |_PER_FDEFAULT(MCASP,PDOUT,AXR6)\
    |_PER_FDEFAULT(MCASP,PDOUT,AXR7)\
    |_PER_FDEFAULT(MCASP,PDOUT,AMUTE)\
    |_PER_FDEFAULT(MCASP,PDOUT,ACLKX)\
    |_PER_FDEFAULT(MCASP,PDOUT,AHCLKX)\
    |_PER_FDEFAULT(MCASP,PDOUT,AFSX)\
    |_PER_FDEFAULT(MCASP,PDOUT,ACLKR)\
    |_PER_FDEFAULT(MCASP,PDOUT,AHCLKR)\
    |_PER_FDEFAULT(MCASP,PDOUT,AFSR)\
  )

  #define MCASP_PDOUT_RMK(afsr,ahclkr,aclkr,afsx,ahclkx,aclkx,amute,  \
                          axr7,axr6,axr5,axr4,axr3,axr2,axr1, axr0) \
  (Uint32)( \
     _PER_FMK(MCASP,PDOUT,AXR0,axr0)\
    |_PER_FMK(MCASP,PDOUT,AXR1,axr1)\
    |_PER_FMK(MCASP,PDOUT,AXR2,axr2)\
    |_PER_FMK(MCASP,PDOUT,AXR3,axr3)\
    |_PER_FMK(MCASP,PDOUT,AXR4,axr4)\
    |_PER_FMK(MCASP,PDOUT,AXR5,axr5)\
    |_PER_FMK(MCASP,PDOUT,AXR6,axr6)\
    |_PER_FMK(MCASP,PDOUT,AXR7,axr7)\
    |_PER_FMK(MCASP,PDOUT,AMUTE,amute)\
    |_PER_FMK(MCASP,PDOUT,ACLKX,aclkx)\
    |_PER_FMK(MCASP,PDOUT,AHCLKX,ahclkx)\
    |_PER_FMK(MCASP,PDOUT,AFSX,afsx)\
    |_PER_FMK(MCASP,PDOUT,ACLKR,aclkr)\
    |_PER_FMK(MCASP,PDOUT,AHCLKR,ahclkr)\
    |_PER_FMK(MCASP,PDOUT,AFSR,afsr)\
  )
#endif /* _MCASP_CHANNEL_CNT == 8 */

#if (_MCASP_CHANNEL_CNT == 6)
  #define MCASP_PDOUT_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,PDOUT,AXR0)\
    |_PER_FDEFAULT(MCASP,PDOUT,AXR1)\
    |_PER_FDEFAULT(MCASP,PDOUT,AXR2)\
    |_PER_FDEFAULT(MCASP,PDOUT,AXR3)\
    |_PER_FDEFAULT(MCASP,PDOUT,AXR4)\
    |_PER_FDEFAULT(MCASP,PDOUT,AXR5)\
    |_PER_FDEFAULT(MCASP,PDOUT,AMUTE)\
    |_PER_FDEFAULT(MCASP,PDOUT,ACLKX)\
    |_PER_FDEFAULT(MCASP,PDOUT,AHCLKX)\
    |_PER_FDEFAULT(MCASP,PDOUT,AFSX)\
    |_PER_FDEFAULT(MCASP,PDOUT,ACLKR)\
    |_PER_FDEFAULT(MCASP,PDOUT,AHCLKR)\
    |_PER_FDEFAULT(MCASP,PDOUT,AFSR)\
  )

  #define MCASP_PDOUT_RMK(afsr,ahclkr,aclkr,afsx,ahclkx,aclkx,amute,  \
                          axr5,axr4,axr3,axr2,axr1, axr0) \
  (Uint32)( \
     _PER_FMK(MCASP,PDOUT,AXR0,axr0)\
    |_PER_FMK(MCASP,PDOUT,AXR1,axr1)\
    |_PER_FMK(MCASP,PDOUT,AXR2,axr2)\
    |_PER_FMK(MCASP,PDOUT,AXR3,axr3)\
    |_PER_FMK(MCASP,PDOUT,AXR4,axr4)\
    |_PER_FMK(MCASP,PDOUT,AXR5,axr5)\
    |_PER_FMK(MCASP,PDOUT,AMUTE,amute)\
    |_PER_FMK(MCASP,PDOUT,ACLKX,aclkx)\
    |_PER_FMK(MCASP,PDOUT,AHCLKX,ahclkx)\
    |_PER_FMK(MCASP,PDOUT,AFSX,afsx)\
    |_PER_FMK(MCASP,PDOUT,ACLKR,aclkr)\
    |_PER_FMK(MCASP,PDOUT,AHCLKR,ahclkr)\
    |_PER_FMK(MCASP,PDOUT,AFSR,afsr)\
  )
#endif /* _MCASP_CHANNEL_CNT == 6 */

#if (_MCASP_CHANNEL_CNT == 4)
  #define MCASP_PDOUT_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,PDOUT,AXR0)\
    |_PER_FDEFAULT(MCASP,PDOUT,AXR1)\
    |_PER_FDEFAULT(MCASP,PDOUT,AXR2)\
    |_PER_FDEFAULT(MCASP,PDOUT,AXR3)\
    |_PER_FDEFAULT(MCASP,PDOUT,AMUTE)\
    |_PER_FDEFAULT(MCASP,PDOUT,ACLKX)\
    |_PER_FDEFAULT(MCASP,PDOUT,AHCLKX)\
    |_PER_FDEFAULT(MCASP,PDOUT,AFSX)\
    |_PER_FDEFAULT(MCASP,PDOUT,ACLKR)\
    |_PER_FDEFAULT(MCASP,PDOUT,AHCLKR)\
    |_PER_FDEFAULT(MCASP,PDOUT,AFSR)\
  )

  #define MCASP_PDOUT_RMK(afsr,ahclkr,aclkr,afsx,ahclkx,aclkx,amute,  \
                          axr3,axr2,axr1, axr0) \
  (Uint32)( \
     _PER_FMK(MCASP,PDOUT,AXR0,axr0)\
    |_PER_FMK(MCASP,PDOUT,AXR1,axr1)\
    |_PER_FMK(MCASP,PDOUT,AXR2,axr2)\
    |_PER_FMK(MCASP,PDOUT,AXR3,axr3)\
    |_PER_FMK(MCASP,PDOUT,AMUTE,amute)\
    |_PER_FMK(MCASP,PDOUT,ACLKX,aclkx)\
    |_PER_FMK(MCASP,PDOUT,AHCLKX,ahclkx)\
    |_PER_FMK(MCASP,PDOUT,AFSX,afsx)\
    |_PER_FMK(MCASP,PDOUT,ACLKR,aclkr)\
    |_PER_FMK(MCASP,PDOUT,AHCLKR,ahclkr)\
    |_PER_FMK(MCASP,PDOUT,AFSR,afsr)\
  )
#endif /* _MCASP_CHANNEL_CNT == 4 */

  #define _MCASP_PDOUT_FGET(N,FIELD)\
    _PER_FGET(_MCASP_PDOUT##N##_ADDR,MCASP,PDOUT,##FIELD)

  #define _MCASP_PDOUT_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_PDOUT##N##_ADDR,MCASP,PDOUT,##FIELD,field)

  #define _MCASP_PDOUT_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_PDOUT##N##_ADDR,MCASP,PDOUT,##FIELD,##SYM)

  #define _MCASP_PDOUT0_FGET(FIELD) _MCASP_PDOUT_FGET(0,##FIELD)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PDOUT1_FGET(FIELD) _MCASP_PDOUT_FGET(1,##FIELD)
#endif
 
  #define _MCASP_PDOUT0_FSET(FIELD,f) _MCASP_PDOUT_FSET(0,##FIELD,f)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PDOUT1_FSET(FIELD,f) _MCASP_PDOUT_FSET(1,##FIELD,f)
#endif

  #define _MCASP_PDOUT0_FSETS(FIELD,SYM) _MCASP_PDOUT_FSETS(0,##FIELD,##SYM)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PDOUT1_FSETS(FIELD,SYM) _MCASP_PDOUT_FSETS(1,##FIELD,##SYM)
#endif


/******************************************************************************\
* 
* _____________________
* |                   |
* |     PDIN          |
* |___________________|
*
* PDIN		- Pin Data Input Register
*
* FIELDS (msb -> lsb)
* (rw)  AFSR
* (rw)  AHCLKR 
* (rw)  ACLKR 
* (rw)  AFSX
* (rw)  AHCLKX 
* (rw)  ACLKX
* (rw)  AMUTE
* (rw)  AXR0-15 
*
\******************************************************************************/

  #define _MCASP_PDIN_OFFSET            7

  #define _MCASP_PDIN0_ADDR		(_MCASP_BASE_PORT0+4*_MCASP_PDIN_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PDIN1_ADDR		(_MCASP_BASE_PORT1+4*_MCASP_PDIN_OFFSET)
#endif

  #define _MCASP_PDIN_AXR0_MASK        	0x00000001u
  #define _MCASP_PDIN_AXR0_SHIFT       	0x00000000u
  #define  MCASP_PDIN_AXR0_DEFAULT     	0x00000000u
  #define  MCASP_PDIN_AXR0_OF(x)   	_VALUEOF(x)
  #define  MCASP_PDIN_AXR0_SET          0x00000001u

  #define _MCASP_PDIN_AXR1_MASK        	0x00000002u
  #define _MCASP_PDIN_AXR1_SHIFT       	0x00000001u
  #define  MCASP_PDIN_AXR1_DEFAULT     	0x00000000u
  #define  MCASP_PDIN_AXR1_OF(x)   	_VALUEOF(x)
  #define  MCASP_PDIN_AXR1_SET         	0x00000001u

  #define _MCASP_PDIN_AXR2_MASK        	0x00000004u
  #define _MCASP_PDIN_AXR2_SHIFT       	0x00000002u
  #define  MCASP_PDIN_AXR2_DEFAULT     	0x00000000u
  #define  MCASP_PDIN_AXR2_OF(x)        _VALUEOF(x)
  #define  MCASP_PDIN_AXR2_SET         	0x00000001u

  #define _MCASP_PDIN_AXR3_MASK        	0x00000008u
  #define _MCASP_PDIN_AXR3_SHIFT       	0x00000003u
  #define  MCASP_PDIN_AXR3_DEFAULT     	0x00000000u
  #define  MCASP_PDIN_AXR3_OF(x)        _VALUEOF(x)
  #define  MCASP_PDIN_AXR3_SET         	0x00000001u
 /* Fields for _MCASP_CHANNEL_CNT == 4 end here*/

#if (_MCASP_CHANNEL_CNT > 4)
  #define _MCASP_PDIN_AXR4_MASK        	0x00000010u
  #define _MCASP_PDIN_AXR4_SHIFT       	0x00000004u
  #define  MCASP_PDIN_AXR4_DEFAULT     	0x00000000u
  #define  MCASP_PDIN_AXR4_OF(x)        _VALUEOF(x)
  #define  MCASP_PDIN_AXR4_SET         	0x00000001

  #define _MCASP_PDIN_AXR5_MASK        	0x00000020u
  #define _MCASP_PDIN_AXR5_SHIFT       	0x00000005u
  #define  MCASP_PDIN_AXR5_DEFAULT     	0x00000000u
  #define  MCASP_PDIN_AXR5_OF(x)        _VALUEOF(x)
  #define  MCASP_PDIN_AXR5_SET         	0x00000001u
#endif /* _MCASP_CHANNEL_CNT == 6 */

#if (_MCASP_CHANNEL_CNT > 6) /* For channel count 8 and 16 */
  #define _MCASP_PDIN_AXR6_MASK        	0x00000040u
  #define _MCASP_PDIN_AXR6_SHIFT       	0x00000006u
  #define  MCASP_PDIN_AXR6_DEFAULT     	0x00000000u
  #define  MCASP_PDIN_AXR6_OF(x)         _VALUEOF(x)
  #define  MCASP_PDIN_AXR6_SET         	0x00000001u

  #define _MCASP_PDIN_AXR7_MASK        	0x00000080u
  #define _MCASP_PDIN_AXR7_SHIFT       	0x00000007u
  #define  MCASP_PDIN_AXR7_DEFAULT     	0x00000000u
  #define  MCASP_PDIN_AXR7_OF(x)   	      _VALUEOF(x)
  #define  MCASP_PDIN_AXR7_SET        	0x00000001u
#endif /* _MCASP_CHANNEL_CNT == 8 */

#if (_MCASP_CHANNEL_CNT == 16)
  #define _MCASP_PDIN_AXR8_MASK        	0x00000100u
  #define _MCASP_PDIN_AXR8_SHIFT       	0x00000008u
  #define  MCASP_PDIN_AXR8_DEFAULT     	0x00000000u
  #define  MCASP_PDIN_AXR8_OF(x)   	      _VALUEOF(x)
  #define  MCASP_PDIN_AXR8_SET          	0x00000001u

  #define _MCASP_PDIN_AXR9_MASK        	0x00000200u
  #define _MCASP_PDIN_AXR9_SHIFT       	0x00000009u
  #define  MCASP_PDIN_AXR9_DEFAULT     	0x00000000u
  #define  MCASP_PDIN_AXR9_OF(x)   	      _VALUEOF(x)
  #define  MCASP_PDIN_AXR9_SET           	0x00000001u

  #define _MCASP_PDIN_AXR10_MASK        	0x00000400u
  #define _MCASP_PDIN_AXR10_SHIFT       	0x0000000Au
  #define  MCASP_PDIN_AXR10_DEFAULT     	0x00000000u
  #define  MCASP_PDIN_AXR10_OF(x)         _VALUEOF(x)
  #define  MCASP_PDIN_AXR10_SET         	0x00000001u

  #define _MCASP_PDIN_AXR11_MASK        	0x00000800u
  #define _MCASP_PDIN_AXR11_SHIFT       	0x0000000Bu
  #define  MCASP_PDIN_AXR11_DEFAULT     	0x00000000u
  #define  MCASP_PDIN_AXR11_OF(x)          _VALUEOF(x)
  #define  MCASP_PDIN_AXR11_SET        	0x00000001u

  #define _MCASP_PDIN_AXR12_MASK        	0x00001000u
  #define _MCASP_PDIN_AXR12_SHIFT       	0x0000000Cu
  #define  MCASP_PDIN_AXR12_DEFAULT     	0x00000000u
  #define  MCASP_PDIN_AXR12_OF(x)         _VALUEOF(x)
  #define  MCASP_PDIN_AXR12_SET       	0x00000001u

  #define _MCASP_PDIN_AXR13_MASK        	0x00002000u
  #define _MCASP_PDIN_AXR13_SHIFT       	0x0000000Du
  #define  MCASP_PDIN_AXR13_DEFAULT     	0x00000000u
  #define  MCASP_PDIN_AXR13_OF(x)         _VALUEOF(x)
  #define  MCASP_PDIN_AXR13_SET         	0x00000001u

  #define _MCASP_PDIN_AXR14_MASK        	0x00004000u
  #define _MCASP_PDIN_AXR14_SHIFT       	0x0000000Eu
  #define  MCASP_PDIN_AXR14_DEFAULT     	0x00000000u
  #define  MCASP_PDIN_AXR14_OF(x)          _VALUEOF(x)
  #define  MCASP_PDIN_AXR14_SET          	0x00000001u

  #define _MCASP_PDIN_AXR15_MASK        	0x00008000u
  #define _MCASP_PDIN_AXR15_SHIFT       	0x0000000Fu
  #define  MCASP_PDIN_AXR15_DEFAULT     	0x00000000u
  #define  MCASP_PDIN_AXR15_OF(x)         _VALUEOF(x)
  #define  MCASP_PDIN_AXR15_SET         	0x00000001u
#endif /* _MCASP_CHANNEL_CNT == 16 */

  #define _MCASP_PDIN_AMUTE_MASK        	0x02000000u
  #define _MCASP_PDIN_AMUTE_SHIFT       	0x00000019u
  #define  MCASP_PDIN_AMUTE_DEFAULT     	0x00000000u
  #define  MCASP_PDIN_AMUTE_OF(x)         _VALUEOF(x)
  #define  MCASP_PDIN_AMUTE_SET         	0x00000001u

  #define _MCASP_PDIN_ACLKX_MASK        	0x04000000u
  #define _MCASP_PDIN_ACLKX_SHIFT       	0x0000001Au
  #define  MCASP_PDIN_ACLKX_DEFAULT     	0x00000000u
  #define  MCASP_PDIN_ACLKX_OF(x)         _VALUEOF(x)
  #define  MCASP_PDIN_ACLKX_SET         	0x00000001u

  #define _MCASP_PDIN_AHCLKX_MASK        	0x08000000u
  #define _MCASP_PDIN_AHCLKX_SHIFT       	0x0000001Bu
  #define  MCASP_PDIN_AHCLKX_DEFAULT     	0x00000000u
  #define  MCASP_PDIN_AHCLKX_OF(x)       _VALUEOF(x)
  #define  MCASP_PDIN_AHCLKX_SET          0x00000001u

  #define _MCASP_PDIN_AFSX_MASK        	0x10000000u
  #define _MCASP_PDIN_AFSX_SHIFT       	0x0000001Cu
  #define  MCASP_PDIN_AFSX_DEFAULT     	0x00000000u
  #define  MCASP_PDIN_AFSX_OF(x)   	     _VALUEOF(x)
  #define  MCASP_PDIN_AFSX_SET          	0x00000001u

  #define _MCASP_PDIN_ACLKR_MASK        	0x20000000u
  #define _MCASP_PDIN_ACLKR_SHIFT       	0x0000001Du
  #define  MCASP_PDIN_ACLKR_DEFAULT     	0x00000000u
  #define  MCASP_PDIN_ACLKR_OF(x)         _VALUEOF(x)
  #define  MCASP_PDIN_ACLKR_SET          	0x00000001u

  #define _MCASP_PDIN_AHCLKR_MASK        	0x40000000u
  #define _MCASP_PDIN_AHCLKR_SHIFT       	0x0000001Eu
  #define  MCASP_PDIN_AHCLKR_DEFAULT     	0x00000000u
  #define  MCASP_PDIN_AHCLKR_OF(x)       _VALUEOF(x)
  #define  MCASP_PDIN_AHCLKR_SET        	0x00000001u

  #define _MCASP_PDIN_AFSR_MASK        	0x80000000u
  #define _MCASP_PDIN_AFSR_SHIFT       	0x0000001Fu
  #define  MCASP_PDIN_AFSR_DEFAULT     	0x00000000u
  #define  MCASP_PDIN_AFSR_OF(x)   	      _VALUEOF(x)
  #define  MCASP_PDIN_AFSR_SET          	0x00000001u

  #define  MCASP_PDIN_OF(x)              _VALUEOF(x)

#if (_MCASP_CHANNEL_CNT == 16)
  #define MCASP_PDIN_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,PDIN,AXR0)\
    |_PER_FDEFAULT(MCASP,PDIN,AXR1)\
    |_PER_FDEFAULT(MCASP,PDIN,AXR2)\
    |_PER_FDEFAULT(MCASP,PDIN,AXR3)\
    |_PER_FDEFAULT(MCASP,PDIN,AXR4)\
    |_PER_FDEFAULT(MCASP,PDIN,AXR5)\
    |_PER_FDEFAULT(MCASP,PDIN,AXR6)\
    |_PER_FDEFAULT(MCASP,PDIN,AXR7)\
    |_PER_FDEFAULT(MCASP,PDIN,AXR8)\
    |_PER_FDEFAULT(MCASP,PDIN,AXR9)\
    |_PER_FDEFAULT(MCASP,PDIN,AXR10)\
    |_PER_FDEFAULT(MCASP,PDIN,AXR11)\
    |_PER_FDEFAULT(MCASP,PDIN,AXR12)\
    |_PER_FDEFAULT(MCASP,PDIN,AXR13)\
    |_PER_FDEFAULT(MCASP,PDIN,AXR14)\
    |_PER_FDEFAULT(MCASP,PDIN,AXR15)\
    |_PER_FDEFAULT(MCASP,PDIN,AMUTE)\
    |_PER_FDEFAULT(MCASP,PDIN,ACLKX)\
    |_PER_FDEFAULT(MCASP,PDIN,AHCLKX)\
    |_PER_FDEFAULT(MCASP,PDIN,AFSX)\
    |_PER_FDEFAULT(MCASP,PDIN,ACLKR)\
    |_PER_FDEFAULT(MCASP,PDIN,AHCLKR)\
    |_PER_FDEFAULT(MCASP,PDIN,AFSR)\
  )

  #define MCASP_PDIN_RMK(afsr,ahclkr,aclkr,afsx,ahclkx,aclkx,amute,  \
    axr15,axr14,axr13,axr12,axr11,axr10,\
    axr9, axr8,axr7,axr6,axr5,axr4,axr3,axr2,axr1, axr0) \
   (Uint32)( \
     _PER_FMK(MCASP,PDIN,AXR0,axr0)\
    |_PER_FMK(MCASP,PDIN,AXR1,axr1)\
    |_PER_FMK(MCASP,PDIN,AXR2,axr2)\
    |_PER_FMK(MCASP,PDIN,AXR3,axr3)\
    |_PER_FMK(MCASP,PDIN,AXR4,axr4)\
    |_PER_FMK(MCASP,PDIN,AXR5,axr5)\
    |_PER_FMK(MCASP,PDIN,AXR6,axr6)\
    |_PER_FMK(MCASP,PDIN,AXR7,axr7)\
    |_PER_FMK(MCASP,PDIN,AXR8,axr8)\
    |_PER_FMK(MCASP,PDIN,AXR9,axr9)\
    |_PER_FMK(MCASP,PDIN,AXR10,axr10)\
    |_PER_FMK(MCASP,PDIN,AXR11,axr11)\
    |_PER_FMK(MCASP,PDIN,AXR12,axr12)\
    |_PER_FMK(MCASP,PDIN,AXR13,axr13)\
    |_PER_FMK(MCASP,PDIN,AXR14,axr14)\
    |_PER_FMK(MCASP,PDIN,AXR15,axr15)\
    |_PER_FMK(MCASP,PDIN,AMUTE,amute)\
    |_PER_FMK(MCASP,PDIN,ACLKX,aclkx)\
    |_PER_FMK(MCASP,PDIN,AHCLKX,ahclkx)\
    |_PER_FMK(MCASP,PDIN,AFSX,afsx)\
    |_PER_FMK(MCASP,PDIN,ACLKR,aclkr)\
    |_PER_FMK(MCASP,PDIN,AHCLKR,ahclkr)\
    |_PER_FMK(MCASP,PDIN,AFSR,afsr)\
  )
#endif  /* _MCASP_CHANNEL_CNT == 16 */

#if (_MCASP_CHANNEL_CNT == 8)
  #define MCASP_PDIN_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,PDIN,AXR0)\
    |_PER_FDEFAULT(MCASP,PDIN,AXR1)\
    |_PER_FDEFAULT(MCASP,PDIN,AXR2)\
    |_PER_FDEFAULT(MCASP,PDIN,AXR3)\
    |_PER_FDEFAULT(MCASP,PDIN,AXR4)\
    |_PER_FDEFAULT(MCASP,PDIN,AXR5)\
    |_PER_FDEFAULT(MCASP,PDIN,AXR6)\
    |_PER_FDEFAULT(MCASP,PDIN,AXR7)\
    |_PER_FDEFAULT(MCASP,PDIN,AMUTE)\
    |_PER_FDEFAULT(MCASP,PDIN,ACLKX)\
    |_PER_FDEFAULT(MCASP,PDIN,AHCLKX)\
    |_PER_FDEFAULT(MCASP,PDIN,AFSX)\
    |_PER_FDEFAULT(MCASP,PDIN,ACLKR)\
    |_PER_FDEFAULT(MCASP,PDIN,AHCLKR)\
    |_PER_FDEFAULT(MCASP,PDIN,AFSR)\
  )

  #define MCASP_PDIN_RMK(afsr,ahclkr,aclkr,afsx,ahclkx,aclkx,amute,  \
                         axr7,axr6,axr5,axr4,axr3,axr2,axr1, axr0) \
   (Uint32)( \
     _PER_FMK(MCASP,PDIN,AXR0,axr0)\
    |_PER_FMK(MCASP,PDIN,AXR1,axr1)\
    |_PER_FMK(MCASP,PDIN,AXR2,axr2)\
    |_PER_FMK(MCASP,PDIN,AXR3,axr3)\
    |_PER_FMK(MCASP,PDIN,AXR4,axr4)\
    |_PER_FMK(MCASP,PDIN,AXR5,axr5)\
    |_PER_FMK(MCASP,PDIN,AXR6,axr6)\
    |_PER_FMK(MCASP,PDIN,AXR7,axr7)\
    |_PER_FMK(MCASP,PDIN,AMUTE,amute)\
    |_PER_FMK(MCASP,PDIN,ACLKX,aclkx)\
    |_PER_FMK(MCASP,PDIN,AHCLKX,ahclkx)\
    |_PER_FMK(MCASP,PDIN,AFSX,afsx)\
    |_PER_FMK(MCASP,PDIN,ACLKR,aclkr)\
    |_PER_FMK(MCASP,PDIN,AHCLKR,ahclkr)\
    |_PER_FMK(MCASP,PDIN,AFSR,afsr)\
  )
#endif /* _MCASP_CHANNEL_CNT == 8 */

#if (_MCASP_CHANNEL_CNT == 6)
  #define MCASP_PDIN_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,PDIN,AXR0)\
    |_PER_FDEFAULT(MCASP,PDIN,AXR1)\
    |_PER_FDEFAULT(MCASP,PDIN,AXR2)\
    |_PER_FDEFAULT(MCASP,PDIN,AXR3)\
    |_PER_FDEFAULT(MCASP,PDIN,AXR4)\
    |_PER_FDEFAULT(MCASP,PDIN,AXR5)\
    |_PER_FDEFAULT(MCASP,PDIN,AMUTE)\
    |_PER_FDEFAULT(MCASP,PDIN,ACLKX)\
    |_PER_FDEFAULT(MCASP,PDIN,AHCLKX)\
    |_PER_FDEFAULT(MCASP,PDIN,AFSX)\
    |_PER_FDEFAULT(MCASP,PDIN,ACLKR)\
    |_PER_FDEFAULT(MCASP,PDIN,AHCLKR)\
    |_PER_FDEFAULT(MCASP,PDIN,AFSR)\
  )

  #define MCASP_PDIN_RMK(afsr,ahclkr,aclkr,afsx,ahclkx,aclkx,amute,  \
                         axr5,axr4,axr3,axr2,axr1, axr0) \
   (Uint32)( \
     _PER_FMK(MCASP,PDIN,AXR0,axr0)\
    |_PER_FMK(MCASP,PDIN,AXR1,axr1)\
    |_PER_FMK(MCASP,PDIN,AXR2,axr2)\
    |_PER_FMK(MCASP,PDIN,AXR3,axr3)\
    |_PER_FMK(MCASP,PDIN,AXR4,axr4)\
    |_PER_FMK(MCASP,PDIN,AXR5,axr5)\
    |_PER_FMK(MCASP,PDIN,AMUTE,amute)\
    |_PER_FMK(MCASP,PDIN,ACLKX,aclkx)\
    |_PER_FMK(MCASP,PDIN,AHCLKX,ahclkx)\
    |_PER_FMK(MCASP,PDIN,AFSX,afsx)\
    |_PER_FMK(MCASP,PDIN,ACLKR,aclkr)\
    |_PER_FMK(MCASP,PDIN,AHCLKR,ahclkr)\
    |_PER_FMK(MCASP,PDIN,AFSR,afsr)\
  )
#endif /* _MCASP_CHANNEL_CNT == 6 */

#if (_MCASP_CHANNEL_CNT == 4)
  #define MCASP_PDIN_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,PDIN,AXR0)\
    |_PER_FDEFAULT(MCASP,PDIN,AXR1)\
    |_PER_FDEFAULT(MCASP,PDIN,AXR2)\
    |_PER_FDEFAULT(MCASP,PDIN,AXR3)\
    |_PER_FDEFAULT(MCASP,PDIN,AMUTE)\
    |_PER_FDEFAULT(MCASP,PDIN,ACLKX)\
    |_PER_FDEFAULT(MCASP,PDIN,AHCLKX)\
    |_PER_FDEFAULT(MCASP,PDIN,AFSX)\
    |_PER_FDEFAULT(MCASP,PDIN,ACLKR)\
    |_PER_FDEFAULT(MCASP,PDIN,AHCLKR)\
    |_PER_FDEFAULT(MCASP,PDIN,AFSR)\
  )

  #define MCASP_PDIN_RMK(afsr,ahclkr,aclkr,afsx,ahclkx,aclkx,amute,  \
                         axr3,axr2,axr1, axr0) \
   (Uint32)( \
     _PER_FMK(MCASP,PDIN,AXR0,axr0)\
    |_PER_FMK(MCASP,PDIN,AXR1,axr1)\
    |_PER_FMK(MCASP,PDIN,AXR2,axr2)\
    |_PER_FMK(MCASP,PDIN,AXR3,axr3)\
    |_PER_FMK(MCASP,PDIN,AMUTE,amute)\
    |_PER_FMK(MCASP,PDIN,ACLKX,aclkx)\
    |_PER_FMK(MCASP,PDIN,AHCLKX,ahclkx)\
    |_PER_FMK(MCASP,PDIN,AFSX,afsx)\
    |_PER_FMK(MCASP,PDIN,ACLKR,aclkr)\
    |_PER_FMK(MCASP,PDIN,AHCLKR,ahclkr)\
    |_PER_FMK(MCASP,PDIN,AFSR,afsr)\
  )
#endif /* _MCASP_CHANNEL_CNT == 4 */

  #define _MCASP_PDIN_FGET(N,FIELD)\
    _PER_FGET(_MCASP_PDIN##N##_ADDR,MCASP,PDIN,##FIELD)

  #define _MCASP_PDIN_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_PDIN##N##_ADDR,MCASP,PDIN,##FIELD,field)

  #define _MCASP_PDIN_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_PDIN##N##_ADDR,MCASP,PDIN,##FIELD,##SYM)

  #define _MCASP_PDIN0_FGET(FIELD) _MCASP_PDIN_FGET(0,##FIELD)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PDIN1_FGET(FIELD) _MCASP_PDIN_FGET(1,##FIELD)
#endif

  #define _MCASP_PDIN0_FSET(FIELD,f) _MCASP_PDIN_FSET(0,##FIELD,f)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PDIN1_FSET(FIELD,f) _MCASP_PDIN_FSET(1,##FIELD,f)
#endif

  #define _MCASP_PDIN0_FSETS(FIELD,SYM) _MCASP_PDIN_FSETS(0,##FIELD,##SYM)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PDIN1_FSETS(FIELD,SYM) _MCASP_PDIN_FSETS(1,##FIELD,##SYM)
#endif


/******************************************************************************\
* 
* _____________________
* |                   |
* |     PDSET         |
* |___________________|
*
* PDSET		- Pin Data Input Register
*
* FIELDS (msb -> lsb)
* (rw)  AFSR
* (rw)  AHCLKR 
* (rw)  ACLKR 
* (rw)  AFSX
* (rw)  AHCLKX 
* (rw)  ACLKX
* (rw)  AMUTE
* (rw)  AXR0-15 
*
\******************************************************************************/

  #define _MCASP_PDSET_OFFSET                   7

  #define _MCASP_PDSET0_ADDR			(_MCASP_BASE_PORT0+4*_MCASP_PDSET_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PDSET1_ADDR			(_MCASP_BASE_PORT1+4*_MCASP_PDSET_OFFSET)
#endif


  #define _MCASP_PDSET_AXR0_MASK        	0x00000001u
  #define _MCASP_PDSET_AXR0_SHIFT       	0x00000000u
  #define  MCASP_PDSET_AXR0_DEFAULT		0x00000000u
  #define  MCASP_PDSET_AXR0_OF(x)		_VALUEOF(x)
  #define  MCASP_PDSET_AXR0_SET		0x00000001u

  #define _MCASP_PDSET_AXR1_MASK        	0x00000002u
  #define _MCASP_PDSET_AXR1_SHIFT       	0x00000001u
  #define  MCASP_PDSET_AXR1_DEFAULT		0x00000000u
  #define  MCASP_PDSET_AXR1_OF(x)		_VALUEOF(x)
  #define  MCASP_PDSET_AXR1_SET		0x00000001u

  #define _MCASP_PDSET_AXR2_MASK        	0x00000004u
  #define _MCASP_PDSET_AXR2_SHIFT       	0x00000002u
  #define  MCASP_PDSET_AXR2_DEFAULT		0x00000000u
  #define  MCASP_PDSET_AXR2_OF(x)		_VALUEOF(x)
  #define  MCASP_PDSET_AXR2_SET		0x00000001u

  #define _MCASP_PDSET_AXR3_MASK        	0x00000008u
  #define _MCASP_PDSET_AXR3_SHIFT       	0x00000003u
  #define  MCASP_PDSET_AXR3_DEFAULT		0x00000000u
  #define  MCASP_PDSET_AXR3_OF(x)		_VALUEOF(x)
  #define  MCASP_PDSET_AXR3_SET		0x00000001u
 /* Fields for _MCASP_CHANNEL_CNT == 4 end here*/

#if (_MCASP_CHANNEL_CNT > 4)
  #define _MCASP_PDSET_AXR4_MASK        	0x00000010u
  #define _MCASP_PDSET_AXR4_SHIFT       	0x00000004u
  #define  MCASP_PDSET_AXR4_DEFAULT		0x00000000u
  #define  MCASP_PDSET_AXR4_OF(x)		_VALUEOF(x)
  #define  MCASP_PDSET_AXR4_SET		0x00000001u

  #define _MCASP_PDSET_AXR5_MASK        	0x00000020u
  #define _MCASP_PDSET_AXR5_SHIFT       	0x00000005u
  #define  MCASP_PDSET_AXR5_DEFAULT		0x00000000u
  #define  MCASP_PDSET_AXR5_OF(x)		_VALUEOF(x)
  #define  MCASP_PDSET_AXR5_SET		0x00000001u
#endif /* _MCASP_CHANNEL_CNT == 6 */

#if (_MCASP_CHANNEL_CNT > 6) /* For channel count 8 and 16 */
  #define _MCASP_PDSET_AXR6_MASK                0x00000040u
  #define _MCASP_PDSET_AXR6_SHIFT               0x00000006u
  #define  MCASP_PDSET_AXR6_DEFAULT        	0x00000000u
  #define  MCASP_PDSET_AXR6_OF(x)        	_VALUEOF(x)
  #define  MCASP_PDSET_AXR6_SET        		0x00000001u

  #define _MCASP_PDSET_AXR7_MASK                0x00000080u
  #define _MCASP_PDSET_AXR7_SHIFT               0x00000007u
  #define  MCASP_PDSET_AXR7_DEFAULT        	0x00000000u
  #define  MCASP_PDSET_AXR7_OF(x)        	_VALUEOF(x)
  #define  MCASP_PDSET_AXR7_SET        		0x00000001u
#endif /* _MCASP_CHANNEL_CNT == 8 */

#if (_MCASP_CHANNEL_CNT == 16)
  #define _MCASP_PDSET_AXR8_MASK                0x00000100u
  #define _MCASP_PDSET_AXR8_SHIFT               0x00000008u
  #define  MCASP_PDSET_AXR8_DEFAULT        	0x00000000u
  #define  MCASP_PDSET_AXR8_OF(x)        	_VALUEOF(x)
  #define  MCASP_PDSET_AXR8_SET        		0x00000001u

  #define _MCASP_PDSET_AXR9_MASK                0x00000200u
  #define _MCASP_PDSET_AXR9_SHIFT               0x00000009u
  #define  MCASP_PDSET_AXR9_DEFAULT        	0x00000000u
  #define  MCASP_PDSET_AXR9_OF(x)        	_VALUEOF(x)
  #define  MCASP_PDSET_AXR9_SET        		0x00000001u

  #define _MCASP_PDSET_AXR10_MASK                0x00000400u
  #define _MCASP_PDSET_AXR10_SHIFT               0x0000000Au
  #define  MCASP_PDSET_AXR10_DEFAULT        	0x00000000u
  #define  MCASP_PDSET_AXR10_OF(x)        	_VALUEOF(x)
  #define  MCASP_PDSET_AXR10_SET        	0x00000001u

  #define _MCASP_PDSET_AXR11_MASK                0x00000800u
  #define _MCASP_PDSET_AXR11_SHIFT               0x0000000Bu
  #define  MCASP_PDSET_AXR11_DEFAULT        	0x00000000u
  #define  MCASP_PDSET_AXR11_OF(x)        	_VALUEOF(x)
  #define  MCASP_PDSET_AXR11_SET        	0x00000001u

  #define _MCASP_PDSET_AXR12_MASK                0x00001000u
  #define _MCASP_PDSET_AXR12_SHIFT               0x0000000Cu
  #define  MCASP_PDSET_AXR12_DEFAULT        	0x00000000u
  #define  MCASP_PDSET_AXR12_OF(x)        	_VALUEOF(x)
  #define  MCASP_PDSET_AXR12_SET        	0x00000001u

  #define _MCASP_PDSET_AXR13_MASK                0x00002000u
  #define _MCASP_PDSET_AXR13_SHIFT               0x0000000Du
  #define  MCASP_PDSET_AXR13_DEFAULT        	0x00000000u
  #define  MCASP_PDSET_AXR13_OF(x)        	_VALUEOF(x)
  #define  MCASP_PDSET_AXR13_SET        	0x00000001u

  #define _MCASP_PDSET_AXR14_MASK                0x00004000u
  #define _MCASP_PDSET_AXR14_SHIFT               0x0000000Eu
  #define  MCASP_PDSET_AXR14_DEFAULT        	0x00000000u
  #define  MCASP_PDSET_AXR14_OF(x)        	_VALUEOF(x)
  #define  MCASP_PDSET_AXR14_SET        	0x00000001u

  #define _MCASP_PDSET_AXR15_MASK                0x00008000u
  #define _MCASP_PDSET_AXR15_SHIFT               0x0000000Fu
  #define  MCASP_PDSET_AXR15_DEFAULT        	0x00000000u
  #define  MCASP_PDSET_AXR15_OF(x)        	_VALUEOF(x)
  #define  MCASP_PDSET_AXR15_SET        	0x00000001u
#endif /* _MCASP_CHANNEL_CNT == 16 */

  #define _MCASP_PDSET_AMUTE_MASK                0x02000000u
  #define _MCASP_PDSET_AMUTE_SHIFT               0x00000019u
  #define  MCASP_PDSET_AMUTE_DEFAULT        	0x00000000u
  #define  MCASP_PDSET_AMUTE_OF(x)        	_VALUEOF(x)
  #define  MCASP_PDSET_AMUTE_SET        	0x00000001u

  #define _MCASP_PDSET_ACLKX_MASK                0x04000000u
  #define _MCASP_PDSET_ACLKX_SHIFT               0x0000001Au
  #define  MCASP_PDSET_ACLKX_DEFAULT        	0x00000000u
  #define  MCASP_PDSET_ACLKX_OF(x)        	_VALUEOF(x)
  #define  MCASP_PDSET_ACLKX_SET        	0x00000001u

  #define _MCASP_PDSET_AHCLKX_MASK              0x08000000u
  #define _MCASP_PDSET_AHCLKX_SHIFT             0x0000001Bu
  #define  MCASP_PDSET_AHCLKX_DEFAULT        	0x00000000u
  #define  MCASP_PDSET_AHCLKX_OF(x)        	_VALUEOF(x)
  #define  MCASP_PDSET_AHCLKX_SET        	0x00000001u

  #define _MCASP_PDSET_AFSX_MASK                0x10000000u
  #define _MCASP_PDSET_AFSX_SHIFT               0x0000001Cu
  #define  MCASP_PDSET_AFSX_DEFAULT        	0x00000000u
  #define  MCASP_PDSET_AFSX_OF(x)        	_VALUEOF(x)
  #define  MCASP_PDSET_AFSX_SET        		0x00000001u

  #define _MCASP_PDSET_ACLKR_MASK                0x20000000u
  #define _MCASP_PDSET_ACLKR_SHIFT               0x0000001Du
  #define  MCASP_PDSET_ACLKR_DEFAULT        	0x00000000u
  #define  MCASP_PDSET_ACLKR_OF(x)        	_VALUEOF(x)
  #define  MCASP_PDSET_ACLKR_SET        	0x00000001u

  #define _MCASP_PDSET_AHCLKR_MASK        0x40000000u
  #define _MCASP_PDSET_AHCLKR_SHIFT       0x0000001Eu
  #define  MCASP_PDSET_AHCLKR_DEFAULT        	0x00000000u
  #define  MCASP_PDSET_AHCLKR_OF(x)        	_VALUEOF(x)
  #define  MCASP_PDSET_AHCLKR_SET        	0x00000001u

  #define _MCASP_PDSET_AFSR_MASK                0x80000000u
  #define _MCASP_PDSET_AFSR_SHIFT               0x0000001Fu
  #define  MCASP_PDSET_AFSR_DEFAULT        	0x00000000u
  #define  MCASP_PDSET_AFSR_OF(x)        	_VALUEOF(x)
  #define  MCASP_PDSET_AFSR_SET        		0x00000001u



  #define  MCASP_PDSET_OF(x)        	_VALUEOF(x)

#if (_MCASP_CHANNEL_CNT == 16)
  #define MCASP_PDSET_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,PDSET,AXR0)\
    |_PER_FDEFAULT(MCASP,PDSET,AXR1)\
    |_PER_FDEFAULT(MCASP,PDSET,AXR2)\
    |_PER_FDEFAULT(MCASP,PDSET,AXR3)\
    |_PER_FDEFAULT(MCASP,PDSET,AXR4)\
    |_PER_FDEFAULT(MCASP,PDSET,AXR5)\
    |_PER_FDEFAULT(MCASP,PDSET,AXR6)\
    |_PER_FDEFAULT(MCASP,PDSET,AXR7)\
    |_PER_FDEFAULT(MCASP,PDSET,AXR8)\
    |_PER_FDEFAULT(MCASP,PDSET,AXR9)\
    |_PER_FDEFAULT(MCASP,PDSET,AXR10)\
    |_PER_FDEFAULT(MCASP,PDSET,AXR11)\
    |_PER_FDEFAULT(MCASP,PDSET,AXR12)\
    |_PER_FDEFAULT(MCASP,PDSET,AXR13)\
    |_PER_FDEFAULT(MCASP,PDSET,AXR14)\
    |_PER_FDEFAULT(MCASP,PDSET,AXR15)\
    |_PER_FDEFAULT(MCASP,PDSET,AMUTE)\
    |_PER_FDEFAULT(MCASP,PDSET,ACLKX)\
    |_PER_FDEFAULT(MCASP,PDSET,AHCLKX)\
    |_PER_FDEFAULT(MCASP,PDSET,AFSX)\
    |_PER_FDEFAULT(MCASP,PDSET,ACLKR)\
    |_PER_FDEFAULT(MCASP,PDSET,AHCLKR)\
    |_PER_FDEFAULT(MCASP,PDSET,AFSR)\
  )

  #define MCASP_PDSET_RMK(afsr,ahclkr,aclkr,afsx,ahclkx,aclkx,amute,  \
    axr15,axr14,axr13,axr12,axr11,axr10,\
    axr9, axr8,axr7,axr6,axr5,axr4,axr3,axr2,axr1, axr0) \
 (Uint32)( \
     _PER_FMK(MCASP,PDSET,AXR0,axr0)\
    |_PER_FMK(MCASP,PDSET,AXR1,axr1)\
    |_PER_FMK(MCASP,PDSET,AXR2,axr2)\
    |_PER_FMK(MCASP,PDSET,AXR3,axr3)\
    |_PER_FMK(MCASP,PDSET,AXR4,axr4)\
    |_PER_FMK(MCASP,PDSET,AXR5,axr5)\
    |_PER_FMK(MCASP,PDSET,AXR6,axr6)\
    |_PER_FMK(MCASP,PDSET,AXR7,axr7)\
    |_PER_FMK(MCASP,PDSET,AXR8,axr8)\
    |_PER_FMK(MCASP,PDSET,AXR9,axr9)\
    |_PER_FMK(MCASP,PDSET,AXR10,axr10)\
    |_PER_FMK(MCASP,PDSET,AXR11,axr11)\
    |_PER_FMK(MCASP,PDSET,AXR12,axr12)\
    |_PER_FMK(MCASP,PDSET,AXR13,axr13)\
    |_PER_FMK(MCASP,PDSET,AXR14,axr14)\
    |_PER_FMK(MCASP,PDSET,AXR15,axr15)\
    |_PER_FMK(MCASP,PDSET,AMUTE,amute)\
    |_PER_FMK(MCASP,PDSET,ACLKX,aclkx)\
    |_PER_FMK(MCASP,PDSET,AHCLKX,ahclkx)\
    |_PER_FMK(MCASP,PDSET,AFSX,afsx)\
    |_PER_FMK(MCASP,PDSET,ACLKR,aclkr)\
    |_PER_FMK(MCASP,PDSET,AHCLKR,ahclkr)\
    |_PER_FMK(MCASP,PDSET,AFSR,afsr)\
  )
#endif /* _MCASP_CHANNEL_CNT == 16 */

#if (_MCASP_CHANNEL_CNT == 8)
  #define MCASP_PDSET_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,PDSET,AXR0)\
    |_PER_FDEFAULT(MCASP,PDSET,AXR1)\
    |_PER_FDEFAULT(MCASP,PDSET,AXR2)\
    |_PER_FDEFAULT(MCASP,PDSET,AXR3)\
    |_PER_FDEFAULT(MCASP,PDSET,AXR4)\
    |_PER_FDEFAULT(MCASP,PDSET,AXR5)\
    |_PER_FDEFAULT(MCASP,PDSET,AXR6)\
    |_PER_FDEFAULT(MCASP,PDSET,AXR7)\
    |_PER_FDEFAULT(MCASP,PDSET,AMUTE)\
    |_PER_FDEFAULT(MCASP,PDSET,ACLKX)\
    |_PER_FDEFAULT(MCASP,PDSET,AHCLKX)\
    |_PER_FDEFAULT(MCASP,PDSET,AFSX)\
    |_PER_FDEFAULT(MCASP,PDSET,ACLKR)\
    |_PER_FDEFAULT(MCASP,PDSET,AHCLKR)\
    |_PER_FDEFAULT(MCASP,PDSET,AFSR)\
  )

  #define MCASP_PDSET_RMK(afsr,ahclkr,aclkr,afsx,ahclkx,aclkx,amute,  \
                          axr7,axr6,axr5,axr4,axr3,axr2,axr1, axr0) \
 (Uint32)( \
     _PER_FMK(MCASP,PDSET,AXR0,axr0)\
    |_PER_FMK(MCASP,PDSET,AXR1,axr1)\
    |_PER_FMK(MCASP,PDSET,AXR2,axr2)\
    |_PER_FMK(MCASP,PDSET,AXR3,axr3)\
    |_PER_FMK(MCASP,PDSET,AXR4,axr4)\
    |_PER_FMK(MCASP,PDSET,AXR5,axr5)\
    |_PER_FMK(MCASP,PDSET,AXR6,axr6)\
    |_PER_FMK(MCASP,PDSET,AXR7,axr7)\
    |_PER_FMK(MCASP,PDSET,AMUTE,amute)\
    |_PER_FMK(MCASP,PDSET,ACLKX,aclkx)\
    |_PER_FMK(MCASP,PDSET,AHCLKX,ahclkx)\
    |_PER_FMK(MCASP,PDSET,AFSX,afsx)\
    |_PER_FMK(MCASP,PDSET,ACLKR,aclkr)\
    |_PER_FMK(MCASP,PDSET,AHCLKR,ahclkr)\
    |_PER_FMK(MCASP,PDSET,AFSR,afsr)\
  )
#endif /* _MCASP_CHANNEL_CNT == 8 */

#if (_MCASP_CHANNEL_CNT == 6)
  #define MCASP_PDSET_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,PDSET,AXR0)\
    |_PER_FDEFAULT(MCASP,PDSET,AXR1)\
    |_PER_FDEFAULT(MCASP,PDSET,AXR2)\
    |_PER_FDEFAULT(MCASP,PDSET,AXR3)\
    |_PER_FDEFAULT(MCASP,PDSET,AXR4)\
    |_PER_FDEFAULT(MCASP,PDSET,AXR5)\
    |_PER_FDEFAULT(MCASP,PDSET,AMUTE)\
    |_PER_FDEFAULT(MCASP,PDSET,ACLKX)\
    |_PER_FDEFAULT(MCASP,PDSET,AHCLKX)\
    |_PER_FDEFAULT(MCASP,PDSET,AFSX)\
    |_PER_FDEFAULT(MCASP,PDSET,ACLKR)\
    |_PER_FDEFAULT(MCASP,PDSET,AHCLKR)\
    |_PER_FDEFAULT(MCASP,PDSET,AFSR)\
  )

  #define MCASP_PDSET_RMK(afsr,ahclkr,aclkr,afsx,ahclkx,aclkx,amute,  \
                          axr5,axr4,axr3,axr2,axr1, axr0) \
 (Uint32)( \
     _PER_FMK(MCASP,PDSET,AXR0,axr0)\
    |_PER_FMK(MCASP,PDSET,AXR1,axr1)\
    |_PER_FMK(MCASP,PDSET,AXR2,axr2)\
    |_PER_FMK(MCASP,PDSET,AXR3,axr3)\
    |_PER_FMK(MCASP,PDSET,AXR4,axr4)\
    |_PER_FMK(MCASP,PDSET,AXR5,axr5)\
    |_PER_FMK(MCASP,PDSET,AMUTE,amute)\
    |_PER_FMK(MCASP,PDSET,ACLKX,aclkx)\
    |_PER_FMK(MCASP,PDSET,AHCLKX,ahclkx)\
    |_PER_FMK(MCASP,PDSET,AFSX,afsx)\
    |_PER_FMK(MCASP,PDSET,ACLKR,aclkr)\
    |_PER_FMK(MCASP,PDSET,AHCLKR,ahclkr)\
    |_PER_FMK(MCASP,PDSET,AFSR,afsr)\
  )
#endif /* _MCASP_CHANNEL_CNT == 6 */

#if (_MCASP_CHANNEL_CNT == 4)
  #define MCASP_PDSET_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,PDSET,AXR0)\
    |_PER_FDEFAULT(MCASP,PDSET,AXR1)\
    |_PER_FDEFAULT(MCASP,PDSET,AXR2)\
    |_PER_FDEFAULT(MCASP,PDSET,AXR3)\
    |_PER_FDEFAULT(MCASP,PDSET,AMUTE)\
    |_PER_FDEFAULT(MCASP,PDSET,ACLKX)\
    |_PER_FDEFAULT(MCASP,PDSET,AHCLKX)\
    |_PER_FDEFAULT(MCASP,PDSET,AFSX)\
    |_PER_FDEFAULT(MCASP,PDSET,ACLKR)\
    |_PER_FDEFAULT(MCASP,PDSET,AHCLKR)\
    |_PER_FDEFAULT(MCASP,PDSET,AFSR)\
  )

  #define MCASP_PDSET_RMK(afsr,ahclkr,aclkr,afsx,ahclkx,aclkx,amute,  \
                          axr3,axr2,axr1, axr0) \
 (Uint32)( \
     _PER_FMK(MCASP,PDSET,AXR0,axr0)\
    |_PER_FMK(MCASP,PDSET,AXR1,axr1)\
    |_PER_FMK(MCASP,PDSET,AXR2,axr2)\
    |_PER_FMK(MCASP,PDSET,AXR3,axr3)\
    |_PER_FMK(MCASP,PDSET,AMUTE,amute)\
    |_PER_FMK(MCASP,PDSET,ACLKX,aclkx)\
    |_PER_FMK(MCASP,PDSET,AHCLKX,ahclkx)\
    |_PER_FMK(MCASP,PDSET,AFSX,afsx)\
    |_PER_FMK(MCASP,PDSET,ACLKR,aclkr)\
    |_PER_FMK(MCASP,PDSET,AHCLKR,ahclkr)\
    |_PER_FMK(MCASP,PDSET,AFSR,afsr)\
  )
#endif /* _MCASP_CHANNEL_CNT == 4 */

  #define _MCASP_PDSET_FGET(N,FIELD)\
    _PER_FGET(_MCASP_PDSET##N##_ADDR,MCASP,PDSET,##FIELD)

  #define _MCASP_PDSET_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_PDSET##N##_ADDR,MCASP,PDSET,##FIELD,field)

  #define _MCASP_PDSET_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_PDSET##N##_ADDR,MCASP,PDSET,##FIELD,##SYM)

  #define _MCASP_PDSET0_FGET(FIELD) _MCASP_PDSET_FGET(0,##FIELD)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PDSET1_FGET(FIELD) _MCASP_PDSET_FGET(1,##FIELD)
#endif
 
  #define _MCASP_PDSET0_FSET(FIELD,f) _MCASP_PDSET_FSET(0,##FIELD,f)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PDSET1_FSET(FIELD,f) _MCASP_PDSET_FSET(1,##FIELD,f)
#endif

  #define _MCASP_PDSET0_FSETS(FIELD,SYM) _MCASP_PDSET_FSETS(0,##FIELD,##SYM)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PDSET1_FSETS(FIELD,SYM) _MCASP_PDSET_FSETS(1,##FIELD,##SYM)
#endif


/******************************************************************************\
* 
* _____________________
* |                   |
* |     P D C L R     |
* |___________________|
*
* PDCLR		- Pin Data Clear Register
*
* FIELDS (msb -> lsb)
* (rw)  AFSR
* (rw)  AHCLKR 
* (rw)  ACLKR 
* (rw)  AFSX
* (rw)  AHCLKX 
* (rw)  ACLKX
* (rw)  AMUTE
* (rw)  AXR0-15 
*
\******************************************************************************/

  #define _MCASP_PDCLR_OFFSET		8

  #define _MCASP_PDCLR0_ADDR		(_MCASP_BASE_PORT0+4*_MCASP_PDCLR_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PDCLR1_ADDR		(_MCASP_BASE_PORT1+4*_MCASP_PDCLR_OFFSET)
#endif

  #define _MCASP_PDCLR_AXR0_MASK		0x00000001u
  #define _MCASP_PDCLR_AXR0_SHIFT		0x00000000u
  #define  MCASP_PDCLR_AXR0_DEFAULT		0x00000000u
  #define  MCASP_PDCLR_AXR0_OF(x)		_VALUEOF(x)
  #define  MCASP_PDCLR_AXR0_CLR	         	0x00000001u

  #define _MCASP_PDCLR_AXR1_MASK		0x00000002u
  #define _MCASP_PDCLR_AXR1_SHIFT		0x00000001u
  #define  MCASP_PDCLR_AXR1_DEFAULT		0x00000000u
  #define  MCASP_PDCLR_AXR1_OF(x)		_VALUEOF(x)
  #define  MCASP_PDCLR_AXR1_CLR	         	0x00000001u

  #define _MCASP_PDCLR_AXR2_MASK		0x00000004u
  #define _MCASP_PDCLR_AXR2_SHIFT		0x00000002u
  #define  MCASP_PDCLR_AXR2_DEFAULT		0x00000000u
  #define  MCASP_PDCLR_AXR2_OF(x)		_VALUEOF(x)
  #define  MCASP_PDCLR_AXR2_CLR	         	0x00000001u

  #define _MCASP_PDCLR_AXR3_MASK		0x00000008u
  #define _MCASP_PDCLR_AXR3_SHIFT		0x00000003u
  #define  MCASP_PDCLR_AXR3_DEFAULT		0x00000000u
  #define  MCASP_PDCLR_AXR3_OF(x)		_VALUEOF(x)
  #define  MCASP_PDCLR_AXR3_CLR	         	0x00000001u
 /* Fields for _MCASP_CHANNEL_CNT == 4 end here*/

#if (_MCASP_CHANNEL_CNT > 4)
  #define _MCASP_PDCLR_AXR4_MASK		0x00000010u
  #define _MCASP_PDCLR_AXR4_SHIFT		0x00000004u
  #define  MCASP_PDCLR_AXR4_DEFAULT		0x00000000u
  #define  MCASP_PDCLR_AXR4_OF(x)		_VALUEOF(x)
  #define  MCASP_PDCLR_AXR4_CLR	         	0x00000001u

  #define _MCASP_PDCLR_AXR5_MASK		0x00000020u
  #define _MCASP_PDCLR_AXR5_SHIFT		0x00000005u
  #define  MCASP_PDCLR_AXR5_DEFAULT		0x00000000u
  #define  MCASP_PDCLR_AXR5_OF(x)		_VALUEOF(x)
  #define  MCASP_PDCLR_AXR5_CLR	         	0x00000001u
#endif /* _MCASP_CHANNEL_CNT == 6 */

#if (_MCASP_CHANNEL_CNT > 6) /* For channel count 8 and 16 */
  #define _MCASP_PDCLR_AXR6_MASK		0x00000040u
  #define _MCASP_PDCLR_AXR6_SHIFT		0x00000006u
  #define  MCASP_PDCLR_AXR6_DEFAULT		0x00000000u
  #define  MCASP_PDCLR_AXR6_OF(x)		_VALUEOF(x)
  #define  MCASP_PDCLR_AXR6_CLR	         	0x00000001u

  #define _MCASP_PDCLR_AXR7_MASK		0x00000080u
  #define _MCASP_PDCLR_AXR7_SHIFT		0x00000007u
  #define  MCASP_PDCLR_AXR7_DEFAULT		0x00000000u
  #define  MCASP_PDCLR_AXR7_OF(x)		_VALUEOF(x)
  #define  MCASP_PDCLR_AXR7_CLR	         	0x00000001u
#endif /* _MCASP_CHANNEL_CNT == 8 */

#if (_MCASP_CHANNEL_CNT == 16)
  #define _MCASP_PDCLR_AXR8_MASK		0x00000100u
  #define _MCASP_PDCLR_AXR8_SHIFT		0x00000008u
  #define  MCASP_PDCLR_AXR8_DEFAULT		0x00000000u
  #define  MCASP_PDCLR_AXR8_OF(x)		_VALUEOF(x)
  #define  MCASP_PDCLR_AXR8_CLR	         	0x00000001u

  #define _MCASP_PDCLR_AXR9_MASK		0x00000200u
  #define _MCASP_PDCLR_AXR9_SHIFT		0x00000009u
  #define  MCASP_PDCLR_AXR9_DEFAULT		0x00000000u
  #define  MCASP_PDCLR_AXR9_OF(x)		_VALUEOF(x)
  #define  MCASP_PDCLR_AXR9_CLR	         	0x00000001u

  #define _MCASP_PDCLR_AXR10_MASK		0x00000400u
  #define _MCASP_PDCLR_AXR10_SHIFT		0x0000000Au
  #define  MCASP_PDCLR_AXR10_DEFAULT		0x00000000u
  #define  MCASP_PDCLR_AXR10_OF(x)		_VALUEOF(x)
  #define  MCASP_PDCLR_AXR10_CLR		0x00000001u

  #define _MCASP_PDCLR_AXR11_MASK		0x00000800u
  #define _MCASP_PDCLR_AXR11_SHIFT		0x0000000Bu
  #define  MCASP_PDCLR_AXR11_DEFAULT		0x00000000u
  #define  MCASP_PDCLR_AXR11_OF(x)		_VALUEOF(x)
  #define  MCASP_PDCLR_AXR11_CLR		0x00000001u

  #define _MCASP_PDCLR_AXR12_MASK		0x00001000u
  #define _MCASP_PDCLR_AXR12_SHIFT		0x0000000Cu
  #define  MCASP_PDCLR_AXR12_DEFAULT		0x00000000u
  #define  MCASP_PDCLR_AXR12_OF(x)		_VALUEOF(x)
  #define  MCASP_PDCLR_AXR12_CLR		0x00000001u

  #define _MCASP_PDCLR_AXR13_MASK		0x00002000u
  #define _MCASP_PDCLR_AXR13_SHIFT		0x0000000Du
  #define  MCASP_PDCLR_AXR13_DEFAULT		0x00000000u
  #define  MCASP_PDCLR_AXR13_OF(x)		_VALUEOF(x)
  #define  MCASP_PDCLR_AXR13_CLR		0x00000001u

  #define _MCASP_PDCLR_AXR14_MASK		0x00004000u
  #define _MCASP_PDCLR_AXR14_SHIFT		0x0000000Eu
  #define  MCASP_PDCLR_AXR14_DEFAULT		0x00000000u
  #define  MCASP_PDCLR_AXR14_OF(x)		_VALUEOF(x)
  #define  MCASP_PDCLR_AXR14_CLR		0x00000001u

  #define _MCASP_PDCLR_AXR15_MASK		0x00008000u
  #define _MCASP_PDCLR_AXR15_SHIFT		0x0000000Fu
  #define  MCASP_PDCLR_AXR15_DEFAULT		0x00000000u
  #define  MCASP_PDCLR_AXR15_OF(x)		_VALUEOF(x)
  #define  MCASP_PDCLR_AXR15_CLR		0x00000001u
#endif /* _MCASP_CHANNEL_CNT == 16 */

  #define _MCASP_PDCLR_AMUTE_MASK		0x02000000u
  #define _MCASP_PDCLR_AMUTE_SHIFT		0x00000019u
  #define  MCASP_PDCLR_AMUTE_DEFAULT		0x00000000u
  #define  MCASP_PDCLR_AMUTE_OF(x)		_VALUEOF(x)
  #define  MCASP_PDCLR_AMUTE_CLR		0x00000001u

  #define _MCASP_PDCLR_ACLKX_MASK		0x04000000u
  #define _MCASP_PDCLR_ACLKX_SHIFT		0x0000001Au
  #define  MCASP_PDCLR_ACLKX_DEFAULT		0x00000000u
  #define  MCASP_PDCLR_ACLKX_OF(x)		_VALUEOF(x)
  #define  MCASP_PDCLR_ACLKX_CLR		0x00000001u

  #define _MCASP_PDCLR_AHCLKX_MASK		0x08000000u
  #define _MCASP_PDCLR_AHCLKX_SHIFT		0x0000001Bu
  #define  MCASP_PDCLR_AHCLKX_DEFAULT		0x00000000u
  #define  MCASP_PDCLR_AHCLKX_OF(x)		_VALUEOF(x)
  #define  MCASP_PDCLR_AHCLKX_CLR		0x00000001u

  #define _MCASP_PDCLR_AFSX_MASK		0x10000000u
  #define _MCASP_PDCLR_AFSX_SHIFT		0x0000001Cu
  #define  MCASP_PDCLR_AFSX_DEFAULT		0x00000000u
  #define  MCASP_PDCLR_AFSX_OF(x)		_VALUEOF(x)
  #define  MCASP_PDCLR_AFSX_CLR	         	0x00000001u

  #define _MCASP_PDCLR_ACLKR_MASK		0x20000000u
  #define _MCASP_PDCLR_ACLKR_SHIFT		0x0000001Du
  #define  MCASP_PDCLR_ACLKR_DEFAULT		0x00000000u
  #define  MCASP_PDCLR_ACLKR_OF(x)		_VALUEOF(x)
  #define  MCASP_PDCLR_ACLKR_CLR		0x00000001u


  #define _MCASP_PDCLR_AHCLKR_MASK		0x40000000u
  #define _MCASP_PDCLR_AHCLKR_SHIFT		0x0000001Eu
  #define  MCASP_PDCLR_AHCLKR_DEFAULT		0x00000000u
  #define  MCASP_PDCLR_AHCLKR_OF(x)		_VALUEOF(x)
  #define  MCASP_PDCLR_AHCLKR_CLR		0x00000001u

  #define _MCASP_PDCLR_AFSR_MASK		0x80000000u
  #define _MCASP_PDCLR_AFSR_SHIFT		0x0000001Fu
  #define  MCASP_PDCLR_AFSR_DEFAULT		0x00000000u
  #define  MCASP_PDCLR_AFSR_OF(x)		_VALUEOF(x)
  #define  MCASP_PDCLR_AFSR_CLR	         	0x00000001u

  #define  MCASP_PDCLR_OF(x)                    _VALUEOF(x)

#if (_MCASP_CHANNEL_CNT == 16)
  #define MCASP_PDCLR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,PDCLR,AXR0)\
    |_PER_FDEFAULT(MCASP,PDCLR,AXR1)\
    |_PER_FDEFAULT(MCASP,PDCLR,AXR2)\
    |_PER_FDEFAULT(MCASP,PDCLR,AXR3)\
    |_PER_FDEFAULT(MCASP,PDCLR,AXR4)\
    |_PER_FDEFAULT(MCASP,PDCLR,AXR5)\
    |_PER_FDEFAULT(MCASP,PDCLR,AXR6)\
    |_PER_FDEFAULT(MCASP,PDCLR,AXR7)\
    |_PER_FDEFAULT(MCASP,PDCLR,AXR8)\
    |_PER_FDEFAULT(MCASP,PDCLR,AXR9)\
    |_PER_FDEFAULT(MCASP,PDCLR,AXR10)\
    |_PER_FDEFAULT(MCASP,PDCLR,AXR11)\
    |_PER_FDEFAULT(MCASP,PDCLR,AXR12)\
    |_PER_FDEFAULT(MCASP,PDCLR,AXR13)\
    |_PER_FDEFAULT(MCASP,PDCLR,AXR14)\
    |_PER_FDEFAULT(MCASP,PDCLR,AXR15)\
    |_PER_FDEFAULT(MCASP,PDCLR,AMUTE)\
    |_PER_FDEFAULT(MCASP,PDCLR,ACLKX)\
    |_PER_FDEFAULT(MCASP,PDCLR,AHCLKX)\
    |_PER_FDEFAULT(MCASP,PDCLR,AFSX)\
    |_PER_FDEFAULT(MCASP,PDCLR,ACLKR)\
    |_PER_FDEFAULT(MCASP,PDCLR,AHCLKR)\
    |_PER_FDEFAULT(MCASP,PDCLR,AFSR)\
  )

  #define MCASP_PDCLR_RMK(afsr,ahclkr,aclkr,afsx,ahclkx,aclkx,amute,  \
    axr15,axr14,axr13,axr12,axr11,axr10,\
    axr9, axr8,axr7,axr6,axr5,axr4,axr3,axr2,axr1, axr0) \
  (Uint32)( \
     _PER_FMK(MCASP,PDCLR,AXR0,axr0)\
    |_PER_FMK(MCASP,PDCLR,AXR1,axr1)\
    |_PER_FMK(MCASP,PDCLR,AXR2,axr2)\
    |_PER_FMK(MCASP,PDCLR,AXR3,axr3)\
    |_PER_FMK(MCASP,PDCLR,AXR4,axr4)\
    |_PER_FMK(MCASP,PDCLR,AXR5,axr5)\
    |_PER_FMK(MCASP,PDCLR,AXR6,axr6)\
    |_PER_FMK(MCASP,PDCLR,AXR7,axr7)\
    |_PER_FMK(MCASP,PDCLR,AXR8,axr8)\
    |_PER_FMK(MCASP,PDCLR,AXR9,axr9)\
    |_PER_FMK(MCASP,PDCLR,AXR10,axr10)\
    |_PER_FMK(MCASP,PDCLR,AXR11,axr11)\
    |_PER_FMK(MCASP,PDCLR,AXR12,axr12)\
    |_PER_FMK(MCASP,PDCLR,AXR13,axr13)\
    |_PER_FMK(MCASP,PDCLR,AXR14,axr14)\
    |_PER_FMK(MCASP,PDCLR,AXR15,axr15)\
    |_PER_FMK(MCASP,PDCLR,AMUTE,amute)\
    |_PER_FMK(MCASP,PDCLR,ACLKX,aclkx)\
    |_PER_FMK(MCASP,PDCLR,AHCLKX,ahclkx)\
    |_PER_FMK(MCASP,PDCLR,AFSX,afsx)\
    |_PER_FMK(MCASP,PDCLR,ACLKR,aclkr)\
    |_PER_FMK(MCASP,PDCLR,AHCLKR,ahclkr)\
    |_PER_FMK(MCASP,PDCLR,AFSR,afsr)\
  )
#endif /* _MCASP_CHANNEL_CNT == 16 */

#if (_MCASP_CHANNEL_CNT == 8)
  #define MCASP_PDCLR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,PDCLR,AXR0)\
    |_PER_FDEFAULT(MCASP,PDCLR,AXR1)\
    |_PER_FDEFAULT(MCASP,PDCLR,AXR2)\
    |_PER_FDEFAULT(MCASP,PDCLR,AXR3)\
    |_PER_FDEFAULT(MCASP,PDCLR,AXR4)\
    |_PER_FDEFAULT(MCASP,PDCLR,AXR5)\
    |_PER_FDEFAULT(MCASP,PDCLR,AXR6)\
    |_PER_FDEFAULT(MCASP,PDCLR,AXR7)\
    |_PER_FDEFAULT(MCASP,PDCLR,AMUTE)\
    |_PER_FDEFAULT(MCASP,PDCLR,ACLKX)\
    |_PER_FDEFAULT(MCASP,PDCLR,AHCLKX)\
    |_PER_FDEFAULT(MCASP,PDCLR,AFSX)\
    |_PER_FDEFAULT(MCASP,PDCLR,ACLKR)\
    |_PER_FDEFAULT(MCASP,PDCLR,AHCLKR)\
    |_PER_FDEFAULT(MCASP,PDCLR,AFSR)\
  )

  #define MCASP_PDCLR_RMK(afsr,ahclkr,aclkr,afsx,ahclkx,aclkx,amute,  \
                          axr7,axr6,axr5,axr4,axr3,axr2,axr1, axr0) \
  (Uint32)( \
     _PER_FMK(MCASP,PDCLR,AXR0,axr0)\
    |_PER_FMK(MCASP,PDCLR,AXR1,axr1)\
    |_PER_FMK(MCASP,PDCLR,AXR2,axr2)\
    |_PER_FMK(MCASP,PDCLR,AXR3,axr3)\
    |_PER_FMK(MCASP,PDCLR,AXR4,axr4)\
    |_PER_FMK(MCASP,PDCLR,AXR5,axr5)\
    |_PER_FMK(MCASP,PDCLR,AXR6,axr6)\
    |_PER_FMK(MCASP,PDCLR,AXR7,axr7)\
    |_PER_FMK(MCASP,PDCLR,AMUTE,amute)\
    |_PER_FMK(MCASP,PDCLR,ACLKX,aclkx)\
    |_PER_FMK(MCASP,PDCLR,AHCLKX,ahclkx)\
    |_PER_FMK(MCASP,PDCLR,AFSX,afsx)\
    |_PER_FMK(MCASP,PDCLR,ACLKR,aclkr)\
    |_PER_FMK(MCASP,PDCLR,AHCLKR,ahclkr)\
    |_PER_FMK(MCASP,PDCLR,AFSR,afsr)\
  )
#endif /* _MCASP_CHANNEL_CNT == 8 */

#if (_MCASP_CHANNEL_CNT == 6)
  #define MCASP_PDCLR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,PDCLR,AXR0)\
    |_PER_FDEFAULT(MCASP,PDCLR,AXR1)\
    |_PER_FDEFAULT(MCASP,PDCLR,AXR2)\
    |_PER_FDEFAULT(MCASP,PDCLR,AXR3)\
    |_PER_FDEFAULT(MCASP,PDCLR,AXR4)\
    |_PER_FDEFAULT(MCASP,PDCLR,AXR5)\
    |_PER_FDEFAULT(MCASP,PDCLR,AMUTE)\
    |_PER_FDEFAULT(MCASP,PDCLR,ACLKX)\
    |_PER_FDEFAULT(MCASP,PDCLR,AHCLKX)\
    |_PER_FDEFAULT(MCASP,PDCLR,AFSX)\
    |_PER_FDEFAULT(MCASP,PDCLR,ACLKR)\
    |_PER_FDEFAULT(MCASP,PDCLR,AHCLKR)\
    |_PER_FDEFAULT(MCASP,PDCLR,AFSR)\
  )

  #define MCASP_PDCLR_RMK(afsr,ahclkr,aclkr,afsx,ahclkx,aclkx,amute,  \
                          axr5,axr4,axr3,axr2,axr1, axr0) \
  (Uint32)( \
     _PER_FMK(MCASP,PDCLR,AXR0,axr0)\
    |_PER_FMK(MCASP,PDCLR,AXR1,axr1)\
    |_PER_FMK(MCASP,PDCLR,AXR2,axr2)\
    |_PER_FMK(MCASP,PDCLR,AXR3,axr3)\
    |_PER_FMK(MCASP,PDCLR,AXR4,axr4)\
    |_PER_FMK(MCASP,PDCLR,AXR5,axr5)\
    |_PER_FMK(MCASP,PDCLR,AMUTE,amute)\
    |_PER_FMK(MCASP,PDCLR,ACLKX,aclkx)\
    |_PER_FMK(MCASP,PDCLR,AHCLKX,ahclkx)\
    |_PER_FMK(MCASP,PDCLR,AFSX,afsx)\
    |_PER_FMK(MCASP,PDCLR,ACLKR,aclkr)\
    |_PER_FMK(MCASP,PDCLR,AHCLKR,ahclkr)\
    |_PER_FMK(MCASP,PDCLR,AFSR,afsr)\
  )
#endif /* _MCASP_CHANNEL_CNT == 6 */

#if (_MCASP_CHANNEL_CNT == 4)
  #define MCASP_PDCLR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,PDCLR,AXR0)\
    |_PER_FDEFAULT(MCASP,PDCLR,AXR1)\
    |_PER_FDEFAULT(MCASP,PDCLR,AXR2)\
    |_PER_FDEFAULT(MCASP,PDCLR,AXR3)\
    |_PER_FDEFAULT(MCASP,PDCLR,AMUTE)\
    |_PER_FDEFAULT(MCASP,PDCLR,ACLKX)\
    |_PER_FDEFAULT(MCASP,PDCLR,AHCLKX)\
    |_PER_FDEFAULT(MCASP,PDCLR,AFSX)\
    |_PER_FDEFAULT(MCASP,PDCLR,ACLKR)\
    |_PER_FDEFAULT(MCASP,PDCLR,AHCLKR)\
    |_PER_FDEFAULT(MCASP,PDCLR,AFSR)\
  )

  #define MCASP_PDCLR_RMK(afsr,ahclkr,aclkr,afsx,ahclkx,aclkx,amute,  \
                          axr3,axr2,axr1, axr0) \
  (Uint32)( \
     _PER_FMK(MCASP,PDCLR,AXR0,axr0)\
    |_PER_FMK(MCASP,PDCLR,AXR1,axr1)\
    |_PER_FMK(MCASP,PDCLR,AXR2,axr2)\
    |_PER_FMK(MCASP,PDCLR,AXR3,axr3)\
    |_PER_FMK(MCASP,PDCLR,AMUTE,amute)\
    |_PER_FMK(MCASP,PDCLR,ACLKX,aclkx)\
    |_PER_FMK(MCASP,PDCLR,AHCLKX,ahclkx)\
    |_PER_FMK(MCASP,PDCLR,AFSX,afsx)\
    |_PER_FMK(MCASP,PDCLR,ACLKR,aclkr)\
    |_PER_FMK(MCASP,PDCLR,AHCLKR,ahclkr)\
    |_PER_FMK(MCASP,PDCLR,AFSR,afsr)\
  )
#endif /* _MCASP_CHANNEL_CNT == 4 */

  #define _MCASP_PDCLR_FGET(N,FIELD)\
    _PER_FGET(_MCASP_PDCLR##N##_ADDR,MCASP,PDCLR,##FIELD)

  #define _MCASP_PDCLR_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_PDCLR##N##_ADDR,MCASP,PDCLR,##FIELD,field)

  #define _MCASP_PDCLR_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_PDCLR##N##_ADDR,MCASP,PDCLR,##FIELD,##SYM)


  #define _MCASP_PDCLR0_FGET(FIELD) _MCASP_PDCLR_FGET(0,##FIELD)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PDCLR1_FGET(FIELD) _MCASP_PDCLR_FGET(1,##FIELD)
#endif
 
  #define _MCASP_PDCLR0_FSET(FIELD,f) _MCASP_PDCLR_FSET(0,##FIELD,f)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PDCLR1_FSET(FIELD,f) _MCASP_PDCLR_FSET(1,##FIELD,f)
#endif

  #define _MCASP_PDCLR0_FSETS(FIELD,SYM) _MCASP_PDCLR_FSETS(0,##FIELD,##SYM)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_PDCLR1_FSETS(FIELD,SYM) _MCASP_PDCLR_FSETS(1,##FIELD,##SYM)
#endif


/******************************************************************************\
* 
* _____________________
* |                   |
* |     GBLCTL        |
* |___________________|
*
* GBLCTL  -  Global Control Register
*
* FIELDS (msb -> lsb)
* (rw)  XFRST
* (rw)  XSMRST
* (rw)  XSRCLR
* (rw)  XHCLKRST
* (rw)  XCLKRST
* (rw)  RFRST
* (rw)  RSMRST
* (rw)  RSRCLR
* (rw)  RHCLKRST
* (rw)  RCLKRST
*
\******************************************************************************/

  #define _MCASP_GBLCTL_OFFSET               17

  #define _MCASP_GBLCTL0_ADDR				(_MCASP_BASE_PORT0+4*_MCASP_GBLCTL_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_GBLCTL1_ADDR				(_MCASP_BASE_PORT1+4*_MCASP_GBLCTL_OFFSET)
#endif

  #define _MCASP_GBLCTL_XFRST_MASK              0x00001000u
  #define _MCASP_GBLCTL_XFRST_SHIFT             0x0000000Cu
  #define  MCASP_GBLCTL_XFRST_DEFAULT           0x00000000u
  #define  MCASP_GBLCTL_XFRST_OF(x)             _VALUEOF(x)
  #define  MCASP_GBLCTL_XFRST_RESET             0x00000000u
  #define  MCASP_GBLCTL_XFRST_ACTIVE            0x00000001u


  #define _MCASP_GBLCTL_XSMRST_MASK              0x00000800u
  #define _MCASP_GBLCTL_XSMRST_SHIFT             0x0000000Bu
  #define  MCASP_GBLCTL_XSMRST_DEFAULT           0x00000000u
  #define  MCASP_GBLCTL_XSMRST_OF(x)             _VALUEOF(x)
  #define  MCASP_GBLCTL_XSMRST_RESET			0x00000000u
  #define  MCASP_GBLCTL_XSMRST_ACTIVE			0x00000001u


  #define _MCASP_GBLCTL_XSRCLR_MASK            0x00000400u
  #define _MCASP_GBLCTL_XSRCLR_SHIFT           0x0000000Au
  #define  MCASP_GBLCTL_XSRCLR_DEFAULT         0x00000000u
  #define  MCASP_GBLCTL_XSRCLR_OF(x)           _VALUEOF(x)
  #define  MCASP_GBLCTL_XSRCLR_CLEAR         0x00000000u
  #define  MCASP_GBLCTL_XSRCLR_ACTIVE          0x00000001u


  #define _MCASP_GBLCTL_XHCLKRST_MASK           0x00000200u
  #define _MCASP_GBLCTL_XHCLKRST_SHIFT          0x00000009u
  #define  MCASP_GBLCTL_XHCLKRST_DEFAULT        0x00000000u
  #define  MCASP_GBLCTL_XHCLKRST_OF(x)          _VALUEOF(x)
  #define  MCASP_GBLCTL_XHCLKRST_RESET		0x00000000u
  #define  MCASP_GBLCTL_XHCLKRST_ACTIVE		0x00000001u


  #define _MCASP_GBLCTL_XCLKRST_MASK              0x00000100u
  #define _MCASP_GBLCTL_XCLKRST_SHIFT             0x00000008u
  #define  MCASP_GBLCTL_XCLKRST_DEFAULT           0x00000000u
  #define  MCASP_GBLCTL_XCLKRST_OF(x)             _VALUEOF(x)
  #define  MCASP_GBLCTL_XCLKRST_RESET			0x00000000u
  #define  MCASP_GBLCTL_XCLKRST_ACTIVE		0x00000001u

  #define _MCASP_GBLCTL_RFRST_MASK              0x00000010u
  #define _MCASP_GBLCTL_RFRST_SHIFT             0x00000004u
  #define  MCASP_GBLCTL_RFRST_DEFAULT           0x00000000u
  #define  MCASP_GBLCTL_RFRST_OF(x)             _VALUEOF(x)
  #define  MCASP_GBLCTL_RFRST_RESET             0x00000000u
  #define  MCASP_GBLCTL_RFRST_ACTIVE            0x00000001u

  #define _MCASP_GBLCTL_RSMRST_MASK              0x00000008u
  #define _MCASP_GBLCTL_RSMRST_SHIFT             0x00000003u
  #define  MCASP_GBLCTL_RSMRST_DEFAULT           0x00000000u
  #define  MCASP_GBLCTL_RSMRST_OF(x)             _VALUEOF(x)
  #define  MCASP_GBLCTL_RSMRST_RESET		     0x00000000u
  #define  MCASP_GBLCTL_RSMRST_ACTIVE		     0x00000001u


  #define _MCASP_GBLCTL_RSRCLR_MASK             0x00000004u
  #define _MCASP_GBLCTL_RSRCLR_SHIFT            0x00000002u
  #define  MCASP_GBLCTL_RSRCLR_DEFAULT          0x00000000u
  #define  MCASP_GBLCTL_RSRCLR_OF(x)            _VALUEOF(x)
  #define  MCASP_GBLCTL_RSRCLR_CLEAR          0x00000000u
  #define  MCASP_GBLCTL_RSRCLR_ACTIVE           0x00000001u


  #define _MCASP_GBLCTL_RHCLKRST_MASK           0x00000002u
  #define _MCASP_GBLCTL_RHCLKRST_SHIFT          0x00000001u
  #define  MCASP_GBLCTL_RHCLKRST_DEFAULT        0x00000000u
  #define  MCASP_GBLCTL_RHCLKRST_OF(x)         _VALUEOF(x)
  #define  MCASP_GBLCTL_RHCLKRST_RESET	     0x00000000u
  #define  MCASP_GBLCTL_RHCLKRST_ACTIVE        0x00000001u


  #define _MCASP_GBLCTL_RCLKRST_MASK             0x00000001u
  #define _MCASP_GBLCTL_RCLKRST_SHIFT            0x00000000u
  #define  MCASP_GBLCTL_RCLKRST_DEFAULT          0x00000000u
  #define  MCASP_GBLCTL_RCLKRST_OF(x)            _VALUEOF(x)
  #define  MCASP_GBLCTL_RCLKRST_RESET	       0x00000000u
  #define  MCASP_GBLCTL_RCLKRST_ACTIVE	       0x00000001u


  #define  MCASP_GBLCTL_OF(x)                _VALUEOF(x)

  #define MCASP_GBLCTL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,GBLCTL,XFRST)\
    |_PER_FDEFAULT(MCASP,GBLCTL,XSMRST)\
    |_PER_FDEFAULT(MCASP,GBLCTL,XSRCLR)\
    |_PER_FDEFAULT(MCASP,GBLCTL,XHCLKRST)\
    |_PER_FDEFAULT(MCASP,GBLCTL,XCLKRST)\
    |_PER_FDEFAULT(MCASP,GBLCTL,RFRST)\
    |_PER_FDEFAULT(MCASP,GBLCTL,RSMRST)\
    |_PER_FDEFAULT(MCASP,GBLCTL,RSRCLR)\
    |_PER_FDEFAULT(MCASP,GBLCTL,RHCLKRST)\
    |_PER_FDEFAULT(MCASP,GBLCTL,RCLKRST)\
  )


  #define MCASP_GBLCTL_RMK(xfrst, xsmrst, xsrclr, xhclkrst, xclkrst, rfrst, rsmrst, rsrclr, rhclkrst, rclkrst) (Uint32)( \
     _PER_FMK(MCASP,GBLCTL,XFRST,xfrst)\
    |_PER_FMK(MCASP,GBLCTL,XSMRST,xsmrst)\
    |_PER_FMK(MCASP,GBLCTL,XSRCLR,xsrclr)\
    |_PER_FMK(MCASP,GBLCTL,XHCLKRST,xhclkrst)\
    |_PER_FMK(MCASP,GBLCTL,XCLKRST,xclkrst)\
    |_PER_FMK(MCASP,GBLCTL,RFRST,rfrst)\
    |_PER_FMK(MCASP,GBLCTL,RSMRST,rsmrst)\
    |_PER_FMK(MCASP,GBLCTL,RSRCLR,rsrclr)\
    |_PER_FMK(MCASP,GBLCTL,RHCLKRST,rhclkrst)\
    |_PER_FMK(MCASP,GBLCTL,RCLKRST,rclkrst)\
  )


  #define _MCASP_GBLCTL_FGET(N,FIELD)\
    _PER_FGET(_MCASP_GBLCTL##N##_ADDR,MCASP,GBLCTL,##FIELD)

  #define _MCASP_GBLCTL_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_GBLCTL##N##_ADDR,MCASP,GBLCTL,##FIELD,field)

  #define _MCASP_GBLCTL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_GBLCTL##N##_ADDR,MCASP,GBLCTL,##FIELD,##SYM)


  #define _MCASP_GBLCTL0_FGET(FIELD) _MCASP_GBLCTL_FGET(0,##FIELD)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_GBLCTL1_FGET(FIELD) _MCASP_GBLCTL_FGET(1,##FIELD)
#endif
 
  #define _MCASP_GBLCTL0_FSET(FIELD,f) _MCASP_GBLCTL_FSET(0,##FIELD,f)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_GBLCTL1_FSET(FIELD,f) _MCASP_GBLCTL_FSET(1,##FIELD,f)
#endif

  #define _MCASP_GBLCTL0_FSETS(FIELD,SYM) _MCASP_GBLCTL_FSETS(0,##FIELD,##SYM)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_GBLCTL1_FSETS(FIELD,SYM) _MCASP_GBLCTL_FSETS(1,##FIELD,##SYM)
#endif


/******************************************************************************\
* 
* _____________________
* |                   |
* |     AMUTE         |
* |___________________|
*
* AMUTE  -  register name
*
* FIELDS (msb -> lsb)
* (rw)  XDMAERR  
* (rw)  RDMAERR  
* (rw)  XCKFAIL  
* (rw)  RCKFAIL
* (rw)  XSYNCERR 
* (rw)  RSYNCERR
* (rw)  XUNDRN
* (rw)  ROVRN  
* (r )  INSTAT
* (rw)  INEN
* (r )  INPOL
* (rw)  MUTEN
\******************************************************************************/

  #define _MCASP_AMUTE_OFFSET               18

  #define _MCASP_AMUTE0_ADDR				(_MCASP_BASE_PORT0+4*_MCASP_AMUTE_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_AMUTE1_ADDR				(_MCASP_BASE_PORT1+4*_MCASP_AMUTE_OFFSET)
#endif
  
  #define _MCASP_AMUTE_XDMAERR_MASK              0x00001000u
  #define _MCASP_AMUTE_XDMAERR_SHIFT             0x0000000Cu
  #define  MCASP_AMUTE_XDMAERR_DEFAULT           0x00000000u
  #define  MCASP_AMUTE_XDMAERR_OF(x)             _VALUEOF(x)
  #define  MCASP_AMUTE_XDMAERR_DISABLE          0x00000000u
  #define  MCASP_AMUTE_XDMAERR_ENABLE           0x00000001u

  #define _MCASP_AMUTE_RDMAERR_MASK              0x00000800u
  #define _MCASP_AMUTE_RDMAERR_SHIFT             0x0000000Bu
  #define  MCASP_AMUTE_RDMAERR_DEFAULT           0x00000000u
  #define  MCASP_AMUTE_RDMAERR_OF(x)             _VALUEOF(x)
  #define  MCASP_AMUTE_RDMAERR_DISABLE          0x00000000u
  #define  MCASP_AMUTE_RDMAERR_ENABLE           0x00000001u

  #define _MCASP_AMUTE_XCKFAIL_MASK              0x00000400u
  #define _MCASP_AMUTE_XCKFAIL_SHIFT             0x0000000Au
  #define  MCASP_AMUTE_XCKFAIL_DEFAULT           0x00000000u
  #define  MCASP_AMUTE_XCKFAIL_OF(x)             _VALUEOF(x)
  #define  MCASP_AMUTE_XCKFAIL_DISABLE          0x00000000u
  #define  MCASP_AMUTE_XCKFAIL_ENABLE           0x00000001u
  

  #define _MCASP_AMUTE_RCKFAIL_MASK              0x00000200u
  #define _MCASP_AMUTE_RCKFAIL_SHIFT             0x00000009u
  #define  MCASP_AMUTE_RCKFAIL_DEFAULT           0x00000000u
  #define  MCASP_AMUTE_RCKFAIL_OF(x)             _VALUEOF(x)
  #define  MCASP_AMUTE_RCKFAIL_DISABLE          0x00000000u
  #define  MCASP_AMUTE_RCKFAIL_ENABLE           0x00000001u
  

  #define _MCASP_AMUTE_XSYNCERR_MASK              0x00000100u
  #define _MCASP_AMUTE_XSYNCERR_SHIFT             0x00000008u
  #define  MCASP_AMUTE_XSYNCERR_DEFAULT           0x00000000u
  #define  MCASP_AMUTE_XSYNCERR_OF(x)             _VALUEOF(x)
  #define  MCASP_AMUTE_XSYNCERR_DISABLE          0x00000000u
  #define  MCASP_AMUTE_XSYNCERR_ENABLE           0x00000001u
  

  #define _MCASP_AMUTE_RSYNCERR_MASK              0x00000080u
  #define _MCASP_AMUTE_RSYNCERR_SHIFT             0x00000007u
  #define  MCASP_AMUTE_RSYNCERR_DEFAULT           0x00000000u
  #define  MCASP_AMUTE_RSYNCERR_OF(x)             _VALUEOF(x)
  #define  MCASP_AMUTE_RSYNCERR_DISABLE          0x00000000u
  #define  MCASP_AMUTE_RSYNCERR_ENABLE           0x00000001u
  

  #define _MCASP_AMUTE_XUNDRN_MASK              0x00000040u
  #define _MCASP_AMUTE_XUNDRN_SHIFT             0x00000006u
  #define  MCASP_AMUTE_XUNDRN_DEFAULT           0x00000000u
  #define  MCASP_AMUTE_XUNDRN_OF(x)             _VALUEOF(x)
  #define  MCASP_AMUTE_XUNDRN_DISABLE          0x00000000u
  #define  MCASP_AMUTE_XUNDRN_ENABLE           0x00000001u
  

  #define _MCASP_AMUTE_ROVRN_MASK              0x00000020u
  #define _MCASP_AMUTE_ROVRN_SHIFT             0x00000005u
  #define  MCASP_AMUTE_ROVRN_DEFAULT           0x00000000u
  #define  MCASP_AMUTE_ROVRN_OF(x)             _VALUEOF(x)
  #define  MCASP_AMUTE_ROVRN_DISABLE          0x00000000u
  #define  MCASP_AMUTE_ROVRN_ENABLE           0x00000001u


  #define _MCASP_AMUTE_INSTAT_MASK              0x00000010u
  #define _MCASP_AMUTE_INSTAT_SHIFT             0x00000004u
  #define  MCASP_AMUTE_INSTAT_DEFAULT           0x00000000u
  #define  MCASP_AMUTE_INSTAT_OF(x)             _VALUEOF(x)
   

  #define _MCASP_AMUTE_INEN_MASK              0x00000008u
  #define _MCASP_AMUTE_INEN_SHIFT             0x00000003u
  #define  MCASP_AMUTE_INEN_DEFAULT           0x00000000u
  #define  MCASP_AMUTE_INEN_OF(x)             _VALUEOF(x)
  #define  MCASP_AMUTE_INEN_DISABLE          0x00000000u
  #define  MCASP_AMUTE_INEN_ENABLE           0x00000001u
  

  #define _MCASP_AMUTE_INPOL_MASK              0x00000004u
  #define _MCASP_AMUTE_INPOL_SHIFT             0x00000002u
  #define  MCASP_AMUTE_INPOL_DEFAULT           0x00000000u
  #define  MCASP_AMUTE_INPOL_OF(x)             _VALUEOF(x)
  #define  MCASP_AMUTE_INPOL_ACTHIGH           0x00000000u
  #define  MCASP_AMUTE_INPOL_ACTLOW            0x00000001u


  #define _MCASP_AMUTE_MUTEN_MASK              0x00000003u
  #define _MCASP_AMUTE_MUTEN_SHIFT             0x00000000u
  #define  MCASP_AMUTE_MUTEN_DEFAULT           0x00000000u
  #define  MCASP_AMUTE_MUTEN_OF(x)             _VALUEOF(x)
  #define  MCASP_AMUTE_MUTEN_DISABLE          0x00000000u
  #define  MCASP_AMUTE_MUTEN_ERRHIGH         0x00000001u
  #define  MCASP_AMUTE_MUTEN_ERRLOW          0x00000002u 
  
  #define  MCASP_AMUTE_OF(x)                _VALUEOF(x)

  #define MCASP_AMUTE_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,AMUTE,XDMAERR)\
	| _PER_FDEFAULT(MCASP,AMUTE,RDMAERR)\
    | _PER_FDEFAULT(MCASP,AMUTE,XCKFAIL)\
	| _PER_FDEFAULT(MCASP,AMUTE,RCKFAIL)\
	| _PER_FDEFAULT(MCASP,AMUTE,XSYNCERR )\
	| _PER_FDEFAULT(MCASP,AMUTE,RSYNCERR)\
	| _PER_FDEFAULT(MCASP,AMUTE,XUNDRN)\
	| _PER_FDEFAULT(MCASP,AMUTE,ROVRN)\
	| _PER_FDEFAULT(MCASP,AMUTE,INSTAT)\
	| _PER_FDEFAULT(MCASP,AMUTE,INEN)\
	| _PER_FDEFAULT(MCASP,AMUTE,MUTEN)\
  )

  #define MCASP_AMUTE_RMK(xdmaerr,rdmaerr,xckfail, rckfail, xsyncerr, rsyncerr, xundrn, rovrn,inen, muten) (Uint32)( \
     _PER_FMK(MCASP,AMUTE,XDMAERR,xdmaerr)\
	| _PER_FMK(MCASP,AMUTE,RDMAERR,rdmaerr)\
      | _PER_FMK(MCASP,AMUTE,XCKFAIL,xckfail)\
	| _PER_FMK(MCASP,AMUTE,RCKFAIL,rckfail)\
	| _PER_FMK(MCASP,AMUTE,XSYNCERR ,xsyncerr)\
	| _PER_FMK(MCASP,AMUTE,RSYNCERR,rsyncerr)\
	| _PER_FMK(MCASP,AMUTE,XUNDRN,xundrn)\
	| _PER_FMK(MCASP,AMUTE,ROVRN,rovrn)\
	| _PER_FMK(MCASP,AMUTE,INEN,inen)\
	| _PER_FMK(MCASP,AMUTE,MUTEN,muten)\
  )


  #define _MCASP_AMUTE_FGET(N,FIELD)\
    _PER_FGET(_MCASP_AMUTE##N##_ADDR,MCASP,AMUTE,##FIELD)

  #define _MCASP_AMUTE_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_AMUTE##N##_ADDR,MCASP,AMUTE,##FIELD,field)

  #define _MCASP_AMUTE_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_AMUTE##N##_ADDR,MCASP,AMUTE,##FIELD,##SYM)

  #define _MCASP_AMUTE0_FGET(FIELD) _MCASP_AMUTE_FGET(0,##FIELD)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_AMUTE1_FGET(FIELD) _MCASP_AMUTE_FGET(1,##FIELD)
#endif
 
  #define _MCASP_AMUTE0_FSET(FIELD,f) _MCASP_AMUTE_FSET(0,##FIELD,f)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_AMUTE1_FSET(FIELD,f) _MCASP_AMUTE_FSET(1,##FIELD,f)
#endif

  #define _MCASP_AMUTE0_FSETS(FIELD,SYM) _MCASP_AMUTE_FSETS(0,##FIELD,##SYM)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_AMUTE1_FSETS(FIELD,SYM) _MCASP_AMUTE_FSETS(1,##FIELD,##SYM)
#endif


/******************************************************************************\
* 
* _____________________
* |                   |
* |       DLBCTL      |
* |___________________|
*
* DLBCTL  -  Digital Loopback Control Register
*
* FIELDS (msb -> lsb)
* (rw)  MODE  
* (rw)  ORD 
* (rw)  DLBEN  
\******************************************************************************/

  #define _MCASP_DLBCTL_OFFSET               19

  #define _MCASP_DLBCTL0_ADDR				(_MCASP_BASE_PORT0+4*_MCASP_DLBCTL_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_DLBCTL1_ADDR				(_MCASP_BASE_PORT1+4*_MCASP_DLBCTL_OFFSET)
#endif

  #define _MCASP_DLBCTL_MODE_MASK              0x0000000Cu 
  #define _MCASP_DLBCTL_MODE_SHIFT             0x00000002u 
  #define  MCASP_DLBCTL_MODE_DEFAULT           0x00000000u
  #define  MCASP_DLBCTL_MODE_OF(x)             _VALUEOF(x)
  #define  MCASP_DLBCTL_MODE_XMTCLK            0x00000001u 

  #define _MCASP_DLBCTL_ORD_MASK              0x00000002u 
  #define _MCASP_DLBCTL_ORD_SHIFT             0x00000001u 
  #define  MCASP_DLBCTL_ORD_DEFAULT           0x00000000u
  #define  MCASP_DLBCTL_ORD_OF(x)             _VALUEOF(x)
  #define  MCASP_DLBCTL_ORD_XMTODD             0x00000000u 
  #define  MCASP_DLBCTL_ORD_XMTEVEN            0x00000001u 


  #define _MCASP_DLBCTL_DLBEN_MASK              0x00000001u 
  #define _MCASP_DLBCTL_DLBEN_SHIFT             0x00000000u 
  #define  MCASP_DLBCTL_DLBEN_DEFAULT           0x00000000u
  #define  MCASP_DLBCTL_DLBEN_OF(x)             _VALUEOF(x)
  #define  MCASP_DLBCTL_DLBEN_DISABLE           0x00000000u 
  #define  MCASP_DLBCTL_DLBEN_ENABLE            0x00000001u 

  #define  MCASP_DLBCTL_OF(x)                _VALUEOF(x)

  #define MCASP_DLBCTL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,DLBCTL,MODE)\
    |_PER_FDEFAULT(MCASP,DLBCTL,ORD)\
    |_PER_FDEFAULT(MCASP,DLBCTL,DLBEN)\
  )

  #define MCASP_DLBCTL_RMK(mode, ord, dlben) (Uint32)( \
     _PER_FMK(MCASP,DLBCTL,MODE,mode)\
    |_PER_FMK(MCASP,DLBCTL,ORD,ord)\
    |_PER_FMK(MCASP,DLBCTL,DLBEN,dlben)\
  )


  #define _MCASP_DLBCTL_FGET(N,FIELD)\
    _PER_FGET(_MCASP_DLBCTL##N##_ADDR,MCASP,DLBCTL,##FIELD)

  #define _MCASP_DLBCTL_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_DLBCTL##N##_ADDR,MCASP,DLBCTL,##FIELD,field)

  #define _MCASP_DLBCTL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_DLBCTL##N##_ADDR,MCASP,DLBCTL,##FIELD,##SYM)


  #define _MCASP_DLBCTL0_FGET(FIELD) _MCASP_DLBCTL_FGET(0,##FIELD)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_DLBCTL1_FGET(FIELD) _MCASP_DLBCTL_FGET(1,##FIELD)
#endif
 
  #define _MCASP_DLBCTL0_FSET(FIELD,f) _MCASP_DLBCTL_FSET(0,##FIELD,f)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_DLBCTL1_FSET(FIELD,f) _MCASP_DLBCTL_FSET(1,##FIELD,f)
#endif

  #define _MCASP_DLBCTL0_FSETS(FIELD,SYM) _MCASP_DLBCTL_FSETS(0,##FIELD,##SYM)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_DLBCTL1_FSETS(FIELD,SYM) _MCASP_DLBCTL_FSETS(1,##FIELD,##SYM)
#endif


/******************************************************************************\
* 
* _____________________
* |                   |
* |     DITCTL        |
* |___________________|
*
* DITCTL  -  Transmit DIT Control Register
*
* FIELDS (msb -> lsb)
* (rw)  VB  
* (rw)  VA
* (rw)  DITEN  
*
\******************************************************************************/

  #define _MCASP_DITCTL_OFFSET               20

  #define _MCASP_DITCTL0_ADDR				(_MCASP_BASE_PORT0+4*_MCASP_DITCTL_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_DITCTL1_ADDR				(_MCASP_BASE_PORT1+4*_MCASP_DITCTL_OFFSET)
#endif

  #define _MCASP_DITCTL_VB_MASK              0x00000008u
  #define _MCASP_DITCTL_VB_SHIFT             0x00000003u
  #define  MCASP_DITCTL_VB_DEFAULT           0x00000000u
  #define  MCASP_DITCTL_VB_OF(x)             _VALUEOF(x)
  #define  MCASP_DITCTL_VB_ZERO	           0x00000000u
  #define  MCASP_DITCTL_VB_ONE		   0x00000001u

  #define _MCASP_DITCTL_VA_MASK              0x00000004u
  #define _MCASP_DITCTL_VA_SHIFT             0x00000002u
  #define  MCASP_DITCTL_VA_DEFAULT           0x00000000u
  #define  MCASP_DITCTL_VA_OF(x)             _VALUEOF(x)
  #define  MCASP_DITCTL_VA_ZERO              0x00000000u
  #define  MCASP_DITCTL_VA_ONE	         0x00000001u

  #define _MCASP_DITCTL_DITEN_MASK           0x00000001u
  #define _MCASP_DITCTL_DITEN_SHIFT          0x00000000u
  #define  MCASP_DITCTL_DITEN_DEFAULT        0x00000000u
  #define  MCASP_DITCTL_DITEN_OF(x)          _VALUEOF(x)
  #define  MCASP_DITCTL_DITEN_TDM            0x00000000u
  #define  MCASP_DITCTL_DITEN_DIT            0x00000001u

  #define  MCASP_DITCTL_OF(x)                _VALUEOF(x)

  #define MCASP_DITCTL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,DITCTL,VB)\
    |_PER_FDEFAULT(MCASP,DITCTL,VA)\
    |_PER_FDEFAULT(MCASP,DITCTL,DITEN)\
  )

  #define MCASP_DITCTL_RMK(vb,va,diten) (Uint32)( \
     _PER_FMK(MCASP,DITCTL,VB,vb)\
    |_PER_FMK(MCASP,DITCTL,VA,va)\
    |_PER_FMK(MCASP,DITCTL,DITEN,diten)\
  )

  #define _MCASP_DITCTL_FGET(N,FIELD)\
    _PER_FGET(_MCASP_DITCTL##N##_ADDR,MCASP,DITCTL,##FIELD)

  #define _MCASP_DITCTL_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_DITCTL##N##_ADDR,MCASP,DITCTL,##FIELD,field)

  #define _MCASP_DITCTL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_DITCTL##N##_ADDR,MCASP,DITCTL,##FIELD,##SYM)

  #define _MCASP_DITCTL0_FGET(FIELD) _MCASP_DITCTL_FGET(0,##FIELD)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_DITCTL1_FGET(FIELD) _MCASP_DITCTL_FGET(1,##FIELD)
#endif

  #define _MCASP_DITCTL0_FSET(FIELD,f) _MCASP_DITCTL_FSET(0,##FIELD,f)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_DITCTL1_FSET(FIELD,f) _MCASP_DITCTL_FSET(1,##FIELD,f)
#endif

  #define _MCASP_DITCTL0_FSETS(FIELD,SYM) _MCASP_DITCTL_FSETS(0,##FIELD,##SYM)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_DITCTL1_FSETS(FIELD,SYM) _MCASP_DITCTL_FSETS(1,##FIELD,##SYM)
#endif


/******************************************************************************\
* 
* _____________________
* |                   |
* |     RGBLCTL       |
* |___________________|
*
* RGBLCTL  -  Global Control Register
*
* FIELDS (msb -> lsb)
* (r)   XFRST
* (r)   XSMRST
* (r)   XSRCLR
* (r)   XHCLKRST
* (r)   XCLKRST
* (rw)  RFRST
* (rw)  RSMRST
* (rw)  RSRCLR
* (rw)  RHCLKRST
* (rw)  RCLKRST
*
\******************************************************************************/

  #define _MCASP_RGBLCTL_OFFSET               24

  #define _MCASP_RGBLCTL0_ADDR		(_MCASP_BASE_PORT0+4*_MCASP_RGBLCTL_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RGBLCTL1_ADDR		(_MCASP_BASE_PORT1+4*_MCASP_RGBLCTL_OFFSET)
#endif

  #define _MCASP_RGBLCTL_XFRST_MASK      0x00001000u
  #define _MCASP_RGBLCTL_XFRST_SHIFT     0x0000000Cu
  #define  MCASP_RGBLCTL_XFRST_DEFAULT   0x00000000u
  #define  MCASP_RGBLCTL_XFRST_OF(x)     _VALUEOF(x)
  #define  MCASP_RGBLCTL_XFRST_RESET     0x00000000u
  #define  MCASP_RGBLCTL_XFRST_ACTIVE    0x00000001u

  #define _MCASP_RGBLCTL_XSMRST_MASK     0x00000800u
  #define _MCASP_RGBLCTL_XSMRST_SHIFT    0x0000000Bu
  #define  MCASP_RGBLCTL_XSMRST_DEFAULT  0x00000000u
  #define  MCASP_RGBLCTL_XSMRST_OF(x)    _VALUEOF(x)
  #define  MCASP_RGBLCTL_XSMRST_RESET	 0x00000000u
  #define  MCASP_RGBLCTL_XSMRST_ACTIVE	 0x00000001u

  #define _MCASP_RGBLCTL_XSRCLR_MASK     0x00000400u
  #define _MCASP_RGBLCTL_XSRCLR_SHIFT    0x0000000Au
  #define  MCASP_RGBLCTL_XSRCLR_DEFAULT  0x00000000u
  #define  MCASP_RGBLCTL_XSRCLR_OF(x)    _VALUEOF(x)
  #define  MCASP_RGBLCTL_XSRCLR_CLEAR    0x00000000u
  #define  MCASP_RGBLCTL_XSRCLR_ACTIVE   0x00000001u

  #define _MCASP_RGBLCTL_XHCLKRST_MASK     0x00000200u
  #define _MCASP_RGBLCTL_XHCLKRST_SHIFT    0x00000009u
  #define  MCASP_RGBLCTL_XHCLKRST_DEFAULT  0x00000000u
  #define  MCASP_RGBLCTL_XHCLKRST_OF(x)    _VALUEOF(x)
  #define  MCASP_RGBLCTL_XHCLKRST_RESET	   0x00000000u
  #define  MCASP_RGBLCTL_XHCLKRST_ACTIVE   0x00000001u

  #define _MCASP_RGBLCTL_XCLKRST_MASK      0x00000100u
  #define _MCASP_RGBLCTL_XCLKRST_SHIFT     0x00000008u
  #define  MCASP_RGBLCTL_XCLKRST_DEFAULT   0x00000000u
  #define  MCASP_RGBLCTL_XCLKRST_OF(x)     _VALUEOF(x)
  #define  MCASP_RGBLCTL_XCLKRST_RESET	   0x00000000u
  #define  MCASP_RGBLCTL_XCLKRST_ACTIVE	   0x00000001u

  #define _MCASP_RGBLCTL_RFRST_MASK              0x00000010u
  #define _MCASP_RGBLCTL_RFRST_SHIFT             0x00000004u
  #define  MCASP_RGBLCTL_RFRST_DEFAULT           0x00000000u
  #define  MCASP_RGBLCTL_RFRST_OF(x)             _VALUEOF(x)
  #define  MCASP_RGBLCTL_RFRST_RESET             0x00000000u
  #define  MCASP_RGBLCTL_RFRST_ACTIVE            0x00000001u

  #define _MCASP_RGBLCTL_RSMRST_MASK              0x00000008u
  #define _MCASP_RGBLCTL_RSMRST_SHIFT             0x00000003u
  #define  MCASP_RGBLCTL_RSMRST_DEFAULT           0x00000000u
  #define  MCASP_RGBLCTL_RSMRST_OF(x)             _VALUEOF(x)
  #define  MCASP_RGBLCTL_RSMRST_RESET		      0x00000000u
  #define  MCASP_RGBLCTL_RSMRST_ACTIVE	      0x00000001u

  #define _MCASP_RGBLCTL_RSRCLR_MASK              0x00000004u
  #define _MCASP_RGBLCTL_RSRCLR_SHIFT             0x00000002u
  #define  MCASP_RGBLCTL_RSRCLR_DEFAULT           0x00000000u
  #define  MCASP_RGBLCTL_RSRCLR_OF(x)             _VALUEOF(x)
  #define  MCASP_RGBLCTL_RSRCLR_CLEAR           0x00000000u
  #define  MCASP_RGBLCTL_RSRCLR_ACTIVE            0x00000001u

  #define _MCASP_RGBLCTL_RHCLKRST_MASK              0x00000002u
  #define _MCASP_RGBLCTL_RHCLKRST_SHIFT             0x00000001u
  #define  MCASP_RGBLCTL_RHCLKRST_DEFAULT           0x00000000u
  #define  MCASP_RGBLCTL_RHCLKRST_OF(x)             _VALUEOF(x)
  #define  MCASP_RGBLCTL_RHCLKRST_RESET		    0x00000000u
  #define  MCASP_RGBLCTL_RHCLKRST_ACTIVE		    0x00000001u

  #define _MCASP_RGBLCTL_RCLKRST_MASK              0x00000001u
  #define _MCASP_RGBLCTL_RCLKRST_SHIFT             0x00000000u
  #define  MCASP_RGBLCTL_RCLKRST_DEFAULT           0x00000000u
  #define  MCASP_RGBLCTL_RCLKRST_OF(x)             _VALUEOF(x)
  #define  MCASP_RGBLCTL_RCLKRST_RESET		0x00000000u
  #define  MCASP_RGBLCTL_RCLKRST_ACTIVE		0x00000001u


  #define  MCASP_RGBLCTL_OF(x)                _VALUEOF(x)

  #define MCASP_RGBLCTL_DEFAULT (Uint32)( \
    _PER_FDEFAULT(MCASP,RGBLCTL,RFRST)\
    |_PER_FDEFAULT(MCASP,RGBLCTL,RSMRST)\
    |_PER_FDEFAULT(MCASP,RGBLCTL,RSRCLR)\
    |_PER_FDEFAULT(MCASP,RGBLCTL,RHCLKRST)\
    |_PER_FDEFAULT(MCASP,RGBLCTL,RCLKRST)\
  )


  #define MCASP_RGBLCTL_RMK(rfrst, rsmrst, rsrclr, rhclkrst, rclkrst) (Uint32)( \
    _PER_FMK(MCASP,RGBLCTL,RFRST,rfrst)\
    |_PER_FMK(MCASP,RGBLCTL,RSMRST,rsmrst)\
    |_PER_FMK(MCASP,RGBLCTL,RSRCLR,rsrclr)\
    |_PER_FMK(MCASP,RGBLCTL,RHCLKRST,rhclkrst)\
    |_PER_FMK(MCASP,RGBLCTL,RCLKRST,rclkrst)\
  )


  #define _MCASP_RGBLCTL_FGET(N,FIELD)\
    _PER_FGET(_MCASP_RGBLCTL##N##_ADDR,MCASP,RGBLCTL,##FIELD)

  #define _MCASP_RGBLCTL_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_RGBLCTL##N##_ADDR,MCASP,RGBLCTL,##FIELD,field)

  #define _MCASP_RGBLCTL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_RGBLCTL##N##_ADDR,MCASP,RGBLCTL,##FIELD,##SYM)

  #define _MCASP_RGBLCTL0_FGET(FIELD) _MCASP_RGBLCTL_FGET(0,##FIELD)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RGBLCTL1_FGET(FIELD) _MCASP_RGBLCTL_FGET(1,##FIELD)
#endif
 
  #define _MCASP_RGBLCTL0_FSET(FIELD,f) _MCASP_RGBLCTL_FSET(0,##FIELD,f)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RGBLCTL1_FSET(FIELD,f) _MCASP_RGBLCTL_FSET(1,##FIELD,f)
#endif

  #define _MCASP_RGBLCTL0_FSETS(FIELD,SYM) _MCASP_RGBLCTL_FSETS(0,##FIELD,##SYM)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RGBLCTL1_FSETS(FIELD,SYM) _MCASP_RGBLCTL_FSETS(1,##FIELD,##SYM)
#endif


/******************************************************************************\
* 
* _____________________
* |                   |
* |     RMASK         |
* |___________________|
*
* RMASK		- Pin Data Output Register
*
* FIELDS (msb -> lsb)
* (rw)  RMASKn n:0 to 31  
*
\******************************************************************************/

  #define _MCASP_RMASK_OFFSET               25

  #define _MCASP_RMASK0_ADDR				(_MCASP_BASE_PORT0+4*_MCASP_RMASK_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RMASK1_ADDR				(_MCASP_BASE_PORT1+4*_MCASP_RMASK_OFFSET)
#endif

  #define _MCASP_RMASK_RMASK0_MASK     		0x00000001u
  #define _MCASP_RMASK_RMASK0_SHIFT       	0x00000000u
  #define  MCASP_RMASK_RMASK0_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK0_OF(x)   	        _VALUEOF(x)
  #define  MCASP_RMASK_RMASK0_USEMASK	       0x00000000u
  #define  MCASP_RMASK_RMASK0_NOMASK            0x00000001u

  #define _MCASP_RMASK_RMASK1_MASK        	0x00000002u
  #define _MCASP_RMASK_RMASK1_SHIFT       	0x00000001u
  #define  MCASP_RMASK_RMASK1_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK1_OF(x)   	        _VALUEOF(x)
  #define  MCASP_RMASK_RMASK1_USEMASK	        0x00000000u
  #define  MCASP_RMASK_RMASK1_NOMASK           0x00000001u

  #define _MCASP_RMASK_RMASK2_MASK        	0x00000004u
  #define _MCASP_RMASK_RMASK2_SHIFT       	0x00000002u
  #define  MCASP_RMASK_RMASK2_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK2_OF(x)   	        _VALUEOF(x)
  #define  MCASP_RMASK_RMASK2_USEMASK	       0x00000000u
  #define  MCASP_RMASK_RMASK2_NOMASK             0x00000001u

  #define _MCASP_RMASK_RMASK3_MASK        	0x00000008u
  #define _MCASP_RMASK_RMASK3_SHIFT       	0x00000003u
  #define  MCASP_RMASK_RMASK3_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK3_OF(x)   	        _VALUEOF(x)
  #define  MCASP_RMASK_RMASK3_USEMASK	      0x00000000u
  #define  MCASP_RMASK_RMASK3_NOMASK            0x00000001u

  #define _MCASP_RMASK_RMASK4_MASK        	0x00000010u
  #define _MCASP_RMASK_RMASK4_SHIFT       	0x00000004u
  #define  MCASP_RMASK_RMASK4_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK4_OF(x)   	        _VALUEOF(x)
  #define  MCASP_RMASK_RMASK4_USEMASK	       0x00000000u
  #define  MCASP_RMASK_RMASK4_NOMASK            0x00000001u

  #define _MCASP_RMASK_RMASK5_MASK        	0x00000020u
  #define _MCASP_RMASK_RMASK5_SHIFT       	0x00000005u
  #define  MCASP_RMASK_RMASK5_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK5_OF(x)   	        _VALUEOF(x)
  #define  MCASP_RMASK_RMASK5_USEMASK	        0x00000000u
  #define  MCASP_RMASK_RMASK5_NOMASK            0x00000001u

  #define _MCASP_RMASK_RMASK6_MASK        	0x00000040u
  #define _MCASP_RMASK_RMASK6_SHIFT       	0x00000006u
  #define  MCASP_RMASK_RMASK6_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK6_OF(x)   	        _VALUEOF(x)
  #define  MCASP_RMASK_RMASK6_USEMASK	      0x00000000u
  #define  MCASP_RMASK_RMASK6_NOMASK            0x00000001u

  #define _MCASP_RMASK_RMASK7_MASK        	0x00000080u
  #define _MCASP_RMASK_RMASK7_SHIFT       	0x00000007u
  #define  MCASP_RMASK_RMASK7_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK7_OF(x)   	       _VALUEOF(x)
  #define  MCASP_RMASK_RMASK7_USEMASK	      0x00000000u
  #define  MCASP_RMASK_RMASK7_NOMASK            0x00000001u

  #define _MCASP_RMASK_RMASK8_MASK        	0x00000100u
  #define _MCASP_RMASK_RMASK8_SHIFT       	0x00000008u
  #define  MCASP_RMASK_RMASK8_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK8_OF(x)   	      _VALUEOF(x)
  #define  MCASP_RMASK_RMASK8_USEMASK	      0x00000000u
  #define  MCASP_RMASK_RMASK8_NOMASK            0x00000001u

  #define _MCASP_RMASK_RMASK9_MASK        	0x00000200u
  #define _MCASP_RMASK_RMASK9_SHIFT       	0x00000009u
  #define  MCASP_RMASK_RMASK9_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK9_OF(x)   	      _VALUEOF(x)
  #define  MCASP_RMASK_RMASK9_USEMASK	      0x00000000u
  #define  MCASP_RMASK_RMASK9_NOMASK            0x00000001u

  #define _MCASP_RMASK_RMASK10_MASK        	0x00000400u
  #define _MCASP_RMASK_RMASK10_SHIFT       	0x0000000Au
  #define  MCASP_RMASK_RMASK10_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK10_OF(x)   	      _VALUEOF(x)
  #define  MCASP_RMASK_RMASK10_USEMASK        	0x00000000u
  #define  MCASP_RMASK_RMASK10_NOMASK           0x00000001u

  #define _MCASP_RMASK_RMASK11_MASK        	0x00000800u
  #define _MCASP_RMASK_RMASK11_SHIFT       	0x0000000Bu
  #define  MCASP_RMASK_RMASK11_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK11_OF(x)   	      _VALUEOF(x)
  #define  MCASP_RMASK_RMASK11_USEMASK	      0x00000000u
  #define  MCASP_RMASK_RMASK11_NOMASK           0x00000001u

  #define _MCASP_RMASK_RMASK12_MASK        	0x00001000u
  #define _MCASP_RMASK_RMASK12_SHIFT       	0x0000000Cu
  #define  MCASP_RMASK_RMASK12_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK12_OF(x)   	      _VALUEOF(x)
  #define  MCASP_RMASK_RMASK12_USEMASK        	0x00000000u
  #define  MCASP_RMASK_RMASK12_NOMASK           0x00000001u

  #define _MCASP_RMASK_RMASK13_MASK        	0x00002000u
  #define _MCASP_RMASK_RMASK13_SHIFT       	0x0000000Du
  #define  MCASP_RMASK_RMASK13_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK13_OF(x)   	      _VALUEOF(x)
  #define  MCASP_RMASK_RMASK13_USEMASK        	0x00000000u
  #define  MCASP_RMASK_RMASK13_NOMASK           0x00000001u

  #define _MCASP_RMASK_RMASK14_MASK        	0x00004000u
  #define _MCASP_RMASK_RMASK14_SHIFT       	0x0000000Eu
  #define  MCASP_RMASK_RMASK14_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK14_OF(x)   	      _VALUEOF(x)
  #define  MCASP_RMASK_RMASK14_USEMASK        	0x00000000u
  #define  MCASP_RMASK_RMASK14_NOMASK           0x00000001u

  #define _MCASP_RMASK_RMASK15_MASK        	0x00008000u
  #define _MCASP_RMASK_RMASK15_SHIFT       	0x0000000Fu
  #define  MCASP_RMASK_RMASK15_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK15_OF(x)   	      _VALUEOF(x)
  #define  MCASP_RMASK_RMASK15_USEMASK        	0x00000000u
  #define  MCASP_RMASK_RMASK15_NOMASK           0x00000001u

  #define _MCASP_RMASK_RMASK16_MASK        	0x00010000u
  #define _MCASP_RMASK_RMASK16_SHIFT       	0x00000010u
  #define  MCASP_RMASK_RMASK16_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK16_OF(x)   	      _VALUEOF(x)
  #define  MCASP_RMASK_RMASK16_USEMASK        	0x00000000u
  #define  MCASP_RMASK_RMASK16_NOMASK           0x00000001u

  #define _MCASP_RMASK_RMASK17_MASK        	0x00020000u
  #define _MCASP_RMASK_RMASK17_SHIFT       	0x00000011u
  #define  MCASP_RMASK_RMASK17_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK17_OF(x)   	      _VALUEOF(x)
  #define  MCASP_RMASK_RMASK17_USEMASK        	0x00000000u
  #define  MCASP_RMASK_RMASK17_NOMASK           0x00000001u

  #define _MCASP_RMASK_RMASK18_MASK        	0x00040000u
  #define _MCASP_RMASK_RMASK18_SHIFT       	0x00000012u
  #define  MCASP_RMASK_RMASK18_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK18_OF(x)   	      _VALUEOF(x)
  #define  MCASP_RMASK_RMASK18_USEMASK        	0x00000000u
  #define  MCASP_RMASK_RMASK18_NOMASK           0x00000001u

  #define _MCASP_RMASK_RMASK19_MASK        	0x00080000u
  #define _MCASP_RMASK_RMASK19_SHIFT       	0x00000013u
  #define  MCASP_RMASK_RMASK19_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK19_OF(x)   	      _VALUEOF(x)
  #define  MCASP_RMASK_RMASK19_USEMASK        	0x00000000u
  #define  MCASP_RMASK_RMASK19_NOMASK           0x00000001u

  #define _MCASP_RMASK_RMASK20_MASK        	0x00100000u
  #define _MCASP_RMASK_RMASK20_SHIFT       	0x00000014u
  #define  MCASP_RMASK_RMASK20_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK20_OF(x)   	      _VALUEOF(x)
  #define  MCASP_RMASK_RMASK20_USEMASK        	0x00000000u
  #define  MCASP_RMASK_RMASK20_NOMASK           0x00000001u

  #define _MCASP_RMASK_RMASK21_MASK        	0x00200000u
  #define _MCASP_RMASK_RMASK21_SHIFT       	0x00000015u
  #define  MCASP_RMASK_RMASK21_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK21_OF(x)   	      _VALUEOF(x)
  #define  MCASP_RMASK_RMASK21_USEMASK        	0x00000000u
  #define  MCASP_RMASK_RMASK21_NOMASK           0x00000001u

  #define _MCASP_RMASK_RMASK22_MASK        	0x00400000u
  #define _MCASP_RMASK_RMASK22_SHIFT       	0x00000016u
  #define  MCASP_RMASK_RMASK22_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK22_OF(x)   	      _VALUEOF(x)
  #define  MCASP_RMASK_RMASK22_USEMASK        	0x00000000u
  #define  MCASP_RMASK_RMASK22_NOMASK           0x00000001u

  #define _MCASP_RMASK_RMASK23_MASK        	0x00800000u
  #define _MCASP_RMASK_RMASK23_SHIFT       	0x00000017u
  #define  MCASP_RMASK_RMASK23_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK23_OF(x)   	      _VALUEOF(x)
  #define  MCASP_RMASK_RMASK23_USEMASK        	0x00000000u
  #define  MCASP_RMASK_RMASK23_NOMASK           0x00000001u

  #define _MCASP_RMASK_RMASK24_MASK        	0x01000000u
  #define _MCASP_RMASK_RMASK24_SHIFT       	0x00000018u
  #define  MCASP_RMASK_RMASK24_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK24_OF(x)   	      _VALUEOF(x)
  #define  MCASP_RMASK_RMASK24_USEMASK        	0x00000000u
  #define  MCASP_RMASK_RMASK24_NOMASK           0x00000001u

  #define _MCASP_RMASK_RMASK25_MASK        	0x02000000u
  #define _MCASP_RMASK_RMASK25_SHIFT       	0x00000019u
  #define  MCASP_RMASK_RMASK25_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK25_OF(x)   	      _VALUEOF(x)
  #define  MCASP_RMASK_RMASK25_USEMASK        	0x00000000u
  #define  MCASP_RMASK_RMASK25_NOMASK           0x00000001u

  #define _MCASP_RMASK_RMASK26_MASK        	0x04000000u
  #define _MCASP_RMASK_RMASK26_SHIFT       	0x0000001Au
  #define  MCASP_RMASK_RMASK26_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK26_OF(x)   	      _VALUEOF(x)
  #define  MCASP_RMASK_RMASK26_USEMASK        	0x00000000u
  #define  MCASP_RMASK_RMASK26_NOMASK           0x00000001u

  #define _MCASP_RMASK_RMASK27_MASK        	0x08000000u
  #define _MCASP_RMASK_RMASK27_SHIFT       	0x0000001Bu
  #define  MCASP_RMASK_RMASK27_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK27_OF(x)   	        _VALUEOF(x)
  #define  MCASP_RMASK_RMASK27_USEMASK        	0x00000000u
  #define  MCASP_RMASK_RMASK27_NOMASK           0x00000001u

  #define _MCASP_RMASK_RMASK28_MASK        	0x10000000u
  #define _MCASP_RMASK_RMASK28_SHIFT       	0x0000001Cu
  #define  MCASP_RMASK_RMASK28_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK28_OF(x)   	        _VALUEOF(x)
  #define  MCASP_RMASK_RMASK28_USEMASK        	0x00000000u
  #define  MCASP_RMASK_RMASK28_NOMASK           0x00000001u

  #define _MCASP_RMASK_RMASK29_MASK        	0x20000000u
  #define _MCASP_RMASK_RMASK29_SHIFT       	0x0000001Du
  #define  MCASP_RMASK_RMASK29_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK29_OF(x)   	        _VALUEOF(x)
  #define  MCASP_RMASK_RMASK29_USEMASK        	0x00000000u
  #define  MCASP_RMASK_RMASK29_NOMASK           0x00000001u

  #define _MCASP_RMASK_RMASK30_MASK        	0x40000000u
  #define _MCASP_RMASK_RMASK30_SHIFT       	0x0000001Eu
  #define  MCASP_RMASK_RMASK30_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK30_OF(x)   	        _VALUEOF(x)
  #define  MCASP_RMASK_RMASK30_USEMASK        	0x00000000u
  #define  MCASP_RMASK_RMASK30_NOMASK           0x00000001u

  #define _MCASP_RMASK_RMASK31_MASK        	0x80000000u
  #define _MCASP_RMASK_RMASK31_SHIFT       	0x0000001Fu
  #define  MCASP_RMASK_RMASK31_DEFAULT     	0x00000000u
  #define  MCASP_RMASK_RMASK31_OF(x)   	        _VALUEOF(x)
  #define  MCASP_RMASK_RMASK31_USEMASK        	0x00000000u
  #define  MCASP_RMASK_RMASK31_NOMASK           0x00000001u



  #define  MCASP_RMASK_OF(x)                	_VALUEOF(x)

  #define MCASP_RMASK_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,RMASK,RMASK0)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK1)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK2)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK3)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK4)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK5)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK6)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK7)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK8)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK9)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK10)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK11)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK12)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK13)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK14)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK15)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK16)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK17)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK18)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK19)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK20)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK21)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK22)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK23)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK24)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK25)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK26)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK27)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK28)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK29)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK30)\
    |_PER_FDEFAULT(MCASP,RMASK,RMASK31)\
  )

  #define MCASP_RMASK_RMK(rmask31, rmask30,rmask29,rmask28,rmask27,rmask26,rmask25,\
    rmask24,rmask23,rmask22,rmask21,rmask20,rmask19,rmask18,rmask17,\
   rmask16,rmask15,rmask14,rmask13,rmask12,rmask11,rmask10,rmask9,\
   rmask8, rmask7, rmask6,  rmask5,rmask4, rmask3, rmask2, rmask1, rmask0 ) \
(Uint32)( \
     _PER_FMK(MCASP,RMASK,RMASK0,rmask0)\
    |_PER_FMK(MCASP,RMASK,RMASK1,rmask1)\
    |_PER_FMK(MCASP,RMASK,RMASK2,rmask2)\
    |_PER_FMK(MCASP,RMASK,RMASK3,rmask3)\
    |_PER_FMK(MCASP,RMASK,RMASK4,rmask4)\
    |_PER_FMK(MCASP,RMASK,RMASK5,rmask5)\
    |_PER_FMK(MCASP,RMASK,RMASK6,rmask6)\
    |_PER_FMK(MCASP,RMASK,RMASK7,rmask7)\
    |_PER_FMK(MCASP,RMASK,RMASK8,rmask8)\
    |_PER_FMK(MCASP,RMASK,RMASK9,rmask9)\
    |_PER_FMK(MCASP,RMASK,RMASK10,rmask10)\
    |_PER_FMK(MCASP,RMASK,RMASK11,rmask11)\
    |_PER_FMK(MCASP,RMASK,RMASK12,rmask12)\
    |_PER_FMK(MCASP,RMASK,RMASK13,rmask13)\
    |_PER_FMK(MCASP,RMASK,RMASK14,rmask14)\
    |_PER_FMK(MCASP,RMASK,RMASK15,rmask15)\
    |_PER_FMK(MCASP,RMASK,RMASK16,rmask16)\
    |_PER_FMK(MCASP,RMASK,RMASK17,rmask17)\
    |_PER_FMK(MCASP,RMASK,RMASK18,rmask18)\
    |_PER_FMK(MCASP,RMASK,RMASK19,rmask19)\
    |_PER_FMK(MCASP,RMASK,RMASK20,rmask20)\
    |_PER_FMK(MCASP,RMASK,RMASK21,rmask21)\
    |_PER_FMK(MCASP,RMASK,RMASK22,rmask22)\
    |_PER_FMK(MCASP,RMASK,RMASK23,rmask23)\
    |_PER_FMK(MCASP,RMASK,RMASK24,rmask24)\
    |_PER_FMK(MCASP,RMASK,RMASK25,rmask25)\
    |_PER_FMK(MCASP,RMASK,RMASK26,rmask26)\
    |_PER_FMK(MCASP,RMASK,RMASK27,rmask27)\
    |_PER_FMK(MCASP,RMASK,RMASK28,rmask28)\
    |_PER_FMK(MCASP,RMASK,RMASK29,rmask29)\
    |_PER_FMK(MCASP,RMASK,RMASK30,rmask30)\
    |_PER_FMK(MCASP,RMASK,RMASK31,rmask31)\
  )

  #define _MCASP_RMASK_FGET(N,FIELD)\
    _PER_FGET(_MCASP_RMASK##N##_ADDR,MCASP,RMASK,##FIELD)

  #define _MCASP_RMASK_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_RMASK##N##_ADDR,MCASP,RMASK,##FIELD,field)

  #define _MCASP_RMASK_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_RMASK##N##_ADDR,MCASP,RMASK,##FIELD,##SYM)

  #define _MCASP_RMASK0_FGET(FIELD) _MCASP_RMASK_FGET(0,##FIELD)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RMASK1_FGET(FIELD) _MCASP_RMASK_FGET(1,##FIELD)
#endif
 
  #define _MCASP_RMASK0_FSET(FIELD,f) _MCASP_RMASK_FSET(0,##FIELD,f)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RMASK1_FSET(FIELD,f) _MCASP_RMASK_FSET(1,##FIELD,f)
#endif

  #define _MCASP_RMASK0_FSETS(FIELD,SYM) _MCASP_RMASK_FSETS(0,##FIELD,##SYM)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RMASK1_FSETS(FIELD,SYM) _MCASP_RMASK_FSETS(1,##FIELD,##SYM)
#endif


/******************************************************************************\
* 
* _____________________
* |                   |
* |     RFMT          |
* |___________________|
*
* RFMT		- Receive Bitstream Format Register
*
* FIELDS (msb -> lsb)
* (rw)  RDATDLY
* (rw)  RRVRS  
* (rw)  RPAD
* (rw)  RPBIT  
* (rw)  RSSZ
* (rw)  RBUSEL
* (rw)  RROT  
*
\******************************************************************************/

  #define _MCASP_RFMT_OFFSET               26

  #define _MCASP_RFMT0_ADDR					(_MCASP_BASE_PORT0+4*_MCASP_RFMT_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RFMT1_ADDR					(_MCASP_BASE_PORT1+4*_MCASP_RFMT_OFFSET)
#endif

  #define _MCASP_RFMT_RDATDLY_MASK              0x00030000u
  #define _MCASP_RFMT_RDATDLY_SHIFT             0x00000010u
  #define  MCASP_RFMT_RDATDLY_DEFAULT           0x00000000u
  #define  MCASP_RFMT_RDATDLY_OF(x)             _VALUEOF(x)
  #define  MCASP_RFMT_RDATDLY_0BIT              0x00000000u
  #define  MCASP_RFMT_RDATDLY_1BIT              0x00000001u
  #define  MCASP_RFMT_RDATDLY_2BIT              0x00000002u


  #define _MCASP_RFMT_RRVRS_MASK        	      0x00008000u
  #define _MCASP_RFMT_RRVRS_SHIFT       	      0x0000000Fu
  #define  MCASP_RFMT_RRVRS_DEFAULT             0x00000000u
  #define  MCASP_RFMT_RRVRS_OF(x)   	        _VALUEOF(x)
  #define  MCASP_RFMT_RRVRS_LSBFIRST            0x00000000u
  #define  MCASP_RFMT_RRVRS_MSBFIRST            0x00000001u

  #define _MCASP_RFMT_RPAD_MASK     		0x00006000u
  #define _MCASP_RFMT_RPAD_SHIFT          	0x0000000Du
  #define  MCASP_RFMT_RPAD_DEFAULT        	0x00000000u
  #define  MCASP_RFMT_RPAD_OF(x)          	_VALUEOF(x)
  #define  MCASP_RFMT_RPAD_ZERO            	0x00000000u
  #define  MCASP_RFMT_RPAD_ONE            	0x00000001u
  #define  MCASP_RFMT_RPAD_RPBIT          	0x00000002u

  #define _MCASP_RFMT_RPBIT_MASK           	0x00001F00u
  #define _MCASP_RFMT_RPBIT_SHIFT          	0x00000008u
  #define  MCASP_RFMT_RPBIT_DEFAULT        	0x00000000u
  #define  MCASP_RFMT_RPBIT_OF(x)          	_VALUEOF(x)

  #define _MCASP_RFMT_RSSZ_MASK           	0x000000F0u
  #define _MCASP_RFMT_RSSZ_SHIFT          	0x00000004u
  #define  MCASP_RFMT_RSSZ_DEFAULT        	0x00000000u
  #define  MCASP_RFMT_RSSZ_OF(x)          	_VALUEOF(x)
  #define  MCASP_RFMT_RSSZ_8BITS            	0x00000003u
  #define  MCASP_RFMT_RSSZ_12BITS            	0x00000005u
  #define  MCASP_RFMT_RSSZ_16BITS            	0x00000007u
  #define  MCASP_RFMT_RSSZ_20BITS            	0x00000009u
  #define  MCASP_RFMT_RSSZ_24BITS            	0x0000000Bu
  #define  MCASP_RFMT_RSSZ_28BITS            	0x0000000Du
  #define  MCASP_RFMT_RSSZ_32BITS            	0x0000000Fu

  #define _MCASP_RFMT_RBUSEL_MASK           	0x00000008u
  #define _MCASP_RFMT_RBUSEL_SHIFT          	0x00000003u
  #define  MCASP_RFMT_RBUSEL_DEFAULT        	0x00000000u
  #define  MCASP_RFMT_RBUSEL_OF(x)         	_VALUEOF(x)
  #define  MCASP_RFMT_RBUSEL_DAT            	0x00000000u
  #define  MCASP_RFMT_RBUSEL_CFG            	0x00000001u


  #define _MCASP_RFMT_RROT_MASK           	0x00000007u
  #define _MCASP_RFMT_RROT_SHIFT          	0x00000000u
  #define  MCASP_RFMT_RROT_DEFAULT        	0x00000000u
  #define  MCASP_RFMT_RROT_OF(x)         	_VALUEOF(x)
  #define  MCASP_RFMT_RROT_NONE            	0x00000000u
  #define  MCASP_RFMT_RROT_4BITS            	0x00000001u
  #define  MCASP_RFMT_RROT_8BITS            	0x00000002u
  #define  MCASP_RFMT_RROT_12BITS            	0x00000003u
  #define  MCASP_RFMT_RROT_16BITS            	0x00000004u
  #define  MCASP_RFMT_RROT_20BITS            	0x00000005u
  #define  MCASP_RFMT_RROT_24BITS            	0x00000006u
  #define  MCASP_RFMT_RROT_28BITS            	0x00000007u

  #define  MCASP_RFMT_OF(x)                	_VALUEOF(x)

  #define MCASP_RFMT_DEFAULT (Uint32)( \
  	 _PER_FDEFAULT(MCASP,RFMT,RDATDLY)\
    |_PER_FDEFAULT(MCASP,RFMT,RRVRS)\
    |_PER_FDEFAULT(MCASP,RFMT,RPAD)\
    |_PER_FDEFAULT(MCASP,RFMT,RPBIT)\
    |_PER_FDEFAULT(MCASP,RFMT,RSSZ)\
    |_PER_FDEFAULT(MCASP,RFMT,RBUSEL)\
    |_PER_FDEFAULT(MCASP,RFMT,RROT)\
    )

  #define MCASP_RFMT_RMK(rdatdly,rrvrs,rpad,rpbit,rssz,rbusel,rrot) (Uint32)( \
     _PER_FMK(MCASP,RFMT,RDATDLY,rdatdly)\
    |_PER_FMK(MCASP,RFMT,RRVRS,rrvrs)\
    |_PER_FMK(MCASP,RFMT,RPAD,rpad)\
    |_PER_FMK(MCASP,RFMT,RPBIT,rpbit)\
    |_PER_FMK(MCASP,RFMT,RSSZ,rssz)\
    |_PER_FMK(MCASP,RFMT,RBUSEL,rbusel)\
    |_PER_FMK(MCASP,RFMT,RROT,rrot)\
  )

  #define _MCASP_RFMT_FGET(N,FIELD)\
    _PER_FGET(_MCASP_RFMT##N##_ADDR,MCASP,RFMT,##FIELD)

  #define _MCASP_RFMT_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_RFMT##N##_ADDR,MCASP,RFMT,##FIELD,field)

  #define _MCASP_RFMT_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_RFMT##N##_ADDR,MCASP,RFMT,##FIELD,##SYM)

  #define _MCASP_RFMT0_FGET(FIELD) _MCASP_RFMT_FGET(0,##FIELD)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RFMT1_FGET(FIELD) _MCASP_RFMT_FGET(1,##FIELD)
#endif
 
  #define _MCASP_RFMT0_FSET(FIELD,f) _MCASP_RFMT_FSET(0,##FIELD,f)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RFMT1_FSET(FIELD,f) _MCASP_RFMT_FSET(1,##FIELD,f)
#endif

  #define _MCASP_RFMT0_FSETS(FIELD,SYM) _MCASP_RFMT_FSETS(0,##FIELD,##SYM)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RFMT1_FSETS(FIELD,SYM) _MCASP_RFMT_FSETS(1,##FIELD,##SYM)
#endif


/******************************************************************************\
* 
* _____________________
* |                   |
* |     AFSRCTL       |
* |___________________|
*
* AFSRCTL  -  Receive Frame Control Register
*
* FIELDS (msb -> lsb)
* (rw)  RMOD
* (rw)  FRWID
* (rw)  FSRM
* (rw)  FSRP
*
\******************************************************************************/

  #define _MCASP_AFSRCTL_OFFSET               27

  #define _MCASP_AFSRCTL0_ADDR				(_MCASP_BASE_PORT0+4*_MCASP_AFSRCTL_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_AFSRCTL1_ADDR				(_MCASP_BASE_PORT1+4*_MCASP_AFSRCTL_OFFSET)
#endif

  #define _MCASP_AFSRCTL_RMOD_MASK              0x0000FF80u
  #define _MCASP_AFSRCTL_RMOD_SHIFT             0x00000007u
  #define  MCASP_AFSRCTL_RMOD_DEFAULT           0x00000000u
  #define  MCASP_AFSRCTL_RMOD_OF(x)             _VALUEOF(x)
  #define  MCASP_AFSRCTL_RMOD_BURST             0x00000000u

  #define _MCASP_AFSRCTL_FRWID_MASK              0x00000010u
  #define _MCASP_AFSRCTL_FRWID_SHIFT             0x00000004u
  #define  MCASP_AFSRCTL_FRWID_DEFAULT           0x00000000u
  #define  MCASP_AFSRCTL_FRWID_OF(x)             _VALUEOF(x)
  #define  MCASP_AFSRCTL_FRWID_BIT               0x00000000u
  #define  MCASP_AFSRCTL_FRWID_WORD             0x00000001u
  

  #define _MCASP_AFSRCTL_FSRM_MASK              0x00000002u
  #define _MCASP_AFSRCTL_FSRM_SHIFT             0x00000001u
  #define  MCASP_AFSRCTL_FSRM_DEFAULT           0x00000000u
  #define  MCASP_AFSRCTL_FSRM_OF(x)             _VALUEOF(x)
  #define  MCASP_AFSRCTL_FSRM_EXTERNAL          0x00000000u
  #define  MCASP_AFSRCTL_FSRM_INTERNAL          0x00000001u
  

  #define _MCASP_AFSRCTL_FSRP_MASK              0x00000001u
  #define _MCASP_AFSRCTL_FSRP_SHIFT             0x00000000u
  #define  MCASP_AFSRCTL_FSRP_DEFAULT           0x00000000u
  #define  MCASP_AFSRCTL_FSRP_OF(x)             _VALUEOF(x)
  #define  MCASP_AFSRCTL_FSRP_ACTIVEHIGH        0x00000000u
  #define  MCASP_AFSRCTL_FSRP_ACTIVELOW         0x00000001u
  

  #define  MCASP_AFSRCTL_OF(x)                _VALUEOF(x)

  #define MCASP_AFSRCTL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,AFSRCTL,RMOD)\
	| _PER_FDEFAULT(MCASP,AFSRCTL,FRWID)\
	| _PER_FDEFAULT(MCASP,AFSRCTL,FSRM)\
	| _PER_FDEFAULT(MCASP,AFSRCTL,FSRP)\
  )

  #define MCASP_AFSRCTL_RMK(rmod, frwid, fsrm, fsrp) (Uint32)( \
     _PER_FMK(MCASP,AFSRCTL,RMOD,rmod)\
	| _PER_FMK(MCASP,AFSRCTL,FRWID,frwid)\
	| _PER_FMK(MCASP,AFSRCTL,FSRM,fsrm)\
	| _PER_FMK(MCASP,AFSRCTL,FSRP,fsrp)\
  )

  #define _MCASP_AFSRCTL_FGET(N,FIELD)\
    _PER_FGET(_MCASP_AFSRCTL##N##_ADDR,MCASP,AFSRCTL,##FIELD)

  #define _MCASP_AFSRCTL_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_AFSRCTL##N##_ADDR,MCASP,AFSRCTL,##FIELD,field)

  #define _MCASP_AFSRCTL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCAS_AFSRCTL##N##_ADDR,MCASP,AFSRCTL,##FIELD,##SYM)

  #define _MCASP_AFSRCTL0_FGET(FIELD) _MCASP_AFSRCTL_FGET(0,##FIELD)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_AFSRCTL1_FGET(FIELD) _MCASP_AFSRCTL_FGET(1,##FIELD)
#endif
 
  #define _MCASP_AFSRCTL0_FSET(FIELD,f) _MCASP_AFSRCTL_FSET(0,##FIELD,f)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_AFSRCTL1_FSET(FIELD,f) _MCASP_AFSRCTL_FSET(1,##FIELD,f)
#endif

  #define _MCASP_AFSRCTL0_FSETS(FIELD,SYM) _MCASP_AFSRCTL_FSETS(0,##FIELD,##SYM)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_AFSRCTL1_FSETS(FIELD,SYM) _MCASP_AFSRCTL_FSETS(1,##FIELD,##SYM)
#endif


/******************************************************************************\
* 
* _____________________
* |                   |
* |     ACLKRCTL      |
* |___________________|
*
* ACLKRCTL  -  Receive Clock Control Register
*
*  FIELDS (msb -> lsb)
* (rw)  CLKRP  
* (rw)  CLKRM  
* (rw)  CLKRDIV
*
\******************************************************************************/

  #define _MCASP_ACLKRCTL_OFFSET               28

  #define _MCASP_ACLKRCTL0_ADDR				(_MCASP_BASE_PORT0+4*_MCASP_ACLKRCTL_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_ACLKRCTL1_ADDR				(_MCASP_BASE_PORT1+4*_MCASP_ACLKRCTL_OFFSET)
#endif

  #define _MCASP_ACLKRCTL_CLKRP_MASK              0x00000080u
  #define _MCASP_ACLKRCTL_CLKRP_SHIFT             0x00000007u
  #define  MCASP_ACLKRCTL_CLKRP_DEFAULT           0x00000000u
  #define  MCASP_ACLKRCTL_CLKRP_OF(x)             _VALUEOF(x)
  #define  MCASP_ACLKRCTL_CLKRP_RISING            0x00000001u
  #define  MCASP_ACLKRCTL_CLKRP_FALLING           0x00000000u
  

  #define _MCASP_ACLKRCTL_CLKRM_MASK              0x00000020u
  #define _MCASP_ACLKRCTL_CLKRM_SHIFT             0x00000005u
  #define  MCASP_ACLKRCTL_CLKRM_DEFAULT           0x00000001u
  #define  MCASP_ACLKRCTL_CLKRM_OF(x)             _VALUEOF(x)
  #define  MCASP_ACLKRCTL_CLKRM_EXTERNAL            0x00000000u
  #define  MCASP_ACLKRCTL_CLKRM_INTERNAL            0x00000001u
  

  #define _MCASP_ACLKRCTL_CLKRDIV_MASK              0x0000001Fu
  #define _MCASP_ACLKRCTL_CLKRDIV_SHIFT             0x00000000u
  #define  MCASP_ACLKRCTL_CLKRDIV_DEFAULT           0x00000000u
  #define  MCASP_ACLKRCTL_CLKRDIV_OF(x)             _VALUEOF(x)

  #define  MCASP_ACLKRCTL_OF(x)                _VALUEOF(x)

  #define MCASP_ACLKRCTL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,ACLKRCTL,CLKRP)\
	| _PER_FDEFAULT(MCASP,ACLKRCTL,CLKRM)\
	| _PER_FDEFAULT(MCASP,ACLKRCTL,CLKRDIV)\
  )

  #define MCASP_ACLKRCTL_RMK(clkrp, clkrm, clkrdiv) (Uint32)( \
     _PER_FMK(MCASP,ACLKRCTL,CLKRP,clkrp)\
	| _PER_FMK(MCASP,ACLKRCTL,CLKRM,clkrm)\
	| _PER_FMK(MCASP,ACLKRCTL,CLKRDIV,clkrdiv)\
  )


  #define _MCASP_ACLKRCTL_FGET(N,FIELD)\
    _PER_FGET(_MCASP_ACLKRCTL##N##_ADDR,MCASP,ACLKRCTL,##FIELD)

  #define _MCASP_ACLKRCTL_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_ACLKRCTL##N##_ADDR,MCASP,ACLKRCTL,##FIELD,field)

  #define _MCASP_ACLKRCTL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_ACLKRCTL##N##_ADDR,MCASP,ACLKRCTL,##FIELD,##SYM)

  #define _MCASP_ACLKRCTL0_FGET(FIELD) _MCASP_ACLKRCTL_FGET(0,##FIELD)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_ACLKRCTL1_FGET(FIELD) _MCASP_ACLKRCTL_FGET(1,##FIELD)
#endif

  #define _MCASP_ACLKRCTL0_FSET(FIELD,f) _MCASP_ACLKRCTL_FSET(0,##FIELD,f)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_ACLKRCTL1_FSET(FIELD,f) _MCASP_ACLKRCTL_FSET(1,##FIELD,f)
#endif

  #define _MCASP_ACLKRCTL0_FSETS(FIELD,SYM) _MCASP_ACLKRCTL_FSETS(0,##FIELD,##SYM)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_ACLKRCTL1_FSETS(FIELD,SYM) _MCASP_ACLKRCTL_FSETS(1,##FIELD,##SYM)
#endif


/******************************************************************************\
* 
* _____________________
* |                   |
* |     AHCLKRCTL     |
* |___________________|
*
* AHCLKRCTL  -  High Frequency Receive Clock Control Register
*
* FIELDS (msb -> lsb)
* (rw)  HCLKRM 
* (rw)  HCLKRP
* (rw)  HCLKRDIV 
*
\******************************************************************************/

  #define _MCASP_AHCLKRCTL_OFFSET                   29

  #define _MCASP_AHCLKRCTL0_ADDR	  	    (_MCASP_BASE_PORT0+4*_MCASP_AHCLKRCTL_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_AHCLKRCTL1_ADDR		    (_MCASP_BASE_PORT1+4*_MCASP_AHCLKRCTL_OFFSET)
#endif
 
  #define _MCASP_AHCLKRCTL_HCLKRM_MASK              0x00008000u
  #define _MCASP_AHCLKRCTL_HCLKRM_SHIFT             0x0000000Fu
  #define  MCASP_AHCLKRCTL_HCLKRM_DEFAULT           0x00000001u
  #define  MCASP_AHCLKRCTL_HCLKRM_OF(x)             _VALUEOF(x)
  #define  MCASP_AHCLKRCTL_HCLKRM_EXTERNAL          0x00000000u
  #define  MCASP_AHCLKRCTL_HCLKRM_INTERNAL     	    0x00000001u

  #define _MCASP_AHCLKRCTL_HCLKRP_MASK              0x00004000u
  #define _MCASP_AHCLKRCTL_HCLKRP_SHIFT             0x0000000Eu
  #define  MCASP_AHCLKRCTL_HCLKRP_DEFAULT           0x00000000u
  #define  MCASP_AHCLKRCTL_HCLKRP_OF(x)             _VALUEOF(x)
  #define  MCASP_AHCLKRCTL_HCLKRP_RISING            0x00000000u
  #define  MCASP_AHCLKRCTL_HCLKRP_FALLING           0x00000001u

  #define _MCASP_AHCLKRCTL_HCLKRDIV_MASK            0x00000FFFu
  #define _MCASP_AHCLKRCTL_HCLKRDIV_SHIFT           0x00000000u
  #define  MCASP_AHCLKRCTL_HCLKRDIV_DEFAULT         0x00000000u
  #define  MCASP_AHCLKRCTL_HCLKRDIV_OF(x)           _VALUEOF(x)


  #define  MCASP_AHCLKRCTL_OF(x)                _VALUEOF(x)

  #define MCASP_AHCLKRCTL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,AHCLKRCTL,HCLKRM)\
    | _PER_FDEFAULT(MCASP,AHCLKRCTL,HCLKRP)\
	| _PER_FDEFAULT(MCASP,AHCLKRCTL,HCLKRDIV)\
  )

  #define MCASP_AHCLKRCTL_RMK(hclkrm, hclkrp, hclkrdiv) (Uint32)( \
     _PER_FMK(MCASP,AHCLKRCTL,HCLKRM,hclkrm)\
	| _PER_FMK(MCASP,AHCLKRCTL,HCLKRP,hclkrp)\
	| _PER_FMK(MCASP,AHCLKRCTL,HCLKRDIV,hclkrdiv)\
  )

  #define _MCASP_AHCLKRCTL_FGET(N,FIELD)\
    _PER_FGET(_MCASP_AHCLKRCTL##N##_ADDR,MCASP,AHCLKRCTL,##FIELD)

  #define _MCASP_AHCLKRCTL_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_AHCLKRCTL##N##_ADDR,MCASP,AHCLKRCTL,##FIELD,field)

  #define _MCASP_AHCLKRCTL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_AHCLKRCTL##N##_ADDR,MCASP,AHCLKRCTL,##FIELD,##SYM)

 #define _MCASP_AHCLKRCTL0_FGET(FIELD) _MCASP_AHCLKRCTL_FGET(0,##FIELD)
#if (_MCASP_PORT_CNT > 1)
 #define _MCASP_AHCLKRCTL1_FGET(FIELD) _MCASP_AHCLKRCTL_FGET(1,##FIELD)
#endif

  #define _MCASP_AHCLKRCTL0_FSET(FIELD,f) _MCASP_AHCLKRCTL_FSET(0,##FIELD,f)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_AHCLKRCTL1_FSET(FIELD,f) _MCASP_AHCLKRCTL_FSET(1,##FIELD,f)
#endif

  #define _MCASP_AHCLKRCTL0_FSETS(FIELD,SYM) _MCASP_AHCLKRCTL_FSETS(0,##FIELD,##SYM)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_AHCLKRCTL1_FSETS(FIELD,SYM) _MCASP_AHCLKRCTL_FSETS(1,##FIELD,##SYM)
#endif

/******************************************************************************\
* 
* _____________________
* |                   |
* |    R  T  D  M     |
* |___________________|
*
* RTDM  -  Receive TDM register
*
* FIELDS (msb -> lsb)
* (rw)  RTDMS0
* (rw)  RTDMS1
*   .
*   .
*   .
* (rw)  RTDMS31
*
\******************************************************************************/

  #define _MCASP_RTDM_OFFSET               30

  #define _MCASP_RTDM0_ADDR			(_MCASP_BASE_PORT0+4*_MCASP_RTDM_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RTDM1_ADDR			(_MCASP_BASE_PORT1+4*_MCASP_RTDM_OFFSET)
#endif

  #define _MCASP_RTDM_RTDMS31_MASK              0x80000000u
  #define _MCASP_RTDM_RTDMS31_SHIFT             0x0000001Fu
  #define  MCASP_RTDM_RTDMS31_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS31_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS31_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS31_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS30_MASK              0x40000000u
  #define _MCASP_RTDM_RTDMS30_SHIFT             0x0000001Eu
  #define  MCASP_RTDM_RTDMS30_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS30_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS30_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS30_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS29_MASK              0x20000000u
  #define _MCASP_RTDM_RTDMS29_SHIFT             0x0000001Du
  #define  MCASP_RTDM_RTDMS29_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS29_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS29_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS29_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS28_MASK              0x10000000u
  #define _MCASP_RTDM_RTDMS28_SHIFT             0x0000001Cu
  #define  MCASP_RTDM_RTDMS28_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS28_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS28_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS28_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS27_MASK              0x08000000u
  #define _MCASP_RTDM_RTDMS27_SHIFT             0x0000001Bu
  #define  MCASP_RTDM_RTDMS27_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS27_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS27_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS27_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS26_MASK              0x04000000u
  #define _MCASP_RTDM_RTDMS26_SHIFT             0x0000001Au
  #define  MCASP_RTDM_RTDMS26_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS26_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS26_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS26_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS25_MASK              0x02000000u
  #define _MCASP_RTDM_RTDMS25_SHIFT             0x00000019u
  #define  MCASP_RTDM_RTDMS25_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS25_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS25_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS25_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS24_MASK              0x01000000u
  #define _MCASP_RTDM_RTDMS24_SHIFT             0x00000018u
  #define  MCASP_RTDM_RTDMS24_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS24_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS24_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS24_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS23_MASK              0x00800000u
  #define _MCASP_RTDM_RTDMS23_SHIFT             0x00000017u
  #define  MCASP_RTDM_RTDMS23_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS23_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS23_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS23_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS22_MASK              0x00400000u
  #define _MCASP_RTDM_RTDMS22_SHIFT             0x00000016u
  #define  MCASP_RTDM_RTDMS22_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS22_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS22_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS22_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS21_MASK              0x00200000u
  #define _MCASP_RTDM_RTDMS21_SHIFT             0x00000015u
  #define  MCASP_RTDM_RTDMS21_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS21_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS21_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS21_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS20_MASK              0x00100000u
  #define _MCASP_RTDM_RTDMS20_SHIFT             0x00000014u
  #define  MCASP_RTDM_RTDMS20_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS20_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS20_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS20_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS19_MASK              0x00080000u
  #define _MCASP_RTDM_RTDMS19_SHIFT             0x00000013u
  #define  MCASP_RTDM_RTDMS19_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS19_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS19_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS19_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS18_MASK              0x00040000u
  #define _MCASP_RTDM_RTDMS18_SHIFT             0x00000012u
  #define  MCASP_RTDM_RTDMS18_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS18_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS18_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS18_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS17_MASK              0x00020000u
  #define _MCASP_RTDM_RTDMS17_SHIFT             0x00000011u
  #define  MCASP_RTDM_RTDMS17_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS17_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS17_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS17_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS16_MASK              0x00010000u
  #define _MCASP_RTDM_RTDMS16_SHIFT             0x00000010u
  #define  MCASP_RTDM_RTDMS16_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS16_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS16_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS16_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS15_MASK              0x00008000u
  #define _MCASP_RTDM_RTDMS15_SHIFT             0x0000000Fu
  #define  MCASP_RTDM_RTDMS15_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS15_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS15_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS15_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS14_MASK              0x00004000u
  #define _MCASP_RTDM_RTDMS14_SHIFT             0x0000000Eu
  #define  MCASP_RTDM_RTDMS14_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS14_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS14_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS14_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS13_MASK              0x00002000u
  #define _MCASP_RTDM_RTDMS13_SHIFT             0x0000000Du
  #define  MCASP_RTDM_RTDMS13_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS13_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS13_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS13_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS12_MASK              0x00001000u
  #define _MCASP_RTDM_RTDMS12_SHIFT             0x0000000Cu
  #define  MCASP_RTDM_RTDMS12_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS12_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS12_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS12_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS11_MASK              0x00000800u
  #define _MCASP_RTDM_RTDMS11_SHIFT             0x0000000Bu
  #define  MCASP_RTDM_RTDMS11_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS11_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS11_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS11_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS10_MASK              0x00000400u
  #define _MCASP_RTDM_RTDMS10_SHIFT             0x0000000Au
  #define  MCASP_RTDM_RTDMS10_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS10_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS10_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS10_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS9_MASK              0x00000200u
  #define _MCASP_RTDM_RTDMS9_SHIFT             0x00000009u
  #define  MCASP_RTDM_RTDMS9_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS9_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS9_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS9_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS8_MASK              0x00000100u
  #define _MCASP_RTDM_RTDMS8_SHIFT             0x00000008u
  #define  MCASP_RTDM_RTDMS8_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS8_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS8_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS8_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS7_MASK              0x00000080u
  #define _MCASP_RTDM_RTDMS7_SHIFT             0x00000007u
  #define  MCASP_RTDM_RTDMS7_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS7_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS7_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS7_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS6_MASK              0x00000040u
  #define _MCASP_RTDM_RTDMS6_SHIFT             0x00000006u
  #define  MCASP_RTDM_RTDMS6_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS6_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS6_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS6_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS5_MASK              0x00000020u
  #define _MCASP_RTDM_RTDMS5_SHIFT             0x00000005u
  #define  MCASP_RTDM_RTDMS5_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS5_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS5_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS5_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS4_MASK              0x00000010u
  #define _MCASP_RTDM_RTDMS4_SHIFT             0x00000004u
  #define  MCASP_RTDM_RTDMS4_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS4_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS4_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS4_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS3_MASK              0x00000008u
  #define _MCASP_RTDM_RTDMS3_SHIFT             0x00000003u
  #define  MCASP_RTDM_RTDMS3_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS3_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS3_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS3_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS2_MASK              0x00000004u
  #define _MCASP_RTDM_RTDMS2_SHIFT             0x00000002u
  #define  MCASP_RTDM_RTDMS2_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS2_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS2_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS2_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS1_MASK              0x00000002u
  #define _MCASP_RTDM_RTDMS1_SHIFT             0x00000001u
  #define  MCASP_RTDM_RTDMS1_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS1_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS1_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS1_ACTIVE            0x00000001u
  
  #define _MCASP_RTDM_RTDMS0_MASK              0x00000001u
  #define _MCASP_RTDM_RTDMS0_SHIFT             0x00000000u
  #define  MCASP_RTDM_RTDMS0_DEFAULT           0x00000000u
  #define  MCASP_RTDM_RTDMS0_OF(x)             _VALUEOF(x)
  #define  MCASP_RTDM_RTDMS0_INACTIVE          0x00000000u
  #define  MCASP_RTDM_RTDMS0_ACTIVE            0x00000001u
  
  #define  MCASP_RTDM_OF(x)                _VALUEOF(x)

  #define MCASP_RTDM_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,RTDM,RTDMS31)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS30)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS29)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS28)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS27)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS26)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS25)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS24)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS23)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS22)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS21)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS20)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS19)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS18)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS17)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS16)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS15)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS14)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS13)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS12)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS11)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS10)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS9)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS8)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS7)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS6)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS5)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS4)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS3)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS2)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS1)\
	| _PER_FDEFAULT(MCASP,RTDM,RTDMS0)\
  )

  #define MCASP_RTDM_RMK(rtdms31, rtdms30, rtdms29, rtdms28, rtdms27, rtdms26, rtdms25, rtdms24, rtdms23, rtdms22, rtdms21, rtdms20, rtdms19, rtdms18, rtdms17, rtdms16, rtdms15, rtdms14, rtdms13, rtdms12, rtdms11, rtdms10, rtdms9, rtdms8, rtdms7, rtdms6, rtdms5, rtdms4, rtdms3, rtdms2, rtdms1, rtdms0) (Uint32)( \
     _PER_FMK(MCASP,RTDM,RTDMS31,rtdms31)\
	| _PER_FMK(MCASP,RTDM,RTDMS30,rtdms30)\
	| _PER_FMK(MCASP,RTDM,RTDMS29,rtdms29)\
	| _PER_FMK(MCASP,RTDM,RTDMS28,rtdms28)\
	| _PER_FMK(MCASP,RTDM,RTDMS27,rtdms27)\
	| _PER_FMK(MCASP,RTDM,RTDMS26,rtdms26)\
	| _PER_FMK(MCASP,RTDM,RTDMS25,rtdms25)\
	| _PER_FMK(MCASP,RTDM,RTDMS24,rtdms24)\
	| _PER_FMK(MCASP,RTDM,RTDMS23,rtdms23)\
	| _PER_FMK(MCASP,RTDM,RTDMS22,rtdms22)\
	| _PER_FMK(MCASP,RTDM,RTDMS21,rtdms21)\
	| _PER_FMK(MCASP,RTDM,RTDMS20,rtdms20)\
	| _PER_FMK(MCASP,RTDM,RTDMS19,rtdms19)\
	| _PER_FMK(MCASP,RTDM,RTDMS18,rtdms18)\
	| _PER_FMK(MCASP,RTDM,RTDMS17,rtdms17)\
	| _PER_FMK(MCASP,RTDM,RTDMS16,rtdms16)\
	| _PER_FMK(MCASP,RTDM,RTDMS15,rtdms15)\
	| _PER_FMK(MCASP,RTDM,RTDMS14,rtdms14)\
	| _PER_FMK(MCASP,RTDM,RTDMS13,rtdms13)\
	| _PER_FMK(MCASP,RTDM,RTDMS12,rtdms12)\
	| _PER_FMK(MCASP,RTDM,RTDMS11,rtdms11)\
	| _PER_FMK(MCASP,RTDM,RTDMS10,rtdms10)\
	| _PER_FMK(MCASP,RTDM,RTDMS9,rtdms9)\
	| _PER_FMK(MCASP,RTDM,RTDMS8,rtdms8)\
	| _PER_FMK(MCASP,RTDM,RTDMS7,rtdms7)\
	| _PER_FMK(MCASP,RTDM,RTDMS6,rtdms6)\
	| _PER_FMK(MCASP,RTDM,RTDMS5,rtdms5)\
	| _PER_FMK(MCASP,RTDM,RTDMS4,rtdms4)\
	| _PER_FMK(MCASP,RTDM,RTDMS3,rtdms3)\
	| _PER_FMK(MCASP,RTDM,RTDMS2,rtdms2)\
	| _PER_FMK(MCASP,RTDM,RTDMS1,rtdms1)\
	| _PER_FMK(MCASP,RTDM,RTDMS0,rtdms0)\
  )


  #define _MCASP_RTDM_FGET(N,FIELD)\
    _PER_FGET(_MCASP_RTDM##N##_ADDR,MCASP,RTDM,##FIELD)

  #define _MCASP_RTDM_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_RTDM##N##_ADDR,MCASP,RTDM,##FIELD,field)

  #define _MCASP_RTDM_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_RTDM##N##_ADDR,MCASP,RTDM,##FIELD,##SYM)

  #define _MCASP_RTDM0_FGET(FIELD) _MCASP_RTDM_FGET(0,##FIELD) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RTDM1_FGET(FIELD) _MCASP_RTDM_FGET(1,##FIELD) 
#endif

  #define _MCASP_RTDM0_FSET(FIELD,f) _MCASP_RTDM_FSET(0,##FIELD,f) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RTDM1_FSET(FIELD,f) _MCASP_RTDM_FSET(1,##FIELD,f) 
#endif

  #define _MCASP_RTDM0_FSETS(FIELD,SYM) _MCASP_RTDM_FSETS(0,##FIELD,##SYM) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RTDM1_FSETS(FIELD,SYM) _MCASP_RTDM_FSETS(1,##FIELD,##SYM) 
#endif


/******************************************************************************\
* 
* _____________________
* |                   |
* |     RINTCTL       |
* |___________________|
*
* RINTCTL  -  Receiver Interrupt Control Register
*
* FIELDS (msb -> lsb)
* (rw)  RSTAFRM  
* (rw)  RDATA  
* (rw)  RLAST  
* (rw)  RDMAERR  
* (rw)  RCKFAIL  
* (rw)  RSYNCERR  
* (rw)  ROVRN  
*
\******************************************************************************/

  #define _MCASP_RINTCTL_OFFSET               31

  #define _MCASP_RINTCTL0_ADDR			(_MCASP_BASE_PORT0+4*_MCASP_RINTCTL_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RINTCTL1_ADDR			(_MCASP_BASE_PORT1+4*_MCASP_RINTCTL_OFFSET)
#endif

  #define _MCASP_RINTCTL_RSTAFRM_MASK           0x00000080u
  #define _MCASP_RINTCTL_RSTAFRM_SHIFT          0x00000007u
  #define  MCASP_RINTCTL_RSTAFRM_DEFAULT        0x00000000u
  #define  MCASP_RINTCTL_RSTAFRM_OF(x)          _VALUEOF(x)
  #define  MCASP_RINTCTL_RSTAFRM_DISABLE        0x00000000u
  #define  MCASP_RINTCTL_RSTAFRM_ENABLE         0x00000001u


  #define _MCASP_RINTCTL_RDATA_MASK              0x00000020u
  #define _MCASP_RINTCTL_RDATA_SHIFT             0x00000005u
  #define  MCASP_RINTCTL_RDATA_DEFAULT           0x00000000u
  #define  MCASP_RINTCTL_RDATA_OF(x)             _VALUEOF(x)
  #define  MCASP_RINTCTL_RDATA_DISABLE           0x00000000u
  #define  MCASP_RINTCTL_RDATA_ENABLE            0x00000001u


  #define _MCASP_RINTCTL_RLAST_MASK              0x00000010u
  #define _MCASP_RINTCTL_RLAST_SHIFT             0x00000004u
  #define  MCASP_RINTCTL_RLAST_DEFAULT           0x00000000u
  #define  MCASP_RINTCTL_RLAST_OF(x)             _VALUEOF(x)
  #define  MCASP_RINTCTL_RLAST_DISABLE           0x00000000u
  #define  MCASP_RINTCTL_RLAST_ENABLE            0x00000001u

  #define _MCASP_RINTCTL_RDMAERR_MASK            0x0000008u
  #define _MCASP_RINTCTL_RDMAERR_SHIFT           0x00000003u
  #define  MCASP_RINTCTL_RDMAERR_DEFAULT         0x00000000u
  #define  MCASP_RINTCTL_RDMAERR_OF(x)           _VALUEOF(x)
  #define  MCASP_RINTCTL_RDMAERR_DISABLE         0x00000000u
  #define  MCASP_RINTCTL_RDMAERR_ENABLE          0x00000001u

  #define _MCASP_RINTCTL_RCKFAIL_MASK            0x00000004u
  #define _MCASP_RINTCTL_RCKFAIL_SHIFT           0x00000002u
  #define  MCASP_RINTCTL_RCKFAIL_DEFAULT         0x00000000u
  #define  MCASP_RINTCTL_RCKFAIL_OF(x)           _VALUEOF(x)
  #define  MCASP_RINTCTL_RCKFAIL_DISABLE         0x00000000u
  #define  MCASP_RINTCTL_RCKFAIL_ENABLE          0x00000001u


  #define _MCASP_RINTCTL_RSYNCERR_MASK           0x00000002u
  #define _MCASP_RINTCTL_RSYNCERR_SHIFT          0x00000001u
  #define  MCASP_RINTCTL_RSYNCERR_DEFAULT        0x00000000u
  #define  MCASP_RINTCTL_RSYNCERR_OF(x)          _VALUEOF(x)
  #define  MCASP_RINTCTL_RSYNCERR_DISABLE        0x00000000u
  #define  MCASP_RINTCTL_RSYNCERR_ENABLE         0x00000001u


  #define _MCASP_RINTCTL_ROVRN_MASK              0x00000001u
  #define _MCASP_RINTCTL_ROVRN_SHIFT             0x00000000u
  #define  MCASP_RINTCTL_ROVRN_DEFAULT           0x00000000u
  #define  MCASP_RINTCTL_ROVRN_OF(x)             _VALUEOF(x)
  #define  MCASP_RINTCTL_ROVRN_DISABLE           0x00000000u
  #define  MCASP_RINTCTL_ROVRN_ENABLE            0x00000001u


  #define  MCASP_RINTCTL_OF(x)                  _VALUEOF(x)


  #define MCASP_RINTCTL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,RINTCTL,RSTAFRM)\
    |_PER_FDEFAULT(MCASP,RINTCTL,RDATA)\
    |_PER_FDEFAULT(MCASP,RINTCTL,RLAST)\
    |_PER_FDEFAULT(MCASP,RINTCTL,RDMAERR)\
    |_PER_FDEFAULT(MCASP,RINTCTL,RCKFAIL)\
    |_PER_FDEFAULT(MCASP,RINTCTL,RSYNCERR)\
    |_PER_FDEFAULT(MCASP,RINTCTL,ROVRN)\
  )


  #define MCASP_RINTCTL_RMK(rstafrm, rdata, rlast, rdmaerr, rckfail,rsyncerr, rovrn) (Uint32)( \
     _PER_FMK(MCASP,RINTCTL,RSTAFRM,rstafrm)\
    |_PER_FMK(MCASP,RINTCTL,RDATA,rdata)\
    |_PER_FMK(MCASP,RINTCTL,RLAST,rlast)\
    |_PER_FMK(MCASP,RINTCTL,RDMAERR,rdmaerr)\
    |_PER_FMK(MCASP,RINTCTL,RCKFAIL,rckfail)\
    |_PER_FMK(MCASP,RINTCTL,RSYNCERR,rsyncerr)\
    |_PER_FMK(MCASP,RINTCTL,ROVRN,rovrn)\
  )


  #define _MCASP_RINTCTL_FGET(N,FIELD)\
    _PER_FGET(_MCASP_RINTCTL##N##_ADDR,MCASP,RINTCTL,##FIELD)

  #define _MCASP_RINTCTL_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_RINTCTL##N##_ADDR,MCASP,RINTCTL,##FIELD,field)

  #define _MCASP_RINTCTL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_RINTCTL##N##_ADDR,MCASP,RINTCTL,##FIELD,##SYM)

  #define _MCASP_RINTCTL0_FGET(FIELD) _MCASP_RINTCTL_FGET(0,##FIELD) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RINTCTL1_FGET(FIELD) _MCASP_RINTCTL_FGET(1,##FIELD) 
#endif

  #define _MCASP_RINTCTL0_FSET(FIELD,f) _MCASP_RINTCTL_FSET(0,##FIELD,f) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RINTCTL1_FSET(FIELD,f) _MCASP_RINTCTL_FSET(1,##FIELD,f) 
#endif

  #define _MCASP_RINTCTL0_FSETS(FIELD,SYM) _MCASP_RINTCTL_FSETS(0,##FIELD,##SYM) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RINTCTL1_FSETS(FIELD,SYM) _MCASP_RINTCTL_FSETS(1,##FIELD,##SYM) 
#endif


/******************************************************************************\
* 
* _____________________
* |                   |
* |       RSTAT       |
* |___________________|
*
* RSTAT  -  Receiver Status Register
*
* FIELDS (msb -> lsb)
* (r)  RERR  
* (r)  RDMAERR  
* (r)  RSTAFRM  
* (r)  RDAT  
* (r)  RLAST 
* (r)  RTDMSLOT  
* (r)  RCKFAIL  
* (r)  RSYNCERR  
* (r)  ROVRN 
*
\******************************************************************************/

  #define _MCASP_RSTAT_OFFSET               32

  #define _MCASP_RSTAT0_ADDR				(_MCASP_BASE_PORT0+4*_MCASP_RSTAT_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RSTAT1_ADDR				(_MCASP_BASE_PORT1+4*_MCASP_RSTAT_OFFSET)
#endif

  #define _MCASP_RSTAT_RERR_MASK              0x00000100u
  #define _MCASP_RSTAT_RERR_SHIFT             0x00000008u
  #define  MCASP_RSTAT_RERR_DEFAULT           0x00000000u
  #define  MCASP_RSTAT_RERR_OF(x)             _VALUEOF(x)

  #define _MCASP_RSTAT_RDMAERR_MASK              0x00000080u
  #define _MCASP_RSTAT_RDMAERR_SHIFT             0x00000007u
  #define  MCASP_RSTAT_RDMAERR_DEFAULT           0x00000000u
  #define  MCASP_RSTAT_RDMAERR_OF(x)             _VALUEOF(x)

  #define _MCASP_RSTAT_RSTAFRM_MASK              0x00000040u
  #define _MCASP_RSTAT_RSTAFRM_SHIFT             0x00000006u
  #define  MCASP_RSTAT_RSTAFRM_DEFAULT           0x00000000u
  #define  MCASP_RSTAT_RSTAFRM_OF(x)             _VALUEOF(x)
  #define  MCASP_RSTAT_RSTAFRM_0                 0x00000000u
  #define  MCASP_RSTAT_RSTAFRM_1                 0x00000001u
  #define  MCASP_RSTAT_RSTAFRM_NO                0x00000000u
  #define  MCASP_RSTAT_RSTAFRM_YES               0x00000001u


  #define _MCASP_RSTAT_RDATA_MASK              0x00000020u
  #define _MCASP_RSTAT_RDATA_SHIFT             0x00000005u
  #define  MCASP_RSTAT_RDATA_DEFAULT           0x00000000u
  #define  MCASP_RSTAT_RDATA_OF(x)             _VALUEOF(x)
  #define  MCASP_RSTAT_RDATA_0                0x00000000u
  #define  MCASP_RSTAT_RDATA_1               0x00000001u
  #define  MCASP_RSTAT_RDATA_NO                0x00000000u
  #define  MCASP_RSTAT_RDATA_YES              0x00000001u


  #define _MCASP_RSTAT_RLAST_MASK              0x00000010u
  #define _MCASP_RSTAT_RLAST_SHIFT             0x00000004u
  #define  MCASP_RSTAT_RLAST_DEFAULT           0x00000000u
  #define  MCASP_RSTAT_RLAST_OF(x)             _VALUEOF(x)
  #define  MCASP_RSTAT_RLAST_0                 0x00000000u
  #define  MCASP_RSTAT_RLAST_1                 0x00000001u
  #define  MCASP_RSTAT_RLAST_NO                0x00000000u
  #define  MCASP_RSTAT_RLAST_YES               0x00000001u

  #define _MCASP_RSTAT_RTDMSLOT_MASK              0x00000008u
  #define _MCASP_RSTAT_RTDMSLOT_SHIFT             0x00000003u
  #define  MCASP_RSTAT_RTDMSLOT_DEFAULT           0x00000000u
  #define  MCASP_RSTAT_RTDMSLOT_OF(x)             _VALUEOF(x)


  #define _MCASP_RSTAT_RCKFAIL_MASK              0x00000004u
  #define _MCASP_RSTAT_RCKFAIL_SHIFT             0x00000002u
  #define  MCASP_RSTAT_RCKFAIL_DEFAULT           0x00000000u
  #define  MCASP_RSTAT_RCKFAIL_OF(x)             _VALUEOF(x)
  #define  MCASP_RSTAT_RCKFAIL_0                 0x00000000u
  #define  MCASP_RSTAT_RCKFAIL_1                 0x00000001u
  #define  MCASP_RSTAT_RCKFAIL_NO                0x00000000u
  #define  MCASP_RSTAT_RCKFAIL_YES               0x00000001u


  #define _MCASP_RSTAT_RSYNCERR_MASK              0x00000002u
  #define _MCASP_RSTAT_RSYNCERR_SHIFT             0x00000001u
  #define  MCASP_RSTAT_RSYNCERR_DEFAULT           0x00000000u
  #define  MCASP_RSTAT_RSYNCERR_OF(x)             _VALUEOF(x)
  #define  MCASP_RSTAT_RSYNCERR_0                 0x00000000u
  #define  MCASP_RSTAT_RSYNCERR_1                 0x00000001u
  #define  MCASP_RSTAT_RSYNCERR_NO                0x00000000u
  #define  MCASP_RSTAT_RSYNCERR_YES               0x00000001u

  #define _MCASP_RSTAT_ROVRN_MASK              0x00000001u
  #define _MCASP_RSTAT_ROVRN_SHIFT             0x00000000u
  #define  MCASP_RSTAT_ROVRN_DEFAULT           0x00000000u
  #define  MCASP_RSTAT_ROVRN_OF(x)             _VALUEOF(x)
  #define  MCASP_RSTAT_ROVRN_0                 0x00000000u 
  #define  MCASP_RSTAT_ROVRN_1                 0x00000001u 
  #define  MCASP_RSTAT_ROVRN_NO                0x00000000u 
  #define  MCASP_RSTAT_ROVRN_YES               0x00000001u 

  #define  MCASP_RSTAT_OF(x)                _VALUEOF(x)

  #define MCASP_RSTAT_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,RSTAT,RERR)\
	| _PER_FDEFAULT(MCASP,RSTAT,RDMAERR)\
	| _PER_FDEFAULT(MCASP,RSTAT,RSTAFRM)\
	| _PER_FDEFAULT(MCASP,RSTAT,RDATA)\
	| _PER_FDEFAULT(MCASP,RSTAT,RLAST)\
	| _PER_FDEFAULT(MCASP,RSTAT,RTDMSLOT)\
	| _PER_FDEFAULT(MCASP,RSTAT,RCKFAIL)\
	| _PER_FDEFAULT(MCASP,RSTAT,RSYNCERR)\
	| _PER_FDEFAULT(MCASP,RSTAT,ROVRN)\
  )

  #define MCASP_RSTAT_RMK(rerr, rdmaerr, rstafrm, rdata, rlast, rtdmslot, rckfail, rsyncerr, rovrn) (Uint32)( \
     _PER_FMK(MCASP,RSTAT,RERR,rerr)\
	| _PER_FMK(MCASP,RSTAT,RDMAERR,rdmaerr)\
	| _PER_FMK(MCASP,RSTAT,RSTAFRM,rstafrm)\
	| _PER_FMK(MCASP,RSTAT,RDATA,rdata)\
	| _PER_FMK(MCASP,RSTAT,RLAST,rlast)\
	| _PER_FMK(MCASP,RSTAT,RTDMSLOT,rtdmslot)\
	| _PER_FMK(MCASP,RSTAT,RCKFAIL,rckfail)\
	| _PER_FMK(MCASP,RSTAT,RSYNCERR,rsyncerr)\
	| _PER_FMK(MCASP,RSTAT,ROVRN,rovrn)\
  )

  #define _MCASP_RSTAT_FGET(N,FIELD)\
    _PER_FGET(_MCASP_RSTAT##N##_ADDR,MCASP,RSTAT,##FIELD)

  #define _MCASP_RSTAT_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_RSTAT##N##_ADDR,MCASP,RSTAT,##FIELD,field)

  #define _MCASP_RSTAT_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_RSTAT##N##_ADDR,MCASP,RSTAT,##FIELD,##SYM)

  #define _MCASP_RSTAT0_FGET(FIELD) _MCASP_RSTAT_FGET(0,##FIELD) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RSTAT1_FGET(FIELD) _MCASP_RSTAT_FGET(1,##FIELD) 
#endif

  #define _MCASP_RSTAT0_FSET(FIELD,f) _MCASP_RSTAT_FSET(0,##FIELD,f) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RSTAT1_FSET(FIELD,f) _MCASP_RSTAT_FSET(1,##FIELD,f) 
#endif

  #define _MCASP_RSTAT0_FSETS(FIELD,SYM) _MCASP_RSTAT_FSETS(0,##FIELD,##SYM) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RSTAT1_FSETS(FIELD,SYM) _MCASP_RSTAT_FSETS(1,##FIELD,##SYM) 
#endif


/******************************************************************************\
* 
* _____________________
* |                   |
* |     RSLOT         |
* |___________________|
*
* RSLOT0    -  Receiver TDM Slot Counter MCASP0
* RSLOT1    -  Receiver TDM Slot Counter MCASP1
*
* FIELDS (msb -> lsb)
* (r )  RSLOTCNT  
*
\******************************************************************************/

  #define _MCASP_RSLOT_OFFSET               33

  #define _MCASP_RSLOT0_ADDR				(_MCASP_BASE_PORT0+4*_MCASP_RSLOT_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RSLOT1_ADDR				(_MCASP_BASE_PORT1+4*_MCASP_RSLOT_OFFSET)
#endif


  #define _MCASP_RSLOT_RSLOTCNT_MASK              0x000003FFu
  #define _MCASP_RSLOT_RSLOTCNT_SHIFT             0x00000000u
  #define  MCASP_RSLOT_RSLOTCNT_DEFAULT           0x00000000u
  #define  MCASP_RSLOT_RSLOTCNT_OF(x)             _VALUEOF(x)

  #define  MCASP_RSLOT_OF(x)                _VALUEOF(x)

  #define MCASP_RSLOT_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,RSLOT,RSLOTCNT)\
  )

  #define MCASP_RSLOT_RMK(rslotcnt) (Uint32)( \
     _PER_FMK(MCASP,RSLOT,RSLOTCNT,rslotcnt)\
  )


  #define _MCASP_RSLOT_FGET(N,FIELD)\
    _PER_FGET(_MCASP_RSLOT##N##_ADDR,MCASP,RSLOT,##FIELD)

  #define _MCASP_RSLOT_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_RSLOT##N##_ADDR,MCASP,RSLOT,##FIELD,field)

  #define _MCASP_RSLOT_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_RSLOT##N##_ADDR,MCASP,RSLOT,##FIELD,##SYM)

  #define _MCASP_RSLOT0_FGET(FIELD) _MCASP_RSLOT_FGET(0,##FIELD) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RSLOT1_FGET(FIELD) _MCASP_RSLOT_FGET(1,##FIELD) 
#endif

  #define _MCASP_RSLOT0_FSET(FIELD,f) _MCASP_RSLOT_FSET(0,##FIELD,f) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RSLOT1_FSET(FIELD,f) _MCASP_RSLOT_FSET(1,##FIELD,f) 
#endif

  #define _MCASP_RSLOT0_FSETS(FIELD,SYM) _MCASP_RSLOT_FSETS(0,##FIELD,##SYM) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RSLOT1_FSETS(FIELD,SYM) _MCASP_RSLOT_FSETS(1,##FIELD,##SYM) 
#endif


/******************************************************************************\
* 
* _____________________
* |                   |
* |     RCLKCHK       |
* |___________________|
*
* RCLKCHK  -  Receiver Clock Check Control Register 
*
* FIELDS (msb -> lsb)
* (r )  RCNT  
* (rw)  RMAX  
* (rw)  RMIN  
* (rw)  RPS  
\******************************************************************************/

  #define _MCASP_RCLKCHK_OFFSET               34

  #define _MCASP_RCLKCHK0_ADDR				(_MCASP_BASE_PORT0+4*_MCASP_RCLKCHK_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RCLKCHK1_ADDR				(_MCASP_BASE_PORT1+4*_MCASP_RCLKCHK_OFFSET)
#endif

  #define _MCASP_RCLKCHK_RCNT_MASK              0xFF000000u
  #define _MCASP_RCLKCHK_RCNT_SHIFT             0x00000018u
  #define  MCASP_RCLKCHK_RCNT_DEFAULT           0x00000000u 
  #define  MCASP_RCLKCHK_RCNT_OF(x)             _VALUEOF(x)


  #define _MCASP_RCLKCHK_RMAX_MASK              0x00FF0000u
  #define _MCASP_RCLKCHK_RMAX_SHIFT             0x00000010u
  #define  MCASP_RCLKCHK_RMAX_DEFAULT           0x00000000u 
  #define  MCASP_RCLKCHK_RMAX_OF(x)             _VALUEOF(x)


  #define _MCASP_RCLKCHK_RMIN_MASK              0x0000FF00u
  #define _MCASP_RCLKCHK_RMIN_SHIFT             0x00000008u
  #define  MCASP_RCLKCHK_RMIN_DEFAULT           0x00000000u 
  #define  MCASP_RCLKCHK_RMIN_OF(x)             _VALUEOF(x)


  #define _MCASP_RCLKCHK_RPS_MASK              0x0000000Fu
  #define _MCASP_RCLKCHK_RPS_SHIFT             0x00000000u
  #define  MCASP_RCLKCHK_RPS_DEFAULT           0x00000000u 
  #define  MCASP_RCLKCHK_RPS_OF(x)             _VALUEOF(x)
  #define  MCASP_RCLKCHK_RPS_DIVBY1            0x00000000u
  #define  MCASP_RCLKCHK_RPS_DIVBY2            0x00000001u
  #define  MCASP_RCLKCHK_RPS_DIVBY4            0x00000002u
  #define  MCASP_RCLKCHK_RPS_DIVBY8            0x00000003u 
  #define  MCASP_RCLKCHK_RPS_DIVBY16           0x00000004u 
  #define  MCASP_RCLKCHK_RPS_DIVBY32           0x00000005u 
  #define  MCASP_RCLKCHK_RPS_DIVBY64           0x00000006u 
  #define  MCASP_RCLKCHK_RPS_DIVBY128          0x00000007u 
  #define  MCASP_RCLKCHK_RPS_DIVBY256          0x00000008u 


  #define  MCASP_RCLKCHK_OF(x)                _VALUEOF(x)

  #define MCASP_RCLKCHK_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,RCLKCHK,RCNT)\
	| _PER_FDEFAULT(MCASP,RCLKCHK,RMAX)\
	| _PER_FDEFAULT(MCASP,RCLKCHK,RMIN)\
	| _PER_FDEFAULT(MCASP,RCLKCHK,RPS)\
  )

  #define MCASP_RCLKCHK_RMK(rcnt, rmax, rmin, rps) (Uint32)( \
     _PER_FMK(MCASP,RCLKCHK,RCNT,rcnt)\
	| _PER_FMK(MCASP,RCLKCHK,RMAX,rmax)\
	| _PER_FMK(MCASP,RCLKCHK,RMIN,rmin)\
	| _PER_FMK(MCASP,RCLKCHK,RPS,rps)\
  )

  #define _MCASP_RCLKCHK_FGET(N,FIELD)\
    _PER_FGET(_MCASP_RCLKCHK##N##_ADDR,MCASP,RCLKCHK,##FIELD)

  #define _MCASP_RCLKCHK_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_RCLKCHK##N##_ADDR,MCASP,RCLKCHK,##FIELD,field)

  #define _MCASP_RCLKCHK_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_RCLKCHK##N##_ADDR,MCASP,RCLKCHK,##FIELD,##SYM)

  #define _MCASP_RCLKCHK0_FGET(FIELD) _MCASP_RCLKCHK_FGET(0,##FIELD) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RCLKCHK1_FGET(FIELD) _MCASP_RCLKCHK_FGET(1,##FIELD) 
#endif

  #define _MCASP_RCLKCHK0_FSET(FIELD,f) _MCASP_RCLKCHK_FSET(0,##FIELD,f) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RCLKCHK1_FSET(FIELD,f) _MCASP_RCLKCHK_FSET(1,##FIELD,f) 
#endif

  #define _MCASP_RCLKCHK0_FSETS(FIELD,SYM) _MCASP_RCLKCHK_FSETS(0,##FIELD,##SYM) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RCLKCHK1_FSETS(FIELD,SYM) _MCASP_RCLKCHK_FSETS(1,##FIELD,##SYM) 
#endif


/******************************************************************************\
* 
* _____________________
* |                   |
* |     XGBLCTL       |
* |___________________|
*
* XGBLCTL  -  Global Control Register
*
* FIELDS (msb -> lsb)
* (rw)  XFRST
* (rw)  XSMRST
* (rw)  XSRCLR
* (rw)  XHCLKRST
* (rw)  XCLKRST
* (rw)  RFRST
* (rw)  RSMRST
* (rw)  RSRCLR
* (rw)  RHCLKRST
* (rw)  RCLKRST
*
\******************************************************************************/

  #define _MCASP_XGBLCTL_OFFSET             40

  #define _MCASP_XGBLCTL0_ADDR				(_MCASP_BASE_PORT0+4*_MCASP_XGBLCTL_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XGBLCTL1_ADDR				(_MCASP_BASE_PORT1+4*_MCASP_XGBLCTL_OFFSET)
#endif

  #define _MCASP_XGBLCTL_XFRST_MASK              0x00001000u
  #define _MCASP_XGBLCTL_XFRST_SHIFT             0x0000000Cu
  #define  MCASP_XGBLCTL_XFRST_DEFAULT           0x00000000u
  #define  MCASP_XGBLCTL_XFRST_OF(x)             _VALUEOF(x)
  #define  MCASP_XGBLCTL_XFRST_RESET             0x00000000u
  #define  MCASP_XGBLCTL_XFRST_ACTIVE            0x00000001u

  #define _MCASP_XGBLCTL_XSMRST_MASK              0x00000800u
  #define _MCASP_XGBLCTL_XSMRST_SHIFT             0x0000000Bu
  #define  MCASP_XGBLCTL_XSMRST_DEFAULT           0x00000000u
  #define  MCASP_XGBLCTL_XSMRST_OF(x)            _VALUEOF(x)
  #define  MCASP_XGBLCTL_XSMRST_RESET		0x00000000u
  #define  MCASP_XGBLCTL_XSMRST_ACTIVE		0x00000001u

  #define _MCASP_XGBLCTL_XSRCLR_MASK              0x00000400u
  #define _MCASP_XGBLCTL_XSRCLR_SHIFT             0x0000000Au
  #define  MCASP_XGBLCTL_XSRCLR_DEFAULT           0x00000000u
  #define  MCASP_XGBLCTL_XSRCLR_OF(x)             _VALUEOF(x)
  #define  MCASP_XGBLCTL_XSRCLR_CLEAR           0x00000000u
  #define  MCASP_XGBLCTL_XSRCLR_ACTIVE            0x00000001u

  #define _MCASP_XGBLCTL_XHCLKRST_MASK              0x00000200u
  #define _MCASP_XGBLCTL_XHCLKRST_SHIFT             0x00000009u
  #define  MCASP_XGBLCTL_XHCLKRST_DEFAULT           0x00000000u
  #define  MCASP_XGBLCTL_XHCLKRST_OF(x)             _VALUEOF(x)
  #define  MCASP_XGBLCTL_XHCLKRST_RESET				0x00000000u
  #define  MCASP_XGBLCTL_XHCLKRST_ACTIVE			0x00000001u

  #define _MCASP_XGBLCTL_XCLKRST_MASK              0x00000100u
  #define _MCASP_XGBLCTL_XCLKRST_SHIFT             0x00000008u
  #define  MCASP_XGBLCTL_XCLKRST_DEFAULT           0x00000000u
  #define  MCASP_XGBLCTL_XCLKRST_OF(x)             _VALUEOF(x)
  #define  MCASP_XGBLCTL_XCLKRST_RESET			0x00000000u
  #define  MCASP_XGBLCTL_XCLKRST_ACTIVE			0x00000001u

  #define _MCASP_XGBLCTL_RFRST_MASK           0x00000010u
  #define _MCASP_XGBLCTL_RFRST_SHIFT          0x00000004u
  #define  MCASP_XGBLCTL_RFRST_DEFAULT        0x00000000u
  #define  MCASP_XGBLCTL_RFRST_OF(x)          _VALUEOF(x)
  #define  MCASP_XGBLCTL_RFRST_RESET          0x00000000u
  #define  MCASP_XGBLCTL_RFRST_ACTIVE         0x00000001u

  #define _MCASP_XGBLCTL_RSMRST_MASK          0x00000008u
  #define _MCASP_XGBLCTL_RSMRST_SHIFT         0x00000003u
  #define  MCASP_XGBLCTL_RSMRST_DEFAULT       0x00000000u
  #define  MCASP_XGBLCTL_RSMRST_OF(x)         _VALUEOF(x)
  #define  MCASP_XGBLCTL_RSMRST_RESET	      0x00000000u
  #define  MCASP_XGBLCTL_RSMRST_ACTIVE	      0x00000001u

  #define _MCASP_XGBLCTL_RSRCLR_MASK          0x00000004u
  #define _MCASP_XGBLCTL_RSRCLR_SHIFT         0x00000002u
  #define  MCASP_XGBLCTL_RSRCLR_DEFAULT       0x00000000u
  #define  MCASP_XGBLCTL_RSRCLR_OF(x)         _VALUEOF(x)
  #define  MCASP_XGBLCTL_RSRCLR_CLEAR         0x00000000u
  #define  MCASP_XGBLCTL_RSRCLR_ACTIVE        0x00000001u

  #define _MCASP_XGBLCTL_RHCLKRST_MASK        0x00000002u
  #define _MCASP_XGBLCTL_RHCLKRST_SHIFT       0x00000001u
  #define  MCASP_XGBLCTL_RHCLKRST_DEFAULT     0x00000000u
  #define  MCASP_XGBLCTL_RHCLKRST_OF(x)       _VALUEOF(x)
  #define  MCASP_XGBLCTL_RHCLKRST_RESET	      0x00000000u
  #define  MCASP_XGBLCTL_RHCLKRST_ACTIVE      0x00000001u

  #define _MCASP_XGBLCTL_RCLKRST_MASK         0x00000001u
  #define _MCASP_XGBLCTL_RCLKRST_SHIFT        0x00000000u
  #define  MCASP_XGBLCTL_RCLKRST_DEFAULT      0x00000000u
  #define  MCASP_XGBLCTL_RCLKRST_OF(x)        _VALUEOF(x)
  #define  MCASP_XGBLCTL_RCLKRST_RESET	      0x00000000u
  #define  MCASP_XGBLCTL_RCLKRST_ACTIVE	      0x00000001u

  #define  MCASP_XGBLCTL_OF(x)                _VALUEOF(x)

  #define MCASP_XGBLCTL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,XGBLCTL,XFRST)\
    |_PER_FDEFAULT(MCASP,XGBLCTL,XSMRST)\
    |_PER_FDEFAULT(MCASP,XGBLCTL,XSRCLR)\
    |_PER_FDEFAULT(MCASP,XGBLCTL,xXHCLKRST)\
    |_PER_FDEFAULT(MCASP,XGBLCTL,XCLKRST)\
  )


  #define MCASP_XGBLCTL_RMK(xfrst, xsmrst, xsrclr, xhclkrst, xclkrst) (Uint32)( \
     _PER_FMK(MCASP,XGBLCTL,XFRST,xfrst)\
    |_PER_FMK(MCASP,XGBLCTL,XSMRST,xsmrst)\
    |_PER_FMK(MCASP,XGBLCTL,XSRCLR,xsrclr)\
    |_PER_FMK(MCASP,XGBLCTL,XHCLKRST,xhclkrst)\
    |_PER_FMK(MCASP,XGBLCTL,XCLKRST,xclkrst)\
  )


  #define _MCASP_XGBLCTL_FGET(N,FIELD)\
    _PER_FGET(_MCASP_XGBLCTL##N##_ADDR,MCASP,XGBLCTL,##FIELD)

  #define _MCASP_XGBLCTL_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_XGBLCTL##N##_ADDR,MCASP,XGBLCTL,##FIELD,field)

  #define _MCASP_XGBLCTL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_XGBLCTL##N##_ADDR,MCASP,XGBLCTL,##FIELD,##SYM)

  #define _MCASP_XGBLCTL0_FGET(FIELD) _MCASP_XGBLCTL_FGET(0,##FIELD) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XGBLCTL1_FGET(FIELD) _MCASP_XGBLCTL_FGET(1,##FIELD)  
#endif

  #define _MCASP_XGBLCTL0_FSET(FIELD,f) _MCASP_XGBLCTL_FSET(0,##FIELD,f) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XGBLCTL1_FSET(FIELD,f) _MCASP_XGBLCTL_FSET(1,##FIELD,f)  
#endif

  #define _MCASP_XGBLCTL0_FSETS(FIELD,SYM) _MCASP_XGBLCTL_FSETS(0,##FIELD,##SYM) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XGBLCTL1_FSETS(FIELD,SYM) _MCASP_XGBLCTL_FSETS(1,##FIELD,##SYM) 
#endif


/******************************************************************************\
* 
* _____________________
* |                   |
* |     XMASK         |
* |___________________|
*
* XMASK		- Pin Data Output Register
*
* FIELDS (msb -> lsb)
* (rw)  XMASKn n:0 to 31  
*
\******************************************************************************/

  #define _MCASP_XMASK_OFFSET               41

  #define _MCASP_XMASK0_ADDR				(_MCASP_BASE_PORT0+4*_MCASP_XMASK_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XMASK1_ADDR				(_MCASP_BASE_PORT1+4*_MCASP_XMASK_OFFSET)
#endif

  #define _MCASP_XMASK_XMASK0_MASK        	0x00000001u
  #define _MCASP_XMASK_XMASK0_SHIFT       	0x00000000u
  #define  MCASP_XMASK_XMASK0_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK0_OF(x)   	    _VALUEOF(x)
  #define  MCASP_XMASK_XMASK0_USEMASK	    0x00000000u
  #define  MCASP_XMASK_XMASK0_NOMASK        0x00000001u

  #define _MCASP_XMASK_XMASK1_MASK        	0x00000002u
  #define _MCASP_XMASK_XMASK1_SHIFT       	0x00000001u
  #define  MCASP_XMASK_XMASK1_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK1_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK1_USEMASK	        	0x00000000u
  #define  MCASP_XMASK_XMASK1_NOMASK            	0x00000001u

  #define _MCASP_XMASK_XMASK2_MASK        	0x00000004u
  #define _MCASP_XMASK_XMASK2_SHIFT       	0x00000002u
  #define  MCASP_XMASK_XMASK2_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK2_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK2_USEMASK	        	0x00000000u
  #define  MCASP_XMASK_XMASK2_NOMASK            	0x00000001u

  #define _MCASP_XMASK_XMASK3_MASK        	0x00000008u
  #define _MCASP_XMASK_XMASK3_SHIFT       	0x00000003u
  #define  MCASP_XMASK_XMASK3_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK3_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK3_USEMASK	        	0x00000000u
  #define  MCASP_XMASK_XMASK3_NOMASK            	0x00000001u

  #define _MCASP_XMASK_XMASK4_MASK        	0x00000010u
  #define _MCASP_XMASK_XMASK4_SHIFT       	0x00000004u
  #define  MCASP_XMASK_XMASK4_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK4_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK4_USEMASK	       	0x00000000u
  #define  MCASP_XMASK_XMASK4_NOMASK            	0x00000001u

  #define _MCASP_XMASK_XMASK5_MASK        	0x00000020u
  #define _MCASP_XMASK_XMASK5_SHIFT       	0x00000005u
  #define  MCASP_XMASK_XMASK5_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK5_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK5_USEMASK	       	0x00000000u
  #define  MCASP_XMASK_XMASK5_NOMASK            	0x00000001u

  #define _MCASP_XMASK_XMASK6_MASK        	0x00000040u
  #define _MCASP_XMASK_XMASK6_SHIFT       	0x00000006u
  #define  MCASP_XMASK_XMASK6_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK6_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK6_USEMASK	       	0x00000000u
  #define  MCASP_XMASK_XMASK6_NOMASK            	0x00000001u

  #define _MCASP_XMASK_XMASK7_MASK        	0x00000080u
  #define _MCASP_XMASK_XMASK7_SHIFT       	0x00000007u
  #define  MCASP_XMASK_XMASK7_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK7_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK7_USEMASK	       	0x00000000u
  #define  MCASP_XMASK_XMASK7_NOMASK            	0x00000001u

  #define _MCASP_XMASK_XMASK8_MASK        	0x00000100u
  #define _MCASP_XMASK_XMASK8_SHIFT       	0x00000008u
  #define  MCASP_XMASK_XMASK8_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK8_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK8_USEMASK	       	0x00000000u
  #define  MCASP_XMASK_XMASK8_NOMASK            	0x00000001u

  #define _MCASP_XMASK_XMASK9_MASK        	0x00000200u
  #define _MCASP_XMASK_XMASK9_SHIFT       	0x00000009u
  #define  MCASP_XMASK_XMASK9_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK9_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK9_USEMASK	       	0x00000000u
  #define  MCASP_XMASK_XMASK9_NOMASK            	0x00000001u

  #define _MCASP_XMASK_XMASK10_MASK        	0x00000400u
  #define _MCASP_XMASK_XMASK10_SHIFT       	0x0000000Au
  #define  MCASP_XMASK_XMASK10_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK10_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK10_USEMASK        	0x00000000u
  #define  MCASP_XMASK_XMASK10_NOMASK            	0x00000001u

  #define _MCASP_XMASK_XMASK11_MASK        	0x00000800u
  #define _MCASP_XMASK_XMASK11_SHIFT       	0x0000000Bu
  #define  MCASP_XMASK_XMASK11_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK11_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK11_USEMASK	       	0x00000000u
  #define  MCASP_XMASK_XMASK11_NOMASK            	0x00000001u

  #define _MCASP_XMASK_XMASK12_MASK        	0x00001000u
  #define _MCASP_XMASK_XMASK12_SHIFT       	0x0000000Cu
  #define  MCASP_XMASK_XMASK12_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK12_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK12_USEMASK        	0x00000000u
  #define  MCASP_XMASK_XMASK12_NOMASK            	0x00000001u

  #define _MCASP_XMASK_XMASK13_MASK        	0x00002000u
  #define _MCASP_XMASK_XMASK13_SHIFT       	0x0000000Du
  #define  MCASP_XMASK_XMASK13_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK13_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK13_USEMASK        	0x00000000u
  #define  MCASP_XMASK_XMASK13_NOMASK            	0x00000001u

  #define _MCASP_XMASK_XMASK14_MASK        	0x00004000u
  #define _MCASP_XMASK_XMASK14_SHIFT       	0x0000000Eu
  #define  MCASP_XMASK_XMASK14_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK14_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK14_USEMASK        	0x00000000u
  #define  MCASP_XMASK_XMASK14_NOMASK            	0x00000001u

  #define _MCASP_XMASK_XMASK15_MASK        	0x00008000u
  #define _MCASP_XMASK_XMASK15_SHIFT       	0x0000000Fu
  #define  MCASP_XMASK_XMASK15_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK15_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK15_USEMASK        	0x00000000u
  #define  MCASP_XMASK_XMASK15_NOMASK            	0x00000001u

  #define _MCASP_XMASK_XMASK16_MASK        	0x00010000u
  #define _MCASP_XMASK_XMASK16_SHIFT       	0x00000010u
  #define  MCASP_XMASK_XMASK16_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK16_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK16_USEMASK        	0x00000000u
  #define  MCASP_XMASK_XMASK16_NOMASK            	0x00000001u

  #define _MCASP_XMASK_XMASK17_MASK        	0x00020000u
  #define _MCASP_XMASK_XMASK17_SHIFT       	0x00000011u
  #define  MCASP_XMASK_XMASK17_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK17_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK17_USEMASK        	0x00000000u
  #define  MCASP_XMASK_XMASK17_NOMASK            	0x00000001u

  #define _MCASP_XMASK_XMASK18_MASK        	0x00040000u
  #define _MCASP_XMASK_XMASK18_SHIFT       	0x00000012u
  #define  MCASP_XMASK_XMASK18_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK18_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK18_USEMASK        	0x00000000u
  #define  MCASP_XMASK_XMASK18_NOMASK            	0x00000001u

  #define _MCASP_XMASK_XMASK19_MASK        	0x00080000u
  #define _MCASP_XMASK_XMASK19_SHIFT       	0x00000013u
  #define  MCASP_XMASK_XMASK19_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK19_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK19_USEMASK        	0x00000000u
  #define  MCASP_XMASK_XMASK19_NOMASK            	0x00000001u

  #define _MCASP_XMASK_XMASK20_MASK        	0x00100000u
  #define _MCASP_XMASK_XMASK20_SHIFT       	0x00000014u
  #define  MCASP_XMASK_XMASK20_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK20_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK20_USEMASK        	0x00000000u
  #define  MCASP_XMASK_XMASK20_NOMASK            	0x00000001u

  #define _MCASP_XMASK_XMASK21_MASK        	0x00200000u
  #define _MCASP_XMASK_XMASK21_SHIFT       	0x00000015u
  #define  MCASP_XMASK_XMASK21_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK21_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK21_USEMASK        	0x00000000u
  #define  MCASP_XMASK_XMASK21_NOMASK            	0x00000001u

  #define _MCASP_XMASK_XMASK22_MASK        	0x00400000u
  #define _MCASP_XMASK_XMASK22_SHIFT       	0x00000016u
  #define  MCASP_XMASK_XMASK22_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK22_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK22_USEMASK        	0x00000000u
  #define  MCASP_XMASK_XMASK22_NOMASK            	0x00000001u

  #define _MCASP_XMASK_XMASK23_MASK        	0x00800000u
  #define _MCASP_XMASK_XMASK23_SHIFT       	0x00000017u
  #define  MCASP_XMASK_XMASK23_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK23_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK23_USEMASK        	0x00000000u
  #define  MCASP_XMASK_XMASK23_NOMASK            	0x00000001u

  #define _MCASP_XMASK_XMASK24_MASK        	0x01000000u
  #define _MCASP_XMASK_XMASK24_SHIFT       	0x00000018u
  #define  MCASP_XMASK_XMASK24_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK24_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK24_USEMASK        	0x00000000u
  #define  MCASP_XMASK_XMASK24_NOMASK            	0x00000001u

  #define _MCASP_XMASK_XMASK25_MASK        	0x02000000u
  #define _MCASP_XMASK_XMASK25_SHIFT       	0x00000019u
  #define  MCASP_XMASK_XMASK25_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK25_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK25_USEMASK        	0x00000000u
  #define  MCASP_XMASK_XMASK25_NOMASK            	0x00000001u

  #define _MCASP_XMASK_XMASK26_MASK        	0x04000000u
  #define _MCASP_XMASK_XMASK26_SHIFT       	0x0000001Au
  #define  MCASP_XMASK_XMASK26_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK26_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK26_USEMASK        	0x00000000u
  #define  MCASP_XMASK_XMASK26_NOMASK            	0x00000001u

  #define _MCASP_XMASK_XMASK27_MASK        	0x08000000u
  #define _MCASP_XMASK_XMASK27_SHIFT       	0x0000001Bu
  #define  MCASP_XMASK_XMASK27_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK27_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK27_USEMASK        	0x00000000u
  #define  MCASP_XMASK_XMASK27_NOMASK            	0x00000001u

  #define _MCASP_XMASK_XMASK28_MASK        	0x10000000u
  #define _MCASP_XMASK_XMASK28_SHIFT       	0x0000001Cu
  #define  MCASP_XMASK_XMASK28_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK28_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK28_USEMASK        	0x00000000u
  #define  MCASP_XMASK_XMASK28_NOMASK            	0x00000001u

  #define _MCASP_XMASK_XMASK29_MASK        	0x20000000u
  #define _MCASP_XMASK_XMASK29_SHIFT       	0x0000001Du
  #define  MCASP_XMASK_XMASK29_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK29_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK29_USEMASK        	0x00000000u
  #define  MCASP_XMASK_XMASK29_NOMASK            	0x00000001u

  #define _MCASP_XMASK_XMASK30_MASK        	0x40000000u
  #define _MCASP_XMASK_XMASK30_SHIFT       	0x0000001Eu
  #define  MCASP_XMASK_XMASK30_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK30_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK30_USEMASK        	0x00000000u
  #define  MCASP_XMASK_XMASK30_NOMASK            	0x00000001u

  #define _MCASP_XMASK_XMASK31_MASK        	0x80000000u
  #define _MCASP_XMASK_XMASK31_SHIFT       	0x0000001Fu
  #define  MCASP_XMASK_XMASK31_DEFAULT     	0x00000000u
  #define  MCASP_XMASK_XMASK31_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XMASK_XMASK31_USEMASK        	0x00000000u
  #define  MCASP_XMASK_XMASK31_NOMASK            	0x00000001u

  #define  MCASP_XMASK_OF(x)                	_VALUEOF(x)

  #define MCASP_XMASK_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,XMASK,XMASK0)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK1)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK2)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK3)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK4)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK5)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK6)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK7)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK8)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK9)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK10)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK11)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK12)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK13)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK14)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK15)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK16)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK17)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK18)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK19)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK20)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK21)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK22)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK23)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK24)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK25)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK26)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK27)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK28)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK29)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK30)\
    |_PER_FDEFAULT(MCASP,XMASK,XMASK31)\
  )

  #define MCASP_XMASK_RMK(xmask31, xmask30,xmask29,xmask28,xmask27,xmask26,xmask25,\
    xmask24,xmask23,xmask22,xmask21,xmask20,xmask19,xmask18,xmask17,\
   xmask16,xmask15,xmask14,xmask13,xmask12,xmask11,xmask10,xmask9,\
   xmask8, xmask7, xmask6,  xmask5,xmask4, xmask3, xmask2, xmask1, xmask0 ) \
 (Uint32)( \
     _PER_FMK(MCASP,XMASK,XMASK0,xmask0)\
    |_PER_FMK(MCASP,XMASK,XMASK1,xmask1)\
    |_PER_FMK(MCASP,XMASK,XMASK2,xmask2)\
    |_PER_FMK(MCASP,XMASK,XMASK3,xmask3)\
    |_PER_FMK(MCASP,XMASK,XMASK4,xmask4)\
    |_PER_FMK(MCASP,XMASK,XMASK5,xmask5)\
    |_PER_FMK(MCASP,XMASK,XMASK6,xmask6)\
    |_PER_FMK(MCASP,XMASK,XMASK7,xmask7)\
    |_PER_FMK(MCASP,XMASK,XMASK8,xmask8)\
    |_PER_FMK(MCASP,XMASK,XMASK9,xmask9)\
    |_PER_FMK(MCASP,XMASK,XMASK10,xmask10)\
    |_PER_FMK(MCASP,XMASK,XMASK11,xmask11)\
    |_PER_FMK(MCASP,XMASK,XMASK12,xmask12)\
    |_PER_FMK(MCASP,XMASK,XMASK13,xmask13)\
    |_PER_FMK(MCASP,XMASK,XMASK14,xmask14)\
    |_PER_FMK(MCASP,XMASK,XMASK15,xmask15)\
    |_PER_FMK(MCASP,XMASK,XMASK16,xmask16)\
    |_PER_FMK(MCASP,XMASK,XMASK17,xmask17)\
    |_PER_FMK(MCASP,XMASK,XMASK18,xmask18)\
    |_PER_FMK(MCASP,XMASK,XMASK19,xmask19)\
    |_PER_FMK(MCASP,XMASK,XMASK20,xmask20)\
    |_PER_FMK(MCASP,XMASK,XMASK21,xmask21)\
    |_PER_FMK(MCASP,XMASK,XMASK22,xmask22)\
    |_PER_FMK(MCASP,XMASK,XMASK23,xmask23)\
    |_PER_FMK(MCASP,XMASK,XMASK24,xmask24)\
    |_PER_FMK(MCASP,XMASK,XMASK25,xmask25)\
    |_PER_FMK(MCASP,XMASK,XMASK26,xmask26)\
    |_PER_FMK(MCASP,XMASK,XMASK27,xmask27)\
    |_PER_FMK(MCASP,XMASK,XMASK28,xmask28)\
    |_PER_FMK(MCASP,XMASK,XMASK29,xmask29)\
    |_PER_FMK(MCASP,XMASK,XMASK30,xmask30)\
    |_PER_FMK(MCASP,XMASK,XMASK31,xmask31)\
  )

  #define _MCASP_XMASK_FGET(N,FIELD)\
    _PER_FGET(_MCASP_XMASK##N##_ADDR,MCASP,XMASK,##FIELD)

  #define _MCASP_XMASK_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_XMASK##N##_ADDR,MCASP,XMASK,##FIELD,field)

  #define _MCASP_XMASK_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_XMASK##N##_ADDR,MCASP,XMASK,##FIELD,##SYM)

  #define _MCASP_XMASK0_FGET(FIELD) _MCASP_XMASK_FGET(0,##FIELD) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XMASK1_FGET(FIELD) _MCASP_XMASK_FGET(1,##FIELD) 
#endif

  #define _MCASP_XMASK0_FSET(FIELD,f) _MCASP_XMASK_FSET(0,##FIELD,f) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XMASK1_FSET(FIELD,f) _MCASP_XMASK_FSET(1,##FIELD,f) 
#endif

  #define _MCASP_XMASK0_FSETS(FIELD,SYM) _MCASP_XMASK_FSETS(0,##FIELD,##SYM) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XMASK1_FSETS(FIELD,SYM) _MCASP_XMASK_FSETS(1,##FIELD,##SYM) 
#endif

 
/******************************************************************************\
* 
* _____________________
* |                   |
* |     XFMT          |
* |___________________|
*
* XFMT		- Transmit Bitstream Format Register
*
* FIELDS (msb -> lsb)
* (rw)  XDATDLY
* (rw)  XRVRS  
* (rw)  XPAD
* (rw)  XPBIT  
* (rw)  XSSZ
* (rw)  XBUSEL
* (rw)  XROT  
*
\******************************************************************************/

  #define _MCASP_XFMT_OFFSET               42

  #define _MCASP_XFMT0_ADDR					(_MCASP_BASE_PORT0+4*_MCASP_XFMT_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XFMT1_ADDR					(_MCASP_BASE_PORT1+4*_MCASP_XFMT_OFFSET)
#endif

  #define _MCASP_XFMT_XDATDLY_MASK              0x00030000u
  #define _MCASP_XFMT_XDATDLY_SHIFT             0x00000010u
  #define  MCASP_XFMT_XDATDLY_DEFAULT           0x00000000u
  #define  MCASP_XFMT_XDATDLY_OF(x)             _VALUEOF(x)
  #define  MCASP_XFMT_XDATDLY_0BIT              0x00000000u
  #define  MCASP_XFMT_XDATDLY_1BIT              0x00000001u
  #define  MCASP_XFMT_XDATDLY_2BIT              0x00000002u


  #define _MCASP_XFMT_XRVRS_MASK                0x00008000u
  #define _MCASP_XFMT_XRVRS_SHIFT       	      0x0000000Fu
  #define  MCASP_XFMT_XRVRS_DEFAULT     	      0x00000000u
  #define  MCASP_XFMT_XRVRS_OF(x)   	        _VALUEOF(x)
  #define  MCASP_XFMT_XRVRS_LSBFIRST            0x00000000u
  #define  MCASP_XFMT_XRVRS_MSBFIRST            0x00000001u

  #define _MCASP_XFMT_XPAD_MASK     		0x00006000u
  #define _MCASP_XFMT_XPAD_SHIFT          	0x0000000Du
  #define  MCASP_XFMT_XPAD_DEFAULT        	0x00000000u
  #define  MCASP_XFMT_XPAD_OF(x)          	_VALUEOF(x)
  #define  MCASP_XFMT_XPAD_ZERO            	0x00000000u
  #define  MCASP_XFMT_XPAD_ONE            	0x00000001u
  #define  MCASP_XFMT_XPAD_XPBIT          	0x00000002u

  #define _MCASP_XFMT_XPBIT_MASK           	0x00001F00u
  #define _MCASP_XFMT_XPBIT_SHIFT          	0x00000008u
  #define  MCASP_XFMT_XPBIT_DEFAULT        	0x00000000u
  #define  MCASP_XFMT_XPBIT_OF(x)          	_VALUEOF(x)

  #define _MCASP_XFMT_XSSZ_MASK           	0x000000F0u
  #define _MCASP_XFMT_XSSZ_SHIFT          	0x00000004u
  #define  MCASP_XFMT_XSSZ_DEFAULT        	0x00000000u
  #define  MCASP_XFMT_XSSZ_OF(x)          	_VALUEOF(x)
  #define  MCASP_XFMT_XSSZ_8BITS            	0x00000003u
  #define  MCASP_XFMT_XSSZ_12BITS            	0x00000005u
  #define  MCASP_XFMT_XSSZ_16BITS            	0x00000007u
  #define  MCASP_XFMT_XSSZ_20BITS            	0x00000009u
  #define  MCASP_XFMT_XSSZ_24BITS            	0x0000000Bu
  #define  MCASP_XFMT_XSSZ_28BITS            	0x0000000Du
  #define  MCASP_XFMT_XSSZ_32BITS            	0x0000000Fu

  #define _MCASP_XFMT_XBUSEL_MASK           	0x00000008u
  #define _MCASP_XFMT_XBUSEL_SHIFT          	0x00000003u
  #define  MCASP_XFMT_XBUSEL_DEFAULT        	0x00000000u
  #define  MCASP_XFMT_XBUSEL_OF(x)         	_VALUEOF(x)
  #define  MCASP_XFMT_XBUSEL_DAT            	0x00000000u
  #define  MCASP_XFMT_XBUSEL_CFG            	0x00000001u

  #define _MCASP_XFMT_XROT_MASK           	0x00000007u
  #define _MCASP_XFMT_XROT_SHIFT          	0x00000000u
  #define  MCASP_XFMT_XROT_DEFAULT        	0x00000000u
  #define  MCASP_XFMT_XROT_OF(x)                _VALUEOF(x)
  #define  MCASP_XFMT_XROT_NONE            	0x00000000u
  #define  MCASP_XFMT_XROT_4BITS            	0x00000001u
  #define  MCASP_XFMT_XROT_8BITS            	0x00000002u
  #define  MCASP_XFMT_XROT_12BITS            	0x00000003u
  #define  MCASP_XFMT_XROT_16BITS            	0x00000004u
  #define  MCASP_XFMT_XROT_20BITS            	0x00000005u
  #define  MCASP_XFMT_XROT_24BITS            	0x00000006u
  #define  MCASP_XFMT_XROT_28BITS            	0x00000007u

  #define  MCASP_XFMT_OF(x)                	_VALUEOF(x)

  #define MCASP_XFMT_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,XFMT,XDATDLY)\
    |_PER_FDEFAULT(MCASP,XFMT,XRVRS)\
    |_PER_FDEFAULT(MCASP,XFMT,XPAD)\
    |_PER_FDEFAULT(MCASP,XFMT,XPBIT)\
    |_PER_FDEFAULT(MCASP,XFMT,XSSZ)\
    |_PER_FDEFAULT(MCASP,XFMT,XBUSEL)\
    |_PER_FDEFAULT(MCASP,XFMT,XROT)\
  )

  #define MCASP_XFMT_RMK(xdatdly,xrvrs,xpad,xpbit,xssz,xbusel,xrot) (Uint32)( \
     _PER_FMK(MCASP,XFMT,XDATDLY,xdatdly)\
    |_PER_FMK(MCASP,XFMT,XRVRS,xrvrs)\
    |_PER_FMK(MCASP,XFMT,XPAD,xpad)\
    |_PER_FMK(MCASP,XFMT,XPBIT,xpbit)\
    |_PER_FMK(MCASP,XFMT,XSSZ,xssz)\
    |_PER_FMK(MCASP,XFMT,XBUSEL,xbusel)\
    |_PER_FMK(MCASP,XFMT,XROT,xrot)\
  )

  #define _MCASP_XFMT_FGET(N,FIELD)\
    _PER_FGET(_MCASP_XFMT##N##_ADDR,MCASP,XFMT,##FIELD)

  #define _MCASP_XFMT_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_XFMT##N##_ADDR,MCASP,XFMT,##FIELD,field)

  #define _MCASP_XFMT_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_XFMT##N##_ADDR,MCASP,XFMT,##FIELD,##SYM)

  #define _MCASP_XFMT0_FGET(FIELD) _MCASP_XFMT_FGET(0,##FIELD) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XFMT1_FGET(FIELD) _MCASP_XFMT_FGET(1,##FIELD) 
#endif

  #define _MCASP_XFMT0_FSET(FIELD,f) _MCASP_XFMT_FSET(0,##FIELD,f) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XFMT1_FSET(FIELD,f) _MCASP_XFMT_FSET(1,##FIELD,f) 
#endif

  #define _MCASP_XFMT0_FSETS(FIELD,SYM) _MCASP_XFMT_FSETS(0,##FIELD,##SYM) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XFMT1_FSETS(FIELD,SYM) _MCASP_XFMT_FSETS(1,##FIELD,##SYM) 
#endif
 

/******************************************************************************\
* 
* _____________________
* |                   |
* |     AFSXCTL       |
* |___________________|
*
* AFSXCTL  -  Transmit Frame Control Register
*
* FIELDS (msb -> lsb)
* (rw)  XMOD
* (rw)  FXWID
* (rw)  FSXM
* (rw)  FSXP
*
\******************************************************************************/

  #define _MCASP_AFSXCTL_OFFSET             43

  #define _MCASP_AFSXCTL0_ADDR				(_MCASP_BASE_PORT0+4*_MCASP_AFSXCTL_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_AFSXCTL1_ADDR				(_MCASP_BASE_PORT1+4*_MCASP_AFSXCTL_OFFSET)
#endif

  #define _MCASP_AFSXCTL_XMOD_MASK              0x0000FF80u
  #define _MCASP_AFSXCTL_XMOD_SHIFT             0x00000007u
  #define  MCASP_AFSXCTL_XMOD_DEFAULT           0x00000000u
  #define  MCASP_AFSXCTL_XMOD_OF(x)             _VALUEOF(x)
  #define  MCASP_AFSXCTL_XMOD_BURST             0x00000000u

  #define _MCASP_AFSXCTL_FXWID_MASK              0x00000010u
  #define _MCASP_AFSXCTL_FXWID_SHIFT             0x00000004u
  #define  MCASP_AFSXCTL_FXWID_DEFAULT           0x00000000u
  #define  MCASP_AFSXCTL_FXWID_OF(x)             _VALUEOF(x)
  #define  MCASP_AFSXCTL_FXWID_BIT              0x00000000u
  #define  MCASP_AFSXCTL_FXWID_WORD             0x00000001u

  #define _MCASP_AFSXCTL_FSXM_MASK              0x00000002u
  #define _MCASP_AFSXCTL_FSXM_SHIFT             0x00000001u
  #define  MCASP_AFSXCTL_FSXM_DEFAULT           0x00000000u
  #define  MCASP_AFSXCTL_FSXM_OF(x)             _VALUEOF(x)
  #define  MCASP_AFSXCTL_FSXM_EXTERNAL          0x00000000u
  #define  MCASP_AFSXCTL_FSXM_INTERNAL          0x00000001u
  

  #define _MCASP_AFSXCTL_FSXP_MASK              0x00000001u
  #define _MCASP_AFSXCTL_FSXP_SHIFT             0x00000000u
  #define  MCASP_AFSXCTL_FSXP_DEFAULT           0x00000000u
  #define  MCASP_AFSXCTL_FSXP_OF(x)             _VALUEOF(x)
  #define  MCASP_AFSXCTL_FSXP_ACTIVEHIGH        0x00000000u
  #define  MCASP_AFSXCTL_FSXP_ACTIVELOW         0x00000001u
  

  #define  MCASP_AFSXCTL_OF(x)                _VALUEOF(x)

  #define MCASP_AFSXCTL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,AFSXCTL,XMOD)\
	| _PER_FDEFAULT(MCASP,AFSXCTL,FXWID)\
	| _PER_FDEFAULT(MCASP,AFSXCTL,FSXM)\
	| _PER_FDEFAULT(MCASP,AFSXCTL,FSXP)\
  )

  #define MCASP_AFSXCTL_RMK(xmod, fxwid, fsxm, fsxp) (Uint32)( \
     _PER_FMK(MCASP,AFSXCTL,XMOD,xmod)\
	| _PER_FMK(MCASP,AFSXCTL,FXWID,fxwid)\
	| _PER_FMK(MCASP,AFSXCTL,FSXM,fsxm)\
	| _PER_FMK(MCASP,AFSXCTL,FSXP,fsxp)\
  )

  #define _MCASP_AFSXCTL_FGET(N,FIELD)\
    _PER_FGET(_MCASP_AFSXCTL##N##_ADDR,MCASP,AFSXCTL,##FIELD)

  #define _MCASP_AFSXCTL_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_AFSXCTL##N##_ADDR,MCASP,AFSXCTL,##FIELD,field)

  #define _MCASP_AFSXCTL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_AFSXCTL##N##_ADDR,MCASP,AFSXCTL,##FIELD,##SYM)

  #define _MCASP_AFSXCTL0_FGET(FIELD) _MCASP_AFSXCTL_FGET(0,##FIELD) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_AFSXCTL1_FGET(FIELD) _MCASP_AFSXCTL_FGET(1,##FIELD) 
#endif

  #define _MCASP_AFSXCTL0_FSET(FIELD,f) _MCASP_AFSXCTL_FSET(0,##FIELD,f) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_AFSXCTL1_FSET(FIELD,f) _MCASP_AFSXCTL_FSET(1,##FIELD,f) 
#endif

  #define _MCASP_AFSXCTL0_FSETS(FIELD,SYM) _MCASP_AFSXCTL_FSETS(0,##FIELD,##SYM) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_AFSXCTL1_FSETS(FIELD,SYM) _MCASP_AFSXCTL_FSETS(1,##FIELD,##SYM) 
#endif


/******************************************************************************\
* 
* _____________________
* |                   |
* |     ACLKXCTL      |
* |___________________|
*
* ACLKXCTL  -  Transmit Clock Control Register
*
* FIELDS (msb -> lsb)
* (rw)  CLKXP  
* (rw)  ASYNC  
* (rw)  CLKXM  
* (rw)  CLKXDIV
*
*
\******************************************************************************/

  #define _MCASP_ACLKXCTL_OFFSET               44

  #define _MCASP_ACLKXCTL0_ADDR				(_MCASP_BASE_PORT0+4*_MCASP_ACLKXCTL_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_ACLKXCTL1_ADDR				(_MCASP_BASE_PORT1+4*_MCASP_ACLKXCTL_OFFSET)
#endif


  #define _MCASP_ACLKXCTL_CLKXP_MASK              0x00000080u
  #define _MCASP_ACLKXCTL_CLKXP_SHIFT             0x00000007u
  #define  MCASP_ACLKXCTL_CLKXP_DEFAULT           0x00000000u
  #define  MCASP_ACLKXCTL_CLKXP_OF(x)             _VALUEOF(x)
  #define  MCASP_ACLKXCTL_CLKXP_RISING            0x00000000u
  #define  MCASP_ACLKXCTL_CLKXP_FALLING           0x00000001u
  

  #define _MCASP_ACLKXCTL_ASYNC_MASK              0x00000040u
  #define _MCASP_ACLKXCTL_ASYNC_SHIFT             0x00000006u
  #define  MCASP_ACLKXCTL_ASYNC_DEFAULT           0x00000001u
  #define  MCASP_ACLKXCTL_ASYNC_OF(x)             _VALUEOF(x)
  #define  MCASP_ACLKXCTL_ASYNC_SYNC              0x00000000u
  #define  MCASP_ACLKXCTL_ASYNC_ASYNC             0x00000001u
  

  #define _MCASP_ACLKXCTL_CLKXM_MASK              0x00000020u
  #define _MCASP_ACLKXCTL_CLKXM_SHIFT             0x00000005u
  #define  MCASP_ACLKXCTL_CLKXM_DEFAULT           0x00000001u
  #define  MCASP_ACLKXCTL_CLKXM_OF(x)             _VALUEOF(x)
  #define  MCASP_ACLKXCTL_CLKXM_EXTERNAL          0x00000000u
  #define  MCASP_ACLKXCTL_CLKXM_INTERNAL            0x00000001u
  

  #define _MCASP_ACLKXCTL_CLKXDIV_MASK              0x0000001Fu
  #define _MCASP_ACLKXCTL_CLKXDIV_SHIFT             0x00000000u
  #define  MCASP_ACLKXCTL_CLKXDIV_DEFAULT           0x00000000u
  #define  MCASP_ACLKXCTL_CLKXDIV_OF(x)             _VALUEOF(x)

  #define  MCASP_ACLKXCTL_OF(x)                _VALUEOF(x)

  #define MCASP_ACLKXCTL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,ACLKXCTL,CLKXP)\
	| _PER_FDEFAULT(MCASP,ACLKXCTL,ASYNC)\
	| _PER_FDEFAULT(MCASP,ACLKXCTL,CLKXM)\
	| _PER_FDEFAULT(MCASP,ACLKXCTL,CLKXDIV)\
  )

  #define MCASP_ACLKXCTL_RMK(clkxp, async, clkxm, clkxdiv) (Uint32)( \
     _PER_FMK(MCASP,ACLKXCTL,CLKXP,clkxp)\
	| _PER_FMK(MCASP,ACLKXCTL,ASYNC,async)\
	| _PER_FMK(MCASP,ACLKXCTL,CLKXM,clkxm)\
	| _PER_FMK(MCASP,ACLKXCTL,CLKXDIV,clkxdiv)\
  )


  #define _MCASP_ACLKXCTL_FGET(N,FIELD)\
    _PER_FGET(_MCASP_ACLKXCTL##N##_ADDR,MCASP,ACLKXCTL,##FIELD)

  #define _MCASP_ACLKXCTL_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_ACLKXCTL##N##_ADDR,MCASP,ACLKXCTL,##FIELD,field)

  #define _MCASP_ACLKXCTL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_ACLKXCTL##N##_ADDR,MCASP,ACLKXCTL,##FIELD,##SYM)

  #define _MCASP_ACLKXCTL0_FGET(FIELD) _MCASP_ACLKXCTL_FGET(0,##FIELD) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_ACLKXCTL1_FGET(FIELD) _MCASP_ACLKXCTL_FGET(1,##FIELD) 
#endif

  #define _MCASP_ACLKXCTL0_FSET(FIELD,f) _MCASP_ACLKXCTL_FSET(0,##FIELD,f) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_ACLKXCTL1_FSET(FIELD,f) _MCASP_ACLKXCTL_FSET(1,##FIELD,f) 
#endif

  #define _MCASP_ACLKXCTL0_FSETS(FIELD,SYM) _MCASP_ACLKXCTL_FSETS(0,##FIELD,##SYM) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_ACLKXCTL1_FSETS(FIELD,SYM) _MCASP_ACLKXCTL_FSETS(1,##FIELD,##SYM) 
#endif


/******************************************************************************\
* 
* _____________________
* |                   |
* |     AHCLKXCTL     |
* |___________________|
*
* AHCLKXCTL  -  High Frequency Transmit Clock Control Register
*
* FIELDS (msb -> lsb)
* (rw)  HCLKXM 
* (rw)  HCLKXDIV 
*
\******************************************************************************/

  #define _MCASP_AHCLKXCTL_OFFSET           45

  #define _MCASP_AHCLKXCTL0_ADDR			(_MCASP_BASE_PORT0+4*_MCASP_AHCLKXCTL_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_AHCLKXCTL1_ADDR			(_MCASP_BASE_PORT1+4*_MCASP_AHCLKXCTL_OFFSET)
#endif

  #define _MCASP_AHCLKXCTL_HCLKXM_MASK              0x00008000u
  #define _MCASP_AHCLKXCTL_HCLKXM_SHIFT             0x0000000Fu
  #define  MCASP_AHCLKXCTL_HCLKXM_DEFAULT           0x00000001u
  #define  MCASP_AHCLKXCTL_HCLKXM_OF(x)             _VALUEOF(x)
  #define  MCASP_AHCLKXCTL_HCLKXM_EXTERNAL            0x00000000u
  #define  MCASP_AHCLKXCTL_HCLKXM_INTERNAL        0x00000001u

  #define _MCASP_AHCLKXCTL_HCLKXP_MASK              0x00004000u
  #define _MCASP_AHCLKXCTL_HCLKXP_SHIFT             0x0000000Eu
  #define  MCASP_AHCLKXCTL_HCLKXP_DEFAULT           0x00000000u
  #define  MCASP_AHCLKXCTL_HCLKXP_OF(x)             _VALUEOF(x)
  #define  MCASP_AHCLKXCTL_HCLKXP_RISING         0x00000000u
  #define  MCASP_AHCLKXCTL_HCLKXP_FALLING		  0x00000001u

  #define _MCASP_AHCLKXCTL_HCLKXDIV_MASK              0x00000FFFu
  #define _MCASP_AHCLKXCTL_HCLKXDIV_SHIFT             0x00000000u
  #define  MCASP_AHCLKXCTL_HCLKXDIV_DEFAULT           0x00000000u
  #define  MCASP_AHCLKXCTL_HCLKXDIV_OF(x)             _VALUEOF(x)


  #define  MCASP_AHCLKXCTL_OF(x)                _VALUEOF(x)

  #define MCASP_AHCLKXCTL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,AHCLKXCTL,HCLKXM)\
	| _PER_FDEFAULT(MCASP,AHCLKXCTL,HCLKXP)\
	| _PER_FDEFAULT(MCASP,AHCLKXCTL,HCLKXDIV)\
  )

  #define MCASP_AHCLKXCTL_RMK(hclkxm,hclkxp,hclkxdiv) (Uint32)( \
     _PER_FMK(MCASP,AHCLKXCTL,HCLKXM,hclkxm)\
	| _PER_FMK(MCASP,AHCLKXCTL,HCLKXP,hclkxp)\
	| _PER_FMK(MCASP,AHCLKXCTL,HCLKXDIV,hclkxdiv)\
  )

  #define _MCASP_AHCLKXCTL_FGET(N,FIELD)\
    _PER_FGET(_MCASP_AHCLKXCTL##N##_ADDR,MCASP,AHCLKXCTL,##FIELD)

  #define _MCASP_AHCLKXCTL_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_AHCLKXCTL##N##_ADDR,MCASP,AHCLKXCTL,##FIELD,field)

  #define _MCASP_AHCLKXCTL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_AHCLKXCTL##N##_ADDR,MCASP,AHCLKXCTL,##FIELD,##SYM)

  #define _MCASP_AHCLKXCTL0_FGET(FIELD) _MCASP_AHCLKXCTL_FGET(0,##FIELD) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_AHCLKXCTL1_FGET(FIELD) _MCASP_AHCLKXCTL_FGET(1,##FIELD) 
#endif

  #define _MCASP_AHCLKXCTL0_FSET(FIELD,f) _MCASP_AHCLKXCTL_FSET(0,##FIELD,f) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_AHCLKXCTL1_FSET(FIELD,f) _MCASP_AHCLKXCTL_FSET(1,##FIELD,f) 
#endif

  #define _MCASP_AHCLKXCTL0_FSETS(FIELD,SYM) _MCASP_AHCLKXCTL_FSETS(0,##FIELD,##SYM) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_AHCLKXCTL1_FSETS(FIELD,SYM) _MCASP_AHCLKXCTL_FSETS(1,##FIELD,##SYM) 
#endif


/******************************************************************************\
* 
* _____________________
* |                   |
* |    X  T  D  M     |
* |___________________|
*
* XTDM  -  Transmit TDM register
*
* FIELDS (msb -> lsb)
* (rw)  XTDMS0
* (rw)  XTDMS1
*   .
*   .
*   .
* (rw)  XTDMS31
*
\******************************************************************************/

  #define _MCASP_XTDM_OFFSET               46

  #define _MCASP_XTDM0_ADDR					(_MCASP_BASE_PORT0+4*_MCASP_XTDM_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XTDM1_ADDR					(_MCASP_BASE_PORT1+4*_MCASP_XTDM_OFFSET)
#endif

  #define _MCASP_XTDM_XTDMS31_MASK              0x80000000u
  #define _MCASP_XTDM_XTDMS31_SHIFT             0x0000001Fu
  #define  MCASP_XTDM_XTDMS31_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS31_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS31_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS31_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS30_MASK              0x40000000u
  #define _MCASP_XTDM_XTDMS30_SHIFT             0x0000001Eu
  #define  MCASP_XTDM_XTDMS30_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS30_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS30_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS30_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS29_MASK              0x20000000u
  #define _MCASP_XTDM_XTDMS29_SHIFT             0x0000001Du
  #define  MCASP_XTDM_XTDMS29_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS29_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS29_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS29_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS28_MASK              0x10000000u
  #define _MCASP_XTDM_XTDMS28_SHIFT             0x0000001Cu
  #define  MCASP_XTDM_XTDMS28_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS28_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS28_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS28_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS27_MASK              0x08000000u
  #define _MCASP_XTDM_XTDMS27_SHIFT             0x0000001Bu
  #define  MCASP_XTDM_XTDMS27_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS27_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS27_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS27_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS26_MASK              0x04000000u
  #define _MCASP_XTDM_XTDMS26_SHIFT             0x0000001Au
  #define  MCASP_XTDM_XTDMS26_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS26_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS26_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS26_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS25_MASK              0x02000000u
  #define _MCASP_XTDM_XTDMS25_SHIFT             0x00000019u
  #define  MCASP_XTDM_XTDMS25_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS25_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS25_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS25_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS24_MASK              0x01000000u
  #define _MCASP_XTDM_XTDMS24_SHIFT             0x00000018u
  #define  MCASP_XTDM_XTDMS24_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS24_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS24_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS24_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS23_MASK              0x00800000u
  #define _MCASP_XTDM_XTDMS23_SHIFT             0x00000017u
  #define  MCASP_XTDM_XTDMS23_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS23_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS23_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS23_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS22_MASK              0x00400000u
  #define _MCASP_XTDM_XTDMS22_SHIFT             0x00000016u
  #define  MCASP_XTDM_XTDMS22_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS22_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS22_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS22_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS21_MASK              0x00200000u
  #define _MCASP_XTDM_XTDMS21_SHIFT             0x00000015u
  #define  MCASP_XTDM_XTDMS21_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS21_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS21_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS21_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS20_MASK              0x00100000u
  #define _MCASP_XTDM_XTDMS20_SHIFT             0x00000014u
  #define  MCASP_XTDM_XTDMS20_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS20_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS20_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS20_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS19_MASK              0x00080000u
  #define _MCASP_XTDM_XTDMS19_SHIFT             0x00000013u
  #define  MCASP_XTDM_XTDMS19_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS19_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS19_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS19_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS18_MASK              0x00040000u
  #define _MCASP_XTDM_XTDMS18_SHIFT             0x00000012u
  #define  MCASP_XTDM_XTDMS18_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS18_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS18_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS18_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS17_MASK              0x00020000u
  #define _MCASP_XTDM_XTDMS17_SHIFT             0x00000011u
  #define  MCASP_XTDM_XTDMS17_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS17_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS17_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS17_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS16_MASK              0x00010000u
  #define _MCASP_XTDM_XTDMS16_SHIFT             0x00000010u
  #define  MCASP_XTDM_XTDMS16_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS16_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS16_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS16_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS15_MASK              0x00008000u
  #define _MCASP_XTDM_XTDMS15_SHIFT             0x0000000Fu
  #define  MCASP_XTDM_XTDMS15_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS15_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS15_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS15_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS14_MASK              0x00004000u
  #define _MCASP_XTDM_XTDMS14_SHIFT             0x0000000Eu
  #define  MCASP_XTDM_XTDMS14_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS14_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS14_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS14_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS13_MASK              0x00002000u
  #define _MCASP_XTDM_XTDMS13_SHIFT             0x0000000Du
  #define  MCASP_XTDM_XTDMS13_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS13_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS13_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS13_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS12_MASK              0x00001000u
  #define _MCASP_XTDM_XTDMS12_SHIFT             0x0000000Cu
  #define  MCASP_XTDM_XTDMS12_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS12_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS12_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS12_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS11_MASK              0x00000800u
  #define _MCASP_XTDM_XTDMS11_SHIFT             0x0000000Bu
  #define  MCASP_XTDM_XTDMS11_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS11_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS11_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS11_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS10_MASK              0x00000400u
  #define _MCASP_XTDM_XTDMS10_SHIFT             0x0000000Au
  #define  MCASP_XTDM_XTDMS10_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS10_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS10_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS10_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS9_MASK              0x00000200u
  #define _MCASP_XTDM_XTDMS9_SHIFT             0x00000009u
  #define  MCASP_XTDM_XTDMS9_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS9_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS9_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS9_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS8_MASK              0x00000100u
  #define _MCASP_XTDM_XTDMS8_SHIFT             0x00000008u
  #define  MCASP_XTDM_XTDMS8_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS8_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS8_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS8_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS7_MASK              0x00000080u
  #define _MCASP_XTDM_XTDMS7_SHIFT             0x00000007u
  #define  MCASP_XTDM_XTDMS7_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS7_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS7_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS7_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS6_MASK              0x00000040u
  #define _MCASP_XTDM_XTDMS6_SHIFT             0x00000006u
  #define  MCASP_XTDM_XTDMS6_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS6_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS6_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS6_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS5_MASK              0x00000020u
  #define _MCASP_XTDM_XTDMS5_SHIFT             0x00000005u
  #define  MCASP_XTDM_XTDMS5_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS5_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS5_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS5_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS4_MASK              0x00000010u
  #define _MCASP_XTDM_XTDMS4_SHIFT             0x00000004u
  #define  MCASP_XTDM_XTDMS4_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS4_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS4_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS4_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS3_MASK              0x00000008u
  #define _MCASP_XTDM_XTDMS3_SHIFT             0x00000003u
  #define  MCASP_XTDM_XTDMS3_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS3_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS3_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS3_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS2_MASK              0x00000004u
  #define _MCASP_XTDM_XTDMS2_SHIFT             0x00000002u
  #define  MCASP_XTDM_XTDMS2_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS2_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS2_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS2_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS1_MASK              0x00000002u
  #define _MCASP_XTDM_XTDMS1_SHIFT             0x00000001u
  #define  MCASP_XTDM_XTDMS1_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS1_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS1_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS1_ACTIVE            0x00000001u
  

  #define _MCASP_XTDM_XTDMS0_MASK              0x00000001u
  #define _MCASP_XTDM_XTDMS0_SHIFT             0x00000000u
  #define  MCASP_XTDM_XTDMS0_DEFAULT           0x00000000u
  #define  MCASP_XTDM_XTDMS0_OF(x)             _VALUEOF(x)
  #define  MCASP_XTDM_XTDMS0_INACTIVE          0x00000000u
  #define  MCASP_XTDM_XTDMS0_ACTIVE            0x00000001u
  

  #define  MCASP_XTDM_OF(x)                _VALUEOF(x)

  #define MCASP_XTDM_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,XTDM,XTDMS31)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS30)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS29)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS28)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS27)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS26)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS25)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS24)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS23)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS22)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS21)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS20)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS19)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS18)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS17)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS16)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS15)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS14)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS13)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS12)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS11)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS10)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS9)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS8)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS7)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS6)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS5)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS4)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS3)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS2)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS1)\
	| _PER_FDEFAULT(MCASP,XTDM,XTDMS0)\
  )

  #define MCASP_XTDM_RMK(xtdms31, xtdms30, xtdms29, xtdms28, xtdms27, xtdms26, xtdms25, xtdms24, xtdms23, xtdms22, xtdms21, xtdms20, xtdms19, xtdms18, xtdms17, xtdms16, xtdms15, xtdms14, xtdms13, xtdms12, xtdms11, xtdms10, xtdms9, xtdms8, xtdms7, xtdms6, xtdms5, xtdms4, xtdms3, xtdms2, xtdms1, xtdms0) (Uint32)( \
     _PER_FMK(MCASP,XTDM,XTDMS31,xtdms31)\
	| _PER_FMK(MCASP,XTDM,XTDMS30,xtdms30)\
	| _PER_FMK(MCASP,XTDM,XTDMS29,xtdms29)\
	| _PER_FMK(MCASP,XTDM,XTDMS28,xtdms28)\
	| _PER_FMK(MCASP,XTDM,XTDMS27,xtdms27)\
	| _PER_FMK(MCASP,XTDM,XTDMS26,xtdms26)\
	| _PER_FMK(MCASP,XTDM,XTDMS25,xtdms25)\
	| _PER_FMK(MCASP,XTDM,XTDMS24,xtdms24)\
	| _PER_FMK(MCASP,XTDM,XTDMS23,xtdms23)\
	| _PER_FMK(MCASP,XTDM,XTDMS22,xtdms22)\
	| _PER_FMK(MCASP,XTDM,XTDMS21,xtdms21)\
	| _PER_FMK(MCASP,XTDM,XTDMS20,xtdms20)\
	| _PER_FMK(MCASP,XTDM,XTDMS19,xtdms19)\
	| _PER_FMK(MCASP,XTDM,XTDMS18,xtdms18)\
	| _PER_FMK(MCASP,XTDM,XTDMS17,xtdms17)\
	| _PER_FMK(MCASP,XTDM,XTDMS16,xtdms16)\
	| _PER_FMK(MCASP,XTDM,XTDMS15,xtdms15)\
	| _PER_FMK(MCASP,XTDM,XTDMS14,xtdms14)\
	| _PER_FMK(MCASP,XTDM,XTDMS13,xtdms13)\
	| _PER_FMK(MCASP,XTDM,XTDMS12,xtdms12)\
	| _PER_FMK(MCASP,XTDM,XTDMS11,xtdms11)\
	| _PER_FMK(MCASP,XTDM,XTDMS10,xtdms10)\
	| _PER_FMK(MCASP,XTDM,XTDMS9,xtdms9)\
	| _PER_FMK(MCASP,XTDM,XTDMS8,xtdms8)\
	| _PER_FMK(MCASP,XTDM,XTDMS7,xtdms7)\
	| _PER_FMK(MCASP,XTDM,XTDMS6,xtdms6)\
	| _PER_FMK(MCASP,XTDM,XTDMS5,xtdms5)\
	| _PER_FMK(MCASP,XTDM,XTDMS4,xtdms4)\
	| _PER_FMK(MCASP,XTDM,XTDMS3,xtdms3)\
	| _PER_FMK(MCASP,XTDM,XTDMS2,xtdms2)\
	| _PER_FMK(MCASP,XTDM,XTDMS1,xtdms1)\
	| _PER_FMK(MCASP,XTDM,XTDMS0,xtdms0)\
  )


  #define _MCASP_XTDM_FGET(N,FIELD)\
    _PER_FGET(_MCASP_XTDM##N##_ADDR,MCASP,XTDM,##FIELD)

  #define _MCASP_XTDM_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_XTDM##N##_ADDR,MCASP,XTDM,##FIELD,field)

  #define _MCASP_XTDM_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_XTDM##N##_ADDR,MCASP,XTDM,##FIELD,##SYM)

  #define _MCASP_XTDM0_FGET(FIELD) _MCASP_XTDM_FGET(0,##FIELD) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XTDM1_FGET(FIELD) _MCASP_XTDM_FGET(1,##FIELD) 
#endif

  #define _MCASP_XTDM0_FSET(FIELD,f) _MCASP_XTDM_FSET(0,##FIELD,f) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XTDM1_FSET(FIELD,f) _MCASP_XTDM_FSET(1,##FIELD,f) 
#endif

  #define _MCASP_XTDM0_FSETS(FIELD,SYM) _MCASP_XTDM_FSETS(0,##FIELD,##SYM) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XTDM1_FSETS(FIELD,SYM) _MCASP_XTDM_FSETS(1,##FIELD,##SYM) 
#endif


/******************************************************************************\
* 
* _____________________
* |                   |
* |     XINTCTL       |
* |___________________|
*
* XINTCTL  -  Transmitter Interrupt Control Register
*
* FIELDS (msb -> lsb)
* (rw)  XSTAFRM  
* (rw)  XDATA 
* (rw)  XLAST  
* (rw)  XDMAERR
* (rw)  XCKFAIL  
* (rw)  XSYNCERR  
* (rw)  XUNDRN  
*
\******************************************************************************/

  #define _MCASP_XINTCTL_OFFSET             47

  #define _MCASP_XINTCTL0_ADDR				(_MCASP_BASE_PORT0+4*_MCASP_XINTCTL_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XINTCTL1_ADDR				(_MCASP_BASE_PORT1+4*_MCASP_XINTCTL_OFFSET)
#endif

  #define _MCASP_XINTCTL_XSTAFRM_MASK              0x00000080u
  #define _MCASP_XINTCTL_XSTAFRM_SHIFT             0x00000007u
  #define  MCASP_XINTCTL_XSTAFRM_DEFAULT           0x00000000u
  #define  MCASP_XINTCTL_XSTAFRM_OF(x)             _VALUEOF(x)
  #define  MCASP_XINTCTL_XSTAFRM_DISABLE          0x00000000u
  #define  MCASP_XINTCTL_XSTAFRM_ENABLE           0x00000001u


  #define _MCASP_XINTCTL_XDATA_MASK              0x00000020u
  #define _MCASP_XINTCTL_XDATA_SHIFT             0x00000005u
  #define  MCASP_XINTCTL_XDATA_DEFAULT           0x00000000u
  #define  MCASP_XINTCTL_XDATA_OF(x)             _VALUEOF(x)
  #define  MCASP_XINTCTL_XDATA_DISABLE          0x00000000u
  #define  MCASP_XINTCTL_XDATA_ENABLE           0x00000001u


  #define _MCASP_XINTCTL_XLAST_MASK              0x00000010u
  #define _MCASP_XINTCTL_XLAST_SHIFT             0x00000004u
  #define  MCASP_XINTCTL_XLAST_DEFAULT           0x00000000u
  #define  MCASP_XINTCTL_XLAST_OF(x)             _VALUEOF(x)
  #define  MCASP_XINTCTL_XLAST_DISABLE          0x00000000u
  #define  MCASP_XINTCTL_XLAST_ENABLE           0x00000001u


  #define _MCASP_XINTCTL_XDMAERR_MASK              0x00000008u
  #define _MCASP_XINTCTL_XDMAERR_SHIFT             0x00000003u
  #define  MCASP_XINTCTL_XDMAERR_DEFAULT           0x00000000u
  #define  MCASP_XINTCTL_XDMAERR_OF(x)             _VALUEOF(x)
  #define  MCASP_XINTCTL_XDMAERR_DISABLE        0x00000000u
  #define  MCASP_XINTCTL_XDMAERR_ENABLE          0x00000001u


  #define _MCASP_XINTCTL_XCKFAIL_MASK              0x00000004u
  #define _MCASP_XINTCTL_XCKFAIL_SHIFT             0x00000002u
  #define  MCASP_XINTCTL_XCKFAIL_DEFAULT           0x00000000u
  #define  MCASP_XINTCTL_XCKFAIL_OF(x)             _VALUEOF(x)
  #define  MCASP_XINTCTL_XCKFAIL_DISABLE          0x00000000u
  #define  MCASP_XINTCTL_XCKFAIL_ENABLE           0x00000001u


  #define _MCASP_XINTCTL_XSYNCERR_MASK              0x00000002u
  #define _MCASP_XINTCTL_XSYNCERR_SHIFT             0x00000001u
  #define  MCASP_XINTCTL_XSYNCERR_DEFAULT           0x00000000u
  #define  MCASP_XINTCTL_XSYNCERR_OF(x)             _VALUEOF(x)
  #define  MCASP_XINTCTL_XSYNCERR_DISABLE          0x00000000u
  #define  MCASP_XINTCTL_XSYNCERR_ENABLE           0x00000001u


  #define _MCASP_XINTCTL_XUNDRN_MASK              0x00000001u
  #define _MCASP_XINTCTL_XUNDRN_SHIFT             0x00000000u
  #define  MCASP_XINTCTL_XUNDRN_DEFAULT           0x00000000u
  #define  MCASP_XINTCTL_XUNDRN_OF(x)             _VALUEOF(x)
  #define  MCASP_XINTCTL_XUNDRN_DISABLE          0x00000000u
  #define  MCASP_XINTCTL_XUNDRN_ENABLE           0x00000001u


  #define  MCASP_XINTCTL_OF(x)                _VALUEOF(x)



  #define MCASP_XINTCTL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,XINTCTL,XSTAFRM)\
    |_PER_FDEFAULT(MCASP,XINTCTL,XDATA)\
    |_PER_FDEFAULT(MCASP,XINTCTL,XLAST)\
    |_PER_FDEFAULT(MCASP,XINTCTL,XDMAERR)\
    |_PER_FDEFAULT(MCASP,XINTCTL,XCKFAIL)\
    |_PER_FDEFAULT(MCASP,XINTCTL,XSYNCERR)\
    |_PER_FDEFAULT(MCASP,XINTCTL,XUNDRN)\
  )


  #define MCASP_XINTCTL_RMK(xstafrm, xdata, xlast, xdmaerr, xckfail, xsyncerr, xundrn) (Uint32)( \
     _PER_FMK(MCASP,XINTCTL,XSTAFRM,xstafrm)\
    |_PER_FMK(MCASP,XINTCTL,XDATA,xdata)\
    |_PER_FMK(MCASP,XINTCTL,XLAST,xlast)\
    |_PER_FMK(MCASP,XINTCTL,XDMAERR,xdmaerr)\
    |_PER_FMK(MCASP,XINTCTL,XCKFAIL,xckfail)\
    |_PER_FMK(MCASP,XINTCTL,XSYNCERR,xsyncerr)\
    |_PER_FMK(MCASP,XINTCTL,XUNDRN,xundrn)\
  )


  #define _MCASP_XINTCTL_FGET(N,FIELD)\
    _PER_FGET(_MCASP_XINTCTL##N##_ADDR,MCASP,XINTCTL,##FIELD)

  #define _MCASP_XINTCTL_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_XINTCTL##N##_ADDR,MCASP,XINTCTL,##FIELD,field)

  #define _MCASP_XINTCTL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_XINTCTL##N##_ADDR,MCASP,XINTCTL,##FIELD,##SYM)

  #define _MCASP_XINTCTL0_FGET(FIELD) _MCASP_XINTCTL_FGET(0,##FIELD) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XINTCTL1_FGET(FIELD) _MCASP_XINTCTL_FGET(1,##FIELD) 
#endif

  #define _MCASP_XINTCTL0_FSET(FIELD,f) _MCASP_XINTCTL_FSET(0,##FIELD,f) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XINTCTL1_FSET(FIELD,f) _MCASP_XINTCTL_FSET(1,##FIELD,f) 
#endif

  #define _MCASP_XINTCTL0_FSETS(FIELD,SYM) _MCASP_XINTCTL_FSETS(0,##FIELD,##SYM) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XINTCTL1_FSETS(FIELD,SYM) _MCASP_XINTCTL_FSETS(1,##FIELD,##SYM) 
#endif


/******************************************************************************\
* 
* _____________________
* |                   |
* |       XSTAT       |
* |___________________|
*
* XSTAT  -  Transmitter Status Register
*
* FIELDS (msb -> lsb)
* (r)  XERR  
* (r)  XDMAERR  
* (r)  XSTAFRM  
* (r)  XDATA  
* (r)  XLAST 
* (r)  XTDMSLOT  
* (r)  XCKFAIL  
* (r)  XSYNCERR  
* (r)  XUNDRN  
*
\******************************************************************************/

  #define _MCASP_XSTAT_OFFSET               48

  #define _MCASP_XSTAT0_ADDR				(_MCASP_BASE_PORT0+4*_MCASP_XSTAT_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XSTAT1_ADDR				(_MCASP_BASE_PORT1+4*_MCASP_XSTAT_OFFSET)
#endif

  #define _MCASP_XSTAT_XERR_MASK              0x00000100u
  #define _MCASP_XSTAT_XERR_SHIFT             0x00000008u
  #define  MCASP_XSTAT_XERR_DEFAULT           0x00000000u
  #define  MCASP_XSTAT_XERR_OF(x)             _VALUEOF(x)

  #define _MCASP_XSTAT_XDMAERR_MASK              0x0000080u
  #define _MCASP_XSTAT_XDMAERR_SHIFT             0x00000007u
  #define  MCASP_XSTAT_XDMAERR_DEFAULT           0x00000000u
  #define  MCASP_XSTAT_XDMAERR_OF(x)             _VALUEOF(x)

  #define _MCASP_XSTAT_XSTAFRM_MASK              0x00000040u
  #define _MCASP_XSTAT_XSTAFRM_SHIFT             0x00000006u
  #define  MCASP_XSTAT_XSTAFRM_DEFAULT           0x00000000u
  #define  MCASP_XSTAT_XSTAFRM_OF(x)             _VALUEOF(x)
  #define  MCASP_XSTAT_XSTAFRM_NO                0x00000000u
  #define  MCASP_XSTAT_XSTAFRM_YES               0x00000001u
  #define  MCASP_XSTAT_XSTAFRM_0                 0x00000000u
  #define  MCASP_XSTAT_XSTAFRM_1                 0x00000001u


  #define _MCASP_XSTAT_XDATA_MASK              0x00000020u
  #define _MCASP_XSTAT_XDATA_SHIFT             0x00000005u
  #define  MCASP_XSTAT_XDATA_DEFAULT           0x00000000u
  #define  MCASP_XSTAT_XDATA_OF(x)             _VALUEOF(x)
  #define  MCASP_XSTAT_XDATA_NO                0x00000000u
  #define  MCASP_XSTAT_XDATA_YES               0x00000001u
  #define  MCASP_XSTAT_XDATA_0                 0x00000000u
  #define  MCASP_XSTAT_XDATA_1                 0x00000001u

  #define _MCASP_XSTAT_XLAST_MASK              0x00000010u
  #define _MCASP_XSTAT_XLAST_SHIFT             0x00000004u
  #define  MCASP_XSTAT_XLAST_DEFAULT           0x00000000u
  #define  MCASP_XSTAT_XLAST_OF(x)             _VALUEOF(x)
  #define  MCASP_XSTAT_XLAST_NO                0x00000000u
  #define  MCASP_XSTAT_XLAST_YES               0x00000001u
  #define  MCASP_XSTAT_XLAST_0                 0x00000000u
  #define  MCASP_XSTAT_XLAST_1                 0x00000001u


  #define _MCASP_XSTAT_XTDMSLOT_MASK            0x00000008u
  #define _MCASP_XSTAT_XTDMSLOT_SHIFT           0x00000003u
  #define  MCASP_XSTAT_XTDMSLOT_DEFAULT         0x00000000u
  #define  MCASP_XSTAT_XTDMSLOT_OF(x)             _VALUEOF(x)


  #define _MCASP_XSTAT_XCKFAIL_MASK              0x00000004u
  #define _MCASP_XSTAT_XCKFAIL_SHIFT             0x00000002u
  #define  MCASP_XSTAT_XCKFAIL_DEFAULT           0x00000000u
  #define  MCASP_XSTAT_XCKFAIL_OF(x)             _VALUEOF(x)
  #define  MCASP_XSTAT_XCKFAIL_NO                0x00000000u
  #define  MCASP_XSTAT_XCKFAIL_YES               0x00000001u
  #define  MCASP_XSTAT_XCKFAIL_0                 0x00000000u
  #define  MCASP_XSTAT_XCKFAIL_1                 0x00000001u


  #define _MCASP_XSTAT_XSYNCERR_MASK              0x00000002u
  #define _MCASP_XSTAT_XSYNCERR_SHIFT             0x00000001u
  #define  MCASP_XSTAT_XSYNCERR_DEFAULT           0x00000000u
  #define  MCASP_XSTAT_XSYNCERR_OF(x)             _VALUEOF(x)
  #define  MCASP_XSTAT_XSYNCERR_NO                0x00000000u
  #define  MCASP_XSTAT_XSYNCERR_YES               0x00000001u
  #define  MCASP_XSTAT_XSYNCERR_0                 0x00000000u
  #define  MCASP_XSTAT_XSYNCERR_1                 0x00000001u


  #define _MCASP_XSTAT_XUNDRN_MASK              0x00000001u
  #define _MCASP_XSTAT_XUNDRN_SHIFT             0x00000000u
  #define  MCASP_XSTAT_XUNDRN_DEFAULT           0x00000000u
  #define  MCASP_XSTAT_XUNDRN_OF(x)             _VALUEOF(x)
  #define  MCASP_XSTAT_XUNDRN_NO                0x00000000u 
  #define  MCASP_XSTAT_XUNDRN_YES               0x00000001u 
  #define  MCASP_XSTAT_XUNDRN_0                0x00000000u 
  #define  MCASP_XSTAT_XUNDRN_1               0x00000001u 


  #define  MCASP_XSTAT_OF(x)                _VALUEOF(x)

  #define MCASP_XSTAT_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,XSTAT,XERR)\
    | _PER_FDEFAULT(MCASP,XSTAT,XDMAERR)\
	| _PER_FDEFAULT(MCASP,XSTAT,XSTAFRM)\
	| _PER_FDEFAULT(MCASP,XSTAT,XDATA)\
	| _PER_FDEFAULT(MCASP,XSTAT,XLAST)\
	| _PER_FDEFAULT(MCASP,XSTAT,XTDMSLOT)\
	| _PER_FDEFAULT(MCASP,XSTAT,XCKFAIL)\
	| _PER_FDEFAULT(MCASP,XSTAT,XSYNCERR)\
	| _PER_FDEFAULT(MCASP,XSTAT,XUNDRN)\
  )

  #define MCASP_XSTAT_RMK(xerr, xdmaerr, xstafrm, xdata, xlast, xtdmslot, xckfail, xsyncerr, xundrn) (Uint32)( \
     _PER_FMK(MCASP,XSTAT,XERR,xerr)\
    | _PER_FMK(MCASP,XSTAT,XDMAERR,xdmaerr)\
	| _PER_FMK(MCASP,XSTAT,XSTAFRM,xstafrm)\
	| _PER_FMK(MCASP,XSTAT,XDATA,xdata)\
	| _PER_FMK(MCASP,XSTAT,XLAST,xlast)\
	| _PER_FMK(MCASP,XSTAT,XTDMSLOT,xtdmslot)\
	| _PER_FMK(MCASP,XSTAT,XCKFAIL,xckfail)\
	| _PER_FMK(MCASP,XSTAT,XSYNCERR,xsyncerr)\
	| _PER_FMK(MCASP,XSTAT,XUNDRN,xundrn)\
  )

  #define _MCASP_XSTAT_FGET(N,FIELD)\
    _PER_FGET(_MCASP_XSTAT##N##_ADDR,MCASP,XSTAT,##FIELD)

  #define _MCASP_XSTAT_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_XSTAT##N##_ADDR,MCASP,XSTAT,##FIELD,field)

  #define _MCASP_XSTAT_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_XSTAT##N##_ADDR,MCASP,XSTAT,##FIELD,##SYM)

  #define _MCASP_XSTAT0_FGET(FIELD) _MCASP_XSTAT_FGET(0,##FIELD) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XSTAT1_FGET(FIELD) _MCASP_XSTAT_FGET(1,##FIELD) 
#endif

  #define _MCASP_XSTAT0_FSET(FIELD,f) _MCASP_XSTAT_FSET(0,##FIELD,f) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XSTAT1_FSET(FIELD,f) _MCASP_XSTAT_FSET(1,##FIELD,f) 
#endif

  #define _MCASP_XSTAT0_FSETS(FIELD,SYM) _MCASP_XSTAT_FSETS(0,##FIELD,##SYM) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XSTAT1_FSETS(FIELD,SYM) _MCASP_XSTAT_FSETS(1,##FIELD,##SYM) 
#endif


/******************************************************************************\
* 
* _____________________
* |                   |
* |     XSLOT         |
* |___________________|
*
* XSLOT  -  Transmitter TDM Slot Counter
*
* FIELDS (msb -> lsb)
* (r )  XSLOTCNT  
*
\******************************************************************************/

  #define _MCASP_XSLOT_OFFSET               49

  #define _MCASP_XSLOT0_ADDR				(_MCASP_BASE_PORT0+4*_MCASP_XSLOT_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XSLOT1_ADDR				(_MCASP_BASE_PORT1+4*_MCASP_XSLOT_OFFSET)
#endif

  #define _MCASP_XSLOT_XSLOTCNT_MASK              0x000003FFu
  #define _MCASP_XSLOT_XSLOTCNT_SHIFT             0x00000000u
  #define  MCASP_XSLOT_XSLOTCNT_DEFAULT           0x0000017Fu /*383*/
  #define  MCASP_XSLOT_XSLOTCNT_OF(x)             _VALUEOF(x)

  #define  MCASP_XSLOT_OF(x)                _VALUEOF(x)

  #define MCASP_XSLOT_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,XSLOT,XSLOTCNT)\
  )

  #define MCASP_XSLOT_RMK(xslotcnt) (Uint32)( \
     _PER_FMK(MCASP,XSLOT,XSLOTCNT,xslotcnt)\
  )

  #define _MCASP_XSLOT_FGET(N,FIELD)\
    _PER_FGET(_MCASP_XSLOT##N##_ADDR,MCASP,XSLOT,##FIELD)

  #define _MCASP_XSLOT_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_XSLOT##N##_ADDR,MCASP,XSLOT,##FIELD,field)

  #define _MCASP_XSLOT_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_XSLOT##N##_ADDR,MCASP,XSLOT,##FIELD,##SYM)

  #define _MCASP_XSLOT0_FGET(FIELD) _MCASP_XSLOT_FGET(0,##FIELD) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XSLOT1_FGET(FIELD) _MCASP_XSLOT_FGET(1,##FIELD) 
#endif

  #define _MCASP_XSLOT0_FSET(FIELD,f) _MCASP_XSLOT_FSET(0,##FIELD,f) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XSLOT1_FSET(FIELD,f) _MCASP_XSLOT_FSET(1,##FIELD,f) 
#endif

  #define _MCASP_XSLOT0_FSETS(FIELD,SYM) _MCASP_XSLOT_FSETS(0,##FIELD,##SYM) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XSLOT1_FSETS(FIELD,SYM) _MCASP_XSLOT_FSETS(1,##FIELD,##SYM) 
#endif


/******************************************************************************\
* 
* _____________________
* |                   |
* |     XCLKCHK       |
* |___________________|
*
* XCLKCHK  -  Transmit Clock Check Control Register
*
* FIELDS (msb -> lsb)
* (r )  XCNT  
* (rw)  XMAX  
* (rw)  XMIN  
* (rw)  XFAILSW  
* (rw)  XPS  
\******************************************************************************/

  #define _MCASP_XCLKCHK_OFFSET             50

  #define _MCASP_XCLKCHK0_ADDR				(_MCASP_BASE_PORT0+4*_MCASP_XCLKCHK_OFFSET)
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XCLKCHK1_ADDR				(_MCASP_BASE_PORT1+4*_MCASP_XCLKCHK_OFFSET)
#endif

  #define _MCASP_XCLKCHK_XCNT_MASK              0xFF000000u
  #define _MCASP_XCLKCHK_XCNT_SHIFT             0x00000018u
  #define  MCASP_XCLKCHK_XCNT_DEFAULT           0x00000000u 
  #define  MCASP_XCLKCHK_XCNT_OF(x)             _VALUEOF(x)


  #define _MCASP_XCLKCHK_XMAX_MASK              0x00FF0000u
  #define _MCASP_XCLKCHK_XMAX_SHIFT             0x00000010u
  #define  MCASP_XCLKCHK_XMAX_DEFAULT           0x00000000u 
  #define  MCASP_XCLKCHK_XMAX_OF(x)             _VALUEOF(x)

  #define _MCASP_XCLKCHK_XMIN_MASK              0x0000FF00u
  #define _MCASP_XCLKCHK_XMIN_SHIFT             0x00000008u
  #define  MCASP_XCLKCHK_XMIN_DEFAULT           0x00000000u 
  #define  MCASP_XCLKCHK_XMIN_OF(x)             _VALUEOF(x)

  #define _MCASP_XCLKCHK_XCKFAILSW_MASK              0x00000080u
  #define _MCASP_XCLKCHK_XCKFAILSW_SHIFT             0x00000007u
  #define  MCASP_XCLKCHK_XCKFAILSW_DEFAULT           0x00000000u 
  #define  MCASP_XCLKCHK_XCKFAILSW_OF(x)             _VALUEOF(x)
  #define  MCASP_XCLKCHK_XCKFAILSW_DISABLE          0x00000000u
  #define  MCASP_XCLKCHK_XCKFAILSW_ENABLE           0x00000001u


  #define _MCASP_XCLKCHK_XPS_MASK              0x0000000Fu
  #define _MCASP_XCLKCHK_XPS_SHIFT             0x00000000u
  #define  MCASP_XCLKCHK_XPS_DEFAULT           0x00000000u 
  #define  MCASP_XCLKCHK_XPS_OF(x)             _VALUEOF(x)
  #define  MCASP_XCLKCHK_XPS_DIVBY1            0x00000000u
  #define  MCASP_XCLKCHK_XPS_DIVBY2            0x00000001u
  #define  MCASP_XCLKCHK_XPS_DIVBY4            0x00000002u
  #define  MCASP_XCLKCHK_XPS_DIVBY8            0x00000003u 
  #define  MCASP_XCLKCHK_XPS_DIVBY16           0x00000004u 
  #define  MCASP_XCLKCHK_XPS_DIVBY32           0x00000005u 
  #define  MCASP_XCLKCHK_XPS_DIVBY64           0x00000006u 
  #define  MCASP_XCLKCHK_XPS_DIVBY128          0x00000007u 
  #define  MCASP_XCLKCHK_XPS_DIVBY256          0x00000008u 


  #define  MCASP_XCLKCHK_OF(x)                _VALUEOF(x)

  #define MCASP_XCLKCHK_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,XCLKCHK,XCNT)\
	| _PER_FDEFAULT(MCASP,XCLKCHK,XMAX)\
	| _PER_FDEFAULT(MCASP,XCLKCHK,XMIN)\
	| _PER_FDEFAULT(MCASP,XCLKCHK,XCKFAILSW)\
	| _PER_FDEFAULT(MCASP,XCLKCHK,XPS)\
  )

  #define MCASP_XCLKCHK_RMK(xcnt, xmax, xmin, xckfailsw, xps) (Uint32)( \
     _PER_FMK(MCASP,XCLKCHK,XCNT,xcnt)\
	| _PER_FMK(MCASP,XCLKCHK,XMAX,xmax)\
	| _PER_FMK(MCASP,XCLKCHK,XMIN,xmin)\
	| _PER_FMK(MCASP,XCLKCHK,XCKFAILSW,xckfailsw)\
	| _PER_FMK(MCASP,XCLKCHK,XPS,xps)\
  )

  #define _MCASP_XCLKCHK_FGET(N,FIELD)\
    _PER_FGET(_MCASP_XCLKCHK##N##_ADDR,MCASP,XCLKCHK,##FIELD)

  #define _MCASP_XCLKCHK_FSET(N,FIELD,field)\
    _PER_FSET(_MCASP_XCLKCHK##N##_ADDR,MCASP,XCLKCHK,##FIELD,field)

  #define _MCASP_XCLKCHK_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_XCLKCHK##N##_ADDR,MCASP,XCLKCHK,##FIELD,##SYM)

  #define _MCASP_XCLKCHK0_FGET(FIELD) _MCASP_XCLKCHK_FGET(0,##FIELD) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XCLKCHK1_FGET(FIELD) _MCASP_XCLKCHK_FGET(1,##FIELD) 
#endif

  #define _MCASP_XCLKCHK0_FSET(FIELD,f) _MCASP_XCLKCHK_FSET(0,##FIELD,f) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XCLKCHK1_FSET(FIELD,f) _MCASP_XCLKCHK_FSET(1,##FIELD,f) 
#endif

  #define _MCASP_XCLKCHK0_FSETS(FIELD,SYM) _MCASP_XCLKCHK_FSETS(0,##FIELD,##SYM) 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XCLKCHK1_FSETS(FIELD,SYM) _MCASP_XCLKCHK_FSETS(1,##FIELD,##SYM) 
#endif


/******************************************************************************\
*  
* _____________________
* |                   |
* |       DITCSR      |
* |_______n: 0-15_____|
*
* DITCSR  -  Channel Status Register File
*
* FIELDS (msb -> lsb)
* (rw)  DITCSRA0	- Left (even TDM slot)  
* (rw)  DITCSRA1  
* (rw)  DITCSRA2  
* (rw)  DITCSRA3  
* (rw)  DITCSRA4  
* (rw)  DITCSRA5  
* (rw)  DITCSRB0  	- Right (odd TDM slot)
* (rw)  DITCSRB1  
* (rw)  DITCSRB2  
* (rw)  DITCSRB3  
* (rw)  DITCSRB4  
* (rw)  DITCSRB5  
*
\******************************************************************************/

  #define _MCASP_DITCSRA0_OFFSET               64
  #define _MCASP_DITCSRA1_OFFSET               65
  #define _MCASP_DITCSRA2_OFFSET               66
  #define _MCASP_DITCSRA3_OFFSET               67
  #define _MCASP_DITCSRA4_OFFSET               68
  #define _MCASP_DITCSRA5_OFFSET               69

  #define _MCASP_DITCSRB0_OFFSET               70
  #define _MCASP_DITCSRB1_OFFSET               71
  #define _MCASP_DITCSRB2_OFFSET               72
  #define _MCASP_DITCSRB3_OFFSET               73
  #define _MCASP_DITCSRB4_OFFSET               74
  #define _MCASP_DITCSRB5_OFFSET               75

/* registers for MCASP0 */  
  #define _MCASP_DITCSR0_ADDR                 (_MCASP_BASE_PORT0 + 4*_MCASP_DITCSRA0_OFFSET)
  #define _MCASP_DITCSRA00_ADDR               (_MCASP_BASE_PORT0 + 4*_MCASP_DITCSRA0_OFFSET)
  #define _MCASP_DITCSRA10_ADDR               (_MCASP_BASE_PORT0 + 4*_MCASP_DITCSRA1_OFFSET)
  #define _MCASP_DITCSRA20_ADDR               (_MCASP_BASE_PORT0 + 4*_MCASP_DITCSRA2_OFFSET)
  #define _MCASP_DITCSRA30_ADDR               (_MCASP_BASE_PORT0 + 4*_MCASP_DITCSRA3_OFFSET)
  #define _MCASP_DITCSRA40_ADDR               (_MCASP_BASE_PORT0 + 4*_MCASP_DITCSRA4_OFFSET)
  #define _MCASP_DITCSRA50_ADDR               (_MCASP_BASE_PORT0 + 4*_MCASP_DITCSRA5_OFFSET)

  #define _MCASP_DITCSRB00_ADDR               (_MCASP_BASE_PORT0 + 4*_MCASP_DITCSRB0_OFFSET)
  #define _MCASP_DITCSRB10_ADDR               (_MCASP_BASE_PORT0 + 4*_MCASP_DITCSRB1_OFFSET)
  #define _MCASP_DITCSRB20_ADDR               (_MCASP_BASE_PORT0 + 4*_MCASP_DITCSRB2_OFFSET)
  #define _MCASP_DITCSRB30_ADDR               (_MCASP_BASE_PORT0 + 4*_MCASP_DITCSRB3_OFFSET)
  #define _MCASP_DITCSRB40_ADDR               (_MCASP_BASE_PORT0 + 4*_MCASP_DITCSRB4_OFFSET)
  #define _MCASP_DITCSRB50_ADDR               (_MCASP_BASE_PORT0 + 4*_MCASP_DITCSRB5_OFFSET)

/* registers for MCASP1 */   
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_DITCSR1_ADDR                  (_MCASP_BASE_PORT1 + 4*_MCASP_DITCSRA0_OFFSET)
  #define _MCASP_DITCSRA01_ADDR               (_MCASP_BASE_PORT1 + 4*_MCASP_DITCSRA0_OFFSET)
  #define _MCASP_DITCSRA11_ADDR               (_MCASP_BASE_PORT1 + 4*_MCASP_DITCSRA1_OFFSET)
  #define _MCASP_DITCSRA21_ADDR               (_MCASP_BASE_PORT1 + 4*_MCASP_DITCSRA2_OFFSET)
  #define _MCASP_DITCSRA31_ADDR               (_MCASP_BASE_PORT1 + 4*_MCASP_DITCSRA3_OFFSET)
  #define _MCASP_DITCSRA41_ADDR               (_MCASP_BASE_PORT1 + 4*_MCASP_DITCSRA4_OFFSET)
  #define _MCASP_DITCSRA51_ADDR               (_MCASP_BASE_PORT1 + 4*_MCASP_DITCSRA5_OFFSET)

  #define _MCASP_DITCSRB01_ADDR               (_MCASP_BASE_PORT1 + 4*_MCASP_DITCSRB0_OFFSET)
  #define _MCASP_DITCSRB11_ADDR               (_MCASP_BASE_PORT1 + 4*_MCASP_DITCSRB1_OFFSET)
  #define _MCASP_DITCSRB21_ADDR               (_MCASP_BASE_PORT1 + 4*_MCASP_DITCSRB2_OFFSET)
  #define _MCASP_DITCSRB31_ADDR               (_MCASP_BASE_PORT1 + 4*_MCASP_DITCSRB3_OFFSET)
  #define _MCASP_DITCSRB41_ADDR               (_MCASP_BASE_PORT1 + 4*_MCASP_DITCSRB4_OFFSET)
  #define _MCASP_DITCSRB51_ADDR               (_MCASP_BASE_PORT1 + 4*_MCASP_DITCSRB5_OFFSET)
#endif


/******************************************************************************\
*  
* _____________________
* |                   |
* |       DITUDR      |
* |_______n: 0-15_____|
*
* DITUDR  -  User Data Register File
*
* FIELDS (msb -> lsb)
* (rw)  DITUDRA0	- Left (even TDM slot)  
* (rw)  DITUDRA1  
* (rw)  DITUDRA2  
* (rw)  DITUDRA3  
* (rw)  DITUDRA4  
* (rw)  DITUDRA5  
* (rw)  DITUDRB0  	- Right (odd TDM slot)
* (rw)  DITUDRB1  
* (rw)  DITUDRB2  
* (rw)  DITUDRB3  
* (rw)  DITUDRB4  
* (rw)  DITUDRB5  
*
\******************************************************************************/

  #define _MCASP_DITUDRA0_OFFSET               76
  #define _MCASP_DITUDRA1_OFFSET               77
  #define _MCASP_DITUDRA2_OFFSET               78
  #define _MCASP_DITUDRA3_OFFSET               79
  #define _MCASP_DITUDRA4_OFFSET               80
  #define _MCASP_DITUDRA5_OFFSET               81

  #define _MCASP_DITUDRB0_OFFSET               82
  #define _MCASP_DITUDRB1_OFFSET               83
  #define _MCASP_DITUDRB2_OFFSET               84
  #define _MCASP_DITUDRB3_OFFSET               85
  #define _MCASP_DITUDRB4_OFFSET               86
  #define _MCASP_DITUDRB5_OFFSET               87

  #define _MCASP_DITUDR0_ADDR               (_MCASP_BASE_PORT0 + 4*_MCASP_DITUDRA0_OFFSET)
  /* registers for MCASP0 */ 
  #define _MCASP_DITUDRA00_ADDR               (_MCASP_BASE_PORT0 + 4*_MCASP_DITUDRA0_OFFSET)
  #define _MCASP_DITUDRA10_ADDR               (_MCASP_BASE_PORT0 + 4*_MCASP_DITUDRA1_OFFSET)
  #define _MCASP_DITUDRA20_ADDR               (_MCASP_BASE_PORT0 + 4*_MCASP_DITUDRA2_OFFSET)
  #define _MCASP_DITUDRA30_ADDR               (_MCASP_BASE_PORT0 + 4*_MCASP_DITUDRA3_OFFSET)
  #define _MCASP_DITUDRA40_ADDR               (_MCASP_BASE_PORT0 + 4*_MCASP_DITUDRA4_OFFSET)
  #define _MCASP_DITUDRA50_ADDR               (_MCASP_BASE_PORT0 + 4*_MCASP_DITUDRA5_OFFSET)

  #define _MCASP_DITUDRB00_ADDR               (_MCASP_BASE_PORT0 + 4*_MCASP_DITUDRB0_OFFSET)
  #define _MCASP_DITUDRB10_ADDR               (_MCASP_BASE_PORT0 + 4*_MCASP_DITUDRB1_OFFSET)
  #define _MCASP_DITUDRB20_ADDR               (_MCASP_BASE_PORT0 + 4*_MCASP_DITUDRB2_OFFSET)
  #define _MCASP_DITUDRB30_ADDR               (_MCASP_BASE_PORT0 + 4*_MCASP_DITUDRB3_OFFSET)
  #define _MCASP_DITUDRB40_ADDR               (_MCASP_BASE_PORT0 + 4*_MCASP_DITUDRB4_OFFSET)
  #define _MCASP_DITUDRB50_ADDR               (_MCASP_BASE_PORT0 + 4*_MCASP_DITUDRB5_OFFSET)

/* registers for MCASP1 */ 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_DITUDR1_ADDR                 (_MCASP_BASE_PORT1 + 4*_MCASP_DITUDRA0_OFFSET)
  #define _MCASP_DITUDRA01_ADDR               (_MCASP_BASE_PORT1 + 4*_MCASP_DITUDRA0_OFFSET)
  #define _MCASP_DITUDRA11_ADDR               (_MCASP_BASE_PORT1 + 4*_MCASP_DITUDRA1_OFFSET)
  #define _MCASP_DITUDRA21_ADDR               (_MCASP_BASE_PORT1 + 4*_MCASP_DITUDRA2_OFFSET)
  #define _MCASP_DITUDRA31_ADDR               (_MCASP_BASE_PORT1 + 4*_MCASP_DITUDRA3_OFFSET)
  #define _MCASP_DITUDRA41_ADDR               (_MCASP_BASE_PORT1 + 4*_MCASP_DITUDRA4_OFFSET)
  #define _MCASP_DITUDRA51_ADDR               (_MCASP_BASE_PORT1 + 4*_MCASP_DITUDRA5_OFFSET)
  #define _MCASP_DITUDRB01_ADDR               (_MCASP_BASE_PORT1 + 4*_MCASP_DITUDRB0_OFFSET)
  #define _MCASP_DITUDRB11_ADDR               (_MCASP_BASE_PORT1 + 4*_MCASP_DITUDRB1_OFFSET)
  #define _MCASP_DITUDRB21_ADDR               (_MCASP_BASE_PORT1 + 4*_MCASP_DITUDRB2_OFFSET)
  #define _MCASP_DITUDRB31_ADDR               (_MCASP_BASE_PORT1 + 4*_MCASP_DITUDRB3_OFFSET)
  #define _MCASP_DITUDRB41_ADDR               (_MCASP_BASE_PORT1 + 4*_MCASP_DITUDRB4_OFFSET)
  #define _MCASP_DITUDRB51_ADDR               (_MCASP_BASE_PORT1 + 4*_MCASP_DITUDRB5_OFFSET)
#endif


/******************************************************************************\
*  
* _____________________
* |                   |
* |       SRCTL       |
* |_______n: 0-15_____|
*
* SRCTL  -  Serializer Control Registers
*
* FIELDS (msb -> lsb)
* (r )  RRDY  
* (r )  XRDY  
* (rw)  DISMOD  
* (rw)  SRMOD 
*
\******************************************************************************/

  #define _MCASP_SRCTL0_OFFSET               96
  #define _MCASP_SRCTL1_OFFSET               97
  #define _MCASP_SRCTL2_OFFSET               98
  #define _MCASP_SRCTL3_OFFSET               99
 /* Fields for _MCASP_CHANNEL_CNT == 4 end here*/

#if (_MCASP_CHANNEL_CNT > 4)
  #define _MCASP_SRCTL4_OFFSET               100
  #define _MCASP_SRCTL5_OFFSET               101
#endif /* _MCASP_CHANNEL_CNT == 6 */

#if (_MCASP_CHANNEL_CNT > 6) /* For channel count 8 and 16 */
  #define _MCASP_SRCTL6_OFFSET               102
  #define _MCASP_SRCTL7_OFFSET               103
#endif /* _MCASP_CHANNEL_CNT == 8 */

#if (_MCASP_CHANNEL_CNT == 16)
  #define _MCASP_SRCTL8_OFFSET               104
  #define _MCASP_SRCTL9_OFFSET               105
  #define _MCASP_SRCTL10_OFFSET              106
  #define _MCASP_SRCTL11_OFFSET              107
  #define _MCASP_SRCTL12_OFFSET              108
  #define _MCASP_SRCTL13_OFFSET              109
  #define _MCASP_SRCTL14_OFFSET              110
  #define _MCASP_SRCTL15_OFFSET              111
#endif /* _MCASP_CHANNEL_CNT == 16 */

  #define _MCASP_SRCTL0_ADDR                  (_MCASP_BASE_PORT0 + 4*_MCASP_SRCTL0_OFFSET)
 /* registers for MCASP0 */ 

  #define _MCASP_SRCTL00_ADDR                 (_MCASP_BASE_PORT0 + 4*_MCASP_SRCTL0_OFFSET)
  #define _MCASP_SRCTL10_ADDR                 (_MCASP_BASE_PORT0 + 4*_MCASP_SRCTL1_OFFSET)
  #define _MCASP_SRCTL20_ADDR                 (_MCASP_BASE_PORT0 + 4*_MCASP_SRCTL2_OFFSET)
  #define _MCASP_SRCTL30_ADDR                 (_MCASP_BASE_PORT0 + 4*_MCASP_SRCTL3_OFFSET)
 /* Fields for _MCASP_CHANNEL_CNT == 4 end here*/

#if (_MCASP_CHANNEL_CNT > 4)
  #define _MCASP_SRCTL40_ADDR                 (_MCASP_BASE_PORT0 + 4*_MCASP_SRCTL4_OFFSET)
  #define _MCASP_SRCTL50_ADDR                 (_MCASP_BASE_PORT0 + 4*_MCASP_SRCTL5_OFFSET)
#endif /* _MCASP_CHANNEL_CNT == 6 */

#if (_MCASP_CHANNEL_CNT > 6) /* For channel count 8 and 16 */
  #define _MCASP_SRCTL60_ADDR                 (_MCASP_BASE_PORT0 + 4*_MCASP_SRCTL6_OFFSET)
  #define _MCASP_SRCTL70_ADDR                 (_MCASP_BASE_PORT0 + 4*_MCASP_SRCTL7_OFFSET)
#endif /* _MCASP_CHANNEL_CNT == 8 */

#if (_MCASP_CHANNEL_CNT == 16)
  #define _MCASP_SRCTL80_ADDR                 (_MCASP_BASE_PORT0 + 4*_MCASP_SRCTL8_OFFSET)
  #define _MCASP_SRCTL90_ADDR                 (_MCASP_BASE_PORT0 + 4*_MCASP_SRCTL9_OFFSET)
  #define _MCASP_SRCTL100_ADDR                (_MCASP_BASE_PORT0 + 4*_MCASP_SRCTL10_OFFSET)
  #define _MCASP_SRCTL110_ADDR                (_MCASP_BASE_PORT0 + 4*_MCASP_SRCTL11_OFFSET)
  #define _MCASP_SRCTL120_ADDR                (_MCASP_BASE_PORT0 + 4*_MCASP_SRCTL12_OFFSET)
  #define _MCASP_SRCTL130_ADDR                (_MCASP_BASE_PORT0 + 4*_MCASP_SRCTL13_OFFSET)
  #define _MCASP_SRCTL140_ADDR                (_MCASP_BASE_PORT0 + 4*_MCASP_SRCTL14_OFFSET)
  #define _MCASP_SRCTL150_ADDR                (_MCASP_BASE_PORT0 + 4*_MCASP_SRCTL15_OFFSET)
#endif /* _MCASP_CHANNEL_CNT == 16 */

/* registers for MCASP1 */ 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_SRCTL1_ADDR               (_MCASP_BASE_PORT1 + 4*_MCASP_SRCTL0_OFFSET)
  #define _MCASP_SRCTL01_ADDR               (_MCASP_BASE_PORT1 + 4*_MCASP_SRCTL0_OFFSET)
  #define _MCASP_SRCTL11_ADDR                 (_MCASP_BASE_PORT1 + 4*_MCASP_SRCTL1_OFFSET)
  #define _MCASP_SRCTL21_ADDR                 (_MCASP_BASE_PORT1 + 4*_MCASP_SRCTL2_OFFSET)
  #define _MCASP_SRCTL31_ADDR                 (_MCASP_BASE_PORT1 + 4*_MCASP_SRCTL3_OFFSET)
 /* Fields for _MCASP_CHANNEL_CNT == 4 end here*/

 #if (_MCASP_CHANNEL_CNT > 4)
  #define _MCASP_SRCTL41_ADDR                 (_MCASP_BASE_PORT1 + 4*_MCASP_SRCTL4_OFFSET)
  #define _MCASP_SRCTL51_ADDR                 (_MCASP_BASE_PORT1 + 4*_MCASP_SRCTL5_OFFSET)
 #endif /* _MCASP_CHANNEL_CNT == 6 */

 #if (_MCASP_CHANNEL_CNT > 6) /* For channel count 8 and 16 */
  #define _MCASP_SRCTL61_ADDR                 (_MCASP_BASE_PORT1 + 4*_MCASP_SRCTL6_OFFSET)
  #define _MCASP_SRCTL71_ADDR                 (_MCASP_BASE_PORT1 + 4*_MCASP_SRCTL7_OFFSET)
 #endif /* _MCASP_CHANNEL_CNT == 8 */

 #if (_MCASP_CHANNEL_CNT == 16)
  #define _MCASP_SRCTL81_ADDR                 (_MCASP_BASE_PORT1 + 4*_MCASP_SRCTL8_OFFSET)
  #define _MCASP_SRCTL91_ADDR                 (_MCASP_BASE_PORT1 + 4*_MCASP_SRCTL9_OFFSET)
  #define _MCASP_SRCTL101_ADDR                (_MCASP_BASE_PORT1 + 4*_MCASP_SRCTL10_OFFSET)
  #define _MCASP_SRCTL111_ADDR                (_MCASP_BASE_PORT1 + 4*_MCASP_SRCTL11_OFFSET)
  #define _MCASP_SRCTL121_ADDR                (_MCASP_BASE_PORT1 + 4*_MCASP_SRCTL12_OFFSET)
  #define _MCASP_SRCTL131_ADDR                (_MCASP_BASE_PORT1 + 4*_MCASP_SRCTL13_OFFSET)
  #define _MCASP_SRCTL141_ADDR                (_MCASP_BASE_PORT1 + 4*_MCASP_SRCTL14_OFFSET)
  #define _MCASP_SRCTL151_ADDR                (_MCASP_BASE_PORT1 + 4*_MCASP_SRCTL15_OFFSET)
 #endif /* _MCASP_CHANNEL_CNT == 16 */
#endif

  #define _MCASP_SRCTL_RRDY_MASK              0x00000020u
  #define _MCASP_SRCTL_RRDY_SHIFT             0x00000005u
  #define  MCASP_SRCTL_RRDY_DEFAULT           0x00000000u
  #define  MCASP_SRCTL_RRDY_OF(x)             _VALUEOF(x)
  
  #define _MCASP_SRCTL_XRDY_MASK              0x00000010u
  #define _MCASP_SRCTL_XRDY_SHIFT             0x00000004u
  #define  MCASP_SRCTL_XRDY_DEFAULT           0x00000000u
  #define  MCASP_SRCTL_XRDY_OF(x)             _VALUEOF(x)
  
  
  #define _MCASP_SRCTL_DISMOD_MASK              0x0000000Cu
  #define _MCASP_SRCTL_DISMOD_SHIFT             0x00000002u
  #define  MCASP_SRCTL_DISMOD_DEFAULT           0x00000000u
  #define  MCASP_SRCTL_DISMOD_OF(x)             _VALUEOF(x)
  #define  MCASP_SRCTL_DISMOD_LOW               0x00000002u
  #define  MCASP_SRCTL_DISMOD_HIGH              0x00000003u
  #define  MCASP_SRCTL_DISMOD_3STATE            0x00000000u


  #define _MCASP_SRCTL_SRMOD_MASK              0x00000003u
  #define _MCASP_SRCTL_SRMOD_SHIFT             0x00000000u
  #define  MCASP_SRCTL_SRMOD_DEFAULT           0x00000000u
  #define  MCASP_SRCTL_SRMOD_OF(x)             _VALUEOF(x)
  #define  MCASP_SRCTL_SRMOD_INACTIVE          0x00000000u
  #define  MCASP_SRCTL_SRMOD_XMT               0x00000001u
  #define  MCASP_SRCTL_SRMOD_RCV               0x00000002u

  #define  MCASP_SRCTL_OF(x)                _VALUEOF(x)

  #define MCASP_SRCTL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(MCASP,SRCTL,RRDY)\
| _PER_FDEFAULT(MCASP,SRCTL,XRDY)\
| _PER_FDEFAULT(MCASP,SRCTL,DISMOD)\
| _PER_FDEFAULT(MCASP,SRCTL,SRMOD)\
  )

  #define MCASP_SRCTL_RMK(dismod, srmod) (Uint32)( \
     	  _PER_FMK(MCASP,SRCTL,DISMOD,dismod)\
	| _PER_FMK(MCASP,SRCTL,SRMOD,srmod)\
  )


  #define _MCASP_SRCTL_FGET(M,N,FIELD)\
    _PER_FGET(_MCASP_SRCTL##M##N##_ADDR,MCASP,SRCTL,##FIELD)

  #define _MCASP_SRCTL_FSET(M,N,FIELD,f)\
    _PER_FSET(_MCASP_SRCTL##M##N##_ADDR,MCASP,SRCTL,##FIELD,f)

  #define _MCASP_SRCTL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_MCASP_SRCTL##M##N##_ADDR,MCASP,SRCTL,##FIELD,##SYM)

  #define _MCASP_SRCTL00_FGET(FIELD)  _MCASP_SRCTL_FGET(0,0,##FIELD)
  #define _MCASP_SRCTL10_FGET(FIELD)  _MCASP_SRCTL_FGET(1,0,##FIELD)
  #define _MCASP_SRCTL20_FGET(FIELD)  _MCASP_SRCTL_FGET(2,0,##FIELD)
  #define _MCASP_SRCTL30_FGET(FIELD)  _MCASP_SRCTL_FGET(3,0,##FIELD)
 /* Fields for _MCASP_CHANNEL_CNT == 4 end here*/

#if (_MCASP_CHANNEL_CNT > 4)
  #define _MCASP_SRCTL40_FGET(FIELD)  _MCASP_SRCTL_FGET(4,0,##FIELD)
  #define _MCASP_SRCTL50_FGET(FIELD)  _MCASP_SRCTL_FGET(5,0,##FIELD)
#endif /* _MCASP_CHANNEL_CNT == 6 */

#if (_MCASP_CHANNEL_CNT > 6) /* For channel count 8 and 16 */
  #define _MCASP_SRCTL60_FGET(FIELD)  _MCASP_SRCTL_FGET(6,0,##FIELD)
  #define _MCASP_SRCTL70_FGET(FIELD)  _MCASP_SRCTL_FGET(7,0,##FIELD)
#endif /* _MCASP_CHANNEL_CNT == 8 */

#if (_MCASP_CHANNEL_CNT == 16)
  #define _MCASP_SRCTL80_FGET(FIELD)  _MCASP_SRCTL_FGET(8,0,##FIELD)
  #define _MCASP_SRCTL90_FGET(FIELD)  _MCASP_SRCTL_FGET(9,0,##FIELD)
  #define _MCASP_SRCTL100_FGET(FIELD) _MCASP_SRCTL_FGET(10,0,##FIELD)
  #define _MCASP_SRCTL110_FGET(FIELD) _MCASP_SRCTL_FGET(11,0,##FIELD)
  #define _MCASP_SRCTL120_FGET(FIELD) _MCASP_SRCTL_FGET(12,0,##FIELD)
  #define _MCASP_SRCTL130_FGET(FIELD) _MCASP_SRCTL_FGET(13,0,##FIELD)
  #define _MCASP_SRCTL140_FGET(FIELD) _MCASP_SRCTL_FGET(14,0,##FIELD)
  #define _MCASP_SRCTL150_FGET(FIELD) _MCASP_SRCTL_FGET(15,0,##FIELD)
#endif /* _MCASP_CHANNEL_CNT == 16 */

  #define _MCASP_SRCTL00_FSET(FIELD,f)  _MCASP_SRCTL_FSET(0,0,##FIELD,f)
  #define _MCASP_SRCTL10_FSET(FIELD,f)  _MCASP_SRCTL_FSET(1,0,##FIELD,f)
  #define _MCASP_SRCTL20_FSET(FIELD,f)  _MCASP_SRCTL_FSET(2,0,##FIELD,f)
  #define _MCASP_SRCTL30_FSET(FIELD,f)  _MCASP_SRCTL_FSET(3,0,##FIELD,f)
 /* Fields for _MCASP_CHANNEL_CNT == 4 end here*/

#if (_MCASP_CHANNEL_CNT > 4)
  #define _MCASP_SRCTL40_FSET(FIELD,f)  _MCASP_SRCTL_FSET(4,0,##FIELD,f)
  #define _MCASP_SRCTL50_FSET(FIELD,f)  _MCASP_SRCTL_FSET(5,0,##FIELD,f)
#endif /* _MCASP_CHANNEL_CNT == 6 */

#if (_MCASP_CHANNEL_CNT > 6) /* For channel count 8 and 16 */
  #define _MCASP_SRCTL60_FSET(FIELD,f)  _MCASP_SRCTL_FSET(6,0,##FIELD,f)
  #define _MCASP_SRCTL70_FSET(FIELD,f)  _MCASP_SRCTL_FSET(7,0,##FIELD,f)
#endif /* _MCASP_CHANNEL_CNT == 8 */

#if (_MCASP_CHANNEL_CNT == 16)
  #define _MCASP_SRCTL80_FSET(FIELD,f)  _MCASP_SRCTL_FSET(8,0,##FIELD,f)
  #define _MCASP_SRCTL90_FSET(FIELD,f)  _MCASP_SRCTL_FSET(9,0,##FIELD,f)
  #define _MCASP_SRCTL100_FSET(FIELD,f) _MCASP_SRCTL_FSET(10,0,##FIELD,f)
  #define _MCASP_SRCTL110_FSET(FIELD,f) _MCASP_SRCTL_FSET(11,0,##FIELD,f)
  #define _MCASP_SRCTL120_FSET(FIELD,f) _MCASP_SRCTL_FSET(12,0,##FIELD,f)
  #define _MCASP_SRCTL130_FSET(FIELD,f) _MCASP_SRCTL_FSET(13,0,##FIELD,f)
  #define _MCASP_SRCTL140_FSET(FIELD,f) _MCASP_SRCTL_FSET(14,0,##FIELD,f)
  #define _MCASP_SRCTL150_FSET(FIELD,f) _MCASP_SRCTL_FSET(15,0,##FIELD,f)
#endif /* _MCASP_CHANNEL_CNT == 16 */

  #define _MCASP_SRCTL00_FSETS(FIELD,SYM)  _MCASP_SRCTL_FSETS(0,0,##FIELD,##SYM)
  #define _MCASP_SRCTL10_FSETS(FIELD,SYM)  _MCASP_SRCTL_FSETS(1,0,##FIELD,##SYM)
  #define _MCASP_SRCTL20_FSETS(FIELD,SYM)  _MCASP_SRCTL_FSETS(2,0,##FIELD,##SYM)
  #define _MCASP_SRCTL30_FSETS(FIELD,SYM)  _MCASP_SRCTL_FSETS(3,0,##FIELD,##SYM)
 /* Fields for _MCASP_CHANNEL_CNT == 4 end here*/

#if (_MCASP_CHANNEL_CNT > 4)
  #define _MCASP_SRCTL40_FSETS(FIELD,SYM)  _MCASP_SRCTL_FSETS(4,0,##FIELD,##SYM)
  #define _MCASP_SRCTL50_FSETS(FIELD,SYM)  _MCASP_SRCTL_FSETS(5,0,##FIELD,##SYM)
#endif /* _MCASP_CHANNEL_CNT == 6 */

#if (_MCASP_CHANNEL_CNT > 6) /* For channel count 8 and 16 */
  #define _MCASP_SRCTL60_FSETS(FIELD,SYM)  _MCASP_SRCTL_FSETS(6,0,##FIELD,##SYM)
  #define _MCASP_SRCTL70_FSETS(FIELD,SYM)  _MCASP_SRCTL_FSETS(7,0,##FIELD,##SYM)
#endif /* _MCASP_CHANNEL_CNT == 8 */

#if (_MCASP_CHANNEL_CNT == 16)
  #define _MCASP_SRCTL80_FSETS(FIELD,SYM)  _MCASP_SRCTL_FSETS(8,0,##FIELD,##SYM)
  #define _MCASP_SRCTL90_FSETS(FIELD,SYM)  _MCASP_SRCTL_FSETS(9,0,##FIELD,##SYM)
  #define _MCASP_SRCTL100_FSETS(FIELD,SYM) _MCASP_SRCTL_FSETS(10,0,##FIELD,##SYM)
  #define _MCASP_SRCTL110_FSETS(FIELD,SYM) _MCASP_SRCTL_FSETS(11,0,##FIELD,##SYM)
  #define _MCASP_SRCTL120_FSETS(FIELD,SYM) _MCASP_SRCTL_FSETS(12,0,##FIELD,##SYM)
  #define _MCASP_SRCTL130_FSETS(FIELD,SYM) _MCASP_SRCTL_FSETS(13,0,##FIELD,##SYM)
  #define _MCASP_SRCTL140_FSETS(FIELD,SYM) _MCASP_SRCTL_FSETS(14,0,##FIELD,##SYM)
  #define _MCASP_SRCTL150_FSETS(FIELD,SYM) _MCASP_SRCTL_FSETS(15,0,##FIELD,##SYM)
#endif /* _MCASP_CHANNEL_CNT == 16 */

#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_SRCTL01_FGET(FIELD)  _MCASP_SRCTL_FGET(0,1,##FIELD)
  #define _MCASP_SRCTL11_FGET(FIELD)  _MCASP_SRCTL_FGET(1,1,##FIELD)
  #define _MCASP_SRCTL21_FGET(FIELD)  _MCASP_SRCTL_FGET(2,1,##FIELD)
  #define _MCASP_SRCTL31_FGET(FIELD)  _MCASP_SRCTL_FGET(3,1,##FIELD)
 /* Fields for _MCASP_CHANNEL_CNT == 4 end here*/

 #if (_MCASP_CHANNEL_CNT > 4)
  #define _MCASP_SRCTL41_FGET(FIELD)  _MCASP_SRCTL_FGET(4,1,##FIELD)
  #define _MCASP_SRCTL51_FGET(FIELD)  _MCASP_SRCTL_FGET(5,1,##FIELD)
 #endif /* _MCASP_CHANNEL_CNT == 6 */

 #if (_MCASP_CHANNEL_CNT > 6) /* For channel count 8 and 16 */
  #define _MCASP_SRCTL61_FGET(FIELD)  _MCASP_SRCTL_FGET(6,1,##FIELD)
  #define _MCASP_SRCTL71_FGET(FIELD)  _MCASP_SRCTL_FGET(7,1,##FIELD)
 #endif /* _MCASP_CHANNEL_CNT == 8 */

 #if (_MCASP_CHANNEL_CNT == 16)
  #define _MCASP_SRCTL81_FGET(FIELD)  _MCASP_SRCTL_FGET(8,1,##FIELD)
  #define _MCASP_SRCTL91_FGET(FIELD)  _MCASP_SRCTL_FGET(9,1,##FIELD)
  #define _MCASP_SRCTL101_FGET(FIELD) _MCASP_SRCTL_FGET(10,1,##FIELD)
  #define _MCASP_SRCTL111_FGET(FIELD) _MCASP_SRCTL_FGET(11,1,##FIELD)
  #define _MCASP_SRCTL121_FGET(FIELD) _MCASP_SRCTL_FGET(12,1,##FIELD)
  #define _MCASP_SRCTL131_FGET(FIELD) _MCASP_SRCTL_FGET(13,1,##FIELD)
  #define _MCASP_SRCTL141_FGET(FIELD) _MCASP_SRCTL_FGET(14,1,##FIELD)
  #define _MCASP_SRCTL151_FGET(FIELD) _MCASP_SRCTL_FGET(15,1,##FIELD)
 #endif /* _MCASP_CHANNEL_CNT == 16 */

  #define _MCASP_SRCTL01_FSET(FIELD,f)  _MCASP_SRCTL_FSET(0,1,##FIELD,f)
  #define _MCASP_SRCTL11_FSET(FIELD,f)  _MCASP_SRCTL_FSET(1,1,##FIELD,f)
  #define _MCASP_SRCTL21_FSET(FIELD,f)  _MCASP_SRCTL_FSET(2,1,##FIELD,f)
  #define _MCASP_SRCTL31_FSET(FIELD,f)  _MCASP_SRCTL_FSET(3,1,##FIELD,f)
 /* Fields for _MCASP_CHANNEL_CNT == 4 end here*/

 #if (_MCASP_CHANNEL_CNT > 4)
  #define _MCASP_SRCTL41_FSET(FIELD,f)  _MCASP_SRCTL_FSET(4,1,##FIELD,f)
  #define _MCASP_SRCTL51_FSET(FIELD,f)  _MCASP_SRCTL_FSET(5,1,##FIELD,f)
 #endif /* _MCASP_CHANNEL_CNT == 6 */

 #if (_MCASP_CHANNEL_CNT > 6) /* For channel count 8 and 16 */
  #define _MCASP_SRCTL61_FSET(FIELD,f)  _MCASP_SRCTL_FSET(6,1,##FIELD,f)
  #define _MCASP_SRCTL71_FSET(FIELD,f)  _MCASP_SRCTL_FSET(7,1,##FIELD,f)
 #endif /* _MCASP_CHANNEL_CNT == 8 */

 #if (_MCASP_CHANNEL_CNT == 16)
  #define _MCASP_SRCTL81_FSET(FIELD,f)  _MCASP_SRCTL_FSET(8,1,##FIELD,f)
  #define _MCASP_SRCTL91_FSET(FIELD,f)  _MCASP_SRCTL_FSET(9,1,##FIELD,f)
  #define _MCASP_SRCTL101_FSET(FIELD,f) _MCASP_SRCTL_FSET(10,1,##FIELD,f)
  #define _MCASP_SRCTL111_FSET(FIELD,f) _MCASP_SRCTL_FSET(11,1,##FIELD,f)
  #define _MCASP_SRCTL121_FSET(FIELD,f) _MCASP_SRCTL_FSET(12,1,##FIELD,f)
  #define _MCASP_SRCTL131_FSET(FIELD,f) _MCASP_SRCTL_FSET(13,1,##FIELD,f)
  #define _MCASP_SRCTL141_FSET(FIELD,f) _MCASP_SRCTL_FSET(14,1,##FIELD,f)
  #define _MCASP_SRCTL151_FSET(FIELD,f) _MCASP_SRCTL_FSET(15,1,##FIELD,f)
 #endif /* _MCASP_CHANNEL_CNT == 16 */

  #define _MCASP_SRCTL01_FSETS(FIELD,SYM)  _MCASP_SRCTL_FSETS(0,1,##FIELD,##SYM)
  #define _MCASP_SRCTL11_FSETS(FIELD,SYM)  _MCASP_SRCTL_FSETS(1,1,##FIELD,##SYM)
  #define _MCASP_SRCTL21_FSETS(FIELD,SYM)  _MCASP_SRCTL_FSETS(2,1,##FIELD,##SYM)
  #define _MCASP_SRCTL31_FSETS(FIELD,SYM)  _MCASP_SRCTL_FSETS(3,1,##FIELD,##SYM)
 /* Fields for _MCASP_CHANNEL_CNT == 4 end here*/

 #if (_MCASP_CHANNEL_CNT > 4)
  #define _MCASP_SRCTL41_FSETS(FIELD,SYM)  _MCASP_SRCTL_FSETS(4,1,##FIELD,##SYM)
  #define _MCASP_SRCTL51_FSETS(FIELD,SYM)  _MCASP_SRCTL_FSETS(5,1,##FIELD,##SYM)
 #endif /* _MCASP_CHANNEL_CNT == 6 */

 #if (_MCASP_CHANNEL_CNT > 6) /* For channel count 8 and 16 */
  #define _MCASP_SRCTL61_FSETS(FIELD,SYM)  _MCASP_SRCTL_FSETS(6,1,##FIELD,##SYM)
  #define _MCASP_SRCTL71_FSETS(FIELD,SYM)  _MCASP_SRCTL_FSETS(7,1,##FIELD,##SYM)
 #endif /* _MCASP_CHANNEL_CNT == 8 */

 #if (_MCASP_CHANNEL_CNT == 16)
  #define _MCASP_SRCTL81_FSETS(FIELD,SYM)  _MCASP_SRCTL_FSETS(8,1,##FIELD,##SYM)
  #define _MCASP_SRCTL91_FSETS(FIELD,SYM)  _MCASP_SRCTL_FSETS(9,1,##FIELD,##SYM)
  #define _MCASP_SRCTL101_FSETS(FIELD,SYM) _MCASP_SRCTL_FSETS(10,1,##FIELD,##SYM)
  #define _MCASP_SRCTL111_FSETS(FIELD,SYM) _MCASP_SRCTL_FSETS(11,1,##FIELD,##SYM)
  #define _MCASP_SRCTL121_FSETS(FIELD,SYM) _MCASP_SRCTL_FSETS(12,1,##FIELD,##SYM)
  #define _MCASP_SRCTL131_FSETS(FIELD,SYM) _MCASP_SRCTL_FSETS(13,1,##FIELD,##SYM)
  #define _MCASP_SRCTL141_FSETS(FIELD,SYM) _MCASP_SRCTL_FSETS(14,1,##FIELD,##SYM)
  #define _MCASP_SRCTL151_FSETS(FIELD,SYM) _MCASP_SRCTL_FSETS(15,1,##FIELD,##SYM)
 #endif /* _MCASP_CHANNEL_CNT == 16 */                              
#endif


/******************************************************************************\
*  
* _____________________
* |                   |
* |       XBUF        |
* |_______n: 0-15_____|
*
* XBUF  -  Transmit Buffer for Serializers
*
*
\******************************************************************************/
  
  #define _MCASP_XBUF0_ADDR                 0x3C000000u
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XBUF1_ADDR                 0x3C100000u
#endif

  #define _MCASP_XBUF0_OFFSET               128
  #define _MCASP_XBUF1_OFFSET               129
  #define _MCASP_XBUF2_OFFSET               130
  #define _MCASP_XBUF3_OFFSET               131
 /* Fields for _MCASP_CHANNEL_CNT == 4 end here*/

#if (_MCASP_CHANNEL_CNT > 4)
  #define _MCASP_XBUF4_OFFSET               132
  #define _MCASP_XBUF5_OFFSET               133
#endif /* _MCASP_CHANNEL_CNT == 6 */

#if (_MCASP_CHANNEL_CNT > 6) /* For channel count 8 and 16 */
  #define _MCASP_XBUF6_OFFSET               134
  #define _MCASP_XBUF7_OFFSET               135
#endif /* _MCASP_CHANNEL_CNT == 8 */

#if (_MCASP_CHANNEL_CNT == 16)
  #define _MCASP_XBUF8_OFFSET               136
  #define _MCASP_XBUF9_OFFSET               137
  #define _MCASP_XBUF10_OFFSET              138
  #define _MCASP_XBUF11_OFFSET              139
  #define _MCASP_XBUF12_OFFSET              140
  #define _MCASP_XBUF13_OFFSET              141
  #define _MCASP_XBUF14_OFFSET              142
  #define _MCASP_XBUF15_OFFSET              143
#endif /* _MCASP_CHANNEL_CNT == 16 */


  #define _MCASP_XBUF00_ADDR                 (_MCASP_BASE_PORT0 + 4*_MCASP_XBUF0_OFFSET)
  #define _MCASP_XBUF10_ADDR                 (_MCASP_BASE_PORT0 + 4*_MCASP_XBUF1_OFFSET)
  #define _MCASP_XBUF20_ADDR                 (_MCASP_BASE_PORT0 + 4*_MCASP_XBUF2_OFFSET)
  #define _MCASP_XBUF30_ADDR                 (_MCASP_BASE_PORT0 + 4*_MCASP_XBUF3_OFFSET)
 /* Fields for _MCASP_CHANNEL_CNT == 4 end here*/

#if (_MCASP_CHANNEL_CNT > 4)
  #define _MCASP_XBUF40_ADDR                 (_MCASP_BASE_PORT0 + 4*_MCASP_XBUF4_OFFSET)
  #define _MCASP_XBUF50_ADDR                 (_MCASP_BASE_PORT0 + 4*_MCASP_XBUF5_OFFSET)
#endif /* _MCASP_CHANNEL_CNT == 6 */

#if (_MCASP_CHANNEL_CNT > 6) /* For channel count 8 and 16 */
  #define _MCASP_XBUF60_ADDR                 (_MCASP_BASE_PORT0 + 4*_MCASP_XBUF6_OFFSET)
  #define _MCASP_XBUF70_ADDR                 (_MCASP_BASE_PORT0 + 4*_MCASP_XBUF7_OFFSET)
#endif /* _MCASP_CHANNEL_CNT == 8 */

#if (_MCASP_CHANNEL_CNT == 16)
  #define _MCASP_XBUF80_ADDR                 (_MCASP_BASE_PORT0 + 4*_MCASP_XBUF8_OFFSET)
  #define _MCASP_XBUF90_ADDR                 (_MCASP_BASE_PORT0 + 4*_MCASP_XBUF9_OFFSET)
  #define _MCASP_XBUF100_ADDR                (_MCASP_BASE_PORT0 + 4*_MCASP_XBUF10_OFFSET)
  #define _MCASP_XBUF110_ADDR                (_MCASP_BASE_PORT0 + 4*_MCASP_XBUF11_OFFSET)
  #define _MCASP_XBUF120_ADDR                (_MCASP_BASE_PORT0 + 4*_MCASP_XBUF12_OFFSET)
  #define _MCASP_XBUF130_ADDR                (_MCASP_BASE_PORT0 + 4*_MCASP_XBUF13_OFFSET)
  #define _MCASP_XBUF140_ADDR                (_MCASP_BASE_PORT0 + 4*_MCASP_XBUF14_OFFSET)
  #define _MCASP_XBUF150_ADDR                (_MCASP_BASE_PORT0 + 4*_MCASP_XBUF15_OFFSET)
#endif /* _MCASP_CHANNEL_CNT == 16 */
 
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_XBUF01_ADDR               (_MCASP_BASE_PORT1 + 4*_MCASP_XBUF0_OFFSET)
  #define _MCASP_XBUF11_ADDR                 (_MCASP_BASE_PORT1 + 4*_MCASP_XBUF1_OFFSET)
  #define _MCASP_XBUF21_ADDR                 (_MCASP_BASE_PORT1 + 4*_MCASP_XBUF2_OFFSET)
  #define _MCASP_XBUF31_ADDR                 (_MCASP_BASE_PORT1 + 4*_MCASP_XBUF3_OFFSET)
 /* Fields for _MCASP_CHANNEL_CNT == 4 end here*/

 #if (_MCASP_CHANNEL_CNT > 4)
  #define _MCASP_XBUF41_ADDR                 (_MCASP_BASE_PORT1 + 4*_MCASP_XBUF4_OFFSET)
  #define _MCASP_XBUF51_ADDR                 (_MCASP_BASE_PORT1 + 4*_MCASP_XBUF5_OFFSET)
 #endif /* _MCASP_CHANNEL_CNT == 6 */

 #if (_MCASP_CHANNEL_CNT > 6) /* For channel count 8 and 16 */
  #define _MCASP_XBUF61_ADDR                 (_MCASP_BASE_PORT1 + 4*_MCASP_XBUF6_OFFSET)
  #define _MCASP_XBUF71_ADDR                 (_MCASP_BASE_PORT1 + 4*_MCASP_XBUF7_OFFSET)
 #endif /* _MCASP_CHANNEL_CNT == 8 */

 #if (_MCASP_CHANNEL_CNT == 16)
  #define _MCASP_XBUF81_ADDR                 (_MCASP_BASE_PORT1 + 4*_MCASP_XBUF8_OFFSET)
  #define _MCASP_XBUF91_ADDR                 (_MCASP_BASE_PORT1 + 4*_MCASP_XBUF9_OFFSET)
  #define _MCASP_XBUF101_ADDR                (_MCASP_BASE_PORT1 + 4*_MCASP_XBUF10_OFFSET)
  #define _MCASP_XBUF111_ADDR                (_MCASP_BASE_PORT1 + 4*_MCASP_XBUF11_OFFSET)
  #define _MCASP_XBUF121_ADDR                (_MCASP_BASE_PORT1 + 4*_MCASP_XBUF12_OFFSET)
  #define _MCASP_XBUF131_ADDR                (_MCASP_BASE_PORT1 + 4*_MCASP_XBUF13_OFFSET)
  #define _MCASP_XBUF141_ADDR                (_MCASP_BASE_PORT1 + 4*_MCASP_XBUF14_OFFSET)
  #define _MCASP_XBUF151_ADDR                (_MCASP_BASE_PORT1 + 4*_MCASP_XBUF15_OFFSET)
 #endif /* _MCASP_CHANNEL_CNT == 16 */
#endif
  

/******************************************************************************\
*  
* _____________________
* |                   |
* |       RBUF        |
* |_______n: 0-15_____|
*
* RBUF  -  Receive Buffer for Serializers
*
*
\******************************************************************************/

  #define _MCASP_RBUF0_ADDR                 0x3C000000u
#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RBUF1_ADDR                 0x3C100000u
#endif


  #define _MCASP_RBUF0_OFFSET               160
  #define _MCASP_RBUF1_OFFSET               161
  #define _MCASP_RBUF2_OFFSET               162
  #define _MCASP_RBUF3_OFFSET               163
 /* Fields for _MCASP_CHANNEL_CNT == 4 end here*/

#if (_MCASP_CHANNEL_CNT > 4)
  #define _MCASP_RBUF4_OFFSET               164
  #define _MCASP_RBUF5_OFFSET               165
#endif /* _MCASP_CHANNEL_CNT == 6 */

#if (_MCASP_CHANNEL_CNT > 6) /* For channel count 8 and 16 */
  #define _MCASP_RBUF6_OFFSET               166
  #define _MCASP_RBUF7_OFFSET               167
#endif /* _MCASP_CHANNEL_CNT == 8 */

#if (_MCASP_CHANNEL_CNT == 16)
  #define _MCASP_RBUF8_OFFSET               168
  #define _MCASP_RBUF9_OFFSET               169
  #define _MCASP_RBUF10_OFFSET               170
  #define _MCASP_RBUF11_OFFSET               171
  #define _MCASP_RBUF12_OFFSET               172
  #define _MCASP_RBUF13_OFFSET               173
  #define _MCASP_RBUF14_OFFSET               174
  #define _MCASP_RBUF15_OFFSET               175
#endif /* _MCASP_CHANNEL_CNT == 16 */

  #define _MCASP_RBUF00_ADDR               (_MCASP_BASE_PORT0 + 4*_MCASP_RBUF0_OFFSET)
  #define _MCASP_RBUF10_ADDR                 (_MCASP_BASE_PORT0 + 4*_MCASP_RBUF1_OFFSET)
  #define _MCASP_RBUF20_ADDR                 (_MCASP_BASE_PORT0 + 4*_MCASP_RBUF2_OFFSET)
  #define _MCASP_RBUF30_ADDR                 (_MCASP_BASE_PORT0 + 4*_MCASP_RBUF3_OFFSET)
 /* Fields for _MCASP_CHANNEL_CNT == 4 end here*/

#if (_MCASP_CHANNEL_CNT > 4)
  #define _MCASP_RBUF40_ADDR                 (_MCASP_BASE_PORT0 + 4*_MCASP_RBUF4_OFFSET)
  #define _MCASP_RBUF50_ADDR                 (_MCASP_BASE_PORT0 + 4*_MCASP_RBUF5_OFFSET)
#endif /* _MCASP_CHANNEL_CNT == 6 */

#if (_MCASP_CHANNEL_CNT > 6) /* For channel count 8 and 16 */
  #define _MCASP_RBUF60_ADDR                 (_MCASP_BASE_PORT0 + 4*_MCASP_RBUF6_OFFSET)
  #define _MCASP_RBUF70_ADDR                 (_MCASP_BASE_PORT0 + 4*_MCASP_RBUF7_OFFSET)
#endif /* _MCASP_CHANNEL_CNT == 8 */

#if (_MCASP_CHANNEL_CNT == 16)
  #define _MCASP_RBUF80_ADDR                 (_MCASP_BASE_PORT0 + 4*_MCASP_RBUF8_OFFSET)
  #define _MCASP_RBUF90_ADDR                 (_MCASP_BASE_PORT0 + 4*_MCASP_RBUF9_OFFSET)
  #define _MCASP_RBUF100_ADDR                (_MCASP_BASE_PORT0 + 4*_MCASP_RBUF10_OFFSET)
  #define _MCASP_RBUF110_ADDR                (_MCASP_BASE_PORT0 + 4*_MCASP_RBUF11_OFFSET)
  #define _MCASP_RBUF120_ADDR                (_MCASP_BASE_PORT0 + 4*_MCASP_RBUF12_OFFSET)
  #define _MCASP_RBUF130_ADDR                (_MCASP_BASE_PORT0 + 4*_MCASP_RBUF13_OFFSET)
  #define _MCASP_RBUF140_ADDR                (_MCASP_BASE_PORT0 + 4*_MCASP_RBUF14_OFFSET)
  #define _MCASP_RBUF150_ADDR                (_MCASP_BASE_PORT0 + 4*_MCASP_RBUF15_OFFSET)
#endif /* _MCASP_CHANNEL_CNT == 16 */

#if (_MCASP_PORT_CNT > 1)
  #define _MCASP_RBUF01_ADDR                 (_MCASP_BASE_PORT1 + 4*_MCASP_RBUF0_OFFSET)
  #define _MCASP_RBUF11_ADDR                 (_MCASP_BASE_PORT1 + 4*_MCASP_RBUF1_OFFSET)
  #define _MCASP_RBUF21_ADDR                 (_MCASP_BASE_PORT1 + 4*_MCASP_RBUF2_OFFSET)
  #define _MCASP_RBUF31_ADDR                 (_MCASP_BASE_PORT1 + 4*_MCASP_RBUF3_OFFSET)
 /* Fields for _MCASP_CHANNEL_CNT == 4 end here*/

 #if (_MCASP_CHANNEL_CNT > 4)
  #define _MCASP_RBUF41_ADDR                 (_MCASP_BASE_PORT1 + 4*_MCASP_RBUF4_OFFSET)
  #define _MCASP_RBUF51_ADDR                 (_MCASP_BASE_PORT1 + 4*_MCASP_RBUF5_OFFSET)
 #endif /* _MCASP_CHANNEL_CNT == 6 */

 #if (_MCASP_CHANNEL_CNT > 6) /* For channel count 8 and 16 */
  #define _MCASP_RBUF61_ADDR                 (_MCASP_BASE_PORT1 + 4*_MCASP_RBUF6_OFFSET)
  #define _MCASP_RBUF71_ADDR                 (_MCASP_BASE_PORT1 + 4*_MCASP_RBUF7_OFFSET)
 #endif /* _MCASP_CHANNEL_CNT == 8 */

 #if (_MCASP_CHANNEL_CNT == 16)
  #define _MCASP_RBUF81_ADDR                 (_MCASP_BASE_PORT1 + 4*_MCASP_RBUF8_OFFSET)
  #define _MCASP_RBUF91_ADDR                 (_MCASP_BASE_PORT1 + 4*_MCASP_RBUF9_OFFSET)
  #define _MCASP_RBUF101_ADDR                (_MCASP_BASE_PORT1 + 4*_MCASP_RBUF10_OFFSET)
  #define _MCASP_RBUF111_ADDR                (_MCASP_BASE_PORT1 + 4*_MCASP_RBUF11_OFFSET)
  #define _MCASP_RBUF121_ADDR                (_MCASP_BASE_PORT1 + 4*_MCASP_RBUF12_OFFSET)
  #define _MCASP_RBUF131_ADDR                (_MCASP_BASE_PORT1 + 4*_MCASP_RBUF13_OFFSET)
  #define _MCASP_RBUF141_ADDR                (_MCASP_BASE_PORT1 + 4*_MCASP_RBUF14_OFFSET)
  #define _MCASP_RBUF151_ADDR                (_MCASP_BASE_PORT1 + 4*_MCASP_RBUF15_OFFSET)
 #endif /* _MCASP_CHANNEL_CNT == 16 */
#endif


/******************************************************************\
* Step 5. #endif MODULE_SUPPORT and _CSL_MODULELHAL_H_
\******************************************************************/

#endif /* (MODULE_SUPPORT) */
#endif /* _CSL_MCASPHAL_H_ */
/******************************************************************************\
* End of csl_mcasphal.h
\******************************************************************************/

