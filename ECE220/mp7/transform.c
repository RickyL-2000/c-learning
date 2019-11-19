#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void transformImage(uint8_t *inRed,uint8_t *outRed,double transform[2][3],int width,int height);
void nearestPixel(int pixelYTransform, int pixelXTransform, double transform[2][3],int *pixelY, int *pixelX, int width, int height);


int main() {
    uint8_t channel[36] = {
        0,0,1,1,0,0,
        0,0,1,1,0,0,
        0,0,1,1,0,0,
        0,0,1,1,0,0,
        0,0,1,1,0,0,
        0,0,1,1,0,0,
    };
    int width = 6, height = 6;
    int i, j;
    uint8_t *outChannel = (uint8_t*) malloc (sizeof(uint8_t)*height*width);
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            outChannel[width*i + j] = 0;
        }
    }
    double transform[2][3] = {
        {0.82, -0.57, 0},
        {0.57, 0.82, 0}
    };
    transformImage(channel, outChannel, transform, width, height);

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d  ", outChannel[width*i + j]);
        }
        printf("\n");
    }
    return 0;
}

void transformImage(uint8_t *inRed,uint8_t *outRed,double transform[2][3],int width,int height)
{
    int x=0, y=0, i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            nearestPixel(i, j, transform, &y, &x, width, height);
            if (x < 0 || y < 0 || x > width-1 || y > height-1) {
                outRed[width*i + j] = 0;
            } else {
                outRed[width*i + j] = inRed[width*y + x];
            }
        }
    }
    return;
}

void nearestPixel(int pixelYTransform, int pixelXTransform, double transform[2][3],int *pixelY, int *pixelX, int width, int height)
{
    //* calculation convenience *//
    double oldX, oldY;
    long newX = pixelXTransform - (width-1)/2,
        newY = - pixelYTransform + (height-1)/2;  //* TODO
    double k = 1/(transform[0][0]*transform[1][1] - transform[0][1]*transform[1][0]);
    double t1 = k*transform[1][1],
           t2 = -k*transform[0][1],
           t3 = -k*transform[1][0],
           t4 = k*transform[0][0];   //* this represents T^(-1) = {t1, t2, t3, t4}  which in this case is {2, 0, 0, 2} *//
    oldX = t1*(newX - transform[0][2]) + t2*(newY - transform[1][2]);
    oldY = t3*(newX - transform[0][2]) + t4*(newY - transform[1][2]);
    oldX += (width-1)/2;
    oldY = (height-1)/2 - oldY;

    *pixelX = (long)oldX;
    *pixelY = (long)oldY;

    return;
}
