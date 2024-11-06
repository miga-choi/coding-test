#include <stdlib.h>
#include <unordered_map>
#include <vector>
using namespace std;

class ContainsDuplicateII
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> numsMap;
        for (int i = 0; i < nums.size(); i++)
        {
            if (numsMap.count(nums[i]) == 0)
            {
                numsMap.insert(make_pair(nums[i], i));
            }
            else
            {
                if (abs(numsMap.find(nums[i])->second - i) <= k)
                {
                    return true;
                }
                numsMap.find(nums[i])->second = i;
            }
        }
        return false;
    }

    // Best Solution
    bool bestSolution(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            // mp.count() will tell whatever ith index that I want, have I seen it before?
            if (mp.count(nums[i]))
            {
                // if I have already seen this number, then check for condition abs(i - j) <= k
                if (abs(i - mp[nums[i]]) <= k)
                {
                    return true;
                }
            }

            // if I have not seen this number before, insert the number with its position in the map
            // and if the number is already present in the map, then update the position of that number
            mp[nums[i]] = i;
        }

        // after the complete traversal, if we don't find a pair to satisfy the condition, return false
        return false;
    }
};