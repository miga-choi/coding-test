/**
 * Auxiliary Array
 *
 * Complexities:
 *   N - The Size of `nums`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDisappearedNumbers = function (nums) {
  const result = [];

  for (let i = 1; i <= nums.length; i++) {
    if (!nums.includes(i)) {
      result.push(i);
    }
  }

  return result;
};


// Solution
/**
 * Solution 1
 *
 * Set
 *
 * Complexities:
 *   N - The Size of `nums`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var solution1 = function (nums) {
  const seen = new Set(nums);
  const result = [];

  for (let i = 1; i <= nums.length; i++) {
    if (!seen.has(i)) result.push(i);
  }

  return result;
};

/**
 * Solution 2
 *
 * Negative Marking
 *
 * Complexities:
 *   N - The Size of `nums`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var solution2 = function (nums) {
  for (let i = 0; i < nums.length; i++) {
    const idx = Math.abs(nums[i]) - 1;
    if (nums[idx] > 0) {
      nums[idx] = -nums[idx];
    }
  }

  const result = [];
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] > 0) {
      result.push(i + 1);
    }
  }

  return result;
};

/**
 * Solution 3
 *
 * Add-n Marking
 *
 * Complexities:
 *   N - The Size of `nums`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var solution3 = function (nums) {
  const n = nums.length;

  for (let i = 0; i < n; i++) {
    const idx = (nums[i] - 1) % n;
    nums[idx] += n;
  }

  const result = [];
  for (let i = 0; i < n; i++) {
    if (nums[i] <= n) result.push(i + 1);
  }

  return result;
};

/**
 * Solution 4
 *
 * Cyclic Sort
 *
 * Complexities:
 *   N - The Size of `nums`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var solution4 = function (nums) {
  let i = 0;
  while (i < nums.length) {
    const target = nums[i] - 1;
    if (nums[i] !== nums[target]) {
      [nums[i], nums[target]] = [nums[target], nums[i]];
    } else {
      i++;
    }
  }

  const result = [];
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] !== i + 1) {
      result.push(i + 1);
    }
  }

  return result;
};
