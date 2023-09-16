#include <stdio.h>
#include <stdbool.h>

bool canJump(int *nums, int numsSize)
{
    if (numsSize <= 1)
    {
        return 0; // The array is empty or only contains one element
    }

    int maxReach = nums[0]; // The maximum index that can be reached from the current position
    int step = 0;
    for (int i = 1; i < numsSize; i++)
    {
        maxReach = (i + nums[i] > maxReach) ? i + nums[i] : maxReach;
        if (maxReach < i + nums[i])
        {
            maxReach = i + nums[i];
            step++;
        }
        if (maxReach >= numsSize - 1)
            break;
    }

    return step;
}

int main()
{
    int num[] = {2, 0, 0};
    if (canJump(num, 3))
    {
        printf("It is possible to reach the last index.\n");
    }
    else
    {
        printf("It is not possible to reach the last index.\n");
    }

    return 0;
}
