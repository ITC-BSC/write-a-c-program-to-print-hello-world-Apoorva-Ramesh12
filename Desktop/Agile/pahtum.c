#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 7

// Function to print the board with ASCII graphics
void printBoard(char board[SIZE][SIZE]) {
    printf("    ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d   ", i);
    }
    printf("\n");
   
    printf("  ");
    for (int i = 0; i <= SIZE * 4; i++) {
        printf("-");
    }
    printf("\n");
   
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("  ");
    for (int i = 0; i <= SIZE * 4; i++) {
        printf("-");
    }
    printf("\n");
}

// Function to check if a move is valid
bool isValidMove(char board[SIZE][SIZE], int row, int col) {
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ');
}

// Function to play a move
void playMove(char board[SIZE][SIZE], char player) {
    int row, col;
    do {
        row = rand() % SIZE;
        col = rand() % SIZE;
    } while (!isValidMove(board, row, col));
   
    board[row][col] = player;
}

// Function to score the board and show breakdown of scores
void scoreBoard(char board[SIZE][SIZE]) {
    int scoreX = 0, scoreO = 0;
    int countX[5] = {0}, countO[5] = {0}; // To store counts of sequences of lengths 3, 4, 5, 6, and 7
   
    // Check vertically
    for (int i = 0; i < SIZE; i++) {
        int countXCurrent = 0, countOCurrent = 0;
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 'X') {
                countXCurrent++;
                countOCurrent = 0;
            } else if (board[i][j] == 'O') {
                countOCurrent++;
                countXCurrent = 0;
            } else {
                countXCurrent = 0;
                countOCurrent = 0;
            }
        printf("X=%d ,O=%d",countXCurrent,countOCurrent);
            if (countXCurrent >= 3) {
                scoreX += (countXCurrent == 3) ? 3 : (countXCurrent == 4) ? 10 : (countXCurrent == 5) ? 25 : (countXCurrent == 6) ? 56 : 119;
                countX[countXCurrent - 3]++; // Increment count for sequence length
            }
            if (countOCurrent >= 3) {
                scoreO += (countOCurrent == 3) ? 3 : (countOCurrent == 4) ? 10 : (countOCurrent == 5) ? 25 : (countOCurrent == 6) ? 56 : 119;
                countO[countOCurrent - 3]++; // Increment count for sequence length
            }
        }
    }

    // Check horizontally
    for (int j = 0; j < SIZE; j++) {
        int countXCurrent = 0, countOCurrent = 0;
        for (int i = 0; i < SIZE; i++) {
            if (board[i][j] == 'X') {
                countXCurrent++;
                countOCurrent = 0;
            } else if (board[i][j] == 'O') {
                countOCurrent++;
                countXCurrent = 0;
            } else {
                countXCurrent = 0;
                countOCurrent = 0;
            }
            if (countXCurrent >= 3) {
                scoreX += (countXCurrent == 3) ? 3 : (countXCurrent == 4) ? 10 : (countXCurrent == 5) ? 25 : (countXCurrent == 6) ? 56 : 119;
                countX[countXCurrent - 3]++; // Increment count for sequence length
            }
            if (countOCurrent >= 3) {
                scoreO += (countOCurrent == 3) ? 3 : (countOCurrent == 4) ? 10 : (countOCurrent == 5) ? 25 : (countOCurrent == 6) ? 56 : 119;
                countO[countOCurrent - 3]++; // Increment count for sequence length
            }
        }
    }

    printf("Score for Player X: %d\n", scoreX);
    printf("Score for Player O: %d\n", scoreO);
   
    // Print breakdown of scores
    printf("\nBreakdown of Scores:\n");
    printf("Player X: ");
    for (int i = 0; i < 5; i++) {
        printf("%d sequences of %d, ", countX[i], i + 3);
    }
    printf("\n");
    printf("Player O: ");
    for (int i = 0; i < 5; i++) {
        printf("%d sequences of %d, ", countO[i], i + 3);
    }
    printf("\n");
}

// Function to perform unit tests
void runUnitTests() {
    char testBoard[SIZE][SIZE];
    // Initialize the test board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            testBoard[i][j] = ' ';
        }
    }
   
    // Test 1: Check if isValidMove correctly validates moves
    printf("Unit Test 1: isValidMove\n");
    printf("Testing invalid move at (7,7)...\n");
    if (isValidMove(testBoard, 7, 7))
        printf("Test failed: (7,7) should be an invalid move.\n");
    else
        printf("Test passed!\n");

    printf("Testing valid move at (3,3)...\n");
    if (!isValidMove(testBoard, 3, 3))
        printf("Test failed: (3,3) should be a valid move.\n");
    else
        printf("Test passed!\n");

    // Test 2: Check if playMove correctly plays a move
    printf("\nUnit Test 2: playMove\n");
    printf("Playing a move for 'X'...\n");
    playMove(testBoard, 'X');
    printf("Current Board:\n");
    printBoard(testBoard);
   
    printf("\nPlaying a move for 'O'...\n");
    playMove(testBoard, 'O');
    printf("Current Board:\n");
    printBoard(testBoard);
}

int main() {
    srand(time(NULL)); // Seed the random number generator
   
    // Run unit tests
    runUnitTests();
   
    char board[SIZE][SIZE];
    // Initialize the board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
   
    char currentPlayer = 'X';
    int moves = 0;

    // Main game loop
    while (moves < SIZE * SIZE) {
        printf("\nCurrent Board:\n");
        printBoard(board);
        playMove(board, currentPlayer);
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch player
        moves++;
    }

    printf("\nFinal Board:\n");
    printBoard(board);
   
    // Score the board
    printf("\nScoring the board:\n");
    scoreBoard(board);
   
    printf("\nGame over!\n");
   
    return 0;
}