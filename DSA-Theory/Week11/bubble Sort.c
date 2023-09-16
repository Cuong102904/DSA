
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Bubble_Sort(int a[], int size)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int k = i; k < n - k - 1; k++)
        {
            if (a[k] > a[k + 1])
            {
                swap(&a[k], &a[k + 1]);
            }
        }
    }
}