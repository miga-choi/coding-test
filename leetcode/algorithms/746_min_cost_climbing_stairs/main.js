/**
 * @param {number[]} cost
 * @return {number}
 */
var minCostClimbingStairs = function (cost) {
  const size = cost.length;

  const dp = Array(size);

  dp[0] = cost[0];
  dp[1] = cost[1];

  for (let i = 2; i < size; i++) {
    dp[i] = cost[i] + Math.min(dp[i - 1], dp[i - 2]);
  }

  return Math.min(dp[size - 1], dp[size - 2]);
};


// Solution
var solution = function (cost) {
  let first = cost[0];
  let second = cost[1];

  for (let i = 2; i < cost.length; i++) {
    let curr = cost[i] + Math.min(first, second);
    first = second;
    second = curr;
  }

  return Math.min(first, second);
};
