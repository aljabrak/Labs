//Muhammad Saud Zahir.

#include <iostream>
#include <string>
using namespace std;
class Insurance
{
private:
	string carName;
	int carModel, carPrice;
	float insuranceAmount;
	friend class Details;
public:
	Insurance();
	void calcInsurance();
	void setCarName(string name);
	void setCarModel(int model);
	void setCarPrice(int price);
	void setInsuranceAmount(float insAmount);
};
class Details
{
public:
	void details(Insurance a) const;
};


source.cpp File:

#include <iostream>
#include <string>
#include "Header.h"
using namespace std;
Insurance::Insurance()
{
	setCarName("car");
	setCarModel(0000);
	setCarPrice(00);
}
void Insurance::calcInsurance()
{
	float amount = carPrice * (0.02);
	setInsuranceAmount(amount);
}
void Insurance::setCarName(string name)
{
	carName = name;
}
void Insurance::setCarModel(int model)
{
	carModel = model;
}
void Insurance::setCarPrice(int price)
{
	carPrice = price;
}
void Insurance::setInsuranceAmount(float insAmount)
{
	insuranceAmount = insAmount;
}
void Details::details(Insurance a) const
{
	cout << " Your Car Is : " << a.carName << endl;
	cout << " Your Car Model Is: " << a.carModel << endl;
	cout << " Your Car Price Is: " << a.carPrice << endl;
	cout << " Insurance Amount Of Your Car Is: " << a.insuranceAmount << endl;
}

test.cpp File:

#include <iostream>
#include <string>
#include "Header.h"
using namespace std;
int main()
{
	system("color b0");
	Insurance ins;
	const Details det;
	string name;
	int model, price;
	cout << " Enter Your Car Name: ";
	cin >> name;
	ins.setCarName(name);
	cout << " Enter Car Model: ";
	cin >> model;
	ins.setCarModel(model);
	cout << " Enter Car Price In Lacs: ";
	cin >> price;
	ins.setCarPrice(price);
	ins.calcInsurance();
	det.details(ins);
	system("pause");

}
