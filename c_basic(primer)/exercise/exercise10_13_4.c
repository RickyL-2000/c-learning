//返回储存在double类型数组中最大值的下标
#include <stdio.h>
int index(double array[], int n);
int main()
{
    double array[10] = {2.524, 6.2478, 4.8246, 7.11579, 9.254, 4.2546, 2.16322, 6.234, 8.5, 3.0};
    int ind = index(array, 10);
    printf("%d", ind);
}

int index(double array[], int n)
{
    double m = array[0];
    int ind = 0;
    for (int i = 1; i < n; i++)
    {
        if (m < array[i])
        {
            m = array[i];
            ind = i;
        }
    }
    return ind;
}