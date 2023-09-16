#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Q 1000000007

typedef struct value
{
    int val;
} value;

typedef struct Node
{
    struct value val;
    struct Node *next;
} Node;
Node *Top;
char trash[100000006];
int KetQua = 0;

Node *makeNode(int x)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->next = NULL;
    p->val.val = x;
    return p;
}

int checkEmpty(Node *Top)
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
    if (checkEmpty(Top))
        return ' ';
    Node *tmp = Top;
    Top = Top->next;
    int res = tmp->val.val;
    free(tmp);
    return res;
}
void check()
{
    scanf("%s", trash);
    long k = 0;
    long v = 0;
    long first, second, tong;
    for (int i = 0; i < strlen(trash); i++)
    {
        if (trash[i] <= '9' && trash[i] >= '0')
        {
            {
                int b = i;
                long num = 0;
                while (b < strlen(trash) && trash[b] >= '0' && trash[b] <= '9')
                {
                    num = (num * 10 + (trash[b] - '0')) % Q;
                    b++;
                }
                i = b;
                PUSH(num);
            }
        }
        if (v)
        {
            first = POP();
            second = POP();
            tong = ((first % Q) * (second % Q)) % Q;
            PUSH(tong);
            v = 0;
        }
        else if ((trash[i] == '+' && trash[i + 1] == '*') || (trash[i] == '*' && trash[i + 1] == '+'))
        {
            printf("NOT_CORRECT");
            return;
        }
        if (trash[i] == '+')
            k++;
        if (trash[i] == '*')
            v = 1;
    }
    while (k != 0)
    {
        first = POP();
        second = POP();
        tong = (first + second) % Q;
        PUSH(tong);
        k--;
    }
    printf("%ld", POP());
}

int main()
{
    check();

    return 0;
}