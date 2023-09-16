#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int row;
    int col;
    int step;
    struct Node *next;
} Node;

Node *MakeNode(int row, int col, int step)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->next = NULL;
    p->row = row;
    p->col = col;
    p->step = step;
    return p;
}

Node *first;
Node *last;
int Isempty()
{
    return first == NULL && last == NULL;
}

void push(int r, int c)
{
    Node *p = MakeNode(v);
    if (Isempty())
    {
        first = p;
        last = p;
        return;
    }
    last->next = p;
    last = p;
}
int pop()
{
    if (Isempty())
        return -1;
    Node *tmp = first;
    first = first->next;
    int v = tmp->value;
    free(tmp);
    if (first == NULL)
        last = NULL;
    return v;
}
int main()
{
    //  freopen("TEST_QUEUE.txt", "r", stdin);
    char trash[5];
    while (1)
    {
        scanf("%s", trash);

        if (strcmp(trash, "PUSH") == 0)
        {
            int x;
            scanf("%d", &x);
            push(x);
        }
        if (strcmp(trash, "POP") == 0)
        {
            if (first == NULL && last == NULL)
            {
                printf("NULL\n");
            }
            else
            {
                int v = pop();
                printf("%d\n", v);
            }
        }
        if (strcmp(trash, "#") == 0)
            break;
    }
    return 0;
}
