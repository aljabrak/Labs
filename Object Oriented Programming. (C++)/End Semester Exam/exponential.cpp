#include <iostream>
#include <iostream>
using namespace std;

class exponential
{
private:
    int a, b;
public:
    exponential() 
    { a = 0; b = 0; }
    void set_base(int aa)
    {
        a = aa;
    }
    void set_exponent(int bb)
    {
        b = bb;
    }
    int get_base(int a)
    {
        return a;
    }
    int get_exponent(int b)
    {
        return b;
    }
    int calculatePower(int get_base, int get_exponent)
    {
        if (b != 0)
            return (get_base * calculatePower(get_base, get_exponent - 1));
        else
            return 1;
    }
};

int main()
{
    exponential e1, e2;
    e1.calculatePower();
    return 0;
}
