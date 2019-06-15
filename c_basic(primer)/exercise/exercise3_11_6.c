#include <stdio.h>
int main()
{
    unsigned long number = 0;
    float quart;
    printf("Enter quarts of water: ");
    scanf("%f\n", &quart);
    printf("There are %e water molecules.", quart*950/3.0e-23);
    return 0;
}