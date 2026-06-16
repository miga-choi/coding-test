#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

class ContainsDuplicate {
public:
    /**
     * Set
     * 
     * Complexities:
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
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
     * unordered_set
     * 
     * Complexities:
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    bool solution1(vector<int> &nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }

        return false;
        // return unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
    }

    /**
     * Solution 2
     * 
     * Sort
     * 
     * Complexities:
     *   - Time Complexity: O(N * logᴺ)
     *   - Space Complexity: O(1)
     */
    bool solution2(vector<int> &nums) {
        if (nums.size() <= 1) {
            return false;
        }

        sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }

        return false;
    }
};
