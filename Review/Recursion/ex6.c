/*Write a program in C to find the sum of digits of a number using recursion. >
Test Data :
Input any number to find sum of digits: 25
Expected Output:

The Sum of digits of 25 = 7*/
#include <stdio.h>

int Sumofdigits(int val, int count)
{
    if (val != 0)
    {
        count += val % 10;
        return Sumofdigits(val / 10, count);
    }
    else
        return count;
}

int main()
{
    int val;
    printf("Input any number to find sum of digits: ");
    scanf("%d", &val);
    printf("The sum of digits of %d = %d", val, Sumofdigits(val, 0));
}