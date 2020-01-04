#include <iostream>
using namespace std;

class Base
{
public:
    int f(int i)
    {
        cout << "Base::f(int) : ";
        return i + 3;
    }
};
class Derived : public Base
{
public:
    int f(int i)
    { //overrides Base::f(int)
        cout << "Derived::f(int) : " << endl;
        return i + 5;
    }
    double f(double i, double j)
    { //overloads with Derived::f(int)
        cout << "f(double, double) : " << endl;
        return i + j;
    }
};

int main()
{
    //test code
    Derived *dp = new Derived;
    Base *bp = dp;
    cout << dp->f(3) << std::endl; //what is printed?
    cout << dp->f(2, 3.3) << std::endl;
    cout << bp->f(3) << std::endl;
    //cout << dp->f(2, 3.3) << std::endl; //what is printed?
    //cout << bp->f(2, 3.3) << std::endl;
    return 0;
}