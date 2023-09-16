#include <stdio.h>

int A[100][100];
int B[100][100];
int C[100][100];
int n, k, m;
void nhapMatrix(int matrix[100][100], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int nhanMatrix(int A[100][100], int B[100][100], int C[100][100], int n, int k, int m)
{
    int sum = 0;
    int i, j, b;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            sum = 0;
            for (b = 0; b < k; b++)
            {

                sum += A[i][b] * B[b][j];
            }
            C[i][j] = sum;
        }
    }
}

int main()
{
    scanf("%d %d", &n, &k);
    nhapMatrix(A, n, k);
    scanf("%d %d", &k, &m);
    nhapMatrix(B, k, m);
    nhanMatrix(A, B, C, n, k, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}