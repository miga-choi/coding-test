/**
 * Time Complexity should <= O(N)
 *
 * Complexities:
 *   - Time Complexity: O(N * logᴺ)
 *   - Space Complexity: O(N * logᴺ)
 */
/**
 * @param {number} n
 * @return {number[]}
 */
var countBits = function (n) {
  let result = [];

  for (let i = 0; i <= n; i++) {
    let sum = 0;
    const bits = i.toString(2);
    for (j = 0; j < bits.length; j++) {
      sum += parseInt(bits[j]);
    }
    result.push(sum);
  }

  return result;
};


// Solution
/**
 * Solution 1
 *
 * Time Complexity should <= O(N)
 *
 * Complexities:
 *   - Time Complexity: O(N * logᴺ)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number} n
 * @return {number[]}
 */
var solution1 = function (n) {
  const result = [];

  for (let i = 0; i <= n; i++) {
    let count = 0,
      x = i;

    while (x > 0) {
      count += x & 1;
      x >>= 1;
    }

    result.push(count);
  }

  return result;
};

/**
 * Solution 2
 *
 * DP (Dynamic programming)
 *
 * Complexities:
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number} n
 * @return {number[]}
 */
var solution2 = function (n) {
  const dp = new Array(n + 1).fill(0);

  for (let i = 1; i <= n; i++) {
    dp[i] = dp[i >> 1] + (i & 1);
  }

  return dp;
};

/**
 * Solution 3
 *
 * DP (Dynamic programming)
 *
 * Complexities:
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number} n
 * @return {number[]}
 */
var solution3 = function (n) {
  const dp = new Array(n + 1).fill(0);

  for (let i = 1; i <= n; i++) {
    dp[i] = dp[i & (i - 1)] + 1;
  }

  return dp;
};

/**
 * Solution 4
 *
 * DP (Dynamic programming)
 *
 * Complexities:
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number} n
 * @return {number[]}
 */
var solution4 = function (n) {
  const dp = new Array(n + 1).fill(0);
  let offset = 1;

  for (let i = 1; i <= n; i++) {
    if (offset * 2 === i) {
      offset *= 2;
    }

    dp[i] = dp[i - offset] + 1;
  }

  return dp;
};
