#include <stdio.h>
double ProdDivDiff(double a, double b);
int main()
{
    double a, b;
    int check = 1;
    printf("Enter two nonzero floating-point numbers: ");
    while (check)
    {
        if (scanf("%f", &a) != 1)
            check = 0;
        else if (scanf("%f%f", &a, &b) != 2 || a == 0 || b == 0)
            printf("Enter two nonzero floating-point numbers: ");
        else {
            if (a >= b)
                printf("The difference of these two numbers divided by their product is %.6f.\n", 
                    ProdDivDiff(a,b));
            else
                printf("The difference of these two numbers divided by their product is %.6f.\n", 
                    ProdDivDiff(b,a));
        }
    }
    return 0;
}

double ProdDivDiff (double a, double b)
{
    //此时a>=b
    double c = (a-b)/(a*b);
    return c;
}