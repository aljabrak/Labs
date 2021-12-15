#include<iostream>
#include<string>
using namespace std;

class gym
{
private:
	string name;
	int age;
	string type;
public:
	gym(int age, string name)
	{
		name = "username";
		age = 00;
	}
	gym(int age, string name, string type)
	{
		age = 00;
		name = "username";
		type = "gold";
	}
	void set_age()
	{
		cout << "Enter age: ";
		cin >> age;
	}
	void set_name()
	{
		cout << "Enter name: ";
		cin >> name;
	}
	void display1()
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Account type: Regular" << endl;
	}
	void display2()
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Account type: Gold" << endl;
	}
};
int main()
{
	int choice;
	cout << "************ Welcome to NUST Central Gym ************" << endl;
	cout << "Enter the type of Membership you want..." << endl; //Choose the account type. 
	cout << "1. GOLD    2.REGULAR" << endl;
	cin >> choice;
	if (choice == 1) //For Gold membership.
	{
		gym User1(0, "username", "GOLD");
		User1.set_age();
		User1.set_name();
		cout << " " << endl;
		cout << " " << endl;
		User1.display2();
	}
	else if (choice == 2) //For Regular membership.
	{
		gym User2(0, "username");
		User2.set_age();
		User2.set_name();
		cout << " " << endl;
		cout << " " << endl;
		User2.display1();
	}
	else
	{
		cout << "INVALID SELECTION" << endl;
	}
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << "************ HOPE TO SEE YOU SOON ************ " << endl;
	system("color b0");
	system("pause");
	getchar();
	return 0;
}
