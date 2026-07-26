/**
 * Complexities:
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function (nums) {
  nums.sort((p, n) => p - n);

  for (let i = 0; i < nums.length; i++) {
    if (nums[i] !== i) {
      return i;
    }
  }

  return nums.length;
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
 * @return {number}
 */
var solution1 = function (nums) {
  const n = nums.length;

  const expectedSum = (n * (n + 1)) / 2;

  const actualSum = nums.reduce((acc, curr) => acc + curr, 0);

  return expectedSum - actualSum;
};

/**
 * Solution 2
 *
 * XOR
 *
 * Complexities:
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @return {number}
 */
var solution2 = function (nums) {
  const n = nums.length;
  let xor = n;

  for (let i = 0; i < n; i++) {
    xor ^= i ^ nums[i];
  }

  return xor;
};
