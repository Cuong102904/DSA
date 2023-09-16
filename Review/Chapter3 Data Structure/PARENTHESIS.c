#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char val;
    struct Node *next;
} Node;
Node *Top;
char trash[100000006];

Node *makeNode(char x)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->next = NULL;
    p->val = x;
    return p;
}

int checkEmpty()
{
    return (Top == NULL);
}

void PUSH(char v)
{
    Node *p = makeNode(v);
    p->next = Top;
    Top = p;
}
char POP()
{
    if (checkEmpty())
    {
        return ' ';
    }
    Node *tmp = Top;
    Top = Top->next;
    char res = tmp->val;
    free(tmp);
    return res;
}

int isPair(char open, char close)
{
    if (open == '(' && close == ')')
        return 1;
    if (open == '[' && close == ']')
        return 1;
    if (open == '{' && close == '}')
        return 1;
    return 0;
}

int check()
{
    for (int i = 0; i <= strlen(trash) - 1; i++)
    {
        if (trash[i] == '[' || trash[i] == '(' || trash[i] == '{')
        {
            PUSH(trash[i]);
        }
        else
        {
            if (Top == NULL)
            {
                return 0;
            }
            char o = POP();
            if (!isPair(o, trash[i]))
                return 0;
        }
    }
    return Top == NULL;
}

int main()
{
    Top = NULL;
    scanf("%s", trash);
    int result = check();
    printf("%d", result);
    return 0;
}