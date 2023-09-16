#include <stdio.h>

typedef struct Node
{
    int data;
    struct node *next;
} Node;
// Node *head;

Node *makeNode(int k)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = k;
    p->next = NULL;
    return p;
}

void printlist(Node *head)
{
    Node *cur = head;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}
int main()
{
    Node *node1 = makeNode(1);
    Node *node2 = makeNode(2);
    Node *node3 = makeNode(3);
    node1->next = node2;
    node2->next = node3;
    printlist(node1);
}
