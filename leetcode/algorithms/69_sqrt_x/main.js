/**
 * Complexities:
 *   N - Value of `x`
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function (x) {
  for (let i = 0; i <= x; i++) {
    if (i * i <= x && (i + 1) * (i + 1) > x) {
      return i;
    }
  }
};


// Solution
/**
 * Solution 1
 *
 * Binary Search
 *
 * Complexities:
 *   N - Value of `x`
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} x
 * @return {number}
 */
var solution1 = function (x) {
  if (x < 2) {
    return x;
  }

  let left = 1;
  let right = x;

  while (left <= right) {
    const mid = Math.floor((left + right) / 2);
    const square = mid * mid;

    if (square === x) {
      return mid;
    } else if (square < x) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return right;
};

/**
 * Solution 2
 *
 * Newton-Raphson Method
 *
 * Complexities:
 *   N - Value of `x`
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} x
 * @return {number}
 */
var solution2 = function (x) {
  if (x === 0) return 0;

  let r = x;
  while (r * r > x) {
    r = Math.floor((r + x / r) / 2);
  }

  return r;
};
