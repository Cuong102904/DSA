#include <stdio.h>
#define MAX 1000
#define MOD 1000000007

int dp[MAX][MAX];

int countSubsets(int n, int m, int *arr)
{
    // Khởi tạo giá trị ban đầu cho mảng dp
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        dp[0][i] = 0;
    }

    // Tính các giá trị của mảng dp
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i] <= j)
            {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i]]) % MOD;
                        }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Trả về giá trị cần tìm
    return dp[n][m];
}

int main()
{
    int n, m;
    int arr[MAX];
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("%d", countSubsets(n, m, arr));
    return 0;
}
