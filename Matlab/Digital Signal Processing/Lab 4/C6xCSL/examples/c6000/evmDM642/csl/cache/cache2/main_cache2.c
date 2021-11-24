/*
 * Copyright (C) 2003 Texas Instruments Incorporated
 * All Rights Reserved
 */
/*
 *---------main_cache2.c---------
 *
 * This example demonstrates how to maintain coherence between external
 * memory and cache.
 * The double buffers are located in external memory.
 * Data is brought from source array in external memory to input double 
 * buffers, processed and written back from output double buffers to
 * destination array.
 * L2 memory is configured as 64K cache.
 */

#include <stdlib.h>
#include <stdio.h>
#include <csl.h>
#include <csl_dat.h>
#include <csl_cache.h>

//---------Global constants---------

//BUFSIZE:  Size of buffers A and B in bytes (double buffers). Must be a
//          multiple of the L2 cache line size to prevent line sharing
//DATASIZE: Size of source data array to process

#define BUFSIZE     (32*CACHE_L2_LINESIZE)
#define DATASIZE    (4*BUFSIZE)

//---------Global data definition---------


//Buffers A and B in cacheable external memory.
//Align buffers at L2 cache line and make size of buffers a multiple of L2
//  cache line size to prevent line sharing.
//Place buffers contiguously in memory to reduce probability of eviction
#pragma DATA_SECTION(Buff,".external")
#pragma DATA_ALIGN(Buff, CACHE_L2_LINESIZE)
char Buff[4*BUFSIZE];
char *InBuffA = Buff + 0 * BUFSIZE;
char *OutBuffA= Buff + 1 * BUFSIZE;
char *InBuffB = Buff + 2 * BUFSIZE;
char *OutBuffB= Buff + 3 * BUFSIZE;


//Source data to process in external memory
//Destination contains processed data in external memory
#pragma DATA_SECTION(src_data_ext,".external")
#pragma DATA_SECTION(dst_data_ext,".external")
char src_data_ext[DATASIZE];
char dst_data_ext[DATASIZE];


//---------Function prototypes---------
void process(char *input, char *output, int size);
void copy_and_process();
int compare1D(char *in1, char *in2, int len);

//---------main routine---------
void main()
{
    int i;
    
	//Initialise CSL
    CSL_init();
    
    //Make 0x80000000 to 0x80FFFFFF : external memory block cacheable
	CACHE_enableCaching(CACHE_EMIFA_CE00);
    
    //Set L2 to 64K Cache (setup linker command file accordingly)
    CACHE_setL2Mode(CACHE_64KCACHE);
    
    //Open DAT
    DAT_open(DAT_CHAANY, DAT_PRI_HIGH, 0);
    
    //Initialize source array with some value and reset destination to 0
    for (i=0; i<DATASIZE; i++)
    {
        src_data_ext[i] = rand() & 0xFF;
        dst_data_ext[i] = 0x00;
    }

    
    //1. Transfer src_data_ext into double buffers using DMA
    //2. Process the double buffers
    //3. Transfer the output of processed buffer to dst_data_ext using DMA
	
    //Since we just wrote to external memory that is now being accessed
    //  in copy_and_process(), we have to ensure coherence. Some of the
    //  data written is still contained in L2/L1D cache and now has to be
    //  written back to external memory before the DMA accesses this data.
    //Since the DMA will modify the data, and the CPU at the end reads it
    //  back for a memory compare, the arrays also have to be invalidated.
    CACHE_wbInvL2(src_data_ext, DATASIZE, CACHE_WAIT);  
    CACHE_wbInvL2(dst_data_ext, DATASIZE, CACHE_WAIT);  
    
    //Function to handle DMA transfers and processing of data
    copy_and_process();

	//Compare the destination content with the source
	if (compare1D(src_data_ext, dst_data_ext, DATASIZE))
			printf("\nTEST FAILED\n");
	else 	printf("\nTEST PASSED\n");
	
	//Close DAT before exiting the program
    DAT_close();
    
    return;
}
    


