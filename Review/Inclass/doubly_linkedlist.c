#include <stdio.h>
#include <stdlib.h>
typedef struct dllist
{
    int val;
    dllist *prev;
    dllist *next;
} dllist;
dllist *head;
dllist *tail;

dllist makeNode(int value)
{
    dllist *p = (dllist *)malloc(sizeof(dllist));
    p->val = value;
    p->next = NULL;
    p->prev = NULL;
}
