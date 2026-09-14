/**
 * Counting Array + Two-Pass
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
var firstUniqChar = function (s) {
  const alphabetNumArray = new Array(26).fill(0);

  for (const c of s) {
    alphabetNumArray[c.charCodeAt(0) - 97]++;
  }

  for (let i = 0; i < s.length; i++) {
    if (alphabetNumArray[s.charCodeAt(i) - 97] === 1) {
      return i;
    }
  }

  return -1;
};


// Solution
/**
 * Solution 1
 *
 * Counting Array + Two-Pass
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
  const count = new Array(26).fill(0);
  const base = "a".charCodeAt(0);

  for (const c of s) {
    count[c.charCodeAt(0) - base]++;
  }

  for (let i = 0; i < s.length; i++) {
    if (count[s.charCodeAt(i) - base] === 1) {
      return i;
    }
  }

  return -1;
};

/**
 * Solution 2
 *
 * Map + Two-Pass
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
  const count = new Map();

  for (const c of s) {
    count.set(c, (count.get(c) ?? 0) + 1);
  }

  for (let i = 0; i < s.length; i++) {
    if (count.get(s[i]) === 1) {
      return i;
    }
  }

  return -1;
};

/**
 * Solution 3
 *
 * Map + Two-Pass
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
  const seen = new Map();

  for (let i = 0; i < s.length; i++) {
    seen.set(s[i], seen.has(s[i]) ? -1 : i);
  }

  for (const idx of seen.values()) {
    if (idx !== -1) {
      return idx;
    }
  }

  return -1;
};

/**
 * Solution 4
 *
 * String.prototype.indexOf() + String.prototype.lastIndexOf()
 *
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N²)
 *   - Space Complexity: O(1)
 */
/**
 * @param {string} s
 * @return {number}
 */
var solution4 = function (s) {
  for (let i = 0; i < s.length; i++) {
    if (s.indexOf(s[i]) === s.lastIndexOf(s[i])) {
      return i;
    }
  }

  return -1;
};

/**
 * Solution 5
 *
 * Alphabet Traversal + String.prototype.indexOf
 *
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N²)
 *   - Space Complexity: O(1)
 */
/**
 * @param {string} s
 * @return {number}
 */
var solution5 = function (s) {
  let result = s.length;

  for (let i = 0; i < 26; i++) {
    const c = String.fromCharCode(97 + i);
    const first = s.indexOf(c);
    if (first !== -1 && first === s.lastIndexOf(c)) {
      result = Math.min(result, first);
    }
  }

  return result === s.length ? -1 : result;
};
