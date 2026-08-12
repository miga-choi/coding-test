/**
 * DP (Dynamic Programming)
 *
 * Complexities:
 *   N - `amount`
 *   M - The types of coins
 *   - Time Complexity: O(M * N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var coinChange = function (coins, amount) {
  if (amount == 0) {
    return 0;
  }

  const dp = new Array(amount + 1);
  for (let i = 0; i <= amount; i++) {
    dp[i] = amount + 1;
  }

  dp[0] = 0;

  for (let i = 1; i <= amount; i++) {
    for (let j = 0; j < coins.length; j++) {
      let coin = coins[j];
      if (i >= coin) {
        dp[i] = Math.min(dp[i], dp[i - coin] + 1);
      }
    }
  }

  if (dp[amount] > amount) {
    return -1;
  } else {
    return dp[amount];
  }
};


// Solution
/**
 * DP (Dynamic Programming)
 *
 * Complexities:
 *   N - `amount`
 *   M - The types of coins
 *   - Time Complexity: O(M * N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var solution = function (coins, amount) {
  const INF = amount + 1;
  const dp = new Array(amount + 1).fill(INF);
  dp[0] = 0;

  for (let i = 1; i <= amount; i++) {
    for (const coin of coins) {
      if (coin <= i) {
        dp[i] = Math.min(dp[i], dp[i - coin] + 1);
      }
    }
  }

  return dp[amount] === INF ? -1 : dp[amount];
};
