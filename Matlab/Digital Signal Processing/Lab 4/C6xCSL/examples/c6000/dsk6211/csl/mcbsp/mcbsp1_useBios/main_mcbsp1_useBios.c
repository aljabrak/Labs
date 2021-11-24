/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/*
 *---------main_mcbsp1_useBios.c---------
 *
 * This example configures the serial port for digital loopback mode.
 * We then use the CPU to write/read from the port. In loopback mode, we 
 * should read back the same value as written, which is checked for in a loop
 */
#include <std.h>
#include <log.h>

#include <csl.h>
#include <csl_mcbsp.h>

/*----------------------------------------------------------------------------*/
extern far LOG_Obj LogMain;

/*----------------------------------------------------------------------------*/
/* create a config structure for digital loopback mode */
static MCBSP_Config ConfigLoopback = {
  MCBSP_SPCR_RMK(
    MCBSP_SPCR_FREE_YES,
    MCBSP_SPCR_SOFT_YES,
    MCBSP_SPCR_FRST_YES,
    MCBSP_SPCR_GRST_YES,
    MCBSP_SPCR_XINTM_XRDY,
    MCBSP_SPCR_XSYNCERR_NO,
    MCBSP_SPCR_XRST_YES,
    MCBSP_SPCR_DLB_ON,
    MCBSP_SPCR_RJUST_RZF,
    MCBSP_SPCR_CLKSTP_DISABLE,
    MCBSP_SPCR_DXENA_OFF,
    MCBSP_SPCR_RINTM_RRDY,
    MCBSP_SPCR_RSYNCERR_NO,
    MCBSP_SPCR_RRST_YES
  ),
  MCBSP_RCR_RMK(
    MCBSP_RCR_RPHASE_SINGLE,
    MCBSP_RCR_RFRLEN2_OF(0),
    MCBSP_RCR_RWDLEN2_8BIT,
    MCBSP_RCR_RCOMPAND_MSB,
    MCBSP_RCR_RFIG_YES,
    MCBSP_RCR_RDATDLY_0BIT,
    MCBSP_RCR_RFRLEN1_OF(0),
    MCBSP_RCR_RWDLEN1_32BIT,
    MCBSP_RCR_RWDREVRS_DISABLE
  ),
  MCBSP_XCR_RMK(
    MCBSP_XCR_XPHASE_SINGLE,
    MCBSP_XCR_XFRLEN2_OF(0),
    MCBSP_XCR_XWDLEN2_8BIT,
    MCBSP_XCR_XCOMPAND_MSB,
    MCBSP_XCR_XFIG_YES,
    MCBSP_XCR_XDATDLY_0BIT,
    MCBSP_XCR_XFRLEN1_OF(0),
    MCBSP_XCR_XWDLEN1_32BIT,
    MCBSP_XCR_XWDREVRS_DISABLE
  ),
  MCBSP_SRGR_RMK(
    MCBSP_SRGR_GSYNC_FREE,
    MCBSP_SRGR_CLKSP_RISING,
    MCBSP_SRGR_CLKSM_INTERNAL,
    MCBSP_SRGR_FSGM_DXR2XSR,
    MCBSP_SRGR_FPER_OF(63),
    MCBSP_SRGR_FWID_OF(31),
    MCBSP_SRGR_CLKGDV_OF(15)
  ),
  MCBSP_MCR_DEFAULT,
  MCBSP_RCER_DEFAULT,
  MCBSP_XCER_DEFAULT,
  MCBSP_PCR_RMK(
    MCBSP_PCR_XIOEN_SP,
    MCBSP_PCR_RIOEN_SP,
    MCBSP_PCR_FSXM_INTERNAL,
    MCBSP_PCR_FSRM_EXTERNAL,
    MCBSP_PCR_CLKXM_OUTPUT,
    MCBSP_PCR_CLKRM_INPUT,
    MCBSP_PCR_CLKSSTAT_0,
    MCBSP_PCR_DXSTAT_0,
    MCBSP_PCR_FSXP_ACTIVEHIGH,
    MCBSP_PCR_FSRP_ACTIVEHIGH,
    MCBSP_PCR_CLKXP_RISING,
    MCBSP_PCR_CLKRP_FALLING
  )
};

/*----------------------------------------------------------------------------*/
void main() {

  MCBSP_Handle hMcbsp;
  volatile Uint32 x,y;
  int success = 1;

  /* Initialize the chip support library, required */
  CSL_init();

  LOG_printf(&LogMain,"<MCBSP1>");

  /* Let's open up serial port 1 */
  hMcbsp = MCBSP_open(MCBSP_DEV1, MCBSP_OPEN_RESET);

  /* We'll set it up for digital loopback, 32bit mode. We have   */
  /* to setup the sample rate generator to allow self clocking.  */
  MCBSP_config(hMcbsp,&ConfigLoopback);

  /* Now that the port is setup, let's enable it in steps. */
  MCBSP_start(hMcbsp,MCBSP_RCV_START | MCBSP_XMIT_START | MCBSP_SRGR_START| MCBSP_SRGR_FRAMESYNC, MCBSP_SRGR_DEFAULT_DELAY);


  /* Now we'll loop for a while writing values out to the port */
  /* then reading them back in. This should take a few seconds.*/
  for (y=0; y<0x00080000; y++) {

    /* wait until the transmitter is ready for a sample then write to it */
    while (!MCBSP_xrdy(hMcbsp));
    MCBSP_write(hMcbsp,y);

    /* now wait until the value is received then read it */
    while (!MCBSP_rrdy(hMcbsp));
    x = MCBSP_read(hMcbsp);

    /* check to make sure they match */
    if (x != y) {
      success = 0;
      break;
    }
  }

  /* All done now, close the port. */
  MCBSP_close(hMcbsp);

  /******************************************************************************\
   *   Add a Break Point at the Second LOG_Printf Statement. Result is displayed*
   * in the message log window                                                  *
   *                                    success=1  -> PASS                                      *
   *                                    success=0  -> FAIL                                      *
   ******************************************************************************/

  LOG_printf(&LogMain,"success=%d",success);
  LOG_printf(&LogMain,"<DONE>");
}
