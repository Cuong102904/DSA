/*Write a program in C to find the GCD of two numbers using recursion. >
Test Data :
Input 1st number: 10
Input 2nd number: 50
Expected Output :

The GCD of 10 and 50 is: 10 */
#include <stdio.h>
// tim uoc chung lon nhat
int GCD(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            return GCD(b, a - b);
        else
            return GCD(a, b - a);
    }
    return b;
}

int main()
{
    int a, b;
    printf("Input 2 numbers :");
    scanf("%d %d", &a, &b);
    int GCD1 = GCD(a, b);
    printf("The GCD of %d and %d is: %d", a, b, GCD1);
    return 0;
}