/**
 * Bit Manipulation
 *
 * Complexities:
 *   N - Size of `nums`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function (nums) {
  let result = 0;

  for (const num of nums) {
    result ^= num;
  }

  return result;
};


// Solution
/**
 * Solution 1
 *
 * XOR
 *
 * Complexities:
 *   N - Size of `nums`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @return {number}
 */
var solution1 = function (nums) {
  let result = 0;

  for (let i = 0; i < nums.length; i++) {
    result ^= nums[i];
  }

  return result;
};

/**
 * Solution 2
 *
 * Array.prototype.reduce
 *
 * Complexities:
 *   N - Size of `nums`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @return {number}
 */
var solution2 = function (nums) {
  return nums.reduce((acc, current) => acc ^ current, 0);
};
