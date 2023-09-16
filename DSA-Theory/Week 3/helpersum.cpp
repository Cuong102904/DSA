#include <stdio.h>

int helpersum(int a[], int k)
{
    if (k == 0)
        return a[0];
    else
        return a[k] + helpersum(a, k - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[1000];
    for (int i = 0; i <= n - 1; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Sum is : %d", helpersum(a, n - 1));
    return 0;
}