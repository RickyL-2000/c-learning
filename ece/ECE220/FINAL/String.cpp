#include <iostream>
#include <string.h>
using namespace std;

class String
{
private:
    char *s;
    int size;

public:
    String(const char *);   //constructor
    String(const String &); //copy constructor
    ~String() { delete s; } //deconstructor
    void disp() { cout << s << endl; }
    void set(const char *);
};
String::String(const char *str)
{
    size = strlen(str);
    s = new char[size + 1];
    strcpy(s, str);
}
String::String(const String &old_str)
{
    size = old_str.size;
    s = new char[size + 1];
    strcpy(s, old_str.s);
}

void String::set(const char *str)
{
    delete[] s;
    size = strlen(str);
    s = new char[size + 1];
    strcpy(s, str);
}
int main()
{
    String str1("ECE220"); //calling first constructor
    String str2 = str1;    //calling the copy constructor
    str1.disp();
    str2.disp();
    str2.set("CHEM102");
    str1.disp();
    return 0;
}