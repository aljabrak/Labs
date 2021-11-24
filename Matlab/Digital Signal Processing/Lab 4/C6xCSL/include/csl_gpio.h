/******************************************************************************\
*         Copyright (C) 2000-2001 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_gpio.h
* DATE CREATED.. 12/04/2000 
* LAST MODIFIED. 05/09/2001
\******************************************************************************/

#ifndef _CSL_GPIO_H_
#define _CSL_GPIO_H_

#include <csl_stdinc.h>
#include <csl_chip.h>
#include <csl_irq.h>
#include "csl_gpiohal.h"


#if (GPIO_SUPPORT)
/******************************************************************************\
*     scope and inline control macros
\******************************************************************************/
#ifdef __cplusplus
#define CSLAPI extern "C" far 
#else
#define CSLAPI extern far
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _GPIO_MOD_
  #define IDECL CSLAPI
  #define USEDEFS
  #define IDEF
#else
  #ifdef  _INLINE
    #define IDECL static inline
    #define USEDEFS
    #define IDEF  static inline
  #else
    #define IDECL CSLAPI
  #endif
#endif

/******************************************************************************\
*       global macro declarations
\******************************************************************************/

/* Macro define devices */
#define GPIO_DEV0          0
#if CHIP_DA610
#define GPIO_DEV1          1
#endif

/* misc global settings */
#define GPIO_INT_CNT       5
#define GPIO_PIN_CNT      32
#define GPIO_OPEN_RESET    1


/* Pin id definitions */
#define GPIO_PIN0          0x00000001u
#define GPIO_PIN1          0x00000002u
#define GPIO_PIN2          0x00000004u
#define GPIO_PIN3          0x00000008u
#define GPIO_PIN4          0x00000010u
#define GPIO_PIN5          0x00000020u
#define GPIO_PIN6          0x00000040u
#define GPIO_PIN7          0x00000080u
#define GPIO_PIN8          0x00000100u
#define GPIO_PIN9          0x00000200u
#define GPIO_PIN10         0x00000400u
#define GPIO_PIN11         0x00000800u
#define GPIO_PIN12         0x00001000u
#define GPIO_PIN13         0x00002000u
#define GPIO_PIN14         0x00004000u
#define GPIO_PIN15         0x00008000u
#define GPIO_PIN16         0x00010000u
#define GPIO_PIN17         0x00020000u
#define GPIO_PIN18         0x00040000u
#define GPIO_PIN19         0x00080000u
#define GPIO_PIN20         0x00100000u
#define GPIO_PIN21         0x00200000u
#define GPIO_PIN22         0x00400000u
#define GPIO_PIN23         0x00800000u
#define GPIO_PIN24         0x01000000u
#define GPIO_PIN25         0x02000000u
#define GPIO_PIN26         0x04000000u
#define GPIO_PIN27         0x08000000u
#define GPIO_PIN28         0x10000000u
#define GPIO_PIN29         0x20000000u
#define GPIO_PIN30         0x40000000u
#define GPIO_PIN31         0x80000000u

/* CPU Interrupt Pins for GPIO0 only */

#define GPIO_GPINT0        0
#define GPIO_GPINT4        1
#define GPIO_GPINT5        2
#define GPIO_GPINT6        3
#define GPIO_GPINT7        4

/* Interrupt Polarity */
#define GPIO_RISING     0
#define GPIO_FALLING    1

/* Pin  Direction */
#define GPIO_INPUT         0
#define GPIO_OUTPUT        1

/* GPIO masks */
#define GPIO_MASK_NA       0x00000000u
#define GPIO_MASK_00       0x00000001u
#define GPIO_MASK_01       0x00000002u
#define GPIO_MASK_02       0x00000004u
#define GPIO_MASK_03       0x00000008u
#define GPIO_MASK_04       0x00000010u
#define GPIO_MASK_05       0x00000020u
#define GPIO_MASK_06       0x00000040u
#define GPIO_MASK_07       0x00000080u
#define GPIO_MASK_08       0x00000100u
#define GPIO_MASK_09       0x00000200u
#define GPIO_MASK_10       0x00000400u
#define GPIO_MASK_11       0x00000800u
#define GPIO_MASK_12       0x00001000u
#define GPIO_MASK_13       0x00002000u
#define GPIO_MASK_14       0x00004000u
#define GPIO_MASK_15       0x00008000u

