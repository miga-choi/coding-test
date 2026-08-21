/**
 * Built-in function
 *
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfFour = function (n) {
  if ((Math.log10(n) / Math.log10(4)) % 1 === 0) {
    return true;
  }

  return false;
};


// Solution
/**
 * Solution 1
 *
 * Repeated Division
 *
 * Complexities:
 *   N - `n`
 *   - Time Complexity: O(log₄ᴺ)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} n
 * @return {boolean}
 */
var solution1 = function (n) {
  if (n < 1) {
    return false;
  }

  while (n % 4 === 0) {
    n /= 4;
  }

  return n === 1;
};

/**
 * Solution 2
 *
 * Bit Trick
 *
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} n
 * @return {boolean}
 */
var solution2 = function (n) {
  return n > 0 && (n & (n - 1)) === 0 && (n & 0x55555555) !== 0;
};

/**
 * Solution 3
 *
 * Remaining 3
 *
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} n
 * @return {boolean}
 */
var solution3 = function (n) {
  return n > 0 && (n & (n - 1)) === 0 && (n - 1) % 3 === 0;
};
