#include <stdio.h>

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}

int step(int fromCap, int tocCap, int value)
{
    int from = fromCap;
    int to = 0;
    int step = 1; // fulfill in from Cap

    while (from != value && to != value)
    {
        int tmp = min(from, tocCap - to); // check the maximum that can pour to the ToCap
        to += tmp;
        from -= tmp;
        step++;
        if (from == value || to == value)
        {
            break;
        }
        if (from == 0)
        {
            from = fromCap;
            step++;
        }
        if (to == tocCap)
        {
            step++;
            to = 0;
        }
    }
    return step;
}

void checkminStep(int fromCap, int toCap, int value)
{
    int step1 = step(fromCap, toCap, value);
    int step2 = step(toCap, fromCap, value);
    int minstep = min(step1, step2);
    printf("%d", minstep);
}

int main()
{
    int from_cap;
    int to_cap;
    int value;
    scanf("%d %d %d", &from_cap, &to_cap, &value);
    checkminStep(from_cap, to_cap, value);
    return 0;
}