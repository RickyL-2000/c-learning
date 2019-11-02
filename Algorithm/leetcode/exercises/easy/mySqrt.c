/* Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned. */

#include <stdio.h>

int mySqrt(int x);

int main() {
    long long x = 2147395600;
    long long sqrt = mySqrt(x);
    printf("%d", sqrt);
    return 0;
}

int mySqrt(int x) {
    if (x == 0) return 0;
    long long i = 1;
    while (i*i <= x) {
        i++;
    }
    i--;
    return i;
}