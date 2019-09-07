// * Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.
// *  I 1; V 5; X 10; L 50; C 100; D 500; M 1000
// ! I can be places before V and X to make 4 and 9
// ! X can be places before L and C to make 40 and 90
// ! C can be places before D and M to make 400 and 900

#include <iostream>
#include <string>
using namespace std;
int romanToInt(string);
int romanSum(const string&, string::iterator, int&);

int main()
{
    string s;
    cout << "Enter the roman numbers (q to quit):";
    while (cin >> s && s != "q") {
        int num = romanToInt(s);
        cout << "This is equal to " << num << endl;

        cout << "Enter the next roman number (q to quit):";
    }
}

int romanToInt(string s){
    auto it = s.begin();
    int sum = 0;
    return romanSum(s, it, sum);
}

int romanSum(const string& s, string::iterator it, int& sum) {
    const auto end = s.end();
    if (it == s.end()) {
        return sum;
    }
    switch (*it) {
        case 'M':
            sum += 1000;
            return romanSum(s, it+1, sum);
            break;
        case 'D':
            sum += 500;
            return romanSum(s, it+1, sum);
            break;
        case 'C':
            if (it+1 == s.end()) {
                sum += 100;
                return sum;
            }
            switch (*(it+1)) {
                case 'M':
                    sum += 900;
                    return romanSum(s, it+2, sum);
                    break;
                case 'D':
                    sum += 400;
                    return romanSum(s, it+2, sum);
                    break;
                default:
                    sum += 100;
                    return romanSum(s, it+1, sum);
                    break;                    
            }
        case 'L':
            sum += 50;
            return romanSum(s, it+1, sum);
            break;
        case 'X':
            if (it+1 == s.end()) {
                sum += 10;
                return sum;
            }
            switch (*(it+1)) {
                case 'C':
                    sum += 90;
                    return romanSum(s, it+2, sum);
                    break;
                case 'L':
                    sum += 40;
                    return romanSum(s, it+2, sum);
                    break;
                default:
                    sum += 10;
                    return romanSum(s, it+1, sum);
                    break;
            }
        case 'V':
            sum += 5;
            return romanSum(s, it+1, sum);
            break;
        case 'I':
            if (it+1 == s.end()) {
                sum += 1;
                return sum;
            }
            switch (*(it+1)) {
                case 'X':
                    sum += 9;
                    return romanSum(s, it+2, sum);
                    break;
                case 'V':
                    sum += 4;
                    return romanSum(s, it+2, sum);
                    break;
                default:
                    sum += 1;
                    return romanSum(s, it+1, sum);
                    break;
            }
    }
}