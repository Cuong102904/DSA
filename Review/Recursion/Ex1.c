// Write a program in C to print the first 50 natural numbers using recursion.
#include <stdio.h>

int print(int value)
{
    if (value <= 50)
    {
        printf("%d ", value);
        return print(1 + value);
    }
    return 1;
}

int main()
{
    int value = 1;
    print(value);
    return 0;
}
