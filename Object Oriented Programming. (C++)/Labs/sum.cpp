#include<iostream>
using namespace std;
int sum(int n);
int main()
{
	int n;
	cout << "Enter a positive integer: ";
	cin >> n;
	cout << "Sum =  " << sum(n) <<endl;
	system("pause");
	return 0;
}
int sum(int n)
{
	if (n != 0)
		return n + sum(n - 1);
	else
	return 0;
}
