/**
 * DP
 *
 * Complexities:
 *   M - `m`
 *   N - `n`
 *   - Time Complexity: O(M * N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function (m, n) {
  const dp = new Array(n).fill(1);

  for (let i = 1; i < m; i++) {
    for (let j = 1; j < n; j++) {
      dp[j] = dp[j] + dp[j - 1];
    }
  }

  return dp[n - 1];
};


// Solution
/**
 * Solution 1
 *
 * DP
 *
 * Complexities:
 *   M - `m`
 *   N - `n`
 *   - Time Complexity: O(M * N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var solution1 = function (m, n) {
  const dp = new Array(n).fill(1);

  for (let i = 1; i < m; i++) {
    for (let j = 1; j < n; j++) {
      dp[j] = dp[j] + dp[j - 1];
    }
  }

  return dp[n - 1];
};

/**
 * Solution 2
 *
 * Combinatorics
 *
 * Complexities:
 *   M - `m`
 *   N - `n`
 *   - Time Complexity: O(min(M, N))
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var solution2 = function (m, n) {
  const N = m + n - 2;
  const K = Math.min(m - 1, n - 1);

  let result = 1;

  for (let i = 1; i <= K; i++) {
    result = (result * (N - i + 1)) / i;
  }

  return result;
};
