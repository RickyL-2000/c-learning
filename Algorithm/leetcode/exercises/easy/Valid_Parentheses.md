# Valid Parentheses

## my solution 1    19/7/18

摸索阶段：

valid examples:
()[]{}; 
(()[]){};

invalid examples: 
[({)}[]]; 

思路：从最小优先级的括号开始往外，即从头开始遍历string，遍历到最小单位的括号对(如"()")时将其标记为删除。标记的方法是新建一个新的vector<int>，长度和string一样，每个位置上标记对应的char的状态。

问题：很简单，有bug。

初稿：Valid_Parenthses.cpp

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

主要问题是bug，fail


## my solution 2    19/7/19 - 19/7/23

这是通过理解 leetcode 上官方题解的思路后自己实现的算法。

思路：
1. 整体的思路和 my solution 1 是差不多的，但是可以用一种新的数据结构**栈(stack)**来解决这个问题
2. 首先，有效表达式的子表达式也应该是有效表达式。这就为问题提供了一种递归结构
3. 我们无法真正地从内到外处理这个问题，因为我们对整体结构一无所知。但是，栈可以递归地处理这种情况，即从外部到内部
4. 算法：
   1. 初始化栈S
   2. 一次处理表达式的每个括号
   3. 如果遇到左括号，我们只需要将其压入栈上即可
   4. 如果遇到一个右括号，那么我们检查栈顶的元素。如果栈顶的元素是一个相同类型的左括号，那么我们将它从栈中弹出并继续处理。否则，这意味着表达式无效。
   5. 如果到最后我们剩下的栈中仍然有元素，那么意味着表达式无效。
5. 优化：
   1. 增加一个判断：如果栈的深度大于字符串长度的1/2，就返回false



初稿：Valid_Parentheses(2).cpp

time: 8 ms

memory: 8.4 mb


    bool isValid(string s) {
        vector<char> stack;
        for (int i = 0; i < s.length(); ++i) {
            if (stack.size() > s.length()/2) {
                return false;
            }
            if (s[i]=='(' || s[i]=='[' || s[i]=='{') {
                stack.push_back(s[i]);
            } else if (s[i]==')') {
                if (stack.begin()==stack.end() || *(stack.end()-1)!='(') {
                    return false;
                } else {
                    stack.pop_back();
                }
            } else if (s[i]==']') {
                if (stack.begin()==stack.end() || *(stack.end()-1)!='[') {
                    return false;
                } else {
                    stack.pop_back();
                }
            } else if (s[i]=='}') {
                if (stack.begin()==stack.end() || *(stack.end()-1)!='{') {
                    return false;
                } else {
                    stack.pop_back();
                }
            }
        }
        if (stack.begin() != stack.end()) {
            return false;
        }
        return true;
    }

 
问题：逻辑还是有点繁琐啊


## reference solution 1    19/7/23

time: 0 ms

    bool isValid(string s) {
        vector<char> pre = {'(', '{', '['};
        vector<char> post = {')', '}', ']'};
        stack<char> st;                           // 原来真的有栈啊
        for ( auto ch : s ) {
            if ( st.empty() ){ // st empty
                if (  find( post.begin(), post.end(), ch) != post.end() ){  // } ] )   // 妙啊！！！！
                    return false;
                } else {
                    st.push( ch );
                }
            } else {  // st has elements
                if (  find( post.begin(), post.end(), ch) != post.end() ){  // ch = } ] )
                    char ch2 = st.top();
                    if ((ch2 == '(' && ch == ')') || (ch2 == '{' && ch == '}') || (ch2 == '[' && ch == ']')){
                        st.pop();
                    } else {
                        return false;
                    }
                } else {
                    st.push(ch);
                }
            }
        }
        return st.empty() ? 1 : 0;
    }
