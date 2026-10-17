/**
 * Complexities:
 *   N - `n`
 *   - Time Complexity: O(√N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} n
 * @return {number}
 */
var arrangeCoins = function (n) {
  for (i = 1; i > 0; i++) {
    n -= i;

    if (n === 0) {
      return i;
    } else if (n < 0) {
      return i - 1;
    }
  }
};


// Solution
/**
 * Solution 1
 *
 * Complexities:
 *   N - `n`
 *   - Time Complexity: O(√N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} n
 * @return {number}
 */
var solution1 = function (n) {
  let row = 0;

  while (n >= row + 1) {
    row++;
    n -= row;
  }

  return row;
};

/**
 * Solution 2
 *
 * Binary Search
 *
 * Complexities:
 *   N - `n`
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} n
 * @return {number}
 */
var solution2 = function (n) {
  let left = 1;
  let right = Math.min(n, 65536);

  while (left <= right) {
    const mid = left + Math.floor((right - left) / 2);
    const coins = (mid * (mid + 1)) / 2;

    if (coins === n) {
      return mid;
    }

    if (coins < n) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return right;
};

/**
 * Solution 3
 *
 * Quadratic Formula
 *
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} n
 * @return {number}
 */
var solution3 = function (n) {
  return Math.floor((Math.sqrt(8 * n + 1) - 1) / 2);
};
