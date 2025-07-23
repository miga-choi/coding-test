/**
 *  * Brute-Force
 * - Time Complexity: O(N²)
 * - Space Complexity: O(1)
 *
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
 * Map
 * - Time Complexity: O(N)
 * - Space Complexity: O(N)
 *
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
// Solution 1: Map
var solution1 = function (nums, target) {
  let map = new Map();
  for (let i = 0; i < nums.length; i++) {
    if (map.has(target - nums[i])) {
      return [map.get(target - nums[i]), i];
    } else {
      map.set(nums[i], i);
    }
  }
  return [];
};

// Solution 2: Object
var solution2 = function (nums, target) {
  let hash = {};
  for (let i = 0; i < nums.length; i++) {
    const n = nums[i];
    if (hash[target - n] !== undefined) {
      return [hash[target - n], i];
    }
    hash[n] = i;
  }
  return [];
};
