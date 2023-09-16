#include <stdio.h>
#define N 100

int arr[N];

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int Partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int pIndex = start + 1;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(&arr[i], &arr[pIndex]);
            ++pIndex;
        }
    }
    swap(&arr[pIndex - 1], &arr[start]);
    return pIndex - 1;
}

void quick_sort(int arr[], int start, int end)
{
    if (start < end)
    {
        int partition = Partition(arr, start, end);
        quick_sort(arr, start, partition - 1);
        quick_sort(arr, partition + 1, end);
    }
}
void Print(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    quick_sort(arr, 0, n - 1);
    Print(n);
}