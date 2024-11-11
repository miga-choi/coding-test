#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **summaryRanges(int *nums, int numsSize, int *returnSize)
{
}

// Best Solution 1
char **bestSolution1(int *nums, int numsSize, int *returnSize)
{
    int start = 0;
    char **final_arr = (char **)malloc(20 * sizeof(char *));
    int count = 0;
    for (int k = 0; k < numsSize; k++)
    {
        // did "-1" here, since the number will not be stored (too large)
        if (k == 0 || nums[k] - 1 > nums[k - 1])
        {
            start = nums[k];
        }

        // we are at the finish line
        if (k == numsSize - 1 || nums[k] + 1 < nums[k + 1])
        {
            final_arr[count] = (char *)malloc(30 * sizeof(char));
            if (start < nums[k])
            {
                snprintf(final_arr[count], 28, "%d->%d", start, nums[k]);
            }
            else
            {
                snprintf(final_arr[count], 28, "%d", start);
            }
            printf("%s\n", final_arr[count]);
            count++;
        }
    }
    *returnSize = count;
    return final_arr;
}

// Best Solution 2
char **bestSolution2(int *nums, int numsSize, int *returnSize)
{
    *returnSize = 0;
    if (numsSize == 0)
        return NULL;
    int i, count = 0, start = nums[0], prev = nums[0];
    char **ret = (char **)malloc(sizeof(char *) * 20);
    ret[0] = (char *)malloc(sizeof(char) * 25);
    for (i = 1; i < numsSize; i++)
    {
        ret[i] = (char *)malloc(sizeof(char) * 25);
        if (prev != nums[i] - 1)
        {
            if (start == prev)
                sprintf(ret[count++], "%d", start);
            else
                sprintf(ret[count++], "%d->%d", start, prev);
            start = nums[i];
        }
        prev = nums[i];
    }
    if (start == prev)
        sprintf(ret[count++], "%d", start);
    else
        sprintf(ret[count++], "%d->%d", start, prev);
    *returnSize = count;
    return ret;
}
