#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(int);

int main()
{
    int x = 10;
    cout << isPalindrome(x) << endl;
    return 0;
}

bool isPalindrome(int x) {
    string num = to_string(x);
    for (auto it = num.begin(); it < num.begin() + (num.end() - num.begin())/2; ++it) {
        if ( *it != *(num.end() - (it - num.begin()) - 1) ) {
            return false;
        }
    }
    return true;
}