/**
 * Brute-Force
 *
 * Complexities:
 *   N - Size of `nums`
 *   - Time Complexity: O(N²)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum1 = function (nums, target) {
  for (let i = 0; i < nums.length; i++) {
    for (let j = i + 1; j < nums.length; j++) {
      if (nums[i] + nums[j] == target) {
        return [i, j];
      }
    }
  }

  return [];
};

/**
 * Hash Map
 *
 * Complexities:
 *   N - Size of `nums`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum2 = function (nums, target) {
  const map = new Map();

  for (let i = 0; i < nums.length; i++) {
    const complement = target - nums[i];
    if (map[complement] != undefined) {
      return [i, map[complement]];
    }
    map[nums[i]] = i;
  }

  return [];
};


// Solution
/**
 * Hash Map
 *
 * Complexities:
 *   N - Size of `nums`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var solution = function (nums, target) {
  const map = new Map();

  for (let i = 0; i < nums.length; i++) {
    const currentNum = nums[i];
    const neededNum = target - currentNum;

    if (map.has(neededNum)) {
      return [map.get(neededNum), i];
    }

    map.set(currentNum, i);
  }

  return [];
};
