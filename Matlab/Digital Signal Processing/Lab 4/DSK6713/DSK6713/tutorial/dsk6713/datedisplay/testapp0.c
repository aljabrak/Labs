
// Description: Driver program that makes use of two library functions to
//				calculate the maximum and minimum values within an array

#include <stdio.h>

int main()
{
	int test_data[] = { 7, 13, 3, 25, 64, 15 };

	// call library functions
	printf( "The maximum value in the data is %d\n", maximumValue(test_data, 5) );
	printf( "The minimum value in the data is %d\n", minimumValue(test_data, 5) );	
	return 0;
}