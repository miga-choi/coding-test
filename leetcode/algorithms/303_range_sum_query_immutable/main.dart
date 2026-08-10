/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = NumArray(nums);
 * int param1 = obj.sumRange(left,right);
 */

/**
 * Complexities:
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
class NumArray {
  late final List<int> _numArray;

  NumArray(List<int> nums) {
    _numArray = nums;
  }

  int sumRange(int left, int right) {
    int sum = 0;
    for (var i = left; i <= right; i++) {
      sum += _numArray[i];
    }
    return sum;
  }
}


// Solution
/**
 * Complexities:
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
class Solution {
  final List<int> _prefix;

  Solution(List<int> nums) : _prefix = List<int>.filled(nums.length + 1, 0) {
    for (var i = 0; i < nums.length; i++) {
      _prefix[i + 1] = _prefix[i] + nums[i];
    }
  }

  int sumRange(int left, int right) => _prefix[right + 1] - _prefix[left];
}
