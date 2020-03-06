/*
 *  This program is supposed to find the greatest common divisor of
 *  two integers using Euclid's algorithm. At least one of the
 *  arguments must be non-zero.
 *  
 *  Euclid's algorithm is as follows:
 *  gcd(x, y) = { gcd(y, remainder of (x / y))   , if y != 0
 *                 x                             , otherwise }
 */

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

int main()
{
    int x, y, result;

    printf("Enter x and y: ");
    if (2 != scanf("%d %d", &x, &y))
    {
        return EXIT_FAILURE;
    }

    result = gcd(x, y);

    printf("The GCD of %d and %d is %d\n", x, y, result);

    return EXIT_SUCCESS;
}

