/**
 * Your NumArray object will be instantiated and called as such:
 * var obj = new NumArray(nums)
 * var param_1 = obj.sumRange(left,right)
 */

/**
 * Complexities:
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 */
var NumArray = function (nums) {
  this.nums = [];

  for (const num of nums) {
    this.nums.push(num);
  }
};

/**
 * @param {number} left
 * @param {number} right
 * @return {number}
 */
NumArray.prototype.sumRange = function (left, right) {
  let sum = 0;

  for (let i = left; i <= right; i++) {
    sum += this.nums[i];
  }

  return sum;
};


// Solution
/**
 * Solution 1
 *
 * Complexities:
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 */
var Solution1_NumArray = function (nums) {
  this.prefix = new Array(nums.length + 1).fill(0);
  for (let i = 0; i < nums.length; i++) {
    this.prefix[i + 1] = this.prefix[i] + nums[i];
  }
};

/**
 * @param {number} left
 * @param {number} right
 * @return {number}
 */
Solution1_NumArray.prototype.sumRange = function (left, right) {
  return this.prefix[right + 1] - this.prefix[left];
};

/**
 * Solution 2
 *
 * Complexities:
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
class Solution2_NumArray {
  constructor(nums) {
    this.prefix = [0];
    for (const num of nums) {
      this.prefix.push(this.prefix[this.prefix.length - 1] + num);
    }
  }

  sumRange(left, right) {
    return this.prefix[right + 1] - this.prefix[left];
  }
}
