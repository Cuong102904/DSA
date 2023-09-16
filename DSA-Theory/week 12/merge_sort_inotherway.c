#include <stdio.h>
#define N 1000

int arr[N];

void merge_sort(int start, int mid, int end)
{
    int length_left = mid - start + 1;
    int length_right = end - mid;
    int temp_left[length_left];
    int temp_right[length_right];
    int i, j, k;

    for (i = 0; i < length_left; i++)
    {
        temp_left[i] = arr[start + i];
    }
    for (j = 0; j < length_right; j++)
    {
        temp_right[j] = arr[mid + 1 + j];
    }
    for (i = 0, j = 0, k = start; k <= end; k++)
    {
        if ((i < length_left) && ((j >= length_right) || (temp_left[i] <= temp_right[j])))
        {
            arr[k] = temp_left[i];
            i++;
        }
        else
        {
            arr[k] = temp_right[j];
            j++;
        }
    }
}

void merge_sort_recursion(int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        merge_sort_recursion(start, mid);
        merge_sort_recursion(mid + 1, end);
        merge_sort(start, mid, end);
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
    merge_sort_recursion(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    return 0;
}