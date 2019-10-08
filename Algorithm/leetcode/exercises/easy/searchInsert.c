#include <stdio.h>

int searchInsert(int*, int, int);

int main() {

    /****以下为测试样例，可以修改****/
    int nums[4] = {1, 3, 5, 6};
    int target = 2;
    /******************************/

    int position = searchInsert(nums, 4, target);
    printf("%d", position);
    return 0;
}

int searchInsert(int* nums, int numsSize, int target) {
    size_t left = 0, 
           right = numsSize-1,
           mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (target < nums[mid]) {
            if (mid == 0) break;
            right = mid - 1;
        } else if (target > nums[mid]) {
            if (mid == numsSize-1) {left = numsSize; break;}
            left = mid + 1;
        } else if (target == nums[mid]) {
            break;
        }
    }
    if (target == nums[mid]) return mid;
    if (target != nums[mid]) return left;
}