/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_i2chal.h
* DATE CREATED.. 10/02/2001 
* LAST MODIFIED. 08/02/2004 - Adding support for C6418
*                11/19/2001    register renaming 
*                11/09/2001    update bit field names 
*                07/02/2003    update to latest spec.
*------------------------------------------------------------------------------
* REGISTERS
*
* I2COAR0    - I2C0 Own Address register
* I2COAR1    - I2C1 Own Address register
* I2CIER0    - I2C0 Interrupt Mask/Status register
* I2CIER1    - I2C1 Interrupt Mask/Status register
* I2CSTR0    - I2C0 Interrupt Status register
* I2CSTR1    - I2C1 Interrupt Status register
* I2CCLKL0   - I2C0 Clock Divider Low register
* I2CCLKL1   - I2C1 Clock Divider Low register
* I2CCLKH0   - I2C0 Clock Divider High register
* I2CCLKH1   - I2C1 Clock Divider High register
* I2CCNT0    - I2C0 Data Count register
* I2CCNT1    - I2C1 Data Count register
* I2CDRR0    - I2C0 Data Receive register
* I2CDRR1    - I2C1 Data Receive register
* I2CSAR0    - I2C0 Slave Address register
* I2CSAR1    - I2C1 Slave Address register
* I2CDXR0    - I2C0 Data Transmit register
* I2CDXR1    - I2C1 Data Transmit register
* I2CMDR0    - I2C0 Mode register
* I2CMDR1    - I2C1 Mode register
* I2CISRC0    - I2C0 Interrupt Vector register
* I2CISRC1    - I2C1 Interrupt Vector register
* I2CEMDR0   - I2C0 Extended Mode register(1)
* I2CEMDR1   - I2C1 Extended Mode register(1)
* I2CPSC0    - I2C0 Prescaler register
* I2CPSC1    - I2C1 Prescaler register
* I2CPID10   - I2C0 Peripheral ID register 1(1)
* I2CPID11   - I2C1 Peripheral ID register 1(1)
* I2CPID20   - I2C0 Peripheral ID register 2(1)
* I2CPID21   - I2C1 Peripheral ID register 2(1)
* I2CPFUNC0  - I2C0 Peripheral Functional register(1)
* I2CPFUNC1  - I2C1 Peripheral Functional register(1)
* I2CPDIR0   - I2C0 Pin Direction register(1)
* I2CPDIR1   - I2C1 Pin Direction register(1)
* I2CPDIN0   - I2C0 Pin Data In register(1)
* I2CPDIN1   - I2C1 Pin Data In register(1)
* I2CPDOUT0  - I2C0 Pin Data Out register(1)
* I2CPDOUT1  - I2C1 Pin Data Out register(1)
* I2CPDSET0  - I2C0 Pin Data Set register(1)
* I2CPDSET1  - I2C1 Pin Data Set register(1)
* I2CPDCLR0  - I2C0 Pin Data Clear register(1)
* I2CPDCLR1  - I2C1 Pin Data Clear register(1)
*
* (1) For C6418/C6413/C6410 only
\******************************************************************************/
#ifndef _CSL_I2CHAL_H_
#define _CSL_I2CHAL_H_

#include <csl_stdinc.h>
#include <csl_chip.h>
#if (I2C_SUPPORT)
/******************************************************************************\
* MISC section
\******************************************************************************/
#if (CHIP_6713 | CHIP_DA610 | CHIP_6413 | CHIP_6418 | CHIP_6410)
  #define _I2C_PORT_CNT        2
  #define _I2C_BASE_PORT0      0x01B40000u
  #define _I2C_BASE_PORT1      0x01B44000u
#endif

#if (CHIP_DM642 | CHIP_DM641 | CHIP_DM640 | CHIP_6412)
  #define _I2C_PORT_CNT        1
  #define _I2C_BASE_PORT0      0x01B40000u
#endif
 

