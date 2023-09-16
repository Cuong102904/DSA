#include <stdio.h>
int n;
int arr[20];

void PrintSol()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

void Check(int k)
{
    for (int i = 0; i <= 1; i++)
    {
        arr[k] = i;
        if (k == n - 1)
            PrintSol();
        else
            Check(k + 1);
    }
}

int main()
{
    scanf("%d", &n);
    Check(0);
    return 0;
}
