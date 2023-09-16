#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// Example 1
int n, m;
int a[100];
int row[100];
int col[100];
long count = 0;
int check(int k, int j)
{

    for (int i = 1; i <= n; i++)
    {
        if (a[i] != 0 && ((abs(a[i] - j) == abs(i - k)) || (a[i] == j)))
            return 0;
    }

    for (int i = 1; i <= m; i++)
    {
        if ((abs(a[row[i]] - j) == abs(row[i] - k)) || (a[row[i]] == j))
            return 0;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = i + 1; j <= m; j++)
        {

            if ((abs(row[i] - row[j]) == abs(col[i] - col[j])) || (row[i] == row[j]))
                return 0;
        }

        return 1;
    }
}
void Try(int k)
{
    if (a[k] == 0)
    {
        for (int j = 1; j <= n; j++)
        {

            if (check(k, j) == 1)
            {
                a[k] = j;
                if (k == n)
                {
                    count++;
                }
                else
                    Try(k + 1);
                a[k] = 0;
            }
        }
    }
    else
        Try(k + 1);
}

int main()
{
    scanf("%d", &n);
    scanf("%d", &m);

    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &row[i], &col[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        a[row[i]] = col[i];
    }
    Try(1);
    printf("%d", count);
    return 0;
}