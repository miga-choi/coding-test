#include <vector>
using namespace std;

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
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
class Solution {
public:
    vector<int>& preSum; // `preSum` will reference to `nums` array, no copy at all!

    Solution(vector<int>& nums) : preSum(nums) {
        for (int i = 1; i < preSum.size(); ++i) {
            preSum[i] += preSum[i - 1];
        }
    }

    int sumRange(int left, int right) {
        if (left == 0) {
            return preSum[right];
        }
        return preSum[right] - preSum[left - 1];
    }
};
