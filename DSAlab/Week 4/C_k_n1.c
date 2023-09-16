#include <stdio.h>

long tohop(int n, int k)
{
    long C[n + 1][k + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (j == 0 || j == i)
            {
                C[i][j] = 1;
            }
            else
            {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }
    return C[n][k];
}

int main()
{
    int n;
    int k;
    scanf("%d %d", &k, &n);
    printf("%ld", tohop(n, k));
    return 0;
}