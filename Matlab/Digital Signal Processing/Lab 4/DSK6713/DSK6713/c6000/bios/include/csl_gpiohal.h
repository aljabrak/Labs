/******************************************************************************\
*      Copyright (C) 2000-2001 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_gpiohal.h
* DATE CREATED.. 12/04/2000 
* LAST MODIFIED. 06/17/2003   - Added support for 6712C
*                06/09/2003   - Added support for 6711C
*                10/02/2001   - GPIO1 implementation
*                      
*------------------------------------------------------------------------------
* REGISTERS
*
* GPENx    - GPIO Enable register
* GPDIRx   - GPIO Direction register 
* GPVALx   - GPIO Value register 
* GPDHx   -  GPIO Delta High register 
* GPHMx    - GPIO High Mask register 
* GPDLx    - GPIO Delta Low register 
* GPLMx    - GPIO Low Mask register 
* GPGCx    - GPIO Global Control register 
* GPPOLx   - GPIO Interrupt Polarity register 
*
* with x = {0,1} 
\******************************************************************************/
#ifndef _CSL_GPIOHAL_H_
#define _CSL_GPIOHAL_H_

#include <csl_stdinchal.h>
#include <csl_chip.h>

#if (GPIO_SUPPORT)
/******************************************************************************\
*  MISC section 
\******************************************************************************/

#define _GPIO_BASE_ADDR    0x01B00000u 
#define _GPIO_BASE_ADDR0   0x01B00000u
#if (CHIP_DA610)
#define _GPIO_BASE_ADDR1   0x01B04000u
#endif

