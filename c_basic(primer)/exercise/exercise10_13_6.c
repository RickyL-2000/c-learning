//把double类型数组中的数据倒序排列
#include <stdio.h>
void rearrange(double array[], int n);
int main()
{
    double array[10] = {2.524, 6.2478, 4.8246, 7.11579, 9.254, 4.2546, 2.16322, 6.234, 8.5, 3.0};
    rearrange(array, 10);
    for (int i = 0; i < 10; i++)
        printf("%f  ", array[i]);
    
    return 0;
}

void rearrange(double array[], int n)
{
    //稍微学了一下插入排序
    for (int j = 1; j < n; j++)
    {
        double key = array[j];
        int i = j - 1;
        while (i >= 0 && array[i]<key)
        {
            array[i+1] = array[i];
            i--;
        }
        array[i+1] = key;
    }
}