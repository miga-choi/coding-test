/**
 * DP (Dynamic Programming)
 *
 * Complexities:
 *   N - The size of `coins`
 *   M - `amount`
 *   - Time Complexity: O(N * M)
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
 * Solution 1
 *
 * DP (Dynamic Programming)
 *
 * Complexities:
 *   N - The size of `coins`
 *   M - `amount`
 *   - Time Complexity: O(N * M)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var solution1 = function (coins, amount) {
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

/**
 * Solution 2
 *
 * BFS
 *
 * Complexities:
 *   N - The size of `coins`
 *   M - `amount`
 *   - Time Complexity: O(N * M)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var solution2 = function (coins, amount) {
  if (amount === 0) {
    return 0;
  }

  const visited = new Uint8Array(amount + 1);
  let queue = [0];
  visited[0] = 1;
  let steps = 0;

  while (queue.length > 0) {
    steps++;

    const next = [];

    for (const cur of queue) {
      for (const coin of coins) {
        const sum = cur + coin;

        if (sum === amount) {
          return steps;
        }

        if (sum < amount && !visited[sum]) {
          visited[sum] = 1;
          next.push(sum);
        }
      }
    }

    queue = next;
  }

  return -1;
};
