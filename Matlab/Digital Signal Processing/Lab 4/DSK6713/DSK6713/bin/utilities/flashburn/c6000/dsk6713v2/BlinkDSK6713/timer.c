/*H*****************************************************************************
*
* $Archive::                                                                   $
* $Revision::                                                                  $
* $Date::                                                                      $
* $Author::                                                                    $
*
* DESCRIPTION:  Timer delay code
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
*
* COMPILE SWITCHES:
*
*H***************************************************************************/
#define timer_c

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

/*****************************************************************************
* EXTERNAL REFERENCE    
*****************************************************************************/
/*---- data declarations ---------------------------------------------------*/

/*---- function prototypes -------------------------------------------------*/

/*****************************************************************************
* PUBLIC DECLARATIONS 
*****************************************************************************/

/*---- data declarations ---------------------------------------------------*/
TIMER_Handle hTimer = NULL;


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
* NAME:   TIMER_Init()
*
* DESCRIPTION: Setup our timer that is used for all TEB examples.       
*       
* NOTES:
*   
*F***************************************************************************/
void TIMER_Init(void)
{
  
  TIMER_Config myTimerConfig;  
                 
  hTimer = TIMER_open(TIMER_DEVANY, TIMER_OPEN_RESET);
  TIMER_getConfig( hTimer, &myTimerConfig);
  myTimerConfig.ctl &= 0xff3f;
  myTimerConfig.ctl |= 0x200;
  myTimerConfig.prd = 0xFFFFFFFF;
  myTimerConfig.cnt = 0x00000000;
  TIMER_config(hTimer, &myTimerConfig);

  TIMER_start(hTimer);
  TIMER_pause(hTimer);
}

/*F***************************************************************************
* NAME:   TIMER_DelayMsec()
*
* DESCRIPTION: Simple delay based on 500 MHz DSP clock.       
*       
* NOTES:
*   
*F***************************************************************************/

void TIMER_DelayMsec(short msec)
{ 

  /* Assume 500 MHz CPU, timer period is CPUCLK/8 for C64x */
  Uint32 timer_limit = (msec*62500);
  Uint32 time_start;
  Uint32 time_current;

  if( hTimer == NULL )
      return;
      
  time_start = TIMER_getCount(hTimer);
  TIMER_resume(hTimer);
  do
  {
  	time_current = TIMER_getCount(hTimer);
  }while( (time_current-time_start) < timer_limit);
  
}
