#include <stdio.h>
#include <string.h>
#define N 10000
int main()
{
    char upper[N];
    while (fgets(upper, N, stdin))
    {
        for (int i = 0; i < strlen(upper); i++)
        {
            if (upper[i] >= 'a' && upper[i] <= 'z')
            {
                upper[i] -= 32;
            }
        }
        printf("%s", upper);
    }
}