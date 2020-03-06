/* the coordinate can be represented by board[colSize * i + j] */

/*
 * countLiveNeighbor
 * Inputs:
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * row: the row of the cell that needs to count alive neighbors.
 * col: the col of the cell that needs to count alive neighbors.
 * Output:
 * return the number of alive neighbors. There are at most eight neighbors.
 * Pay attention for the edge and corner cells, they have less neighbors.
 */

int countLiveNeighbor(int *board, int boardRowSize, int boardColSize, int row, int col) {
    int count = 0;
    count += cellState(board, boardRowSize, boardColSize, row-1, col-1);
    count += cellState(board, boardRowSize, boardColSize, row-1, col);
    count += cellState(board, boardRowSize, boardColSize, row-1, col+1);
    count += cellState(board, boardRowSize, boardColSize, row, col-1);
    count += cellState(board, boardRowSize, boardColSize, row, col+1);
    count += cellState(board, boardRowSize, boardColSize, row+1, col-1);
    count += cellState(board, boardRowSize, boardColSize, row+1, col);
    count += cellState(board, boardRowSize, boardColSize, row+1, col+1);
    return count;
}
/*
 * Return the state of a specific cell
 */
int cellState(int *board, int boardRowSize, int boardColSize, int row, int col) {
    if (row < 0 || row > boardRowSize-1 || col < 0 || col > boardColSize) return 0;
    if (board[boardColSize*row + col]) return 1;
    return 0;
}

    /*
 * Update the game board to the next step.
 * Input: 
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * Output: board is updated with new values for next step.
 */
void updateBoard(int *board, int boardRowSize, int boardColSize) {
    int i, j;
    int* neighbors = (int *) malloc (boardRowSize * boardColSize * sizeof(int));
    for (i = 0; i < boardRowSize; i++) {
        for (j = 0; j < boardColSize; j++) {
            neighbors[boardColSize*i + j] = countLiveNeighbor(board, boardRowSize, boardColSize, i, j);
        }
    }
    for (i = 0; i < boardRowSize; i++) {
        for (j = 0; j < boardColSize; j++) {
            if (board[boardColSize*i + j] == 1) {   /* if the cell was alive last generation */
                if ((neighbors[boardColSize*i + j] < 2) || (neighbors[boardColSize*i + j] > 3)) {
                    board[boardColSize*i + j] = 0;
                }
            } else if (board[boardColSize*i + j] == 0) {    /* if the cell was dead */
                if (neighbors[boardColSize*i + j] == 3) {
                    board[boardColSize*i + j] = 1;
                }
            }
        }
    }
    free(neighbors);
    return;
}

/*
 * aliveStable
 * Checks if the alive cells stay the same for next step
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * Output: return 1 if the alive cells for next step is exactly the same with 
 * current step or there is no alive cells at all.
 * return 0 if the alive cells change for the next step.
 */
int aliveStable(int *board, int boardRowSize, int boardColSize) {
    int i, j, same = 1, allDead = 1;
    int* lastGeneration = (int *) malloc (boardRowSize * boardColSize * sizeof(int));
    for (i = 0; i < boardRowSize; i++) {
        for (j = 0; j < boardColSize; j++) {
            if (board[boardColSize*i + j]) allDead = 0;    /* not all dead */
            lastGeneration[boardColSize*i + j] = board[boardColSize*i + j];
        }
    }
    if (allDead) return 0;
    updateBoard(board, boardRowSize, boardColSize);
    for (i = 0; i < boardRowSize; i++) {
        if (!same) break;
        for (j = 0; j < boardColSize; j++) {
            if (board[boardColSize*i + j] == lastGeneration[boardColSize*i + j]) {
                continue;
            } else {
                same = 0;  /* they are not the same */
                break;
            }
        }
    }
    free(lastGeneration);
    return same;
}
