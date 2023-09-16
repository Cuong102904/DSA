#include <stdio.h>
#include <string.h>
int A[1000], B[1000];
int a, b;
int C[100];
void nhapMatrix(int A[], int B[], int a, int b)
{
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < b; i++)
    {
        scanf("%d", &B[i]);
    }
}
void nhapTest(int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        nhapMatrix(A, B, a, b);
        int isSmame = 1;
        for (int j = 0; j < a; j++)
        {
            if (A[j] != B[j])
            {
                isSmame = 0;
                break;
            }
        }
        C[i] = isSmame;
    }
}

int main()
{
    // freopen("testcase.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    nhapTest(n);
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", C[i]);
    }

    return 0;
}