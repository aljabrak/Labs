/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_i2c.h
* DATE CREATED.. 06/11/1999 
* LAST MODIFIED. 08/02/2004 - Adding support for C6418
*                13/03/2002 - added I2C_outOfReset()
*                01/08/2003 - Removing unused variable 'I2C_isrDispatchTable[6]'
\******************************************************************************/
#ifndef _CSL_I2C_H_
#define _CSL_I2C_H_

#include <csl_chip.h>
#include <csl_irq.h>
#include <csl_i2chal.h>


/* defining i2cimr as i2cier for backward compatibility */

#define i2cimr i2cier

#if (I2C_SUPPORT)
/******************************************************************************\
* scope and inline control macros
\******************************************************************************/
#ifdef __cplusplus
#define CSLAPI extern "C" far
#else
#define CSLAPI extern far
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _I2C_MOD_
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
* global macro declarations
\******************************************************************************/

/* I2C_open() flags */
#define I2C_OPEN_RESET     (0x00000001)

/* device identifiers for I2C_open() */

#if (CHIP_6713 | CHIP_DA610 | CHIP_6413 | CHIP_6418 | CHIP_6410)
  #define I2C_DEV0           (0)
  #define I2C_DEV1           (1)
#endif

#if (CHIP_DM642 | CHIP_DM641 | CHIP_DM640 | CHIP_6412)
  #define I2C_DEV0           (0)
#endif

/* device identifiers for I2C_open() */

#if (CHIP_6713 | CHIP_DA610 | CHIP_6413 | CHIP_6418 | CHIP_6410)
  #define I2C_PORT0          I2C_DEV0
  #define I2C_PORT1          I2C_DEV1
#endif

#if (CHIP_DM642 | CHIP_DM641 | CHIP_DM640 | CHIP_6412)
  #define I2C_PORT0           I2C_DEV0
#endif

/* error codes */
#define I2C_ERR_ALLOC	        (0x00000000) 
#define I2C_ERR_INVALID_HANDLE  (0x00000001) 

#define I2C_EVT_AL      0x01     // Arbitration win/lose
#define I2C_EVT_NACK    0x02     // No acknowledgement 
#define I2C_EVT_ARDY    0x03     // register access ready
#define I2C_EVT_ICRRDY  0x04     // receive data ready
#define I2C_EVT_ICXRDY  0x05     // transmit data ready

#if (CHIP_6413 | CHIP_6418 | CHIP_6410)
  #define I2C_EVT_SCD     0x06     // stop condition detect 
  #define I2C_EVT_AAS     0x07     // address as slave
#endif

/******************************************************************************\
* global typedef declarations
\******************************************************************************/

/* device handle object */
typedef struct {
  Uint32 allocated;
  Uint32 eventId;
  volatile Uint32 *baseAddr;
  Uint32 i2cdrrAddr;
  Uint32 i2cdxrAddr;
} I2C_Obj, *I2C_Handle;

/* device configuration structure */
typedef struct {
	Uint32 i2coar;
	Uint32 i2cier;
	Uint32 i2cclkl;
	Uint32 i2cclkh;
	Uint32 i2ccnt;
	Uint32 i2csar;
	Uint32 i2cmdr;
	Uint32 i2cpsc;
#if (CHIP_6413 | CHIP_6418 | CHIP_6410)
        Uint32 i2cemdr;
        Uint32 i2cpfunc;
        Uint32 i2cpdir;
#endif    
} I2C_Config;

typedef struct {
	Uint32 addrmode;        /* 7 or 10 bit address mode */
	Uint32 ownaddr;         /* don't care if master */
	Uint32 sysinclock;      /* clkout value (Mhz)  */
	Uint32 rate;            /* a number between 10 and 400 in kbps*/
	Uint32 bitbyte;         /* number of bits/byte to be received or transmitted */
	Uint32 dlb;             /* digital loopback mode */
	Uint32 free;	        /* free mode */
} I2C_Init;


/******************************************************************************\
* global variable declarations
\******************************************************************************/

/******************************************************************************\
* global function declarations
\******************************************************************************/
CSLAPI void I2C_reset(I2C_Handle hI2c);
CSLAPI void I2C_resetAll();
CSLAPI I2C_Handle I2C_open(int devNum, Uint32 flags);
CSLAPI void I2C_close(I2C_Handle hI2c);
//CSLAPI void I2C_init(I2C_Init *init);

/******************************************************************************\
* inline function declarations
\******************************************************************************/
IDECL Uint32 I2C_getXmtAddr(I2C_Handle hI2c);
IDECL Uint32 I2C_getRcvAddr(I2C_Handle hI2c);
IDECL Uint32 I2C_getEventId(I2C_Handle hI2c);
IDECL Uint32 I2C_rfull(I2C_Handle hI2c);
IDECL Uint32 I2C_rrdy(I2C_Handle hI2c);
IDECL Uint32 I2C_xempty(I2C_Handle hI2c);
IDECL Uint32 I2C_xrdy(I2C_Handle hI2c);
IDECL Uint32 I2C_bb(I2C_Handle hI2c);

