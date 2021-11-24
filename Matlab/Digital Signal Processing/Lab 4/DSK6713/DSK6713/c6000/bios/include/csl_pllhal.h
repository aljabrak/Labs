/****************************************************************************\
*           Copyright (C) 2001 Texas Instruments Incorporated.
*                           All Rights Reserved 
*------------------------------------------------------------------------------
* MODULE NAME... PLL
* FILENAME...... csl_pllhal.h 
* DATE CREATED.. Tue 10-30-2001 at 9:08:46a
* DATE MODIFIED. Fri 04-16-2004 Modified PID field default values(CLASS,TYPE).
*------------------------------------------------------------------------------
* HISTORY:
*------------------------------------------------------------------------------
* DESCRIPTION: (HAL interface file for the PLL module) 
*
* REGISTERS  
*   
*   PID        -   "PLL Controller Peripheral Identification Register"
*   PLLCSR     -   "Control Status register"                                       
*   PLLM       -   "Multiplier Control register"   (PLLM)
*   PLLDIV0    -   "PLL Divider 0 register"  
*   PLLDIV1    -   "PLL Divider 1 register"  
*   PLLDIV2    -   "PLL Divider 2 register"  
*   PLLDIV3    -   "PLL Divider 3 register"  
*   OSCDIV1    -   "Oscillator Divider 1 register"  
*
\***************************************************************************/

#ifndef  _CSL_PLLHAL_H_  
#define  _CSL_PLLHAL_H_  

/*****************************\
*   Include files        
\*****************************/
#include <csl_stdinc.h> 
#include <csl_chip.h> 

#if (PLL_SUPPORT) 
/************************************************************\
*    Misc. Declarations          
\************************************************************/

 #define   _PLL_BASE_ADDR  0x01B7C000u

