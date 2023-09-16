#include <stdio.h>
#include <stdlib.h>
// chuaw hoan thanh

int cost = 0, graph[15][15], visited[15];
int chon[100000];
int l = 0;
int dem = 0;
int cur;
void takeInput(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
}

void TSP(int node, int start, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (!visited[i] && graph[node][i] != 0)
        {
            visited[i] = 1;
            cost += graph[node][i];
            dem++;
            cur = i;
            TSP(i, start, n);
            visited[i] = 0;
            dem--;
            cost -= graph[node][i];
        }
    }
    if (dem == n - 1)
    {
        chon[l] = cost + graph[cur][start];
        l++;
    }
    return;
}

int check(int m)
{
    int count = 0;
    for (int i = 0; i < l; i++)
    {
        if (chon[i] <= m)
            count++;
    }
    return count;
}

int main()
{
    int i, n, m;
    scanf("%d %d", &n, &m);
    takeInput(n);
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    for (int j = 0; j < n; j++)
    {
        visited[j] = 1;
        TSP(j, j, n);
        visited[j] = 0;
    }
    int val = check(m);
    printf("%d", val);
    return 0;
}
