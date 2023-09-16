#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
    int val;
    struct Node *next;
} Node;
Node *head;

void PrintSol()
{
    Node *p = head;
    while (p != NULL)
    {
        printf("%d ", p->val);
        p = p->next;
    }
}

Node *makeNode(int k)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->val = k;
    p->next = NULL;
    return p;
}

Node *Insert_to_first(int k)
{
    Node *check = head;
    while (check->next != NULL)
    {
        if (check->next->val == k || check->val == k)
        {
            return head;
        }
        check = check->next;
    }
    Node *newnode = makeNode(k);
    newnode->next = head;
    head = newnode;
    return head;
}

Node *ADDlast(int k)
{
    Node *newnode = makeNode(k);

    if (head == NULL)
        head = newnode;
    else
    {
        Node *prev = head;
        while (prev->next != NULL)
        {
            if (prev->val == k)
            {
                free(newnode);
                return head;
            }
            prev = prev->next;
            if (prev->val == k)
            {
                free(newnode);
                return head;
            }
        }
        prev->next = newnode;
    }
    return head;
}

int check(int u, int v)
{
    Node *p = head;
    while (p->next != NULL)
    {
        if (p->val == u)
            return 0;
        p = p->next;
        if (p->val == u)
            return 0;
    }
    Node *h = head;
    while (h->next != NULL)
    {
        if (h->val == v)
            return 1;
        h = h->next;
        if (h->val == v)
            return 1;
    }

    return 0;
}

Node *Addafter(int u, int v)
{
    if (check(u, v))
    {

        Node *newNode = makeNode(u);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *cur = head;
            while (cur != NULL)
            {
                if (cur->val == v)
                {
                    newNode->next = cur->next;
                    cur->next = newNode;
                    break;
                }
                cur = cur->next;
            }
        }
    }
    return head;
}

Node *Addbefore(int u, int v)
{
    if (check(u, v))
    {

        Node *cur = head;
        Node *newnode = makeNode(u);
        while (cur->val != v) // tim vi tri co val = v
        {
            cur = cur->next;
        }
        if (head == NULL)
        {
            head = newnode;
        }
        else if (cur == head)
        {
            head = newnode;
            newnode->next = cur;
        }
        else
        {
            Node *prev = head;
            while (prev->next != cur)
                prev = prev->next;
            prev->next = newnode;
            newnode->next = cur;
        }
    }
    return head;
}

Node *Remove(int v)
{
    Node *del = head;
    if (head == NULL)
        return NULL;
    if (head->val == v)
    {
        Node *tmp = head;
        head = head->next;
        free(tmp);
        return head;
    }

    while (del->next != NULL)
    {
        if (del->next->val == v)
            break;
        del = del->next;
    }

    if (del->next != NULL)
    {
        Node *q = del->next;
        del->next = q->next;
        free(q);
    }
    return head;
}

Node *Reverse()
{
    Node *prev = NULL;
    Node *cur = head;
    Node *next = NULL;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
int main()
{
    int n, k;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &k);
        head = ADDlast(k);
    }
    char trash[20];
    while (1)
    {
        scanf("%s", trash);
        if (strcmp(trash, "#") == 0)
            break;
        if (strcmp(trash, "addlast") == 0)
        {
            int k;
            scanf("%d", &k);
            head = ADDlast(k);
        }
        if (strcmp(trash, "addfirst") == 0)
        {
            int k;
            scanf("%d", &k);
            head = Insert_to_first(k);
        }
        if (strcmp(trash, "addafter") == 0)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            head = Addafter(u, v);
        }
        if (strcmp(trash, "addbefore") == 0)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            head = Addbefore(u, v);
        }
        if (strcmp(trash, "remove") == 0)
        {
            int k;
            scanf("%d", &k);
            head = Remove(k);
        }
        if (strcmp(trash, "reverse") == 0)
        {
            head = Reverse();
        }
    }
    PrintSol();
    return 0;
}