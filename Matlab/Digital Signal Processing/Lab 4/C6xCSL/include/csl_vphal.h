/******************************************************************************\
*           Copyright (C) 2002-2004 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_vphal.h
* DATE CREATED.. 12/06/2001 
*                updated for version 1.3.............01/10/2002
* LAST MODIFIED. 08/12/2004  Fixed defintion error in  _VP_VDIMGOFFxx_ADDR              
*                02/28/2002
*
*------------------------------------------------------------------------------
* REGISTERS
********************************************************************************
* Memory Mapping Register -- Global
*
* VPPID0       -  Video Port 0 Peripheral Identification Register
* VPPID1       -  Video Port 1 Peripheral Identification Register
* VPPID2       -  Video Port 2 Peripheral Identification Register
* PCR0         -  Video Port 0 Peripheral Control                    
* PCR1         -  Video Port 1 Peripheral Control
* PCR2         -  Video Port 2 Peripheral Control
* PFUNC0       -  Video Port 0 Pin Function
* PFUNC1       -  Video Port 1 Pin Function
* PFUNC2       -  Video Port 2 Pin Function
* PDIR0        -  Video Port 0 Pin Direction
* PDIR1        -  Video Port 1 Pin Direction
* PDIR2        -  Video Port 2 Pin Direction
* PDIN0        -  Video Port 0 Pin Data In
* PDIN1        -  Video Port 1 Pin Data In
* PDIN2        -  Video Port 2 Pin Data In
* PDOUT0       -  Video Port 0 Pin Data Out
* PDOUT1       -  Video Port 1 Pin Data Out
* PDOUT2       -  Video Port 2 Pin Data Out
* PDSET0       -  Video Port 0 Pin Data Set
* PDSET1       -  Video Port 1 Pin Data Set
* PDSET2       -  Video Port 2 Pin Data Set
* PDCLR0       -  Video Port 0 Pin Data Clear
* PDCLR1       -  Video Port 1 Pin Data Clear
* PDCLR2       -  Video Port 2 Pin Data Clear
* PIEN0        -  Video Port 0 Pin Interrupt Enable
* PIEN1        -  Video Port 1 Pin Interrupt Enable
* PIEN2        -  Video Port 2 Pin Interrupt Enable
* PIPOL0       -  Video Port 0 Pin Interrupt Polarity
* PIPOL1       -  Video Port 1 Pin Interrupt Polarity
* PIPOL2       -  Video Port 2 Pin Interrupt Polarity
* PISTAT0      -  Video Port 0 Pin Interrupt Status
* PISTAT1      -  Video Port 1 Pin Interrupt Status
* PISTAT2      -  Video Port 2 Pin Interrupt Status
* PICLR0       -  Video Port 0 Pin Interrupt Clear
* PICLR1       -  Video Port 1 Pin Interrupt Clear
* PICLR2       -  Video Port 2 Pin Interrupt Clear
* VPCTL0       -  Video Port 0 Control Register
* VPCTL1       -  Video Port 1 Control Register
* VPCTL2       -  Video Port 2 Control Register
* VPSTAT0      -  Video Port 0 Status Register	
* VPSTAT1      -  Video Port 1 Status Register	
* VPSTAT2      -  Video Port 2 Status Register	
* VPIE0        -  Video Port 0 Interrupt Enable Register
* VPIE1        -  Video Port 1 Interrupt Enable Register
* VPIE2        -  Video Port 2 Interrupt Enable Register
* VPIS0        -  Video Port 0 Interrupt Status Register
* VPIS1        -  Video Port 1 Interrupt Status Register
* VPIS2        -  Video Port 2 Interrupt Status Register
********************************************************************************
* Memory Mapping Register -- Capture
*
* VCASTAT0     -  Video Port 0 Video Capture A Status
* VCASTAT1     -  Video Port 1 Video Capture A Status
* VCASTAT2     -  Video Port 2 Video Capture A Status
* VCACTL0      -  Video Port 0 Video Capture A Control
* VCACTL1      -  Video Port 1 Video Capture A Control
* VCACTL2      -  Video Port 2 Video Capture A Control
* VCASTRT10    -  Video Port 0 Video Capture A Field1 Start
* VCASTRT11    -  Video Port 1 Video Capture A Field1 Start
* VCASTRT12    -  Video Port 2 Video Capture A Field1 Start
* VCASTOP10    -  Video Port 0 Video Capture A Field1 Stop
* VCASTOP11    -  Video Port 1 Video Capture A Field1 Stop
* VCASTOP12    -  Video Port 2 Video Capture A Field1 Stop
* VCASTRT20    -  Video Port 0 Video Capture A Field2 Start
* VCASTRT21    -  Video Port 1 Video Capture A Field2 Start
* VCASTRT22    -  Video Port 2 Video Capture A Field2 Start
* VCASTOP20    -  Video Port 0 Video Capture A Field2 Stop
* VCASTOP21    -  Video Port 1 Video Capture A Field2 Stop
* VCASTOP22    -  Video Port 2 Video Capture A Field2 Stop
* VCAVINT0     -  Video Port 0 Video Capture A Vertical Interrupt
* VCAVINT1     -  Video Port 1 Video Capture A Vertical Interrupt
* VCAVINT2     -  Video Port 2 Video Capture A Vertical Interrupt
* VCATHRLD0    -  Video Port 0 Video Capture A Threshold
* VCATHRLD1    -  Video Port 1 Video Capture A Threshold
* VCATHRLD2    -  Video Port 2 Video Capture A Threshold
* VCAEVTCT0    -  Video Port 0 Video Capture A Event Count
* VCAEVTCT1    -  Video Port 1 Video Capture A Event Count
* VCAEVTCT2    -  Video Port 2 Video Capture A Event Count
*
* VCBSTAT0     -  Video Port 0 Video Capture B Status (only for DM642)
* VCBSTAT1     -  Video Port 1 Video Capture B Status (only for DM642)
* VCBSTAT2     -  Video Port 2 Video Capture B Status (only for DM642)
* VCBCTL0      -  Video Port 0 Video Capture B Control (only for DM642)
* VCBCTL1      -  Video Port 1 Video Capture B Control (only for DM642)
* VCBCTL2      -  Video Port 2 Video Capture B Control (only for DM642)
* VCBSTRT10    -  Video Port 0 Video Capture B Field1 Start (only for DM642)
* VCBSTRT11    -  Video Port 1 Video Capture B Field1 Start (only for DM642)
* VCBSTRT12    -  Video Port 2 Video Capture B Field1 Start (only for DM642)
* VCBSTOP10    -  Video Port 0 Video Capture B Field1Stop (only for DM642)
* VCBSTOP11    -  Video Port 1 Video Capture B Field1Stop (only for DM642)
* VCBSTOP12    -  Video Port 2 Video Capture B Field1Stop (only for DM642)
* VCBSTRT20    -  Video Port 0 Video Capture B Field2 Start (only for DM642)
* VCBSTRT21    -  Video Port 1 Video Capture B Field2 Start (only for DM642)
* VCBSTRT22    -  Video Port 2 Video Capture B Field2 Start (only for DM642)
* VCBSTOP20    -  Video Port 0 Video Capture B Field2Stop (only for DM642)
* VCBSTOP21    -  Video Port 1 Video Capture B Field2Stop (only for DM642)
* VCBSTOP22    -  Video Port 2 Video Capture B Field2Stop (only for DM642)
* VCBVINT0     -  Video Port 0 Video Capture B Vertical Interrupt (only for DM642)
* VCBVINT1     -  Video Port 1 Video Capture B Vertical Interrupt (only for DM642)
* VCBVINT2     -  Video Port 2 Video Capture B Vertical Interrupt (only for DM642)
* VCBTHRLD0    -  Video Port 0 Video Capture B Threshold (only for DM642)
* VCBTHRLD1    -  Video Port 1 Video Capture B Threshold (only for DM642)
* VCBTHRLD2    -  Video Port 2 Video Capture B Threshold (only for DM642)
* VCBEVTCT0    -  Video Port 0 Video Capture B Event Count (only for DM642)
* VCBEVTCT1    -  Video Port 1 Video Capture B Event Count (only for DM642)
* VCBEVTCT2    -  Video Port 2 Video Capture B Event Count (only for DM642)
*
* TSICTL0      -  Video Port 0 Transport Stream Interface Capture Control
* TSICTL1      -  Video Port 1 Transport Stream Interface Capture Control
* TSICTL2      -  Video Port 2 Transport Stream Interface Capture Control
* TSICLKINITL0 -  Video Port 0 Transport Stream Interface Clock Initialization LSB
* TSICLKINITL1 -  Video Port 1 Transport Stream Interface Clock Initialization LSB
* TSICLKINITL2 -  Video Port 2 Transport Stream Interface Clock Initialization LSB
* TSICLKINITM0 -  Video Port 0 Transport Stream Interface Clock Initialization MSB
* TSICLKINITM1 -  Video Port 1 Transport Stream Interface Clock Initialization MSB
* TSICLKINITM2 -  Video Port 2 Transport Stream Interface Clock Initialization MSB
* TSISTCLKL0   -  Video Port 0 Transport Stream Interface System Time Clock LSB
* TSISTCLKL1   -  Video Port 1 Transport Stream Interface System Time Clock LSB
* TSISTCLKL2   -  Video Port 2 Transport Stream Interface System Time Clock LSB
* TSISTCLKM0   -  Video Port 0 Transport Stream Interface System Time Clock  MSB
* TSISTCLKM1   -  Video Port 1 Transport Stream Interface System Time Clock  MSB
* TSISTCLKM2   -  Video Port 2 Transport Stream Interface System Time Clock  MSB
* TSISTCMPL0   -  Video Port 0 Transport Stream Interface STC Compare LSB
* TSISTCMPL1   -  Video Port 1 Transport Stream Interface STC Compare LSB
* TSISTCMPL2   -  Video Port 2 Transport Stream Interface STC Compare LSB
* TSISTCMPM0   -  Video Port 0 Transport Stream Interface STC Compare MSB
* TSISTCMPM1   -  Video Port 1 Transport Stream Interface STC Compare MSB
* TSISTCMPM2   -  Video Port 2 Transport Stream Interface STC Compare MSB
* TSISTMSKL0   -  Video Port 0 Transport Stream Interface STC Compare Mask LSB
* TSISTMSKL1   -  Video Port 1 Transport Stream Interface STC Compare Mask LSB
* TSISTMSKL2   -  Video Port 2 Transport Stream Interface STC Compare Mask LSB
* TSISTMSKM0   -  Video Port 0 Transport Stream Interface STC Compare Mask MSB
* TSISTMSKM1   -  Video Port 1 Transport Stream Interface STC Compare Mask MSB
* TSISTMSKM2   -  Video Port 2 Transport Stream Interface STC Compare Mask MSB
* TSITICKS0    -  Video Port 0 Transport Stream Interface STC Ticks Interrupt
* TSITICKS1    -  Video Port 1 Transport Stream Interface STC Ticks Interrupt
* TSITICKS2    -  Video Port 2 Transport Stream Interface STC Ticks Interrupt
*
********************************************************************************
* Memory Mapping Register -- Display
*
* (DM640 has only one video port, i.e. only Port 0 registers are valid)
* (DM641 has only two video ports, i.e. only Port 0 and Port 1 registers are valid)
* (DM642 has three video ports, i.e. Port 0, Port 1 and Port 2)
*
* VDSTAT0      -  Video Port 0 Video Display Status
* VDSTAT1      -  Video Port 1 Video Display Status
* VDSTAT2      -  Video Port 2 Video Display Status
* VDCTL0       -  Video Port 0 Video Display Control
* VDCTL1       -  Video Port 1 Video Display Control
* VDCTL2       -  Video Port 2 Video Display Control
* VDFRMSZ0     -  Video Port 0 Video Display Frame Size
* VDFRMSZ1     -  Video Port 1 Video Display Frame Size
* VDFRMSZ2     -  Video Port 2 Video Display Frame Size
* VDHBLNK0     -  Video Port 0 Video Display Horizontal Blanking
* VDHBLNK1     -  Video Port 1 Video Display Horizontal Blanking
* VDHBLNK2     -  Video Port 2 Video Display Horizontal Blanking
* VDVBLKS10    -  Video Port 0 Video Display Vertical Blanking Start - Field 1
* VDVBLKS11    -  Video Port 1 Video Display Vertical Blanking Start - Field 1
* VDVBLKS12    -  Video Port 2 Video Display Vertical Blanking Start - Field 1
* VDVBLKE10    -  Video Port 0 Video Display Vertical Blanking End - Field 1
* VDVBLKE11    -  Video Port 1 Video Display Vertical Blanking End - Field 1
* VDVBLKE12    -  Video Port 2 Video Display Vertical Blanking End - Field 1
* VDVBLKS20    -  Video Port 0 Video Display Vertical Blanking Start - Field 2
* VDVBLKS21    -  Video Port 1 Video Display Vertical Blanking Start - Field 2
* VDVBLKS22    -  Video Port 2 Video Display Vertical Blanking Start - Field 2
* VDVBLKE20    -  Video Port 0 Video Display Vertical Blanking End - Field 2
* VDVBLKE21    -  Video Port 1 Video Display Vertical Blanking End - Field 2
* VDVBLKE22    -  Video Port 2 Video Display Vertical Blanking End - Field 2
* VDIMGOFF10   -  Video Port 0 Video Display Image Offset - Field 1
* VDIMGOFF11   -  Video Port 1 Video Display Image Offset - Field 1
* VDIMGOFF12   -  Video Port 2 Video Display Image Offset - Field 1
* VDIMGSZ10    -  Video Port 0 Video Display Image Size - Field 1
* VDIMGSZ11    -  Video Port 1 Video Display Image Size - Field 1
* VDIMGSZ12    -  Video Port 2 Video Display Image Size - Field 1
* VDIMGOFF20   -  Video Port 0 Video Display Image Offset - Field 2
* VDIMGOFF21   -  Video Port 1 Video Display Image Offset - Field 2
* VDIMGOFF22   -  Video Port 2 Video Display Image Offset - Field 2
* VDIMGSZ20    -  Video Port 0 Video Display Image Size - Field 2
* VDIMGSZ21    -  Video Port 1 Video Display Image Size - Field 2
* VDIMGSZ22    -  Video Port 2 Video Display Image Size - Field 2
* VDFLDT10     -  Video Port 0 Video Display Field1 Timing
* VDFLDT11     -  Video Port 1 Video Display Field1 Timing
* VDFLDT12     -  Video Port 2 Video Display Field1 Timing
* VDFLDT20     -  Video Port 0 Video Display Field2 Timing
* VDFLDT21     -  Video Port 1 Video Display Field2 Timing
* VDFLDT22     -  Video Port 2 Video Display Field2 Timing
* VDTHRLD0     -  Video Port 0 Video Display Threshold
* VDTHRLD1     -  Video Port 1 Video Display Threshold
* VDTHRLD2     -  Video Port 2 Video Display Threshold
* VDHSYNC0     -  Video Port 0 Video Display Horizontal Sync
* VDHSYNC1     -  Video Port 1 Video Display Horizontal Sync
* VDHSYNC2     -  Video Port 2 Video Display Horizontal Sync
* VDVSYNS10    -  Video Port 0 Video Display Vertical Synchronization Start - Field 1
* VDVSYNS11    -  Video Port 1 Video Display Vertical Synchronization Start - Field 1
* VDVSYNS12    -  Video Port 2 Video Display Vertical Synchronization Start - Field 1
* VDVSYNE10    -  Video Port 0 Video Display Vertical Synchronization End - Field 1
* VDVSYNE11    -  Video Port 1 Video Display Vertical Synchronization End - Field 1
* VDVSYNE12    -  Video Port 2 Video Display Vertical Synchronization End - Field 1
* VDVSYNS20    -  Video Port 0 Video Display Vertical Synchronization Start - Field 2
* VDVSYNS21    -  Video Port 1 Video Display Vertical Synchronization Start - Field 2
* VDVSYNS22    -  Video Port 2 Video Display Vertical Synchronization Start - Field 2
* VDVSYNE20    -  Video Port 0 Video Display Vertical Synchronization End - Field 2
* VDVSYNE21    -  Video Port 1 Video Display Vertical Synchronization End - Field 2
* VDVSYNE22    -  Video Port 2 Video Display Vertical Synchronization End - Field 2
* VDRELOAD0    -  Video Port 0 Video Display Counter Reload
* VDRELOAD1    -  Video Port 1 Video Display Counter Reload
* VDRELOAD2    -  Video Port 2 Video Display Counter Reload
* VDDISPEVT0   -  Video Port 0 Video Display Display Event Register
* VDDISPEVT1   -  Video Port 1 Video Display Display Event Register
* VDDISPEVT2   -  Video Port 2 Video Display Display Event Register
* VDCLIP0      -  Video Port 0 Video Display Clipping Register
* VDCLIP1      -  Video Port 1 Video Display Clipping Register
* VDCLIP2      -  Video Port 2 Video Display Clipping Register
* VDDEFVAL0    -  Video Port 0 Video Display Default Display Value
* VDDEFVAL1    -  Video Port 1 Video Display Default Display Value
* VDDEFVAL2    -  Video Port 2 Video Display Default Display Value
* VDVINT0      -  Video Port 0 Video Display Vertical Interrupt
* VDVINT1      -  Video Port 1 Video Display Vertical Interrupt
* VDVINT2      -  Video Port 2 Video Display Vertical Interrupt
* VDFBIT0      -  Video Port 0 Video Display Field Bit Register
* VDFBIT1      -  Video Port 1 Video Display Field Bit Register
* VDFBIT2      -  Video Port 2 Video Display Field Bit Register
* VDVBIT10     -  Video Port 0 Video Display Vertical Blank Bit-Field 1 Register
* VDVBIT11     -  Video Port 1 Video Display Vertical Blank Bit-Field 1 Register
* VDVBIT12     -  Video Port 2 Video Display Vertical Blank Bit-Field 1 Register
* VDVBIT20     -  Video Port 0 Video Display Vertical Blank Bit-Field 2 Register
* VDVBIT21     -  Video Port 1 Video Display Vertical Blank Bit-Field 2 Register
* VDVBIT22     -  Video Port 2 Video Display Vertical Blank Bit-Field 2 Register
*
********************************************************************************
* FIFO Mapping
*
* YSRCA0       -  Video Port 0 Y FIFO Source Register A
* YSRCA1       -  Video Port 1 Y FIFO Source Register A
* YSRCA2       -  Video Port 2 Y FIFO Source Register A
* CBSRCA0      -  Video Port 0 Cb FIFO Source Register A
* CBSRCA1      -  Video Port 1 Cb FIFO Source Register A
* CBSRCA2      -  Video Port 2 Cb FIFO Source Register A
* CRSRCA0      -  Video Port 0 Cr FIFO Source Register A
* CRSRCA1      -  Video Port 1 Cr FIFO Source Register A
* CRSRCA2      -  Video Port 2 Cr FIFO Source Register A
* YSRCB0       -  Video Port 0 Y FIFO Source Register B  (only for DM642)
* YSRCB1       -  Video Port 1 Y FIFO Source Register B  (only for DM642)
* YSRCB2       -  Video Port 2 Y FIFO Source Register B  (only for DM642)
* CBSRCB0      -  Video Port 0 Cb FIFO Source Register B (only for DM642)
* CBSRCB1      -  Video Port 1 Cb FIFO Source Register B (only for DM642)
* CBSRCB2      -  Video Port 2 Cb FIFO Source Register B (only for DM642)
* CRSRCB0      -  Video Port 0 Cr FIFO Source Register B (only for DM642)
* CRSRCB1      -  Video Port 1 Cr FIFO Source Register B (only for DM642)
* CRSRCB2      -  Video Port 2 Cr FIFO Source Register B (only for DM642)
* YDSTA0       -  Video Port 0 Y FIFO Destination Register A
* YDSTA1       -  Video Port 1 Y FIFO Destination Register A
* YDSTA2       -  Video Port 2 Y FIFO Destination Register A
* CBDST0       -  Video Port 0 Cb FIFO Destination Register 
* CBDST1       -  Video Port 1 Cb FIFO Destination Register 
* CBDST2       -  Video Port 2 Cb FIFO Destination Register 
* CRDST0       -  Video Port 0 Cr FIFO Destination Register
* CRDST1       -  Video Port 1 Cr FIFO Destination Register
* CRDST2       -  Video Port 2 Cr FIFO Destination Register
* YDSTB0       -  Video Port 0 Y FIFO Destination Register B (only for DM642)
* YDSTB1       -  Video Port 1 Y FIFO Destination Register B (only for DM642)
* YDSTB2       -  Video Port 2 Y FIFO Destination Register B (only for DM642)
*
\******************************************************************************/
#ifndef _CSL_VPHAL_H_
#define _CSL_VPHAL_H_

#include <csl_stdinc.h>
#include <csl_chip.h>

#if (VP_SUPPORT)
/******************************************************************************\
* MISC section
\******************************************************************************/

 #if (CHIP_DM642)
  #define _VP_PORT_CNT        3
 #endif

 #if (CHIP_DM641)
  #define _VP_PORT_CNT        2
 #endif

 #if (CHIP_DM640)
  #define _VP_PORT_CNT        1
 #endif

  #define _VP_BASE_PORT0      0x01C40000u
 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_BASE_PORT1      0x01C44000u
 #endif

 #if (CHIP_DM642)
  #define _VP_BASE_PORT2      0x01C48000u
 #endif

/* Capture Channel A base address */
  #define _VP_BASE_CHAPORT0   _VP_BASE_PORT0 + 0x00000100u

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_BASE_CHAPORT1   _VP_BASE_PORT1 + 0x00000100u
 #endif

 #if (CHIP_DM642)
  #define _VP_BASE_CHAPORT2   _VP_BASE_PORT2 + 0x00000100u
 #endif

/* Capture Channel B base address */
  #define _VP_BASE_CHBPORT0   _VP_BASE_PORT0 + 0x00000140u

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_BASE_CHBPORT1   _VP_BASE_PORT1 + 0x00000140u
 #endif

 #if (CHIP_DM642)
  #define _VP_BASE_CHBPORT2   _VP_BASE_PORT2 + 0x00000140u
 #endif

  #define _VP_AFBASE_PORT0    0x74000000u
  #define _VP_BFBASE_PORT0    0x76000000u

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_AFBASE_PORT1    0x78000000u
  #define _VP_BFBASE_PORT1    0x7A000000u
 #endif

 #if (CHIP_DM642)
  #define _VP_AFBASE_PORT2    0x7C000000u
  #define _VP_BFBASE_PORT2    0x7E000000u
 #endif


/******************************************************************************\
* module level register/field access macros
\******************************************************************************/

  /* ----------------- */
  /* FIELD MAKE MACROS */
  /* ----------------- */

  #define VP_FMK(REG,FIELD,x)\
    _PER_FMK(VP,##REG,##FIELD,x)

  #define VP_FMKS(REG,FIELD,SYM)\
    _PER_FMKS(VP,##REG,##FIELD,##SYM)


  /* -------------------------------- */
  /* RAW REGISTER/FIELD ACCESS MACROS */
  /* -------------------------------- */

  #define VP_ADDR(REG)\
    _VP_##REG##_ADDR

  #define VP_RGET(REG)\
    _PER_RGET(_VP_##REG##_ADDR,VP,##REG)

  #define VP_RSET(REG,x)\
    _PER_RSET(_VP_##REG##_ADDR,VP,##REG,x)

  #define VP_FGET(REG,FIELD)\
    _VP_##REG##_FGET(##FIELD)

  #define VP_FSET(REG,FIELD,x)\
    _VP_##REG##_FSET(##FIELD,##x)

  #define VP_FSETS(REG,FIELD,SYM)\
    _VP_##REG##_FSETS(##FIELD,##SYM)


  /* ------------------------------------------ */
  /* ADDRESS BASED REGISTER/FIELD ACCESS MACROS */
  /* ------------------------------------------ */

  #define VP_RGETA(addr,REG)\
    _PER_RGET(addr,VP,##REG)

  #define VP_RSETA(addr,REG,x)\
    _PER_RSET(addr,VP,##REG,x)

  #define VP_FGETA(addr,REG,FIELD)\
    _PER_FGET(addr,VP,##REG,##FIELD)

  #define VP_FSETA(addr,REG,FIELD,x)\
    _PER_FSET(addr,VP,##REG,##FIELD,x)

  #define VP_FSETSA(addr,REG,FIELD,SYM)\
    _PER_FSETS(addr,VP,##REG,##FIELD,##SYM)


  /* ----------------------------------------- */
  /* HANDLE BASED REGISTER/FIELD ACCESS MACROS */
  /* ----------------------------------------- */

  #define VP_ADDRH(h,REG)\
    (Uint32)(&((h)->baseAddr[_VP_##REG##_OFFSET]))

  #define VP_RGETH(h,REG)\
    VP_RGETA(VP_ADDRH(h,##REG),##REG)


  #define VP_RSETH(h,REG,x)\
    VP_RSETA(VP_ADDRH(h,##REG),##REG,x)


  #define VP_FGETH(h,REG,FIELD)\
    VP_FGETA(VP_ADDRH(h,##REG),##REG,##FIELD)


  #define VP_FSETH(h,REG,FIELD,x)\
    VP_FSETA(VP_ADDRH(h,##REG),##REG,##FIELD,x)


  #define VP_FSETSH(h,REG,FIELD,SYM)\
    VP_FSETSA(VP_ADDRH(h,##REG),##REG,##FIELD,##SYM)



/******************************************************************************\
* _____________________
* |                   |
* |  V P P I D        |
* |___________________|
*
* VPPID0 - Video Port 0 Peripheral Identification Register
* VPPID1 - Video Port 1 Peripheral Identification Register
* VPPID2 - Video Port 2 Peripheral Identification Register
*
*
* FIELDS (msb -> lsb)
* (r) TYPE
* (r) CLASS
* (r) REVISION
*
\******************************************************************************/
  #define _VP_VPPID_OFFSET            0

  #define _VP_VPPID0_ADDR   (_VP_BASE_PORT0 + 4*_VP_VPPID_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VPPID1_ADDR   (_VP_BASE_PORT1 + 4*_VP_VPPID_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VPPID2_ADDR   (_VP_BASE_PORT2 + 4*_VP_VPPID_OFFSET)
 #endif


  #define _VP_VPPID_TYPE_MASK              0x00FF0000u
  #define _VP_VPPID_TYPE_SHIFT             0x00000010u
  #define  VP_VPPID_TYPE_DEFAULT           0x00000001u /* spec. 1.4 */
  #define  VP_VPPID_TYPE_OF(x)             _VALUEOF(x)

  #define _VP_VPPID_CLASS_MASK             0x0000FF00u
  #define _VP_VPPID_CLASS_SHIFT            0x00000008u
  #define  VP_VPPID_CLASS_DEFAULT          0x00000009u /* spec. 1.4 */
  #define  VP_VPPID_CLASS_OF(x)            _VALUEOF(x)

  #define _VP_VPPID_REVISION_MASK          0x000000FFu
  #define _VP_VPPID_REVISION_SHIFT         0x00000000u
  #define  VP_VPPID_REVISION_DEFAULT       0x00000001u /* temp fix, wait for spec. ??? */
  #define  VP_VPPID_REVISION_OF(x)         _VALUEOF(x)

  #define VP_VPPID_OF(x)               _VALUEOF(x)

  #define VP_VPPID_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VPPID,TYPE)\
    |_PER_FDEFAULT(VP,VPPID,CLASS)\
    |_PER_FDEFAULT(VP,VPPID,REVISION)\
  )
 #if (!(CHIP_6413 | CHIP_6418 | CHIP_6410))
  #define VP_VPPID_RMK(type,class,revision) (Uint32)(\
              _PER_FMK(VP,VPPID,TYPE,type)\
	     |_PER_FMK(VP,VPPID,CLASS,class)\
	     |_PER_FMK(VP,VPPID,REVISION,revision)\
  )	     
 #endif  
 
  #define _VP_VPPID_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VPPID##N##_ADDR,VP,VPPID,##FIELD,field)

  #define _VP_VPPID_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VPPID##N##_ADDR,VP,VPPID,##FIELD,##SYM)

  #define _VP_VPPID_FGET(N,FIELD)\
    _PER_FGET(_VP_VPPID##N##_ADDR,VP,VPPID,##FIELD)


  #define _VP_VPPID0_FGET(FIELD)   _VP_VPPID_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VPPID1_FGET(FIELD)   _VP_VPPID_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VPPID2_FGET(FIELD)   _VP_VPPID_FGET(2,##FIELD)
 #endif


  #define _VP_VPPID0_FSET(FIELD,f)   _VP_VPPID_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VPPID1_FSET(FIELD,f)   _VP_VPPID_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VPPID2_FSET(FIELD,f)   _VP_VPPID_FSET(2,##FIELD,f)
 #endif


  #define _VP_VPPID0_FSETS(FIELD,SYM)   _VP_VPPID_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VPPID1_FSETS(FIELD,SYM)   _VP_VPPID_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VPPID2_FSETS(FIELD,SYM)   _VP_VPPID_FSETS(2,##FIELD,##SYM)
 #endif



/******************************************************************************\
* _____________________
* |                   |
* |  P C R            |
* |___________________|
*
* PCR0  - Video Port 0 Peripheral Control Register
* PCR1  - Video Port 1 Peripheral Control Register
* PCR2  - Video Port 2 Peripheral Control Register
*
* FIELDS (msb -> lsb)
* (rw) PEREN
* (r)  SOFT
* (rw) FREE
*
\******************************************************************************/
  #define _VP_PCR_OFFSET            1

  #define _VP_PCR0_ADDR   (_VP_BASE_PORT0 + 4*_VP_PCR_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PCR1_ADDR   (_VP_BASE_PORT1 + 4*_VP_PCR_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_PCR2_ADDR   (_VP_BASE_PORT2 + 4*_VP_PCR_OFFSET)
 #endif


  #define _VP_PCR_PEREN_MASK           0x00000004u
  #define _VP_PCR_PEREN_SHIFT          0x00000002u
  #define  VP_PCR_PEREN_DEFAULT        0x00000000u
  #define  VP_PCR_PEREN_OF(x)          _VALUEOF(x)
  #define  VP_PCR_PEREN_DISABLE        0x00000000u
  #define  VP_PCR_PEREN_ENABLE         0x00000001u
  
  #define _VP_PCR_SOFT_MASK           0x00000002u
  #define _VP_PCR_SOFT_SHIFT          0x00000001u
  #define  VP_PCR_SOFT_DEFAULT        0x00000000u
  #define  VP_PCR_SOFT_OF(x)          _VALUEOF(x)
  #define  VP_PCR_SOFT_STOP           0x00000000u
  #define  VP_PCR_SOFT_COMP           0x00000001u
  
  #define _VP_PCR_FREE_MASK           0x00000001u
  #define _VP_PCR_FREE_SHIFT          0x00000000u
  #define  VP_PCR_FREE_DEFAULT        0x00000001u
  #define  VP_PCR_FREE_OF(x)          _VALUEOF(x)
  #define  VP_PCR_FREE_SOFT           0x00000000u
  
  #define  VP_PCR_OF(x)             _VALUEOF(x)

  #define VP_PCR_DEFAULT (Uint32)(\
    _PER_FDEFAULT(VP,PCR,PEREN)\
   |_PER_FDEFAULT(VP,PCR,SOFT)\
   |_PER_FDEFAULT(VP,PCR,FREE)\
  )

#define VP_PCR_RMK(peren,free) (Uint32)(\
    _PER_FMK(VP,PCR,PEREN,peren)\
   |_PER_FMK(VP,PCR,FREE,free)\
  )

  #define _VP_PCR_FGET(N,FIELD)\
    _PER_FGET(_VP_PCR##N##_ADDR,VP,PCR,##FIELD)

  #define _VP_PCR_FSET(N,FIELD,field)\
    _PER_FSET(_VP_PCR##N##_ADDR,VP,PCR,##FIELD,field)

  #define _VP_PCR_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_PCR##N##_ADDR,VP,PCR,##FIELD,##SYM)

  #define _VP_PCR0_FGET(FIELD)   _VP_PCR_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PCR1_FGET(FIELD)   _VP_PCR_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_PCR2_FGET(FIELD)   _VP_PCR_FGET(2,##FIELD)
 #endif


  #define _VP_PCR0_FSET(FIELD,f)   _VP_PCR_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PCR1_FSET(FIELD,f)   _VP_PCR_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_PCR2_FSET(FIELD,f)   _VP_PCR_FSET(2,##FIELD,f)
 #endif


  #define _VP_PCR0_FSETS(FIELD,SYM)   _VP_PCR_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PCR1_FSETS(FIELD,SYM)   _VP_PCR_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_PCR2_FSETS(FIELD,SYM)   _VP_PCR_FSETS(2,##FIELD,##SYM)
 #endif

  
/******************************************************************************\
* _____________________
* |                   |
* |  P F U N C        |
* |___________________|
*
* PFUNC0  - Video Port 0 Pin Function Register
* PFUNC1  - Video Port 1 Pin Function Register
* PFUNC2  - Video Port 2 Pin Function Register
*
* FIELDS (msb -> lsb)
* (rw) PFUNC22
* (rw) PFUNC21
* (rw) PFUNC20
* (rw) PFUNC10
* (rw) PFUNC0
*
\******************************************************************************/
  #define _VP_PFUNC_OFFSET            8

  #define _VP_PFUNC0_ADDR   (_VP_BASE_PORT0 + 4*_VP_PFUNC_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PFUNC1_ADDR   (_VP_BASE_PORT1 + 4*_VP_PFUNC_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_PFUNC2_ADDR   (_VP_BASE_PORT2 + 4*_VP_PFUNC_OFFSET)
 #endif


  #define _VP_PFUNC_PFUNC22_MASK           0x00400000u
  #define _VP_PFUNC_PFUNC22_SHIFT          0x00000016u
  #define  VP_PFUNC_PFUNC22_DEFAULT        0x00000000u
  #define  VP_PFUNC_PFUNC22_OF(x)          _VALUEOF(x)
  #define  VP_PFUNC_PFUNC22_NORMAL         0x00000000u
  #define  VP_PFUNC_PFUNC22_VCTL2      0x00000001u
  
  #define _VP_PFUNC_PFUNC21_MASK           0x00200000u
  #define _VP_PFUNC_PFUNC21_SHIFT          0x00000015u
  #define  VP_PFUNC_PFUNC21_DEFAULT        0x00000000u
  #define  VP_PFUNC_PFUNC21_OF(x)          _VALUEOF(x)
  #define  VP_PFUNC_PFUNC21_NORMAL         0x00000000u
  #define  VP_PFUNC_PFUNC21_VCTL1      0x00000001u
  
  #define _VP_PFUNC_PFUNC20_MASK           0x00100000u
  #define _VP_PFUNC_PFUNC20_SHIFT          0x00000014u
  #define  VP_PFUNC_PFUNC20_DEFAULT        0x00000000u
  #define  VP_PFUNC_PFUNC20_OF(x)          _VALUEOF(x)
  #define  VP_PFUNC_PFUNC20_NORMAL         0x00000000u
  #define  VP_PFUNC_PFUNC20_VCTL0      0x00000001u
  
  #define _VP_PFUNC_PFUNC10_MASK           0x00000400u
  #define _VP_PFUNC_PFUNC10_SHIFT          0x0000000Au
  #define  VP_PFUNC_PFUNC10_DEFAULT        0x00000000u
  #define  VP_PFUNC_PFUNC10_OF(x)          _VALUEOF(x)
  #define  VP_PFUNC_PFUNC10_NORMAL         0x00000000u
  #define  VP_PFUNC_PFUNC10_VDATA10TO19    0x00000001u
  
  #define _VP_PFUNC_PFUNC0_MASK            0x00000001u
  #define _VP_PFUNC_PFUNC0_SHIFT           0x00000000u
  #define  VP_PFUNC_PFUNC0_DEFAULT         0x00000000u
  #define  VP_PFUNC_PFUNC0_OF(x)           _VALUEOF(x)
  #define  VP_PFUNC_PFUNC0_NORMAL          0x00000000u
  #define  VP_PFUNC_PFUNC0_VDATA0TO9       0x00000001u
  
  #define  VP_PFUNC_OF(x)             _VALUEOF(x)

  #define VP_PFUNC_DEFAULT (Uint32)(\
    _PER_FDEFAULT(VP,PFUNC,PFUNC22)\
   |_PER_FDEFAULT(VP,PFUNC,PFUNC21)\
   |_PER_FDEFAULT(VP,PFUNC,PFUNC20)\
   |_PER_FDEFAULT(VP,PFUNC,PFUNC10)\
   |_PER_FDEFAULT(VP,PFUNC,PFUNC0)\
  )

#define VP_PFUNC_RMK(pfunc22,pfunc21,pfunc20,pfunc10,pfunc0) (Uint32)(\
    _PER_FMK(VP,PFUNC,PFUNC22,pfunc22)\
   |_PER_FMK(VP,PFUNC,PFUNC21,pfunc21)\
   |_PER_FMK(VP,PFUNC,PFUNC20,pfunc20)\
   |_PER_FMK(VP,PFUNC,PFUNC10,pfunc10)\
   |_PER_FMK(VP,PFUNC,PFUNC0,pfunc0)\
  )

  #define _VP_PFUNC_FGET(N,FIELD)\
    _PER_FGET(_VP_PFUNC##N##_ADDR,VP,PFUNC,##FIELD)

  #define _VP_PFUNC_FSET(N,FIELD,field)\
    _PER_FSET(_VP_PFUNC##N##_ADDR,VP,PFUNC,##FIELD,field)

  #define _VP_PFUNC_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_PFUNC##N##_ADDR,VP,PFUNC,##FIELD,##SYM)

  #define _VP_PFUNC0_FGET(FIELD)   _VP_PFUNC_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PFUNC1_FGET(FIELD)   _VP_PFUNC_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_PFUNC2_FGET(FIELD)   _VP_PFUNC_FGET(2,##FIELD)
 #endif


  #define _VP_PFUNC0_FSET(FIELD,f)   _VP_PFUNC_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PFUNC1_FSET(FIELD,f)   _VP_PFUNC_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_PFUNC2_FSET(FIELD,f)   _VP_PFUNC_FSET(2,##FIELD,f)
 #endif


  #define _VP_PFUNC0_FSETS(FIELD,SYM)   _VP_PFUNC_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PFUNC1_FSETS(FIELD,SYM)   _VP_PFUNC_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_PFUNC2_FSETS(FIELD,SYM)   _VP_PFUNC_FSETS(2,##FIELD,##SYM)
 #endif

  
/******************************************************************************\
* _____________________
* |                   |
* |  P D I R          |
* |___________________|
*
* PDIR0  - Video Port 0 Pin Direction Register
* PDIR1  - Video Port 1 Pin Direction Register
* PDIR2  - Video Port 2 Pin Direction Register
*
* FIELDS (msb -> lsb)
* (rw) PDIR22
* (rw) PDIR21
* (rw) PDIR20
* (rw) PDIR16
* (rw) PDIR12
* (rw) PDIR10
* (rw) PDIR8
* (rw) PDIR4
* (rw) PDIR0
*
\******************************************************************************/
  #define _VP_PDIR_OFFSET            9

  #define _VP_PDIR0_ADDR   (_VP_BASE_PORT0 + 4*_VP_PDIR_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PDIR1_ADDR   (_VP_BASE_PORT1 + 4*_VP_PDIR_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_PDIR2_ADDR   (_VP_BASE_PORT2 + 4*_VP_PDIR_OFFSET)
 #endif


  #define _VP_PDIR_PDIR22_MASK           0x00400000u
  #define _VP_PDIR_PDIR22_SHIFT          0x00000016u
  #define  VP_PDIR_PDIR22_DEFAULT        0x00000000u
  #define  VP_PDIR_PDIR22_OF(x)          _VALUEOF(x)
  #define  VP_PDIR_PDIR22_VCTL2IN        0x00000000u
  #define  VP_PDIR_PDIR22_VCTL2OUT       0x00000001u
  
  #define _VP_PDIR_PDIR21_MASK           0x00200000u
  #define _VP_PDIR_PDIR21_SHIFT          0x00000015u
  #define  VP_PDIR_PDIR21_DEFAULT        0x00000000u
  #define  VP_PDIR_PDIR21_OF(x)          _VALUEOF(x)
  #define  VP_PDIR_PDIR21_VCTL1IN        0x00000000u
  #define  VP_PDIR_PDIR21_VCTL1OUT       0x00000001u
  
  #define _VP_PDIR_PDIR20_MASK           0x00100000u
  #define _VP_PDIR_PDIR20_SHIFT          0x00000014u
  #define  VP_PDIR_PDIR20_DEFAULT        0x00000000u
  #define  VP_PDIR_PDIR20_OF(x)          _VALUEOF(x)
  #define  VP_PDIR_PDIR20_VCTL0IN        0x00000000u
  #define  VP_PDIR_PDIR20_VCTL0OUT       0x00000001u
  
  #define _VP_PDIR_PDIR16_MASK           0x00010000u
  #define _VP_PDIR_PDIR16_SHIFT          0x00000010u
  #define  VP_PDIR_PDIR16_DEFAULT        0x00000000u
  #define  VP_PDIR_PDIR16_OF(x)          _VALUEOF(x)
  #define  VP_PDIR_PDIR16_VDATA16TO19IN  0x00000000u
  #define  VP_PDIR_PDIR16_VDATA16TO19OUT 0x00000001u
  
  #define _VP_PDIR_PDIR12_MASK           0x00001000u
  #define _VP_PDIR_PDIR12_SHIFT          0x0000000Cu
  #define  VP_PDIR_PDIR12_DEFAULT        0x00000000u
  #define  VP_PDIR_PDIR12_OF(x)          _VALUEOF(x)
  #define  VP_PDIR_PDIR12_VDATA12TO15IN  0x00000000u
  #define  VP_PDIR_PDIR12_VDATA12TO15OUT 0x00000001u
  
  #define _VP_PDIR_PDIR10_MASK           0x00000400u
  #define _VP_PDIR_PDIR10_SHIFT          0x0000000Au
  #define  VP_PDIR_PDIR10_DEFAULT        0x00000000u
  #define  VP_PDIR_PDIR10_OF(x)          _VALUEOF(x)
  #define  VP_PDIR_PDIR10_VDATA10TO11IN  0x00000000u
  #define  VP_PDIR_PDIR10_VDATA10TO11OUT 0x00000001u
  
  #define _VP_PDIR_PDIR8_MASK            0x00000100u
  #define _VP_PDIR_PDIR8_SHIFT           0x00000008u
  #define  VP_PDIR_PDIR8_DEFAULT         0x00000000u
  #define  VP_PDIR_PDIR8_OF(x)           _VALUEOF(x)
  #define  VP_PDIR_PDIR8_VDATA8TO9IN     0x00000000u
  #define  VP_PDIR_PDIR8_VDATA8TO9OUT    0x00000001u
  
  #define _VP_PDIR_PDIR4_MASK            0x00000010u
  #define _VP_PDIR_PDIR4_SHIFT           0x00000004u
  #define  VP_PDIR_PDIR4_DEFAULT         0x00000000u
  #define  VP_PDIR_PDIR4_OF(x)           _VALUEOF(x)
  #define  VP_PDIR_PDIR4_VDATA4TO7IN     0x00000000u
  #define  VP_PDIR_PDIR4_VDATA4TO7OUT    0x00000001u
  
  #define _VP_PDIR_PDIR0_MASK            0x00000001u
  #define _VP_PDIR_PDIR0_SHIFT           0x00000000u
  #define  VP_PDIR_PDIR0_DEFAULT         0x00000000u
  #define  VP_PDIR_PDIR0_OF(x)           _VALUEOF(x)
  #define  VP_PDIR_PDIR0_VDATA0TO3IN     0x00000000u
  #define  VP_PDIR_PDIR0_VDATA0TO3OUT    0x00000001u
  
  #define  VP_PDIR_OF(x)             _VALUEOF(x)

  #define VP_PDIR_DEFAULT (Uint32)(\
    _PER_FDEFAULT(VP,PDIR,PDIR22)\
   |_PER_FDEFAULT(VP,PDIR,PDIR21)\
   |_PER_FDEFAULT(VP,PDIR,PDIR20)\
   |_PER_FDEFAULT(VP,PDIR,PDIR16)\
   |_PER_FDEFAULT(VP,PDIR,PDIR12)\
   |_PER_FDEFAULT(VP,PDIR,PDIR10)\
   |_PER_FDEFAULT(VP,PDIR,PDIR8)\
   |_PER_FDEFAULT(VP,PDIR,PDIR4)\
   |_PER_FDEFAULT(VP,PDIR,PDIR0)\
  )

#define VP_PDIR_RMK(pdir22,pdir21,pdir20,pdir16,\
  pdir12,pdir10,pdir8,pdir4,pdir0) (Uint32)(\
    _PER_FMK(VP,PDIR,PDIR22,pdir22)\
   |_PER_FMK(VP,PDIR,PDIR21,pdir21)\
   |_PER_FMK(VP,PDIR,PDIR20,pdir20)\
   |_PER_FMK(VP,PDIR,PDIR16,pdir16)\
   |_PER_FMK(VP,PDIR,PDIR12,pdir12)\
   |_PER_FMK(VP,PDIR,PDIR10,pdir10)\
   |_PER_FMK(VP,PDIR,PDIR8,pdir8)\
   |_PER_FMK(VP,PDIR,PDIR4,pdir4)\
   |_PER_FMK(VP,PDIR,PDIR0,pdir0)\
  )

  #define _VP_PDIR_FGET(N,FIELD)\
    _PER_FGET(_VP_PDIR##N##_ADDR,VP,PDIR,##FIELD)

  #define _VP_PDIR_FSET(N,FIELD,field)\
    _PER_FSET(_VP_PDIR##N##_ADDR,VP,PDIR,##FIELD,field)

  #define _VP_PDIR_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_PDIR##N##_ADDR,VP,PDIR,##FIELD,##SYM)

  #define _VP_PDIR0_FGET(FIELD)   _VP_PDIR_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PDIR1_FGET(FIELD)   _VP_PDIR_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_PDIR2_FGET(FIELD)   _VP_PDIR_FGET(2,##FIELD)
 #endif


  #define _VP_PDIR0_FSET(FIELD,f)   _VP_PDIR_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PDIR1_FSET(FIELD,f)   _VP_PDIR_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_PDIR2_FSET(FIELD,f)   _VP_PDIR_FSET(2,##FIELD,f)
 #endif


  #define _VP_PDIR0_FSETS(FIELD,SYM)   _VP_PDIR_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PDIR1_FSETS(FIELD,SYM)   _VP_PDIR_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_PDIR2_FSETS(FIELD,SYM)   _VP_PDIR_FSETS(2,##FIELD,##SYM)
 #endif

  
/******************************************************************************\
* _____________________
* |                   |
* |  P D I N          |
* |___________________|
*
* PDIN0  - Video Port 0 Pin Data In Register
* PDIN1  - Video Port 1 Pin Data In Register
* PDIN2  - Video Port 2 Pin Data In Register
*
* FIELDS (msb -> lsb)
* (r) PDIN22
* (r) PDIN21
* (r) PDIN20
* (r) PDIN19
* (r) PDIN18
* (r) PDIN17
* (r) PDIN16
* (r) PDIN15
* (r) PDIN14
* (r) PDIN13
* (r) PDIN12
* (r) PDIN11
* (r) PDIN10
* (r) PDIN9
* (r) PDIN8
* (r) PDIN7
* (r) PDIN6
* (r) PDIN5
* (r) PDIN4
* (r) PDIN3
* (r) PDIN2
* (r) PDIN1
* (r) PDIN0
*
\******************************************************************************/
  #define _VP_PDIN_OFFSET            10

  #define _VP_PDIN0_ADDR   (_VP_BASE_PORT0 + 4*_VP_PDIN_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PDIN1_ADDR   (_VP_BASE_PORT1 + 4*_VP_PDIN_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_PDIN2_ADDR   (_VP_BASE_PORT2 + 4*_VP_PDIN_OFFSET)
 #endif


  #define _VP_PDIN_PDIN22_MASK           0x00400000u
  #define _VP_PDIN_PDIN22_SHIFT          0x00000016u
  #define  VP_PDIN_PDIN22_DEFAULT        0x00000000u
  #define  VP_PDIN_PDIN22_OF(x)          _VALUEOF(x)
  #define  VP_PDIN_PDIN22_VCTL2LO        0x00000000u
  #define  VP_PDIN_PDIN22_VCTL2HI        0x00000001u
  
  #define _VP_PDIN_PDIN21_MASK           0x00200000u
  #define _VP_PDIN_PDIN21_SHIFT          0x00000015u
  #define  VP_PDIN_PDIN21_DEFAULT        0x00000000u
  #define  VP_PDIN_PDIN21_OF(x)          _VALUEOF(x)
  #define  VP_PDIN_PDIN21_VCTL1LO        0x00000000u
  #define  VP_PDIN_PDIN21_VCTL1HI        0x00000001u
  
  #define _VP_PDIN_PDIN20_MASK           0x00100000u
  #define _VP_PDIN_PDIN20_SHIFT          0x00000014u
  #define  VP_PDIN_PDIN20_DEFAULT        0x00000000u
  #define  VP_PDIN_PDIN20_OF(x)          _VALUEOF(x)
  #define  VP_PDIN_PDIN20_VCTL0LO        0x00000000u
  #define  VP_PDIN_PDIN20_VCTL0HI        0x00000001u
  
  #define _VP_PDIN_PDIN19_MASK           0x00080000u
  #define _VP_PDIN_PDIN19_SHIFT          0x00000013u
  #define  VP_PDIN_PDIN19_DEFAULT        0x00000000u
  #define  VP_PDIN_PDIN19_OF(x)          _VALUEOF(x)
  #define  VP_PDIN_PDIN19_VDATA19LO      0x00000000u
  #define  VP_PDIN_PDIN19_VDATA19HI      0x00000001u
  
  #define _VP_PDIN_PDIN18_MASK           0x00040000u
  #define _VP_PDIN_PDIN18_SHIFT          0x00000012u
  #define  VP_PDIN_PDIN18_DEFAULT        0x00000000u
  #define  VP_PDIN_PDIN18_OF(x)          _VALUEOF(x)
  #define  VP_PDIN_PDIN18_VDATA18LO      0x00000000u
  #define  VP_PDIN_PDIN18_VDATA18HI      0x00000001u
  
  #define _VP_PDIN_PDIN17_MASK           0x00020000u
  #define _VP_PDIN_PDIN17_SHIFT          0x00000011u
  #define  VP_PDIN_PDIN17_DEFAULT        0x00000000u
  #define  VP_PDIN_PDIN17_OF(x)          _VALUEOF(x)
  #define  VP_PDIN_PDIN17_VDATA17LO      0x00000000u
  #define  VP_PDIN_PDIN17_VDATA17HI      0x00000001u
  
  #define _VP_PDIN_PDIN16_MASK           0x00010000u
  #define _VP_PDIN_PDIN16_SHIFT          0x00000010u
  #define  VP_PDIN_PDIN16_DEFAULT        0x00000000u
  #define  VP_PDIN_PDIN16_OF(x)          _VALUEOF(x)
  #define  VP_PDIN_PDIN16_VDATA16LO      0x00000000u
  #define  VP_PDIN_PDIN16_VDATA16HI      0x00000001u
  
  #define _VP_PDIN_PDIN15_MASK           0x00008000u
  #define _VP_PDIN_PDIN15_SHIFT          0x0000000Fu
  #define  VP_PDIN_PDIN15_DEFAULT        0x00000000u
  #define  VP_PDIN_PDIN15_OF(x)          _VALUEOF(x)
  #define  VP_PDIN_PDIN15_VDATA15LO      0x00000000u
  #define  VP_PDIN_PDIN15_VDATA15HI      0x00000001u
  
  #define _VP_PDIN_PDIN14_MASK           0x00004000u
  #define _VP_PDIN_PDIN14_SHIFT          0x0000000Eu
  #define  VP_PDIN_PDIN14_DEFAULT        0x00000000u
  #define  VP_PDIN_PDIN14_OF(x)          _VALUEOF(x)
  #define  VP_PDIN_PDIN14_VDATA14LO      0x00000000u
  #define  VP_PDIN_PDIN14_VDATA14HI      0x00000001u
  
  #define _VP_PDIN_PDIN13_MASK           0x00002000u
  #define _VP_PDIN_PDIN13_SHIFT          0x0000000Du
  #define  VP_PDIN_PDIN13_DEFAULT        0x00000000u
  #define  VP_PDIN_PDIN13_OF(x)          _VALUEOF(x)
  #define  VP_PDIN_PDIN13_VDATA13LO      0x00000000u
  #define  VP_PDIN_PDIN13_VDATA13HI      0x00000001u
  
  #define _VP_PDIN_PDIN12_MASK           0x00001000u
  #define _VP_PDIN_PDIN12_SHIFT          0x0000000Cu
  #define  VP_PDIN_PDIN12_DEFAULT        0x00000000u
  #define  VP_PDIN_PDIN12_OF(x)          _VALUEOF(x)
  #define  VP_PDIN_PDIN12_VDATA12LO      0x00000000u
  #define  VP_PDIN_PDIN12_VDATA12HI      0x00000001u
  
  #define _VP_PDIN_PDIN11_MASK           0x00000800u
  #define _VP_PDIN_PDIN11_SHIFT          0x0000000Bu
  #define  VP_PDIN_PDIN11_DEFAULT        0x00000000u
  #define  VP_PDIN_PDIN11_OF(x)          _VALUEOF(x)
  #define  VP_PDIN_PDIN11_VDATA11LO      0x00000000u
  #define  VP_PDIN_PDIN11_VDATA11HI      0x00000001u
  
  #define _VP_PDIN_PDIN10_MASK           0x00000400u
  #define _VP_PDIN_PDIN10_SHIFT          0x0000000Au
  #define  VP_PDIN_PDIN10_DEFAULT        0x00000000u
  #define  VP_PDIN_PDIN10_OF(x)          _VALUEOF(x)
  #define  VP_PDIN_PDIN10_VDATA10LO      0x00000000u
  #define  VP_PDIN_PDIN10_VDATA10HI      0x00000001u
  
  #define _VP_PDIN_PDIN9_MASK            0x00000200u
  #define _VP_PDIN_PDIN9_SHIFT           0x00000009u
  #define  VP_PDIN_PDIN9_DEFAULT         0x00000000u
  #define  VP_PDIN_PDIN9_OF(x)           _VALUEOF(x)
  #define  VP_PDIN_PDIN9_VDATA9LO        0x00000000u
  #define  VP_PDIN_PDIN9_VDATA9HI        0x00000001u
  
  #define _VP_PDIN_PDIN8_MASK            0x00000100u
  #define _VP_PDIN_PDIN8_SHIFT           0x00000008u
  #define  VP_PDIN_PDIN8_DEFAULT         0x00000000u
  #define  VP_PDIN_PDIN8_OF(x)           _VALUEOF(x)
  #define  VP_PDIN_PDIN8_VDATA8LO        0x00000000u
  #define  VP_PDIN_PDIN8_VDATA8HI        0x00000001u
  
  #define _VP_PDIN_PDIN7_MASK            0x00000080u
  #define _VP_PDIN_PDIN7_SHIFT           0x00000007u
  #define  VP_PDIN_PDIN7_DEFAULT         0x00000000u
  #define  VP_PDIN_PDIN7_OF(x)           _VALUEOF(x)
  #define  VP_PDIN_PDIN7_VDATA7LO        0x00000000u
  #define  VP_PDIN_PDIN7_VDATA7HI        0x00000001u
  
  #define _VP_PDIN_PDIN6_MASK            0x00000040u
  #define _VP_PDIN_PDIN6_SHIFT           0x00000006u
  #define  VP_PDIN_PDIN6_DEFAULT         0x00000000u
  #define  VP_PDIN_PDIN6_OF(x)           _VALUEOF(x)
  #define  VP_PDIN_PDIN6_VDATA6LO        0x00000000u
  #define  VP_PDIN_PDIN6_VDATA6HI        0x00000001u
  
  #define _VP_PDIN_PDIN5_MASK            0x00000020u
  #define _VP_PDIN_PDIN5_SHIFT           0x00000005u
  #define  VP_PDIN_PDIN5_DEFAULT         0x00000000u
  #define  VP_PDIN_PDIN5_OF(x)           _VALUEOF(x)
  #define  VP_PDIN_PDIN5_VDATA5LO        0x00000000u
  #define  VP_PDIN_PDIN5_VDATA5HI        0x00000001u
  
  #define _VP_PDIN_PDIN4_MASK            0x00000010u
  #define _VP_PDIN_PDIN4_SHIFT           0x00000004u
  #define  VP_PDIN_PDIN4_DEFAULT         0x00000000u
  #define  VP_PDIN_PDIN4_OF(x)           _VALUEOF(x)
  #define  VP_PDIN_PDIN4_VDATA4LO        0x00000000u
  #define  VP_PDIN_PDIN4_VDATA4HI        0x00000001u
  
  #define _VP_PDIN_PDIN3_MASK            0x00000008u
  #define _VP_PDIN_PDIN3_SHIFT           0x00000003u
  #define  VP_PDIN_PDIN3_DEFAULT         0x00000000u
  #define  VP_PDIN_PDIN3_OF(x)           _VALUEOF(x)
  #define  VP_PDIN_PDIN3_VDATA3LO        0x00000000u
  #define  VP_PDIN_PDIN3_VDATA3HI        0x00000001u
  
  #define _VP_PDIN_PDIN2_MASK            0x00000004u
  #define _VP_PDIN_PDIN2_SHIFT           0x00000002u
  #define  VP_PDIN_PDIN2_DEFAULT         0x00000000u
  #define  VP_PDIN_PDIN2_OF(x)           _VALUEOF(x)
  #define  VP_PDIN_PDIN2_VDATA2LO        0x00000000u
  #define  VP_PDIN_PDIN2_VDATA2HI        0x00000001u
  
  #define _VP_PDIN_PDIN1_MASK            0x00000002u
  #define _VP_PDIN_PDIN1_SHIFT           0x00000001u
  #define  VP_PDIN_PDIN1_DEFAULT         0x00000000u
  #define  VP_PDIN_PDIN1_OF(x)           _VALUEOF(x)
  #define  VP_PDIN_PDIN1_VDATA1LO        0x00000000u
  #define  VP_PDIN_PDIN1_VDATA1HI        0x00000001u
  
  #define _VP_PDIN_PDIN0_MASK            0x00000001u
  #define _VP_PDIN_PDIN0_SHIFT           0x00000000u
  #define  VP_PDIN_PDIN0_DEFAULT         0x00000000u
  #define  VP_PDIN_PDIN0_OF(x)           _VALUEOF(x)
  #define  VP_PDIN_PDIN0_VDATA0LO        0x00000000u
  #define  VP_PDIN_PDIN0_VDATA0HI        0x00000001u
  
  #define  VP_PDIN_OF(x)             _VALUEOF(x)

  #define VP_PDIN_DEFAULT (Uint32)(\
    _PER_FDEFAULT(VP,PDIN,PDIN22)\
   |_PER_FDEFAULT(VP,PDIN,PDIN21)\
   |_PER_FDEFAULT(VP,PDIN,PDIN20)\
   |_PER_FDEFAULT(VP,PDIN,PDIN19)\
   |_PER_FDEFAULT(VP,PDIN,PDIN18)\
   |_PER_FDEFAULT(VP,PDIN,PDIN17)\
   |_PER_FDEFAULT(VP,PDIN,PDIN16)\
   |_PER_FDEFAULT(VP,PDIN,PDIN15)\
   |_PER_FDEFAULT(VP,PDIN,PDIN14)\
   |_PER_FDEFAULT(VP,PDIN,PDIN13)\
   |_PER_FDEFAULT(VP,PDIN,PDIN12)\
   |_PER_FDEFAULT(VP,PDIN,PDIN11)\
   |_PER_FDEFAULT(VP,PDIN,PDIN10)\
   |_PER_FDEFAULT(VP,PDIN,PDIN9)\
   |_PER_FDEFAULT(VP,PDIN,PDIN8)\
   |_PER_FDEFAULT(VP,PDIN,PDIN7)\
   |_PER_FDEFAULT(VP,PDIN,PDIN6)\
   |_PER_FDEFAULT(VP,PDIN,PDIN5)\
   |_PER_FDEFAULT(VP,PDIN,PDIN4)\
   |_PER_FDEFAULT(VP,PDIN,PDIN3)\
   |_PER_FDEFAULT(VP,PDIN,PDIN2)\
   |_PER_FDEFAULT(VP,PDIN,PDIN1)\
   |_PER_FDEFAULT(VP,PDIN,PDIN0)\
  )
#if (!(CHIP_6413 | CHIP_6418 | CHIP_6410))
  #define VP_PDIN_RMK(pdin22,pdin21,pdin20,pdin19,pdin18,pdin17,pdin16,\
  pdin15,pdin14,pdin13,pdin12,pdin11,pdin10,pdin9,pdin8,pdin7,\
  pdin6,pdin5,pdin4,pdin3,pdin2,pdin1,pdin0) (Uint32)(\
    _PER_FMK(VP,PDIN,PDIN22,pdin22)\
   |_PER_FMK(VP,PDIN,PDIN21,pdin21)\
   |_PER_FMK(VP,PDIN,PDIN20,pdin20)\
   |_PER_FMK(VP,PDIN,PDIN19,pdin19)\
   |_PER_FMK(VP,PDIN,PDIN18,pdin18)\
   |_PER_FMK(VP,PDIN,PDIN17,pdin17)\
   |_PER_FMK(VP,PDIN,PDIN16,pdin16)\
   |_PER_FMK(VP,PDIN,PDIN15,pdin15)\
   |_PER_FMK(VP,PDIN,PDIN14,pdin14)\
   |_PER_FMK(VP,PDIN,PDIN13,pdin13)\
   |_PER_FMK(VP,PDIN,PDIN12,pdin12)\
   |_PER_FMK(VP,PDIN,PDIN11,pdin11)\
   |_PER_FMK(VP,PDIN,PDIN10,pdin10)\
   |_PER_FMK(VP,PDIN,PDIN9,pdin9)\
   |_PER_FMK(VP,PDIN,PDIN8,pdin8)\
   |_PER_FMK(VP,PDIN,PDIN7,pdin7)\
   |_PER_FMK(VP,PDIN,PDIN6,pdin6)\
   |_PER_FMK(VP,PDIN,PDIN5,pdin5)\
   |_PER_FMK(VP,PDIN,PDIN4,pdin4)\
   |_PER_FMK(VP,PDIN,PDIN3,pdin3)\
   |_PER_FMK(VP,PDIN,PDIN2,pdin2)\
   |_PER_FMK(VP,PDIN,PDIN1,pdin1)\
   |_PER_FMK(VP,PDIN,PDIN0,pdin0)\
   )
#endif   
  #define _VP_PDIN_FGET(N,FIELD)\
    _PER_FGET(_VP_PDIN##N##_ADDR,VP,PDIN,##FIELD)

  #define _VP_PDIN_FSET(N,FIELD,field)\
    _PER_FSET(_VP_PDIN##N##_ADDR,VP,PDIN,##FIELD,field)

  #define _VP_PDIN_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_PDIN##N##_ADDR,VP,PDIN,##FIELD,##SYM)

  #define _VP_PDIN0_FGET(FIELD)   _VP_PDIN_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PDIN1_FGET(FIELD)   _VP_PDIN_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_PDIN2_FGET(FIELD)   _VP_PDIN_FGET(2,##FIELD)
 #endif


  #define _VP_PDIN0_FSET(FIELD,f)   _VP_PDIN_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PDIN1_FSET(FIELD,f)   _VP_PDIN_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_PDIN2_FSET(FIELD,f)   _VP_PDIN_FSET(2,##FIELD,f)
 #endif


  #define _VP_PDIN0_FSETS(FIELD,SYM)   _VP_PDIN_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PDIN1_FSETS(FIELD,SYM)   _VP_PDIN_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_PDIN2_FSETS(FIELD,SYM)   _VP_PDIN_FSETS(2,##FIELD,##SYM)
 #endif

  
/******************************************************************************\
* _____________________
* |                   |
* |  P D O U T        |
* |___________________|
*
* PDOUT0  - Video Port 0 Pin Data Out Register
* PDOUT1  - Video Port 1 Pin Data Out Register
* PDOUT2  - Video Port 2 Pin Data Out Register
*
* FIELDS (msb -> lsb)
* (rw) PDOUT22
* (rw) PDOUT21
* (rw) PDOUT20
* (rw) PDOUT19
* (rw) PDOUT18
* (rw) PDOUT17
* (rw) PDOUT16
* (rw) PDOUT15
* (rw) PDOUT14
* (rw) PDOUT13
* (rw) PDOUT12
* (rw) PDOUT11
* (rw) PDOUT10
* (rw) PDOUT9
* (rw) PDOUT8
* (rw) PDOUT7
* (rw) PDOUT6
* (rw) PDOUT5
* (rw) PDOUT4
* (rw) PDOUT3
* (rw) PDOUT2
* (rw) PDOUT1
* (rw) PDOUT0
*
\******************************************************************************/
  #define _VP_PDOUT_OFFSET            11

  #define _VP_PDOUT0_ADDR   (_VP_BASE_PORT0 + 4*_VP_PDOUT_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PDOUT1_ADDR   (_VP_BASE_PORT1 + 4*_VP_PDOUT_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_PDOUT2_ADDR   (_VP_BASE_PORT2 + 4*_VP_PDOUT_OFFSET)
 #endif


  #define _VP_PDOUT_PDOUT22_MASK           0x00400000u
  #define _VP_PDOUT_PDOUT22_SHIFT          0x00000016u
  #define  VP_PDOUT_PDOUT22_DEFAULT        0x00000000u
  #define  VP_PDOUT_PDOUT22_OF(x)          _VALUEOF(x)
  #define  VP_PDOUT_PDOUT22_VCTL2LO        0x00000000u
  #define  VP_PDOUT_PDOUT22_VCTL2HI        0x00000001u
  
  #define _VP_PDOUT_PDOUT21_MASK           0x00200000u
  #define _VP_PDOUT_PDOUT21_SHIFT          0x00000015u
  #define  VP_PDOUT_PDOUT21_DEFAULT        0x00000000u
  #define  VP_PDOUT_PDOUT21_OF(x)          _VALUEOF(x)
  #define  VP_PDOUT_PDOUT21_VCTL1LO        0x00000000u
  #define  VP_PDOUT_PDOUT21_VCTL1HI        0x00000001u
  
  #define _VP_PDOUT_PDOUT20_MASK           0x00100000u
  #define _VP_PDOUT_PDOUT20_SHIFT          0x00000014u
  #define  VP_PDOUT_PDOUT20_DEFAULT        0x00000000u
  #define  VP_PDOUT_PDOUT20_OF(x)          _VALUEOF(x)
  #define  VP_PDOUT_PDOUT20_VCTL0LO        0x00000000u
  #define  VP_PDOUT_PDOUT20_VCTL0HI        0x00000001u
  
  #define _VP_PDOUT_PDOUT19_MASK           0x00080000u
  #define _VP_PDOUT_PDOUT19_SHIFT          0x00000013u
  #define  VP_PDOUT_PDOUT19_DEFAULT        0x00000000u
  #define  VP_PDOUT_PDOUT19_OF(x)          _VALUEOF(x)
  #define  VP_PDOUT_PDOUT19_VDATA19LO      0x00000000u
  #define  VP_PDOUT_PDOUT19_VDATA19HI      0x00000001u
  
  #define _VP_PDOUT_PDOUT18_MASK           0x00040000u
  #define _VP_PDOUT_PDOUT18_SHIFT          0x00000012u
  #define  VP_PDOUT_PDOUT18_DEFAULT        0x00000000u
  #define  VP_PDOUT_PDOUT18_OF(x)          _VALUEOF(x)
  #define  VP_PDOUT_PDOUT18_VDATA18LO      0x00000000u
  #define  VP_PDOUT_PDOUT18_VDATA18HI      0x00000001u
  
  #define _VP_PDOUT_PDOUT17_MASK           0x00020000u
  #define _VP_PDOUT_PDOUT17_SHIFT          0x00000011u
  #define  VP_PDOUT_PDOUT17_DEFAULT        0x00000000u
  #define  VP_PDOUT_PDOUT17_OF(x)          _VALUEOF(x)
  #define  VP_PDOUT_PDOUT17_VDATA17LO      0x00000000u
  #define  VP_PDOUT_PDOUT17_VDATA17HI      0x00000001u
  
  #define _VP_PDOUT_PDOUT16_MASK           0x00010000u
  #define _VP_PDOUT_PDOUT16_SHIFT          0x00000010u
  #define  VP_PDOUT_PDOUT16_DEFAULT        0x00000000u
  #define  VP_PDOUT_PDOUT16_OF(x)          _VALUEOF(x)
  #define  VP_PDOUT_PDOUT16_VDATA16LO      0x00000000u
  #define  VP_PDOUT_PDOUT16_VDATA16HI      0x00000001u
  
  #define _VP_PDOUT_PDOUT15_MASK           0x00008000u
  #define _VP_PDOUT_PDOUT15_SHIFT          0x0000000Fu
  #define  VP_PDOUT_PDOUT15_DEFAULT        0x00000000u
  #define  VP_PDOUT_PDOUT15_OF(x)          _VALUEOF(x)
  #define  VP_PDOUT_PDOUT15_VDATA15LO      0x00000000u
  #define  VP_PDOUT_PDOUT15_VDATA15HI      0x00000001u
  
  #define _VP_PDOUT_PDOUT14_MASK           0x00004000u
  #define _VP_PDOUT_PDOUT14_SHIFT          0x0000000Eu
  #define  VP_PDOUT_PDOUT14_DEFAULT        0x00000000u
  #define  VP_PDOUT_PDOUT14_OF(x)          _VALUEOF(x)
  #define  VP_PDOUT_PDOUT14_VDATA14LO      0x00000000u
  #define  VP_PDOUT_PDOUT14_VDATA14HI      0x00000001u
  
  #define _VP_PDOUT_PDOUT13_MASK           0x00002000u
  #define _VP_PDOUT_PDOUT13_SHIFT          0x0000000Du
  #define  VP_PDOUT_PDOUT13_DEFAULT        0x00000000u
  #define  VP_PDOUT_PDOUT13_OF(x)          _VALUEOF(x)
  #define  VP_PDOUT_PDOUT13_VDATA13LO      0x00000000u
  #define  VP_PDOUT_PDOUT13_VDATA13HI      0x00000001u
  
  #define _VP_PDOUT_PDOUT12_MASK           0x00001000u
  #define _VP_PDOUT_PDOUT12_SHIFT          0x0000000Cu
  #define  VP_PDOUT_PDOUT12_DEFAULT        0x00000000u
  #define  VP_PDOUT_PDOUT12_OF(x)          _VALUEOF(x)
  #define  VP_PDOUT_PDOUT12_VDATA12LO      0x00000000u
  #define  VP_PDOUT_PDOUT12_VDATA12HI      0x00000001u
  
  #define _VP_PDOUT_PDOUT11_MASK           0x00000800u
  #define _VP_PDOUT_PDOUT11_SHIFT          0x0000000Bu
  #define  VP_PDOUT_PDOUT11_DEFAULT        0x00000000u
  #define  VP_PDOUT_PDOUT11_OF(x)          _VALUEOF(x)
  #define  VP_PDOUT_PDOUT11_VDATA11LO      0x00000000u
  #define  VP_PDOUT_PDOUT11_VDATA11HI      0x00000001u
  
  #define _VP_PDOUT_PDOUT10_MASK           0x00000400u
  #define _VP_PDOUT_PDOUT10_SHIFT          0x0000000Au
  #define  VP_PDOUT_PDOUT10_DEFAULT        0x00000000u
  #define  VP_PDOUT_PDOUT10_OF(x)          _VALUEOF(x)
  #define  VP_PDOUT_PDOUT10_VDATA10LO      0x00000000u
  #define  VP_PDOUT_PDOUT10_VDATA10HI      0x00000001u
  
  #define _VP_PDOUT_PDOUT9_MASK            0x00000200u
  #define _VP_PDOUT_PDOUT9_SHIFT           0x00000009u
  #define  VP_PDOUT_PDOUT9_DEFAULT         0x00000000u
  #define  VP_PDOUT_PDOUT9_OF(x)           _VALUEOF(x)
  #define  VP_PDOUT_PDOUT9_VDATA9LO        0x00000000u
  #define  VP_PDOUT_PDOUT9_VDATA9HI        0x00000001u
  
  #define _VP_PDOUT_PDOUT8_MASK            0x00000100u
  #define _VP_PDOUT_PDOUT8_SHIFT           0x00000008u
  #define  VP_PDOUT_PDOUT8_DEFAULT         0x00000000u
  #define  VP_PDOUT_PDOUT8_OF(x)           _VALUEOF(x)
  #define  VP_PDOUT_PDOUT8_VDATA8LO        0x00000000u
  #define  VP_PDOUT_PDOUT8_VDATA8HI        0x00000001u
  
  #define _VP_PDOUT_PDOUT7_MASK            0x00000080u
  #define _VP_PDOUT_PDOUT7_SHIFT           0x00000007u
  #define  VP_PDOUT_PDOUT7_DEFAULT         0x00000000u
  #define  VP_PDOUT_PDOUT7_OF(x)           _VALUEOF(x)
  #define  VP_PDOUT_PDOUT7_VDATA7LO        0x00000000u
  #define  VP_PDOUT_PDOUT7_VDATA7HI        0x00000001u
  
  #define _VP_PDOUT_PDOUT6_MASK            0x00000040u
  #define _VP_PDOUT_PDOUT6_SHIFT           0x00000006u
  #define  VP_PDOUT_PDOUT6_DEFAULT         0x00000000u
  #define  VP_PDOUT_PDOUT6_OF(x)           _VALUEOF(x)
  #define  VP_PDOUT_PDOUT6_VDATA6LO        0x00000000u
  #define  VP_PDOUT_PDOUT6_VDATA6HI        0x00000001u
  
  #define _VP_PDOUT_PDOUT5_MASK            0x00000020u
  #define _VP_PDOUT_PDOUT5_SHIFT           0x00000005u
  #define  VP_PDOUT_PDOUT5_DEFAULT         0x00000000u
  #define  VP_PDOUT_PDOUT5_OF(x)           _VALUEOF(x)
  #define  VP_PDOUT_PDOUT5_VDATA5LO        0x00000000u
  #define  VP_PDOUT_PDOUT5_VDATA5HI        0x00000001u
  
  #define _VP_PDOUT_PDOUT4_MASK            0x00000010u
  #define _VP_PDOUT_PDOUT4_SHIFT           0x00000004u
  #define  VP_PDOUT_PDOUT4_DEFAULT         0x00000000u
  #define  VP_PDOUT_PDOUT4_OF(x)           _VALUEOF(x)
  #define  VP_PDOUT_PDOUT4_VDATA4LO        0x00000000u
  #define  VP_PDOUT_PDOUT4_VDATA4HI        0x00000001u
  
  #define _VP_PDOUT_PDOUT3_MASK            0x00000008u
  #define _VP_PDOUT_PDOUT3_SHIFT           0x00000003u
  #define  VP_PDOUT_PDOUT3_DEFAULT         0x00000000u
  #define  VP_PDOUT_PDOUT3_OF(x)           _VALUEOF(x)
  #define  VP_PDOUT_PDOUT3_VDATA3LO        0x00000000u
  #define  VP_PDOUT_PDOUT3_VDATA3HI        0x00000001u
  
  #define _VP_PDOUT_PDOUT2_MASK            0x00000004u
  #define _VP_PDOUT_PDOUT2_SHIFT           0x00000002u
  #define  VP_PDOUT_PDOUT2_DEFAULT         0x00000000u
  #define  VP_PDOUT_PDOUT2_OF(x)           _VALUEOF(x)
  #define  VP_PDOUT_PDOUT2_VDATA2LO        0x00000000u
  #define  VP_PDOUT_PDOUT2_VDATA2HI        0x00000001u
  
  #define _VP_PDOUT_PDOUT1_MASK            0x00000002u
  #define _VP_PDOUT_PDOUT1_SHIFT           0x00000001u
  #define  VP_PDOUT_PDOUT1_DEFAULT         0x00000000u
  #define  VP_PDOUT_PDOUT1_OF(x)           _VALUEOF(x)
  #define  VP_PDOUT_PDOUT1_VDATA1LO        0x00000000u
  #define  VP_PDOUT_PDOUT1_VDATA1HI        0x00000001u
  
  #define _VP_PDOUT_PDOUT0_MASK            0x00000001u
  #define _VP_PDOUT_PDOUT0_SHIFT           0x00000000u
  #define  VP_PDOUT_PDOUT0_DEFAULT         0x00000000u
  #define  VP_PDOUT_PDOUT0_OF(x)           _VALUEOF(x)
  #define  VP_PDOUT_PDOUT0_VDATA0LO        0x00000000u
  #define  VP_PDOUT_PDOUT0_VDATA0HI        0x00000001u
  
  #define  VP_PDOUT_OF(x)             _VALUEOF(x)

  #define VP_PDOUT_DEFAULT (Uint32)(\
    _PER_FDEFAULT(VP,PDOUT,PDOUT22)\
   |_PER_FDEFAULT(VP,PDOUT,PDOUT21)\
   |_PER_FDEFAULT(VP,PDOUT,PDOUT20)\
   |_PER_FDEFAULT(VP,PDOUT,PDOUT19)\
   |_PER_FDEFAULT(VP,PDOUT,PDOUT18)\
   |_PER_FDEFAULT(VP,PDOUT,PDOUT17)\
   |_PER_FDEFAULT(VP,PDOUT,PDOUT16)\
   |_PER_FDEFAULT(VP,PDOUT,PDOUT15)\
   |_PER_FDEFAULT(VP,PDOUT,PDOUT14)\
   |_PER_FDEFAULT(VP,PDOUT,PDOUT13)\
   |_PER_FDEFAULT(VP,PDOUT,PDOUT12)\
   |_PER_FDEFAULT(VP,PDOUT,PDOUT11)\
   |_PER_FDEFAULT(VP,PDOUT,PDOUT10)\
   |_PER_FDEFAULT(VP,PDOUT,PDOUT9)\
   |_PER_FDEFAULT(VP,PDOUT,PDOUT8)\
   |_PER_FDEFAULT(VP,PDOUT,PDOUT7)\
   |_PER_FDEFAULT(VP,PDOUT,PDOUT6)\
   |_PER_FDEFAULT(VP,PDOUT,PDOUT5)\
   |_PER_FDEFAULT(VP,PDOUT,PDOUT4)\
   |_PER_FDEFAULT(VP,PDOUT,PDOUT3)\
   |_PER_FDEFAULT(VP,PDOUT,PDOUT2)\
   |_PER_FDEFAULT(VP,PDOUT,PDOUT1)\
   |_PER_FDEFAULT(VP,PDOUT,PDOUT0)\
  )

#define VP_PDOUT_RMK(pdout22,pdout21,pdout20,pdout19,pdout18,pdout17,pdout16,\
  pdout15,pdout14,pdout13,pdout12,pdout11,pdout10,pdout9,pdout8,pdout7,\
  pdout6,pdout5,pdout4,pdout3,pdout2,pdout1,pdout0) (Uint32)(\
    _PER_FMK(VP,PDOUT,PDOUT22,pdout22)\
   |_PER_FMK(VP,PDOUT,PDOUT21,pdout21)\
   |_PER_FMK(VP,PDOUT,PDOUT20,pdout20)\
   |_PER_FMK(VP,PDOUT,PDOUT19,pdout19)\
   |_PER_FMK(VP,PDOUT,PDOUT18,pdout18)\
   |_PER_FMK(VP,PDOUT,PDOUT17,pdout17)\
   |_PER_FMK(VP,PDOUT,PDOUT16,pdout16)\
   |_PER_FMK(VP,PDOUT,PDOUT15,pdout15)\
   |_PER_FMK(VP,PDOUT,PDOUT14,pdout14)\
   |_PER_FMK(VP,PDOUT,PDOUT13,pdout13)\
   |_PER_FMK(VP,PDOUT,PDOUT12,pdout12)\
   |_PER_FMK(VP,PDOUT,PDOUT11,pdout11)\
   |_PER_FMK(VP,PDOUT,PDOUT10,pdout10)\
   |_PER_FMK(VP,PDOUT,PDOUT9,pdout9)\
   |_PER_FMK(VP,PDOUT,PDOUT8,pdout8)\
   |_PER_FMK(VP,PDOUT,PDOUT7,pdout7)\
   |_PER_FMK(VP,PDOUT,PDOUT6,pdout6)\
   |_PER_FMK(VP,PDOUT,PDOUT5,pdout5)\
   |_PER_FMK(VP,PDOUT,PDOUT4,pdout4)\
   |_PER_FMK(VP,PDOUT,PDOUT3,pdout3)\
   |_PER_FMK(VP,PDOUT,PDOUT2,pdout2)\
   |_PER_FMK(VP,PDOUT,PDOUT1,pdout1)\
   |_PER_FMK(VP,PDOUT,PDOUT0,pdout0)\
  )

  #define _VP_PDOUT_FGET(N,FIELD)\
    _PER_FGET(_VP_PDOUT##N##_ADDR,VP,PDOUT,##FIELD)

  #define _VP_PDOUT_FSET(N,FIELD,field)\
    _PER_FSET(_VP_PDOUT##N##_ADDR,VP,PDOUT,##FIELD,field)

  #define _VP_PDOUT_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_PDOUT##N##_ADDR,VP,PDOUT,##FIELD,##SYM)

  #define _VP_PDOUT0_FGET(FIELD)   _VP_PDOUT_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PDOUT1_FGET(FIELD)   _VP_PDOUT_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_PDOUT2_FGET(FIELD)   _VP_PDOUT_FGET(2,##FIELD)
 #endif


  #define _VP_PDOUT0_FSET(FIELD,f)   _VP_PDOUT_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PDOUT1_FSET(FIELD,f)   _VP_PDOUT_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_PDOUT2_FSET(FIELD,f)   _VP_PDOUT_FSET(2,##FIELD,f)
 #endif


  #define _VP_PDOUT0_FSETS(FIELD,SYM)   _VP_PDOUT_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PDOUT1_FSETS(FIELD,SYM)   _VP_PDOUT_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_PDOUT2_FSETS(FIELD,SYM)   _VP_PDOUT_FSETS(2,##FIELD,##SYM)
 #endif

  
/******************************************************************************\
* _____________________
* |                   |
* |  P D S E T        |
* |___________________|
*
* PDSET0  - Video Port 0 Pin Data Set Register
* PDSET1  - Video Port 1 Pin Data Set Register
* PDSET2  - Video Port 2 Pin Data Set Register
*
* FIELDS (msb -> lsb)
* (w) PDSET22
* (w) PDSET21
* (w) PDSET20
* (w) PDSET19
* (w) PDSET18
* (w) PDSET17
* (w) PDSET16
* (w) PDSET15
* (w) PDSET14
* (w) PDSET13
* (w) PDSET12
* (w) PDSET11
* (w) PDSET10
* (w) PDSET9
* (w) PDSET8
* (w) PDSET7
* (w) PDSET6
* (w) PDSET5
* (w) PDSET4
* (w) PDSET3
* (w) PDSET2
* (w) PDSET1
* (w) PDSET0
*
\******************************************************************************/
  #define _VP_PDSET_OFFSET            12

  #define _VP_PDSET0_ADDR   (_VP_BASE_PORT0 + 4*_VP_PDSET_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PDSET1_ADDR   (_VP_BASE_PORT1 + 4*_VP_PDSET_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_PDSET2_ADDR   (_VP_BASE_PORT2 + 4*_VP_PDSET_OFFSET)
 #endif


  #define _VP_PDSET_PDSET22_MASK           0x00400000u
  #define _VP_PDSET_PDSET22_SHIFT          0x00000016u
  #define  VP_PDSET_PDSET22_DEFAULT        0x00000000u
  #define  VP_PDSET_PDSET22_OF(x)          _VALUEOF(x)
  #define  VP_PDSET_PDSET22_NONE           0x00000000u
  #define  VP_PDSET_PDSET22_VCTL2HI        0x00000001u
  
  #define _VP_PDSET_PDSET21_MASK           0x00200000u
  #define _VP_PDSET_PDSET21_SHIFT          0x00000015u
  #define  VP_PDSET_PDSET21_DEFAULT        0x00000000u
  #define  VP_PDSET_PDSET21_OF(x)          _VALUEOF(x)
  #define  VP_PDSET_PDSET21_NONE           0x00000000u
  #define  VP_PDSET_PDSET21_VCTL1HI        0x00000001u
  
  #define _VP_PDSET_PDSET20_MASK           0x00100000u
  #define _VP_PDSET_PDSET20_SHIFT          0x00000014u
  #define  VP_PDSET_PDSET20_DEFAULT        0x00000000u
  #define  VP_PDSET_PDSET20_OF(x)          _VALUEOF(x)
  #define  VP_PDSET_PDSET20_NONE           0x00000000u
  #define  VP_PDSET_PDSET20_VCTL0HI        0x00000001u
  
  #define _VP_PDSET_PDSET19_MASK           0x00080000u
  #define _VP_PDSET_PDSET19_SHIFT          0x00000013u
  #define  VP_PDSET_PDSET19_DEFAULT        0x00000000u
  #define  VP_PDSET_PDSET19_OF(x)          _VALUEOF(x)
  #define  VP_PDSET_PDSET19_NONE           0x00000000u
  #define  VP_PDSET_PDSET19_VDATA19HI      0x00000001u
  
  #define _VP_PDSET_PDSET18_MASK           0x00040000u
  #define _VP_PDSET_PDSET18_SHIFT          0x00000012u
  #define  VP_PDSET_PDSET18_DEFAULT        0x00000000u
  #define  VP_PDSET_PDSET18_OF(x)          _VALUEOF(x)
  #define  VP_PDSET_PDSET18_NONE           0x00000000u
  #define  VP_PDSET_PDSET18_VDATA18HI      0x00000001u
  
  #define _VP_PDSET_PDSET17_MASK           0x00020000u
  #define _VP_PDSET_PDSET17_SHIFT          0x00000011u
  #define  VP_PDSET_PDSET17_DEFAULT        0x00000000u
  #define  VP_PDSET_PDSET17_OF(x)          _VALUEOF(x)
  #define  VP_PDSET_PDSET17_NONE           0x00000000u
  #define  VP_PDSET_PDSET17_VDATA17HI      0x00000001u
  
  #define _VP_PDSET_PDSET16_MASK           0x00010000u
  #define _VP_PDSET_PDSET16_SHIFT          0x00000010u
  #define  VP_PDSET_PDSET16_DEFAULT        0x00000000u
  #define  VP_PDSET_PDSET16_OF(x)          _VALUEOF(x)
  #define  VP_PDSET_PDSET16_NONE           0x00000000u
  #define  VP_PDSET_PDSET16_VDATA16HI      0x00000001u
  
  #define _VP_PDSET_PDSET15_MASK           0x00008000u
  #define _VP_PDSET_PDSET15_SHIFT          0x0000000Fu
  #define  VP_PDSET_PDSET15_DEFAULT        0x00000000u
  #define  VP_PDSET_PDSET15_OF(x)          _VALUEOF(x)
  #define  VP_PDSET_PDSET15_NONE           0x00000000u
  #define  VP_PDSET_PDSET15_VDATA15HI      0x00000001u
  
  #define _VP_PDSET_PDSET14_MASK           0x00004000u
  #define _VP_PDSET_PDSET14_SHIFT          0x0000000Eu
  #define  VP_PDSET_PDSET14_DEFAULT        0x00000000u
  #define  VP_PDSET_PDSET14_OF(x)          _VALUEOF(x)
  #define  VP_PDSET_PDSET14_NONE           0x00000000u
  #define  VP_PDSET_PDSET14_VDATA14HI      0x00000001u
  
  #define _VP_PDSET_PDSET13_MASK           0x00002000u
  #define _VP_PDSET_PDSET13_SHIFT          0x0000000Du
  #define  VP_PDSET_PDSET13_DEFAULT        0x00000000u
  #define  VP_PDSET_PDSET13_OF(x)          _VALUEOF(x)
  #define  VP_PDSET_PDSET13_NONE           0x00000000u
  #define  VP_PDSET_PDSET13_VDATA13HI      0x00000001u
  
  #define _VP_PDSET_PDSET12_MASK           0x00001000u
  #define _VP_PDSET_PDSET12_SHIFT          0x0000000Cu
  #define  VP_PDSET_PDSET12_DEFAULT        0x00000000u
  #define  VP_PDSET_PDSET12_OF(x)          _VALUEOF(x)
  #define  VP_PDSET_PDSET12_NONE           0x00000000u
  #define  VP_PDSET_PDSET12_VDATA12HI      0x00000001u
  
  #define _VP_PDSET_PDSET11_MASK           0x00000800u
  #define _VP_PDSET_PDSET11_SHIFT          0x0000000Bu
  #define  VP_PDSET_PDSET11_DEFAULT        0x00000000u
  #define  VP_PDSET_PDSET11_OF(x)          _VALUEOF(x)
  #define  VP_PDSET_PDSET11_NONE           0x00000000u
  #define  VP_PDSET_PDSET11_VDATA11HI      0x00000001u
  
  #define _VP_PDSET_PDSET10_MASK           0x00000400u
  #define _VP_PDSET_PDSET10_SHIFT          0x0000000Au
  #define  VP_PDSET_PDSET10_DEFAULT        0x00000000u
  #define  VP_PDSET_PDSET10_OF(x)          _VALUEOF(x)
  #define  VP_PDSET_PDSET10_NONE           0x00000000u
  #define  VP_PDSET_PDSET10_VDATA10HI      0x00000001u
  
  #define _VP_PDSET_PDSET9_MASK            0x00000200u
  #define _VP_PDSET_PDSET9_SHIFT           0x00000009u
  #define  VP_PDSET_PDSET9_DEFAULT         0x00000000u
  #define  VP_PDSET_PDSET9_OF(x)           _VALUEOF(x)
  #define  VP_PDSET_PDSET9_NONE            0x00000000u
  #define  VP_PDSET_PDSET9_VDATA9HI        0x00000001u
  
  #define _VP_PDSET_PDSET8_MASK            0x00000100u
  #define _VP_PDSET_PDSET8_SHIFT           0x00000008u
  #define  VP_PDSET_PDSET8_DEFAULT         0x00000000u
  #define  VP_PDSET_PDSET8_OF(x)           _VALUEOF(x)
  #define  VP_PDSET_PDSET8_NONE            0x00000000u
  #define  VP_PDSET_PDSET8_VDATA8HI        0x00000001u
  
  #define _VP_PDSET_PDSET7_MASK            0x00000080u
  #define _VP_PDSET_PDSET7_SHIFT           0x00000007u
  #define  VP_PDSET_PDSET7_DEFAULT         0x00000000u
  #define  VP_PDSET_PDSET7_OF(x)           _VALUEOF(x)
  #define  VP_PDSET_PDSET7_NONE            0x00000000u
  #define  VP_PDSET_PDSET7_VDATA7HI        0x00000001u
  
  #define _VP_PDSET_PDSET6_MASK            0x00000040u
  #define _VP_PDSET_PDSET6_SHIFT           0x00000006u
  #define  VP_PDSET_PDSET6_DEFAULT         0x00000000u
  #define  VP_PDSET_PDSET6_OF(x)           _VALUEOF(x)
  #define  VP_PDSET_PDSET6_NONE            0x00000000u
  #define  VP_PDSET_PDSET6_VDATA6HI        0x00000001u
  
  #define _VP_PDSET_PDSET5_MASK            0x00000020u
  #define _VP_PDSET_PDSET5_SHIFT           0x00000005u
  #define  VP_PDSET_PDSET5_DEFAULT         0x00000000u
  #define  VP_PDSET_PDSET5_OF(x)           _VALUEOF(x)
  #define  VP_PDSET_PDSET5_NONE            0x00000000u
  #define  VP_PDSET_PDSET5_VDATA5HI        0x00000001u
  
  #define _VP_PDSET_PDSET4_MASK            0x00000010u
  #define _VP_PDSET_PDSET4_SHIFT           0x00000004u
  #define  VP_PDSET_PDSET4_DEFAULT         0x00000000u
  #define  VP_PDSET_PDSET4_OF(x)           _VALUEOF(x)
  #define  VP_PDSET_PDSET4_NONE            0x00000000u
  #define  VP_PDSET_PDSET4_VDATA4HI        0x00000001u
  
  #define _VP_PDSET_PDSET3_MASK            0x00000008u
  #define _VP_PDSET_PDSET3_SHIFT           0x00000003u
  #define  VP_PDSET_PDSET3_DEFAULT         0x00000000u
  #define  VP_PDSET_PDSET3_OF(x)           _VALUEOF(x)
  #define  VP_PDSET_PDSET3_NONE            0x00000000u
  #define  VP_PDSET_PDSET3_VDATA3HI        0x00000001u
  
  #define _VP_PDSET_PDSET2_MASK            0x00000004u
  #define _VP_PDSET_PDSET2_SHIFT           0x00000002u
  #define  VP_PDSET_PDSET2_DEFAULT         0x00000000u
  #define  VP_PDSET_PDSET2_OF(x)           _VALUEOF(x)
  #define  VP_PDSET_PDSET2_NONE            0x00000000u
  #define  VP_PDSET_PDSET2_VDATA2HI        0x00000001u
  
  #define _VP_PDSET_PDSET1_MASK            0x00000002u
  #define _VP_PDSET_PDSET1_SHIFT           0x00000001u
  #define  VP_PDSET_PDSET1_DEFAULT         0x00000000u
  #define  VP_PDSET_PDSET1_OF(x)           _VALUEOF(x)
  #define  VP_PDSET_PDSET1_NONE            0x00000000u
  #define  VP_PDSET_PDSET1_VDATA1HI        0x00000001u
  
  #define _VP_PDSET_PDSET0_MASK            0x00000001u
  #define _VP_PDSET_PDSET0_SHIFT           0x00000000u
  #define  VP_PDSET_PDSET0_DEFAULT         0x00000000u
  #define  VP_PDSET_PDSET0_OF(x)           _VALUEOF(x)
  #define  VP_PDSET_PDSET0_NONE            0x00000000u
  #define  VP_PDSET_PDSET0_VDATA0HI        0x00000001u
  
  #define  VP_PDSET_OF(x)             _VALUEOF(x)

  #define VP_PDSET_DEFAULT (Uint32)(\
    _PER_FDEFAULT(VP,PDSET,PDSET22)\
   |_PER_FDEFAULT(VP,PDSET,PDSET21)\
   |_PER_FDEFAULT(VP,PDSET,PDSET20)\
   |_PER_FDEFAULT(VP,PDSET,PDSET19)\
   |_PER_FDEFAULT(VP,PDSET,PDSET18)\
   |_PER_FDEFAULT(VP,PDSET,PDSET17)\
   |_PER_FDEFAULT(VP,PDSET,PDSET16)\
   |_PER_FDEFAULT(VP,PDSET,PDSET15)\
   |_PER_FDEFAULT(VP,PDSET,PDSET14)\
   |_PER_FDEFAULT(VP,PDSET,PDSET13)\
   |_PER_FDEFAULT(VP,PDSET,PDSET12)\
   |_PER_FDEFAULT(VP,PDSET,PDSET11)\
   |_PER_FDEFAULT(VP,PDSET,PDSET10)\
   |_PER_FDEFAULT(VP,PDSET,PDSET9)\
   |_PER_FDEFAULT(VP,PDSET,PDSET8)\
   |_PER_FDEFAULT(VP,PDSET,PDSET7)\
   |_PER_FDEFAULT(VP,PDSET,PDSET6)\
   |_PER_FDEFAULT(VP,PDSET,PDSET5)\
   |_PER_FDEFAULT(VP,PDSET,PDSET4)\
   |_PER_FDEFAULT(VP,PDSET,PDSET3)\
   |_PER_FDEFAULT(VP,PDSET,PDSET2)\
   |_PER_FDEFAULT(VP,PDSET,PDSET1)\
   |_PER_FDEFAULT(VP,PDSET,PDSET0)\
  )

#define VP_PDSET_RMK(pdset22,pdset21,pdset20,pdset19,pdset18,pdset17,pdset16,\
  pdset15,pdset14,pdset13,pdset12,pdset11,pdset10,pdset9,pdset8,pdset7,\
  pdset6,pdset5,pdset4,pdset3,pdset2,pdset1,pdset0) (Uint32)(\
    _PER_FMK(VP,PDSET,PDSET22,pdset22)\
   |_PER_FMK(VP,PDSET,PDSET21,pdset21)\
   |_PER_FMK(VP,PDSET,PDSET20,pdset20)\
   |_PER_FMK(VP,PDSET,PDSET19,pdset19)\
   |_PER_FMK(VP,PDSET,PDSET18,pdset18)\
   |_PER_FMK(VP,PDSET,PDSET17,pdset17)\
   |_PER_FMK(VP,PDSET,PDSET16,pdset16)\
   |_PER_FMK(VP,PDSET,PDSET15,pdset15)\
   |_PER_FMK(VP,PDSET,PDSET14,pdset14)\
   |_PER_FMK(VP,PDSET,PDSET13,pdset13)\
   |_PER_FMK(VP,PDSET,PDSET12,pdset12)\
   |_PER_FMK(VP,PDSET,PDSET11,pdset11)\
   |_PER_FMK(VP,PDSET,PDSET10,pdset10)\
   |_PER_FMK(VP,PDSET,PDSET9,pdset9)\
   |_PER_FMK(VP,PDSET,PDSET8,pdset8)\
   |_PER_FMK(VP,PDSET,PDSET7,pdset7)\
   |_PER_FMK(VP,PDSET,PDSET6,pdset6)\
   |_PER_FMK(VP,PDSET,PDSET5,pdset5)\
   |_PER_FMK(VP,PDSET,PDSET4,pdset4)\
   |_PER_FMK(VP,PDSET,PDSET3,pdset3)\
   |_PER_FMK(VP,PDSET,PDSET2,pdset2)\
   |_PER_FMK(VP,PDSET,PDSET1,pdset1)\
   |_PER_FMK(VP,PDSET,PDSET0,pdset0)\
  )

  #define _VP_PDSET_FGET(N,FIELD)\
    _PER_FGET(_VP_PDSET##N##_ADDR,VP,PDSET,##FIELD)

  #define _VP_PDSET_FSET(N,FIELD,field)\
    _PER_FSET(_VP_PDSET##N##_ADDR,VP,PDSET,##FIELD,field)

  #define _VP_PDSET_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_PDSET##N##_ADDR,VP,PDSET,##FIELD,##SYM)

  #define _VP_PDSET0_FGET(FIELD)   _VP_PDSET_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PDSET1_FGET(FIELD)   _VP_PDSET_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_PDSET2_FGET(FIELD)   _VP_PDSET_FGET(2,##FIELD)
 #endif


  #define _VP_PDSET0_FSET(FIELD,f)   _VP_PDSET_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PDSET1_FSET(FIELD,f)   _VP_PDSET_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_PDSET2_FSET(FIELD,f)   _VP_PDSET_FSET(2,##FIELD,f)
 #endif


  #define _VP_PDSET0_FSETS(FIELD,SYM)   _VP_PDSET_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PDSET1_FSETS(FIELD,SYM)   _VP_PDSET_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_PDSET2_FSETS(FIELD,SYM)   _VP_PDSET_FSETS(2,##FIELD,##SYM)
 #endif

  
/******************************************************************************\
* _____________________
* |                   |
* |  P D C L R        |
* |___________________|
*
* PDCLR0  - Video Port 0 Pin Data Clear Register
* PDCLR1  - Video Port 1 Pin Data Clear Register
* PDCLR2  - Video Port 2 Pin Data Clear Register
*
* FIELDS (msb -> lsb)
* (w) PDCLR22
* (w) PDCLR21
* (w) PDCLR20
* (w) PDCLR19
* (w) PDCLR18
* (w) PDCLR17
* (w) PDCLR16
* (w) PDCLR15
* (w) PDCLR14
* (w) PDCLR13
* (w) PDCLR12
* (w) PDCLR11
* (w) PDCLR10
* (w) PDCLR9
* (w) PDCLR8
* (w) PDCLR7
* (w) PDCLR6
* (w) PDCLR5
* (w) PDCLR4
* (w) PDCLR3
* (w) PDCLR2
* (w) PDCLR1
* (w) PDCLR0
*
\******************************************************************************/
  #define _VP_PDCLR_OFFSET            13

  #define _VP_PDCLR0_ADDR   (_VP_BASE_PORT0 + 4*_VP_PDCLR_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PDCLR1_ADDR   (_VP_BASE_PORT1 + 4*_VP_PDCLR_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_PDCLR2_ADDR   (_VP_BASE_PORT2 + 4*_VP_PDCLR_OFFSET)
 #endif


  #define _VP_PDCLR_PDCLR22_MASK           0x00400000u
  #define _VP_PDCLR_PDCLR22_SHIFT          0x00000016u
  #define  VP_PDCLR_PDCLR22_DEFAULT        0x00000000u
  #define  VP_PDCLR_PDCLR22_OF(x)          _VALUEOF(x)
  #define  VP_PDCLR_PDCLR22_NONE           0x00000000u
  #define  VP_PDCLR_PDCLR22_VCTL2CLR       0x00000001u
  
  #define _VP_PDCLR_PDCLR21_MASK           0x00200000u
  #define _VP_PDCLR_PDCLR21_SHIFT          0x00000015u
  #define  VP_PDCLR_PDCLR21_DEFAULT        0x00000000u
  #define  VP_PDCLR_PDCLR21_OF(x)          _VALUEOF(x)
  #define  VP_PDCLR_PDCLR21_NONE           0x00000000u
  #define  VP_PDCLR_PDCLR21_VCTL1CLR       0x00000001u
  
  #define _VP_PDCLR_PDCLR20_MASK           0x00100000u
  #define _VP_PDCLR_PDCLR20_SHIFT          0x00000014u
  #define  VP_PDCLR_PDCLR20_DEFAULT        0x00000000u
  #define  VP_PDCLR_PDCLR20_OF(x)          _VALUEOF(x)
  #define  VP_PDCLR_PDCLR20_NONE           0x00000000u
  #define  VP_PDCLR_PDCLR20_VCTL0CLR       0x00000001u
  
  #define _VP_PDCLR_PDCLR19_MASK           0x00080000u
  #define _VP_PDCLR_PDCLR19_SHIFT          0x00000013u
  #define  VP_PDCLR_PDCLR19_DEFAULT        0x00000000u
  #define  VP_PDCLR_PDCLR19_OF(x)          _VALUEOF(x)
  #define  VP_PDCLR_PDCLR19_NONE           0x00000000u
  #define  VP_PDCLR_PDCLR19_VDATA19CLR     0x00000001u
  
  #define _VP_PDCLR_PDCLR18_MASK           0x00040000u
  #define _VP_PDCLR_PDCLR18_SHIFT          0x00000012u
  #define  VP_PDCLR_PDCLR18_DEFAULT        0x00000000u
  #define  VP_PDCLR_PDCLR18_OF(x)          _VALUEOF(x)
  #define  VP_PDCLR_PDCLR18_NONE           0x00000000u
  #define  VP_PDCLR_PDCLR18_VDATA18CLR     0x00000001u
  
  #define _VP_PDCLR_PDCLR17_MASK           0x00020000u
  #define _VP_PDCLR_PDCLR17_SHIFT          0x00000011u
  #define  VP_PDCLR_PDCLR17_DEFAULT        0x00000000u
  #define  VP_PDCLR_PDCLR17_OF(x)          _VALUEOF(x)
  #define  VP_PDCLR_PDCLR17_NONE           0x00000000u
  #define  VP_PDCLR_PDCLR17_VDATA17CLR     0x00000001u
  
  #define _VP_PDCLR_PDCLR16_MASK           0x00010000u
  #define _VP_PDCLR_PDCLR16_SHIFT          0x00000010u
  #define  VP_PDCLR_PDCLR16_DEFAULT        0x00000000u
  #define  VP_PDCLR_PDCLR16_OF(x)          _VALUEOF(x)
  #define  VP_PDCLR_PDCLR16_NONE           0x00000000u
  #define  VP_PDCLR_PDCLR16_VDATA16CLR     0x00000001u
  
  #define _VP_PDCLR_PDCLR15_MASK           0x00008000u
  #define _VP_PDCLR_PDCLR15_SHIFT          0x0000000Fu
  #define  VP_PDCLR_PDCLR15_DEFAULT        0x00000000u
  #define  VP_PDCLR_PDCLR15_OF(x)          _VALUEOF(x)
  #define  VP_PDCLR_PDCLR15_NONE           0x00000000u
  #define  VP_PDCLR_PDCLR15_VDATA15CLR     0x00000001u
  
  #define _VP_PDCLR_PDCLR14_MASK           0x00004000u
  #define _VP_PDCLR_PDCLR14_SHIFT          0x0000000Eu
  #define  VP_PDCLR_PDCLR14_DEFAULT        0x00000000u
  #define  VP_PDCLR_PDCLR14_OF(x)          _VALUEOF(x)
  #define  VP_PDCLR_PDCLR14_NONE           0x00000000u
  #define  VP_PDCLR_PDCLR14_VDATA14CLR     0x00000001u
  
  #define _VP_PDCLR_PDCLR13_MASK           0x00002000u
  #define _VP_PDCLR_PDCLR13_SHIFT          0x0000000Du
  #define  VP_PDCLR_PDCLR13_DEFAULT        0x00000000u
  #define  VP_PDCLR_PDCLR13_OF(x)          _VALUEOF(x)
  #define  VP_PDCLR_PDCLR13_NONE           0x00000000u
  #define  VP_PDCLR_PDCLR13_VDATA13CLR     0x00000001u
  
  #define _VP_PDCLR_PDCLR12_MASK           0x00001000u
  #define _VP_PDCLR_PDCLR12_SHIFT          0x0000000Cu
  #define  VP_PDCLR_PDCLR12_DEFAULT        0x00000000u
  #define  VP_PDCLR_PDCLR12_OF(x)          _VALUEOF(x)
  #define  VP_PDCLR_PDCLR12_NONE           0x00000000u
  #define  VP_PDCLR_PDCLR12_VDATA12CLR     0x00000001u
  
  #define _VP_PDCLR_PDCLR11_MASK           0x00000800u
  #define _VP_PDCLR_PDCLR11_SHIFT          0x0000000Bu
  #define  VP_PDCLR_PDCLR11_DEFAULT        0x00000000u
  #define  VP_PDCLR_PDCLR11_OF(x)          _VALUEOF(x)
  #define  VP_PDCLR_PDCLR11_NONE           0x00000000u
  #define  VP_PDCLR_PDCLR11_VDATA11CLR     0x00000001u
  
  #define _VP_PDCLR_PDCLR10_MASK           0x00000400u
  #define _VP_PDCLR_PDCLR10_SHIFT          0x0000000Au
  #define  VP_PDCLR_PDCLR10_DEFAULT        0x00000000u
  #define  VP_PDCLR_PDCLR10_OF(x)          _VALUEOF(x)
  #define  VP_PDCLR_PDCLR10_NONE           0x00000000u
  #define  VP_PDCLR_PDCLR10_VDATA10CLR     0x00000001u
  
  #define _VP_PDCLR_PDCLR9_MASK            0x00000200u
  #define _VP_PDCLR_PDCLR9_SHIFT           0x00000009u
  #define  VP_PDCLR_PDCLR9_DEFAULT         0x00000000u
  #define  VP_PDCLR_PDCLR9_OF(x)           _VALUEOF(x)
  #define  VP_PDCLR_PDCLR9_NONE            0x00000000u
  #define  VP_PDCLR_PDCLR9_VDATA9CLR       0x00000001u
  
  #define _VP_PDCLR_PDCLR8_MASK            0x00000100u
  #define _VP_PDCLR_PDCLR8_SHIFT           0x00000008u
  #define  VP_PDCLR_PDCLR8_DEFAULT         0x00000000u
  #define  VP_PDCLR_PDCLR8_OF(x)           _VALUEOF(x)
  #define  VP_PDCLR_PDCLR8_NONE            0x00000000u
  #define  VP_PDCLR_PDCLR8_VDATA8CLR       0x00000001u
  
  #define _VP_PDCLR_PDCLR7_MASK            0x00000080u
  #define _VP_PDCLR_PDCLR7_SHIFT           0x00000007u
  #define  VP_PDCLR_PDCLR7_DEFAULT         0x00000000u
  #define  VP_PDCLR_PDCLR7_OF(x)           _VALUEOF(x)
  #define  VP_PDCLR_PDCLR7_NONE            0x00000000u
  #define  VP_PDCLR_PDCLR7_VDATA7CLR       0x00000001u
  
  #define _VP_PDCLR_PDCLR6_MASK            0x00000040u
  #define _VP_PDCLR_PDCLR6_SHIFT           0x00000006u
  #define  VP_PDCLR_PDCLR6_DEFAULT         0x00000000u
  #define  VP_PDCLR_PDCLR6_OF(x)           _VALUEOF(x)
  #define  VP_PDCLR_PDCLR6_NONE            0x00000000u
  #define  VP_PDCLR_PDCLR6_VDATA6CLR       0x00000001u
  
  #define _VP_PDCLR_PDCLR5_MASK            0x00000020u
  #define _VP_PDCLR_PDCLR5_SHIFT           0x00000005u
  #define  VP_PDCLR_PDCLR5_DEFAULT         0x00000000u
  #define  VP_PDCLR_PDCLR5_OF(x)           _VALUEOF(x)
  #define  VP_PDCLR_PDCLR5_NONE            0x00000000u
  #define  VP_PDCLR_PDCLR5_VDATA5CLR       0x00000001u
  
  #define _VP_PDCLR_PDCLR4_MASK            0x00000010u
  #define _VP_PDCLR_PDCLR4_SHIFT           0x00000004u
  #define  VP_PDCLR_PDCLR4_DEFAULT         0x00000000u
  #define  VP_PDCLR_PDCLR4_OF(x)           _VALUEOF(x)
  #define  VP_PDCLR_PDCLR4_NONE            0x00000000u
  #define  VP_PDCLR_PDCLR4_VDATA4CLR       0x00000001u
  
  #define _VP_PDCLR_PDCLR3_MASK            0x00000008u
  #define _VP_PDCLR_PDCLR3_SHIFT           0x00000003u
  #define  VP_PDCLR_PDCLR3_DEFAULT         0x00000000u
  #define  VP_PDCLR_PDCLR3_OF(x)           _VALUEOF(x)
  #define  VP_PDCLR_PDCLR3_NONE            0x00000000u
  #define  VP_PDCLR_PDCLR3_VDATA3CLR       0x00000001u
  
  #define _VP_PDCLR_PDCLR2_MASK            0x00000004u
  #define _VP_PDCLR_PDCLR2_SHIFT           0x00000002u
  #define  VP_PDCLR_PDCLR2_DEFAULT         0x00000000u
  #define  VP_PDCLR_PDCLR2_OF(x)           _VALUEOF(x)
  #define  VP_PDCLR_PDCLR2_NONE            0x00000000u
  #define  VP_PDCLR_PDCLR2_VDATA2CLR       0x00000001u
  
  #define _VP_PDCLR_PDCLR1_MASK            0x00000002u
  #define _VP_PDCLR_PDCLR1_SHIFT           0x00000001u
  #define  VP_PDCLR_PDCLR1_DEFAULT         0x00000000u
  #define  VP_PDCLR_PDCLR1_OF(x)           _VALUEOF(x)
  #define  VP_PDCLR_PDCLR1_NONE            0x00000000u
  #define  VP_PDCLR_PDCLR1_VDATA1CLR       0x00000001u
  
  #define _VP_PDCLR_PDCLR0_MASK            0x00000001u
  #define _VP_PDCLR_PDCLR0_SHIFT           0x00000000u
  #define  VP_PDCLR_PDCLR0_DEFAULT         0x00000000u
  #define  VP_PDCLR_PDCLR0_OF(x)           _VALUEOF(x)
  #define  VP_PDCLR_PDCLR0_NONE            0x00000000u
  #define  VP_PDCLR_PDCLR0_VDATA0CLR       0x00000001u
  
  #define  VP_PDCLR_OF(x)             _VALUEOF(x)

  #define VP_PDCLR_DEFAULT (Uint32)(\
    _PER_FDEFAULT(VP,PDCLR,PDCLR22)\
   |_PER_FDEFAULT(VP,PDCLR,PDCLR21)\
   |_PER_FDEFAULT(VP,PDCLR,PDCLR20)\
   |_PER_FDEFAULT(VP,PDCLR,PDCLR19)\
   |_PER_FDEFAULT(VP,PDCLR,PDCLR18)\
   |_PER_FDEFAULT(VP,PDCLR,PDCLR17)\
   |_PER_FDEFAULT(VP,PDCLR,PDCLR16)\
   |_PER_FDEFAULT(VP,PDCLR,PDCLR15)\
   |_PER_FDEFAULT(VP,PDCLR,PDCLR14)\
   |_PER_FDEFAULT(VP,PDCLR,PDCLR13)\
   |_PER_FDEFAULT(VP,PDCLR,PDCLR12)\
   |_PER_FDEFAULT(VP,PDCLR,PDCLR11)\
   |_PER_FDEFAULT(VP,PDCLR,PDCLR10)\
   |_PER_FDEFAULT(VP,PDCLR,PDCLR9)\
   |_PER_FDEFAULT(VP,PDCLR,PDCLR8)\
   |_PER_FDEFAULT(VP,PDCLR,PDCLR7)\
   |_PER_FDEFAULT(VP,PDCLR,PDCLR6)\
   |_PER_FDEFAULT(VP,PDCLR,PDCLR5)\
   |_PER_FDEFAULT(VP,PDCLR,PDCLR4)\
   |_PER_FDEFAULT(VP,PDCLR,PDCLR3)\
   |_PER_FDEFAULT(VP,PDCLR,PDCLR2)\
   |_PER_FDEFAULT(VP,PDCLR,PDCLR1)\
   |_PER_FDEFAULT(VP,PDCLR,PDCLR0)\
  )

#define VP_PDCLR_RMK(pdclr22,pdclr21,pdclr20,pdclr19,pdclr18,pdclr17,pdclr16,\
  pdclr15,pdclr14,pdclr13,pdclr12,pdclr11,pdclr10,pdclr9,pdclr8,pdclr7,\
  pdclr6,pdclr5,pdclr4,pdclr3,pdclr2,pdclr1,pdclr0) (Uint32)(\
    _PER_FMK(VP,PDCLR,PDCLR22,pdclr22)\
   |_PER_FMK(VP,PDCLR,PDCLR21,pdclr21)\
   |_PER_FMK(VP,PDCLR,PDCLR20,pdclr20)\
   |_PER_FMK(VP,PDCLR,PDCLR19,pdclr19)\
   |_PER_FMK(VP,PDCLR,PDCLR18,pdclr18)\
   |_PER_FMK(VP,PDCLR,PDCLR17,pdclr17)\
   |_PER_FMK(VP,PDCLR,PDCLR16,pdclr16)\
   |_PER_FMK(VP,PDCLR,PDCLR15,pdclr15)\
   |_PER_FMK(VP,PDCLR,PDCLR14,pdclr14)\
   |_PER_FMK(VP,PDCLR,PDCLR13,pdclr13)\
   |_PER_FMK(VP,PDCLR,PDCLR12,pdclr12)\
   |_PER_FMK(VP,PDCLR,PDCLR11,pdclr11)\
   |_PER_FMK(VP,PDCLR,PDCLR10,pdclr10)\
   |_PER_FMK(VP,PDCLR,PDCLR9,pdclr9)\
   |_PER_FMK(VP,PDCLR,PDCLR8,pdclr8)\
   |_PER_FMK(VP,PDCLR,PDCLR7,pdclr7)\
   |_PER_FMK(VP,PDCLR,PDCLR6,pdclr6)\
   |_PER_FMK(VP,PDCLR,PDCLR5,pdclr5)\
   |_PER_FMK(VP,PDCLR,PDCLR4,pdclr4)\
   |_PER_FMK(VP,PDCLR,PDCLR3,pdclr3)\
   |_PER_FMK(VP,PDCLR,PDCLR2,pdclr2)\
   |_PER_FMK(VP,PDCLR,PDCLR1,pdclr1)\
   |_PER_FMK(VP,PDCLR,PDCLR0,pdclr0)\
  )

  #define _VP_PDCLR_FGET(N,FIELD)\
    _PER_FGET(_VP_PDCLR##N##_ADDR,VP,PDCLR,##FIELD)

  #define _VP_PDCLR_FSET(N,FIELD,field)\
    _PER_FSET(_VP_PDCLR##N##_ADDR,VP,PDCLR,##FIELD,field)

  #define _VP_PDCLR_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_PDCLR##N##_ADDR,VP,PDCLR,##FIELD,##SYM)

  #define _VP_PDCLR0_FGET(FIELD)   _VP_PDCLR_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PDCLR1_FGET(FIELD)   _VP_PDCLR_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_PDCLR2_FGET(FIELD)   _VP_PDCLR_FGET(2,##FIELD)
 #endif


  #define _VP_PDCLR0_FSET(FIELD,f)   _VP_PDCLR_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PDCLR1_FSET(FIELD,f)   _VP_PDCLR_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_PDCLR2_FSET(FIELD,f)   _VP_PDCLR_FSET(2,##FIELD,f)
 #endif


  #define _VP_PDCLR0_FSETS(FIELD,SYM)   _VP_PDCLR_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PDCLR1_FSETS(FIELD,SYM)   _VP_PDCLR_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_PDCLR2_FSETS(FIELD,SYM)   _VP_PDCLR_FSETS(2,##FIELD,##SYM)
 #endif

  
/******************************************************************************\
* _____________________
* |                   |
* |  P I E N          |
* |___________________|
*
* PIEN0  - Video Port 0 Pin Interrupt Enable Register
* PIEN1  - Video Port 1 Pin Interrupt Enable Register
* PIEN2  - Video Port 2 Pin Interrupt Enable Register
*
* FIELDS (msb -> lsb)
* (w) PIEN22
* (w) PIEN21
* (w) PIEN20
* (w) PIEN19
* (w) PIEN18
* (w) PIEN17
* (w) PIEN16
* (w) PIEN15
* (w) PIEN14
* (w) PIEN13
* (w) PIEN12
* (w) PIEN11
* (w) PIEN10
* (w) PIEN9
* (w) PIEN8
* (w) PIEN7
* (w) PIEN6
* (w) PIEN5
* (w) PIEN4
* (w) PIEN3
* (w) PIEN2
* (w) PIEN1
* (w) PIEN0
*
\******************************************************************************/
  #define _VP_PIEN_OFFSET            14

  #define _VP_PIEN0_ADDR   (_VP_BASE_PORT0 + 4*_VP_PIEN_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PIEN1_ADDR   (_VP_BASE_PORT1 + 4*_VP_PIEN_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_PIEN2_ADDR   (_VP_BASE_PORT2 + 4*_VP_PIEN_OFFSET)
 #endif


  #define _VP_PIEN_PIEN22_MASK           0x00400000u
  #define _VP_PIEN_PIEN22_SHIFT          0x00000016u
  #define  VP_PIEN_PIEN22_DEFAULT        0x00000000u
  #define  VP_PIEN_PIEN22_OF(x)          _VALUEOF(x)
  #define  VP_PIEN_PIEN22_VCTL2LO        0x00000000u
  #define  VP_PIEN_PIEN22_VCTL2HI        0x00000001u
  
  #define _VP_PIEN_PIEN21_MASK           0x00200000u
  #define _VP_PIEN_PIEN21_SHIFT          0x00000015u
  #define  VP_PIEN_PIEN21_DEFAULT        0x00000000u
  #define  VP_PIEN_PIEN21_OF(x)          _VALUEOF(x)
  #define  VP_PIEN_PIEN21_VCTL1LO        0x00000000u
  #define  VP_PIEN_PIEN21_VCTL1HI        0x00000001u
  
  #define _VP_PIEN_PIEN20_MASK           0x00100000u
  #define _VP_PIEN_PIEN20_SHIFT          0x00000014u
  #define  VP_PIEN_PIEN20_DEFAULT        0x00000000u
  #define  VP_PIEN_PIEN20_OF(x)          _VALUEOF(x)
  #define  VP_PIEN_PIEN20_VCTL0LO        0x00000000u
  #define  VP_PIEN_PIEN20_VCTL0HI        0x00000001u
  
  #define _VP_PIEN_PIEN19_MASK           0x00080000u
  #define _VP_PIEN_PIEN19_SHIFT          0x00000013u
  #define  VP_PIEN_PIEN19_DEFAULT        0x00000000u
  #define  VP_PIEN_PIEN19_OF(x)          _VALUEOF(x)
  #define  VP_PIEN_PIEN19_VDATA19LO      0x00000000u
  #define  VP_PIEN_PIEN19_VDATA19HI      0x00000001u
  
  #define _VP_PIEN_PIEN18_MASK           0x00040000u
  #define _VP_PIEN_PIEN18_SHIFT          0x00000012u
  #define  VP_PIEN_PIEN18_DEFAULT        0x00000000u
  #define  VP_PIEN_PIEN18_OF(x)          _VALUEOF(x)
  #define  VP_PIEN_PIEN18_VDATA18LO      0x00000000u
  #define  VP_PIEN_PIEN18_VDATA18HI      0x00000001u
  
  #define _VP_PIEN_PIEN17_MASK           0x00020000u
  #define _VP_PIEN_PIEN17_SHIFT          0x00000011u
  #define  VP_PIEN_PIEN17_DEFAULT        0x00000000u
  #define  VP_PIEN_PIEN17_OF(x)          _VALUEOF(x)
  #define  VP_PIEN_PIEN17_VDATA17LO      0x00000000u
  #define  VP_PIEN_PIEN17_VDATA17HI      0x00000001u
  
  #define _VP_PIEN_PIEN16_MASK           0x00010000u
  #define _VP_PIEN_PIEN16_SHIFT          0x00000010u
  #define  VP_PIEN_PIEN16_DEFAULT        0x00000000u
  #define  VP_PIEN_PIEN16_OF(x)          _VALUEOF(x)
  #define  VP_PIEN_PIEN16_VDATA16LO      0x00000000u
  #define  VP_PIEN_PIEN16_VDATA16HI      0x00000001u
  
  #define _VP_PIEN_PIEN15_MASK           0x00008000u
  #define _VP_PIEN_PIEN15_SHIFT          0x0000000Fu
  #define  VP_PIEN_PIEN15_DEFAULT        0x00000000u
  #define  VP_PIEN_PIEN15_OF(x)          _VALUEOF(x)
  #define  VP_PIEN_PIEN15_VDATA15LO      0x00000000u
  #define  VP_PIEN_PIEN15_VDATA15HI      0x00000001u
  
  #define _VP_PIEN_PIEN14_MASK           0x00004000u
  #define _VP_PIEN_PIEN14_SHIFT          0x0000000Eu
  #define  VP_PIEN_PIEN14_DEFAULT        0x00000000u
  #define  VP_PIEN_PIEN14_OF(x)          _VALUEOF(x)
  #define  VP_PIEN_PIEN14_VDATA14LO      0x00000000u
  #define  VP_PIEN_PIEN14_VDATA14HI      0x00000001u
  
  #define _VP_PIEN_PIEN13_MASK           0x00002000u
  #define _VP_PIEN_PIEN13_SHIFT          0x0000000Du
  #define  VP_PIEN_PIEN13_DEFAULT        0x00000000u
  #define  VP_PIEN_PIEN13_OF(x)          _VALUEOF(x)
  #define  VP_PIEN_PIEN13_VDATA13LO      0x00000000u
  #define  VP_PIEN_PIEN13_VDATA13HI      0x00000001u
  
  #define _VP_PIEN_PIEN12_MASK           0x00001000u
  #define _VP_PIEN_PIEN12_SHIFT          0x0000000Cu
  #define  VP_PIEN_PIEN12_DEFAULT        0x00000000u
  #define  VP_PIEN_PIEN12_OF(x)          _VALUEOF(x)
  #define  VP_PIEN_PIEN12_VDATA12LO      0x00000000u
  #define  VP_PIEN_PIEN12_VDATA12HI      0x00000001u
  
  #define _VP_PIEN_PIEN11_MASK           0x00000800u
  #define _VP_PIEN_PIEN11_SHIFT          0x0000000Bu
  #define  VP_PIEN_PIEN11_DEFAULT        0x00000000u
  #define  VP_PIEN_PIEN11_OF(x)          _VALUEOF(x)
  #define  VP_PIEN_PIEN11_VDATA11LO      0x00000000u
  #define  VP_PIEN_PIEN11_VDATA11HI      0x00000001u
  
  #define _VP_PIEN_PIEN10_MASK           0x00000400u
  #define _VP_PIEN_PIEN10_SHIFT          0x0000000Au
  #define  VP_PIEN_PIEN10_DEFAULT        0x00000000u
  #define  VP_PIEN_PIEN10_OF(x)          _VALUEOF(x)
  #define  VP_PIEN_PIEN10_VDATA10LO      0x00000000u
  #define  VP_PIEN_PIEN10_VDATA10HI      0x00000001u
  
  #define _VP_PIEN_PIEN9_MASK            0x00000200u
  #define _VP_PIEN_PIEN9_SHIFT           0x00000009u
  #define  VP_PIEN_PIEN9_DEFAULT         0x00000000u
  #define  VP_PIEN_PIEN9_OF(x)           _VALUEOF(x)
  #define  VP_PIEN_PIEN9_VDATA9LO        0x00000000u
  #define  VP_PIEN_PIEN9_VDATA9HI        0x00000001u
  
  #define _VP_PIEN_PIEN8_MASK            0x00000100u
  #define _VP_PIEN_PIEN8_SHIFT           0x00000008u
  #define  VP_PIEN_PIEN8_DEFAULT         0x00000000u
  #define  VP_PIEN_PIEN8_OF(x)           _VALUEOF(x)
  #define  VP_PIEN_PIEN8_VDATA8LO        0x00000000u
  #define  VP_PIEN_PIEN8_VDATA8HI        0x00000001u
  
  #define _VP_PIEN_PIEN7_MASK            0x00000080u
  #define _VP_PIEN_PIEN7_SHIFT           0x00000007u
  #define  VP_PIEN_PIEN7_DEFAULT         0x00000000u
  #define  VP_PIEN_PIEN7_OF(x)           _VALUEOF(x)
  #define  VP_PIEN_PIEN7_VDATA7LO        0x00000000u
  #define  VP_PIEN_PIEN7_VDATA7HI        0x00000001u
  
  #define _VP_PIEN_PIEN6_MASK            0x00000040u
  #define _VP_PIEN_PIEN6_SHIFT           0x00000006u
  #define  VP_PIEN_PIEN6_DEFAULT         0x00000000u
  #define  VP_PIEN_PIEN6_OF(x)           _VALUEOF(x)
  #define  VP_PIEN_PIEN6_VDATA6LO        0x00000000u
  #define  VP_PIEN_PIEN6_VDATA6HI        0x00000001u
  
  #define _VP_PIEN_PIEN5_MASK            0x00000020u
  #define _VP_PIEN_PIEN5_SHIFT           0x00000005u
  #define  VP_PIEN_PIEN5_DEFAULT         0x00000000u
  #define  VP_PIEN_PIEN5_OF(x)           _VALUEOF(x)
  #define  VP_PIEN_PIEN5_VDATA5LO        0x00000000u
  #define  VP_PIEN_PIEN5_VDATA5HI        0x00000001u
  
  #define _VP_PIEN_PIEN4_MASK            0x00000010u
  #define _VP_PIEN_PIEN4_SHIFT           0x00000004u
  #define  VP_PIEN_PIEN4_DEFAULT         0x00000000u
  #define  VP_PIEN_PIEN4_OF(x)           _VALUEOF(x)
  #define  VP_PIEN_PIEN4_VDATA4LO        0x00000000u
  #define  VP_PIEN_PIEN4_VDATA4HI        0x00000001u
  
  #define _VP_PIEN_PIEN3_MASK            0x00000008u
  #define _VP_PIEN_PIEN3_SHIFT           0x00000003u
  #define  VP_PIEN_PIEN3_DEFAULT         0x00000000u
  #define  VP_PIEN_PIEN3_OF(x)           _VALUEOF(x)
  #define  VP_PIEN_PIEN3_VDATA3LO        0x00000000u
  #define  VP_PIEN_PIEN3_VDATA3HI        0x00000001u
  
  #define _VP_PIEN_PIEN2_MASK            0x00000004u
  #define _VP_PIEN_PIEN2_SHIFT           0x00000002u
  #define  VP_PIEN_PIEN2_DEFAULT         0x00000000u
  #define  VP_PIEN_PIEN2_OF(x)           _VALUEOF(x)
  #define  VP_PIEN_PIEN2_VDATA2LO        0x00000000u
  #define  VP_PIEN_PIEN2_VDATA2HI        0x00000001u
  
  #define _VP_PIEN_PIEN1_MASK            0x00000002u
  #define _VP_PIEN_PIEN1_SHIFT           0x00000001u
  #define  VP_PIEN_PIEN1_DEFAULT         0x00000000u
  #define  VP_PIEN_PIEN1_OF(x)           _VALUEOF(x)
  #define  VP_PIEN_PIEN1_VDATA1LO        0x00000000u
  #define  VP_PIEN_PIEN1_VDATA1HI        0x00000001u
  
  #define _VP_PIEN_PIEN0_MASK            0x00000001u
  #define _VP_PIEN_PIEN0_SHIFT           0x00000000u
  #define  VP_PIEN_PIEN0_DEFAULT         0x00000000u
  #define  VP_PIEN_PIEN0_OF(x)           _VALUEOF(x)
  #define  VP_PIEN_PIEN0_VDATA0LO        0x00000000u
  #define  VP_PIEN_PIEN0_VDATA0HI        0x00000001u
  
  #define  VP_PIEN_OF(x)             _VALUEOF(x)

  #define VP_PIEN_DEFAULT (Uint32)(\
    _PER_FDEFAULT(VP,PIEN,PIEN22)\
   |_PER_FDEFAULT(VP,PIEN,PIEN21)\
   |_PER_FDEFAULT(VP,PIEN,PIEN20)\
   |_PER_FDEFAULT(VP,PIEN,PIEN19)\
   |_PER_FDEFAULT(VP,PIEN,PIEN18)\
   |_PER_FDEFAULT(VP,PIEN,PIEN17)\
   |_PER_FDEFAULT(VP,PIEN,PIEN16)\
   |_PER_FDEFAULT(VP,PIEN,PIEN15)\
   |_PER_FDEFAULT(VP,PIEN,PIEN14)\
   |_PER_FDEFAULT(VP,PIEN,PIEN13)\
   |_PER_FDEFAULT(VP,PIEN,PIEN12)\
   |_PER_FDEFAULT(VP,PIEN,PIEN11)\
   |_PER_FDEFAULT(VP,PIEN,PIEN10)\
   |_PER_FDEFAULT(VP,PIEN,PIEN9)\
   |_PER_FDEFAULT(VP,PIEN,PIEN8)\
   |_PER_FDEFAULT(VP,PIEN,PIEN7)\
   |_PER_FDEFAULT(VP,PIEN,PIEN6)\
   |_PER_FDEFAULT(VP,PIEN,PIEN5)\
   |_PER_FDEFAULT(VP,PIEN,PIEN4)\
   |_PER_FDEFAULT(VP,PIEN,PIEN3)\
   |_PER_FDEFAULT(VP,PIEN,PIEN2)\
   |_PER_FDEFAULT(VP,PIEN,PIEN1)\
   |_PER_FDEFAULT(VP,PIEN,PIEN0)\
  )

#define VP_PIEN_RMK(pien22,pien21,pien20,pien19,pien18,pien17,pien16,\
  pien15,pien14,pien13,pien12,pien11,pien10,pien9,pien8,pien7,\
  pien6,pien5,pien4,pien3,pien2,pien1,pien0) (Uint32)(\
    _PER_FMK(VP,PIEN,PIEN22,pien22)\
   |_PER_FMK(VP,PIEN,PIEN21,pien21)\
   |_PER_FMK(VP,PIEN,PIEN20,pien20)\
   |_PER_FMK(VP,PIEN,PIEN19,pien19)\
   |_PER_FMK(VP,PIEN,PIEN18,pien18)\
   |_PER_FMK(VP,PIEN,PIEN17,pien17)\
   |_PER_FMK(VP,PIEN,PIEN16,pien16)\
   |_PER_FMK(VP,PIEN,PIEN15,pien15)\
   |_PER_FMK(VP,PIEN,PIEN14,pien14)\
   |_PER_FMK(VP,PIEN,PIEN13,pien13)\
   |_PER_FMK(VP,PIEN,PIEN12,pien12)\
   |_PER_FMK(VP,PIEN,PIEN11,pien11)\
   |_PER_FMK(VP,PIEN,PIEN10,pien10)\
   |_PER_FMK(VP,PIEN,PIEN9,pien9)\
   |_PER_FMK(VP,PIEN,PIEN8,pien8)\
   |_PER_FMK(VP,PIEN,PIEN7,pien7)\
   |_PER_FMK(VP,PIEN,PIEN6,pien6)\
   |_PER_FMK(VP,PIEN,PIEN5,pien5)\
   |_PER_FMK(VP,PIEN,PIEN4,pien4)\
   |_PER_FMK(VP,PIEN,PIEN3,pien3)\
   |_PER_FMK(VP,PIEN,PIEN2,pien2)\
   |_PER_FMK(VP,PIEN,PIEN1,pien1)\
   |_PER_FMK(VP,PIEN,PIEN0,pien0)\
  )

  #define _VP_PIEN_FGET(N,FIELD)\
    _PER_FGET(_VP_PIEN##N##_ADDR,VP,PIEN,##FIELD)

  #define _VP_PIEN_FSET(N,FIELD,field)\
    _PER_FSET(_VP_PIEN##N##_ADDR,VP,PIEN,##FIELD,field)

  #define _VP_PIEN_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_PIEN##N##_ADDR,VP,PIEN,##FIELD,##SYM)

  #define _VP_PIEN0_FGET(FIELD)   _VP_PIEN_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PIEN1_FGET(FIELD)   _VP_PIEN_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_PIEN2_FGET(FIELD)   _VP_PIEN_FGET(2,##FIELD)
 #endif


  #define _VP_PIEN0_FSET(FIELD,f)   _VP_PIEN_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PIEN1_FSET(FIELD,f)   _VP_PIEN_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_PIEN2_FSET(FIELD,f)   _VP_PIEN_FSET(2,##FIELD,f)
 #endif


  #define _VP_PIEN0_FSETS(FIELD,SYM)   _VP_PIEN_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PIEN1_FSETS(FIELD,SYM)   _VP_PIEN_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_PIEN2_FSETS(FIELD,SYM)   _VP_PIEN_FSETS(2,##FIELD,##SYM)
 #endif

  
/******************************************************************************\
* _____________________
* |                   |
* |  P I P O L        |
* |___________________|
*
* PIPOL0  - Video Port 0 Pin Interrupt Polarity Register
* PIPOL1  - Video Port 1 Pin Interrupt Polarity Register
* PIPOL2  - Video Port 2 Pin Interrupt Polarity Register
*
* FIELDS (msb -> lsb)
* (rw) PIPOL22
* (rw) PIPOL21
* (rw) PIPOL20
* (rw) PIPOL19
* (rw) PIPOL18
* (rw) PIPOL17
* (rw) PIPOL16
* (rw) PIPOL15
* (rw) PIPOL14
* (rw) PIPOL13
* (rw) PIPOL12
* (rw) PIPOL11
* (rw) PIPOL10
* (rw) PIPOL9
* (rw) PIPOL8
* (rw) PIPOL7
* (rw) PIPOL6
* (rw) PIPOL5
* (rw) PIPOL4
* (rw) PIPOL3
* (rw) PIPOL2
* (rw) PIPOL1
* (rw) PIPOL0
*
\******************************************************************************/
  #define _VP_PIPOL_OFFSET            15

  #define _VP_PIPOL0_ADDR   (_VP_BASE_PORT0 + 4*_VP_PIPOL_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PIPOL1_ADDR   (_VP_BASE_PORT1 + 4*_VP_PIPOL_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_PIPOL2_ADDR   (_VP_BASE_PORT2 + 4*_VP_PIPOL_OFFSET)
 #endif


  #define _VP_PIPOL_PIPOL22_MASK           0x00400000u
  #define _VP_PIPOL_PIPOL22_SHIFT          0x00000016u
  #define  VP_PIPOL_PIPOL22_DEFAULT        0x00000000u
  #define  VP_PIPOL_PIPOL22_OF(x)          _VALUEOF(x)
  #define  VP_PIPOL_PIPOL22_VCTL2ACTHI     0x00000000u
  #define  VP_PIPOL_PIPOL22_VCTL2ACTLO     0x00000001u
  
  #define _VP_PIPOL_PIPOL21_MASK           0x00200000u
  #define _VP_PIPOL_PIPOL21_SHIFT          0x00000015u
  #define  VP_PIPOL_PIPOL21_DEFAULT        0x00000000u
  #define  VP_PIPOL_PIPOL21_OF(x)          _VALUEOF(x)
  #define  VP_PIPOL_PIPOL21_VCTL1ACTHI     0x00000000u
  #define  VP_PIPOL_PIPOL21_VCTL1ACTLO     0x00000001u
  
  #define _VP_PIPOL_PIPOL20_MASK           0x00100000u
  #define _VP_PIPOL_PIPOL20_SHIFT          0x00000014u
  #define  VP_PIPOL_PIPOL20_DEFAULT        0x00000000u
  #define  VP_PIPOL_PIPOL20_OF(x)          _VALUEOF(x)
  #define  VP_PIPOL_PIPOL20_VCTL0ACTHI     0x00000000u
  #define  VP_PIPOL_PIPOL20_VCTL0ACTLO     0x00000001u
  
  #define _VP_PIPOL_PIPOL19_MASK           0x00080000u
  #define _VP_PIPOL_PIPOL19_SHIFT          0x00000013u
  #define  VP_PIPOL_PIPOL19_DEFAULT        0x00000000u
  #define  VP_PIPOL_PIPOL19_OF(x)          _VALUEOF(x)
  #define  VP_PIPOL_PIPOL19_VDATA19ACTHI   0x00000000u
  #define  VP_PIPOL_PIPOL19_VDATA19ACTLO   0x00000001u
  
  #define _VP_PIPOL_PIPOL18_MASK           0x00040000u
  #define _VP_PIPOL_PIPOL18_SHIFT          0x00000012u
  #define  VP_PIPOL_PIPOL18_DEFAULT        0x00000000u
  #define  VP_PIPOL_PIPOL18_OF(x)          _VALUEOF(x)
  #define  VP_PIPOL_PIPOL18_VDATA18ACTHI   0x00000000u
  #define  VP_PIPOL_PIPOL18_VDATA18ACTLO   0x00000001u
  
  #define _VP_PIPOL_PIPOL17_MASK           0x00020000u
  #define _VP_PIPOL_PIPOL17_SHIFT          0x00000011u
  #define  VP_PIPOL_PIPOL17_DEFAULT        0x00000000u
  #define  VP_PIPOL_PIPOL17_OF(x)          _VALUEOF(x)
  #define  VP_PIPOL_PIPOL17_VDATA17ACTHI   0x00000000u
  #define  VP_PIPOL_PIPOL17_VDATA17ACTLO   0x00000001u
  
  #define _VP_PIPOL_PIPOL16_MASK           0x00010000u
  #define _VP_PIPOL_PIPOL16_SHIFT          0x00000010u
  #define  VP_PIPOL_PIPOL16_DEFAULT        0x00000000u
  #define  VP_PIPOL_PIPOL16_OF(x)          _VALUEOF(x)
  #define  VP_PIPOL_PIPOL16_VDATA16ACTHI   0x00000000u
  #define  VP_PIPOL_PIPOL16_VDATA16ACTLO   0x00000001u
  
  #define _VP_PIPOL_PIPOL15_MASK           0x00008000u
  #define _VP_PIPOL_PIPOL15_SHIFT          0x0000000Fu
  #define  VP_PIPOL_PIPOL15_DEFAULT        0x00000000u
  #define  VP_PIPOL_PIPOL15_OF(x)          _VALUEOF(x)
  #define  VP_PIPOL_PIPOL15_VDATA15ACTHI   0x00000000u
  #define  VP_PIPOL_PIPOL15_VDATA15ACTLO   0x00000001u
  
  #define _VP_PIPOL_PIPOL14_MASK           0x00004000u
  #define _VP_PIPOL_PIPOL14_SHIFT          0x0000000Eu
  #define  VP_PIPOL_PIPOL14_DEFAULT        0x00000000u
  #define  VP_PIPOL_PIPOL14_OF(x)          _VALUEOF(x)
  #define  VP_PIPOL_PIPOL14_VDATA14ACTHI   0x00000000u
  #define  VP_PIPOL_PIPOL14_VDATA14ACTLO   0x00000001u
  
  #define _VP_PIPOL_PIPOL13_MASK           0x00002000u
  #define _VP_PIPOL_PIPOL13_SHIFT          0x0000000Du
  #define  VP_PIPOL_PIPOL13_DEFAULT        0x00000000u
  #define  VP_PIPOL_PIPOL13_OF(x)          _VALUEOF(x)
  #define  VP_PIPOL_PIPOL13_VDATA13ACTHI   0x00000000u
  #define  VP_PIPOL_PIPOL13_VDATA13ACTLO   0x00000001u
  
  #define _VP_PIPOL_PIPOL12_MASK           0x00001000u
  #define _VP_PIPOL_PIPOL12_SHIFT          0x0000000Cu
  #define  VP_PIPOL_PIPOL12_DEFAULT        0x00000000u
  #define  VP_PIPOL_PIPOL12_OF(x)          _VALUEOF(x)
  #define  VP_PIPOL_PIPOL12_VDATA12ACTHI   0x00000000u
  #define  VP_PIPOL_PIPOL12_VDATA12ACTLO   0x00000001u
  
  #define _VP_PIPOL_PIPOL11_MASK           0x00000800u
  #define _VP_PIPOL_PIPOL11_SHIFT          0x0000000Bu
  #define  VP_PIPOL_PIPOL11_DEFAULT        0x00000000u
  #define  VP_PIPOL_PIPOL11_OF(x)          _VALUEOF(x)
  #define  VP_PIPOL_PIPOL11_VDATA11ACTHI   0x00000000u
  #define  VP_PIPOL_PIPOL11_VDATA11ACTLO   0x00000001u
  
  #define _VP_PIPOL_PIPOL10_MASK           0x00000400u
  #define _VP_PIPOL_PIPOL10_SHIFT          0x0000000Au
  #define  VP_PIPOL_PIPOL10_DEFAULT        0x00000000u
  #define  VP_PIPOL_PIPOL10_OF(x)          _VALUEOF(x)
  #define  VP_PIPOL_PIPOL10_VDATA10ACTHI   0x00000000u
  #define  VP_PIPOL_PIPOL10_VDATA10ACTLO   0x00000001u
  
  #define _VP_PIPOL_PIPOL9_MASK            0x00000200u
  #define _VP_PIPOL_PIPOL9_SHIFT           0x00000009u
  #define  VP_PIPOL_PIPOL9_DEFAULT         0x00000000u
  #define  VP_PIPOL_PIPOL9_OF(x)           _VALUEOF(x)
  #define  VP_PIPOL_PIPOL9_VDATA9ACTHI     0x00000000u
  #define  VP_PIPOL_PIPOL9_VDATA9ACTLO     0x00000001u
  
  #define _VP_PIPOL_PIPOL8_MASK            0x00000100u
  #define _VP_PIPOL_PIPOL8_SHIFT           0x00000008u
  #define  VP_PIPOL_PIPOL8_DEFAULT         0x00000000u
  #define  VP_PIPOL_PIPOL8_OF(x)           _VALUEOF(x)
  #define  VP_PIPOL_PIPOL8_VDATA8ACTHI     0x00000000u
  #define  VP_PIPOL_PIPOL8_VDATA8ACTLO     0x00000001u
  
  #define _VP_PIPOL_PIPOL7_MASK            0x00000080u
  #define _VP_PIPOL_PIPOL7_SHIFT           0x00000007u
  #define  VP_PIPOL_PIPOL7_DEFAULT         0x00000000u
  #define  VP_PIPOL_PIPOL7_OF(x)           _VALUEOF(x)
  #define  VP_PIPOL_PIPOL7_VDATA7ACTHI     0x00000000u
  #define  VP_PIPOL_PIPOL7_VDATA7ACTLO     0x00000001u
  
  #define _VP_PIPOL_PIPOL6_MASK            0x00000040u
  #define _VP_PIPOL_PIPOL6_SHIFT           0x00000006u
  #define  VP_PIPOL_PIPOL6_DEFAULT         0x00000000u
  #define  VP_PIPOL_PIPOL6_OF(x)           _VALUEOF(x)
  #define  VP_PIPOL_PIPOL6_VDATA6ACTHI     0x00000000u
  #define  VP_PIPOL_PIPOL6_VDATA6ACTLO     0x00000001u
  
  #define _VP_PIPOL_PIPOL5_MASK            0x00000020u
  #define _VP_PIPOL_PIPOL5_SHIFT           0x00000005u
  #define  VP_PIPOL_PIPOL5_DEFAULT         0x00000000u
  #define  VP_PIPOL_PIPOL5_OF(x)           _VALUEOF(x)
  #define  VP_PIPOL_PIPOL5_VDATA5ACTHI     0x00000000u
  #define  VP_PIPOL_PIPOL5_VDATA5ACTLO     0x00000001u
  
  #define _VP_PIPOL_PIPOL4_MASK            0x00000010u
  #define _VP_PIPOL_PIPOL4_SHIFT           0x00000004u
  #define  VP_PIPOL_PIPOL4_DEFAULT         0x00000000u
  #define  VP_PIPOL_PIPOL4_OF(x)           _VALUEOF(x)
  #define  VP_PIPOL_PIPOL4_VDATA4ACTHI     0x00000000u
  #define  VP_PIPOL_PIPOL4_VDATA4ACTLO     0x00000001u
  
  #define _VP_PIPOL_PIPOL3_MASK            0x00000008u
  #define _VP_PIPOL_PIPOL3_SHIFT           0x00000003u
  #define  VP_PIPOL_PIPOL3_DEFAULT         0x00000000u
  #define  VP_PIPOL_PIPOL3_OF(x)           _VALUEOF(x)
  #define  VP_PIPOL_PIPOL3_VDATA3ACTHI     0x00000000u
  #define  VP_PIPOL_PIPOL3_VDATA3ACTLO     0x00000001u
  
  #define _VP_PIPOL_PIPOL2_MASK            0x00000004u
  #define _VP_PIPOL_PIPOL2_SHIFT           0x00000002u
  #define  VP_PIPOL_PIPOL2_DEFAULT         0x00000000u
  #define  VP_PIPOL_PIPOL2_OF(x)           _VALUEOF(x)
  #define  VP_PIPOL_PIPOL2_VDATA2ACTHI     0x00000000u
  #define  VP_PIPOL_PIPOL2_VDATA2ACTLO     0x00000001u
  
  #define _VP_PIPOL_PIPOL1_MASK            0x00000002u
  #define _VP_PIPOL_PIPOL1_SHIFT           0x00000001u
  #define  VP_PIPOL_PIPOL1_DEFAULT         0x00000000u
  #define  VP_PIPOL_PIPOL1_OF(x)           _VALUEOF(x)
  #define  VP_PIPOL_PIPOL1_VDATA1ACTHI     0x00000000u
  #define  VP_PIPOL_PIPOL1_VDATA1ACTLO     0x00000001u
  
  #define _VP_PIPOL_PIPOL0_MASK            0x00000001u
  #define _VP_PIPOL_PIPOL0_SHIFT           0x00000000u
  #define  VP_PIPOL_PIPOL0_DEFAULT         0x00000000u
  #define  VP_PIPOL_PIPOL0_OF(x)           _VALUEOF(x)
  #define  VP_PIPOL_PIPOL0_VDATA0ACTHI     0x00000000u
  #define  VP_PIPOL_PIPOL0_VDATA0ACTLO     0x00000001u
  
  #define  VP_PIPOL_OF(x)             _VALUEOF(x)

  #define VP_PIPOL_DEFAULT (Uint32)(\
    _PER_FDEFAULT(VP,PIPOL,PIPOL22)\
   |_PER_FDEFAULT(VP,PIPOL,PIPOL21)\
   |_PER_FDEFAULT(VP,PIPOL,PIPOL20)\
   |_PER_FDEFAULT(VP,PIPOL,PIPOL19)\
   |_PER_FDEFAULT(VP,PIPOL,PIPOL18)\
   |_PER_FDEFAULT(VP,PIPOL,PIPOL17)\
   |_PER_FDEFAULT(VP,PIPOL,PIPOL16)\
   |_PER_FDEFAULT(VP,PIPOL,PIPOL15)\
   |_PER_FDEFAULT(VP,PIPOL,PIPOL14)\
   |_PER_FDEFAULT(VP,PIPOL,PIPOL13)\
   |_PER_FDEFAULT(VP,PIPOL,PIPOL12)\
   |_PER_FDEFAULT(VP,PIPOL,PIPOL11)\
   |_PER_FDEFAULT(VP,PIPOL,PIPOL10)\
   |_PER_FDEFAULT(VP,PIPOL,PIPOL9)\
   |_PER_FDEFAULT(VP,PIPOL,PIPOL8)\
   |_PER_FDEFAULT(VP,PIPOL,PIPOL7)\
   |_PER_FDEFAULT(VP,PIPOL,PIPOL6)\
   |_PER_FDEFAULT(VP,PIPOL,PIPOL5)\
   |_PER_FDEFAULT(VP,PIPOL,PIPOL4)\
   |_PER_FDEFAULT(VP,PIPOL,PIPOL3)\
   |_PER_FDEFAULT(VP,PIPOL,PIPOL2)\
   |_PER_FDEFAULT(VP,PIPOL,PIPOL1)\
   |_PER_FDEFAULT(VP,PIPOL,PIPOL0)\
  )

#define VP_PIPOL_RMK(pipol22,pipol21,pipol20,pipol19,pipol18,pipol17,pipol16,\
  pipol15,pipol14,pipol13,pipol12,pipol11,pipol10,pipol9,pipol8,pipol7,\
  pipol6,pipol5,pipol4,pipol3,pipol2,pipol1,pipol0) (Uint32)(\
    _PER_FMK(VP,PIPOL,PIPOL22,pipol22)\
   |_PER_FMK(VP,PIPOL,PIPOL21,pipol21)\
   |_PER_FMK(VP,PIPOL,PIPOL20,pipol20)\
   |_PER_FMK(VP,PIPOL,PIPOL19,pipol19)\
   |_PER_FMK(VP,PIPOL,PIPOL18,pipol18)\
   |_PER_FMK(VP,PIPOL,PIPOL17,pipol17)\
   |_PER_FMK(VP,PIPOL,PIPOL16,pipol16)\
   |_PER_FMK(VP,PIPOL,PIPOL15,pipol15)\
   |_PER_FMK(VP,PIPOL,PIPOL14,pipol14)\
   |_PER_FMK(VP,PIPOL,PIPOL13,pipol13)\
   |_PER_FMK(VP,PIPOL,PIPOL12,pipol12)\
   |_PER_FMK(VP,PIPOL,PIPOL11,pipol11)\
   |_PER_FMK(VP,PIPOL,PIPOL10,pipol10)\
   |_PER_FMK(VP,PIPOL,PIPOL9,pipol9)\
   |_PER_FMK(VP,PIPOL,PIPOL8,pipol8)\
   |_PER_FMK(VP,PIPOL,PIPOL7,pipol7)\
   |_PER_FMK(VP,PIPOL,PIPOL6,pipol6)\
   |_PER_FMK(VP,PIPOL,PIPOL5,pipol5)\
   |_PER_FMK(VP,PIPOL,PIPOL4,pipol4)\
   |_PER_FMK(VP,PIPOL,PIPOL3,pipol3)\
   |_PER_FMK(VP,PIPOL,PIPOL2,pipol2)\
   |_PER_FMK(VP,PIPOL,PIPOL1,pipol1)\
   |_PER_FMK(VP,PIPOL,PIPOL0,pipol0)\
  )

  #define _VP_PIPOL_FGET(N,FIELD)\
    _PER_FGET(_VP_PIPOL##N##_ADDR,VP,PIPOL,##FIELD)

  #define _VP_PIPOL_FSET(N,FIELD,field)\
    _PER_FSET(_VP_PIPOL##N##_ADDR,VP,PIPOL,##FIELD,field)

  #define _VP_PIPOL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_PIPOL##N##_ADDR,VP,PIPOL,##FIELD,##SYM)

  #define _VP_PIPOL0_FGET(FIELD)   _VP_PIPOL_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PIPOL1_FGET(FIELD)   _VP_PIPOL_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_PIPOL2_FGET(FIELD)   _VP_PIPOL_FGET(2,##FIELD)
 #endif


  #define _VP_PIPOL0_FSET(FIELD,f)   _VP_PIPOL_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PIPOL1_FSET(FIELD,f)   _VP_PIPOL_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_PIPOL2_FSET(FIELD,f)   _VP_PIPOL_FSET(2,##FIELD,f)
 #endif


  #define _VP_PIPOL0_FSETS(FIELD,SYM)   _VP_PIPOL_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PIPOL1_FSETS(FIELD,SYM)   _VP_PIPOL_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_PIPOL2_FSETS(FIELD,SYM)   _VP_PIPOL_FSETS(2,##FIELD,##SYM)
 #endif

  
/******************************************************************************\
* _____________________
* |                   |
* |  P I S T A T      |
* |___________________|
*
* PISTAT0  - Video Port 0 Pin Interrupt Status Register
* PISTAT1  - Video Port 1 Pin Interrupt Status Register
* PISTAT2  - Video Port 2 Pin Interrupt Status Register
*
* FIELDS (msb -> lsb)
* (r) PISTAT22
* (r) PISTAT21
* (r) PISTAT20
* (r) PISTAT19
* (r) PISTAT18
* (r) PISTAT17
* (r) PISTAT16
* (r) PISTAT15
* (r) PISTAT14
* (r) PISTAT13
* (r) PISTAT12
* (r) PISTAT11
* (r) PISTAT10
* (r) PISTAT9
* (r) PISTAT8
* (r) PISTAT7
* (r) PISTAT6
* (r) PISTAT5
* (r) PISTAT4
* (r) PISTAT3
* (r) PISTAT2
* (r) PISTAT1
* (r) PISTAT0
*
\******************************************************************************/
  #define _VP_PISTAT_OFFSET            16

  #define _VP_PISTAT0_ADDR   (_VP_BASE_PORT0 + 4*_VP_PISTAT_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PISTAT1_ADDR   (_VP_BASE_PORT1 + 4*_VP_PISTAT_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_PISTAT2_ADDR   (_VP_BASE_PORT2 + 4*_VP_PISTAT_OFFSET)
 #endif


  #define _VP_PISTAT_PISTAT22_MASK           0x00400000u
  #define _VP_PISTAT_PISTAT22_SHIFT          0x00000016u
  #define  VP_PISTAT_PISTAT22_DEFAULT        0x00000000u
  #define  VP_PISTAT_PISTAT22_OF(x)          _VALUEOF(x)
  #define  VP_PISTAT_PISTAT22_NONE           0x00000000u
  #define  VP_PISTAT_PISTAT22_VCTL2INT       0x00000001u
  
  #define _VP_PISTAT_PISTAT21_MASK           0x00200000u
  #define _VP_PISTAT_PISTAT21_SHIFT          0x00000015u
  #define  VP_PISTAT_PISTAT21_DEFAULT        0x00000000u
  #define  VP_PISTAT_PISTAT21_OF(x)          _VALUEOF(x)
  #define  VP_PISTAT_PISTAT21_NONE           0x00000000u
  #define  VP_PISTAT_PISTAT21_VCTL1INT       0x00000001u
  
  #define _VP_PISTAT_PISTAT20_MASK           0x00100000u
  #define _VP_PISTAT_PISTAT20_SHIFT          0x00000014u
  #define  VP_PISTAT_PISTAT20_DEFAULT        0x00000000u
  #define  VP_PISTAT_PISTAT20_OF(x)          _VALUEOF(x)
  #define  VP_PISTAT_PISTAT20_NONE           0x00000000u
  #define  VP_PISTAT_PISTAT20_VCTL0INT       0x00000001u
  
  #define _VP_PISTAT_PISTAT19_MASK           0x00080000u
  #define _VP_PISTAT_PISTAT19_SHIFT          0x00000013u
  #define  VP_PISTAT_PISTAT19_DEFAULT        0x00000000u
  #define  VP_PISTAT_PISTAT19_OF(x)          _VALUEOF(x)
  #define  VP_PISTAT_PISTAT19_NONE           0x00000000u
  #define  VP_PISTAT_PISTAT19_VDATA19INT     0x00000001u
  
  #define _VP_PISTAT_PISTAT18_MASK           0x00040000u
  #define _VP_PISTAT_PISTAT18_SHIFT          0x00000012u
  #define  VP_PISTAT_PISTAT18_DEFAULT        0x00000000u
  #define  VP_PISTAT_PISTAT18_OF(x)          _VALUEOF(x)
  #define  VP_PISTAT_PISTAT18_NONE           0x00000000u
  #define  VP_PISTAT_PISTAT18_VDATA18INT     0x00000001u
  
  #define _VP_PISTAT_PISTAT17_MASK           0x00020000u
  #define _VP_PISTAT_PISTAT17_SHIFT          0x00000011u
  #define  VP_PISTAT_PISTAT17_DEFAULT        0x00000000u
  #define  VP_PISTAT_PISTAT17_OF(x)          _VALUEOF(x)
  #define  VP_PISTAT_PISTAT17_NONE           0x00000000u
  #define  VP_PISTAT_PISTAT17_VDATA17INT     0x00000001u
  
  #define _VP_PISTAT_PISTAT16_MASK           0x00010000u
  #define _VP_PISTAT_PISTAT16_SHIFT          0x00000010u
  #define  VP_PISTAT_PISTAT16_DEFAULT        0x00000000u
  #define  VP_PISTAT_PISTAT16_OF(x)          _VALUEOF(x)
  #define  VP_PISTAT_PISTAT16_NONE           0x00000000u
  #define  VP_PISTAT_PISTAT16_VDATA16INT     0x00000001u
  
  #define _VP_PISTAT_PISTAT15_MASK           0x00008000u
  #define _VP_PISTAT_PISTAT15_SHIFT          0x0000000Fu
  #define  VP_PISTAT_PISTAT15_DEFAULT        0x00000000u
  #define  VP_PISTAT_PISTAT15_OF(x)          _VALUEOF(x)
  #define  VP_PISTAT_PISTAT15_NONE           0x00000000u
  #define  VP_PISTAT_PISTAT15_VDATA15INT     0x00000001u
  
  #define _VP_PISTAT_PISTAT14_MASK           0x00004000u
  #define _VP_PISTAT_PISTAT14_SHIFT          0x0000000Eu
  #define  VP_PISTAT_PISTAT14_DEFAULT        0x00000000u
  #define  VP_PISTAT_PISTAT14_OF(x)          _VALUEOF(x)
  #define  VP_PISTAT_PISTAT14_NONE           0x00000000u
  #define  VP_PISTAT_PISTAT14_VDATA14INT     0x00000001u
  
  #define _VP_PISTAT_PISTAT13_MASK           0x00002000u
  #define _VP_PISTAT_PISTAT13_SHIFT          0x0000000Du
  #define  VP_PISTAT_PISTAT13_DEFAULT        0x00000000u
  #define  VP_PISTAT_PISTAT13_OF(x)          _VALUEOF(x)
  #define  VP_PISTAT_PISTAT13_NONE           0x00000000u
  #define  VP_PISTAT_PISTAT13_VDATA13INT     0x00000001u
  
  #define _VP_PISTAT_PISTAT12_MASK           0x00001000u
  #define _VP_PISTAT_PISTAT12_SHIFT          0x0000000Cu
  #define  VP_PISTAT_PISTAT12_DEFAULT        0x00000000u
  #define  VP_PISTAT_PISTAT12_OF(x)          _VALUEOF(x)
  #define  VP_PISTAT_PISTAT12_NONE           0x00000000u
  #define  VP_PISTAT_PISTAT12_VDATA12INT     0x00000001u
  
  #define _VP_PISTAT_PISTAT11_MASK           0x00000800u
  #define _VP_PISTAT_PISTAT11_SHIFT          0x0000000Bu
  #define  VP_PISTAT_PISTAT11_DEFAULT        0x00000000u
  #define  VP_PISTAT_PISTAT11_OF(x)          _VALUEOF(x)
  #define  VP_PISTAT_PISTAT11_NONE           0x00000000u
  #define  VP_PISTAT_PISTAT11_VDATA11INT     0x00000001u
  
  #define _VP_PISTAT_PISTAT10_MASK           0x00000400u
  #define _VP_PISTAT_PISTAT10_SHIFT          0x0000000Au
  #define  VP_PISTAT_PISTAT10_DEFAULT        0x00000000u
  #define  VP_PISTAT_PISTAT10_OF(x)          _VALUEOF(x)
  #define  VP_PISTAT_PISTAT10_NONE           0x00000000u
  #define  VP_PISTAT_PISTAT10_VDATA10INT     0x00000001u
  
  #define _VP_PISTAT_PISTAT9_MASK            0x00000200u
  #define _VP_PISTAT_PISTAT9_SHIFT           0x00000009u
  #define  VP_PISTAT_PISTAT9_DEFAULT         0x00000000u
  #define  VP_PISTAT_PISTAT9_OF(x)           _VALUEOF(x)
  #define  VP_PISTAT_PISTAT9_NONE            0x00000000u
  #define  VP_PISTAT_PISTAT9_VDATA9INT       0x00000001u
  
  #define _VP_PISTAT_PISTAT8_MASK            0x00000100u
  #define _VP_PISTAT_PISTAT8_SHIFT           0x00000008u
  #define  VP_PISTAT_PISTAT8_DEFAULT         0x00000000u
  #define  VP_PISTAT_PISTAT8_OF(x)           _VALUEOF(x)
  #define  VP_PISTAT_PISTAT8_NONE            0x00000000u
  #define  VP_PISTAT_PISTAT8_VDATA8INT       0x00000001u
  
  #define _VP_PISTAT_PISTAT7_MASK            0x00000080u
  #define _VP_PISTAT_PISTAT7_SHIFT           0x00000007u
  #define  VP_PISTAT_PISTAT7_DEFAULT         0x00000000u
  #define  VP_PISTAT_PISTAT7_OF(x)           _VALUEOF(x)
  #define  VP_PISTAT_PISTAT7_NONE            0x00000000u
  #define  VP_PISTAT_PISTAT7_VDATA7INT       0x00000001u
  
  #define _VP_PISTAT_PISTAT6_MASK            0x00000040u
  #define _VP_PISTAT_PISTAT6_SHIFT           0x00000006u
  #define  VP_PISTAT_PISTAT6_DEFAULT         0x00000000u
  #define  VP_PISTAT_PISTAT6_OF(x)           _VALUEOF(x)
  #define  VP_PISTAT_PISTAT6_NONE            0x00000000u
  #define  VP_PISTAT_PISTAT6_VDATA6INT       0x00000001u
  
  #define _VP_PISTAT_PISTAT5_MASK            0x00000020u
  #define _VP_PISTAT_PISTAT5_SHIFT           0x00000005u
  #define  VP_PISTAT_PISTAT5_DEFAULT         0x00000000u
  #define  VP_PISTAT_PISTAT5_OF(x)           _VALUEOF(x)
  #define  VP_PISTAT_PISTAT5_NONE            0x00000000u
  #define  VP_PISTAT_PISTAT5_VDATA5INT       0x00000001u
  
  #define _VP_PISTAT_PISTAT4_MASK            0x00000010u
  #define _VP_PISTAT_PISTAT4_SHIFT           0x00000004u
  #define  VP_PISTAT_PISTAT4_DEFAULT         0x00000000u
  #define  VP_PISTAT_PISTAT4_OF(x)           _VALUEOF(x)
  #define  VP_PISTAT_PISTAT4_NONE            0x00000000u
  #define  VP_PISTAT_PISTAT4_VDATA4INT       0x00000001u
  
  #define _VP_PISTAT_PISTAT3_MASK            0x00000008u
  #define _VP_PISTAT_PISTAT3_SHIFT           0x00000003u
  #define  VP_PISTAT_PISTAT3_DEFAULT         0x00000000u
  #define  VP_PISTAT_PISTAT3_OF(x)           _VALUEOF(x)
  #define  VP_PISTAT_PISTAT3_NONE            0x00000000u
  #define  VP_PISTAT_PISTAT3_VDATA3INT       0x00000001u
  
  #define _VP_PISTAT_PISTAT2_MASK            0x00000004u
  #define _VP_PISTAT_PISTAT2_SHIFT           0x00000002u
  #define  VP_PISTAT_PISTAT2_DEFAULT         0x00000000u
  #define  VP_PISTAT_PISTAT2_OF(x)           _VALUEOF(x)
  #define  VP_PISTAT_PISTAT2_NONE            0x00000000u
  #define  VP_PISTAT_PISTAT2_VDATA2INT       0x00000001u
  
  #define _VP_PISTAT_PISTAT1_MASK            0x00000002u
  #define _VP_PISTAT_PISTAT1_SHIFT           0x00000001u
  #define  VP_PISTAT_PISTAT1_DEFAULT         0x00000000u
  #define  VP_PISTAT_PISTAT1_OF(x)           _VALUEOF(x)
  #define  VP_PISTAT_PISTAT1_NONE            0x00000000u
  #define  VP_PISTAT_PISTAT1_VDATA1INT       0x00000001u
  
  #define _VP_PISTAT_PISTAT0_MASK            0x00000001u
  #define _VP_PISTAT_PISTAT0_SHIFT           0x00000000u
  #define  VP_PISTAT_PISTAT0_DEFAULT         0x00000000u
  #define  VP_PISTAT_PISTAT0_OF(x)           _VALUEOF(x)
  #define  VP_PISTAT_PISTAT0_NONE            0x00000000u
  #define  VP_PISTAT_PISTAT0_VDATA0INT       0x00000001u
  
  #define  VP_PISTAT_OF(x)             _VALUEOF(x)

  #define VP_PISTAT_DEFAULT (Uint32)(\
    _PER_FDEFAULT(VP,PISTAT,PISTAT22)\
   |_PER_FDEFAULT(VP,PISTAT,PISTAT21)\
   |_PER_FDEFAULT(VP,PISTAT,PISTAT20)\
   |_PER_FDEFAULT(VP,PISTAT,PISTAT19)\
   |_PER_FDEFAULT(VP,PISTAT,PISTAT18)\
   |_PER_FDEFAULT(VP,PISTAT,PISTAT17)\
   |_PER_FDEFAULT(VP,PISTAT,PISTAT16)\
   |_PER_FDEFAULT(VP,PISTAT,PISTAT15)\
   |_PER_FDEFAULT(VP,PISTAT,PISTAT14)\
   |_PER_FDEFAULT(VP,PISTAT,PISTAT13)\
   |_PER_FDEFAULT(VP,PISTAT,PISTAT12)\
   |_PER_FDEFAULT(VP,PISTAT,PISTAT11)\
   |_PER_FDEFAULT(VP,PISTAT,PISTAT10)\
   |_PER_FDEFAULT(VP,PISTAT,PISTAT9)\
   |_PER_FDEFAULT(VP,PISTAT,PISTAT8)\
   |_PER_FDEFAULT(VP,PISTAT,PISTAT7)\
   |_PER_FDEFAULT(VP,PISTAT,PISTAT6)\
   |_PER_FDEFAULT(VP,PISTAT,PISTAT5)\
   |_PER_FDEFAULT(VP,PISTAT,PISTAT4)\
   |_PER_FDEFAULT(VP,PISTAT,PISTAT3)\
   |_PER_FDEFAULT(VP,PISTAT,PISTAT2)\
   |_PER_FDEFAULT(VP,PISTAT,PISTAT1)\
   |_PER_FDEFAULT(VP,PISTAT,PISTAT0)\
  )
#if (!(CHIP_6413 | CHIP_6418 | CHIP_6410))
   #define VP_PISTAT_RMK(pistat22,pistat21,pistat20,pistat19,pistat18,pistat17,pistat16,\
  pistat15,pistat14,pistat13,pistat12,pistat11,pistat10,pistat9,pistat8,pistat7,\
  pistat6,pistat5,pistat4,pistat3,pistat2,pistat1,pistat0) (Uint32)(\
    _PER_FMK(VP,PISTAT,PISTAT22,pistat22)\
   |_PER_FMK(VP,PISTAT,PISTAT21,pistat21)\
   |_PER_FMK(VP,PISTAT,PISTAT20,pistat20)\
   |_PER_FMK(VP,PISTAT,PISTAT19,pistat19)\
   |_PER_FMK(VP,PISTAT,PISTAT18,pistat18)\
   |_PER_FMK(VP,PISTAT,PISTAT17,pistat17)\
   |_PER_FMK(VP,PISTAT,PISTAT16,pistat16)\
   |_PER_FMK(VP,PISTAT,PISTAT15,pistat15)\
   |_PER_FMK(VP,PISTAT,PISTAT14,pistat14)\
   |_PER_FMK(VP,PISTAT,PISTAT13,pistat13)\
   |_PER_FMK(VP,PISTAT,PISTAT12,pistat12)\
   |_PER_FMK(VP,PISTAT,PISTAT11,pistat11)\
   |_PER_FMK(VP,PISTAT,PISTAT10,pistat10)\
   |_PER_FMK(VP,PISTAT,PISTAT9,pistat9)\
   |_PER_FMK(VP,PISTAT,PISTAT8,pistat8)\
   |_PER_FMK(VP,PISTAT,PISTAT7,pistat7)\
   |_PER_FMK(VP,PISTAT,PISTAT6,pistat6)\
   |_PER_FMK(VP,PISTAT,PISTAT5,pistat5)\
   |_PER_FMK(VP,PISTAT,PISTAT4,pistat4)\
   |_PER_FMK(VP,PISTAT,PISTAT3,pistat3)\
   |_PER_FMK(VP,PISTAT,PISTAT2,pistat2)\
   |_PER_FMK(VP,PISTAT,PISTAT1,pistat1)\
   |_PER_FMK(VP,PISTAT,PISTAT0,pistat0)\
  )
#endif  
	
  #define _VP_PISTAT_FGET(N,FIELD)\
    _PER_FGET(_VP_PISTAT##N##_ADDR,VP,PISTAT,##FIELD)

  #define _VP_PISTAT_FSET(N,FIELD,field)\
    _PER_FSET(_VP_PISTAT##N##_ADDR,VP,PISTAT,##FIELD,field)

  #define _VP_PISTAT_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_PISTAT##N##_ADDR,VP,PISTAT,##FIELD,##SYM)
   
  #define _VP_PISTAT0_FGET(FIELD)   _VP_PISTAT_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PISTAT1_FGET(FIELD)   _VP_PISTAT_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_PISTAT2_FGET(FIELD)   _VP_PISTAT_FGET(2,##FIELD)		
 #endif

  
  #define _VP_PISTAT0_FSET(FIELD,f)   _VP_PISTAT_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PISTAT1_FSET(FIELD,f)   _VP_PISTAT_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_PISTAT2_FSET(FIELD,f)   _VP_PISTAT_FSET(2,##FIELD,f)
 #endif


  #define _VP_PISTAT0_FSETS(FIELD,SYM)   _VP_PISTAT_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PISTAT1_FSETS(FIELD,SYM)   _VP_PISTAT_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_PISTAT2_FSETS(FIELD,SYM)   _VP_PISTAT_FSETS(2,##FIELD,##SYM)
 #endif

  

/**************************************************************\
* ___________________
* |                   |
* |  P I C L R        |
* |___________________|
*
* PICLR0  - Video Port 0 Pin Interrupt Clear Register
* PICLR1  - Video Port 1 Pin Interrupt Clear Register
* PICLR2  - Video Port 2 Pin Interrupt Clear Register
*
* FIELDS (msb -> lsb)
* (w) PICLR22
* (w) PICLR21
* (w) PICLR20
* (w) PICLR19
* (w) PICLR18
* (w) PICLR17
* (w) PICLR16
* (w) PICLR15
* (w) PICLR14
* (w) PICLR13
* (w) PICLR12
* (w) PICLR11
* (w) PICLR10
* (w) PICLR9
* (w) PICLR8
* (w) PICLR7
* (w) PICLR6
* (w) PICLR5
* (w) PICLR4
* (w) PICLR3
* (w) PICLR2
* (w) PICLR1
* (w) PICLR0
*
\******************************************************************************/
  #define _VP_PICLR_OFFSET            17

  #define _VP_PICLR0_ADDR   (_VP_BASE_PORT0 + 4*_VP_PICLR_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PICLR1_ADDR   (_VP_BASE_PORT1 + 4*_VP_PICLR_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_PICLR2_ADDR   (_VP_BASE_PORT2 + 4*_VP_PICLR_OFFSET)
 #endif


  #define _VP_PICLR_PICLR22_MASK           0x00400000u
  #define _VP_PICLR_PICLR22_SHIFT          0x00000016u
  #define  VP_PICLR_PICLR22_DEFAULT        0x00000000u
  #define  VP_PICLR_PICLR22_OF(x)          _VALUEOF(x)
  #define  VP_PICLR_PICLR22_NONE           0x00000000u
  #define  VP_PICLR_PICLR22_VCTL2CLR       0x00000001u
  
  #define _VP_PICLR_PICLR21_MASK           0x00200000u
  #define _VP_PICLR_PICLR21_SHIFT          0x00000015u
  #define  VP_PICLR_PICLR21_DEFAULT        0x00000000u
  #define  VP_PICLR_PICLR21_OF(x)          _VALUEOF(x)
  #define  VP_PICLR_PICLR21_NONE           0x00000000u
  #define  VP_PICLR_PICLR21_VCTL1CLR       0x00000001u
  
  #define _VP_PICLR_PICLR20_MASK           0x00100000u
  #define _VP_PICLR_PICLR20_SHIFT          0x00000014u
  #define  VP_PICLR_PICLR20_DEFAULT        0x00000000u
  #define  VP_PICLR_PICLR20_OF(x)          _VALUEOF(x)
  #define  VP_PICLR_PICLR20_NONE           0x00000000u
  #define  VP_PICLR_PICLR20_VCTL0CLR       0x00000001u
  
  #define _VP_PICLR_PICLR19_MASK           0x00080000u
  #define _VP_PICLR_PICLR19_SHIFT          0x00000013u
  #define  VP_PICLR_PICLR19_DEFAULT        0x00000000u
  #define  VP_PICLR_PICLR19_OF(x)          _VALUEOF(x)
  #define  VP_PICLR_PICLR19_NONE           0x00000000u
  #define  VP_PICLR_PICLR19_VDATA19CLR     0x00000001u
  
  #define _VP_PICLR_PICLR18_MASK           0x00040000u
  #define _VP_PICLR_PICLR18_SHIFT          0x00000012u
  #define  VP_PICLR_PICLR18_DEFAULT        0x00000000u
  #define  VP_PICLR_PICLR18_OF(x)          _VALUEOF(x)
  #define  VP_PICLR_PICLR18_NONE           0x00000000u
  #define  VP_PICLR_PICLR18_VDATA18CLR     0x00000001u
  
  #define _VP_PICLR_PICLR17_MASK           0x00020000u
  #define _VP_PICLR_PICLR17_SHIFT          0x00000011u
  #define  VP_PICLR_PICLR17_DEFAULT        0x00000000u
  #define  VP_PICLR_PICLR17_OF(x)          _VALUEOF(x)
  #define  VP_PICLR_PICLR17_NONE           0x00000000u
  #define  VP_PICLR_PICLR17_VDATA17CLR     0x00000001u
  
  #define _VP_PICLR_PICLR16_MASK           0x00010000u
  #define _VP_PICLR_PICLR16_SHIFT          0x00000010u
  #define  VP_PICLR_PICLR16_DEFAULT        0x00000000u
  #define  VP_PICLR_PICLR16_OF(x)          _VALUEOF(x)
  #define  VP_PICLR_PICLR16_NONE           0x00000000u
  #define  VP_PICLR_PICLR16_VDATA16CLR     0x00000001u
  
  #define _VP_PICLR_PICLR15_MASK           0x00008000u
  #define _VP_PICLR_PICLR15_SHIFT          0x0000000Fu
  #define  VP_PICLR_PICLR15_DEFAULT        0x00000000u
  #define  VP_PICLR_PICLR15_OF(x)          _VALUEOF(x)
  #define  VP_PICLR_PICLR15_NONE           0x00000000u
  #define  VP_PICLR_PICLR15_VDATA15CLR     0x00000001u
  
  #define _VP_PICLR_PICLR14_MASK           0x00004000u
  #define _VP_PICLR_PICLR14_SHIFT          0x0000000Eu
  #define  VP_PICLR_PICLR14_DEFAULT        0x00000000u
  #define  VP_PICLR_PICLR14_OF(x)          _VALUEOF(x)
  #define  VP_PICLR_PICLR14_NONE           0x00000000u
  #define  VP_PICLR_PICLR14_VDATA14CLR     0x00000001u
  
  #define _VP_PICLR_PICLR13_MASK           0x00002000u
  #define _VP_PICLR_PICLR13_SHIFT          0x0000000Du
  #define  VP_PICLR_PICLR13_DEFAULT        0x00000000u
  #define  VP_PICLR_PICLR13_OF(x)          _VALUEOF(x)
  #define  VP_PICLR_PICLR13_NONE           0x00000000u
  #define  VP_PICLR_PICLR13_VDATA13CLR     0x00000001u
  
  #define _VP_PICLR_PICLR12_MASK           0x00001000u
  #define _VP_PICLR_PICLR12_SHIFT          0x0000000Cu
  #define  VP_PICLR_PICLR12_DEFAULT        0x00000000u
  #define  VP_PICLR_PICLR12_OF(x)          _VALUEOF(x)
  #define  VP_PICLR_PICLR12_NONE           0x00000000u
  #define  VP_PICLR_PICLR12_VDATA12CLR     0x00000001u
  
  #define _VP_PICLR_PICLR11_MASK           0x00000800u
  #define _VP_PICLR_PICLR11_SHIFT          0x0000000Bu
  #define  VP_PICLR_PICLR11_DEFAULT        0x00000000u
  #define  VP_PICLR_PICLR11_OF(x)          _VALUEOF(x)
  #define  VP_PICLR_PICLR11_NONE           0x00000000u
  #define  VP_PICLR_PICLR11_VDATA11CLR     0x00000001u
  
  #define _VP_PICLR_PICLR10_MASK           0x00000400u
  #define _VP_PICLR_PICLR10_SHIFT          0x0000000Au
  #define  VP_PICLR_PICLR10_DEFAULT        0x00000000u
  #define  VP_PICLR_PICLR10_OF(x)          _VALUEOF(x)
  #define  VP_PICLR_PICLR10_NONE           0x00000000u
  #define  VP_PICLR_PICLR10_VDATA10CLR     0x00000001u
  
  #define _VP_PICLR_PICLR9_MASK            0x00000200u
  #define _VP_PICLR_PICLR9_SHIFT           0x00000009u
  #define  VP_PICLR_PICLR9_DEFAULT         0x00000000u
  #define  VP_PICLR_PICLR9_OF(x)           _VALUEOF(x)
  #define  VP_PICLR_PICLR9_NONE            0x00000000u
  #define  VP_PICLR_PICLR9_VDATA9CLR       0x00000001u
  
  #define _VP_PICLR_PICLR8_MASK            0x00000100u
  #define _VP_PICLR_PICLR8_SHIFT           0x00000008u
  #define  VP_PICLR_PICLR8_DEFAULT         0x00000000u
  #define  VP_PICLR_PICLR8_OF(x)           _VALUEOF(x)
  #define  VP_PICLR_PICLR8_NONE            0x00000000u
  #define  VP_PICLR_PICLR8_VDATA8CLR       0x00000001u
  
  #define _VP_PICLR_PICLR7_MASK            0x00000080u
  #define _VP_PICLR_PICLR7_SHIFT           0x00000007u
  #define  VP_PICLR_PICLR7_DEFAULT         0x00000000u
  #define  VP_PICLR_PICLR7_OF(x)           _VALUEOF(x)
  #define  VP_PICLR_PICLR7_NONE            0x00000000u
  #define  VP_PICLR_PICLR7_VDATA7CLR       0x00000001u
  
  #define _VP_PICLR_PICLR6_MASK            0x00000040u
  #define _VP_PICLR_PICLR6_SHIFT           0x00000006u
  #define  VP_PICLR_PICLR6_DEFAULT         0x00000000u
  #define  VP_PICLR_PICLR6_OF(x)           _VALUEOF(x)
  #define  VP_PICLR_PICLR6_NONE            0x00000000u
  #define  VP_PICLR_PICLR6_VDATA6CLR       0x00000001u
  
  #define _VP_PICLR_PICLR5_MASK            0x00000020u
  #define _VP_PICLR_PICLR5_SHIFT           0x00000005u
  #define  VP_PICLR_PICLR5_DEFAULT         0x00000000u
  #define  VP_PICLR_PICLR5_OF(x)           _VALUEOF(x)
  #define  VP_PICLR_PICLR5_NONE            0x00000000u
  #define  VP_PICLR_PICLR5_VDATA5CLR       0x00000001u
  
  #define _VP_PICLR_PICLR4_MASK            0x00000010u
  #define _VP_PICLR_PICLR4_SHIFT           0x00000004u
  #define  VP_PICLR_PICLR4_DEFAULT         0x00000000u
  #define  VP_PICLR_PICLR4_OF(x)           _VALUEOF(x)
  #define  VP_PICLR_PICLR4_NONE            0x00000000u
  #define  VP_PICLR_PICLR4_VDATA4CLR       0x00000001u
  
  #define _VP_PICLR_PICLR3_MASK            0x00000008u
  #define _VP_PICLR_PICLR3_SHIFT           0x00000003u
  #define  VP_PICLR_PICLR3_DEFAULT         0x00000000u
  #define  VP_PICLR_PICLR3_OF(x)           _VALUEOF(x)
  #define  VP_PICLR_PICLR3_NONE            0x00000000u
  #define  VP_PICLR_PICLR3_VDATA3CLR       0x00000001u
  
  #define _VP_PICLR_PICLR2_MASK            0x00000004u
  #define _VP_PICLR_PICLR2_SHIFT           0x00000002u
  #define  VP_PICLR_PICLR2_DEFAULT         0x00000000u
  #define  VP_PICLR_PICLR2_OF(x)           _VALUEOF(x)
  #define  VP_PICLR_PICLR2_NONE            0x00000000u
  #define  VP_PICLR_PICLR2_VDATA2CLR       0x00000001u
  
  #define _VP_PICLR_PICLR1_MASK            0x00000002u
  #define _VP_PICLR_PICLR1_SHIFT           0x00000001u
  #define  VP_PICLR_PICLR1_DEFAULT         0x00000000u
  #define  VP_PICLR_PICLR1_OF(x)           _VALUEOF(x)
  #define  VP_PICLR_PICLR1_NONE            0x00000000u
  #define  VP_PICLR_PICLR1_VDATA1CLR       0x00000001u
  
  #define _VP_PICLR_PICLR0_MASK            0x00000001u
  #define _VP_PICLR_PICLR0_SHIFT           0x00000000u
  #define  VP_PICLR_PICLR0_DEFAULT         0x00000000u
  #define  VP_PICLR_PICLR0_OF(x)           _VALUEOF(x)
  #define  VP_PICLR_PICLR0_NONE            0x00000000u
  #define  VP_PICLR_PICLR0_VDATA0CLR       0x00000001u
  
  #define  VP_PICLR_OF(x)             _VALUEOF(x)

  #define VP_PICLR_DEFAULT (Uint32)(\
    _PER_FDEFAULT(VP,PICLR,PICLR22)\
   |_PER_FDEFAULT(VP,PICLR,PICLR21)\
   |_PER_FDEFAULT(VP,PICLR,PICLR20)\
   |_PER_FDEFAULT(VP,PICLR,PICLR19)\
   |_PER_FDEFAULT(VP,PICLR,PICLR18)\
   |_PER_FDEFAULT(VP,PICLR,PICLR17)\
   |_PER_FDEFAULT(VP,PICLR,PICLR16)\
   |_PER_FDEFAULT(VP,PICLR,PICLR15)\
   |_PER_FDEFAULT(VP,PICLR,PICLR14)\
   |_PER_FDEFAULT(VP,PICLR,PICLR13)\
   |_PER_FDEFAULT(VP,PICLR,PICLR12)\
   |_PER_FDEFAULT(VP,PICLR,PICLR11)\
   |_PER_FDEFAULT(VP,PICLR,PICLR10)\
   |_PER_FDEFAULT(VP,PICLR,PICLR9)\
   |_PER_FDEFAULT(VP,PICLR,PICLR8)\
   |_PER_FDEFAULT(VP,PICLR,PICLR7)\
   |_PER_FDEFAULT(VP,PICLR,PICLR6)\
   |_PER_FDEFAULT(VP,PICLR,PICLR5)\
   |_PER_FDEFAULT(VP,PICLR,PICLR4)\
   |_PER_FDEFAULT(VP,PICLR,PICLR3)\
   |_PER_FDEFAULT(VP,PICLR,PICLR2)\
   |_PER_FDEFAULT(VP,PICLR,PICLR1)\
   |_PER_FDEFAULT(VP,PICLR,PICLR0)\
  )

#define VP_PICLR_RMK(piclr22,piclr21,piclr20,piclr19,piclr18,piclr17,piclr16,\
  piclr15,piclr14,piclr13,piclr12,piclr11,piclr10,piclr9,piclr8,piclr7,\
  piclr6,piclr5,piclr4,piclr3,piclr2,piclr1,piclr0) (Uint32)(\
    _PER_FMK(VP,PICLR,PICLR22,piclr22)\
   |_PER_FMK(VP,PICLR,PICLR21,piclr21)\
   |_PER_FMK(VP,PICLR,PICLR20,piclr20)\
   |_PER_FMK(VP,PICLR,PICLR19,piclr19)\
   |_PER_FMK(VP,PICLR,PICLR18,piclr18)\
   |_PER_FMK(VP,PICLR,PICLR17,piclr17)\
   |_PER_FMK(VP,PICLR,PICLR16,piclr16)\
   |_PER_FMK(VP,PICLR,PICLR15,piclr15)\
   |_PER_FMK(VP,PICLR,PICLR14,piclr14)\
   |_PER_FMK(VP,PICLR,PICLR13,piclr13)\
   |_PER_FMK(VP,PICLR,PICLR12,piclr12)\
   |_PER_FMK(VP,PICLR,PICLR11,piclr11)\
   |_PER_FMK(VP,PICLR,PICLR10,piclr10)\
   |_PER_FMK(VP,PICLR,PICLR9,piclr9)\
   |_PER_FMK(VP,PICLR,PICLR8,piclr8)\
   |_PER_FMK(VP,PICLR,PICLR7,piclr7)\
   |_PER_FMK(VP,PICLR,PICLR6,piclr6)\
   |_PER_FMK(VP,PICLR,PICLR5,piclr5)\
   |_PER_FMK(VP,PICLR,PICLR4,piclr4)\
   |_PER_FMK(VP,PICLR,PICLR3,piclr3)\
   |_PER_FMK(VP,PICLR,PICLR2,piclr2)\
   |_PER_FMK(VP,PICLR,PICLR1,piclr1)\
   |_PER_FMK(VP,PICLR,PICLR0,piclr0)\
  )

  #define _VP_PICLR_FGET(N,FIELD)\
    _PER_FGET(_VP_PICLR##N##_ADDR,VP,PICLR,##FIELD)

  #define _VP_PICLR_FSET(N,FIELD,field)\
    _PER_FSET(_VP_PICLR##N##_ADDR,VP,PICLR,##FIELD,field)

  #define _VP_PICLR_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_PICLR##N##_ADDR,VP,PICLR,##FIELD,##SYM)

  #define _VP_PICLR0_FGET(FIELD)   _VP_PICLR_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PICLR1_FGET(FIELD)   _VP_PICLR_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_PICLR2_FGET(FIELD)   _VP_PICLR_FGET(2,##FIELD)
 #endif


  #define _VP_PICLR0_FSET(FIELD,f)   _VP_PICLR_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PICLR1_FSET(FIELD,f)   _VP_PICLR_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_PICLR2_FSET(FIELD,f)   _VP_PICLR_FSET(2,##FIELD,f)
 #endif


  #define _VP_PICLR0_FSETS(FIELD,SYM)   _VP_PICLR_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_PICLR1_FSETS(FIELD,SYM)   _VP_PICLR_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_PICLR2_FSETS(FIELD,SYM)   _VP_PICLR_FSETS(2,##FIELD,##SYM)
 #endif

  
/******************************************************************************\
* _____________________
* |                   |
* |  V P C T L        |
* |___________________|
*
* VPCTL0  -  Video Port 0 Control Register
* VPCTL1  -  Video Port 1 Control Register
* VPCTL2  -  Video Port 2 Control Register
*
* FIELDS (msb -> lsb)
* (rs) VPRST
* (rc) VPHLT
* (rw) VCLK2P
* (rw) VCT2P
* (rw) VCT1P
* (rw) VCT0P
* (rw) TSI
* (rw) DISP
* (rw) DCHNL   ???
*
\******************************************************************************/
  #define _VP_VPCTL_OFFSET           48

  #define _VP_VPCTL0_ADDR   (_VP_BASE_PORT0 + 4*_VP_VPCTL_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VPCTL1_ADDR   (_VP_BASE_PORT1 + 4*_VP_VPCTL_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VPCTL2_ADDR   (_VP_BASE_PORT2 + 4*_VP_VPCTL_OFFSET)
 #endif


  #define _VP_VPCTL_VPRST_MASK        0x00008000u
  #define _VP_VPCTL_VPRST_SHIFT       0x0000000Fu
  #define  VP_VPCTL_VPRST_DEFAULT     0x00000000u
  #define  VP_VPCTL_VPRST_OF(x)       _VALUEOF(x)
  #define  VP_VPCTL_VPRST_NO          0x00000000u
  #define  VP_VPCTL_VPRST_RESET       0x00000001u

  #define _VP_VPCTL_VPHLT_MASK        0x00004000u
  #define _VP_VPCTL_VPHLT_SHIFT       0x0000000Eu
  #define  VP_VPCTL_VPHLT_DEFAULT     0x00000001u
  #define  VP_VPCTL_VPHLT_OF(x)       _VALUEOF(x)
  #define  VP_VPCTL_VPHLT_NONE        0x00000000u
  #define  VP_VPCTL_VPHLT_CLEAR       0x00000001u

  #define _VP_VPCTL_VCLK2P_MASK       0x00000080u
  #define _VP_VPCTL_VCLK2P_SHIFT      0x00000007u
  #define  VP_VPCTL_VCLK2P_DEFAULT    0x00000000u
  #define  VP_VPCTL_VCLK2P_OF(x)      _VALUEOF(x)
  #define  VP_VPCTL_VCLK2P_NONE       0x00000000u
  #define  VP_VPCTL_VCLK2P_REVERSE    0x00000001u

  #define _VP_VPCTL_VCT2P_MASK       0x00000040u
  #define _VP_VPCTL_VCT2P_SHIFT      0x00000006u
  #define  VP_VPCTL_VCT2P_DEFAULT    0x00000000u
  #define  VP_VPCTL_VCT2P_OF(x)      _VALUEOF(x)
  #define  VP_VPCTL_VCT2P_NONE       0x00000000u
  #define  VP_VPCTL_VCT2P_ACTIVELOW  0x00000001u

  #define _VP_VPCTL_VCT1P_MASK       0x00000020u
  #define _VP_VPCTL_VCT1P_SHIFT      0x00000005u
  #define  VP_VPCTL_VCT1P_DEFAULT    0x00000000u
  #define  VP_VPCTL_VCT1P_OF(x)      _VALUEOF(x)
  #define  VP_VPCTL_VCT1P_NONE       0x00000000u
  #define  VP_VPCTL_VCT1P_ACTIVELOW  0x00000001u

  #define _VP_VPCTL_VCT0P_MASK       0x00000010u
  #define _VP_VPCTL_VCT0P_SHIFT      0x00000004u
  #define  VP_VPCTL_VCT0P_DEFAULT    0x00000000u
  #define  VP_VPCTL_VCT0P_OF(x)      _VALUEOF(x)
  #define  VP_VPCTL_VCT0P_NONE       0x00000000u
  #define  VP_VPCTL_VCT0P_ACTIVELOW  0x00000001u

  #define _VP_VPCTL_TSI_MASK         0x00000004u
  #define _VP_VPCTL_TSI_SHIFT        0x00000002u
  #define  VP_VPCTL_TSI_DEFAULT      0x00000000u
  #define  VP_VPCTL_TSI_OF(x)        _VALUEOF(x)
  #define  VP_VPCTL_TSI_NONE         0x00000000u
  #define  VP_VPCTL_TSI_CAPTURE      0x00000001u

  #define _VP_VPCTL_DISP_MASK      0x00000002u
  #define _VP_VPCTL_DISP_SHIFT     0x00000001u
  #define  VP_VPCTL_DISP_DEFAULT   0x00000000u
  #define  VP_VPCTL_DISP_OF(x)     _VALUEOF(x)
  #define  VP_VPCTL_DISP_CAPTURE   0x00000000u
  #define  VP_VPCTL_DISP_DISPLAY   0x00000001u

/* Changed 2CHNL to DCHNL ??? */
  #define _VP_VPCTL_DCHNL_MASK      0x00000001u
  #define _VP_VPCTL_DCHNL_SHIFT     0x00000000u
  #define  VP_VPCTL_DCHNL_DEFAULT   0x00000000u
  #define  VP_VPCTL_DCHNL_OF(x)     _VALUEOF(x)
  #define  VP_VPCTL_DCHNL_SINGLE    0x00000000u
  #define  VP_VPCTL_DCHNL_DUAL      0x00000001u

  #define  VP_VPCTL_OF(x)            _VALUEOF(x)

  #define VP_VPCTL_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VPCTL,VPRST)\
    |_PER_FDEFAULT(VP,VPCTL,VPHLT)\
    |_PER_FDEFAULT(VP,VPCTL,VCLK2P)\
    |_PER_FDEFAULT(VP,VPCTL,VCT2P)\
    |_PER_FDEFAULT(VP,VPCTL,VCT1P)\
    |_PER_FDEFAULT(VP,VPCTL,VCT0P)\
    |_PER_FDEFAULT(VP,VPCTL,TSI)\
    |_PER_FDEFAULT(VP,VPCTL,DISP)\
    |_PER_FDEFAULT(VP,VPCTL,DCHNL)\
  )

  #define VP_VPCTL_RMK(vprst,vphlt,vclk2p,vct2p,vct1p,vct0p,\
    tsi,disp,dchnl) (Uint32)(\
     _PER_FMK(VP,VPCTL,VPRST,vprst)\
    |_PER_FMK(VP,VPCTL,VPHLT,vphlt)\
    |_PER_FMK(VP,VPCTL,VCLK2P,vclk2p)\
    |_PER_FMK(VP,VPCTL,VCT2P,vct2p)\
    |_PER_FMK(VP,VPCTL,VCT1P,vct1p)\
    |_PER_FMK(VP,VPCTL,VCT0P,vct0p)\
    |_PER_FMK(VP,VPCTL,TSI,tsi)\
    |_PER_FMK(VP,VPCTL,DISP,disp)\
    |_PER_FMK(VP,VPCTL,DCHNL,dchnl)\
  )

  #define _VP_VPCTL_FGET(N,FIELD)\
    _PER_FGET(_VP_VPCTL##N##_ADDR,VP,VPCTL,##FIELD)

  #define _VP_VPCTL_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VPCTL##N##_ADDR,VP,VPCTL,##FIELD,field)

  #define _VP_VPCTL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VPCTL##N##_ADDR,VP,VPCTL,##FIELD,##SYM)

  #define _VP_VPCTL0_FGET(FIELD)   _VP_VPCTL_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VPCTL1_FGET(FIELD)   _VP_VPCTL_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VPCTL2_FGET(FIELD)   _VP_VPCTL_FGET(2,##FIELD)
 #endif


  #define _VP_VPCTL0_FSET(FIELD,f)   _VP_VPCTL_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VPCTL1_FSET(FIELD,f)   _VP_VPCTL_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VPCTL2_FSET(FIELD,f)   _VP_VPCTL_FSET(2,##FIELD,f)
 #endif


  #define _VP_VPCTL0_FSETS(FIELD,SYM)   _VP_VPCTL_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VPCTL1_FSETS(FIELD,SYM)   _VP_VPCTL_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VPCTL2_FSETS(FIELD,SYM)   _VP_VPCTL_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V P S T A T      |
* |___________________|
*
* VPSTAT0  -  Video Port 0 Status Register
* VPSTAT1  -  Video Port 1 Status Register
* VPSTAT2  -  Video Port 2 Status Register
*
* FIELDS (msb -> lsb)
* (r) DCDIS
* (r) HIDATA
* (r) PWDTH
*
\******************************************************************************/
  #define _VP_VPSTAT_OFFSET           49

  #define _VP_VPSTAT0_ADDR   (_VP_BASE_PORT0 + 4*_VP_VPSTAT_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VPSTAT1_ADDR   (_VP_BASE_PORT1 + 4*_VP_VPSTAT_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VPSTAT2_ADDR   (_VP_BASE_PORT2 + 4*_VP_VPSTAT_OFFSET)
 #endif


/* Change 2CDIS to DCDIS ??? */
  #define _VP_VPSTAT_DCDIS_MASK        0x00000008u
  #define _VP_VPSTAT_DCDIS_SHIFT       0x00000003u
  #define  VP_VPSTAT_DCDIS_DEFAULT     0x00000000u
  #define  VP_VPSTAT_DCDIS_OF(x)       _VALUEOF(x)
  #define  VP_VPSTAT_DCDIS_ENABLE      0x00000000u
  #define  VP_VPSTAT_DCDIS_DISABLE     0x00000001u

  #define _VP_VPSTAT_HIDATA_MASK       0x00000004u
  #define _VP_VPSTAT_HIDATA_SHIFT      0x00000002u
  #define  VP_VPSTAT_HIDATA_DEFAULT    0x00000000u
  #define  VP_VPSTAT_HIDATA_OF(x)      _VALUEOF(x)
  #define  VP_VPSTAT_HIDATA_NONE       0x00000000u
  #define  VP_VPSTAT_HIDATA_USE        0x00000001u

  #define _VP_VPSTAT_PWDTH_MASK        0x00000003u
  #define _VP_VPSTAT_PWDTH_SHIFT       0x00000000u
  #define  VP_VPSTAT_PWDTH_DEFAULT     0x00000000u
  #define  VP_VPSTAT_PWDTH_OF(x)       _VALUEOF(x)
  #define  VP_VPSTAT_PWDTH_20BITS      0x00000000u
  #define  VP_VPSTAT_PWDTH_10BITS      0x00000002u
  #define  VP_VPSTAT_PWDTH_8BITS       0x00000003u

  #define  VP_VPSTAT_OF(x)            _VALUEOF(x)

  #define VP_VPSTAT_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VPSTAT,DCDIS)\
    |_PER_FDEFAULT(VP,VPSTAT,HIDATA)\
    |_PER_FDEFAULT(VP,VPSTAT,PWDTH)\
  )
#if (!(CHIP_6413 | CHIP_6418 | CHIP_6410))
  #define VP_VPSTAT_RMK(dcdis,hidata,pwdth) (Uint32)(\
	       _PER_FMK(VP,VPSTAT,DCDIS,dcdis)\
	      |_PER_FMK(VP,VPSTAT,HIDATA,hidata)\
	      |_PER_FMK(VP,VPSTAT,PWDTH,pwdth)\
  )	      
#endif  
  #define _VP_VPSTAT_FGET(N,FIELD)\
    _PER_FGET(_VP_VPSTAT##N##_ADDR,VP,VPSTAT,##FIELD)

  #define _VP_VPSTAT_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VPSTAT##N##_ADDR,VP,VPSTAT,##FIELD,field)

  #define _VP_VPSTAT_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VPSTAT##N##_ADDR,VP,VPSTAT,##FIELD,##SYM)

  #define _VP_VPSTAT0_FGET(FIELD)   _VP_VPSTAT_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VPSTAT1_FGET(FIELD)   _VP_VPSTAT_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VPSTAT2_FGET(FIELD)   _VP_VPSTAT_FGET(2,##FIELD)
 #endif


  #define _VP_VPSTAT0_FSET(FIELD,f)   _VP_VPSTAT_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VPSTAT1_FSET(FIELD,f)   _VP_VPSTAT_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VPSTAT2_FSET(FIELD,f)   _VP_VPSTAT_FSET(2,##FIELD,f)
 #endif


  #define _VP_VPSTAT0_FSETS(FIELD,SYM)   _VP_VPSTAT_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VPSTAT1_FSETS(FIELD,SYM)   _VP_VPSTAT_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VPSTAT2_FSETS(FIELD,SYM)   _VP_VPSTAT_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V P I E          |
* |___________________|
*
* VPIE0 - Video Port 0 Interrupt Enable Register
* VPIE1 - Video Port 1 Interrupt Enable Register
* VPIE2 - Video Port 2 Interrupt Enable Register
*
* FIELDS (msb -> lsb)
*
* (rw) LFDB
* (rw) SFDB
* (rw) VINTB2
* (rw) VINTB1
* (rw) SERRB
* (rw) CCMPB
* (rw) COVRB
* (rw) GPIO
* (rw) DCNA
* (rw) DCMP
* (rw) DUND
* (rw) TICK
* (rw) STC
* (rw) LFDA
* (rw) SFDA
* (rw) VINTA2
* (rw) VINTA1
* (rw) SERRA
* (rw) CCMPA
* (rw) COVRA
* (rw) VIE
*
\******************************************************************************/
  #define _VP_VPIE_OFFSET           50

  #define _VP_VPIE0_ADDR   (_VP_BASE_PORT0 + 4*_VP_VPIE_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VPIE1_ADDR   (_VP_BASE_PORT1 + 4*_VP_VPIE_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VPIE2_ADDR   (_VP_BASE_PORT2 + 4*_VP_VPIE_OFFSET)
 #endif


  #define _VP_VPIE_LFDB_MASK         0x00800000u
  #define _VP_VPIE_LFDB_SHIFT        0x00000017u
  #define  VP_VPIE_LFDB_DEFAULT      0x00000000u
  #define  VP_VPIE_LFDB_OF(x)        _VALUEOF(x)
  #define  VP_VPIE_LFDB_DISABLE      0x00000000u
  #define  VP_VPIE_LFDB_ENABLE       0x00000001u

  #define _VP_VPIE_SFDB_MASK         0x00400000u
  #define _VP_VPIE_SFDB_SHIFT        0x00000016u
  #define  VP_VPIE_SFDB_DEFAULT      0x00000000u
  #define  VP_VPIE_SFDB_OF(x)        _VALUEOF(x)
  #define  VP_VPIE_SFDB_DISABLE      0x00000000u
  #define  VP_VPIE_SFDB_ENABLE       0x00000001u

  #define _VP_VPIE_VINTB2_MASK         0x00200000u
  #define _VP_VPIE_VINTB2_SHIFT        0x00000015u
  #define  VP_VPIE_VINTB2_DEFAULT      0x00000000u
  #define  VP_VPIE_VINTB2_OF(x)        _VALUEOF(x)
  #define  VP_VPIE_VINTB2_DISABLE      0x00000000u
  #define  VP_VPIE_VINTB2_ENABLE       0x00000001u

  #define _VP_VPIE_VINTB1_MASK         0x00100000u
  #define _VP_VPIE_VINTB1_SHIFT        0x00000014u
  #define  VP_VPIE_VINTB1_DEFAULT      0x00000000u
  #define  VP_VPIE_VINTB1_OF(x)        _VALUEOF(x)
  #define  VP_VPIE_VINTB1_DISABLE      0x00000000u
  #define  VP_VPIE_VINTB1_ENABLE       0x00000001u

  #define _VP_VPIE_SERRB_MASK         0x00080000u
  #define _VP_VPIE_SERRB_SHIFT        0x00000013u
  #define  VP_VPIE_SERRB_DEFAULT      0x00000000u
  #define  VP_VPIE_SERRB_OF(x)        _VALUEOF(x)
  #define  VP_VPIE_SERRB_DISABLE      0x00000000u
  #define  VP_VPIE_SERRB_ENABLE       0x00000001u

  #define _VP_VPIE_CCMPB_MASK         0x00040000u
  #define _VP_VPIE_CCMPB_SHIFT        0x00000012u
  #define  VP_VPIE_CCMPB_DEFAULT      0x00000000u
  #define  VP_VPIE_CCMPB_OF(x)        _VALUEOF(x)
  #define  VP_VPIE_CCMPB_DISABLE      0x00000000u
  #define  VP_VPIE_CCMPB_ENABLE       0x00000001u

  #define _VP_VPIE_COVRB_MASK         0x00020000u
  #define _VP_VPIE_COVRB_SHIFT        0x00000011u
  #define  VP_VPIE_COVRB_DEFAULT      0x00000000u
  #define  VP_VPIE_COVRB_OF(x)        _VALUEOF(x)
  #define  VP_VPIE_COVRB_DISABLE      0x00000000u
  #define  VP_VPIE_COVRB_ENABLE       0x00000001u

  #define _VP_VPIE_GPIO_MASK         0x00010000u
  #define _VP_VPIE_GPIO_SHIFT        0x00000010u
  #define  VP_VPIE_GPIO_DEFAULT      0x00000000u
  #define  VP_VPIE_GPIO_OF(x)        _VALUEOF(x)
  #define  VP_VPIE_GPIO_DISABLE      0x00000000u
  #define  VP_VPIE_GPIO_ENABLE       0x00000001u

  #define _VP_VPIE_DCNA_MASK         0x00004000u
  #define _VP_VPIE_DCNA_SHIFT        0x0000000Eu
  #define  VP_VPIE_DCNA_DEFAULT      0x00000000u
  #define  VP_VPIE_DCNA_OF(x)        _VALUEOF(x)
  #define  VP_VPIE_DCNA_DISABLE      0x00000000u
  #define  VP_VPIE_DCNA_ENABLE       0x00000001u

  #define _VP_VPIE_DCMP_MASK         0x00002000u
  #define _VP_VPIE_DCMP_SHIFT        0x0000000Du
  #define  VP_VPIE_DCMP_DEFAULT      0x00000000u
  #define  VP_VPIE_DCMP_OF(x)        _VALUEOF(x)
  #define  VP_VPIE_DCMP_DISABLE      0x00000000u
  #define  VP_VPIE_DCMP_ENABLE       0x00000001u

  #define _VP_VPIE_DUND_MASK         0x00001000u
  #define _VP_VPIE_DUND_SHIFT        0x0000000Cu
  #define  VP_VPIE_DUND_DEFAULT      0x00000000u
  #define  VP_VPIE_DUND_OF(x)        _VALUEOF(x)
  #define  VP_VPIE_DUND_DISABLE      0x00000000u
  #define  VP_VPIE_DUND_ENABLE       0x00000001u

  #define _VP_VPIE_TICK_MASK         0x00000800u
  #define _VP_VPIE_TICK_SHIFT        0x0000000Bu
  #define  VP_VPIE_TICK_DEFAULT      0x00000000u
  #define  VP_VPIE_TICK_OF(x)        _VALUEOF(x)
  #define  VP_VPIE_TICK_DISABLE      0x00000000u
  #define  VP_VPIE_TICK_ENABLE       0x00000001u

  #define _VP_VPIE_STC_MASK         0x00000400u
  #define _VP_VPIE_STC_SHIFT        0x0000000Au
  #define  VP_VPIE_STC_DEFAULT      0x00000000u
  #define  VP_VPIE_STC_OF(x)        _VALUEOF(x)
  #define  VP_VPIE_STC_DISABLE      0x00000000u
  #define  VP_VPIE_STC_ENABLE       0x00000001u

  #define _VP_VPIE_LFDA_MASK         0x00000080u
  #define _VP_VPIE_LFDA_SHIFT        0x00000007u
  #define  VP_VPIE_LFDA_DEFAULT      0x00000000u
  #define  VP_VPIE_LFDA_OF(x)        _VALUEOF(x)
  #define  VP_VPIE_LFDA_DISABLE      0x00000000u
  #define  VP_VPIE_LFDA_ENABLE       0x00000001u

  #define _VP_VPIE_SFDA_MASK         0x00000040u
  #define _VP_VPIE_SFDA_SHIFT        0x00000006u
  #define  VP_VPIE_SFDA_DEFAULT      0x00000000u
  #define  VP_VPIE_SFDA_OF(x)        _VALUEOF(x)
  #define  VP_VPIE_SFDA_DISABLE      0x00000000u
  #define  VP_VPIE_SFDA_ENABLE       0x00000001u

  #define _VP_VPIE_VINTA2_MASK         0x00000020u
  #define _VP_VPIE_VINTA2_SHIFT        0x00000005u
  #define  VP_VPIE_VINTA2_DEFAULT      0x00000000u
  #define  VP_VPIE_VINTA2_OF(x)        _VALUEOF(x)
  #define  VP_VPIE_VINTA2_DISABLE      0x00000000u
  #define  VP_VPIE_VINTA2_ENABLE       0x00000001u

  #define _VP_VPIE_VINTA1_MASK         0x00000010u
  #define _VP_VPIE_VINTA1_SHIFT        0x00000004u
  #define  VP_VPIE_VINTA1_DEFAULT      0x00000000u
  #define  VP_VPIE_VINTA1_OF(x)        _VALUEOF(x)
  #define  VP_VPIE_VINTA1_DISABLE      0x00000000u
  #define  VP_VPIE_VINTA1_ENABLE       0x00000001u

  #define _VP_VPIE_SERRA_MASK         0x00000008u
  #define _VP_VPIE_SERRA_SHIFT        0x00000003u
  #define  VP_VPIE_SERRA_DEFAULT      0x00000000u
  #define  VP_VPIE_SERRA_OF(x)        _VALUEOF(x)
  #define  VP_VPIE_SERRA_DISABLE      0x00000000u
  #define  VP_VPIE_SERRA_ENABLE       0x00000001u

  #define _VP_VPIE_CCMPA_MASK         0x00000004u
  #define _VP_VPIE_CCMPA_SHIFT        0x00000002u
  #define  VP_VPIE_CCMPA_DEFAULT      0x00000000u
  #define  VP_VPIE_CCMPA_OF(x)        _VALUEOF(x)
  #define  VP_VPIE_CCMPA_DISABLE      0x00000000u
  #define  VP_VPIE_CCMPA_ENABLE       0x00000001u

  #define _VP_VPIE_COVRA_MASK         0x00000002u
  #define _VP_VPIE_COVRA_SHIFT        0x00000001u
  #define  VP_VPIE_COVRA_DEFAULT      0x00000000u
  #define  VP_VPIE_COVRA_OF(x)        _VALUEOF(x)
  #define  VP_VPIE_COVRA_DISABLE      0x00000000u
  #define  VP_VPIE_COVRA_ENABLE       0x00000001u

  #define _VP_VPIE_VIE_MASK         0x00000001u
  #define _VP_VPIE_VIE_SHIFT        0x00000000u
  #define  VP_VPIE_VIE_DEFAULT      0x00000000u
  #define  VP_VPIE_VIE_OF(x)        _VALUEOF(x)
  #define  VP_VPIE_VIE_DISABLE      0x00000000u
  #define  VP_VPIE_VIE_ENABLE       0x00000001u

  #define  VP_VPIE_OF(x)            _VALUEOF(x)

  #define VP_VPIE_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VPIE,LFDB)\
    |_PER_FDEFAULT(VP,VPIE,SFDB)\
    |_PER_FDEFAULT(VP,VPIE,VINTB2)\
    |_PER_FDEFAULT(VP,VPIE,VINTB1)\
    |_PER_FDEFAULT(VP,VPIE,SERRB)\
    |_PER_FDEFAULT(VP,VPIE,CCMPB)\
    |_PER_FDEFAULT(VP,VPIE,COVRB)\
    |_PER_FDEFAULT(VP,VPIE,GPIO)\
    |_PER_FDEFAULT(VP,VPIE,DCNA)\
    |_PER_FDEFAULT(VP,VPIE,DCMP)\
    |_PER_FDEFAULT(VP,VPIE,DUND)\
    |_PER_FDEFAULT(VP,VPIE,TICK)\
    |_PER_FDEFAULT(VP,VPIE,STC)\
    |_PER_FDEFAULT(VP,VPIE,LFDA)\
    |_PER_FDEFAULT(VP,VPIE,SFDA)\
    |_PER_FDEFAULT(VP,VPIE,VINTA2)\
    |_PER_FDEFAULT(VP,VPIE,VINTA1)\
    |_PER_FDEFAULT(VP,VPIE,SERRA)\
    |_PER_FDEFAULT(VP,VPIE,CCMPA)\
    |_PER_FDEFAULT(VP,VPIE,COVRA)\
    |_PER_FDEFAULT(VP,VPIE,VIE)\
  )

  #define VP_VPIE_RMK(lfdb,sfdb,vintb2,vintb1,serrb,ccmpb,covrb,gpio,\
    dcna,dcmp,dund,tick,stc,lfda,sfda,vinta2,vinta1,serra,ccmpa,covra,\
	vie) (Uint32)(\
     _PER_FMK(VP,VPIE,LFDB,lfdb)\
    |_PER_FMK(VP,VPIE,SFDB,sfdb)\
    |_PER_FMK(VP,VPIE,VINTB2,vintb2)\
    |_PER_FMK(VP,VPIE,VINTB1,vintb1)\
    |_PER_FMK(VP,VPIE,SERRB,serrb)\
    |_PER_FMK(VP,VPIE,CCMPB,ccmpb)\
    |_PER_FMK(VP,VPIE,COVRB,covrb)\
    |_PER_FMK(VP,VPIE,GPIO,gpio)\
    |_PER_FMK(VP,VPIE,DCNA,dcna)\
    |_PER_FMK(VP,VPIE,DCMP,dcmp)\
    |_PER_FMK(VP,VPIE,DUND,dund)\
    |_PER_FMK(VP,VPIE,TICK,tick)\
    |_PER_FMK(VP,VPIE,STC,stc)\
    |_PER_FMK(VP,VPIE,LFDA,lfda)\
    |_PER_FMK(VP,VPIE,SFDA,sfda)\
    |_PER_FMK(VP,VPIE,VINTA2,vinta2)\
    |_PER_FMK(VP,VPIE,VINTA1,vinta1)\
    |_PER_FMK(VP,VPIE,SERRA,serra)\
    |_PER_FMK(VP,VPIE,CCMPA,ccmpa)\
    |_PER_FMK(VP,VPIE,COVRA,covra)\
    |_PER_FMK(VP,VPIE,VIE,vie)\
  )

  #define _VP_VPIE_FGET(N,FIELD)\
    _PER_FGET(_VP_VPIE##N##_ADDR,VP,VPIE,##FIELD)

  #define _VP_VPIE_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VPIE##N##_ADDR,VP,VPIE,##FIELD,field)

  #define _VP_VPIE_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VPIE##N##_ADDR,VP,VPIE,##FIELD,##SYM)

  #define _VP_VPIE0_FGET(FIELD)   _VP_VPIE_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VPIE1_FGET(FIELD)   _VP_VPIE_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VPIE2_FGET(FIELD)   _VP_VPIE_FGET(2,##FIELD)
 #endif


  #define _VP_VPIE0_FSET(FIELD,f)   _VP_VPIE_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VPIE1_FSET(FIELD,f)   _VP_VPIE_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VPIE2_FSET(FIELD,f)   _VP_VPIE_FSET(2,##FIELD,f)
 #endif


  #define _VP_VPIE0_FSETS(FIELD,SYM)   _VP_VPIE_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VPIE1_FSETS(FIELD,SYM)   _VP_VPIE_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VPIE2_FSETS(FIELD,SYM)   _VP_VPIE_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V P I S          |
* |___________________|
*
* VPIS0 - Video Port 0 Interrupt Status Register
* VPIS1 - Video Port 1 Interrupt Status Register
* VPIS2 - Video Port 2 Interrupt Status Register
*
* FIELDS (msb -> lsb)
*
* (rc) LFDB
* (rc) SFDB
* (rc) VINTB2
* (rc) VINTB1
* (rc) SERRB
* (rc) CCMPB
* (rc) COVRB
* (rc) GPIO
* (rc) DCNA
* (rc) DCMP
* (rc) DUND
* (rc) TICK
* (rc) STC
* (rc) LFDA
* (rc) SFDA
* (rc) VINTA2
* (rc) VINTA1
* (rc) SERRA
* (rc) CCMPA
* (rc) COVRA
*
\******************************************************************************/
  #define _VP_VPIS_OFFSET           51

  #define _VP_VPIS0_ADDR   (_VP_BASE_PORT0 + 4*_VP_VPIS_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VPIS1_ADDR   (_VP_BASE_PORT1 + 4*_VP_VPIS_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VPIS2_ADDR   (_VP_BASE_PORT2 + 4*_VP_VPIS_OFFSET)
 #endif


  #define _VP_VPIS_LFDB_MASK         0x00800000u
  #define _VP_VPIS_LFDB_SHIFT        0x00000017u
  #define  VP_VPIS_LFDB_DEFAULT      0x00000000u
  #define  VP_VPIS_LFDB_OF(x)        _VALUEOF(x)
  #define  VP_VPIS_LFDB_NONE         0x00000000u
  #define  VP_VPIS_LFDB_CLEAR        0x00000001u

  #define _VP_VPIS_SFDB_MASK         0x00400000u
  #define _VP_VPIS_SFDB_SHIFT        0x00000016u
  #define  VP_VPIS_SFDB_DEFAULT      0x00000000u
  #define  VP_VPIS_SFDB_OF(x)        _VALUEOF(x)
  #define  VP_VPIS_SFDB_NONE         0x00000000u
  #define  VP_VPIS_SFDB_CLEAR        0x00000001u

  #define _VP_VPIS_VINTB2_MASK         0x00200000u
  #define _VP_VPIS_VINTB2_SHIFT        0x00000015u
  #define  VP_VPIS_VINTB2_DEFAULT      0x00000000u
  #define  VP_VPIS_VINTB2_OF(x)        _VALUEOF(x)
  #define  VP_VPIS_VINTB2_NONE         0x00000000u
  #define  VP_VPIS_VINTB2_CLEAR        0x00000001u

  #define _VP_VPIS_VINTB1_MASK         0x00100000u
  #define _VP_VPIS_VINTB1_SHIFT        0x00000014u
  #define  VP_VPIS_VINTB1_DEFAULT      0x00000000u
  #define  VP_VPIS_VINTB1_OF(x)        _VALUEOF(x)
  #define  VP_VPIS_VINTB1_NONE         0x00000000u
  #define  VP_VPIS_VINTB1_CLEAR        0x00000001u

  #define _VP_VPIS_SERRB_MASK         0x00080000u
  #define _VP_VPIS_SERRB_SHIFT        0x00000013u
  #define  VP_VPIS_SERRB_DEFAULT      0x00000000u
  #define  VP_VPIS_SERRB_OF(x)        _VALUEOF(x)
  #define  VP_VPIS_SERRB_NONE         0x00000000u
  #define  VP_VPIS_SERRB_CLEAR        0x00000001u

  #define _VP_VPIS_CCMPB_MASK         0x00040000u
  #define _VP_VPIS_CCMPB_SHIFT        0x00000012u
  #define  VP_VPIS_CCMPB_DEFAULT      0x00000000u
  #define  VP_VPIS_CCMPB_OF(x)        _VALUEOF(x)
  #define  VP_VPIS_CCMPB_NONE         0x00000000u
  #define  VP_VPIS_CCMPB_CLEAR        0x00000001u

  #define _VP_VPIS_COVRB_MASK         0x00020000u
  #define _VP_VPIS_COVRB_SHIFT        0x00000011u
  #define  VP_VPIS_COVRB_DEFAULT      0x00000000u
  #define  VP_VPIS_COVRB_OF(x)        _VALUEOF(x)
  #define  VP_VPIS_COVRB_NONE         0x00000000u
  #define  VP_VPIS_COVRB_CLEAR        0x00000001u

  #define _VP_VPIS_GPIO_MASK         0x00010000u
  #define _VP_VPIS_GPIO_SHIFT        0x00000010u
  #define  VP_VPIS_GPIO_DEFAULT      0x00000000u
  #define  VP_VPIS_GPIO_OF(x)        _VALUEOF(x)
  #define  VP_VPIS_GPIO_NONE         0x00000000u
  #define  VP_VPIS_GPIO_CLEAR        0x00000001u

  #define _VP_VPIS_DCNA_MASK         0x00004000u
  #define _VP_VPIS_DCNA_SHIFT        0x0000000Eu
  #define  VP_VPIS_DCNA_DEFAULT      0x00000000u
  #define  VP_VPIS_DCNA_OF(x)        _VALUEOF(x)
  #define  VP_VPIS_DCNA_NONE         0x00000000u
  #define  VP_VPIS_DCNA_CLEAR        0x00000001u

  #define _VP_VPIS_DCMP_MASK         0x00002000u
  #define _VP_VPIS_DCMP_SHIFT        0x0000000Du
  #define  VP_VPIS_DCMP_DEFAULT      0x00000000u
  #define  VP_VPIS_DCMP_OF(x)        _VALUEOF(x)
  #define  VP_VPIS_DCMP_NONE         0x00000000u
  #define  VP_VPIS_DCMP_CLEAR        0x00000001u

  #define _VP_VPIS_DUND_MASK         0x00001000u
  #define _VP_VPIS_DUND_SHIFT        0x0000000Cu
  #define  VP_VPIS_DUND_DEFAULT      0x00000000u
  #define  VP_VPIS_DUND_OF(x)        _VALUEOF(x)
  #define  VP_VPIS_DUND_NONE         0x00000000u
  #define  VP_VPIS_DUND_CLEAR        0x00000001u

  #define _VP_VPIS_TICK_MASK         0x00000800u
  #define _VP_VPIS_TICK_SHIFT        0x0000000Bu
  #define  VP_VPIS_TICK_DEFAULT      0x00000000u
  #define  VP_VPIS_TICK_OF(x)        _VALUEOF(x)
  #define  VP_VPIS_TICK_NONE         0x00000000u
  #define  VP_VPIS_TICK_CLEAR        0x00000001u

  #define _VP_VPIS_STC_MASK         0x00000400u
  #define _VP_VPIS_STC_SHIFT        0x0000000Au
  #define  VP_VPIS_STC_DEFAULT      0x00000000u
  #define  VP_VPIS_STC_OF(x)        _VALUEOF(x)
  #define  VP_VPIS_STC_NONE         0x00000000u
  #define  VP_VPIS_STC_CLEAR        0x00000001u

  #define _VP_VPIS_LFDA_MASK         0x00000080u
  #define _VP_VPIS_LFDA_SHIFT        0x00000007u
  #define  VP_VPIS_LFDA_DEFAULT      0x00000000u
  #define  VP_VPIS_LFDA_OF(x)        _VALUEOF(x)
  #define  VP_VPIS_LFDA_NONE         0x00000000u
  #define  VP_VPIS_LFDA_CLEAR        0x00000001u

  #define _VP_VPIS_SFDA_MASK         0x00000040u
  #define _VP_VPIS_SFDA_SHIFT        0x00000006u
  #define  VP_VPIS_SFDA_DEFAULT      0x00000000u
  #define  VP_VPIS_SFDA_OF(x)        _VALUEOF(x)
  #define  VP_VPIS_SFDA_NONE         0x00000000u
  #define  VP_VPIS_SFDA_CLEAR        0x00000001u

  #define _VP_VPIS_VINTA2_MASK         0x00000020u
  #define _VP_VPIS_VINTA2_SHIFT        0x00000005u
  #define  VP_VPIS_VINTA2_DEFAULT      0x00000000u
  #define  VP_VPIS_VINTA2_OF(x)        _VALUEOF(x)
  #define  VP_VPIS_VINTA2_NONE         0x00000000u
  #define  VP_VPIS_VINTA2_CLEAR        0x00000001u

  #define _VP_VPIS_VINTA1_MASK         0x00000010u
  #define _VP_VPIS_VINTA1_SHIFT        0x00000004u
  #define  VP_VPIS_VINTA1_DEFAULT      0x00000000u
  #define  VP_VPIS_VINTA1_OF(x)        _VALUEOF(x)
  #define  VP_VPIS_VINTA1_NONE         0x00000000u
  #define  VP_VPIS_VINTA1_CLEAR        0x00000001u

  #define _VP_VPIS_SERRA_MASK         0x00000008u
  #define _VP_VPIS_SERRA_SHIFT        0x00000003u
  #define  VP_VPIS_SERRA_DEFAULT      0x00000000u
  #define  VP_VPIS_SERRA_OF(x)        _VALUEOF(x)
  #define  VP_VPIS_SERRA_NONE         0x00000000u
  #define  VP_VPIS_SERRA_CLEAR        0x00000001u

  #define _VP_VPIS_CCMPA_MASK         0x00000004u
  #define _VP_VPIS_CCMPA_SHIFT        0x00000002u
  #define  VP_VPIS_CCMPA_DEFAULT      0x00000000u
  #define  VP_VPIS_CCMPA_OF(x)        _VALUEOF(x)
  #define  VP_VPIS_CCMPA_NONE         0x00000000u
  #define  VP_VPIS_CCMPA_CLEAR        0x00000001u

  #define _VP_VPIS_COVRA_MASK         0x00000002u
  #define _VP_VPIS_COVRA_SHIFT        0x00000001u
  #define  VP_VPIS_COVRA_DEFAULT      0x00000000u
  #define  VP_VPIS_COVRA_OF(x)        _VALUEOF(x)
  #define  VP_VPIS_COVRA_NONE         0x00000000u
  #define  VP_VPIS_COVRA_CLEAR        0x00000001u

  #define  VP_VPIS_OF(x)            _VALUEOF(x)

  #define VP_VPIS_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VPIS,LFDB)\
    |_PER_FDEFAULT(VP,VPIS,SFDB)\
    |_PER_FDEFAULT(VP,VPIS,VINTB2)\
    |_PER_FDEFAULT(VP,VPIS,VINTB1)\
    |_PER_FDEFAULT(VP,VPIS,SERRB)\
    |_PER_FDEFAULT(VP,VPIS,CCMPB)\
    |_PER_FDEFAULT(VP,VPIS,COVRB)\
    |_PER_FDEFAULT(VP,VPIS,GPIO)\
    |_PER_FDEFAULT(VP,VPIS,DCNA)\
    |_PER_FDEFAULT(VP,VPIS,DCMP)\
    |_PER_FDEFAULT(VP,VPIS,DUND)\
    |_PER_FDEFAULT(VP,VPIS,TICK)\
    |_PER_FDEFAULT(VP,VPIS,STC)\
    |_PER_FDEFAULT(VP,VPIS,LFDA)\
    |_PER_FDEFAULT(VP,VPIS,SFDA)\
    |_PER_FDEFAULT(VP,VPIS,VINTA2)\
    |_PER_FDEFAULT(VP,VPIS,VINTA1)\
    |_PER_FDEFAULT(VP,VPIS,SERRA)\
    |_PER_FDEFAULT(VP,VPIS,CCMPA)\
    |_PER_FDEFAULT(VP,VPIS,COVRA)\
  )

  #define VP_VPIS_RMK(lfdb,sfdb,vintb2,vintb1,serrb,ccmpb,covrb,gpio,\
    dcna,dcmp,dund,tick,stc,lfda,sfda,vinta2,vinta1,serra,ccmpa,\
	covra) (Uint32)(\
     _PER_FMK(VP,VPIS,LFDB,lfdb)\
    |_PER_FMK(VP,VPIS,SFDB,sfdb)\
    |_PER_FMK(VP,VPIS,VINTB2,vintb2)\
    |_PER_FMK(VP,VPIS,VINTB1,vintb1)\
    |_PER_FMK(VP,VPIS,SERRB,serrb)\
    |_PER_FMK(VP,VPIS,CCMPB,ccmpb)\
    |_PER_FMK(VP,VPIS,COVRB,covrb)\
    |_PER_FMK(VP,VPIS,GPIO,gpio)\
    |_PER_FMK(VP,VPIS,DCNA,dcna)\
    |_PER_FMK(VP,VPIS,DCMP,dcmp)\
    |_PER_FMK(VP,VPIS,DUND,dund)\
    |_PER_FMK(VP,VPIS,TICK,tick)\
    |_PER_FMK(VP,VPIS,STC,stc)\
    |_PER_FMK(VP,VPIS,LFDA,lfda)\
    |_PER_FMK(VP,VPIS,SFDA,sfda)\
    |_PER_FMK(VP,VPIS,VINTA2,vinta2)\
    |_PER_FMK(VP,VPIS,VINTA1,vinta1)\
    |_PER_FMK(VP,VPIS,SERRA,serra)\
    |_PER_FMK(VP,VPIS,CCMPA,ccmpa)\
    |_PER_FMK(VP,VPIS,COVRA,covra)\
  )

  #define _VP_VPIS_FGET(N,FIELD)\
    _PER_FGET(_VP_VPIS##N##_ADDR,VP,VPIS,##FIELD)

  #define _VP_VPIS_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VPIS##N##_ADDR,VP,VPIS,##FIELD,field)

  #define _VP_VPIS_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VPIS##N##_ADDR,VP,VPIS,##FIELD,##SYM)

  #define _VP_VPIS0_FGET(FIELD)   _VP_VPIS_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VPIS1_FGET(FIELD)   _VP_VPIS_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VPIS2_FGET(FIELD)   _VP_VPIS_FGET(2,##FIELD)
 #endif


  #define _VP_VPIS0_FSET(FIELD,f)   _VP_VPIS_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VPIS1_FSET(FIELD,f)   _VP_VPIS_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VPIS2_FSET(FIELD,f)   _VP_VPIS_FSET(2,##FIELD,f)
 #endif


  #define _VP_VPIS0_FSETS(FIELD,SYM)   _VP_VPIS_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VPIS1_FSETS(FIELD,SYM)   _VP_VPIS_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VPIS2_FSETS(FIELD,SYM)   _VP_VPIS_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V C A S T A T    |
* |___________________|
*
* VCASTAT0 - Video Port 0 Video Capture A Status
* VCASTAT1 - Video Port 1 Video Capture A Status
* VCASTAT2 - Video Port 2 Video Capture A Status
*
* FIELDS (msb -> lsb)
*
* (r)  FSYNC
* (rc) FRMC
* (rc) F2C
* (rc) F1C
* (r)  VCYPOS
* (r)  VCFLD
* (r)  VCXPOS
*
\******************************************************************************/
  #define _VP_VCASTAT_OFFSET           64
  #define _VP_VCASTAT_OFFSETA           0

  #define _VP_VCASTAT0_ADDR   (_VP_BASE_PORT0 + 4*_VP_VCASTAT_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCASTAT1_ADDR   (_VP_BASE_PORT1 + 4*_VP_VCASTAT_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCASTAT2_ADDR   (_VP_BASE_PORT2 + 4*_VP_VCASTAT_OFFSET)
 #endif


  #define _VP_VCASTAT0_ADDRA   (_VP_BASE_CHAPORT0 + 4*_VP_VCASTAT_OFFSETA)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCASTAT1_ADDRA   (_VP_BASE_CHAPORT1 + 4*_VP_VCASTAT_OFFSETA)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCASTAT2_ADDRA   (_VP_BASE_CHAPORT2 + 4*_VP_VCASTAT_OFFSETA)
 #endif


  #define _VP_VCASTAT_FSYNC_MASK        0x80000000u
  #define _VP_VCASTAT_FSYNC_SHIFT       0x0000001Fu
  #define  VP_VCASTAT_FSYNC_DEFAULT     0x00000000u
  #define  VP_VCASTAT_FSYNC_OF(x)       _VALUEOF(x)
  #define  VP_VCASTAT_FSYNC_CLEARD      0x00000000u
  #define  VP_VCASTAT_FSYNC_SET         0x00000001u

  #define _VP_VCASTAT_FRMC_MASK        0x40000000u
  #define _VP_VCASTAT_FRMC_SHIFT       0x0000001Eu
  #define  VP_VCASTAT_FRMC_DEFAULT     0x00000000u
  #define  VP_VCASTAT_FRMC_OF(x)       _VALUEOF(x)
  #define  VP_VCASTAT_FRMC_NONE        0x00000000u
  #define  VP_VCASTAT_FRMC_CAPTURED    0x00000001u
  #define  VP_VCASTAT_FRMC_CLEAR       0x00000001u

  #define _VP_VCASTAT_F2C_MASK        0x20000000u
  #define _VP_VCASTAT_F2C_SHIFT       0x0000001Du
  #define  VP_VCASTAT_F2C_DEFAULT     0x00000000u
  #define  VP_VCASTAT_F2C_OF(x)       _VALUEOF(x)
  #define  VP_VCASTAT_F2C_NONE        0x00000000u
  #define  VP_VCASTAT_F2C_CAPTURED    0x00000001u
  #define  VP_VCASTAT_F2C_CLEAR       0x00000001u

  #define _VP_VCASTAT_F1C_MASK        0x10000000u
  #define _VP_VCASTAT_F1C_SHIFT       0x0000001Cu
  #define  VP_VCASTAT_F1C_DEFAULT     0x00000000u
  #define  VP_VCASTAT_F1C_OF(x)       _VALUEOF(x)
  #define  VP_VCASTAT_F1C_NONE        0x00000000u
  #define  VP_VCASTAT_F1C_CAPTURED    0x00000001u
  #define  VP_VCASTAT_F1C_CLEAR       0x00000001u

  #define _VP_VCASTAT_VCYPOS_MASK        0x0FFF0000u
  #define _VP_VCASTAT_VCYPOS_SHIFT       0x00000010u
  #define  VP_VCASTAT_VCYPOS_DEFAULT     0x00000000u
  #define  VP_VCASTAT_VCYPOS_OF(x)       _VALUEOF(x)

  #define _VP_VCASTAT_VCFLD_MASK        0x00001000u
  #define _VP_VCASTAT_VCFLD_SHIFT       0x0000000Cu
  #define  VP_VCASTAT_VCFLD_DEFAULT     0x00000000u
  #define  VP_VCASTAT_VCFLD_OF(x)       _VALUEOF(x)
  #define  VP_VCASTAT_VCFLD_NONE        0x00000000u
  #define  VP_VCASTAT_VCFLD_DETECTED    0x00000001u

  #define _VP_VCASTAT_VCXPOS_MASK        0x00000FFFu
  #define _VP_VCASTAT_VCXPOS_SHIFT       0x00000000u
  #define  VP_VCASTAT_VCXPOS_DEFAULT     0x00000000u
  #define  VP_VCASTAT_VCXPOS_OF(x)       _VALUEOF(x)


  #define  VP_VCASTAT_OF(x)            _VALUEOF(x)

  #define VP_VCASTAT_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VCASTAT,FSYNC)\
    |_PER_FDEFAULT(VP,VCASTAT,FRMC)\
    |_PER_FDEFAULT(VP,VCASTAT,F2C)\
    |_PER_FDEFAULT(VP,VCASTAT,F1C)\
    |_PER_FDEFAULT(VP,VCASTAT,VCYPOS)\
    |_PER_FDEFAULT(VP,VCASTAT,VCFLD)\
    |_PER_FDEFAULT(VP,VCASTAT,VCXPOS)\
  )

  #define VP_VCASTAT_RMK(frmc,f2c,f1c) (Uint32)(\
     _PER_FMK(VP,VCASTAT,FRMC,frmc)\
    |_PER_FMK(VP,VCASTAT,F2C,f2c)\
    |_PER_FMK(VP,VCASTAT,F1C,f1c)\
  )

  #define _VP_VCASTAT_FGET(N,FIELD)\
    _PER_FGET(_VP_VCASTAT##N##_ADDR,VP,VCASTAT,##FIELD)

  #define _VP_VCASTAT_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VCASTAT##N##_ADDR,VP,VCASTAT,##FIELD,field)

  #define _VP_VCASTAT_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VCASTAT##N##_ADDR,VP,VCASTAT,##FIELD,##SYM)

  #define _VP_VCASTAT0_FGET(FIELD)   _VP_VCASTAT_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCASTAT1_FGET(FIELD)   _VP_VCASTAT_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCASTAT2_FGET(FIELD)   _VP_VCASTAT_FGET(2,##FIELD)
 #endif


  #define _VP_VCASTAT0_FSET(FIELD,f)   _VP_VCASTAT_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCASTAT1_FSET(FIELD,f)   _VP_VCASTAT_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCASTAT2_FSET(FIELD,f)   _VP_VCASTAT_FSET(2,##FIELD,f)
 #endif


  #define _VP_VCASTAT0_FSETS(FIELD,SYM)   _VP_VCASTAT_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCASTAT1_FSETS(FIELD,SYM)   _VP_VCASTAT_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCASTAT2_FSETS(FIELD,SYM)   _VP_VCASTAT_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V C A C T L      |
* |___________________|
*
* VCACTL0 -  Video Port 0 Video Capture A Control
* VCACTL1 -  Video Port 1 Video Capture A Control
* VCACTL2 -  Video Port 2 Video Capture A Control
*
* FIELDS (msb -> lsb)
*
* (rw) RSTCH
* (rw) BLKCAP
* (rw) RDFE
* (rw) FINV
* (rw) EXC
* (rw) FLDD
* (rw) VRST
* (rw) HRST
* (rw) VCEN
* (rw) PK10B
* (rw) LFDE
* (rw) SFDE
* (rw) RESMPL
* (rw) SCALE
* (rw) CON
* (rw) FRAME
* (rw) CF2
* (rw) CF1
* (rw) CMODE
*
\******************************************************************************/
  #define _VP_VCACTL_OFFSET            65
  #define _VP_VCACTL_OFFSETA           1

  #define _VP_VCACTL0_ADDR   (_VP_BASE_PORT0 + 4*_VP_VCACTL_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCACTL1_ADDR   (_VP_BASE_PORT1 + 4*_VP_VCACTL_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCACTL2_ADDR   (_VP_BASE_PORT2 + 4*_VP_VCACTL_OFFSET)
 #endif


  #define _VP_VCACTL0_ADDRA   (_VP_BASE_CHAPORT0 + 4*_VP_VCACTL_OFFSETA)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCACTL1_ADDRA   (_VP_BASE_CHAPORT1 + 4*_VP_VCACTL_OFFSETA)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCACTL2_ADDRA   (_VP_BASE_CHAPORT2 + 4*_VP_VCACTL_OFFSETA)
 #endif



  #define _VP_VCACTL_RSTCH_MASK        0x80000000u
  #define _VP_VCACTL_RSTCH_SHIFT       0x0000001Fu
  #define  VP_VCACTL_RSTCH_DEFAULT     0x00000000u
  #define  VP_VCACTL_RSTCH_OF(x)       _VALUEOF(x)
  #define  VP_VCACTL_RSTCH_NONE        0x00000000u
  #define  VP_VCACTL_RSTCH_RESET       0x00000001u

  #define _VP_VCACTL_BLKCAP_MASK       0x40000000u
  #define _VP_VCACTL_BLKCAP_SHIFT      0x0000001Eu
  #define  VP_VCACTL_BLKCAP_DEFAULT    0x00000001u
  #define  VP_VCACTL_BLKCAP_OF(x)      _VALUEOF(x)
  #define  VP_VCACTL_BLKCAP_CLEAR      0x00000000u
  #define  VP_VCACTL_BLKCAP_BLOCK      0x00000001u

  #define _VP_VCACTL_RDFE_MASK         0x00200000u
  #define _VP_VCACTL_RDFE_SHIFT        0x00000015u
  #define  VP_VCACTL_RDFE_DEFAULT      0x00000000u
  #define  VP_VCACTL_RDFE_OF(x)        _VALUEOF(x)
  #define  VP_VCACTL_RDFE_DISABLE      0x00000000u
  #define  VP_VCACTL_RDFE_ENABLE       0x00000001u

  #define _VP_VCACTL_FINV_MASK         0x00100000u
  #define _VP_VCACTL_FINV_SHIFT        0x00000014u
  #define  VP_VCACTL_FINV_DEFAULT      0x00000000u
  #define  VP_VCACTL_FINV_OF(x)        _VALUEOF(x)
  #define  VP_VCACTL_FINV_FIELD1       0x00000000u
  #define  VP_VCACTL_FINV_FIELD2       0x00000001u

  #define _VP_VCACTL_EXC_MASK          0x00080000u
  #define _VP_VCACTL_EXC_SHIFT         0x00000013u
  #define  VP_VCACTL_EXC_DEFAULT       0x00000000u
  #define  VP_VCACTL_EXC_OF(x)         _VALUEOF(x)
  #define  VP_VCACTL_EXC_EAVSAV        0x00000000u
  #define  VP_VCACTL_EXC_EXTERN        0x00000001u

  #define _VP_VCACTL_FLDD_MASK         0x00040000u
  #define _VP_VCACTL_FLDD_SHIFT        0x00000012u
  #define  VP_VCACTL_FLDD_DEFAULT      0x00000000u
  #define  VP_VCACTL_FLDD_OF(x)        _VALUEOF(x)
  #define  VP_VCACTL_FLDD_EAVFID       0x00000000u
  #define  VP_VCACTL_FLDD_FDL          0x00000001u

  #define _VP_VCACTL_VRST_MASK         0x00020000u
  #define _VP_VCACTL_VRST_SHIFT        0x00000011u
  #define  VP_VCACTL_VRST_DEFAULT      0x00000001u
  #define  VP_VCACTL_VRST_OF(x)        _VALUEOF(x)
  #define  VP_VCACTL_VRST_V1EAV        0x00000000u
  #define  VP_VCACTL_VRST_V0EAV        0x00000001u

  #define _VP_VCACTL_HRST_MASK         0x00010000u
  #define _VP_VCACTL_HRST_SHIFT        0x00000010u
  #define  VP_VCACTL_HRST_DEFAULT      0x00000000u
  #define  VP_VCACTL_HRST_OF(x)        _VALUEOF(x)
  #define  VP_VCACTL_HRST_EAV          0x00000000u
  #define  VP_VCACTL_HRST_SAV          0x00000001u

  #define _VP_VCACTL_VCEN_MASK         0x00008000u
  #define _VP_VCACTL_VCEN_SHIFT        0x0000000Fu
  #define  VP_VCACTL_VCEN_DEFAULT      0x00000000u
  #define  VP_VCACTL_VCEN_OF(x)        _VALUEOF(x)
  #define  VP_VCACTL_VCEN_DISABLE      0x00000000u
  #define  VP_VCACTL_VCEN_ENABLE       0x00000001u

  #define _VP_VCACTL_PK10B_MASK        0x00006000u
  #define _VP_VCACTL_PK10B_SHIFT       0x0000000Du
  #define  VP_VCACTL_PK10B_DEFAULT     0x00000000u
  #define  VP_VCACTL_PK10B_OF(x)       _VALUEOF(x)
  #define  VP_VCACTL_PK10B_ZERO        0x00000000u
  #define  VP_VCACTL_PK10B_SIGN        0x00000001u
  #define  VP_VCACTL_PK10B_DENSEPK     0x00000002u

  #define _VP_VCACTL_LFDE_MASK         0x00001000u
  #define _VP_VCACTL_LFDE_SHIFT        0x0000000Cu
  #define  VP_VCACTL_LFDE_DEFAULT      0x00000000u
  #define  VP_VCACTL_LFDE_OF(x)        _VALUEOF(x)
  #define  VP_VCACTL_LFDE_DISABLE      0x00000000u
  #define  VP_VCACTL_LFDE_ENABLE       0x00000001u

  #define _VP_VCACTL_SFDE_MASK         0x00000800u
  #define _VP_VCACTL_SFDE_SHIFT        0x0000000Bu
  #define  VP_VCACTL_SFDE_DEFAULT      0x00000000u
  #define  VP_VCACTL_SFDE_OF(x)        _VALUEOF(x)
  #define  VP_VCACTL_SFDE_DISABLE      0x00000000u
  #define  VP_VCACTL_SFDE_ENABLE       0x00000001u

  #define _VP_VCACTL_RESMPL_MASK       0x00000400u
  #define _VP_VCACTL_RESMPL_SHIFT      0x0000000Au
  #define  VP_VCACTL_RESMPL_DEFAULT    0x00000000u
  #define  VP_VCACTL_RESMPL_OF(x)      _VALUEOF(x)
  #define  VP_VCACTL_RESMPL_DISABLE    0x00000000u
  #define  VP_VCACTL_RESMPL_ENABLE     0x00000001u

  #define _VP_VCACTL_SCALE_MASK        0x00000100u
  #define _VP_VCACTL_SCALE_SHIFT       0x00000008u
  #define  VP_VCACTL_SCALE_DEFAULT     0x00000000u
  #define  VP_VCACTL_SCALE_OF(x)       _VALUEOF(x)
  #define  VP_VCACTL_SCALE_NONE        0x00000000u
  #define  VP_VCACTL_SCALE_HALF        0x00000001u

  #define _VP_VCACTL_CON_MASK          0x00000080u
  #define _VP_VCACTL_CON_SHIFT         0x00000007u
  #define  VP_VCACTL_CON_DEFAULT       0x00000000u
  #define  VP_VCACTL_CON_OF(x)         _VALUEOF(x)
  #define  VP_VCACTL_CON_DISABLE       0x00000000u
  #define  VP_VCACTL_CON_ENABLE        0x00000001u

  #define _VP_VCACTL_FRAME_MASK        0x00000040u
  #define _VP_VCACTL_FRAME_SHIFT       0x00000006u
  #define  VP_VCACTL_FRAME_DEFAULT     0x00000000u
  #define  VP_VCACTL_FRAME_OF(x)       _VALUEOF(x)
  #define  VP_VCACTL_FRAME_NONE        0x00000000u
  #define  VP_VCACTL_FRAME_FRMCAP      0x00000001u

  #define _VP_VCACTL_CF2_MASK          0x00000020u
  #define _VP_VCACTL_CF2_SHIFT         0x00000005u
  #define  VP_VCACTL_CF2_DEFAULT       0x00000001u
  #define  VP_VCACTL_CF2_OF(x)         _VALUEOF(x)
  #define  VP_VCACTL_CF2_NONE          0x00000000u
  #define  VP_VCACTL_CF2_FLDCAP        0x00000001u

  #define _VP_VCACTL_CF1_MASK          0x00000010u
  #define _VP_VCACTL_CF1_SHIFT         0x00000004u
  #define  VP_VCACTL_CF1_DEFAULT       0x00000001u
  #define  VP_VCACTL_CF1_OF(x)         _VALUEOF(x)
  #define  VP_VCACTL_CF1_NONE          0x00000000u
  #define  VP_VCACTL_CF1_FLDCAP        0x00000001u

  #define _VP_VCACTL_CMODE_MASK        0x00000007u
  #define _VP_VCACTL_CMODE_SHIFT       0x00000000u
  #define  VP_VCACTL_CMODE_DEFAULT     0x00000000u
  #define  VP_VCACTL_CMODE_OF(x)       _VALUEOF(x)
  #define  VP_VCACTL_CMODE_BT656B      0x00000000u
  #define  VP_VCACTL_CMODE_BT656D      0x00000001u
  #define  VP_VCACTL_CMODE_RAWB        0x00000002u
  #define  VP_VCACTL_CMODE_RAWD        0x00000003u
  #define  VP_VCACTL_CMODE_YCB         0x00000004u
  #define  VP_VCACTL_CMODE_YCD         0x00000005u
  #define  VP_VCACTL_CMODE_RAW16       0x00000006u
  #define  VP_VCACTL_CMODE_RAW20       0x00000007u

  #define  VP_VCACTL_OF(x)            _VALUEOF(x)

  #define VP_VCACTL_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VCACTL,RSTCH)\
    |_PER_FDEFAULT(VP,VCACTL,BLKCAP)\
    |_PER_FDEFAULT(VP,VCACTL,RDFE)\
    |_PER_FDEFAULT(VP,VCACTL,FINV)\
    |_PER_FDEFAULT(VP,VCACTL,EXC)\
    |_PER_FDEFAULT(VP,VCACTL,FLDD)\
    |_PER_FDEFAULT(VP,VCACTL,VRST)\
    |_PER_FDEFAULT(VP,VCACTL,HRST)\
    |_PER_FDEFAULT(VP,VCACTL,VCEN)\
    |_PER_FDEFAULT(VP,VCACTL,PK10B)\
    |_PER_FDEFAULT(VP,VCACTL,LFDE)\
    |_PER_FDEFAULT(VP,VCACTL,SFDE)\
    |_PER_FDEFAULT(VP,VCACTL,RESMPL)\
    |_PER_FDEFAULT(VP,VCACTL,SCALE)\
    |_PER_FDEFAULT(VP,VCACTL,CON)\
    |_PER_FDEFAULT(VP,VCACTL,FRAME)\
    |_PER_FDEFAULT(VP,VCACTL,CF2)\
    |_PER_FDEFAULT(VP,VCACTL,CF1)\
    |_PER_FDEFAULT(VP,VCACTL,CMODE)\
  )

  #define VP_VCACTL_RMK(rstch,blkcap,rdfe,finv,exc,fldd,vrst,\
    hrst,vcen,pk10b,lfde,sfde,resmpl,scale,con,frame,cf2,cf1,cmode) (Uint32)(\
     _PER_FMK(VP,VCACTL,RSTCH,rstch)\
    |_PER_FMK(VP,VCACTL,BLKCAP,blkcap)\
    |_PER_FMK(VP,VCACTL,RDFE,rdfe)\
    |_PER_FMK(VP,VCACTL,FINV,finv)\
    |_PER_FMK(VP,VCACTL,EXC,exc)\
    |_PER_FMK(VP,VCACTL,FLDD,fldd)\
    |_PER_FMK(VP,VCACTL,VRST,vrst)\
    |_PER_FMK(VP,VCACTL,HRST,hrst)\
    |_PER_FMK(VP,VCACTL,VCEN,vcen)\
    |_PER_FMK(VP,VCACTL,PK10B,pk10b)\
    |_PER_FMK(VP,VCACTL,LFDE,lfde)\
    |_PER_FMK(VP,VCACTL,SFDE,sfde)\
    |_PER_FMK(VP,VCACTL,RESMPL,resmpl)\
    |_PER_FMK(VP,VCACTL,SCALE,scale)\
    |_PER_FMK(VP,VCACTL,CON,con)\
    |_PER_FMK(VP,VCACTL,FRAME,frame)\
    |_PER_FMK(VP,VCACTL,CF2,cf2)\
    |_PER_FMK(VP,VCACTL,CF1,cf1)\
    |_PER_FMK(VP,VCACTL,CMODE,cmode)\
  )

  #define _VP_VCACTL_FGET(N,FIELD)\
    _PER_FGET(_VP_VCACTL##N##_ADDR,VP,VCACTL,##FIELD)

  #define _VP_VCACTL_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VCACTL##N##_ADDR,VP,VCACTL,##FIELD,field)

  #define _VP_VCACTL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VCACTL##N##_ADDR,VP,VCACTL,##FIELD,##SYM)

  #define _VP_VCACTL0_FGET(FIELD)   _VP_VCACTL_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCACTL1_FGET(FIELD)   _VP_VCACTL_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCACTL2_FGET(FIELD)   _VP_VCACTL_FGET(2,##FIELD)
 #endif


  #define _VP_VCACTL0_FSET(FIELD,f)   _VP_VCACTL_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCACTL1_FSET(FIELD,f)   _VP_VCACTL_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCACTL2_FSET(FIELD,f)   _VP_VCACTL_FSET(2,##FIELD,f)
 #endif


  #define _VP_VCACTL0_FSETS(FIELD,SYM)   _VP_VCACTL_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCACTL1_FSETS(FIELD,SYM)   _VP_VCACTL_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCACTL2_FSETS(FIELD,SYM)   _VP_VCACTL_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V C A S T R T 1  |
* |___________________|
*
* VCASTRT10 -  Video Port 0 Video Capture A Field1 Start
* VCASTRT11 -  Video Port 1 Video Capture A Field1 Start
* VCASTRT12 -  Video Port 2 Video Capture A Field1 Start
*
* FIELDS (msb -> lsb)
* (rw) VCYSTART
* (rw) SSE
* (rw) VCXSTART/VCVBLNKP
*
\******************************************************************************/
  #define _VP_VCASTRT1_OFFSET           66
  #define _VP_VCASTRT1_OFFSETA           2

  #define _VP_VCASTRT10_ADDR   (_VP_BASE_PORT0 + 4*_VP_VCASTRT1_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCASTRT11_ADDR   (_VP_BASE_PORT1 + 4*_VP_VCASTRT1_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCASTRT12_ADDR   (_VP_BASE_PORT2 + 4*_VP_VCASTRT1_OFFSET)
 #endif


  #define _VP_VCASTRT10_ADDRA   (_VP_BASE_CHAPORT0 + 4*_VP_VCASTRT1_OFFSETA)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCASTRT11_ADDRA   (_VP_BASE_CHAPORT1 + 4*_VP_VCASTRT1_OFFSETA)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCASTRT12_ADDRA   (_VP_BASE_CHAPORT2 + 4*_VP_VCASTRT1_OFFSETA)
 #endif


  #define _VP_VCASTRT1_VCYSTART_MASK        0x0FFF0000u
  #define _VP_VCASTRT1_VCYSTART_SHIFT       0x00000010u
  #define  VP_VCASTRT1_VCYSTART_DEFAULT     0x00000000u
  #define  VP_VCASTRT1_VCYSTART_OF(x)       _VALUEOF(x)

  #define _VP_VCASTRT1_SSE_MASK             0x00008000u
  #define _VP_VCASTRT1_SSE_SHIFT            0x0000000Fu
  #define  VP_VCASTRT1_SSE_DEFAULT          0x00000001u
  #define  VP_VCASTRT1_SSE_OF(x)            _VALUEOF(x)
  #define  VP_VCASTRT1_SSE_DISABLE          0x00000000u
  #define  VP_VCASTRT1_SSE_ENABLE           0x00000001u

  #define _VP_VCASTRT1_VCXSTART_MASK        0x00000FFFu
  #define _VP_VCASTRT1_VCXSTART_SHIFT       0x00000000u
  #define  VP_VCASTRT1_VCXSTART_DEFAULT     0x00000000u
  #define  VP_VCASTRT1_VCXSTART_OF(x)       _VALUEOF(x)

  #define _VP_VCASTRT1_VCVBLNKP_MASK        0x00000FFFu
  #define _VP_VCASTRT1_VCVBLNKP_SHIFT       0x00000000u
  #define  VP_VCASTRT1_VCVBLNKP_DEFAULT     0x00000000u
  #define  VP_VCASTRT1_VCVBLNKP_OF(x)       _VALUEOF(x)

  #define  VP_VCASTRT1_OF(x)            _VALUEOF(x)

  #define VP_VCASTRT1_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VCASTRT1,VCYSTART)\
    |_PER_FDEFAULT(VP,VCASTRT1,SSE)\
    |_PER_FDEFAULT(VP,VCASTRT1,VCXSTART)\
  )

  #define VP_VCASTRT1_RMK(vcystart,sse,vcxstart) (Uint32)(\
     _PER_FMK(VP,VCASTRT1,VCYSTART,vcystart)\
    |_PER_FMK(VP,VCASTRT1,SSE,sse)\
    |_PER_FMK(VP,VCASTRT1,VCXSTART,vcxstart)\
  )

  #define _VP_VCASTRT1_FGET(N,FIELD)\
    _PER_FGET(_VP_VCASTRT1##N##_ADDR,VP,VCASTRT1,##FIELD)

  #define _VP_VCASTRT1_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VCASTRT1##N##_ADDR,VP,VCASTRT1,##FIELD,field)

  #define _VP_VCASTRT1_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VCASTRT1##N##_ADDR,VP,VCASTRT1,##FIELD,##SYM)

  #define _VP_VCASTRT10_FGET(FIELD)   _VP_VCASTRT1_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCASTRT11_FGET(FIELD)   _VP_VCASTRT1_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCASTRT12_FGET(FIELD)   _VP_VCASTRT1_FGET(2,##FIELD)
 #endif


  #define _VP_VCASTRT10_FSET(FIELD,f)   _VP_VCASTRT1_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCASTRT11_FSET(FIELD,f)   _VP_VCASTRT1_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCASTRT12_FSET(FIELD,f)   _VP_VCASTRT1_FSET(2,##FIELD,f)
 #endif


  #define _VP_VCASTRT10_FSETS(FIELD,SYM)   _VP_VCASTRT1_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCASTRT11_FSETS(FIELD,SYM)   _VP_VCASTRT1_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCASTRT12_FSETS(FIELD,SYM)   _VP_VCASTRT1_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V C A S T O P 1  |
* |___________________|
*
* VCASTOP10 -  Video Port 0 Video Capture A Field1 Stop
* VCASTOP11 -  Video Port 1 Video Capture A Field1 Stop
* VCASTOP12 -  Video Port 2 Video Capture A Field1 Stop
*
* FIELDS (msb -> lsb)
* (rw) VCYSTOP
* (rw) VCXSTOP
*
\******************************************************************************/
  #define _VP_VCASTOP1_OFFSET           67
  #define _VP_VCASTOP1_OFFSETA           3

  #define _VP_VCASTOP10_ADDR   (_VP_BASE_PORT0 + 4*_VP_VCASTOP1_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCASTOP11_ADDR   (_VP_BASE_PORT1 + 4*_VP_VCASTOP1_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCASTOP12_ADDR   (_VP_BASE_PORT2 + 4*_VP_VCASTOP1_OFFSET)
 #endif


  #define _VP_VCASTOP10_ADDRA   (_VP_BASE_CHAPORT0 + 4*_VP_VCASTOP1_OFFSETA)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCASTOP11_ADDRA   (_VP_BASE_CHAPORT1 + 4*_VP_VCASTOP1_OFFSETA)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCASTOP12_ADDRA   (_VP_BASE_CHAPORT2 + 4*_VP_VCASTOP1_OFFSETA)
 #endif


  #define _VP_VCASTOP1_VCYSTOP_MASK        0x0FFF0000u
  #define _VP_VCASTOP1_VCYSTOP_SHIFT       0x00000010u
  #define  VP_VCASTOP1_VCYSTOP_DEFAULT     0x00000000u
  #define  VP_VCASTOP1_VCYSTOP_OF(x)       _VALUEOF(x)

  #define _VP_VCASTOP1_VCXSTOP_MASK        0x00000FFFu
  #define _VP_VCASTOP1_VCXSTOP_SHIFT       0x00000000u
  #define  VP_VCASTOP1_VCXSTOP_DEFAULT     0x00000000u
  #define  VP_VCASTOP1_VCXSTOP_OF(x)       _VALUEOF(x)

  #define  VP_VCASTOP1_OF(x)            _VALUEOF(x)

  #define VP_VCASTOP1_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VCASTOP1,VCYSTOP)\
    |_PER_FDEFAULT(VP,VCASTOP1,VCXSTOP)\
  )

  #define VP_VCASTOP1_RMK(vcystop,vcxstop) (Uint32)(\
     _PER_FMK(VP,VCASTOP1,VCYSTOP,vcystop)\
    |_PER_FMK(VP,VCASTOP1,VCXSTOP,vcxstop)\
  )

  #define _VP_VCASTOP1_FGET(N,FIELD)\
    _PER_FGET(_VP_VCASTOP1##N##_ADDR,VP,VCASTOP1,##FIELD)

  #define _VP_VCASTOP1_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VCASTOP1##N##_ADDR,VP,VCASTOP1,##FIELD,field)

  #define _VP_VCASTOP1_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VCASTOP1##N##_ADDR,VP,VCASTOP1,##FIELD,##SYM)

  #define _VP_VCASTOP10_FGET(FIELD)   _VP_VCASTOP1_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCASTOP11_FGET(FIELD)   _VP_VCASTOP1_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCASTOP12_FGET(FIELD)   _VP_VCASTOP1_FGET(2,##FIELD)
 #endif


  #define _VP_VCASTOP10_FSET(FIELD,f)   _VP_VCASTOP1_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCASTOP11_FSET(FIELD,f)   _VP_VCASTOP1_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCASTOP12_FSET(FIELD,f)   _VP_VCASTOP1_FSET(2,##FIELD,f)
 #endif


  #define _VP_VCASTOP10_FSETS(FIELD,SYM)   _VP_VCASTOP1_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCASTOP11_FSETS(FIELD,SYM)   _VP_VCASTOP1_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCASTOP12_FSETS(FIELD,SYM)   _VP_VCASTOP1_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V C A S T R T 2  |
* |___________________|
*
* VCASTRT20 -  Video Port 0 Video Capture A Field2 Start
* VCASTRT21 -  Video Port 1 Video Capture A Field2 Start
* VCASTRT22 -  Video Port 2 Video Capture A Field2 Start
*
* FIELDS (msb -> lsb)
* (rw) VCYSTART
* (rw) VCXSTART
*
\******************************************************************************/
  #define _VP_VCASTRT2_OFFSET           68
  #define _VP_VCASTRT2_OFFSETA           4

  #define _VP_VCASTRT20_ADDR   (_VP_BASE_PORT0 + 4*_VP_VCASTRT2_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCASTRT21_ADDR   (_VP_BASE_PORT1 + 4*_VP_VCASTRT2_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCASTRT22_ADDR   (_VP_BASE_PORT2 + 4*_VP_VCASTRT2_OFFSET)
 #endif


  #define _VP_VCASTRT20_ADDRA   (_VP_BASE_CHAPORT0 + 4*_VP_VCASTRT2_OFFSETA)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCASTRT21_ADDRA   (_VP_BASE_CHAPORT1 + 4*_VP_VCASTRT2_OFFSETA)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCASTRT22_ADDRA   (_VP_BASE_CHAPORT2 + 4*_VP_VCASTRT2_OFFSETA)
 #endif


  #define _VP_VCASTRT2_VCYSTART_MASK        0x0FFF0000u
  #define _VP_VCASTRT2_VCYSTART_SHIFT       0x00000010u
  #define  VP_VCASTRT2_VCYSTART_DEFAULT     0x00000000u
  #define  VP_VCASTRT2_VCYSTART_OF(x)       _VALUEOF(x)

  #define _VP_VCASTRT2_VCXSTART_MASK        0x00000FFFu
  #define _VP_VCASTRT2_VCXSTART_SHIFT       0x00000000u
  #define  VP_VCASTRT2_VCXSTART_DEFAULT     0x00000000u
  #define  VP_VCASTRT2_VCXSTART_OF(x)       _VALUEOF(x)

  #define  VP_VCASTRT2_OF(x)            _VALUEOF(x)

  #define VP_VCASTRT2_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VCASTRT2,VCYSTART)\
    |_PER_FDEFAULT(VP,VCASTRT2,VCXSTART)\
  )

  #define VP_VCASTRT2_RMK(vcystart,vcxstart) (Uint32)(\
     _PER_FMK(VP,VCASTRT2,VCYSTART,vcystart)\
    |_PER_FMK(VP,VCASTRT2,VCXSTART,vcxstart)\
  )

  #define _VP_VCASTRT2_FGET(N,FIELD)\
    _PER_FGET(_VP_VCASTRT2##N##_ADDR,VP,VCASTRT2,##FIELD)

  #define _VP_VCASTRT2_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VCASTRT2##N##_ADDR,VP,VCASTRT2,##FIELD,field)

  #define _VP_VCASTRT2_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VCASTRT2##N##_ADDR,VP,VCASTRT2,##FIELD,##SYM)

  #define _VP_VCASTRT20_FGET(FIELD)   _VP_VCASTRT2_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCASTRT21_FGET(FIELD)   _VP_VCASTRT2_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCASTRT22_FGET(FIELD)   _VP_VCASTRT2_FGET(2,##FIELD)
 #endif


  #define _VP_VCASTRT20_FSET(FIELD,f)   _VP_VCASTRT2_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCASTRT21_FSET(FIELD,f)   _VP_VCASTRT2_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCASTRT22_FSET(FIELD,f)   _VP_VCASTRT2_FSET(2,##FIELD,f)
 #endif


  #define _VP_VCASTRT20_FSETS(FIELD,SYM)   _VP_VCASTRT2_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCASTRT21_FSETS(FIELD,SYM)   _VP_VCASTRT2_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCASTRT22_FSETS(FIELD,SYM)   _VP_VCASTRT2_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V C A S T O P 2  |
* |___________________|
*
* VCASTOP20 -  Video Port 0 Video Capture A Field2 Stop
* VCASTOP21 -  Video Port 1 Video Capture A Field2 Stop
* VCASTOP22 -  Video Port 2 Video Capture A Field2 Stop
*
* FIELDS (msb -> lsb)
* (rw) VCYSTOP
* (rw) VCXSTOP
*
\******************************************************************************/
  #define _VP_VCASTOP2_OFFSET           69
  #define _VP_VCASTOP2_OFFSETA           5

  #define _VP_VCASTOP20_ADDR   (_VP_BASE_PORT0 + 4*_VP_VCASTOP2_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCASTOP21_ADDR   (_VP_BASE_PORT1 + 4*_VP_VCASTOP2_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCASTOP22_ADDR   (_VP_BASE_PORT2 + 4*_VP_VCASTOP2_OFFSET)
 #endif


  #define _VP_VCASTOP20_ADDRA   (_VP_BASE_CHAPORT0 + 4*_VP_VCASTOP2_OFFSETA)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCASTOP21_ADDRA   (_VP_BASE_CHAPORT1 + 4*_VP_VCASTOP2_OFFSETA)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCASTOP22_ADDRA   (_VP_BASE_CHAPORT2 + 4*_VP_VCASTOP2_OFFSETA)
 #endif


  #define _VP_VCASTOP2_VCYSTOP_MASK        0x0FFF0000u
  #define _VP_VCASTOP2_VCYSTOP_SHIFT       0x00000010u
  #define  VP_VCASTOP2_VCYSTOP_DEFAULT     0x00000000u
  #define  VP_VCASTOP2_VCYSTOP_OF(x)       _VALUEOF(x)

  #define _VP_VCASTOP2_VCXSTOP_MASK        0x00000FFFu
  #define _VP_VCASTOP2_VCXSTOP_SHIFT       0x00000000u
  #define  VP_VCASTOP2_VCXSTOP_DEFAULT     0x00000000u
  #define  VP_VCASTOP2_VCXSTOP_OF(x)       _VALUEOF(x)

  #define  VP_VCASTOP2_OF(x)            _VALUEOF(x)

  #define VP_VCASTOP2_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VCASTOP2,VCYSTOP)\
    |_PER_FDEFAULT(VP,VCASTOP2,VCXSTOP)\
  )

  #define VP_VCASTOP2_RMK(vcystop,vcxstop) (Uint32)(\
     _PER_FMK(VP,VCASTOP2,VCYSTOP,vcystop)\
    |_PER_FMK(VP,VCASTOP2,VCXSTOP,vcxstop)\
  )

  #define _VP_VCASTOP2_FGET(N,FIELD)\
    _PER_FGET(_VP_VCASTOP2##N##_ADDR,VP,VCASTOP2,##FIELD)

  #define _VP_VCASTOP2_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VCASTOP2##N##_ADDR,VP,VCASTOP2,##FIELD,field)

  #define _VP_VCASTOP2_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VCASTOP2##N##_ADDR,VP,VCASTOP2,##FIELD,##SYM)

  #define _VP_VCASTOP20_FGET(FIELD)   _VP_VCASTOP2_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCASTOP21_FGET(FIELD)   _VP_VCASTOP2_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCASTOP22_FGET(FIELD)   _VP_VCASTOP2_FGET(2,##FIELD)
 #endif


  #define _VP_VCASTOP20_FSET(FIELD,f)   _VP_VCASTOP2_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCASTOP21_FSET(FIELD,f)   _VP_VCASTOP2_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCASTOP22_FSET(FIELD,f)   _VP_VCASTOP2_FSET(2,##FIELD,f)
 #endif


  #define _VP_VCASTOP20_FSETS(FIELD,SYM)   _VP_VCASTOP2_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCASTOP21_FSETS(FIELD,SYM)   _VP_VCASTOP2_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCASTOP22_FSETS(FIELD,SYM)   _VP_VCASTOP2_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V C A V I N T    |
* |___________________|
*
* VCAVINT0 -  Video Port 0 Video Capture A Vertical Interrupt
* VCAVINT1 -  Video Port 1 Video Capture A Vertical Interrupt
* VCAVINT2 -  Video Port 2 Video Capture A Vertical Interrupt
*
* FIELDS (msb -> lsb)
* (rw) VIF2 
* (rw) FSCL2
* (rw) VINT2
* (rw) VIF1 
* (rw) VINT1
*
\******************************************************************************/
  #define _VP_VCAVINT_OFFSET            70
  #define _VP_VCAVINT_OFFSETA            6

  #define _VP_VCAVINT0_ADDR   (_VP_BASE_PORT0 + 4*_VP_VCAVINT_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCAVINT1_ADDR   (_VP_BASE_PORT1 + 4*_VP_VCAVINT_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCAVINT2_ADDR   (_VP_BASE_PORT2 + 4*_VP_VCAVINT_OFFSET)
 #endif


  #define _VP_VCAVINT0_ADDRA   (_VP_BASE_CHAPORT0 + 4*_VP_VCAVINT_OFFSETA)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCAVINT1_ADDRA   (_VP_BASE_CHAPORT1 + 4*_VP_VCAVINT_OFFSETA)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCAVINT2_ADDRA   (_VP_BASE_CHAPORT2 + 4*_VP_VCAVINT_OFFSETA)
 #endif


  #define _VP_VCAVINT_VIF2_MASK        0x80000000u
  #define _VP_VCAVINT_VIF2_SHIFT       0x0000001Fu
  #define  VP_VCAVINT_VIF2_DEFAULT     0x00000000u
  #define  VP_VCAVINT_VIF2_OF(x)       _VALUEOF(x)
  #define  VP_VCAVINT_VIF2_DISABLE     0x00000000u
  #define  VP_VCAVINT_VIF2_ENABLE      0x00000001u

  #define _VP_VCAVINT_FSCL2_MASK         0x40000000u
  #define _VP_VCAVINT_FSCL2_SHIFT        0x0000001Eu
  #define  VP_VCAVINT_FSCL2_DEFAULT      0x00000000u
  #define  VP_VCAVINT_FSCL2_OF(x)        _VALUEOF(x)
  #define  VP_VCAVINT_FSCL2_NONE         0x00000000u
  #define  VP_VCAVINT_FSCL2_FIELD2       0x00000001u

  #define _VP_VCAVINT_VINT2_MASK         0x0FFF0000u
  #define _VP_VCAVINT_VINT2_SHIFT        0x00000010u
  #define  VP_VCAVINT_VINT2_DEFAULT      0x00000000u
  #define  VP_VCAVINT_VINT2_OF(x)        _VALUEOF(x)

  #define _VP_VCAVINT_VIF1_MASK        0x00008000u
  #define _VP_VCAVINT_VIF1_SHIFT       0x0000000Fu
  #define  VP_VCAVINT_VIF1_DEFAULT     0x00000000u
  #define  VP_VCAVINT_VIF1_OF(x)       _VALUEOF(x)
  #define  VP_VCAVINT_VIF1_DISABLE     0x00000000u
  #define  VP_VCAVINT_VIF1_ENABLE      0x00000001u

  #define _VP_VCAVINT_VINT1_MASK         0x00000FFFu
  #define _VP_VCAVINT_VINT1_SHIFT        0x00000000u
  #define  VP_VCAVINT_VINT1_DEFAULT      0x00000000u
  #define  VP_VCAVINT_VINT1_OF(x)        _VALUEOF(x)

  #define  VP_VCAVINT_OF(x)            _VALUEOF(x)

  #define VP_VCAVINT_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VCAVINT,VIF2)\
    |_PER_FDEFAULT(VP,VCAVINT,FSCL2)\
    |_PER_FDEFAULT(VP,VCAVINT,VINT2)\
    |_PER_FDEFAULT(VP,VCAVINT,VIF1)\
    |_PER_FDEFAULT(VP,VCAVINT,VINT1)\
  )

  #define VP_VCAVINT_RMK(vif2,fscl2,vint2,vif1,vint1) (Uint32)(\
     _PER_FMK(VP,VCAVINT,VIF2,vif2)\
    |_PER_FMK(VP,VCAVINT,FSCL2,fscl2)\
    |_PER_FMK(VP,VCAVINT,VINT2,vint2)\
    |_PER_FMK(VP,VCAVINT,VIF1,vif1)\
    |_PER_FMK(VP,VCAVINT,VINT1,vint1)\
  )

  #define _VP_VCAVINT_FGET(N,FIELD)\
    _PER_FGET(_VP_VCAVINT##N##_ADDR,VP,VCAVINT,##FIELD)

  #define _VP_VCAVINT_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VCAVINT##N##_ADDR,VP,VCAVINT,##FIELD,field)

  #define _VP_VCAVINT_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VCAVINT##N##_ADDR,VP,VCAVINT,##FIELD,##SYM)

  #define _VP_VCAVINT0_FGET(FIELD)   _VP_VCAVINT_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCAVINT1_FGET(FIELD)   _VP_VCAVINT_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCAVINT2_FGET(FIELD)   _VP_VCAVINT_FGET(2,##FIELD)
 #endif


  #define _VP_VCAVINT0_FSET(FIELD,f)   _VP_VCAVINT_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCAVINT1_FSET(FIELD,f)   _VP_VCAVINT_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCAVINT2_FSET(FIELD,f)   _VP_VCAVINT_FSET(2,##FIELD,f)
 #endif


  #define _VP_VCAVINT0_FSETS(FIELD,SYM)   _VP_VCAVINT_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCAVINT1_FSETS(FIELD,SYM)   _VP_VCAVINT_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCAVINT2_FSETS(FIELD,SYM)   _VP_VCAVINT_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V C A T H R L D  |
* |___________________|
*
* VCATHRLD0    -  Video Port 0 Video Capture A Threshold
* VCATHRLD1    -  Video Port 1 Video Capture A Threshold
* VCATHRLD2    -  Video Port 2 Video Capture A Threshold
*
* FIELDS (msb -> lsb)
* (rw) VCTHRLD2
* (rw) VCTHRLD1
*
\******************************************************************************/
  #define _VP_VCATHRLD_OFFSET           71
  #define _VP_VCATHRLD_OFFSETA           7

  #define _VP_VCATHRLD0_ADDR   (_VP_BASE_PORT0 + 4*_VP_VCATHRLD_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCATHRLD1_ADDR   (_VP_BASE_PORT1 + 4*_VP_VCATHRLD_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCATHRLD2_ADDR   (_VP_BASE_PORT2 + 4*_VP_VCATHRLD_OFFSET)
 #endif


  #define _VP_VCATHRLD0_ADDRA   (_VP_BASE_CHAPORT0 + 4*_VP_VCATHRLD_OFFSETA)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCATHRLD1_ADDRA   (_VP_BASE_CHAPORT1 + 4*_VP_VCATHRLD_OFFSETA)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCATHRLD2_ADDRA   (_VP_BASE_CHAPORT2 + 4*_VP_VCATHRLD_OFFSETA)
 #endif


  #define _VP_VCATHRLD_VCTHRLD2_MASK         0x03FF0000u
  #define _VP_VCATHRLD_VCTHRLD2_SHIFT        0x00000010u
  #define  VP_VCATHRLD_VCTHRLD2_DEFAULT      0x00000000u
  #define  VP_VCATHRLD_VCTHRLD2_OF(x)        _VALUEOF(x)

  #define _VP_VCATHRLD_VCTHRLD1_MASK         0x000003FFu
  #define _VP_VCATHRLD_VCTHRLD1_SHIFT        0x00000000u
  #define  VP_VCATHRLD_VCTHRLD1_DEFAULT      0x00000000u
  #define  VP_VCATHRLD_VCTHRLD1_OF(x)        _VALUEOF(x)

  #define  VP_VCATHRLD_OF(x)            _VALUEOF(x)

  #define VP_VCATHRLD_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VCATHRLD,VCTHRLD2)\
    |_PER_FDEFAULT(VP,VCATHRLD,VCTHRLD1)\
  )

  #define VP_VCATHRLD_RMK(vcthrld2,vcthrld1) (Uint32)(\
     _PER_FMK(VP,VCATHRLD,VCTHRLD2,vcthrld2)\
    |_PER_FMK(VP,VCATHRLD,VCTHRLD1,vcthrld1)\
  )

  #define _VP_VCATHRLD_FGET(N,FIELD)\
    _PER_FGET(_VP_VCATHRLD##N##_ADDR,VP,VCATHRLD,##FIELD)

  #define _VP_VCATHRLD_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VCATHRLD##N##_ADDR,VP,VCATHRLD,##FIELD,field)

  #define _VP_VCATHRLD_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VCATHRLD##N##_ADDR,VP,VCATHRLD,##FIELD,##SYM)

  #define _VP_VCATHRLD0_FGET(FIELD)   _VP_VCATHRLD_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCATHRLD1_FGET(FIELD)   _VP_VCATHRLD_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCATHRLD2_FGET(FIELD)   _VP_VCATHRLD_FGET(2,##FIELD)
 #endif


  #define _VP_VCATHRLD0_FSET(FIELD,f)   _VP_VCATHRLD_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCATHRLD1_FSET(FIELD,f)   _VP_VCATHRLD_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCATHRLD2_FSET(FIELD,f)   _VP_VCATHRLD_FSET(2,##FIELD,f)
 #endif


  #define _VP_VCATHRLD0_FSETS(FIELD,SYM)   _VP_VCATHRLD_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCATHRLD1_FSETS(FIELD,SYM)   _VP_VCATHRLD_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCATHRLD2_FSETS(FIELD,SYM)   _VP_VCATHRLD_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V C A E V T C T  |
* |___________________|
*
* VCAEVTCT0    -  Video Port 0 Video Capture A Event Count
* VCAEVTCT1    -  Video Port 1 Video Capture A Event Count
* VCAEVTCT2    -  Video Port 2 Video Capture A Event Count
*
* FIELDS (msb -> lsb)
* (rw) CAPEVTCT2
* (rw) CAPEVTCT1
*
\******************************************************************************/
  #define _VP_VCAEVTCT_OFFSET           72
  #define _VP_VCAEVTCT_OFFSETA           8

  #define _VP_VCAEVTCT0_ADDR   (_VP_BASE_PORT0 + 4*_VP_VCAEVTCT_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCAEVTCT1_ADDR   (_VP_BASE_PORT1 + 4*_VP_VCAEVTCT_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCAEVTCT2_ADDR   (_VP_BASE_PORT2 + 4*_VP_VCAEVTCT_OFFSET)
 #endif


  #define _VP_VCAEVTCT0_ADDRA   (_VP_BASE_CHAPORT0 + 4*_VP_VCAEVTCT_OFFSETA)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCAEVTCT1_ADDRA   (_VP_BASE_CHAPORT1 + 4*_VP_VCAEVTCT_OFFSETA)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCAEVTCT2_ADDRA   (_VP_BASE_CHAPORT2 + 4*_VP_VCAEVTCT_OFFSETA)
 #endif


  #define _VP_VCAEVTCT_CAPEVTCT2_MASK         0x0FFF0000u
  #define _VP_VCAEVTCT_CAPEVTCT2_SHIFT        0x00000010u
  #define  VP_VCAEVTCT_CAPEVTCT2_DEFAULT      0x00000000u
  #define  VP_VCAEVTCT_CAPEVTCT2_OF(x)        _VALUEOF(x)

  #define _VP_VCAEVTCT_CAPEVTCT1_MASK         0x00000FFFu
  #define _VP_VCAEVTCT_CAPEVTCT1_SHIFT        0x00000000u
  #define  VP_VCAEVTCT_CAPEVTCT1_DEFAULT      0x00000000u
  #define  VP_VCAEVTCT_CAPEVTCT1_OF(x)        _VALUEOF(x)

  #define  VP_VCAEVTCT_OF(x)            _VALUEOF(x)

  #define VP_VCAEVTCT_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VCAEVTCT,CAPEVTCT2)\
    |_PER_FDEFAULT(VP,VCAEVTCT,CAPEVTCT1)\
  )

  #define VP_VCAEVTCT_RMK(capevtct2,capevtct1) (Uint32)(\
     _PER_FMK(VP,VCAEVTCT,CAPEVTCT2,capevtct2)\
    |_PER_FMK(VP,VCAEVTCT,CAPEVTCT1,capevtct1)\
  )

  #define _VP_VCAEVTCT_FGET(N,FIELD)\
    _PER_FGET(_VP_VCAEVTCT##N##_ADDR,VP,VCAEVTCT,##FIELD)

  #define _VP_VCAEVTCT_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VCAEVTCT##N##_ADDR,VP,VCAEVTCT,##FIELD,field)

  #define _VP_VCAEVTCT_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VCAEVTCT##N##_ADDR,VP,VCAEVTCT,##FIELD,##SYM)

  #define _VP_VCAEVTCT0_FGET(FIELD)   _VP_VCAEVTCT_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCAEVTCT1_FGET(FIELD)   _VP_VCAEVTCT_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCAEVTCT2_FGET(FIELD)   _VP_VCAEVTCT_FGET(2,##FIELD)
 #endif


  #define _VP_VCAEVTCT0_FSET(FIELD,f)   _VP_VCAEVTCT_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCAEVTCT1_FSET(FIELD,f)   _VP_VCAEVTCT_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCAEVTCT2_FSET(FIELD,f)   _VP_VCAEVTCT_FSET(2,##FIELD,f)
 #endif


  #define _VP_VCAEVTCT0_FSETS(FIELD,SYM)   _VP_VCAEVTCT_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VCAEVTCT1_FSETS(FIELD,SYM)   _VP_VCAEVTCT_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VCAEVTCT2_FSETS(FIELD,SYM)   _VP_VCAEVTCT_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V C B S T A T    |
* |___________________|
*
* VCBSTAT0 - Video Port 0 Video Capture B Status
* VCBSTAT1 - Video Port 1 Video Capture B Status
* VCBSTAT2 - Video Port 2 Video Capture B Status
*
* Defined only for DM642
*
* FIELDS (msb -> lsb)
*
* (r)  FSYNC
* (rc) FRMC
* (rc) F2C
* (rc) F1C
* (r)  VCYPOS
* (r)  VCFLD
* (r)  VCXPOS
*
\******************************************************************************/
#if (CHIP_DM642)
  #define _VP_VCBSTAT_OFFSET           80
  #define _VP_VCBSTAT_OFFSETB           0

  #define _VP_VCBSTAT0_ADDR   (_VP_BASE_PORT0 + 4*_VP_VCBSTAT_OFFSET)
  #define _VP_VCBSTAT1_ADDR   (_VP_BASE_PORT1 + 4*_VP_VCBSTAT_OFFSET)
  #define _VP_VCBSTAT2_ADDR   (_VP_BASE_PORT2 + 4*_VP_VCBSTAT_OFFSET)


  #define _VP_VCBSTAT0_ADDRB   (_VP_BASE_CHBPORT0 + 4*_VP_VCBSTAT_OFFSETB)
  #define _VP_VCBSTAT1_ADDRB   (_VP_BASE_CHBPORT1 + 4*_VP_VCBSTAT_OFFSETB)
  #define _VP_VCBSTAT2_ADDRB   (_VP_BASE_CHBPORT2 + 4*_VP_VCBSTAT_OFFSETB)

  #define _VP_VCBSTAT_FSYNC_MASK        0x80000000u
  #define _VP_VCBSTAT_FSYNC_SHIFT       0x0000001Fu
  #define  VP_VCBSTAT_FSYNC_DEFAULT     0x00000000u
  #define  VP_VCBSTAT_FSYNC_OF(x)       _VALUEOF(x)
  #define  VP_VCBSTAT_FSYNC_CLEARD      0x00000000u
  #define  VP_VCBSTAT_FSYNC_SET         0x00000001u

  #define _VP_VCBSTAT_FRMC_MASK        0x40000000u
  #define _VP_VCBSTAT_FRMC_SHIFT       0x0000001Eu
  #define  VP_VCBSTAT_FRMC_DEFAULT     0x00000000u
  #define  VP_VCBSTAT_FRMC_OF(x)       _VALUEOF(x)
  #define  VP_VCBSTAT_FRMC_NONE        0x00000000u
  #define  VP_VCBSTAT_FRMC_CAPTURED    0x00000001u
  #define  VP_VCBSTAT_FRMC_CLEAR       0x00000001u

  #define _VP_VCBSTAT_F2C_MASK        0x20000000u
  #define _VP_VCBSTAT_F2C_SHIFT       0x0000001Du
  #define  VP_VCBSTAT_F2C_DEFAULT     0x00000000u
  #define  VP_VCBSTAT_F2C_OF(x)       _VALUEOF(x)
  #define  VP_VCBSTAT_F2C_NONE        0x00000000u
  #define  VP_VCBSTAT_F2C_CAPTURED    0x00000001u
  #define  VP_VCBSTAT_F2C_CLEAR       0x00000001u

  #define _VP_VCBSTAT_F1C_MASK        0x10000000u
  #define _VP_VCBSTAT_F1C_SHIFT       0x0000001Cu
  #define  VP_VCBSTAT_F1C_DEFAULT     0x00000000u
  #define  VP_VCBSTAT_F1C_OF(x)       _VALUEOF(x)
  #define  VP_VCBSTAT_F1C_NONE        0x00000000u
  #define  VP_VCBSTAT_F1C_CAPTURED    0x00000001u
  #define  VP_VCBSTAT_F1C_CLEAR       0x00000001u

  #define _VP_VCBSTAT_VCYPOS_MASK        0x0FFF0000u
  #define _VP_VCBSTAT_VCYPOS_SHIFT       0x00000010u
  #define  VP_VCBSTAT_VCYPOS_DEFAULT     0x00000000u
  #define  VP_VCBSTAT_VCYPOS_OF(x)       _VALUEOF(x)

  #define _VP_VCBSTAT_VCFLD_MASK        0x00001000u
  #define _VP_VCBSTAT_VCFLD_SHIFT       0x0000000Cu
  #define  VP_VCBSTAT_VCFLD_DEFAULT     0x00000000u
  #define  VP_VCBSTAT_VCFLD_OF(x)       _VALUEOF(x)
  #define  VP_VCBSTAT_VCFLD_NONE        0x00000000u
  #define  VP_VCBSTAT_VCFLD_DETECTED    0x00000001u

  #define _VP_VCBSTAT_VCXPOS_MASK        0x00000FFFu
  #define _VP_VCBSTAT_VCXPOS_SHIFT       0x00000000u
  #define  VP_VCBSTAT_VCXPOS_DEFAULT     0x00000000u
  #define  VP_VCBSTAT_VCXPOS_OF(x)       _VALUEOF(x)


  #define  VP_VCBSTAT_OF(x)            _VALUEOF(x)

  #define VP_VCBSTAT_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VCBSTAT,FSYNC)\
    |_PER_FDEFAULT(VP,VCBSTAT,FRMC)\
    |_PER_FDEFAULT(VP,VCBSTAT,F2C)\
    |_PER_FDEFAULT(VP,VCBSTAT,F1C)\
    |_PER_FDEFAULT(VP,VCBSTAT,VCYPOS)\
    |_PER_FDEFAULT(VP,VCBSTAT,VCFLD)\
    |_PER_FDEFAULT(VP,VCBSTAT,VCXPOS)\
  )

  #define VP_VCBSTAT_RMK(frmc,f2c,f1c) (Uint32)(\
     _PER_FMK(VP,VCBSTAT,FRMC,frmc)\
    |_PER_FMK(VP,VCBSTAT,F2C,f2c)\
    |_PER_FMK(VP,VCBSTAT,F1C,f1c)\
  )

  #define _VP_VCBSTAT_FGET(N,FIELD)\
    _PER_FGET(_VP_VCBSTAT##N##_ADDR,VP,VCBSTAT,##FIELD)

  #define _VP_VCBSTAT_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VCBSTAT##N##_ADDR,VP,VCBSTAT,##FIELD,field)

  #define _VP_VCBSTAT_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VCBSTAT##N##_ADDR,VP,VCBSTAT,##FIELD,##SYM)

  #define _VP_VCBSTAT0_FGET(FIELD)   _VP_VCBSTAT_FGET(0,##FIELD)
  #define _VP_VCBSTAT1_FGET(FIELD)   _VP_VCBSTAT_FGET(1,##FIELD)
  #define _VP_VCBSTAT2_FGET(FIELD)   _VP_VCBSTAT_FGET(2,##FIELD)


  #define _VP_VCBSTAT0_FSET(FIELD,f)   _VP_VCBSTAT_FSET(0,##FIELD,f)
  #define _VP_VCBSTAT1_FSET(FIELD,f)   _VP_VCBSTAT_FSET(1,##FIELD,f)
  #define _VP_VCBSTAT2_FSET(FIELD,f)   _VP_VCBSTAT_FSET(2,##FIELD,f)

  #define _VP_VCBSTAT0_FSETS(FIELD,SYM)   _VP_VCBSTAT_FSETS(0,##FIELD,##SYM)
  #define _VP_VCBSTAT1_FSETS(FIELD,SYM)   _VP_VCBSTAT_FSETS(1,##FIELD,##SYM)
  #define _VP_VCBSTAT2_FSETS(FIELD,SYM)   _VP_VCBSTAT_FSETS(2,##FIELD,##SYM)
#endif

/******************************************************************************\
* _____________________
* |                   |
* |  V C B C T L      |
* |___________________|
*
* VCBCTL0 -  Video Port 0 Video Capture A Control
* VCBCTL1 -  Video Port 1 Video Capture A Control
* VCBCTL2 -  Video Port 2 Video Capture A Control
*
* Defined only for DM642
*
* FIELDS (msb -> lsb)
*
* (rw) RSTCH
* (rw) BLKCAP
* (rw) FINV
* (rw) VRST
* (rw) HRST
* (rw) VCEN
* (rw) 10BPK
* (rw) LFDE
* (rw) SFDE
* (rw) RESMPL
* (rw) SCALE
* (rw) CON
* (rw) FRAME
* (rw) CF2
* (rw) CF1
* (rw) CMODE
*
\******************************************************************************/
 #if (CHIP_DM642)
  #define _VP_VCBCTL_OFFSET           81
  #define _VP_VCBCTL_OFFSETB           1

  #define _VP_VCBCTL0_ADDR   (_VP_BASE_PORT0 + 4*_VP_VCBCTL_OFFSET)
  #define _VP_VCBCTL1_ADDR   (_VP_BASE_PORT1 + 4*_VP_VCBCTL_OFFSET)
  #define _VP_VCBCTL2_ADDR   (_VP_BASE_PORT2 + 4*_VP_VCBCTL_OFFSET)


  #define _VP_VCBCTL0_ADDRB   (_VP_BASE_CHBPORT0 + 4*_VP_VCBCTL_OFFSETB)
  #define _VP_VCBCTL1_ADDRB   (_VP_BASE_CHBPORT1 + 4*_VP_VCBCTL_OFFSETB)
  #define _VP_VCBCTL2_ADDRB   (_VP_BASE_CHBPORT2 + 4*_VP_VCBCTL_OFFSETB)


  #define _VP_VCBCTL_RSTCH_MASK        0x80000000u
  #define _VP_VCBCTL_RSTCH_SHIFT       0x0000001Fu
  #define  VP_VCBCTL_RSTCH_DEFAULT     0x00000000u
  #define  VP_VCBCTL_RSTCH_OF(x)       _VALUEOF(x)
  #define  VP_VCBCTL_RSTCH_NONE        0x00000000u
  #define  VP_VCBCTL_RSTCH_RESET       0x00000001u

  #define _VP_VCBCTL_BLKCAP_MASK         0x40000000u
  #define _VP_VCBCTL_BLKCAP_SHIFT        0x0000001Eu
  #define  VP_VCBCTL_BLKCAP_DEFAULT      0x00000001u
  #define  VP_VCBCTL_BLKCAP_OF(x)        _VALUEOF(x)
  #define  VP_VCBCTL_BLKCAP_CLEAR        0x00000000u
  #define  VP_VCBCTL_BLKCAP_BLOCK        0x00000001u

  #define _VP_VCBCTL_FINV_MASK           0x00100000u
  #define _VP_VCBCTL_FINV_SHIFT          0x00000014u
  #define  VP_VCBCTL_FINV_DEFAULT        0x00000000u
  #define  VP_VCBCTL_FINV_OF(x)          _VALUEOF(x)
  #define  VP_VCBCTL_FINV_FIELD1         0x00000000u
  #define  VP_VCBCTL_FINV_FIELD2         0x00000001u

  #define _VP_VCBCTL_VRST_MASK           0x00020000u
  #define _VP_VCBCTL_VRST_SHIFT          0x00000011u
  #define  VP_VCBCTL_VRST_DEFAULT        0x00000001u
  #define  VP_VCBCTL_VRST_OF(x)          _VALUEOF(x)
  #define  VP_VCBCTL_VRST_V1EAV          0x00000000u
  #define  VP_VCBCTL_VRST_V0EAV          0x00000001u

  #define _VP_VCBCTL_HRST_MASK           0x00010000u
  #define _VP_VCBCTL_HRST_SHIFT          0x00000010u
  #define  VP_VCBCTL_HRST_DEFAULT        0x00000000u
  #define  VP_VCBCTL_HRST_OF(x)          _VALUEOF(x)
  #define  VP_VCBCTL_HRST_EAV            0x00000000u
  #define  VP_VCBCTL_HRST_SAV            0x00000001u

  #define _VP_VCBCTL_VCEN_MASK         0x00008000u
  #define _VP_VCBCTL_VCEN_SHIFT        0x0000000Fu
  #define  VP_VCBCTL_VCEN_DEFAULT      0x00000000u
  #define  VP_VCBCTL_VCEN_OF(x)        _VALUEOF(x)
  #define  VP_VCBCTL_VCEN_DISABLE      0x00000000u
  #define  VP_VCBCTL_VCEN_ENABLE       0x00000001u

  #define _VP_VCBCTL_PK10B_MASK         0x00006000u
  #define _VP_VCBCTL_PK10B_SHIFT        0x0000000Du
  #define  VP_VCBCTL_PK10B_DEFAULT      0x00000000u
  #define  VP_VCBCTL_PK10B_OF(x)        _VALUEOF(x)
  #define  VP_VCBCTL_PK10B_ZERO         0x00000000u
  #define  VP_VCBCTL_PK10B_SIGN         0x00000001u
  #define  VP_VCBCTL_PK10B_DENSEPK      0x00000002u

  #define _VP_VCBCTL_LFDE_MASK         0x00001000u
  #define _VP_VCBCTL_LFDE_SHIFT        0x0000000Cu
  #define  VP_VCBCTL_LFDE_DEFAULT      0x00000000u
  #define  VP_VCBCTL_LFDE_OF(x)        _VALUEOF(x)
  #define  VP_VCBCTL_LFDE_DISABLE      0x00000000u
  #define  VP_VCBCTL_LFDE_ENABLE       0x00000001u

  #define _VP_VCBCTL_SFDE_MASK         0x00000800u
  #define _VP_VCBCTL_SFDE_SHIFT        0x0000000Bu
  #define  VP_VCBCTL_SFDE_DEFAULT      0x00000000u
  #define  VP_VCBCTL_SFDE_OF(x)        _VALUEOF(x)
  #define  VP_VCBCTL_SFDE_DISABLE      0x00000000u
  #define  VP_VCBCTL_SFDE_ENABLE       0x00000001u

  #define _VP_VCBCTL_RESMPL_MASK         0x00000400u
  #define _VP_VCBCTL_RESMPL_SHIFT        0x0000000Au
  #define  VP_VCBCTL_RESMPL_DEFAULT      0x00000000u
  #define  VP_VCBCTL_RESMPL_OF(x)        _VALUEOF(x)
  #define  VP_VCBCTL_RESMPL_DISABLE      0x00000000u
  #define  VP_VCBCTL_RESMPL_ENABLE       0x00000001u

  #define _VP_VCBCTL_SCALE_MASK         0x00000100u
  #define _VP_VCBCTL_SCALE_SHIFT        0x00000008u
  #define  VP_VCBCTL_SCALE_DEFAULT      0x00000000u
  #define  VP_VCBCTL_SCALE_OF(x)        _VALUEOF(x)
  #define  VP_VCBCTL_SCALE_NONE         0x00000000u
  #define  VP_VCBCTL_SCALE_HALF         0x00000001u

  #define _VP_VCBCTL_CON_MASK         0x00000080u
  #define _VP_VCBCTL_CON_SHIFT        0x00000007u
  #define  VP_VCBCTL_CON_DEFAULT      0x00000000u
  #define  VP_VCBCTL_CON_OF(x)        _VALUEOF(x)
  #define  VP_VCBCTL_CON_DISABLE      0x00000000u
  #define  VP_VCBCTL_CON_ENABLE        0x00000001u

  #define _VP_VCBCTL_FRAME_MASK         0x00000040u
  #define _VP_VCBCTL_FRAME_SHIFT        0x00000006u
  #define  VP_VCBCTL_FRAME_DEFAULT      0x00000000u
  #define  VP_VCBCTL_FRAME_OF(x)        _VALUEOF(x)
  #define  VP_VCBCTL_FRAME_NONE         0x00000000u
  #define  VP_VCBCTL_FRAME_FRMCAP       0x00000001u

  #define _VP_VCBCTL_CF2_MASK         0x00000020u
  #define _VP_VCBCTL_CF2_SHIFT        0x00000005u
  #define  VP_VCBCTL_CF2_DEFAULT      0x00000001u
  #define  VP_VCBCTL_CF2_OF(x)        _VALUEOF(x)
  #define  VP_VCBCTL_CF2_NONE         0x00000000u
  #define  VP_VCBCTL_CF2_FLDCAP       0x00000001u

  #define _VP_VCBCTL_CF1_MASK         0x00000010u
  #define _VP_VCBCTL_CF1_SHIFT        0x00000004u
  #define  VP_VCBCTL_CF1_DEFAULT      0x00000001u
  #define  VP_VCBCTL_CF1_OF(x)        _VALUEOF(x)
  #define  VP_VCBCTL_CF1_NONE         0x00000000u
  #define  VP_VCBCTL_CF1_FLDCAP       0x00000001u

  #define _VP_VCBCTL_CMODE_MASK         0x00000003u
  #define _VP_VCBCTL_CMODE_SHIFT        0x00000000u
  #define  VP_VCBCTL_CMODE_DEFAULT      0x00000000u
  #define  VP_VCBCTL_CMODE_OF(x)        _VALUEOF(x)
  #define  VP_VCBCTL_CMODE_BT656B       0x00000000u
  #define  VP_VCBCTL_CMODE_BT656D       0x00000001u
  #define  VP_VCBCTL_CMODE_RAWB         0x00000002u
  #define  VP_VCBCTL_CMODE_RAWD         0x00000003u

  #define  VP_VCBCTL_OF(x)            _VALUEOF(x)

  #define VP_VCBCTL_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VCBCTL,RSTCH)\
    |_PER_FDEFAULT(VP,VCBCTL,BLKCAP)\
    |_PER_FDEFAULT(VP,VCBCTL,FINV)\
    |_PER_FDEFAULT(VP,VCBCTL,VRST)\
    |_PER_FDEFAULT(VP,VCBCTL,HRST)\
    |_PER_FDEFAULT(VP,VCBCTL,VCEN)\
    |_PER_FDEFAULT(VP,VCBCTL,PK10B)\
    |_PER_FDEFAULT(VP,VCBCTL,LFDE)\
    |_PER_FDEFAULT(VP,VCBCTL,SFDE)\
    |_PER_FDEFAULT(VP,VCBCTL,RESMPL)\
    |_PER_FDEFAULT(VP,VCBCTL,SCALE)\
    |_PER_FDEFAULT(VP,VCBCTL,CON)\
    |_PER_FDEFAULT(VP,VCBCTL,FRAME)\
    |_PER_FDEFAULT(VP,VCBCTL,CF2)\
    |_PER_FDEFAULT(VP,VCBCTL,CF1)\
    |_PER_FDEFAULT(VP,VCBCTL,CMODE)\
  )

  #define VP_VCBCTL_RMK(rstch,blkcap,finv,vrst,hrst,\
    vcen,pk10b,lfde,sfde,resmpl,scale,con,frame,cf2,cf1,cmode) (Uint32)(\
     _PER_FMK(VP,VCBCTL,RSTCH,rstch)\
    |_PER_FMK(VP,VCBCTL,BLKCAP,blkcap)\
    |_PER_FMK(VP,VCBCTL,RDFE,rdfe)\
    |_PER_FMK(VP,VCBCTL,FINV,finv)\
    |_PER_FMK(VP,VCBCTL,FLDD,fldd)\
    |_PER_FMK(VP,VCBCTL,VRST,vrst)\
    |_PER_FMK(VP,VCBCTL,HRST,hrst)\
    |_PER_FMK(VP,VCBCTL,VCEN,vcen)\
    |_PER_FMK(VP,VCBCTL,PK10B,pk10b)\
    |_PER_FMK(VP,VCBCTL,LFDE,lfde)\
    |_PER_FMK(VP,VCBCTL,SFDE,sfde)\
    |_PER_FMK(VP,VCBCTL,RESMPL,resmpl)\
    |_PER_FMK(VP,VCBCTL,SCALE,scale)\
    |_PER_FMK(VP,VCBCTL,CON,con)\
    |_PER_FMK(VP,VCBCTL,FRAME,frame)\
    |_PER_FMK(VP,VCBCTL,CF2,cf2)\
    |_PER_FMK(VP,VCBCTL,CF1,cf1)\
    |_PER_FMK(VP,VCBCTL,CMODE,cmode)\
  )

  #define _VP_VCBCTL_FGET(N,FIELD)\
    _PER_FGET(_VP_VCBCTL##N##_ADDR,VP,VCBCTL,##FIELD)

  #define _VP_VCBCTL_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VCBCTL##N##_ADDR,VP,VCBCTL,##FIELD,field)

  #define _VP_VCBCTL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VCBCTL##N##_ADDR,VP,VCBCTL,##FIELD,##SYM)

  #define _VP_VCBCTL0_FGET(FIELD)   _VP_VCBCTL_FGET(0,##FIELD)
  #define _VP_VCBCTL1_FGET(FIELD)   _VP_VCBCTL_FGET(1,##FIELD)
  #define _VP_VCBCTL2_FGET(FIELD)   _VP_VCBCTL_FGET(2,##FIELD)


  #define _VP_VCBCTL0_FSET(FIELD,f)   _VP_VCBCTL_FSET(0,##FIELD,f)
  #define _VP_VCBCTL1_FSET(FIELD,f)   _VP_VCBCTL_FSET(1,##FIELD,f)
  #define _VP_VCBCTL2_FSET(FIELD,f)   _VP_VCBCTL_FSET(2,##FIELD,f)

  #define _VP_VCBCTL0_FSETS(FIELD,SYM)   _VP_VCBCTL_FSETS(0,##FIELD,##SYM)
  #define _VP_VCBCTL1_FSETS(FIELD,SYM)   _VP_VCBCTL_FSETS(1,##FIELD,##SYM)
  #define _VP_VCBCTL2_FSETS(FIELD,SYM)   _VP_VCBCTL_FSETS(2,##FIELD,##SYM)
 #endif

/******************************************************************************\
* _____________________
* |                   |
* |  V C B S T R T 1  |
* |___________________|
*
* VCBSTRT10 -  Video Port 0 Video Capture B Field1 Start
* VCBSTRT11 -  Video Port 1 Video Capture B Field1 Start
* VCBSTRT12 -  Video Port 2 Video Capture B Field1 Start
*
* Defined only for DM642
*
* FIELDS (msb -> lsb)
* (rw) VCYSTART
* (rw) SSE
* (rw) VCXSTART/VCVBLNKP
*
\******************************************************************************/
 #if (CHIP_DM642)
  #define _VP_VCBSTRT1_OFFSET           82
  #define _VP_VCBSTRT1_OFFSETB           2

  #define _VP_VCBSTRT10_ADDR   (_VP_BASE_PORT0 + 4*_VP_VCBSTRT1_OFFSET)
  #define _VP_VCBSTRT11_ADDR   (_VP_BASE_PORT1 + 4*_VP_VCBSTRT1_OFFSET)
  #define _VP_VCBSTRT12_ADDR   (_VP_BASE_PORT2 + 4*_VP_VCBSTRT1_OFFSET)

  #define _VP_VCBSTRT10_ADDRB   (_VP_BASE_CHBPORT0 + 4*_VP_VCBSTRT1_OFFSETB)
  #define _VP_VCBSTRT11_ADDRB   (_VP_BASE_CHBPORT1 + 4*_VP_VCBSTRT1_OFFSETB)
  #define _VP_VCBSTRT12_ADDRB   (_VP_BASE_CHBPORT2 + 4*_VP_VCBSTRT1_OFFSETB)

  #define _VP_VCBSTRT1_VCYSTART_MASK        0x0FFF0000u
  #define _VP_VCBSTRT1_VCYSTART_SHIFT       0x00000010u
  #define  VP_VCBSTRT1_VCYSTART_DEFAULT     0x00000000u
  #define  VP_VCBSTRT1_VCYSTART_OF(x)       _VALUEOF(x)

  #define _VP_VCBSTRT1_SSE_MASK             0x00008000u
  #define _VP_VCBSTRT1_SSE_SHIFT            0x0000000Fu
  #define  VP_VCBSTRT1_SSE_DEFAULT          0x00000001u
  #define  VP_VCBSTRT1_SSE_OF(x)            _VALUEOF(x)
  #define  VP_VCBSTRT1_SSE_DISABLE          0x00000000u
  #define  VP_VCBSTRT1_SSE_ENABLE           0x00000001u

  #define _VP_VCBSTRT1_VCXSTART_MASK        0x00000FFFu
  #define _VP_VCBSTRT1_VCXSTART_SHIFT       0x00000000u
  #define  VP_VCBSTRT1_VCXSTART_DEFAULT     0x00000000u
  #define  VP_VCBSTRT1_VCXSTART_OF(x)       _VALUEOF(x)

  #define _VP_VCBSTRT1_VCVBLNKP_MASK        0x00000FFFu
  #define _VP_VCBSTRT1_VCVBLNKP_SHIFT       0x00000000u
  #define  VP_VCBSTRT1_VCVBLNKP_DEFAULT     0x00000000u
  #define  VP_VCBSTRT1_VCVBLNKP_OF(x)       _VALUEOF(x)

  #define  VP_VCBSTRT1_OF(x)            _VALUEOF(x)

  #define VP_VCBSTRT1_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VCBSTRT1,VCYSTART)\
    |_PER_FDEFAULT(VP,VCBSTRT1,SSE)\
    |_PER_FDEFAULT(VP,VCBSTRT1,VCXSTART)\
  )

  #define VP_VCBSTRT1_RMK(vcystart,sse,vcxstart) (Uint32)(\
     _PER_FMK(VP,VCBSTRT1,VCYSTART,vcystart)\
    |_PER_FMK(VP,VCBSTRT1,SSE,sse)\
    |_PER_FMK(VP,VCBSTRT1,VCXSTART,vcxstart)\
  )

  #define _VP_VCBSTRT1_FGET(N,FIELD)\
    _PER_FGET(_VP_VCBSTRT1##N##_ADDR,VP,VCBSTRT1,##FIELD)

  #define _VP_VCBSTRT1_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VCBSTRT1##N##_ADDR,VP,VCBSTRT1,##FIELD,field)

  #define _VP_VCBSTRT1_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VCBSTRT1##N##_ADDR,VP,VCBSTRT1,##FIELD,##SYM)

  #define _VP_VCBSTRT10_FGET(FIELD)   _VP_VCBSTRT1_FGET(0,##FIELD)
  #define _VP_VCBSTRT11_FGET(FIELD)   _VP_VCBSTRT1_FGET(1,##FIELD)
  #define _VP_VCBSTRT12_FGET(FIELD)   _VP_VCBSTRT1_FGET(2,##FIELD)

  #define _VP_VCBSTRT10_FSET(FIELD,f)   _VP_VCBSTRT1_FSET(0,##FIELD,f)
  #define _VP_VCBSTRT11_FSET(FIELD,f)   _VP_VCBSTRT1_FSET(1,##FIELD,f)
  #define _VP_VCBSTRT12_FSET(FIELD,f)   _VP_VCBSTRT1_FSET(2,##FIELD,f)

  #define _VP_VCBSTRT10_FSETS(FIELD,SYM)   _VP_VCBSTRT1_FSETS(0,##FIELD,##SYM)
  #define _VP_VCBSTRT11_FSETS(FIELD,SYM)   _VP_VCBSTRT1_FSETS(1,##FIELD,##SYM)
  #define _VP_VCBSTRT12_FSETS(FIELD,SYM)   _VP_VCBSTRT1_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V C B S T O P 1  |
* |___________________|
*
* VCBSTOP10 -  Video Port 0 Video Capture B Field1 Stop
* VCBSTOP11 -  Video Port 1 Video Capture B Field1 Stop
* VCBSTOP12 -  Video Port 2 Video Capture B Field1 Stop
*
* Defined only for DM642
*
* FIELDS (msb -> lsb)
* (rw) VCYSTOP
* (rw) VCXSTOP
*
\******************************************************************************/
 #if (CHIP_DM642)
  #define _VP_VCBSTOP1_OFFSET           83
  #define _VP_VCBSTOP1_OFFSETB           3

  #define _VP_VCBSTOP10_ADDR   (_VP_BASE_PORT0 + 4*_VP_VCBSTOP1_OFFSET)
  #define _VP_VCBSTOP11_ADDR   (_VP_BASE_PORT1 + 4*_VP_VCBSTOP1_OFFSET)
  #define _VP_VCBSTOP12_ADDR   (_VP_BASE_PORT2 + 4*_VP_VCBSTOP1_OFFSET)

  #define _VP_VCBSTOP10_ADDRB   (_VP_BASE_CHBPORT0 + 4*_VP_VCBSTOP1_OFFSETB)
  #define _VP_VCBSTOP11_ADDRB   (_VP_BASE_CHBPORT1 + 4*_VP_VCBSTOP1_OFFSETB)
  #define _VP_VCBSTOP12_ADDRB   (_VP_BASE_CHBPORT2 + 4*_VP_VCBSTOP1_OFFSETB)

  #define _VP_VCBSTOP1_VCYSTOP_MASK        0x0FFF0000u
  #define _VP_VCBSTOP1_VCYSTOP_SHIFT       0x00000010u
  #define  VP_VCBSTOP1_VCYSTOP_DEFAULT     0x00000000u
  #define  VP_VCBSTOP1_VCYSTOP_OF(x)       _VALUEOF(x)

  #define _VP_VCBSTOP1_VCXSTOP_MASK        0x00000FFFu
  #define _VP_VCBSTOP1_VCXSTOP_SHIFT       0x00000000u
  #define  VP_VCBSTOP1_VCXSTOP_DEFAULT     0x00000000u
  #define  VP_VCBSTOP1_VCXSTOP_OF(x)       _VALUEOF(x)

  #define  VP_VCBSTOP1_OF(x)            _VALUEOF(x)

  #define VP_VCBSTOP1_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VCBSTOP1,VCYSTOP)\
    |_PER_FDEFAULT(VP,VCBSTOP1,VCXSTOP)\
  )

  #define VP_VCBSTOP1_RMK(vcystop,vcxstop) (Uint32)(\
     _PER_FMK(VP,VCBSTOP1,VCYSTOP,vcystop)\
    |_PER_FMK(VP,VCBSTOP1,VCXSTOP,vcxstop)\
  )

  #define _VP_VCBSTOP1_FGET(N,FIELD)\
    _PER_FGET(_VP_VCBSTOP1##N##_ADDR,VP,VCBSTOP1,##FIELD)

  #define _VP_VCBSTOP1_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VCBSTOP1##N##_ADDR,VP,VCBSTOP1,##FIELD,field)

  #define _VP_VCBSTOP1_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VCBSTOP1##N##_ADDR,VP,VCBSTOP1,##FIELD,##SYM)

  #define _VP_VCBSTOP10_FGET(FIELD)   _VP_VCBSTOP1_FGET(0,##FIELD)
  #define _VP_VCBSTOP11_FGET(FIELD)   _VP_VCBSTOP1_FGET(1,##FIELD)
  #define _VP_VCBSTOP12_FGET(FIELD)   _VP_VCBSTOP1_FGET(2,##FIELD)

  #define _VP_VCBSTOP10_FSET(FIELD,f)   _VP_VCBSTOP1_FSET(0,##FIELD,f)
  #define _VP_VCBSTOP11_FSET(FIELD,f)   _VP_VCBSTOP1_FSET(1,##FIELD,f)
  #define _VP_VCBSTOP12_FSET(FIELD,f)   _VP_VCBSTOP1_FSET(2,##FIELD,f)

  #define _VP_VCBSTOP10_FSETS(FIELD,SYM)   _VP_VCBSTOP1_FSETS(0,##FIELD,##SYM)
  #define _VP_VCBSTOP11_FSETS(FIELD,SYM)   _VP_VCBSTOP1_FSETS(1,##FIELD,##SYM)
  #define _VP_VCBSTOP12_FSETS(FIELD,SYM)   _VP_VCBSTOP1_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V C B S T R T 2  |
* |___________________|
*
* VCBSTRT20 -  Video Port 0 Video Capture B Field2 Start
* VCBSTRT21 -  Video Port 1 Video Capture B Field2 Start
* VCBSTRT22 -  Video Port 2 Video Capture B Field2 Start
*
* Defined only for DM642
*
* FIELDS (msb -> lsb)
* (rw) VCYSTART
* (rw) VCXSTART
*
\******************************************************************************/
 #if (CHIP_DM642)
  #define _VP_VCBSTRT2_OFFSET           84
  #define _VP_VCBSTRT2_OFFSETB           4

  #define _VP_VCBSTRT20_ADDR   (_VP_BASE_PORT0 + 4*_VP_VCBSTRT2_OFFSET)
  #define _VP_VCBSTRT21_ADDR   (_VP_BASE_PORT1 + 4*_VP_VCBSTRT2_OFFSET)
  #define _VP_VCBSTRT22_ADDR   (_VP_BASE_PORT2 + 4*_VP_VCBSTRT2_OFFSET)

  #define _VP_VCBSTRT20_ADDRB   (_VP_BASE_CHBPORT0 + 4*_VP_VCBSTRT2_OFFSETB)
  #define _VP_VCBSTRT21_ADDRB   (_VP_BASE_CHBPORT1 + 4*_VP_VCBSTRT2_OFFSETB)
  #define _VP_VCBSTRT22_ADDRB   (_VP_BASE_CHBPORT2 + 4*_VP_VCBSTRT2_OFFSETB)

  #define _VP_VCBSTRT2_VCYSTART_MASK        0x0FFF0000u
  #define _VP_VCBSTRT2_VCYSTART_SHIFT       0x00000010u
  #define  VP_VCBSTRT2_VCYSTART_DEFAULT     0x00000000u
  #define  VP_VCBSTRT2_VCYSTART_OF(x)       _VALUEOF(x)

  #define _VP_VCBSTRT2_VCXSTART_MASK        0x00000FFFu
  #define _VP_VCBSTRT2_VCXSTART_SHIFT       0x00000000u
  #define  VP_VCBSTRT2_VCXSTART_DEFAULT     0x00000000u
  #define  VP_VCBSTRT2_VCXSTART_OF(x)       _VALUEOF(x)

  #define  VP_VCBSTRT2_OF(x)            _VALUEOF(x)

  #define VP_VCBSTRT2_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VCBSTRT2,VCYSTART)\
    |_PER_FDEFAULT(VP,VCBSTRT2,VCXSTART)\
  )

  #define VP_VCBSTRT2_RMK(vcystart,vcxstart) (Uint32)(\
     _PER_FMK(VP,VCBSTRT2,VCYSTART,vcystart)\
    |_PER_FMK(VP,VCBSTRT2,VCXSTART,vcxstart)\
  )

  #define _VP_VCBSTRT2_FGET(N,FIELD)\
    _PER_FGET(_VP_VCBSTRT2##N##_ADDR,VP,VCBSTRT2,##FIELD)

  #define _VP_VCBSTRT2_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VCBSTRT2##N##_ADDR,VP,VCBSTRT2,##FIELD,field)

  #define _VP_VCBSTRT2_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VCBSTRT2##N##_ADDR,VP,VCBSTRT2,##FIELD,##SYM)

  #define _VP_VCBSTRT20_FGET(FIELD)   _VP_VCBSTRT2_FGET(0,##FIELD)
  #define _VP_VCBSTRT21_FGET(FIELD)   _VP_VCBSTRT2_FGET(1,##FIELD)
  #define _VP_VCBSTRT22_FGET(FIELD)   _VP_VCBSTRT2_FGET(2,##FIELD)

  #define _VP_VCBSTRT20_FSET(FIELD,f)   _VP_VCBSTRT2_FSET(0,##FIELD,f)
  #define _VP_VCBSTRT21_FSET(FIELD,f)   _VP_VCBSTRT2_FSET(1,##FIELD,f)
  #define _VP_VCBSTRT22_FSET(FIELD,f)   _VP_VCBSTRT2_FSET(2,##FIELD,f)

  #define _VP_VCBSTRT20_FSETS(FIELD,SYM)   _VP_VCBSTRT2_FSETS(0,##FIELD,##SYM)
  #define _VP_VCBSTRT21_FSETS(FIELD,SYM)   _VP_VCBSTRT2_FSETS(1,##FIELD,##SYM)
  #define _VP_VCBSTRT22_FSETS(FIELD,SYM)   _VP_VCBSTRT2_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V C B S T O P 2  |
* |___________________|
*
* VCBSTOP20 -  Video Port 0 Video Capture B Field2 Stop
* VCBSTOP21 -  Video Port 1 Video Capture B Field2 Stop
* VCBSTOP22 -  Video Port 2 Video Capture B Field2 Stop
*
* Defined only for DM642
*
* FIELDS (msb -> lsb)
* (rw) VCYSTOP
* (rw) VCXSTOP
*
\******************************************************************************/
 #if (CHIP_DM642)
  #define _VP_VCBSTOP2_OFFSET           85
  #define _VP_VCBSTOP2_OFFSETB           5

  #define _VP_VCBSTOP20_ADDR   (_VP_BASE_PORT0 + 4*_VP_VCBSTOP2_OFFSET)
  #define _VP_VCBSTOP21_ADDR   (_VP_BASE_PORT1 + 4*_VP_VCBSTOP2_OFFSET)
  #define _VP_VCBSTOP22_ADDR   (_VP_BASE_PORT2 + 4*_VP_VCBSTOP2_OFFSET)

  #define _VP_VCBSTOP20_ADDRB   (_VP_BASE_CHBPORT0 + 4*_VP_VCBSTOP2_OFFSETB)
  #define _VP_VCBSTOP21_ADDRB   (_VP_BASE_CHBPORT1 + 4*_VP_VCBSTOP2_OFFSETB)
  #define _VP_VCBSTOP22_ADDRB   (_VP_BASE_CHBPORT2 + 4*_VP_VCBSTOP2_OFFSETB)

  #define _VP_VCBSTOP2_VCYSTOP_MASK        0x0FFF0000u
  #define _VP_VCBSTOP2_VCYSTOP_SHIFT       0x00000010u
  #define  VP_VCBSTOP2_VCYSTOP_DEFAULT     0x00000000u
  #define  VP_VCBSTOP2_VCYSTOP_OF(x)       _VALUEOF(x)

  #define _VP_VCBSTOP2_VCXSTOP_MASK        0x00000FFFu
  #define _VP_VCBSTOP2_VCXSTOP_SHIFT       0x00000000u
  #define  VP_VCBSTOP2_VCXSTOP_DEFAULT     0x00000000u
  #define  VP_VCBSTOP2_VCXSTOP_OF(x)       _VALUEOF(x)

  #define  VP_VCBSTOP2_OF(x)            _VALUEOF(x)

  #define VP_VCBSTOP2_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VCBSTOP2,VCYSTOP)\
    |_PER_FDEFAULT(VP,VCBSTOP2,VCXSTOP)\
  )

  #define VP_VCBSTOP2_RMK(vcystop,vcxstop) (Uint32)(\
     _PER_FMK(VP,VCBSTOP2,VCYSTOP,vcystop)\
    |_PER_FMK(VP,VCBSTOP2,VCXSTOP,vcxstop)\
  )

  #define _VP_VCBSTOP2_FGET(N,FIELD)\
    _PER_FGET(_VP_VCBSTOP2##N##_ADDR,VP,VCBSTOP2,##FIELD)

  #define _VP_VCBSTOP2_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VCBSTOP2##N##_ADDR,VP,VCBSTOP2,##FIELD,field)

  #define _VP_VCBSTOP2_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VCBSTOP2##N##_ADDR,VP,VCBSTOP2,##FIELD,##SYM)

  #define _VP_VCBSTOP20_FGET(FIELD)   _VP_VCBSTOP2_FGET(0,##FIELD)
  #define _VP_VCBSTOP21_FGET(FIELD)   _VP_VCBSTOP2_FGET(1,##FIELD)
  #define _VP_VCBSTOP22_FGET(FIELD)   _VP_VCBSTOP2_FGET(2,##FIELD)

  #define _VP_VCBSTOP20_FSET(FIELD,f)   _VP_VCBSTOP2_FSET(0,##FIELD,f)
  #define _VP_VCBSTOP21_FSET(FIELD,f)   _VP_VCBSTOP2_FSET(1,##FIELD,f)
  #define _VP_VCBSTOP22_FSET(FIELD,f)   _VP_VCBSTOP2_FSET(2,##FIELD,f)

  #define _VP_VCBSTOP20_FSETS(FIELD,SYM)   _VP_VCBSTOP2_FSETS(0,##FIELD,##SYM)
  #define _VP_VCBSTOP21_FSETS(FIELD,SYM)   _VP_VCBSTOP2_FSETS(1,##FIELD,##SYM)
  #define _VP_VCBSTOP22_FSETS(FIELD,SYM)   _VP_VCBSTOP2_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V C B V I N T    |
* |___________________|
*
* VCBVINT0 -  Video Port 0 Video Capture B Vertical Interrupt
* VCBVINT1 -  Video Port 1 Video Capture B Vertical Interrupt
* VCBVINT2 -  Video Port 2 Video Capture B Vertical Interrupt
*
* Defined only for DM642
*
* FIELDS (msb -> lsb)
* (rw) VIF2 
* (rw) FSCL2
* (rw) VINT2
* (rw) VIF1 
* (rw) VINT1
*
\******************************************************************************/
 #if (CHIP_DM642)
  #define _VP_VCBVINT_OFFSET           86
  #define _VP_VCBVINT_OFFSETB           6

  #define _VP_VCBVINT0_ADDR   (_VP_BASE_PORT0 + 4*_VP_VCBVINT_OFFSET)
  #define _VP_VCBVINT1_ADDR   (_VP_BASE_PORT1 + 4*_VP_VCBVINT_OFFSET)
  #define _VP_VCBVINT2_ADDR   (_VP_BASE_PORT2 + 4*_VP_VCBVINT_OFFSET)

  #define _VP_VCBVINT0_ADDRB   (_VP_BASE_CHBPORT0 + 4*_VP_VCBVINT_OFFSETB)
  #define _VP_VCBVINT1_ADDRB   (_VP_BASE_CHBPORT1 + 4*_VP_VCBVINT_OFFSETB)
  #define _VP_VCBVINT2_ADDRB   (_VP_BASE_CHBPORT2 + 4*_VP_VCBVINT_OFFSETB)

  #define _VP_VCBVINT_VIF2_MASK        0x80000000u
  #define _VP_VCBVINT_VIF2_SHIFT       0x0000001Fu
  #define  VP_VCBVINT_VIF2_DEFAULT     0x00000000u
  #define  VP_VCBVINT_VIF2_OF(x)       _VALUEOF(x)
  #define  VP_VCBVINT_VIF2_DISABLE     0x00000000u
  #define  VP_VCBVINT_VIF2_ENABLE      0x00000001u

  #define _VP_VCBVINT_FSCL2_MASK         0x40000000u
  #define _VP_VCBVINT_FSCL2_SHIFT        0x0000001Eu
  #define  VP_VCBVINT_FSCL2_DEFAULT      0x00000000u
  #define  VP_VCBVINT_FSCL2_OF(x)        _VALUEOF(x)
  #define  VP_VCBVINT_FSCL2_NONE         0x00000000u
  #define  VP_VCBVINT_FSCL2_FIELD2       0x00000001u

  #define _VP_VCBVINT_VINT2_MASK         0x0FFF0000u
  #define _VP_VCBVINT_VINT2_SHIFT        0x00000010u
  #define  VP_VCBVINT_VINT2_DEFAULT      0x00000000u
  #define  VP_VCBVINT_VINT2_OF(x)        _VALUEOF(x)

  #define _VP_VCBVINT_VIF1_MASK        0x00008000u
  #define _VP_VCBVINT_VIF1_SHIFT       0x0000000Fu
  #define  VP_VCBVINT_VIF1_DEFAULT     0x00000000u
  #define  VP_VCBVINT_VIF1_OF(x)       _VALUEOF(x)
  #define  VP_VCBVINT_VIF1_DISABLE     0x00000000u
  #define  VP_VCBVINT_VIF1_ENABLE      0x00000001u

  #define _VP_VCBVINT_VINT1_MASK         0x00000FFFu
  #define _VP_VCBVINT_VINT1_SHIFT        0x00000000u
  #define  VP_VCBVINT_VINT1_DEFAULT      0x00000000u
  #define  VP_VCBVINT_VINT1_OF(x)        _VALUEOF(x)

  #define  VP_VCBVINT_OF(x)            _VALUEOF(x)

  #define VP_VCBVINT_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VCBVINT,VIF2)\
    |_PER_FDEFAULT(VP,VCBVINT,FSCL2)\
    |_PER_FDEFAULT(VP,VCBVINT,VINT2)\
    |_PER_FDEFAULT(VP,VCBVINT,VIF1)\
    |_PER_FDEFAULT(VP,VCBVINT,VINT1)\
  )

  #define VP_VCBVINT_RMK(vif2,fscl2,vint2,vif1,vint1) (Uint32)(\
     _PER_FMK(VP,VCBVINT,VIF2,vif2)\
    |_PER_FMK(VP,VCBVINT,FSCL2,fscl2)\
    |_PER_FMK(VP,VCBVINT,VINT2,vint2)\
    |_PER_FMK(VP,VCBVINT,VIF1,vif1)\
    |_PER_FMK(VP,VCBVINT,VINT1,vint1)\
  )

  #define _VP_VCBVINT_FGET(N,FIELD)\
    _PER_FGET(_VP_VCBVINT##N##_ADDR,VP,VCBVINT,##FIELD)

  #define _VP_VCBVINT_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VCBVINT##N##_ADDR,VP,VCBVINT,##FIELD,field)

  #define _VP_VCBVINT_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VCBVINT##N##_ADDR,VP,VCBVINT,##FIELD,##SYM)

  #define _VP_VCBVINT0_FGET(FIELD)   _VP_VCBVINT_FGET(0,##FIELD)
  #define _VP_VCBVINT1_FGET(FIELD)   _VP_VCBVINT_FGET(1,##FIELD)
  #define _VP_VCBVINT2_FGET(FIELD)   _VP_VCBVINT_FGET(2,##FIELD)

  #define _VP_VCBVINT0_FSET(FIELD,f)   _VP_VCBVINT_FSET(0,##FIELD,f)
  #define _VP_VCBVINT1_FSET(FIELD,f)   _VP_VCBVINT_FSET(1,##FIELD,f)
  #define _VP_VCBVINT2_FSET(FIELD,f)   _VP_VCBVINT_FSET(2,##FIELD,f)

  #define _VP_VCBVINT0_FSETS(FIELD,SYM)   _VP_VCBVINT_FSETS(0,##FIELD,##SYM)
  #define _VP_VCBVINT1_FSETS(FIELD,SYM)   _VP_VCBVINT_FSETS(1,##FIELD,##SYM)
  #define _VP_VCBVINT2_FSETS(FIELD,SYM)   _VP_VCBVINT_FSETS(2,##FIELD,##SYM)
 #endif

/******************************************************************************\
* _____________________
* |                   |
* |  V C B T H R L D  |
* |___________________|
*
* VCBTHRLD0    -  Video Port 0 Video Capture B Threshold
* VCBTHRLD1    -  Video Port 1 Video Capture B Threshold
* VCBTHRLD2    -  Video Port 2 Video Capture B Threshold
*
* Defined only for DM642
*
* FIELDS (msb -> lsb)
* (rw) VCTHRLD2
* (rw) VCTHRLD1
*
\******************************************************************************/
 #if (CHIP_DM642)
  #define _VP_VCBTHRLD_OFFSET           87
  #define _VP_VCBTHRLD_OFFSETB           7

  #define _VP_VCBTHRLD0_ADDR   (_VP_BASE_PORT0 + 4*_VP_VCBTHRLD_OFFSET)
  #define _VP_VCBTHRLD1_ADDR   (_VP_BASE_PORT1 + 4*_VP_VCBTHRLD_OFFSET)
  #define _VP_VCBTHRLD2_ADDR   (_VP_BASE_PORT2 + 4*_VP_VCBTHRLD_OFFSET)

  #define _VP_VCBTHRLD0_ADDRB   (_VP_BASE_CHBPORT0 + 4*_VP_VCBTHRLD_OFFSETB)
  #define _VP_VCBTHRLD1_ADDRB   (_VP_BASE_CHBPORT1 + 4*_VP_VCBTHRLD_OFFSETB)
  #define _VP_VCBTHRLD2_ADDRB   (_VP_BASE_CHBPORT2 + 4*_VP_VCBTHRLD_OFFSETB)

  #define _VP_VCBTHRLD_VCTHRLD2_MASK         0x03FF0000u
  #define _VP_VCBTHRLD_VCTHRLD2_SHIFT        0x00000010u
  #define  VP_VCBTHRLD_VCTHRLD2_DEFAULT      0x00000000u
  #define  VP_VCBTHRLD_VCTHRLD2_OF(x)        _VALUEOF(x)

  #define _VP_VCBTHRLD_VCTHRLD1_MASK         0x000003FFu
  #define _VP_VCBTHRLD_VCTHRLD1_SHIFT        0x00000000u
  #define  VP_VCBTHRLD_VCTHRLD1_DEFAULT      0x00000000u
  #define  VP_VCBTHRLD_VCTHRLD1_OF(x)        _VALUEOF(x)

  #define  VP_VCBTHRLD_OF(x)            _VALUEOF(x)

  #define VP_VCBTHRLD_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VCBTHRLD,VCTHRLD2)\
    |_PER_FDEFAULT(VP,VCBTHRLD,VCTHRLD1)\
  )

  #define VP_VCBTHRLD_RMK(vcthrld2,vcthrld1) (Uint32)(\
     _PER_FMK(VP,VCBTHRLD,VCTHRLD2,vcthrld2)\
    |_PER_FMK(VP,VCBTHRLD,VCTHRLD1,vcthrld1)\
  )

  #define _VP_VCBTHRLD_FGET(N,FIELD)\
    _PER_FGET(_VP_VCBTHRLD##N##_ADDR,VP,VCBTHRLD,##FIELD)

  #define _VP_VCBTHRLD_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VCBTHRLD##N##_ADDR,VP,VCBTHRLD,##FIELD,field)

  #define _VP_VCBTHRLD_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VCBTHRLD##N##_ADDR,VP,VCBTHRLD,##FIELD,##SYM)

  #define _VP_VCBTHRLD0_FGET(FIELD)   _VP_VCBTHRLD_FGET(0,##FIELD)
  #define _VP_VCBTHRLD1_FGET(FIELD)   _VP_VCBTHRLD_FGET(1,##FIELD)
  #define _VP_VCBTHRLD2_FGET(FIELD)   _VP_VCBTHRLD_FGET(2,##FIELD)

  #define _VP_VCBTHRLD0_FSET(FIELD,f)   _VP_VCBTHRLD_FSET(0,##FIELD,f)
  #define _VP_VCBTHRLD1_FSET(FIELD,f)   _VP_VCBTHRLD_FSET(1,##FIELD,f)
  #define _VP_VCBTHRLD2_FSET(FIELD,f)   _VP_VCBTHRLD_FSET(2,##FIELD,f)

  #define _VP_VCBTHRLD0_FSETS(FIELD,SYM)   _VP_VCBTHRLD_FSETS(0,##FIELD,##SYM)
  #define _VP_VCBTHRLD1_FSETS(FIELD,SYM)   _VP_VCBTHRLD_FSETS(1,##FIELD,##SYM)
  #define _VP_VCBTHRLD2_FSETS(FIELD,SYM)   _VP_VCBTHRLD_FSETS(2,##FIELD,##SYM)
 #endif

/******************************************************************************\
* _____________________
* |                   |
* |  V C B E V T C T  |
* |___________________|
*
* VCBEVTCT0    -  Video Port 0 Video Capture B Event Count
* VCBEVTCT1    -  Video Port 1 Video Capture B Event Count
* VCBEVTCT2    -  Video Port 2 Video Capture B Event Count
*
* Defined only for DM642
*
* FIELDS (msb -> lsb)
* (rw) CAPEVTCT2
* (rw) CAPEVTCT1
*
\******************************************************************************/
 #if (CHIP_DM642)
  #define _VP_VCBEVTCT_OFFSET           88
  #define _VP_VCBEVTCT_OFFSETB           8

  #define _VP_VCBEVTCT0_ADDR   (_VP_BASE_PORT0 + 4*_VP_VCBEVTCT_OFFSET)
  #define _VP_VCBEVTCT1_ADDR   (_VP_BASE_PORT1 + 4*_VP_VCBEVTCT_OFFSET)
  #define _VP_VCBEVTCT2_ADDR   (_VP_BASE_PORT2 + 4*_VP_VCBEVTCT_OFFSET)

  #define _VP_VCBEVTCT0_ADDRB   (_VP_BASE_CHBPORT0 + 4*_VP_VCBEVTCT_OFFSETB)
  #define _VP_VCBEVTCT1_ADDRB   (_VP_BASE_CHBPORT1 + 4*_VP_VCBEVTCT_OFFSETB)
  #define _VP_VCBEVTCT2_ADDRB   (_VP_BASE_CHBPORT2 + 4*_VP_VCBEVTCT_OFFSETB)

  #define _VP_VCBEVTCT_CAPEVTCT2_MASK         0x0FFF0000u
  #define _VP_VCBEVTCT_CAPEVTCT2_SHIFT        0x00000010u
  #define  VP_VCBEVTCT_CAPEVTCT2_DEFAULT      0x00000000u
  #define  VP_VCBEVTCT_CAPEVTCT2_OF(x)        _VALUEOF(x)

  #define _VP_VCBEVTCT_CAPEVTCT1_MASK         0x00000FFFu
  #define _VP_VCBEVTCT_CAPEVTCT1_SHIFT        0x00000000u
  #define  VP_VCBEVTCT_CAPEVTCT1_DEFAULT      0x00000000u
  #define  VP_VCBEVTCT_CAPEVTCT1_OF(x)        _VALUEOF(x)

  #define  VP_VCBEVTCT_OF(x)            _VALUEOF(x)

  #define VP_VCBEVTCT_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VCBEVTCT,CAPEVTCT2)\
    |_PER_FDEFAULT(VP,VCBEVTCT,CAPEVTCT1)\
  )

  #define VP_VCBEVTCT_RMK(capevtct2,capevtct1) (Uint32)(\
     _PER_FMK(VP,VCBEVTCT,CAPEVTCT2,capevtct2)\
    |_PER_FMK(VP,VCBEVTCT,CAPEVTCT1,capevtct1)\
  )

  #define _VP_VCBEVTCT_FGET(N,FIELD)\
    _PER_FGET(_VP_VCBEVTCT##N##_ADDR,VP,VCBEVTCT,##FIELD)

  #define _VP_VCBEVTCT_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VCBEVTCT##N##_ADDR,VP,VCBEVTCT,##FIELD,field)

  #define _VP_VCBEVTCT_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VCBEVTCT##N##_ADDR,VP,VCBEVTCT,##FIELD,##SYM)

  #define _VP_VCBEVTCT0_FGET(FIELD)   _VP_VCBEVTCT_FGET(0,##FIELD)
  #define _VP_VCBEVTCT1_FGET(FIELD)   _VP_VCBEVTCT_FGET(1,##FIELD)
  #define _VP_VCBEVTCT2_FGET(FIELD)   _VP_VCBEVTCT_FGET(2,##FIELD)

  #define _VP_VCBEVTCT0_FSET(FIELD,f)   _VP_VCBEVTCT_FSET(0,##FIELD,f)
  #define _VP_VCBEVTCT1_FSET(FIELD,f)   _VP_VCBEVTCT_FSET(1,##FIELD,f)
  #define _VP_VCBEVTCT2_FSET(FIELD,f)   _VP_VCBEVTCT_FSET(2,##FIELD,f)

  #define _VP_VCBEVTCT0_FSETS(FIELD,SYM)   _VP_VCBEVTCT_FSETS(0,##FIELD,##SYM)
  #define _VP_VCBEVTCT1_FSETS(FIELD,SYM)   _VP_VCBEVTCT_FSETS(1,##FIELD,##SYM)
  #define _VP_VCBEVTCT2_FSETS(FIELD,SYM)   _VP_VCBEVTCT_FSETS(2,##FIELD,##SYM)
 #endif

/******************************************************************************\
* _____________________
* |                   |
* |  T S I C T L      |
* |___________________|
*
* TSICTL0 -  Video Port 0 Transport Stream Interface Capture Control
* TSICTL1 -  Video Port 1 Transport Stream Interface Capture Control
* TSICTL2 -  Video Port 2 Transport Stream Interface Capture Control
*
* FIELDS (msb -> lsb)
* (rw) ENSTC
* (rw) TCKEN
* (rw) STEN
* (rw) CTMODE
* (rw) ERRFILT
*
\******************************************************************************/
  #define _VP_TSICTL_OFFSET           96

  #define _VP_TSICTL0_ADDR   (_VP_BASE_PORT0 + 4*_VP_TSICTL_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSICTL1_ADDR   (_VP_BASE_PORT1 + 4*_VP_TSICTL_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSICTL2_ADDR   (_VP_BASE_PORT2 + 4*_VP_TSICTL_OFFSET)
 #endif


  #define _VP_TSICTL_ENSTC_MASK        0x00000020u
  #define _VP_TSICTL_ENSTC_SHIFT       0x00000005u
  #define  VP_TSICTL_ENSTC_DEFAULT     0x00000000u
  #define  VP_TSICTL_ENSTC_OF(x)       _VALUEOF(x)
  #define  VP_TSICTL_ENSTC_HALTED      0x00000000u
  #define  VP_TSICTL_ENSTC_CLKED       0x00000001u

  #define _VP_TSICTL_TCKEN_MASK        0x00000010u
  #define _VP_TSICTL_TCKEN_SHIFT       0x00000004u
  #define  VP_TSICTL_TCKEN_DEFAULT     0x00000000u
  #define  VP_TSICTL_TCKEN_OF(x)       _VALUEOF(x)
  #define  VP_TSICTL_TCKEN_DISABLE     0x00000000u
  #define  VP_TSICTL_TCKEN_SET         0x00000001u

  #define _VP_TSICTL_STEN_MASK        0x00000008u
  #define _VP_TSICTL_STEN_SHIFT       0x00000003u
  #define  VP_TSICTL_STEN_DEFAULT     0x00000000u
  #define  VP_TSICTL_STEN_OF(x)       _VALUEOF(x)
  #define  VP_TSICTL_STEN_DISABLE     0x00000000u
  #define  VP_TSICTL_STEN_SET         0x00000001u

  #define _VP_TSICTL_CTMODE_MASK        0x00000004u
  #define _VP_TSICTL_CTMODE_SHIFT       0x00000002u
  #define  VP_TSICTL_CTMODE_DEFAULT     0x00000000u
  #define  VP_TSICTL_CTMODE_OF(x)       _VALUEOF(x)
  #define  VP_TSICTL_CTMODE_90KHZ       0x00000000u
  #define  VP_TSICTL_CTMODE_STCLK       0x00000001u

  #define _VP_TSICTL_ERRFILT_MASK        0x00000002u
  #define _VP_TSICTL_ERRFILT_SHIFT       0x00000001u
  #define  VP_TSICTL_ERRFILT_DEFAULT     0x00000000u
  #define  VP_TSICTL_ERRFILT_OF(x)       _VALUEOF(x)
  #define  VP_TSICTL_ERRFILT_ACCEPT      0x00000000u
  #define  VP_TSICTL_ERRFILT_REJECT      0x00000001u

  #define  VP_TSICTL_OF(x)            _VALUEOF(x)

  #define VP_TSICTL_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,TSICTL,ENSTC)\
    |_PER_FDEFAULT(VP,TSICTL,TCKEN)\
    |_PER_FDEFAULT(VP,TSICTL,STEN)\
    |_PER_FDEFAULT(VP,TSICTL,CTMODE)\
    |_PER_FDEFAULT(VP,TSICTL,ERRFILT)\
  )

  #define VP_TSICTL_RMK(enstc,tcken,sten,ctmode,errfilt) (Uint32)(\
     _PER_FMK(VP,TSICTL,ENSTC,enstc)\
    |_PER_FMK(VP,TSICTL,TCKEN,tcken)\
    |_PER_FMK(VP,TSICTL,STEN,sten)\
    |_PER_FMK(VP,TSICTL,CTMODE,ctmode)\
    |_PER_FMK(VP,TSICTL,ERRFILT,errfilt)\
  )

  #define _VP_TSICTL_FGET(N,FIELD)\
    _PER_FGET(_VP_TSICTL##N##_ADDR,VP,TSICTL,##FIELD)

  #define _VP_TSICTL_FSET(N,FIELD,field)\
    _PER_FSET(_VP_TSICTL##N##_ADDR,VP,TSICTL,##FIELD,field)

  #define _VP_TSICTL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_TSICTL##N##_ADDR,VP,TSICTL,##FIELD,##SYM)

  #define _VP_TSICTL0_FGET(FIELD)   _VP_TSICTL_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSICTL1_FGET(FIELD)   _VP_TSICTL_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSICTL2_FGET(FIELD)   _VP_TSICTL_FGET(2,##FIELD)
 #endif


  #define _VP_TSICTL0_FSET(FIELD,f)   _VP_TSICTL_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSICTL1_FSET(FIELD,f)   _VP_TSICTL_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSICTL2_FSET(FIELD,f)   _VP_TSICTL_FSET(2,##FIELD,f)
 #endif


  #define _VP_TSICTL0_FSETS(FIELD,SYM)   _VP_TSICTL_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSICTL1_FSETS(FIELD,SYM)   _VP_TSICTL_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSICTL2_FSETS(FIELD,SYM)   _VP_TSICTL_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* ___________________________
* |                         |
* |  T S I C L K I N I T L  |
* |_________________________|
*
* TSICLKINITL0  -  Video Port 0 Transport Stream Interface Clock Initialization LSB
* TSICLKINITL1  -  Video Port 1 Transport Stream Interface Clock Initialization LSB
* TSICLKINITL2  -  Video Port 2 Transport Stream Interface Clock Initialization LSB
*
* FIELDS (msb -> lsb)
* (rw) INPCR 
*
\******************************************************************************/
  #define _VP_TSICLKINITL_OFFSET           97

  #define _VP_TSICLKINITL0_ADDR   (_VP_BASE_PORT0 + 4*_VP_TSICLKINITL_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSICLKINITL1_ADDR   (_VP_BASE_PORT1 + 4*_VP_TSICLKINITL_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSICLKINITL2_ADDR   (_VP_BASE_PORT2 + 4*_VP_TSICLKINITL_OFFSET)
 #endif


  #define _VP_TSICLKINITL_INPCR_MASK         0xFFFFFFFFu
  #define _VP_TSICLKINITL_INPCR_SHIFT        0x00000000u
  #define  VP_TSICLKINITL_INPCR_DEFAULT      0x00000000u
  #define  VP_TSICLKINITL_INPCR_OF(x)        _VALUEOF(x)

  #define  VP_TSICLKINITL_OF(x)            _VALUEOF(x)

  #define VP_TSICLKINITL_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,TSICLKINITL,INPCR)\
  )

  #define VP_TSICLKINITL_RMK(inpcr) (Uint32)(\
     _PER_FMK(VP,TSICLKINITL,INPCR,inpcr)\
  )

  #define _VP_TSICLKINITL_FGET(N,FIELD)\
    _PER_FGET(_VP_TSICLKINITL##N##_ADDR,VP,TSICLKINITL,##FIELD)

  #define _VP_TSICLKINITL_FSET(N,FIELD,field)\
    _PER_FSET(_VP_TSICLKINITL##N##_ADDR,VP,TSICLKINITL,##FIELD,field)

  #define _VP_TSICLKINITL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_TSICLKINITL##N##_ADDR,VP,TSICLKINITL,##FIELD,##SYM)

  #define _VP_TSICLKINITL0_FGET(FIELD)   _VP_TSICLKINITL_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSICLKINITL1_FGET(FIELD)   _VP_TSICLKINITL_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSICLKINITL2_FGET(FIELD)   _VP_TSICLKINITL_FGET(2,##FIELD)
 #endif


  #define _VP_TSICLKINITL0_FSET(FIELD,f)   _VP_TSICLKINITL_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSICLKINITL1_FSET(FIELD,f)   _VP_TSICLKINITL_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSICLKINITL2_FSET(FIELD,f)   _VP_TSICLKINITL_FSET(2,##FIELD,f)
 #endif


  #define _VP_TSICLKINITL0_FSETS(FIELD,SYM)   _VP_TSICLKINITL_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSICLKINITL1_FSETS(FIELD,SYM)   _VP_TSICLKINITL_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSICLKINITL2_FSETS(FIELD,SYM)   _VP_TSICLKINITL_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* ___________________________
* |                         |
* |  T S I C L K I N I T M  |
* |_________________________|
*
* TSICLKINITM0  -  Video Port 0 Transport Stream Interface Clock Initialization MSB
* TSICLKINITM1  -  Video Port 1 Transport Stream Interface Clock Initialization MSB
* TSICLKINITM2  -  Video Port 2 Transport Stream Interface Clock Initialization MSB
*
* FIELDS (msb -> lsb)
* (rw) INPCRE 
* (rw) INPCRM 
*
\******************************************************************************/
  #define _VP_TSICLKINITM_OFFSET           98

  #define _VP_TSICLKINITM0_ADDR   (_VP_BASE_PORT0 + 4*_VP_TSICLKINITM_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSICLKINITM1_ADDR   (_VP_BASE_PORT1 + 4*_VP_TSICLKINITM_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSICLKINITM2_ADDR   (_VP_BASE_PORT2 + 4*_VP_TSICLKINITM_OFFSET)
 #endif


  #define _VP_TSICLKINITM_INPCRE_MASK         0x000003FEu
  #define _VP_TSICLKINITM_INPCRE_SHIFT        0x00000001u
  #define  VP_TSICLKINITM_INPCRE_DEFAULT      0x00000000u
  #define  VP_TSICLKINITM_INPCRE_OF(x)        _VALUEOF(x)

  #define _VP_TSICLKINITM_INPCRM_MASK         0x00000001u
  #define _VP_TSICLKINITM_INPCRM_SHIFT        0x00000000u
  #define  VP_TSICLKINITM_INPCRM_DEFAULT      0x00000000u
  #define  VP_TSICLKINITM_INPCRM_OF(x)        _VALUEOF(x)

  #define  VP_TSICLKINITM_OF(x)            _VALUEOF(x)

  #define VP_TSICLKINITM_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,TSICLKINITM,INPCRE)\
    |_PER_FDEFAULT(VP,TSICLKINITM,INPCRM)\
  )

  #define VP_TSICLKINITM_RMK(inpcre,inpcrm) (Uint32)(\
     _PER_FMK(VP,TSICLKINITM,INPCRE,inpcre)\
    |_PER_FMK(VP,TSICLKINITM,INPCRM,inpcrm)\
  )

  #define _VP_TSICLKINITM_FGET(N,FIELD)\
    _PER_FGET(_VP_TSICLKINITM##N##_ADDR,VP,TSICLKINITM,##FIELD)

  #define _VP_TSICLKINITM_FSET(N,FIELD,field)\
    _PER_FSET(_VP_TSICLKINITM##N##_ADDR,VP,TSICLKINITM,##FIELD,field)

  #define _VP_TSICLKINITM_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_TSICLKINITM##N##_ADDR,VP,TSICLKINITM,##FIELD,##SYM)

  #define _VP_TSICLKINITM0_FGET(FIELD)   _VP_TSICLKINITM_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSICLKINITM1_FGET(FIELD)   _VP_TSICLKINITM_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSICLKINITM2_FGET(FIELD)   _VP_TSICLKINITM_FGET(2,##FIELD)
 #endif


  #define _VP_TSICLKINITM0_FSET(FIELD,f)   _VP_TSICLKINITM_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSICLKINITM1_FSET(FIELD,f)   _VP_TSICLKINITM_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSICLKINITM2_FSET(FIELD,f)   _VP_TSICLKINITM_FSET(2,##FIELD,f)
 #endif


  #define _VP_TSICLKINITM0_FSETS(FIELD,SYM)   _VP_TSICLKINITM_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSICLKINITM1_FSETS(FIELD,SYM)   _VP_TSICLKINITM_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSICLKINITM2_FSETS(FIELD,SYM)   _VP_TSICLKINITM_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _______________________
* |                     |
* |  T S I S T C L K L  |
* |_____________________|
*
* TSISTCLKL0    -  Video Port 0 Transport Stream Interface System Time Clock LSB
* TSISTCLKL1    -  Video Port 1 Transport Stream Interface System Time Clock LSB
* TSISTCLKL2    -  Video Port 2 Transport Stream Interface System Time Clock LSB
*
* FIELDS (msb -> lsb)
* (rw) PCR 
*
\******************************************************************************/
  #define _VP_TSISTCLKL_OFFSET           99

  #define _VP_TSISTCLKL0_ADDR   (_VP_BASE_PORT0 + 4*_VP_TSISTCLKL_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSISTCLKL1_ADDR   (_VP_BASE_PORT1 + 4*_VP_TSISTCLKL_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSISTCLKL2_ADDR   (_VP_BASE_PORT2 + 4*_VP_TSISTCLKL_OFFSET)
 #endif


  #define _VP_TSISTCLKL_PCR_MASK         0xFFFFFFFFu
  #define _VP_TSISTCLKL_PCR_SHIFT        0x00000000u
  #define  VP_TSISTCLKL_PCR_DEFAULT      0x00000000u
  #define  VP_TSISTCLKL_PCR_OF(x)        _VALUEOF(x)

  #define  VP_TSISTCLKL_OF(x)            _VALUEOF(x)

  #define VP_TSISTCLKL_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,TSISTCLKL,PCR)\
  )

  #define VP_TSISTCLKL_RMK(pcr) (Uint32)(\
     _PER_FMK(VP,TSISTCLKL,PCR,pcr)\
  )

  #define _VP_TSISTCLKL_FGET(N,FIELD)\
    _PER_FGET(_VP_TSISTCLKL##N##_ADDR,VP,TSISTCLKL,##FIELD)

  #define _VP_TSISTCLKL_FSET(N,FIELD,field)\
    _PER_FSET(_VP_TSISTCLKL##N##_ADDR,VP,TSISTCLKL,##FIELD,field)

  #define _VP_TSISTCLKL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_TSISTCLKL##N##_ADDR,VP,TSISTCLKL,##FIELD,##SYM)

  #define _VP_TSISTCLKL0_FGET(FIELD)   _VP_TSISTCLKL_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSISTCLKL1_FGET(FIELD)   _VP_TSISTCLKL_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSISTCLKL2_FGET(FIELD)   _VP_TSISTCLKL_FGET(2,##FIELD)
 #endif


  #define _VP_TSISTCLKL0_FSET(FIELD,f)   _VP_TSISTCLKL_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSISTCLKL1_FSET(FIELD,f)   _VP_TSISTCLKL_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSISTCLKL2_FSET(FIELD,f)   _VP_TSISTCLKL_FSET(2,##FIELD,f)
 #endif


  #define _VP_TSISTCLKL0_FSETS(FIELD,SYM)   _VP_TSISTCLKL_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSISTCLKL1_FSETS(FIELD,SYM)   _VP_TSISTCLKL_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSISTCLKL2_FSETS(FIELD,SYM)   _VP_TSISTCLKL_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _______________________
* |                     |
* |  T S I S T C L K M  |
* |_____________________|
*
* TSISTCLKM0 -  Video Port 0 Transport Stream Interface System Time Clock  MSB
* TSISTCLKM1 -  Video Port 1 Transport Stream Interface System Time Clock  MSB
* TSISTCLKM2 -  Video Port 2 Transport Stream Interface System Time Clock  MSB
*
* FIELDS (msb -> lsb)
* (rw) PCRE 
* (rw) PCRM 
*
\******************************************************************************/
  #define _VP_TSISTCLKM_OFFSET           100

  #define _VP_TSISTCLKM0_ADDR   (_VP_BASE_PORT0 + 4*_VP_TSISTCLKM_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSISTCLKM1_ADDR   (_VP_BASE_PORT1 + 4*_VP_TSISTCLKM_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSISTCLKM2_ADDR   (_VP_BASE_PORT2 + 4*_VP_TSISTCLKM_OFFSET)
 #endif


  #define _VP_TSISTCLKM_PCRE_MASK         0x000003FEu
  #define _VP_TSISTCLKM_PCRE_SHIFT        0x00000001u
  #define  VP_TSISTCLKM_PCRE_DEFAULT      0x00000000u
  #define  VP_TSISTCLKM_PCRE_OF(x)        _VALUEOF(x)

  #define _VP_TSISTCLKM_PCRM_MASK         0x00000001u
  #define _VP_TSISTCLKM_PCRM_SHIFT        0x00000000u
  #define  VP_TSISTCLKM_PCRM_DEFAULT      0x00000000u
  #define  VP_TSISTCLKM_PCRM_OF(x)        _VALUEOF(x)

  #define  VP_TSISTCLKM_OF(x)            _VALUEOF(x)

  #define VP_TSISTCLKM_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,TSISTCLKM,PCRE)\
    |_PER_FDEFAULT(VP,TSISTCLKM,PCRM)\
  )

  #define VP_TSISTCLKM_RMK(pcre,pcrm) (Uint32)(\
     _PER_FMK(VP,TSISTCLKM,PCRE,pcre)\
    |_PER_FMK(VP,TSISTCLKM,PCRM,pcrm)\
  )

  #define _VP_TSISTCLKM_FGET(N,FIELD)\
    _PER_FGET(_VP_TSISTCLKM##N##_ADDR,VP,TSISTCLKM,##FIELD)

  #define _VP_TSISTCLKM_FSET(N,FIELD,field)\
    _PER_FSET(_VP_TSISTCLKM##N##_ADDR,VP,TSISTCLKM,##FIELD,field)

  #define _VP_TSISTCLKM_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_TSISTCLKM##N##_ADDR,VP,TSISTCLKM,##FIELD,##SYM)

  #define _VP_TSISTCLKM0_FGET(FIELD)   _VP_TSISTCLKM_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSISTCLKM1_FGET(FIELD)   _VP_TSISTCLKM_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSISTCLKM2_FGET(FIELD)   _VP_TSISTCLKM_FGET(2,##FIELD)
 #endif


  #define _VP_TSISTCLKM0_FSET(FIELD,f)   _VP_TSISTCLKM_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSISTCLKM1_FSET(FIELD,f)   _VP_TSISTCLKM_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSISTCLKM2_FSET(FIELD,f)   _VP_TSISTCLKM_FSET(2,##FIELD,f)
 #endif


  #define _VP_TSISTCLKM0_FSETS(FIELD,SYM)   _VP_TSISTCLKM_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSISTCLKM1_FSETS(FIELD,SYM)   _VP_TSISTCLKM_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSISTCLKM2_FSETS(FIELD,SYM)   _VP_TSISTCLKM_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _______________________
* |                     |
* |  T S I S T C M P L  |
* |_____________________|
*
* TSISTCMPL0 -  Video Port 0 Transport Stream Interface STC Compare LSB
* TSISTCMPL1 -  Video Port 1 Transport Stream Interface STC Compare LSB
* TSISTCMPL2 -  Video Port 2 Transport Stream Interface STC Compare LSB
*
* FIELDS (msb -> lsb)
* (r) ATC 
*
\******************************************************************************/
  #define _VP_TSISTCMPL_OFFSET           101

  #define _VP_TSISTCMPL0_ADDR   (_VP_BASE_PORT0 + 4*_VP_TSISTCMPL_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSISTCMPL1_ADDR   (_VP_BASE_PORT1 + 4*_VP_TSISTCMPL_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSISTCMPL2_ADDR   (_VP_BASE_PORT2 + 4*_VP_TSISTCMPL_OFFSET)
 #endif


  #define _VP_TSISTCMPL_ATC_MASK         0xFFFFFFFFu
  #define _VP_TSISTCMPL_ATC_SHIFT        0x00000000u
  #define  VP_TSISTCMPL_ATC_DEFAULT      0x00000000u
  #define  VP_TSISTCMPL_ATC_OF(x)        _VALUEOF(x)

  #define  VP_TSISTCMPL_OF(x)            _VALUEOF(x)

  #define VP_TSISTCMPL_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,TSISTCMPL,ATC)\
  )

  #define VP_TSISTCMPL_RMK(atc) (Uint32)(\
     _PER_FMK(VP,TSISTCMPL,ATC,atc)\
  )

  #define _VP_TSISTCMPL_FGET(N,FIELD)\
    _PER_FGET(_VP_TSISTCMPL##N##_ADDR,VP,TSISTCMPL,##FIELD)

  #define _VP_TSISTCMPL_FSET(N,FIELD,field)\
    _PER_FSET(_VP_TSISTCMPL##N##_ADDR,VP,TSISTCMPL,##FIELD,field)

  #define _VP_TSISTCMPL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_TSISTCMPL##N##_ADDR,VP,TSISTCMPL,##FIELD,##SYM)

  #define _VP_TSISTCMPL0_FGET(FIELD)   _VP_TSISTCMPL_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSISTCMPL1_FGET(FIELD)   _VP_TSISTCMPL_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSISTCMPL2_FGET(FIELD)   _VP_TSISTCMPL_FGET(2,##FIELD)
 #endif


  #define _VP_TSISTCMPL0_FSET(FIELD,f)   _VP_TSISTCMPL_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSISTCMPL1_FSET(FIELD,f)   _VP_TSISTCMPL_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSISTCMPL2_FSET(FIELD,f)   _VP_TSISTCMPL_FSET(2,##FIELD,f)
 #endif


  #define _VP_TSISTCMPL0_FSETS(FIELD,SYM)   _VP_TSISTCMPL_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSISTCMPL1_FSETS(FIELD,SYM)   _VP_TSISTCMPL_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSISTCMPL2_FSETS(FIELD,SYM)   _VP_TSISTCMPL_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _______________________
* |                     |
* |  T S I S T C M P M  |
* |_____________________|
*
* TSISTCMPM0    -  Video Port 0 Transport Stream Interface STC Compare MSB
* TSISTCMPM1    -  Video Port 1 Transport Stream Interface STC Compare MSB
* TSISTCMPM2    -  Video Port 2 Transport Stream Interface STC Compare MSB
*
* FIELDS (msb -> lsb)
* (rw) ATC
*
\******************************************************************************/
  #define _VP_TSISTCMPM_OFFSET           102

  #define _VP_TSISTCMPM0_ADDR   (_VP_BASE_PORT0 + 4*_VP_TSISTCMPM_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSISTCMPM1_ADDR   (_VP_BASE_PORT1 + 4*_VP_TSISTCMPM_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSISTCMPM2_ADDR   (_VP_BASE_PORT2 + 4*_VP_TSISTCMPM_OFFSET)
 #endif


  #define _VP_TSISTCMPM_ATC_MASK         0x00000001u
  #define _VP_TSISTCMPM_ATC_SHIFT        0x00000000u
  #define  VP_TSISTCMPM_ATC_DEFAULT      0x00000000u
  #define  VP_TSISTCMPM_ATC_OF(x)        _VALUEOF(x)

  #define  VP_TSISTCMPM_OF(x)            _VALUEOF(x)

  #define VP_TSISTCMPM_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,TSISTCMPM,ATC)\
  )

  #define VP_TSISTCMPM_RMK(atc) (Uint32)(\
     _PER_FMK(VP,TSISTCMPM,ATC,atc)\
  )

  #define _VP_TSISTCMPM_FGET(N,FIELD)\
    _PER_FGET(_VP_TSISTCMPM##N##_ADDR,VP,TSISTCMPM,##FIELD)

  #define _VP_TSISTCMPM_FSET(N,FIELD,field)\
    _PER_FSET(_VP_TSISTCMPM##N##_ADDR,VP,TSISTCMPM,##FIELD,field)

  #define _VP_TSISTCMPM_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_TSISTCMPM##N##_ADDR,VP,TSISTCMPM,##FIELD,##SYM)

  #define _VP_TSISTCMPM0_FGET(FIELD)   _VP_TSISTCMPM_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSISTCMPM1_FGET(FIELD)   _VP_TSISTCMPM_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSISTCMPM2_FGET(FIELD)   _VP_TSISTCMPM_FGET(2,##FIELD)
 #endif


  #define _VP_TSISTCMPM0_FSET(FIELD,f)   _VP_TSISTCMPM_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSISTCMPM1_FSET(FIELD,f)   _VP_TSISTCMPM_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSISTCMPM2_FSET(FIELD,f)   _VP_TSISTCMPM_FSET(2,##FIELD,f)
 #endif


  #define _VP_TSISTCMPM0_FSETS(FIELD,SYM)   _VP_TSISTCMPM_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSISTCMPM1_FSETS(FIELD,SYM)   _VP_TSISTCMPM_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSISTCMPM2_FSETS(FIELD,SYM)   _VP_TSISTCMPM_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _______________________
* |                     |
* |  T S I S T M S K L  |
* |_____________________|
*
* TSISTMSKL0 -  Video Port 0 Transport Stream Interface STC Compare Mask LSB
* TSISTMSKL1 -  Video Port 1 Transport Stream Interface STC Compare Mask LSB
* TSISTMSKL2 -  Video Port 2 Transport Stream Interface STC Compare Mask LSB
*
* FIELDS (msb -> lsb)
* (r) ATCM 
*
\******************************************************************************/
  #define _VP_TSISTMSKL_OFFSET           103

  #define _VP_TSISTMSKL0_ADDR   (_VP_BASE_PORT0 + 4*_VP_TSISTMSKL_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSISTMSKL1_ADDR   (_VP_BASE_PORT1 + 4*_VP_TSISTMSKL_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSISTMSKL2_ADDR   (_VP_BASE_PORT2 + 4*_VP_TSISTMSKL_OFFSET)
 #endif


  #define _VP_TSISTMSKL_ATCM_MASK         0xFFFFFFFFu
  #define _VP_TSISTMSKL_ATCM_SHIFT        0x00000000u
  #define  VP_TSISTMSKL_ATCM_DEFAULT      0x00000000u
  #define  VP_TSISTMSKL_ATCM_OF(x)        _VALUEOF(x)

  #define  VP_TSISTMSKL_OF(x)            _VALUEOF(x)

  #define VP_TSISTMSKL_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,TSISTMSKL,ATCM)\
  )

/**** read only bit field ****/
  #define VP_TSISTMSKL_RMK(atcm) (Uint32)(\
     _PER_FMK(VP,TSISTMSKL,ATCM,atcm)\
  )

  #define _VP_TSISTMSKL_FGET(N,FIELD)\
    _PER_FGET(_VP_TSISTMSKL##N##_ADDR,VP,TSISTMSKL,##FIELD)

  #define _VP_TSISTMSKL_FSET(N,FIELD,field)\
    _PER_FSET(_VP_TSISTMSKL##N##_ADDR,VP,TSISTMSKL,##FIELD,field)

  #define _VP_TSISTMSKL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_TSISTMSKL##N##_ADDR,VP,TSISTMSKL,##FIELD,##SYM)

  #define _VP_TSISTMSKL0_FGET(FIELD)   _VP_TSISTMSKL_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSISTMSKL1_FGET(FIELD)   _VP_TSISTMSKL_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSISTMSKL2_FGET(FIELD)   _VP_TSISTMSKL_FGET(2,##FIELD)
 #endif


  #define _VP_TSISTMSKL0_FSET(FIELD,f)   _VP_TSISTMSKL_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSISTMSKL1_FSET(FIELD,f)   _VP_TSISTMSKL_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSISTMSKL2_FSET(FIELD,f)   _VP_TSISTMSKL_FSET(2,##FIELD,f)
 #endif


  #define _VP_TSISTMSKL0_FSETS(FIELD,SYM)   _VP_TSISTMSKL_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSISTMSKL1_FSETS(FIELD,SYM)   _VP_TSISTMSKL_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSISTMSKL2_FSETS(FIELD,SYM)   _VP_TSISTMSKL_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _______________________
* |                     |
* |  T S I S T M S K M  |
* |_____________________|
*
* TSISTMSKM0 -  Video Port 0 Transport Stream Interface STC Compare Mask MSB
* TSISTMSKM1 -  Video Port 1 Transport Stream Interface STC Compare Mask MSB
* TSISTMSKM2 -  Video Port 2 Transport Stream Interface STC Compare Mask MSB
*
* FIELDS (msb -> lsb)
* (rw) ATCM
*
\******************************************************************************/
  #define _VP_TSISTMSKM_OFFSET           104

  #define _VP_TSISTMSKM0_ADDR   (_VP_BASE_PORT0 + 4*_VP_TSISTMSKM_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSISTMSKM1_ADDR   (_VP_BASE_PORT1 + 4*_VP_TSISTMSKM_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSISTMSKM2_ADDR   (_VP_BASE_PORT2 + 4*_VP_TSISTMSKM_OFFSET)
 #endif


  #define _VP_TSISTMSKM_ATCM_MASK         0x00000001u
  #define _VP_TSISTMSKM_ATCM_SHIFT        0x00000000u
  #define  VP_TSISTMSKM_ATCM_DEFAULT      0x00000000u
  #define  VP_TSISTMSKM_ATCM_OF(x)        _VALUEOF(x)

  #define  VP_TSISTMSKM_OF(x)            _VALUEOF(x)

  #define VP_TSISTMSKM_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,TSISTMSKM,ATCM)\
  )

  #define VP_TSISTMSKM_RMK(atcm) (Uint32)(\
     _PER_FMK(VP,TSISTMSKM,ATCM,atcm)\
  )

  #define _VP_TSISTMSKM_FGET(N,FIELD)\
    _PER_FGET(_VP_TSISTMSKM##N##_ADDR,VP,TSISTMSKM,##FIELD)

  #define _VP_TSISTMSKM_FSET(N,FIELD,field)\
    _PER_FSET(_VP_TSISTMSKM##N##_ADDR,VP,TSISTMSKM,##FIELD,field)

  #define _VP_TSISTMSKM_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_TSISTMSKM##N##_ADDR,VP,TSISTMSKM,##FIELD,##SYM)

  #define _VP_TSISTMSKM0_FGET(FIELD)   _VP_TSISTMSKM_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSISTMSKM1_FGET(FIELD)   _VP_TSISTMSKM_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSISTMSKM2_FGET(FIELD)   _VP_TSISTMSKM_FGET(2,##FIELD)
 #endif


  #define _VP_TSISTMSKM0_FSET(FIELD,f)   _VP_TSISTMSKM_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSISTMSKM1_FSET(FIELD,f)   _VP_TSISTMSKM_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSISTMSKM2_FSET(FIELD,f)   _VP_TSISTMSKM_FSET(2,##FIELD,f)
 #endif


  #define _VP_TSISTMSKM0_FSETS(FIELD,SYM)   _VP_TSISTMSKM_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSISTMSKM1_FSETS(FIELD,SYM)   _VP_TSISTMSKM_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSISTMSKM2_FSETS(FIELD,SYM)   _VP_TSISTMSKM_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _______________________
* |                     |
* |  T S I T I C K S    |
* |_____________________|
*
* TSITICKS0 -  Video Port 0 Transport Stream Interface STC Ticks Interrupt
* TSITICKS1 -  Video Port 1 Transport Stream Interface STC Ticks Interrupt
* TSITICKS2 -  Video Port 2 Transport Stream Interface STC Ticks Interrupt
*
* FIELDS (msb -> lsb)
* (rw) TICKCT
*
\******************************************************************************/
  #define _VP_TSITICKS_OFFSET           105

  #define _VP_TSITICKS0_ADDR   (_VP_BASE_PORT0 + 4*_VP_TSITICKS_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSITICKS1_ADDR   (_VP_BASE_PORT1 + 4*_VP_TSITICKS_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSITICKS2_ADDR   (_VP_BASE_PORT2 + 4*_VP_TSITICKS_OFFSET)
 #endif


  #define _VP_TSITICKS_TICKCT_MASK         0xFFFFFFFFu
  #define _VP_TSITICKS_TICKCT_SHIFT        0x00000000u
  #define  VP_TSITICKS_TICKCT_DEFAULT      0x00000000u
  #define  VP_TSITICKS_TICKCT_OF(x)        _VALUEOF(x)

  #define  VP_TSITICKS_OF(x)            _VALUEOF(x)

  #define VP_TSITICKS_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,TSITICKS,TICKCT)\
  )

  #define VP_TSITICKS_RMK(tickct) (Uint32)(\
     _PER_FMK(VP,TSITICKS,TICKCT,tickct)\
  )

  #define _VP_TSITICKS_FGET(N,FIELD)\
    _PER_FGET(_VP_TSITICKS##N##_ADDR,VP,TSITICKS,##FIELD)

  #define _VP_TSITICKS_FSET(N,FIELD,field)\
    _PER_FSET(_VP_TSITICKS##N##_ADDR,VP,TSITICKS,##FIELD,field)

  #define _VP_TSITICKS_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_TSITICKS##N##_ADDR,VP,TSITICKS,##FIELD,##SYM)

  #define _VP_TSITICKS0_FGET(FIELD)   _VP_TSITICKS_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSITICKS1_FGET(FIELD)   _VP_TSITICKS_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSITICKS2_FGET(FIELD)   _VP_TSITICKS_FGET(2,##FIELD)
 #endif


  #define _VP_TSITICKS0_FSET(FIELD,f)   _VP_TSITICKS_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSITICKS1_FSET(FIELD,f)   _VP_TSITICKS_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSITICKS2_FSET(FIELD,f)   _VP_TSITICKS_FSET(2,##FIELD,f)
 #endif


  #define _VP_TSITICKS0_FSETS(FIELD,SYM)   _VP_TSITICKS_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_TSITICKS1_FSETS(FIELD,SYM)   _VP_TSITICKS_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_TSITICKS2_FSETS(FIELD,SYM)   _VP_TSITICKS_FSETS(2,##FIELD,##SYM)
 #endif



/******************************************************************************\
* _____________________
* |                   |
* |  V D S T A T      |
* |___________________|
*
* VDSTAT0 -  Video Port 0 Video Display Status
* VDSTAT1 -  Video Port 1 Video Display Status
* VDSTAT2 -  Video Port 2 Video Display Status
*
* FIELDS (msb -> lsb)
*
* (rc) FRMD
* (rc) F2D
* (rc) F1D
* (r)  VDYPOS
* (r)  VBLNK
* (r)  VDFLD
* (r)  VDXPOS
*
\******************************************************************************/
  #define _VP_VDSTAT_OFFSET           128

  #define _VP_VDSTAT0_ADDR   (_VP_BASE_PORT0 + 4*_VP_VDSTAT_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDSTAT1_ADDR   (_VP_BASE_PORT1 + 4*_VP_VDSTAT_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDSTAT2_ADDR   (_VP_BASE_PORT2 + 4*_VP_VDSTAT_OFFSET)
 #endif


  #define _VP_VDSTAT_FRMD_MASK        0x40000000u
  #define _VP_VDSTAT_FRMD_SHIFT       0x0000001Eu
  #define  VP_VDSTAT_FRMD_DEFAULT     0x00000000u
  #define  VP_VDSTAT_FRMD_OF(x)       _VALUEOF(x)
  #define  VP_VDSTAT_FRMD_NONE        0x00000000u
  #define  VP_VDSTAT_FRMD_DISPLAYED   0x00000001u
  #define  VP_VDSTAT_FRMD_CLEAR       0x00000001u

  #define _VP_VDSTAT_F2D_MASK        0x20000000u
  #define _VP_VDSTAT_F2D_SHIFT       0x0000001Du
  #define  VP_VDSTAT_F2D_DEFAULT     0x00000000u
  #define  VP_VDSTAT_F2D_OF(x)       _VALUEOF(x)
  #define  VP_VDSTAT_F2D_NONE        0x00000000u
  #define  VP_VDSTAT_F2D_DISPLAYED    0x00000001u
  #define  VP_VDSTAT_F2D_CLEAR       0x00000001u

  #define _VP_VDSTAT_F1D_MASK        0x10000000u
  #define _VP_VDSTAT_F1D_SHIFT       0x0000001Cu
  #define  VP_VDSTAT_F1D_DEFAULT     0x00000000u
  #define  VP_VDSTAT_F1D_OF(x)       _VALUEOF(x)
  #define  VP_VDSTAT_F1D_NONE        0x00000000u
  #define  VP_VDSTAT_F1D_DISPLAYED   0x00000001u
  #define  VP_VDSTAT_F1D_CLEAR       0x00000001u

  #define _VP_VDSTAT_VDYPOS_MASK        0x0FFF0000u
  #define _VP_VDSTAT_VDYPOS_SHIFT       0x00000010u
  #define  VP_VDSTAT_VDYPOS_DEFAULT     0x00000000u
  #define  VP_VDSTAT_VDYPOS_OF(x)       _VALUEOF(x)

  #define _VP_VDSTAT_VBLNK_MASK        0x00002000u
  #define _VP_VDSTAT_VBLNK_SHIFT       0x0000000Du
  #define  VP_VDSTAT_VBLNK_DEFAULT     0x00000000u
  #define  VP_VDSTAT_VBLNK_OF(x)       _VALUEOF(x)
  #define  VP_VDSTAT_VBLNK_EMPTY       0x00000000u
  #define  VP_VDSTAT_VBLNK_NOTEMPTY    0x00000001u

  #define _VP_VDSTAT_VDFLD_MASK        0x00001000u
  #define _VP_VDSTAT_VDFLD_SHIFT       0x0000000Cu
  #define  VP_VDSTAT_VDFLD_DEFAULT     0x00000000u
  #define  VP_VDSTAT_VDFLD_OF(x)       _VALUEOF(x)
  #define  VP_VDSTAT_VDFLD_FIELD1ACT   0x00000000u
  #define  VP_VDSTAT_VDFLD_FIELD2ACT   0x00000001u

  #define _VP_VDSTAT_VDXPOS_MASK        0x00000FFFu
  #define _VP_VDSTAT_VDXPOS_SHIFT       0x00000000u
  #define  VP_VDSTAT_VDXPOS_DEFAULT     0x00000000u
  #define  VP_VDSTAT_VDXPOS_OF(x)       _VALUEOF(x)


  #define  VP_VDSTAT_OF(x)            _VALUEOF(x)

  #define VP_VDSTAT_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VDSTAT,FRMD)\
    |_PER_FDEFAULT(VP,VDSTAT,F2D)\
    |_PER_FDEFAULT(VP,VDSTAT,F1D)\
    |_PER_FDEFAULT(VP,VDSTAT,VDYPOS)\
    |_PER_FDEFAULT(VP,VDSTAT,VBLNK)\
    |_PER_FDEFAULT(VP,VDSTAT,VDFLD)\
    |_PER_FDEFAULT(VP,VDSTAT,VDXPOS)\
  )

  #define VP_VDSTAT_RMK(frmd,f2d,f1d) (Uint32)(\
     _PER_FMK(VP,VDSTAT,FRMD,frmd)\
    |_PER_FMK(VP,VDSTAT,F2D,f2d)\
    |_PER_FMK(VP,VDSTAT,F1D,f1d)\
  )

  #define _VP_VDSTAT_FGET(N,FIELD)\
    _PER_FGET(_VP_VDSTAT##N##_ADDR,VP,VDSTAT,##FIELD)

  #define _VP_VDSTAT_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VDSTAT##N##_ADDR,VP,VDSTAT,##FIELD,field)

  #define _VP_VDSTAT_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VDSTAT##N##_ADDR,VP,VDSTAT,##FIELD,##SYM)

  #define _VP_VDSTAT0_FGET(FIELD)   _VP_VDSTAT_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDSTAT1_FGET(FIELD)   _VP_VDSTAT_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDSTAT2_FGET(FIELD)   _VP_VDSTAT_FGET(2,##FIELD)
 #endif


  #define _VP_VDSTAT0_FSET(FIELD,f)   _VP_VDSTAT_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDSTAT1_FSET(FIELD,f)   _VP_VDSTAT_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDSTAT2_FSET(FIELD,f)   _VP_VDSTAT_FSET(2,##FIELD,f)
 #endif


  #define _VP_VDSTAT0_FSETS(FIELD,SYM)   _VP_VDSTAT_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDSTAT1_FSETS(FIELD,SYM)   _VP_VDSTAT_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDSTAT2_FSETS(FIELD,SYM)   _VP_VDSTAT_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V D C T L        |
* |___________________|
*
* VDCTL0 -  Video Port 0 Video Display Control
* VDCTL1 -  Video Port 1 Video Display Control
* VDCTL2 -  Video Port 2 Video Display Control
*
* FIELDS (msb -> lsb)
*
* (rw) RSTCH
* (rw) BLKDIS
* (rw) PVPSYN
* (rw) FXS
* (rw) VXS
* (rw) HXS
* (rw) VCTL2S
* (rw) VCTL1S
* (rw) VCTL0S
* (rw) VDEN
* (rw) DPK
* (rw) RGBX
* (rw) RSYNC
* (rw) DVEN
* (rw) RESMPL
* (rw) SCALE
* (rw) CON
* (rw) FRAME
* (rw) DF2
* (rw) DF1
* (rw) DMODE
*
\******************************************************************************/
  #define _VP_VDCTL_OFFSET           129

  #define _VP_VDCTL0_ADDR   (_VP_BASE_PORT0 + 4*_VP_VDCTL_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDCTL1_ADDR   (_VP_BASE_PORT1 + 4*_VP_VDCTL_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDCTL2_ADDR   (_VP_BASE_PORT2 + 4*_VP_VDCTL_OFFSET)
 #endif


  #define _VP_VDCTL_RSTCH_MASK        0x80000000u
  #define _VP_VDCTL_RSTCH_SHIFT       0x0000001Fu
  #define  VP_VDCTL_RSTCH_DEFAULT     0x00000000u
  #define  VP_VDCTL_RSTCH_OF(x)       _VALUEOF(x)
  #define  VP_VDCTL_RSTCH_NONE        0x00000000u
  #define  VP_VDCTL_RSTCH_RESET       0x00000001u

  #define _VP_VDCTL_BLKDIS_MASK         0x40000000u
  #define _VP_VDCTL_BLKDIS_SHIFT        0x0000001Eu
  #define  VP_VDCTL_BLKDIS_DEFAULT      0x00000001u
  #define  VP_VDCTL_BLKDIS_OF(x)        _VALUEOF(x)
  #define  VP_VDCTL_BLKDIS_CLEAR        0x00000000u
  #define  VP_VDCTL_BLKDIS_BLOCK        0x00000001u

  #define _VP_VDCTL_PVPSYN_MASK         0x10000000u
  #define _VP_VDCTL_PVPSYN_SHIFT        0x0000001Cu
  #define  VP_VDCTL_PVPSYN_DEFAULT      0x00000000u
  #define  VP_VDCTL_PVPSYN_OF(x)        _VALUEOF(x)
  #define  VP_VDCTL_PVPSYN_DISABLE      0x00000000u
  #define  VP_VDCTL_PVPSYN_ENABLE       0x00000001u

  #define _VP_VDCTL_FXS_MASK         0x00800000u
  #define _VP_VDCTL_FXS_SHIFT        0x00000017u
  #define  VP_VDCTL_FXS_DEFAULT      0x00000000u
  #define  VP_VDCTL_FXS_OF(x)        _VALUEOF(x)
  #define  VP_VDCTL_FXS_OUTPUT       0x00000000u
  #define  VP_VDCTL_FXS_FSINPUT      0x00000001u

  #define _VP_VDCTL_VXS_MASK         0x00400000u
  #define _VP_VDCTL_VXS_SHIFT        0x00000016u
  #define  VP_VDCTL_VXS_DEFAULT      0x00000000u
  #define  VP_VDCTL_VXS_OF(x)        _VALUEOF(x)
  #define  VP_VDCTL_VXS_OUTPUT       0x00000000u
  #define  VP_VDCTL_VXS_VSINPUT      0x00000001u

  #define _VP_VDCTL_HXS_MASK         0x00200000u
  #define _VP_VDCTL_HXS_SHIFT        0x00000015u
  #define  VP_VDCTL_HXS_DEFAULT      0x00000000u
  #define  VP_VDCTL_HXS_OF(x)        _VALUEOF(x)
  #define  VP_VDCTL_HXS_OUTPUT       0x00000000u
  #define  VP_VDCTL_HXS_HSINPUT      0x00000001u

  #define _VP_VDCTL_VCTL2S_MASK         0x00100000u
  #define _VP_VDCTL_VCTL2S_SHIFT        0x00000014u
  #define  VP_VDCTL_VCTL2S_DEFAULT      0x00000000u
  #define  VP_VDCTL_VCTL2S_OF(x)        _VALUEOF(x)
  #define  VP_VDCTL_VCTL2S_CBLNK        0x00000000u
  #define  VP_VDCTL_VCTL2S_FLD          0x00000001u

  #define _VP_VDCTL_VCTL1S_MASK         0x000C0000u
  #define _VP_VDCTL_VCTL1S_SHIFT        0x00000012u
  #define  VP_VDCTL_VCTL1S_DEFAULT      0x00000000u
  #define  VP_VDCTL_VCTL1S_OF(x)        _VALUEOF(x)
  #define  VP_VDCTL_VCTL1S_VYSYNC       0x00000000u
  #define  VP_VDCTL_VCTL1S_VBLNK        0x00000001u
  #define  VP_VDCTL_VCTL1S_CSYNC        0x00000002u
  #define  VP_VDCTL_VCTL1S_FLD          0x00000003u

  #define _VP_VDCTL_VCTL0S_MASK         0x00030000u
  #define _VP_VDCTL_VCTL0S_SHIFT        0x00000010u
  #define  VP_VDCTL_VCTL0S_DEFAULT      0x00000000u
  #define  VP_VDCTL_VCTL0S_OF(x)        _VALUEOF(x)
  #define  VP_VDCTL_VCTL0S_HYSYNC       0x00000000u
  #define  VP_VDCTL_VCTL0S_HBLNK        0x00000001u
  #define  VP_VDCTL_VCTL0S_AVID         0x00000002u
  #define  VP_VDCTL_VCTL0S_FLD          0x00000003u

  #define _VP_VDCTL_VDEN_MASK         0x00008000u
  #define _VP_VDCTL_VDEN_SHIFT        0x0000000Fu
  #define  VP_VDCTL_VDEN_DEFAULT      0x00000000u
  #define  VP_VDCTL_VDEN_OF(x)        _VALUEOF(x)
  #define  VP_VDCTL_VDEN_DISABLE      0x00000000u
  #define  VP_VDCTL_VDEN_ENABLE       0x00000001u

  #define _VP_VDCTL_DPK_MASK         0x00004000u
  #define _VP_VDCTL_DPK_SHIFT        0x0000000Eu
  #define  VP_VDCTL_DPK_DEFAULT      0x00000000u
  #define  VP_VDCTL_DPK_OF(x)        _VALUEOF(x)
  #define  VP_VDCTL_DPK_N10UNPK      0x00000000u
  #define  VP_VDCTL_DPK_D10UNPK      0x00000001u

  #define _VP_VDCTL_RGBX_MASK         0x00002000u
  #define _VP_VDCTL_RGBX_SHIFT        0x0000000Du
  #define  VP_VDCTL_RGBX_DEFAULT      0x00000000u
  #define  VP_VDCTL_RGBX_OF(x)        _VALUEOF(x)
  #define  VP_VDCTL_RGBX_DISABLE      0x00000000u
  #define  VP_VDCTL_RGBX_ENABLE       0x00000001u

  #define _VP_VDCTL_RSYNC_MASK         0x00001000u
  #define _VP_VDCTL_RSYNC_SHIFT        0x0000000Cu
  #define  VP_VDCTL_RSYNC_DEFAULT      0x00000000u
  #define  VP_VDCTL_RSYNC_OF(x)        _VALUEOF(x)
  #define  VP_VDCTL_RSYNC_DISABLE      0x00000000u
  #define  VP_VDCTL_RSYNC_ENABLE       0x00000001u

  #define _VP_VDCTL_DVEN_MASK         0x00000800u
  #define _VP_VDCTL_DVEN_SHIFT        0x0000000Bu
  #define  VP_VDCTL_DVEN_DEFAULT      0x00000000u
  #define  VP_VDCTL_DVEN_OF(x)        _VALUEOF(x)
  #define  VP_VDCTL_DVEN_BLANKING     0x00000000u
  #define  VP_VDCTL_DVEN_DV           0x00000001u

  #define _VP_VDCTL_RESMPL_MASK         0x00000400u
  #define _VP_VDCTL_RESMPL_SHIFT        0x0000000Au
  #define  VP_VDCTL_RESMPL_DEFAULT      0x00000000u
  #define  VP_VDCTL_RESMPL_OF(x)        _VALUEOF(x)
  #define  VP_VDCTL_RESMPL_DISABLE      0x00000000u
  #define  VP_VDCTL_RESMPL_ENABLE       0x00000001u

/*    ??? */
  #define _VP_VDCTL_SCALE_MASK         0x00000100u
  #define _VP_VDCTL_SCALE_SHIFT        0x00000008u
  #define  VP_VDCTL_SCALE_DEFAULT      0x00000000u
  #define  VP_VDCTL_SCALE_OF(x)        _VALUEOF(x)
  #define  VP_VDCTL_SCALE_NONE         0x00000000u
  #define  VP_VDCTL_SCALE_X2           0x00000001u

  #define _VP_VDCTL_CON_MASK         0x00000080u
  #define _VP_VDCTL_CON_SHIFT        0x00000007u
  #define  VP_VDCTL_CON_DEFAULT      0x00000000u
  #define  VP_VDCTL_CON_OF(x)        _VALUEOF(x)
  #define  VP_VDCTL_CON_DISABLE      0x00000000u
  #define  VP_VDCTL_CON_ENABLE        0x00000001u

  #define _VP_VDCTL_FRAME_MASK         0x00000040u
  #define _VP_VDCTL_FRAME_SHIFT        0x00000006u
  #define  VP_VDCTL_FRAME_DEFAULT      0x00000000u
  #define  VP_VDCTL_FRAME_OF(x)        _VALUEOF(x)
  #define  VP_VDCTL_FRAME_NONE         0x00000000u
  #define  VP_VDCTL_FRAME_FRMDIS       0x00000001u

  #define _VP_VDCTL_DF2_MASK         0x00000020u
  #define _VP_VDCTL_DF2_SHIFT        0x00000005u
  #define  VP_VDCTL_DF2_DEFAULT      0x00000000u
  #define  VP_VDCTL_DF2_OF(x)        _VALUEOF(x)
  #define  VP_VDCTL_DF2_NONE         0x00000000u
  #define  VP_VDCTL_DF2_FLDDIS       0x00000001u

  #define _VP_VDCTL_DF1_MASK         0x00000010u
  #define _VP_VDCTL_DF1_SHIFT        0x00000004u
  #define  VP_VDCTL_DF1_DEFAULT      0x00000000u
  #define  VP_VDCTL_DF1_OF(x)        _VALUEOF(x)
  #define  VP_VDCTL_DF1_NONE         0x00000000u
  #define  VP_VDCTL_DF1_FLDDIS       0x00000001u

  #define _VP_VDCTL_DMODE_MASK         0x00000007u
  #define _VP_VDCTL_DMODE_SHIFT        0x00000000u
  #define  VP_VDCTL_DMODE_DEFAULT      0x00000000u
  #define  VP_VDCTL_DMODE_OF(x)        _VALUEOF(x)
  #define  VP_VDCTL_DMODE_BT656B       0x00000000u
  #define  VP_VDCTL_DMODE_BT656D       0x00000001u
  #define  VP_VDCTL_DMODE_RAWB         0x00000002u
  #define  VP_VDCTL_DMODE_RAWD         0x00000003u
  #define  VP_VDCTL_DMODE_YC16         0x00000004u
  #define  VP_VDCTL_DMODE_YC20         0x00000005u
  #define  VP_VDCTL_DMODE_RAW16        0x00000006u
  #define  VP_VDCTL_DMODE_RAW20        0x00000007u

  #define  VP_VDCTL_OF(x)            _VALUEOF(x)

  #define VP_VDCTL_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VDCTL,RSTCH)\
    |_PER_FDEFAULT(VP,VDCTL,BLKDIS)\
    |_PER_FDEFAULT(VP,VDCTL,PVPSYN)\
    |_PER_FDEFAULT(VP,VDCTL,FXS)\
    |_PER_FDEFAULT(VP,VDCTL,VXS)\
    |_PER_FDEFAULT(VP,VDCTL,HXS)\
    |_PER_FDEFAULT(VP,VDCTL,VCTL2S)\
    |_PER_FDEFAULT(VP,VDCTL,VCTL1S)\
    |_PER_FDEFAULT(VP,VDCTL,VCTL0S)\
    |_PER_FDEFAULT(VP,VDCTL,VDEN)\
    |_PER_FDEFAULT(VP,VDCTL,DPK)\
    |_PER_FDEFAULT(VP,VDCTL,RGBX)\
    |_PER_FDEFAULT(VP,VDCTL,RSYNC)\
    |_PER_FDEFAULT(VP,VDCTL,DVEN)\
    |_PER_FDEFAULT(VP,VDCTL,RESMPL)\
    |_PER_FDEFAULT(VP,VDCTL,SCALE)\
    |_PER_FDEFAULT(VP,VDCTL,CON)\
    |_PER_FDEFAULT(VP,VDCTL,FRAME)\
    |_PER_FDEFAULT(VP,VDCTL,DF2)\
    |_PER_FDEFAULT(VP,VDCTL,DF1)\
    |_PER_FDEFAULT(VP,VDCTL,DMODE)\
  )

  #define VP_VDCTL_RMK(rstch,blkdis,pvpsyn,fxs,vxs,hxs,vctl2s,vctl1s,vctl0s,\
    vden,dpk,rgbx,rsync,dven,resmpl,scale,con,frame,df2,df1,dmode) (Uint32)(\
     _PER_FMK(VP,VDCTL,RSTCH,rstch)\
    |_PER_FMK(VP,VDCTL,BLKDIS,blkdis)\
    |_PER_FMK(VP,VDCTL,PVPSYN,pvpsyn)\
    |_PER_FMK(VP,VDCTL,FXS,fxs)\
    |_PER_FMK(VP,VDCTL,VXS,vxs)\
    |_PER_FMK(VP,VDCTL,HXS,hxs)\
    |_PER_FMK(VP,VDCTL,VCTL2S,vctl2s)\
    |_PER_FMK(VP,VDCTL,VCTL1S,vctl1s)\
    |_PER_FMK(VP,VDCTL,VCTL0S,vctl0s)\
    |_PER_FMK(VP,VDCTL,VDEN,vden)\
    |_PER_FMK(VP,VDCTL,DPK,dpk)\
    |_PER_FMK(VP,VDCTL,RGBX,rgbx)\
    |_PER_FMK(VP,VDCTL,RSYNC,rsync)\
    |_PER_FMK(VP,VDCTL,DVEN,dven)\
    |_PER_FMK(VP,VDCTL,RESMPL,resmpl)\
    |_PER_FMK(VP,VDCTL,SCALE,scale)\
    |_PER_FMK(VP,VDCTL,CON,con)\
    |_PER_FMK(VP,VDCTL,FRAME,frame)\
    |_PER_FMK(VP,VDCTL,DF2,df2)\
    |_PER_FMK(VP,VDCTL,DF1,df1)\
    |_PER_FMK(VP,VDCTL,DMODE,dmode)\
  )

  #define _VP_VDCTL_FGET(N,FIELD)\
    _PER_FGET(_VP_VDCTL##N##_ADDR,VP,VDCTL,##FIELD)

  #define _VP_VDCTL_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VDCTL##N##_ADDR,VP,VDCTL,##FIELD,field)

  #define _VP_VDCTL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VDCTL##N##_ADDR,VP,VDCTL,##FIELD,##SYM)

  #define _VP_VDCTL0_FGET(FIELD)   _VP_VDCTL_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDCTL1_FGET(FIELD)   _VP_VDCTL_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDCTL2_FGET(FIELD)   _VP_VDCTL_FGET(2,##FIELD)
 #endif


  #define _VP_VDCTL0_FSET(FIELD,f)   _VP_VDCTL_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDCTL1_FSET(FIELD,f)   _VP_VDCTL_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDCTL2_FSET(FIELD,f)   _VP_VDCTL_FSET(2,##FIELD,f)
 #endif


  #define _VP_VDCTL0_FSETS(FIELD,SYM)   _VP_VDCTL_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDCTL1_FSETS(FIELD,SYM)   _VP_VDCTL_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDCTL2_FSETS(FIELD,SYM)   _VP_VDCTL_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V D F R M S Z    |
* |___________________|
*
* VDFRMSZ0 -  Video Port 0 Video Display Frame Size
* VDFRMSZ1 -  Video Port 1 Video Display Frame Size
* VDFRMSZ2 -  Video Port 2 Video Display Frame Size
*
* FIELDS (msb -> lsb)
* (rw) FRMHEIGHT
* (rw) FRMWIDTH
*
\******************************************************************************/
  #define _VP_VDFRMSZ_OFFSET           130

  #define _VP_VDFRMSZ0_ADDR   (_VP_BASE_PORT0 + 4*_VP_VDFRMSZ_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDFRMSZ1_ADDR   (_VP_BASE_PORT1 + 4*_VP_VDFRMSZ_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDFRMSZ2_ADDR   (_VP_BASE_PORT2 + 4*_VP_VDFRMSZ_OFFSET)
 #endif


  #define _VP_VDFRMSZ_FRMHEIGHT_MASK        0x0FFF0000u
  #define _VP_VDFRMSZ_FRMHEIGHT_SHIFT       0x00000010u
  #define  VP_VDFRMSZ_FRMHEIGHT_DEFAULT     0x00000000u
  #define  VP_VDFRMSZ_FRMHEIGHT_OF(x)       _VALUEOF(x)

  #define _VP_VDFRMSZ_FRMWIDTH_MASK        0x00000FFFu
  #define _VP_VDFRMSZ_FRMWIDTH_SHIFT       0x00000000u
  #define  VP_VDFRMSZ_FRMWIDTH_DEFAULT     0x00000000u
  #define  VP_VDFRMSZ_FRMWIDTH_OF(x)       _VALUEOF(x)

  #define  VP_VDFRMSZ_OF(x)            _VALUEOF(x)

  #define VP_VDFRMSZ_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VDFRMSZ,FRMHEIGHT)\
    |_PER_FDEFAULT(VP,VDFRMSZ,FRMWIDTH)\
  )

  #define VP_VDFRMSZ_RMK(frmheight,frmwidth) (Uint32)(\
     _PER_FMK(VP,VDFRMSZ,FRMHEIGHT,frmheight)\
    |_PER_FMK(VP,VDFRMSZ,FRMWIDTH,frmwidth)\
  )

  #define _VP_VDFRMSZ_FGET(N,FIELD)\
    _PER_FGET(_VP_VDFRMSZ##N##_ADDR,VP,VDFRMSZ,##FIELD)

  #define _VP_VDFRMSZ_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VDFRMSZ##N##_ADDR,VP,VDFRMSZ,##FIELD,field)

  #define _VP_VDFRMSZ_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VDFRMSZ##N##_ADDR,VP,VDFRMSZ,##FIELD,##SYM)

  #define _VP_VDFRMSZ0_FGET(FIELD)   _VP_VDFRMSZ_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDFRMSZ1_FGET(FIELD)   _VP_VDFRMSZ_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDFRMSZ2_FGET(FIELD)   _VP_VDFRMSZ_FGET(2,##FIELD)
 #endif


  #define _VP_VDFRMSZ0_FSET(FIELD,f)   _VP_VDFRMSZ_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDFRMSZ1_FSET(FIELD,f)   _VP_VDFRMSZ_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDFRMSZ2_FSET(FIELD,f)   _VP_VDFRMSZ_FSET(2,##FIELD,f)
 #endif


  #define _VP_VDFRMSZ0_FSETS(FIELD,SYM)   _VP_VDFRMSZ_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDFRMSZ1_FSETS(FIELD,SYM)   _VP_VDFRMSZ_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDFRMSZ2_FSETS(FIELD,SYM)   _VP_VDFRMSZ_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V D H B L N K    |
* |___________________|
*
* VDHBLNK0 -  Video Port 0 Video Display Horizontal Blanking
* VDHBLNK1 -  Video Port 1 Video Display Horizontal Blanking
* VDHBLNK2 -  Video Port 2 Video Display Horizontal Blanking
*
* FIELDS (msb -> lsb)
* (rw) HBLNKSTOP
* (rw) HBDLA
* (rw) HBLNKSTART
*
\******************************************************************************/
  #define _VP_VDHBLNK_OFFSET           131

  #define _VP_VDHBLNKA_ADDR            (_VP_BASE_PORT0 + 4*_VP_VDHBLNK_OFFSET)
  #define _VP_VDHBLNKB_ADDR            (_VP_BASE_PORT1 + 4*_VP_VDHBLNK_OFFSET)
  #define _VP_VDHBLNKC_ADDR            (_VP_BASE_PORT2 + 4*_VP_VDHBLNK_OFFSET)

  #define _VP_VDHBLNK_HBLNKSTOP_MASK        0x0FFF0000u
  #define _VP_VDHBLNK_HBLNKSTOP_SHIFT       0x00000010u
  #define  VP_VDHBLNK_HBLNKSTOP_DEFAULT     0x00000000u
  #define  VP_VDHBLNK_HBLNKSTOP_OF(x)       _VALUEOF(x)

  #define _VP_VDHBLNK_HBDLA_MASK        0x00008000u
  #define _VP_VDHBLNK_HBDLA_SHIFT       0x0000000Fu
  #define  VP_VDHBLNK_HBDLA_DEFAULT     0x00000000u
  #define  VP_VDHBLNK_HBDLA_OF(x)       _VALUEOF(x)
  #define  VP_VDHBLNK_HBDLA_NONE        0x00000000u
  #define  VP_VDHBLNK_HBDLA_DELAY       0x00000001u

  #define _VP_VDHBLNK_HBLNKSTART_MASK        0x00000FFFu
  #define _VP_VDHBLNK_HBLNKSTART_SHIFT       0x00000000u
  #define  VP_VDHBLNK_HBLNKSTART_DEFAULT     0x00000000u
  #define  VP_VDHBLNK_HBLNKSTART_OF(x)       _VALUEOF(x)

  #define  VP_VDHBLNK_OF(x)            _VALUEOF(x)

  #define VP_VDHBLNK_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VDHBLNK,HBLNKSTOP)\
    |_PER_FDEFAULT(VP,VDHBLNK,HBDLA)\
    |_PER_FDEFAULT(VP,VDHBLNK,HBLNKSTART)\
  )

  #define VP_VDHBLNK_RMK(hblnkstop,hbdla,hblnkstart) (Uint32)(\
     _PER_FMK(VP,VDHBLNK,HBLNKSTOP,hblnkstop)\
    |_PER_FMK(VP,VDHBLNK,HBDLA,hbdla)\
    |_PER_FMK(VP,VDHBLNK,HBLNKSTART,hblnkstart)\
  )

  #define _VP_VDHBLNK_FGET(N,FIELD)\
    _PER_FGET(_VP_VDHBLNK##N##_ADDR,VP,VDHBLNK,##FIELD)

  #define _VP_VDHBLNK_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VDHBLNK##N##_ADDR,VP,VDHBLNK,##FIELD,field)

  #define _VP_VDHBLNK_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VDHBLNK##N##_ADDR,VP,VDHBLNK,##FIELD,##SYM)

  #define _VP_VDHBLNK0_FGET(FIELD)   _VP_VDHBLNK_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDHBLNK1_FGET(FIELD)   _VP_VDHBLNK_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDHBLNK2_FGET(FIELD)   _VP_VDHBLNK_FGET(2,##FIELD)
 #endif


  #define _VP_VDHBLNK0_FSET(FIELD,f)   _VP_VDHBLNK_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDHBLNK1_FSET(FIELD,f)   _VP_VDHBLNK_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDHBLNK2_FSET(FIELD,f)   _VP_VDHBLNK_FSET(2,##FIELD,f)
 #endif


  #define _VP_VDHBLNK0_FSETS(FIELD,SYM)   _VP_VDHBLNK_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDHBLNK1_FSETS(FIELD,SYM)   _VP_VDHBLNK_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDHBLNK2_FSETS(FIELD,SYM)   _VP_VDHBLNK_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V D V B L K S 1  |
* |___________________|
*
* VDVBLKS10 -  Video Port 0 Video Display Vertical Blanking Start - Field 1
* VDVBLKS11 -  Video Port 1 Video Display Vertical Blanking Start - Field 1
* VDVBLKS12 -  Video Port 2 Video Display Vertical Blanking Start - Field 1
*
* FIELDS (msb -> lsb)
* (rw) VBLNKYSTART1
* (rw) VBLNKXSTART1
*
\******************************************************************************/
  #define _VP_VDVBLKS1_OFFSET           132

  #define _VP_VDVBLKS10_ADDR   (_VP_BASE_PORT0 + 4*_VP_VDVBLKS1_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVBLKS11_ADDR   (_VP_BASE_PORT1 + 4*_VP_VDVBLKS1_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVBLKS12_ADDR   (_VP_BASE_PORT2 + 4*_VP_VDVBLKS1_OFFSET)
 #endif


  #define _VP_VDVBLKS1_VBLNKYSTART1_MASK        0x0FFF0000u
  #define _VP_VDVBLKS1_VBLNKYSTART1_SHIFT       0x00000010u
  #define  VP_VDVBLKS1_VBLNKYSTART1_DEFAULT     0x00000000u
  #define  VP_VDVBLKS1_VBLNKYSTART1_OF(x)       _VALUEOF(x)

  #define _VP_VDVBLKS1_VBLNKXSTART1_MASK        0x00000FFFu
  #define _VP_VDVBLKS1_VBLNKXSTART1_SHIFT       0x00000000u
  #define  VP_VDVBLKS1_VBLNKXSTART1_DEFAULT     0x00000000u
  #define  VP_VDVBLKS1_VBLNKXSTART1_OF(x)       _VALUEOF(x)

  #define  VP_VDVBLKS1_OF(x)            _VALUEOF(x)

  #define VP_VDVBLKS1_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VDVBLKS1,VBLNKYSTART1)\
    |_PER_FDEFAULT(VP,VDVBLKS1,VBLNKXSTART1)\
  )

  #define VP_VDVBLKS1_RMK(vblnkystart1,vblnkxstart1) (Uint32)(\
     _PER_FMK(VP,VDVBLKS1,VBLNKYSTART1,vblnkystart1)\
    |_PER_FMK(VP,VDVBLKS1,VBLNKXSTART1,vblnkxstart1)\
  )

  #define _VP_VDVBLKS1_FGET(N,FIELD)\
    _PER_FGET(_VP_VDVBLKS1##N##_ADDR,VP,VDVBLKS1,##FIELD)

  #define _VP_VDVBLKS1_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VDVBLKS1##N##_ADDR,VP,VDVBLKS1,##FIELD,field)

  #define _VP_VDVBLKS1_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VDVBLKS1##N##_ADDR,VP,VDVBLKS1,##FIELD,##SYM)

  #define _VP_VDVBLKS10_FGET(FIELD)   _VP_VDVBLKS1_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVBLKS11_FGET(FIELD)   _VP_VDVBLKS1_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVBLKS12_FGET(FIELD)   _VP_VDVBLKS1_FGET(2,##FIELD)
 #endif


  #define _VP_VDVBLKS10_FSET(FIELD,f)   _VP_VDVBLKS1_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVBLKS11_FSET(FIELD,f)   _VP_VDVBLKS1_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVBLKS12_FSET(FIELD,f)   _VP_VDVBLKS1_FSET(2,##FIELD,f)
 #endif


  #define _VP_VDVBLKS10_FSETS(FIELD,SYM)   _VP_VDVBLKS1_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVBLKS11_FSETS(FIELD,SYM)   _VP_VDVBLKS1_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVBLKS12_FSETS(FIELD,SYM)   _VP_VDVBLKS1_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V D V B L K E 1  |
* |___________________|
*
* VDVBLKE10 -  Video Port 0 Video Display Vertical Blanking End - Field 1
* VDVBLKE11 -  Video Port 1 Video Display Vertical Blanking End - Field 1
* VDVBLKE12 -  Video Port 2 Video Display Vertical Blanking End - Field 1
*
* FIELDS (msb -> lsb)
* (rw) VBLNKYSTOP1
* (rw) VBLNKXSTOP1
*
\******************************************************************************/
  #define _VP_VDVBLKE1_OFFSET           133

  #define _VP_VDVBLKE10_ADDR   (_VP_BASE_PORT0 + 4*_VP_VDVBLKE1_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVBLKE11_ADDR   (_VP_BASE_PORT1 + 4*_VP_VDVBLKE1_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVBLKE12_ADDR   (_VP_BASE_PORT2 + 4*_VP_VDVBLKE1_OFFSET)
 #endif


  #define _VP_VDVBLKE1_VBLNKYSTOP1_MASK        0x0FFF0000u
  #define _VP_VDVBLKE1_VBLNKYSTOP1_SHIFT       0x00000010u
  #define  VP_VDVBLKE1_VBLNKYSTOP1_DEFAULT     0x00000000u
  #define  VP_VDVBLKE1_VBLNKYSTOP1_OF(x)       _VALUEOF(x)

  #define _VP_VDVBLKE1_VBLNKXSTOP1_MASK        0x00000FFFu
  #define _VP_VDVBLKE1_VBLNKXSTOP1_SHIFT       0x00000000u
  #define  VP_VDVBLKE1_VBLNKXSTOP1_DEFAULT     0x00000000u
  #define  VP_VDVBLKE1_VBLNKXSTOP1_OF(x)       _VALUEOF(x)

  #define  VP_VDVBLKE1_OF(x)            _VALUEOF(x)

  #define VP_VDVBLKE1_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VDVBLKE1,VBLNKYSTOP1)\
    |_PER_FDEFAULT(VP,VDVBLKE1,VBLNKXSTOP1)\
  )

  #define VP_VDVBLKE1_RMK(vblnkystop1,vblnkxstop1) (Uint32)(\
     _PER_FMK(VP,VDVBLKE1,VBLNKYSTOP1,vblnkystop1)\
    |_PER_FMK(VP,VDVBLKE1,VBLNKXSTOP1,vblnkxstop1)\
  )

  #define _VP_VDVBLKE1_FGET(N,FIELD)\
    _PER_FGET(_VP_VDVBLKE1##N##_ADDR,VP,VDVBLKE1,##FIELD)

  #define _VP_VDVBLKE1_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VDVBLKE1##N##_ADDR,VP,VDVBLKE1,##FIELD,field)

  #define _VP_VDVBLKE1_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VDVBLKE1##N##_ADDR,VP,VDVBLKE1,##FIELD,##SYM)

  #define _VP_VDVBLKE10_FGET(FIELD)   _VP_VDVBLKE1_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVBLKE11_FGET(FIELD)   _VP_VDVBLKE1_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVBLKE12_FGET(FIELD)   _VP_VDVBLKE1_FGET(2,##FIELD)
 #endif


  #define _VP_VDVBLKE10_FSET(FIELD,f)   _VP_VDVBLKE1_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVBLKE11_FSET(FIELD,f)   _VP_VDVBLKE1_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVBLKE12_FSET(FIELD,f)   _VP_VDVBLKE1_FSET(2,##FIELD,f)
 #endif


  #define _VP_VDVBLKE10_FSETS(FIELD,SYM)   _VP_VDVBLKE1_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVBLKE11_FSETS(FIELD,SYM)   _VP_VDVBLKE1_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVBLKE12_FSETS(FIELD,SYM)   _VP_VDVBLKE1_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V D V B L K S 2  |
* |___________________|
*
* VDVBLKS20 -  Video Port 0 Video Display Vertical Blanking Start - Field 2
* VDVBLKS21 -  Video Port 1 Video Display Vertical Blanking Start - Field 2
* VDVBLKS22 -  Video Port 2 Video Display Vertical Blanking Start - Field 2
*
* FIELDS (msb -> lsb)
* (rw) VBLNKYSTART2
* (rw) VBLNKXSTART2
*
\******************************************************************************/
  #define _VP_VDVBLKS2_OFFSET           134

  #define _VP_VDVBLKS20_ADDR   (_VP_BASE_PORT0 + 4*_VP_VDVBLKS2_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVBLKS21_ADDR   (_VP_BASE_PORT1 + 4*_VP_VDVBLKS2_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVBLKS22_ADDR   (_VP_BASE_PORT2 + 4*_VP_VDVBLKS2_OFFSET)
 #endif


  #define _VP_VDVBLKS2_VBLNKYSTART2_MASK        0x0FFF0000u
  #define _VP_VDVBLKS2_VBLNKYSTART2_SHIFT       0x00000010u
  #define  VP_VDVBLKS2_VBLNKYSTART2_DEFAULT     0x00000000u
  #define  VP_VDVBLKS2_VBLNKYSTART2_OF(x)       _VALUEOF(x)

  #define _VP_VDVBLKS2_VBLNKXSTART2_MASK        0x00000FFFu
  #define _VP_VDVBLKS2_VBLNKXSTART2_SHIFT       0x00000000u
  #define  VP_VDVBLKS2_VBLNKXSTART2_DEFAULT     0x00000000u
  #define  VP_VDVBLKS2_VBLNKXSTART2_OF(x)       _VALUEOF(x)

  #define  VP_VDVBLKS2_OF(x)            _VALUEOF(x)

  #define VP_VDVBLKS2_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VDVBLKS2,VBLNKYSTART2)\
    |_PER_FDEFAULT(VP,VDVBLKS2,VBLNKXSTART2)\
  )

  #define VP_VDVBLKS2_RMK(vblnkystart2,vblnkxstart2) (Uint32)(\
     _PER_FMK(VP,VDVBLKS2,VBLNKYSTART2,vblnkystart2)\
    |_PER_FMK(VP,VDVBLKS2,VBLNKXSTART2,vblnkxstart2)\
  )

  #define _VP_VDVBLKS2_FGET(N,FIELD)\
    _PER_FGET(_VP_VDVBLKS2##N##_ADDR,VP,VDVBLKS2,##FIELD)

  #define _VP_VDVBLKS2_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VDVBLKS2##N##_ADDR,VP,VDVBLKS2,##FIELD,field)

  #define _VP_VDVBLKS2_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VDVBLKS2##N##_ADDR,VP,VDVBLKS2,##FIELD,##SYM)

  #define _VP_VDVBLKS20_FGET(FIELD)   _VP_VDVBLKS2_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVBLKS21_FGET(FIELD)   _VP_VDVBLKS2_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVBLKS22_FGET(FIELD)   _VP_VDVBLKS2_FGET(2,##FIELD)
 #endif


  #define _VP_VDVBLKS20_FSET(FIELD,f)   _VP_VDVBLKS2_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVBLKS21_FSET(FIELD,f)   _VP_VDVBLKS2_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVBLKS22_FSET(FIELD,f)   _VP_VDVBLKS2_FSET(2,##FIELD,f)
 #endif


  #define _VP_VDVBLKS20_FSETS(FIELD,SYM)   _VP_VDVBLKS2_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVBLKS21_FSETS(FIELD,SYM)   _VP_VDVBLKS2_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVBLKS22_FSETS(FIELD,SYM)   _VP_VDVBLKS2_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V D V B L K E 2  |
* |___________________|
*
* VDVBLKE20 -  Video Port 0 Video Display Vertical Blanking End - Field 2
* VDVBLKE21 -  Video Port 1 Video Display Vertical Blanking End - Field 2
* VDVBLKE22 -  Video Port 2 Video Display Vertical Blanking End - Field 2
*
* FIELDS (msb -> lsb)
* (rw) VBLNKYSTOP2
* (rw) VBLNKXSTOP2
*
\******************************************************************************/
  #define _VP_VDVBLKE2_OFFSET           135

  #define _VP_VDVBLKE20_ADDR   (_VP_BASE_PORT0 + 4*_VP_VDVBLKE2_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVBLKE21_ADDR   (_VP_BASE_PORT1 + 4*_VP_VDVBLKE2_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVBLKE22_ADDR   (_VP_BASE_PORT2 + 4*_VP_VDVBLKE2_OFFSET)
 #endif


  #define _VP_VDVBLKE2_VBLNKYSTOP2_MASK        0x0FFF0000u
  #define _VP_VDVBLKE2_VBLNKYSTOP2_SHIFT       0x00000010u
  #define  VP_VDVBLKE2_VBLNKYSTOP2_DEFAULT     0x00000000u
  #define  VP_VDVBLKE2_VBLNKYSTOP2_OF(x)       _VALUEOF(x)

  #define _VP_VDVBLKE2_VBLNKXSTOP2_MASK        0x00000FFFu
  #define _VP_VDVBLKE2_VBLNKXSTOP2_SHIFT       0x00000000u
  #define  VP_VDVBLKE2_VBLNKXSTOP2_DEFAULT     0x00000000u
  #define  VP_VDVBLKE2_VBLNKXSTOP2_OF(x)       _VALUEOF(x)

  #define  VP_VDVBLKE2_OF(x)            _VALUEOF(x)

  #define VP_VDVBLKE2_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VDVBLKE2,VBLNKYSTOP2)\
    |_PER_FDEFAULT(VP,VDVBLKE2,VBLNKXSTOP2)\
  )

  #define VP_VDVBLKE2_RMK(vblnkystop2,vblnkxstop2) (Uint32)(\
     _PER_FMK(VP,VDVBLKE2,VBLNKYSTOP2,vblnkystop2)\
    |_PER_FMK(VP,VDVBLKE2,VBLNKXSTOP2,vblnkxstop2)\
  )

  #define _VP_VDVBLKE2_FGET(N,FIELD)\
    _PER_FGET(_VP_VDVBLKE2##N##_ADDR,VP,VDVBLKE2,##FIELD)

  #define _VP_VDVBLKE2_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VDVBLKE2##N##_ADDR,VP,VDVBLKE2,##FIELD,field)

  #define _VP_VDVBLKE2_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VDVBLKE2##N##_ADDR,VP,VDVBLKE2,##FIELD,##SYM)

  #define _VP_VDVBLKE20_FGET(FIELD)   _VP_VDVBLKE2_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVBLKE21_FGET(FIELD)   _VP_VDVBLKE2_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVBLKE22_FGET(FIELD)   _VP_VDVBLKE2_FGET(2,##FIELD)
 #endif


  #define _VP_VDVBLKE20_FSET(FIELD,f)   _VP_VDVBLKE2_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVBLKE21_FSET(FIELD,f)   _VP_VDVBLKE2_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVBLKE22_FSET(FIELD,f)   _VP_VDVBLKE2_FSET(2,##FIELD,f)
 #endif


  #define _VP_VDVBLKE20_FSETS(FIELD,SYM)   _VP_VDVBLKE2_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVBLKE21_FSETS(FIELD,SYM)   _VP_VDVBLKE2_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVBLKE22_FSETS(FIELD,SYM)   _VP_VDVBLKE2_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* ______________________
* |                    |
* |  V D I M G O F F 1 |
* |____________________|
*
* VDIMGOFF10 -  Video Port 0 Video Display Image Offset - Field 1
* VDIMGOFF11 -  Video Port 1 Video Display Image Offset - Field 1
* VDIMGOFF12 -  Video Port 2 Video Display Image Offset - Field 1
*
* FIELDS (msb -> lsb)
* (rw) NV
* (rw) IMGVOFF1
* (rw) NH
* (rw) IMGHOFF1
*
\******************************************************************************/
  #define _VP_VDIMGOFF1_OFFSET             136

  #define _VP_VDIMGOFF10_ADDR   (_VP_BASE_PORT0 + 4*_VP_VDIMGOFF1_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDIMGOFF11_ADDR   (_VP_BASE_PORT1 + 4*_VP_VDIMGOFF1_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDIMGOFF12_ADDR   (_VP_BASE_PORT2 + 4*_VP_VDIMGOFF1_OFFSET)
 #endif


  #define _VP_VDIMGOFF1_NV_MASK            0x80000000u
  #define _VP_VDIMGOFF1_NV_SHIFT           0x0000001Fu
  #define  VP_VDIMGOFF1_NV_DEFAULT         0x00000000u
  #define  VP_VDIMGOFF1_NV_OF(x)           _VALUEOF(x)
  #define  VP_VDIMGOFF1_NV_NONE            0x00000000u
  #define  VP_VDIMGOFF1_NV_NEGOFF          0x00000001u

  #define _VP_VDIMGOFF1_IMGVOFF1_MASK      0x0FFF0000u
  #define _VP_VDIMGOFF1_IMGVOFF1_SHIFT     0x00000010u
  #define  VP_VDIMGOFF1_IMGVOFF1_DEFAULT   0x00000000u
  #define  VP_VDIMGOFF1_IMGVOFF1_OF(x)     _VALUEOF(x)

  #define _VP_VDIMGOFF1_NH_MASK            0x00008000u
  #define _VP_VDIMGOFF1_NH_SHIFT           0x0000000Fu
  #define  VP_VDIMGOFF1_NH_DEFAULT         0x00000000u
  #define  VP_VDIMGOFF1_NH_OF(x)           _VALUEOF(x)
  #define  VP_VDIMGOFF1_NH_NONE            0x00000000u
  #define  VP_VDIMGOFF1_NH_NEGOFF          0x00000001u

  #define _VP_VDIMGOFF1_IMGHOFF1_MASK      0x00000FFFu
  #define _VP_VDIMGOFF1_IMGHOFF1_SHIFT     0x00000000u
  #define  VP_VDIMGOFF1_IMGHOFF1_DEFAULT   0x00000000u
  #define  VP_VDIMGOFF1_IMGHOFF1_OF(x)     _VALUEOF(x)

  #define  VP_VDIMGOFF1_OF(x)            _VALUEOF(x)

  #define VP_VDIMGOFF1_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VDIMGOFF1,NV)\
    |_PER_FDEFAULT(VP,VDIMGOFF1,IMGVOFF1)\
    |_PER_FDEFAULT(VP,VDIMGOFF1,NH)\
    |_PER_FDEFAULT(VP,VDIMGOFF1,IMGHOFF1)\
  )

  #define VP_VDIMGOFF1_RMK(nv,imgvoff1,nh,imghoff1) (Uint32)(\
     _PER_FMK(VP,VDIMGOFF1,NV,nv)\
    |_PER_FMK(VP,VDIMGOFF1,IMGVOFF1,imgvoff1)\
    |_PER_FMK(VP,VDIMGOFF1,NH,nh)\
    |_PER_FMK(VP,VDIMGOFF1,IMGHOFF1,imghoff1)\
  )

  #define _VP_VDIMGOFF1_FGET(N,FIELD)\
    _PER_FGET(_VP_VDIMGOFF1##N##_ADDR,VP,VDIMGOFF1,##FIELD)

  #define _VP_VDIMGOFF1_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VDIMGOFF1##N##_ADDR,VP,VDIMGOFF1,##FIELD,field)

  #define _VP_VDIMGOFF1_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VDIMGOFF1##N##_ADDR,VP,VDIMGOFF1,##FIELD,##SYM)

  #define _VP_VDIMGOFF10_FGET(FIELD)   _VP_VDIMGOFF1_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDIMGOFF11_FGET(FIELD)   _VP_VDIMGOFF1_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDIMGOFF12_FGET(FIELD)   _VP_VDIMGOFF1_FGET(2,##FIELD)
 #endif


  #define _VP_VDIMGOFF10_FSET(FIELD,f)   _VP_VDIMGOFF1_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDIMGOFF11_FSET(FIELD,f)   _VP_VDIMGOFF1_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDIMGOFF12_FSET(FIELD,f)   _VP_VDIMGOFF1_FSET(2,##FIELD,f)
 #endif


  #define _VP_VDIMGOFF10_FSETS(FIELD,SYM)   _VP_VDIMGOFF1_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDIMGOFF11_FSETS(FIELD,SYM)   _VP_VDIMGOFF1_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDIMGOFF12_FSETS(FIELD,SYM)   _VP_VDIMGOFF1_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V D I M G S Z 1  |
* |___________________|
*
* VDIMGSZ10 -  Video Port 0 Video Display Image Size - Field 1
* VDIMGSZ11 -  Video Port 1 Video Display Image Size - Field 1
* VDIMGSZ12 -  Video Port 2 Video Display Image Size - Field 1
*
* FIELDS (msb -> lsb)
* (rw) IMGVSIZE1
* (rw) IMGHSIZE1
*
\******************************************************************************/
  #define _VP_VDIMGSZ1_OFFSET           137

  #define _VP_VDIMGSZ10_ADDR   (_VP_BASE_PORT0 + 4*_VP_VDIMGSZ1_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDIMGSZ11_ADDR   (_VP_BASE_PORT1 + 4*_VP_VDIMGSZ1_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDIMGSZ12_ADDR   (_VP_BASE_PORT2 + 4*_VP_VDIMGSZ1_OFFSET)
 #endif


  #define _VP_VDIMGSZ1_IMGVSIZE1_MASK        0x0FFF0000u
  #define _VP_VDIMGSZ1_IMGVSIZE1_SHIFT       0x00000010u
  #define  VP_VDIMGSZ1_IMGVSIZE1_DEFAULT     0x00000000u
  #define  VP_VDIMGSZ1_IMGVSIZE1_OF(x)       _VALUEOF(x)

  #define _VP_VDIMGSZ1_IMGHSIZE1_MASK        0x00000FFFu
  #define _VP_VDIMGSZ1_IMGHSIZE1_SHIFT       0x00000000u
  #define  VP_VDIMGSZ1_IMGHSIZE1_DEFAULT     0x00000000u
  #define  VP_VDIMGSZ1_IMGHSIZE1_OF(x)       _VALUEOF(x)

  #define  VP_VDIMGSZ1_OF(x)            _VALUEOF(x)

  #define VP_VDIMGSZ1_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VDIMGSZ1,IMGVSIZE1)\
    |_PER_FDEFAULT(VP,VDIMGSZ1,IMGHSIZE1)\
  )

  #define VP_VDIMGSZ1_RMK(imgvsize1,imghsize1) (Uint32)(\
     _PER_FMK(VP,VDIMGSZ1,IMGVSIZE1,imgvsize1)\
    |_PER_FMK(VP,VDIMGSZ1,IMGHSIZE1,imghsize1)\
  )

  #define _VP_VDIMGSZ1_FGET(N,FIELD)\
    _PER_FGET(_VP_VDIMGSZ1##N##_ADDR,VP,VDIMGSZ1,##FIELD)

  #define _VP_VDIMGSZ1_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VDIMGSZ1##N##_ADDR,VP,VDIMGSZ1,##FIELD,field)

  #define _VP_VDIMGSZ1_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VDIMGSZ1##N##_ADDR,VP,VDIMGSZ1,##FIELD,##SYM)

  #define _VP_VDIMGSZ10_FGET(FIELD)   _VP_VDIMGSZ1_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDIMGSZ11_FGET(FIELD)   _VP_VDIMGSZ1_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDIMGSZ12_FGET(FIELD)   _VP_VDIMGSZ1_FGET(2,##FIELD)
 #endif


  #define _VP_VDIMGSZ10_FSET(FIELD,f)   _VP_VDIMGSZ1_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDIMGSZ11_FSET(FIELD,f)   _VP_VDIMGSZ1_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDIMGSZ12_FSET(FIELD,f)   _VP_VDIMGSZ1_FSET(2,##FIELD,f)
 #endif


  #define _VP_VDIMGSZ10_FSETS(FIELD,SYM)   _VP_VDIMGSZ1_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDIMGSZ11_FSETS(FIELD,SYM)   _VP_VDIMGSZ1_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDIMGSZ12_FSETS(FIELD,SYM)   _VP_VDIMGSZ1_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* ______________________
* |                    |
* |  V D I M G O F F 2 |
* |____________________|
*
* VDIMGOFF20    -  Video Port 0 Video Display Image Offset - Field 2
* VDIMGOFF21    -  Video Port 1 Video Display Image Offset - Field 2
* VDIMGOFF22    -  Video Port 2 Video Display Image Offset - Field 2
*
* FIELDS (msb -> lsb)
* (rw) NV
* (rw) IMGVOFF2
* (rw) NH
* (rw) IMGHOFF2
*
\******************************************************************************/
  #define _VP_VDIMGOFF2_OFFSET           138

  #define _VP_VDIMGOFF20_ADDR   (_VP_BASE_PORT0 + 4*_VP_VDIMGOFF2_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDIMGOFF21_ADDR   (_VP_BASE_PORT1 + 4*_VP_VDIMGOFF2_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDIMGOFF22_ADDR   (_VP_BASE_PORT2 + 4*_VP_VDIMGOFF2_OFFSET)
 #endif


  #define _VP_VDIMGOFF2_NV_MASK            0x80000000u
  #define _VP_VDIMGOFF2_NV_SHIFT           0x0000001Fu
  #define  VP_VDIMGOFF2_NV_DEFAULT         0x00000000u
  #define  VP_VDIMGOFF2_NV_OF(x)           _VALUEOF(x)
  #define  VP_VDIMGOFF2_NV_NONE            0x00000000u
  #define  VP_VDIMGOFF2_NV_NEGOFF          0x00000001u

  #define _VP_VDIMGOFF2_IMGVOFF2_MASK        0x0FFF0000u
  #define _VP_VDIMGOFF2_IMGVOFF2_SHIFT       0x00000010u
  #define  VP_VDIMGOFF2_IMGVOFF2_DEFAULT     0x00000000u
  #define  VP_VDIMGOFF2_IMGVOFF2_OF(x)       _VALUEOF(x)

  #define _VP_VDIMGOFF2_NH_MASK            0x00008000u
  #define _VP_VDIMGOFF2_NH_SHIFT           0x0000000Fu
  #define  VP_VDIMGOFF2_NH_DEFAULT         0x00000000u
  #define  VP_VDIMGOFF2_NH_OF(x)           _VALUEOF(x)
  #define  VP_VDIMGOFF2_NH_NONE            0x00000000u
  #define  VP_VDIMGOFF2_NH_NEGOFF          0x00000001u

  #define _VP_VDIMGOFF2_IMGHOFF2_MASK        0x00000FFFu
  #define _VP_VDIMGOFF2_IMGHOFF2_SHIFT       0x00000000u
  #define  VP_VDIMGOFF2_IMGHOFF2_DEFAULT     0x00000000u
  #define  VP_VDIMGOFF2_IMGHOFF2_OF(x)       _VALUEOF(x)

  #define  VP_VDIMGOFF2_OF(x)            _VALUEOF(x)

  #define VP_VDIMGOFF2_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VDIMGOFF2,NV)\
    |_PER_FDEFAULT(VP,VDIMGOFF2,IMGVOFF2)\
    |_PER_FDEFAULT(VP,VDIMGOFF2,NH)\
    |_PER_FDEFAULT(VP,VDIMGOFF2,IMGHOFF2)\
  )

  #define VP_VDIMGOFF2_RMK(nv,imgvoff2,nh,imghoff2) (Uint32)(\
     _PER_FMK(VP,VDIMGOFF2,NV,nv)\
    |_PER_FMK(VP,VDIMGOFF2,IMGVOFF2,imgvoff2)\
    |_PER_FMK(VP,VDIMGOFF2,NH,nh)\
    |_PER_FMK(VP,VDIMGOFF2,IMGHOFF2,imghoff2)\
  )

  #define _VP_VDIMGOFF2_FGET(N,FIELD)\
    _PER_FGET(_VP_VDIMGOFF2##N##_ADDR,VP,VDIMGOFF2,##FIELD)

  #define _VP_VDIMGOFF2_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VDIMGOFF2##N##_ADDR,VP,VDIMGOFF2,##FIELD,field)

  #define _VP_VDIMGOFF2_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VDIMGOFF2##N##_ADDR,VP,VDIMGOFF2,##FIELD,##SYM)

  #define _VP_VDIMGOFF20_FGET(FIELD)   _VP_VDIMGOFF2_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDIMGOFF21_FGET(FIELD)   _VP_VDIMGOFF2_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDIMGOFF22_FGET(FIELD)   _VP_VDIMGOFF2_FGET(2,##FIELD)
 #endif


  #define _VP_VDIMGOFF20_FSET(FIELD,f)   _VP_VDIMGOFF2_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDIMGOFF21_FSET(FIELD,f)   _VP_VDIMGOFF2_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDIMGOFF22_FSET(FIELD,f)   _VP_VDIMGOFF2_FSET(2,##FIELD,f)
 #endif


  #define _VP_VDIMGOFF20_FSETS(FIELD,SYM)   _VP_VDIMGOFF2_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDIMGOFF21_FSETS(FIELD,SYM)   _VP_VDIMGOFF2_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDIMGOFF22_FSETS(FIELD,SYM)   _VP_VDIMGOFF2_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V D I M G S Z 2  |
* |___________________|
*
* VDIMGSZ20 -  Video Port 0 Video Display Image Size - Field 2
* VDIMGSZ21 -  Video Port 1 Video Display Image Size - Field 2
* VDIMGSZ22 -  Video Port 2 Video Display Image Size - Field 2
*
* FIELDS (msb -> lsb)
* (rw) IMGVSIZE2
* (rw) IMGHSIZE2
*
\******************************************************************************/
  #define _VP_VDIMGSZ2_OFFSET           139

  #define _VP_VDIMGSZ20_ADDR   (_VP_BASE_PORT0 + 4*_VP_VDIMGSZ2_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDIMGSZ21_ADDR   (_VP_BASE_PORT1 + 4*_VP_VDIMGSZ2_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDIMGSZ22_ADDR   (_VP_BASE_PORT2 + 4*_VP_VDIMGSZ2_OFFSET)
 #endif


  #define _VP_VDIMGSZ2_IMGVSIZE2_MASK        0x0FFF0000u
  #define _VP_VDIMGSZ2_IMGVSIZE2_SHIFT       0x00000010u
  #define  VP_VDIMGSZ2_IMGVSIZE2_DEFAULT     0x00000000u
  #define  VP_VDIMGSZ2_IMGVSIZE2_OF(x)       _VALUEOF(x)

  #define _VP_VDIMGSZ2_IMGHSIZE2_MASK        0x00000FFFu
  #define _VP_VDIMGSZ2_IMGHSIZE2_SHIFT       0x00000000u
  #define  VP_VDIMGSZ2_IMGHSIZE2_DEFAULT     0x00000000u
  #define  VP_VDIMGSZ2_IMGHSIZE2_OF(x)       _VALUEOF(x)

  #define  VP_VDIMGSZ2_OF(x)            _VALUEOF(x)

  #define VP_VDIMGSZ2_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VDIMGSZ2,IMGVSIZE2)\
    |_PER_FDEFAULT(VP,VDIMGSZ2,IMGHSIZE2)\
  )

  #define VP_VDIMGSZ2_RMK(imgvsize2,imghsize2) (Uint32)(\
     _PER_FMK(VP,VDIMGSZ2,IMGVSIZE2,imgvsize2)\
    |_PER_FMK(VP,VDIMGSZ2,IMGHSIZE2,imghsize2)\
  )

  #define _VP_VDIMGSZ2_FGET(N,FIELD)\
    _PER_FGET(_VP_VDIMGSZ2##N##_ADDR,VP,VDIMGSZ2,##FIELD)

  #define _VP_VDIMGSZ2_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VDIMGSZ2##N##_ADDR,VP,VDIMGSZ2,##FIELD,field)

  #define _VP_VDIMGSZ2_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VDIMGSZ2##N##_ADDR,VP,VDIMGSZ2,##FIELD,##SYM)

  #define _VP_VDIMGSZ20_FGET(FIELD)   _VP_VDIMGSZ2_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDIMGSZ21_FGET(FIELD)   _VP_VDIMGSZ2_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDIMGSZ22_FGET(FIELD)   _VP_VDIMGSZ2_FGET(2,##FIELD)
 #endif


  #define _VP_VDIMGSZ20_FSET(FIELD,f)   _VP_VDIMGSZ2_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDIMGSZ21_FSET(FIELD,f)   _VP_VDIMGSZ2_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDIMGSZ22_FSET(FIELD,f)   _VP_VDIMGSZ2_FSET(2,##FIELD,f)
 #endif


  #define _VP_VDIMGSZ20_FSETS(FIELD,SYM)   _VP_VDIMGSZ2_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDIMGSZ21_FSETS(FIELD,SYM)   _VP_VDIMGSZ2_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDIMGSZ22_FSETS(FIELD,SYM)   _VP_VDIMGSZ2_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V D F L D T 1    |
* |___________________|
*
* VDFLDT10 -  Video Port 0 Video Display Field1 Timing
* VDFLDT11 -  Video Port 1 Video Display Field1 Timing
* VDFLDT12 -  Video Port 2 Video Display Field1 Timing
*
* FIELDS (msb -> lsb)
* (rw) FLD1YSTART
* (rw) FLD1XSTART
*
\******************************************************************************/
  #define _VP_VDFLDT1_OFFSET           140

  #define _VP_VDFLDT10_ADDR   (_VP_BASE_PORT0 + 4*_VP_VDFLDT1_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDFLDT11_ADDR   (_VP_BASE_PORT1 + 4*_VP_VDFLDT1_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDFLDT12_ADDR   (_VP_BASE_PORT2 + 4*_VP_VDFLDT1_OFFSET)
 #endif


  #define _VP_VDFLDT1_FLD1YSTART_MASK        0x0FFF0000u
  #define _VP_VDFLDT1_FLD1YSTART_SHIFT       0x00000010u
  #define  VP_VDFLDT1_FLD1YSTART_DEFAULT     0x00000000u
  #define  VP_VDFLDT1_FLD1YSTART_OF(x)       _VALUEOF(x)

  #define _VP_VDFLDT1_FLD1XSTART_MASK        0x00000FFFu
  #define _VP_VDFLDT1_FLD1XSTART_SHIFT       0x00000000u
  #define  VP_VDFLDT1_FLD1XSTART_DEFAULT     0x00000000u
  #define  VP_VDFLDT1_FLD1XSTART_OF(x)       _VALUEOF(x)

  #define  VP_VDFLDT1_OF(x)            _VALUEOF(x)

  #define VP_VDFLDT1_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VDFLDT1,FLD1YSTART)\
    |_PER_FDEFAULT(VP,VDFLDT1,FLD1XSTART)\
  )

  #define VP_VDFLDT1_RMK(fld1ystart,fld1xstart) (Uint32)(\
     _PER_FMK(VP,VDFLDT1,FLD1YSTART,fld1ystart)\
    |_PER_FMK(VP,VDFLDT1,FLD1XSTART,fld1xstart)\
  )

  #define _VP_VDFLDT1_FGET(N,FIELD)\
    _PER_FGET(_VP_VDFLDT1##N##_ADDR,VP,VDFLDT1,##FIELD)

  #define _VP_VDFLDT1_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VDFLDT1##N##_ADDR,VP,VDFLDT1,##FIELD,field)

  #define _VP_VDFLDT1_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VDFLDT1##N##_ADDR,VP,VDFLDT1,##FIELD,##SYM)

  #define _VP_VDFLDT10_FGET(FIELD)   _VP_VDFLDT1_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDFLDT11_FGET(FIELD)   _VP_VDFLDT1_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDFLDT12_FGET(FIELD)   _VP_VDFLDT1_FGET(2,##FIELD)
 #endif


  #define _VP_VDFLDT10_FSET(FIELD,f)   _VP_VDFLDT1_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDFLDT11_FSET(FIELD,f)   _VP_VDFLDT1_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDFLDT12_FSET(FIELD,f)   _VP_VDFLDT1_FSET(2,##FIELD,f)
 #endif


  #define _VP_VDFLDT10_FSETS(FIELD,SYM)   _VP_VDFLDT1_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDFLDT11_FSETS(FIELD,SYM)   _VP_VDFLDT1_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDFLDT12_FSETS(FIELD,SYM)   _VP_VDFLDT1_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V D F L D T 2    |
* |___________________|
*
* VDFLDT20 -  Video Port 0 Video Display Field2 Timing
* VDFLDT21 -  Video Port 1 Video Display Field2 Timing
* VDFLDT22 -  Video Port 2 Video Display Field2 Timing
*
* FIELDS (msb -> lsb)
* (rw) FLD2YSTART
* (rw) FLD2XSTART
*
\******************************************************************************/
  #define _VP_VDFLDT2_OFFSET           141

  #define _VP_VDFLDT20_ADDR   (_VP_BASE_PORT0 + 4*_VP_VDFLDT2_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDFLDT21_ADDR   (_VP_BASE_PORT1 + 4*_VP_VDFLDT2_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDFLDT22_ADDR   (_VP_BASE_PORT2 + 4*_VP_VDFLDT2_OFFSET)
 #endif


  #define _VP_VDFLDT2_FLD2YSTART_MASK        0x0FFF0000u
  #define _VP_VDFLDT2_FLD2YSTART_SHIFT       0x00000010u
  #define  VP_VDFLDT2_FLD2YSTART_DEFAULT     0x00000000u
  #define  VP_VDFLDT2_FLD2YSTART_OF(x)       _VALUEOF(x)

  #define _VP_VDFLDT2_FLD2XSTART_MASK        0x00000FFFu
  #define _VP_VDFLDT2_FLD2XSTART_SHIFT       0x00000000u
  #define  VP_VDFLDT2_FLD2XSTART_DEFAULT     0x00000000u
  #define  VP_VDFLDT2_FLD2XSTART_OF(x)       _VALUEOF(x)

  #define  VP_VDFLDT2_OF(x)            _VALUEOF(x)

  #define VP_VDFLDT2_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VDFLDT2,FLD2YSTART)\
    |_PER_FDEFAULT(VP,VDFLDT2,FLD2XSTART)\
  )

  #define VP_VDFLDT2_RMK(fld2ystart,fld2xstart) (Uint32)(\
     _PER_FMK(VP,VDFLDT2,FLD2YSTART,fld2ystart)\
    |_PER_FMK(VP,VDFLDT2,FLD2XSTART,fld2xstart)\
  )

  #define _VP_VDFLDT2_FGET(N,FIELD)\
    _PER_FGET(_VP_VDFLDT2##N##_ADDR,VP,VDFLDT2,##FIELD)

  #define _VP_VDFLDT2_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VDFLDT2##N##_ADDR,VP,VDFLDT2,##FIELD,field)

  #define _VP_VDFLDT2_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VDFLDT2##N##_ADDR,VP,VDFLDT2,##FIELD,##SYM)

  #define _VP_VDFLDT20_FGET(FIELD)   _VP_VDFLDT2_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDFLDT21_FGET(FIELD)   _VP_VDFLDT2_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDFLDT22_FGET(FIELD)   _VP_VDFLDT2_FGET(2,##FIELD)
 #endif


  #define _VP_VDFLDT20_FSET(FIELD,f)   _VP_VDFLDT2_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDFLDT21_FSET(FIELD,f)   _VP_VDFLDT2_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDFLDT22_FSET(FIELD,f)   _VP_VDFLDT2_FSET(2,##FIELD,f)
 #endif


  #define _VP_VDFLDT20_FSETS(FIELD,SYM)   _VP_VDFLDT2_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDFLDT21_FSETS(FIELD,SYM)   _VP_VDFLDT2_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDFLDT22_FSETS(FIELD,SYM)   _VP_VDFLDT2_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V D T H R L D    |
* |___________________|
*
* VDTHRLD0 -  Video Port 0 Video Display Threshold
* VDTHRLD1 -  Video Port 1 Video Display Threshold
* VDTHRLD2 -  Video Port 2 Video Display Threshold
*
* FIELDS (msb -> lsb)
* (rw) VDTHRLD2
* (rw) INCPIX
* (rw) VDTHRLD1
*
\******************************************************************************/
  #define _VP_VDTHRLD_OFFSET           142

  #define _VP_VDTHRLD0_ADDR   (_VP_BASE_PORT0 + 4*_VP_VDTHRLD_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDTHRLD1_ADDR   (_VP_BASE_PORT1 + 4*_VP_VDTHRLD_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDTHRLD2_ADDR   (_VP_BASE_PORT2 + 4*_VP_VDTHRLD_OFFSET)
 #endif


  #define _VP_VDTHRLD_VDTHRLD2_MASK        0x03FF0000u
  #define _VP_VDTHRLD_VDTHRLD2_SHIFT       0x00000010u
  #define  VP_VDTHRLD_VDTHRLD2_DEFAULT     0x00000000u
  #define  VP_VDTHRLD_VDTHRLD2_OF(x)       _VALUEOF(x)

  #define _VP_VDTHRLD_INCPIX_MASK        0x0000F000u
  #define _VP_VDTHRLD_INCPIX_SHIFT       0x0000000Cu
  #define  VP_VDTHRLD_INCPIX_DEFAULT     0x00000001u
  #define  VP_VDTHRLD_INCPIX_OF(x)       _VALUEOF(x)

  #define _VP_VDTHRLD_VDTHRLD1_MASK        0x000003FFu
  #define _VP_VDTHRLD_VDTHRLD1_SHIFT       0x00000000u
  #define  VP_VDTHRLD_VDTHRLD1_DEFAULT     0x00000000u
  #define  VP_VDTHRLD_VDTHRLD1_OF(x)       _VALUEOF(x)

  #define  VP_VDTHRLD_OF(x)            _VALUEOF(x)

  #define VP_VDTHRLD_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VDTHRLD,VDTHRLD2)\
    |_PER_FDEFAULT(VP,VDTHRLD,INCPIX)\
    |_PER_FDEFAULT(VP,VDTHRLD,VDTHRLD1)\
  )

  #define VP_VDTHRLD_RMK(vdthrld2,incpix,vdthrld1) (Uint32)(\
     _PER_FMK(VP,VDTHRLD,VDTHRLD2,vdthrld2)\
    |_PER_FMK(VP,VDTHRLD,INCPIX,incpix)\
    |_PER_FMK(VP,VDTHRLD,VDTHRLD1,vdthrld1)\
  )

  #define _VP_VDTHRLD_FGET(N,FIELD)\
    _PER_FGET(_VP_VDTHRLD##N##_ADDR,VP,VDTHRLD,##FIELD)

  #define _VP_VDTHRLD_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VDTHRLD##N##_ADDR,VP,VDTHRLD,##FIELD,field)

  #define _VP_VDTHRLD_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VDTHRLD##N##_ADDR,VP,VDTHRLD,##FIELD,##SYM)

  #define _VP_VDTHRLD0_FGET(FIELD)   _VP_VDTHRLD_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDTHRLD1_FGET(FIELD)   _VP_VDTHRLD_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDTHRLD2_FGET(FIELD)   _VP_VDTHRLD_FGET(2,##FIELD)
 #endif


  #define _VP_VDTHRLD0_FSET(FIELD,f)   _VP_VDTHRLD_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDTHRLD1_FSET(FIELD,f)   _VP_VDTHRLD_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDTHRLD2_FSET(FIELD,f)   _VP_VDTHRLD_FSET(2,##FIELD,f)
 #endif


  #define _VP_VDTHRLD0_FSETS(FIELD,SYM)   _VP_VDTHRLD_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDTHRLD1_FSETS(FIELD,SYM)   _VP_VDTHRLD_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDTHRLD2_FSETS(FIELD,SYM)   _VP_VDTHRLD_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V D H S Y N C    |
* |___________________|
*
* VDHSYNC0 -  Video Port 0 Video Display Horizontal Sync
* VDHSYNC1 -  Video Port 1 Video Display Horizontal Sync
* VDHSYNC2 -  Video Port 2 Video Display Horizontal Sync
*
* FIELDS (msb -> lsb)
* (rw) HSYNCSTOP
* (rw) HSYNCSTART
*
\******************************************************************************/
  #define _VP_VDHSYNC_OFFSET           143

  #define _VP_VDHSYNC0_ADDR   (_VP_BASE_PORT0 + 4*_VP_VDHSYNC_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDHSYNC1_ADDR   (_VP_BASE_PORT1 + 4*_VP_VDHSYNC_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDHSYNC2_ADDR   (_VP_BASE_PORT2 + 4*_VP_VDHSYNC_OFFSET)
 #endif


  #define _VP_VDHSYNC_HSYNCSTOP_MASK        0x0FFF0000u
  #define _VP_VDHSYNC_HSYNCSTOP_SHIFT       0x00000010u
  #define  VP_VDHSYNC_HSYNCSTOP_DEFAULT     0x00000000u
  #define  VP_VDHSYNC_HSYNCSTOP_OF(x)       _VALUEOF(x)

  #define _VP_VDHSYNC_HSYNCSTART_MASK        0x00000FFFu
  #define _VP_VDHSYNC_HSYNCSTART_SHIFT       0x00000000u
  #define  VP_VDHSYNC_HSYNCSTART_DEFAULT     0x00000000u
  #define  VP_VDHSYNC_HSYNCSTART_OF(x)       _VALUEOF(x)

  #define  VP_VDHSYNC_OF(x)            _VALUEOF(x)

  #define VP_VDHSYNC_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VDHSYNC,HSYNCSTOP)\
    |_PER_FDEFAULT(VP,VDHSYNC,HSYNCSTART)\
  )

  #define VP_VDHSYNC_RMK(hsyncstop,hsyncstart) (Uint32)(\
     _PER_FMK(VP,VDHSYNC,HSYNCSTOP,hsyncstop)\
    |_PER_FMK(VP,VDHSYNC,HSYNCSTART,hsyncstart)\
  )

  #define _VP_VDHSYNC_FGET(N,FIELD)\
    _PER_FGET(_VP_VDHSYNC##N##_ADDR,VP,VDHSYNC,##FIELD)

  #define _VP_VDHSYNC_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VDHSYNC##N##_ADDR,VP,VDHSYNC,##FIELD,field)

  #define _VP_VDHSYNC_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VDHSYNC##N##_ADDR,VP,VDHSYNC,##FIELD,##SYM)

  #define _VP_VDHSYNC0_FGET(FIELD)   _VP_VDHSYNC_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDHSYNC1_FGET(FIELD)   _VP_VDHSYNC_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDHSYNC2_FGET(FIELD)   _VP_VDHSYNC_FGET(2,##FIELD)
 #endif


  #define _VP_VDHSYNC0_FSET(FIELD,f)   _VP_VDHSYNC_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDHSYNC1_FSET(FIELD,f)   _VP_VDHSYNC_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDHSYNC2_FSET(FIELD,f)   _VP_VDHSYNC_FSET(2,##FIELD,f)
 #endif


  #define _VP_VDHSYNC0_FSETS(FIELD,SYM)   _VP_VDHSYNC_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDHSYNC1_FSETS(FIELD,SYM)   _VP_VDHSYNC_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDHSYNC2_FSETS(FIELD,SYM)   _VP_VDHSYNC_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V D V S Y N S 1  |
* |___________________|
*
* VDVSYNS10 -  Video Port 0 Video Display Vertical Sync. Start - Field 1
* VDVSYNS11 -  Video Port 1 Video Display Vertical Sync. Start - Field 1
* VDVSYNS12 -  Video Port 2 Video Display Vertical Sync. Start - Field 1
*
* FIELDS (msb -> lsb)
* (rw) VSYNCYSTART1
* (rw) VSYNCXSTART1
*
\******************************************************************************/
  #define _VP_VDVSYNS1_OFFSET           144

  #define _VP_VDVSYNS10_ADDR   (_VP_BASE_PORT0 + 4*_VP_VDVSYNS1_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVSYNS11_ADDR   (_VP_BASE_PORT1 + 4*_VP_VDVSYNS1_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVSYNS12_ADDR   (_VP_BASE_PORT2 + 4*_VP_VDVSYNS1_OFFSET)
 #endif


  #define _VP_VDVSYNS1_VSYNCYSTART1_MASK        0x0FFF0000u
  #define _VP_VDVSYNS1_VSYNCYSTART1_SHIFT       0x00000010u
  #define  VP_VDVSYNS1_VSYNCYSTART1_DEFAULT     0x00000000u
  #define  VP_VDVSYNS1_VSYNCYSTART1_OF(x)       _VALUEOF(x)

  #define _VP_VDVSYNS1_VSYNCXSTART1_MASK        0x00000FFFu
  #define _VP_VDVSYNS1_VSYNCXSTART1_SHIFT       0x00000000u
  #define  VP_VDVSYNS1_VSYNCXSTART1_DEFAULT     0x00000000u
  #define  VP_VDVSYNS1_VSYNCXSTART1_OF(x)       _VALUEOF(x)

  #define  VP_VDVSYNS1_OF(x)            _VALUEOF(x)

  #define VP_VDVSYNS1_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VDVSYNS1,VSYNCYSTART1)\
    |_PER_FDEFAULT(VP,VDVSYNS1,VSYNCXSTART1)\
  )

  #define VP_VDVSYNS1_RMK(vsyncystart1,vsyncxstart1) (Uint32)(\
     _PER_FMK(VP,VDVSYNS1,VSYNCYSTART1,vsyncystart1)\
    |_PER_FMK(VP,VDVSYNS1,VSYNCXSTART1,vsyncxstart1)\
  )

  #define _VP_VDVSYNS1_FGET(N,FIELD)\
    _PER_FGET(_VP_VDVSYNS1##N##_ADDR,VP,VDVSYNS1,##FIELD)

  #define _VP_VDVSYNS1_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VDVSYNS1##N##_ADDR,VP,VDVSYNS1,##FIELD,field)

  #define _VP_VDVSYNS1_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VDVSYNS1##N##_ADDR,VP,VDVSYNS1,##FIELD,##SYM)

  #define _VP_VDVSYNS10_FGET(FIELD)   _VP_VDVSYNS1_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVSYNS11_FGET(FIELD)   _VP_VDVSYNS1_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVSYNS12_FGET(FIELD)   _VP_VDVSYNS1_FGET(2,##FIELD)
 #endif


  #define _VP_VDVSYNS10_FSET(FIELD,f)   _VP_VDVSYNS1_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVSYNS11_FSET(FIELD,f)   _VP_VDVSYNS1_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVSYNS12_FSET(FIELD,f)   _VP_VDVSYNS1_FSET(2,##FIELD,f)
 #endif


  #define _VP_VDVSYNS10_FSETS(FIELD,SYM)   _VP_VDVSYNS1_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVSYNS11_FSETS(FIELD,SYM)   _VP_VDVSYNS1_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVSYNS12_FSETS(FIELD,SYM)   _VP_VDVSYNS1_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V D V S Y N E 1  |
* |___________________|
*
* VDVSYNE10 -  Video Port 0 Video Display Vertical Sync. End - Field 1
* VDVSYNE11 -  Video Port 1 Video Display Vertical Sync. End - Field 1
* VDVSYNE12 -  Video Port 2 Video Display Vertical Sync. End - Field 1
*
* FIELDS (msb -> lsb)
* (rw) VSYNCYSTOP1
* (rw) VSYNCXSTOP1
*
\******************************************************************************/
  #define _VP_VDVSYNE1_OFFSET           145

  #define _VP_VDVSYNE10_ADDR   (_VP_BASE_PORT0 + 4*_VP_VDVSYNE1_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVSYNE11_ADDR   (_VP_BASE_PORT1 + 4*_VP_VDVSYNE1_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVSYNE12_ADDR   (_VP_BASE_PORT2 + 4*_VP_VDVSYNE1_OFFSET)
 #endif


  #define _VP_VDVSYNE1_VSYNCYSTOP1_MASK        0x0FFF0000u
  #define _VP_VDVSYNE1_VSYNCYSTOP1_SHIFT       0x00000010u
  #define  VP_VDVSYNE1_VSYNCYSTOP1_DEFAULT     0x00000000u
  #define  VP_VDVSYNE1_VSYNCYSTOP1_OF(x)       _VALUEOF(x)

  #define _VP_VDVSYNE1_VSYNCXSTOP1_MASK        0x00000FFFu
  #define _VP_VDVSYNE1_VSYNCXSTOP1_SHIFT       0x00000000u
  #define  VP_VDVSYNE1_VSYNCXSTOP1_DEFAULT     0x00000000u
  #define  VP_VDVSYNE1_VSYNCXSTOP1_OF(x)       _VALUEOF(x)

  #define  VP_VDVSYNE1_OF(x)            _VALUEOF(x)

  #define VP_VDVSYNE1_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VDVSYNE1,VSYNCYSTOP1)\
    |_PER_FDEFAULT(VP,VDVSYNE1,VSYNCXSTOP1)\
  )

  #define VP_VDVSYNE1_RMK(vsyncystop1,vsyncxstop1) (Uint32)(\
     _PER_FMK(VP,VDVSYNE1,VSYNCYSTOP1,vsyncystop1)\
    |_PER_FMK(VP,VDVSYNE1,VSYNCXSTOP1,vsyncxstop1)\
  )

  #define _VP_VDVSYNE1_FGET(N,FIELD)\
    _PER_FGET(_VP_VDVSYNE1##N##_ADDR,VP,VDVSYNE1,##FIELD)

  #define _VP_VDVSYNE1_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VDVSYNE1##N##_ADDR,VP,VDVSYNE1,##FIELD,field)

  #define _VP_VDVSYNE1_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VDVSYNE1##N##_ADDR,VP,VDVSYNE1,##FIELD,##SYM)

  #define _VP_VDVSYNE10_FGET(FIELD)   _VP_VDVSYNE1_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVSYNE11_FGET(FIELD)   _VP_VDVSYNE1_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVSYNE12_FGET(FIELD)   _VP_VDVSYNE1_FGET(2,##FIELD)
 #endif


  #define _VP_VDVSYNE10_FSET(FIELD,f)   _VP_VDVSYNE1_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVSYNE11_FSET(FIELD,f)   _VP_VDVSYNE1_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVSYNE12_FSET(FIELD,f)   _VP_VDVSYNE1_FSET(2,##FIELD,f)
 #endif


  #define _VP_VDVSYNE10_FSETS(FIELD,SYM)   _VP_VDVSYNE1_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVSYNE11_FSETS(FIELD,SYM)   _VP_VDVSYNE1_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVSYNE12_FSETS(FIELD,SYM)   _VP_VDVSYNE1_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V D V S Y N S 2  |
* |___________________|
*
* VDVSYNS20 -  Video Port 0 Video Display Vertical Sync. Start - Field 2
* VDVSYNS21 -  Video Port 1 Video Display Vertical Sync. Start - Field 2
* VDVSYNS22 -  Video Port 2 Video Display Vertical Sync. Start - Field 2
*
* FIELDS (msb -> lsb)
* (rw) VSYNCYSTART2
* (rw) VSYNCXSTART2
*
\******************************************************************************/
  #define _VP_VDVSYNS2_OFFSET           146

  #define _VP_VDVSYNS20_ADDR   (_VP_BASE_PORT0 + 4*_VP_VDVSYNS2_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVSYNS21_ADDR   (_VP_BASE_PORT1 + 4*_VP_VDVSYNS2_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVSYNS22_ADDR   (_VP_BASE_PORT2 + 4*_VP_VDVSYNS2_OFFSET)
 #endif


  #define _VP_VDVSYNS2_VSYNCYSTART2_MASK        0x0FFF0000u
  #define _VP_VDVSYNS2_VSYNCYSTART2_SHIFT       0x00000010u
  #define  VP_VDVSYNS2_VSYNCYSTART2_DEFAULT     0x00000000u
  #define  VP_VDVSYNS2_VSYNCYSTART2_OF(x)       _VALUEOF(x)

  #define _VP_VDVSYNS2_VSYNCXSTART2_MASK        0x00000FFFu
  #define _VP_VDVSYNS2_VSYNCXSTART2_SHIFT       0x00000000u
  #define  VP_VDVSYNS2_VSYNCXSTART2_DEFAULT     0x00000000u
  #define  VP_VDVSYNS2_VSYNCXSTART2_OF(x)       _VALUEOF(x)

  #define  VP_VDVSYNS2_OF(x)            _VALUEOF(x)

  #define VP_VDVSYNS2_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VDVSYNS2,VSYNCYSTART2)\
    |_PER_FDEFAULT(VP,VDVSYNS2,VSYNCXSTART2)\
  )

  #define VP_VDVSYNS2_RMK(vsyncystart2,vsyncxstart2) (Uint32)(\
     _PER_FMK(VP,VDVSYNS2,VSYNCYSTART2,vsyncystart2)\
    |_PER_FMK(VP,VDVSYNS2,VSYNCXSTART2,vsyncxstart2)\
  )

  #define _VP_VDVSYNS2_FGET(N,FIELD)\
    _PER_FGET(_VP_VDVSYNS2##N##_ADDR,VP,VDVSYNS2,##FIELD)

  #define _VP_VDVSYNS2_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VDVSYNS2##N##_ADDR,VP,VDVSYNS2,##FIELD,field)

  #define _VP_VDVSYNS2_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VDVSYNS2##N##_ADDR,VP,VDVSYNS2,##FIELD,##SYM)

  #define _VP_VDVSYNS20_FGET(FIELD)   _VP_VDVSYNS2_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVSYNS21_FGET(FIELD)   _VP_VDVSYNS2_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVSYNS22_FGET(FIELD)   _VP_VDVSYNS2_FGET(2,##FIELD)
 #endif


  #define _VP_VDVSYNS20_FSET(FIELD,f)   _VP_VDVSYNS2_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVSYNS21_FSET(FIELD,f)   _VP_VDVSYNS2_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVSYNS22_FSET(FIELD,f)   _VP_VDVSYNS2_FSET(2,##FIELD,f)
 #endif


  #define _VP_VDVSYNS20_FSETS(FIELD,SYM)   _VP_VDVSYNS2_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVSYNS21_FSETS(FIELD,SYM)   _VP_VDVSYNS2_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVSYNS22_FSETS(FIELD,SYM)   _VP_VDVSYNS2_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V D V S Y N E 2  |
* |___________________|
*
* VDVSYNE20 -  Video Port 0 Video Display Vertical Sync. End - Field 2
* VDVSYNE21 -  Video Port 1 Video Display Vertical Sync. End - Field 2
* VDVSYNE22 -  Video Port 2 Video Display Vertical Sync. End - Field 2
*
* FIELDS (msb -> lsb)
* (rw) VSYNCYSTOP2
* (rw) VSYNCXSTOP2
*
\******************************************************************************/
  #define _VP_VDVSYNE2_OFFSET           147

  #define _VP_VDVSYNE20_ADDR   (_VP_BASE_PORT0 + 4*_VP_VDVSYNE2_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVSYNE21_ADDR   (_VP_BASE_PORT1 + 4*_VP_VDVSYNE2_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVSYNE22_ADDR   (_VP_BASE_PORT2 + 4*_VP_VDVSYNE2_OFFSET)
 #endif


  #define _VP_VDVSYNE2_VSYNCYSTOP2_MASK        0x0FFF0000u
  #define _VP_VDVSYNE2_VSYNCYSTOP2_SHIFT       0x00000010u
  #define  VP_VDVSYNE2_VSYNCYSTOP2_DEFAULT     0x00000000u
  #define  VP_VDVSYNE2_VSYNCYSTOP2_OF(x)       _VALUEOF(x)

  #define _VP_VDVSYNE2_VSYNCXSTOP2_MASK        0x00000FFFu
  #define _VP_VDVSYNE2_VSYNCXSTOP2_SHIFT       0x00000000u
  #define  VP_VDVSYNE2_VSYNCXSTOP2_DEFAULT     0x00000000u
  #define  VP_VDVSYNE2_VSYNCXSTOP2_OF(x)       _VALUEOF(x)

  #define  VP_VDVSYNE2_OF(x)            _VALUEOF(x)

  #define VP_VDVSYNE2_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VDVSYNE2,VSYNCYSTOP2)\
    |_PER_FDEFAULT(VP,VDVSYNE2,VSYNCXSTOP2)\
  )

  #define VP_VDVSYNE2_RMK(vsyncystop2,vsyncxstop2) (Uint32)(\
     _PER_FMK(VP,VDVSYNE2,VSYNCYSTOP2,vsyncystop2)\
    |_PER_FMK(VP,VDVSYNE2,VSYNCXSTOP2,vsyncxstop2)\
  )

  #define _VP_VDVSYNE2_FGET(N,FIELD)\
    _PER_FGET(_VP_VDVSYNE2##N##_ADDR,VP,VDVSYNE2,##FIELD)

  #define _VP_VDVSYNE2_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VDVSYNE2##N##_ADDR,VP,VDVSYNE2,##FIELD,field)

  #define _VP_VDVSYNE2_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VDVSYNE2##N##_ADDR,VP,VDVSYNE2,##FIELD,##SYM)

  #define _VP_VDVSYNE20_FGET(FIELD)   _VP_VDVSYNE2_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVSYNE21_FGET(FIELD)   _VP_VDVSYNE2_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVSYNE22_FGET(FIELD)   _VP_VDVSYNE2_FGET(2,##FIELD)
 #endif


  #define _VP_VDVSYNE20_FSET(FIELD,f)   _VP_VDVSYNE2_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVSYNE21_FSET(FIELD,f)   _VP_VDVSYNE2_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVSYNE22_FSET(FIELD,f)   _VP_VDVSYNE2_FSET(2,##FIELD,f)
 #endif


  #define _VP_VDVSYNE20_FSETS(FIELD,SYM)   _VP_VDVSYNE2_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVSYNE21_FSETS(FIELD,SYM)   _VP_VDVSYNE2_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVSYNE22_FSETS(FIELD,SYM)   _VP_VDVSYNE2_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V D R E L O A D  |
* |___________________|
*
* VDRELOAD0 -  Video Port 0 Video Display Counter Reload
* VDRELOAD1 -  Video Port 1 Video Display Counter Reload
* VDRELOAD2 -  Video Port 2 Video Display Counter Reload
*
* FIELDS (msb -> lsb)
* (rw) VRLD
* (rw) CRLD
* (rw) HRLD
*
\******************************************************************************/
  #define _VP_VDRELOAD_OFFSET           148

  #define _VP_VDRELOAD0_ADDR   (_VP_BASE_PORT0 + 4*_VP_VDRELOAD_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDRELOAD1_ADDR   (_VP_BASE_PORT1 + 4*_VP_VDRELOAD_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDRELOAD2_ADDR   (_VP_BASE_PORT2 + 4*_VP_VDRELOAD_OFFSET)
 #endif


  #define _VP_VDRELOAD_VRLD_MASK        0x0FFF0000u
  #define _VP_VDRELOAD_VRLD_SHIFT       0x00000010u
  #define  VP_VDRELOAD_VRLD_DEFAULT     0x00000000u
  #define  VP_VDRELOAD_VRLD_OF(x)       _VALUEOF(x)

  #define _VP_VDRELOAD_CRLD_MASK        0x0000F000u
  #define _VP_VDRELOAD_CRLD_SHIFT       0x0000000Cu
  #define  VP_VDRELOAD_CRLD_DEFAULT     0x00000000u
  #define  VP_VDRELOAD_CRLD_OF(x)       _VALUEOF(x)

  #define _VP_VDRELOAD_HRLD_MASK        0x00000FFFu
  #define _VP_VDRELOAD_HRLD_SHIFT       0x00000000u
  #define  VP_VDRELOAD_HRLD_DEFAULT     0x00000000u
  #define  VP_VDRELOAD_HRLD_OF(x)       _VALUEOF(x)

  #define  VP_VDRELOAD_OF(x)            _VALUEOF(x)

  #define VP_VDRELOAD_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VDRELOAD,VRLD)\
    |_PER_FDEFAULT(VP,VDRELOAD,CRLD)\
    |_PER_FDEFAULT(VP,VDRELOAD,HRLD)\
  )

  #define VP_VDRELOAD_RMK(vrld,crld,hrld) (Uint32)(\
     _PER_FMK(VP,VDRELOAD,VRLD,vrld)\
    |_PER_FMK(VP,VDRELOAD,CRLD,crld)\
    |_PER_FMK(VP,VDRELOAD,HRLD,hrld)\
  )

  #define _VP_VDRELOAD_FGET(N,FIELD)\
    _PER_FGET(_VP_VDRELOAD##N##_ADDR,VP,VDRELOAD,##FIELD)

  #define _VP_VDRELOAD_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VDRELOAD##N##_ADDR,VP,VDRELOAD,##FIELD,field)

  #define _VP_VDRELOAD_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VDRELOAD##N##_ADDR,VP,VDRELOAD,##FIELD,##SYM)

  #define _VP_VDRELOAD0_FGET(FIELD)   _VP_VDRELOAD_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDRELOAD1_FGET(FIELD)   _VP_VDRELOAD_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDRELOAD2_FGET(FIELD)   _VP_VDRELOAD_FGET(2,##FIELD)
 #endif


  #define _VP_VDRELOAD0_FSET(FIELD,f)   _VP_VDRELOAD_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDRELOAD1_FSET(FIELD,f)   _VP_VDRELOAD_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDRELOAD2_FSET(FIELD,f)   _VP_VDRELOAD_FSET(2,##FIELD,f)
 #endif


  #define _VP_VDRELOAD0_FSETS(FIELD,SYM)   _VP_VDRELOAD_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDRELOAD1_FSETS(FIELD,SYM)   _VP_VDRELOAD_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDRELOAD2_FSETS(FIELD,SYM)   _VP_VDRELOAD_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _______________________
* |                     |
* |  V D D I S P E V T  |
* |_____________________|
*
* VDDISPEVT0 -  Video Port 0 Video Display Display Event Register
* VDDISPEVT1 -  Video Port 1 Video Display Display Event Register
* VDDISPEVT2 -  Video Port 2 Video Display Display Event Register
*
* FIELDS (msb -> lsb)
* (rw) DISPEVT2
* (rw) DISPEVT1
*
\******************************************************************************/
  #define _VP_VDDISPEVT_OFFSET           149

  #define _VP_VDDISPEVT0_ADDR   (_VP_BASE_PORT0 + 4*_VP_VDDISPEVT_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDDISPEVT1_ADDR   (_VP_BASE_PORT1 + 4*_VP_VDDISPEVT_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDDISPEVT2_ADDR   (_VP_BASE_PORT2 + 4*_VP_VDDISPEVT_OFFSET)
 #endif


  #define _VP_VDDISPEVT_DISPEVT2_MASK        0x0FFF0000u
  #define _VP_VDDISPEVT_DISPEVT2_SHIFT       0x00000010u
  #define  VP_VDDISPEVT_DISPEVT2_DEFAULT     0x00000000u
  #define  VP_VDDISPEVT_DISPEVT2_OF(x)       _VALUEOF(x)

  #define _VP_VDDISPEVT_DISPEVT1_MASK        0x00000FFFu
  #define _VP_VDDISPEVT_DISPEVT1_SHIFT       0x00000000u
  #define  VP_VDDISPEVT_DISPEVT1_DEFAULT     0x00000000u
  #define  VP_VDDISPEVT_DISPEVT1_OF(x)       _VALUEOF(x)

  #define  VP_VDDISPEVT_OF(x)            _VALUEOF(x)

  #define VP_VDDISPEVT_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VDDISPEVT,DISPEVT2)\
    |_PER_FDEFAULT(VP,VDDISPEVT,DISPEVT1)\
  )

  #define VP_VDDISPEVT_RMK(dispevt2,dispevt1) (Uint32)(\
     _PER_FMK(VP,VDDISPEVT,DISPEVT2,dispevt2)\
    |_PER_FMK(VP,VDDISPEVT,DISPEVT1,dispevt1)\
  )

  #define _VP_VDDISPEVT_FGET(N,FIELD)\
    _PER_FGET(_VP_VDDISPEVT##N##_ADDR,VP,VDDISPEVT,##FIELD)

  #define _VP_VDDISPEVT_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VDDISPEVT##N##_ADDR,VP,VDDISPEVT,##FIELD,field)

  #define _VP_VDDISPEVT_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VDDISPEVT##N##_ADDR,VP,VDDISPEVT,##FIELD,##SYM)

  #define _VP_VDDISPEVT0_FGET(FIELD)   _VP_VDDISPEVT_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDDISPEVT1_FGET(FIELD)   _VP_VDDISPEVT_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDDISPEVT2_FGET(FIELD)   _VP_VDDISPEVT_FGET(2,##FIELD)
 #endif


  #define _VP_VDDISPEVT0_FSET(FIELD,f)   _VP_VDDISPEVT_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDDISPEVT1_FSET(FIELD,f)   _VP_VDDISPEVT_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDDISPEVT2_FSET(FIELD,f)   _VP_VDDISPEVT_FSET(2,##FIELD,f)
 #endif


  #define _VP_VDDISPEVT0_FSETS(FIELD,SYM)   _VP_VDDISPEVT_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDDISPEVT1_FSETS(FIELD,SYM)   _VP_VDDISPEVT_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDDISPEVT2_FSETS(FIELD,SYM)   _VP_VDDISPEVT_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _________________
* |               |
* |  V D C L I P  |
* |_______________|
*
* VDCLIP0 -  Video Port 0 Video Display Clipping Register
* VDCLIP1 -  Video Port 1 Video Display Clipping Register
* VDCLIP2 -  Video Port 2 Video Display Clipping Register
*
* FIELDS (msb -> lsb)
* (rw) CLIPCHIGH
* (rw) CLIPCLOW
* (rw) CLIPYHIGH
* (rw) CLIPYLOW
*
\******************************************************************************/
  #define _VP_VDCLIP_OFFSET           150

  #define _VP_VDCLIP0_ADDR   (_VP_BASE_PORT0 + 4*_VP_VDCLIP_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDCLIP1_ADDR   (_VP_BASE_PORT1 + 4*_VP_VDCLIP_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDCLIP2_ADDR   (_VP_BASE_PORT2 + 4*_VP_VDCLIP_OFFSET)
 #endif


  #define _VP_VDCLIP_CLIPCHIGH_MASK        0xFF000000u
  #define _VP_VDCLIP_CLIPCHIGH_SHIFT       0x00000018u
  #define  VP_VDCLIP_CLIPCHIGH_DEFAULT     0x000000F0u
  #define  VP_VDCLIP_CLIPCHIGH_OF(x)       _VALUEOF(x)

  #define _VP_VDCLIP_CLIPCLOW_MASK        0x00FF0000u
  #define _VP_VDCLIP_CLIPCLOW_SHIFT       0x00000010u
  #define  VP_VDCLIP_CLIPCLOW_DEFAULT     0x00000010u
  #define  VP_VDCLIP_CLIPCLOW_OF(x)       _VALUEOF(x)

  #define _VP_VDCLIP_CLIPYHIGH_MASK        0x0000FF00u
  #define _VP_VDCLIP_CLIPYHIGH_SHIFT       0x00000008u
  #define  VP_VDCLIP_CLIPYHIGH_DEFAULT     0x000000EBu
  #define  VP_VDCLIP_CLIPYHIGH_OF(x)       _VALUEOF(x)

  #define _VP_VDCLIP_CLIPYLOW_MASK        0x000000FFu
  #define _VP_VDCLIP_CLIPYLOW_SHIFT       0x00000000u
  #define  VP_VDCLIP_CLIPYLOW_DEFAULT     0x00000010u
  #define  VP_VDCLIP_CLIPYLOW_OF(x)       _VALUEOF(x)

  #define  VP_VDCLIP_OF(x)            _VALUEOF(x)

  #define VP_VDCLIP_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VDCLIP,CLIPCHIGH)\
    |_PER_FDEFAULT(VP,VDCLIP,CLIPCLOW)\
    |_PER_FDEFAULT(VP,VDCLIP,CLIPYHIGH)\
    |_PER_FDEFAULT(VP,VDCLIP,CLIPYLOW)\
  )

  #define VP_VDCLIP_RMK(clipchigh,clipclow,clipyhigh,clipylow) (Uint32)(\
     _PER_FMK(VP,VDCLIP,CLIPCHIGH,clipchigh)\
    |_PER_FMK(VP,VDCLIP,CLIPCLOW,clipclow)\
    |_PER_FMK(VP,VDCLIP,CLIPYHIGH,clipyhigh)\
    |_PER_FMK(VP,VDCLIP,CLIPYLOW,clipylow)\
  )

  #define _VP_VDCLIP_FGET(N,FIELD)\
    _PER_FGET(_VP_VDCLIP##N##_ADDR,VP,VDCLIP,##FIELD)

  #define _VP_VDCLIP_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VDCLIP##N##_ADDR,VP,VDCLIP,##FIELD,field)

  #define _VP_VDCLIP_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VDCLIP##N##_ADDR,VP,VDCLIP,##FIELD,##SYM)

  #define _VP_VDCLIP0_FGET(FIELD)   _VP_VDCLIP_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDCLIP1_FGET(FIELD)   _VP_VDCLIP_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDCLIP2_FGET(FIELD)   _VP_VDCLIP_FGET(2,##FIELD)
 #endif


  #define _VP_VDCLIP0_FSET(FIELD,f)   _VP_VDCLIP_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDCLIP1_FSET(FIELD,f)   _VP_VDCLIP_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDCLIP2_FSET(FIELD,f)   _VP_VDCLIP_FSET(2,##FIELD,f)
 #endif


  #define _VP_VDCLIP0_FSETS(FIELD,SYM)   _VP_VDCLIP_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDCLIP1_FSETS(FIELD,SYM)   _VP_VDCLIP_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDCLIP2_FSETS(FIELD,SYM)   _VP_VDCLIP_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _____________________
* |                   |
* |  V D D E F V A L  |
* |___________________|
*
* VDDEFVAL0 -  Video Port 0 Video Display Default Display Value
* VDDEFVAL1 -  Video Port 1 Video Display Default Display Value
* VDDEFVAL2 -  Video Port 2 Video Display Default Display Value
*
* FIELDS (msb -> lsb)
*
* (rw) CRDEFVAL
* (rw) CBDEFVAL
* (rw) YDEFVAL
* (rw) DEFVAL
*
*
\******************************************************************************/
  #define _VP_VDDEFVAL_OFFSET           151

  #define _VP_VDDEFVAL0_ADDR   (_VP_BASE_PORT0 + 4*_VP_VDDEFVAL_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDDEFVAL1_ADDR   (_VP_BASE_PORT1 + 4*_VP_VDDEFVAL_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDDEFVAL2_ADDR   (_VP_BASE_PORT2 + 4*_VP_VDDEFVAL_OFFSET)
 #endif


  #define _VP_VDDEFVAL_CRDEFVAL_MASK         0xFF000000u
  #define _VP_VDDEFVAL_CRDEFVAL_SHIFT        0x00000018u
  #define  VP_VDDEFVAL_CRDEFVAL_DEFAULT      0x00000000u
  #define  VP_VDDEFVAL_CRDEFVAL_OF(x)        _VALUEOF(x)

  #define _VP_VDDEFVAL_CBDEFVAL_MASK         0x00FF0000u
  #define _VP_VDDEFVAL_CBDEFVAL_SHIFT        0x00000010u
  #define  VP_VDDEFVAL_CBDEFVAL_DEFAULT      0x00000000u
  #define  VP_VDDEFVAL_CBDEFVAL_OF(x)        _VALUEOF(x)

  #define _VP_VDDEFVAL_YDEFVAL_MASK          0x000000FFu
  #define _VP_VDDEFVAL_YDEFVAL_SHIFT         0x00000000u
  #define  VP_VDDEFVAL_YDEFVAL_DEFAULT       0x00000000u
  #define  VP_VDDEFVAL_YDEFVAL_OF(x)         _VALUEOF(x)

  #define _VP_VDDEFVAL_DEFVAL_MASK           0x000FFFFFu
  #define _VP_VDDEFVAL_DEFVAL_SHIFT          0x00000000u
  #define  VP_VDDEFVAL_DEFVAL_DEFAULT        0x00000000u
  #define  VP_VDDEFVAL_DEFVAL_OF(x)          _VALUEOF(x)

  #define  VP_VDDEFVAL_OF(x)            _VALUEOF(x)

/***********************************************************************\
* Note: Since this register location been used for two different
*       mode no VP_VDDEFVAL_DEFAULT and VP_VDDEFVAL_RMK were defined
\***********************************************************************/

  #define _VP_VDDEFVAL_FGET(N,FIELD)\
    _PER_FGET(_VP_VDDEFVAL##N##_ADDR,VP,VDDEFVAL,##FIELD)

  #define _VP_VDDEFVAL_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VDDEFVAL##N##_ADDR,VP,VDDEFVAL,##FIELD,field)

  #define _VP_VDDEFVAL_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VDDEFVAL##N##_ADDR,VP,VDDEFVAL,##FIELD,##SYM)

  #define _VP_VDDEFVAL0_FGET(FIELD)   _VP_VDDEFVAL_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDDEFVAL1_FGET(FIELD)   _VP_VDDEFVAL_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDDEFVAL2_FGET(FIELD)   _VP_VDDEFVAL_FGET(2,##FIELD)
 #endif


  #define _VP_VDDEFVAL0_FSET(FIELD,f)   _VP_VDDEFVAL_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDDEFVAL1_FSET(FIELD,f)   _VP_VDDEFVAL_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDDEFVAL2_FSET(FIELD,f)   _VP_VDDEFVAL_FSET(2,##FIELD,f)
 #endif


  #define _VP_VDDEFVAL0_FSETS(FIELD,SYM)   _VP_VDDEFVAL_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDDEFVAL1_FSETS(FIELD,SYM)   _VP_VDDEFVAL_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDDEFVAL2_FSETS(FIELD,SYM)   _VP_VDDEFVAL_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _________________
* |               |
* |  V D V I N T  |
* |_______________|
*
* VDVINT0 -  Video Port 0 Video Display Vertical Interrupt
* VDVINT1 -  Video Port 1 Video Display Vertical Interrupt
* VDVINT2 -  Video Port 2 Video Display Vertical Interrupt
*
* FIELDS (msb -> lsb)
* (rw) VIF2
* (rw) VINT2
* (rw) VIF1
* (rw) VINT1
*
\******************************************************************************/
  #define _VP_VDVINT_OFFSET           152

  #define _VP_VDVINT0_ADDR   (_VP_BASE_PORT0 + 4*_VP_VDVINT_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVINT1_ADDR   (_VP_BASE_PORT1 + 4*_VP_VDVINT_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVINT2_ADDR   (_VP_BASE_PORT2 + 4*_VP_VDVINT_OFFSET)
 #endif


  #define _VP_VDVINT_VIF2_MASK        0x80000000u
  #define _VP_VDVINT_VIF2_SHIFT       0x0000001Fu
  #define  VP_VDVINT_VIF2_DEFAULT     0x00000000u
  #define  VP_VDVINT_VIF2_OF(x)       _VALUEOF(x)
  #define  VP_VDVINT_VIF2_DISABLE     0x00000000u
  #define  VP_VDVINT_VIF2_ENABLE      0x00000001u

  #define _VP_VDVINT_VINT2_MASK        0x0FFF0000u
  #define _VP_VDVINT_VINT2_SHIFT       0x00000010u
  #define  VP_VDVINT_VINT2_DEFAULT     0x00000000u
  #define  VP_VDVINT_VINT2_OF(x)       _VALUEOF(x)

  #define _VP_VDVINT_VIF1_MASK        0x00008000u
  #define _VP_VDVINT_VIF1_SHIFT       0x0000000Fu
  #define  VP_VDVINT_VIF1_DEFAULT     0x00000000u
  #define  VP_VDVINT_VIF1_OF(x)       _VALUEOF(x)
  #define  VP_VDVINT_VIF1_DISABLE     0x00000000u
  #define  VP_VDVINT_VIF1_ENABLE      0x00000001u

  #define _VP_VDVINT_VINT1_MASK        0x00000FFFu
  #define _VP_VDVINT_VINT1_SHIFT       0x00000000u
  #define  VP_VDVINT_VINT1_DEFAULT     0x00000000u
  #define  VP_VDVINT_VINT1_OF(x)       _VALUEOF(x)

  #define  VP_VDVINT_OF(x)            _VALUEOF(x)

  #define VP_VDVINT_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VDVINT,VIF2)\
    |_PER_FDEFAULT(VP,VDVINT,VINT2)\
    |_PER_FDEFAULT(VP,VDVINT,VIF1)\
    |_PER_FDEFAULT(VP,VDVINT,VINT1)\
  )

  #define VP_VDVINT_RMK(vif2,vint2,vif1,vint1) (Uint32)(\
     _PER_FMK(VP,VDVINT,VIF2,vif2)\
    |_PER_FMK(VP,VDVINT,VINT2,vint2)\
    |_PER_FMK(VP,VDVINT,VIF1,vif1)\
    |_PER_FMK(VP,VDVINT,VINT1,vint1)\
  )

  #define _VP_VDVINT_FGET(N,FIELD)\
    _PER_FGET(_VP_VDVINT##N##_ADDR,VP,VDVINT,##FIELD)

  #define _VP_VDVINT_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VDVINT##N##_ADDR,VP,VDVINT,##FIELD,field)

  #define _VP_VDVINT_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VDVINT##N##_ADDR,VP,VDVINT,##FIELD,##SYM)

  #define _VP_VDVINT0_FGET(FIELD)   _VP_VDVINT_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVINT1_FGET(FIELD)   _VP_VDVINT_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVINT2_FGET(FIELD)   _VP_VDVINT_FGET(2,##FIELD)
 #endif


  #define _VP_VDVINT0_FSET(FIELD,f)   _VP_VDVINT_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVINT1_FSET(FIELD,f)   _VP_VDVINT_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVINT2_FSET(FIELD,f)   _VP_VDVINT_FSET(2,##FIELD,f)
 #endif


  #define _VP_VDVINT0_FSETS(FIELD,SYM)   _VP_VDVINT_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVINT1_FSETS(FIELD,SYM)   _VP_VDVINT_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVINT2_FSETS(FIELD,SYM)   _VP_VDVINT_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _________________
* |               |
* |  V D F B I T  |
* |_______________|
*
* VDFBIT0 -  Video Port 0 Video Display Field Bit Register
* VDFBIT1 -  Video Port 1 Video Display Field Bit Register
* VDFBIT2 -  Video Port 2 Video Display Field Bit Register
*
* FIELDS (msb -> lsb)
* (rw) FBITSET
* (rw) FBITCLR
*
\******************************************************************************/
  #define _VP_VDFBIT_OFFSET           153

  #define _VP_VDFBIT0_ADDR   (_VP_BASE_PORT0 + 4*_VP_VDFBIT_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDFBIT1_ADDR   (_VP_BASE_PORT1 + 4*_VP_VDFBIT_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDFBIT2_ADDR   (_VP_BASE_PORT2 + 4*_VP_VDFBIT_OFFSET)
 #endif


  #define _VP_VDFBIT_FBITSET_MASK        0x0FFF0000u
  #define _VP_VDFBIT_FBITSET_SHIFT       0x00000010u
  #define  VP_VDFBIT_FBITSET_DEFAULT     0x00000000u
  #define  VP_VDFBIT_FBITSET_OF(x)       _VALUEOF(x)

  #define _VP_VDFBIT_FBITCLR_MASK        0x00000FFFu
  #define _VP_VDFBIT_FBITCLR_SHIFT       0x00000000u
  #define  VP_VDFBIT_FBITCLR_DEFAULT     0x00000000u
  #define  VP_VDFBIT_FBITCLR_OF(x)       _VALUEOF(x)

  #define  VP_VDFBIT_OF(x)            _VALUEOF(x)

  #define VP_VDFBIT_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VDFBIT,FBITSET)\
    |_PER_FDEFAULT(VP,VDFBIT,FBITCLR)\
  )

  #define VP_VDFBIT_RMK(fbitset,fbitclr) (Uint32)(\
     _PER_FMK(VP,VDFBIT,FBITSET,fbitset)\
    |_PER_FMK(VP,VDFBIT,FBITCLR,fbitclr)\
  )

  #define _VP_VDFBIT_FGET(N,FIELD)\
    _PER_FGET(_VP_VDFBIT##N##_ADDR,VP,VDFBIT,##FIELD)

  #define _VP_VDFBIT_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VDFBIT##N##_ADDR,VP,VDFBIT,##FIELD,field)

  #define _VP_VDFBIT_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VDFBIT##N##_ADDR,VP,VDFBIT,##FIELD,##SYM)

  #define _VP_VDFBIT0_FGET(FIELD)   _VP_VDFBIT_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDFBIT1_FGET(FIELD)   _VP_VDFBIT_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDFBIT2_FGET(FIELD)   _VP_VDFBIT_FGET(2,##FIELD)
 #endif


  #define _VP_VDFBIT0_FSET(FIELD,f)   _VP_VDFBIT_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDFBIT1_FSET(FIELD,f)   _VP_VDFBIT_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDFBIT2_FSET(FIELD,f)   _VP_VDFBIT_FSET(2,##FIELD,f)
 #endif


  #define _VP_VDFBIT0_FSETS(FIELD,SYM)   _VP_VDFBIT_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDFBIT1_FSETS(FIELD,SYM)   _VP_VDFBIT_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDFBIT2_FSETS(FIELD,SYM)   _VP_VDFBIT_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* __________________
* |                |
* |  V D V B I T 1 |
* |________________|
*
* VDVBIT10 -  Video Port 0 Video Display Vertical Blank Bit-Field 1 Register
* VDVBIT11 -  Video Port 1 Video Display Vertical Blank Bit-Field 1 Register
* VDVBIT12 -  Video Port 2 Video Display Vertical Blank Bit-Field 1 Register
*
* FIELDS (msb -> lsb)
* (rw) VBITCLR1
* (rw) VBITSET1
*
\******************************************************************************/
  #define _VP_VDVBIT1_OFFSET           154

  #define _VP_VDVBIT10_ADDR   (_VP_BASE_PORT0 + 4*_VP_VDVBIT1_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVBIT11_ADDR   (_VP_BASE_PORT1 + 4*_VP_VDVBIT1_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVBIT12_ADDR   (_VP_BASE_PORT2 + 4*_VP_VDVBIT1_OFFSET)
 #endif


  #define _VP_VDVBIT1_VBITCLR1_MASK        0x0FFF0000u
  #define _VP_VDVBIT1_VBITCLR1_SHIFT       0x00000010u
  #define  VP_VDVBIT1_VBITCLR1_DEFAULT     0x00000000u
  #define  VP_VDVBIT1_VBITCLR1_OF(x)       _VALUEOF(x)

  #define _VP_VDVBIT1_VBITSET1_MASK        0x00000FFFu
  #define _VP_VDVBIT1_VBITSET1_SHIFT       0x00000000u
  #define  VP_VDVBIT1_VBITSET1_DEFAULT     0x00000000u
  #define  VP_VDVBIT1_VBITSET1_OF(x)       _VALUEOF(x)

  #define  VP_VDVBIT1_OF(x)            _VALUEOF(x)

  #define VP_VDVBIT1_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VDVBIT1,VBITCLR1)\
    |_PER_FDEFAULT(VP,VDVBIT1,VBITSET1)\
  )

  #define VP_VDVBIT1_RMK(vbitclr1,vbitset1) (Uint32)(\
  _PER_FMK(VP,VDVBIT1,VBITCLR1,vbitclr1)\
    |_PER_FMK(VP,VDVBIT1,VBITSET1,vbitset1)\
  )

  #define _VP_VDVBIT1_FGET(N,FIELD)\
    _PER_FGET(_VP_VDVBIT1##N##_ADDR,VP,VDVBIT1,##FIELD)

  #define _VP_VDVBIT1_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VDVBIT1##N##_ADDR,VP,VDVBIT1,##FIELD,field)

  #define _VP_VDVBIT1_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VDVBIT1##N##_ADDR,VP,VDVBIT1,##FIELD,##SYM)

  #define _VP_VDVBIT10_FGET(FIELD)   _VP_VDVBIT1_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVBIT11_FGET(FIELD)   _VP_VDVBIT1_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVBIT12_FGET(FIELD)   _VP_VDVBIT1_FGET(2,##FIELD)
 #endif


  #define _VP_VDVBIT10_FSET(FIELD,f)   _VP_VDVBIT1_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVBIT11_FSET(FIELD,f)   _VP_VDVBIT1_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVBIT12_FSET(FIELD,f)   _VP_VDVBIT1_FSET(2,##FIELD,f)
 #endif


  #define _VP_VDVBIT10_FSETS(FIELD,SYM)   _VP_VDVBIT1_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVBIT11_FSETS(FIELD,SYM)   _VP_VDVBIT1_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVBIT12_FSETS(FIELD,SYM)   _VP_VDVBIT1_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* __________________
* |                |
* |  V D V B I T 2 |
* |________________|
*
* VDVBIT20 -  Video Port 0 Video Display Vertical Blank Bit-Field 2 Register
* VDVBIT21 -  Video Port 1 Video Display Vertical Blank Bit-Field 2 Register
* VDVBIT22 -  Video Port 2 Video Display Vertical Blank Bit-Field 2 Register
*
* FIELDS (msb -> lsb)
* (rw) VBITCLR2
* (rw) VBITSET2
*
\******************************************************************************/
  #define _VP_VDVBIT2_OFFSET           155

  #define _VP_VDVBIT20_ADDR   (_VP_BASE_PORT0 + 4*_VP_VDVBIT2_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVBIT21_ADDR   (_VP_BASE_PORT1 + 4*_VP_VDVBIT2_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVBIT22_ADDR   (_VP_BASE_PORT2 + 4*_VP_VDVBIT2_OFFSET)
 #endif


  #define _VP_VDVBIT2_VBITCLR2_MASK        0x0FFF0000u
  #define _VP_VDVBIT2_VBITCLR2_SHIFT       0x00000010u
  #define  VP_VDVBIT2_VBITCLR2_DEFAULT     0x00000000u
  #define  VP_VDVBIT2_VBITCLR2_OF(x)       _VALUEOF(x)

  #define _VP_VDVBIT2_VBITSET2_MASK        0x00000FFFu
  #define _VP_VDVBIT2_VBITSET2_SHIFT       0x00000000u
  #define  VP_VDVBIT2_VBITSET2_DEFAULT     0x00000000u
  #define  VP_VDVBIT2_VBITSET2_OF(x)       _VALUEOF(x)

  #define  VP_VDVBIT2_OF(x)            _VALUEOF(x)

  #define VP_VDVBIT2_DEFAULT (Uint32)(\
     _PER_FDEFAULT(VP,VDVBIT2,VBITCLR2)\
    |_PER_FDEFAULT(VP,VDVBIT2,VBITSET2)\
  )

  #define VP_VDVBIT2_RMK(vbitclr2,vbitset2) (Uint32)(\
     _PER_FMK(VP,VDVBIT2,VBITCLR2,vbitclr2)\
    |_PER_FMK(VP,VDVBIT2,VBITSET2,vbitset2)\
  )

  #define _VP_VDVBIT2_FGET(N,FIELD)\
    _PER_FGET(_VP_VDVBIT2##N##_ADDR,VP,VDVBIT2,##FIELD)

  #define _VP_VDVBIT2_FSET(N,FIELD,field)\
    _PER_FSET(_VP_VDVBIT2##N##_ADDR,VP,VDVBIT2,##FIELD,field)

  #define _VP_VDVBIT2_FSETS(N,FIELD,SYM)\
    _PER_FSETS(_VP_VDVBIT2##N##_ADDR,VP,VDVBIT2,##FIELD,##SYM)

  #define _VP_VDVBIT20_FGET(FIELD)   _VP_VDVBIT2_FGET(0,##FIELD)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVBIT21_FGET(FIELD)   _VP_VDVBIT2_FGET(1,##FIELD)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVBIT22_FGET(FIELD)   _VP_VDVBIT2_FGET(2,##FIELD)
 #endif


  #define _VP_VDVBIT20_FSET(FIELD,f)   _VP_VDVBIT2_FSET(0,##FIELD,f)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVBIT21_FSET(FIELD,f)   _VP_VDVBIT2_FSET(1,##FIELD,f)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVBIT22_FSET(FIELD,f)   _VP_VDVBIT2_FSET(2,##FIELD,f)
 #endif


  #define _VP_VDVBIT20_FSETS(FIELD,SYM)   _VP_VDVBIT2_FSETS(0,##FIELD,##SYM)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_VDVBIT21_FSETS(FIELD,SYM)   _VP_VDVBIT2_FSETS(1,##FIELD,##SYM)
 #endif

 #if (CHIP_DM642)
  #define _VP_VDVBIT22_FSETS(FIELD,SYM)   _VP_VDVBIT2_FSETS(2,##FIELD,##SYM)
 #endif


/******************************************************************************\
* _________________
* |               |
* |  Y S R C A    |
* |_______________|
*
* YSRCA0       -  Video Port 0 Y FIFO Source Register A
* YSRCA1       -  Video Port 1 Y FIFO Source Register A
* YSRCA2       -  Video Port 2 Y FIFO Source Register A
* _________________
* |               |
* |  C B S R C A  |
* |_______________|
*
* CBSRCA0      -  Video Port 0 Cb FIFO Source Register A
* CBSRCA1      -  Video Port 1 Cb FIFO Source Register A
* CBSRCA2      -  Video Port 2 Cb FIFO Source Register A
* _________________
* |               |
* |  C R S R C A  |
* |_______________|
*
* CRSRCA0      -  Video Port 0 Cr FIFO Source Register A
* CRSRCA1      -  Video Port 1 Cr FIFO Source Register A
* CRSRCA2      -  Video Port 2 Cr FIFO Source Register A
* _________________
* |               |
* |  Y S R C B    |
* |_______________|
*
* YSRCB0       -  Video Port 0 Y FIFO Source Register B (only for DM642)
* YSRCB1       -  Video Port 1 Y FIFO Source Register B (only for DM642)
* YSRCB2       -  Video Port 2 Y FIFO Source Register B (only for DM642)
* _________________
* |               |
* |  C B S R C B  |
* |_______________|
*
* CBSRCB0      -  Video Port 0 Cb FIFO Source Register B (only for DM642)
* CBSRCB1      -  Video Port 1 Cb FIFO Source Register B (only for DM642)
* CBSRCB2      -  Video Port 2 Cb FIFO Source Register B (only for DM642)
* _________________
* |               |
* |  C R S R C B  |
* |_______________|
*
* CRSRCB0      -  Video Port 0 Cr FIFO Source Register B (only for DM642)
* CRSRCB1      -  Video Port 1 Cr FIFO Source Register B (only for DM642)
* CRSRCB2      -  Video Port 2 Cr FIFO Source Register B (only for DM642)
* _________________
* |               |
* |  Y D S T A    |
* |_______________|
*
* YDSTA0       -  Video Port 0 Y FIFO Destination Register A
* YDSTA1       -  Video Port 1 Y FIFO Destination Register A
* YDSTA2       -  Video Port 2 Y FIFO Destination Register A
* _________________
* |               |
* |  C B D S T    |
* |_______________|
*
* CBDST0       -  Video Port 0 Cb FIFO Destination Register 
* CBDST1       -  Video Port 1 Cb FIFO Destination Register 
* CBDST2       -  Video Port 2 Cb FIFO Destination Register 
* _________________
* |               |
* |  C R D S T    |
* |_______________|
*
* CRDST0       -  Video Port 0 Cr FIFO Destination Register
* CRDST1       -  Video Port 1 Cr FIFO Destination Register
* CRDST2       -  Video Port 2 Cr FIFO Destination Register
* _________________
* |               |
* |  Y D S T B    |
* |_______________|
*
* YDSTB0       -  Video Port 0 Y FIFO Destination Register B (only for DM642)
* YDSTB1       -  Video Port 1 Y FIFO Destination Register B (only for DM642)
* YDSTB2       -  Video Port 2 Y FIFO Destination Register B (only for DM642)
\******************************************************************************/
  #define _VP_YSRCA_OFFSET             0
  #define _VP_CBSRCA_OFFSET            2
  #define _VP_CRSRCA_OFFSET            4
  #define _VP_YDSTA_OFFSET             8
  #define _VP_CBDST_OFFSET             10
  #define _VP_CRDST_OFFSET             12

 #if (CHIP_DM642)
  #define _VP_YSRCB_OFFSET             0
  #define _VP_CBSRCB_OFFSET            2
  #define _VP_CRSRCB_OFFSET            4
  #define _VP_YDSTB_OFFSET             8
 #endif

  #define _VP_YSRCA0_ADDR   (_VP_AFBASE_PORT0 + 4*_VP_YSRCA_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_YSRCA1_ADDR   (_VP_AFBASE_PORT1 + 4*_VP_YSRCA_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_YSRCA2_ADDR   (_VP_AFBASE_PORT2 + 4*_VP_YSRCA_OFFSET)
 #endif


  #define _VP_CBSRCA0_ADDR   (_VP_AFBASE_PORT0 + 4*_VP_CBSRCA_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_CBSRCA1_ADDR   (_VP_AFBASE_PORT1 + 4*_VP_CBSRCA_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_CBSRCA2_ADDR   (_VP_AFBASE_PORT2 + 4*_VP_CBSRCA_OFFSET)
 #endif


  #define _VP_CRSRCA0_ADDR   (_VP_AFBASE_PORT0 + 4*_VP_CRSRCA_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_CRSRCA1_ADDR   (_VP_AFBASE_PORT1 + 4*_VP_CRSRCA_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_CRSRCA2_ADDR   (_VP_AFBASE_PORT2 + 4*_VP_CRSRCA_OFFSET)
 #endif


  #define _VP_YDSTA0_ADDR   (_VP_AFBASE_PORT0 + 4*_VP_YDSTA_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_YDSTA1_ADDR   (_VP_AFBASE_PORT1 + 4*_VP_YDSTA_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_YDSTA2_ADDR   (_VP_AFBASE_PORT2 + 4*_VP_YDSTA_OFFSET)
 #endif


  #define _VP_CBDST0_ADDR   (_VP_AFBASE_PORT0 + 4*_VP_CBDST_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_CBDST1_ADDR   (_VP_AFBASE_PORT1 + 4*_VP_CBDST_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_CBDST2_ADDR   (_VP_AFBASE_PORT2 + 4*_VP_CBDST_OFFSET)
 #endif


  #define _VP_CRDST0_ADDR   (_VP_AFBASE_PORT0 + 4*_VP_CRDST_OFFSET)

 #if (CHIP_DM641 | CHIP_DM642)
  #define _VP_CRDST1_ADDR   (_VP_AFBASE_PORT1 + 4*_VP_CRDST_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_CRDST2_ADDR   (_VP_AFBASE_PORT2 + 4*_VP_CRDST_OFFSET)
 #endif

 #if (CHIP_DM642)
  #define _VP_YSRCB0_ADDR   (_VP_BFBASE_PORT0 + 4*_VP_YSRCB_OFFSET)
  #define _VP_YSRCB1_ADDR   (_VP_BFBASE_PORT1 + 4*_VP_YSRCB_OFFSET)
  #define _VP_YSRCB2_ADDR   (_VP_BFBASE_PORT2 + 4*_VP_YSRCB_OFFSET)

  #define _VP_CBSRCB0_ADDR   (_VP_BFBASE_PORT0 + 4*_VP_CBSRCB_OFFSET)
  #define _VP_CBSRCB1_ADDR   (_VP_BFBASE_PORT1 + 4*_VP_CBSRCB_OFFSET)
  #define _VP_CBSRCB2_ADDR   (_VP_BFBASE_PORT2 + 4*_VP_CBSRCB_OFFSET)

  #define _VP_CRSRCB0_ADDR   (_VP_BFBASE_PORT0 + 4*_VP_CRSRCB_OFFSET)
  #define _VP_CRSRCB1_ADDR   (_VP_BFBASE_PORT1 + 4*_VP_CRSRCB_OFFSET)
  #define _VP_CRSRCB2_ADDR   (_VP_BFBASE_PORT2 + 4*_VP_CRSRCB_OFFSET)

  #define _VP_YDSTB0_ADDR   (_VP_BFBASE_PORT0 + 4*_VP_YDSTB_OFFSET)
  #define _VP_YDSTB1_ADDR   (_VP_BFBASE_PORT1 + 4*_VP_YDSTB_OFFSET)
  #define _VP_YDSTB2_ADDR   (_VP_BFBASE_PORT2 + 4*_VP_YDSTB_OFFSET)
 #endif


/*----------------------------------------------------------------------------*/

#endif /* VP_SUPPORT */
#endif /* _CSL_VPHAL_H_ */
/******************************************************************************\
* End of csl_vphal.h
\******************************************************************************/
