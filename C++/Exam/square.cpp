#include<iostream> 
using namespace std;

class operatorLoading
{
    int number;
public:

    operatorLoading(int n)
    {
        number = n;
    }

    void operator / (int)
    {
        cout << "Square of " << number << " :" << number * number << endl;
        number % 2 == 0 ? cout << "Number " << number << " is Even" : cout << "Number " << number << " is Odd";
    }
};

int main()
{
    int v;
    cout << "Enter Number: ";
    cin >> v;
    operatorLoading o(v);
    o/o;
}
