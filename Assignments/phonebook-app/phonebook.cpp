//Muhammad Saud Zahir.

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class contact {
private:
	string name, gender, fathername, relation, email, address;
	string number;
	int entrynum;
public:
	void setName();
	void setFatherName();
	void setRelation();
	void setEmail();
	void setAddress();
	void setGender();
	void setNumber();
	void DisplayContact();
	void AddContact();
	void deleteContact();
	void updateContact();
	string getName(); //function to facilitate in searching

};
void contact::setName()
{


	cout << "Enter Name: ";
	getline(cin, name);
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void contact::setFatherName()
{
	cout << "Enter Father Name: ";
	getline(cin, fathername);
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void contact::setRelation()
{


	cout << "Enter Relation : ";
	getline(cin, relation);
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void contact::setAddress()
{
	cout << "Enter Address : ";
	getline(cin, address);
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void contact::setGender()
{
	cout << "Enter Gender : ";
	getline(cin, gender);
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void contact::setEmail()
{
	cout << "Enter Email Address : ";
	getline(cin, email);
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void contact::setNumber()
{
	cout << "Enter Phone Number : ";
	cin >> number;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}
string contact::getName()
{
	return name;
}

void contact::AddContact()
{
	setName();
	setFatherName();
	setGender();
	setRelation();
	setAddress();
	setEmail();
	setNumber();
}

void contact::updateContact()
{
	cout << "What information would you like to update : " << endl;
	cout << "1.Name\n2.Father's Name\n3.Gender\n4.Relation\n5.Email Address\n6.Home Address\n7.Number\n8.Update whole contact" << endl;
	int update;
	cin >> update;
	cin.ignore();
	switch (update)
	{
	case 1: contact::setName(); break;
	case 2: contact::setFatherName(); break;
	case 3: contact::setGender(); break;
	case 4: contact::setRelation(); break;
	case 5: contact::setEmail(); break;
	case 6: contact::setAddress(); break;
	case 7: contact::setNumber(); break;
	case 8: contact::AddContact(); break;
	}
}
void contact::deleteContact()
{
	name = "NULL";
	fathername = "NULL";
	email = "NULL";
	relation = "NULL";
	gender = "NULL";
	address = "NULL";
	number = "NULL";
}
void contact::DisplayContact()
{
	cout << "NAME: " << name << endl;
	cout << "FATHER'S NAME: " << fathername << endl;
	cout << "GENDER: " << gender << endl;
	cout << "RELATION: " << relation << endl;
	cout << "EMAIL ADDRESS: " << email << endl;
	cout << "HOME ADDRESS: " << address << endl;
	cout << "PHONE NUMBER: " << number << endl;
}

int  main()
{
	contact obj1[1000];

	int choice = 0;
	static int k = 0;
	while (choice != 6)
	{
		cout << "        CHOOSE A OPTION FROM THE FOLLOWING MENU          " << endl << endl << endl;
		cout << "1.ADD CONTACT\n2.LIST\n3.UPDATE CONTACT\n4.SEARCH CONTACT\n5.DELETE CONTACT\n6.EXIT PHONEBOOK " << endl;
		cin >> choice;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch (choice)
		{
		case 1: obj1[k].AddContact(); k++; break;
		case 2: {
			if (k == 0)
			{
				cout << "NO CONTACTS EXIST. PLEASE ENTER CONTACTS FIRST \n";
			}
			else {
				for (int i = 0; i < k; i++)
				{
					obj1[k].DisplayContact();
					cout << endl;
					cout << endl;
				}
			}
			break;
		}
		case 3: {
			cout << "Enter name of contact you want to update : ";
			string stemp;
			getline(cin, stemp);
			getchar();
			for (int i = 0; i < k; i++)
			{
				if (obj1[i].getName() == stemp)
				{
					obj1[i].DisplayContact();
					obj1[i].updateContact();
				}
				else
				{
					cout << "CONTACT DOES NOT EXIST \n";
				}
			}
			cout << "CONTACT WAS UPDATED \n";
			break;
		}
		case 4: {
			cout << "Enter name of contact you want to search : ";
			string stemp;
			getline(cin, stemp);
			getchar();
			for (int i = 0; i < k; i++)
			{
				if (obj1[i].getName() == stemp)
				{
					obj1[i].DisplayContact();
				}
				else
				{
					cout << "CONTACT DOES NOT EXIST \n";
				}
			}
			break;
		}
		case 5: {
			cout << "Enter name of contact you want to delete : ";
			string stemp;
			getline(cin, stemp);
			getchar();
			for (int i = 0; i < k; i++)
			{
				if (obj1[i].getName() == stemp)
				{
					obj1[i].deleteContact();
					cout << "CONTACT WAS DELETED \n";
				}
				else
				{
					cout << "CONTACT DOES NOT EXIST \n";
				}
			}
			break;
		}
		case 6: cout << "EXITING PHONE BOOK. SEE YOU LATER\n"; choice = 6; break;
		}
	}
	return 0;
}

