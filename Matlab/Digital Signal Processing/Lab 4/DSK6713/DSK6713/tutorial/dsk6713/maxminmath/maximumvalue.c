
// ****************************************************************
// Description: Library function to determine the 
// maximum value within a integer array. Note this code stresses
// simplicity over robustness and efficiency.
// ****************************************************************

int maximumValue( int [], int);

// Requires:	array_size equals the number of elements in the array, array_size > 0
// Returns:		The maximum value contained in the integer array  
int maximumValue( int values[], int array_size)
{	
	int maximum_value;
	int i = 0;
			
	maximum_value = values[0];

	for (i = 0; i < array_size; i++) {
		if (values[i] > maximum_value) 
			maximum_value = values[i];
	}
	
	return maximum_value;
}
	

