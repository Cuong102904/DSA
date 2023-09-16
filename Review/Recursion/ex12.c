/*Write a program in C to check if a number is a prime number or not using recursion. >
Test Data :
Input any positive number : 7
Expected Output :

The number 7 is a prime number.*/

#include <stdio.h>
#include <math.h>
void Primenumber(int k, int i)
{
    if (k == 2)
        printf("%d is a prime number\n");
    if (i <= sqrt(k))
    {
        if (k % i == 0)
            printf("The number %d is not a prime number", k);
        else
            return Primenumber(k, i + 1);
    }
    else
        printf("%d is a prime number\n", k);
}

int main()
{

    int i = 2;
    int k;
    printf("Input any positive number: ");
    scanf("%d", &k);
    Primenumber(k, i);
    return 0;
}