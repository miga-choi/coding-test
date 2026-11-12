/**
 * Single Pass Counting
 *
 * Complexities:
 *   n - The Size of `nums`
 *   - Time Complexity: O(n)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function (nums) {
  let result = 0;
  let curr = 0;

  for (const num of nums) {
    if (num === 1) {
      curr += 1;
    } else {
      if (curr > result) {
        result = curr;
      }
      curr = 0;
    }
  }

  return Math.max(result, curr);
};


// Solution
/**
 * Solution 1
 *
 * Single Pass Counting
 *
 * Complexities:
 *   n - The Size of `nums`
 *   - Time Complexity: O(n)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @return {number}
 */
var solution1 = function (nums) {
  let max = 0;
  let count = 0;

  for (const num of nums) {
    if (num === 1) {
      count++;
      if (count > max) max = count;
    } else {
      count = 0;
    }
  }

  return max;
};

/**
 * Solution 2
 *
 * Single Pass Counting
 *
 * Complexities:
 *   n - The Size of `nums`
 *   - Time Complexity: O(n)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @return {number}
 */
var solution2 = function (nums) {
  let max = 0,
    count = 0;

  for (const num of nums) {
    count = (count + 1) * num;
    max = Math.max(max, count);
  }

  return max;
};

/**
 * Solution 3
 *
 * Sliding Window (Streak Start Index)
 *
 * Complexities:
 *   n - The Size of `nums`
 *   - Time Complexity: O(n)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @return {number}
 */
var solution3 = function (nums) {
  let max = 0;
  let start = 0;

  for (let i = 0; i < nums.length; i++) {
    if (nums[i] === 0) {
      start = i + 1;
    } else {
      max = Math.max(max, i - start + 1);
    }
  }

  return max;
};

/**
 * Solution 4
 *
 * Join + Split
 *
 * Complexities:
 *   n - The Size of `nums`
 *   - Time Complexity: O(n)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @return {number}
 */
var solution4 = function (nums) {
  return Math.max(...nums.join("").split("0").map((s) => s.length));
};

/**
 * Solution 5
 *
 * Join + Split
 *
 * Complexities:
 *   n - The Size of `nums`
 *   - Time Complexity: O(n)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @return {number}
 */
var solution5 = function (nums) {
  return nums.join('').split('0').reduce((m, s) => Math.max(m, s.length), 0);
};
