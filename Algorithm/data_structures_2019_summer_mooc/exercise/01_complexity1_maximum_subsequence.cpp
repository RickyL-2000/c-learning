#include <iostream>
#include <vector>
using namespace std;
int maxSubArray(vector<int>&);

int main() {
    int num;
    cin >> num;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    int maxSum = maxSubArray(nums);
    cout << ((maxSum > 0) ? maxSum : 0) << endl;
    return 0;
}

int maxSubArray(vector<int>& nums) {
    int thisSum = nums[0], maxSum = nums[0];
    for (size_t i = 1; i != nums.size(); ++i) {  // 这里比较规范的写法是用 size_t 而不是 int，因为有符号整数和无符号整数之间的比较可能会出问题
        if (thisSum > 0) {
            thisSum += nums[i];
        } else {
            thisSum = nums[i];
        }
        if (thisSum > maxSum) {
            maxSum = thisSum;
        }
    }
    return maxSum;
}