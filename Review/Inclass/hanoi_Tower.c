#include <stdio.h>

void HanoiTower(int n, char start, char end, char middle)
{
    if (n == 1)
    {
        printf("Move disk from %c to %c\n", start, end);
        return;
    }
    else
    {
        HanoiTower(n - 1, start, middle, end);
        HanoiTower(1, start, end, middle);
        HanoiTower(n - 1, middle, end, start);
    }
}

int main()
{
    int n;
    printf("Moi nhap chieu cao cua cot: ");
    scanf("%d", &n);
    HanoiTower(n, 'A', 'C', 'B');
    return 0;
}