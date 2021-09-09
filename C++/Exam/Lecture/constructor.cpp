//Constructor

#include <iostream>
#include <string>
using namespace std;
class demo {
private:
	int data;
public:
	demo()
	{
		data = 50;
	};
	void display()
	{
		cout << "Data = " << data;
	};
};
int main()
{
	demo obj1;
	obj1.display();
	return 0;
}
