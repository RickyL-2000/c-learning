#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int getRadius(double sigma);
void calculateGausFilter(double *gausFilter,double sigma);
uint8_t convolve(uint8_t *channel, 
                 const double *filter, int radius, 
                 int width, int height,
                 int x, int y);
void convolveImage(uint8_t *inRed, uint8_t *outRed,const double *filter,
                   int radius,int width,int height);
