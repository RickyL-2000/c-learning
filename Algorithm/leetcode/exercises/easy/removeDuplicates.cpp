#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == nums[i+1]) {
            nums.erase(nums.begin() + i);
        }
    }
    return nums.size();
}

int main()
{
    vector<int> nums = {1,1,2};
    removeDuplicates(nums);
    return 0;
}