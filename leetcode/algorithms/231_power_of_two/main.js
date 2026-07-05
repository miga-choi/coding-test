/**
 * Complexities:
 *   N - `n`
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfTwo = function (n) {
  let m = 0;

  while (2 ** m <= n) {
    if (2 ** m === n) {
      return true;
    }
    m++;
  }

  return false;
};


// Solution
/**
 * Solution 1
 *
 * Bit Manipulation
 *
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} n
 * @return {boolean}
 */
var solution1 = function (n) {
  return n > 0 && (n & (n - 1)) === 0;
};

/**
 * Solution 2
 *
 * Complexities:
 *   N - `n`
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} n
 * @return {boolean}
 */
var solution2 = function (n) {
  if (n <= 0) {
    return false;
  }

  while (n % 2 === 0) {
    n = n / 2;
  }

  return n === 1;
};
