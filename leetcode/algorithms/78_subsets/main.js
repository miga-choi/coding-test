/**
 * Backtracking
 *
 * Complexities:
 *   N - Size of `nums`
 *   - Time Complexity: O(N * 2ᴺ)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function (nums) {
  const result = [];
  const current = [];

  function backtracking(start) {
    result.push([...current]);

    for (let i = start; i < nums.length; ++i) {
      current.push(nums[i]);

      backtracking(i + 1);

      current.pop();
    }
  }

  backtracking(0);

  return result;
};


// Solution
/**
 * Solution 1
 *
 * Backtracking
 *
 * Complexities:
 *   N - Size of `nums`
 *   - Time Complexity: O(N * 2ᴺ)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var solution1 = function (nums) {
  const result = [];

  function backtrack(startIndex, currentSubset) {
    result.push([...currentSubset]);

    for (let i = startIndex; i < nums.length; i++) {
      currentSubset.push(nums[i]);

      backtrack(i + 1, currentSubset);

      currentSubset.pop();
    }
  }

  backtrack(0, []);

  return result;
};

/**
 * Solution 2
 *
 * Cascading
 *
 * Complexities:
 *   N - Size of `nums`
 *   - Time Complexity: O(N * 2ᴺ)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var solution2 = function (nums) {
  let result = [[]];

  for (const num of nums) {
    const currentLength = result.length;

    for (let i = 0; i < currentLength; i++) {
      result.push([...result[i], num]);
    }
  }

  return result;
};
