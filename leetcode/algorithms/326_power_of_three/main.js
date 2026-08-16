/**
 * Complexities:
 *   N - `n`
 *   - Time Complexity: O(log₃ᴺ)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfThree = function (n) {
  if (n < 1) {
    return false;
  }

  while (n % 3 === 0) {
    n /= 3;
  }

  return n === 1;
};


// Solution
/**
 * Solution 1
 *
 * Complexities:
 *   N - `n`
 *   - Time Complexity: O(log₃ᴺ)
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

  while (n % 3 === 0) {
    n /= 3;
  }

  return n === 1;
};

/**
 * Solution 2
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
  return n > 0 && 1162261467 % n === 0;
};