/******************************************************************************\
*  Module level register/field access macros
\******************************************************************************/

  /* -------------------------- */
  /*  FIELD MAKE MACROS */
  /* -------------------------- */

  #define GPIO_FMK(REG,FIELD,x)\
    _PER_FMK(GPIO,##REG,##FIELD,x)

  #define GPIO_FMKS(REG,FIELD,SYM)\
    _PER_FMKS(GPIO,##REG,##FIELD,##SYM)
 
 
  /* ----------------------------------------- */
  /*  RAW REGISTER/FIELD ACCESS MACROS */
  /* ----------------------------------------- */

  #define GPIO_ADDR(REG)\
    _GPIO_##REG##_ADDR

  #define GPIO_RGET(REG)\
    _PER_RGET(_GPIO_##REG##_ADDR,GPIO,##REG)

  #define GPIO_RSET(REG,x)\
    _PER_RSET(_GPIO_##REG##_ADDR,GPIO,##REG,x)

  #define GPIO_FGET(REG,FIELD)\
    _GPIO_##REG##_FGET(##FIELD)

  #define GPIO_FSET(REG,FIELD,x)\
    _GPIO_##REG##_FSET(##FIELD,##x)

  #define GPIO_FSETS(REG,FIELD,SYM)\
    _GPIO_##REG##_FSETS(##FIELD,##SYM)
 
 
  /* --------------------------------------------------- */
  /*  ADDRESS BASED REGISTER/FIELD ACCESS MACROS */
  /* --------------------------------------------------- */

  #define GPIO_RGETA(addr,REG)\
    _PER_RGET(addr,GPIO,##REG)

  #define GPIO_RSETA(addr,REG,x)\
    _PER_RSET(addr,GPIO,##REG,x)

  #define GPIO_FGETA(addr,REG,FIELD)\
    _PER_FGET(addr,GPIO,##REG,##FIELD)

  #define GPIO_FSETA(addr,REG,FIELD,x)\
    _PER_FSET(addr,GPIO,##REG,##FIELD,x)

  #define GPIO_FSETSA(addr,REG,FIELD,SYM)\
    _PER_FSETS(addr,GPIO,##REG,##FIELD,##SYM)

  /* -------------------------------------------------- */
  /*  HANDLE BASED REGISTER/FIELD ACCESS MACROS */
  /* -------------------------------------------------- */


  #define GPIO_ADDRH(h,REG)\
    (Uint32)(&((h)->baseAddr[_GPIO_##REG##_OFFSET]))

  #define GPIO_RGETH(h,REG)\
    GPIO_RGETA(GPIO_ADDRH(h,##REG),##REG)


  #define GPIO_RSETH(h,REG,x)\
    GPIO_RSETA(GPIO_ADDRH(h,##REG),##REG,x)


  #define GPIO_FGETH(h,REG,FIELD)\
    GPIO_FGETA(GPIO_ADDRH(h,##REG),##REG,##FIELD)


  #define GPIO_FSETH(h,REG,FIELD,x)\
    GPIO_FSETA(GPIO_ADDRH(h,##REG),##REG,##FIELD,x)


  #define GPIO_FSETSH(h,REG,FIELD,SYM)\
    GPIO_FSETSA(GPIO_ADDRH(h,##REG),##REG,##FIELD,##SYM)




/******************************************************************************\
* _____________________
* |                   |
* |     G P E N       |
* |___________________|
*
* GPEN  - GPIO Enable register
*
* FIELDS (msb -> lsb)
* (rw)  GPXEN  
*
\******************************************************************************/
  #define _GPIO_GPEN_OFFSET              0

  #define _GPIO_GPEN_ADDR                0x01B00000u

#if (CHIP_6711C || CHIP_6712C)
  #define _GPIO_GPEN_GPXEN_MASK          0x000000F4u
#else
  #define _GPIO_GPEN_GPXEN_MASK          0x0000FFFFu
#endif

  #define _GPIO_GPEN_GPXEN_SHIFT         0x00000000u

#if (CHIP_6713 || CHIP_DA610 || CHIP_6711C || CHIP_6712C)
  #define  GPIO_GPEN_GPXEN_DEFAULT       0x000000F0u
#else
  #define  GPIO_GPEN_GPXEN_DEFAULT       0x000000F9u
#endif

  #define  GPIO_GPEN_GPXEN_OF(x)         _VALUEOF(x)

  #define  GPIO_GPEN_OF(x)               _VALUEOF(x)

  #define GPIO_GPEN_DEFAULT (Uint32)( \
     _PER_FDEFAULT(GPIO,GPEN,GPXEN)\
  )

  #define GPIO_GPEN_RMK(gpxen) (Uint32)( \
     _PER_FMK(GPIO,GPEN,GPXEN,gpxen)\
  )

  #define _GPIO_GPEN_FGET(FIELD)\
    _PER_FGET(_GPIO_GPEN_ADDR,GPIO,GPEN,##FIELD)

  #define _GPIO_GPEN_FSET(FIELD,field)\
    _PER_FSET(_GPIO_GPEN_ADDR,GPIO,GPEN,##FIELD,field)

  #define _GPIO_GPEN_FSETS(FIELD,SYM)\
    _PER_FSETS(_GPIO_GPEN_ADDR,GPIO,GPEN,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |     G P D I R     |
* |___________________|
*
* GPDIR  - GPIO Direction register
*
* FIELDS (msb -> lsb)
* (rw)  GPXDIR  
*
\******************************************************************************/
  #define _GPIO_GPDIR_OFFSET               1

  #define _GPIO_GPDIR_ADDR                 0x01B00004u

#if (CHIP_6711C || CHIP_6712C)
  #define _GPIO_GPDIR_GPXDIR_MASK          0x000000F4u
#else
  #define _GPIO_GPDIR_GPXDIR_MASK          0x0000FFFFu
#endif
  
  #define _GPIO_GPDIR_GPXDIR_SHIFT         0x00000000u
  #define  GPIO_GPDIR_GPXDIR_DEFAULT       0x00000000u
  #define  GPIO_GPDIR_GPXDIR_OF(x)         _VALUEOF(x)

  #define  GPIO_GPDIR_OF(x)               _VALUEOF(x)

  #define GPIO_GPDIR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(GPIO,GPDIR,GPXDIR)\
  )

  #define GPIO_GPDIR_RMK(gpxdir) (Uint32)( \
     _PER_FMK(GPIO,GPDIR,GPXDIR,gpxdir)\
  )

  #define _GPIO_GPDIR_FGET(FIELD)\
    _PER_FGET(_GPIO_GPDIR_ADDR,GPIO,GPDIR,##FIELD)

  #define _GPIO_GPDIR_FSET(FIELD,field)\
    _PER_FSET(_GPIO_GPDIR_ADDR,GPIO,GPDIR,##FIELD,field)

  #define _GPIO_GPDIR_FSETS(FIELD,SYM)\
    _PER_FSETS(_GPIO_GPDIR_ADDR,GPIO,GPDIR,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |     G P V A L     |
* |___________________|
*
* GPVAL  - GPIO Value register
*
* FIELDS (msb -> lsb)
* (rw)  GPXVAL  
*
\******************************************************************************/
  #define _GPIO_GPVAL_OFFSET               2

  #define _GPIO_GPVAL_ADDR                 0x01B00008u

#if (CHIP_6711C || CHIP_6712C)
  #define _GPIO_GPVAL_GPXVAL_MASK          0x000000F4u
#else
  #define _GPIO_GPVAL_GPXVAL_MASK          0x0000FFFFu
#endif

  #define _GPIO_GPVAL_GPXVAL_SHIFT         0x00000000u
  #define  GPIO_GPVAL_GPXVAL_DEFAULT       0x00000000u
  #define  GPIO_GPVAL_GPXVAL_OF(x)         _VALUEOF(x)

  #define  GPIO_GPVAL_OF(x)               _VALUEOF(x)

  #define GPIO_GPVAL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(GPIO,GPVAL,GPXVAL)\
  )

  #define GPIO_GPVAL_RMK(gpxval) (Uint32)( \
     _PER_FMK(GPIO,GPVAL,GPXVAL,gpxval)\
  )

  #define _GPIO_GPVAL_FGET(FIELD)\
    _PER_FGET(_GPIO_GPVAL_ADDR,GPIO,GPVAL,##FIELD)

  #define _GPIO_GPVAL_FSET(FIELD,field)\
    _PER_FSET(_GPIO_GPVAL_ADDR,GPIO,GPVAL,##FIELD,field)

  #define _GPIO_GPVAL_FSETS(FIELD,SYM)\
    _PER_FSETS(_GPIO_GPVAL_ADDR,GPIO,GPVAL,##FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |     G P D H       |
* |___________________|
*
* GPDH  - GPIO Delta High register
*
* FIELDS (msb -> lsb)
* (rw)  GPXDH  
*
\******************************************************************************/
  #define _GPIO_GPDH_OFFSET              4

  #define _GPIO_GPDH_ADDR                0x01B00010u

#if (CHIP_6711C || CHIP_6712C)
  #define _GPIO_GPDH_GPXDH_MASK          0x000000F4u
#else
  #define _GPIO_GPDH_GPXDH_MASK          0x0000FFFFu
#endif

  #define _GPIO_GPDH_GPXDH_SHIFT         0x00000000u
  #define  GPIO_GPDH_GPXDH_DEFAULT       0x00000000u
  #define  GPIO_GPDH_GPXDH_OF(x)         _VALUEOF(x)

  #define  GPIO_GPDH_OF(x)               _VALUEOF(x)

  #define GPIO_GPDH_DEFAULT (Uint32)( \
     _PER_FDEFAULT(GPIO,GPDH,GPXDH)\
  )

  #define GPIO_GPDH_RMK(gpxdh) (Uint32)( \
     _PER_FMK(GPIO,GPDH,GPXDH,gpxdh)\
  )

  #define _GPIO_GPDH_FGET(FIELD)\
    _PER_FGET(_GPIO_GPDH_ADDR,GPIO,GPDH,##FIELD)

  #define _GPIO_GPDH_FSET(FIELD,field)\
    _PER_FSET(_GPIO_GPDH_ADDR,GPIO,GPDH,##FIELD,field)

  #define _GPIO_GPDH_FSETS(FIELD,SYM)\
    _PER_FSETS(_GPIO_GPDH_ADDR,GPIO,GPDH,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |     G P H M       |
* |___________________|
*
* GPHM  - GPIO High Mask register
*
* FIELDS (msb -> lsb)
* (rw)  GPXHM  
*
\******************************************************************************/
  #define _GPIO_GPHM_OFFSET              5

  #define _GPIO_GPHM_ADDR              0x01B00014u

#if (CHIP_6711C || CHIP_6712C)
  #define _GPIO_GPHM_GPXHM_MASK          0x000000F4u
#else
  #define _GPIO_GPHM_GPXHM_MASK          0x0000FFFFu
#endif

  #define _GPIO_GPHM_GPXHM_SHIFT         0x00000000u
  #define  GPIO_GPHM_GPXHM_DEFAULT       0x00000000u
  #define  GPIO_GPHM_GPXHM_OF(x)         _VALUEOF(x)

  #define  GPIO_GPHM_OF(x)               _VALUEOF(x)

  #define GPIO_GPHM_DEFAULT (Uint32)( \
     _PER_FDEFAULT(GPIO,GPHM,GPXHM)\
  )

  #define GPIO_GPHM_RMK(gpxhm) (Uint32)( \
     _PER_FMK(GPIO,GPHM,GPXHM,gpxhm)\
  )

  #define _GPIO_GPHM_FGET(FIELD)\
    _PER_FGET(_GPIO_GPHM_ADDR,GPIO,GPHM,##FIELD)

  #define _GPIO_GPHM_FSET(FIELD,field)\
    _PER_FSET(_GPIO_GPHM_ADDR,GPIO,GPHM,##FIELD,field)

  #define _GPIO_GPHM_FSETS(FIELD,SYM)\
    _PER_FSETS(_GPIO_GPHM_ADDR,GPIO,GPHM,##FIELD,##SYM)



/******************************************************************************\
* _____________________
* |                   |
* |     G P D L       |
* |___________________|
*
* GPDL  - GPIO Delta Low register
*
* FIELDS (msb -> lsb)
* (rw)  GPXDL  
*
\******************************************************************************/
  #define _GPIO_GPDL_OFFSET              6

  #define _GPIO_GPDL_ADDR                0x01B00018u

#if (CHIP_6711C || CHIP_6712C)
  #define _GPIO_GPDL_GPXDL_MASK          0x000000F4u
#else
  #define _GPIO_GPDL_GPXDL_MASK          0x0000FFFFu
#endif

  #define _GPIO_GPDL_GPXDL_SHIFT         0x00000000u
  #define  GPIO_GPDL_GPXDL_DEFAULT       0x00000000u
  #define  GPIO_GPDL_GPXDL_OF(x)         _VALUEOF(x)

  #define  GPIO_GPDL_OF(x)               _VALUEOF(x)

  #define GPIO_GPDL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(GPIO,GPDL,GPXDL)\
  )

  #define GPIO_GPDL_RMK(gpxdl) (Uint32)( \
     _PER_FMK(GPIO,GPDL,GPXDL,gpxdl)\
  )

  #define _GPIO_GPDL_FGET(FIELD)\
    _PER_FGET(_GPIO_GPDL_ADDR,GPIO,GPDL,##FIELD)

  #define _GPIO_GPDL_FSET(FIELD,field)\
    _PER_FSET(_GPIO_GPDL_ADDR,GPIO,GPDL,##FIELD,field)

  #define _GPIO_GPDL_FSETS(FIELD,SYM)\
    _PER_FSETS(_GPIO_GPDL_ADDR,GPIO,GPDL,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |     G P L M       |
* |___________________|
*
* GPLM  - GPIO Low Mask register
*
* FIELDS (msb -> lsb)
* (rw)  GPXLM  
*
\******************************************************************************/
  #define _GPIO_GPLM_OFFSET              7

  #define _GPIO_GPLM_ADDR                0x01B0001Cu

#if (CHIP_6711C || CHIP_6712C)
  #define _GPIO_GPLM_GPXLM_MASK          0x000000F4u
#else
  #define _GPIO_GPLM_GPXLM_MASK          0x0000FFFFu
#endif

  #define _GPIO_GPLM_GPXLM_SHIFT         0x00000000u
  #define  GPIO_GPLM_GPXLM_DEFAULT       0x00000000u
  #define  GPIO_GPLM_GPXLM_OF(x)         _VALUEOF(x)

  #define  GPIO_GPLM_OF(x)               _VALUEOF(x)

  #define GPIO_GPLM_DEFAULT (Uint32)( \
     _PER_FDEFAULT(GPIO,GPLM,GPXLM)\
  )

  #define GPIO_GPLM_RMK(gpxlm) (Uint32)( \
     _PER_FMK(GPIO,GPLM,GPXLM,gpxlm)\
  )

  #define _GPIO_GPLM_FGET(FIELD)\
    _PER_FGET(_GPIO_GPLM_ADDR,GPIO,GPLM,##FIELD)

  #define _GPIO_GPLM_FSET(FIELD,field)\
    _PER_FSET(_GPIO_GPLM_ADDR,GPIO,GPLM,##FIELD,field)

  #define _GPIO_GPLM_FSETS(FIELD,SYM)\
    _PER_FSETS(_GPIO_GPLM_ADDR,GPIO,GPLM,##FIELD,##SYM)



/******************************************************************************\
* _____________________
* |                   |
* |     G P G C       |
* |___________________|
*
* GPGC  - GPIO Global Control register
*
* FIELDS (msb -> lsb)
* (rw)  GP0M
* (rw)  GPINT0M
* (rw)  GPINTPOL
* (rw)  LOGIC
* (rw)  GPINTDV
*
\******************************************************************************/
  #define _GPIO_GPGC_OFFSET                8

  #define _GPIO_GPGC_ADDR                  0x01B00020u

  #define _GPIO_GPGC_GP0M_MASK             0x00000020u
  #define _GPIO_GPGC_GP0M_SHIFT            0x00000005u
  #define  GPIO_GPGC_GP0M_DEFAULT          0x00000000u
  #define  GPIO_GPGC_GP0M_OF(x)            _VALUEOF(x)
  #define  GPIO_GPGC_GP0M_GPIOMODE         0x00000000u
  #define  GPIO_GPGC_GP0M_LOGICMODE        0x00000001u
  
  #define _GPIO_GPGC_GPINT0M_MASK          0x00000010u
  #define _GPIO_GPGC_GPINT0M_SHIFT         0x00000004u
  #define  GPIO_GPGC_GPINT0M_DEFAULT       0x00000000u
  #define  GPIO_GPGC_GPINT0M_OF(x)         _VALUEOF(x)
  #define  GPIO_GPGC_GPINT0M_PASSMODE      0x00000000u
  #define  GPIO_GPGC_GPINT0M_LOGICMODE     0x00000001u

  #define _GPIO_GPGC_GPINTPOL_MASK         0x00000004u
  #define _GPIO_GPGC_GPINTPOL_SHIFT        0x00000002u
  #define  GPIO_GPGC_GPINTPOL_DEFAULT      0x00000000u
  #define  GPIO_GPGC_GPINTPOL_OF(x)        _VALUEOF(x)
  #define  GPIO_GPGC_GPINTPOL_LOGICTRUE    0x00000000u
  #define  GPIO_GPGC_GPINTPOL_LOGICFALSE   0x00000001u

  #define _GPIO_GPGC_LOGIC_MASK            0x00000002u
  #define _GPIO_GPGC_LOGIC_SHIFT           0x00000001u
  #define  GPIO_GPGC_LOGIC_DEFAULT         0x00000000u
  #define  GPIO_GPGC_LOGIC_OF(x)           _VALUEOF(x)
  #define  GPIO_GPGC_LOGIC_ORMODE          0x00000000u
  #define  GPIO_GPGC_LOGIC_ANDMODE         0x00000001u

  #define _GPIO_GPGC_GPINTDV_MASK          0x00000001u
  #define _GPIO_GPGC_GPINTDV_SHIFT         0x00000000u
  #define  GPIO_GPGC_GPINTDV_DEFAULT       0x00000000u
  #define  GPIO_GPGC_GPINTDV_OF(x)         _VALUEOF(x)
  #define  GPIO_GPGC_GPINTDV_DELTAMODE     0x00000000u
  #define  GPIO_GPGC_GPINTDV_VALUEMODE     0x00000001u

  #define  GPIO_GPGC_OF(x)                 _VALUEOF(x)

  #define GPIO_GPGC_DEFAULT (Uint32)( \
     _PER_FDEFAULT(GPIO,GPGC,GP0M)\
    |_PER_FDEFAULT(GPIO,GPGC,GPINT0M)\
    |_PER_FDEFAULT(GPIO,GPGC,GPINTPOL)\
    |_PER_FDEFAULT(GPIO,GPGC,LOGIC)\
    |_PER_FDEFAULT(GPIO,GPGC,GPINTDV)\
  )

  #define GPIO_GPGC_RMK(gp0m,gpint0m,gpintpol,logic,gpintdv) (Uint32)( \
     _PER_FMK(GPIO,GPGC,GP0M,gp0m)\
    |_PER_FMK(GPIO,GPGC,GPINT0M,gpint0m)\
    |_PER_FMK(GPIO,GPGC,GPINTPOL,gpintpol)\
    |_PER_FMK(GPIO,GPGC,LOGIC,logic)\
    |_PER_FMK(GPIO,GPGC,GPINTDV,gpintdv)\
  )

  #define _GPIO_GPGC_FGET(FIELD)\
    _PER_FGET(_GPIO_GPGC_ADDR,GPIO,GPGC,##FIELD)

  #define _GPIO_GPGC_FSET(FIELD,field)\
    _PER_FSET(_GPIO_GPGC_ADDR,GPIO,GPGC,##FIELD,field)

  #define _GPIO_GPGC_FSETS(FIELD,SYM)\
    _PER_FSETS(_GPIO_GPGC_ADDR,GPIO,GPGC,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |     G P P O L     |
* |___________________|
*
* GPPOL  - GPIO Interrupt Polarity register
*
* FIELDS (msb -> lsb)
* (rw)  GPINTXPOL  
*
\******************************************************************************/
  #define _GPIO_GPPOL_OFFSET                  9

  #define _GPIO_GPPOL_ADDR                    0x01B00024u

  #define _GPIO_GPPOL_GPINTXPOL_MASK          0x000000F9u
  #define _GPIO_GPPOL_GPINTXPOL_SHIFT         0x00000000u
  #define  GPIO_GPPOL_GPINTXPOL_DEFAULT       0x00000000u
  #define  GPIO_GPPOL_GPINTXPOL_OF(x)         _VALUEOF(x)

  #define  GPIO_GPPOL_OF(x)                   _VALUEOF(x)
  
  #define GPIO_GPPOL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(GPIO,GPPOL,GPINTXPOL)\
  )

  #define GPIO_GPPOL_RMK(gpintxpol) (Uint32)( \
     _PER_FMK(GPIO,GPPOL,GPINTXPOL,gpintxpol)\
  )

  #define _GPIO_GPPOL_FGET(FIELD)\
    _PER_FGET(_GPIO_GPPOL_ADDR,GPIO,GPPOL,##FIELD)  /* bug fixed pn 10/02/2001 */

  #define _GPIO_GPPOL_FSET(FIELD,field)\
    _PER_FSET(_GPIO_GPPOL_ADDR,GPIO,GPPOL,##FIELD,field)

  #define _GPIO_GPPOL_FSETS(FIELD,SYM)\
    _PER_FSETS(_GPIO_GPPOL_ADDR,GPIO,GPPOL,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |     G P E N       |
* |___________________|
*
* GPEN0  - GPIO0 Enable register
* GPEN1  - GPIO1 Enable register
*
* FIELDS (msb -> lsb)
* (rw)  GPXEN  
*
\******************************************************************************/
  #define _GPIO_GPEN0_OFFSET              0
#if (CHIP_DA610)
  #define _GPIO_GPEN1_OFFSET              0
#endif

  #define _GPIO_GPEN0_ADDR               0x01B00000u
#if (CHIP_DA610)
  #define _GPIO_GPEN1_ADDR               0x01B04000u
#endif

#if (CHIP_6711C || CHIP_6712C)
  #define _GPIO_GPEN_GPXEN_MASK          0x000000F4u
#else
  #define _GPIO_GPEN_GPXEN_MASK          0x0000FFFFu
#endif

  #define _GPIO_GPEN_GPXEN_SHIFT         0x00000000u

#if (CHIP_6713 || CHIP_DA610 || CHIP_6711C || CHIP_6712C)
  #define  GPIO_GPEN_GPXEN_DEFAULT       0x000000F0u
#else
  #define  GPIO_GPEN_GPXEN_DEFAULT       0x000000F9u
#endif

  #define  GPIO_GPEN_GPXEN_OF(x)         _VALUEOF(x)

  #define  GPIO_GPEN_OF(x)               _VALUEOF(x)

  #define GPIO_GPEN_DEFAULT (Uint32)( \
     _PER_FDEFAULT(GPIO,GPEN,GPXEN)\
  )

  #define GPIO_GPEN_RMK(gpxen) (Uint32)( \
     _PER_FMK(GPIO,GPEN,GPXEN,gpxen)\
  )

  #define _GPIO_GPEN0_FGET(FIELD)\
    _PER_FGET(_GPIO_GPEN0_ADDR,GPIO,GPEN,##FIELD)

#if (CHIP_DA610)
  #define _GPIO_GPEN1_FGET(FIELD)\
    _PER_FGET(_GPIO_GPEN1_ADDR,GPIO,GPEN,##FIELD)
#endif

  #define _GPIO_GPEN0_FSET(FIELD,field)\
    _PER_FSET(_GPIO_GPEN0_ADDR,GPIO,GPEN,##FIELD,field)

#if (CHIP_DA610)
  #define _GPIO_GPEN1_FSET(FIELD,field)\
    _PER_FSET(_GPIO_GPEN1_ADDR,GPIO,GPEN,##FIELD,field)
#endif

  #define _GPIO_GPEN0_FSETS(FIELD,SYM)\
    _PER_FSETS(_GPIO_GPEN0_ADDR,GPIO,GPEN,##FIELD,##SYM)

#if (CHIP_DA610)
  #define _GPIO_GPEN1_FSETS(FIELD,SYM)\
    _PER_FSETS(_GPIO_GPEN1_ADDR,GPIO,GPEN,##FIELD,##SYM)
#endif


/******************************************************************************\
* _____________________
* |                   |
* |     G P D I R     |
* |___________________|
*
* GPDIR0  - GPIO0 Direction register
* GPDIR1  - GPIO1 Direction register
* FIELDS (msb -> lsb)
* (rw)  GPXDIR  
*
\******************************************************************************/
  #define _GPIO_GPDIR0_OFFSET               1
#if (CHIP_DA610)
  #define _GPIO_GPDIR1_OFFSET               1
#endif

  #define _GPIO_GPDIR0_ADDR                 0x01B00004u
#if (CHIP_DA610)
  #define _GPIO_GPDIR1_ADDR                 0x01B04004u
#endif

#if (CHIP_6711C || CHIP_6712C)
  #define _GPIO_GPDIR_GPXDIR_MASK          0x000000F4u
#else
  #define _GPIO_GPDIR_GPXDIR_MASK          0x0000FFFFu
#endif

  #define _GPIO_GPDIR_GPXDIR_SHIFT         0x00000000u
  #define  GPIO_GPDIR_GPXDIR_DEFAULT       0x00000000u
  #define  GPIO_GPDIR_GPXDIR_OF(x)         _VALUEOF(x)

  #define  GPIO_GPDIR_OF(x)               _VALUEOF(x)

  #define GPIO_GPDIR_DEFAULT (Uint32)( \
     _PER_FDEFAULT(GPIO,GPDIR,GPXDIR)\
  )

  #define GPIO_GPDIR_RMK(gpxdir) (Uint32)( \
     _PER_FMK(GPIO,GPDIR,GPXDIR,gpxdir)\
  )


  #define _GPIO_GPDIR0_FGET(FIELD)\
    _PER_FGET(_GPIO_GPDIR0_ADDR,GPIO,GPDIR,##FIELD)

#if (CHIP_DA610)
  #define _GPIO_GPDIR1_FGET(FIELD)\
    _PER_FGET(_GPIO_GPDIR1_ADDR,GPIO,GPDIR,##FIELD)
#endif

  #define _GPIO_GPDIR0_FSET(FIELD,field)\
    _PER_FSET(_GPIO_GPDIR0_ADDR,GPIO,GPDIR,##FIELD,field)

#if (CHIP_DA610)
  #define _GPIO_GPDIR1_FSET(FIELD,field)\
    _PER_FSET(_GPIO_GPDIR1_ADDR,GPIO,GPDIR,##FIELD,field)
#endif


  #define _GPIO_GPDIR0_FSETS(FIELD,SYM)\
    _PER_FSETS(_GPIO_GPDIR0_ADDR,GPIO,GPDIR,##FIELD,##SYM)
#if (CHIP_DA610)
  #define _GPIO_GPDIR1_FSETS(FIELD,SYM)\
    _PER_FSETS(_GPIO_GPDIR1_ADDR,GPIO,GPDIR,##FIELD,##SYM)
#endif

/******************************************************************************\
* _____________________
* |                   |
* |     G P V A L     |
* |___________________|
*
* GPVAL0  - GPIO0 Value register
* GPVAL1  - GPIO1 Value register
* FIELDS (msb -> lsb)
* (rw)  GPXVAL  
*
\******************************************************************************/
  #define _GPIO_GPVAL0_OFFSET               2
#if (CHIP_DA610)
  #define _GPIO_GPVAL1_OFFSET               2
#endif

  #define _GPIO_GPVAL0_ADDR                 0x01B00008u
#if (CHIP_DA610)
  #define _GPIO_GPVAL1_ADDR                 0x01B04008u
#endif

#if (CHIP_6711C || CHIP_6712C)
  #define _GPIO_GPVAL_GPXVAL_MASK          0x000000F4u
#else
  #define _GPIO_GPVAL_GPXVAL_MASK          0x0000FFFFu
#endif

  #define _GPIO_GPVAL_GPXVAL_SHIFT         0x00000000u
  #define  GPIO_GPVAL_GPXVAL_DEFAULT       0x00000000u
  #define  GPIO_GPVAL_GPXVAL_OF(x)         _VALUEOF(x)

  #define  GPIO_GPVAL_OF(x)               _VALUEOF(x)

  #define GPIO_GPVAL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(GPIO,GPVAL,GPXVAL)\
  )

  #define GPIO_GPVAL_RMK(gpxval) (Uint32)( \
     _PER_FMK(GPIO,GPVAL,GPXVAL,gpxval)\
  )

  #define _GPIO_GPVAL0_FGET(FIELD)\
    _PER_FGET(_GPIO_GPVAL0_ADDR,GPIO,GPVAL,##FIELD)
#if (CHIP_DA610)
  #define _GPIO_GPVAL1_FGET(FIELD)\
    _PER_FGET(_GPIO_GPVAL1_ADDR,GPIO,GPVAL,##FIELD)
#endif

  #define _GPIO_GPVAL0_FSET(FIELD,field)\
    _PER_FSET(_GPIO_GPVAL0_ADDR,GPIO,GPVAL,##FIELD,field)
#if (CHIP_DA610)
  #define _GPIO_GPVAL1_FSET(FIELD,field)\
    _PER_FSET(_GPIO_GPVAL1_ADDR,GPIO,GPVAL,##FIELD,field)
#endif

  #define _GPIO_GPVAL0_FSETS(FIELD,SYM)\
    _PER_FSETS(_GPIO_GPVAL0_ADDR,GPIO,GPVAL,##FIELD,##SYM)
#if (CHIP_DA610)
  #define _GPIO_GPVAL1_FSETS(FIELD,SYM)\
    _PER_FSETS(_GPIO_GPVAL1_ADDR,GPIO,GPVAL,##FIELD,##SYM)
#endif

/******************************************************************************\
* _____________________
* |                   |
* |     G P D H       |
* |___________________|
*
* GPDH0  - GPIO0 Delta High register
* GPDH1  - GPIO1 Delta High register
* FIELDS (msb -> lsb)
* (rw)  GPXDH  
*
\******************************************************************************/
  #define _GPIO_GPDH0_OFFSET              4
#if (CHIP_DA610)
  #define _GPIO_GPDH1_OFFSET              4
#endif

  #define _GPIO_GPDH0_ADDR                0x01B04010u
#if (CHIP_DA610)
  #define _GPIO_GPDH1_ADDR                0x01B04010u
#endif

#if (CHIP_6711C || CHIP_6712C)
  #define _GPIO_GPDH_GPXDH_MASK          0x000000F4u
#else
  #define _GPIO_GPDH_GPXDH_MASK          0x0000FFFFu
#endif

  #define _GPIO_GPDH_GPXDH_SHIFT         0x00000000u
  #define  GPIO_GPDH_GPXDH_DEFAULT       0x00000000u
  #define  GPIO_GPDH_GPXDH_OF(x)         _VALUEOF(x)

  #define  GPIO_GPDH_OF(x)               _VALUEOF(x)

  #define GPIO_GPDH_DEFAULT (Uint32)( \
     _PER_FDEFAULT(GPIO,GPDH,GPXDH)\
  )

  #define GPIO_GPDH_RMK(gpxdh) (Uint32)( \
     _PER_FMK(GPIO,GPDH,GPXDH,gpxdh)\
  )

  #define _GPIO_GPDH0_FGET(FIELD)\
    _PER_FGET(_GPIO_GPDH0_ADDR,GPIO,GPDH,##FIELD)
#if (CHIP_DA610)
  #define _GPIO_GPDH1_FGET(FIELD)\
    _PER_FGET(_GPIO_GPDH1_ADDR,GPIO,GPDH,##FIELD)
#endif

  #define _GPIO_GPDH0_FSET(FIELD,field)\
    _PER_FSET(_GPIO_GPDH0_ADDR,GPIO,GPDH,##FIELD,field)
#if (CHIP_DA610)
  #define _GPIO_GPDH1_FSET(FIELD,field)\
    _PER_FSET(_GPIO_GPDH1_ADDR,GPIO,GPDH,##FIELD,field)
#endif


  #define _GPIO_GPDH0_FSETS(FIELD,SYM)\
    _PER_FSETS(_GPIO_GPDH0_ADDR,GPIO,GPDH,##FIELD,##SYM)
#if (CHIP_DA610)
  #define _GPIO_GPDH1_FSETS(FIELD,SYM)\
    _PER_FSETS(_GPIO_GPDH1_ADDR,GPIO,GPDH,##FIELD,##SYM)
#endif

/******************************************************************************\
* _____________________
* |                   |
* |     G P H M       |
* |___________________|
*
* GPHM0  - GPIO0 High Mask register
* GPHM1  - GPIO1 High Mask register
* FIELDS (msb -> lsb)
* (rw)  GPXHM  
*
\******************************************************************************/
  #define _GPIO_GPHM0_OFFSET              5
#if (CHIP_DA610)
  #define _GPIO_GPHM1_OFFSET              5
#endif
 
  #define _GPIO_GPHM0_ADDR              0x01B00014u
#if (CHIP_DA610)
  #define _GPIO_GPHM1_ADDR              0x01B04014u
#endif

#if (CHIP_6711C || CHIP_6712C)
  #define _GPIO_GPHM_GPXHM_MASK          0x000000F4u
#else
  #define _GPIO_GPHM_GPXHM_MASK          0x0000FFFFu
#endif

  #define _GPIO_GPHM_GPXHM_SHIFT         0x00000000u
  #define  GPIO_GPHM_GPXHM_DEFAULT       0x00000000u
  #define  GPIO_GPHM_GPXHM_OF(x)         _VALUEOF(x)

  #define  GPIO_GPHM_OF(x)               _VALUEOF(x)

  #define GPIO_GPHM_DEFAULT (Uint32)( \
     _PER_FDEFAULT(GPIO,GPHM,GPXHM)\
  )

  #define GPIO_GPHM_RMK(gpxhm) (Uint32)( \
     _PER_FMK(GPIO,GPHM,GPXHM,gpxhm)\
  )

  #define _GPIO_GPHM0_FGET(FIELD)\
    _PER_FGET(_GPIO_GPHM0_ADDR,GPIO,GPHM,##FIELD)
#if (CHIP_DA610)
  #define _GPIO_GPHM1_FGET(FIELD)\
    _PER_FGET(_GPIO_GPHM1_ADDR,GPIO,GPHM,##FIELD)
#endif

  #define _GPIO_GPHM0_FSET(FIELD,field)\
    _PER_FSET(_GPIO_GPHM0_ADDR,GPIO,GPHM,##FIELD,field)
#if (CHIP_DA610)
  #define _GPIO_GPHM1_FSET(FIELD,field)\
    _PER_FSET(_GPIO_GPHM1_ADDR,GPIO,GPHM,##FIELD,field)
#endif

  #define _GPIO_GPHM0_FSETS(FIELD,SYM)\
    _PER_FSETS(_GPIO_GPHM0_ADDR,GPIO,GPHM,##FIELD,##SYM)
#if (CHIP_DA610)
 #define _GPIO_GPHM1_FSETS(FIELD,SYM)\
    _PER_FSETS(_GPIO_GPHM1_ADDR,GPIO,GPHM,##FIELD,##SYM)
#endif

/******************************************************************************\
* _____________________
* |                   |
* |     G P D L       |
* |___________________|
*
* GPDL0  - GPIO0 Delta Low register
* GPDL1  - GPIO1 Delta Low register
* FIELDS (msb -> lsb)
* (rw)  GPXDL  
*
\******************************************************************************/
  #define _GPIO_GPDL0_OFFSET              6
#if (CHIP_DA610)
  #define _GPIO_GPDL1_OFFSET              6
#endif
  
  #define _GPIO_GPDL0_ADDR                0x01B00018u
#if (CHIP_DA610)
  #define _GPIO_GPDL1_ADDR                0x01B04018u
#endif

#if (CHIP_6711C || CHIP_6712C)
  #define _GPIO_GPDL_GPXDL_MASK          0x000000F4u
#else
  #define _GPIO_GPDL_GPXDL_MASK          0x0000FFFFu
#endif

  #define _GPIO_GPDL_GPXDL_SHIFT         0x00000000u
  #define  GPIO_GPDL_GPXDL_DEFAULT       0x00000000u
  #define  GPIO_GPDL_GPXDL_OF(x)         _VALUEOF(x)

  #define  GPIO_GPDL_OF(x)               _VALUEOF(x)

  #define GPIO_GPDL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(GPIO,GPDL,GPXDL)\
  )

  #define GPIO_GPDL_RMK(gpxdl) (Uint32)( \
     _PER_FMK(GPIO,GPDL,GPXDL,gpxdl)\
  )

  #define _GPIO_GPDL0_FGET(FIELD)\
    _PER_FGET(_GPIO_GPDL0_ADDR,GPIO,GPDL,##FIELD)
#if (CHIP_DA610)
  #define _GPIO_GPDL1_FGET(FIELD)\
    _PER_FGET(_GPIO_GPDL1_ADDR,GPIO,GPDL,##FIELD)
#endif

  #define _GPIO_GPDL0_FSET(FIELD,field)\
    _PER_FSET(_GPIO_GPDL0_ADDR,GPIO,GPDL,##FIELD,field)
#if (CHIP_DA610)
  #define _GPIO_GPDL1_FSET(FIELD,field)\
    _PER_FSET(_GPIO_GPDL1_ADDR,GPIO,GPDL,##FIELD,field)
#endif

  #define _GPIO_GPDL0_FSETS(FIELD,SYM)\
    _PER_FSETS(_GPIO_GPDL0_ADDR,GPIO,GPDL,##FIELD,##SYM)
#if (CHIP_DA610)
  #define _GPIO_GPDL1_FSETS(FIELD,SYM)\
    _PER_FSETS(_GPIO_GPDL1_ADDR,GPIO,GPDL,##FIELD,##SYM)
#endif

/******************************************************************************\
* _____________________
* |                   |
* |     G P L M       |
* |___________________|
*
* GPLM0  - GPIO0 Low Mask register
* GPLM1  - GPIO1 Low Mask register
* FIELDS (msb -> lsb)
* (rw)  GPXLM  
*
\******************************************************************************/
  #define _GPIO_GPLM0_OFFSET             7
#if (CHIP_DA610)
  #define _GPIO_GPLM1_OFFSET             7
#endif

  #define _GPIO_GPLM0_ADDR               0x01B0001Cu
#if (CHIP_DA610)
  #define _GPIO_GPLM1_ADDR               0x01B0401Cu
#endif

#if (CHIP_6711C || CHIP_6712C)
  #define _GPIO_GPLM_GPXLM_MASK          0x000000F4u
#else
  #define _GPIO_GPLM_GPXLM_MASK          0x0000FFFFu
#endif

  #define _GPIO_GPLM_GPXLM_SHIFT         0x00000000u
  #define  GPIO_GPLM_GPXLM_DEFAULT       0x00000000u
  #define  GPIO_GPLM_GPXLM_OF(x)         _VALUEOF(x)

  #define  GPIO_GPLM_OF(x)               _VALUEOF(x)

  #define GPIO_GPLM_DEFAULT (Uint32)( \
     _PER_FDEFAULT(GPIO,GPLM,GPXLM)\
  )

  #define GPIO_GPLM_RMK(gpxlm) (Uint32)( \
     _PER_FMK(GPIO,GPLM,GPXLM,gpxlm)\
  )

  #define _GPIO_GPLM0_FGET(FIELD)\
    _PER_FGET(_GPIO_GPLM0_ADDR,GPIO,GPLM,##FIELD)
#if (CHIP_DA610)
  #define _GPIO_GPLM1_FGET(FIELD)\
    _PER_FGET(_GPIO_GPLM1_ADDR,GPIO,GPLM,##FIELD)
#endif


  #define _GPIO_GPLM0_FSET(FIELD,field)\
    _PER_FSET(_GPIO_GPLM0_ADDR,GPIO,GPLM,##FIELD,field)
#if (CHIP_DA610)
  #define _GPIO_GPLM1_FSET(FIELD,field)\
    _PER_FSET(_GPIO_GPLM1_ADDR,GPIO,GPLM,##FIELD,field)
#endif

  #define _GPIO_GPLM0_FSETS(FIELD,SYM)\
    _PER_FSETS(_GPIO_GPLM0_ADDR,GPIO,GPLM,##FIELD,##SYM)
#if (CHIP_DA610)
 #define _GPIO_GPLM1_FSETS(FIELD,SYM)\
    _PER_FSETS(_GPIO_GPLM1_ADDR,GPIO,GPLM,##FIELD,##SYM)
#endif

/******************************************************************************\
* _____________________
* |                   |
* |     G P G C       |
* |___________________|
*
* GPGC0  - GPIO Global Control register
* GPGC1  - GPIO Global Control register
* FIELDS (msb -> lsb)
* (rw)  GP0M
* (rw)  GPINT0M
* (rw)  GPINTPOL
* (rw)  LOGIC
* (rw)  GPINTDV
*
\******************************************************************************/
  #define _GPIO_GPGC0_OFFSET               8
#if (CHIP_DA610)
  #define _GPIO_GPGC1_OFFSET               8
#endif

  #define _GPIO_GPGC0_ADDR                 0x01B00020u
#if (CHIP_DA610)
  #define _GPIO_GPGC1_ADDR                 0x01B04020u
#endif

  #define _GPIO_GPGC_GP0M_MASK             0x00000020u
  #define _GPIO_GPGC_GP0M_SHIFT            0x00000005u
  #define  GPIO_GPGC_GP0M_DEFAULT          0x00000000u
  #define  GPIO_GPGC_GP0M_OF(x)            _VALUEOF(x)
  #define  GPIO_GPGC_GP0M_GPIOMODE         0x00000000u
  #define  GPIO_GPGC_GP0M_LOGICMODE        0x00000001u
  
  #define _GPIO_GPGC_GPINT0M_MASK          0x00000010u
  #define _GPIO_GPGC_GPINT0M_SHIFT         0x00000004u
  #define  GPIO_GPGC_GPINT0M_DEFAULT       0x00000000u
  #define  GPIO_GPGC_GPINT0M_OF(x)         _VALUEOF(x)
  #define  GPIO_GPGC_GPINT0M_PASSMODE      0x00000000u
  #define  GPIO_GPGC_GPINT0M_LOGICMODE     0x00000001u

  #define _GPIO_GPGC_GPINTPOL_MASK         0x00000004u
  #define _GPIO_GPGC_GPINTPOL_SHIFT        0x00000002u
  #define  GPIO_GPGC_GPINTPOL_DEFAULT      0x00000000u
  #define  GPIO_GPGC_GPINTPOL_OF(x)        _VALUEOF(x)
  #define  GPIO_GPGC_GPINTPOL_LOGICTRUE    0x00000000u
  #define  GPIO_GPGC_GPINTPOL_LOGICFALSE   0x00000001u

  #define _GPIO_GPGC_LOGIC_MASK            0x00000002u
  #define _GPIO_GPGC_LOGIC_SHIFT           0x00000001u
  #define  GPIO_GPGC_LOGIC_DEFAULT         0x00000000u
  #define  GPIO_GPGC_LOGIC_OF(x)           _VALUEOF(x)
  #define  GPIO_GPGC_LOGIC_ORMODE          0x00000000u
  #define  GPIO_GPGC_LOGIC_ANDMODE         0x00000001u

  #define _GPIO_GPGC_GPINTDV_MASK          0x00000001u
  #define _GPIO_GPGC_GPINTDV_SHIFT         0x00000000u
  #define  GPIO_GPGC_GPINTDV_DEFAULT       0x00000000u
  #define  GPIO_GPGC_GPINTDV_OF(x)         _VALUEOF(x)
  #define  GPIO_GPGC_GPINTDV_DELTAMODE     0x00000000u
  #define  GPIO_GPGC_GPINTDV_VALUEMODE     0x00000001u

  #define  GPIO_GPGC_OF(x)                 _VALUEOF(x)

  #define GPIO_GPGC_DEFAULT (Uint32)( \
     _PER_FDEFAULT(GPIO,GPGC,GP0M)\
    |_PER_FDEFAULT(GPIO,GPGC,GPINT0M)\
    |_PER_FDEFAULT(GPIO,GPGC,GPINTPOL)\
    |_PER_FDEFAULT(GPIO,GPGC,LOGIC)\
    |_PER_FDEFAULT(GPIO,GPGC,GPINTDV)\
  )

  #define GPIO_GPGC_RMK(gp0m,gpint0m,gpintpol,logic,gpintdv) (Uint32)( \
     _PER_FMK(GPIO,GPGC,GP0M,gp0m)\
    |_PER_FMK(GPIO,GPGC,GPINT0M,gpint0m)\
    |_PER_FMK(GPIO,GPGC,GPINTPOL,gpintpol)\
    |_PER_FMK(GPIO,GPGC,LOGIC,logic)\
    |_PER_FMK(GPIO,GPGC,GPINTDV,gpintdv)\
  )

  #define _GPIO_GPGC0_FGET(FIELD)\
    _PER_FGET(_GPIO_GPGC0_ADDR,GPIO,GPGC,##FIELD)
#if (CHIP_DA610)
  #define _GPIO_GPGC1_FGET(FIELD)\
    _PER_FGET(_GPIO_GPGC1_ADDR,GPIO,GPGC,##FIELD)
#endif

  #define _GPIO_GPGC0_FSET(FIELD,field)\
    _PER_FSET(_GPIO_GPGC0_ADDR,GPIO,GPGC,##FIELD,field)
#if (CHIP_DA610)
  #define _GPIO_GPGC1_FSET(FIELD,field)\
    _PER_FSET(_GPIO_GPGC1_ADDR,GPIO,GPGC,##FIELD,field)
#endif

  #define _GPIO_GPGC0_FSETS(FIELD,SYM)\
    _PER_FSETS(_GPIO_GPGC0_ADDR,GPIO,GPGC,##FIELD,##SYM)
#if (CHIP_DA610)
 #define _GPIO_GPGC1_FSETS(FIELD,SYM)\
    _PER_FSETS(_GPIO_GPGC1_ADDR,GPIO,GPGC,##FIELD,##SYM)
#endif
/******************************************************************************\
* _____________________
* |                   |
* |     G P P O L     |
* |___________________|
*
* GPPOL0  - GPIO0 Interrupt Polarity register
* GPPOL1  - GPIO1 Interrupt Polarity register
* FIELDS (msb -> lsb)
* (rw)  GPINTXPOL  
*
\******************************************************************************/
  #define _GPIO_GPPOL0_OFFSET                  9
#if (CHIP_DA610)
  #define _GPIO_GPPOL1_OFFSET                  9
#endif

  #define _GPIO_GPPOL0_ADDR                    0x01B00024u
#if (CHIP_DA610)
  #define _GPIO_GPPOL1_ADDR                    0x01B04024u
#endif

  #define _GPIO_GPPOL_GPINTXPOL_MASK          0x000000F9u
  #define _GPIO_GPPOL_GPINTXPOL_SHIFT         0x00000000u
  #define  GPIO_GPPOL_GPINTXPOL_DEFAULT       0x00000000u
  #define  GPIO_GPPOL_GPINTXPOL_OF(x)         _VALUEOF(x)

  #define  GPIO_GPPOL_OF(x)                   _VALUEOF(x)
  
  #define GPIO_GPPOL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(GPIO,GPPOL,GPINTXPOL)\
  )

  #define GPIO_GPPOL_RMK(gpintxpol) (Uint32)( \
     _PER_FMK(GPIO,GPPOL,GPINTXPOL,gpintxpol)\
  )
  #define _GPIO_GPPOL0_FGET(FIELD)\
    _PER_FGET(_GPIO_GPPOL0_ADDR,GPIO,GPPOL,##FIELD)  
#if (CHIP_DA610)
  #define _GPIO_GPPOL1_FGET(FIELD)\
    _PER_FGET(_GPIO_GPPOL1_ADDR,GPIO,GPPOL,##FIELD)  
#endif

  #define _GPIO_GPPOL0_FSET(FIELD,field)\
    _PER_FSET(_GPIO_GPPOL0_ADDR,GPIO,GPPOL,##FIELD,field)
#if (CHIP_DA610)
  #define _GPIO_GPPOL1_FSET(FIELD,field)\
    _PER_FSET(_GPIO_GPPOL1_ADDR,GPIO,GPPOL,##FIELD,field)
#endif

  #define _GPIO_GPPOL0_FSETS(FIELD,SYM)\
    _PER_FSETS(_GPIO_GPPOL0_ADDR,GPIO,GPPOL,##FIELD,##SYM)
#if (CHIP_DA610)
  #define _GPIO_GPPOL1_FSETS(FIELD,SYM)\
    _PER_FSETS(_GPIO_GPPOL1_ADDR,GPIO,GPPOL,##FIELD,##SYM)
#endif

/*----------------------------------------------------------------------------*/


#endif /* GPIO_SUPPORT */
#endif /* _CSL_GPIOHAL_H_ */
/******************************************************************************\
* End of csl_gpiohal.h
\******************************************************************************/







