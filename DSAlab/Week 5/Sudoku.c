#include <stdio.h>
#include <stdlib.h>
// tìm số cách để giải bài toán sudoku. Tìm được hết các số 0 được tính là 1 cách.
int arr[9][9];
int count;

void nhap(int arr[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}
int check(int col, int row, int num)
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
    // check in boxes
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (arr[startRow + i][startCol + j] == num)
                return 0;

    return 1;
}

void solveSoduku(int col, int row)
{
    if (row == 9)
    {
        count++;
        return;
    }
    if (col == 9)
    {
        solveSoduku(0, row + 1);
    }
    else if (arr[row][col] > 0)
    {
        solveSoduku(col + 1, row);
    }
    else
    {
        for (int num = 1; num <= 9; num++)
        {
            if (check(col, row, num) == 1)
            {
                arr[row][col] = num;
                solveSoduku(col + 1, row);
                arr[row][col] = 0;
            }
        }
    }
}

int main()
{
    count = 0;
    freopen("30.txt", "r", stdin);
    nhap(arr);
    solveSoduku(0, 0);
    printf("%d", count);
    return 0;
}
