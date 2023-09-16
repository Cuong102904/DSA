/* Write a program in C to print the array elements using recursion.
Test Data :
Input the number of elements to be stored in the array :6
Input 6 elements in the array :
element - 0 : 2
element - 1 : 4
element - 2 : 6
element - 3 : 8
element - 4 : 10
element - 5 : 12
Expected Output :

The elements in the array are : 2  4  6  8  10  12*/

#include <stdio.h>

void nhap(int arr[], int val)
{
    for (int i = 0; i <= val; i++)
    {
        printf("element -%d: ", i);
        scanf("%d", &arr[i]);
    }
}
void xuat(int arr[], int val, int i)
{
    if (val >= 0)
    {
        printf(" %d", arr[i]);
        xuat(arr, val - 1, i + 1);
    }
}

int main()
{
    int arr[10];
    int val;
    scanf("%d", &val);
    nhap(arr, val);
    printf("The elements in the array are :");
    xuat(arr, val, 0);
    return 0;
}