// Generate m-elements subsets of the set of n elements
#include <stdio.h>

int a[100];
int m, n;
void PrintSol()
{
    for (int i = 1; i <= m; i++)
        printf("%d", a[i]);
    printf("\n");
}
void Try(int k)
{
    for (int y = a[k - 1] + 1; y <= n - m + k; y++)
    {
        a[k] = y;
        if (k == m)
            PrintSol();
        else
            Try(k + 1);
    }
}

int main()
{
    m = 3;
    a[0] = 0;
    n = 5;
    Try(1);
}