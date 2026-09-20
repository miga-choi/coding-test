/**
 * Complexities:
 *   N - The Size of `s`
 *   M - The Size of `t`
 *   - Time Complexity: O(M)
 *   - Space Complexity: O(1)
 */
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isSubsequence = function (s, t) {
  while (s.length > 0) {
    const index = t.indexOf(s[0]);

    if (index === -1) {
      return false;
    }

    t = t.slice(index + 1, t.length);
    s = s.slice(1, s.length);
  }

  return true;
};


// Solution
/**
 * Solution 1
 *
 * Two Pointers
 *
 * Complexities:
 *   N - The Size of `s`
 *   M - The Size of `t`
 *   - Time Complexity: O(M)
 *   - Space Complexity: O(1)
 */
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var solution1 = function (s, t) {
  let i = 0;

  for (let j = 0; j < t.length && i < s.length; j++) {
    if (s[i] === t[j]) {
      i++;
    }
  }

  return i === s.length;
};

/**
 * Solution 2
 *
 * Two Pointers
 *
 * Complexities:
 *   N - The Size of `s`
 *   M - The Size of `t`
 *   - Time Complexity: O(M)
 *   - Space Complexity: O(1)
 */
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var solution2 = function (s, t) {
  let i = 0, j = 0;

  while (i < s.length && j < t.length) {
    if (s[i] === t[j]) {
      i++;
    }

    j++;
  }

  return i === s.length;
};
