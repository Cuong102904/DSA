#include <stdio.h>
#include <string.h>
#define N 100

int arr[N];
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
// void bublesort(int arr[], int n)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         int cnt = 0;
//         for (int j = 0; j <= n - 1 - i; j++)
//             if (arr[j] > arr[j + 1])
//             {
//                 swap(&arr[j], &arr[j + 1]);
//                 cnt++;
//             }
//         if(cnt ==0) break;
//     }
// }

void bublesort(int arr[], int n)
{
    int sort = 0;
    for (int i = 1; i <= n; i++)
    {
        int sort = 1;
        for (int j = 0; j <= n - 1 - i; j++)
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                sort = 0;
            }
        if (sort == 1)
            break;
    }
}

void print(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int n;
    printf("moi nhap so phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d]= ", i);
        scanf("%d", &arr[i]);
    }
    bublesort(arr, n);
    print(n);
}