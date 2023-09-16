#include <stdio.h>

int findMaxSubarry(int arr[], int n)
{
    int i, j, k;
    int max = arr[0];
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            int sum = 0;
            for (k = i; k <= j; k++)
            {
                sum += arr[k];
                if (sum >= max)
                    max = sum;
            }
        }
    }
    return max;
}

void nhap(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d]= ", i);
        scanf("%d", &arr[i]);
    }
}
int main()
{
    int arr[100];
    int n;
    scanf("%d", &n);
    nhap(arr, n);
    printf("the max of subarray is: %d", findMaxSubarry(arr, n));
}