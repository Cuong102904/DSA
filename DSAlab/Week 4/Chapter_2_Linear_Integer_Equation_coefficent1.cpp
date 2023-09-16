#include <stdio.h>
int n, M;
int x[100];
int T;
int check(int v, int k)
{
    if (k < n)
        return 1;
    else
        return T + v == M;
}

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d", x[i]);
    }
    printf("\n");
}

void Try(int k)
{
    for (int v = 0; v <= M - T - (n - k); v++)
    {
        if (check(v, k))
        {
            x[k] = v;
            T = T + x[k]; // update T when taking decision x[k]=v
            if (k == n)
                solution();
            else
                Try(k + 1);
            T = T - x[k]; // recover when backtracking
        }
    }
}
int main()
{
    scanf("%d", &n);
}