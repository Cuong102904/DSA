/*Write a program in C to find the Factorial of a number using recursion. >
Test Data :
Input a number : 5
Expected Output:

The Factorial of 5 is : 120*/
#include <stdio.h>

int factorial(int k, int val)
{
    if (k == 0 || k == 1)
    {
        return val;
    }
    else
    {
        val *= k;
        factorial(k - 1, val);
    }
}

int main()
{
    int k;
    printf("Input the number: ");
    scanf("%d", &k);
    int ketqua = factorial(k, 1);
    printf(" The Factorial of %d: %d", k, ketqua);
    return 0;
}