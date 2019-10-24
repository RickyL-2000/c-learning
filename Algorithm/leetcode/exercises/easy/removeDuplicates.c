/*Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory. */

#include <stdio.h>
#define SIZE 2

int removeDuplicates(int* nums, int numsSize);
void bubble(int* nums, int numsSize, int*target, int targetSize);
void print(int* nums, int numsSize);

int main() {
    int nums[SIZE] = {2, 2};
    int result = removeDuplicates(nums, SIZE);
    printf("%d\n", result);
    print(nums, result);
    return 0;
}

int removeDuplicates(int* nums, int numsSize) {
    /* returnSize store the size of the array that will be returned */
    int i = 0, targetSize = 0, returnSize = numsSize;
    while (i < returnSize) {
        while (*(nums+i) == *(nums+i+1)) {
            targetSize++;
            i++;
        }
        i -= targetSize-1;
        bubble(nums, returnSize, nums+i, targetSize);   /* move <targetSize> digits to the right of the array */
        returnSize -= targetSize;
        targetSize = 0;
    }
    return returnSize;
}

void bubble(int* nums, int numsSize, int*target, int targetSize) {
    int temp, i;
    /* have to loop for nums+numsSize-target - targetSize times */
    for (i = 0; i < nums+numsSize-target - targetSize; i++) {
        temp = *(target+targetSize+i);
        *(target+targetSize+i) = *(target+i);
        *(target+i) = temp;
    }
    return;
}

void print(int* nums, int numsSize) {
    int i = 0; 
    for (; i < numsSize; i++) {
        printf("%d ", *(nums+i));
    }
    return;
}