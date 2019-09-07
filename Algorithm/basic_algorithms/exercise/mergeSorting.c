#include <stdio.h>
#define LEN 8
void merge(int array[], int p, int q, int r, int temp[]);
void mergeSort(int array[], int left, int right, int sorted_array[]);
void show1dArray(int array[], int length);
int main(void)
{
    printf("Enter %d integers: \n", LEN);
    int array[LEN], temp[LEN];
    for (int i = 0; i < LEN; i++) {
        scanf("%d", &array[i]);
    }
    mergeSort(array, 0, LEN-1, temp);
    show1dArray(array, LEN);
    return 0;
}

void merge(int array[], int left, int mid, int right, int temp[])
{
    int i = left, j = mid+1;    //用i和j把array分成两个部分，假设这两个部分已经完成排序了
    int k = 0;      //用于标记temp的长度
    while (i <= mid && j <= right) { //把较小的牌依次放入temp，这样temp中就是排好序的，直到某一个牌堆被取完
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else 
            temp[k++] = array[j++];
    }
    while (i <= mid)    //检查是哪一个牌堆被取完，并把剩下的放入temp中
        temp[k++] = array[i++];
    while (j <= right)
        temp[k++] = array[j++];
    for (i = 0; i < k; i++)   //k在不同的递归层是不一样的，这就避免了在底层的时候访问>k时错误的数据
        array[left+i] = temp[i]; //把temp中的数据拷贝到原数组对应位置 这里的left容易忘记！！！
}

void mergeSort(int array[], int left, int right, int temp[]) //标记开始和结束位置。此位置在递归过程中会移动和复制
{
    if (left < right) {  //如果left >= right，只有一个可能，就是每个牌堆只有一张牌了，递归则开始“回升”
        int mid = (left+right)/2;
        mergeSort(array, left, mid, temp);
        mergeSort(array, mid+1, right, temp);
        merge(array, left, mid, right, temp);
    }
}

void show1dArray(int array[], int length)
{
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
}