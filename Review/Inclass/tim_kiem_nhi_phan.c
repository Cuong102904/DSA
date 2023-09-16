#include <stdio.h>

int BSearch(int arr[], int start, int end, int x)
{
    int middle = (end + start) / 2;
    if (start == end)
    {
        if (x == arr[middle])
        {
            printf("Da tim ra va nam o vi tri [%d]", middle + 1);
            return 1;
        }
        else
        {
            printf("khong co \n");
            return 0;
        }
    }
    if (x == arr[middle])
    {
        printf("Da tim thay, nam o vi tri %d ", middle + 1);
        return 1;
    }
    if (x < arr[middle])
        return BSearch(arr, start + 1, middle, x);
    if (x > arr[middle])
        return BSearch(arr, middle + 1, end, x);
}

void nhap(int arr[], int k)
{
    for (int i = 0; i < k; i++)
    {
        printf("arr[%d]= ", i + 1);
        scanf("%d", &arr[i]);
    }
}

int main()
{
    int arr[100];
    int k;
    printf("Nhap so phan tu: ");
    scanf("%d", &k);
    nhap(arr, k);
    int x;
    printf("Moi nhap bien can tim: ");
    scanf("%d", &x);
    BSearch(arr, 0, k - 1, x);
    return 0;
}