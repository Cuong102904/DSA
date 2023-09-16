#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
// lm thu cach khac = linear probing
#define MAX_LEN 11
#define TABLE_SIZE 100004

typedef struct person
{
    // int time;
    int price;
    char proID[MAX_LEN];
    char shopID[MAX_LEN];
    struct person *next;
} person;

typedef struct Order
{
    int timePoint;
    int money;
} Order;
int l;
Order orders[TABLE_SIZE];
person *hash_Table[TABLE_SIZE];
int count = 0;
unsigned int hash(char *name)
{
    int length = strlen(name);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++)
    {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void init_hash_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_Table[i] = NULL;
    }
}

bool hash_table_insert(person *p)
{
    if (p == NULL)
        return false;
    int index = hash(p->shopID); // update version
    p->next = hash_Table[index];
    hash_Table[index] = p;
    return true;
}
// find a person in the table by their name
person *hash_table_lookup(char name[])
{
    int index = hash(name);
    person *tmp = hash_Table[index];
    while (tmp != NULL && strcmp(tmp->shopID, name) != 0)
    {
        tmp = tmp->next;
    }
    return tmp;
}

int hash1(char *t)
{
    int h = (t[0] - '0') * 10 + (t[1] - '0');
    int m = (t[3] - '0') * 10 + (t[4] - '0');
    int s = (t[6] - '0') * 10 + (t[7] - '0');
    return h * 3600 + m * 60 + s;
}

void run()
{
    l = 0;
    char trash[10];
    int sum = 0;
    while (1)
    {
        scanf("%s", trash);
        if (strcmp(trash, "#") == 0)
            break;

        char proID[11], ShopID[11], Time[10];
        int price;
        scanf("%s %d %s %s", proID, &price, ShopID, Time);

        count++;      // for first order
        sum += price; // for second order

        orders[l].timePoint = hash1(Time); // for final order
        orders[l].money = price;           // for final order
        l++;

        person *p = (person *)malloc(sizeof(person)); // for third order
        p->price = price;
        // p->time = hash1(Time);
        strcpy(p->proID, trash);
        strcpy(p->shopID, ShopID);
        p->next = NULL;
        hash_table_insert(p);
    }
    /////////////////////
    // xu ly time
    // use for total revenue in period
    int M = 24 * 3600;
    int a[M];
    int T[M];
    for (int i = 1; i <= M; i++)
        a[i] = 0;
    for (int i = 0; i <= l; i++)
    {
        a[orders[i].timePoint] += orders[i].money;
    }
    T[0] = 0;
    for (int i = 1; i <= M; i++)
    {
        T[i] = T[i - 1] + a[i];
    }
    /////////////////////////////////////////
    //////////////////////////
    char cmd[30];
    while (1)
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "#") == 0)
            break;
        else if (strcmp(cmd, "?total_number_orders") == 0)
            printf("%d\n", count);
        else if (strcmp(cmd, "?total_revenue") == 0)
        {
            printf("%d\n", sum);
        }
        else if (strcmp(cmd, "?revenue_of_shop") == 0)
        {
            char trash[MAX_LEN];
            scanf("%s", trash);
            person *k = hash_table_lookup(trash);
            int total = 0;
            while (k != NULL)
            {
                if (strcmp(trash, k->shopID) == 0)
                {
                    total += k->price;
                }
                k = k->next;
            }
            printf("%d\n", total);
        }
        else if (strcmp(cmd, "?total_consume_of_customer_shop") == 0)
        {
            char pID[11], sID[11];
            scanf("%s %s", pID, sID);
            person *n = hash_table_lookup(sID);
            int a = 0;
            while (n != NULL)
            {
                if (strcmp(pID, n->proID) == 0 && strcmp(sID, n->shopID) == 0)
                {
                    a += n->price;
                }
                n = n->next;
            }
            printf("%d\n", a);
        }
        else if (strcmp(cmd, "?total_revenue_in_period") == 0)
        {
            char from[MAX_LEN], to[MAX_LEN];

            scanf("%s %s", from, to);
            int i = hash1(from);
            int j = hash1(to);
            int res = T[j] - T[i - 1];
            printf("%d\n", res);
        }
    }
}

int main()
{
    run();
    return 0;
}
