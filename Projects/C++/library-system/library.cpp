include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
using namespace std;
string user1 = "Ahsan Ahmed", password1 = "ahsan";			//global variables for library member "Ahsan Ahmed"
string user2 = "Hamza Altaf", password2 = "hamza";			//global variables for library member "Hamza Altaf"
string user3 = "Saud Zahir", password3 = "saud";		//global variables for library member "Saud Zahir"
string admin = "Administrator", ad_password = "admin";		//global variables for "Administrator"
string str = "   ISSUED";
string str1 = "AVAILABLE";
string loggedin_user;
int choose;

///*/*/*/*LOGIN CLASS*/*/*/*/

class login
{
private:
	string user_name;
	string password;
public:
	login()												//constructor to login an account
	{
	top:
		system("cls");
		cout << endl << "Enter:" << endl;
		cout << setw(22) << "1. STUDENT LOGIN" << endl;
		cout << setw(28) << "2. ADMINISTRATOR LOGIN" << endl;
		cout << setw(13) << "3. EXIT" << endl;
		int choice;
		cin >> choice;
		if (choice == 1)									//choice to login as a student
		{
			cout << "Enter user name: ";
			cin.ignore();
			getline(cin, user_name);
			cout << "Enter the password: ";
			getline(cin, password);						//remove newline
			if (user_name == user1 && password == password1)
			{
				cout << endl << "Logging in .";
				Sleep(500);
				cout << ".";
				Sleep(500);
				cout << ".";
				Sleep(500);
				cout << ".";
				system("cls");
				cout << endl << endl << setw(45) << "LOGIN SUCCESSFUL" << endl;
				cout << setw(45) << "----------------" << endl;
				Sleep(500);
				choose = 1;
				loggedin_user = user1;
			}
			else if (user_name == user2 && password == password2)
			{
				cout << endl << "Logging in .";
				Sleep(500);
				cout << ".";
				Sleep(500);
				cout << ".";
				Sleep(500);
				cout << ".";
				system("cls");
				cout << endl << endl << setw(45) << "LOGIN SUCCESSFUL" << endl;
				cout << setw(45) << "----------------" << endl;
				Sleep(500);
				choose = 1;
				loggedin_user = user2;
			}
			else if (user_name == user3 && password == password3)
			{
				cout << endl << "Logging in .";
				Sleep(500);
				cout << ".";
				Sleep(500);
				cout << ".";
				Sleep(500);
				cout << ".";
				system("cls");
				cout << endl << endl << setw(45) << "LOGIN SUCCESSFUL" << endl;
				Sleep(500);
				cout << setw(45) << "----------------" << endl;
				choose = 1;
				loggedin_user = user3;
			}
			else
				throw 1;
		}
		else if (choice == 2)								//choice to login as an administrator
		{
			cout << "Enter user name: ";
			cin.ignore();
			getline(cin, user_name);
			cout << "Enter the password: ";
			getline(cin, password);
			if (user_name == admin && password == ad_password)
			{
				cout << endl << "Logging in .";
				Sleep(500);
				cout << ".";
				Sleep(500);
				cout << ".";
				Sleep(500);
				cout << ".";
				system("cls");
				cout << endl << endl << setw(45) << "LOGIN SUCCESSFUL" << endl;
				cout << setw(45) << "----------------" << endl;
				Sleep(500);
				choose = 2;
				loggedin_user = admin;
			}
			else
				throw 1;
		}
		else if (choice == 3)								//choice to exit the program
		{
			cout << setw(44) << "=====>THANK YOU<=====" << endl;
			cout << setw(38) << "---------" << endl;
			exit(1);
		}
	}
};

//*/*/*/*LIBRARY CLASS*/*/*/*/
class library
{
protected:
	string title;
	string author;										//data members to store the record of a book
	string ref_id;
	string av_status;
public:
	class file_error									//exception class to deal with errors occured in the opening of a file
	{
	};
	class student_error
	{
	};
	friend void operator >> (istream& in, library& lib);	//overloading extraction operator
	friend void operator << (ostream& out, library& lib);	//overloading insertion operator

