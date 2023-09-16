#include <stdio.h>
int n;
int arr[1000];
int k, m;

void PrintSol()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void Check(int k, int count)
{
    if (k == n)
    {
        if (count == m)
        {
            PrintSol();
        }
        return;
    }

    for (int i = 1; i <= m && i <= m - count; i++)
    {
        arr[k] = i;
        Check(k + 1, count + i);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    Check(0, 0);
}