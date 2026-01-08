#include <algorithm>
#include <vector>
using namespace std;

class SearchInsertPosition {
public:
    /**
     * Binary Search
     *
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(logᴺ)
     *   - Space Complexity: O(1)
     */
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (target > nums[mid]) {
                left = mid + 1;
            } else if (target < nums[mid]) {
                right = mid - 1;
            } else {
                return mid;
            }
        }

        return left;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Binary Search
     *
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(logᴺ)
     *   - Space Complexity: O(1)
     */
    int solution1(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }

    /**
     * Solution 2
     * 
     * algorithm::lower_bound
     *
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(logᴺ)
     *   - Space Complexity: O(1)
     */
    int solution2(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
