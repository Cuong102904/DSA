#include <stdio.h>

void InsertSort(int a[], int size)
{
    int i, j;
    for (i = 1; i < size; i++)
    {
        int temp = a[i];
        j = i;
        while (temp < a[i - 1] && j > 0)
        {
            // shift right each element from a[i+1]...a[k-1]
            a[j] = a[j - 1];
            j--;
        }
        a[j] = temp;
    }
}

// shift right all element from a[1+1]..a[k-1]
void InsertSort1(int a[], int size)
{
}

int main()
{
    int n;
    int a[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    InsertSort(a, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}