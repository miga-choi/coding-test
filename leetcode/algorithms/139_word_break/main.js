/**
 * Dynamic Programming
 *
 * Complexities:
 *   N - Size of `s`
 *   - Time Complexity: O(N³)
 *   - Space Complexity: O(N)
 */
/**
 * @param {string} s
 * @param {string[]} wordDict
 * @return {boolean}
 */
var wordBreak = function (s, wordDict) {
  const dict = new Set(wordDict);
  const sLen = s.length;

  const dp = new Array(sLen + 1).fill(false);
  dp[0] = true;

  for (let i = 1; i <= sLen; i++) {
    for (let j = 0; j < i; j++) {
      if (dp[j] && dict.has(s.substring(j, i))) {
        dp[i] = true;
        break;
      }
    }
  }

  return dp[sLen];
};


// Solution
/**
 * Dynamic Programming
 *
 * Complexities:
 *   N - Size of `s`
 *   - Time Complexity: O(N³)
 *   - Space Complexity: O(N)
 */
/**
 * @param {string} s
 * @param {string[]} wordDict
 * @return {boolean}
 */
var solution = function (s, wordDict) {
  const wordSet = new Set(wordDict);
  const n = s.length;

  const dp = new Array(n + 1).fill(false);

  dp[0] = true;

  for (let i = 1; i <= n; i++) {
    for (let j = 0; j < i; j++) {
      if (dp[j] && wordSet.has(s.slice(j, i))) {
        dp[i] = true;
        break;
      }
    }
  }

  return dp[n];
};
