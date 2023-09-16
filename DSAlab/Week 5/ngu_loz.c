#include <stdio.h>
#define N 9
int arr[9][9];
int count;
int check(int row, int col, int num)
{
    // check in row
    for (int i = 0; i < 9; i++)
    {
        if (arr[row][i] == num)
            return 0;
    }
    // check in col
    for (int i = 0; i < 9; i++)
    {
        if (arr[i][col] == num)
            return 0;
    }
    // check in the boxes
    int startcol, startrow;
    startcol = col - col % 3;
    startrow = row - row % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i + startrow][j + startcol] == num)
                return 0;
        }
    }
    return 1;
}

void xuat(int arr[N][N])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}

int main()
{
}