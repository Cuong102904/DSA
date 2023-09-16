#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

#define MAX_NAME 256
#define TABLE_SIZE 100000

typedef struct person
{
    char name[MAX_NAME];
    struct person *next;
} person;

typedef struct Node
{ // bst
    char name[MAX_NAME];
    struct Node *left;
    struct Node *right;
} Node;

Node *root = NULL; // store ten theo alpha order using bst
person *hash_Table[TABLE_SIZE];

unsigned int hash(char name[])
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

// insert by bst
Node *makenode(char name[])
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (p != NULL)
    {
        strcpy(p->name, name);
        p->left = NULL;
        p->right = NULL;
    }
    return p;
}

Node *insert(Node *root, char name[])
{
    if (root == NULL)
    {
        root = makenode(name);
        return root;
    }

    if (strcmp(root->name, name) > 0)
    {
        root->left = insert(root->left, name);
    }
    else
    {
        root->right = insert(root->right, name);
    }
    return root;
}

void free_bst(Node *node)
{
    if (node == NULL)
        return;
    free_bst(node->left);
    free_bst(node->right);
    free(node);
}

void free_hash_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        person *current = hash_Table[i];
        while (current != NULL)
        {
            person *next = current->next;
            free(current);
            current = next;
        }
    }
}

void printInorder(Node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    int count = hash_table_lookup(node->name);
    printf("%s %d ", node->name, count);
    printInorder(node->right);
}

int main()
{
    // FILE *input_file = fopen("2910.txt", "r");
    // if (input_file == NULL)
    // {
    //     printf("Error opening the input file.\n");
    //     return 1;
    // }

    init_hash_table();

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
                root = insert(root, words[i]);
            }
            person *p = (person *)malloc(sizeof(person));
            if (p != NULL)
            {
                strcpy(p->name, words[i]);
                p->next = NULL;
                hash_table_insert(p);
            }
            else
            {
                // Handle memory allocation error if needed
            }
        }
    }
    // fclose(input_file);
    printInorder(root);

    // Free allocated memory
    free_bst(root);
    free_hash_table();
    return 0;
}
