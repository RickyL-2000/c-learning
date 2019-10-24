#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LOW_TOLERANCE 0.000001
#define UP_ITERATION  10000

/* function prototypes */
double abs_double(double y);
double fx_val(double a, double b, double c, double d, double e, double x);
double fx_dval(double a, double b, double c, double d, double e, double x);
double fx_ddval(double a, double b, double c, double d, double e, double x);
double newrfind_halley(double a, double b, double c, double d, double e, double x);
int rootbound(double a, double b, double c, double d, double e, double r, double l);
int find_sign_variat(double a, double b, double c, double d, double e, double o);

int main(int argc, char **argv)
{
    double a = 3, 
           b = -8, 
           c = -2, 
           d = -5, 
           e = 6, 
           l = 0, 
           r = 5;
        
    int upperbound = rootbound(a, b, c, d, e, r, l);
    if (upperbound == 0) {
        printf("The polynomial has no roots in the given interval.");
        return 0;
    }
    int i, found = 0;
    double x, root, newroot;
    for (x = l; x <= r; x += 0.5) {
        root = x;
        for (i = 0; i < UP_ITERATION; ++i) {
            newroot = newrfind_halley(a, b, c, d, e, root);
            if (abs_double(root - newroot) <= LOW_TOLERANCE) {
                found = 1;
                break;
            }
            root = newroot;
        }
        if (found) printf("Root found: %f\n", newroot);
        else       printf("No roots found.\n");
    }
    return 0;
}

double abs_double(double y)
{
    if (y < 0)  return -y;
    return y;
}

double fx_val(double a, double b, double c, double d, double e, double x)
{
    double value;
    value = a*x*x*x*x + b*x*x*x + c*x*x + d*x + e;
    return value;
}

double fx_dval(double a, double b, double c, double d, double e, double x)
{
    double dval;
    dval = 4*a*x*x*x + 3*b*x*x + 2*c*x + d;
    return dval;
}

double fx_ddval(double a, double b, double c, double d, double e, double x)
{
    double ddval;
    ddval = 12*a*x*x + 6*b*x + 2*c;
    return ddval;
}

double newrfind_halley(double a, double b, double c, double d, double e, double x)
{
    double value,
           fx = fx_val(a, b, c, d, e, x),
           fx_d = fx_dval(a, b, c, d, e, x),
           fx_dd = fx_ddval(a, b, c, d, e, x);
    value = x - (2*fx*fx_d / (2*fx_d*fx_d - fx*fx_dd));
    return value;
}

int rootbound(double a, double b, double c, double d, double e, double r, double l)
{
    int bound = find_sign_variat(a, b, c, d, e, l) - find_sign_variat(a, b, c, d, e, r);
    if (bound < 0) return -bound;
    return bound;
}

int find_sign_variat(double a, double b, double c, double d, double e, double o) { 
    /* o means the offset */
    double fa = a,
           fb = 4*a*o + b,
           fc = 6*a*o*o + 3*b*o + c,
           fd = 4*a*o*o*o + 3*b*o*o + 2*c*o + d,
           fe = a*o*o*o*o + b*o*o*o + c*o*o + d*o + e;
    int sum = 0;
    if (fa*fb < 0) sum++;
    if (fb*fc < 0) sum++;
    if (fc*fd < 0) sum++;
    if (fd*fe < 0) sum++;
    return sum;
}