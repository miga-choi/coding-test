#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class MajorityElement {
public:
    /**
     * Boyer-Moore Voting Algorithm
     *
     * Complexities:
     *   N - `numsSize`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int majorityElement(vector<int>& nums) {
        int result;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                result = nums[i];
            }

            if (result == nums[i]) {
                count++;
            } else {
                count--;
            }
        }

        return result;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Boyer-Moore Voting Algorithm
     *
     * Complexities:
     *   N - `numsSize`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int solution1(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }

            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }

    /**
     * Solution 2
     * 
     * Sorting
     *
     * Complexities:
     *   N - `numsSize`
     *   - Time Complexity: O(N * logᴺ)
     *   - Space Complexity: O(logᴺ)
     */
    int solution2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        return nums[nums.size() / 2];
    }
};
