#include <stdio.h>

long long C(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    return C(n - 1, k - 1) + C(n - 1, k);
}

int binsearch(int low, int high, int s[], int key)
{
    if (low > high)
        return -1;
    else
    {
        int mid = (low + high) / 2;
        if (s[mid] == key)
            return mid;
        else if (s[mid] > key)
            return binsearch(low, mid - 1, s, key);
        else
            return binsearch(mid + 1, high, s, key);
        return 1;
    }
}

int main()
{
    int s[] = {1, 3, 4, 5, 6, 7, 8, 9};
    int n = 8;
    int key = 3;
    printf("%d", binsearch(0, 8, s, 3));
    return 0;
}
