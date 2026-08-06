/**
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} n
 * @return {boolean}
 */
var canWinNim = function (n) {
  if (n % 4 === 0) {
    return false;
  }
  return true;
};


// Solution
/**
 * Solution 1
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
  return n % 4 !== 0;
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
  return (n & 3) !== 0;
};
