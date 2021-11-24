/*
 *  Linker-command file for the application
 *
 */
 
/* include config-generated link command file */
-l pip_audiocfg.cmd

/* include libraries for the IOM driver and PIO adapter */
/* bind the low level codec driver to C6416-PCM3002 implementation*/
-l dsk6713_edma_aic23.l67
-l c6x1x_edma_mcbsp.l67
-l pio.l67