//Copy input data to double buffer and process it
void copy_and_process()
{
    int i;
    
    
    //DMA Transfer IDs
    Uint32  id_InBuffA  = DAT_XFRID_WAITNONE,
            id_InBuffB  = DAT_XFRID_WAITNONE,
            id_OutBuffA = DAT_XFRID_WAITNONE,
            id_OutBuffB = DAT_XFRID_WAITNONE;

    //Initially, fill buffer InBuffA and InBuffB.
    //Each call of DAT_copy places the transfer request in a queue. If the
    //  tranfer request has reached the head of the queue it is being 
    //  processed.
    //Invalidate InBuffA and InBuffB. This we need to do before the DMA,
    //  otherwise the new data will be overwritten.
    CACHE_invL2(InBuffA, BUFSIZE, CACHE_WAIT);  
    id_InBuffA = DAT_copy(src_data_ext, InBuffA, BUFSIZE);
    CACHE_invL2(InBuffB, BUFSIZE, CACHE_WAIT);  
    id_InBuffB = DAT_copy(src_data_ext+BUFSIZE, InBuffB, BUFSIZE);
        
    for (i=0; i<(DATASIZE/BUFSIZE)-2; i+=2)
    {
        
        //InBuffA -> OutBuffA Processing
        //Wait for InBuffA to be filled, and OutBuffA to be emptied.
        //Then InBuffA can be processed. After that the results in
        //  OutBuffA are send to the destination in external memory,
        //  and InbuffA is filled with new data.
        DAT_wait(id_InBuffA); 
        DAT_wait(id_OutBuffA); 
        
        process(InBuffA, OutBuffA, BUFSIZE);
        
        //OutBuffA has been filled, but it's still in L2 Cache.
        //Therfore, before copying it to the dst buffer, it must be
        //  written back. An invalidate is not required here and will
        //  actually speed up the processing since the next time OutBuffA
        //  is written to, data doesn't need to be allocated again in
        //  L2 Cache.
        CACHE_wbL2(OutBuffA, BUFSIZE, CACHE_WAIT);  
        id_OutBuffA = DAT_copy(OutBuffA, &dst_data_ext[i*BUFSIZE], BUFSIZE);
        CACHE_invL2(InBuffA, BUFSIZE, CACHE_WAIT);  
        id_InBuffA  = DAT_copy(&src_data_ext[(i+2)*BUFSIZE], InBuffA, BUFSIZE);
        
        //InBuffB -> OutBuffB Processing
        //Wait for InBuffB to be filled, and OutBuffB to be emptied.
        //Then InBuffB can be processed. After that the results in
        //  OutBuffB are send to the destination in external memory,
        //  and InbuffB is filled with new data.
        DAT_wait(id_InBuffB); 
        DAT_wait(id_OutBuffB); 
        
        //Call the processing function
        process(InBuffB, OutBuffB, BUFSIZE);
        
        CACHE_wbL2(OutBuffB, BUFSIZE, CACHE_WAIT);  
        id_OutBuffB = DAT_copy(OutBuffB, &dst_data_ext[(i+1)*BUFSIZE], BUFSIZE);
        CACHE_invL2(InBuffB, BUFSIZE, CACHE_WAIT);  
        id_InBuffB  = DAT_copy(&src_data_ext[(i+3)*BUFSIZE], InBuffB, BUFSIZE);
    }

    //Complete the last two buffers without copying new data into InBuffA
    //  and InBuffB.
    DAT_wait(id_InBuffA); 
    DAT_wait(id_OutBuffA); 
        
    process(InBuffA, OutBuffA, BUFSIZE);

    CACHE_wbL2(OutBuffA, BUFSIZE, CACHE_WAIT);  
    id_OutBuffA = DAT_copy(OutBuffA, &dst_data_ext[i*BUFSIZE], BUFSIZE);
        
    DAT_wait(id_InBuffB); 
    DAT_wait(id_OutBuffB); 
        
    process(InBuffB, OutBuffB, BUFSIZE);
        
    CACHE_wbL2(OutBuffB, BUFSIZE, CACHE_WAIT);  
    id_OutBuffB = DAT_copy(OutBuffB, &dst_data_ext[(i+1)*BUFSIZE], BUFSIZE);
}

//Dummy process routine that just copies the data
void process(char *input, char *output, int size)
{
    int i;
    
    for (i=0; i<size; i++)
    {
        output[i] = input[i];
    }
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
