# 回文数

判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

## my solution 1    (19/7/11)   15 min

time: 40 ms

memory: 8.2 mb

    class Solution {
    public:
        bool isPalindrome(int x) {
            string num = to_string(x);
            for (auto it = num.begin(); it < num.begin() + (num.end() - num.begin())/2; ++it) {
                if ( *it != *(num.end() - (it - num.begin()) - 1) ) {
                    return false;
                }
            }
            return true;    
        }
    };

思路：
1. 把数值转换成字符串，然后简单地从左到中间遍历查看是否有不同的数字。这算是目前最简单的一道题，我的算法也是最容易想到的了吧。


反思：
1. 用字符串来解决此问题据说需要额外的非常量空间来创建问题中所不允许的字符串
2. 第二个想法是将数值本身反转，但是容易溢出
3. 但是，既然反转整个数值有可能溢出，为什么不反转数值的一半？如果该数字的回文数。其后半部分反转后应该与原始数字的前半部分相同。

## my solution 2    (19/7/11)   10 min

这种算法即反转一半数值，然后将反转的结果和剩下的相比较。这是我一开始的代码：

    class Solution {
    public:
        bool isPalindrome(int x) {
            if (x < 0) {
                return false;
            }
            int y = 0, pop;
            while (x / 10 >= y * 10) {
                pop = x % 10;
                x /= 10;
                y = y * 10 + pop;
            }
            return x == y || x/10 == y;
        }
    };

然而遇到了问题，超出了时间限制。原因是有一个测试用例居然是0，这下就会进入死循环......

出题的人真狠，这都能想到。

然后我就把 x % 10 != 0 加入到了while的条件中，然而...

有一个测试用例居然是1，就出错了

然后见招拆招...加了一句检查是否是个位数...

    class Solution {
    public:
        bool isPalindrome(int x) {
            if (x < 0) {
                return false;
            }
            if (x / 10 == 0) {
                return true;
            }
            int y = 0, pop;
            while (x % 10 != 0 && x / 10 >= y * 10) {
                pop = x % 10;
                x /= 10;
                y = y * 10 + pop;
            }
            return x == y || x/10 == y;
        }
    };

还是不对...如果测试用例是1001的话。

哎，明天再看看吧