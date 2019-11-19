//* FIXME: logical bug here!!! *//

#include <stdio.h>
char* Queen(N);
int isValid(char* board, int N, const int row, const int col);
int QueenSearch(char* board, int N, int row);
void printBoard(char* board, int N);


char* Queen(N) {
    char* board;
    board = (char*) malloc (sizeof (char)*N*N);
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            *(board+i*N+j) = '-';
        }
    }
    // *board = '+';
    QueenSearch(board, N, 0);
    return board;
}

int isValid(char* board, int N, const int row, const int col) {
    if (row == 0) return 1;
    int i, j;
    for (i = row-1, j = col; i >= 0; i--) {
        if (*(board + i*N + j) == '+') return 0;
    }
    i = row;
    j = col;
    while (i-1>=0 && j-1>=0) {
        i--;
        j--;
        if (*(board + i*N + j) == '+') return 0;
    }
    i = row;
    j = col;
    while (i+1<N && j+1<N) {
        i++;
        j++;
        if (*(board + i*N + j) == '+') return 0;   
    }
    return 1;
}

int QueenSearch(char* board, int N, int row) {
    if (row == N-1) return 1;
    int col;
    for (col = 0; col < N; col++) {
        if (isValid(board, N, row, col)) {
            *(board + row*N + col) = '+';
            if (QueenSearch(board, N, row+1)) return 1;
            *(board + row*N + col) = '-';
        }
    }
    return 0;
}

void printBoard(char* board, int N) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%c", *(board+i*N+j));
        }
        printf("\n");
    }
}

int main() {
    int N = 10;
    char * board = Queen(N);
    printBoard(board, N);
    free(board);
    return 0;
}