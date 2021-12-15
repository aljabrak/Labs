//Constructor Overloading.

#include <iostream>
#include <string>
using namespace std;
class car {
private:
	int model_number;
	string model_name;
public:
	car(int model_number,string model_name);
};
 car::car(int model_number,string model_name)
{
	cin >> model_number;
	cout << model_number;
	cin >> model_name;
	cout << model_name;
}
int main()
{
	car a(2016,"Suzuki");
	return 0;
}
