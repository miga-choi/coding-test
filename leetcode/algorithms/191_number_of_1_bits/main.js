/**
 * Built-in Function
 *
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function (n) {
  const nString = n.toString(2);
  let result = 0;

  for (const c of nString) {
    if (c === "1") {
      result++;
    }
  }

  return result;
};


// Solution
/**
 * Solution 1
 *
 * Brian Kernighan's Algorithm
 *
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var solution1 = function (int) {
  let count = 0;

  while (n !== 0) {
    n = n & (n - 1);
    count++;
  }

  return count;
};

/**
 * Solution 2
 *
 * Bit Shift & Masking
 *
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var solution2 = function (int) {
  let count = 0;

  while (n !== 0) {
    count += n & 1;
    n = n >>> 1;
  }

  return count;
};

/**
 * Solution 3
 *
 * Built-in Function
 *
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var solution3 = function (int) {
  return n.toString(2).replaceAll("0", "").length;
};
