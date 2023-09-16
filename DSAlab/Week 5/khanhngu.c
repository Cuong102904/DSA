#include <stdio.h>
#include <stdlib.h>
// tìm lời giải bài toán soduku
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
void xuat(int arr[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
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

int solveSoduku(int col, int row)
{
    if (row == 9 - 1 && col == 9)
        return 1;
    if (col == 9)
    {
        row++;
        col = 0;
    }
    if (arr[row][col] > 0)
    {
        solveSoduku(col + 1, row);
    }

    for (int num = 1; num <= 9; num++)
    {
        if (check(col, row, num) == 1)
        {
            arr[row][col] = num;
            if (solveSoduku(col + 1, row))
                return 1;
        }
        arr[row][col] = 0;
    }
    return 0;
}

int main()
{

    // freopen("30.txt", "r", stdin);
    nhap(arr);
    printf("\n");
    if (solveSoduku(0, 0) == 1)
        xuat(arr);
    return 0;
}
