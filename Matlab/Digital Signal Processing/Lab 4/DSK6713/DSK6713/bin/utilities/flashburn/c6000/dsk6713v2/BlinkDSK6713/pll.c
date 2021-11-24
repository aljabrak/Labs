/*H*****************************************************************************
*
* $Archive::                                                                   $
* $Revision::                                                                  $
* $Date::                                                                      $
* $Author::                                                                    $
*
* DESCRIPTION:  TMS320C6713 PLL setup.
*
* GLOBALS 
*
* PUBLIC FUNCTIONS:
*                              
* PRIVATE FUNCTIONS:
*
* USAGE/LIMITATIONS:
*
*H***************************************************************************/
#define pll_c

/*---- compilation control switches ----------------------------------------*/

/*****************************************************************************
* INCLUDE FILES
*****************************************************************************/
/*---- system and platform files -------------------------------------------*/

/*---- program files -------------------------------------------------------*/
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
typedef  volatile unsigned * PPLL;
#define PLL_BASE_ADDR           0x01b7c000
#define PLL_PID         ( PLL_BASE_ADDR + 0x000 )
#define PLL_CSR         ( PLL_BASE_ADDR + 0x100 )
#define PLL_MULT        ( PLL_BASE_ADDR + 0x110 )
#define PLL_DIV0        ( PLL_BASE_ADDR + 0x114 )
#define PLL_DIV1        ( PLL_BASE_ADDR + 0x118 )
#define PLL_DIV2        ( PLL_BASE_ADDR + 0x11C )
#define PLL_DIV3        ( PLL_BASE_ADDR + 0x120 )
#define PLL_OSCDIV1     ( PLL_BASE_ADDR + 0x124 )

#define CSR_PLLEN          0x00000001
#define CSR_PLLPWRDN       0x00000002
#define CSR_PLLRST         0x00000008 
#define CSR_PLLSTABLE      0x00000040

#define DIV_ENABLE         0x00008000

/*---- function prototypes -------------------------------------------------*/

/*---- macros --------------------------------------------------------------*/

/*****************************************************************************
* PUBLIC FUNCTION DEFINITIONS
*****************************************************************************/
static void PllDelay( int Count )
{
    volatile int i = Count;
    while(i--);
}

void PLL_Init( void )
{

    // NOTE: If we were running out of SDRAM.  Then user should
    //       first adjust the SDRAM refersh counter such that it
    //       does not miss refreshes.  We can be inside PLL_init
    //       for > 200 us which is more then the 15us SDRAM fresh
    //       period.
     
    // When PLLEN is off DSP is running with CLKIN clock source,
    // currently 50MHz or 20ns clk rate.
    *(PPLL)PLL_CSR  &= ~CSR_PLLEN;
    PllDelay(20);

    // Reset the pll.  PLL takes 125ns to reset.    
    *(PPLL)PLL_CSR  |= CSR_PLLRST;
    PllDelay(20);

    // PLLOUT = CLKIN/(DIV0+1) * PLLM
    // 450    = 50/1 * 9
    // 
    *(PPLL)PLL_DIV0    = DIV_ENABLE + 0;  // Div 1
    *(PPLL)PLL_MULT    = 9;               // x9

#if defined( CE_TEST )
    *(PPLL)PLL_OSCDIV1 = 4;               // Turn CLKOUT3 OFF
#else
    *(PPLL)PLL_OSCDIV1 = DIV_ENABLE + 4;  // 10 MHZ (50/5)
#endif

    // Program in reverse order so that DIV2. 
    // DSP requires that pheriheral clocks be less then
    // 1/2 the CPU clock at all times.
    //

    *(PPLL)PLL_DIV3    = DIV_ENABLE + 4; // 90 MHz EMIF (450/5)
    PllDelay(20);

    *(PPLL)PLL_DIV2    = DIV_ENABLE + 3; // 112.5MHz Pheriherals ()
    PllDelay(20);

    *(PPLL)PLL_DIV1    = DIV_ENABLE + 1; // 225 MHz CPU CLK (450/2)
    PllDelay(20);
    
    *(PPLL)PLL_CSR  &= ~CSR_PLLRST;

    // Delay for minimum of 187.5 us.  In theory the CPU is running
    // at 25MHz at this point (50/2)
    PllDelay( 1500 );

	// Now enable pll path and we are off and running at 225MHz
    *(PPLL)PLL_CSR |= CSR_PLLEN;
    PllDelay(20);
}

