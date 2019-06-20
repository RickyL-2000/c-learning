#include <stdio.h>
void cubic(double n);
int main(void)
{
    printf("Enter a number (double): \n");
    double n;
    scanf("%lf", &n);

    cubic(n);

    return 0;
}

void cubic(double n)
{   
    printf("%f", n*n*n);
}