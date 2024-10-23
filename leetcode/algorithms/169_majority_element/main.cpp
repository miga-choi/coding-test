#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class MajorityElement
{
public:
    int majorityElement(vector<int> &nums)
    {
        int result;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
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

    // Best Solution 1: Sorting
    int bestSolution1(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n / 2];
    }

    // Best Solution 2: Hash Map
    int bestSolution2(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> m;

        for (int i = 0; i < n; i++)
        {
            m[nums[i]]++;
        }
        n = n / 2;
        for (auto x : m)
        {
            if (x.second > n)
            {
                return x.first;
            }
        }
        return 0;
    }

    // Best Solution 3: Moore Voting Algorithm
    int bestSolution3(vector<int> &nums)
    {
        int count = 0;
        int candidate = 0;

        for (int num : nums)
        {
            if (count == 0)
            {
                candidate = num;
            }

            if (num == candidate)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        return candidate;
    }
};