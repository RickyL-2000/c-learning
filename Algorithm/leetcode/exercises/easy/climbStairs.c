/* You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? */

/* suppose that on the nth stair we have f(n) ways, then f(n+2) = f(n) + f(n+1), where f(1) = 1, f(2) = 2 */

#include <stdio.h>
#include <math.h>

int climbStairs(int n);

int main() {
    int n = 3;
    int ways = climbStairs(n);
    printf("%d", ways);
    return 0;
}

int climbStairs(int n) {
    double sqrt5 = sqrt(5);
    int result = 1/sqrt5*( pow((1+sqrt5)/2, n+1) - pow((1-sqrt5)/2, n+1));
    return result;
}