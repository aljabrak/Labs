/*H*****************************************************************************
*
* $Archive::                                                                   $
* $Revision::                                                                  $
* $Date::                                                                      $
* $Author::                                                                    $
*
* DESCRIPTION:  TMS320C64xx TEB emif code 
*
* GLOBALS 
*
* PUBLIC FUNCTIONS:
*                              
* PRIVATE FUNCTIONS:
*
* USAGE/LIMITATIONS:
*
* NOTES: Assumptions:
*             TMS320C64x TEB
*             CPLD connected to EMIF B, TBCE0
*             AMD29LV400BT flash connected to EMIF B, TBCE1
*             SDRAM connected to EMIF A, TACE0
*
* COMPILE SWITCHES:

*H***************************************************************************/
#define emif_c

/*---- compilation control switches ----------------------------------------*/

/*****************************************************************************
* INCLUDE FILES
*****************************************************************************/
/*---- system and platform files -------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <c6x.h>
/*---- program files -------------------------------------------------------*/

#include "c6713dsk.h"
#include "emif.h"
#include "csl_emif.h"

/*****************************************************************************
* EXTERNAL REFERENCE    
*****************************************************************************/
/*---- data declarations ---------------------------------------------------*/

/*---- function prototypes -------------------------------------------------*/

/*****************************************************************************
* PUBLIC DECLARATIONS 
*****************************************************************************/

/*---- data declarations ---------------------------------------------------*/

/*****************************************************************************
* PRIVATE DECLARATIONS  
*****************************************************************************/
/*---- context -------------------------------------------------------------*/

/*---- data declarations ---------------------------------------------------*/
	
/*---- function prototypes -------------------------------------------------*/

/*---- macros --------------------------------------------------------------*/

/*****************************************************************************
* PUBLIC FUNCTION DEFINITIONS
*****************************************************************************/
/*F***************************************************************************
* NAME:   EMIF_Init()
*
* DESCRIPTION: Setup the DSK EMIF A and B.       
*       
* NOTES:
*   
*F***************************************************************************/

void EMIF_Init( void )
{
    EMIF_Config emifCfg0 = {
        0x60                                  |
        EMIF_FMKS(GBLCTL, NOHOLD, DISABLE)    |
        EMIF_FMKS(GBLCTL, CLK1EN, DISABLE)    |
        EMIF_FMKS(GBLCTL, CLK2EN, ENABLE),

        EMIF_FMKS(CECTL, WRSETUP, DEFAULT)    |
        EMIF_FMKS(CECTL, WRSTRB, DEFAULT)     |
        EMIF_FMKS(CECTL, WRHLD, DEFAULT)      |
        EMIF_FMKS(CECTL, RDSETUP, DEFAULT)    |
        EMIF_FMKS(CECTL, TA, OF(2))           |
        EMIF_FMKS(CECTL, RDSTRB, DEFAULT)     |
        EMIF_FMKS(CECTL, MTYPE, SDRAM32)      |
        EMIF_FMKS(CECTL, RDHLD, DEFAULT),
                
        EMIF_FMKS(CECTL, WRSETUP, OF(0))      |
        EMIF_FMKS(CECTL, WRSTRB, OF(8))       |
        EMIF_FMKS(CECTL, WRHLD, OF(0))        |
        EMIF_FMKS(CECTL, RDSETUP, OF(0))      |
        EMIF_FMKS(CECTL, TA, OF(2))           |
        EMIF_FMKS(CECTL, RDSTRB, OF(8))       |
        EMIF_FMKS(CECTL, MTYPE, ASYNC8)       |
        EMIF_FMKS(CECTL, RDHLD, OF(0)),
        
        EMIF_FMKS(CECTL, WRSETUP, OF(2))      |
        EMIF_FMKS(CECTL, WRSTRB, OF(10))      |
        EMIF_FMKS(CECTL, WRHLD, OF(2))        |
        EMIF_FMKS(CECTL, RDSETUP, OF(2))      |
        EMIF_FMKS(CECTL, TA, OF(2))           |
        EMIF_FMKS(CECTL, RDSTRB, OF(10))      |
        EMIF_FMKS(CECTL, MTYPE, ASYNC32)      |
        EMIF_FMKS(CECTL, RDHLD, OF(2)),

        EMIF_FMKS(CECTL, WRSETUP, OF(2))      |
        EMIF_FMKS(CECTL, WRSTRB, OF(10))      |
        EMIF_FMKS(CECTL, WRHLD, OF(2))        |
        EMIF_FMKS(CECTL, RDSETUP, OF(2))      |
        EMIF_FMKS(CECTL, TA, OF(2))           |
        EMIF_FMKS(CECTL, RDSTRB, OF(10))      |
        EMIF_FMKS(CECTL, MTYPE, ASYNC32)      |
        EMIF_FMKS(CECTL, RDHLD, OF(2)),
        
        EMIF_FMKS(SDCTL, SDBSZ, 4BANKS)       |
        EMIF_FMKS(SDCTL, SDRSZ, 12ROW)        |
        EMIF_FMKS(SDCTL, SDCSZ, 8COL)         |
        EMIF_FMKS(SDCTL, RFEN, ENABLE)        |
        EMIF_FMKS(SDCTL, INIT, YES)           |
        EMIF_FMKS(SDCTL, TRCD, OF(1))         |
        EMIF_FMKS(SDCTL, TRP, OF(1))          |
        EMIF_FMKS(SDCTL, TRC, OF(5)),
    
        EMIF_FMKS(SDTIM, CNTR, OF(0))         |
        EMIF_FMKS(SDTIM, PERIOD, OF(1400)),

        EMIF_FMKS(SDEXT, WR2RD, OF(0))        |
        EMIF_FMKS(SDEXT, WR2DEAC, OF(2))      |
        EMIF_FMKS(SDEXT, WR2WR, OF(1))        |
        EMIF_FMKS(SDEXT, R2WDQM, OF(1))       |
        EMIF_FMKS(SDEXT, RD2WR, OF(0))        |
        EMIF_FMKS(SDEXT, RD2DEAC, OF(1))      |
        EMIF_FMKS(SDEXT, RD2RD, OF(0))        |
        EMIF_FMKS(SDEXT, THZP, OF(2))         |
        EMIF_FMKS(SDEXT, TWR, OF(1))          |
        EMIF_FMKS(SDEXT, TRRD, OF(0))         |
        EMIF_FMKS(SDEXT, TRAS, OF(4))         |
        EMIF_FMKS(SDEXT, TCL, OF(1))         
    };
	EMIF_config( &emifCfg0 );
	
	return;
}
