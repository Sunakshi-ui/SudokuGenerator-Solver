#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdbool.h>
#define SIZE 9

//linked list for generation
typedef struct Cell {
    int row;
    int col;
    struct Cell* next;
} Cell;
Cell* createNode(int row, int col);
void addCell(Cell** head, int row, int col);
void removeCell(Cell** head, int row, int col);

//step 1:
bool generateGrid(int grid[SIZE][SIZE], Cell* emptyCells);
//step 2:
void removeNumbers(int grid[SIZE][SIZE], int numToRemove, Cell** emptyCells);

//for solving
// step 1: boolean masking
bool rowMask[SIZE][SIZE + 1];  // rowMask[row][num]: true if 'num' is in the row
bool colMask[SIZE][SIZE + 1];  // colMask[col][num]: true if 'num' is in the column
bool gridMask[SIZE][SIZE + 1]; // gridMask[grid][num]: true if 'num' is in the subgrid
//step 2:
bool solveSudoku(int grid[SIZE][SIZE], int row, int col);

//common functions
bool isValid(int grid[SIZE][SIZE], int row, int col, int num);
int getGridIndex(int row, int col); 
void printGrid(int grid[SIZE][SIZE]);

#endif

