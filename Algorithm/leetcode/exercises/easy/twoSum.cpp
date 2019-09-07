#include <iostream>
#include <vector>

int main()
{
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    int i, j;
    for (i = 0; i < nums.size()-1; ++i) {
        for (j = i+1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                std::cout << i << ' ' << j << std::endl;
                break;
            }
        }
    }
}