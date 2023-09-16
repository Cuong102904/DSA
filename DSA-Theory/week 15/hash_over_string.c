#include <stdio.h>
#include <string.h>

#define MAX_NAME 256

typedef struct person
{
    char name[MAX_NAME];
    struct person *next;
    //..... add more
} person;

unsigned int hash(char *name, int m)
{

    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++)
    {
        hash_value = (hash_value * 256 + name[i]) % m;
    }

    return hash_value;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, m);
    for (int i = 0; i < n; i++)
    {
        char ans[MAX_NAME];
        scanf("%s", ans);
        unsigned int val = hash(ans, m);
        printf("%d\n", val);
    }

    return 0;
}