#include <stdio.h>
#include <stdlib.h>
#include "maze.h"


/*
 * createMaze -- Creates and fills a maze structure from the given file
 * INPUTS:       fileName - character array containing the name of the maze file
 * OUTPUTS:      None 
 * RETURN:       A filled maze structure that represents the contents of the input file
 * SIDE EFFECTS: None
 */
maze_t * createMaze(char* filename)
{
    FILE* mazeData = fopen("maze3.txt", "r");
    if (mazeData == NULL) return NULL;

    //* allocate memory for structure maze*//
    maze_t* maze;
    maze = (maze_t*) malloc (sizeof (maze_t));
    
    fscanf(mazeData, "%d %d\n", &(maze->width), &(maze->height));

    //* allocate memory for the array in maze *//
    maze->cells = (char**) malloc (maze->height * sizeof (char*));
    int i, j;
    for (i = 0; i < maze->height; i++) {
        (maze->cells)[i] = (char*) malloc (maze->width * sizeof (char));
    }

    //* store the maze data to the structure *//
    char ch;
    for (i = 0; i < maze->height; i++) {
        for (j = 0; j < maze->width; j++) {
            ch = fgetc(mazeData);
            if (ch == EOF) break;
            if (ch == '\n') {   //* caution! fgetc() will capture '\n'! TODO: changed *//
                ch = fgetc(mazeData);
            }
            maze->cells[i][j] = ch;

            //* process the start and end point *//
            if (ch == START) {
                maze->startRow = i;
                maze->startColumn = j;
            } else if (ch == END) {
                maze->endRow = i;
                maze->endColumn = j;
            }
        }
    }

    fclose(mazeData);
    
    return maze;
}

/*
 * destroyMaze -- Frees all memory associated with the maze structure, including the structure itself
 * INPUTS:        maze -- pointer to maze structure that contains all necessary information 
 * OUTPUTS:       None
 * RETURN:        None
 * SIDE EFFECTS:  All memory that has been allocated for the maze is freed
 */
void destroyMaze(maze_t * maze)
{
    int i;
    for (i = 0; i < maze->height; i++) {
        free(maze->cells[i]);   //* free the arrays of data respectively *//
    }
    free(maze->cells);  //* free the array of first-order pointes *//
    free(maze); //* free the structure *//
}

/*
 * printMaze --  Prints out the maze in a human readable format (should look like examples)
 * INPUTS:       maze -- pointer to maze structure that contains all necessary information 
 *               width -- width of the maze
 *               height -- height of the maze
 * OUTPUTS:      None
 * RETURN:       None
 * SIDE EFFECTS: Prints the maze to the console
 */
void printMaze(maze_t * maze)
{
    int i, j;
    for (i = 0; i < maze->height; i++) {
        for (j = 0; j < maze->width; j++) {
            printf("%c", maze->cells[i][j]);
        }
        //* now control the boundary *//
        if (i == maze->height-1 && j == maze->width) break; //* reach the end of the data *//
        printf("\n");
    }
}

/*
 * solveMazeDFS -- recursively solves the maze using depth first search,
 * INPUTS:               maze -- pointer to maze structure with all necessary maze information
 *                       col -- the column of the cell currently beinging visited within the maze
 *                       row -- the row of the cell currently being visited within the maze
 * OUTPUTS:              None
 * RETURNS:              0 if the maze is unsolvable, 1 if it is solved
 * SIDE EFFECTS:         Marks maze cells as visited or part of the solution path
 */ 
int solveMazeDFS(maze_t * maze, int col, int row)
{
    static int turns = 0;       //*TODO changed*//
    turns++;
    if (row < 0 || row >= maze->height || col < 0 || col >= maze->width)
        return 0;
    if (maze->cells[row][col] == '%' || maze->cells[row][col] == '.' || maze->cells[row][col] == '~')
        return 0;
    if (maze->cells[row][col] == 'S' && turns != 1)
        return 0;
    if (maze->cells[row][col] == END)
        return 1;

    if (maze->cells[row][col] != START)
        maze->cells[row][col] = '.';
    if (solveMazeDFS(maze, col-1, row)) return 1;
    if (solveMazeDFS(maze, col+1, row)) return 1;
    if (solveMazeDFS(maze, col, row-1)) return 1;
    if (solveMazeDFS(maze, col, row+1)) return 1;
    if (maze->cells[row][col] != START)
        maze->cells[row][col] = '~';

    return 0;
}

int main() {
    printf("Creating new maze:\n");
    maze_t* maze = createMaze("maze1.txt");

    printf("\nUnsolved maze:\n");
    printMaze(maze);

    if(solveMazeDFS(maze, maze->startColumn, maze->startRow))
    {
        printf("\nSolved maze:\n");
        printMaze(maze);
    }
    else
    {
        printf("\nMaze is unsolvable\n");
    }

    printf("\nDestroying maze\n");

    destroyMaze(maze);
 
    return 0;

}