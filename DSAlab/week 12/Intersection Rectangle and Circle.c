#include <stdio.h>
#include <math.h>

int max(int *a, int *b)
{
    if (*a > *b)
    {
        return *a;
    }
    else
        return *b;
}
int min(int *a, int *b)
{
    if (*a < *b)
        return *a;
    else
        return *b;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int check(int x1, int y1, int x2, int y2, int x, int y, int r)
{ // chọn x2 is higher abscissa
    if (x1 > x2)
        swap(&x1, &x2);
    if (y1 > y2) // choose y2 is higher ordinate
        swap(&y1, &y2);
    // check wheares circle intesect with rectangle in 1 point?
    if (x1 <= x && x <= x2)
    {
        if (abs(y1 - y) <= r || abs(y2 - y) <= r)
            return 1;
    }
    else if (y1 <= y && y2 >= y)
    {
        if (abs(x1 - x) <= r || abs(x2 - x) <= r)
            return 1;
    }
    /*Case 1: The side of the rectangle touches or intersects the circle. In order to check whether the shapes intersect, we need to find a point on or inside the rectangle that is closest to the center of the circle. If this point lies on or inside the circle, it is guaranteed that both the shapes intersect. Let the closest point be denoted by (Xn, Yn).*/
    int tmpx = min(&x2, &x);
    int tmpy = min(&y2, &y);
    int xn = max(&x1, &tmpx);
    int yn = max(&y1, &tmpy);
    int Dx = xn - x;
    int Dy = yn - y;
    return (Dx * Dx + Dy * Dy) <= r * r;
}

void run()
{
    int cases, x1, x2, y1, y2, x, y, r;
    scanf("%d", &cases);
    for (int i = 1; i <= cases; i++)
    {
        scanf("%d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x, &y, &r);
        if (check(x1, y1, x2, y2, x, y, r))
        {
            printf("1\n");
        }
        else
            printf("0\n");
    }
}

int main()
{
    run();
    return 0;
}