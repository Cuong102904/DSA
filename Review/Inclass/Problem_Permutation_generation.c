#include <stdio.h>
int n;
int arr[10000];
int mark[1000];
void PrintfSol()
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int test(int v)
{
    return mark[v] == 0;
}

void Check(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (test(i))
        {
            arr[k] = i;
            mark[i] = i;

            if (k == n)
                PrintfSol();
            else
                Check(k + 1);
            mark[i] = 0;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        mark[i] = 0;
    }
    Check(1);
    return 0;
}