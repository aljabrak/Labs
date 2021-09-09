// Scope Resolution.

#include <iostream>
#include <string>
using namespace std;
class car {
private:
	int model;
public:
    void c_model();
};
inline void car::c_model()
{
	cout << "Model Number: " << endl;
	cin >> model;
	cout << model;
}
int main()
{
	car a;
	a.c_model();
	return 0;
}
