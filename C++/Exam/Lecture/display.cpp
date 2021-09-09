#include <iostream>
#include <iostream>
using namespace std;

class display
{
	void arrayprint(int arr1[5], int arr2[5])
	{
		int* ptrint;
		for (int j = 0; j < 5; j++)
		{
			if (j % 2 == 0)
			{
				ptrint = arr1;
				cout << *(ptrint + j) << endl;
			}
			else
			{
				ptrint = arr2;
				cout << *(ptrint--) << endl;
			}

		}
	}
};
int main()
{
	int arr1[5] = { 11,22,77,22,44 };
	int arr2[5] = { 33,55,77,66,33 };

}
