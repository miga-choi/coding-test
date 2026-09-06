/**
 * Complexities:
 *   N - `num`
 *   - Time Complexity: O(√N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} num
 * @return {boolean}
 */
var isPerfectSquare = function (num) {
  let i = 0;

  while (true) {
    if (i ** 2 === num) {
      return true;
    } else if (i ** 2 > num) {
      return false;
    } else {
      i++;
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
 *   N - `num`
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} num
 * @return {boolean}
 */
var solution1 = function (num) {
  if (num < 2) {
    return true;
  }

  let left = 2;
  let right = Math.floor(num / 2);

  while (left <= right) {
    const mid = left + Math.floor((right - left) / 2);
    const square = mid * mid;

    if (square === num) {
      return true;
    }

    if (square > num) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return false;
};

/**
 * Solution 2
 *
 * Sum of Odd Numbers
 *
 * Complexities:
 *   N - `num`
 *   - Time Complexity: O(√N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} num
 * @return {boolean}
 */
var solution2 = function (num) {
  let odd = 1;

  while (num > 0) {
    num -= odd;
    odd += 2;
  }

  return num === 0;
};

/**
 * Solution 3
 *
 * Newton-Raphson Method
 *
 * Complexities:
 *   N - `num`
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} num
 * @return {boolean}
 */
var solution3 = function (num) {
  if (num < 2) {
    return true;
  }

  let x = Math.floor(num / 2);
  while (x * x > num) {
    x = Math.floor((x + Math.floor(num / x)) / 2);
  }

  return x * x === num;
};
