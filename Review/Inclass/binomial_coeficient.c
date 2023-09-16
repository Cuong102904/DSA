#include <stdio.h>
// tim C(n,k) bằng đệ quy

int C(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    else
        return C(n - 1, k - 1) + C(n - 1, k);
}

int main()
{
    int n, k;
    printf("Nhap n va k: ");
    scanf("%d %d", &n, &k);
    printf("%d\n", C(n, k));
    return 0;
}