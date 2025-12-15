/**
 * Complexities:
 *   S = N * L
 *   N - `strsSize`
 *   L - Length of Shortest `str` in `strs
 *   - Time Complexity: O(S)
 *   - Space Complexity: O(1)
 */
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
  const minStrLength = Math.min(...strs.map((v) => v.length));
  let result = "";

  for (let i = 0; i < minStrLength; i++) {
    const char = strs[0][i];
    if (strs.every((str) => str[i] === char)) {
      result += char;
    } else {
      break;
    }
  }

  return result;
};


// Solution
/**
 * Solution 1
 *
 * Horizontal Scanning
 *
 * Complexities:
 *   S - Quantity of characters in `strs`
 *   - Time Complexity: O(S)
 *   - Space Complexity: O(1)
 */
/**
 * @param {string[]} strs
 * @return {string}
 */
var solution1 = function (strs) {
  let prefix = strs[0];

  for (let i = 1; i < strs.length; i++) {
    while (strs[i].indexOf(prefix) !== 0) {
      prefix = prefix.substring(0, prefix.length - 1);

      if (prefix === "") {
        return "";
      }
    }
  }

  return prefix;
};

/**
 * Solution 2
 *
 * Sorting
 *
 * Complexities:
 *   N - Length of `strs`
 *   L - Length of Longest `str` in `strs`
 *   - Time Complexity: O(N * L * logᴺ)
 *   - Space Complexity: O(1)
 */
/**
 * @param {string[]} strs
 * @return {string}
 */
var solution2 = function (strs) {
  strs.sort();

  const s1 = strs[0];
  const s2 = strs[strs.length - 1];

  let idx = 0;
  while (idx < s1.length && idx < s2.length) {
    if (s1[idx] === s2[idx]) {
      idx++;
    } else {
      break;
    }
  }

  return s1.substring(0, idx);
};
