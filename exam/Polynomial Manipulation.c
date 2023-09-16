#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct Node
{
    int coef;
    int exp;
    struct Node *next;
} Node;

typedef struct Arr
{
    int id;
    Node *node;
    struct Arr *next;
} Arr;

Arr *head;

void destroy(int id);

Arr *createArr(int id) // tao mang lua tru cac ptrinh co id la x
{
    Arr *p = (Arr *)malloc(sizeof(Arr));
    p->id = id;
    p->next = NULL;
    p->node = NULL;
    return p;
}
Node *makeNode(int cof, int exp) // tao node bac cua ptrinh
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->coef = cof;
    p->exp = exp;
    p->next = NULL;
    return p;
}

Arr *findTheArray(int id) // tim array co id la x
{
    Arr *cur = head;
    while (cur != NULL)
    {
        if (cur->id == id)
            return cur;
        cur = cur->next;
    }
    return NULL;
}

void AddTerm(Arr *head, int cof, int exp) // tem so lieu vao phan tu
{
    Node *term = makeNode(cof, exp);
    if (head->node == NULL) // kiem tra xem phan tu dau tien cua arr head co NULL khong
    {
        head->node = term;
        return;
    }
    else
    {
        Node *cur = head->node;
        while (cur->next != NULL)
        {
            if (cur->exp == exp) // nếu cùng bậc thì cộng hệ số
            {
                cur->coef += cof;
                return;
            }
            if (cur->next->exp < exp) // tìm phân tử đứng đằng trước
            {
                term->next = cur->next; // dang bị sai
                cur->next = term;
                return;
            }

            cur = cur->next;
        }
        if (cur->exp == exp)
        {
            cur->coef = cof;
        }
        else if (cur->exp < exp) // add newnode before a current node
        {
            // Create a new node
            Node *newNode = term;

            // Set the next pointer of the new node
            newNode->next = cur;

            // Update the head node if cur is the head
            if (cur == head->node)
            {
                head->node = newNode;
            }
            else
            {
                // Find the node that precedes cur
                Node *prev = head->node;
                while (prev->next != cur)
                    prev = prev->next;

                // Set the next pointer of prev to the new node
                prev->next = newNode;
            }

            // Return after successful insertion
            return;
        }

        else
        {
            cur->next = term;
        }
    }
}

void evaluatePoly(int id, int value) // Put value x to calculate the function having id is "id"
{
    Arr *polynomial = findTheArray(id);
    if (polynomial == NULL)
    {
        printf("0\n");
        return;
    }
    float result = 0;
    Node *curr = polynomial->node;
    while (curr != NULL)
    {
        result += curr->coef * pow(value, curr->exp);
        curr = curr->next;
    }
    printf("%.0f\n", result);
}

void AddPoly(int id1, int id2, int result_id) // compute 2 function have id 1 and 2, after that put the addition function into array and mark it with id "result_id"
{
    Arr *poly1 = findTheArray(id1);
    Arr *poly2 = findTheArray(id2);
    Arr *poly_result = findTheArray(result_id);

    if (poly_result != NULL)
    {
        destroy(result_id);
    }
    poly_result = createArr(result_id);
    if (poly1 != NULL && poly2 == NULL)
    {
        poly_result->node = poly1->node;
    }
    else if (poly2 != NULL && poly1 == NULL)
    {
        poly_result->node = poly2->node;
    }
    else if (poly2 != NULL && poly1 != NULL)
    {
        Node *cur1 = poly1->node;
        Node *cur2 = poly2->node;
        while (cur1 != NULL && cur2 != NULL)
        {
            if (cur1->exp > cur2->exp)
            {
                AddTerm(poly_result, cur1->coef, cur1->exp);
                cur1 = cur1->next;
            }
            else if (cur2->exp > cur1->exp)
            {
                AddTerm(poly_result, cur2->coef, cur2->exp);
                cur2 = cur2->next;
            }
            else
            {
                int coef_result = cur1->coef + cur2->coef;
                if (coef_result != 0)
                {
                    AddTerm(poly_result, coef_result, cur1->exp);
                }
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
        }
        while (cur1 != NULL)
        {
            AddTerm(poly_result, cur1->coef, cur1->exp);
            cur1 = cur1->next;
        }
        while (cur2 != NULL)
        {
            AddTerm(poly_result, cur2->coef, cur2->exp);
            cur2 = cur2->next;
        }
        if (poly_result->node != NULL)
        {
            if (head == NULL)
            {
                head = poly_result;
            }
            else
            {
                Arr *cur = head;
                while (cur->next != NULL)
                {
                    cur = cur->next;
                }
                cur->next = poly_result;
            }
        }
        else
        {
            free(poly_result);
        }
    }
}

void printPoly(int id) // print the poly having id is "id"
{
    Arr *poly = findTheArray(id);
    if (poly == NULL)
    {
        return;
    }
    Node *cur = poly->node;
    while (cur != NULL)
    {
        printf("%d %d ", cur->coef, cur->exp);
        cur = cur->next;
    }
    printf("\n");
}

void destroy(int id) // destroy a node in the array
{
    Arr *curr = head;
    Arr *prev = NULL;
    while (curr != NULL)
    {
        if (curr->id == id)
        {
            if (prev == NULL)
            {
                head = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }
            Node *term = curr->node;
            while (term != NULL)
            {
                Node *temp = term;
                term = term->next;
                free(temp);
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

int main()
{
    char trash[20];
    while (1)
    {
        scanf("%s", trash);
        if (strcmp(trash, "*") == 0)
            break;
        if (strcmp(trash, "Create") == 0)
        {
            int id;
            scanf("%d", &id);
            if (head == NULL)
            {
                head = createArr(id);
            }
            else
            {
                Arr *check = findTheArray(id);
                if (check == NULL)
                {
                    Arr *cur = head;
                    Arr *poly = createArr(id);
                    while (cur != NULL)
                    {
                        cur = cur->next;
                    }
                    cur->next = poly;
                }
            }
        }
        if (strcmp(trash, "AddTerm") == 0)
        {
            int id, coef, exp;
            scanf("%d %d %d", &id, &coef, &exp);
            if (head == NULL)
            {
                head = createArr(id);
                AddTerm(head, coef, exp);
            }
            else
            {
                Arr *find = findTheArray(id);
                if (find == NULL)
                {
                    Arr *cur = head;
                    Arr *poly = createArr(id);
                    while (cur->next != NULL)
                    {
                        cur = cur->next;
                    }
                    cur->next = poly;
                    AddTerm(poly, coef, exp);
                }
                else
                    AddTerm(find, coef, exp);
            }
        }
        if (strcmp(trash, "EvaluatePoly") == 0)
        {
            int id, val;
            scanf("%d %d", &id, &val);
            evaluatePoly(id, val);
        }
        if (strcmp(trash, "AddPoly") == 0)
        {
            int id1, id2, result_id;
            scanf("%d %d %d", &id1, &id2, &result_id);
            AddPoly(id1, id2, result_id);
        }
        if (strcmp(trash, "PrintPoly") == 0)
        {
            int id;
            scanf("%d", &id);
            printPoly(id);
        }
        if (strcmp(trash, "Destroy") == 0)
        {
            int id;
            scanf("%d", &id);
            destroy(id);
        }
    }
    return 0;
}
