#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NAME 30
#define TABLE_SIZE 1000007

typedef struct Order
{
    int type;
    char name[MAX_NAME];
    int price;
    int time;
    struct Order *next;
} Order;

Order *hash_table[TABLE_SIZE];
int k = 0;
int thoigian = 0;
int thoigiandoan = 0;
int thoigiandouong = 0;
int drink, food;
char trash[MAX_NAME];

unsigned int hash(char *name)
{
    int length = strlen(name);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++)
    {
        hash_value = (hash_value * 10 + (name[i] - 48)) % TABLE_SIZE;
    }
    return hash_value;
}

void init_hash_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
}

bool insert_hash_table(Order *p)
{
    if (p == NULL)
        return false;
    int index = hash(p->name);
    if (hash_table[index] == NULL)
    {
        hash_table[index] = p;
        return true;
    }
    return false;
}

int donhang(int order1, int order2, int thoigianchet, int *thoigiandoan, int *thoigiandouong)
{

    Order *p1 = hash_table[order1];
    Order *p2 = hash_table[order2];

    *thoigiandoan -= thoigianchet;
    *thoigiandouong -= thoigianchet;
    if (*thoigiandoan < 0)
        *thoigiandoan = 0;
    if (*thoigiandouong < 0)
        *thoigiandouong = 0;

    if (p1->type == drink)
    {
        if (p2->type == drink)
        {
            *thoigiandouong += (p2->time + p1->time);
        }
        else
        {
            *thoigiandoan += p2->time;
            *thoigiandouong += p1->time;
        }
    }
    if (p1->type == food)
    {
        if (p2->type == food)
        {
            *thoigiandoan += (p2->time + p1->time);
        }
        else
        {
            *thoigiandouong += p2->time;
            *thoigiandoan += p1->time;
        }
    }
    int k = *thoigiandoan < *thoigiandouong ? *thoigiandouong : *thoigiandoan;
    printf("%d\n", k);
}

void run()
{
    int arr[TABLE_SIZE];
    food = hash("FOOD");
    drink = hash("DRINK");

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        arr[i] = 0;
    }
    while (1)
    {
        scanf("%s", trash);
        if (strcmp(trash, "$ADD") == 0)
        {
            char type[MAX_NAME], ten[MAX_NAME];
            int time, tien;
            scanf("%s %s %d %d", type, ten, &tien, &time);

            Order *p = (Order *)malloc(sizeof(Order));
            strcpy(p->name, ten);
            int loai = hash(type);
            p->type = loai;
            p->price = tien;
            p->time = time;
            if (insert_hash_table(p))
            {
                k++;
                printf("%d\n", k);
            }
        }
        if (strcmp(trash, "$PRICE") == 0)
        {
            scanf("%s", trash);
            int a = hash(trash);
            if (hash_table[a] != NULL)
            {
                printf("%d\n", hash_table[a]->price);
            }
        }
        if (strcmp(trash, "$ORDER") == 0)
        {
            int hour, minute;
            char meal1[MAX_NAME], meal2[MAX_NAME];
            scanf("%d %d %s %s", &hour, &minute, meal1, meal2);

            int quydoitime = hour * 60 + minute;
            if (thoigian == 0)
            {
                thoigian = quydoitime;
            }
            int order1 = hash(meal1);
            int order2 = hash(meal2);

            arr[order1] += 1;
            arr[order2] += 1;

            int thoigianchet = quydoitime - thoigian;
            thoigian = quydoitime;
            donhang(order1, order2, thoigianchet, &thoigiandoan, &thoigiandouong);
        }
        if (strcmp(trash, "$COUNT") == 0)
        {
            scanf("%s", trash);
            int h = hash(trash);
            printf("%d\n", arr[h]);
        }
        if (strcmp(trash, "WAIT") == 0)
        {
        }
    }
}

int main()
{
    init_hash_table();
    run();
    return 0;
}