// A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main ()
{
    printf("Enter a intager: ");
    double inputValue;
    scanf("%d", inputValue);
    double outputValue = sqrt(inputValue);
    printf("The square root of %g is %g\n",
            inputValue, outputValue);
    return 0;
}