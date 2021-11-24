/******************************************************************************\
*  Step 1.      Copyright (C) 2001 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_pll.h
* DATE CREATED.. 10/29/2001 
* LAST MODIFIED. 11/30/2001
*                11/30/2003 Modified PLL_init() sequence to fix the PLL 
*                           initialization problem
*                4/13/2005  Modified the sequence of the plldiv1 and plldiv2 
*                           according to the data sheet in PLL_config() and
*                           PLL_configArgs().
\******************************************************************************/

/******************************************************************************\
* Step 2. Private Macros - Include files - PLL_SUPPORT
\******************************************************************************/
#ifndef _CSL_PLL_H_
#define _CSL_PLL_H_

#include <csl_stdinc.h>
#include <csl_chip.h>
#include <csl_pllhal.h>

#if (PLL_SUPPORT)
/******************************************************************************\
* Step 3. scope and inline control macros  
\******************************************************************************/
#ifdef __cplusplus
#define CSLAPI extern "C" far 
#else
#define CSLAPI extern far
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _PLL_MOD_
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
* Step 4. global macro declarations
\******************************************************************************/
#define PLL_DIV0  0
#define PLL_DIV1  1
#define PLL_DIV2  2
#define PLL_DIV3  3


/*****************************************************************************\
* Step 5. global typedef declarations
* Example : Config structure 
* typedef struct {
*   Uint32 rg1;
*   Uint32 rg2;
*  } PLL_Config;
\******************************************************************************/
typedef struct{
    Uint32 pllcsr;
    Uint32 pllm;
    Uint32 plldiv0;
    Uint32 plldiv1;
    Uint32 plldiv2;
    Uint32 plldiv3;
    Uint32 oscdiv1;
}PLL_Config;
    
  
typedef struct {
   Uint32  mdiv;
   Uint32  d0ratio;
   Uint32  d1ratio;
   Uint32  d2ratio;
   Uint32  d3ratio;
   Uint32  od1ratio;
 }PLL_Init;	 

/******************************************************************************\
* Step 6. global variable declarations
\******************************************************************************/
/* private vars */
extern far Uint32 _PLL_divAddr[4];


/******************************************************************************\
* Step 7. global function declarations
\******************************************************************************/

/* Private functions (If applicable)*/

static void plldelay(Uint32 count);

/* API functions (Non-Inline function : Source file) */
CSLAPI void PLL_wait100();
CSLAPI Uint32 PLL_wait1();

/******************************************************************************\
* Step 8. inline function declarations ( IDECL keyword)
\******************************************************************************/
IDECL void PLL_config(PLL_Config *config);
IDECL void PLL_configArgs(Uint32 pllcsr, Uint32 pllm, Uint32 plldiv0, Uint32 plldiv1, Uint32 plldiv2, Uint32 plldiv3,Uint32 oscdiv1);
IDECL void PLL_getConfig(PLL_Config *config);

IDECL void PLL_init(PLL_Init *init);

IDECL void PLL_pwrdwn();
IDECL void PLL_operational();
IDECL void PLL_enable();
IDECL void PLL_bypass();
IDECL void PLL_reset();
IDECL void PLL_deassert();


IDECL Uint32 PLL_clkTest();

IDECL void PLL_enablePllDiv(Uint32 divId);
IDECL void PLL_disablePllDiv(Uint32 divId);

IDECL void PLL_enableOscDiv();
IDECL void PLL_disableOscDiv();

IDECL void PLL_setMultiplier(Uint32 val);
IDECL void PLL_setPllRatio(Uint32 divId,Uint32 val);
IDECL void PLL_setOscRatio(Uint32 val);

IDECL Uint32 PLL_getMultiplier();
IDECL Uint32 PLL_getPllRatio(Uint32 divnum);
IDECL Uint32 PLL_getOscRatio();

/******************************************************************************\
* Step 9. inline function definitions  ( #if USEDEF - IDEF keywords)
\******************************************************************************/

