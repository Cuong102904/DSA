/* Write a C program to find the Hailstone Sequence of a given number up to 1. >
Test Data :
Input any number (positive) to start for Hailstone Sequence : 13
Expected Output :

 The hailstone sequence starting at 13 is :
 13  40  20  10  5  16  8  4  2 1
 The length of the sequence is 10.*/
#include <stdio.h>
#include <stdlib.h>

int Getnextval(int i)
{

    if (i % 2 == 0)
    {
        i /= 2;
    }
    else
    {
        i = 3 * i + 1;
    }
    return i;
}

int check(int fir, int *count)
{
    if (fir == 1)
    {
        printf("%d", fir);
        *count += 1;
    }
    else
    {
        printf("%d ", fir);
        *count += 1;
        return check(Getnextval(fir), count);
    }
    return *count;
}

int main()
{
    //   int *count = malloc(sizeof(int));
    int count = 0;
    int fir;
    scanf("%d", &fir);
    printf("The hailstone sequence starting at %d is :\n", fir);
    check(fir, &count);
    printf("\nThe length of the sequence: %d", count);
    //   free(count);
    return 0;
}