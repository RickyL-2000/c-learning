#ifndef STDLIB_H
#define STDLIB_H 1

#include <stdlib.h>

#endif

#ifndef STDIO_H
#define STDIO_H 1

#include <stdio.h>

#endif


//********************屏幕结构*********************//
typedef struct {
    int h, w;  /* 游戏画面尺寸 */
    char* frame;       /* 游戏画面数据 */
} Screen;

void screenInit(Screen *scr) {
    scr = (Screen*) malloc (sizeof(Screen));
    scr->h = 40;
    scr->w = 50;
    scr->frame = (char*) malloc (sizeof(char) * (scr->h * scr->w));    /* 不要忘了 '\0'(是否有必要？) */
    //(scr->frame)[scr->h * scr->w] = '\0';
    int i, j;
    for (i = 0; i < scr->h; i++) {
        for (j = 0; j < scr->w; j++) {
            (scr->frame)[scr->w * i + j] = ' ';
        }
    }
}

void show(const Screen *scr) {
    system("cls");
    int i, j;
    for (i = 0; i < scr->h; i++) {
        for (j = 0; j < scr->w; j++) {
            printf("%c", (scr->frame)[scr->w*i+j]);
        }
        printf("\n");
    }
}

//********************图案结构**********************//
typedef struct {
    int x, y;   /* 该文字的位置，取该图案的左上角 */
    int h, w;   /* 该文字的大小 */
    char* frame;    /* 该文字的画面数据，以该文字的位置为(0,0)位置 */
} Character;

//* FIXME: 为什么这个地方传结构体参数的时候要传指针的指针？这个指针难道不是全局变量吗？*//
void characterInit(Character** ch, int x, int y, int h, int w) {
    //* TODO: 补上对长度范围的限定! *//
    *ch = (Character*) malloc (sizeof(Character));
    (*ch)->x = x;
    (*ch)->y = y;
    (*ch)->h = h;
    (*ch)->w = w;
    (*ch)->frame = (char*) malloc (sizeof(char) * (*ch)->h * (*ch)->w);
    int i, j;
    for (i = 0; i < (*ch)->h; i++) {
        for (j = 0; j < (*ch)->w; j++) {
            ((*ch)->frame)[(*ch)->w * i + j] = ' ';
        }
    }
}

//* 该函数对图案的显示是有图层顺序的，因为会无条件修改原值 *//
void characterSend(const Character** ch, Screen** scr) {
    int i, j;
    for (i = 0; i < (*ch)->h; i++) {
        for (j = 0; j < (*ch)->w; j++) {
            ((*scr)->frame)[(*scr)->w*(i+(*ch)->x) + j+(*ch)->y] = 
                ((*ch)->frame)[(*ch)->w*i + j];
        }
    }
}