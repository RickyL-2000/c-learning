#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M_PI 3.14159265358979323846

double sqrt(double x);
double sin(double x);

int main(int argc, char **argv) {
    double omega1, omega2, omegac, T, dt;
    int N, method;
    FILE *in;

    int i;
    double Vout1new = 0.0, Vout1cur = 0.0, Vout1prev = 0.0,
           Vout2new = 0.0, Vout2cur = 0.0, Vout2prev = 0.0;
        
    /* Open the file and scan the input variables. */
    if (argv[1] == NULL) {
        printf("You need an input file.\n");
        return -1;
    }

    if ((in = fopen(argv[1], "r")) == NULL) {
        printf("Unable to open specified file %s\n", argv[1]);
        return -1;
    }

    fscanf(in, "%lf", &omega1);
    fscanf(in, "%lf", &omega2);
    fscanf(in, "%lf", &omegac);
    fscanf(in, "%d", &method);

    fclose(in);

    T = 3 * 2 * M_PI / omega1; 	        /* Total time */
    N = 20 * T / (2 * M_PI / omega2);   /* Total number of time steps */
    dt = T / N;                         /* Time step ("delta t") */

    /* Method number 1 corresponds to the finite difference method. */
    if (method == 1) {
        /* Some massive parameter */
        double k = 1 / ( 1/(sqrt(2)*dt*omegac) + 1/(dt*dt*omegac*omegac) ),
               a = 2/(dt*dt*omegac*omegac) - 1,
               b = 1/(sqrt(2)*dt*omegac) - 1/(dt*dt*omegac*omegac);
        Vout1new = k*(a*Vout1cur + b*Vout1prev + sin(0) + 0.5*sin(0));  /* Vout[1] */
        /* FIXME: The "n" in sin may cause problems.*/
        printf("%Lf\n%Lf\n", Vout1cur, Vout1new);
        Vout1cur = Vout1new;                                            /* update the current value */
        for (i = 1; i < N-1; ++i) {
            Vout1new = k*(a*Vout1cur + b*Vout1prev + sin(omega1*i*dt) + 0.5*sin(omega2*i*dt));
            Vout1prev = Vout1cur;
            Vout1cur = Vout1new;
            printf("%Lf\n", Vout1cur);
        }
    }
    else if (method == 2) {
        printf("%Lf\n", Vout1prev);
        double k1, k2, k3, k4, m1, m2, m3, m4;
        for (i = 0; i < N-1; ++i) {
            /* massive calculation */
            k1 = Vout2cur;
            k2 = Vout2cur + k1*dt/2;
            k3 = Vout2cur + k2*dt/2;
            k4 = Vout2cur + k3*dt;
            Vout1new = Vout1cur + dt*(k1 + 2*k2 + 2*k3 + k4)/6;
            m1 = omegac*omegac*(sin(omega1*i*dt) + 0.5*sin(omega2*i*dt)
                                - omegac*omegac*Vout1cur - omegac*sqrt(2)*Vout2cur);
            m2 = m1*(1 + dt/2);
            m3 = m1 + m2*dt/2;
            m4 = m1 + m3*dt;
            Vout2new = Vout2cur + dt*(m1 + 2*m2 + 2*m3 + m4)/6;
            /* variable updates */
            Vout1prev = Vout1cur;
            Vout1cur = Vout1new;
            Vout2prev = Vout2cur;
            Vout2cur = Vout2new;
            printf("%Lf\n", Vout1cur);
        }
    }
    else {
        printf("Incorrect method number.\n");
        return -1;
    }
    return 0;
}
