/**
 * DP
 *
 * Complexities:
 *   N - Size of `nums`
 *   - Time Complexity: O(N²)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function (nums) {
  const n = nums.length;
  const dp = new Array(n).fill(1);

  for (let i = 1; i < n; i++) {
    for (let j = 0; j < i; j++) {
      if (nums[i] > nums[j]) {
        if (dp[j] + 1 > dp[i]) {
          dp[i] = dp[j] + 1;
        }
      }
    }
  }

  return Math.max(...dp);
};


// Solution
/**
 * Solution 1
 *
 * DP
 *
 * Complexities:
 *   N - Size of `nums`
 *   - Time Complexity: O(N²)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number[]} nums
 * @return {number}
 */
var solution1 = function (nums) {
  const dp = new Array(nums.length).fill(1);
  let maxLength = 1;

  for (let i = 1; i < nums.length; i++) {
    for (let j = 0; j < i; j++) {
      if (nums[j] < nums[i]) {
        dp[i] = Math.max(dp[i], dp[j] + 1);
      }
    }

    maxLength = Math.max(maxLength, dp[i]);
  }

  return maxLength;
};

/**
 * Solution 2
 *
 * Binary Search
 *
 * Complexities:
 *   N - Size of `nums`
 *   - Time Complexity: O(N * logᴺ)
 *   - Space Complexity: O(N)
 */
var solution2 = function (nums) {
  const tails = [];

  for (const x of nums) {
    let left = 0;
    let right = tails.length;

    while (left < right) {
      const mid = Math.floor((left + right) / 2);
      if (tails[mid] < x) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    if (left === tails.length) {
      tails.push(x);
    } else {
      tails[left] = x;
    }
  }

  return tails.length;
};
