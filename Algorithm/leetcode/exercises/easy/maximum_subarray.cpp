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
    int thisSum = 0, maxSum = 0;
    for (int i = 0; i != nums.size(); ++i) {
        thisSum += nums[i];
        if (thisSum > maxSum) {
            maxSum = thisSum;
        } else if (thisSum < 0) {
            thisSum = 0;
        }
    }
    return maxSum;
}