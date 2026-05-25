#include <stdio.h>

int board[20][20];
int n;

int isSafe(int row, int col)
{
    int i, j;

    // Check column
    for(i = 0; i < row; i++)
    {
        if(board[i][col] == 1)
            return 0;
    }

    // Check left diagonal
    for(i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if(board[i][j] == 1)
            return 0;
    }

    // Check right diagonal
    for(i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if(board[i][j] == 1)
            return 0;
    }

    return 1;
}

void solveNQueens(int row)
{
    int col, i, j;

    // All queens placed
    if(row == n)
    {
        printf("\nSolution:\n");

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(board[i][j] == 1)
                    printf("Q ");
                else
                    printf(". ");
            }
            printf("\n");
        }

        return;
    }

    // Try placing queen in each column
    for(col = 0; col < n; col++)
    {
        if(isSafe(row, col))
        {
            board[row][col] = 1;

            solveNQueens(row + 1);

            // Backtracking
            board[row][col] = 0;
        }
    }
}

int main()
{
    printf("Enter number of queens: ");
    scanf("%d", &n);

    solveNQueens(0);

    return 0;
}
