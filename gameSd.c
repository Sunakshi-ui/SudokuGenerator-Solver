#include "gameSd.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to create a new linked list node
Cell* createNode(int row, int col) {
    Cell* newNode = (Cell*)malloc(sizeof(Cell));
    newNode->row = row;
    newNode->col = col;
    newNode->next = NULL;
    return newNode;
}

// Function to add a cell to the linked list
void addCell(Cell** head, int row, int col) {
    Cell* newNode = createNode(row, col);
    newNode->next = *head;
    *head = newNode;
}

// Function to remove a cell from the linked list
void removeCell(Cell** head, int row, int col) {
    Cell *temp = *head, *prev = NULL;

    while (temp != NULL) {
        if (temp->row == row && temp->col == col) {
            if (prev == NULL) {
                *head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

// Function to print the Sudoku grid with separators
void printGrid(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        if (row % 3 == 0 && row != 0) {
            // Print horizontal separator after every 3 rows
            printf("---------------------\n");
        }

        for (int col = 0; col < SIZE; col++) {
            if (col % 3 == 0 && col != 0) {
                // Print vertical separator after every 3 columns
                printf("| ");
            }
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Function to check if placing a number is valid
bool isValid(int grid[SIZE][SIZE], int row, int col, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false; // Conflict in row or column
        }
    }

    int startRow = (row / 3) * 3, startCol = (col / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[startRow + i][startCol + j] == num) {
                return false; // Conflict in subgrid
            }
        }
    }
    return true;
}

// Function to generate a complete Sudoku grid using backtracking
bool generateGrid(int grid[SIZE][SIZE], Cell* emptyCells) {
    if (emptyCells == NULL) {
        return true; // Grid completed
    }

    int row = emptyCells->row;
    int col = emptyCells->col;
    Cell* next = emptyCells->next;

    for (int num = 1; num <= SIZE; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;
            if (generateGrid(grid, next)) {
                return true;
            }
            grid[row][col] = 0; // Backtrack
        }
    }
    return false; // No solution found
}

// Function to remove numbers from the grid to create a puzzle
void removeNumbers(int grid[SIZE][SIZE], int numToRemove, Cell** emptyCells) {
    srand(time(NULL));
    while (numToRemove > 0) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;

        if (grid[row][col] != 0) {
            grid[row][col] = 0;
            addCell(emptyCells, row, col);
            numToRemove--;
        }
    }
}

// Boolean arrays to track constraints for rows, columns, and subgrids
bool rowMask[SIZE][SIZE + 1];  // rowMask[row][num]: true if 'num' is in the row
bool colMask[SIZE][SIZE + 1];  // colMask[col][num]: true if 'num' is in the column
bool gridMask[SIZE][SIZE + 1]; // gridMask[grid][num]: true if 'num' is in the subgrid

// Function to calculate the 3x3 subgrid index based on row and column
int getGridIndex(int row, int col) {
    return (row / 3) * 3 + (col / 3);
}

// Function to solve the Sudoku using backtracking
bool solveSudoku(int grid[SIZE][SIZE], int row, int col) {
    if (row == SIZE) {
        return true; // Puzzle solved
    }

    int nextRow = (col == SIZE - 1) ? row + 1 : row;
    int nextCol = (col == SIZE - 1) ? 0 : col + 1;

    if (grid[row][col] != 0) {
        return solveSudoku(grid, nextRow, nextCol);
    }

    for (int num = 1; num <= SIZE; num++) {
        int gridIndex = getGridIndex(row, col);

        if (!rowMask[row][num] && !colMask[col][num] && !gridMask[gridIndex][num]) {
            grid[row][col] = num;
            rowMask[row][num] = true;
            colMask[col][num] = true;
            gridMask[gridIndex][num] = true;

            if (solveSudoku(grid, nextRow, nextCol)) {
                return true;
            }

            grid[row][col] = 0;
            rowMask[row][num] = false;
            colMask[col][num] = false;
            gridMask[gridIndex][num] = false;
        }
    }

    return false; // No valid number can be placed
}

