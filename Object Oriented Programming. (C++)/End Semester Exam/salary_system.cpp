#include <iostream>
#include <fstream>
using namespace std;


ofstream Salaried_Employee;
ofstream Commisioned_Employee;
ofstream base_salary_plus_commissioned_Employee;


class Employee
{
    protected:
    string fName;
    string lName;
    string employeeNumber;
    // int weeklySalary;
    double totalEarning;

    public:

    Employee (string n1, string n2, string eNumber)
    {
        fName = n1;
        lName = n2;
        employeeNumber = eNumber;
        // weeklySalary = salary;
    }

    string get_fName()
    {
        return fName;
    }
    void set_fName(string name)
    {
        fName = name;
    }

    string get_lName()
    {
        return lName;
    }
    void set_lName(string name)
    {
        lName = name;
    }

    string get_employeeNumber()
    {
        return employeeNumber;
    }


    double get_totalEarning()
    {
        return totalEarning;
    }

    void set_totalEarning (double x)
    {
        totalEarning = x;
    }


    virtual void calculate_earnings()
    {
        // cout << "Parents calculate_earnings( ) called\n";
    }

    virtual void write_to_file()
    {
        // cout << "Parent write_to_file( ) called\n";
    }
};

class Salaried: public Employee
{
    int weeklySalary;
    public:

    Salaried (string first, string second, string id, int sal): Employee (first, second, id)
    {
        weeklySalary = sal;
    }

    int get_weeklySalary()
    {
        return weeklySalary;
    }
    void set_weeklySalary(int number)
    {
        weeklySalary = number;
    }

    void calculare_earnings()
    {
        set_totalEarning(4*(get_weeklySalary()));
    }

    void write_to_file()
    {
        Salaried_Employee.open("Salaried.txt");
        Salaried_Employee << get_fName() << ", " << get_lName() << ", " << get_employeeNumber() << ", " << get_weeklySalary() << ", " << get_totalEarning() << endl;
    }
};

class Commisioned: public Employee
{
    int sales;
    double commisionRate;
    public:

    Commisioned (string first, string second, string id, int SAL, double cRate): Employee (first, second, id)
    {
        sales = SAL;
        commisionRate = cRate;
    }

    void calculare_earnings()
    {
        set_totalEarning(4*sales*commisionRate);
    }

    void write_to_file()
    {
        Commisioned_Employee.open("Commisioned.txt");
        Commisioned_Employee << get_fName() << ", " << get_lName() << ", " << get_employeeNumber() << ", " << sales << ", " << commisionRate << ", " << get_totalEarning() << endl;
    }
};

class base_salary_plus_commissioned: public Employee
{
    int weeklySalary;
    int sales;
    double commisionRate;
    public:

    base_salary_plus_commissioned (string first, string second, string id, int wSAL ,int SAL, double cRate): Employee (first, second, id)
    {
        weeklySalary = wSAL;
        sales = SAL;
        commisionRate = cRate;
    }

    void calculare_earnings()
    {
        set_totalEarning(4*(weeklySalary + (sales*commisionRate)));
    }

    void write_to_file()
    {
        base_salary_plus_commissioned_Employee.open("base_salary_plus_commissioned.txt");
        base_salary_plus_commissioned_Employee << get_fName() << ", " << get_lName() << ", " << get_employeeNumber() << ", " << weeklySalary << ", " << sales << ", " << commisionRate << ", " << get_totalEarning() << endl;
    }
};


int main ()
{
    Employee* e1;
    Salaried s1("Saud", "Zahir", "12345", 1000);
    e1 = &s1;
    e1 -> calculate_earnings();
    e1 -> write_to_file();

    Commisioned c1("Talal", "Qamar", "1357", 1000, 0.5);
    c1.calculare_earnings();
    c1.write_to_file();

    base_salary_plus_commissioned b1("Asad", "Azhar", "0301", 1000, 2000, 0.5);
    b1.calculare_earnings();
    b1.write_to_file();
}
