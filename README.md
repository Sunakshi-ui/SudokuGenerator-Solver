# Sudoku Generator and Solver

## Overview
This is a Sudoku game written in C, featuring both a generator and a solver. The generator uses a linked list approach, avoiding arrays, while the solver employs a boolean mask. Additionally, the game includes a timing mechanism implemented with a stack.

## File Structure
The project consists of the following key files:
- `mainSd.c` - Handles the main logic of the game, including user interaction.
- `gameSd.c` - Implements the Sudoku solver (using boolean masking) and generator (using linked lists).
- `gameSd.h` - Contains function declarations for the solver and generator.
- `stack.c` - Implements the timer using a stack.
- `stack.h` - Contains function declarations for the timing mechanism.

## Features
- **Sudoku Generator**: Creates a randomized Sudoku puzzle using linked lists.
- **Sudoku Solver**: Solves a given Sudoku puzzle using a boolean mask approach.
- **Game Timer**: Uses a stack-based mechanism to track the time spent solving a puzzle.

## Compilation & Execution
To build the project, use the following command:

```sh
gcc mainSd.c gameSd.c stack.c -o sudokuGame
./sudokuGame
```
## How to Play
- Run the game.
- Choose whether to generate a puzzle or solve one.
- If solving, input the puzzle.
- The program will solve the puzzle and display the solution.

## Dependencies
- Standard C library (stdio.h, stdlib.h, stdbool.h, time.h).
- Additional POSIX Library (unistd.h).
- Ensure you have a C compiler (such as GCC).

## Future Enhancements
- By using pthread.h, we can also stop the timer and then save the time taken to solve the sudoku.
- Improved puzzle generation logic.
- Enhanced graphical interface (CLI or GUI).
- Additional difficulty levels.

License:
This project is open-source. Feel free to modify and distribute it.
