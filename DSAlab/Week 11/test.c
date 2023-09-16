#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 100
typedef struct Node
{
	char name[LEN];
	struct Node *parent;
	struct Node *leftMostChild;
	struct Node *rightSibling;
} Node;
Node *nodes[LEN];
int n;

Node *find(char *name)
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(name, nodes[i]->name) == 0)
			return nodes[i];
	}
	return NULL;
}
Node *addNode(char *name)
{
	Node *p = (Node *)malloc(sizeof(Node));
	strcpy(p->name, name);
	p->leftMostChild = NULL;
	p->rightSibling = NULL;
	p->parent = NULL;
	nodes[n] = p;
	n++;
	return p;
}
int height(Node *r)
{
	if (r == NULL)
		return 0;
	int maxH = 0;
	for (Node *p = r->leftMostChild; p != NULL; p = p->rightSibling)
	{
		int h = height(p);
		if (maxH < h)
			maxH = h;
	}
	return maxH + 1;
}

int count(Node *r)
{
	if (r == NULL)
		return 0;
	int c = 1;
	for (Node *p = r->leftMostChild; p != NULL; p = p->rightSibling)
	{
		c += count(p);
	}
	return c;
}
void makeChildParent(Node *child_node, Node *parent_node)
{

	child_node->parent = parent_node;
	child_node->rightSibling = parent_node->leftMostChild;
	parent_node->leftMostChild = child_node;
}

void run()
{
	char child_name[LEN], parent_name[LEN];
	while (1)
	{
		scanf("%s", child_name);
		if (strcmp(child_name, "*") == 0)
			break;
		scanf("%s", parent_name);
		Node *node_child = find(child_name);
		Node *node_parent = find(parent_name);
		if (node_parent == NULL)
		{
			node_parent = addNode(parent_name);
		}

		makeChildParent(node_child, node_parent);
	}
	char query[LEN], name[LEN];
	while (1)
	{
		scanf("%s", query);
		if (strcmp(query, "*") == 0)
			break;
		else if (strcmp(query, "descendants") == 0)
		{
			scanf("%s", name);
			Node *p = find(name);
			int res = count(p) - 1;
			printf("%d\n", res);
		}
		else if (strcmp(query, "generation") == 0)
		{
			scanf("%s", name);
			Node *p = find(name);
			int res = height(p) - 1;
			printf("%d\n", res);
		}
	}
}

int main()
{

	run();
	return 0;
}