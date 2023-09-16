#include <stdio.h>

#include <stdio.h>
#define P 100007
int n, k;
int M[100000][100000];

int C(int k, int n)
{

    if (k == 0 || k == n)
        M[k][n] = 1;

    else if (M[k][n] == 0)
    {
        M[k][n] = (C(k - 1, n - 1) + C(k, n - 1)) % P;
    }
    return M[k][n];
}

int main()
{
    scanf("%d %d", &k, &n);
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
            M[i][j] = 0;
    printf("%d", C(k, n));
    return 0;
}
