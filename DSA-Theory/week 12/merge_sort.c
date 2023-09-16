#include <stdio.h>
#include <string.h>
#define N 100
int arr[N];
int n;
int tmp[N];
void Merge(int start, int mid, int end)
{
    int tmp[N];
    int first1 = start;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = end;
    int index = first1;
    for (; first1 <= last1 && first2 <= last2; ++index)
    {
        if (arr[first1] < arr[first2])
        {
            tmp[index] = arr[first1];
            ++first1;
        }
        else
        {
            tmp[index] = arr[first2];
            ++first2;
        }
    }
    for (; first1 <= last1; ++index, ++first1)
    {
        tmp[index] = arr[first1];
    }
    for (; first2 <= last2; ++index, ++first2)
    {
        tmp[index] = arr[first2];
    }
    for (index = start; index <= end; index++)
    {
        arr[index] = tmp[index];
    }
}

void Merge_sort(int start, int end)
{
    int mid = (start + end) / 2;
    if (start >= end)
        return;
    Merge_sort(start, mid);
    Merge_sort(mid + 1, end);
    Merge(start, mid, end);
}

void print()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    printf("nhap so phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    Merge_sort(0, n - 1);
    print();
}