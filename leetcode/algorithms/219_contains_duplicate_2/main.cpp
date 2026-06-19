#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class ContainsDuplicateII {
public:
    /**
     * Hash Map
     * 
     * Complexities:
     *   N - `numsSize`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> numsMap;

        for (int i = 0; i < nums.size(); i++) {
            if (numsMap.count(nums[i]) == 0) {
                numsMap.insert(make_pair(nums[i], i));
            } else {
                if (abs(numsMap.find(nums[i])->second - i) <= k) {
                    return true;
                }
                numsMap.find(nums[i])->second = i;
            }
        }

        return false;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Sliding Window + Hash Set
     * 
     * Complexities:
     *   N - Size of `nums`
     *   K - `k`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(min(N, K))
     */
    bool solution1(vector<int>& nums, int k) {
        unordered_set<int> window;

        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) {
                window.erase(nums[i - k - 1]);
            }

            if (window.count(nums[i])) {
                return true;
            }

            window.insert(nums[i]);
        }

        return false;
    }

    /**
     * Solution 2
     * 
     * Hash Map
     * 
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    bool solution2(vector<int>& nums, int k) {
        unordered_map<int, int> num_to_index;

        for (int i = 0; i < nums.size(); ++i) {
            if (num_to_index.count(nums[i]) && (i - num_to_index[nums[i]] <= k)) {
                return true;
            }
            num_to_index[nums[i]] = i;
        }

        return false;
    }
};
