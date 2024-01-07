#include <vector>

using namespace std;

class TwoSum
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }

        return {};
    }


    // Best Solution
    // Best Solution 1: Brute Force
    vector<int> bestSolution1(vector<int> &nums, int target)
    {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {}; // No solution found
    }

    // Best Solution 2: Two-pass Hash Table
    vector<int> bestSolution2(vector<int> &nums, int target)
    {
        unordered_map<int, int> numMap;
        int n = nums.size();

        // Build the hash table
        for (int i = 0; i < n; i++)
        {
            numMap[nums[i]] = i;
        }

        // Find the complement
        for (int i = 0; i < n; i++)
        {
            int complement = target - nums[i];
            if (numMap.count(complement) && numMap[complement] != i)
            {
                return {i, numMap[complement]};
            }
        }

        return {}; // No solution found
    }

    // Best Solution 3: One-pass Hash Table
    vector<int> bestSolution3(vector<int> &nums, int target)
    {
        unordered_map<int, int> numMap;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int complement = target - nums[i];
            if (numMap.count(complement))
            {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }

        return {}; // No solution found
    }
};