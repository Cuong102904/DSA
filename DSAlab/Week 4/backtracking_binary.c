#include <stdio.h>

int k, a[100];
int n;

int Check(int y, int k)
{
    if (k == 1)
        return 1;
    else
    {
        return a[k - 1] + y <= 1;
    }
}

void PrintSol()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
    printf("\n");
}

void Try(int k)
{
    for (int y = 0; y <= 1; y++)
    {
        if (Check(y, k))
        {
            a[k] = y;
            if (k == (n - 1))
                PrintSol();
            else
                Try(k + 1);
        }
    }
}
int main()
{
    scanf("%d", &n);
    Try(0);
    return 0;
}