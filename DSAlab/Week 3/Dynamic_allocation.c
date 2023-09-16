#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *p;
    p = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        *(p + i) = 10 * i;
    }
    for (int i = 0; i < n; i++)
    {
        printf("p[%d] = %d \n", i, p[i]);
    }

    return 0;
}