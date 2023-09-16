#include <stdio.h>

int a[100];
int n;
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
        a[k] = y;
        if (k == n)
            PrintSol();
        else
            Try(k + 1);
    }
}
int main()
{
    printf("Enter n = ");
    scanf("%d", &n);
    Try(1);
}