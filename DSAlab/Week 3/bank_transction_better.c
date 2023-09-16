#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 1000007
#define NAME 30

typedef struct Bank_trans
{
    int fromacc;
    int toacc;
    int money;
    struct Bank_trans *next;
} Bank_trans;

Bank_trans *hash_table[TABLE_SIZE];

unsigned int hash(char *name)
{
    int length = strlen(name);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++)
    {
        hash_value = (hash_value * 10 + (name[i] - 48)) % TABLE_SIZE;
    }
    return hash_value;
}

void init_hash_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
}

bool insert_hash_table(Bank_trans *p)
{
    if (p == NULL)
    {
        return false;
    }
    int index = p->fromacc;
    p->next = hash_table[index];
    hash_table[index] = p;
    return true;
}

Bank_trans *hash_table_lookup(int index)
{
    // int index = hash(name);
    Bank_trans *tmp = hash_table[index];
    while (tmp != NULL && tmp->fromacc != index)
    {
        tmp = tmp->next;
    }
    return tmp;
}

/// AVLLLLLL
typedef struct Node
{
    char name[NAME];
    struct Node *leftChild;
    struct Node *rightChild;
    int height;
} Node;
Node *root;
int max(int a, int b);
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}

Node *newNode(char *name)
{
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->leftChild = NULL;
    node->rightChild = NULL;
    node->height = 1;
    return (node);
}
Node *rightRotate(Node *y)
{
    Node *x = y->leftChild;
    Node *T2 = x->rightChild;
    x->rightChild = y;
    y->leftChild = T2;
    y->height = max(height(y->leftChild), height(y->rightChild)) + 1;
    x->height = max(height(x->leftChild), height(x->rightChild)) + 1;
    return x;
}
Node *leftRotate(Node *x)
{
    Node *y = x->rightChild;
    Node *T2 = y->leftChild;
    y->leftChild = x;
    x->rightChild = T2;
    x->height = max(height(x->leftChild), height(x->rightChild)) + 1;
    y->height = max(height(y->leftChild), height(y->rightChild)) + 1;
    return y;
}
int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->leftChild) - height(N->rightChild);
}

Node *insertNode(Node *node, char *name)
{
    if (node == NULL)
        return (newNode(name));

    int cmp = strcmp(node->name, name);
    if (cmp > 0)
        node->leftChild = insertNode(node->leftChild, name);
    else if (cmp < 0) // Use 'cmp < 0' instead of 'strcmp(node->name, name) > 0'
        node->rightChild = insertNode(node->rightChild, name);
    else
        return node;

    node->height = 1 + max(height(node->leftChild),
                           height(node->rightChild));
    int balance = getBalance(node);
    if (balance > 1 && strcmp(node->leftChild->name, name) > 0)
        return rightRotate(node);
    if (balance < -1 && strcmp(node->rightChild->name, name) < 0) // Use 'strcmp(node->rightChild->name, name) < 0' instead of 'strcmp(node->rightChild->name, name) > 0'
        return leftRotate(node);
    if (balance > 1 && strcmp(node->leftChild->name, name) < 0) // Use 'strcmp(node->leftChild->name, name) < 0' instead of 'strcmp(node->leftChild->name, name) > 0'
    {
        node->leftChild = leftRotate(node->leftChild);
        return rightRotate(node);
    }
    if (balance < -1 && strcmp(node->rightChild->name, name) > 0)
    {
        node->rightChild = rightRotate(node->rightChild);
        return leftRotate(node);
    }
    return node;
}

void printTree(struct Node *root)
{
    if (root != NULL)
    {
        printTree(root->leftChild);
        printf("%s ", root->name);
        printTree(root->rightChild);
    }
}

bool dfs_cycle(int current_account, int start_account, int length, int depth, bool visited[])
{
    if (depth > length)
    {
        return false; // Length exceeded, not a cycle of the given length
    }

    if (visited[current_account])
    {
        if (depth == length && current_account == start_account)
        {
            return true; // Found a cycle of the given length
        }
        return false; // Already visited, but not a cycle
    }

    visited[current_account] = true; // Mark current account as visited

    // Explore all outgoing transactions from the current account
    Bank_trans *p = hash_table[current_account];
    while (p != NULL)
    {
        if (dfs_cycle(p->toacc, start_account, length, depth + 1, visited))
        {
            return true; // Cycle found in the child path
        }
        p = p->next;
    }

    visited[current_account] = false; // Backtrack and mark the current account as unvisited
    return false;
}

// Function to check if there is a transaction cycle of a given length starting from the account
bool inspect_cycle(char account[], int length)
{
    int start_account = hash(account);  // Hash the given account to get the start_account
    bool visited[TABLE_SIZE] = {false}; // Initialize visited array

    // Perform DFS from the start_account with initial depth 1
    return dfs_cycle(start_account, start_account, length, 0, visited);
}

void run()
{
    int count = 0;
    root = NULL;
    char from[NAME];
    int total = 0;
    while (1)
    {
        scanf("%s", from);
        if (strcmp(from, "#") == 0)
            break;
        char to[NAME], timePoint[NAME], ATM[NAME];
        int price;
        scanf("%s %d %s %s", to, &price, timePoint, ATM);
        // for first and second order
        count++;
        total += price;

        int fr = hash(from);
        int tu = hash(to);
        // for third order
        root = insertNode(root, from);
        root = insertNode(root, to);

        Bank_trans *p = (Bank_trans *)malloc(sizeof(Bank_trans));
        p->fromacc = fr;
        p->toacc = tu;
        p->money = price;
        p->next = NULL;
        insert_hash_table(p);
    }

    char cmd[NAME];
    while (1)
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "#") == 0)
            break;
        else if (strcmp(cmd, "?number_transactions") == 0)
        {
            printf("%d", count);
        }
        else if (strcmp(cmd, "?total_money_transaction") == 0)
        {
            printf("%d", total);
        }
        else if (strcmp(cmd, "?list_sorted_accounts") == 0)
        {
            printTree(root);
        }
        else if (strcmp(cmd, "?total_money_transaction_from") == 0)
        {
            char k[NAME];
            scanf("%s", k);
            int in = hash(k);
            Bank_trans *q = hash_table_lookup(in);
            int tong = 0;
            int check = hash(k);
            while (q != NULL)
            {
                if (q->fromacc == check)
                {
                    tong += q->money;
                }
                q = q->next;
            }
            printf("%d\n", tong);
        }
        else if (strcmp(cmd, "?inspect_cycle") == 0)
        {
            int so;
            char ten[NAME];
            scanf("%s %d", ten, &so);
            if (inspect_cycle(ten, so))
            {
                printf("1\n");
            }
            else
                printf("0\n");
        }
    }
}

int main()
{
    init_hash_table();
    run();
    return 0;
}