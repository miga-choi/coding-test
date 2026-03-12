/**
 * Backtracking
 *
 * Complexities:
 *   N - Size of `nums`
 *   - Time Complexity: O(N * N!)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function (nums) {
  const result = [];
  const visited = new Array(nums.length).fill(false);

  function backtrack(path) {
    if (path.length === nums.length) {
      result.push([...path]);
      return;
    }

    for (let i = 0; i < nums.length; i++) {
      if (visited[i]) {
        continue;
      }

      visited[i] = true;
      path.push(nums[i]);

      backtrack(path);

      path.pop();
      visited[i] = false;
    }
  }

  backtrack([]);

  return result;
};


// Solution
/**
 * Backtracking
 *
 * Complexities:
 *   N - Size of `nums`
 *   - Time Complexity: O(N * N!)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var solution = function (nums) {
  const result = [];
  const visited = new Array(nums.length).fill(false);

  function backtrack(currentPath) {
    if (currentPath.length === nums.length) {
      result.push([...currentPath]);
      return;
    }

    for (let i = 0; i < nums.length; i++) {
      if (visited[i]) {
        continue;
      }

      visited[i] = true;
      currentPath.push(nums[i]);

      backtrack(currentPath);

      currentPath.pop();
      visited[i] = false;
    }
  }

  backtrack([]);

  return result;
};
