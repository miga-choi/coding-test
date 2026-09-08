/**
 * Forward declaration of guess API.
 * @param {number} num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * var guess = function(num) {}
 */
var guess = function (num) {};

/**
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
var guessNumber = function (n) {
  let size = n / 2;

  while (guess(n) !== 0) {
    if (guess(n) === 1) {
      n += size;
    } else {
      n -= size;
    }
    size /= 2;
  }

  return n;
};


// Solution
/**
 * Solution 1
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
var solution1 = function (n) {
  let left = 1;
  let right = n;

  while (left <= right) {
    const mid = left + Math.floor((right - left) / 2);
    const res = guess(mid);

    if (res === 0) {
      return mid;
    }

    if (res === -1) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return -1;
};

/**
 * Solution 2
 *
 * Recursion
 *
 * Complexities:
 *   N - `n`
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(logᴺ)
 */
/**
 * @param {number} n
 * @return {number}
 */
var solution2 = function (n) {
  const search = (left, right) => {
    const mid = left + Math.floor((right - left) / 2);
    const res = guess(mid);

    if (res === 0) {
      return mid;
    }

    if (res === -1) {
      return search(left, mid - 1);
    }

    return search(mid + 1, right);
  };

  return search(1, n);
};
