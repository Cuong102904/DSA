#include <stdio.h>
#include <math.h>
#define PI 3.1415926535898

int main()
{
    float b, c, d;
    float a = 1;
    float dt, k, x1, x2, x3, x;
    scanf("%f %f %f", &b, &c, &d);

    dt = b * b - 3 * a * c;
    k = (9 * a * b * c - 2 * pow(b, 3) - 27 * pow(a, 2) * d) / (2 * sqrt(pow(fabs(dt), 3)));
    if (dt > 0)
    {
        if (fabs(k) <= 1)
        {
            x1 = (2 * sqrt(dt) * cos(acos(k) / 3) - b) / (3 * a);
            x2 = (2 * sqrt(dt) * cos(acos(k) / 3 - 2 * PI / 3) - b) / (3 * a);
            x3 = (2 * sqrt(dt) * cos(acos(k) / 3 + 2 * PI / 3) - b) / (3 * a);
            if (x1 == (int)x1 && x2 == (int)x2 && x3 == (int)x3)
            {
                if (x1 != x2 && x1 != x2 && x2 != x3)
                {
                    printf(" %.0f 1 \n", x3);
                    printf(" %.0f 1 \n", x2);
                    printf(" %.0f 1 \n", x1);
                }
                else if (x1 = x2 && x2 != x3)
                {
                    printf(" %.0f 2\n", x1);
                    printf(" %.0f 1\n", x3);
                }
                else if (x1 = x3 && x2 != x3)
                {
                    printf(" %.0f 2\n", x1);
                    printf(" %.0f 1\n", x2);
                }
                else if (x2 = x3 && x1 != x3)
                {
                    printf(" %.0f 2\n", x2);
                    printf(" %.0f 1\n", x1);
                }
            }
            else
                printf("NO SOLUTION");
        }
        if (fabs(k) > 1)
        {
            x = ((sqrt(dt) * fabs(k)) / (3 * a * k)) * (pow((fabs(k) + sqrt(pow(k, 2) - 1)), 1.0 / 3) + pow((fabs(k) - sqrt(pow(k, 2) - 1)), 1.0 / 3)) - (b / (3 * a));

            printf("NO SOLUTION");
        }
    }
    else if (dt == 0)
    {
        x = (-b - pow(-(pow(b, 3) - 27 * a * a * d), 1.0 / 3)) / (3 * a); // do ham pow khong dung doi so am nen ta phai doi dau.Ct goc:x=(-b+pow(pow(b,3)-27*a*a*d),1.0/3))/(3*a)

        printf("NO SOLUTION");
    }
    else
    {
        x = (sqrt(fabs(dt)) / (3 * a)) * (pow((k + sqrt(k * k + 1)), 1.0 / 3) - pow(-(k - sqrt(k * k + 1)), 1.0 / 3)) - (b / (3 * a));

        printf("NO SOLUTION");
    }
    return 0;
}