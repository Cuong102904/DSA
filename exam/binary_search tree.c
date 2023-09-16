#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node
{
    int val;
    struct Node *leftmost;
    struct Node *rightsiblings;
} Node;
Node *root;

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

Node *remove_Node(Node *root)
{
    if (root->leftmost == NULL)
    {
        struct Node *temp = root->rightsiblings;
        free(root);
        return temp;
    }
    else if (root->rightsiblings == NULL)
    {
        struct Node *temp = root->leftmost;
        free(root);
        return temp;
    }
    else
    {
        Node *currPar = root;
        Node *succParent = root;

        // Find successor
        struct Node *succ = root->rightsiblings;
        while (succ->leftmost != NULL)
        {
            succParent = succ;
            succ = succ->leftmost;

            if (succParent != root)
                succParent->leftmost = succ->rightsiblings;
            else
                succParent->rightsiblings = succ->rightsiblings;

            // Copy Successor Data to root
            root->val = succ->val;

            // Delete Successor and return root
            free(succ);
            return root;
        }
    }
}

Node *remove1(Node *root, int k)
{
    if (root == NULL)
        return NULL;
    if (root->val == k)
        return remove_Node(root);
    else if (root->val < k)
        root->rightsiblings = remove1(root->rightsiblings, k);
    else
        root->leftmost = remove1(root->leftmost, k);
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

int main()
{
    root = NULL;
    root = Insert(root, 5);
    root = Insert(root, 7);
    root = Insert(root, 22);
    root = Insert(root, 10);
    root = Insert(root, 4);

    if (Search(root, 10))
    {
        printf("done!");
    }

    return 0;
}
