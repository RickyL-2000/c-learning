/* Implement pow(x, n), which calculates x raised to the power n (xn).*/

#include <stdio.h>
#include <math.h>

double myPow(double x, int n);

int main() {}

double myPow(double x, int n) {
    double result = 1;
    if (x == 0) return 0.0;
    if (n == 0) return 1.0;
    if (n > 0) {
        int i;
        for (i = 0; i < n; i++) {
            result *= x;
        }
        return result;
    } else {
        n = -n;
        int i;
        for (i = 0; i < n; i++) {
            result *= x;
        }
        return 1/result;
    }
    return;
}