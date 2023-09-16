#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define N 1000001

typedef struct data
{
    char id[15];
    int total;
} data;
data list[N];
int n;

int convert()
{
    char date_string[9]; // Assuming the maximum date string length is 19 characters (e.g., "YYYY-MM-DD HH:MM:SS")
    int h, m, s;
    scanf("%s", date_string);
    // fgets(date_string, sizeof(date_string), stdin);

    sscanf(date_string, "%d:%d:%d", &h, &m, &s);

    return h * 3600 + m * 60 + s;
}

void find()
{
    int data1 = convert();
    int data2 = convert();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (list[i].total >= data1 && list[i].total <= data2)
            cnt++;
    }
    printf("%d\n", cnt);
}
void exact()
{
    int data = convert();
    int count = 0;
    for (int i = 0; i < n; i++)
        if (list[i].total == data)
            count++;
    printf("%d\n", count);
}

void run()
{
    n = 0;

    while (1)
    {

        char id[15];
        scanf("%s", id);
        if (strcmp(id, "#") == 0)
            break;
        strcpy(list[n].id, id);
        list[n].total = convert();
        n++;
    }
    while (1)
    {
        char id[25];
        scanf("%s", id);
        if (strcmp(id, "###") == 0)
            break;
        else if (strcmp(id, "?number_orders") == 0)
            printf("%d\n", n);
        else if (strcmp(id, "?number_orders_in_period") == 0)
            find();
        else if (strcmp(id, "?number_orders_at_time") == 0)
            exact();
    }
}

int main()
{
    // time_t startT, endT;  (check time)
    // startT = clock();
    run();
    // endT = clock();
    // printf("\n--> Time: %.30f\n", (float)(endT - startT) / CLOCKS_PER_SEC);
    return 0;
}
