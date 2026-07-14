/**
 * Frequency Counting
 *
 * Complexities:
 *   N - The size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function (s, t) {
  const len = s.length;

  if (len != t.length) {
    return false;
  }

  const alphabetNumArray = new Array(26).fill(0);

  for (let i = 0; i < len; i++) {
    alphabetNumArray[s[i].charCodeAt(0) - 97]++;
    alphabetNumArray[t[i].charCodeAt(0) - 97]--;
  }

  for (let i = 0; i < 26; i++) {
    if (alphabetNumArray[i] != 0) {
      return false;
    }
  }

  return true;
};


// Solution
/**
 * Solution 1
 *
 * Frequency Counting
 *
 * Complexities:
 *   N - The size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var solution1 = function (s, t) {
  if (s.length !== t.length) {
    return false;
  }

  const charCount = new Array(26).fill(0);
  const charCodeA = 97;

  for (let i = 0; i < s.length; i++) {
    charCount[s.charCodeAt(i) - charCodeA]++;
    charCount[t.charCodeAt(i) - charCodeA]--;
  }

  return charCount.every((count) => count === 0);
};

/**
 * Solution 2
 *
 * Sorting
 *
 * Complexities:
 *   N - The size of `s`
 *   - Time Complexity: O(N * logᴺ)
 *   - Space Complexity: O(N)
 */
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var solution2 = function (s, t) {
  if (s.length !== t.length) {
    return false;
  }

  return s.split("").sort().join("") === t.split("").sort().join("");
};
