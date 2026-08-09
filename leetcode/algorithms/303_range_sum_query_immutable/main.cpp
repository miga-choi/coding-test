#include <vector>
using namespace std;

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

/**
 * Complexities:
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
class NumArray {
public:
    vector<int>& numArray;

    NumArray(vector<int>& nums) : numArray(nums) {}

    int sumRange(int left, int right) {
        int sum = 0;
        for (int i = left; i <= right; i++) {
            sum += numArray[i];
        }
        return sum;
    }
};


// Solution
/**
 * Solution 1
 * 
 * Complexities:
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
class Solution1 {
    vector<int> prefix;

public:
    Solution1(vector<int>& nums) : prefix(nums.size() + 1, 0) {
        for (size_t i = 0; i < nums.size(); ++i)
            prefix[i + 1] = prefix[i] + nums[i];
    }

    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

/**
 * Solution 2
 * 
 * Complexities:
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
class Solution2 {
    vector<int> prefix;

public:
    Solution2(vector<int>& nums) : prefix(nums.size() + 1, 0) {
        partial_sum(nums.begin(), nums.end(), prefix.begin() + 1);
    }

    int sumRange(int left, int right) const {
        return prefix[right + 1] - prefix[left];
    }
};
