#include <stdio.h>

void nhap(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d]=: ", i);
        scanf("%d", &arr[i]);
    }
}

int bruteforceV2(int arr[], int n)
{
    int i;
    int j;
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum >= max)
            {
                max = sum;
            }
        }
    }
    return max;
}

int main()
{
    int arr[100];
    int n;
    scanf("%d", &n);
    nhap(arr, n);
    printf("%d", bruteforceV2(arr, n));
    return 0;
}