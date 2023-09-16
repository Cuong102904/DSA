/*Write a program in C to get the largest element of an array using recursion. >
Test Data :
Input the number of elements to be stored in the array :5
Input 5 elements in the array :
element - 0 : 5
element - 1 : 10
element - 2 : 15
element - 3 : 20
element - 4 : 25
Expected Output :

Largest element of an array is: 25  */

#include <stdio.h>

void nhap(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }
}

int checklargest(int arr[], int largest, int n)
{
    if (n >= 0)
    {
        if (largest <= arr[n])
        {
            largest = arr[n];
        }
        return checklargest(arr, largest, n - 1);
    }
    else
        return largest;
}

int main()
{
    int arr[100];
    int n;
    printf("nhap so phan tu: ");
    scanf("%d", &n);
    nhap(arr, n);

    int solonnhat = checklargest(arr, 0, n - 1);
    printf("Largest element of an array is: %d ", solonnhat);

    return 0;
}