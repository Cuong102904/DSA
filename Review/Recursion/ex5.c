/*Write a program in C to count the digits of a given number using recursion. >
Test Data :
Input a number : 50
Expected Output :

The number of digits in the number is :  2*/

#include <stdio.h>

int countdigits(int k, int i)
{
    if (k != 0)
    {
        i++;
        return countdigits(k / 10, i);
    }
    else
        return i;
}
int main()
{
    int val;
    scanf("%d", &val);
    printf("%d", countdigits(val, 0));
}