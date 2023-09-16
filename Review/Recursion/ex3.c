/* Write a program in C to print the Fibonacci Series using recursion. >
Test Data :
Input number of terms for the Series (< 20) : 10
Expected Output:

 Input number of terms for the Series (< 20) : 10
 The Series are :
 1  1  2  3  5  8  13  21  34  55 */
#include <stdio.h>

int FIbonacci(int val)
{
    if (val < 0)
        return 1;
    if (val == 1 || val == 0)
        return val;
    else

        return FIbonacci(val - 1) + FIbonacci(val - 2);
}

int main()
{
    int val;
    scanf("%d", &val);
    for (int i = 1; i <= val; i++)
    {
        printf("%d ", FIbonacci(i));
    }
    return 0;
}