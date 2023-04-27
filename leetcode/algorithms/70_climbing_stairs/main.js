/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function (n) {
  if (n < 2) {
    return 1;
  }

  // Fibonacci numbers
  let dp = [];
  dp[0] = 1;
  dp[1] = 2;

  for (let i = 2; i < n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  return dp[n - 1];
};

// Best Solution
var bestSolution = function (n) {
  if (n < 2) {
    return 1;
  }

  let firstStep = 1;

  let secondStep = 1;

  let thirdStep = 0;

  for (let i = 2; i <= n; i++) {
    thirdStep = firstStep + secondStep;

    firstStep = secondStep;

    secondStep = thirdStep;
  }

  return thirdStep;
};
