#include <stdio.h>
#include <string.h>

int main()
{
    float numbera;
    int intparta;
    float decimala;

    scanf("%f", &numbera);
    if (numbera > 0)
    {
        intparta = (int)numbera;
        decimala = numbera - (float)intparta;
        printf("%d %.2f", intparta, decimala);
    }
    else
    {
        intparta = (int)numbera - 1;
        decimala = -((float)intparta - numbera);
        printf("%d %.2f", intparta, decimala);
    }
    return 0;
}