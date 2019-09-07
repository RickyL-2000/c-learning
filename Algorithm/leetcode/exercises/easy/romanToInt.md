# 罗马数字转整数

## my solution 1    19/7/14    30 min

time: 16 ms

memory: 8.6 mb

    class Solution {
    public:
        int romanToInt(string s) {
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
            return 0;
        }
    };


思路：其实是用了极其繁琐的方法...但是说起来我还是用了递归不是？用了递归居然也只花了这么点内存，真是奇怪。
1. 用迭代器从string数组最左边开始遍历，同时在I、X和C的时候检查右边的字母以保证本层递归要sum的值。其中sum用引用传递以保证值的继承，string用引用传递以节省空间。
2. 在本层检查字母并在sum上加上相应的值
3. 调用自己，继续向右迭代递归
4. 直到迭代器指向尾后元素，递归开始回升————其实就是一堆break，函数停止调用，返回sum。

## reference solution 1

emmmmm...别人的算法总是比我好......(管他呢我刚学)

    class Solution {
    public:
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
                if(roman[s[i]]>=roman[s[i+1]]) // 如果左边的比右边的大，就加上对应的值
                    result+=roman[s[i]];
                else
                {
                    result+=(roman[s[i+1]]-roman[s[i]]);  // 如果左边的比右边的小，就加上这两个值的差的绝对值
                    i++;
                }
            }
            return result;
        }
    };

思路：
1. 将罗马数字的字母和阿拉伯数字的对应关系放入哈希表
2. 遍历string
3. 如果左边的比右边的大，就加上对应的值
4. 如果左边的比右边的小，就加上这两个值的差的绝对值