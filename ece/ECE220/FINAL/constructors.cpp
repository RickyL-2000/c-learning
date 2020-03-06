#include <iostream>
using namespace std;

class Base
{
public:
    Base() { cout << "in Base::Base()" << endl; }
};

class ClassA
{
    int i;

public:
    ClassA() { cout << "in ClassA::ClassA()" << endl; }
    ClassA(int i_) : i(i_) { cout << "in ClassA::ClassA(int)" << endl; }
};

class ClassB
{
public:
    ClassB() { cout << "in ClassB : ClassB()" << endl; }
};

class MyClass : public Base
{
    ClassA a;
    ClassB *b;

public:
    MyClass(int val = 0) : b(NULL) { a = ClassA(val); } /*constructor with default parameter*/
};

int main()
{
    MyClass a; //what does this line do?
    /*
    * 
    * in Base::Base()
    * in ClassA::ClassA()
    * in ClassA::ClassA(int)
    * 因为要先根据derivation list初始化base，然后b因为只有一个指针就不需要初始化
    * */
    return 0;
}