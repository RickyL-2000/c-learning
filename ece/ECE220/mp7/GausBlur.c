#include "GausBlur.h"
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)


int main() {
    //* initialize filters *//
    int i, j;
    double sigma = 0.3;
    int radius = getRadius(sigma);
    int filterSize = (2*radius+1) * (2*radius+1);
    double *filter = (double*) malloc (sizeof(double)*filterSize);
    calculateGausFilter(filter, sigma);
    printf("Filter: \n");
    for (i = 0; i < radius*2+1; i++) {
        for (j = 0; j < radius*2+1; j++) {
            printf("%f  ", filter[(radius*2+1)*i + j]);
        }
        printf("\n");
    }


    int height = 6, width = 6;
    uint8_t *outChannel = (uint8_t*) malloc (sizeof(uint8_t)*height*width);
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            outChannel[width*i + j] = 0;
        }
    }
    uint8_t channel[36] = {
        1, 2, 3, 4, 3, 2,
        2, 3, 4, 5, 4, 3,
        3, 4, 5, 6, 5, 4,
        4, 5, 6, 7, 6, 5, 
        3, 4, 5, 6, 5, 4,
        2, 3, 4, 5, 4, 3,       
    };
    convolveImage(channel, outChannel, filter, radius, width, height);
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d ", outChannel[width*i + j]);
        }
        printf("\n");
    }

    return 0;
}


int getRadius(double sigma)
{
    return ceil(3*sigma);
}


void calculateGausFilter(double *gausFilter,double sigma)
{
    //* calculation convenience *//
    double k = 1/(sqrt(2*M_PI*sigma*sigma));
    double m = -1/(2*sigma*sigma);
    //* filter data *//
    int radius = getRadius(sigma);
    int x, y, i, j, length = radius*2+1;
    //* shift the coordinate *//
    for (i = 0; i < length; i++) {
        for (j = 0; j < length; j++) {
            x = (j - radius < 0) ? (radius - j) : (j - radius);
            y = (i - radius < 0) ? (radius - i) : (i - radius);
            gausFilter[length*i + j] = k*exp(m*(x*x + y*y));
        }
    }
    //* calculate the weight *//
    double weight = 0;
    for (i = 0; i < length; i++) {
        for (j = 0; j < length; j++) {
            weight += gausFilter[length*i + j];
        }
    }
    //* normallization *//
    for (i = 0; i < length; i++) {
        for (j = 0; j < length; j++) {
            gausFilter[length*i + j] /= weight;
        }
    }
    return;
}


uint8_t convolve(uint8_t *channel, 
                 const double *filter, int radius, 
                 int width, int height,
                 int x, int y)
{
    uint8_t result;
    double temp = 0;
    int i, j;
    for (i = 0; i < radius*2+1; i++) {
        for (j = 0; j < radius*2+1; j++) {
            //* Consider the boundary case *//
            if ((x + i < radius) || (x + i > radius + height-1) || 
                (y + j < radius) || (y + j > radius + width-1)) {
                    temp += 0;   //* plus 0 *//
            } else
            temp += filter[(2*radius+1)*i + j] * channel[width*(x-radius+i) + y-radius+j];
        }
    }
    //* manipulate the upper and lower bound *//
    result = (int)max(min(temp, 255), 0);
    
    return result;
}


void convolveImage(uint8_t *inRed,uint8_t *outRed,const double *filter,
                   int radius,int width,int height)
{
    //* this i, j is to describe the kernel, not the image *//
    int i, j;
    //* calculate all the convolved data in three channels *//
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            outRed[width*i + j] = convolve(inRed, filter, radius, width, height, i, j);
        }
    }
    return;
}
