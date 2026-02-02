/**
 * DP (Dynamic Programming) with Array
 *
 * Complexities:
 *   N - Value of `n`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
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
 * DP (Dynamic Programming)
 *
 * Complexities:
 *   N - Value of `n`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} n
 * @return {number}
 */
var solution = function (n) {
  if (n <= 2) {
    return n;
  }

  let twoStepsBefore = 1;
  let oneStepBefore = 2;

  for (let i = 3; i <= n; i++) {
    const current = oneStepBefore + twoStepsBefore;

    twoStepsBefore = oneStepBefore;
    oneStepBefore = current;
  }

  return oneStepBefore;
};
