#include <set>
#include <vector>
using namespace std;

class ContainsDuplicate
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] == nums[j])
                {
                    return true;
                }
            }
        }
        return false;
    }

    // Best Solution 1: Brute Force
    bool bestSolution1(vector<int> &nums)
    {
        bool flag = false;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] == nums[j])
                {
                    return true;
                }
            }
        }
        return flag;
    }

    // Best Solution 2: Sort
    bool bestSolution2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        bool flag = false;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                return true;
            }
        }
        return flag;
    }

    // Best Solution 3: Set
    bool bestSolution3(vector<int> &nums)
    {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();
    }

    // Best Solution 4: Map
    bool bestSolution4(vector<int> &nums)
    {
        map<int, int> mp;
        for (auto i : nums)
        {
            mp[i]++;
        }
        bool flag = false;
        for (auto i : mp)
        {
            if (i.second >= 2)
            {
                return true;
            }
        }
        return flag;
    }

    // Best Solution 5: HashMap
    bool bestSolution5(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (auto i : nums)
        {
            mp[i]++;
        }
        bool flag = false;
        for (auto i : mp)
        {
            if (i.second >= 2)
            {
                return true;
            }
        }
        return flag;
    }
};