/*Write a program in C to copy one string to another using recursion. >
Test Data :
Input the string to copy : w3resource
Expected Output :

 The string successfully copied.

 The first string is : w3resource
 The copied string is : w3resource*/
#include <stdio.h>

void copy(char fir[], char cp[], int k)
{
    cp[k] = fir[k];
    if (fir[k] == '\0')
        return;
    return copy(fir, cp, k + 1);
}

int main()
{
    char fir[100];
    char cp[100];
    scanf("%s", fir);
    copy(fir, cp, 0);
    printf("%s", cp);
}