	void search_book()									//member function to search a book by its name
	{
		cout << "Enter the category of the book:" << endl;
		cout << "------------------------------" << endl;
		cout << setw(44) << "===> Electrical" << endl;
		cout << setw(44) << "===> Humanities" << endl;
		cout << setw(48) << "===> Basic Sciences" << endl;
		cout << setw(37) << "===> DOC" << endl;
		cout << setw(56) << "===> Journals and Magazines" << endl;
		string choice;									//string variable to open file according to user input
		cin.ignore();
		getline(cin, choice);
		choice += ".txt";
		ifstream searchfile(choice.c_str(), ios::in);	//opening file to search a book
		if (!searchfile)
		{
			throw file_error();							//throw exception if file not opened
		}
		cout << "Enter the name of the book to be searched: ";
		string book_name;
		int counter = 0;
		getline(cin, book_name);
		while (!searchfile.eof())						//read data from file until end of file
		{
			getline(searchfile, title, ',');
			getline(searchfile, author, ',');
			getline(searchfile, ref_id, ',');
			getline(searchfile, av_status, '\n');
			if (book_name == title)							//display data if name of the searched book matches a book in database
			{
				cout << "Title: " << title << endl;
				cout << "Author: " << author << endl;
				cout << "Refernce ID: " << ref_id << endl;
				cout << "Availability Status: " << av_status << endl;
				counter = 1;
			}
		}
		if (counter == 0)									//true if book not found
			cout << "BOOK NOT AVAILABLE" << endl;
		searchfile.close();								//close the file
		_getch();
	}
	void return_book(string loggedin_user)				//member function to return a book to library
	{
		cout << "Enter the category of the book:" << endl;
		cout << "-------------------------------" << endl;
		cout << setw(44) << "===> Electrical" << endl;
		cout << setw(44) << "===> Humanities" << endl;
		cout << setw(48) << "===> Basic Sciences" << endl;
		cout << setw(37) << "===> DOC" << endl;
		cout << setw(56) << "===> Journals and Magazines" << endl;
		string choice;
		cin.ignore();									//remove newline
		getline(cin, choice);
		choice += ".txt";
		fstream returnfile(choice.c_str(), ios::in | ios::out);	//open file in both input and output mode
		if (!returnfile)
		{
			throw file_error();							//throw exception if file not opened
		}
		string book_name;
		string student_name;
		int counter = 0;
		cout << "Enter the name of the book to be returned: ";
		getline(cin, book_name);
		while (!returnfile.eof())						//read data until end of file
		{
			getline(returnfile, title, ',');
			getline(returnfile, author, ',');
			getline(returnfile, ref_id, ',');
			getline(returnfile, av_status, '\n');
			if (book_name == title && av_status == str)		//true if status of book is ISSUED
			{
				cout << "Enter the name of the student: ";
				getline(cin, student_name);
				if (student_name == user1 || student_name == user2 || student_name == user3)
				{
					student_name += ".txt";
					ifstream studentfile(student_name.c_str(), ios::in);	//open student file according to user input
					if (!studentfile)
					{
						throw file_error();
					}
					ofstream studenttemp("temp.txt", ios::out | ios::trunc);	//create a temporary file to store student data 
					string temp;
					getline(studentfile, temp, ',');						//read from student file until ',' is encountered
					studenttemp << temp << ",";							//write in temporary file
					while (!studentfile.eof())
					{
						getline(studentfile, temp, ',');					//read the names of issued books from student file
						if (!(temp == book_name))
							studenttemp << temp << ",";					//write book names in temporary file except the one to be returned
					}
					studentfile.close();								//close student file
					studenttemp.close();								//close temporary file
					ofstream outfile(student_name.c_str(), ios::out | ios::trunc);	//open student file in out and truncade mode
					ifstream infile("temp.txt", ios::in);				//open temporary file for reading data
					getline(infile, temp);
					temp.erase(temp.length() - 1);						//removes last character from temporary file
					outfile << temp;									//write temporary file data in student file
					infile.close();
					outfile.close();
					system("del temp.txt");								//delete temporary file
					int i = returnfile.tellp();
					returnfile.seekp(i - 11);								//put pointer at the start of availability status
					returnfile << str1 << endl;							//change the status of the book to AVAILABLE
					cout << "BOOK RETURNED" << endl;
					counter = 1;
				}
			}
		}
		if (counter == 0)
			cout << "BOOK NOT AVAILABLE OR NOT ISSUED" << endl;
		returnfile.close();
		_getch();
	}
	void display_issued_books(string loggedin_user)						//member function to display all issued books
	{
		cout << "Enter the category of the book:" << endl;
		cout << "-------------------------------" << endl;
		cout << setw(44) << "===> Electrical" << endl;
		cout << setw(44) << "===> Humanities" << endl;
		cout << setw(48) << "===> Basic Sciences" << endl;
		cout << setw(37) << "===> DOC" << endl;
		cout << setw(56) << "===> Journals and Magazines" << endl;
		string choice;
		cin.ignore();												//remove newline
		getline(cin, choice);
		choice += ".txt";
		ifstream display_issuedfile(choice.c_str(), ios::in);
		if (!display_issuedfile)
		{
			throw file_error();										//throw exception if file not opened
		}
		int counter = 0;
		while (!display_issuedfile.eof())
		{
			getline(display_issuedfile, title, ',');
			getline(display_issuedfile, author, ',');
			getline(display_issuedfile, ref_id, ',');
			getline(display_issuedfile, av_status, '\n');
			if (av_status == str)
			{
				cout << title << endl;								//display book name if status is ISSUED
				counter = 1;
			}
		}
		if (counter == 0)
			cout << "NO BOOK ISSUED YET" << endl;
		display_issuedfile.close();
		_getch();
	}
	void display_all()												//member function to display all books of a category
	{
		cout << "Enter the category of the book:" << endl;
		cout << "-------------------------------" << endl;
		cout << setw(44) << "===> Electrical" << endl;
		cout << setw(44) << "===> Humanities" << endl;
		cout << setw(48) << "===> Basic Sciences" << endl;
		cout << setw(37) << "===> DOC" << endl;
		cout << setw(56) << "===> Journals and Magazines" << endl;
		string choice;
		cin.ignore();
		getline(cin, choice);
		choice += ".txt";
		ifstream displayfile(choice.c_str(), ios::in);
		if (!displayfile)
		{
			throw file_error();
		}
		while (getline(displayfile, title, ',')&&
		getline(displayfile, author, ',')&&
		getline(displayfile, ref_id, ',')&&
		getline(displayfile, av_status, '\n'))							//display all books until end of file
		{
			
			cout << "Title: " << title << endl;
			cout << "Author: " << author << endl;
			cout << "Reference ID: " << ref_id << endl;
			cout << "Availability status: " << av_status << endl << endl;
		}
		displayfile.close();
		_getch();
	}
};

