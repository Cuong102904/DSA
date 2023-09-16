/* Write a program in C to calculate the sum of numbers from 1 to n using recursion.
Test Data :
Input the last number of the range starting from 1 : 5
Expected Output:

The sum of numbers from 1 to 5 : 15  */
#include <stdio.h>
int sum = 0;
int Sum(int value)
{
    sum += value;
    if (value == 1)
        return sum;
    else
        return Sum(value - 1);
}

int main()
{
    int value;
    printf("%d THe lát number ò the range starting from 1: ");
    scanf("%d", &value);
    printf("The sum of numbers from 1 to %d is : %d", value, Sum(value));
    return 0;
}
