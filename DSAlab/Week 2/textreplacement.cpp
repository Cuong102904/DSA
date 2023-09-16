#include <stdio.h>
#include <string.h>
#define N 100000

char P1[N];
char P2[N];
char T[N];
char arr[N];

int matchAt(int i)
{
    if (i + strlen(P1) > strlen(T))
        return 0;
    for (int k = 0; k < strlen(P1); k++)
    {
        if (P1[k] != T[i + k])
            return 0;
    }
    return 1;
}

void findAndReplace()
{
    int i = 0;
    int j = 0;
    while (i < strlen(T))
    {
        if (matchAt(i))
        {
            for (int k = 0; k < strlen(P2); k++)
            {
                arr[j + k] = P2[k];
            }
            j += strlen(P2);
            i += strlen(P1);
        }
        else
        {
            arr[j] = T[i];
            j++;
            i++;
        }
    }
    arr[j] = '\0';
    printf("%s", arr);
}

void input()
{
    fgets(P1, N, stdin);
    fgets(P2, N, stdin);
    fgets(T, N, stdin);
    if (P1[strlen(P1) - 1] == '\n')
        P1[strlen(P1) - 1] = '\0';
    if (P2[strlen(P2) - 1] == '\n')
        P2[strlen(P2) - 1] = '\0';
    if (T[strlen(T) - 1] == '\n')
        T[strlen(T) - 1] = '\0';
}

int main()
{
    input();
    findAndReplace();
    return 0;
}