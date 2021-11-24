/*
 * Copyright (C) 2003 Texas Instruments Incorporated
 * All Rights Reserved
 */
/*
 *---------main_cache1.c---------
 *
 * This example demonstrates how to switch L2 CACHE mode at run-time.
 * It assumes that Task A uses 32K cache and has its state stored in an array
 * stateA. Task B needs 64K cache and has its state stored in stateB array.
 * Task B executes in between two runs of Task A and stateA is stored in the
 * SRAM region which will be treated as cache after increasing the cache size.
 * It is therefore required to copy the state information of Task A into an
 * external memmory buffer. Once Task B finishes the execution, the program
 * restores original 32K cache configuration.
 * Now copy back the buffer content holding the state information of Task A
 * into original memory region and then run Task A further.
 */

#include <stdio.h>
#include <csl.h>
#include <csl_cache.h>

//---------Global constants---------
#define STATE_SZ	100	

//---------Global data definition---------

//Task A state: simulated using an array stateA
#pragma DATA_SECTION(stateA, ".sramStateA");
char stateA[STATE_SZ];

//Buffer to hold the Task A state
#pragma DATA_SECTION(buf, ".external")
char buf[STATE_SZ];

//Task B state: simulated using an array stateB
char stateB[STATE_SZ];

//Pointer to the memory location that holds stateA when Task A is running
//This is also the start address of internal memory segment that behaves as
//  SRAM for 0K and 32K cache-mode and CACHE for rest of the modes
char *ptr = (char *)0x30000;

//---------Function prototypes---------
void processAdd (char *in, int len, int val);
void copy1D(char *src, char *dst, int len);
int compare1D(char *in1, char *in2, int len);

//---------main routine---------
void main()
{
	int i;
	
	//Initialise CSL
    CSL_init();
    
    //Make 0x80000000 to 0x80FFFFFF : external memory block cacheable
    CACHE_enableCaching(CACHE_EMIFA_CE00);
    
    //Task A requires 32K cache size
	CACHE_setL2Mode(CACHE_32KCACHE);
	
	//Initialise Task A state array
	for (i = 0; i < STATE_SZ; i++)
		stateA[i] = 'a';		
	
	//Task A state processing
	processAdd(stateA, STATE_SZ, 1);
	
	//Before increasing cache size, copy Task A state into a buffer in 
	//  the external memory
	copy1D(stateA, buf, STATE_SZ);
	
	//Increase cache size as required by Task B
	CACHE_setL2Mode(CACHE_64KCACHE);
	
	//Task B running with the increased cache size
	processAdd(stateB, STATE_SZ, -10);
	
	//Task B finished running and Task A to start again
	//Restore previous cache size
	CACHE_setL2Mode(CACHE_32KCACHE);
	
	//copy back from external memory to internal memory
	//Assumption: stateA start address is same as pointed to by 'ptr'
	copy1D(buf, ptr, STATE_SZ);
	
	//compare the restored state of Task A with the buffer content
	if (compare1D(stateA, buf, STATE_SZ)) 
			printf("\nTEST FAILED\n");
	else 	printf("\nTEST PASSED\n");
	
	return;
}

//---------Subroutine definition---------

//Function to add a value to all the elements of an array
void processAdd (char *in, int len, int val)
{
	int i;
	for (i = 0; i < len; i++)
		in[i] += val;
}

//Function to copy 1 Dimensional source array to destination array
void copy1D(char *src, char *dst, int len)
{
	int i;
	for (i = 0; i < STATE_SZ; i++)
		dst[i] = src[i];
}

//Function to compare two 1 Dimensional arrays
int compare1D(char *in1, char *in2, int len)
{
	int i, retVal = 0;
		
	for (i = 0; i < len; i++)
	{
		if (in1[i] != in2[i])
		{
			retVal = 1;
			break;
		}
	}
	return retVal;
}