#ifdef USEDEFS
/*----------------------------------------------------------------------------*/
IDEF void PLL_pwrdwn(){       
      PLL_FSETS(PLLCSR,PLLEN,BYPASS); /* Bypass mode PLLEN = 0 */ 
      PLL_FSETS(PLLCSR,PLLPWRDN,YES); /* PwrDwn mode */

}
/*----------------------------------------------------------------------------*/
IDEF void PLL_operational(){       
      PLL_FSETS(PLLCSR,PLLPWRDN,NO);     /* Operational mode */
      PLL_FSETS(PLLDIV0,D0EN,ENABLE);    /* Enable D0 path   */
      PLL_FSETS(PLLCSR,PLLEN,ENABLE);    /* Enable PLLEN = 1 */ 
}
/*----------------------------------------------------------------------------*/
IDEF void PLL_enable(){
      PLL_FSETS(PLLCSR,PLLEN,ENABLE); /* Bypass mode PLLEN = 1 */ 
}
/*----------------------------------------------------------------------------*/
IDEF void PLL_bypass(){
     PLL_FSETS(PLLCSR,PLLEN,BYPASS); /* Bypass mode PLLEN = 0 */ 
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 PLL_clkTest(){   
     return(PLL_FGET(PLLCSR,STABLE));  
}
/*----------------------------------------------------------------------------*/
IDEF void PLL_reset(){   
     PLL_FSETS(PLLCSR,PLLRST,1);     /* reset mode */
}
/*----------------------------------------------------------------------------*/
IDEF void PLL_deassert(){   
     PLL_FSETS(PLLCSR,PLLRST,0);    /* deassert PLL */ 
}
/*----------------------------------------------------------------------------*/
IDEF void PLL_enablePllDiv(Uint32 divId){
   (*(volatile Uint32*) _PLL_divAddr[divId]) |=(0x00008000u);
}
/*----------------------------------------------------------------------------*/
IDEF void PLL_disablePllDiv(Uint32 divId){
   (*(volatile Uint32*)  _PLL_divAddr[divId]) &=~(0x00008000u);
}
/*----------------------------------------------------------------------------*/
IDEF void PLL_enableOscDiv(){
    PLL_FSET(OSCDIV1,OD1EN,1);
}
/*----------------------------------------------------------------------------*/
IDEF void PLL_disableOscDiv(){
    PLL_FSET(OSCDIV1,OD1EN,0);
}
/*----------------------------------------------------------------------------*/
IDEF void PLL_setPllRatio(Uint32 divId, Uint32 val){
  Uint32  tmp= ((*(volatile Uint32*) _PLL_divAddr[divId])  & 0xFFFFFFE0u);
     (*(volatile Uint32*) _PLL_divAddr[divId]) =(val | tmp );
}
/*----------------------------------------------------------------------------*/
IDEF void PLL_setOscRatio(Uint32 val){
    PLL_FSET(OSCDIV1,RATIO,val);
}
/*----------------------------------------------------------------------------*/
IDEF void PLL_setMultiplier(Uint32 val){
    PLL_FSET(PLLM,PLLM,val);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 PLL_getPllRatio(Uint32 divId){
    return (Uint32)((*(volatile Uint32*) _PLL_divAddr[divId]) & 0x0000001Fu);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 PLL_getOscRatio(){
    return(PLL_FGET(OSCDIV1,RATIO));
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 PLL_getMultiplier(){
    return(PLL_FGET(PLLM,PLLM));
}

/*----------------------------------------------------------------------------*/
IDEF void PLL_init(PLL_Init *init) {

  Uint32 gie ;
  gie = IRQ_globalDisable();

  PLL_FSETS(PLLCSR,PLLEN,BYPASS); /* Bypass mode PLLEN = 0 */ 

  plldelay(20);

  PLL_FSETS(PLLCSR,PLLRST,1);     /* reset mode */
  
  plldelay(20);

  // Set main multiplier/divisor 
  PLL_RSET(PLLM,init->mdiv);
  PLL_RSET(PLLDIV0, PLL_PLLDIV0_RMK(0,init->d0ratio));
  PLL_RSET(OSCDIV1,PLL_OSCDIV1_RMK(0,init->od1ratio));		  
  
  // Set DSP clock 
  PLL_RSET(PLLDIV1,PLL_PLLDIV1_RMK(1,init->d1ratio));
  
  // Set EMIF clock 
  PLL_RSET(PLLDIV3,PLL_PLLDIV3_RMK(0,init->d3ratio));

  plldelay(20);

  //   Take PLL out of reset
  PLL_FSETS(PLLCSR,PLLRST,0);
  plldelay(1500);

  // Enable PLL
  PLL_FSETS(PLLCSR,PLLEN,ENABLE);
  plldelay(20);
 
  IRQ_globalRestore(gie);
}
  

/*----------------------------------------------------------------------------*/
IDEF void PLL_config(PLL_Config *config) {
  Uint32 gie;
  volatile Uint32 *base;
  register Uint32 x0,x1,x2,x3,x4,x5,x6;
 
  gie = IRQ_globalDisable();

  x0 = config->pllcsr;
  x1 = config->pllm;
  x2 = config->plldiv0;
  x3 = config->plldiv1;
  x4 = config->plldiv2;
  x5 = config->plldiv3;
  x6 = config->oscdiv1;


  base = (volatile Uint32 *)(_PLL_BASE_ADDR);

  base[_PLL_PLLM_OFFSET] = x1;
  base[_PLL_PLLDIV0_OFFSET] = x2;
  if ( base[_PLL_PLLDIV1_OFFSET] > x3 ) {
      base[_PLL_PLLDIV1_OFFSET] = x3;
      base[_PLL_PLLDIV2_OFFSET] = x4;
  }
  else {
     base[_PLL_PLLDIV2_OFFSET] = x4;
     base[_PLL_PLLDIV1_OFFSET] = x3;
  }
     
  base[_PLL_PLLDIV3_OFFSET] = x5;
  base[_PLL_OSCDIV1_OFFSET] = x6;
  base[_PLL_PLLCSR_OFFSET] = x0;

  IRQ_globalRestore(gie);
  
}

/*----------------------------------------------------------------------------*/
IDEF void PLL_configArgs(Uint32 pllcsr, Uint32 pllm, Uint32 plldiv0, Uint32 plldiv1, Uint32 plldiv2, Uint32 plldiv3,Uint32 oscdiv1){

  Uint32 gie;
  volatile Uint32 *base;
  gie = IRQ_globalDisable();

  base = (volatile Uint32 *)(_PLL_BASE_ADDR);

  base[_PLL_PLLM_OFFSET] = pllm;
  base[_PLL_PLLDIV0_OFFSET] = plldiv0;
  if ( base[_PLL_PLLDIV1_OFFSET] > plldiv1) { 
      base[_PLL_PLLDIV1_OFFSET] = plldiv1;
      base[_PLL_PLLDIV2_OFFSET] = plldiv2;
  }
  else {
      base[_PLL_PLLDIV2_OFFSET] = plldiv2;
      base[_PLL_PLLDIV1_OFFSET] = plldiv1;
  }
  base[_PLL_PLLDIV3_OFFSET] = plldiv3;
  base[_PLL_OSCDIV1_OFFSET] = oscdiv1;
  base[_PLL_PLLCSR_OFFSET] = pllcsr;

  IRQ_globalRestore(gie);
}


/*----------------------------------------------------------------------------*/
IDEF void PLL_getConfig(PLL_Config *config) {
  Uint32 gie;
  volatile Uint32 *base;
  register Uint32 x0,x1,x2,x3,x4,x5,x6;
 
  gie = IRQ_globalDisable();

  base = (volatile Uint32 *)(_PLL_BASE_ADDR);
 
 x0 = base[_PLL_PLLCSR_OFFSET];
 x1 = base[_PLL_PLLM_OFFSET];
 x2 = base[_PLL_PLLDIV0_OFFSET];
 x3 = base[_PLL_PLLDIV1_OFFSET];
 x4 = base[_PLL_PLLDIV2_OFFSET];
 x5 = base[_PLL_PLLDIV3_OFFSET];
 x6 = base[_PLL_OSCDIV1_OFFSET];

  config->pllcsr = x0;
  config->pllm = x1;
  config->plldiv0 = x2;
  config->plldiv1 = x3;
  config->plldiv2 = x4;
  config->plldiv3 = x5;
  config->oscdiv1 = x6;

  IRQ_globalRestore(gie);
  
}



/*----------------------------------------------------------------------------*/
#endif /* USEDEFS */

/* Local software delay function */

static void plldelay(Uint32 count){
   Uint32 i = count;
   while(i--){
     asm(" NOP 1");
   }
}

/******************************************************************************\
* Step 10. #endif for PLL_SUPPORT and CSL_PLL_H Macro + Footer
\******************************************************************************/
#endif /* PLL_SUPPORT */
#endif /* _CSL_PLL_H_ */
/******************************************************************************\
* End of csl_module.h
\******************************************************************************/
