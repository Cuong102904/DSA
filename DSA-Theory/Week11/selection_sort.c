#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void SelectionSort(int a[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        swap(&a[i], &a[min]);
    }
}

int main()
{
    int a[7] = {9, 8, 6, 4, 3, 5, 2};
    SelectionSort(a, 7);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}