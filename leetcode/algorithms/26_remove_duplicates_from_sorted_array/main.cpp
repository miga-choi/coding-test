#include <vector>
using namespace std;

class RemoveDuplicatesFromSortedArray
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }

        int j = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[j - 1])
            {
                nums[j] = nums[i];
                j++;
            }
        }

        return j;
    }


    // Best Solution
    // Best Solution 1:
    int bestSolution1(vector<int> &nums)
    {
        int j = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }

    // Best Solution 2:
    int bestSolution2(vector<int> &nums)
    {
        int count = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
                count++;
            else
                nums[i - count] = nums[i];
        }
        return nums.size() - count;
    }

    // Best Solution 3:
    int bestSolution3(vector<int> &nums)
    {
        int i = 0;
        for (int n : nums)
        {
            if (!i || n > nums[i - 1])
            {
                nums[i++] = n;
            }
        }
        return i;
    }

    // Best Solution 4:
    int bestSolution4(vector<int> &nums)
    {
        int i = !nums.empty();
        for (int n : nums)
        {
            if (n > nums[i - 1])
            {
                nums[i++] = n;
            }
        }
        return i;
    }
};