/*****************************************************************************\
*       global typedef declarations
\******************************************************************************/
  typedef struct {
   Uint32 gpgc;
   Uint32 gpen;
   Uint32 gpdir;
   Uint32 gpval;
   Uint32 gphm;
   Uint32 gplm;   
   Uint32 gppol;
  } GPIO_Config;

/* device handle object */
typedef struct {
  Uint32 allocated;
  volatile Uint32 *baseAddr;
  Uint32 pinAllocMask;
} GPIO_Obj, *GPIO_Handle;


/******************************************************************************\
*       global variable declarations
\******************************************************************************/
//extern far Uint32 _GPIO_pinTable[GPIO_PIN_CNT];
extern far Uint32 _GPIO_intTable[GPIO_INT_CNT];
extern far GPIO_Handle _hGpioDev0;

/******************************************************************************\
*      global function declarations
\******************************************************************************/

/* private functions */
/* API functions (Non-Inline function : Source file) */
CSLAPI GPIO_Handle GPIO_open(int devnum, Uint32 flags);
CSLAPI void GPIO_close(GPIO_Handle hGpio);
CSLAPI void GPIO_reset(GPIO_Handle hGpio);
CSLAPI void GPIO_clear(GPIO_Handle hGpio);


/******************************************************************************\
*       inline function declarations
\******************************************************************************/
/* configuration */

IDECL void GPIO_config(GPIO_Handle hGpio, GPIO_Config *config);
IDECL void GPIO_configArgs(GPIO_Handle hGpio,Uint32 gpgc,Uint32 gpen, Uint32 gpdir,Uint32 gpval, 
                  Uint32 gphm, Uint32 gplm, Uint32 gppol);
IDECL void GPIO_getConfig(GPIO_Handle hGpio, GPIO_Config *config);


IDECL void GPIO_pinDisable(GPIO_Handle hGpio, Uint32 pinId);
IDECL void GPIO_pinEnable(GPIO_Handle hGpio,Uint32 pinId);

IDECL Uint32 GPIO_pinDirection(GPIO_Handle hGpio, Uint32 pinId, Uint32 direction);
IDECL Uint32 GPIO_pinRead(GPIO_Handle hGpio,Uint32 pinId);
IDECL Uint32 GPIO_read(GPIO_Handle hGpio, Uint32 pinMask);


/* For output Pins */
IDECL void GPIO_pinWrite(GPIO_Handle hGpio,Uint32 pinId, Uint32 val);
IDECL void GPIO_write(GPIO_Handle hGpio, Uint32 pinMask, Uint32 val);


/* For input Pins */
IDECL Uint32 GPIO_deltaHighGet(GPIO_Handle hGpio,Uint32 pinId);
IDECL void GPIO_deltaHighClear(GPIO_Handle hGpio,Uint32 pinId);
IDECL Uint32 GPIO_deltaLowGet(GPIO_Handle hGpio,Uint32 pinId);
IDECL void GPIO_deltaLowClear(GPIO_Handle hGpio,Uint32 pinId);

IDECL void GPIO_maskHighSet(GPIO_Handle hGpio,Uint32 pinId);
IDECL void GPIO_maskHighClear(GPIO_Handle hGpio,Uint32 pinId);
IDECL void GPIO_maskLowSet(GPIO_Handle hGpio,Uint32 pinId);
IDECL void GPIO_maskLowClear(GPIO_Handle hGpio,Uint32 pinId);


/* Pass Through Mode */
IDECL Uint32 GPIO_intPolarity(GPIO_Handle hGpio,Uint32 signal, Uint32 polarity);


