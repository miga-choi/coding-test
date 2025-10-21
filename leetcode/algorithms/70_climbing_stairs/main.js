/**
 * DP (Dynamic Programming)
 * - Time Complexity: O(N)
 * - Space Complexity: O(N)
 *
 * @param {number} n
 * @return {number}
 */
var climbStairs = function (n) {
  if (n < 3) {
    return n;
  }

  const dp = new Array(n + 1);
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;

  for (let i = 3; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  return dp[n];
};


// Solution
/**
 * Solution 1
 *
 * Recursion (Time Limit Exceeded)
 * - Time Complexity: O(2ᴺ)
 * - Space Complexity: O(1)
 *
 * @param {number} n
 * @return {number}
 */
var solution1 = function (n) {
  if (n <= 2) {
    return n;
  }
  return solution1(n - 1) + solution1(n - 2);
};

/**
 * Solution 2
 *
 * DP (Dynamic Programming): Top-down with Memoization
 * - Time Complexity: O(N)
 * - Space Complexity: O(N)
 *
 * @param {number} n
 * @param {Map} memo
 * @return {number}
 */
var solution2 = function (n, memo = {}) {
  if (n in memo) {
    return memo[n];
  }

  if (n <= 2) {
    return n;
  }

  memo[n] = solution2(n - 1, memo) + solution2(n - 2, memo);

  return memo[n];
};

/**
 * Solution 3
 *
 * DP (Dynamic Programming): Bottom-up with Tabulation
 * - Time Complexity: O(N)
 * - Space Complexity: O(N)
 *
 * @param {number} n
 * @return {number}
 */
var solution3 = function (n) {
  if (n <= 2) {
    return n;
  }

  const dp = new Array(n + 1);
  dp[1] = 1;
  dp[2] = 2;

  for (let i = 3; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  return dp[n];
};

/**
 * Solution 4
 *
 * DP (Dynamic Programming): Space Optimization
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 *
 * @param {number} n
 * @return {number}
 */
var solution4 = function (n) {
  if (n <= 2) {
    return n;
  }

  let two_steps_before = 1;
  let one_step_before = 2;

  for (let i = 3; i <= n; i++) {
    const current = one_step_before + two_steps_before;

    two_steps_before = one_step_before;
    one_step_before = current;
  }

  return one_step_before;
};
