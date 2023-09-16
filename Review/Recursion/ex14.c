/* Write a C program to check whether a given string is a palindrome or not using recursion. >
Test Data :
Input a word to check for palindrome : mom
Expected Output :

 The entered word is a palindrome.*/

#include <stdio.h>
#include <string.h>
void check();
int main()
{
    char arr[100];
    scanf("%s", &arr);
    check(arr, 0);
}
void check(char arr[], int fir)
{
    int last = strlen(arr) - (fir + 1);
    if (arr[fir] == arr[last])
    {
        if (fir + 1 == last || fir == last)
        {
            printf("This entered word is palindrome");
            return;
        }

        return check(arr, fir + 1);
    }
    else
        printf("this entered word is not palindrome");
}
