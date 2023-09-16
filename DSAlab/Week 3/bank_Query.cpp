#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct bankquery
{
    char from_account[21];
    char to_account[21];
    int money;
};

int toInt(char *str) // best function for ck for
{
    int num = 0;

    for (int i = 1; str[i] != '\0'; i++)
    {
        num = num * 10 + (str[i] - 48);
    }

    return num;
}

void run()
{
    int count = 0;
    bankquery *bankinf = (bankquery *)malloc(sizeof(bankquery) * 1000000);
    int m[100000] = {0};
    char trash[22];
    char times[10];
    char atm[10];
    while (1)
    {
        scanf("%s", trash);
        if (strcmp(trash, "#") == 0)
        {
            break;
        }
        scanf("%s %d %s %s", bankinf[count].to_account, &bankinf[count].money, times, atm);
        strcpy(bankinf[count].from_account, trash);
        m[toInt(trash)] += bankinf[count].money;
        count++;
        }
    char trash1[30]; // d?c cái ?total_money_transaction_from
    char ans[20];
    while (1)
    {
        scanf("%s", trash1);
        if (strcmp(trash1, "#") == 0)
        {
            break;
        }
        else if (strcmp(trash1, "?number_transactions") == 0)
        {
            printf("%d", count);
        }
        else if (strcmp(trash1, "?total_money_transaction_from") == 0)
        {
            char ans[20];
            printf("%d\n", m[toInt(ans)]);
        }
        else if (strcmp(trash1, "?total_money_transaction") == 0)
        {
            int total_money = 0;
            for (int j = 0; j < count; j++)
                total_money += bankinf[j].money;
            printf("%d\n", total_money);
        }
        else if (strcmp(trash1, "?list_sorted_accounts") == 0)
        {
            char accounts[200] = ""; // assuming no more than 100 accounts
            for (int i = 0; i < count; i++)
            {
                strcat(accounts, bankinf[i].from_account);
                strcat(accounts, " ");
                strcat(accounts, bankinf[i].to_account);
                strcat(accounts, " ");
            }
            char *token = strtok(accounts, " ");
            char *uniqueAccounts[100];
            int numUniqueAccounts = 0;
            while (token != NULL) // loai bo ma bi trung
            {
                int i;
                for (i = 0; i < numUniqueAccounts; i++)
                {
                    if (strcmp(token, uniqueAccounts[i]) == 0)
                    {
                        break;
                    }
                }
                if (i == numUniqueAccounts)
                {
                    uniqueAccounts[numUniqueAccounts] = token;
                    numUniqueAccounts++;
                }
                token = strtok(NULL, " ");
            }

            for (int i = 0; i < numUniqueAccounts - 1; i++)
            {
                for (int j = 0; j < numUniqueAccounts - i - 1; j++)
                {
                    if (strcmp(uniqueAccounts[j], uniqueAccounts[j + 1]) > 0)
                    {
                        char *temp = uniqueAccounts[j];
                        uniqueAccounts[j] = uniqueAccounts[j + 1];
                        uniqueAccounts[j + 1] = temp;
                    }
                }
            }
            for (int i = 0; i < numUniqueAccounts; i++)
            {
                printf("%s ", uniqueAccounts[i]);
            }
            printf("\n");
        }
    }

    free(bankinf);
}

int main()
{
    run();
    return 0;
}
