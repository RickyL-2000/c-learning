// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// 有bug，得治
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool isValid(string);
bool changeStatus(string, vector<int>&, int&);

int main() {
    string s = "{()[()](})";
    bool check = isValid(s);
    cout << check << endl;
    return 0;
}

bool isValid(string s) {
    if (s == "") return false;
    vector<int> status(s.length(), 1);
    int sum = 0;
    return changeStatus(s, status, sum);
}

bool changeStatus(string s, vector<int>& status, int& sum) {
    for (int i = 0; i < s.length()-1; ++i) {
        if (status[i]) {
            for (int j = i+1; j < s.length(); ++j) {
                if (!status[j])
                    continue;
                else if (status[j]) {
                    if ( (s[i] == '(' && s[j] == ')')||(s[i] == '[' && s[j] == ']')||(s[i] == '{' && s[j] == '}') ) {
                        status[i] = 0;
                        status[j] = 0;
                        break;
                    }
                }
            }
        }
    }
    int newsum = 0;
    for (int j = 0; j < status.size(); ++j) {
        newsum += status[j];
    }
    if (newsum > 0) {
        if (newsum == sum) {
            return false;
        } else {
            return changeStatus(s, status, newsum);
        }
    } else if (newsum == 0) {
        return true;
    }
}