/**
 * Built-in Function
 *
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {string} s
 * @return {number}
 */
var countSegments = function (s) {
  return s
    .split(" ")
    .map((v) => v.trim())
    .filter((v) => v).length;
};


// Solution
/**
 * Solution 1
 *
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {string} s
 * @return {number}
 */
var solution1 = function (s) {
  let count = 0;

  for (let i = 0; i < s.length; i++) {
    if (s[i] !== " " && (i === 0 || s[i - 1] === " ")) {
      count++;
    }
  }

  return count;
};

/**
 * Solution 2
 *
 * Status flag
 *
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {string} s
 * @return {number}
 */
var solution2 = function (s) {
  let count = 0;
  let inSegment = false;

  for (const c of s) {
    if (c === " ") {
      inSegment = false;
    } else if (!inSegment) {
      inSegment = true;
      count++;
    }
  }

  return count;
};

/**
 * Solution 3
 *
 * Built-in Function
 *
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {string} s
 * @return {number}
 */
var solution3 = function (s) {
  return s.split(" ").filter(Boolean).length;
};

/**
 * Solution 4
 *
 * Built-in Function + RegEx
 *
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {string} s
 * @return {number}
 */
var solution4 = function (s) {
  return (s.match(/[^ ]+/g) ?? []).length;
};
