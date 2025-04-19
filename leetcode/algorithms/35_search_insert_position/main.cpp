#include <vector>
using namespace std;

class SearchInsertPosition {
public:
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
    // Solution 1: Binary Search
    // Time complexity: O(log(n)), Space complexity: O(1)
    int solution1(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size();
        int mid;
        if (target > nums[high - 1]) {
            return high;
        }
        while (low <= high) {
            mid = (low + high) / 2;
            if (target > nums[mid]) {
                low = mid + 1;
            } else if (target < nums[mid]) {
                high = mid - 1;
            } else {
                return mid;
            }
        }
        return low;
    }

    // Solution 2:
    int solution2(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
