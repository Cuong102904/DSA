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
} person;

typedef struct array
{
    char arr[MAX_NAME];
} array;

array arr[TABLE_SIZE];
person *hash_Table[TABLE_SIZE];

unsigned int hash(char *name)
{
    int length = strlen(name);
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
}

bool hash_table_insert(person *p)
{
    if (p == NULL)
        return false;
    int index = hash(p->name);
    p->next = hash_Table[index];
    hash_Table[index] = p;
    return true;
}

int hash_table_lookup(char *name)
{
    int index = hash(name);
    person *tmp = hash_Table[index];
    int count = 0;
    while (tmp != NULL)
    {
        if (strcmp(tmp->name, name) == 0)
        {
            count++;
        }
        tmp = tmp->next;
    }
    return count;
}

int main()
{
    int k = 0;
    char paragraph[TABLE_SIZE];
    while (fgets(paragraph, TABLE_SIZE, stdin))
    {
        char *words[TABLE_SIZE];
        int numWords = 0;

        char *word = strtok(paragraph, " \t\n");

        while (word != NULL && numWords < TABLE_SIZE)
        {
            words[numWords] = word;
            numWords++;
            word = strtok(NULL, " \t\n");
        }

        for (int i = 0; i < numWords; i++)
        {
            if (hash_table_lookup(words[i]) == 0)
            {
                strcpy(arr[k].arr, words[i]);
                k++;
            }
            person *p = (person *)malloc(sizeof(person));
            strcpy(p->name, words[i]);
            p->next = NULL;
            hash_table_insert(p);
        }
    }
    char temp[30];
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k - 1 - i; j++)
        {
            if (strcmp(arr[j].arr, arr[j + 1].arr) > 0)
            {
                strcpy(temp, arr[j].arr);
                strcpy(arr[j].arr, arr[j + 1].arr);
                strcpy(arr[j + 1].arr, temp);
            }
        }
    }

    for (int i = 0; i < k; i++)
    {
        int count = hash_table_lookup(arr[i].arr);
        printf("%s %d\n", arr[i].arr, count);
    }

    return 0;
}
