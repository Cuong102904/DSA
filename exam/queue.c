#include <stdio.h>
// queue
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	int val;
	struct Node *next;
} Node;
Node *first;
Node *last;

Node *makeNode(int v)
{
	Node *p = (Node *)malloc(sizeof(Node));
	p->val = v;
	p->next = NULL;
	return p;
}

int isEmpty()
{
	return first == NULL && last == NULL;
}

void Push(int v)
{
	Node *newnode = makeNode(v);
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

int Pop()
{
	if (isEmpty())
	{
		return -1;
	}
	int res;
	Node *tmp = first;
	res = first->val;
	first = first->next;
	free(tmp);
	if (first == NULL)
		last = NULL;
	return res;
}

int main()
{
	first = NULL;
	last = NULL;
	char trash[20];
	while (1)
	{
		scanf("%s", trash);
		if (strcmp(trash, "POP") == 0)
		{
			if (first == NULL && last == NULL)
			{
				printf("NULL\n");
			}
			else
			{
				int c = Pop();
				printf("%d\n", c);
			}
		}
		if (strcmp(trash, "PUSH") == 0)
		{
			int gtri;
			scanf("%d", &gtri);
			Push(gtri);
		}
		if (strcmp(trash, "#") == 0)
		{
			break;
		}
	}
	return 0;
}
