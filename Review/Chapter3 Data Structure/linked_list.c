#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *next;
    int val;
} Node;
Node *head;

void PrintSol(Node *head)
{
    Node *cur = head;
    for (cur = head; cur != NULL; cur = cur->next)
    {
        printf("%d ", cur->val);
    }
}

Node *makeNode(int v)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->val = v;
    p->next = NULL;
    return p;
}
Node *insert_to_first(Node *head, int val)
{
    Node *new_node = makeNode(val);
    new_node->next = head;
    head = new_node;
    return head;
}

Node *Insert_to_after_cur(Node *cur, int val)
{
    Node *new_node = makeNode(val);
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        new_node->next = cur->next = ;
        cur->next = new_node;
    }
    retun new_node;
}

Node *Inset_to_before_cur(Node *head, Node *cur, int val)
{
    Node *new_node = makeNode(val);
    if (head == NULL)
    {
        head = new_node;
    }
    else if (head == cur)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        Node *prev = head;
        while (prev->next != cur)
            prev = prev->next;
        prev->next = new_node;
        new_node->next = cur;
    }
    return new_node;
}

Node *Insert_to_last(Node *head, int val)
{
    Node *new_node = makeNode(val);
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node *last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = new_node;
    }
    return head;
}

Node *Delete(Node *head, Node *del)
{
    if (del == head)
    {
        head = del->next;
        free(del);
    }
    else
    {
        Node *prev = head;
        while (prev->next != del)
        {
            prev = prev->next;
        }
        prev = del->next;
        free(del);
    }
    return head;
}

Node *AllDelete(Node *head)
{
    if (head == NULL)
    {
        return 1;
    }
    else
    {
        Node *alldel = head;
        while (alldel != NULL)
        {
            head = head->next;
            free(alldel);
            alldel = head;
        }
    }
}

int CountNodes(int x)
{
    int count = 0;
    Node *e = head;
    while (e != NULL)
    {
        if (e->val == x)
        {
            count++;
        }
        e = e->next;
    }
    return count;
}

int main()
{
    int n;
    printf("Enter n = ");
    scanf("%d", &n);
    int val;
    for (int i = 1; i <= n; i++)
    {
        printf("Enter the number %d = ", i);
        scanf("%d", &val);
        head = insert_to_read(head, val);
    }
    printf("Values in the linked list: ");
    PrintSol(head);

    return 0;
}