/******************************************************************************\
* module level register/field access macros
\******************************************************************************/

  /* ----------------- */
  /* FIELD MAKE MACROS */
  /* ----------------- */

  #define I2C_FMK(REG,FIELD,x)\
    _PER_FMK(I2C,##REG,##FIELD,x)

  #define I2C_FMKS(REG,FIELD,SYM)\
    _PER_FMKS(I2C,##REG,##FIELD,##SYM)


  /* -------------------------------- */
  /* RAW REGISTER/FIELD ACCESS MACROS */
  /* -------------------------------- */

  #define I2C_ADDR(REG)\
    _I2C_##REG##_ADDR

  #define I2C_RGET(REG)\
    _PER_RGET(_I2C_##REG##_ADDR,I2C,##REG)

  #define I2C_RSET(REG,x)\
    _PER_RSET(_I2C_##REG##_ADDR,I2C,##REG,x)

  #define I2C_FGET(REG,FIELD)\
    _I2C_##REG##_FGET(##FIELD)

  #define I2C_FSET(REG,FIELD,x)\
    _I2C_##REG##_FSET(##FIELD,##x)

  #define I2C_FSETS(REG,FIELD,SYM)\
    _I2C_##REG##_FSETS(##FIELD,##SYM)


  /* ------------------------------------------ */
  /* ADDRESS BASED REGISTER/FIELD ACCESS MACROS */
  /* ------------------------------------------ */

  #define I2C_RGETA(addr,REG)\
    _PER_RGET(addr,I2C,##REG)

  #define I2C_RSETA(addr,REG,x)\
    _PER_RSET(addr,I2C,##REG,x)

  #define I2C_FGETA(addr,REG,FIELD)\
    _PER_FGET(addr,I2C,##REG,##FIELD)

  #define I2C_FSETA(addr,REG,FIELD,x)\
    _PER_FSET(addr,I2C,##REG,##FIELD,x)

  #define I2C_FSETSA(addr,REG,FIELD,SYM)\
    _PER_FSETS(addr,I2C,##REG,##FIELD,##SYM)


  /* ----------------------------------------- */
  /* HANDLE BASED REGISTER/FIELD ACCESS MACROS */
  /* ----------------------------------------- */

  #define I2C_ADDRH(h,REG)\
    (Uint32)(&((h)->baseAddr[_I2C_##REG##_OFFSET]))

  #define I2C_RGETH(h,REG)\
    I2C_RGETA(I2C_ADDRH(h,##REG),##REG)


  #define I2C_RSETH(h,REG,x)\
    I2C_RSETA(I2C_ADDRH(h,##REG),##REG,x)


  #define I2C_FGETH(h,REG,FIELD)\
    I2C_FGETA(I2C_ADDRH(h,##REG),##REG,##FIELD)


  #define I2C_FSETH(h,REG,FIELD,x)\
    I2C_FSETA(I2C_ADDRH(h,##REG),##REG,##FIELD,x)


  #define I2C_FSETSH(h,REG,FIELD,SYM)\
    I2C_FSETSA(I2C_ADDRH(h,##REG),##REG,##FIELD,##SYM)



/******************************************************************************\
*  ___________________
* |                   |
* |  I 2 C O A R      |
* |___________________|
*
* I2COAR0    - I2C0 Own Address register
* I2COAR1    - I2C1 Own Address register
*
* FIELDS (msb -> lsb)
* (rw) A
*
\******************************************************************************/
  #define _I2C_I2COAR_OFFSET           0

  #define _I2C_I2COAR0_ADDR            0x01B40000
  #define _I2C_I2COAR1_ADDR            0x01B44000

  #define _I2C_I2COAR_A_MASK          0x000003FFu 
  #define _I2C_I2COAR_A_SHIFT         0x00000000u
  #define  I2C_I2COAR_A_DEFAULT       0x00000000u
  #define  I2C_I2COAR_A_OF(x)         _VALUEOF(x)

  #define  I2C_I2COAR_OF(x)             _VALUEOF(x)

  #define I2C_I2COAR_DEFAULT (Uint32)(\
     _PER_FDEFAULT(I2C,I2COAR,A)\
  )

  #define I2C_I2COAR_RMK(a) (Uint32)(\
     _PER_FMK(I2C,I2COAR,A,a)\
  )
   
  #define _I2C_I2COAR_FGET(N,FIELD)\
    _PER_FGET(_I2C_I2COAR##N##_ADDR,I2C,I2COAR,##FIELD)

  #define _I2C_I2COAR_FSET(N,FIELD,field)\
    _PER_FSET(_I2C_I2COAR##N##_ADDR,I2C,I2COAR,##FIELD,field)

  #define _I2C_I2COAR_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_I2C_I2COAR##N##_ADDR,I2C,I2COAR,##FIELD,##SYM)

  #define _I2C_I2COAR0_FGET(FIELD) _I2C_I2COAR_FGET(0,##FIELD)
  #define _I2C_I2COAR1_FGET(FIELD) _I2C_I2COAR_FGET(1,##FIELD)

  #define _I2C_I2COAR0_FSET(FIELD,f) _I2C_I2COAR_FSET(0,##FIELD,f)
  #define _I2C_I2COAR1_FSET(FIELD,f) _I2C_I2COAR_FSET(1,##FIELD,f)

  #define _I2C_I2COAR0_FSETS(FIELD,SYM) _I2C_I2COAR_FSETS(0,##FIELD,##SYM)
  #define _I2C_I2COAR1_FSETS(FIELD,SYM) _I2C_I2COAR_FSETS(1,##FIELD,##SYM)

/******************************************************************************\
*  (Keeping the old definitions for backward compatibility)
*  ___________________
* |                   |
* |  I 2 C I M R      |
* |___________________|
*
* I2CIMR0    - I2C0 Interrupt Mask/Status register
* I2CIMR1    - I2C1 Interrupt Mask/Status register
*
* FIELDS (msb -> lsb)
* (rw) ICXRDY
* (rw) ICRRDY
* (rw) ARDY
* (rw) NACK
* (rw) AL
\******************************************************************************/
#if (!(CHIP_6410 | CHIP_6413| CHIP_6418 ))

  #define _I2C_I2CIMR_OFFSET           1

  #define _I2C_I2CIMR0_ADDR            0x01B40004
  #define _I2C_I2CIMR1_ADDR            0x01B44004

  #define _I2C_I2CIMR_ICXRDY_MASK          0x00000010u
  #define _I2C_I2CIMR_ICXRDY_SHIFT         0x00000004u
  #define  I2C_I2CIMR_ICXRDY_DEFAULT       0x00000000u
  #define  I2C_I2CIMR_ICXRDY_OF(x)         _VALUEOF(x)
  #define  I2C_I2CIMR_ICXRDY_MSK           0x00000000u
  #define  I2C_I2CIMR_ICXRDY_UNMSK         0x00000001u

  #define _I2C_I2CIMR_ICRRDY_MASK          0x00000008u
  #define _I2C_I2CIMR_ICRRDY_SHIFT         0x00000003u
  #define  I2C_I2CIMR_ICRRDY_DEFAULT       0x00000000u
  #define  I2C_I2CIMR_ICRRDY_OF(x)         _VALUEOF(x)
  #define  I2C_I2CIMR_ICRRDY_MSK           0x00000000u
  #define  I2C_I2CIMR_ICRRDY_UNMSK         0x00000001u

  #define _I2C_I2CIMR_ARDY_MASK            0x00000004u
  #define _I2C_I2CIMR_ARDY_SHIFT           0x00000002u
  #define  I2C_I2CIMR_ARDY_DEFAULT         0x00000000u
  #define  I2C_I2CIMR_ARDY_OF(x)           _VALUEOF(x)
  #define  I2C_I2CIMR_ARDY_MSK             0x00000000u
  #define  I2C_I2CIMR_ARDY_UNMSK           0x00000001u

  #define _I2C_I2CIMR_NACK_MASK            0x00000002u
  #define _I2C_I2CIMR_NACK_SHIFT           0x00000001u
  #define  I2C_I2CIMR_NACK_DEFAULT         0x00000000u
  #define  I2C_I2CIMR_NACK_OF(x)           _VALUEOF(x)
  #define  I2C_I2CIMR_NACK_MSK             0x00000000u
  #define  I2C_I2CIMR_NACK_UNMSK           0x00000001u

  #define _I2C_I2CIMR_AL_MASK              0x00000001u
  #define _I2C_I2CIMR_AL_SHIFT             0x00000000u
  #define  I2C_I2CIMR_AL_DEFAULT           0x00000000u
  #define  I2C_I2CIMR_AL_OF(x)             _VALUEOF(x)
  #define  I2C_I2CIMR_AL_MSK               0x00000000u
  #define  I2C_I2CIMR_AL_UNMSK             0x00000001u


  #define  I2C_I2CIMR_OF(x)                _VALUEOF(x)

  #define I2C_I2CIMR_DEFAULT (Uint32)(\
      _PER_FDEFAULT(I2C,I2CIMR,ICXRDY)\
     |_PER_FDEFAULT(I2C,I2CIMR,ICRRDY)\
     |_PER_FDEFAULT(I2C,I2CIMR,ARDY)\
     |_PER_FDEFAULT(I2C,I2CIMR,NACK)\
     |_PER_FDEFAULT(I2C,I2CIMR,AL)\
  )

  #define I2C_I2CIMR_RMK(icxrdy,icrrdy,ardy,nack,al) (Uint32)(\
      _PER_FMK(I2C,I2CIMR,ICXRDY,icxrdy)\
     |_PER_FMK(I2C,I2CIMR,ICRRDY,icrrdy)\
     |_PER_FMK(I2C,I2CIMR,ARDY,ardy)\
     |_PER_FMK(I2C,I2CIMR,NACK,nack)\
     |_PER_FMK(I2C,I2CIMR,AL,al)\
  )
  
   
  #define _I2C_I2CIMR_FGET(N,FIELD)\
    _PER_FGET(_I2C_I2CIMR##N##_ADDR,I2C,I2CIMR,##FIELD)

  #define _I2C_I2CIMR_FSET(N,FIELD,field)\
    _PER_FSET(_I2C_I2CIMR##N##_ADDR,I2C,I2CIMR,##FIELD,field)

  #define _I2C_I2CIMR_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_I2C_I2CIMR##N##_ADDR,I2C,I2CIMR,##FIELD,##SYM)

  #define _I2C_I2CIMR0_FGET(FIELD) _I2C_I2CIMR_FGET(0,##FIELD)
  #define _I2C_I2CIMR1_FGET(FIELD) _I2C_I2CIMR_FGET(1,##FIELD)

  #define _I2C_I2CIMR0_FSET(FIELD,f) _I2C_I2CIMR_FSET(0,##FIELD,f)
  #define _I2C_I2CIMR1_FSET(FIELD,f) _I2C_I2CIMR_FSET(1,##FIELD,f)

  #define _I2C_I2CIMR0_FSETS(FIELD,SYM) _I2C_I2CIMR_FSETS(0,##FIELD,##SYM)
  #define _I2C_I2CIMR1_FSETS(FIELD,SYM) _I2C_I2CIMR_FSETS(1,##FIELD,##SYM)
#endif

/******************************************************************************\
*  ___________________
* |                   |
* |  I 2 C I E R      |
* |___________________|
*
* I2CIER0    - I2C0 Interrupt Mask/Status register
* I2CIER1    - I2C1 Interrupt Mask/Status register
*
* FIELDS (msb -> lsb)
* (rw) AAS(1)
* (rw) SCD(1)
* (rw) ICXRDY
* (rw) ICRRDY
* (rw) ARDY
* (rw) NACK
* (rw) AL
*
*  (1) For  C6418/C6413/C6410 only
\******************************************************************************/
  #define _I2C_I2CIER_OFFSET           1

  #define _I2C_I2CIER0_ADDR            0x01B40004
  #define _I2C_I2CIER1_ADDR            0x01B44004

#if (CHIP_6413 | CHIP_6418 | CHIP_6410)
  #define _I2C_I2CIER_AAS_MASK             0x00000040u
  #define _I2C_I2CIER_AAS_SHIFT            0x00000006u
  #define  I2C_I2CIER_AAS_DEFAULT          0x00000000u
  #define  I2C_I2CIER_AAS_OF(x)            _VALUEOF(x)
  #define  I2C_I2CIER_AAS_MSK              0x00000000u
  #define  I2C_I2CIER_AAS_UNMSK            0x00000001u

  #define _I2C_I2CIER_SCD_MASK             0x00000020u
  #define _I2C_I2CIER_SCD_SHIFT            0x00000005u
  #define  I2C_I2CIER_SCD_DEFAULT          0x00000000u
  #define  I2C_I2CIER_SCD_OF(x)            _VALUEOF(x)
  #define  I2C_I2CIER_SCD_MSK              0x00000000u
  #define  I2C_I2CIER_SCD_UNMSK            0x00000001u
#endif

  #define _I2C_I2CIER_ICXRDY_MASK          0x00000010u
  #define _I2C_I2CIER_ICXRDY_SHIFT         0x00000004u
  #define  I2C_I2CIER_ICXRDY_DEFAULT       0x00000000u
  #define  I2C_I2CIER_ICXRDY_OF(x)         _VALUEOF(x)
  #define  I2C_I2CIER_ICXRDY_MSK           0x00000000u
  #define  I2C_I2CIER_ICXRDY_UNMSK         0x00000001u

  #define _I2C_I2CIER_ICRRDY_MASK          0x00000008u
  #define _I2C_I2CIER_ICRRDY_SHIFT         0x00000003u
  #define  I2C_I2CIER_ICRRDY_DEFAULT       0x00000000u
  #define  I2C_I2CIER_ICRRDY_OF(x)         _VALUEOF(x)
  #define  I2C_I2CIER_ICRRDY_MSK           0x00000000u
  #define  I2C_I2CIER_ICRRDY_UNMSK         0x00000001u

  #define _I2C_I2CIER_ARDY_MASK            0x00000004u
  #define _I2C_I2CIER_ARDY_SHIFT           0x00000002u
  #define  I2C_I2CIER_ARDY_DEFAULT         0x00000000u
  #define  I2C_I2CIER_ARDY_OF(x)           _VALUEOF(x)
  #define  I2C_I2CIER_ARDY_MSK             0x00000000u
  #define  I2C_I2CIER_ARDY_UNMSK           0x00000001u

  #define _I2C_I2CIER_NACK_MASK            0x00000002u
  #define _I2C_I2CIER_NACK_SHIFT           0x00000001u
  #define  I2C_I2CIER_NACK_DEFAULT         0x00000000u
  #define  I2C_I2CIER_NACK_OF(x)           _VALUEOF(x)
  #define  I2C_I2CIER_NACK_MSK             0x00000000u
  #define  I2C_I2CIER_NACK_UNMSK           0x00000001u

  #define _I2C_I2CIER_AL_MASK              0x00000001u
  #define _I2C_I2CIER_AL_SHIFT             0x00000000u
  #define  I2C_I2CIER_AL_DEFAULT           0x00000000u
  #define  I2C_I2CIER_AL_OF(x)             _VALUEOF(x)
  #define  I2C_I2CIER_AL_MSK               0x00000000u
  #define  I2C_I2CIER_AL_UNMSK             0x00000001u


  #define  I2C_I2CIER_OF(x)                _VALUEOF(x)

#if (!(CHIP_6413 | CHIP_6418 | CHIP_6410))
  #define I2C_I2CIER_DEFAULT (Uint32)(\
      _PER_FDEFAULT(I2C,I2CIER,ICXRDY)\
     |_PER_FDEFAULT(I2C,I2CIER,ICRRDY)\
     |_PER_FDEFAULT(I2C,I2CIER,ARDY)\
     |_PER_FDEFAULT(I2C,I2CIER,NACK)\
     |_PER_FDEFAULT(I2C,I2CIER,AL)\
  )

  #define I2C_I2CIER_RMK(icxrdy,icrrdy,ardy,nack,al) (Uint32)(\
      _PER_FMK(I2C,I2CIER,ICXRDY,icxrdy)\
     |_PER_FMK(I2C,I2CIER,ICRRDY,icrrdy)\
     |_PER_FMK(I2C,I2CIER,ARDY,ardy)\
     |_PER_FMK(I2C,I2CIER,NACK,nack)\
     |_PER_FMK(I2C,I2CIER,AL,al)\
  )
#else
  #define I2C_I2CIER_DEFAULT (Uint32)(\
      _PER_FDEFAULT(I2C,I2CIER,AAS)\
     |_PER_FDEFAULT(I2C,I2CIER,SCD)\
     |_PER_FDEFAULT(I2C,I2CIER,ICXRDY)\
     |_PER_FDEFAULT(I2C,I2CIER,ICRRDY)\
     |_PER_FDEFAULT(I2C,I2CIER,ARDY)\
     |_PER_FDEFAULT(I2C,I2CIER,NACK)\
     |_PER_FDEFAULT(I2C,I2CIER,AL)\
  )

  #define I2C_I2CIER_RMK(aas,scd,icxrdy,icrrdy,ardy,nack,al) (Uint32)(\
      _PER_FMK(I2C,I2CIER,AAS,aas)\
     |_PER_FMK(I2C,I2CIER,SCD,scd)\
     |_PER_FMK(I2C,I2CIER,ICXRDY,icxrdy)\
     |_PER_FMK(I2C,I2CIER,ICRRDY,icrrdy)\
     |_PER_FMK(I2C,I2CIER,ARDY,ardy)\
     |_PER_FMK(I2C,I2CIER,NACK,nack)\
     |_PER_FMK(I2C,I2CIER,AL,al)\
  )
#endif  
   
  #define _I2C_I2CIER_FGET(N,FIELD)\
    _PER_FGET(_I2C_I2CIER##N##_ADDR,I2C,I2CIER,##FIELD)

  #define _I2C_I2CIER_FSET(N,FIELD,field)\
    _PER_FSET(_I2C_I2CIER##N##_ADDR,I2C,I2CIER,##FIELD,field)

  #define _I2C_I2CIER_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_I2C_I2CIER##N##_ADDR,I2C,I2CIER,##FIELD,##SYM)

  #define _I2C_I2CIER0_FGET(FIELD) _I2C_I2CIER_FGET(0,##FIELD)
  #define _I2C_I2CIER1_FGET(FIELD) _I2C_I2CIER_FGET(1,##FIELD)

  #define _I2C_I2CIER0_FSET(FIELD,f) _I2C_I2CIER_FSET(0,##FIELD,f)
  #define _I2C_I2CIER1_FSET(FIELD,f) _I2C_I2CIER_FSET(1,##FIELD,f)

  #define _I2C_I2CIER0_FSETS(FIELD,SYM) _I2C_I2CIER_FSETS(0,##FIELD,##SYM)
  #define _I2C_I2CIER1_FSETS(FIELD,SYM) _I2C_I2CIER_FSETS(1,##FIELD,##SYM)

/******************************************************************************\
*  ___________________
* |                   |
* |  I 2 C S T R      |
* |___________________|
*
* I2CSTR0    - I2C0 Interrupt Status register
* I2CSTR1    - I2C1 Interrupt Status register
*
* FIELDS (msb -> lsb)
* (rc)  SDIR(1)
* (rc)  NACKSNT
* (rc)  BB
* (r)   RSFULL
* (r)   XSMT
* (r)   AAS
* (r)   AD0
* (rc)  SCD(1)
* (rc)  ICXRDY
* (rc)  ICRRDY
* (rc)  ARDY
* (rc)  NACK
* (rc)  AL
*
* (1) For  C6418/C6413/C6410 only
\******************************************************************************/
  #define _I2C_I2CSTR_OFFSET                2

  #define _I2C_I2CSTR0_ADDR                 0x01B40008
  #define _I2C_I2CSTR1_ADDR                 0x01B44008

#if (CHIP_6413 | CHIP_6418 | CHIP_6410)
  #define _I2C_I2CSTR_SDIR_MASK             0x00004000u
  #define _I2C_I2CSTR_SDIR_SHIFT            0x0000000Eu
  #define  I2C_I2CSTR_SDIR_DEFAULT          0x00000000u
  #define  I2C_I2CSTR_SDIR_OF(x)            _VALUEOF(x)
  #define  I2C_I2CSTR_SDIR_NONE             0x00000000u
  #define  I2C_I2CSTR_SDIR_INT              0x00000001u
  #define  I2C_I2CSTR_SDIR_CLR              0x00000001u
#endif

  #define _I2C_I2CSTR_NACKSNT_MASK          0x00002000u
  #define _I2C_I2CSTR_NACKSNT_SHIFT         0x0000000Du
  #define  I2C_I2CSTR_NACKSNT_DEFAULT       0x00000000u
  #define  I2C_I2CSTR_NACKSNT_OF(x)         _VALUEOF(x)
  #define  I2C_I2CSTR_NACKSNT_NONE          0x00000000u
  #define  I2C_I2CSTR_NACKSNT_INT           0x00000001u
  #define  I2C_I2CSTR_NACKSNT_CLR           0x00000001u

  #define _I2C_I2CSTR_BB_MASK               0x00001000u
  #define _I2C_I2CSTR_BB_SHIFT              0x0000000Cu
  #define  I2C_I2CSTR_BB_DEFAULT            0x00000000u
  #define  I2C_I2CSTR_BB_OF(x)              _VALUEOF(x)
  #define  I2C_I2CSTR_BB_NONE               0x00000000u
  #define  I2C_I2CSTR_BB_INT                0x00000001u
  #define  I2C_I2CSTR_BB_CLR                0x00000001u

  #define _I2C_I2CSTR_RSFULL_MASK           0x00000800u
  #define _I2C_I2CSTR_RSFULL_SHIFT          0x0000000Bu
  #define  I2C_I2CSTR_RSFULL_DEFAULT        0x00000000u
  #define  I2C_I2CSTR_RSFULL_OF(x)          _VALUEOF(x)
  #define  I2C_I2CSTR_RSFULL_NONE           0x00000000u
  #define  I2C_I2CSTR_RSFULL_INT            0x00000001u

  #define _I2C_I2CSTR_XSMT_MASK             0x00000400u
  #define _I2C_I2CSTR_XSMT_SHIFT            0x0000000Au
  #define  I2C_I2CSTR_XSMT_DEFAULT          0x00000001u
  #define  I2C_I2CSTR_XSMT_OF(x)            _VALUEOF(x)
  #define  I2C_I2CSTR_XSMT_NONE             0x00000000u
  #define  I2C_I2CSTR_XSMT_INT              0x00000001u

  #define _I2C_I2CSTR_AAS_MASK              0x00000200u
  #define _I2C_I2CSTR_AAS_SHIFT             0x00000009u
  #define  I2C_I2CSTR_AAS_DEFAULT           0x00000000u
  #define  I2C_I2CSTR_AAS_OF(x)             _VALUEOF(x)
  #define  I2C_I2CSTR_AAS_NONE              0x00000000u
  #define  I2C_I2CSTR_AAS_INT               0x00000001u

  #define _I2C_I2CSTR_AD0_MASK              0x00000100u
  #define _I2C_I2CSTR_AD0_SHIFT             0x00000008u
  #define  I2C_I2CSTR_AD0_DEFAULT           0x00000000u
  #define  I2C_I2CSTR_AD0_OF(x)             _VALUEOF(x)
  #define  I2C_I2CSTR_AD0_NONE              0x00000000u
  #define  I2C_I2CSTR_AD0_INT               0x00000001u

#if (CHIP_6413 | CHIP_6418 | CHIP_6410)
  #define _I2C_I2CSTR_SCD_MASK              0x00000020u
  #define _I2C_I2CSTR_SCD_SHIFT             0x00000005u
  #define  I2C_I2CSTR_SCD_DEFAULT           0x00000000u
  #define  I2C_I2CSTR_SCD_OF(x)             _VALUEOF(x)
  #define  I2C_I2CSTR_SCD_NONE              0x00000000u
  #define  I2C_I2CSTR_SCD_INT               0x00000001u
  #define  I2C_I2CSTR_SCD_CLR               0x00000001u
#endif

  #define _I2C_I2CSTR_ICXRDY_MASK           0x00000010u
  #define _I2C_I2CSTR_ICXRDY_SHIFT          0x00000004u
  #define  I2C_I2CSTR_ICXRDY_DEFAULT        0x00000001u
  #define  I2C_I2CSTR_ICXRDY_OF(x)          _VALUEOF(x)
  #define  I2C_I2CSTR_ICXRDY_NONE           0x00000000u
  #define  I2C_I2CSTR_ICXRDY_INT            0x00000001u
  #define  I2C_I2CSTR_ICXRDY_CLR            0x00000001u

  #define _I2C_I2CSTR_ICRRDY_MASK           0x00000008u
  #define _I2C_I2CSTR_ICRRDY_SHIFT          0x00000003u
  #define  I2C_I2CSTR_ICRRDY_DEFAULT        0x00000000u
  #define  I2C_I2CSTR_ICRRDY_OF(x)          _VALUEOF(x)
  #define  I2C_I2CSTR_ICRRDY_NONE           0x00000000u
  #define  I2C_I2CSTR_ICRRDY_INT            0x00000001u
  #define  I2C_I2CSTR_ICRRDY_CLR            0x00000001u

  #define _I2C_I2CSTR_ARDY_MASK             0x00000004u
  #define _I2C_I2CSTR_ARDY_SHIFT            0x00000002u
  #define  I2C_I2CSTR_ARDY_DEFAULT          0x00000000u
  #define  I2C_I2CSTR_ARDY_OF(x)            _VALUEOF(x)
  #define  I2C_I2CSTR_ARDY_NONE             0x00000000u
  #define  I2C_I2CSTR_ARDY_INT              0x00000001u
  #define  I2C_I2CSTR_ARDY_CLR              0x00000001u

  #define _I2C_I2CSTR_NACK_MASK             0x00000002u
  #define _I2C_I2CSTR_NACK_SHIFT            0x00000001u
  #define  I2C_I2CSTR_NACK_DEFAULT          0x00000000u
  #define  I2C_I2CSTR_NACK_OF(x)            _VALUEOF(x)
  #define  I2C_I2CSTR_NACK_NONE             0x00000000u
  #define  I2C_I2CSTR_NACK_INT              0x00000001u
  #define  I2C_I2CSTR_NACK_CLR              0x00000001u

  #define _I2C_I2CSTR_AL_MASK               0x00000001u
  #define _I2C_I2CSTR_AL_SHIFT              0x00000000u
  #define  I2C_I2CSTR_AL_DEFAULT            0x00000000u
  #define  I2C_I2CSTR_AL_OF(x)              _VALUEOF(x)
  #define  I2C_I2CSTR_AL_NONE               0x00000000u
  #define  I2C_I2CSTR_AL_INT                0x00000001u
  #define  I2C_I2CSTR_AL_CLR                0x00000001u


  #define  I2C_I2CSTR_OF(x)                _VALUEOF(x)

#if !(CHIP_6413 | CHIP_6418 | CHIP_6410)
  #define I2C_I2CSTR_DEFAULT (Uint32)(\
      _PER_FDEFAULT(I2C,I2CSTR,NACKSNT)\
     |_PER_FDEFAULT(I2C,I2CSTR,BB)\
     |_PER_FDEFAULT(I2C,I2CSTR,RSFULL)\
     |_PER_FDEFAULT(I2C,I2CSTR,XSMT)\
     |_PER_FDEFAULT(I2C,I2CSTR,AAS)\
     |_PER_FDEFAULT(I2C,I2CSTR,AD0)\
     |_PER_FDEFAULT(I2C,I2CSTR,ICXRDY)\
     |_PER_FDEFAULT(I2C,I2CSTR,ICRRDY)\
     |_PER_FDEFAULT(I2C,I2CSTR,ARDY)\
     |_PER_FDEFAULT(I2C,I2CSTR,NACK)\
     |_PER_FDEFAULT(I2C,I2CSTR,AL)\
  )
#else
  #define I2C_I2CSTR_DEFAULT (Uint32)(\
      _PER_FDEFAULT(I2C,I2CSTR,SDIR)\
     |_PER_FDEFAULT(I2C,I2CSTR,NACKSNT)\
     |_PER_FDEFAULT(I2C,I2CSTR,BB)\
     |_PER_FDEFAULT(I2C,I2CSTR,RSFULL)\
     |_PER_FDEFAULT(I2C,I2CSTR,XSMT)\
     |_PER_FDEFAULT(I2C,I2CSTR,AAS)\
     |_PER_FDEFAULT(I2C,I2CSTR,AD0)\
     |_PER_FDEFAULT(I2C,I2CSTR,SCD)\
     |_PER_FDEFAULT(I2C,I2CSTR,ICXRDY)\
     |_PER_FDEFAULT(I2C,I2CSTR,ICRRDY)\
     |_PER_FDEFAULT(I2C,I2CSTR,ARDY)\
     |_PER_FDEFAULT(I2C,I2CSTR,NACK)\
     |_PER_FDEFAULT(I2C,I2CSTR,AL)\
  )
#endif
#if !(CHIP_6413 | CHIP_6418 | CHIP_6410)
  #define I2C_I2CSTR_RMK(nacksnt,bb,icxrdy,icrrdy,ardy,nack,al) (Uint32)(\
      _PER_FMK(I2C,I2CSTR,NACKSNT,nacksnt)\
     |_PER_FMK(I2C,I2CSTR,BB,bb)\
     |_PER_FMK(I2C,I2CSTR,ICXRDY,icxrdy)\
     |_PER_FMK(I2C,I2CSTR,ICRRDY,icrrdy)\
     |_PER_FMK(I2C,I2CSTR,ARDY,ardy)\
     |_PER_FMK(I2C,I2CSTR,NACK,nack)\
     |_PER_FMK(I2C,I2CSTR,AL,al)\
  )
#else
  #define I2C_I2CSTR_RMK(sdir,nacksnt,bb,scd,icxrdy,icrrdy,ardy,nack,al) (Uint32)(\
      _PER_FMK(I2C,I2CSTR,SDIR,sdir)\
      _PER_FMK(I2C,I2CSTR,NACKSNT,nacksnt)\
     |_PER_FMK(I2C,I2CSTR,BB,bb)\
     |_PER_FMK(I2C,I2CSTR,SCD,scd)\
     |_PER_FMK(I2C,I2CSTR,ICXRDY,icxrdy)\
     |_PER_FMK(I2C,I2CSTR,ICRRDY,icrrdy)\
     |_PER_FMK(I2C,I2CSTR,ARDY,ardy)\
     |_PER_FMK(I2C,I2CSTR,NACK,nack)\
     |_PER_FMK(I2C,I2CSTR,AL,al)\
  )
#endif
  #define _I2C_I2CSTR_FGET(N,FIELD)\
    _PER_FGET(_I2C_I2CSTR##N##_ADDR,I2C,I2CSTR,##FIELD)

  #define _I2C_I2CSTR_FSET(N,FIELD,field)\
    _PER_FSET(_I2C_I2CSTR##N##_ADDR,I2C,I2CSTR,##FIELD,field)

  #define _I2C_I2CSTR_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_I2C_I2CSTR##N##_ADDR,I2C,I2CSTR,##FIELD,##SYM)

  #define _I2C_I2CSTR0_FGET(FIELD) _I2C_I2CSTR_FGET(0,##FIELD)
  #define _I2C_I2CSTR1_FGET(FIELD) _I2C_I2CSTR_FGET(1,##FIELD)

  #define _I2C_I2CSTR0_FSET(FIELD,f) _I2C_I2CSTR_FSET(0,##FIELD,f)
  #define _I2C_I2CSTR1_FSET(FIELD,f) _I2C_I2CSTR_FSET(1,##FIELD,f)

  #define _I2C_I2CSTR0_FSETS(FIELD,SYM) _I2C_I2CSTR_FSETS(0,##FIELD,##SYM)
  #define _I2C_I2CSTR1_FSETS(FIELD,SYM) _I2C_I2CSTR_FSETS(1,##FIELD,##SYM)


/******************************************************************************\
*  ___________________
* |                   |
* |  I 2 C C L K L    |
* |___________________|
*
* I2CCLKL0   - I2C0 Clock Divider Low register
* I2CCLKL1   - I2C1 Clock Divider Low register
*
* FIELDS (msb -> lsb)
* (rw) ICCL
*
\******************************************************************************/
  #define _I2C_I2CCLKL_OFFSET           3

  #define _I2C_I2CCLKL0_ADDR            0x01B4000C
  #define _I2C_I2CCLKL1_ADDR            0x01B4400C

  #define _I2C_I2CCLKL_ICCL_MASK           0x0000FFFFu
  #define _I2C_I2CCLKL_ICCL_SHIFT          0x00000000u
  #define  I2C_I2CCLKL_ICCL_DEFAULT        0x00000000u
  #define  I2C_I2CCLKL_ICCL_OF(x)          _VALUEOF(x)

  #define  I2C_I2CCLKL_OF(x)             _VALUEOF(x)

  #define I2C_I2CCLKL_DEFAULT (Uint32)(\
     _PER_FDEFAULT(I2C,I2CCLKL,ICCL)\
  )

  #define I2C_I2CCLKL_RMK(iccl) (Uint32)(\
     _PER_FMK(I2C,I2CCLKL,ICCL,iccl)\
  )
   
  #define _I2C_I2CCLKL_FGET(N,FIELD)\
    _PER_FGET(_I2C_I2CCLKL##N##_ADDR,I2C,I2CCLKL,##FIELD)

  #define _I2C_I2CCLKL_FSET(N,FIELD,field)\
    _PER_FSET(_I2C_I2CCLKL##N##_ADDR,I2C,I2CCLKL,##FIELD,field)

  #define _I2C_I2CCLKL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_I2C_I2CCLKL##N##_ADDR,I2C,I2CCLKL,##FIELD,##SYM)

  #define _I2C_I2CCLKL0_FGET(FIELD) _I2C_I2CCLKL_FGET(0,##FIELD)
  #define _I2C_I2CCLKL1_FGET(FIELD) _I2C_I2CCLKL_FGET(1,##FIELD)

  #define _I2C_I2CCLKL0_FSET(FIELD,f) _I2C_I2CCLKL_FSET(0,##FIELD,f)
  #define _I2C_I2CCLKL1_FSET(FIELD,f) _I2C_I2CCLKL_FSET(1,##FIELD,f)

  #define _I2C_I2CCLKL0_FSETS(FIELD,SYM) _I2C_I2CCLKL_FSETS(0,##FIELD,##SYM)
  #define _I2C_I2CCLKL1_FSETS(FIELD,SYM) _I2C_I2CCLKL_FSETS(1,##FIELD,##SYM)


/******************************************************************************\
*  ___________________
* |                   |
* |  I 2 C C L K H    |
* |___________________|
*
* I2CCLKH0   - I2C0 Clock Divider High register
* I2CCLKH1   - I2C1 Clock Divider High register
*
* FIELDS (msb -> lsb)
* (rw) ICCH
*
\******************************************************************************/
  #define _I2C_I2CCLKH_OFFSET           4

  #define _I2C_I2CCLKH0_ADDR            0x01B40010
  #define _I2C_I2CCLKH1_ADDR            0x01B44010

  #define _I2C_I2CCLKH_ICCH_MASK        0x0000FFFFu
  #define _I2C_I2CCLKH_ICCH_SHIFT       0x00000000u
  #define  I2C_I2CCLKH_ICCH_DEFAULT     0x00000000u
  #define  I2C_I2CCLKH_ICCH_OF(x)       _VALUEOF(x)

  #define  I2C_I2CCLKH_OF(x)             _VALUEOF(x)

  #define I2C_I2CCLKH_DEFAULT (Uint32)(\
     _PER_FDEFAULT(I2C,I2CCLKH,ICCH)\
  )

  #define I2C_I2CCLKH_RMK(icch) (Uint32)(\
     _PER_FMK(I2C,I2CCLKH,ICCH,icch)\
  )
   
  #define _I2C_I2CCLKH_FGET(N,FIELD)\
    _PER_FGET(_I2C_I2CCLKH##N##_ADDR,I2C,I2CCLKH,##FIELD)

  #define _I2C_I2CCLKH_FSET(N,FIELD,field)\
    _PER_FSET(_I2C_I2CCLKH##N##_ADDR,I2C,I2CCLKH,##FIELD,field)

  #define _I2C_I2CCLKH_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_I2C_I2CCLKH##N##_ADDR,I2C,I2CCLKH,##FIELD,##SYM)

  #define _I2C_I2CCLKH0_FGET(FIELD) _I2C_I2CCLKH_FGET(0,##FIELD)
  #define _I2C_I2CCLKH1_FGET(FIELD) _I2C_I2CCLKH_FGET(1,##FIELD)

  #define _I2C_I2CCLKH0_FSET(FIELD,f) _I2C_I2CCLKH_FSET(0,##FIELD,f)
  #define _I2C_I2CCLKH1_FSET(FIELD,f) _I2C_I2CCLKH_FSET(1,##FIELD,f)

  #define _I2C_I2CCLKH0_FSETS(FIELD,SYM) _I2C_I2CCLKH_FSETS(0,##FIELD,##SYM)
  #define _I2C_I2CCLKH1_FSETS(FIELD,SYM) _I2C_I2CCLKH_FSETS(1,##FIELD,##SYM)


/******************************************************************************\
*  ___________________
* |                   |
* |  I 2 C C N T      |
* |___________________|
*
* I2CCNT0    - I2C0 Data Count register
* I2CCNT1    - I2C1 Data Count register
*
* FIELDS (msb -> lsb)
* (rw) ICDC
\******************************************************************************/
  #define _I2C_I2CCNT_OFFSET           5

  #define _I2C_I2CCNT0_ADDR            0x01B40014
  #define _I2C_I2CCNT1_ADDR            0x01B44014

  #define _I2C_I2CCNT_ICDC_MASK        0x0000FFFFu
  #define _I2C_I2CCNT_ICDC_SHIFT       0x00000000u
  #define  I2C_I2CCNT_ICDC_DEFAULT     0x00000000u
  #define  I2C_I2CCNT_ICDC_OF(x)       _VALUEOF(x)

  #define  I2C_I2CCNT_OF(x)             _VALUEOF(x)

  #define I2C_I2CCNT_DEFAULT (Uint32)(\
     _PER_FDEFAULT(I2C,I2CCNT,ICDC)\
  )

  #define I2C_I2CCNT_RMK(icdc) (Uint32)(\
     _PER_FMK(I2C,I2CCNT,ICDC,icdc)\
  )
   
  #define _I2C_I2CCNT_FGET(N,FIELD)\
    _PER_FGET(_I2C_I2CCNT##N##_ADDR,I2C,I2CCNT,##FIELD)

  #define _I2C_I2CCNT_FSET(N,FIELD,field)\
    _PER_FSET(_I2C_I2CCNT##N##_ADDR,I2C,I2CCNT,##FIELD,field)

  #define _I2C_I2CCNT_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_I2C_I2CCNT##N##_ADDR,I2C,I2CCNT,##FIELD,##SYM)

  #define _I2C_I2CCNT0_FGET(FIELD) _I2C_I2CCNT_FGET(0,##FIELD)
  #define _I2C_I2CCNT1_FGET(FIELD) _I2C_I2CCNT_FGET(1,##FIELD)

  #define _I2C_I2CCNT0_FSET(FIELD,f) _I2C_I2CCNT_FSET(0,##FIELD,f)
  #define _I2C_I2CCNT1_FSET(FIELD,f) _I2C_I2CCNT_FSET(1,##FIELD,f)

  #define _I2C_I2CCNT0_FSETS(FIELD,SYM) _I2C_I2CCNT_FSETS(0,##FIELD,##SYM)
  #define _I2C_I2CCNT1_FSETS(FIELD,SYM) _I2C_I2CCNT_FSETS(1,##FIELD,##SYM)


/******************************************************************************\
*  ___________________
* |                   |
* |  I 2 C D R R      |
* |___________________|
*
* I2CDRR0    - I2C0 Data Receive register
* I2CDRR1    - I2C1 Data Receive register
*
* FIELDS (msb -> lsb)
* (r) D
\******************************************************************************/
  #define _I2C_I2CDRR_OFFSET           6

  #define _I2C_I2CDRR0_ADDR            0x01B40018
  #define _I2C_I2CDRR1_ADDR            0x01B44018

  #define _I2C_I2CDRR_D_MASK        0x000000FFu
  #define _I2C_I2CDRR_D_SHIFT       0x00000000u
  #define  I2C_I2CDRR_D_DEFAULT     0x00000000u
  #define  I2C_I2CDRR_D_OF(x)       _VALUEOF(x)

  #define  I2C_I2CDRR_OF(x)             _VALUEOF(x)

  #define I2C_I2CDRR_DEFAULT (Uint32)(\
     _PER_FDEFAULT(I2C,I2CDRR,D)\
  )

  #define I2C_I2CDRR_RMK(d) (Uint32)(\
     _PER_FMK(I2C,I2CDRR,D,d)\
  )
   
  #define _I2C_I2CDRR_FGET(N,FIELD)\
    _PER_FGET(_I2C_I2CDRR##N##_ADDR,I2C,I2CDRR,##FIELD)

  #define _I2C_I2CDRR_FSET(N,FIELD,field)\
    _PER_FSET(_I2C_I2CDRR##N##_ADDR,I2C,I2CDRR,##FIELD,field)

  #define _I2C_I2CDRR_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_I2C_I2CDRR##N##_ADDR,I2C,I2CDRR,##FIELD,##SYM)

  #define _I2C_I2CDRR0_FGET(FIELD) _I2C_I2CDRR_FGET(0,##FIELD)
  #define _I2C_I2CDRR1_FGET(FIELD) _I2C_I2CDRR_FGET(1,##FIELD)

  #define _I2C_I2CDRR0_FSET(FIELD,f) _I2C_I2CDRR_FSET(0,##FIELD,f)
  #define _I2C_I2CDRR1_FSET(FIELD,f) _I2C_I2CDRR_FSET(1,##FIELD,f)

  #define _I2C_I2CDRR0_FSETS(FIELD,SYM) _I2C_I2CDRR_FSETS(0,##FIELD,##SYM)
  #define _I2C_I2CDRR1_FSETS(FIELD,SYM) _I2C_I2CDRR_FSETS(1,##FIELD,##SYM)


/******************************************************************************\
*  ___________________
* |                   |
* |  I 2 C S A R      |
* |___________________|
*
* I2CSAR0    - I2C0 Slave Address register
* I2CSAR1    - I2C1 Slave Address register
*
* FIELDS (msb -> lsb)
* (rw) A
\******************************************************************************/
  #define _I2C_I2CSAR_OFFSET           7

  #define _I2C_I2CSAR0_ADDR            0x01B4001C
  #define _I2C_I2CSAR1_ADDR            0x01B4401C

  #define _I2C_I2CSAR_A_MASK           0x000003FFu
  #define _I2C_I2CSAR_A_SHIFT          0x00000000u
  #define  I2C_I2CSAR_A_DEFAULT        0x000003FFu /*???*/
  #define  I2C_I2CSAR_A_OF(x)          _VALUEOF(x)

  #define  I2C_I2CSAR_OF(x)             _VALUEOF(x)

  #define I2C_I2CSAR_DEFAULT (Uint32)(\
     _PER_FDEFAULT(I2C,I2CSAR,A)\
  )

  #define I2C_I2CSAR_RMK(a) (Uint32)(\
     _PER_FMK(I2C,I2CSAR,A,a)\
  )
   
  #define _I2C_I2CSAR_FGET(N,FIELD)\
    _PER_FGET(_I2C_I2CSAR##N##_ADDR,I2C,I2CSAR,##FIELD)

  #define _I2C_I2CSAR_FSET(N,FIELD,field)\
    _PER_FSET(_I2C_I2CSAR##N##_ADDR,I2C,I2CSAR,##FIELD,field)

  #define _I2C_I2CSAR_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_I2C_I2CSAR##N##_ADDR,I2C,I2CSAR,##FIELD,##SYM)

  #define _I2C_I2CSAR0_FGET(FIELD) _I2C_I2CSAR_FGET(0,##FIELD)
  #define _I2C_I2CSAR1_FGET(FIELD) _I2C_I2CSAR_FGET(1,##FIELD)

  #define _I2C_I2CSAR0_FSET(FIELD,f) _I2C_I2CSAR_FSET(0,##FIELD,f)
  #define _I2C_I2CSAR1_FSET(FIELD,f) _I2C_I2CSAR_FSET(1,##FIELD,f)

  #define _I2C_I2CSAR0_FSETS(FIELD,SYM) _I2C_I2CSAR_FSETS(0,##FIELD,##SYM)
  #define _I2C_I2CSAR1_FSETS(FIELD,SYM) _I2C_I2CSAR_FSETS(1,##FIELD,##SYM)


/******************************************************************************\
*  ___________________
* |                   |
* |  I 2 C D X R      |
* |___________________|
*
* I2CDXR0    - I2C0 Data Transmit register
* I2CDXR1    - I2C1 Data Transmit register
*
* FIELDS (msb -> lsb)
* (rw) D
\******************************************************************************/
  #define _I2C_I2CDXR_OFFSET           8

  #define _I2C_I2CDXR0_ADDR            0x01B40020
  #define _I2C_I2CDXR1_ADDR            0x01B44020

  #define _I2C_I2CDXR_D_MASK           0x000000FFu
  #define _I2C_I2CDXR_D_SHIFT          0x00000000u
  #define  I2C_I2CDXR_D_DEFAULT        0x00000000u
  #define  I2C_I2CDXR_D_OF(x)          _VALUEOF(x)

  #define  I2C_I2CDXR_OF(x)             _VALUEOF(x)

  #define I2C_I2CDXR_DEFAULT (Uint32)(\
     _PER_FDEFAULT(I2C,I2CDXR,D)\
  )

  #define I2C_I2CDXR_RMK(d) (Uint32)(\
     _PER_FMK(I2C,I2CDXR,D,d)\
  )
   
  #define _I2C_I2CDXR_FGET(N,FIELD)\
    _PER_FGET(_I2C_I2CDXR##N##_ADDR,I2C,I2CDXR,##FIELD)

  #define _I2C_I2CDXR_FSET(N,FIELD,field)\
    _PER_FSET(_I2C_I2CDXR##N##_ADDR,I2C,I2CDXR,##FIELD,field)

  #define _I2C_I2CDXR_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_I2C_I2CDXR##N##_ADDR,I2C,I2CDXR,##FIELD,##SYM)

  #define _I2C_I2CDXR0_FGET(FIELD) _I2C_I2CDXR_FGET(0,##FIELD)
  #define _I2C_I2CDXR1_FGET(FIELD) _I2C_I2CDXR_FGET(1,##FIELD)

  #define _I2C_I2CDXR0_FSET(FIELD,f) _I2C_I2CDXR_FSET(0,##FIELD,f)
  #define _I2C_I2CDXR1_FSET(FIELD,f) _I2C_I2CDXR_FSET(1,##FIELD,f)

  #define _I2C_I2CDXR0_FSETS(FIELD,SYM) _I2C_I2CDXR_FSETS(0,##FIELD,##SYM)
  #define _I2C_I2CDXR1_FSETS(FIELD,SYM) _I2C_I2CDXR_FSETS(1,##FIELD,##SYM)

/******************************************************************************\
*  ___________________
* |                   |
* |  I 2 C M D R      |
* |___________________|
*
* I2CMDR0    - I2C0 Mode register
* I2CMDR1    - I2C1 Mode register
*
* FIELDS (msb -> lsb)
* (rw) NACKMOD
* (rw) FREE
* (rw) STT
* (rw) STP
* (rw) MST
* (rw) TRX
* (rw) XA
* (rw) RM
* (rw) DLB
* (rw) IRS
* (rw) STB
* (rw) FDF
* (rw) BC
\******************************************************************************/
  #define _I2C_I2CMDR_OFFSET           9

  #define _I2C_I2CMDR0_ADDR            0x01B40024
  #define _I2C_I2CMDR1_ADDR            0x01B44024

  #define _I2C_I2CMDR_NACKMOD_MASK     0x00008000u
  #define _I2C_I2CMDR_NACKMOD_SHIFT    0x0000000Fu
  #define  I2C_I2CMDR_NACKMOD_DEFAULT  0x00000000u
  #define  I2C_I2CMDR_NACKMOD_OF(x)    _VALUEOF(x)
  #define  I2C_I2CMDR_NACKMOD_ACK      0x00000000u
  #define  I2C_I2CMDR_NACKMOD_NACK     0x00000001u

  #define _I2C_I2CMDR_FREE_MASK        0x00004000u
  #define _I2C_I2CMDR_FREE_SHIFT       0x0000000Eu
  #define  I2C_I2CMDR_FREE_DEFAULT     0x00000000u
  #define  I2C_I2CMDR_FREE_OF(x)       _VALUEOF(x)
  #define  I2C_I2CMDR_FREE_BSTOP       0x00000000u
  #define  I2C_I2CMDR_FREE_RFREE       0x00000001u

  #define _I2C_I2CMDR_STT_MASK         0x00002000u
  #define _I2C_I2CMDR_STT_SHIFT        0x0000000Du
  #define  I2C_I2CMDR_STT_DEFAULT      0x00000000u
  #define  I2C_I2CMDR_STT_OF(x)        _VALUEOF(x)
  #define  I2C_I2CMDR_STT_NONE         0x00000000u
  #define  I2C_I2CMDR_STT_START        0x00000001u

  #define _I2C_I2CMDR_STP_MASK         0x00000800u
  #define _I2C_I2CMDR_STP_SHIFT        0x0000000Bu
  #define  I2C_I2CMDR_STP_DEFAULT      0x00000000u
  #define  I2C_I2CMDR_STP_OF(x)        _VALUEOF(x)
  #define  I2C_I2CMDR_STP_NONE         0x00000000u
  #define  I2C_I2CMDR_STP_STOP         0x00000001u

  #define _I2C_I2CMDR_MST_MASK         0x00000400u
  #define _I2C_I2CMDR_MST_SHIFT        0x0000000Au
  #define  I2C_I2CMDR_MST_DEFAULT      0x00000000u
  #define  I2C_I2CMDR_MST_OF(x)        _VALUEOF(x)
  #define  I2C_I2CMDR_MST_SLAVE        0x00000000u
  #define  I2C_I2CMDR_MST_MASTER       0x00000001u

  #define _I2C_I2CMDR_TRX_MASK         0x00000200u
  #define _I2C_I2CMDR_TRX_SHIFT        0x00000009u
  #define  I2C_I2CMDR_TRX_DEFAULT      0x00000000u
  #define  I2C_I2CMDR_TRX_OF(x)        _VALUEOF(x)
  #define  I2C_I2CMDR_TRX_RCV          0x00000000u
  #define  I2C_I2CMDR_TRX_XMT          0x00000001u

  #define _I2C_I2CMDR_XA_MASK          0x00000100u
  #define _I2C_I2CMDR_XA_SHIFT         0x00000008u
  #define  I2C_I2CMDR_XA_DEFAULT       0x00000000u
  #define  I2C_I2CMDR_XA_OF(x)         _VALUEOF(x)
  #define  I2C_I2CMDR_XA_7BIT          0x00000000u
  #define  I2C_I2CMDR_XA_10BIT         0x00000001u

  #define _I2C_I2CMDR_RM_MASK          0x00000080u
  #define _I2C_I2CMDR_RM_SHIFT         0x00000007u
  #define  I2C_I2CMDR_RM_DEFAULT       0x00000000u
  #define  I2C_I2CMDR_RM_OF(x)         _VALUEOF(x)
  #define  I2C_I2CMDR_RM_NONE          0x00000000u
  #define  I2C_I2CMDR_RM_REPEAD        0x00000001u

  #define _I2C_I2CMDR_DLB_MASK         0x00000040u
  #define _I2C_I2CMDR_DLB_SHIFT        0x00000006u
  #define  I2C_I2CMDR_DLB_DEFAULT      0x00000000u
  #define  I2C_I2CMDR_DLB_OF(x)        _VALUEOF(x)
  #define  I2C_I2CMDR_DLB_NONE         0x00000000u
  #define  I2C_I2CMDR_DLB_LOOPBACK     0x00000001u

  #define _I2C_I2CMDR_IRS_MASK         0x00000020u
  #define _I2C_I2CMDR_IRS_SHIFT        0x00000005u
  #define  I2C_I2CMDR_IRS_DEFAULT      0x00000000u
  #define  I2C_I2CMDR_IRS_OF(x)        _VALUEOF(x)
  #define  I2C_I2CMDR_IRS_RST          0x00000000u
  #define  I2C_I2CMDR_IRS_NRST         0x00000001u

  #define _I2C_I2CMDR_STB_MASK         0x00000010u
  #define _I2C_I2CMDR_STB_SHIFT        0x00000004u
  #define  I2C_I2CMDR_STB_DEFAULT      0x00000000u
  #define  I2C_I2CMDR_STB_OF(x)        _VALUEOF(x)
  #define  I2C_I2CMDR_STB_NONE         0x00000000u
  #define  I2C_I2CMDR_STB_SET          0x00000001u

  #define _I2C_I2CMDR_FDF_MASK         0x00000008u
  #define _I2C_I2CMDR_FDF_SHIFT        0x00000003u
  #define  I2C_I2CMDR_FDF_DEFAULT      0x00000000u
  #define  I2C_I2CMDR_FDF_OF(x)        _VFDFUEOF(x)
  #define  I2C_I2CMDR_FDF_NONE         0x00000000u
  #define  I2C_I2CMDR_FDF_SET          0x00000001u

  #define _I2C_I2CMDR_BC_MASK          0x00000007u
  #define _I2C_I2CMDR_BC_SHIFT         0x00000000u
  #define  I2C_I2CMDR_BC_DEFAULT       0x00000000u
  #define  I2C_I2CMDR_BC_OF(x)         _VALUEOF(x)
  #define  I2C_I2CMDR_BC_BIT8FDF       0x00000000u
  #define  I2C_I2CMDR_BC_BIT7FDF       0x00000007u
  #define  I2C_I2CMDR_BC_BIT6FDF       0x00000006u
  #define  I2C_I2CMDR_BC_BIT5FDF       0x00000005u
  #define  I2C_I2CMDR_BC_BIT4FDF       0x00000004u
  #define  I2C_I2CMDR_BC_BIT3FDF       0x00000003u
  #define  I2C_I2CMDR_BC_BIT2FDF       0x00000002u
  #define  I2C_I2CMDR_BC_BIT1FDF       0x00000001u

  #define  I2C_I2CMDR_OF(x)                _VALUEOF(x)

  #define I2C_I2CMDR_DEFAULT (Uint32)(\
      _PER_FDEFAULT(I2C,I2CMDR,NACKMOD)\
     |_PER_FDEFAULT(I2C,I2CMDR,FREE)\
     |_PER_FDEFAULT(I2C,I2CMDR,STT)\
     |_PER_FDEFAULT(I2C,I2CMDR,STP)\
     |_PER_FDEFAULT(I2C,I2CMDR,MST)\
     |_PER_FDEFAULT(I2C,I2CMDR,TRX)\
     |_PER_FDEFAULT(I2C,I2CMDR,XA)\
     |_PER_FDEFAULT(I2C,I2CMDR,RM)\
     |_PER_FDEFAULT(I2C,I2CMDR,DLB)\
     |_PER_FDEFAULT(I2C,I2CMDR,IRS)\
     |_PER_FDEFAULT(I2C,I2CMDR,STB)\
     |_PER_FDEFAULT(I2C,I2CMDR,FDF)\
     |_PER_FDEFAULT(I2C,I2CMDR,BC)\
  )

  #define I2C_I2CMDR_RMK(nackmod,free,stt,stp,mst,trx,xa,rm,dlb,irs,stb,fdf,bc) (Uint32)(\
      _PER_FMK(I2C,I2CMDR,NACKMOD,nackmod)\
     |_PER_FMK(I2C,I2CMDR,FREE,free)\
     |_PER_FMK(I2C,I2CMDR,STT,stt)\
     |_PER_FMK(I2C,I2CMDR,STP,stp)\
     |_PER_FMK(I2C,I2CMDR,MST,mst)\
     |_PER_FMK(I2C,I2CMDR,TRX,trx)\
     |_PER_FMK(I2C,I2CMDR,XA,xa)\
     |_PER_FMK(I2C,I2CMDR,RM,rm)\
     |_PER_FMK(I2C,I2CMDR,DLB,dlb)\
     |_PER_FMK(I2C,I2CMDR,IRS,irs)\
     |_PER_FMK(I2C,I2CMDR,STB,stb)\
     |_PER_FMK(I2C,I2CMDR,FDF,fdf)\
     |_PER_FMK(I2C,I2CMDR,BC,bc)\
  )
   
  #define _I2C_I2CMDR_FGET(N,FIELD)\
    _PER_FGET(_I2C_I2CMDR##N##_ADDR,I2C,I2CMDR,##FIELD)

  #define _I2C_I2CMDR_FSET(N,FIELD,field)\
    _PER_FSET(_I2C_I2CMDR##N##_ADDR,I2C,I2CMDR,##FIELD,field)

  #define _I2C_I2CMDR_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_I2C_I2CMDR##N##_ADDR,I2C,I2CMDR,##FIELD,##SYM)

  #define _I2C_I2CMDR0_FGET(FIELD) _I2C_I2CMDR_FGET(0,##FIELD)
  #define _I2C_I2CMDR1_FGET(FIELD) _I2C_I2CMDR_FGET(1,##FIELD)

  #define _I2C_I2CMDR0_FSET(FIELD,f) _I2C_I2CMDR_FSET(0,##FIELD,f)
  #define _I2C_I2CMDR1_FSET(FIELD,f) _I2C_I2CMDR_FSET(1,##FIELD,f)

  #define _I2C_I2CMDR0_FSETS(FIELD,SYM) _I2C_I2CMDR_FSETS(0,##FIELD,##SYM)
  #define _I2C_I2CMDR1_FSETS(FIELD,SYM) _I2C_I2CMDR_FSETS(1,##FIELD,##SYM)

/******************************************************************************\
*  (Keeping the old definitions for backward compatibility)
*  ___________________
* |                   |
* |  I 2 C I V R      |
* |___________________|
*
* I2CIVR0    - I2C0 Interrupt Vector register
* I2CIVR1    - I2C1 Interrupt Vector register
*
* FIELDS (msb -> lsb)
* (r) INTCODE
\******************************************************************************/

#if (!(CHIP_6410 | CHIP_6413 | CHIP_6418))
  #define _I2C_I2CIVR_OFFSET           10

  #define _I2C_I2CIVR0_ADDR            0x01B40028
  #define _I2C_I2CIVR1_ADDR            0x01B44028

  /*** old names ***/
  #define _I2C_I2CISR0_ADDR        _I2C_I2CIVR0_ADDR            
  #define _I2C_I2CISR1_ADDR        _I2C_I2CIVR1_ADDR            

  #define _I2C_I2CIVR_INTCODE_MASK     0x00000007u
  #define _I2C_I2CIVR_INTCODE_SHIFT    0x00000000u
  #define  I2C_I2CIVR_INTCODE_DEFAULT  0x00000000u
  #define  I2C_I2CIVR_INTCODE_OF(x)    _VALUEOF(x)
  #define  I2C_I2CIVR_INTCODE_NONE     0x00000000u
  #define  I2C_I2CIVR_INTCODE_AL       0x00000001u
  #define  I2C_I2CIVR_INTCODE_NACK     0x00000002u
  #define  I2C_I2CIVR_INTCODE_RAR      0x00000003u
  #define  I2C_I2CIVR_INTCODE_RDR      0x00000004u
  #define  I2C_I2CIVR_INTCODE_XDR      0x00000005u

  #define  I2C_I2CIVR_OF(x)             _VALUEOF(x)

  #define I2C_I2CIVR_DEFAULT (Uint32)(\
     _PER_FDEFAULT(I2C,I2CIVR,INTCODE)\
  )

  #define I2C_I2CIVR_RMK(intcode) (Uint32)(\
     _PER_FMK(I2C,I2CIVR,INTCODE,intcode)\
  )
   
  #define _I2C_I2CIVR_FGET(N,FIELD)\
    _PER_FGET(_I2C_I2CIVR##N##_ADDR,I2C,I2CIVR,##FIELD)

  #define _I2C_I2CIVR_FSET(N,FIELD,field)\
    _PER_FSET(_I2C_I2CIVR##N##_ADDR,I2C,I2CIVR,##FIELD,field)

  #define _I2C_I2CIVR_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_I2C_I2CIVR##N##_ADDR,I2C,I2CIVR,##FIELD,##SYM)

  #define _I2C_I2CIVR0_FGET(FIELD) _I2C_I2CIVR_FGET(0,##FIELD)
  #define _I2C_I2CIVR1_FGET(FIELD) _I2C_I2CIVR_FGET(1,##FIELD)

  #define _I2C_I2CIVR0_FSET(FIELD,f) _I2C_I2CIVR_FSET(0,##FIELD,f)
  #define _I2C_I2CIVR1_FSET(FIELD,f) _I2C_I2CIVR_FSET(1,##FIELD,f)

  #define _I2C_I2CIVR0_FSETS(FIELD,SYM) _I2C_I2CIVR_FSETS(0,##FIELD,##SYM)
  #define _I2C_I2CIVR1_FSETS(FIELD,SYM) _I2C_I2CIVR_FSETS(1,##FIELD,##SYM)
#endif

/******************************************************************************\
*  ___________________
* |                   |
* |  I 2 C I S R C    |
* |___________________|
*
* I2CISRC0    - I2C0 Interrupt Vector register
* I2CISRC1    - I2C1 Interrupt Vector register
*
* FIELDS (msb -> lsb)
* (r) INTCODE
\******************************************************************************/

  #define _I2C_I2CISRC_OFFSET           10

  #define _I2C_I2CISRC0_ADDR            0x01B40028
  #define _I2C_I2CISRC1_ADDR            0x01B44028

  #define _I2C_I2CISRC_INTCODE_MASK     0x00000007u
  #define _I2C_I2CISRC_INTCODE_SHIFT    0x00000000u
  #define  I2C_I2CISRC_INTCODE_DEFAULT  0x00000000u
  #define  I2C_I2CISRC_INTCODE_OF(x)    _VALUEOF(x)
  #define  I2C_I2CISRC_INTCODE_NONE     0x00000000u
  #define  I2C_I2CISRC_INTCODE_AL       0x00000001u
  #define  I2C_I2CISRC_INTCODE_NACK     0x00000002u
  #define  I2C_I2CISRC_INTCODE_RAR      0x00000003u
  #define  I2C_I2CISRC_INTCODE_RDR      0x00000004u
  #define  I2C_I2CISRC_INTCODE_XDR      0x00000005u
#if (CHIP_6413 | CHIP_6418 | CHIP_6410)
  #define  I2C_I2CISRC_INTCODE_SCD      0x00000006u
  #define  I2C_I2CISRC_INTCODE_AAS      0x00000007u
#endif

  #define  I2C_I2CISRC_OF(x)             _VALUEOF(x)

  #define I2C_I2CISRC_DEFAULT (Uint32)(\
     _PER_FDEFAULT(I2C,I2CISRC,INTCODE)\
  )

  #define I2C_I2CISRC_RMK(intcode) (Uint32)(\
     _PER_FMK(I2C,I2CISRC,INTCODE,intcode)\
  )
   
  #define _I2C_I2CISRC_FGET(N,FIELD)\
    _PER_FGET(_I2C_I2CISRC##N##_ADDR,I2C,I2CISRC,##FIELD)

  #define _I2C_I2CISRC_FSET(N,FIELD,field)\
    _PER_FSET(_I2C_I2CISRC##N##_ADDR,I2C,I2CISRC,##FIELD,field)

  #define _I2C_I2CISRC_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_I2C_I2CISRC##N##_ADDR,I2C,I2CISRC,##FIELD,##SYM)

  #define _I2C_I2CISRC0_FGET(FIELD) _I2C_I2CISRC_FGET(0,##FIELD)
  #define _I2C_I2CISRC1_FGET(FIELD) _I2C_I2CISRC_FGET(1,##FIELD)

  #define _I2C_I2CISRC0_FSET(FIELD,f) _I2C_I2CISRC_FSET(0,##FIELD,f)
  #define _I2C_I2CISRC1_FSET(FIELD,f) _I2C_I2CISRC_FSET(1,##FIELD,f)

  #define _I2C_I2CISRC0_FSETS(FIELD,SYM) _I2C_I2CISRC_FSETS(0,##FIELD,##SYM)
  #define _I2C_I2CISRC1_FSETS(FIELD,SYM) _I2C_I2CISRC_FSETS(1,##FIELD,##SYM)

/******************************************************************************\
*  ___________________
* |                   |
* |  I 2 C E M D R    |
* |___________________|
*
* I2CEMDR0    - I2C0 Extended Mode register(1)
* I2CEMDR1    - I2C1 Extended Mode register(1)
*
* FIELDS (msb -> lsb)
* (rw) XRDYM
*
* (1) For C6418/C6413/C6410 only
\******************************************************************************/
#if (CHIP_6413 | CHIP_6418 | CHIP_6410)
  #define _I2C_I2CEMDR_OFFSET           11

  #define _I2C_I2CEMDR0_ADDR            0x01B4002C
  #define _I2C_I2CEMDR1_ADDR            0x01B4402C

  #define _I2C_I2CEMDR_XRDYM_MASK         0x00000001u
  #define _I2C_I2CEMDR_XRDYM_SHIFT        0x00000000u
  #define  I2C_I2CEMDR_XRDYM_DEFAULT      0x00000001u
  #define  I2C_I2CEMDR_XRDYM_OF(x)        _VALUEOF(x)
  #define  I2C_I2CEMDR_XRDYM_MSTACK       0x00000000u
  #define  I2C_I2CEMDR_XRDYM_DXRCPY       0x00000001u

  #define  I2C_I2CEMDR_OF(x)             _VALUEOF(x)

  #define I2C_I2CEMDR_DEFAULT (Uint32)(\
     _PER_FDEFAULT(I2C,I2CEMDR,XRDYM)\
  )

  #define I2C_I2CEMDR_RMK(xrdym) (Uint32)(\
     _PER_FMK(I2C,I2CEMDR,XRDYM,xrdym)\
  )
   
  #define _I2C_I2CEMDR_FGET(N,FIELD)\
    _PER_FGET(_I2C_I2CEMDR##N##_ADDR,I2C,I2CEMDR,##FIELD)

  #define _I2C_I2CEMDR_FSET(N,FIELD,field)\
    _PER_FSET(_I2C_I2CEMDR##N##_ADDR,I2C,I2CEMDR,##FIELD,field)

  #define _I2C_I2CEMDR_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_I2C_I2CEMDR##N##_ADDR,I2C,I2CEMDR,##FIELD,##SYM)

  #define _I2C_I2CEMDR0_FGET(FIELD) _I2C_I2CEMDR_FGET(0,##FIELD)
  #define _I2C_I2CEMDR1_FGET(FIELD) _I2C_I2CEMDR_FGET(1,##FIELD)

  #define _I2C_I2CEMDR0_FSET(FIELD,f) _I2C_I2CEMDR_FSET(0,##FIELD,f)
  #define _I2C_I2CEMDR1_FSET(FIELD,f) _I2C_I2CEMDR_FSET(1,##FIELD,f)

  #define _I2C_I2CEMDR0_FSETS(FIELD,SYM) _I2C_I2CEMDR_FSETS(0,##FIELD,##SYM)
  #define _I2C_I2CEMDR1_FSETS(FIELD,SYM) _I2C_I2CEMDR_FSETS(1,##FIELD,##SYM)
#endif

/******************************************************************************\
*  ___________________
* |                   |
* |  I 2 C P S C      |
* |___________________|
*
* I2CPSC0    - I2C0 Prescaler register
* I2CPSC1    - I2C1 Prescaler register
*
* FIELDS (msb -> lsb)
* (rw) IPSC
\******************************************************************************/
  #define _I2C_I2CPSC_OFFSET           12

  #define _I2C_I2CPSC0_ADDR            0x01B40030
  #define _I2C_I2CPSC1_ADDR            0x01B44030

  #define _I2C_I2CPSC_IPSC_MASK     0x000000FFu
  #define _I2C_I2CPSC_IPSC_SHIFT    0x00000000u
  #define  I2C_I2CPSC_IPSC_DEFAULT  0x00000000u
  #define  I2C_I2CPSC_IPSC_OF(x)    _VALUEOF(x)

  #define  I2C_I2CPSC_OF(x)             _VALUEOF(x)

  #define I2C_I2CPSC_DEFAULT (Uint32)(\
     _PER_FDEFAULT(I2C,I2CPSC,IPSC)\
  )

  #define I2C_I2CPSC_RMK(ipsc) (Uint32)(\
     _PER_FMK(I2C,I2CPSC,IPSC,ipsc)\
  )
   
  #define _I2C_I2CPSC_FGET(N,FIELD)\
    _PER_FGET(_I2C_I2CPSC##N##_ADDR,I2C,I2CPSC,##FIELD)

  #define _I2C_I2CPSC_FSET(N,FIELD,field)\
    _PER_FSET(_I2C_I2CPSC##N##_ADDR,I2C,I2CPSC,##FIELD,field)

  #define _I2C_I2CPSC_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_I2C_I2CPSC##N##_ADDR,I2C,I2CPSC,##FIELD,##SYM)

  #define _I2C_I2CPSC0_FGET(FIELD) _I2C_I2CPSC_FGET(0,##FIELD)
  #define _I2C_I2CPSC1_FGET(FIELD) _I2C_I2CPSC_FGET(1,##FIELD)

  #define _I2C_I2CPSC0_FSET(FIELD,f) _I2C_I2CPSC_FSET(0,##FIELD,f)
  #define _I2C_I2CPSC1_FSET(FIELD,f) _I2C_I2CPSC_FSET(1,##FIELD,f)

  #define _I2C_I2CPSC0_FSETS(FIELD,SYM) _I2C_I2CPSC_FSETS(0,##FIELD,##SYM)
  #define _I2C_I2CPSC1_FSETS(FIELD,SYM) _I2C_I2CPSC_FSETS(1,##FIELD,##SYM)

/******************************************************************************\
*  ___________________
* |                   |
* |  I 2 C P I D 1    |
* |___________________|
*
* I2CPID10    - I2C0 Peripheral ID Register 1(1)
* I2CPID11    - I2C1 Peripheral ID Register 1(1)
*
* FIELDS (msb -> lsb)
* (r) CLASS
* (r) REVISION
*
* (1) For C6418/C6413/C6410 only
\******************************************************************************/
#if (CHIP_6413 | CHIP_6418 | CHIP_6410)
  #define _I2C_I2CPID1_OFFSET           13

  #define _I2C_I2CPID10_ADDR            0x01B40034
  #define _I2C_I2CPID11_ADDR            0x01B44034

  #define _I2C_I2CPID1_CLASS_MASK     0x0000FF00u
  #define _I2C_I2CPID1_CLASS_SHIFT    0x00000008u
  #define  I2C_I2CPID1_CLASS_DEFAULT  0x00000001u
  #define  I2C_I2CPID1_CLASS_OF(x)    _VALUEOF(x)

  #define _I2C_I2CPID1_REVISION_MASK     0x000000FFu
  #define _I2C_I2CPID1_REVISION_SHIFT    0x00000000u
  #define  I2C_I2CPID1_REVISION_DEFAULT  0x00000025u
  #define  I2C_I2CPID1_REVISION_OF(x)    _VALUEOF(x)

  #define  I2C_I2CPID1_OF(x)             _VALUEOF(x)
  
  #define I2C_I2CPID1_DEFAULT (Uint32)(\
     _PER_FDEFAULT(I2C,I2CPID1,CLASS)\
    |_PER_FDEFAULT(I2C,I2CPID1,REVISION)\
  )

  #define _I2C_I2CPID1_FGET(N,FIELD)\
    _PER_FGET(_I2C_I2CPID1##N##_ADDR,I2C,I2CPID1,##FIELD)

  #define _I2C_I2CPID10_FGET(FIELD) _I2C_I2CPID1_FGET(0,##FIELD)
  #define _I2C_I2CPID11_FGET(FIELD) _I2C_I2CPID1_FGET(1,##FIELD)
#endif /* CHIP_6413 | CHIP_6418 | CHIP_6410 */

/******************************************************************************\
*  ___________________
* |                   |
* |  I 2 C P I D 2    |
* |___________________|
*
* I2CPID20    - I2C0 Peripheral ID Register 2(1)
* I2CPID21    - I2C1 Peripheral ID Register 2(1)
*
* FIELDS (msb -> lsb)
* (r) TYPE
*
* (1) For C6418/C6413/C6410 only
\******************************************************************************/
#if (CHIP_6413 | CHIP_6418 | CHIP_6410)
  #define _I2C_I2CPID2_OFFSET           14

  #define _I2C_I2CPID20_ADDR            0x01B40038
  #define _I2C_I2CPID21_ADDR            0x01B44038

  #define _I2C_I2CPID2_TYPE_MASK     0x000000FFu
  #define _I2C_I2CPID2_TYPE_SHIFT    0x00000000u
  #define  I2C_I2CPID2_TYPE_DEFAULT  0x00000005u
  #define  I2C_I2CPID2_TYPE_OF(x)    _VALUEOF(x)

  #define  I2C_I2CPID2_OF(x)             _VALUEOF(x)
  
  #define I2C_I2CPID2_DEFAULT (Uint32)(\
     _PER_FDEFAULT(I2C,I2CPID2,TYPE)\
  )

  #define _I2C_I2CPID2_FGET(N,FIELD)\
    _PER_FGET(_I2C_I2CPID2##N##_ADDR,I2C,I2CPID2,##FIELD)

  #define _I2C_I2CPID20_FGET(FIELD) _I2C_I2CPID2_FGET(0,##FIELD)
  #define _I2C_I2CPID21_FGET(FIELD) _I2C_I2CPID2_FGET(1,##FIELD)

#endif /* CHIP_6413 | CHIP_6418 | CHIP_6410) */

/******************************************************************************\
* _____________________
* |                   |
* |  I 2 C P F U N C  |
* |___________________|
*
* I2CPFUNC0  - I2C 0 Pin Function Register(1)
* I2CPFUNC1  - I2C 1 Pin Function Register(1)
*
* FIELDS (msb -> lsb)
* (rw) GPMODE 
*
* (1) For C6418/C6413/C6410 only
\******************************************************************************/
#if (CHIP_6413 | CHIP_6418 | CHIP_6410)
  #define _I2C_I2CPFUNC_OFFSET            18

  #define _I2C_I2CPFUNC0_ADDR              0x01B40048
  #define _I2C_I2CPFUNC1_ADDR              0x01B44048

  #define _I2C_I2CPFUNC_GPMODE_MASK            0x00000001u
  #define _I2C_I2CPFUNC_GPMODE_SHIFT           0x00000000u
  #define  I2C_I2CPFUNC_GPMODE_DEFAULT         0x00000000u
  #define  I2C_I2CPFUNC_GPMODE_OF(x)           _VALUEOF(x)
  #define  I2C_I2CPFUNC_GPMODE_ENABLE          0x00000001u
  #define  I2C_I2CPFUNC_GPMODE_DISABLE         0x00000000u
  
  #define  I2C_I2CPFUNC_OF(x)             _VALUEOF(x)

  #define I2C_I2CPFUNC_DEFAULT (Uint32)(\
    _PER_FDEFAULT(I2C,I2CPFUNC,GPMODE)\
  )

  #define I2C_I2CPFUNC_RMK(gpmode) (Uint32)(\
    _PER_FMK(I2C,I2CPFUNC,GPMODE,gpmode)\
  )

  #define _I2C_I2CPFUNC_FGET(N,FIELD)\
    _PER_FGET(_I2C_I2CPFUNC##N##_ADDR,I2C,I2CPFUNC,##FIELD)

  #define _I2C_I2CPFUNC_FSET(N,FIELD,field)\
    _PER_FSET(_I2C_I2CPFUNC##N##_ADDR,I2C,I2CPFUNC,##FIELD,field)

  #define _I2C_I2CPFUNC_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_I2C_I2CPFUNC##N##_ADDR,I2C,I2CPFUNC,##FIELD,##SYM)

  #define _I2C_I2CPFUNC0_FGET(FIELD) _I2C_I2CPFUNC_FGET(0,##FIELD)
  #define _I2C_I2CPFUNC1_FGET(FIELD) _I2C_I2CPFUNC_FGET(1,##FIELD)

  #define _I2C_I2CPFUNC0_FSET(FIELD,f) _I2C_I2CPFUNC_FSET(0,##FIELD,f)
  #define _I2C_I2CPFUNC1_FSET(FIELD,f) _I2C_I2CPFUNC_FSET(1,##FIELD,f)

  #define _I2C_I2CPFUNC0_FSETS(FIELD,SYM) _I2C_I2CPFUNC_FSETS(0,##FIELD,##SYM)
  #define _I2C_I2CPFUNC1_FSETS(FIELD,SYM) _I2C_I2CPFUNC_FSETS(1,##FIELD,##SYM)
#endif /* CHIP_6413 | CHIP_6418 | CHIP_6410) */
  
/******************************************************************************\
* ___________________
* |                 |
* |  I 2 C P D I R  |
* |_________________|
*
* I2CPDIR0  - I2C 0 Pin Direction Register(1)
* I2CPDIR1  - I2C 1 Pin Direction Register(1)
*
* FIELDS (msb -> lsb)
* (rw) SDADIR
* (rw) SCLDIR
*
* (1) For C6418/C6413/C6410 only
\******************************************************************************/
#if (CHIP_6413 | CHIP_6418 | CHIP_6410)
  #define _I2C_I2CPDIR_OFFSET             19

  #define _I2C_I2CPDIR0_ADDR              0x01B4004C
  #define _I2C_I2CPDIR1_ADDR              0x01B4404C

  #define _I2C_I2CPDIR_SDADIR_MASK         0x00000002u
  #define _I2C_I2CPDIR_SDADIR_SHIFT        0x00000001u
  #define  I2C_I2CPDIR_SDADIR_DEFAULT      0x00000000u
  #define  I2C_I2CPDIR_SDADIR_OF(x)        _VALUEOF(x)
  #define  I2C_I2CPDIR_SDADIR_INPUT        0x00000000u
  #define  I2C_I2CPDIR_SDADIR_OUTPUT       0x00000001u
  
  #define _I2C_I2CPDIR_SCLDIR_MASK         0x00000001u
  #define _I2C_I2CPDIR_SCLDIR_SHIFT        0x00000000u
  #define  I2C_I2CPDIR_SCLDIR_DEFAULT      0x00000000u
  #define  I2C_I2CPDIR_SCLDIR_OF(x)        _VALUEOF(x)
  #define  I2C_I2CPDIR_SCLDIR_INPUT        0x00000000u
  #define  I2C_I2CPDIR_SCLDIR_OUTPUT       0x00000001u
  
  #define  I2C_I2CPDIR_OF(x)              _VALUEOF(x)

  #define I2C_I2CPDIR_DEFAULT (Uint32)(\
    _PER_FDEFAULT(I2C,I2CPDIR,SDADIR)\
   |_PER_FDEFAULT(I2C,I2CPDIR,SCLDIR)\
  )

  #define I2C_I2CPDIR_RMK(sdadir,scldir) (Uint32)(\
    _PER_FMK(I2C,I2CPDIR,SDADIR,sdadir)\
   |_PER_FMK(I2C,I2CPDIR,SCLDIR,scldir)\
  )

  #define _I2C_I2CPDIR_FGET(N,FIELD)\
    _PER_FGET(_I2C_I2CPDIR##N##_ADDR,I2C,I2CPDIR,##FIELD)

  #define _I2C_I2CPDIR_FSET(N,FIELD,field)\
    _PER_FSET(_I2C_I2CPDIR##N##_ADDR,I2C,I2CPDIR,##FIELD,field)

  #define _I2C_I2CPDIR_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_I2C_I2CPDIR##N##_ADDR,I2C,I2CPDIR,##FIELD,##SYM)

  #define _I2C_I2CPDIR0_FGET(FIELD) _I2C_I2CPDIR_FGET(0,##FIELD)
  #define _I2C_I2CPDIR1_FGET(FIELD) _I2C_I2CPDIR_FGET(1,##FIELD)

  #define _I2C_I2CPDIR0_FSET(FIELD,f) _I2C_I2CPDIR_FSET(0,##FIELD,f)
  #define _I2C_I2CPDIR1_FSET(FIELD,f) _I2C_I2CPDIR_FSET(1,##FIELD,f)

  #define _I2C_I2CPDIR0_FSETS(FIELD,SYM) _I2C_I2CPDIR_FSETS(0,##FIELD,##SYM)
  #define _I2C_I2CPDIR1_FSETS(FIELD,SYM) _I2C_I2CPDIR_FSETS(1,##FIELD,##SYM)
#endif /* CHIP_6413 | CHIP_6418 | CHIP_6410) */

/******************************************************************************\
* ___________________
* |                 |
* |  I 2 C P D I N  |
* |_________________|
*
* I2CPDIN0  - I2C 0 Pin Data In Register(1)
* I2CPDIN1  - I2C 1 Pin Data In Register(1)
*
* FIELDS (msb -> lsb)
* (r) SDAIN
* (r) SCLIN
*
* (1) For C6418/C6413/C6410 only
\******************************************************************************/
#if (CHIP_6413 | CHIP_6418 | CHIP_6410)
  #define _I2C_I2CPDIN_OFFSET             20

  #define _I2C_I2CPDIN0_ADDR              0x01B40050
  #define _I2C_I2CPDIN1_ADDR              0x01B44050

  #define _I2C_I2CPDIN_SDAIN_MASK         0x00000002u
  #define _I2C_I2CPDIN_SDAIN_SHIFT        0x00000001u
  #define  I2C_I2CPDIN_SDAIN_OF(x)        _VALUEOF(x)
  #define  I2C_I2CPDIN_SDAIN_LOW          0x00000000u
  #define  I2C_I2CPDIN_SDAIN_HIGH         0x00000001u
  
  #define _I2C_I2CPDIN_SCLIN_MASK         0x00000001u
  #define _I2C_I2CPDIN_SCLIN_SHIFT        0x00000000u
  #define  I2C_I2CPDIN_SCLIN_OF(x)        _VALUEOF(x)
  #define  I2C_I2CPDIN_SCLIN_LOW          0x00000000u
  #define  I2C_I2CPDIN_SCLIN_HIGH         0x00000001u
  
  #define  I2C_I2CPDIN_OF(x)              _VALUEOF(x)

  #define I2C_I2CPDIN_DEFAULT (Uint32)(\
    _PER_FDEFAULT(I2C,I2CPDIN,SDAIN)\
   |_PER_FDEFAULT(I2C,I2CPDIN,SCLIN)\
  )

  #define I2C_I2CPDIN_RMK(sdain,sclin) (Uint32)(\
    _PER_FMK(I2C,I2CPDIN,SDAIN,sdain)\
   |_PER_FMK(I2C,I2CPDIN,SCLIN,sclin)\
  )

  #define _I2C_I2CPDIN_FGET(N,FIELD)\
    _PER_FGET(_I2C_I2CPDIN##N##_ADDR,I2C,I2CPDIN,##FIELD)

  #define _I2C_I2CPDIN0_FGET(FIELD) _I2C_I2CPDIN_FGET(0,##FIELD)
  #define _I2C_I2CPDIN1_FGET(FIELD) _I2C_I2CPDIN_FGET(1,##FIELD)

#endif /* CHIP_6413 | CHIP_6418 | CHIP_6410) */

/******************************************************************************\
* _____________________
* |                   |
* |  I 2 C P D O U T  |
* |___________________|
*
* I2CPDOUT0  - I2C 0 Pin Data Out Register(1)
* I2CPDOUT1  - I2C 1 Pin Data Out Register(1)
*
* FIELDS (msb -> lsb)
* (rw) SDAOUT
* (rw) SCLOUT
*
* (1) For C6418/C6413/C6410 only
\******************************************************************************/
#if (CHIP_6413 | CHIP_6418 | CHIP_6410)
  #define _I2C_I2CPDOUT_OFFSET              21

  #define _I2C_I2CPDOUT0_ADDR               0x01B40054
  #define _I2C_I2CPDOUT1_ADDR               0x01B44054

  #define _I2C_I2CPDOUT_SDAOUT_MASK         0x00000002u
  #define _I2C_I2CPDOUT_SDAOUT_SHIFT        0x00000001u
  #define  I2C_I2CPDOUT_SDAOUT_DEFAULT      0x00000000u
  #define  I2C_I2CPDOUT_SDAOUT_OF(x)        _VALUEOF(x)
  #define  I2C_I2CPDOUT_SDAOUT_LOW          0x00000000u
  #define  I2C_I2CPDOUT_SDAOUT_HIGH         0x00000001u
  
  #define _I2C_I2CPDOUT_SCLOUT_MASK         0x00000001u
  #define _I2C_I2CPDOUT_SCLOUT_SHIFT        0x00000000u
  #define  I2C_I2CPDOUT_SCLOUT_DEFAULT      0x00000000u
  #define  I2C_I2CPDOUT_SCLOUT_OF(x)        _VALUEOF(x)
  #define  I2C_I2CPDOUT_SCLOUT_LOW          0x00000000u
  #define  I2C_I2CPDOUT_SCLOUT_HIGH         0x00000001u
  
  #define  I2C_I2CPDOUT_OF(x)              _VALUEOF(x)

  #define I2C_I2CPDOUT_DEFAULT (Uint32)(\
    _PER_FDEFAULT(I2C,I2CPDOUT,SDAOUT)\
   |_PER_FDEFAULT(I2C,I2CPDOUT,SCLOUT)\
  )

  #define I2C_I2CPDOUT_RMK(sdaout,sclout) (Uint32)(\
    _PER_FMK(I2C,I2CPDOUT,SDAOUT,sdaout)\
   |_PER_FMK(I2C,I2CPDOUT,SCLOUT,sclout)\
  )

  #define _I2C_I2CPDOUT_FGET(N,FIELD)\
    _PER_FGET(_I2C_I2CPDOUT##N##_ADDR,I2C,I2CPDOUT,##FIELD)

  #define _I2C_I2CPDOUT_FSET(N,FIELD,field)\
    _PER_FSET(_I2C_I2CPDOUT##N##_ADDR,I2C,I2CPDOUT,##FIELD,field)

  #define _I2C_I2CPDOUT_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_I2C_I2CPDOUT##N##_ADDR,I2C,I2CPDOUT,##FIELD,##SYM)

  #define _I2C_I2CPDOUT0_FGET(FIELD) _I2C_I2CPDOUT_FGET(0,##FIELD)
  #define _I2C_I2CPDOUT1_FGET(FIELD) _I2C_I2CPDOUT_FGET(1,##FIELD)

  #define _I2C_I2CPDOUT0_FSET(FIELD,f) _I2C_I2CPDOUT_FSET(0,##FIELD,f)
  #define _I2C_I2CPDOUT1_FSET(FIELD,f) _I2C_I2CPDOUT_FSET(1,##FIELD,f)

  #define _I2C_I2CPDOUT0_FSETS(FIELD,SYM) _I2C_I2CPDOUT_FSETS(0,##FIELD,##SYM)
  #define _I2C_I2CPDOUT1_FSETS(FIELD,SYM) _I2C_I2CPDOUT_FSETS(1,##FIELD,##SYM)
#endif /* CHIP_6413 | CHIP_6418 | CHIP_6410) */

/******************************************************************************\
* _____________________
* |                   |
* |  I 2 C P D S E T  |
* |___________________|
*
* I2CPDSET0  - I2C 0 Pin Data Set Register(1)
* I2CPDSET1  - I2C 1 Pin Data Set Register(1)
*
* FIELDS (msb -> lsb)
* (rw) PDSET1
* (rw) PDSET0
*
* (1) For C6418/C6413/C6410 only
*
* Note: Read of these two bits is indeterminate
\******************************************************************************/
#if (CHIP_6413 | CHIP_6418 | CHIP_6410)
  #define _I2C_I2CPDSET_OFFSET              22

  #define _I2C_I2CPDSET0_ADDR               0x01B40058
  #define _I2C_I2CPDSET1_ADDR               0x01B44058

  #define _I2C_I2CPDSET_SDAOUT_MASK         0x00000002u
  #define _I2C_I2CPDSET_SDAOUT_SHIFT        0x00000001u
  #define  I2C_I2CPDSET_SDAOUT_DEFAULT      0x00000000u
  #define  I2C_I2CPDSET_SDAOUT_OF(x)        _VALUEOF(x)
  #define  I2C_I2CPDSET_SDAOUT_UNCHGN       0x00000000u
  #define  I2C_I2CPDSET_SDAOUT_SET          0x00000001u
  
  #define _I2C_I2CPDSET_SCLOUT_MASK         0x00000001u
  #define _I2C_I2CPDSET_SCLOUT_SHIFT        0x00000000u
  #define  I2C_I2CPDSET_SCLOUT_DEFAULT      0x00000000u
  #define  I2C_I2CPDSET_SCLOUT_OF(x)        _VALUEOF(x)
  #define  I2C_I2CPDSET_SCLOUT_UNCHGN       0x00000000u
  #define  I2C_I2CPDSET_SCLOUT_SET          0x00000001u
  
  #define  I2C_I2CPDSET_OF(x)              _VALUEOF(x)

  #define I2C_I2CPDSET_DEFAULT (Uint32)(\
    _PER_FDEFAULT(I2C,I2CPDSET,SDAOUT)\
   |_PER_FDEFAULT(I2C,I2CPDSET,SCLOUT)\
  )

  #define I2C_I2CPDSET_RMK(sdaout,sclout) (Uint32)(\
    _PER_FMK(I2C,I2CPDSET,SDAOUT,sdaout)\
   |_PER_FMK(I2C,I2CPDSET,SCLOUT,sclout)\
  )

  #define _I2C_I2CPDSET_FGET(N,FIELD)\
    _PER_FGET(_I2C_I2CPDSET##N##_ADDR,I2C,I2CPDSET,##FIELD)

  #define _I2C_I2CPDSET_FSET(N,FIELD,field)\
    _PER_FSET(_I2C_I2CPDSET##N##_ADDR,I2C,I2CPDSET,##FIELD,field)

  #define _I2C_I2CPDSET_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_I2C_I2CPDSET##N##_ADDR,I2C,I2CPDSET,##FIELD,##SYM)

  #define _I2C_I2CPDSET0_FGET(FIELD) _I2C_I2CPDSET_FGET(0,##FIELD)
  #define _I2C_I2CPDSET1_FGET(FIELD) _I2C_I2CPDSET_FGET(1,##FIELD)

  #define _I2C_I2CPDSET0_FSET(FIELD,f) _I2C_I2CPDSET_FSET(0,##FIELD,f)
  #define _I2C_I2CPDSET1_FSET(FIELD,f) _I2C_I2CPDSET_FSET(1,##FIELD,f)

  #define _I2C_I2CPDSET0_FSETS(FIELD,SYM) _I2C_I2CPDSET_FSETS(0,##FIELD,##SYM)
  #define _I2C_I2CPDSET1_FSETS(FIELD,SYM) _I2C_I2CPDSET_FSETS(1,##FIELD,##SYM)
#endif /* CHIP_6413 | CHIP_6418 | CHIP_6410) */

/******************************************************************************\
* _____________________
* |                   |
* |  I 2 C P D C L R  |
* |___________________|
*
* I2CPDCLR0  - I2C 0 Pin Data Clear Register(1)
* I2CPDCLR1  - I2C 1 Pin Data Clear Register(1)
*
* FIELDS (msb -> lsb)
* (rw) PDCLR1
* (rw) PDCLR0
*
* (1) For C6418/C6413/C6410 only
*
* Note: Read of these two bits is indeterminate
\******************************************************************************/
#if (CHIP_6413 | CHIP_6418 | CHIP_6410)
  #define _I2C_I2CPDCLR_OFFSET              23

  #define _I2C_I2CPDCLR0_ADDR               0x01B4005C
  #define _I2C_I2CPDCLR1_ADDR               0x01B4405C

  #define _I2C_I2CPDCLR_SDAOUT_MASK         0x00000002u
  #define _I2C_I2CPDCLR_SDAOUT_SHIFT        0x00000001u
  #define  I2C_I2CPDCLR_SDAOUT_DEFAULT      0x00000000u
  #define  I2C_I2CPDCLR_SDAOUT_OF(x)        _VALUEOF(x)
  #define  I2C_I2CPDCLR_SDAOUT_UNCHGN       0x00000000u
  #define  I2C_I2CPDCLR_SDAOUT_CLR          0x00000001u
  
  #define _I2C_I2CPDCLR_SCLOUT_MASK         0x00000001u
  #define _I2C_I2CPDCLR_SCLOUT_SHIFT        0x00000000u
  #define  I2C_I2CPDCLR_SCLOUT_DEFAULT      0x00000000u
  #define  I2C_I2CPDCLR_SCLOUT_OF(x)        _VALUEOF(x)
  #define  I2C_I2CPDCLR_SCLOUT_UNCHGN       0x00000000u
  #define  I2C_I2CPDCLR_SCLOUT_CLR          0x00000001u
  
  #define  I2C_I2CPDCLR_OF(x)              _VALUEOF(x)

  #define I2C_I2CPDCLR_DEFAULT (Uint32)(\
    _PER_FDEFAULT(I2C,I2CPDCLR,SDAOUT)\
   |_PER_FDEFAULT(I2C,I2CPDCLR,SCLOUT)\
  )

  #define I2C_I2CPDCLR_RMK(sdaout,sclout) (Uint32)(\
    _PER_FMK(I2C,I2CPDCLR,SDAOUT,sdaout)\
   |_PER_FMK(I2C,I2CPDCLR,SCLOUT,sclout)\
  )

  #define _I2C_I2CPDCLR_FGET(N,FIELD)\
    _PER_FGET(_I2C_I2CPDCLR##N##_ADDR,I2C,I2CPDCLR,##FIELD)

  #define _I2C_I2CPDCLR_FSET(N,FIELD,field)\
    _PER_FSET(_I2C_I2CPDCLR##N##_ADDR,I2C,I2CPDCLR,##FIELD,field)

  #define _I2C_I2CPDCLR_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_I2C_I2CPDCLR##N##_ADDR,I2C,I2CPDCLR,##FIELD,##SYM)

  #define _I2C_I2CPDCLR0_FGET(FIELD) _I2C_I2CPDCLR_FGET(0,##FIELD)
  #define _I2C_I2CPDCLR1_FGET(FIELD) _I2C_I2CPDCLR_FGET(1,##FIELD)

  #define _I2C_I2CPDCLR0_FSET(FIELD,f) _I2C_I2CPDCLR_FSET(0,##FIELD,f)
  #define _I2C_I2CPDCLR1_FSET(FIELD,f) _I2C_I2CPDCLR_FSET(1,##FIELD,f)

  #define _I2C_I2CPDCLR0_FSETS(FIELD,SYM) _I2C_I2CPDCLR_FSETS(0,##FIELD,##SYM)
  #define _I2C_I2CPDCLR1_FSETS(FIELD,SYM) _I2C_I2CPDCLR_FSETS(1,##FIELD,##SYM)
#endif /* CHIP_6413 | CHIP_6418 | CHIP_6410 */

#endif /* I2C_SUPPORT */
#endif /* _CSL_I2CHAL_H_ */
/******************************************************************************\
* End of csl_i2chal.h
\******************************************************************************/
