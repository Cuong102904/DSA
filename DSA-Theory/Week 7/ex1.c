// them nut moi vao sau nut cur
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

Node *Insert_TOLast(Node *head, int X)
{
    Node *new_node = makeNode(X);
    if (head == NULL)
        head = new_node;
    else
    {
        Node *last = head;
        while (last->next != NULL)
            last = last->next;
        // for (last = *head; last->next != NULL; last = last->next);  dung ham for
        // last->next = new_node;
    }
    return head;
}
void Insert_toLast1(Node **head_ref, int X)
{
    Node *new_node = makeNode(X);
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
    {
        Node *last = *head_ref;
        for (last = *head_ref; last->next != NULL; last = last->next)
            ;
        last->next = new_node;
    }
}

Node *deleteList(Node *head)
{
    Node *del;
    del = head;
    while (del != NULL)
    {
        head = head->next;
        free(del);
        del = head;
    }
    return head;
}
int IsEmty(Node *head)
{
    if (head == NULL)
        return 1;
    else
        return 0;
}

int CountNode(Node *head, int v)
{
    int count = 0;
    Node *a = head;
    while (a != NULL)
    {
        if (a->data >= v)
            count++;
        head = head->next;
        a = head;
    }
    return count;
}

int main()
{
    int X;
    int n;
    Node *head = NULL;
    printf("Enter n: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("Enter the number %d: ", i);
        scanf("%d", &X);
        // head = Insert_Toread(head, X);
        // Insert_toLast1(&head, X);
        head = Insert_TOLast(head, X);
    }
    printf("Values in the linked list: ");
    printlist(head);
}