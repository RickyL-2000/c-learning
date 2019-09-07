# 只出现一次的数字 I

## my solution 1    (19/7/10)   

由于一些原因，我在第一次独立做出这道题之前就了解了这道题的“亦或”做法。所以这种算法不是我独立想出来的。

time: 12 ms

memory: 9.7 mb

    class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int sum = nums[0];
            for (int i = 1; i < nums.size(); ++i) {
                sum ^= nums[i];
            }
            return sum;
        }
    };

思路：

两个相同的数亦或的结果是0，那么很简单，把所有数字都亦或在一起，偶数个的数字就自然相互抵消了，只剩下唯一的一个单独的数字。

亦或也可以被认为是不进位加法。