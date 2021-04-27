//Muhammad Saud Zahir.

#include <string>
using namespace std;
class Gradebook
{
private:
	string coursename;
public:
	//These are the member functions . They are implemented in a separate file
	Gradebook(string);
	void setCourseName(string);
	string getCourseName();
	void displayMessage();
};


Gradebook.cpp File:
#include <iostream>
#include "Gradebook.h"
using namespace std;
int main()
{
	//We created two objects in which we used constructors to assignm values
	Gradebook gradeBook1("CS101 Introduction To C++ Programming");
	Gradebook gradeBook2("CS101 Data Structures in C++");
	//Printing the values of course name
	cout << "Gradebook1 created for course: " << gradeBook1.getCourseName() << endl;
	cout << "Gradebook2 created for course: " << gradeBook2.getCourseName() << endl;
	system("pause");
}


TestGradebook.cpp File:
#include <iostream>
#include <string.h>
#include "Gradebook.h"
using namespace std;
Gradebook::Gradebook(string name) 
{
	setCourseName(name);
}
void Gradebook::setCourseName(string name)
{
	//Here first it will check the number of characters of given string using size() function
	if (name.size() > 25) {
		//If the size of string is greater than 25 then it will trim the end part using substr and also will display message to user that it trimmed it
		coursename = name.substr(0, 24);
		cout << "The assignment has been successful. But some part is trimmed due to large characters" << endl;
	}
	else {
		coursename = name;
	}
	system("color b0");
}
string Gradebook::getCourseName() {
	return coursename;
}
void Gradebook::displayMessage()
{
	cout << "Welcome to the gradebook for \n" << getCourseName() << "!" << endl;
	system("color b0");
}
