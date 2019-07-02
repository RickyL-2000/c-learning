//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个整数，并返回他们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
//尽量把时间复杂度控制在O(nln(n))

#include <stdio.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize);
int mergeSort(int array[], int left, int right, int temp[]);
int merge(int array[], int left, int mid, int right, int temp[]);
int biSearch(int array[], int left, int right, int target);

int main()
{
    int nums[4] = {2, 7, 11, 15};
    int target = 9;
    int index1, index2;
    index1 = *twoSum(nums, 4, target, 2);
    return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int temp[numsSize];
    mergeSort(nums, 0, numsSize-1, temp);
    int right = numsSize-1;
    while (nums[right] > target) {
        right--;     //这里“--”符号以及循环的先后可能会产生bug （而且排除了负数的可能性）
    }
    int index;
    int answer[2];
    for (int i = 0; i < right; i++) {
        if (nums[i] + nums[right] < target)
            continue;
        else {
            index = biSearch(nums, i+1, right, target-nums[i]);
            if (index == -1)
                continue;
            else {
                answer[0] = i;
                answer[1] = index;
                return answer;
            }
        }
    }
}

int mergeSort(int array[], int left, int right, int temp[]) {
    if (left < right) {
        int mid = (right + left) / 2;
        mergeSort(array, left, mid, temp);
        mergeSort(array, mid+1, right, temp);
        merge(array, left, mid, right, temp);
    }
}

int merge(int array[], int left, int mid, int right, int temp[]) {
    int i = left, j = mid+1;
    int k = 0;
    while (i <= mid && j <= right) {
        if (array[i] <= array[j]) {
            temp[k++] = array[i++];
        }
        else {
            temp[k++] = array[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = array[i++];
    }
    while (j <= mid) {
        temp[k++] = array[j++];
    }
    for (i = 0; i < k; i++) {
        array[left+i] = temp[i];
    }
}

int biSearch(int array[], int left, int right, int target) {
    if (right <= left && array[left] != target) {
        return -1;
    }
    int mid = (left + right) / 2;
    if (array[mid] == target)
        return mid;
    if (array[mid] > target) {
        return biSearch(array, left, mid-1, target);
    }
    return biSearch(array, mid+1, right, target);
}