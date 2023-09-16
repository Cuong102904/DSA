#include <stdio.h>

int fibonacci(int n)
{
    if (n == 1 || n == 0)
    {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    printf("nhap so phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("%d", fibonacci(i));
    }
    return 0;
}