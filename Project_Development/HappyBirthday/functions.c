#include "functions.h"

//********************声明实例**********************//
Screen *scr;
Character *xixi;


//********************基本函数**********************//
void initialize() {
    /* screen initialize */
    screenInit(scr);
}

//*********************嘻嘻***********************//
//* 生成嘻嘻的样子 *//
void constructXixi() {
    characterInit(&xixi, 9, 3, 23, 44); //* TODO:嘻嘻的各项参数先保留 *//
    int i, j1, j2;
    char star = '*';
    /*
     * origin: i0 = 9, j0 = 3
     * i = 0    j = 13
     * i = 1    j = 13
     * i = 2    j = 13
     * i = 3    j = 9~18
     * i = 4    j = 13
     * i = 5    j = 13
     * i = 6    j = 11~16
     * i = 7    j = 0~3
     * i = 8    j = 0, 3, 10~16
     * i = 9    j = 0, 3, 10, 16
     * i = 10   j = 0, 3, 10, 16
     * i = 11   j = 0, 3, 10~16
     * i = 12   j = 0, 3, 17
     * i = 13   j = 0, 3, 8, 9, 16, 17
     * i = 14   j = 0~3, 10, 11, 15
     * i = 15   j = 11, 14
     * i = 16   j = 5~20
     * i = 19   j = 9~18
     * i = 20   j = 9, 18
     * i = 21   j = 9, 18
     * i = 22   j = 9, 18
     * i = 23   j = 9~18
     * */
    for (i = 0, j1 = 13, j2 = j1+25; i < 7; i++) {
        (xixi->frame)[xixi->w*i + j1] = star;
        (xixi->frame)[xixi->w*i + j2] = star;
    }
    for (i = 3, j1 = 9, j2 = j1+25; j1 <= 18; j1++) {
        (xixi->frame)[xixi->w*i + j1] = star;
        (xixi->frame)[xixi->w*i + j2] = star;
    }
    for (i = 6, j1 = 11, j2 = j1+25; j1 <= 16; j1++) {
        (xixi->frame)[xixi->w*i + j1] = star;
        (xixi->frame)[xixi->w*i + j2] = star;
    }
    for (i = 7, j1 = 0, j2 = j1+25; j1 <= 3; j1++) {
        (xixi->frame)[xixi->w*i + j1] = star;
        (xixi->frame)[xixi->w*i + j2] = star;
    }
    for (i = 14, j1 = 0, j2 = j1+25; j1 <= 3; j1++) {
        (xixi->frame)[xixi->w*i + j1] = star;
        (xixi->frame)[xixi->w*i + j2] = star;
    }
    (xixi->frame)[xixi->w*14 + 10] = star;
    (xixi->frame)[xixi->w*14 + 11] = star;
    (xixi->frame)[xixi->w*14 + 15] = star;
    (xixi->frame)[xixi->w*14 + 10+25] = star;
    (xixi->frame)[xixi->w*14 + 11+25] = star;
    (xixi->frame)[xixi->w*14 + 15+25] = star;
    for (i = 8, j1 = 0, j2 = j1+25; i <= 13; i++) {
        (xixi->frame)[xixi->w*i + j1] = star;
        (xixi->frame)[xixi->w*i + j2] = star;
    }
    for (i = 8, j1 = 3, j2 = j1+25; i <= 13; i++) {
        (xixi->frame)[xixi->w*i + j1] = star;
        (xixi->frame)[xixi->w*i + j2] = star;
    }
    for (i = 8, j1 = 10, j2 = j1+25; j1 <= 16; j1++) {
        (xixi->frame)[xixi->w*i + j1] = star;
        (xixi->frame)[xixi->w*i + j2] = star;
    }
    for (i = 11, j1 = 10, j2 = j1+25; j1 <= 16; j1++) {
        (xixi->frame)[xixi->w*i + j1] = star;
        (xixi->frame)[xixi->w*i + j2] = star;
    }
    for (i = 9, j1 = 10, j2 = j1+25; i <= 10; i++) {
        (xixi->frame)[xixi->w*i + j1] = star;
        (xixi->frame)[xixi->w*i + j2] = star;
    }
    for (i = 9, j1 = 16, j2 = j1+25; i <= 10; i++) {
        (xixi->frame)[xixi->w*i + j1] = star;
        (xixi->frame)[xixi->w*i + j2] = star;
    }
    (xixi->frame)[xixi->w*12 + 17] = star;
    (xixi->frame)[xixi->w*13 + 8] = star;
    (xixi->frame)[xixi->w*13 + 9] = star;
    (xixi->frame)[xixi->w*13 + 16] = star;
    (xixi->frame)[xixi->w*13 + 17] = star;
    (xixi->frame)[xixi->w*13 + 8] = star;
    (xixi->frame)[xixi->w*15 + 11] = star;
    (xixi->frame)[xixi->w*15 + 14] = star;
    (xixi->frame)[xixi->w*12 + 17 + 25] = star;
    (xixi->frame)[xixi->w*13 + 8 + 25] = star;
    (xixi->frame)[xixi->w*13 + 9 + 25] = star;
    (xixi->frame)[xixi->w*13 + 16 + 25] = star;
    (xixi->frame)[xixi->w*13 + 17 + 25] = star;
    (xixi->frame)[xixi->w*13 + 8 + 25] = star;
    (xixi->frame)[xixi->w*15 + 11 + 25] = star;
    (xixi->frame)[xixi->w*15 + 14 + 25] = star;
    for (i = 16, j1 = 5, j2 = j1+25; j1 <= 20; j1++) {
        (xixi->frame)[xixi->w*i + j1] = star;
        (xixi->frame)[xixi->w*i + j2] = star;
    }
    for (i = 19, j1 = 9, j2 = j1+25; j1 <= 18; j1++) {
        (xixi->frame)[xixi->w*i + j1] = star;
        (xixi->frame)[xixi->w*i + j2] = star;
    }
    for (i = 22, j1 = 9, j2 = j1+25; j1 <= 18; j1++) {
        (xixi->frame)[xixi->w*i + j1] = star;
        (xixi->frame)[xixi->w*i + j2] = star;
    }
    for (i = 20, j1 = 9, j2 = j1+25; i <= 22; i++) {
        (xixi->frame)[xixi->w*i + j1] = star;
        (xixi->frame)[xixi->w*i + j2] = star;
    }
    for (i = 20, j1 = 18, j2 = j1+25; i <= 22; i++) {
        (xixi->frame)[xixi->w*i + j1] = star;
        (xixi->frame)[xixi->w*i + j2] = star;
    }
}