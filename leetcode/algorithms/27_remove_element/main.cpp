#include <vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int i = 0;
        for (int j = 0; j < nums.size(); j++)
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
    int bestSolution1(vector<int> &nums, int val)
    {
        int index = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }

    // Best Solution 2:
    int bestSolution2(vector<int> &nums, int val)
    {
        int length = nums.size(), index = 0;
        while (index < length)
        {
            if (nums[index] == val)
            {
                nums[index] = nums[length - 1];
                --length;
            }
            else
            {
                ++index;
            }
        }
        return length;
    }
};