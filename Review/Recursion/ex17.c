/*Write a program in C to calculate the power of any number using recursion. >
Test Data :
Input the base value : 2
Input the value of power : 6
Expected Output :

The value of 2 to the power of 6 is : 64  */
#include <stdio.h>

int SoMu(int baseval, int valpow, int sum)
{
    if (valpow == 0)
    {
        return sum;
    }
    sum *= baseval;
    return SoMu(baseval, valpow - 1, sum);
}

int main()
{
    int baseval, valpow;
    int sum = 1;
    scanf("%d %d", &baseval, &valpow);
    printf(" So mu: %d", SoMu(baseval, valpow, sum));
    return 0;
}