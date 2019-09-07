// 最简单的全部遍历，复杂度 O(n^2)

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int maxSubArray(vector<int>&);

int main() {
    vector<int> nums = {-1};
    int maxSum = maxSubArray(nums);
    printf("%d", maxSum);
    return 0;
}

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