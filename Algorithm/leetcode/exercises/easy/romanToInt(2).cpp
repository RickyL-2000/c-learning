#include <iostream>
#include <map>
#include <string>
using namespace std;

int romanToInt(string s) {
        int result=0;//存放结果
        map<char,int> roman;//建立罗马表
        //插入对应关系
        roman.insert(map<char,int>::value_type('I',1));
        roman.insert(map<char,int>::value_type('V',5));
        roman.insert(map<char,int>::value_type('X',10));
        roman.insert(map<char,int>::value_type('L',50));
        roman.insert(map<char,int>::value_type('C',100));
        roman.insert(map<char,int>::value_type('D',500));
        roman.insert(map<char,int>::value_type('M',1000));
        for(int i=0;i<s.length();i++)
        {
            if(roman[s[i]]>=roman[s[i+1]])
                result+=roman[s[i]];
            else
            {
                result+=(roman[s[i+1]]-roman[s[i]]);
                i++;
            }
        }
        return result;
    }

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