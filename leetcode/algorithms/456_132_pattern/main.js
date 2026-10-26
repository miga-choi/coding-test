/**
 * Monotonic Stack
 *
 * Complexities:
 *   N - The Size of `nums`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var find132pattern = function (nums) {
  const stack = [];
  let third = -1 * 10 ** 9;

  while (nums.length > 0) {
    const num = nums.pop();

    if (num < third) {
      return true;
    }

    while (stack.length > 0 && stack[stack.length - 1] < num) {
      third = stack.pop();
    }

    stack.push(num);
  }

  return false;
};


// Solution
/**
 * Solution 1
 *
 * Brute Force
 *
 * Complexities:
 *   N - The Size of `nums`
 *   - Time Complexity: O(N³)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var solution1 = function (nums) {
  const n = nums.length;

  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      for (let k = j + 1; k < n; k++) {
        if (nums[i] < nums[k] && nums[k] < nums[j]) {
          return true;
        }
      }
    }
  }

  return false;
};

/**
 * Solution 2
 *
 * Prefix Minimum
 *
 * Complexities:
 *   N - The Size of `nums`
 *   - Time Complexity: O(N²)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var solution2 = function (nums) {
  let minLeft = nums[0];

  for (let j = 1; j < nums.length; j++) {
    for (let k = j + 1; k < nums.length; k++) {
      if (minLeft < nums[k] && nums[k] < nums[j]) {
        return true;
      }
    }

    minLeft = Math.min(minLeft, nums[j]);
  }

  return false;
};

/**
 * Solution 3
 *
 * Monotonic Stack
 *
 * Complexities:
 *   N - The Size of `nums`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var solution3 = function (nums) {
  const stack = [];
  let third = -Infinity;

  for (let i = nums.length - 1; i >= 0; i--) {
    if (nums[i] < third) {
      return true;
    }

    while (stack.length > 0 && stack[stack.length - 1] < nums[i]) {
      third = stack.pop();
    }

    stack.push(nums[i]);
  }

  return false;
};

/**
 * Solution 4
 *
 * Prefix Minimum + Monotonic Stack
 *
 * Complexities:
 *   N - The Size of `nums`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var solution4 = function (nums) {
  const stack = [];
  let min = nums[0];

  for (let j = 1; j < nums.length; j++) {
    const cur = nums[j];

    while (stack.length > 0 && stack[stack.length - 1][0] <= cur) {
      stack.pop();
    }

    if (stack.length > 0 && stack[stack.length - 1][1] < cur) {
      return true;
    }

    stack.push([cur, min]);
    min = Math.min(min, cur);
  }

  return false;
};
