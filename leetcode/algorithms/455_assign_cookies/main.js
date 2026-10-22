/**
 * Sorting + Greedy
 *
 * Complexities:
 *   N - The Size of `g`
 *   M - The Size of `s`
 *   - Time Complexity: O(N * logᴺ + M * logᴹ)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} g
 * @param {number[]} s
 * @return {number}
 */
var findContentChildren = function (g, s) {
  g.sort((p, n) => p - n);
  s.sort((p, n) => p - n);

  let gi = 0;
  for (let si = 0; si < s.length; si++) {
    if (s[si] >= g[gi]) {
      gi++;
    }
  }

  return gi;
};


// Solution
/**
 * Solution 1
 *
 * Sorting + Greedy
 *
 * Complexities:
 *   N - The Size of `g`
 *   M - The Size of `s`
 *   - Time Complexity: O(N * logᴺ + M * logᴹ)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} g
 * @param {number[]} s
 * @return {number}
 */
var solution1 = function (g, s) {
  g.sort((a, b) => a - b);
  s.sort((a, b) => a - b);

  let child = 0;
  let cookie = 0;

  while (child < g.length && cookie < s.length) {
    if (s[cookie] >= g[child]) {
      child++;
    }
    cookie++;
  }

  return child;
};

/**
 * Solution 2
 *
 * Sorting + Greedy
 *
 * Complexities:
 *   N - The Size of `g`
 *   M - The Size of `s`
 *   - Time Complexity: O(N * logᴺ + M * logᴹ)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} g
 * @param {number[]} s
 * @return {number}
 */
var solution2 = function (g, s) {
  g.sort((a, b) => a - b);
  s.sort((a, b) => a - b);

  let child = g.length - 1;
  let cookie = s.length - 1;
  let count = 0;

  while (child >= 0 && cookie >= 0) {
    if (s[cookie] >= g[child]) {
      count++;
      cookie--;
    }
    child--;
  }

  return count;
};
