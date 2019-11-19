#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "functions.c"

int main() {
    system("cls");
    initialize();
    constructXixi();
    characterSend(&xixi, &scr);
    Sleep(5000);
    return 0;
}