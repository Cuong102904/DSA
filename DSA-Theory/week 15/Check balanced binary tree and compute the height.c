#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define HASH_TABLE_SIZE 200007

typedef struct treeNode
{
    int data;
    struct treeNode *leftmost_child;
    struct treeNode *right_sibling;
} treeNode;

treeNode *Root;
treeNode *hashTable[HASH_TABLE_SIZE];

unsigned int hash(int val)
{
    return (unsigned int)(val) % HASH_TABLE_SIZE;
}

void insertIntoHashTable(int val, treeNode *node) // linear probing
{
    unsigned int index = hash(val);
    while (hashTable[index] != NULL)
        index = (index + 1) % HASH_TABLE_SIZE;

    hashTable[index] = node;
}

treeNode *find(int u)
{
    unsigned int index = hash(u);
    while (hashTable[index] != NULL)
    {
        if (hashTable[index]->data == u)
            return hashTable[index];
        index = (index + 1) % HASH_TABLE_SIZE;
    }
    return NULL;
}

treeNode *makeNode(int val)
{
    treeNode *p = (treeNode *)malloc(sizeof(treeNode));
    p->data = val;
    p->leftmost_child = NULL;
    p->right_sibling = NULL;
    return p;
}
// vua tim chieu cao vua kiem tra balanced tree or not
int depth(treeNode *Root, int *isBalanced)
{
    if (Root == NULL)
    {
        *isBalanced = 1;
        return 0;
    }

    int leftHeight = 0, rightHeight = 0;
    int leftBalanced = 0, rightBalanced = 0;

    leftHeight = depth(Root->leftmost_child, &leftBalanced);
    rightHeight = depth(Root->right_sibling, &rightBalanced);

    // *isBalanced = leftBalanced && rightBalanced && abs(leftHeight - rightHeight) <= 1;
    if (rightBalanced && abs(leftHeight - rightHeight) <= 1)
        *isBalanced = leftBalanced;
    else
        *isBalanced = 0;

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

void AddLeft(int u, int v)
{
    // freopen("check.txt", "r", stdin);
    treeNode *pu = find(v);
    if (pu == NULL || pu->leftmost_child != NULL)
        return;

    pu->leftmost_child = makeNode(u);
    insertIntoHashTable(u, pu->leftmost_child);
}

void AddRight(int u, int v)
{
    treeNode *pu = find(v);
    if (pu == NULL || pu->right_sibling != NULL)
        return;

    pu->right_sibling = makeNode(u);
    insertIntoHashTable(u, pu->right_sibling);
}

int main()
{
    Root = NULL;
    for (int i = 0; i < HASH_TABLE_SIZE; i++)
        hashTable[i] = NULL;

    char trash[20];
    while (1)
    {
        scanf("%s", trash);
        if (strcmp(trash, "*") == 0)
            break;
        if (strcmp(trash, "MakeRoot") == 0)
        {
            int val;
            scanf("%d", &val);
            Root = makeNode(val);
            insertIntoHashTable(val, Root);
        }
        if (strcmp(trash, "AddLeft") == 0)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            AddLeft(u, v);
        }
        if (strcmp(trash, "AddRight") == 0)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            AddRight(u, v);
        }
    }

    int isBalanced = 0;
    int treeHeight = depth(Root, &isBalanced);

    if (isBalanced)
        printf("1 %d", treeHeight);
    else
        printf("0 %d", treeHeight);

    return 0;
}
