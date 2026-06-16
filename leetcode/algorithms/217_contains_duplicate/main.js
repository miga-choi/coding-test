/**
 * Hash Set
 *
 * Complexities:
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function (nums) {
  if (nums.length < 2) {
    return false;
  }

  const set = new Set();

  for (const num of nums) {
    if (set.has(num)) {
      return true;
    } else {
      set.add(num);
    }
  }

  return false;
};


// Solution
/**
 * Solution 1
 *
 * Hash Set
 *
 * Complexities:
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var solution1 = function (nums) {
  const seen = new Set();

  for (let i = 0; i < nums.length; i++) {
    if (seen.has(nums[i])) {
      return true;
    }
    seen.add(nums[i]);
  }

  return false;
  // return new Set(nums).size !== nums.length;
};

/**
 * Solution 2
 *
 * Sort
 *
 * Complexities:
 *   - Time Complexity: O(N * logᴺ)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var solution2 = function (nums) {
  nums.sort((a, b) => a - b);

  for (let i = 0; i < nums.length - 1; i++) {
    if (nums[i] === nums[i + 1]) {
      return true;
    }
  }

  return false;
};
