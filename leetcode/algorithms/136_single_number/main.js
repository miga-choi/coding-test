/**
 * Bit Manipulation
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 *
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
