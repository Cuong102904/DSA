/*Write a program in C to reverse a string using recursion. >
Test Data :
Input any string: w3resource
Expected Output:

The reversed string is: ecruoser3w */

#include <stdio.h>
#include <string.h>

void Rever(char *arr)
{

    if (*arr)
    {
        Rever(arr + 1);
        printf("%c", *arr);
    }
}

int main()
{
    char arr[100];
    printf("Input any string : ");
    scanf("%s", arr);
    Rever(arr);
    return 0;
}