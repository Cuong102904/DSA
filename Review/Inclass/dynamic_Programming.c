#include <stdio.h>
#define N 100

void nhap(int arr[], int k)
{
    for (int i = 0; i < k; i++)
    {
        printf("arr[%d]= ", i);
        scanf("%d", &arr[i]);
    }
}

int subMax(int arr[], int k)
{
    int smax = arr[0];
    int maxendhere = arr[0];
    int imax = 0; // vi tri subarrary max
    for (int i = 1; i < k; i++)
    {
        int u = maxendhere + arr[i];
        int v = arr[i];
        if (u > v)
            maxendhere = u;
        else
            maxendhere = v;
        if (maxendhere > smax)
        {
            smax = maxendhere;
            imax = i;
        }
    }
    return smax;
}

int main()
{
    int arr[N];
    int k;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &k);
    nhap(arr, k);
    printf("The maximum subarray is : %d ", subMax(arr, k));
    return 0;
}
