/*
 * Copyright (C) 2003 Texas Instruments Incorporated
 * All Rights Reserved
 */
/*
 *---------main_timer2.c---------
 * This example demonstrates use of Timer to profile (benchmark) the code.
 * Several API's are provided to work with the profiler.
 * It outputs the number of cpu cycles taken by dot product function
 * with optimization and without optimization.
 */

#include <stdio.h>
#include "profiler_timer2.h"

//---------Global constants---------

//Array size
#define BUFF_SIZE			100

//Timer device number to be used for profiling (Use -1 for any timer device)
#define TIMER_NUM			1

//Ratio of (CPU CLK/TIMER CLK) - it is always 8 for 64xx with internal CLK
//  source for timer
#define CPUCLK_BY_TIMCLK	8

//---------Global data definition---------

// The buffers passed to dot product routine
short in1[BUFF_SIZE];
short in2[BUFF_SIZE];

//---------Function prototypes---------
extern int dotprod_ver1(short *, short *, int);
extern int dotprod_ver2(short *, short *, int);

void init_arrays(short *, short *);

//---------main routine---------
void main()
{
	int dot_product1, dot_product2, ret_status;
	long cpu_cycles1, cpu_cycles2;
	
	//Initialise the arrays
	init_arrays(in1, in2);
	
	//Configure timer to be used for profiling
	if ((ret_status = profile_timConfig(TIMER_NUM, CPUCLK_BY_TIMCLK)) != 0)
	{
		switch(ret_status)
		{
			case ERR_INVDEVNUM :
				printf("\nERROR:Invalide timer device number input");
				break;
			case ERR_INVCLKRATIO :
				printf("\nERROR:Invalide CLK ratio input");
				break;
			case ERR_BADHANDLE :
				printf("\nERROR:Timer open failed with invalid handle");
				break;
			default:
				printf("\nERROR:Profiler configure failed");			
		}
		printf("\nTEST FAILED\n");
		exit(1);
	}
	
	//Start profiler
	profile_begin();
	
	//Call the function to be profiled
	dot_product1 = dotprod_ver1(in1, in2, BUFF_SIZE);
	
	//Stop the profiler
	cpu_cycles1 = profile_end();
	
	//Start profiler
	profile_begin();
	
	//Call the function to be profiled
	dot_product2 = dotprod_ver2(in1, in2, BUFF_SIZE);
	
	//Stop the profiler
	cpu_cycles2 = profile_end();
	
	if (cpu_cycles1 < 0  ||  cpu_cycles2 < 0)
	{
		printf("\nERROR:Timer handle is invalid, no profiling is done\n");
		printf("\nTEST FAILED\n");
		exit(1);
	}
	
	//Print appropriate output
	printf("\n\t\tdotprod_ver1\tdotprod_ver2");
	printf("\n-------------------------------------------------");
	printf("\nDot product:\t%d\t%d\n",dot_product1, dot_product2);
	printf("\nCPU cycles :\t%ld\t\t%ld\n",cpu_cycles1, cpu_cycles2);
	
	if ((dot_product1 != dot_product2) || (cpu_cycles1 < cpu_cycles2))
		printf("\nTEST FAILED\n");
	else printf("\nTEST PASSED\n");
	
	//Close the profiler just before returning from main()
	profile_timClose();
}

//Function to initialise two arrays to be used in dot product routine
void init_arrays(short *arr1, short *arr2)
{
	int i;
	
	for (i = 0; i < BUFF_SIZE; i++)
	{
		arr1[i] = i + 0x1111;
		arr2[i] = 0x2222 - i;
	}
}
