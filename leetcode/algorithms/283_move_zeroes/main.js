/**
 * Complexities:
 *   N - The size of `nums`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function (nums) {
  for (let i = 0; i < nums.length - 1; i++) {
    for (let j = 1; j < nums.length - i; j++) {
      if (nums[j - 1] === 0) {
        const temp = nums[j - 1];
        nums[j - 1] = nums[j];
        nums[j] = temp;
      }
    }
  }
  return nums;
};


// Solution
/**
 * Solution 1
 *
 * Two Pointers Swap
 *
 * Complexities:
 *   N - The size of `nums`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var solution1 = function (nums) {
  let lastNonZeroIndex = 0;

  for (let i = 0; i < nums.length; i++) {
    if (nums[i] !== 0) {
      nums[lastNonZeroIndex] = nums[i];
      lastNonZeroIndex++;
    }
  }

  for (let i = lastNonZeroIndex; i < nums.length; i++) {
    nums[i] = 0;
  }
};

/**
 * Solution 2
 *
 * Swap
 *
 * Complexities:
 *   N - The size of `nums`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var solution2 = function (nums) {
  let lastNonZeroIndex = 0;

  for (let i = 0; i < nums.length; i++) {
    if (nums[i] !== 0) {
      [nums[lastNonZeroIndex], nums[i]] = [nums[i], nums[lastNonZeroIndex]];

      lastNonZeroIndex++;
    }
  }
};
