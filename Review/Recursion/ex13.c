/*Write a program in C to find the LCM of two numbers using recursion. >
Test Data :
Input 1st number for LCM : 4
Input 2nd number for LCM : 6
Expected Output :

The LCM of 4 and 6 :  12*/

#include <stdio.h>

int LCM(int a, int b)
{
    static int m;
    m += b;
    if (m % a == 0 && m % b == 0)
    {
        return m;
    }
    else
        return LCM(a, b);
}

int main()
{
    int max;
    int a, b;
    scanf("%d %d", &a, &b);
    if (a <= b)
        max = LCM(a, b);
    else
        max = LCM(b, a);
    printf("%d \n", max);
    return 0;
}