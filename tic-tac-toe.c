#include <stdio.h>

char board[3][3];

// Function to initialize the board

void initializeBoard() {
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the Tic Tac Toe board

void displayBoard() {
    int i, j;

    printf("-------------\n");
    for (i = 0; i < 3; i++) {
        printf("| ");
        for (j = 0; j < 3; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n-------------\n");
    }
}

// Function to check if the game is over

int isGameOver() {
    int i, j;

    // Check rows and columns for a win
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1;
    }

    // Check diagonals for a win
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;

    // Check for a draw
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0;
        }
    }

    return -1; // Game is a draw
}

int main() {
    int row, col, player = 1, gameState;

    initializeBoard();

    do {
        displayBoard();

        // Player 1: 'X', Player 2: 'O'
        printf("Player %d, enter row (0-2) and column (0-2) separated by a space: ", player);
        scanf("%d %d", &row, &col);

        if (player == 1 && board[row][col] == ' ') {
            board[row][col] = 'X';
            player = 2;
        } else if (player == 2 && board[row][col] == ' ') {
            board[row][col] = 'O';
            player = 1;
        } else {
            printf("Invalid move. Try again.\n");
        }

        gameState = isGameOver();

    } while (gameState == 0);

    displayBoard();

    if (gameState == 1)
        printf("Player %d wins!\n", (player == 1) ? 2 : 1);
    else
        printf("It's a draw!\n");

    return 0;
}