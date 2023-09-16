#include <stdio.h>

void HaNoiTower(int n, char A, char B, char C)
{
    if (n > 0)
    {
        HaNoiTower((n - 1), A, C, B);
        printf("Move Dis from %c to %c\n", A, C);
        HaNoiTower(n - 1, B, A, C);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    char A;
    char B;
    char C;
    HaNoiTower(n, 'A', 'B', 'C');
}