/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_pwrhal.h
* DATE CREATED.. 11/11/1999
* LAST MODIFIED. 11/06/2000
*------------------------------------------------------------------------------
* REGISTERS
*
* PDCTL - power down control register
*
\******************************************************************************/
#ifndef _CSL_PWRHAL_H_
#define _CSL_PWRHAL_H_

#include <csl_stdinc.h>
#include <csl_chip.h>

#if (PWR_SUPPORT)
/******************************************************************************\
* MISC section
\******************************************************************************/
#define _PWR_COND1 (CHIP_6202|CHIP_6203|CHIP_6411)

/******************************************************************************\
* module level register/field access macros
\******************************************************************************/

  /* ----------------- */
  /* FIELD MAKE MACROS */
  /* ----------------- */

  #define PWR_FMK(REG,FIELD,x)\
    _PER_FMK(PWR,##REG,##FIELD,x)

  #define PWR_FMKS(REG,FIELD,SYM)\
    _PER_FMKS(PWR,##REG,##FIELD,##SYM)


  /* -------------------------------- */
  /* RAW REGISTER/FIELD ACCESS MACROS */
  /* -------------------------------- */

  #define PWR_ADDR(REG)\
    _PWR_##REG##_ADDR

  #define PWR_RGET(REG)\
    _PER_RGET(_PWR_##REG##_ADDR,PWR,##REG)

  #define PWR_RSET(REG,x)\
    _PER_RSET(_PWR_##REG##_ADDR,PWR,##REG,x)

  #define PWR_FGET(REG,FIELD)\
    _PWR_##REG##_FGET(##FIELD)

  #define PWR_FSET(REG,FIELD,x)\
    _PWR_##REG##_FSET(##FIELD,##x)

  #define PWR_FSETS(REG,FIELD,SYM)\
    _PWR_##REG##_FSETS(##FIELD,##SYM)


  /* ------------------------------------------ */
  /* ADDRESS BASED REGISTER/FIELD ACCESS MACROS */
  /* ------------------------------------------ */

  #define PWR_RGETA(addr,REG)\
    _PER_RGET(addr,PWR,##REG)

  #define PWR_RSETA(addr,REG,x)\
    _PER_RSET(addr,PWR,##REG,x)

  #define PWR_FGETA(addr,REG,FIELD)\
    _PER_FGET(addr,PWR,##REG,##FIELD)

  #define PWR_FSETA(addr,REG,FIELD,x)\
    _PER_FSET(addr,PWR,##REG,##FIELD,x)

  #define PWR_FSETSA(addr,REG,FIELD,SYM)\
    _PER_FSETS(addr,PWR,##REG,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  P D C T L        |
* |___________________|
*
* PDCTL - powerdown control register
*
* FIELDS (msb -> lsb)
* (rw) MCBSP2
* (rw) MCBSP1
* (rw) MCBSP0
* (rw) EMIF
* (rw) DMA
*
\******************************************************************************/
#if (_PWR_COND1)
  #define _PWR_PDCTL_ADDR              0x019C0200u

  #define _PWR_PDCTL_MCBSP2_MASK       0x00000010u
  #define _PWR_PDCTL_MCBSP2_SHIFT      0x00000004u
  #define  PWR_PDCTL_MCBSP2_DEFAULT    0x00000000u
  #define  PWR_PDCTL_MCBSP2_OF(x)      _VALUEOF(x)
  #define  PWR_PDCTL_MCBSP2_CLKON      0x00000000u
  #define  PWR_PDCTL_MCBSP2_CLKOFF     0x00000001u

  #define _PWR_PDCTL_MCBSP1_MASK       0x00000008u
  #define _PWR_PDCTL_MCBSP1_SHIFT      0x00000003u
  #define  PWR_PDCTL_MCBSP1_DEFAULT    0x00000000u
  #define  PWR_PDCTL_MCBSP1_OF(x)      _VALUEOF(x)
  #define  PWR_PDCTL_MCBSP1_CLKON      0x00000000u
  #define  PWR_PDCTL_MCBSP1_CLKOFF     0x00000001u

  #define _PWR_PDCTL_MCBSP0_MASK       0x00000004u
  #define _PWR_PDCTL_MCBSP0_SHIFT      0x00000002u
  #define  PWR_PDCTL_MCBSP0_DEFAULT    0x00000000u
  #define  PWR_PDCTL_MCBSP0_OF(x)      _VALUEOF(x)
  #define  PWR_PDCTL_MCBSP0_CLKON      0x00000000u
  #define  PWR_PDCTL_MCBSP0_CLKOFF     0x00000001u

  #define _PWR_PDCTL_EMIF_MASK         0x00000002u
  #define _PWR_PDCTL_EMIF_SHIFT        0x00000001u
  #define  PWR_PDCTL_EMIF_DEFAULT      0x00000000u
  #define  PWR_PDCTL_EMIF_OF(x)        _VALUEOF(x)
  #define  PWR_PDCTL_EMIF_CLKON        0x00000000u
  #define  PWR_PDCTL_EMIF_CLKOFF       0x00000001u

  #define _PWR_PDCTL_DMA_MASK          0x00000001u
  #define _PWR_PDCTL_DMA_SHIFT         0x00000000u
  #define  PWR_PDCTL_DMA_DEFAULT       0x00000000u
  #define  PWR_PDCTL_DMA_OF(x)         _VALUEOF(x)
  #define  PWR_PDCTL_DMA_CLKON         0x00000000u
  #define  PWR_PDCTL_DMA_CLKOFF        0x00000001u

  #define  PWR_PDCTL_OF(x)             _VALUEOF(x)

  #define PWR_PDCTL_DEFAULT (Uint32)( \
     _PER_FDEFAULT(PWR,PDCTL,MCBSP2) \
    |_PER_FDEFAULT(PWR,PDCTL,MCBSP1) \
    |_PER_FDEFAULT(PWR,PDCTL,MCBSP0) \
    |_PER_FDEFAULT(PWR,PDCTL,EMIF) \
    |_PER_FDEFAULT(PWR,PDCTL,DMA) \
  )

  #define PWR_PDCTL_RMK(mcbsp2,mcbsp1,mcbsp0,emif,dma) (Uint32)( \
     _PER_FMK(PWR,PDCTL,MCBSP2,mcbsp2) \
    |_PER_FMK(PWR,PDCTL,MCBSP1,mcbsp1) \
    |_PER_FMK(PWR,PDCTL,MCBSP0,mcbsp0) \
    |_PER_FMK(PWR,PDCTL,EMIF,emif) \
    |_PER_FMK(PWR,PDCTL,DMA,dma) \
   )

  #define _PWR_PDCTL_FGET(FIELD)\
    _PER_FGET(_PWR_PDCTL_ADDR,PWR,PDCTL,##FIELD)

  #define _PWR_PDCTL_FSET(FIELD,field)\
    _PER_FSET(_PWR_PDCTL_ADDR,PWR,PDCTL,##FIELD,field)

  #define _PWR_PDCTL_FSETS(FIELD,SYM)\
    _PER_FSETS(_PWR_PDCTL_ADDR,PWR,PDCTL,##FIELD,##SYM)
#endif


/*----------------------------------------------------------------------------*/

#endif /* PWR_SUPPORT */
#endif /* _CSL_PWRHAL_H_ */
/******************************************************************************\
* End of csl_pwrhal.h
\******************************************************************************/

