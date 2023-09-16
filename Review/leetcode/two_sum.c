#include <stdio.h>
#define N 10000

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
}

int main()
{
    int nums[N];
    int numSize, target;
    scanf("%d %d", &numSize, &target);
    for (int i = 0; i < numSize; i++)
    {
        scanf("%d", &nums[i]);
    }
    int *returnSize;
    returnSize = twoSum(nums, numSize, target, returnSize)
}