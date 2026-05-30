#include <stdio.h>

#define MAX 20

int board[MAX][MAX];
int N;

// Function to check whether position is safe
int isSafe(int row, int col)
{
    int i;

    // Check same column
    for(i = 0; i < row; i++)
    {
        if(board[i][col] == 1)
            return 0;
    }

    // Check upper left diagonal
    for(i = 1; row - i >= 0 && col - i >= 0; i++)
    {
        if(board[row - i][col - i] == 1)
            return 0;
    }

    // Check upper right diagonal
    for(i = 1; row - i >= 0 && col + i < N; i++)
    {
        if(board[row - i][col + i] == 1)
            return 0;
    }

    return 1;
}

// Backtracking function
int solveNQueens(int row)
{
    int col;

    // All queens placed
    if(row == N)
        return 1;

    // Try all columns
    for(col = 0; col < N; col++)
    {
        if(isSafe(row, col))
        {
            // Place queen
            board[row][col] = 1;

            // Recursive call
            if(solveNQueens(row + 1))
                return 1;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return 0;
}

// Function to print board
void printBoard()
{
    int i, j;

    printf("\nSolution:\n\n");

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(board[i][j] == 1)
                printf("Q ");
            else
                printf(". ");
        }

        printf("\n");
    }
}

int main()
{
    int i, j;

    printf("Enter value of N: ");
    scanf("%d", &N);

    // Initialize board with 0
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }

    if(solveNQueens(0))
        printBoard();
    else
        printf("No solution exists.\n");

    return 0;
}