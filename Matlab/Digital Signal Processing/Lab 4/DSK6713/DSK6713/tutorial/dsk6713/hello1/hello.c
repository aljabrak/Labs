/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.90.270 01-08-04 (bios,dsk6713-c04)" */
/***************************************************************************/
/*                                                                         */
/*     H E L L O . C                                                       */
/*                                                                         */
/*     Basic C standard I/O from main.                                     */
/*                                                                         */
/*                                                                         */
/***************************************************************************/

#include <stdio.h>
#include "hello.h"

#define BUFSIZE 30

struct PARMS str = 
{
    2934,
    9432,
    213,
    9432,
    &str
};


/*
 *  ======== main ========
 */
void main()
{
#ifdef FILEIO
    int       i;
    char      scanStr[BUFSIZE];
    char      fileStr[BUFSIZE];
    size_t    readSize;
    FILE      *fptr;
#endif

    /* write a string to stdout */
    puts("hello world!\n");

#ifdef FILEIO
    /* clear char arrays */
    for (i = 0; i < BUFSIZE; i++) {
        scanStr[i] = 0          /* deliberate syntax error */
        fileStr[i] = 0;
    }
    
    /* read a string from stdin */
    scanf("%s", scanStr);
    
    /* open a file on the host and write char array */
    fptr = fopen("file.txt", "w");
    fprintf(fptr, "%s", scanStr);
    fclose(fptr);
                      
    /* open a file on the host and read char array */                      
    fptr = fopen("file.txt", "r");
    fseek(fptr, 0L, SEEK_SET);                              
    readSize = fread(fileStr, sizeof(char), BUFSIZE, fptr);
    printf("Read a %d byte char array: %s \n", readSize, fileStr);
    fclose(fptr);
#endif    
}
