#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
    int value;
    struct Node *next;
} Node;
Node *top;

Node *MakeNode(int x)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->next = NULL;
    p->value = x;
    return p;
}

int Isempty()
{
    return (top == NULL);
}

void Push(int x)
{
    Node *p = MakeNode(x);
    p->next = top;
    top = p;
}
int pop()
{
    if (Isempty())
    {
        return -1;
    }
    Node *tmp = top;
    top = top->next;
    int res = tmp->value;
    free(tmp);
    return res;
}
int main()
{
    top = NULL;
    char trash[5];
    while (1)
    {
        scanf("%s", trash);

        if (strcmp(trash, "PUSH") == 0)
        {
            int x;
            scanf("%d", &x);
            Push(x);
        }
        if (strcmp(trash, "POP") == 0)
        {
            if (top == NULL)
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
