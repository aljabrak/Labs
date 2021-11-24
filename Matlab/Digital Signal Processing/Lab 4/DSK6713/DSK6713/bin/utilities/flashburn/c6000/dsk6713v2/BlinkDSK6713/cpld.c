/*H*****************************************************************************
*
* $Archive::                                                                   $
* $Revision::                                                                  $
* $Date::                                                                      $
* $Author::                                                                    $
*
* DESCRIPTION:  TMS320C64xx TEB CPLD interface.
*
* GLOBALS 
*
* PUBLIC FUNCTIONS:
*   GLOBAL void    CPLD_Version( BOARD_VERSION * pVersion );
*   GLOBAL int     CPLD_LedOn(  int LedMask );
*   GLOBAL int     CPLD_LedOff( int LedMask );
*   GLOBAL int     CPLD_ReadSwitch( void );
*   GLOBAL int     CPLD_ReadMisc( void );
*   GLOBAL int     CPLD_ReadDc( void );
*   GLOBAL int     CPLD_WriteDc( int DcReg );
*   GLOBAL int     CPLD_WriteCodecMode( int ModeVal );
*   GLOBAL int     CPLD_IsCodecReady( void )

*                              
* PRIVATE FUNCTIONS:
*
* USAGE/LIMITATIONS:
*
* NOTES: Assumes 6713 DSK, with CPLD connected to CE1,
*        little endian.
*
*
*H***************************************************************************/
#define cpld_c

/*---- compilation control switches ----------------------------------------*/

/*****************************************************************************
* INCLUDE FILES
*****************************************************************************/
/*---- system and platform files -------------------------------------------*/

/*---- program files -------------------------------------------------------*/
#include "cpld.h"

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

#define CPLD_BASE_ADDR   0x90080000		// TBCE1, EMIFA
#define REGA_USER        0              // User reg, led/switch
#define REGA_DC          1              // Daughter card
#define REGA_CODEC_L     2              // Codec low byte 
#define REGA_CODEC_H     3              // Codec high byte
#define REGA_VER         4              // Board/Fpga version
#define REGA_MISC        6              // Misc

#define REG_MASK         0x000000FF     // Byte mask

/*---- data declarations ---------------------------------------------------*/
typedef  volatile char CPLD_DTYPE;       // 8-bit access to cpld

/*---- function prototypes -------------------------------------------------*/

/*---- macros --------------------------------------------------------------*/

/*****************************************************************************
* PUBLIC FUNCTION DEFINITIONS
*****************************************************************************/


/*F***************************************************************************
* NAME:  CPLD_Version() 
*
* DESCRIPTION:  Read the pwb and cpld version                
*       
* NOTES:
*   
*F***************************************************************************/
void        
CPLD_Version( BOARD_VERSION * pVersion )
{
	CPLD_DTYPE *pCPLD = (CPLD_DTYPE *)CPLD_BASE_ADDR;
	CPLD_DTYPE  Reg;

	Reg = pCPLD[REGA_VER];
	pVersion->BoardVersion = Reg & 0x07;
	pVersion->FpgaVersion  = (Reg >>4 ) & 0x0f;
}

/*F***************************************************************************
* NAME:  CPLD_LedOn() 
*
* DESCRIPTION: Turn on Led and return the current setting                
*       
* NOTES: 
*   
*F***************************************************************************/
int           
CPLD_LedOn(  int LedMask )
{
	CPLD_DTYPE *pCPLD = (CPLD_DTYPE *)CPLD_BASE_ADDR;
	CPLD_DTYPE  Reg;

	// Set Led bit to '1' to turn it on 
	Reg = pCPLD[REGA_USER];
    Reg |= LedMask;
    pCPLD[REGA_USER] = Reg;

    return((int)Reg & 0x0f );
}

/*F***************************************************************************
* NAME: CPLD_LedOff()  
*
* DESCRIPTION:  Turn off Led and return the current setting                
*       
* NOTES: 
*   
*F***************************************************************************/
int           
CPLD_LedOff( int LedMask )
{
	CPLD_DTYPE *pCPLD = (CPLD_DTYPE *)CPLD_BASE_ADDR;
	CPLD_DTYPE  Reg;

	// Set Led bit to '0' to turn it off
	Reg = pCPLD[REGA_USER];
    Reg &= ~LedMask;
    pCPLD[REGA_USER] = Reg;
    
    return( (int)Reg & 0x0f  );
}

/*F***************************************************************************
* NAME:  CPLD_ReadSwitch()  
*
* DESCRIPTION:  Read the switches and return the value                
*       
* NOTES: 
*   
*F***************************************************************************/
int           
CPLD_ReadSwitch( void )
{
	CPLD_DTYPE *pCPLD = (CPLD_DTYPE *)CPLD_BASE_ADDR;
	CPLD_DTYPE  Reg;

	Reg = pCPLD[REGA_USER];
    
    return( (int)(Reg >> 4) & 0x0f);
}

/*F***************************************************************************
* NAME:  CPLD_ReadMisc() 
*
* DESCRIPTION:  Read the misc registers.              
*       
* NOTES:
*   
*F***************************************************************************/
int           
CPLD_ReadMisc( void )
{
	CPLD_DTYPE *pCPLD = (CPLD_DTYPE *)CPLD_BASE_ADDR;
	CPLD_DTYPE  Reg;

	Reg = pCPLD[REGA_MISC];
    
    return( (int)Reg & 0xFF );
}

/*F***************************************************************************
* NAME: CPLD_ReadDc() 
*
* DESCRIPTION:  Read the daughter card register.               
*       
* NOTES:
*   
*F***************************************************************************/
int           
CPLD_ReadDc( void )
{
	CPLD_DTYPE *pCPLD = (CPLD_DTYPE *)CPLD_BASE_ADDR;
	CPLD_DTYPE  Reg;

	Reg = pCPLD[REGA_DC];
    
    return( (int)Reg & 0xFF );
}

/*F***************************************************************************
* NAME: CPLD_WriteDc() 
*
* DESCRIPTION:  Write the daughter card register.                
*       
* NOTES:
*   
*F***************************************************************************/
int           
CPLD_WriteDc( int DcReg )
{
	CPLD_DTYPE *pCPLD = (CPLD_DTYPE *)CPLD_BASE_ADDR;

	pCPLD[REGA_DC] = DcReg;
    
    return( (int)DcReg & 0xFF );
}

/*F***************************************************************************
* NAME:   CPLD_WriteCodecMode()
*
* DESCRIPTION:  Write the Codec Mode register. Return value written               
*       
* NOTES:
*   
*F***************************************************************************/
int    
CPLD_WriteCodecMode( int ModeVal )
{
	CPLD_DTYPE *pCPLD = (CPLD_DTYPE *)CPLD_BASE_ADDR;

	pCPLD[REGA_CODEC_L] = ModeVal;
	pCPLD[REGA_CODEC_H] = ModeVal>>8;
    
    return( ModeVal & 0x0FFFF );
}

int CPLD_IsCodecReady( void )
{
	CPLD_DTYPE *pCPLD = (CPLD_DTYPE *)CPLD_BASE_ADDR;
    return( (pCPLD[REGA_MISC] & MISC_REG_CODEC_MT_RDY) == 0 );
}

