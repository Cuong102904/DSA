#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    int i;

    scanf("%d", &n);

    for (i = -n; i <= n; i++)
    {
        if (i != 0 && n % abs(i) == 0)
        {
            printf("%d ", i);
        }
    }

    return 0;
}