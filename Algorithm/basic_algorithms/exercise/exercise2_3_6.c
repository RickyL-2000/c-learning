//用二分查找优化后的插入排序
#include <stdio.h>
void insertionSort(int array[], int length);
int biSearch(int array[], int left, int right, int target);
void show1dArray(int array[], int length);
int main(void)
{
    puts("Enter 8 integers: ");
    int array[8];
    for (int i = 0; i < 8; i++) {
        scanf("%d", &array[i]);
    }
    insertionSort(array, 8);
    show1dArray(array, 8);
    return 0;
}

void insertionSort(int array[], int length)
{
    for (int j = 1; j < length; j++) {
        int index = biSearch(array, 0, j-1, array[j]);  //index就是刚好比array[j]小或者相等的数的下标
        int value = array[j];
        for (int i = j-1; i >= index+1; i--) {
            array[i+1] = array[i];
        }
        array[index+1] = value;
    }
}

int biSearch(int array[], int left, int right, int target)
{
    int mid = left + (right - left + 1) / 2;
    if (target > array[mid]) {   //如果目标大于中间数
        if (mid + 1 == right) {  //而且中间数的右边只有一个数
            if (array[right] <= target)   //如果这右边的这一个数比目标小或相等
                return right;             //则返回右边这一个数的下标，因为最终在插入排序中插入的数字是**放在返回的下标的数字右边的**。（适用于从小到大排序，如果反过来则需要改变）
            else if (array[right] > target)      //如果右边这一个数比目标大
                return mid;                      //就返回之前的那个数
        }
        else if (mid == right) {  //如果中间数就是右边数————右边没有数了
            return mid;     //返回中间数
        }
        else if (mid + 1 < right) {   //如果中间数和右边数中间还有数，那就继续递归
            biSearch(array, mid+1, right, target);
        }
    }
    else if (target < array[mid]) {   //如果目标小于中间数
        if (mid - 1 == left) {   //而且中间数的左边只有一个数
            if (target >= array[left])
                return left;
            else if (target < array[left])
                return left-1;
        }
        else if (mid == left) {
            return mid-1;
        }
        else if (mid - 1 > left) {
            biSearch(array, left, mid, target);
        }
    }
    else if (target == array[mid]) {
        return mid;
    }
}

void show1dArray(int array[], int length)
{
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
}