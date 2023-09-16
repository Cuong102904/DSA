#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int a[100];
int n;
int cnt = 0;
int check(int k, int j)
{
    // return true if we can replace the queen k at (rowk, col j)
    for (int i = 1; i <= k - 1; i++)
    {
        if ((a[i] == j))
            return 0;
        if (abs(a[i] - j) == abs(i - k))
            return 0;
    }
    ++cnt;
    return 1;
}
void printfSol()
{
    for (int i = 1; i <= n; i++)
    {
        printf("(row = %d, col = %d)", i, a[i]);
    }
    printf("\n");
}

void try(int k)
{
    for (int j = 1; j <= n; j++)
    {
        // check k-th queen is placed at (row k, col l)??
        if (check(k, j) == 1)
        {
            a[k] = j;
            if (k == n)
                printfSol();
            else
                try(k + 1);
        }
    }
}

int main()
{
    n = 4;
    try(1);
    if (cnt == 0)
        printf("THe Queen problem with n =%d DOES NOT HAVE SOLUTIONS", n);
}