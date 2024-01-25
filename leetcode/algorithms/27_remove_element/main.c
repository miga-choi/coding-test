#include <stdbool.h>

int removeElement(int *nums, int numsSize, int val)
{
    int i = 0;
    for (int j = 0; j < numsSize; j++)
    {
        if (nums[j] != val)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
        }
    }
    return i;
}


// Best Solution
// Best Solution 1:
int bestSolution1(int *nums, int numsSize, int val)
{
    int count = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == val)
        {
            count++;
        }
        else
        {
            nums[i - count] = nums[i];
        }
    }

    return (numsSize - count);
}

// Best Solution 2:
int bestSolution2(int *nums, int numsSize, int val)
{
    int appendIndex = 0;
    bool find = false;
    int k = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == val && !find)
        {
            appendIndex = i;
            find = true;
        }
        if (nums[i] != val)
        {
            nums[appendIndex] = nums[i];
            appendIndex++;
            k++;
        }
    }

    return k;
}