#include <stdio.h>

arr[9][9];
int count;
int col;
int row;

void nhap()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}

int check(int row, int col, int num)
{
    // check for rows
    for (int i = 0; i < 9; i++)
    {
        if (arr[i][col] == num)
            return 0;
    }
    // check for col
    for (int i = 0; i < 9; i++)
    {
        if (arr[row][i] == num)
            return 0;
    }
    // check for 3x3
    int NewRow = row - row % 3;
    int NewCol = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[NewRow + i][NewCol + j] == num)
                return 0;
        }
    }

    return 1;
}

void SolSudoku(int col, int row)
{
    if (col == 9)
    {
        return SolSudoku(0, row + 1);
    }
    if (row == 8)
    {
        count++;
        return;
    }
    if (arr[row][col] > 0)
    {
        return SolSudoku(col + 1, row);
    }
    else
    {
        for (int num = 1; num <= 9; num++)
        {
            if (check(row, col, num))
            {
                arr[row][col] = num;
                SolSudoku(col + 1, row);
                arr[row][col] = 0;
            }
        }
    }
}

int main()
{
    // freopen("testcaseSudoku.txt", "r", stdin);
    nhap();
    SolSudoku(0, 0);
    printf("%d", count);
}