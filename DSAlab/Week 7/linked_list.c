#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
	int value;
	struct Node *next;
} Node;

Node *head;

Node *makenode(int k)
{
	Node *p = (Node *)malloc(sizeof(Node));
	p->value = k;
	p->next = NULL;
	return p;
}

void printlist(Node *head)
{
	Node *p = head;
	while (p != NULL)
	{
		printf("%d ", p->value);
		p = p->next;
	}
	printf("\n");
}

Node *InserttoFirst(Node *head, int x)
{
	Node *newnode = makenode(x);
	newnode->next = head;
	head = newnode;
	return head;
}
Node *InserttoLast(Node *head, int x)
{
	Node *newnode = makenode(x);
	if (head == NULL)
	{
		head = newnode;
	}
	else
	{
		Node *last = head;
		while (last->next != NULL)
			last = last->next;
		last->next = newnode;
	}
	return head;
}
Node *addafter(Node *head, int u, int v)
{
	if (head == NULL)
		return NULL;
	Node *cur = head;
	while (1)
	{ // check v exist or not?
		cur = cur->next;
		if (cur == NULL && cur->value == v)
			return head;
	}
	if (head->value == v)
	{
		Node *p = makenode(u);
		p->next = head->next;
		head->next = p;
	}
	head->next = addafter(head->next, u, v);
	return head;
}

Node *addbefore(Node *head, int u, int v)
{
	Node *cur = head;
	Node *prev = NULL;
	while (cur != NULL && cur->value != v)
	{ // check v exist or not?
		prev = cur;
		cur = cur->next;
	}
	if (cur == NULL)
		return head; // check u in head or not?
	Node *check = head;
	while (check != NULL)
	{
		if (check->value == u)
			break;
		check = check->next;
	}
	Node *newnode = makenode(u);
	prev->next = newnode;
	newnode->next = cur;
	return head;
}

Node *Remove(Node *head, int k)
{
	if (head == NULL)
		return NULL;
	if (head->value == k)
	{
		Node *tmp = head;
		head = head->next;
		free(tmp);
		return head;
	}
	head->next = Remove(head->next, k);
	return head;
}

Node *Reverse(Node *head)
{
	Node *prev = NULL;
	Node *cur = head;
	Node *next = NULL;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}

int main()
{
	int n;
	scanf("%d", &n);
	int i;
	int k;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &k);
		head = InserttoLast(head, k);
	}
	char trash[20];
	while (1)
	{
		scanf("%s", trash);
		if (strcmp(trash, "#") == 0)
			break;

		if (strcmp(trash, "addlast") == 0)
		{
			int k;
			scanf("%d", &k);
			InserttoLast(head, k);
		}
		if (strcmp(trash, "addfirst") == 0)
		{
			int k;
			scanf("%d", &k);
			InserttoFirst(head, k);
		}
		if (strcmp(trash, "addafter") == 0)
		{
			int v, u;
			scanf("%d %d", &u, &v);
			addafter(head, u, v);
		}
		if (strcmp(trash, "addafter") == 0)
		{
			int v, u;
			scanf("%d %d", &u, &v);
			addbefore(head, u, v);
		}
		if (strcmp(trash, "remove") == 0)
		{
			int k;
			scanf("%d", &k);
			Remove(head, k);
		}
		if (strcmp(trash, "reverse") == 0)
		{
			Reverse(head);
		}
	}

	printlist(head);

	/* int i;
	for(i=1; i<=5; i++){
		head = InserttoLast(head,i);
	}
	head = addafter(head,11,3);
	printlist(head);
	head = addbefore(head,7,3);
	printlist(head);
	head =Remove(head,11);
	printlist(head);
	head = Reverse(head);
	printlist(head); */

	return 0;
}
