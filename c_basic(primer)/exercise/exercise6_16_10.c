#include <stdio.h>
int main()
{
    printf("Enter lower and upper integer limits: ");
    int a, b;
    while (scanf("%d%d", &a, &b) == 2 && a < b) {
        int sum = 0;
        for (int i = a; i <= b; i++)
            sum += i*i;
        printf("The sum of the squares from %d to %d is %d\n", a*a, b*b, sum);
    }
    printf("Done");
    return 0;
}