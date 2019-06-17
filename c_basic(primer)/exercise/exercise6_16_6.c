#include <stdio.h>
int main()
{
    int a,b;
    do
        printf("Enter the upper and lower limits of the table: \n");
    while (scanf("%d%d",&a,&b) != 2 || a < b);
    for (int i = 0; i < a-b+1; i++)
        printf("%6d %6d %6d\n", 
            b+i, (b+i)*(b+i), (b+i)*(b+i)*(b+i));
    return 0;
}