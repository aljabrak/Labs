/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.90.270 01-08-04 (bios,dsk6713-c04)" */
/*
 *  ======== volume.h ========
 *
 */

#ifndef __VOLUME_H
#define __VOLUME_H

#ifndef TRUE
#define TRUE 1
#endif

#define BUFSIZE 0x64

#define FRAMESPERBUFFER 10

#define MINGAIN 1
#define MAXGAIN 10

#define MINCONTROL 0
#define MAXCONTROL 2000

#define BASELOAD 1

#define PERCENT 100.0
#define MULTIPLYFACTOR 1000 /* multiplication factor used in load.asm */

#ifdef _DSK67_
LgUns mips = 1500000;
Uns sliderMaxValue = 1400;
#endif

#ifdef _DSK62_
LgUns mips = 1500000;
Uns sliderMaxValue = 1400;
#endif

#ifdef _DSK54_  /* for dsk5402 */
LgUns mips = 1000000;
Uns sliderMaxValue = 900;
#endif

#ifdef _DSK5416_  
LgUns mips = 1600000;
Uns sliderMaxValue = 900;
#endif

#ifdef _EVM55_  
LgUns mips = 1400000;
Uns sliderMaxValue = 1800;
#endif

#ifdef _C5509_  
LgUns mips = 1400000;
Uns sliderMaxValue = 1800;
#endif

#ifdef _C5502_  
LgUns mips = 1400000;
Uns sliderMaxValue = 1800;
#endif

#ifdef _ELVIS55_  
LgUns mips = 1400000;
Uns sliderMaxValue = 1800;
#endif

#ifdef _OMAP1510_  
LgUns mips = 120000;
Uns sliderMaxValue = 900;
#endif

#ifdef _EVM62_  
LgUns mips = 1330000;
Uns sliderMaxValue = 2000;
#endif

#ifdef _c5561_  
LgUns mips = 600000;
Uns sliderMaxValue = 900;
#endif

#ifdef _DSK6416_	  
LgUns mips = 6000000;
Uns sliderMaxValue = 2000;
#endif

#ifdef _TEB6416_	  
LgUns mips = 5000000;
Uns sliderMaxValue = 2000;
#endif

#ifdef _DM642_
LgUns mips = 6000000;
Uns sliderMaxValue = 2000;
#endif

#ifdef _DSK6713_	  
LgUns mips = 2250000;
Uns sliderMaxValue = 2000;
#endif

#ifdef _SIM54_  
LgUns mips = 1000000;
Uns sliderMaxValue = 900;
#endif

#ifdef _SIM55_  
LgUns mips = 1400000;
Uns sliderMaxValue = 1800;
#endif

#ifdef _SIM62_  
LgUns mips = 1330000;
Uns sliderMaxValue = 2000;
#endif

#ifdef _SIM64_  
LgUns mips = 6000000;
Uns sliderMaxValue = 2000;
#endif

#ifdef _SIM67_  
LgUns mips = 500000;
Uns sliderMaxValue = 2000;
#endif

#ifdef _DSK2812_  
LgUns mips = 1400000;
Uns sliderMaxValue = 900;
#endif



#endif /* __VOLUME_H */
