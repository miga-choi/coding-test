#include <vector>
using namespace std;

class SingleNumber
{
public:
    int singleNumber(vector<int> &nums)
    {
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            result = result ^ nums[i];
        }
        return result;
    }

    // Best Solution 1: USING MAPS (NOT USING CONSTANT SPACE)
    int bestSolution1(vector<int> &nums)
    {
        unordered_map<int, int> a;
        for (auto x : nums)
            a[x]++;
        for (auto z : a)
            if (z.second == 1)
                return z.first;
        return -1;
    }

    // Best Solution 2: USING SORTING (USING CONSTANT SPACE)
    int bestSolution2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i += 2)
        {
            if (nums[i] != nums[i - 1])
                return nums[i - 1];
        }
        return nums[nums.size() - 1];
    }

    // Best Solution 3: USING BITWISE XOR OPERATOR (USING CONSTANT SPACE)
    int bestSolution3(vector<int> &nums)
    {
        int ans = 0;
        for (auto x : nums)
            ans ^= x;
        return ans;
    }
};