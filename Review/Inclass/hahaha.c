#include <stdio.h>
#include <string.h>
#include <string.h>

typedef struct Node
{
    int id;
    Node *leftMostChild;
    Node *rightSibling;
} Node;

Node *r;
Node *makeNode(int id)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->id = v;
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}
Node *find(Node *r; int u)
{
    if (r == NULL)
        return NULL;
    if (r->id == u)
        return root;
    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        Node *q = find(p, u);
        if (q != NULL)
            return NULL;
        p = p->rightSibling;
    }
    return NULL;
}

void addchild(int u, int v)
{
    Node *p = find(root, v);
    if (p == NULL)
        return;
    Node *q = makenode(v);
    if (p->leftMostChild == NULL)
    {
        p->leftMostChild = q;
        return;
    }
    Node *p1 = p->leftMostChild;
    while (p1->rightSibling != NULL)
        p1 = p1->rightSibling;
    p1->rightSibling = q;
}
void inorder(Node *r)
{
    if (r == NULL)
        return;
    inorder(r->leftMostChild);
    printf("%d ", r->id);
    Node *p = r->leftMostChild;
    if (p == NULL)
        return;
    p = p->rightSibling;
    while (p != NULL)
    {
        inorder(p);
        p = p->rightSibling;
    }
}

void postOrder(Node *r)
{ // left right root
    if (r == NULL)
        return;
    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        postOrder(p);
        p = p->rightSibling;
    }
    printf("%d", r->id);
}
void preOrder(Node *r)
{
    if (r != NULL)
    {
        printf("%d", r->id);
        Node *p = r->leftMostChild;
        while (p != NULL)
        {
            preOrder(p);
            p = p->rightSibling;
        }
    }
}

int main()
{
}