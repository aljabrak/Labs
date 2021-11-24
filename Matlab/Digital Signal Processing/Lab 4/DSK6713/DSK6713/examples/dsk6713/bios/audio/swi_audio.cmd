/*
 *  Linker-command file for the application
 *
 */
 
/* include config-generated link command file */
-l swi_audiocfg.cmd

/* include libraries for the IOM driver and PIO adapter */
-l dsk6713_edma_aic23.l67
-l c6x1x_edma_mcbsp.l67
