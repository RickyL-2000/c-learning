#include <stdio.h>
int main()
{
    printf("Enter the limit of the series: ");
    int n;
    
    while (scanf("%d", &n) && n>0)
    {
        double sum1 = 0L, sum2 = 0L;  //sum1 is the positive series, sum2 is the alternative series
        for (double i = 1.0; i <= n; i++)
        {
            sum1 += 1/i;
            printf("%f\n", 1/i);
        }
        for (double j = 1.0; j <= n; j++)
        {
            double neg = 1;
            for (int k = 1; k < j; k++)
                neg *= -1;
            sum2 += neg/j;
        }
        printf("The sum of the positive series is %.10f,\n", sum1);
        printf("and the sum of the alternative series is %.10f.\n", sum2);
        printf("Enter the next limit: ");
    }
    printf("Done");
    return 0;
}