#include <stdio.h>
void Temperatures(double t);
int main()
{
    printf("Enter a temperature in Fahrenheit: \n");
    double t;
    while (scanf("%f", &t) == 1) {
        if (t <= -459.67) 
            printf("-459.67 degree is the lowest temperature. \n");
        else
            Temperatures(t);
    }
    return 0;    
}

void Temperatures(double t)
{
    printf("The Centigrade degree is %f\n", 5/9*(t - 32.0));
    printf("The Kelvin degree is %f\n", 5/9*(t - 32.0)+273.16);
}