/*
Ask the user to enter an integer n, then enter nintegers numbers from the keyboard.
Each time an integer is read, insert it at the beginning of a linked list.
Finally, prints on the screen all values stored in that linked list
  Example:
   enter n =4;
   Enter the number 1: 8
   Enter the number 2:  2
   Enter the number 3: 3
   Values in the linked list: 3 2 8*/

// have new node at the beginning of the list

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
    /*Node *cur = head;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }*/
    Node *cur = head;
    for (cur = head; cur != NULL; cur = cur->next)
    {
        printf("%d ", cur->val);
    }
}
Node *Insert_Toread(Node *head, int X)
{
    Node *new_node = makeNode(X);
    new_node->next = head;
    head = new_node;
    return head;
}

void Insert_toRead1(Node **head_ref, int X) // gan head theo tham chieu
{
    Node *new_node = makeNode(X);
    new_node->next = *head_ref;
    *head_ref = new_node;
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
        head = Insert_Toread(head, X);
        // Insert_toRead1(&head, X); // gan head in another way
    }
    printf("Values in the linked list: ");
    printlist(head);
}
