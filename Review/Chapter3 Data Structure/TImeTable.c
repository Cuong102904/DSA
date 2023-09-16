#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// kiểm tra xem giáo viên nào rảnh nhất

int TimeTable[1000][1000];
int N, T, S, R;
void truyengiatri()
{
    int i, j;
    for (i = 0; i < S; i++)
    {
        for (j = 0; j < S; j++)
        {
            TimeTable[i][j] = 0;
        }
    }
}
int findnguoiranhnhat()
{
    int maxteacher = 0;
    int maxslot = 0;
    int classes, teacher, slot, room;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d %d", &classes, &teacher, &slot, &room);
        TimeTable[slot - 1][room - 1] += 1;
    }
    for (slot = 0; slot < S; slot++)
    {
        int teacherranh = T;
        for (room = 0; room < R; room++)
        {
            if (TimeTable[slot][room] > 0)
            {
                teacherranh -= 1;
            }
        }
        if (teacherranh > maxteacher)
        {
            maxteacher = teacherranh;
            maxslot = slot + 1;
        }
    }
    return maxteacher;
}

int main()
{
    // fropen("test.txt","r",stdin);
    scanf("%d %d %d %d", &N, &T, &S, &R);
    truyengiatri();
    int gvienranh = findnguoiranhnhat();
    printf("%d", gvienranh);
    return 0;
}
