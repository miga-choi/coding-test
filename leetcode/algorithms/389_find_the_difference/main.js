/**
 * String.prototype.replace()
 *
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N²)
 *   - Space Complexity: O(N)
 */
/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function (s, t) {
  for (const c of s) {
    t = t.replace(c, "");
  }

  return t;
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
 * @param {string} t
 * @return {character}
 */
var solution1 = function (s, t) {
  const count = new Array(26).fill(0);
  const base = "a".charCodeAt(0);

  for (const c of s) {
    count[c.charCodeAt(0) - base]++;
  }

  for (const c of t) {
    const idx = c.charCodeAt(0) - base;
    if (--count[idx] < 0) {
      return c;
    }
  }

  return "";
};

/**
 * Solution 2
 *
 * XOR
 *
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var solution2 = function (s, t) {
  let xor = 0;

  for (let i = 0; i < s.length; i++) {
    xor ^= s.charCodeAt(i);
  }
  for (let i = 0; i < t.length; i++) {
    xor ^= t.charCodeAt(i);
  }

  return String.fromCharCode(xor);
};

/**
 * Solution 3
 *
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var solution3 = function (s, t) {
  let sum = 0;

  for (let i = 0; i < t.length; i++) {
    sum += t.charCodeAt(i);
  }
  for (let i = 0; i < s.length; i++) {
    sum -= s.charCodeAt(i);
  }

  return String.fromCharCode(sum);
};

/**
 * Solution 4
 *
 * Array.prototype.sort()
 *
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N * logᴺ)
 *   - Space Complexity: O(1)
 */
/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var solution4 = function (s, t) {
  const a = [...s].sort();
  const b = [...t].sort();

  for (let i = 0; i < a.length; i++) {
    if (a[i] !== b[i]) {
      return b[i];
    }
  }

  return b[b.length - 1];
};
