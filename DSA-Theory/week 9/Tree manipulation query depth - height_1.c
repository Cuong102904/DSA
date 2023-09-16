#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node
{
    int id;
    struct Node *leftMostChild;
    struct Node *rightSibling;
    struct Node *parent;
} Node;
Node *r;

Node *makeNode(int id)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->id = id;
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    p->parent = NULL;
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
    q->parent = p;
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

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

// int height(Node *p)
// {
//     if (p == NULL)
//         return 0;
//     int lDepth = height(p->leftMostChild);
//     int rDepth = height(p->rightSibling);
//     return max(lDepth, rDepth) + 1;
// }

int height(Node *p)
{

    if (p == NULL)
        return 0;

    int maxH = 0;

    Node *q = p->leftMostChild;

    while (q != NULL)
    {
        int h = height(q);

        maxH = maxH < h ? h : maxH;

        q = q->rightSibling;
    }

    return maxH + 1;
}

int depth(Node *r)
{
    Node *p = r;
    int k = 1;
    while (p->parent != NULL)
    {
        p = p->parent;
        k++;
    }
    return k;
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
        else if (strcmp(cmd, "Depth") == 0)
        {
            int val;
            scanf("%d", &val);
            Node *tim = find(r, val);
            printf("%d\n", depth(tim));
        }
        else if (strcmp(cmd, "Height") == 0)
        {
            int val;
            scanf("%d", &val);
            Node *tim = find(r, val);
            printf("%d\n", height(tim));
        }
    }
    return 0;
}