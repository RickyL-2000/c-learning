#include <stdio.h>
void Temperatures(double t);
int main()
{
    printf("Enter a temperature in Fahrenheit: \n");
    double t;
    while (scanf("%lf", &t) == 1) {
        if (t <= -459.67) 
            printf("-459.67 degree is the lowest temperature. \n");
        else
            printf("%f\n", t);  //debug
            Temperatures(t);
    }
    return 0;    
}

void Temperatures(double t)
{
    printf("%f\n", t);  //debug   
    double c = (t - 32.0)*5/9;                     //为什么5/9*(t-32.0)就是不行呢??????????
    double k = (t - 32.0)*5/9 + 273.16;
    printf("The Centigrade degree is %g\n", c);
    printf("The Kelvin degree is %g\n", k);
    return;
}