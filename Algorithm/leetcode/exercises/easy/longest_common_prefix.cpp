/* Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".  

All given inputs are in lowercase letters a-z.  */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>&);

int main() {
    vector<string> strs = {"flower", "flow", "f"};
    string ans = longestCommonPrefix(strs);
    cout << ans << endl;
    return 0;
}

string longestCommonPrefix(vector<string>& strs) {
    if (strs.begin() == strs.end()) {
        return "";
    } else if (strs.end() - strs.begin() == 1) {
        return strs[0];
    }
    string ans = strs[0];
    size_t len;
    if (ans.length() > strs[1].length()) {   // 把len缩减为前后对比的两个string的最小len值 （这里指的是strs[1]和strs[2]
        len = strs[1].length();
    } else {
        len = ans.length();
    }
    size_t j;
    for (size_t i = 1; i < strs.size(); ++i) {
        j = 0;
        if (len > strs[i].length()) {                   // i 用来遍历所有strs中的元素
            len = strs[i].length();                     // 把len缩减为前后对比的两个string的最小len值
        }
        while (j < len) {
            if (ans[j] != strs[i][j]) {
                len = j;
                break;
            }
            ++j;
        }
    }
    ans.erase(ans.begin() + j, ans.end());
    return ans;
}