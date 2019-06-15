#include <stdio.h>
int main()
{
    printf("Enter a floating-point value: ");
    float a;
    scanf("%f\n", &a);
    printf("fixed-point notation: %f\n", a);
    printf("exponetial notation: %e\n", a);
    printf("p notation: %a\n", a);

    return 0;
}