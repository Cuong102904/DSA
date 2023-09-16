#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETE_NODE (person *)(0xFFFFFFFFFFFFFFFFFFFUL) // unintptr_t
typedef struct
{
    char name[MAX_NAME];
    int age;
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
    // hash is emty
}

void print_table()
{
    for (int i = 0; i < SIZE_MAX; i++)
    {
        if (hash_Table[i] == NULL)
        {
            printf("\t%i\t--\n", i);
        }
        else if (hash_Table[i] == DELETE_NODE)
        {
            printf("\t%i\t--<deleted>\n", i);
        }
        else
        {
            printf("\t%i\t%s\n", i, hash_Table[i]->name);
        }
    }
}

bool hash_table_insert(person *p)
{
    if (p == NULL)
        return false;
    int index = hash(p->name); // update version
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (i = index) % TABLE_SIZE;
        if (hash_Table[try] == NULL || hash_Table[try] == DELETE_NODE)
        {
            hash_Table[try] = p;
            return true;
        }
    }

    return false;

    // if (hash_Table[index] != NULL)
    // {
    //     return false;
    // }
    // hash_table_insert[index] = p;
    // return true;
}
// find a person in the table by their name
person *hash_table_lookup(char *name)
{
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (index + i) % TABLE_SIZE;
        if (hash_Table[try] == NULL)
            return false;
        if (hash_Table[try] == DELETE_NODE)
            continue;
        if (strncmp(hash_Table[try]->name, name) == 0)
        {
            return hash_Table[index];
        }
    }
    return NULL;

    // int index = hash(name);
    // for (int i = 0; i < TABLE_SIZE; i++)
    // {
    //     int try = (index + i) % TABLE_SIZE;
    //     if (hash_Table[try] != NULL && strncmp(hash_Table[try]->name, name) == 0)
    //     {
    //         return hash_Table[index];
    //     }
    // }
    // return NULL;
}
person *hash_table_delete(char *name)
{
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (index + i) % TABLE_SIZE;
        if (hash_Table[try] == NULL)
            return false;
        if (hash_Table[try] == DELETE_NODE)
            continue;
        if (strncmp(hash_Table[try]->name, name) == 0)
        {
            person *tmp = hash_Table[try];
            hash_Table[try] = DELETE_NODE;
            return tmp;
        }
    }
    return NULL;

    //  int index = hash(name);
    // for (int i = 0; i < TABLE_SIZE; i++)
    // {
    //     int try = (index + i) % TABLE_SIZE;
    //     if (hash_Table[try] != NULL && strncmp(hash_Table[try]->name, name) == 0)
    //     {   person*tmp = hash_Table[try];
    //         hash_Table[try]= DELETE_NODE;
    //         return tmp;
    //     }
    // }
    // return NULL;
}

int main()
{
    init_hash_table();
    person jacob = {.name = "Jacob", .age = 20};
    person hana = {.name = "hana", .age = 21};
    person mpho = {.name = "mpho", .age = 22};
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