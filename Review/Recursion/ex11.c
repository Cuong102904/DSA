/*Write a program in C to convert a decimal number to binary using recursion. >
Test Data :
Input any decimal number : 66
Expected Output :

The Binary value of decimal no. 66 is : 1000010*/
#include <stdio.h>

void convert(int k)
{
    if (k != 0)
    {
        convert(k / 2);
        printf("%d", k - (k / 2) * 2);
    }
}

int main()
{
    int k;
    printf("Input any decimal number: ");
    scanf("%d", &k);
    printf("The binary value of decimal no. %d is : ", k);
    convert(k);
    return 0;
}