/**
 * Iterative
 *
 * Complexities:
 *   - Time Complexity: O(log₁₀ᴺ)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} num
 * @return {number}
 */
var addDigits = function (num) {
  let numString = num.toString();

  while (numString.length > 1) {
    let num = 0;

    for (const num_ of numString) {
      num += parseInt(num_);
    }

    numString = num.toString();
  }

  return numString;
};


// Solution
/**
 * Solution 1
 *
 * Digital Root
 *
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} num
 * @return {number}
 */
var solution1 = function (num) {
  if (num === 0) {
    return 0;
  }

  return ((num - 1) % 9) + 1;
};

/**
 * Solution 2
 *
 * Iterative
 *
 * Complexities:
 *   - Time Complexity: O(log₁₀ᴺ)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} num
 * @return {number}
 */
var solution2 = function (num) {
  while (num >= 10) {
    let sum = 0;

    while (num > 0) {
      sum += num % 10;
      num = Math.floor(num / 10);
    }

    num = sum;
  }

  return num;
};
