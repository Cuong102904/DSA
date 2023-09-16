#include <stdio.h>

typedef struct Point
{
    double x;
    double y;
} point_t;

int main()
{
    point_t pl;
    pl.x = 123;
    pl.y = 345;
    point_t p2 = pl;
    printf("%f %f", p2.x, p2.y);

    point_t *p3;
    p3 = &p2;
    p3->x = 100;
    p3->y = 500;
    printf("\n new p2 = %f, %f", p2.x, p2.y);
    return 0;
}