void operator >> (istream& in, library& lib)				//definition of extraction operator overloading
{
	cout << "Enter the book data: " << endl;
	cin.ignore();
	cout << "Title: ";
	getline(cin, lib.title);
	cout << "Author: ";
	getline(cin, lib.author);
	cout << "Reference ID: ";
	getline(cin, lib.ref_id);
	cout << "Status: ";
	getline(cin, lib.av_status);
}

void operator << (ostream& out, library& lib)				//definition of insertion operator overloading
{
	cout << "The data of the book is: " << endl;
	cout << "Title: " << lib.title << endl;
	cout << "Author: " << lib.author << endl;
	cout << "Reference ID: " << lib.ref_id << endl;
	cout << "Availability Status: " << lib.av_status << endl;
}

///*/*/*/*STUDENT CLASS*/*/*/*/

class student : public library
{
protected:
	string s_name;
	string reg_no;							//data memebers to hold the record of a student
	string dept;
	string issued_books;
public:
	friend void operator >> (istream& in, student& s);		//prototype extraction operator overloading for student class
	friend void operator << (ostream& out, student& s);		//prototype insertion operator overloading for student class
	void display_issued_books(string loggedin_user)			//overridden function to display issued books of a particular student
	{
		loggedin_user += ".txt";
		ifstream display_issuedfile(loggedin_user.c_str(), ios::in);
		if (!display_issuedfile)
		{
			throw file_error();
		}
		string book_name;
		getline(display_issuedfile, book_name, ',');
		while (!display_issuedfile.eof())					//display all issued books until end of file
		{
			getline(display_issuedfile, book_name, ',');
			cout << book_name << endl;
		}
		display_issuedfile.close();
		_getch();
	}
	void return_book(string loggedin_user)					//overridden function to return issued books from a particular user 
	{
		cout << "Enter the category of the book:" << endl;
		cout << "-------------------------------" << endl;
		cout << setw(44) << "===> Electrical" << endl;
		cout << setw(44) << "===> Humanities" << endl;
		cout << setw(48) << "===> Basic Sciences" << endl;
		cout << setw(37) << "===> DOC" << endl;
		cout << setw(56) << "===> Journals and Magazines" << endl;
		string choice;
		cin.ignore();
		getline(cin, choice);
		choice += ".txt";
		fstream returnfile(choice.c_str(), ios::in | ios::out);
		if (!returnfile)
		{
			throw file_error();										//throw exception
		}
		string book_name;
		int counter = 0;
		cout << "Enter the name of the book to be returned: ";
		getline(cin, book_name);
		while (!returnfile.eof())
		{
			getline(returnfile, title, ',');
			getline(returnfile, author, ',');
			getline(returnfile, ref_id, ',');
			getline(returnfile, av_status, '\n');
			if (book_name == title && av_status == str)					//true if availablility status is ISSUED
			{
				loggedin_user += ".txt";
				ifstream studentfile(loggedin_user.c_str(), ios::in);	//open student file for reading data
				if (!studentfile)
				{
					throw file_error();
				}
				ofstream studenttemp("temp.txt", ios::out | ios::trunc);		//create temporary file to hold student data
				string temp;
				getline(studentfile, temp, ',');
				studenttemp << temp << ",";
				while (!studentfile.eof())
				{
					getline(studentfile, temp, ',');
					if (!(temp == book_name))
					{
						studenttemp << temp << ",";				//write issued books to temporary file except the one to be returned
					}
				}
				studentfile.close();
				studenttemp.close();								//close files	
				ofstream outfile(loggedin_user.c_str(), ios::out | ios::trunc);
				ifstream infile("temp.txt", ios::in);
				getline(infile, temp);								//read from temporary file 
				temp.erase(temp.length() - 1);						//remove last character in temporary file
				outfile << temp;									//write temporary file data to student file
				infile.close();
				outfile.close();
				system("del temp.txt");								//delete temporary file
				int i = returnfile.tellp();
				returnfile.seekp(i - 11);								//put pointer at the start of availability status
				returnfile << str1 << endl;							//change status to AVAILABLE
				cout << "BOOK RETURNED" << endl;
				counter = 1;
			}
		}
		if (counter == 0)
			cout << "BOOK NOT AVAILABLE OR NOT ISSUED" << endl;
		returnfile.close();
		_getch();
	}
};

