#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define TABLE_SIZE 100007
#define NAME 30

typedef struct Table
{
    int day;
    char region[NAME];
    int patients;
    struct Table *next;
} Table;

Table *hash_table[TABLE_SIZE];

void init_hash_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
}

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

bool hash_table_insert(Table *p)
{
    if (p == NULL)
        return false;
    int index = hash(p->region);
    if (hash_table[index] == NULL || hash_table[index]->day != p->day)
    {
        p->next = hash_table[index];
        hash_table[index] = p;
        return true;
    }
    return false;
}

Table *hash_table_lookup(char *name, int day)
{
    int index = hash(name);
    Table *tmp = hash_table[index];
    while (tmp != NULL && tmp->day != day)
    {
        tmp = tmp->next;
    }
    return tmp;
}

void run()
{
    int sum = 0;
    char trash[NAME];
    char ten[NAME];
    int ngay;
    int soluong;
    int arr[71];
    for (int i = 1; i < 71; i++)
    {
        arr[i] = 0;
    }
    int l = 0;
    while (1)
    {
        scanf("%s", trash);
        if (strcmp(trash, "***") == 0)
            break;
        if (strcmp(trash, "$Update") == 0)
        {
            scanf("%s %d %d", ten, &ngay, &soluong);

            Table *p = (Table *)malloc(sizeof(Table));
            strcpy(p->region, ten);
            p->day = ngay;
            p->patients = soluong;
            if (hash_table_insert(p))
            {
                sum += soluong;
                arr[ngay] += soluong;
            }
        }
        if (strcmp(trash, "$CountTotalPatients") == 0)
        {
            printf("%d\n", sum);
        }
        if (strcmp(trash, "$FindNumberPatients") == 0)
        {
            // time_t startT, endT;
            // startT = clock();

            scanf("%s %d", ten, &ngay);
            Table *q = hash_table_lookup(ten, ngay);
            if (q != NULL)
                printf("%d\n", q->patients);
            else
                printf("0\n");

            // endT = clock();
            // printf("\n--> Time: %.30f\n", (float)(endT - startT) / CLOCKS_PER_SEC);
        }
        if (strcmp(trash, "$CountNumberPatientsOfRegion") == 0)
        {
            // time_t startT, endT;
            // startT = clock();

            scanf("%s", ten);
            int index = hash(ten);
            Table *k = hash_table[index];
            int total = 0;
            while (k != NULL)
            {
                total += k->patients;
                k = k->next;
            }
            printf("%d\n", total);

            // endT = clock();
            // printf("\n--> Time: %.30f\n", (float)(endT - startT) / CLOCKS_PER_SEC);
        }
        if (strcmp(trash, "$CountNumberPatientsOfPeriod") == 0)
        {
            // time_t startT, endT;
            // startT = clock();
            int T[71];
            for (int i = 1; i < 71; i++)
            {
                T[i] = arr[i] + T[i - 1];
            }
            int a, b;
            scanf("%d %d", &a, &b);
            int hex = T[b] - T[a - 1];
            printf("%d\n", hex);
            // endT = clock();
            // printf("\n--> Time: %.30f\n", (float)(endT - startT) / CLOCKS_PER_SEC);
        }
    }
}

int main()
{
    init_hash_table();
    run();
    return 0;
}
