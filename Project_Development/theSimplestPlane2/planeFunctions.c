#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

//函数外全局变量
int height, width;    /* 游戏画面尺寸 */
int position_x, position_y;     /* 坐标 */
int bullet_x, bullet_y;
int enemy_x, enemy_y;
int score;

void gotoxy(int x, int y) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}

void HideCursor() {     /* 此函数用于隐藏光标。执行一次就可以隐藏 */
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};   /* 第二个值为零表示隐藏光标 */
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void startup() {
    height = 18;
    width = 120;

    position_x = height/2;
    position_y = width/2;

    bullet_y = position_y;
    bullet_x = -1;

    enemy_x = 0;
    enemy_y = 2;

    score = 0;

    HideCursor();
}

void show() { /* 显示画面 */
    int i, j;

    gotoxy(0, 0); /* 光标移动到原点位置，以下重画清屏 */

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if ((i == position_x) && (j == position_y)) {
                printf("*");
            } else if ((i == bullet_x) && (j == bullet_y)) {
                printf("|");
            } else if ((i == enemy_x) && (j == enemy_y)) {
                printf("@");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("SCORE: %d\n", score);
}

void updateWithoutInput() {

    if ((bullet_x == enemy_x) && (bullet_y == enemy_y)) {
        score++;
        enemy_x = 0;
        enemy_y = rand() % width;
        bullet_x = -1;
    }
    
    if (bullet_x > -1) {
        bullet_x--;
    }
    static int speed = 0;   /* 多线程的思想!!! */
    if (speed < 20) {
        speed++;
    } 
    if (enemy_x > height) {
        enemy_x = 0;
        enemy_y = rand() % width;
    } else {
        if (speed == 20) {
            enemy_x++;
            speed = 0;
        }
    }
    //Sleep(150);      /* ms  该函数在 windows.h 下 */
}

void updateWithInput() {
    char input;

    if (kbhit()) {
        input = getch();

        if (input == 's') position_x++;
        if (input == 'w') position_x--;
        if (input == 'a') position_y--;
        if (input == 'd') position_y++;
        if (input == ' ') {
            bullet_x = position_x - 1;
            bullet_y = position_y;
        }
    }
}
