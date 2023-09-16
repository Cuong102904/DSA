#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char c;
    struct Node *next;
} Node;

Node *MakeNode(char x)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->next = NULL;
    p->c = x;
    return p;
}
Node *top;
char s[10000006];
void Push(char c)
{
    Node *p = MakeNode(c);
    p->next = top;
    top = p;
}
char pop()
{
    if (top == NULL)
    {
        return ' ';
    }
    Node *tmp = top;
    top = top->next;
    char res = tmp->c;
    free(tmp);
    return res;
}
int match(char a, char b)
{

    if (a == '(' && b == ')')
        return 1;

    if (a == '[' && b == ']')
        return 1;

    if (a == '{' && b == '}')
        return 1;

    return 0;
}

int check(char *s)
{

    for (int i = 0; i < strlen(s); i++)
    {

        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {

            Push(s[i]);
        }
        else
        {

            if (top == NULL)
                return 0;

            char o = pop();

            if (!match(o, s[i]))
                return 0;
        }
    }
    return top == NULL;
}

int main()
{
    scanf("%s", &s);
    int result = check(s);
    printf("%d", result);
    return 0;
}
