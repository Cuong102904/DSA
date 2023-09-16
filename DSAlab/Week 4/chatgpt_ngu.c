#include <stdio.h>

#define MAX_N 50
#define MAX_B 100

int n, b, a[MAX_N];
int ans = 0;

void solve(int i, int sum)
{
    if (i == n)
    {
        ans += (sum == b);
        return;
    }
    solve(i + 1, sum + a[i]); // Try including a[i] in the sum
    solve(i + 1, sum);        // Try excluding a[i] from the sum
}

int main()
{

    scanf("%d %d", &n, &b);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    solve(0, 0); // Start with empty sum
    printf("%d\n", ans);
    return 0;
}
