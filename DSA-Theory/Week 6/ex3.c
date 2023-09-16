// them nut moi vao sau nut cur
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

Node *Insert_After(Node *cur, int X)
{
    Node *new_node = makeNode(X);
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        new_node->next = cur->next;
        cur->next = new_node;
    }
    return new_node;
}

Node *InsertBefore(Node *head, Node *cur, int X)
{
    Node *newNode = makeNode(X);
    if (head == NULL)
        head = newNode;
    else if (cur == head)
    {
        head = newNode;
        newNode->next = cur;
    }
    else
    {
        // determine the previous node of cur:
        Node *prev = head;
        while (prev->next != cur)
        {
            prev = prev->next;
        }
        prev->next = newNode;
        newNode->next = cur;
    }
    return head;
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
        Insert_toRead1(&head, X); // gan head in another way
    }
    printf("Values in the linked list: ");
    printlist(head);
}