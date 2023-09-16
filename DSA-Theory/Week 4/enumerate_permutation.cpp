#include <stdio.h>
int a[100];
int n;

int check(int y, int k)
{
    for (int j = 1; j < k - 1; j++)

        if (y == a[j])
            return 0;
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
    for (int y = 1; y <= n; y++)
        if (check(y, k) == 1)
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
    Try(1);
}
