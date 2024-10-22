int majorityElement(int *nums, int numsSize)
{
    int result;
    int count = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (count == 0)
        {
            result = nums[i];
        }
        if (result == nums[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return result;
}

// Best Solution
int bestSolution(int *nums, int numsSize)
{
    int sol;
    int cnt = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (cnt == 0)
        {
            sol = nums[i];
        }
        if (nums[i] == sol)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    return sol;
}