/******************************************************************************\
*       inline function definitions
\******************************************************************************/
#ifdef USEDEFS
/*----------------------------------------------------------------------------*/
IDEF void GPIO_pinEnable(GPIO_Handle hGpio,Uint32 pinId) {
  Uint32 gpen = GPIO_RGETH(hGpio,GPEN);
  gpen = gpen | (pinId & hGpio->pinAllocMask);
  GPIO_FSETH(hGpio,GPEN,GPXEN,gpen);
}
/*----------------------------------------------------------------------------*/
IDEF void GPIO_pinDisable(GPIO_Handle hGpio,Uint32 pinId) {
  Uint32 gpen = GPIO_RGETH(hGpio,GPEN);
  gpen = gpen & (~pinId & hGpio->pinAllocMask);
  GPIO_FSETH(hGpio,GPEN,GPXEN,gpen);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 GPIO_pinDirection(GPIO_Handle hGpio,Uint32 pinId, Uint32 direction) {
  Uint32 gpdir = GPIO_RGETH(hGpio,GPDIR);
  if ( direction == 0) {
       GPIO_RSETH(hGpio,GPDIR,(gpdir & (~pinId & hGpio->pinAllocMask)));
  } else {
       GPIO_RSETH(hGpio,GPDIR,(gpdir | (pinId & hGpio->pinAllocMask)));
    }
  return ( GPIO_RGETH(hGpio,GPDIR));

}
/*----------------------------------------------------------------------------*/
IDEF Uint32 GPIO_pinRead(GPIO_Handle hGpio,Uint32 pinId) {
Uint32 x = 0xFFFFFFFF;

      if ( (GPIO_RGETH(hGpio,GPVAL) & (pinId & hGpio->pinAllocMask))!= 0 ) { 
           x = 1;
      } else {
           x = 0;
        }
  
 return ( x );
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 GPIO_read(GPIO_Handle hGpio, Uint32 pinMask)
{
    return ((GPIO_RGETH(hGpio,GPVAL) & pinMask) & hGpio->pinAllocMask);
}
/*----------------------------------------------------------------------------*/
IDEF void GPIO_pinWrite(GPIO_Handle hGpio,Uint32 pinId, Uint32 val) {
 Uint32 gpval = GPIO_RGETH(hGpio,GPVAL);
 if ( val == 0) {
     GPIO_RSETH(hGpio,GPVAL,(gpval & (~pinId  & hGpio->pinAllocMask)));
  } else {
     GPIO_RSETH(hGpio,GPVAL,(gpval | (pinId  & hGpio->pinAllocMask)));
  }

}
/*----------------------------------------------------------------------------*/
IDEF void GPIO_write(GPIO_Handle hGpio, Uint32 pinMask, Uint32 val)
{
    Uint32 gpval = GPIO_RGETH(hGpio,GPVAL);
    GPIO_RSETH(hGpio,GPVAL, ((gpval & ~pinMask) | (pinMask & val)));
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 GPIO_deltaHighGet(GPIO_Handle hGpio,Uint32 pinId) {
  return (GPIO_FGETH(hGpio,GPDH,GPXDH)& (pinId & hGpio->pinAllocMask));
}
/*----------------------------------------------------------------------------*/
IDEF void GPIO_deltaHighClear(GPIO_Handle hGpio,Uint32 pinId) {
  Uint32 gpdh= GPIO_RGETH(hGpio,GPDH); 
  GPIO_FSETH(hGpio,GPDH,GPXDH,(gpdh & (pinId & hGpio->pinAllocMask)));

}
/*----------------------------------------------------------------------------*/
 IDEF Uint32 GPIO_deltaLowGet(GPIO_Handle hGpio,Uint32 pinId) {
  return (GPIO_FGETH(hGpio,GPDL,GPXDL)& (pinId & hGpio->pinAllocMask));
}
/*----------------------------------------------------------------------------*/ 
 IDEF void GPIO_deltaLowClear(GPIO_Handle hGpio,Uint32 pinId) {
  Uint32 gpdl= GPIO_RGETH(hGpio,GPDL); 
  GPIO_FSETH(hGpio,GPDL,GPXDL,(gpdl & (pinId & hGpio->pinAllocMask)));
}
/*----------------------------------------------------------------------------*/
IDEF void GPIO_maskHighSet(GPIO_Handle hGpio,Uint32 pinId) {
  Uint32 gphm = GPIO_RGETH(hGpio,GPHM);
  GPIO_FSETH(hGpio,GPHM,GPXHM,(gphm | (pinId & hGpio->pinAllocMask)));
}
/*----------------------------------------------------------------------------*/
IDEF void GPIO_maskHighClear(GPIO_Handle hGpio,Uint32 pinId) {
  Uint32 gphm = GPIO_RGETH(hGpio,GPHM);
  GPIO_FSETH(hGpio,GPHM,GPXHM,(gphm & (~pinId & hGpio->pinAllocMask)));
}
/*----------------------------------------------------------------------------*/
IDEF void GPIO_maskLowSet(GPIO_Handle hGpio,Uint32 pinId) {
  Uint32 gplm = GPIO_RGETH(hGpio,GPLM);
  GPIO_FSETH(hGpio,GPLM,GPXLM,(gplm | (pinId & hGpio->pinAllocMask)));
}
/*----------------------------------------------------------------------------*/
IDEF void GPIO_maskLowClear(GPIO_Handle hGpio,Uint32 pinId) {
  Uint32 gplm = GPIO_RGETH(hGpio,GPLM);
  GPIO_FSETH(hGpio,GPLM,GPXLM,(gplm & (~pinId & hGpio->pinAllocMask)));
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 GPIO_intPolarity(GPIO_Handle hGpio,Uint32 signal, Uint32 polarity){
  Uint32 gppol = GPIO_RGETH(hGpio,GPPOL);
   if ( polarity == 0) {
     GPIO_FSETH(hGpio,GPPOL,GPINTXPOL,(gppol & ~_GPIO_intTable[signal]));
  } else {   
    GPIO_FSETH(hGpio,GPPOL,GPINTXPOL,(gppol | _GPIO_intTable[signal]));
    }
 return ( GPIO_RGETH(hGpio,GPPOL));
}   
/*----------------------------------------------------------------------------*/
IDEF void GPIO_config(GPIO_Handle hGpio,GPIO_Config *config) {
  Uint32 gie;
  register int x0,x1,x2,x3,x4,x5,x6;
  volatile Uint32 *base = (volatile Uint32 *)(hGpio->baseAddr);

  gie = IRQ_globalDisable();

  x0 = config->gpgc;
  x1 = config->gpen;
  x2 = config->gpdir;
  x3 = config->gpval;
  x4 = config->gphm;
  x5 = config->gplm;
  x6 = config->gppol;

  base[_GPIO_GPGC_OFFSET] = x0;
  base[_GPIO_GPEN_OFFSET] = x1;  
  base[_GPIO_GPDIR_OFFSET]= x2;
  base[_GPIO_GPVAL_OFFSET]= x3;
  base[_GPIO_GPHM_OFFSET] = x4;
  base[_GPIO_GPLM_OFFSET] = x5;
  base[_GPIO_GPPOL_OFFSET]= x6;

 IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void GPIO_configArgs(GPIO_Handle hGpio, Uint32 gpgc,Uint32 gpen, Uint32 gpdir,Uint32 gpval,
                  Uint32 gphm, Uint32 gplm, Uint32 gppol) {
   Uint32 gie;
   volatile Uint32 *base = (volatile Uint32 *)(hGpio->baseAddr);

  gie = IRQ_globalDisable();

   base[_GPIO_GPGC_OFFSET] = gpgc;
   base[_GPIO_GPEN_OFFSET] = gpen;  
   base[_GPIO_GPDIR_OFFSET]= gpdir;
   base[_GPIO_GPVAL_OFFSET]= gpval;
   base[_GPIO_GPHM_OFFSET] = gphm;
   base[_GPIO_GPLM_OFFSET] = gplm;
   base[_GPIO_GPPOL_OFFSET]= gppol ;

  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void GPIO_getConfig(GPIO_Handle hGpio,GPIO_Config *config) {
  Uint32 gie;
  register int x0,x1,x2,x3,x4,x5,x6;
   volatile Uint32 *base = (volatile Uint32 *)(hGpio->baseAddr);

  gie = IRQ_globalDisable();
  
  x0 = base[_GPIO_GPGC_OFFSET];
  x1 = base[_GPIO_GPEN_OFFSET];  
  x2 = base[_GPIO_GPDIR_OFFSET];
  x3 = base[_GPIO_GPVAL_OFFSET];
  x4 = base[_GPIO_GPHM_OFFSET];
  x5 = base[_GPIO_GPLM_OFFSET];
  x6 = base[_GPIO_GPPOL_OFFSET];
  
  config->gpgc  = x0;
  config->gpen  = x1;
  config->gpdir = x2;
  config->gpval = x3;
  config->gphm  = x4;
  config->gplm  = x5;
  config->gppol = x6;

  IRQ_globalRestore(gie);
}
/*---------------------------------------------------------------------------*/

#endif /* USEDEFS */


#endif /* GPIO_SUPPORT */

#endif /* _CSL_GPIO_H_ */
/******************************************************************************\
* End of csl_gpio.h
\******************************************************************************/
