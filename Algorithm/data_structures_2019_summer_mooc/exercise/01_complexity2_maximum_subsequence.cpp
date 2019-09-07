#include <iostream>
#include <vector>
using namespace std;
vector<int> maxSubArray(vector<int>&);

int main() {
    int num;
    cin >> num;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    vector<int> ans = maxSubArray(nums);
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];
    return 0;
}

vector<int> maxSubArray(vector<int>& nums) {
    int thisSum = nums[0], maxSum = nums[0];
    int left = nums[0], right = nums[0];
    int count = 1;
    for (size_t i = 1; i != nums.size(); ++i) {
        if (thisSum >= 0) {
            thisSum += nums[i];
            ++count;
        } else {
            thisSum = nums[i];
            count = 1;
        }
        if (thisSum > maxSum) {
            maxSum = thisSum;
            right = nums[i];        // 到更新 max 的时候再更新 right 的值，否则 right 会一直更新直到最后
            left = nums[i-count+1]; // 我确定 left 的办法比较笨，就是之前在遍历的时候就记录一次不更新 thisSum 的状态下能遍历多少次，最后再往前回溯
        }
    }
    if (maxSum < 0) {
        return {0, *nums.begin(), *(nums.end()-1)};
    }
    return {maxSum, left, right};
}