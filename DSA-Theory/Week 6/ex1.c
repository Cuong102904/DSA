/*A sequence of integers is stored by a singly linked list.
a.  Create a list stored 3 integers: 1, 2, 3
b.  Print the list of these 3 integers
typedef struct Node
{
    int data;struct Node *next;
}Node;
Node *head;*/

#include <stdio.h>

typedef struct Node
{
    int data;
    struct node *next;
} Node;
Node *head;

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
Node *Insert_Toread(Node *head, int X)
{
    Node *new_node = makeNode(X);
    new_node->next = head;
    head = new_node;
    return head;
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
