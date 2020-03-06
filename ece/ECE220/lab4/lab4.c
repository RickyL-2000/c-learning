#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846

double sin(double x);

int main()
{
    /* declarte variables */
    int N, i;
    double x, f, omega1, omega2;
    /* prompt user for input */
    printf("Please enter the N, omega1 and omega2 in order: ");
    /* get user input */
    scanf("%d%lf%lf", &N, &omega1, &omega2);
    //printf("%d %lf %lf", N, omega1, omega2);
    /* for i from 0 to n(?) */
    for (i = 0; i < N; i++) {
        /* compute and print x_i and f(x_i) */
        x = i*M_PI/(N-1);
        f = sin(omega1*x) + 0.5*sin(omega2*x);
        printf("%f %f\n", x, f);
    }
    /* exit the program */
    return 0;
}

