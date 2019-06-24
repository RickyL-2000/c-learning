#include <stdio.h>

int biSearch(int array[], int left, int right, int target)
{
    if (right <= left) //这算法可以啊！！！这就省去了很多繁杂的边界条件！只要考虑right 和 left 的大小关系就可以了！
        return (target > array[left]) ? (left+1) : left;
    int mid = (left + right) / 2;
    if (target == array[mid]) {
        return mid+1; // 他的算法是返回要插值的位置的，我返回的是要差值的位置左边的位置
    }
    if (target > array[mid])
        return biSearch(array, mid+1, right, target); 
        //如果mid右边只有一个数据而且该数据还比target大的话，下一层的递归中left(上一层的mid+1)和right就会相等，在下一层的递归的一开始就会终止递归
        //如果mid右边没有数据的话，mid+1就会大于right，同理会终止下一步递归
    return biSearch(array, left, mid-1, target);
}

void insertionSort(int array[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int j = i - 1;
        int selected = array[i];
        int loc = biSearch(array, 0, j, selected);
        while (j >= loc) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = selected;
    }
}

int main()   // driver function
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