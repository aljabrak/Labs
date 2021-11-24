/*
 * Copyright (C) 2003 Texas Instruments Incorporated
 * All Rights Reserved
 */
/*
 *---------dotpV2_timer2.c---------
 * This file contains 'dot product version 2' routine, which is raw C
 * with some optimization by giving more information to compiler
 * in order to unroll the loop and reduce the cycle count.
 */

int dotprod_ver2 (const short *restrict x, const short *restrict h, int nx)
{
	int i, sum = 0;
   
	//Assumption: Vectors x and h are double-word aligned
	_nassert((int)x % 8 == 0);
	_nassert((int)h % 8 == 0);
   
    //Assumption: Counter nx (vector length) is atleast 36 and multiple of 4
	#pragma MUST_ITERATE(36,,4)
	for (i=0; i<nx; i++)
		sum += x[i] * h[i];

	return sum;
}
