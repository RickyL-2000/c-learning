#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isValid(string);
void print(vector<char>);

int main() {
    string s = "([{}()])";
    cout << isValid(s) << endl;
    return 0;
}

bool isValid(string s) {
    vector<char> stack;
    for (int i = 0; i < s.length(); ++i) {
        cout << "The size of vector is " << stack.size() << ", and the length of the string is " << s.length() << endl;  // debug
        if (stack.size() > s.length()/2) {
            return false;
        }
        if (s[i]=='(' || s[i]=='[' || s[i]=='{') {
            cout << "Now s[" << i << "] is " << s[i] << endl;   // debug
            stack.push_back(s[i]);
            print(stack);         // debug
        } else if (s[i]==')') {
            cout << "Now s[" << i << "] is not a lefter, but " << s[i] << endl;   // debug
            if (stack.begin()==stack.end() || *(stack.end()-1)!='(') {              // 问题出在这里！！！！stack.end()是尾后元素，不是尾元素!!!
                return false;
            } else {
                stack.pop_back();
                print(stack);      // debug
            }
        } else if (s[i]==']') {
            cout << "Now s[" << i << "] is not a lefter, but " << s[i] << endl;   // debug
            if (stack.begin()==stack.end() || *(stack.end()-1)!='[') {
                return false;
            } else {
                stack.pop_back();
                print(stack);      // debug
            }
        } else if (s[i]=='}') {
            cout << "Now s[" << i << "] is not a lefter, but " << s[i] << endl;   // debug
            if (stack.begin()==stack.end() || *(stack.end()-1)!='{') {
                return false;
            } else {
                stack.pop_back();
                print(stack);      // debug
            }
        }
    }
    if (stack.begin() != stack.end()) {
        return false;
    }
    return true;
}

void print(vector<char> vec) {      // debug
    cout << "Print: The vector is: ";
    for (char ch : vec) {
        cout << ch << ' ';
    }
    cout << endl;
    return;
}