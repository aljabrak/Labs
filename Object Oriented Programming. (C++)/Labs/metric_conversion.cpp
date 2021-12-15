//Conversion.h File:
#include <string>
using namespace std;

class Conversion
{
private:
	double length, weight, temperature;
public:
	void setLength(double);
	double getLength();
	void setWeight(double);
	double getWeight();
	void setTemperature(double);
	double getTemperature();
	void footToMeter();
	void footToCentimeter();
	void poundsToKg();
	void kgToPounds();
	void fahrenheitToCelsius();
	void celsiusToFahrenheit();
};

Conversion.cpp File:
#include <iostream>
#include <string>
#include "Conversion.h"
using namespace std;
void Conversion::setTemperature(double a)
{
	temperature = a;
}
void Conversion::setWeight(double a)
{
	weight = a;
}
void Conversion::setLength(double a)
{
	length = a;
}
double Conversion::getTemperature()
{
	return temperature;
}
double Conversion::getWeight()
{
	return weight;
}
double Conversion::getLength()
{
	return length;
}
void Conversion::fahrenheitToCelsius()
{
	temperature = (temperature - 32) * 0.5555555556;
}
void Conversion::celsiusToFahrenheit()
{
	temperature = (temperature * 1.8) + 32;
}
void Conversion::poundsToKg()
{
	weight = weight * 0.453592;
}
void Conversion::kgToPounds()
{
	weight = weight * 2.20462;
}
void Conversion::footToMeter()
{
	length = length*0.3048;
}
void Conversion::footToCentimeter()
{
	length = length * 30.48;
}


//TestConversion.cpp File:
//Muhammad Saud Zahir.

#include <iostream>
#include "Conversion.h"`
using namespace std;
int main() {
	int s;
	int x;
	double T,L,W,a;
line:
	cout << "\t\t\t CONVERSIONS CALCULATOR" << endl;
	cout << "Enter: \t\t\t 1 for Temperature \n\t\t\t 2 for Weight \n\t\t\t 3 for Length" << endl;
	cin >> s;
	if (s == 1 ) 
	{
		cout << "Press 1 for Fahrenheit(*F)-Celsius(*C) and Press 0 for Celsius(*C)-Fahrenheit(*F)" << endl;
		cin >> x;
		if (x == 1)
		{
			cout << "Enter the Temperature" << endl;
			cin >> T;
			Conversion temperature1;
			temperature1.setTemperature(T);
			temperature1.fahrenheitToCelsius();
			cout << T << " Degree Fahrenheit = " << temperature1.getTemperature() << " Degree Celsius" << endl;
			cout << "Press 1 to continue otherwise 0" << endl;
			cin >> x;
			if (x == 1) 
			{
				goto line;
			}
		}
		else if( x== 0)
		{
			cout << "Enter the Temperature" << endl;
			cin >> T;
			Conversion temperature1;
			temperature1.setTemperature(T);
			temperature1.celsiusToFahrenheit();
			cout << T << " Degree Celsius = " << temperature1.getTemperature() << " Degree Fahrenheit" << endl;
			cout << "Press 1 to continue otherwise 0" << endl;
			cin >> x;
			if (x == 1) 
			{
				goto line;
			}
		}
		else
		{
			cout << "Error";
		}
		system("color b0");
		system("pause");
	}
	if (s == 2)
	{
		cout << "Press 1 for Pound(lb)-Kilogramme(Kg) and Press 0 for Kilogramme(Kg)-Pound(lb)" << endl;
		cin >> x;
		if (x == 1) {
			cout << "Enter the Weight" << endl;
			cin >> W;
			Conversion weight1;
			weight1.setWeight(W);
			weight1.poundsToKg();
			cout << W << " Pounds(lb) = " << weight1.getWeight() << " Kilograms(kg) " << endl;
			cout << "Press 1 to continue otherwise 0" << endl;
			cin >> x;
			if (x == 1) 
			{
				goto line;
			}
		}
		else if(x==0)
		{
			cout << "Enter the Weight" << endl;
			cin >> W;
			Conversion weight1;
			weight1.setWeight(W);
			weight1.kgToPounds();
			cout << W << " Kilograms = " << weight1.getWeight() << " Pounds " << endl;
			cout << "Press 1 to continue otherwise 0" << endl;
			cin >> x;
			if (x == 1)
			{
			   goto line;
			}
		}
		else
		{
			cout << "Error";
		}
		system("color b0");
		system("pause");
	}

	if (s == 3 ) 
	{
		cout << "Press 1 for Foot(ft)-Metre(m) and Press 0 for Foot(ft)-Centimetre(cm)" << endl;
		cin >> x;
		if (x == 1) 
		{
			cout << "Enter the Length:" << endl;
			cin >> L;
			Conversion length1;
			length1.setLength(L);
			length1.footToMeter();
			cout << L << " Foot = " << length1.getLength() << " Meters " << endl;
			cout << "Press 1 to continue otherwise 0" << endl;
			cin >> x;
			if (x == 1)
			{
				goto line;
			}
		}
		else if(x == 0)
		{
			cout << "Enter the Length:" << endl;
			cin >> L;
			Conversion length1;
			length1.setLength(L);
			length1.footToCentimeter();
			cout << L << " Foot = " << length1.getLength() << " Centimeters " << endl;
			cout << "Press 1 to continue otherwise 0" << endl;
			cin >> x;
			if (x == 1) 
			{
				goto line;
			}
		}
		else
		{
			cout << "Error";
		}
		system("color b0");
		system("pause");
	}
	return 0;
}
