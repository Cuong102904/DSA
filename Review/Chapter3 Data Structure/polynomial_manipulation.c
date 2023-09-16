#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int coef;
    int exp;
    struct Node *next;
} Node;

Node *head;

Node *makenode(int u, int v)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->coef = u;
    p->exp = v;
    p->next = NULL;
    return p;
}

int main()
{
}
