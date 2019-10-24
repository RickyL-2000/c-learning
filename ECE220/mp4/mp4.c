#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LOW_TOLERANCE 0.000001
#define UP_ITERATION  10000

/***************** function prototypes ******************/
double abs_double(double y);
double fx_val(double a, double b, double c, double d, double e, double x);
double fx_dval(double a, double b, double c, double d, double e, double x);
double fx_ddval(double a, double b, double c, double d, double e, double x);
double newrfind_halley(double a, double b, double c, double d, double e, double x);
int rootbound(double a, double b, double c, double d, double e, double r, double l);
int find_sign_variat(double a, double b, double c, double d, double e, double o);

/******************** main function *********************/
int main(int argc, char **argv)
{
    double a, b, c, d, e, l, r;
    FILE *in;

    if (argv[1] == NULL) 
    {
        printf("You need an input file.\n");
        return -1;
    }

    /* this code reads input from a file  -- do not modify it! */
    in = fopen(argv[1], "r");
    if (in == NULL)
        return -1;

    fscanf(in, "%lf", &a);
    fscanf(in, "%lf", &b);
    fscanf(in, "%lf", &c);
    fscanf(in, "%lf", &d);
    fscanf(in, "%lf", &e);
    fscanf(in, "%lf", &l);
    fscanf(in, "%lf", &r);

    fclose(in);
    
    /* find the upperbound */
    int upperbound = rootbound(a, b, c, d, e, r, l);
    if (upperbound == 0) {
        printf("The polynomial has no roots in the given interval.");
        return 0;
    }
    /* find the root for every x in the interval [l, r] */
    int i, found = 0;
    double x, root, newroot;
    for (x = l; x <= r; x += 0.5) {
        root = x;
        for (i = 0; i < UP_ITERATION; ++i) {    /* control the upper bound of iteration */
            newroot = newrfind_halley(a, b, c, d, e, root);
            if (abs_double(root - newroot) <= LOW_TOLERANCE) {
                /* if the difference between the values from successive iterations is within tolerance */
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

/***************subfunctions***************/
/* calculate the absolute value of a double value */
double abs_double(double y)
{
    if (y < 0)  return -y;
    return y;
}

/* calculate the parametrics of fx */
double fx_val(double a, double b, double c, double d, double e, double x)
{
    double value;
    value = a*x*x*x*x + b*x*x*x + c*x*x + d*x + e;
    return value;
}

/* calculate the parametrics of the derivative of fx */
double fx_dval(double a, double b, double c, double d, double e, double x)
{
    double dval;
    dval = 4*a*x*x*x + 3*b*x*x + 2*c*x + d;
    return dval;
}

/* calculate the parametrics of the second order derivative of fx */
double fx_ddval(double a, double b, double c, double d, double e, double x)
{
    double ddval;
    ddval = 12*a*x*x + 6*b*x + 2*c;
    return ddval;
}

/* calculate the new x found using the halley method */
/* use the function fx, fx_d, fx_dd defined before */
double newrfind_halley(double a, double b, double c, double d, double e, double x)
{
    double value,
           fx = fx_val(a, b, c, d, e, x),
           fx_d = fx_dval(a, b, c, d, e, x),
           fx_dd = fx_ddval(a, b, c, d, e, x);
    value = x - (2*fx*fx_d / (2*fx_d*fx_d - fx*fx_dd));
    return value;
}

/* use Budan's Theorem to find the upper bound on the number of roots in the given interval */
/* using an extra function find_sign_variat() to simplify the process */
int rootbound(double a, double b, double c, double d, double e, double r, double l)
{
    int bound = find_sign_variat(a, b, c, d, e, l) - find_sign_variat(a, b, c, d, e, r);
    if (bound < 0) return -bound;
    return bound;
}

/* an extra function, used to calculate the sign variation of a given polynomial */
int find_sign_variat(double a, double b, double c, double d, double e, double o) {     /* o means the offset (like l and r) */
    /* update the a~e value by plug in o */
    double fa = a,
           fb = 4*a*o + b,
           fc = 6*a*o*o + 3*b*o + c,
           fd = 4*a*o*o*o + 3*b*o*o + 2*c*o + d,
           fe = a*o*o*o*o + b*o*o*o + c*o*o + d*o + e;
    /* sum up the times that signs variate */
    int sum = 0;
    if (fa*fb < 0) sum++;
    if (fb*fc < 0) sum++;
    if (fc*fd < 0) sum++;
    if (fd*fe < 0) sum++;
    return sum;
}