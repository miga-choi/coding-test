/**
 * DP (Dynamic Programming)
 * - Time Complexity: O(M * N)
 * - Space Complexity: O(N)
 *
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
 * Solution 1
 *
 * DP (Dynamic Programming) - Bottom-Up DP / Tabulation
 * - Time Complexity: O(M * N)
 * - Space Complexity: O(N)
 *
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var solution1 = function (coins, amount) {
  const dp = new Array(amount + 1).fill(amount + 1);

  dp[0] = 0;

  for (let i = 1; i <= amount; i++) {
    for (const coin of coins) {
      if (i - coin >= 0) {
        dp[i] = Math.min(dp[i], dp[i - coin] + 1);
      }
    }
  }

  return dp[amount] > amount ? -1 : dp[amount];
};

/**
 * Solution 2
 *
 * DP (Dynamic Programming) - Top-Down DP / Memoization
 * - Time Complexity: O(M * N)
 * - Space Complexity: O(N)
 *
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var solution2 = function (coins, amount) {
  const memo = new Array(amount + 1).fill(null);

  const solve = (target) => {
    if (target === 0) {
      return 0;
    }

    if (target < 0) {
      return Infinity;
    }

    if (memo[target] !== null) {
      return memo[target];
    }

    let minCoins = Infinity;

    for (const coin of coins) {
      const result = solve(target - coin);
      if (result !== Infinity) {
        minCoins = Math.min(minCoins, result + 1);
      }
    }

    memo[target] = minCoins;

    return minCoins;
  };

  const result = solve(amount);

  return result === Infinity ? -1 : result;
};
