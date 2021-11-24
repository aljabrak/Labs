/*******************************************************************************
*
* Borrowed from earlier work done by souls
*   braver than mine....
*
* Originally, this was the Blink program example,
* but I modified it a little to remove the audio
* portions, and to make a slightly different blink
* pattern.
*       Russ Heeschen, TI Pittsburgh
*
* NOTES: Assumptions:
*             6713 DSK
*             CPLD connected to CE1
*             AMD29LV400BT flash connected to CE1
*             SDRAM connected to CE0
*
*
*/

#include "c6713dsk.h"
#include "cpld.h"
#include "timer.h"


/* Main function, initializes and loops, blinking the LEDs
 * (Not much of a surprise, I suppose.)
 */
void main( void )
{   
    int           i;
    
    CSL_init();
	
	/* DSP initialization */
	IRQ_globalDisable();
	for(i=0;i<32;i++)
	{
	    IRQ_disable(i);   /* Disable and clear all IRQ events    */
	    IRQ_clear(i);     /* except reset and NMI interrupts     */
	}

    PLL_Init();
    EMIF_Init();
    TIMER_Init();
    
    CPLD_LedOff( LED_ALL );
    TIMER_DelayMsec( 100 );
    CPLD_LedOn( LED_ALL );
    TIMER_DelayMsec( 500 );
    
    // Very simple Led test.  Turn them all off then on
    // one at a time, then off one at a time.
  	CPLD_LedOff( LED_ALL );
    
    for(;;)
    {
	    for( i=0; i<LED_AVAILABLE; i++ )
	    {
	    	CPLD_LedOn( LED_0 << i );
	    	TIMER_DelayMsec( 100 );
	    }
	    
	    for( i=0; i<LED_AVAILABLE; i++ )
	    {
	    	CPLD_LedOff( LED_0 << i );
         	TIMER_DelayMsec( 100 );	    	
	    }
        
        TIMER_DelayMsec( 500 );	    	
	}
}
