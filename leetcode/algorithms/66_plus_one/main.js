/**
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 *
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function (digits) {
  for (let i = digits.length - 1; i >= 0; i--) {
    digits[i]++;

    if (digits[i] < 10) {
      return digits;
    }

    digits[i] -= 10;
  }

  return new Array(1).fill(1).concat(new Array(digits.length).fill(0));
};


// Solution
/**
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 *
 * @param {number[]} digits
 * @return {number[]}
 */
var solution = function (digits) {
  const n = digits.length;

  for (let i = n - 1; i >= 0; i--) {
    digits[i]++;

    if (digits[i] < 10) {
      return digits;
    }

    digits[i] = 0;
  }

  digits.unshift(1);

  return digits;
};