IDECL void I2C_writeByte(I2C_Handle hI2c, Uint8 val);
IDECL Uint8 I2C_readByte(I2C_Handle hI2c);

IDECL void I2C_sendStop(I2C_Handle hI2c);
IDECL void I2C_start(I2C_Handle hI2c);
IDECL void I2C_outOfReset(I2C_Handle hI2c);

IDECL Uint32 I2C_intClear(I2C_Handle hI2c);
IDECL void I2C_intClearAll(I2C_Handle hI2c);
IDECL void I2C_intEvtEnable(I2C_Handle hI2c,Uint32 maskFlag);
IDECL void I2C_intEvtDisable(I2C_Handle hI2c,Uint32 unmaskFlag);

IDECL void I2C_config(I2C_Handle hI2c,I2C_Config *config);

#if (CHIP_6413 | CHIP_6418 | CHIP_6410)
  IDECL void I2C_configArgs(I2C_Handle hI2c,Uint32 i2coar,Uint32 i2cier,Uint32 i2cclkl,
                            Uint32 i2cclkh,Uint32 i2ccnt,Uint32 i2csar,Uint32 i2cmdr,
                            Uint32 i2cpsc,Uint32 i2cemdr,Uint32 i2cpfunc,Uint32 i2cpdir);
#else
  IDECL void I2C_configArgs(I2C_Handle hI2c,Uint32 i2coar,Uint32 i2cier,Uint32 i2cclkl,
                            Uint32 i2cclkh,Uint32 i2ccnt,Uint32 i2csar,Uint32 i2cmdr,
                            Uint32 i2cpsc);

#endif
IDECL void I2C_getConfig(I2C_Handle hI2c,I2C_Config *config);


