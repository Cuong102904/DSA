#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Q 1000000007

typedef struct value
{
    int val;
    char c;
} value;

typedef struct Node
{
    struct value val;
    struct Node *next;
} Node;
Node *Top1;
Node *Top2;
char trash[100000006];
int KetQua = 0;

Node *makeNode(int x, char A)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->next = NULL;
    p->val.val = x;
    p->val.c = A;
    return p;
}

int checkEmpty(Node *Top)
{
    return (Top == NULL);
}

void PUSH2(int v)
{
    Node *p = makeNode(v, 0);
    p->next = Top2;
    Top2 = p;
}

void PUSH1(char c)
{
    Node *p = makeNode(0, c);
    p->next = Top1;
    Top1 = p;
}

int POP2()
{
    if (checkEmpty(Top2))
        return ' ';
    Node *tmp = Top2;
    Top2 = Top2->next;
    int res = tmp->val.val;
    free(tmp);
    return res;
}
char POP1()
{
    if (checkEmpty(Top1))
        return ' ';
    Node *tmp = Top1;
    Top1 = Top1->next;
    char res = tmp->val.c;
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
    }
    return ans;
}

int check()
{
    int first, second, tong;
    for (int i = 0; i < strlen(trash); i++)
    {
        if (trash[i] <= '9' && trash[i] >= '0')
        {
            {
                int b = i;
                int num = 0;
                while (b < strlen(trash) && trash[b] >= '0' && trash[b] <= '9')
                {
                    num = (num * 10 + (trash[b] - '0')) % Q;
                    b++;
                }
                i = b;
                PUSH2(num);
            }
        }
        if (trash[i] == '(' || CheckOperator(trash[i]) == 1)
        {
            PUSH1(trash[i]);
        }
        else
        {
            if (checkEmpty(Top2))
            {
                return 0;
            }
            else
            {
                first = POP2();
                second = POP2();
                tong = do_op(second, first, POP1());
                POP1();
                PUSH2(tong);
            }
        }
    }

    return POP2();
}

int main()
{
    scanf("%s", trash);
    int sum = check();
    printf("%d", sum);
    return 0;
}