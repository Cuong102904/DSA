#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct Node
{
    int val;
    struct Node *leftmost;
    struct Node *rightsiblings;
} Node;

Node *makeNode(int val)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->val = val;
    p->leftmost = NULL;
    p->rightsiblings = NULL;
    return p;
}
Node *Insert(Node *root, int data)
{
    if (root == NULL)
    {
        root = makeNode(data);
        return root;
    }
    Node *newnode = makeNode(data);

    if (root->val <= data)
    {
        root->rightsiblings = Insert(root->rightsiblings, data);
    }
    else
    {
        root->leftmost = Insert(root->leftmost, data);
    }
    return root;
}

bool Search(Node *root, int key)
{
    if (root == NULL)
        return false;
    if (root->val == key)
        return true;
    else if (root->val < key)
        return Search(root->rightsiblings, key);
    else
        return Search(root->leftmost, key);
}

void PreOrder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->val);
        PreOrder(root->leftmost);
        PreOrder(root->rightsiblings);
    }
}

Node *findmax(Node *root)
{
    if (root != NULL)
    {
        while (root->rightsiblings != NULL)
            root = root->rightsiblings;
        return root;
    }
}

Node *Predecessor(Node *r, Node *x)
{
    if (x->leftmost != NULL)
    {
        return findmax(x->leftmost);
    }
    Tr
}

int main()
{
    freopen("20.txt", "r", stdin);
    Node *root = NULL;
    while (1)
    {
        char lenh[20];
        scanf("%s", lenh);
        if (strcmp(lenh, "#") == 0)
            break;

        else
        {
            int ans;
            scanf("%d", &ans);
            if (Search(root, ans) == false)
            {
                root = Insert(root, ans);
            }
        }
    }
    PreOrder(root);
    return 0;
}
