#include <stdio.h>
int n;
int arr[20];

void PrintSol()
{
    for (int i = 1; i < n + 1; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int test(int k, int y)
{
    if (k == 1)
        return 1;
    else
        return arr[k - 1] + y <= 1;
}

void check(int k)
{
    for (int i = 0; i <= 1; i++)
    {
        if (test(k, i))
        {
            arr[k] = i;
        }
        if (k == n)
        {
            PrintSol();
        }
        else
            check(k + 1);
    }
}

int main()
{
    scanf("%d", &n);
    check(1);
    return 0;
}