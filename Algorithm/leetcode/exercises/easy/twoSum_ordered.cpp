#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers = {3,24,50,79,88,150,345};
    int target = 200;

    int left = 0, i, j;
    //if (numbers[right] > target) {
    //   right--;
    //}
    // 上两行错误的原因：有可能是负数！
    if (numbers[left] + numbers[numbers.size()-1] < target) {
        left++;
    }
    for (i = left; i < numbers.size()-1; ++i) {
        if (numbers[i+1]==numbers[i]) {
            if (2*numbers[i] == target) {
                std::cout << i +1 << ' ' << i+1 +1 << std::endl;
            } else if (2*numbers[i] != target) {
                continue;
            }
        } else {
            int sought = target - numbers[i];
            auto beg = numbers.begin() + i, end = numbers.end();
            auto mid = numbers.begin() + i + (end - beg) / 2;
            while (mid != end && *mid != sought) {
                if (sought > *mid) {
                    beg = mid + 1;
                } else if (sought < *mid) {
                    end = mid;
                }
                mid = beg + (end - beg) / 2;
            }
            if (numbers[i] + numbers[mid - numbers.begin()] == target) {
                std::cout << i +1 << ' ' << mid - numbers.begin() +1 << std::endl;
                break;
            } else {
                continue;
            }
        }
    }
}