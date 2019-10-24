#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y)
{
    int t;

    while (y != 0)
    {
       t = x; 
       x = y; 
       y = t % y;
    }

    return (x < 0) ? -x : x; /* abs(x) */
}

int main() {
    int x = 4,
        y = -6,
        result;
    result = gcd(x, y);

    printf("%d", result);

    return 0;
}