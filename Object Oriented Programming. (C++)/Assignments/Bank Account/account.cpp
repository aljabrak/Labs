
#include <iostream> 
#include<string>
using namespace std;
 
class Account
{
private:
    string username;
    long long int CNIC_No;
    string Account_type;
    string Profit_type;
    float balance;
 
public:
    ///////////////////////////////////////////// 
    Account(float b)
    {
        username = "Name";
        CNIC_No = 0000000000000;
        Account_type = "Current";
        balance = b;
 
    }
    ///////////////////////////////////////////// 
    Account()
    {
        username = "Name";
        CNIC_No = 0000000000000;
        Account_type = "Saving";
        Profit_type = "Yearly";
        balance = 0.0;
 
    }
 
    ///////////////////////////////////////////// 
    void set_name(string uname);
    void set_cnic(long long int cnum);
    void set_accounttype(string acctype);
    void set_profittype(string proftype);
    void set_balance(float bal);
    ///////////////////////////////////////////// 
    string get_name();
    long long int get_cinc();
    string get_accounttype();
    string get_profittype();
    float get_balance();
    ////////////////////////////////////////////// 
    void  display_details();
 
};
 
 
void Account :: set_name(string uname)
{
    username = uname;
}
string Account::get_name()
{
    return username;
}
void Account ::set_cnic(long long int cnum)
{
    CNIC_No = cnum;
}
long long int Account::get_cinc()
{
    return CNIC_No;
}
void Account::set_accounttype(string acctype)
{
    Account_type = acctype;
}
string Account::get_accounttype()
{
    return Account_type;
}
void Account::set_profittype(string proftype)
{
    Profit_type = proftype;
}
string Account::get_profittype()
{
    return Profit_type;
}
void Account::set_balance(float bal)
{
    balance = bal;
}
float Account::get_balance()
{
    return balance;
}
 
void  Account::display_details()
 
{
    cout << "\nNAME : " << get_name() << endl;
    cout << "CNIC NUMBER: " << get_cinc() << endl;
    cout << "ACCOUNT TYPE : " << get_accounttype() << endl;
    cout << "PROFIT TYPE : " << get_profittype() << endl;
 
 
}
 
 
 
 
 
 
int main()
{
    Account A1;
    Account A2(0.0);
    string uname;
    string acctype;
    long long int cnum;
    string proftype;
    float bal;
 
    int ch, ch1, ch2;
 
    cout << "Welcome to NUST Bank." << endl;
 
    cout << "Enter Your name :";
    getline (cin, uname);
    A1.set_name(uname);
 
    cout << "Enter Your CNIC number :";
    cin >> cnum;
    A1.set_cnic(cnum);
    cout << "Account Type : " << endl;
    cout << "Enter 1 for Current and 2 for Saving : ";
    cin >> ch;
    if (ch == 1)
    {
        acctype = "Current";
        A1.set_accounttype(acctype);
    }
    if (ch == 2)
    {
        acctype = "Saving";
        A1.set_accounttype(acctype);
        cout << "Profit Type : " << endl;
        cout << "Enter 1 for Monthly & 2 for Yearly" << endl;
        cin >> ch1;
        if (ch1 == 1)
        {
            proftype = "Monthly";
            A1.set_profittype(proftype);
        }
 
        if (ch1 == 2)
        {
            proftype = "Yearly";
            A1.set_profittype(proftype);
        }
    }
 
    A1.display_details();
 
    cout << "\nEnter Balance amount Or Exit the program." << endl;
    cout << "Press 1 to add amount and Press 2 to EXIT :";
    cin >> ch2;
    if (ch2 == 1) {
 
        cout << "\nEnter Balance amount :";
        cin >> bal;
        A1.set_balance(bal);
 
        A1.display_details();
        cout << "Your Balance is : " << A1.get_balance();
    }
    else if (ch2 == 2)
    {
        cout << "THANK YOU FOR CREATING YOUR ACCOUNT IN OUR BANK.";
    }
    return 0;
}
