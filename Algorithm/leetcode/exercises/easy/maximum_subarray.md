# 最大子列和


## my solution 1 在线处理   2019/7/30

> maximum_subarray.cpp

时间复杂度：O(n)

思想：这个算法采用在线处理的思想，读入一个数马上进行计算。代价是算法不容易被看懂

int maxSubArray(vector<int>& nums) {
    int thisSum = 0, maxSum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        thisSum += nums[i];
        if (thisSum > maxSum) {
            maxSum = thisSum;
        } else if (thisSum < 0) {
            thisSum = 0;
        }
    }
    return maxSum;
}

问题：这个程序跑是跑成功了，但是在leetcode上上传了之后遇到了一个非常恶心的问题：如果测试用例是 {-1} 的话，本应该输出 -1 的却输出为 0 了......

好吧是我看错题目了...姥姥的题目是如果输出为负数就输出0......


## my solution 2    暴力法     2019/7/30

时间复杂度：O(n^2)

time: 456 ms

memory: 9 mb

    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, thisSum;
        for (int i = 0; i != nums.size(); ++i) {
            thisSum = 0;
            for (int j = i; j != nums.size(); ++j) {
                thisSum += nums[j];
                if (thisSum > maxSum) {
                    maxSum = thisSum;
                }
            }
        }
        return maxSum;
    }


思路：这个思路是最简单的。但是按照姥姥的话说，看到O(n^2)的时间复杂度，作为一个专业的程序员，你就要思考是否可以把它降为O(nlgn)


## my solution 3    分治法    2019/7/30

未完成


## reference solution1    动态规划      2019/7/30

时间复杂度：O(n)

time: 4 ms

memory: 9.3 mb

    class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int thisSum = nums[0], maxSum = nums[0];
            for (int i = 1; i != nums.size(); ++i) {
                if (thisSum > 0) {
                    thisSum += nums[i];  //如果之前的sum>0，那么它对于答案有帮助，就加上
                } else {
                    thisSum = nums[i];   //反之，那么它对于答案没有帮助，就把sum更新为当前遍历的数字
                }
                if (thisSum > maxSum) {
                    maxSum = thisSum;
                }
            }
            return maxSum;
        }
    };


这应该算是姥姥的算法的升级版了吧...也是我看了思路之后自己码出来的代码