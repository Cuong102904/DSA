#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
    int val;
    struct Node *next;
} Node;
Node *Top;

Node *makeNode(int x)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->next = NULL;
    p->val = x;
    return p;
}

void PrintSol()
{
    while (Top->next != NULL)
    {
        printf("%d\n", Top->val);
        Top = Top->next;
    }
}
` int checkEmpty()
{
    return (Top == NULL);
}

void PUSH(int v)
{
    Node *p = makeNode(v);
    p->next = Top;
    Top = p;
}
int POP()
{
    if (checkEmpty())
    {
        return -1;
    }
    Node *tmp = Top;
    Top = Top->next;
    int res = tmp->val;
    free(tmp);
    return res;
}

int main()
{
    Top = NULL;
    char trash[20];
    int val;
    while ((1))
    {
        scanf("%s", trash);
        if (strcmp(trash, "PUSH") == 0)
        {
            scanf("%d", &val);
            PUSH(val);
        }
        if (strcmp(trash, "POP") == 0)
        {
            if (Top == NULL)
            {
                printf("NULL\n");
            }
            else
            {
                int x = POP();
                printf("%d\n", x);
            }
        }
        if (strcmp(trash, "#") == 0)
        {
            break;
        }
    }
    return 0;
}