/************************************************************\
*    Module level register/field access macros          
\************************************************************/

  /* ------------------- */
  /* FIELD MAKE MACROS   */
  /* ------------------- */

  #define PLL_FMK(REG,FIELD,x)\
   _PER_FMK(PLL,##REG,##FIELD,x)

  #define PLL_FMKS(REG,FIELD,SYM)\
   _PER_FMKS(PLL,##REG,##FIELD,##SYM)

  /* ---------------------------------- */
  /* RAW REGISTER/FIELD ACCESS MACROS   */
  /* ---------------------------------- */

  #define PLL_REG(REG)  (*(volatile Uint32*) (_PLL_##REG##_ADDR)) 

  #define PLL_ADDR(REG)\
   _PLL_##REG##_ADDR 

  #define PLL_RGET(REG)\
   _PER_RGET(_PLL_##REG##_ADDR,PLL,##REG)

  #define PLL_RSET(REG,x)\
   _PER_RSET(_PLL_##REG##_ADDR,PLL,##REG,x)

  #define PLL_FGET(REG,FIELD)\
   _PLL_##REG##_FGET(##FIELD) 

  #define PLL_FSET(REG,FIELD,x)\
   _PLL_##REG##_FSET(##FIELD,x) 

  #define PLL_FSETS(REG,FIELD,SYM)\
   _PLL_##REG##_FSETS(##FIELD,##SYM)

  /* -------------------------------------------- */
  /* ADDRESS BASED REGISTER/FIELD ACCESS MACROS   */
  /* -------------------------------------------- */

  #define PLL_RGETA(addr,REG)\
   _PER_RGET(addr,PLL,##REG) 

  #define PLL_RSETA(addr,REG,x)\
   _PER_RSET(addr,PLL,##REG,x)

  #define PLL_FGETA(addr,REG,FIELD)\
   _PER_FGET(addr,PLL,##REG,##FIELD)

  #define PLL_FSETA(addr,REG,FIELD,x)\
   _PER_FSET(addr,PLL,##REG,##FIELD,x)

  #define PLL_FSETSA(addr,REG,FIELD,SYM)\
   _PER_FSETS(addr,PLL,##REG,##FIELD,##SYM) 



/*******************************************************************\
*        
*  ________________  
* |                |  
* |  PID           |
* |________________| 
*
*       PID   -    "Peripheral Identification register"  
*
* FIELDS (msb -> lsb)
*   (r) TYPE
*   (r) CLASS
*   (r) REV
*
\*******************************************************************/

   #define _PLL_PID_OFFSET       0
   #define _PLL_PID_ADDR         0x01B7C000u
   #define  PLL_PID              PLL_REG(PID)      


   #define _PLL_PID_TYPE_MASK             0x00FF0000u
   #define _PLL_PID_TYPE_SHIFT            0x00000010u
   #define  PLL_PID_TYPE_DEFAULT          0x00000001u
   #define  PLL_PID_TYPE_OF(x)            _VALUEOF(x)

   #define _PLL_PID_CLASS_MASK             0x0000FF00u
   #define _PLL_PID_CLASS_SHIFT            0x00000008u
   #define  PLL_PID_CLASS_DEFAULT          0x00000008u
   #define  PLL_PID_CLASS_OF(x)            _VALUEOF(x)

   #define _PLL_PID_REV_MASK             0x000000FFu
   #define _PLL_PID_REV_SHIFT            0x00000000u
   #define  PLL_PID_REV_DEFAULT          0x00000001u
   #define  PLL_PID_REV_OF(x)            _VALUEOF(x)

   /*=============   Register DEFAULT macro ==============*/ 
   #define  PLL_PID_DEFAULT  (Uint32) (\
      _PER_FDEFAULT(PLL,PID,TYPE) \
     |_PER_FDEFAULT(PLL,PID,CLASS) \
     |_PER_FDEFAULT(PLL,PID,REV) \
   )


   /*=============   Register MAKE _RMK macro ==============*/ 

   /*=============   Register Access macros ==============*/ 
   #define _PLL_PID_FGET(FIELD)\
     _PER_FGET(_PLL_PID_ADDR,PLL,PID,##FIELD)

   #define _PLL_PID_FSET(FIELD,field)\
     _PER_FSET(_PLL_PID_ADDR,PLL,PID,##FIELD,field)

   #define _PLL_PID_FSETS(FIELD,SYM)\
     _PER_FSETS(_PLL_PID_ADDR,PLL,PID,##FIELD,##SYM)



/*******************************************************************\
*        
*  ________________  
* |                |  
* |  PLLCSR        |
* |________________| 
*
*       PLLCSR   -    "Control Status register"  
*
* FIELDS (msb -> lsb)
*   (r)  STABLE
*   (rw) PLLRST
*   (rw) PLLPWRDN
*   (rw) PLLEN
*
\*******************************************************************/

   #define _PLL_PLLCSR_OFFSET       64
   #define _PLL_PLLCSR_ADDR         (_PLL_BASE_ADDR + 0x100u)
   #define  PLL_PLLCSR              PLL_REG(PLLCSR)      


   #define _PLL_PLLCSR_STABLE_MASK             0x00000040u
   #define _PLL_PLLCSR_STABLE_SHIFT            0x00000006u
   #define  PLL_PLLCSR_STABLE_DEFAULT          0x00000001u
   #define  PLL_PLLCSR_STABLE_OF(x)            _VALUEOF(x)

   #define _PLL_PLLCSR_PLLRST_MASK             0x00000008u
   #define _PLL_PLLCSR_PLLRST_SHIFT            0x00000003u
   #define  PLL_PLLCSR_PLLRST_DEFAULT          0x00000001u
   #define  PLL_PLLCSR_PLLRST_OF(x)            _VALUEOF(x)
   #define  PLL_PLLCSR_PLLRST_1                0x00000001u
   #define  PLL_PLLCSR_PLLRST_0                0x00000000u

   #define _PLL_PLLCSR_PLLPWRDN_MASK             0x00000002u
   #define _PLL_PLLCSR_PLLPWRDN_SHIFT            0x00000001u
   #define  PLL_PLLCSR_PLLPWRDN_DEFAULT          0x00000000u
   #define  PLL_PLLCSR_PLLPWRDN_OF(x)            _VALUEOF(x)
   #define  PLL_PLLCSR_PLLPWRDN_YES             0x00000001u
   #define  PLL_PLLCSR_PLLPWRDN_NO             0x00000000u

   #define _PLL_PLLCSR_PLLEN_MASK             0x00000001u
   #define _PLL_PLLCSR_PLLEN_SHIFT            0x00000000u
   #define  PLL_PLLCSR_PLLEN_DEFAULT          0x00000000u
   #define  PLL_PLLCSR_PLLEN_OF(x)            _VALUEOF(x)
   #define  PLL_PLLCSR_PLLEN_ENABLE             0x00000001u
   #define  PLL_PLLCSR_PLLEN_BYPASS             0x00000000u

   /*=============   Register DEFAULT macro ==============*/ 
   #define  PLL_PLLCSR_DEFAULT  (Uint32) (\
      _PER_FDEFAULT(PLL,PLLCSR,STABLE) \
     |_PER_FDEFAULT(PLL,PLLCSR,PLLRST) \
     |_PER_FDEFAULT(PLL,PLLCSR,PLLPWRDN) \
     |_PER_FDEFAULT(PLL,PLLCSR,PLLEN) \
   )


   /*=============   Register MAKE _RMK macro ==============*/ 
   #define  PLL_PLLCSR_RMK(pllrst,pllpwrdn,pllen) \
 (Uint32) (\
      _PER_FMK(PLL,PLLCSR,PLLRST,pllrst) \
     |_PER_FMK(PLL,PLLCSR,PLLPWRDN,pllpwrdn) \
     |_PER_FMK(PLL,PLLCSR,PLLEN,pllen) \
   )

   /*=============   Register Access macros ==============*/ 
   #define _PLL_PLLCSR_FGET(FIELD)\
     _PER_FGET(_PLL_PLLCSR_ADDR,PLL,PLLCSR,##FIELD)

   #define _PLL_PLLCSR_FSET(FIELD,field)\
     _PER_FSET(_PLL_PLLCSR_ADDR,PLL,PLLCSR,##FIELD,field)

   #define _PLL_PLLCSR_FSETS(FIELD,SYM)\
     _PER_FSETS(_PLL_PLLCSR_ADDR,PLL,PLLCSR,##FIELD,##SYM)



/*******************************************************************\
*        
*  ________________  
* |                |  
*   PLLM   
* |________________| 
*
*       PLLM   -    "Multiplier Control register"  
*
* FIELDS (msb -> lsb)
*   (rw) PLLM
*
\*******************************************************************/

   #define _PLL_PLLM_OFFSET       68
   #define _PLL_PLLM_ADDR         (_PLL_BASE_ADDR + 0x110u) 
   #define  PLL_PLLM              PLL_REG(PLLM)      


   #define _PLL_PLLM_PLLM_MASK             0x0000001Fu
   #define _PLL_PLLM_PLLM_SHIFT            0x00000000u
   #define  PLL_PLLM_PLLM_DEFAULT          0x00000007u
   #define  PLL_PLLM_PLLM_OF(x)            _VALUEOF(x)

   /*=============   Register DEFAULT macro ==============*/ 
   #define  PLL_PLLM_DEFAULT  (Uint32) (\
     _PER_FDEFAULT(PLL,PLLM,PLLM) \
   )


   /*=============   Register MAKE _RMK macro ==============*/ 
   #define  PLL_PLLM_RMK(pllm) \
 (Uint32) (\
      _PER_FMK(PLL,PLLM,PLLM,pllm) \
   )

   /*=============   Register Access macros ==============*/ 
   #define _PLL_PLLM_FGET(FIELD)\
     _PER_FGET(_PLL_PLLM_ADDR,PLL,PLLM,##FIELD)

   #define _PLL_PLLM_FSET(FIELD,field)\
     _PER_FSET(_PLL_PLLM_ADDR,PLL,PLLM,##FIELD,field)

   #define _PLL_PLLM_FSETS(FIELD,SYM)\
     _PER_FSETS(_PLL_PLLM_ADDR,PLL,PLLM,##FIELD,##SYM)



/*******************************************************************\
*        
*  ________________  
* |                |  
* | PLLDIV0        |
* |________________| 
*
*       PLLDIV0   -    "PLL Divider 0 register"  
*
* FIELDS (msb -> lsb)
*   (rw) D0EN
*   (rw) RATIO
*
\*******************************************************************/

   #define _PLL_PLLDIV0_OFFSET       69
   #define _PLL_PLLDIV0_ADDR         (_PLL_BASE_ADDR + 0x114u) 
   #define  PLL_PLLDIV0              PLL_REG(PLLDIV0)      


   #define _PLL_PLLDIV0_D0EN_MASK             0x00008000u
   #define _PLL_PLLDIV0_D0EN_SHIFT            0x0000000Fu
   #define  PLL_PLLDIV0_D0EN_DEFAULT          0x00000001u
   #define  PLL_PLLDIV0_D0EN_OF(x)            _VALUEOF(x)
   #define  PLL_PLLDIV0_D0EN_ENABLE             0x00000001u
   #define  PLL_PLLDIV0_D0EN_DISABLE             0x00000000u

   #define _PLL_PLLDIV0_RATIO_MASK             0x0000001Fu
   #define _PLL_PLLDIV0_RATIO_SHIFT            0x00000000u
   #define  PLL_PLLDIV0_RATIO_DEFAULT          0x00000000u
   #define  PLL_PLLDIV0_RATIO_OF(x)            _VALUEOF(x)

   /*=============   Register DEFAULT macro ==============*/ 
   #define  PLL_PLLDIV0_DEFAULT  (Uint32) (\
      _PER_FDEFAULT(PLL,PLLDIV0,D0EN) \
     |_PER_FDEFAULT(PLL,PLLDIV0,RATIO) \
   )


   /*=============   Register MAKE _RMK macro ==============*/ 
   #define  PLL_PLLDIV0_RMK(d0en,ratio) \
 (Uint32) (\
      _PER_FMK(PLL,PLLDIV0,D0EN,d0en) \
     |_PER_FMK(PLL,PLLDIV0,RATIO,ratio) \
   )

   /*=============   Register Access macros ==============*/ 
   #define _PLL_PLLDIV0_FGET(FIELD)\
     _PER_FGET(_PLL_PLLDIV0_ADDR,PLL,PLLDIV0,##FIELD)

   #define _PLL_PLLDIV0_FSET(FIELD,field)\
     _PER_FSET(_PLL_PLLDIV0_ADDR,PLL,PLLDIV0,##FIELD,field)

   #define _PLL_PLLDIV0_FSETS(FIELD,SYM)\
     _PER_FSETS(_PLL_PLLDIV0_ADDR,PLL,PLLDIV0,##FIELD,##SYM)



/*******************************************************************\
*        
*  ________________  
* |                |  
* |  PLLDIV1       |
* |________________| 
*
*       PLLDIV1   -    "PLL Divider 1 register"  
*
* FIELDS (msb -> lsb)
*   (rw) D1EN
*   (rw) RATIO
*
\*******************************************************************/

   #define _PLL_PLLDIV1_OFFSET       70
   #define _PLL_PLLDIV1_ADDR         (_PLL_BASE_ADDR + 0x118u) 
   #define  PLL_PLLDIV1              PLL_REG(PLLDIV1)      


   #define _PLL_PLLDIV1_D1EN_MASK             0x00008000u
   #define _PLL_PLLDIV1_D1EN_SHIFT            0x0000000Fu
   #define  PLL_PLLDIV1_D1EN_DEFAULT          0x00000001u
   #define  PLL_PLLDIV1_D1EN_OF(x)            _VALUEOF(x)
   #define  PLL_PLLDIV1_D1EN_ENABLE             0x00000001u
   #define  PLL_PLLDIV1_D1EN_DISABLE             0x00000000u

   #define _PLL_PLLDIV1_RATIO_MASK             0x0000001Fu
   #define _PLL_PLLDIV1_RATIO_SHIFT            0x00000000u
   #define  PLL_PLLDIV1_RATIO_DEFAULT          0x00000000u
   #define  PLL_PLLDIV1_RATIO_OF(x)            _VALUEOF(x)

   /*=============   Register DEFAULT macro ==============*/ 
   #define  PLL_PLLDIV1_DEFAULT  (Uint32) (\
      _PER_FDEFAULT(PLL,PLLDIV1,D1EN) \
     |_PER_FDEFAULT(PLL,PLLDIV1,RATIO) \
   )


   /*=============   Register MAKE _RMK macro ==============*/ 
   #define  PLL_PLLDIV1_RMK(d1en,ratio) \
 (Uint32) (\
      _PER_FMK(PLL,PLLDIV1,D1EN,d1en) \
     |_PER_FMK(PLL,PLLDIV1,RATIO,ratio) \
   )

   /*=============   Register Access macros ==============*/ 
   #define _PLL_PLLDIV1_FGET(FIELD)\
     _PER_FGET(_PLL_PLLDIV1_ADDR,PLL,PLLDIV1,##FIELD)

   #define _PLL_PLLDIV1_FSET(FIELD,field)\
     _PER_FSET(_PLL_PLLDIV1_ADDR,PLL,PLLDIV1,##FIELD,field)

   #define _PLL_PLLDIV1_FSETS(FIELD,SYM)\
     _PER_FSETS(_PLL_PLLDIV1_ADDR,PLL,PLLDIV1,##FIELD,##SYM)



/*******************************************************************\
*        
*  ________________  
* |                |  
* |  PLLDIV2       |
* |________________| 
*
*       PLLDIV2   -    "PLL Divider 2 register"  
*
* FIELDS (msb -> lsb)
*   (rw) D2EN
*   (rw) RATIO
*
\*******************************************************************/

   #define _PLL_PLLDIV2_OFFSET       71
   #define _PLL_PLLDIV2_ADDR        (_PLL_BASE_ADDR + 0x11Cu) 
   #define  PLL_PLLDIV2              PLL_REG(PLLDIV2)      


   #define _PLL_PLLDIV2_D2EN_MASK             0x00008000u
   #define _PLL_PLLDIV2_D2EN_SHIFT            0x0000000Fu
   #define  PLL_PLLDIV2_D2EN_DEFAULT          0x00000001u
   #define  PLL_PLLDIV2_D2EN_OF(x)            _VALUEOF(x)
   #define  PLL_PLLDIV2_D2EN_ENABLE             0x00000001u
   #define  PLL_PLLDIV2_D2EN_DISABLE             0x00000000u

   #define _PLL_PLLDIV2_RATIO_MASK             0x0000001Fu
   #define _PLL_PLLDIV2_RATIO_SHIFT            0x00000000u
   #define  PLL_PLLDIV2_RATIO_DEFAULT          0x00000001u
   #define  PLL_PLLDIV2_RATIO_OF(x)            _VALUEOF(x)

   /*=============   Register DEFAULT macro ==============*/ 
   #define  PLL_PLLDIV2_DEFAULT  (Uint32) (\
      _PER_FDEFAULT(PLL,PLLDIV2,D2EN) \
     |_PER_FDEFAULT(PLL,PLLDIV2,RATIO) \
   )


   /*=============   Register MAKE _RMK macro ==============*/ 
   #define  PLL_PLLDIV2_RMK(d2en,ratio) \
 (Uint32) (\
      _PER_FMK(PLL,PLLDIV2,D2EN,d2en) \
     |_PER_FMK(PLL,PLLDIV2,RATIO,ratio) \
   )

   /*=============   Register Access macros ==============*/ 
   #define _PLL_PLLDIV2_FGET(FIELD)\
     _PER_FGET(_PLL_PLLDIV2_ADDR,PLL,PLLDIV2,##FIELD)

   #define _PLL_PLLDIV2_FSET(FIELD,field)\
     _PER_FSET(_PLL_PLLDIV2_ADDR,PLL,PLLDIV2,##FIELD,field)

   #define _PLL_PLLDIV2_FSETS(FIELD,SYM)\
     _PER_FSETS(_PLL_PLLDIV2_ADDR,PLL,PLLDIV2,##FIELD,##SYM)



/*******************************************************************\
*        
*  ________________  
* |                |  
* |  PLLDIV3       |
* |________________| 
*
*       PLLDIV3   -    "PLL Divider 3 register"  
*
* FIELDS (msb -> lsb)
*   (rw) D3EN
*   (rw) RATIO
*
\*******************************************************************/

   #define _PLL_PLLDIV3_OFFSET       72
   #define _PLL_PLLDIV3_ADDR         (_PLL_BASE_ADDR + 0x120u) 
   #define  PLL_PLLDIV3              PLL_REG(PLLDIV3)      


   #define _PLL_PLLDIV3_D3EN_MASK             0x00008000u
   #define _PLL_PLLDIV3_D3EN_SHIFT            0x0000000Fu
   #define  PLL_PLLDIV3_D3EN_DEFAULT          0x00000001u
   #define  PLL_PLLDIV3_D3EN_OF(x)            _VALUEOF(x)
   #define  PLL_PLLDIV3_D3EN_ENABLE             0x00000001u
   #define  PLL_PLLDIV3_D3EN_DISABLE             0x00000000u

   #define _PLL_PLLDIV3_RATIO_MASK             0x0000001Fu
   #define _PLL_PLLDIV3_RATIO_SHIFT            0x00000000u
   #define  PLL_PLLDIV3_RATIO_DEFAULT          0x00000001u
   #define  PLL_PLLDIV3_RATIO_OF(x)            _VALUEOF(x)

   /*=============   Register DEFAULT macro ==============*/ 
   #define  PLL_PLLDIV3_DEFAULT  (Uint32) (\
      _PER_FDEFAULT(PLL,PLLDIV3,D3EN) \
     |_PER_FDEFAULT(PLL,PLLDIV3,RATIO) \
   )


   /*=============   Register MAKE _RMK macro ==============*/ 
   #define  PLL_PLLDIV3_RMK(d3en,ratio) \
 (Uint32) (\
      _PER_FMK(PLL,PLLDIV3,D3EN,d3en) \
     |_PER_FMK(PLL,PLLDIV3,RATIO,ratio) \
   )

   /*=============   Register Access macros ==============*/ 
   #define _PLL_PLLDIV3_FGET(FIELD)\
     _PER_FGET(_PLL_PLLDIV3_ADDR,PLL,PLLDIV3,##FIELD)

   #define _PLL_PLLDIV3_FSET(FIELD,field)\
     _PER_FSET(_PLL_PLLDIV3_ADDR,PLL,PLLDIV3,##FIELD,field)

   #define _PLL_PLLDIV3_FSETS(FIELD,SYM)\
     _PER_FSETS(_PLL_PLLDIV3_ADDR,PLL,PLLDIV3,##FIELD,##SYM)



/*******************************************************************\
*        
*  ________________  
* |                |  
* |  OSCDIV1       |
* |________________| 
*
*       OSCDIV1   -    "Oscillator Divider 1 register"  
*
* FIELDS (msb -> lsb)
*   (rw) OD1EN
*   (rw) RATIO
*
\*******************************************************************/

   #define _PLL_OSCDIV1_OFFSET       73
   #define _PLL_OSCDIV1_ADDR         (_PLL_BASE_ADDR + 0x124u) 

   #define  PLL_OSCDIV1              PLL_REG(OSCDIV1)      


   #define _PLL_OSCDIV1_OD1EN_MASK             0x00008000u
   #define _PLL_OSCDIV1_OD1EN_SHIFT            0x0000000Fu
   #define  PLL_OSCDIV1_OD1EN_DEFAULT          0x00000001u
   #define  PLL_OSCDIV1_OD1EN_OF(x)            _VALUEOF(x)
   #define  PLL_OSCDIV1_OD1EN_ENABLE             0x00000001u
   #define  PLL_OSCDIV1_OD1EN_DISABLE             0x00000000u

   #define _PLL_OSCDIV1_RATIO_MASK             0x0000001Fu
   #define _PLL_OSCDIV1_RATIO_SHIFT            0x00000000u
   #define  PLL_OSCDIV1_RATIO_DEFAULT          0x00000007u
   #define  PLL_OSCDIV1_RATIO_OF(x)            _VALUEOF(x)

   /*=============   Register DEFAULT macro ==============*/ 
   #define  PLL_OSCDIV1_DEFAULT  (Uint32) (\
      _PER_FDEFAULT(PLL,OSCDIV1,OD1EN) \
     |_PER_FDEFAULT(PLL,OSCDIV1,RATIO) \
   )


   /*=============   Register MAKE _RMK macro ==============*/ 
   #define  PLL_OSCDIV1_RMK(od1en,ratio) \
 (Uint32) (\
      _PER_FMK(PLL,OSCDIV1,OD1EN,od1en) \
     |_PER_FMK(PLL,OSCDIV1,RATIO,ratio) \
   )

   /*=============   Register Access macros ==============*/ 
   #define _PLL_OSCDIV1_FGET(FIELD)\
     _PER_FGET(_PLL_OSCDIV1_ADDR,PLL,OSCDIV1,##FIELD)

   #define _PLL_OSCDIV1_FSET(FIELD,field)\
     _PER_FSET(_PLL_OSCDIV1_ADDR,PLL,OSCDIV1,##FIELD,field)

   #define _PLL_OSCDIV1_FSETS(FIELD,SYM)\
     _PER_FSETS(_PLL_OSCDIV1_ADDR,PLL,OSCDIV1,##FIELD,##SYM)



/*******************************************************************\
*        
*  ________________  
* |                |  
*   WAKEUP   
* |________________| 
*
*       WAKEUP   -    "Wakeup register"   Not Documented
*
* FIELDS (msb -> lsb)
*   (rw) WKEN
*
\*******************************************************************/

   #define _PLL_WAKEUP_OFFSET       76
   #define _PLL_WAKEUP_ADDR         (_PLL_BASE_ADDR + 0x130u) 
   #define  PLL_WAKEUP              PLL_REG(WAKEUP)      


   #define _PLL_WAKEUP_WKEN_MASK             0xFFFFFFFFu
   #define _PLL_WAKEUP_WKEN_SHIFT            0x00000000u
   #define  PLL_WAKEUP_WKEN_DEFAULT          0x00000000u
   #define  PLL_WAKEUP_WKEN_OF(x)            _VALUEOF(x)
   #define  PLL_WAKEUP_WKEN_ENABLE           0x00000001u
   #define  PLL_WAKEUP_WKEN_DISABLE          0x00000000u

   /*=============   Register DEFAULT macro ==============*/ 
   #define  PLL_WAKEUP_DEFAULT  (Uint32) (\
     _PER_FDEFAULT(PLL,WAKEUP,WKEN) \
   )


   /*=============   Register MAKE _RMK macro ==============*/ 
   #define  PLL_WAKEUP_RMK(wken) \
 (Uint32) (\
      _PER_FMK(PLL,WAKEUP,WKEN,wken) \
   )

   /*=============   Register Access macros ==============*/ 
   #define _PLL_WAKEUP_FGET(FIELD)\
     _PER_FGET(_PLL_WAKEUP_ADDR,PLL,WAKEUP,##FIELD)

   #define _PLL_WAKEUP_FSET(FIELD,field)\
     _PER_FSET(_PLL_WAKEUP_ADDR,PLL,WAKEUP,##FIELD,field)

   #define _PLL_WAKEUP_FSETS(FIELD,SYM)\
     _PER_FSETS(_PLL_WAKEUP_ADDR,PLL,WAKEUP,##FIELD,##SYM)



/*******************************************************************\
*        
*  ________________  
* |                |  
*   CLK3SEL   
* |________________| 
*
*       CLK3SEL   -    "Clkout3 Select register"   Not Documented
*
* FIELDS (msb -> lsb)
*   (rw) CK3SEL
*
\*******************************************************************/

   #define _PLL_CLK3SEL_OFFSET       65
   #define _PLL_CLK3SEL_ADDR        (_PLL_BASE_ADDR + 0x104u) 
   #define  PLL_CLK3SEL              PLL_REG(CLK3SEL)      


   #define _PLL_CLK3SEL_CK3SEL_MASK             0x0000000Fu
   #define _PLL_CLK3SEL_CK3SEL_SHIFT            0x00000000u
   #define  PLL_CLK3SEL_CK3SEL_DEFAULT          0x00000000u
   #define  PLL_CLK3SEL_CK3SEL_OF(x)            _VALUEOF(x)
   #define  PLL_CLK3SEL_CK3SEL_DISABLED             0x00000008u
   #define  PLL_CLK3SEL_CK3SEL_PTA             0x00000009u
   #define  PLL_CLK3SEL_CK3SEL_PTB             0x0000000Au
   #define  PLL_CLK3SEL_CK3SEL_PTC             0x0000000Bu
   #define  PLL_CLK3SEL_CK3SEL_PTD             0x0000000Cu
   #define  PLL_CLK3SEL_CK3SEL_PTE             0x0000000Du
   #define  PLL_CLK3SEL_CK3SEL_PTF             0x0000000Eu
   #define  PLL_CLK3SEL_CK3SEL_PTG             0x0000000Fu

   /*=============   Register DEFAULT macro ==============*/ 
   #define  PLL_CLK3SEL_DEFAULT  (Uint32) (\
     _PER_FDEFAULT(PLL,CLK3SEL,CK3SEL) \
   )


   /*=============   Register MAKE _RMK macro ==============*/ 
   #define  PLL_CLK3SEL_RMK(ck3sel) \
 (Uint32) (\
      _PER_FMK(PLL,CLK3SEL,CK3SEL,ck3sel) \
   )

   /*=============   Register Access macros ==============*/ 
   #define _PLL_CLK3SEL_FGET(FIELD)\
     _PER_FGET(_PLL_CLK3SEL_ADDR,PLL,CLK3SEL,##FIELD)

   #define _PLL_CLK3SEL_FSET(FIELD,field)\
     _PER_FSET(_PLL_CLK3SEL_ADDR,PLL,CLK3SEL,##FIELD,field)

   #define _PLL_CLK3SEL_FSETS(FIELD,SYM)\
     _PER_FSETS(_PLL_CLK3SEL_ADDR,PLL,CLK3SEL,##FIELD,##SYM)


/*----------------------------------------------------------------------*/
#endif /* PLL_SUPPORT */
#endif /* _PLLHAL_H */ 
/*******************************************************************\
*      End of file            
\*******************************************************************/
