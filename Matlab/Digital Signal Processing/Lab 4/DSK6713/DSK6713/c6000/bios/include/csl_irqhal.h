/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_irqhal.h
* DATE CREATED.. 06/20/1999 
* LAST MODIFIED. 10/03/2000
*------------------------------------------------------------------------------
* REGISTERS
*
* MUXH   - interrupt multiplexer high register
* MUXL   - interrupt multiplexer low register
* EXTPOL - external interrupt polarity register
*
\******************************************************************************/
#ifndef _CSL_IRQHAL_H_
#define _CSL_IRQHAL_H_

#include <csl_stdinchal.h>
#include <csl_chip.h>

#if (IRQ_SUPPORT)
/******************************************************************************\
* MISC section
\******************************************************************************/


/******************************************************************************\
* module level register/field access macros
\******************************************************************************/

  /* ----------------- */
  /* FIELD MAKE MACROS */
  /* ----------------- */

  #define IRQ_FMK(REG,FIELD,x)\
    _PER_FMK(IRQ,##REG,##FIELD,x)

  #define IRQ_FMKS(REG,FIELD,SYM)\
    _PER_FMKS(IRQ,##REG,##FIELD,##SYM)
 
 
  /* -------------------------------- */
  /* RAW REGISTER/FIELD ACCESS MACROS */
  /* -------------------------------- */

  #define IRQ_ADDR(REG)\
    _IRQ_##REG##_ADDR

  #define IRQ_RGET(REG)\
    _PER_RGET(_IRQ_##REG##_ADDR,IRQ,##REG)

  #define IRQ_RSET(REG,x)\
    _PER_RSET(_IRQ_##REG##_ADDR,IRQ,##REG,x)

  #define IRQ_FGET(REG,FIELD)\
    _IRQ_##REG##_FGET(##FIELD)

  #define IRQ_FSET(REG,FIELD,x)\
    _IRQ_##REG##_FSET(##FIELD,##x)

  #define IRQ_FSETS(REG,FIELD,SYM)\
    _IRQ_##REG##_FSETS(##FIELD,##SYM)
 
 
  /* ------------------------------------------ */
  /* ADDRESS BASED REGISTER/FIELD ACCESS MACROS */
  /* ------------------------------------------ */

  #define IRQ_RGETA(addr,REG)\
    _PER_RGET(addr,IRQ,##REG)

  #define IRQ_RSETA(addr,REG,x)\
    _PER_RSET(addr,IRQ,##REG,x)

  #define IRQ_FGETA(addr,REG,FIELD)\
    _PER_FGET(addr,IRQ,##REG,##FIELD)

  #define IRQ_FSETA(addr,REG,FIELD,x)\
    _PER_FSET(addr,IRQ,##REG,##FIELD,x)

  #define IRQ_FSETSA(addr,REG,FIELD,SYM)\
    _PER_FSETS(addr,IRQ,##REG,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  M U X H          |
* |___________________|
*
* MUXH - interrupt multiplexer high register
*
* FIELDS (msb -> lsb)
* (rw) INTSEL15
* (rw) INTSEL14
* (rw) INTSEL13
* (rw) INTSEL12
* (rw) INTSEL11
* (rw) INTSEL10
*
\******************************************************************************/
  #define _IRQ_MUXH_ADDR               0x019C0000u

  #define _IRQ_MUXH_INTSEL15_MASK      0x7C000000u
  #define _IRQ_MUXH_INTSEL15_SHIFT     0x0000001Au
  #define  IRQ_MUXH_INTSEL15_DEFAULT   0x00000002u
  #define  IRQ_MUXH_INTSEL15_OF(x)     _VALUEOF(x)

  #define _IRQ_MUXH_INTSEL14_MASK      0x03E00000u
  #define _IRQ_MUXH_INTSEL14_SHIFT     0x00000015u
  #define  IRQ_MUXH_INTSEL14_DEFAULT   0x00000001u
  #define  IRQ_MUXH_INTSEL14_OF(x)     _VALUEOF(x)

  #define _IRQ_MUXH_INTSEL13_MASK      0x001F0000u
  #define _IRQ_MUXH_INTSEL13_SHIFT     0x00000010u
  #define  IRQ_MUXH_INTSEL13_DEFAULT   0x00000000u
  #define  IRQ_MUXH_INTSEL13_OF(x)     _VALUEOF(x)

  #define _IRQ_MUXH_INTSEL12_MASK      0x00007C00u
  #define _IRQ_MUXH_INTSEL12_SHIFT     0x0000000Au
  #define  IRQ_MUXH_INTSEL12_DEFAULT   0x0000000Bu
  #define  IRQ_MUXH_INTSEL12_OF(x)     _VALUEOF(x)

  #define _IRQ_MUXH_INTSEL11_MASK      0x000003E0u
  #define _IRQ_MUXH_INTSEL11_SHIFT     0x00000005u
  #define  IRQ_MUXH_INTSEL11_DEFAULT   0x0000000Au
  #define  IRQ_MUXH_INTSEL11_OF(x)     _VALUEOF(x)

  #define _IRQ_MUXH_INTSEL10_MASK      0x0000001Fu
  #define _IRQ_MUXH_INTSEL10_SHIFT     0x00000000u
  #define  IRQ_MUXH_INTSEL10_DEFAULT   0x00000003u
  #define  IRQ_MUXH_INTSEL10_OF(x)     _VALUEOF(x)

  #define  IRQ_MUXH_OF(x)              _VALUEOF(x)

  #define IRQ_MUXH_DEFAULT (Uint32)( \
     _PER_FDEFAULT(IRQ,MUXH,INTSEL15) \
    |_PER_FDEFAULT(IRQ,MUXH,INTSEL14) \
    |_PER_FDEFAULT(IRQ,MUXH,INTSEL13) \
    |_PER_FDEFAULT(IRQ,MUXH,INTSEL12) \
    |_PER_FDEFAULT(IRQ,MUXH,INTSEL11) \
    |_PER_FDEFAULT(IRQ,MUXH,INTSEL10) \
  )

  #define IRQ_MUXH_RMK(intsel15,intsel14,intsel13,intsel12,intsel11,intsel10) \
    (Uint32)( \
     _PER_FMK(IRQ,MUXH,INTSEL15,intsel15) \
    |_PER_FMK(IRQ,MUXH,INTSEL14,intsel14) \
    |_PER_FMK(IRQ,MUXH,INTSEL13,intsel13) \
    |_PER_FMK(IRQ,MUXH,INTSEL12,intsel12) \
    |_PER_FMK(IRQ,MUXH,INTSEL11,intsel11) \
    |_PER_FMK(IRQ,MUXH,INTSEL10,intsel10) \
   )

  #define _IRQ_MUXH_FGET(FIELD)\
    _PER_FGET(_IRQ_MUXH_ADDR,IRQ,MUXH,##FIELD)

  #define _IRQ_MUXH_FSET(FIELD,field)\
    _PER_FSET(_IRQ_MUXH_ADDR,IRQ,MUXH,##FIELD,field)

  #define _IRQ_MUXH_FSETS(FIELD,SYM)\
    _PER_FSETS(_IRQ_MUXH_ADDR,IRQ,MUXH,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  M U X L          |
* |___________________|
*
* MUXL - interrupt multiplexer low register
*
* FIELDS (msb -> lsb)
* (rw) INTSEL9
* (rw) INTSEL8
* (rw) INTSEL7
* (rw) INTSEL6
* (rw) INTSEL5
* (rw) INTSEL4
*
\******************************************************************************/
  #define _IRQ_MUXL_ADDR               0x019C0004u

  #define _IRQ_MUXL_INTSEL9_MASK       0x7C000000u
  #define _IRQ_MUXL_INTSEL9_SHIFT      0x0000001Au
  #define  IRQ_MUXL_INTSEL9_DEFAULT    0x00000009u
  #define  IRQ_MUXL_INTSEL9_OF(x)      _VALUEOF(x)

  #define _IRQ_MUXL_INTSEL8_MASK       0x03E00000u
  #define _IRQ_MUXL_INTSEL8_SHIFT      0x00000015u
  #define  IRQ_MUXL_INTSEL8_DEFAULT    0x00000008u
  #define  IRQ_MUXL_INTSEL8_OF(x)      _VALUEOF(x)

  #define _IRQ_MUXL_INTSEL7_MASK       0x001F0000u
  #define _IRQ_MUXL_INTSEL7_SHIFT      0x00000010u
  #define  IRQ_MUXL_INTSEL7_DEFAULT    0x00000007u
  #define  IRQ_MUXL_INTSEL7_OF(x)      _VALUEOF(x)

  #define _IRQ_MUXL_INTSEL6_MASK       0x00007C00u
  #define _IRQ_MUXL_INTSEL6_SHIFT      0x0000000Au
  #define  IRQ_MUXL_INTSEL6_DEFAULT    0x00000006u
  #define  IRQ_MUXL_INTSEL6_OF(x)      _VALUEOF(x)

  #define _IRQ_MUXL_INTSEL5_MASK       0x000003E0u
  #define _IRQ_MUXL_INTSEL5_SHIFT      0x00000005u
  #define  IRQ_MUXL_INTSEL5_DEFAULT    0x00000005u
  #define  IRQ_MUXL_INTSEL5_OF(x)      _VALUEOF(x)

  #define _IRQ_MUXL_INTSEL4_MASK       0x0000001Fu
  #define _IRQ_MUXL_INTSEL4_SHIFT      0x00000000u
  #define  IRQ_MUXL_INTSEL4_DEFAULT    0x00000004u
  #define  IRQ_MUXL_INTSEL4_OF(x)      _VALUEOF(x)

  #define  IRQ_MUXL_OF(x)              _VALUEOF(x)

  #define IRQ_MUXL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(IRQ,MUXL,INTSEL9) \
    |_PER_FDEFAULT(IRQ,MUXL,INTSEL8) \
    |_PER_FDEFAULT(IRQ,MUXL,INTSEL7) \
    |_PER_FDEFAULT(IRQ,MUXL,INTSEL6) \
    |_PER_FDEFAULT(IRQ,MUXL,INTSEL5) \
    |_PER_FDEFAULT(IRQ,MUXL,INTSEL4) \
  )

  #define IRQ_MUXL_RMK(intsel9,intsel8,intsel7,intsel6,intsel5,intsel4) \
    (Uint32)( \
     _PER_FMK(IRQ,MUXL,INTSEL9,intsel9) \
    |_PER_FMK(IRQ,MUXL,INTSEL8,intsel8) \
    |_PER_FMK(IRQ,MUXL,INTSEL7,intsel7) \
    |_PER_FMK(IRQ,MUXL,INTSEL6,intsel6) \
    |_PER_FMK(IRQ,MUXL,INTSEL5,intsel5) \
    |_PER_FMK(IRQ,MUXL,INTSEL4,intsel4) \
   )

  #define _IRQ_MUXL_FGET(FIELD)\
    _PER_FGET(_IRQ_MUXL_ADDR,IRQ,MUXL,##FIELD)

  #define _IRQ_MUXL_FSET(FIELD,field)\
    _PER_FSET(_IRQ_MUXL_ADDR,IRQ,MUXL,##FIELD,field)

  #define _IRQ_MUXL_FSETS(FIELD,SYM)\
    _PER_FSETS(_IRQ_MUXL_ADDR,IRQ,MUXL,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  E X T P O L      |
* |___________________|
*
* EXTPOL - external interrupt polarity register
*
* FIELDS (msb -> lsb)
* (rw) XIP
*
\******************************************************************************/
  #define _IRQ_EXTPOL_ADDR            0x019C0008u

  #define _IRQ_EXTPOL_XIP_MASK        0x0000000Fu
  #define _IRQ_EXTPOL_XIP_SHIFT       0x00000000u
  #define  IRQ_EXTPOL_XIP_DEFAULT     0x00000000u
  #define  IRQ_EXTPOL_XIP_OF(x)       _VALUEOF(x)

  #define  IRQ_EXTPOL_OF(x)           _VALUEOF(x)

  #define IRQ_EXTPOL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(IRQ,EXTPOL,XIP) \
  )

  #define IRQ_EXTPOL_RMK(xip) (Uint32)( \
     _PER_FMK(IRQ,EXTPOL,XIP,xip) \
  )

  #define _IRQ_EXTPOL_FGET(FIELD)\
    _PER_FGET(_IRQ_EXTPOL_ADDR,IRQ,EXTPOL,##FIELD)

  #define _IRQ_EXTPOL_FSET(FIELD,field)\
    _PER_FSET(_IRQ_EXTPOL_ADDR,IRQ,EXTPOL,##FIELD,field)

  #define _IRQ_EXTPOL_FSETS(FIELD,SYM)\
    _PER_FSETS(_IRQ_EXTPOL_ADDR,IRQ,EXTPOL,##FIELD,##SYM)


/*----------------------------------------------------------------------------*/

#endif /* IRQ_SUPPORT */
#endif /* _CSL_IRQHAL_H_ */
/******************************************************************************\
* End of csl_irqhal.h
\******************************************************************************/

