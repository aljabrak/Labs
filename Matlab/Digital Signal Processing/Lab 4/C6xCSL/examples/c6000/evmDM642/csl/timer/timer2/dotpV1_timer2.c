/*
 * Copyright (C) 2003 Texas Instruments Incorporated
 * All Rights Reserved
 */
/*
 *---------dotpV1_timer2.c---------
 * This file contains 'dot product version 1' routine, which is raw C code
 * without any optimization. 
 */

int dotprod_ver1 (short *x, short *h, int nx)
{
	int i, sum = 0;
   
	for (i = 0; i < nx; i++)
		sum += x[i] * h[i];

	return sum;
}
