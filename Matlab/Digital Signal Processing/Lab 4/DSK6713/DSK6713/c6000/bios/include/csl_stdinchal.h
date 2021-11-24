/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_stdinchal.h
* DATE CREATED.. 03/11/1999 
* LAST MODIFIED. 03/23/2001
\******************************************************************************/
#ifndef _CSL_STDINCHAL_H_
#define _CSL_STDINCHAL_H_


/******************************************************************************\
* HAL macro definitions
\******************************************************************************/

  #define _VALUEOF(x) ((Uint32)(x))

  /*******************************************************/
  /* generic macros for field manipulation               */
  /*******************************************************/

  #define _PER_FSHIFT(PER,REG,FIELD) \
    _##PER##_##REG##_##FIELD##_SHIFT

  #define _PER_FMASK(PER,REG,FIELD) \
    _##PER##_##REG##_##FIELD##_MASK

  #define _PER_FSYM(PER,REG,FIELD,SYM)\
    PER##_##REG##_##FIELD##_##SYM

  #define _PER_FDEFAULT(PER,REG,FIELD) \
    ((##PER##_##REG##_##FIELD##_DEFAULT << _##PER##_##REG##_##FIELD##_SHIFT) \
    & _##PER##_##REG##_##FIELD##_MASK)

  #define _PER_FMK(PER,REG,FIELD,x) (\
    (((Uint32)(x))<<_PER_FSHIFT(##PER,##REG,##FIELD))\
    &_PER_FMASK(##PER,##REG,##FIELD)\
  )

  #define _PER_FMKS(PER,REG,FIELD,SYM) (\
    (_PER_FSYM(##PER,##REG,##FIELD,##SYM)<<_PER_FSHIFT(##PER,##REG,##FIELD))\
    &_PER_FMASK(##PER,##REG,##FIELD)\
  )

  #define _PER_FEXTRACT(PER,REG,FIELD,reg) (Uint32)(\
    (((Uint32)(reg)&_PER_FMASK(##PER,##REG,##FIELD))\
    >>_PER_FSHIFT(##PER,##REG,##FIELD))\
  )

  #define _PER_FINSERT(PER,REG,FIELD,reg,field) (Uint32)(\
    (((Uint32)(reg)&~_PER_FMASK(##PER,##REG,##FIELD))|\
    (((Uint32)(field)<<_PER_FSHIFT(##PER,##REG,##FIELD))\
    &_PER_FMASK(##PER,##REG,##FIELD)))\
  )

  /*******************************************************/
  /* macros for memmory mapped registers                 */
  /*******************************************************/

  #define _PER_RAOI(addr,PER,REG,and,or,inv)\
    (*(volatile Uint32*)(addr))=(\
      ((((*(volatile Uint32*)(addr))\
      &((Uint32)(and)))\
      |((Uint32)(or)))\
      ^((Uint32)(inv)))\
    )

  #define _PER_RGET(addr,PER,REG) \
    (*(volatile Uint32*)(addr))

  #define _PER_RSET(addr,PER,REG,x) \
    (*(volatile Uint32*)(addr))=((Uint32)(x))

  #define _PER_FGET(addr,PER,REG,FIELD) \
    _PER_FEXTRACT(##PER,##REG,##FIELD,_PER_RGET(addr,##PER,##REG))

  #define _PER_FSET(addr,PER,REG,FIELD,field)\
    _PER_RSET(addr,##PER,##REG,\
    _PER_FINSERT(##PER,##REG,##FIELD,_PER_RGET(addr,##PER,##REG),field))

  #define _PER_FSETS(addr,PER,REG,FIELD,SYM)\
    _PER_RSET(addr,##PER,##REG,_PER_FINSERT(##PER,##REG,##FIELD,_PER_RGET(addr,##PER,##REG),\
    _PER_FSYM(##PER,##REG,##FIELD,##SYM)))

  /*******************************************************/
  /* macros for CPU control registers                    */
  /*******************************************************/

  #define _PER_CRGET(PER,REG) \
    REG

  #define _PER_CRSET(PER,REG,reg) \
    REG=((Uint32)(reg))

  #define _PER_CFGET(PER,REG,FIELD) \
    _PER_FEXTRACT(##PER,##REG,##FIELD,_PER_CRGET(##PER,##REG))

  #define _PER_CFSET(PER,REG,FIELD,field)\
    _PER_CRSET(##PER,##REG,\
    _PER_FINSERT(##PER,##REG,##FIELD,_PER_CRGET(##PER,##REG),field))

  #define _PER_CFSETS(PER,REG,FIELD,SYM)\
    _PER_CRSET(##PER,##REG,\
    _PER_FINSERT(##PER,##REG,FIELD,_PER_CRGET(##PER,##REG),\
    _PER_FSYM(##PER,##REG,##FIELD,##SYM)))

/*----------------------------------------------------------------------------*/

#endif /* _CSL_STDINCHAL_H_ */
/******************************************************************************\
* End of csl_stdinchal.h
\******************************************************************************/