void operator >> (istream& in, student& s)						//extraction operator overloading definition
{
	cout << "Enter the student data: " << endl;
	cout << "Name: ";
	cin.ignore(1);
	getline(cin, s.s_name);
	cout << "Reg No: ";
	getline(cin, s.reg_no);
	cout << "Department: ";
	getline(cin, s.dept);
	cout << "Books issued: ";
	getline(cin, s.issued_books);
}

void operator << (ostream& out, student& s)						//insertion operator overloading definition
{
	cout << "The data of the student is: " << endl;
	cout << "Name: " << s.s_name << endl;
	cout << "Reg No " << s.reg_no << endl;
	cout << "Department: " << s.dept << endl;
	cout << "Books issued: " << s.issued_books << endl;
}

///*/*/*/*/*BOOK CLASS*/*/*/*/*/

class book : public library
{
public:
	void add_book()												//member function to add a new book to database
	{
		cout << "Enter the category of the book:" << endl;
		cout << "-------------------------------" << endl;
		cout << setw(44) << "===> Electrical" << endl;
		cout << setw(44) << "===> Humanities" << endl;
		cout << setw(48) << "===> Basic Sciences" << endl;
		cout << setw(37) << "===> DOC" << endl;
		cout << setw(56) << "===> Journals and Magazines" << endl;
		string choice;
		cin.ignore();
		getline(cin, choice);
		if (choice == "Electrical" || choice == "Humanities" || choice == "Basic Sciences" || choice == "DOC" || choice == "Journals and Magazines")
		{
			choice += ".txt";
			ofstream addfile(choice.c_str(), ios::app);
			if (!addfile)
			{
				throw file_error();
			}
			cout << "Enter the data of the book:" << endl;
			cout << "Title: ";
			getline(cin, title);
			cout << "Author: ";
			getline(cin, author);
			cout << "Reference ID: ";
			getline(cin, ref_id);
			cout << "Avalability Status: ";
			getline(cin, av_status);
			addfile << title << "," << author << "," << ref_id << "," << av_status << endl;
			addfile.close();
			cout << "BOOK HAS BEEN ADDED TO " << choice.c_str() << " DATABASE" << endl;
		}
		else
			throw file_error();
		_getch();
	}
	void issue_book()										//member function to issue a book to a library member
	{
		cout << "Enter the category of the book:" << endl;
		cout << "-------------------------------" << endl;
		cout << setw(44) << "===> Electrical" << endl;
		cout << setw(44) << "===> Humanities" << endl;
		cout << setw(48) << "===> Basic Sciences" << endl;
		cout << setw(37) << "===> DOC" << endl;
		cout << setw(55) << "===> Jounals and Magazines" << endl;
		string choice;
		cin.ignore();
		getline(cin, choice);
		choice += ".txt";
		fstream issuefile(choice.c_str(), ios::in | ios::out);
		if (!issuefile)
		{
			throw file_error();
		}
		string book_name;
		int counter = 0;
		cout << "Enter the name of the book to be issued: ";
		getline(cin, book_name, '\n');
		while (!issuefile.eof())
		{
			getline(issuefile, title, ',');
			getline(issuefile, author, ',');
			getline(issuefile, ref_id, ',');
			getline(issuefile, av_status, '\n');
			if (book_name == title && av_status == str1)				//true if the required book id AVAILABLE
			{
				cout << "BOOK AVAILABLE" << endl;
				string student_name;
				cout << "Enter the name of the student: ";
				getline(cin, student_name);
				if (student_name == user1 || student_name == user2 || student_name == user3)
				{
					student_name += ".txt";
					ofstream studentfile(student_name.c_str(), ios::app);
					if (!studentfile)
					{
						throw file_error();
					}
					studentfile << book_name << ",";
					int i = issuefile.tellp();
					issuefile.seekp(i - 11);
					issuefile << str << endl;						//change availability status to ISSUED
					cout << "BOOK ISSUED" << endl;
					counter = 1;
					issuefile.close();
					studentfile.close();
				}
				else
					throw student_error();
			}
			else if (book_name == title && av_status == str)			//true if status is ISSUED
			{
				cout << "BOOK ALREADY ISSUED" << endl;
				counter = 1;
			}
		}
		if (counter == 0)
			cout << "BOOK NOT AVAILABLE" << endl;
		_getch();
	}
};

