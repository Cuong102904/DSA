#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 100000

typedef struct person
{
    char name[MAX_NAME];
    struct person *next;
    //..... add more
} person;

person *hash_Table[TABLE_SIZE];

unsigned int hash(char *name)
{
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++)
    {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void init_hash_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_Table[i] = NULL;
    }
    // hash is empty
}

bool hash_table_insert(person *p)
{
    if (p == NULL)
        return false;
    int index = hash(p->name); // update version
    p->next = hash_Table[index];
    hash_Table[index] = p;
    return true;
}
// find a person in the table by their name
person *hash_table_lookup(char *name)
{
    int index = hash(name);
    person *tmp = hash_Table[index];
    while (tmp != NULL && strncmp(tmp->name, name, /*MAX_NAME*/ strlen(name)) != 0)
    {
        tmp = tmp->next;
    }
    return tmp;
}
// giai phong dung luong
void free_hash_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        person *tmp = hash_Table[i];
        while (tmp != NULL)
        {
            person *next = tmp->next;
            free(tmp);
            tmp = next;
        }
    }
}

int main()
{
    init_hash_table();
    while (1)
    {
        char name[MAX_NAME];
        scanf("%s", name);
        if (strcmp(name, "*") == 0)
            break;
        person *p = (person *)malloc(sizeof(person));
        strcpy(p->name, name);
        p->next = NULL;
        hash_table_insert(p);
    }
    while (1)
    {
        char items[MAX_NAME];
        scanf("%s", items);
        if (strcmp(items, "***") == 0)
            break;
        if (strcmp(items, "find") == 0)
        {
            char name[MAX_NAME];
            scanf("%s", name);
            person *tmp = hash_table_lookup(name);
            if (tmp == NULL)
            {
                printf("0\n");
            }
            else
                printf("1\n");
        }
        else if (strcmp(items, "insert") == 0)
        {
            char name[MAX_NAME];
            scanf("%s", name);
            person *tmp = hash_table_lookup(name);
            if (tmp != NULL)
                printf("0\n");
            else
            {
                person *p = (person *)malloc(sizeof(person));
                strcpy(p->name, name);
                p->next = NULL;
                if (hash_table_insert(p))
                    printf("1\n");
                else
                {
                    printf("0\n");
                    free(p);
                }
            }
        }
    }
    free_hash_table();
    return 0;
}
