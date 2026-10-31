/**
 * Math
 *
 * Complexities:
 *   M - `x`
 *   N - `y`
 *   - Time Complexity: O(logᵐᵃˣ⁽ᴹ˒ᴺ⁾)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var hammingDistance = function (x, y) {
  let xBinary = x.toString(2);
  let yBinary = y.toString(2);

  const length = Math.max(xBinary.length, yBinary.length);

  xBinary = xBinary.padStart(length, "0");
  yBinary = yBinary.padStart(length, "0");

  let result = 0;
  for (let i = 0; i < length; i++) {
    if (xBinary[i] !== yBinary[i]) {
      result++;
    }
  }

  return result;
};


// Solution
/**
 * Solution 1
 *
 * Bit Manipulation (XOR + Right Shift)
 *
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var solution1 = function (x, y) {
  let xor = x ^ y;
  let count = 0;

  while (xor !== 0) {
    count += xor & 1;
    xor >>>= 1;
  }

  return count;
};

/**
 * Solution 2
 *
 * Bit Manipulation (Brian Kernighan's Algorithm)
 *
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var solution2 = function (x, y) {
  let xor = x ^ y;
  let count = 0;

  while (xor !== 0) {
    xor &= xor - 1;
    count++;
  }

  return count;
};

/**
 * Solution 3
 *
 * Built-in Methods (toString)
 *
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var solution3 = function (x, y) {
  return (x ^ y).toString(2).split("1").length - 1;
};

/**
 * Solution 4
 *
 * Bit Manipulation (SWAR / Parallel Popcount)
 *
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var solution4 = function (x, y) {
  let n = x ^ y;

  n = n - ((n >>> 1) & 0x55555555);
  n = (n & 0x33333333) + ((n >>> 2) & 0x33333333);
  n = (n + (n >>> 4)) & 0x0f0f0f0f;

  return Math.imul(n, 0x01010101) >>> 24;
};

/**
 * Solution 5
 *
 * Bit Manipulation (Bit Masking)
 *
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var solution5 = function (x, y) {
  let count = 0;

  for (let i = 0; i < 31; i++) {
    if (((x >>> i) & 1) !== ((y >>> i) & 1)) count++;
  }

  return count;
};
