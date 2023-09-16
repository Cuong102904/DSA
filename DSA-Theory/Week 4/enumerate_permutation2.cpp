#include <stdio.h>
int a[100];
int n;
int used[100];

void PrintSol()
{
    for (int i = 1; i <= n; i++)
        printf("%d", a[i]);
    printf("\n");
}
void Try(int k)
{
    for (int y = 1; y <= n; y++)
        if (used[y] == 0)
        {
            a[k] = y;
            if (k == n)
                PrintSol();
            else
                Try(k + 1);
        }
}
int main()
{
    n = 3;
    for (int i = 1; i <= n; i++)
    {
        used[i] = 0;
    }
    Try(1);
}
