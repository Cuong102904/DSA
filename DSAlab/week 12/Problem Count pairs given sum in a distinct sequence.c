#include <stdio.h>
#define N 1000001

int arr[N];

void merge(int start, int mid, int end)
{
    int tmpA[N];
    int first1 = start, last1 = mid;
    int first2 = mid + 1, last2 = end;
    int index = start;

    for (; first1 <= last1 && first2 <= last2; ++index)
    {
        if (arr[first1] < arr[first2])
        {
            tmpA[index] = arr[first1];
            ++first1;
        }
        else
        {
            tmpA[index] = arr[first2];
            ++first2;
        }
    }

    for (; first1 <= last1; ++first1, ++index)
    {
        tmpA[index] = arr[first1];
    }

    for (; first2 <= last2; ++first2, ++index)
    {
        tmpA[index] = arr[first2];
    }

    for (index = start; index <= end; ++index)
    {
        arr[index] = tmpA[index];
    }
}

void merge_sort(int start, int end)
{
    if (start < end)
    {
        int mid = (end + start) / 2;
        merge_sort(start, mid);
        merge_sort(mid + 1, end);
        merge(start, mid, end);
    }
}

void print(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int count(int find, int start, int n)
{
    int i = start;
    int j = n;
    int cnt = 0;
    for (; i < j;)
    {
        if (arr[i] + arr[j] > find)
            j--;
        else if (arr[i] + arr[j] == find)
        {
            i++;
            j--;
            cnt++;
        }
        else if (arr[i] + arr[j] < find)
        {
            i++;
        }
    }
    return cnt;
}

int main()
{
    int n;
    int b;
    scanf("%d %d", &n, &b);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    merge_sort(0, n - 1);
    int result = count(b, 0, n - 1);
    printf("%d", result);

    return 0;
}
