/*Write a program in C for binary search using recursion. >
Test Data :
Input the number of elements to store in the array :3
Input 3 numbers of elements in the array in ascending order :
element - 0 : 15
element - 1 : 25
element - 2 : 35
Input the number to search : 35
Expected Output :

 The search number found in the array.*/

#include <stdio.h>
#define N 100

void nhap(int arr[], int k)
{
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &arr[i]);
    }
}
int check(int arr[], int search, int i)
{
    if (search == arr[i])
        return 1;
    return check(arr, search, i + 1);
    return 0;
}

int main()
{
    int arr[N];
    int search;
    int k;
    scanf("%d", &k);
    nhap(arr, k);
    printf("Input the number to search:");
    scanf("%d", &search);
    if (check(arr, search, 0))
    {
        printf("The search number found in the array.\n");
    }
    else
        printf("The search number did'n find in the array");

    return 0;
}