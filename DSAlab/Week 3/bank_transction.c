#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct banking
{
    char from_ac[21];
    char to_ac[21];
    int money;
} banking;

int transINT(char ans[])
{
    int num = 0;
    int i;
    for (i = 1; ans[i] != '\0'; i++)
    {
        num = num * 10 + (ans[i] - 48);
    }
    return num;
}

void list_sort_account(banking bankif[], int count)
{
    int j;
    int bdau = 0;
    char arr[10000][100];
    int i;

    for (i = 0; i < count; i++)
    {
        int isDuplicate = 0;
        for (j = 0; j < bdau; j++)
        {
            if (strcmp(bankif[i].from_ac, arr[j]) == 0)
            {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate)
        {
            strcpy(arr[bdau], bankif[i].from_ac);
            bdau++;
        }
    }

    for (i = 0; i < bdau; i++)
    {
        for (j = 0; j < bdau - i - 1; j++)
        {
            if (strcmp(arr[j], arr[j + 1]) > 0)
            {
                char tmp[100];
                strcpy(tmp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], tmp);
            }
        }
    }

    for (i = 0; i < bdau; i++)
    {
        printf("%s ", arr[i]);
    }
}

void run()
{
    int count_trans = 0;
    int total_from[100000] = {0};
    banking bankif[100000];
    int total = 0;
    while (1)
    {
        char trash[20];
        scanf("%s", trash);
        if (strcmp(trash, "#") == 0)
            break;
        int money;
        char time[10];
        char atm[6];
        scanf(" %s %d %s %s", bankif[count_trans].to_ac, &money, time, atm);
        bankif[count_trans].money = money;
        total += money;
        total_from[transINT(trash)] += money;
        count_trans++;
    }
    while (1)
    {
        char trash[20];
        scanf("%s", trash);
        if (strcmp(trash, "#") == 0)
            break;
        else if (strcmp(trash, "?total_money_transaction_from") == 0)
        {
            char ans[20];
            scanf("%s", ans);
            printf("%d\n", total_from[transINT(ans)]);
        }
        else if (strcmp(trash, "?total_money_transaction") == 0)
        {
            printf("%d\n", total);
        }
        else if (strcmp(trash, "?number_transactions") == 0)
        {
            printf("%d", count_trans);
        }
        else if (strcmp(trash, "?list_sorted_accounts") == 0) // chua lam duoc
        {
            list_sort_account(bankif, count_trans);
        }
        else if (strcmp(trash, "?inspect_cycle") == 0) // chua lam duoc
        {
        }
    }
}

int main()
{
    run();
    return 0;
}
