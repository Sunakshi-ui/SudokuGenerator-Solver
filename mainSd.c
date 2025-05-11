#include <stdio.h>
#include "gameSd.h"
#include <unistd.h> 
#include "stack.h"

int main() {
    int grid[SIZE][SIZE] = {0};
    Cell* emptyCells = NULL;

    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            addCell(&emptyCells, row, col);
        }
    }
    generateGrid(grid, emptyCells);
    int numToRemove = 40; 
    removeNumbers(grid, numToRemove, &emptyCells);

    printf("\n________________________WELCOME_TO_THE_SUDOKU_GAME________________________\n");
    printf("\nSelect one of the following:\n1. Get a sudoku puzzle.\n2. Provide your puzzle and get its solution.\n");
    int choice = 0;
    char symbols[] = {'^', 'o'};  // Array holding ASCII characters
    for (int i = 0; i < 3; i++) { 
        printf("\rThink wisely before choosing (%c_%c)", symbols[i % 2],symbols[i % 2]);  // Overwrites previous output
        fflush(stdout); // Flush the output buffer to ensure immediate display update
        sleep(1); // Wait for 1 second
    }
    printf("\nEnter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nSudoku Puzzle:\n");
        printGrid(grid);
        int duration;
    	printf("  =====\nEnter the timer duration in seconds: ");
  	scanf("%d", &duration);

    	printf("Starting the timer...\n");
	startTimer(duration);
	printf("  =====\n");


    } else if (choice == 2) {
	printf("_____________________________________\n");
        printf("Enter your Sudoku puzzle row by row (0 for empty cells):\n");
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                scanf("%d", &grid[row][col]);
            }
        }
	printf("\n_____________________________________\n");
    }

    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (grid[row][col] != 0) {
                int num = grid[row][col];
                int gridIndex = getGridIndex(row, col);
                rowMask[row][num] = true;
                colMask[col][num] = true;
                gridMask[gridIndex][num] = true;
            }
        }
    }

    if (solveSudoku(grid, 0, 0)) {
         
        printf("Enter 1 to see the solution: ");
        char enter;
        scanf(" %c", &enter);
        printf("Solved Sudoku:\n");
        printGrid(grid);
    } else {
        printf("No solution exists.\n");
    }
    return 0;
}