/******************************************************************************\
* inline function definitions
\******************************************************************************/
#ifdef USEDEFS
#if (CHIP_6413 | CHIP_6418 | CHIP_6410)
/*----------------------------------------------------------------------------*/
IDEF Uint32 I2C_getPins(I2C_Handle hI2c) {
    return I2C_RGETH(hI2c,I2CPDIN);
}
/*----------------------------------------------------------------------------*/
IDEF void I2C_setPins(I2C_Handle hI2c,Uint32 pins) {
    I2C_RSETH(hI2c,I2CPDSET,
        (
          I2C_FMK(I2CPDSET, SCLOUT, pins>>_I2C_I2CPDSET_SCLOUT_SHIFT)
         |I2C_FMK(I2CPDSET, SDAOUT, pins>>_I2C_I2CPDSET_SDAOUT_SHIFT)
        )
    );        
}
IDEF void I2C_clearPins(I2C_Handle hI2c,Uint32 pins) {
    I2C_RSETH(hI2c,I2CPDCLR,
        (
          I2C_FMK(I2CPDCLR, SCLOUT, pins>>_I2C_I2CPDCLR_SCLOUT_SHIFT)
         |I2C_FMK(I2CPDCLR, SDAOUT, pins>>_I2C_I2CPDCLR_SDAOUT_SHIFT)
        )
    );        
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 I2C_getExtMode(I2C_Handle hI2C) {
    return I2C_FGETH(hI2C,I2CEMDR,XRDYM);
}
/*----------------------------------------------------------------------------*/
IDEF void I2C_setMstAck(I2C_Handle hI2C) {
    I2C_FSETSH(hI2C,I2CEMDR,XRDYM,MSTACK);
}
/*----------------------------------------------------------------------------*/
IDEF void I2C_setDxrCpy(I2C_Handle hI2C) {
    I2C_FSETSH(hI2C,I2CEMDR,XRDYM,DXRCPY);
}
#endif
/*----------------------------------------------------------------------------*/
IDEF Uint32 I2C_getXmtAddr(I2C_Handle hI2c) {
  return (Uint32)(hI2c->i2cdxrAddr);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 I2C_getRcvAddr(I2C_Handle hI2c) {
  return (Uint32)(hI2c->i2cdrrAddr);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 I2C_getEventId(I2C_Handle hI2c) {
  return (Uint32)(hI2c->eventId);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 I2C_rfull(I2C_Handle hI2c){
 return	I2C_FGETH(hI2c,I2CSTR,RSFULL);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 I2C_rrdy(I2C_Handle hI2c){
 return	I2C_FGETH(hI2c,I2CSTR,ICRRDY);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 I2C_xempty(I2C_Handle hI2c){
 return I2C_FGETH(hI2c,I2CSTR,XSMT);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 I2C_xrdy(I2C_Handle hI2c){
 return	I2C_FGETH(hI2c,I2CSTR,ICXRDY);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 I2C_bb(I2C_Handle hI2c){
 return	I2C_FGETH(hI2c,I2CSTR,BB);
}
/*----------------------------------------------------------------------------*/
IDEF Uint8 I2C_readByte(I2C_Handle hI2c) {
  return (*(volatile Uint8 *)(hI2c->i2cdrrAddr));
}
/*----------------------------------------------------------------------------*/
IDEF void I2C_writeByte(I2C_Handle hI2c, Uint8 val) {
  (*(volatile Uint8 *)(hI2c->i2cdxrAddr)) = val;
}
/*----------------------------------------------------------------------------*/
IDEF void I2C_sendStop(I2C_Handle hI2c){
 	I2C_FSETSH(hI2c,I2CMDR,STP,STOP);
}
/*----------------------------------------------------------------------------*/
IDEF void I2C_start(I2C_Handle hI2c){
	I2C_FSETSH(hI2c,I2CMDR,STT,START);
}
/*----------------------------------------------------------------------------*/
IDEF void I2C_outOfReset(I2C_Handle hI2c){
	I2C_FSETSH(hI2c,I2CMDR,IRS,NRST);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 I2C_intClear(I2C_Handle hI2c){
    return I2C_RGETH(hI2c,I2CISRC);
}
/*----------------------------------------------------------------------------*/
IDEF void I2C_intClearAll(I2C_Handle hI2c){
   Uint32 x=I2C_RGETH(hI2c,I2CISRC);
    while(x != 0) { x=I2C_RGETH(hI2c,I2CISRC); }
}
/*----------------------------------------------------------------------------*/
IDEF void I2C_intEvtEnable(I2C_Handle hI2c,Uint32 maskFlag){

    Uint32 newMask;

	newMask = I2C_RGETH(hI2c,I2CIER) | maskFlag;
	I2C_RSETH(hI2c,I2CIER,newMask);
	IRQ_enable(hI2c->eventId);

}
/*----------------------------------------------------------------------------*/
IDEF void I2C_intEvtDisable(I2C_Handle hI2c,Uint32 unmaskFlag){

	Uint32 newMask;

	newMask = I2C_RGETH(hI2c,I2CIER) & unmaskFlag;
	I2C_RSETH(hI2c,I2CIER,newMask);

    #if (CHIP_6410 | CHIP_6413| CHIP_6418 )
	if(!(I2C_RGETH(hI2c,I2CIER) & 0x0000007F))
    #else
	if(!(I2C_RGETH(hI2c,I2CIER) & 0x0000001F))
    #endif
		IRQ_disable(hI2c->eventId);
}
/*----------------------------------------------------------------------------*/

IDEF void I2C_config(I2C_Handle hI2c, I2C_Config *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hI2c->baseAddr);
  register int x0,x1,x2,x3,x4,x5,x6,x7;
#if (CHIP_6413 | CHIP_6418 | CHIP_6410)
  register int x8,x9,x10;
#endif

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */
  x0 = config->i2coar;
  x1 = config->i2cier;
  x2 = config->i2cclkl;
  x3 = config->i2cclkh;
  x4 = config->i2ccnt;
  x5 = config->i2csar;
  x6 = config->i2cpsc;
  x7 = config->i2cmdr;
#if (CHIP_6413 | CHIP_6418 | CHIP_6410)
  x8 = config->i2cemdr;
  x9 = config->i2cpfunc;
  x10 = config->i2cpdir;
#endif  

  base[_I2C_I2COAR_OFFSET]   = x0;
  base[_I2C_I2CIER_OFFSET]   = x1;
  base[_I2C_I2CCLKL_OFFSET]  = x2;
  base[_I2C_I2CCLKH_OFFSET]  = x3;
  base[_I2C_I2CCNT_OFFSET]   = x4;
  base[_I2C_I2CSAR_OFFSET]   = x5;
  base[_I2C_I2CPSC_OFFSET]   = x6;
  base[_I2C_I2CMDR_OFFSET]   = x7;
#if (CHIP_6413 | CHIP_6418 | CHIP_6410)
  base[_I2C_I2CEMDR_OFFSET]  = x8;
  base[_I2C_I2CPFUNC_OFFSET] = x9;
  base[_I2C_I2CPDIR_OFFSET]  = x10;
#endif

  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
#if (CHIP_6413 | CHIP_6418 | CHIP_6410)
IDEF void I2C_configArgs(I2C_Handle hI2c,Uint32 i2coar,Uint32 i2cier,Uint32 i2cclkl,
                         Uint32 i2cclkh,Uint32 i2ccnt,Uint32 i2csar,Uint32 i2cmdr,
                         Uint32 i2cpsc,Uint32 i2cemdr,Uint32 i2cpfunc,Uint32 i2cpdir){

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hI2c->baseAddr);

  gie = IRQ_globalDisable();

  base[_I2C_I2COAR_OFFSET]   = i2coar;
  base[_I2C_I2CIER_OFFSET]   = i2cier;
  base[_I2C_I2CCLKL_OFFSET]  = i2cclkl;
  base[_I2C_I2CCLKH_OFFSET]  = i2cclkh;
  base[_I2C_I2CCNT_OFFSET]   = i2ccnt;
  base[_I2C_I2CSAR_OFFSET]   = i2csar;
  base[_I2C_I2CPSC_OFFSET]   = i2cpsc;
  base[_I2C_I2CMDR_OFFSET]   = i2cmdr;
  base[_I2C_I2CEMDR_OFFSET]  = i2cemdr;
  base[_I2C_I2CPFUNC_OFFSET] = i2cpfunc;
  base[_I2C_I2CPDIR_OFFSET]  = i2cpdir;

  IRQ_globalRestore(gie);
}
#else
IDEF void I2C_configArgs(I2C_Handle hI2c,Uint32 i2coar,Uint32 i2cier,
Uint32 i2cclkl,Uint32 i2cclkh,Uint32 i2ccnt,Uint32 i2csar,
Uint32 i2cmdr,Uint32 i2cpsc){

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hI2c->baseAddr);

  gie = IRQ_globalDisable();

  base[_I2C_I2COAR_OFFSET]  = i2coar;
  base[_I2C_I2CIER_OFFSET]  = i2cier;
  base[_I2C_I2CCLKL_OFFSET] = i2cclkl;
  base[_I2C_I2CCLKH_OFFSET] = i2cclkh;
  base[_I2C_I2CCNT_OFFSET]  = i2ccnt;
  base[_I2C_I2CSAR_OFFSET]  = i2csar;
  base[_I2C_I2CPSC_OFFSET]  = i2cpsc;
  base[_I2C_I2CMDR_OFFSET]  = i2cmdr;

  IRQ_globalRestore(gie);
}
#endif
/*----------------------------------------------------------------------------*/
#if (CHIP_6413 | CHIP_6418 | CHIP_6410)
IDEF void I2C_getConfig(I2C_Handle hI2c, I2C_Config *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hI2c->baseAddr);
  register int x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */

  x0 = base[_I2C_I2COAR_OFFSET];
  x1 = base[_I2C_I2CIER_OFFSET];
  x2 = base[_I2C_I2CCLKL_OFFSET];
  x3 = base[_I2C_I2CCLKH_OFFSET];
  x4 = base[_I2C_I2CCNT_OFFSET];
  x5 = base[_I2C_I2CSAR_OFFSET];
  x6 = base[_I2C_I2CMDR_OFFSET];
  x7 = base[_I2C_I2CPSC_OFFSET];
  x8 = base[_I2C_I2CEMDR_OFFSET];
  x9 = base[_I2C_I2CPFUNC_OFFSET];
  x10 = base[_I2C_I2CPDIR_OFFSET];

  config->i2coar   = x0;
  config->i2cier   = x1;
  config->i2cclkl  = x2;
  config->i2cclkh  = x3;
  config->i2ccnt   = x4;
  config->i2csar   = x5;
  config->i2cmdr   = x6;
  config->i2cpsc   = x7;
  config->i2cemdr  = x8;
  config->i2cpfunc = x9;
  config->i2cpdir  = x10;

  IRQ_globalRestore(gie);
}
#else
IDEF void I2C_getConfig(I2C_Handle hI2c, I2C_Config *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hI2c->baseAddr);
  register int x0,x1,x2,x3,x4,x5,x6,x7;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */

  x0 = base[_I2C_I2COAR_OFFSET];
  x1 = base[_I2C_I2CIER_OFFSET];
  x2 = base[_I2C_I2CCLKL_OFFSET];
  x3 = base[_I2C_I2CCLKH_OFFSET];
  x4 = base[_I2C_I2CCNT_OFFSET];
  x5 = base[_I2C_I2CSAR_OFFSET];
  x6 = base[_I2C_I2CMDR_OFFSET];
  x7 = base[_I2C_I2CPSC_OFFSET];

  config->i2coar  = x0;
  config->i2cier  = x1;
  config->i2cclkl = x2;
  config->i2cclkh = x3;
  config->i2ccnt  = x4;
  config->i2csar  = x5;
  config->i2cmdr  = x6;
  config->i2cpsc  = x7;

  IRQ_globalRestore(gie);
}
#endif
/*----------------------------------------------------------------------------*/
#endif /* USEDEFS */


#endif /* I2C_SUPPORT */
#endif /* _CSL_I2C_H_ */
/******************************************************************************\
* End of csl_i2c.h
\******************************************************************************/

