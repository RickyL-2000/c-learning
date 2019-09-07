//改进版本，用反转数值的一半解决问题
#include <iostream>
using namespace std;
bool isPalindrome(int);

int main()
{
    int x = 1;
    cout << isPalindrome(x) << endl;
    return 0;
}

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    int y = 0, pop;
    while (x % 10 != 0 && x / 10 >= y * 10) { //小于的话意味着数值反转处理到了一半，非回文数也成立
        pop = x % 10;
        x /= 10;
        y = y * 10 + pop;  //这种算法太妙了，一定要好好领会
    }
    return x == y || x/10 == y;
}