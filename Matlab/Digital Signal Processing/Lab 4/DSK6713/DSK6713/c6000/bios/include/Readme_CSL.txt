C6000 CSL Library Installation
(C) Copyright 2004 Texas Instruments Incorporated
All rights reserved worldwide.
-------------------------------------------------

Contents
--------
- ZIPFILE CONTENTS
- INSTALLATION INFORMATION
- BUGS FIXED FOR VERSION 2.31.00.8
- CONTACTING TI


ZIPFILE CONTENTS
----------------
C6xCSL.exe - Contains the installation program for the C6000 CSL Library
Readme.txt - This file.
Releasenote.htm - Release note for version 2.31.00.8
New_CACHE_APIs_refguide.doc - New CACHE APIs reference guide.


INSTALLATION INFORMATION
------------------------
To run the TI C6000 CSL Library Installation, follow the directions below:

Windows 98, Windows NT, Windows 2000, Windows XP
1. Unzip the C6xCSL.exe file to a temporary directory
2. Double Click the executable to launch the Install Shield Wizard
3. Answer all remaining questions presented in Install Shield dialog boxes


NOTES:

1) If you DO NOT accept the software license agreement the library WILL NOT be installed.

2) The default location to install the software is c:\cslc6000, which will install the
   libraries into c:\cslc6000\lib, the header files into c:\cslc6000\include and
   the examples into c:\cslc6000\examples.
   If CSL is installed over <CCS_Install_Dir>\bios\ , it will overwrite existing CSL
   version without taking any backup. So it is recommended that user take backup of
   <CCS_Install_Dir>\bios\ folder before installing CSL there.

BUGS FIXED FOR VERSION 2.31.00.8
--------------------------------

SDSsq38280 - Typo in csl_vphal.h  (definition error in VP - VDIMGOFF address register macros) 
SDSsq37840 - Problem with tccAllocTable definition in 6x csl_edma.h file

Enhancements
------------

* Included chip support library for C6418

BUGS FIXED FOR VERSION 2.31.00.7
--------------------------------

SDSsq37775 - Invalid cache mode for C6410
SDSsq37983 - allocMaskT array not reset in EDMA_resetAll
SDSsq37246 - CACHE_reset does not reset L2 cache size to 0 and disable MAR regions
SDSsq37245 - Replace all instances of EMIFA with EMIFB in csl_emifbhal.h

Enhancements
------------

* Included chip support libraries for DM641 and  DM640  devices

* Fixed BIOS-CSL dependency bug. This version of CSL has a fix for incorrect TIMER0 initialization during BIOS initialization. 
  This CSL version fixes this bug for all BIOS versions.

* CSL has been updated for VP module as per the latest documentation,SPRU629a.pdf 

Please see the release notes for more details.  


CONTACTING TI
-------------
Texas Instruments Incorporated
Post Office Box 655303
Dallas, Texas  75265  USA

Phone: +1(972) 644-5580
Fax: +1(214) 480-7800
Internet: dsph@ti.com
World Wide Web: http://www.ti.com/sc/support

