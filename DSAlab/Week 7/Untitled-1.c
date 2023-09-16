
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100000

typedef struct
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

Node *insertLastRecursive(Node *head, int X)
{
    if (head == NULL)
        return makeNode(X);
    head->next = insertLastRecursive(head->next, X);
    return head;
}

void printlist(Node *head)
{
    Node *cur = head;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

Node *Remove(Node *head, int X)
{
    if (head == NULL)
        return NULL;
    if (head->data == X)
    {
        Node *tmp = head;
        head = head->next;
        free(tmp);
        return head;
    }
    head->next = Remove(head->next, X);
    return head;
}

Node *insertafter(Node *head, int u, int v)
{
    if (head == NULL)
        return NULL;
    if (head->data == v)
    {
        Node *p = makeNode(u);
        p->next = head->next;
        head->next = p;
        return head;
    }
    head->next = insertafter(head->next, u, v);
}

Node *insertBefore(Node *head, int u, int v)
{
    if (head == NULL)
        return NULL;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        head = insertLastRecursive(head, i);
    }
    printlist(head);

    char trash[100];
    int value;
    while (1)
    {
        scanf("%s", trash);
        if (strcmp(trash, "#") == 0)
            break;
        else if (strcmp(trash, "addlast") == 0)
        {
            scanf("%d", &value);
        }
        else if (strcmp(trash, "addlast") == 0)
        {
            printf("1");
        }
        else if (strcmp(trash, "addfirst") == 0)
        {
            printf("1");
        }
        else if (strcmp(trash, "addafter") == 0)
        {
            printf("1");
        }
        else if (strcmp(trash, "addbefore") == 0)
        {
            printf("1");
        }
        else if (strcmp(trash, "remove") == 0)
        {
            scanf("%d", &value);
            Remove(head, value);
        }
        else if (strcmp(trash, "reverse") == 0)
        {
            printf("1");
        }
    }

    return 0;
}