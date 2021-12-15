//Muhammad Saud Zahir.
//How to cook Biryani:

#include <iostream>    
#include<string>
using namespace std;

class cooking 
{         

	float *haandiPtr;
	float b,m; //"b" is the amount of beef and "m" is the amount of masalhay.  

public:
	void chawal(float *cgm) 
	{        

		cout << "Adding chawal: " << *cgm << endl;
		haandiPtr = cgm;
		beef(cgm);  
		system("Color B4");
	}

	void beef(float *haandiPtr) 
	{          
		b = 2 * (*haandiPtr);    
		cout << "Amount of beef is: " << b << " grams" << endl;
		cout << "Adding beef: " << endl;
		*haandiPtr += b;       
		misalhay(haandiPtr);
		system("Color B4");

	}
	void misalhay(float *x) 
	{         

		m = *x / 100;     
		cout << "Amount of misalhay is :" << m << " chutkis" << endl;  
		cout << "Adding misalhay" << endl;
		*haandiPtr += m;   
		pakao(haandiPtr);  
		system("Color B4");
	}
	void pakao(float *haandiPtr) 
	{   

		float Time = 10 + *haandiPtr / 100;  
		cout << "Time for Cooking: " << Time << " minutes" << endl;
		*haandiPtr += Time;    
		cout << "The amount of Biryani is: " << *haandiPtr << endl;
		system("Color B4");
	}

};


int main()   
{
	float chawal, *haandiPtr;           
	cout << "Enter the Amount of Chawal (Rice) between 200 and 1000 grams: " << endl;   
	cin >> chawal;                     
	haandiPtr = &chawal;                
	cooking obj;                        
	obj.chawal(haandiPtr);              
	system("pause");
	return 0;
}
