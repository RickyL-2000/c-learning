//编写一个函数，把3个double变量从小到大排序
#include <stdio.h>
void arrange(double * i, double * j, double * k);

int main(void)
{
    printf("Enter three floating-point numbers: ");
    double i, j, k;
    scanf("%lf%lf%lf", &i, &j, &k);
    //while (scanf("%lf%lf%lf", &i, &j, &k) == 3)
    //{
        arrange(&i, &j, &k);
        printf("Now they are: %f %f %f.\n", i, j, k);
        //printf("Enter the next set of numbers: ");
    //}
    //printf("Done.");
    return 0;
}

void arrange(double * i, double * j, double * k)
{
    double temp;   //不会用数组是真的麻烦！
    if (*i <= *k && *k <= *j)
    {
        temp = *k;
        *k = *j;
        *j = temp;
    }
    else if (*j <= *i && *i <= *k)
    {
        temp = *j;
        *j = *i;
        *i = temp;
    }
    else if (*j <= *k && *k <= *i)
    {
        temp = *i;
        *i = *j;
        *j = *k;
        *k = temp;
    }
    else if (*k <= *i && *i <= *j)
    {
        temp = *k;
        *k = *j;
        *j = *i;
        *i = temp;
    }
    else if (*k <= *j && *j <= *i)
    {
        temp = *k;
        *k = *i;
        *i = temp;
    }

    return;
}