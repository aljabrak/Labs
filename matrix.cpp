//Muhammad Saud Zahir

#include<iostream>
using namespace std;
class matrix    //Class of Matrix. 
{
private:
	int mat[3][3];
public: 
	matrix()                   //Constructor.
	{
		for (int i = 0; i < 3; i++)        //Identity Matrix Initialization.
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == j)
				{
					mat[i][j] = 1;
				}
				else
				{
					mat[i][j] = 0;
				}
			}
		}
	}
	void print_mat()          //Print Matrix Function.
	{
		system("color b0");
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << mat[i][j];
			}
			cout << endl;
		}
	}
};
int main()
{
	matrix m;         //Object of Matrix.
	m.print_mat();
	getchar();
	system("pause");
}
