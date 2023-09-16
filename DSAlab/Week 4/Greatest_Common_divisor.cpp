#include <stdio.h>

void checkdivisor(int a, int b)
{
    int tg;
    while (b != 0)
    {
        tg = a % b;
        a = b;
        b = tg;
    }
    printf("%d", a);
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    checkdivisor(a, b);
    return 0;
}