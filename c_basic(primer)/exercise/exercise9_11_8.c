//写一个能计算正负整数幂的函数
//总结：发现输入和输出double类型的数据的格式化字符居然是不一样的....printf()用的是%f，而scanf()用的是%lf。
//     另外，关于long double的事情一直一直就搞不好...以后还是就不碰这个奇怪的类型了吧....:(
#include <stdio.h>
double power (double num, int p);

int main()
{
    printf("Enter a floating-point number and an integer: ");
    double num;
    int p;
    scanf("%lf%d", &num, &p);    //要打印double类型要用%lf转义字符！这书怎么写得这么不清楚
    printf("%f\n",num);          //debug
    double ans = power (num, p);
    printf("%f", ans);
    return 0;
}

double power (double num, int p)
{
    if (p == 0)
        return 1;
    else
    {
        int q = (p > 0) ? p : -p;
        double prod = 1.00000;
        for (int i = 0; i < q; i++)
        {
            prod *= num;
            printf("%Lf\n",prod);    //debug
        }
        if (p > 0)
        {
            printf("Now p > 0\n"); //debug
            printf("%f\n", prod);
            return prod;
        }
        else if (p < 0)
        {
            printf("Now p < 0\n"); //debug
            prod = 1/prod;
            return prod;
        }
    }
}