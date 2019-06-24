//编写一个函数，返回储存在int类型数组中的最大值，并在一个简单的程序中测试该函数
#include <stdio.h>
int max(int array[], int n);
int main()
{
    int array[10] = {3,6,1,7,8,4,6,2,7,7};
    int m = max(array, 10);
    printf("%d", m);

    return 0;
}

int max(int array[], int n)
{
    int m = array[0];
    for (int i = 1; i < n; i++)
    {
        if (m < array[i])
            m = array[i];
    }
    return m;
}