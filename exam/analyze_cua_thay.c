#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 1000001
#define MAX_LEN 15

typedef struct Order
{
    char orderID[MAX_LEN];
    char timePoint[10];
} Order;

int n;
Order orders[N];

int hash(char *t)
{
    int h = (t[0] - '0') * 10 + (t[1] - '0');
    int m = (t[3] - '0') * 10 + (t[4] - '0');
    int s = (t[6] - '0') * 10 + (t[7] - '0');
    return h * 3600 + m * 60 + s;
}

void run()
{
    char orderID[MAX_LEN];
    char from[MAX_LEN], to[MAX_LEN];
    char timePoint[10];
    n = 0;
    while (1)
    {

        scanf("%s", orderID);
        if (strcmp(orderID, "#") == 0)
            break;
        scanf("%s", timePoint);
        n++;
        strcpy(orders[n].orderID, orderID);
        strcpy(orders[n].timePoint, timePoint);
    }
    int M = 24 * 3600;
    int a[M];
    int T[M];
    for (int i = 1; i <= M; i++)
        a[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        int j = hash(orders[i].timePoint);
        a[j] += 1;
    }
    T[0] = 0;
    for (int i = 1; i <= M; i++)
    {
        T[i] = T[i - 1] + a[i];
    }

    char cmd[MAX_LEN];
    while (1)
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "###") == 0)
            break;
        else if (strcmp(cmd, "?number_orders") == 0)
            printf("%d\n", n);
        else if (strcmp(cmd, "?number_orders_in_period") == 0)
        {
            scanf("%s %s", from, to);
            int i = hash(from);
            int j = hash(to);
            int res = T[j] - T[i - 1];
            printf("%d\n", res);
        }
        else if (strcmp(cmd, "?number_orders_at_time") == 0)
        {
            scanf("%s", from);
            int i = hash(from);
            printf("%d\n", a[i]);
        }
    }
}

int main()
{
    time_t startT, endT;
    startT = clock();
    run();
    endT = clock();
    printf("\n--> Time: %.30f\n", (float)(endT - startT) / CLOCKS_PER_SEC);
    return 0;
}