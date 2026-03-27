/**
 * DP
 *
 * Complexities:
 *   N - Size of `nums`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function (nums) {
  let prev2 = 0;
  let prev1 = 0;
  let current = Math.max(prev1, prev2);

  for (const num of nums) {
    current = Math.max(prev1, prev2 + num);

    prev2 = prev1;
    prev1 = current;
  }

  return current;
};


// Solution
/**
 * DP
 *
 * Complexities:
 *   N - Size of `nums`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @return {number}
 */
var solution = function (nums) {
  if (nums.length === 0) {
    return 0;
  }

  let prev2 = 0;
  let prev1 = 0;

  for (let i = 0; i < nums.length; i++) {
    const currentMax = Math.max(prev1, prev2 + nums[i]);

    prev2 = prev1;
    prev1 = currentMax;
  }

  return prev1;
};
