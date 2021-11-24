
// ****************************************************************
// Description: Library function to determine the 
// average value of a integer array. Note this code stresses
// simplicity over robustness and efficiency.
// ****************************************************************


int averageValue( int [], int);

// Requires:	array_size equals the number of elements in the array, array_size > 0
// Returns:		The average value of the integer array  
int averageValue( int values[], int array_size)
{	
	int total = 0;
	int i = 0;
			
	for (i = 0; i < array_size; i++) {
		total = total + values[i];
	}

	return (int)total/array_size; 
}
	

