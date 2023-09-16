#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Q 1000000007

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

Node *Top1 = NULL;
Node *Top2 = NULL;
char trash[100000006];

Node *makeNode(int x)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->next = NULL;
    p->val = x;
    return p;
}

int checkEmpty(Node *Top)
{
    return (Top == NULL);
}

void PUSH(int v, Node **Top)
{
    Node *p = makeNode(v);
    p->next = *Top;
    *Top = p;
}

int POP(Node **Top)
{
    if (checkEmpty(*Top))
    {
        return ' ';
    }
    Node *tmp = *Top;
    *Top = (*Top)->next;
    int res = tmp->val;
    free(tmp);
    return res;
}

int CheckOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int do_op(int a, int b, char op)
{
    int ans;
    switch (op)
    {
    case '+':
        ans = a + b;
        break;
    case '-':
        ans = a - b;
        break;
    case '*':
        ans = a * b;
        break;
    case '/':
        ans = a / b;
        break;
    }
    return ans;
}

int check()
{
    int first, second, c;
    for (int i = 0; i <= strlen(trash) - 1; i++)
    {
        if (trash[i] == '(' || CheckOperator(trash[i]) == 1)
        {
            PUSH(trash[i], &Top1);
        }
        if (trash[i] <= '9' && trash[i] >= '0')
        {
            int b = i;
            int num = 0;
            while (b < strlen(trash) && trash[b] >= '0' && trash[b] <= '9')
            {
                if (CheckOperator(trash[b]) == 1)
                    break;
                num = (num * 10 + (trash[b] - '0')) % Q;
                b++;
            }
            PUSH(num, &Top2);
        }
        if (CheckOperator(trash[i]) == 1)
        {
            if (Top2 == NULL)
            {
                return 0;
            }
            else if (Top2->next == NULL)
            {
                return 0;
            }
            else
            {
                first = POP(&Top2);
                second = POP(&Top2);
                c = do_op(first, second, trash[i]);
                PUSH(c, &Top2);
            }
        }
    }
    return POP(&Top2);
}

int main()
{
    scanf("%s", trash);
    printf("%d", check());

    return 0;
}
