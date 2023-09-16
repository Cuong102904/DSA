#include <stdio.h>

typedef struct treeNode
{
    int data;
    struct treeNode *Leftmost_child;
    struct treeNode *Right_sibling;
} treeNode;
treeNode *Root;
void preOrder(treeNode *Root)
{
    if (Root != NULL)
    {
        printf("%d", Root->data);
        treeNode *p = Root->Leftmost_child;
        while (p != NULL)
        {
            preOrder(p);
            p = p->Right_sibling;
        }
    }
}
void inOrder(treeNode *Root)
{ // left root right
    if (Root != NULL)
    {
        treeNode *p = Root->Leftmost_child;
        inOrder(p);
        printf("%d", Root->data);
        if (p != NULL)
            p = p->Right_sibling;
        while (p != NULL)
        {
            inOrder(p);
            p = p->Right_sibling;
        }
    }
}
void postOrder(treeNode *Root)
{ // left right root
    if (Root == NULL)
        return;
    treeNode *p = Root->Leftmost_child;
    while (p != NULL)
    {
        postOrder(p);
        p = p->Right_sibling;
    }
    printf("%d", Root->data);
}

int countNode(treeNode *Root)
{
    if (Root == NULL)
        return 0;
    int result = 0;
    result++;
    treeNode *p = Root->Leftmost_child;
    while (p != NULL)
    {
        result += countNode(p);
        p = p->Right_sibling;
    }
    return result;
}

int countLeaves(treeNode *Root)
{
    if (Root == NULL)
        return 0;
    int count = 0;
    treeNode *p = Root->Leftmost_child;
    if (p == NULL)
        count++;
    while ((p != NULL))
    {
        count += countLeaves(p);
        p = p->Right_sibling;
    }
    return count;
}

int heightNode(treeNode *p)
{
    //=1+max of heightNodes(child of p)
}