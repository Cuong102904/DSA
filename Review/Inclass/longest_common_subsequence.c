#include <stdio.h>
#define N 10001

int dp[N][N];

void LCS(int m, int n)
{
    int arr[m + 1];
    int arr1[n + 1];
    for (int i = 0; i < m; i++)
        scanf("%d", &arr[i]);
    for (int j = 0; j < n; j++)
        scanf("%d", &arr1[j]);
    for (int k = 0; k < m; k++)
        dp[k][0] = 0;
    for (int k = 0; k < n; k++)
        dp[0][k] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[i - 1] == arr1[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }
    printf("%d", dp[m][n]);
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    LCS(m, n);
    return 0;
}