#include <stdio.h>

int main() 
{
     int x, y, z;

     scanf("%d %d", &x, &y);

     z = foo1(&x, &y); /* z = x*y; */

     printf("z = %d\n", z);
 
     return 0; /* implement this with HALT */
}
 
int foo1(int *x, int *y) 
{
    int total=0;

    for (; *x > 0; *x = *x - 1) {
        total = foo2(total, *y);
    }

    return total;
}
 
int foo2(int currentTotal, int y) 
{
    return currentTotal + y;
}