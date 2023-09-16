#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

// idea do bài toán sẽ tạo ra nhiều nhà khác nhau nên sẽ dùng node mảng.  Ta sẽ đi tạo ra từng node cho từng hộ gia đình.
// Nêu hộ gia đình đó chưa tồn tại thì ta cho vào tphan tiếp theo của mảng.
//  Nếu tên chủ hộ gia đình là con của chủ hộ khác thì ta gán tên chủ hộ con vào hộ lớn hơn.

typedef struct Node
{
	char name[N];
	struct Node *leftmostchild;
	struct Node *rightsilbing;
	struct Node *parent;
} Node;
Node *nodes[N];
int n;

Node *makeNode(char *c)
{
	Node *p = (Node *)malloc(sizeof(Node));
	strcpy(p->name, c);
	p->parent = NULL;
	p->leftmostchild = NULL;
	p->rightsilbing = NULL;
	nodes[n] = p;
	n++;
	return p;
}

Node *find(char *chad) // tìm vị trí hộ gia đình, tìm thầy trả về vtri gdinh đó, ko thì trả NULL
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(chad, nodes[i]->name) == 0)
		{
			return nodes[i];
		}
	}
	return NULL;
}

int countnode(Node *root) // đếm thành viên của hộ gia đình
{
	if (root == NULL)
	{
		return 0;
	}
	int c = 1;
	Node *p = root->leftmostchild;
	while (p != NULL)
	{
		c += countnode(p);
		p = p->rightsilbing;
	}
	return c;
}

int height(Node *node) // tìm số thế hệ thành viên của 1 hộ gia đình
{
	if (node == 0)
	{
		return 0;
	}

	int maxH = 0;
	for (Node *p = node->leftmostchild; p != NULL; p = p->rightsilbing)
	{
		int h = height(p);
		if (maxH < h)
			maxH = h;
	}
	return maxH + 1;
}
void add(Node *node_child, Node *node_parent)
{
	node_child->parent = node_parent;
	node_child->rightsilbing = node_parent->leftmostchild;
	node_parent->leftmostchild = node_child;
}

void run()
{
	char trash[10];
	while (1)
	{
		scanf("%s", trash);
		if (strcmp(trash, "***") == 0)
			break;
		char cha[N];
		scanf("%s", cha);
		Node *parent = find(cha);
		if (parent == NULL)
		{
			parent = makeNode(cha);
		}
		Node *child = find(trash);
		if (child == NULL)
		{
			child = makeNode(trash);
		}
		add(child, parent);
	}
	while (1)
	{
		scanf("%s", trash);
		if (strcmp(trash, "***") == 0)
			break;
		else if (strcmp(trash, "descendants") == 0)
		{
			char cha[N];
			scanf("%s", cha);
			Node *k = find(cha); // tìm sẳn hộ gia đình rồi đếm số thành viên.
			int result = countnode(k);
			printf("%d\n", result - 1);
		}
		else if (strcmp(trash, "generation") == 0)
		{
			char con[N];
			scanf("%s", con);
			Node *k = find(con); // tìm hộ gia đình cần đếm số thế hệ
			int result = height(k);
			printf("%d\n", result - 1);
		}
	}
}

int main()
{
	run();
	return 0;
}
