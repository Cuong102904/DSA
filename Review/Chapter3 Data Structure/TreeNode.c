#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
    p->id = id;
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}

Node *find(Node *r, int u)
{
    if (r == NULL)
        return NULL;
    if (r->id == u)
        return r;
    Node *p = r->leftMostChild;

    while (p != NULL)
    {
        Node *q = find(p, u);
        if (q != NULL)
            return q;
        p = p->rightSibling;
    }
    return NULL;
}

void addchild(int u, int v)
{
    Node *p = find(r, v);
    if (p == NULL)
        return;
    Node *q = makeNode(u);
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

void preOrder(Node *r)
{
    if (r == NULL)
        return;
    printf("%d ", r->id);
    for (Node *p = r->leftMostChild; p != NULL; p = p->rightSibling)
    {
        preOrder(p);
    }
}

void postOrder(Node *r)
{
    if (r == NULL)
        return;
    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        postOrder(p);
        p = p->rightSibling;
    }
    printf("%d ", r->id);
}

int main()
{

    char cmd[50];
    int u, v;
    while (1)
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "*") == 0)
            break;

        else if (strcmp(cmd, "MakeRoot") == 0)
        {
            scanf("%d", &v);
            r = makeNode(v);
        }
        else if (strcmp(cmd, "Insert") == 0)
        {
            scanf("%d %d", &u, &v);
            addchild(u, v);
        }
        else if (strcmp(cmd, "InOrder") == 0)
        {
            inorder(r);
            printf("\n");
        }
        else if (strcmp(cmd, "PreOrder") == 0)
        {
            preOrder(r);
            printf("\n");
        }
        else if (strcmp(cmd, "PostOrder") == 0)
        {
            postOrder(r);
            printf("\n");
        }
    }
    return 0;
}
