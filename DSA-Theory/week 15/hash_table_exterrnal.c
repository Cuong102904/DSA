#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

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

void print_table()
{
    printf("start\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_Table[i] == NULL)
        {
            printf("\t%i\t---\n", i);
        }
        else
        {
            printf("\t%i\t", i);
            person *tmp = hash_Table[i];
            while (tmp != NULL)
            {
                printf("%s - ", tmp->name);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }
    printf("End\n");
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
    while (tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0)
    {
        tmp = tmp->next;
    }
    return tmp;
}
person *hash_table_delete(char *name)
{
    int index = hash(name);
    person *tmp = hash_Table[index];
    person *prev = NULL;
    while (tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return NULL;
    if (prev == NULL)
    {
        // deleting the head
        hash_Table[index] = tmp->next;
    }
    else
    {
        prev->next = tmp->next;
    }
    return tmp;
}

int main()
{
    init_hash_table();
    person jacob = {.name = "Jacob"};
    person hana = {.name = "hana"};
    person mpho = {.name = "mpho"};
    hash_table_insert(&jacob);
    hash_table_insert(&hana);
    hash_table_insert(&mpho);
    print_table();

    person *tmp = hash_table_lookup("mpho");
    if (tmp == NULL)
    {
        printf("not found!\n");
    }
    else
        printf("Found %s.\n", tmp->name);

    hash_table_delete("mpho");
    tmp = hash_table_lookup("mpho");
    if (tmp == NULL)
    {
        printf("not found!\n");
    }
    else
        printf("Found %s.\n", tmp->name);

    return 0;
}