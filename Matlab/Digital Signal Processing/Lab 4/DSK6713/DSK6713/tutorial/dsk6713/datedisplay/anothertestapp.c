

// Description: Driver program that makes use of the average library function
//				to compute the average value of a set of integer data values

#include <stdio.h>

int main()
{
	int test_data[] = { 7, 13, 3, 25, 64, 15 };

	// call library functions
	printf( "The average value of the data is %d\n", averageValue(test_data, 5) );
			
	return 0;
}