///*/*/*/*MAIN*/*/*/*/		

int main()
{
start:
	try
	{
		login l;								//constructor called as an object is created
	}
	catch (int)
	{
		cout << endl << setw(55) << "INCORRECT USER NAME OR PASSWORD" << endl;
		cout << setw(42) << "TRY AGAIN" << endl << endl;
		_getch();
		system("cls");
		goto start;
	}
	if (choose == 1)
	{
	s_main:
		system("cls");
		cout << endl << setw(67) << loggedin_user << " (logged in)" << endl;
		cout << setw(78) << "----------------------" << endl << endl;
		cout << setw(56) << "=====>|WELCOME TO STUDENT MENU|<=====" << endl;
		cout << setw(50) << "-------------------------" << endl << endl;
		cout << "Enter your choice:" << endl;
		cout << "------------------" << endl;
		cout << setw(38) << "1. DISPLAY ALL BOOKS" << endl;
		cout << setw(42) << "2. SEARCH A BOOK BY NAME" << endl;
		cout << setw(34) << "3. RETURN A BOOK" << endl;
		cout << setw(41) << "4. DISPLAY ISSUED BOOKS" << endl;
		cout << setw(27) << "5. LOGOUT" << endl;
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			try
			{
				system("cls");
				cout << endl << setw(67) << loggedin_user << " (logged in)" << endl;
				cout << setw(78) << "----------------------" << endl;
				cout << endl << endl << setw(51) << "=====>|DISPLAY BOOKS MENU|<=====" << endl;
				cout << setw(45) << "--------------------" << endl << endl;
				student s;
				s.display_all();					//display_all function called from library class
			}
			catch (library::file_error)				//exception handler
			{
				cout << "File could not be opened." << endl;
				_getch();
				goto s_main;
			}
			goto s_main;
		}
		else if (choice == 2)
		{
			try
			{
				system("cls");
				cout << endl << setw(67) << loggedin_user << " (logged in)" << endl;
				cout << setw(78) << "----------------------" << endl;
				cout << endl << endl << setw(51) << "=====>|SEARCH BOOK MENU|<=====" << endl;
				cout << setw(45) << "------------------" << endl << endl;
				student s;
				s.search_book();					//search_book function called from library class
			}
			catch (library::file_error)				//exception handler
			{
				cout << "File could not be opened." << endl;
				_getch();
				goto s_main;
			}
			goto s_main;
		}
		else if (choice == 3)
		{
			try
			{
				system("cls");
				cout << endl << setw(67) << loggedin_user << " (logged in)" << endl;
				cout << setw(78) << "----------------------" << endl;
				cout << endl << endl << setw(51) << "=====>|RETURN BOOK MENU|<=====" << endl;
				cout << setw(45) << "------------------" << endl << endl;
				student s;
				s.return_book(loggedin_user);		//return_book function called from student class
			}
			catch (library::file_error)
			{
				cout << "File could not be opened." << endl;
				_getch();
				goto s_main;
			}
			catch (library::student_error)
			{
				cout << "INVALID USER NAME" << endl;
				goto s_main;
			}
			goto s_main;
		}
		else if (choice == 4)
		{
			try
			{
				system("cls");
				cout << endl << setw(67) << loggedin_user << " (logged in)" << endl;
				cout << setw(78) << "----------------------" << endl;
				cout << endl << endl << setw(55) << "=====>|DISPLAY ISSUED BOOKS MENU|<=====" << endl;
				cout << setw(49) << "---------------------------" << endl << endl;
				student s;
				s.display_issued_books(loggedin_user);		//display_issued_books function called from student class
			}
			catch (library::file_error)
			{
				cout << "File could not be opened." << endl;
				_getch();
				goto s_main;
			}
			catch (library::student_error)
			{
				cout << "INVALID USER NAME" << endl;
				_getch();
				goto s_main;
			}
			goto s_main;
		}
		else
		{
			cout << endl << "Logging out .";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << ".";
			Sleep(500);
			system("cls");
			goto start;
		}
	}
	else if (choose == 2)
	{
	b_main:
		system("cls");
		cout << endl << setw(67) << loggedin_user << " (logged in)" << endl;
		cout << setw(78) << "------------------------" << endl;
		cout << endl << setw(58) << "=====>|WELCOME TO ADMINISTRATOR MENU|<=====" << endl;
		cout << setw(52) << "-------------------------------" << endl << endl;
		cout << "Enter your choice:" << endl;
		cout << "------------------" << endl;
		cout << setw(31) << "1. ADD A BOOK" << endl;
		cout << setw(38) << "2. DISPLAY ALL BOOKS" << endl;
		cout << setw(42) << "3. SEARCH A BOOK BY NAME" << endl;
		cout << setw(33) << "4. ISSUE A BOOK" << endl;
		cout << setw(34) << "5. RETURN A BOOK" << endl;
		cout << setw(41) << "6. DISPLAY ISSUED BOOKS" << endl;
		cout << setw(27) << "7. LOGOUT" << endl;
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			try
			{
				system("cls");
				cout << endl << setw(67) << loggedin_user << " (logged in)" << endl;
				cout << setw(78) << "-----------------------" << endl;
				cout << endl << setw(48) << "=====>|ADD BOOK MENU|<=====" << endl;
				cout << setw(42) << "---------------" << endl << endl;
				book b;
				b.add_book();							//add_book function called from book class
			}
			catch (library::file_error)					//exception handler
			{
				cout << "File could not be opened." << endl;
				_getch();
				goto b_main;
			}
			goto b_main;
		}
		else if (choice == 2)
		{
			try
			{
				system("cls");
				cout << endl << setw(67) << loggedin_user << " (logged in)" << endl;
				cout << setw(78) << "-----------------------" << endl;
				cout << endl << setw(53) << "=====>|DISPLAY BOOKS MENU|<=====" << endl;
				cout << setw(47) << "--------------------" << endl << endl;
				book b;
				b.display_all();						//display_all function called from library class
			}
			catch (library::file_error)
			{
				cout << "File could not be opened." << endl;
				_getch();
				goto b_main;
			}
			goto b_main;
		}
		else if (choice == 3)
		{
			try
			{
				system("cls");
				cout << endl << setw(67) << loggedin_user << " (logged in)" << endl;
				cout << setw(78) << "-----------------------" << endl;
				cout << endl << setw(50) << "=====>|SEARCH BOOK MENU|<=====" << endl;
				cout << setw(44) << "------------------" << endl << endl;
				book b;
				b.search_book();						//search_book function called from library class
			}
			catch (library::file_error)
			{
				cout << "File could not be opened." << endl;
				_getch();
				goto b_main;
			}
			goto b_main;
		}
		else if (choice == 4)
		{
			try
			{
				system("cls");
				cout << endl << setw(67) << loggedin_user << " (logged in)" << endl;
				cout << setw(78) << "-----------------------" << endl;
				cout << endl << setw(50) << "=====>|ISSUE BOOK MENU|<=====" << endl;
				cout << setw(44) << "-----------------" << endl << endl;
				book b;
				b.issue_book();							//issue_book function called from book class
			}
			catch (library::file_error)
			{
				cout << "File could not be opened." << endl;
				_getch();
				goto b_main;
			}
			catch (library::student_error)
			{
				cout << "INVALID USER NAME" << endl;
				_getch();
				goto b_main;
			}
			goto b_main;
		}
		else if (choice == 5)
		{
			try
			{
				system("cls");
				cout << endl << setw(67) << loggedin_user << " (logged in)" << endl;
				cout << setw(78) << "-----------------------" << endl;
				cout << endl << setw(50) << "=====>|RETURN BOOK MENU|<=====" << endl;
				cout << setw(44) << "------------------" << endl << endl;
				book b;
				b.return_book(loggedin_user);				//return_book function called from library class
			}
			catch (library::file_error)
			{
				cout << "File could not be opened." << endl;
				_getch();
				goto b_main;
			}
			catch (library::student_error)
			{
				cout << "INVALID USER NAME" << endl;
				_getch();
				goto b_main;
			}
			goto b_main;
		}
		else if (choice == 6)
		{
			try
			{
				system("cls");
				cout << endl << setw(67) << loggedin_user << " (logged in)" << endl;
				cout << setw(78) << "-----------------------" << endl;
				cout << endl << setw(52) << "=====>|DISPLAY ISSUED BOOKS MENU|<=====" << endl;
				cout << setw(46) << "---------------------------" << endl << endl;
				book b;
				b.display_issued_books(loggedin_user);				//display_issued_books function called from library class
			}
			catch (library::file_error)
			{
				cout << "File could not be opened." << endl;
				_getch();
				goto b_main;
			}
			goto b_main;
		}
		else
		{
			cout << endl << "Logging out .";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << ".";
			Sleep(500);
			system("cls");
			goto start;
		}
	}
	return 0;
}
