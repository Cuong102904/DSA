#include <stdio.h>

int C_betterVersion(int n, int k, int D[100][100])
{
    if (D[n][k] > 0)
        return D[n][k];
    else
    {
        D[n][k] = C_betterVersion(n - 1, k - 1, D) + C_betterVersion(n - 1, k, D);
        return D[n][k];
    }
}

int main() c
{
    int D[100][100];
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            D[i][j] = 0;
            D[j][j] = 1;
            D[0][i] = 1;
        }
    }
    int result = C_betterVersion(n, k, D);
    printf("%d", result);
}