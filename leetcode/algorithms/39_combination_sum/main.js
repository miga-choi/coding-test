/**
 * Backtracking
 *
 * Complexities:
 *   N - Size of `candidates`
 *   T - Value of `target`
 *   M - Minimum value of `candidates`
 *   - Time Complexity: O(Nᵀ/ᴹ)
 *   - Space Complexity: O(T/M)
 */
/**
 * @param {number[]} candidates
 * @param {number} target
 * @param {number} start
 * @param {number[]} current
 * @param {number[][]} result
 */
var backtracking = function (candidates, target, start, current, result) {
  if (target == 0) {
    result.push([...current]);
    return;
  }
  if (target < 0) {
    return;
  }

  for (let i = start; i < candidates.length; i++) {
    current.push(candidates[i]);

    backtracking(candidates, target - candidates[i], i, current, result);

    current.pop();
  }
};

/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function (candidates, target) {
  const result = new Array();
  const current = new Array();

  backtracking(candidates, target, 0, current, result);

  return result;
};


// Solution
/**
 * Backtracking
 *
 * Complexities:
 *   N - Size of `candidates`
 *   T - Value of `target`
 *   M - Minimum value of `candidates`
 *   - Time Complexity: O(Nᵀ/ᴹ)
 *   - Space Complexity: O(T/M)
 */
/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var solution = function (candidates, target) {
  const result = [];

  candidates.sort((a, b) => a - b);

  /**
   * @param {number} remain
   * @param {number[]} currentComb
   * @param {number} start
   */
  function backtrack(remain, currentComb, start) {
    if (remain === 0) {
      result.push([...currentComb]);
      return;
    }

    for (let i = start; i < candidates.length; i++) {
      const currentNum = candidates[i];

      if (currentNum > remain) {
        break;
      }

      currentComb.push(currentNum);

      backtrack(remain - currentNum, currentComb, i);

      currentComb.pop();
    }
  }

  backtrack(target, [], 0);

  return result;
};
