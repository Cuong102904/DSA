#include <stdio.h>

int a[100];
int n;
int check(int y, int k)
{

    return 1;
}
void PrintSol()
{
    for (int i = 1; i <= n; i++)
        printf("%d", a[i]);
    printf("\n");
}
void Try(int k)
{
    for (int y = 0; y <= 1; y++)
    {
        if (check(y, k))
            a[k] = y;
        if (k == n)
            PrintSol();
        else
            Try(k + 1);
    }
}
int main()
{
    scanf("%d", &n);
    Try(1);
}