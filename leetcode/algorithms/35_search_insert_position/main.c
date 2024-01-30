int searchInsert(int *nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (target > nums[mid])
        {
            left = mid + 1;
        }
        else if (target < nums[mid])
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }
    }

    return left;
}


// Best Solution
// Best Solution 1: Linear Search O(n)
int bestSolution1(int *nums, int numsSize, int target)
{
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] >= target)
        {
            return i;
        }
    }
    return numsSize;
}

// Best Solution 2: Binary Search O(log(n))
int bestSolution2(int *nums, int numsSize, int target)
{
    int left = 0, right = numsSize - 1, mid;
    while (left <= right)
    {
        mid = (right + left) / 2;
        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return left;
}