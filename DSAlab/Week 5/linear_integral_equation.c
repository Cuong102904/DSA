#include <stdio.h>
int A[20];
int n, m, k;
void Printf()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", A[i]);
    }
    printf("\n");
}

void Check(int i, int k)
{
    return A[i] + k <= 5;
}

void Try(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (check(i, k))
        {
            A[k] = i;
            if (k == n)
                Printf();
            else
                Try(k + 1);
        }
    }
}