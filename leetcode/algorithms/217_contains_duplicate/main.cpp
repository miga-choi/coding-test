#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class ContainsDuplicate {
public:
    /**
     * Set
     * - Time Complexity: O(N * logⁿ)
     * - Space Complexity: O(N)
     */
    bool containsDuplicate(vector<int> &nums) {
        set<int> s;

        for (int i = 0; i < nums.size(); i++) {
            if (s.count(nums[i]) > 0) {
                return true;
            } else {
                s.insert(nums[i]);
            }
        }

        return false;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Sort
     * - Time Complexity: O(N * logⁿ)
     * - Space Complexity: O(1)
     */
    bool solution1(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }

        return false;
    }

    /**
     * Solution 2
     * 
     * Set
     * - Time Complexity: O(N * logⁿ)
     * - Space Complexity: O(N)
     */
    bool solution2(vector<int> &nums) {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();
    }

    /**
     * Solution 3
     * 
     * Map
     * - Time Complexity: O(N * logⁿ)
     * - Space Complexity: O(N)
     */
    bool solution3(vector<int> &nums) {
        map<int, int> mp;

        for (auto i : nums) {
            mp[i]++;
        }

        for (auto i : mp) {
            if (i.second >= 2) {
                return true;
            }
        }

        return false;
    }

    /**
     * Solution 4
     * 
     * Unordered Map
     * - Time Complexity: O(N)
     * - Space Complexity: O(N)
     */
    bool solution4(vector<int> &nums) {
        unordered_map<int, int> mp;

        for (auto i : nums) {
            mp[i]++;
        }

        for (auto i : mp) {
            if (i.second >= 2) {
                return true;
            }
        }

        return false;
    }
};
