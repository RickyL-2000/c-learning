#include <stdio.h>
void copy_arr(double target1[], double source[], int n);
void copy_ptr(double *target2, double *source, int n);
void copy_ptrs(double target3[], double *start, double *end);

int main()
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];

    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source+5);

    return 0;
}

void copy_arr(double target1[], double source[], int n)
{
    for (int i = 0; i < n; i++)
        target1[i] = source[i];
    printf("Now target1 is: ");
    for (int i = 0; i < n; i++)
        printf("%f  ", target1[i]);
    printf("\n");
}

void copy_ptr(double *target2, double *source, int n)
{
    for (int i = 0; i < n; i++)
        *(target2 + i) = *(source + i);
    printf("Now target2 is: ");
    for (int i = 0; i < n; i++)
        printf("%f  ", target2[i]);
    printf("\n");
}

void copy_ptrs(double target3[], double *start, double *end)
{
    int i = 0;
    while (start < end)
    {
        target3[i] = *start;
        start++;
        i++;
    }
    unsigned m = sizeof(target3);       //debug
    unsigned n = sizeof(target3[0]);    //debug  为什么一个元素的大小比一个数组还大？？？？
    printf("Now target3 is: ");
    for (int i = 0; i < sizeof target3 / sizeof target3[0]; i++)
        printf("%f  ", target3[i]);
    printf("\n");
}