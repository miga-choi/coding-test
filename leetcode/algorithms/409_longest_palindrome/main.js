/**
 * Counting Array
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
var longestPalindrome = function (s) {
  let result = 0;
  const sMap = new Map();

  for (const c of s) {
    if (sMap.get(c)) {
      result += 2;
      sMap.delete(c);
    } else {
      sMap.set(c, 1);
    }
  }

  if (sMap.size > 0) {
    result++;
  }

  return result;
};


// Solution
/**
 * Solution 1
 *
 * Counting Array
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
  const count = new Array(128).fill(0);

  for (let i = 0; i < s.length; i++) {
    count[s.charCodeAt(i)]++;
  }

  let length = 0;
  let hasOdd = false;

  for (const c of count) {
    length += c - (c % 2);
    if (c % 2 === 1) {
      hasOdd = true;
    }
  }

  return length + (hasOdd ? 1 : 0);
};

/**
 * Solution 2
 *
 * Count The Odd Numbers
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
  const odd = new Set();

  for (const c of s) {
    if (odd.has(c)) {
      odd.delete(c);
    } else {
      odd.add(c);
    }
  }

  return s.length - odd.size + (odd.size > 0 ? 1 : 0);
};

/**
 * Solution 3
 *
 * Count The Odd Numbers
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
var solution3 = function (s) {
  const odd = new Set();
  let length = 0;

  for (const c of s) {
    if (odd.has(c)) {
      odd.delete(c);
      length += 2;
    } else {
      odd.add(c);
    }
  }

  return length + (odd.size > 0 ? 1 : 0);
};
