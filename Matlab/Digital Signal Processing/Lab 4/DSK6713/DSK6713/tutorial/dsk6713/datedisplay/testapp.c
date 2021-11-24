
// Description: Driver program that makes use of two library functions to
//				calculate the maximum, minimum and spread values within an array

#include <stdio.h>

int main()
{
	int test_data[] = { 7, 13, 3, 25, 64, 15 };

	int max_value = maximumValue(test_data, 5);
	int min_value = minimumValue(test_data, 5);

	// call library functions
	printf( "The maximum value in the data is %d\n", max_value );
	printf( "The minimum value in the data is %d\n", min_value );	
	printf( "The spread of the data is %d\n", max_value - min_value ); 
		
	return 0;
}
