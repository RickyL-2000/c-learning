#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    int i, j;
    int x = 10;
    int y = 5;
    char input;

    while (1) {
        system("cls");
        for (i = 0; i < x; i++){
            printf("\n");
        }
        for (j = 0; j < y; j++) {
            printf(" ");
        }
        printf("*\n");

        //scanf("%c", &input);
        input = getch();
        if (input == 's') x++;
        if (input == 'w') x--;
        if (input == 'a') y--;
        if (input == 'd') y++;
    }

    return 0;
}