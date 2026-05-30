/**
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} n - a positive integer
 * @return {number} - a positive integer
 */
var reverseBits = function (n) {
  n = n.toString(2).split("").reverse();

  while (n.length < 32) {
    n.push("0");
  }

  return parseInt(n.join(""), 2);
};


// Solution
/**
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} n - a positive integer
 * @return {number} - a positive integer
 */
var solution = function (n) {
  let result = 0;

  for (let i = 0; i < 32; i++) {
    const bit = n & 1;

    result = (result << 1) | bit;

    n = n >>> 1;
  }

  return result >>> 0;
};
