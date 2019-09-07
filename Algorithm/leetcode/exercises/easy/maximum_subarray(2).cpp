#include <iostream>
#include <vector>
using namespace std;
int maxSubArray(vector<int>&);

int main() {
    vector<int> nums = {-1};
    int maxSum = maxSubArray(nums);
    cout << maxSum << endl;
    return 0;
}

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