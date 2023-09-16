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

/*void list_sort_account(banking bankif[], int count)
{
    int j;
    int bdau = 0;
    char *arr[10000];
    int i;
    for (i = 0; i < count; i++)
    {
        for (j = 0; j <= bdau; j++)
        {
            if (!(strcmp(bankif[i].from_ac, arr[i]) == 0))
            {
                strcpy(arr[bdau],bankif[i].from_ac);
            }
        }
        bdau++;
    }
    for (i = 0; i + 1 < bdau; i++)
    {
        if (strcmp(arr[i], arr[i + 1]) > 0)
        {	char *tmp;
           strcpy(tmp,arr[i]);
           strcpy(arr[i],arr[i+1]);
           strcpy(arr[i+1],tmp);
        }
    }
    for (i = 0; i < bdau; i++)
    {
        printf("%s ", arr[i]);
    }
}
*/
void list_sort_account(banking bankif[], int count)
{
    int j;
    int bdau = 0;
    char arr[10000][100]; // Changed char* arr[10000] to char arr[10000][100]
    int i;
    for (i = 0; i < count; i++)
    {
        int isDuplicate = 0;       // Added a flag to check duplicates
        for (j = 0; j < bdau; j++) // Changed j <= bdau to j < bdau
        {
            if (strcmp(bankif[i].from_ac, arr[j]) == 0) // Check for duplicates
            {
                isDuplicate = 1;
                break;
            }
        }
        if (isDuplicate == 0) // If not a duplicate, add to arr
        {
            strcpy(arr[bdau], bankif[i].from_ac);
            bdau++;
        }
    }

    // Sort the array in ascending order
    for (i = 0; i < bdau - 1; i++) // Changed i + 1 < bdau to i < bdau - 1 for correct loop condition
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

    // Print the sorted array
    for (i = 0; i < bdau; i++)
    {
        printf("%s ", arr[i]);
    }
}

void run()
{
}

int main()
{	 freopen("test1.txt","r",stdin);
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
            printf("%d", count_trans);
        }
        else if (strcmp(trash, "?inspect_cycle") == 0) // chua lam duoc
        {
            printf("%d", count_trans);
        }
    }
    return 0;
}
