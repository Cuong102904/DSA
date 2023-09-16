#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char from_account[21];
    char to_account[21];
    int money;
    char time_point[9];
    char atm[11];
    struct Node *next;
} Node;

Node *createNode(char from_account[], char to_account[], int money, char time_point[], char atm[])
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->from_account, from_account);
    strcpy(newNode->to_account, to_account);
    newNode->money = money;
    strcpy(newNode->time_point, time_point);
    strcpy(newNode->atm, atm);
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node **head, Node *newNode)
{
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

int countTransactions(Node *head)
{
    int count = 0;
    Node *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

int totalMoneyTransaction(Node *head)
{
    int total = 0;
    Node *current = head;
    while (current != NULL)
    {
        total += current->money;
        current = current->next;
    }
    return total;
}
void listSortedAccounts(Node *head)
{
    char accounts[10000][21];
    int count = 0;

    Node *current = head;
    while (current != NULL)
    {
        int isDuplicate = 0;
        for (int i = 0; i < count; i++)
        {
            if (strcmp(accounts[i], current->from_account) == 0)
            {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate)
        {
            strcpy(accounts[count], current->from_account);
            count++;
        }

        isDuplicate = 0;
        for (int i = 0; i < count; i++)
        {
            if (strcmp(accounts[i], current->to_account) == 0)
            {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate)
        {
            strcpy(accounts[count], current->to_account);
            count++;
        }

        current = current->next;
    }

    // Sort the accounts in alphabetical order
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (strcmp(accounts[i], accounts[j]) > 0)
            {
                char temp[21];
                strcpy(temp, accounts[i]);
                strcpy(accounts[i], accounts[j]);
                strcpy(accounts[j], temp);
            }
        }
    }

    // Print the sorted accounts
    for (int i = 0; i < count; i++)
    {
        printf("%s ", accounts[i]);
    }
    printf("\n");
}

int totalMoneyTransactionFrom(Node *head, char account[])
{
    int total = 0;

    Node *current = head;
    while (current != NULL)
    {
        if (strcmp(current->from_account, account) == 0)
        {
            total += current->money;
        }
        current = current->next;
    }

    return total;
}
int inspectCycle(Node *head, char account[], int k) // wrong answ

{
    Node *current = head;
    int count = 0;

    while (current != NULL)
    {
        if (strcmp(current->from_account, account) == 0)
        {
            Node *start = current;
            Node *runner = start;
            count = 0;

            while (1)
            {
                if (runner == NULL)
                {
                    break;
                }
                if (strcmp(runner->to_account, account) == 0)
                {
                    count++;
                    if (count == k)
                    {
                        printf("1\n");
                        return 1;
                    }
                    runner = start;
                }
                else
                {
                    runner = runner->next;
                }
            }
        }
        current = current->next;
    }

    printf("0\n");
    return 0;
}

void freeList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}
int main()
{
    Node *head = NULL;

    // Read the data block
    char from_account[21];
    char to_account[21];
    int money;
    char time_point[9];
    char atm[11];

    while (1)
    {
        scanf("%s", from_account);
        if (from_account[0] == '#')
        {
            break;
        }
        scanf("%s %d %s %s", to_account, &money, time_point, atm);
        Node *newNode = createNode(from_account, to_account, money, time_point, atm);
        insertNode(&head, newNode);
    }

    // Process the query block
    char query[21];

    while (1)
    {
        scanf("%s", query);
        if (query[0] == '#')
        {
            break;
        }

        if (strcmp(query, "?number_transactions") == 0)
        {
            printf("%d\n", countTransactions(head));
        }
        else if (strcmp(query, "?total_money_transaction") == 0)
        {
            printf("%d\n", totalMoneyTransaction(head));
        }
        else if (strcmp(query, "?list_sorted_accounts") == 0)
        {
            listSortedAccounts(head);
        }
        else if (strcmp(query, "?total_money_transaction_from") == 0)
        {
            char account[21];
            scanf("%s", account);
            printf("%d\n", totalMoneyTransactionFrom(head, account));
        }
        else if (strcmp(query, "?inspect_cycle") == 0)
        {
            char account[21];
            int k;
            scanf("%s %d", account, &k);
            printf("%d\n", inspectCycle(head, account, k));
        }
    }

    // Free the memory
    freeList(head);

    return 0;
}