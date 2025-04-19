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


// Solution
// Solution 1:
var solution1 = function (n) {
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

// Solution 2: Math
var solution2 = function (n) {
  let ways = 1;

  for (let i = 1; i <= n / 2; i++) {
    let sum = 1;

    for (let j = i; j < 2 * i; j++) {
      sum *= (n - j) / (j - i + 1);
    }

    ways += sum;
  }

  return ways;
};

// Solution 3: Top-Down DP
var solve3 = function (n, dp) {
  if (n < 0) {
    return 0;
  }
  if (n == 0) {
    return 1;
  }

  if (dp[n] != -1) {
    return dp[n];
  }

  dp[n] = solve3(n - 1, dp) + solve3(n - 2, dp);

  return dp[n];
};

var solution3 = function (n) {
  const dp = new Array(n + 1).fill(-1);
  return solve3(n, dp);
};

// Solution 4: Bottom-Up DP
var solve4 = function (i, n, dp) {
  if (i === n) {
    return 1;
  }
  if (i > n) {
    return 0;
  }

  if (dp[i] !== -1) {
    return dp[i];
  }

  dp[i] = solve4(i + 1, n, dp) + solve4(i + 2, n, dp);

  return dp[i];
};

var solution4 = function (n) {
  const dp = new Array(n + 1).fill(-1);
  return solve4(0, n, dp);
};

// Solution 5: Bottom-Up DP
var solution5 = function (n) {
  let a = 0;
  let b = 1;
  let c = 0;

  for (let i = 0; i < n; i++) {
    c = a + b;
    a = b;
    b = c;
  }

  return b;
};
