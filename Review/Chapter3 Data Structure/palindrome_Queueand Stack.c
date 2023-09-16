#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
    char c;
    struct Node *next;
} Node;

Node *last;
Node *first;
Node *Top;
Node *makeNode(char val)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->c = val;
    p->next = NULL;
    return p;
}

int isEmpty() return first == NULL && last == NULL;

void Push_Queue(char val)
{
    Node *newnode = makeNode(val);
    if (isEmpty())
    {
        first = newnode;
        last = newnode;
    }
    else
    {
        last->next = newnode;
        last = newnode;
    }
}

char Pop_Queue()
{
    if (isEmpty())
        return -1;
    char res = first->c;
    Node *tmp = first;
    first = first->next;
    free(tmp);
    if (first == NULL)
        last = NULL;
    return res;
}

// stack

int IsEmpty() return Top == NULL;

void Push_Stack(char c)
{
    Node *p = makeNode(c);
    p->next = Top;
    Top = p;
}

char Pop_Stack()
{
    if (IsEmpty())
        return -1;
    char res = Top->c;
    Node *tmp = Top;
    Top = Top->next;
    free(tmp);
    return res;
}

int checkketqua(trash)
{
    char a;
    char b;
    int count;
    for (int i = 0; i < strlen(trash); i++)
    {
        Push_Queue(trash[i]);
        Push_Stack(trash[i]);
    }
    while (Top != NULL)
    {
        count = 0;
        a = Pop_Queue();
        b = Pop_Stack();
        if (a != b)
        {
            printf("This is not Palindrome\n");
            break;
        }
        count++;
    }
    return count;
}

int main()
{
    last = NULL;
    first = NULL;
    Top = NULL;
    char trash[10000];
    scanf("%s", trash);
    int dem = checkketqua(trash);
    if (dem == 1)
        printf("This is Palindrome\n");
    return 0;
}