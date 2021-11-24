
// ****************************************************************
// Description: Library function to determine the 
// minimum value within a integer array. Note this code stresses
// simplicity over robustness and efficiency.
// ****************************************************************

int minimumValue( int [], int);

// Requires:	array_size equals the number of elements in the array, array_size > 0
// Returns:		The minimum value contained in the integer array  
int minimumValue( int values[], int array_size)
{	
	int minimum_value;
	int i = 0;
			
	minimum_value = values[0];

	for (i = 0; i < array_size; i++) {
		if (values[i] < minimum_value) 
			minimum_value = values[i];
	}
	
	return minimum_value;
}
	

