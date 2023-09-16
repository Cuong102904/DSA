#include <stdio.h>
#include <stdlib.h>
typedef struct treeNode
{
    int val;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;
treeNode *Root;
treeNode *makeNode(int val)
{
    treeNode *newnode = (treeNode *)malloc(sizeof(treeNode));
    newnode->val = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void freeTRee(treeNode *Root)
{
    if (Root == NULL)
        return;
    freeTRee(Root->left);
    freeTRee(Root->right);
    free(Root);
}

void PrintInorder(treeNode *Root)
{
    if (root != NULL)
    {
        PrintInorder(Root->left);
        printf("%d ", root->val);
        PrintInorder(Root->right);
    }
}

void PrintPostOrder(treeNode *Root)
{
    if (Root != NULL)
    {
        PrintPostOrder(Root->left);
        PrintPostOrder(Root->right);
        printf("%d", Root->val);
    }
}

treeNode *insertNode(treeNode *Root, int val, bool LEFT)
{
    treeNode *p = makeNode(val);
    if (Root->left == NULL)
        Root->left = p;
    if (Root == NULL)
        return p;
    if (LEFT == 1)
    {
        treeNode *leftmost = Root;
        while (leftmost->left != NULL)
            leftmost = leftmost->left;
        leftmost->left = p;
    }
    else
    {
        treeNode *rightmost = Root;
        while (rightmost->right != NULL)
            rightmost = rightmost->right;
        rightmost->right = p;
    }
    return Root;
}

int main()
{
}