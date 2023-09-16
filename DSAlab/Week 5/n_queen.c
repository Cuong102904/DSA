#include <stdio.h>
#include <stdlib.h>

int board[20], cloneBoard[20], count;

int place(int row, int column)
{
    int i;
    for (i = 1; i <= row - 1; ++i)
    {
        // checking column and digonal conflicts
        if (board[i] == column)
            return 0;
        else if (abs(board[i] - column) == abs(i - row))
            return 0;
    }

    return 1;
}

// function to check for proper positioning of queen
void queen(int row, int n)
{
    int column;
    if (board[row] == cloneBoard[row])
    {
        queen(row + 1, n);
    }
    else
    {
        for (column = 1; column <= n; ++column)
        {
            if (place(row, column))
            {
                board[row] = column;
                if (row == n)
                    count++;
                else
                    queen(row + 1, n);
            }
        }
    }
}

int main()
{
    int n, i, j, K;
    scanf("%d", &n);
    scanf("%d", &K);
    while (K--)
    {
        int c, r;
        scanf("%d %d", &c, &r);
        board[r] = c;
        cloneBoard[r] = c;
    }
    queen(1, n);
    printf("%d", count);
    return 0;
}
