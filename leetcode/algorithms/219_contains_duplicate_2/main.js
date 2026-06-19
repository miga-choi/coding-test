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
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function (nums, k) {
  let map = {};

  for (let i = 0; i < nums.length; i++) {
    if (map[nums[i]] !== undefined && Math.abs(i - map[nums[i]]) <= k) {
      return true;
    }
    map[nums[i]] = i;
  }

  return false;
};


// Solution
/**
 * Solution 1
 *
 * Hash Set
 *
 * Complexities:
 *   N - Size of `nums`
 *   K - `k`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(min(N, K))
 */
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
function solution1(nums, k) {
  const seen = new Set();

  for (let i = 0; i < nums.length; i++) {
    if (seen.has(nums[i])) {
      return true;
    }
    seen.add(nums[i]);
  }

  return false;
  // return new Set(nums).size !== nums.length;
}

// Solution 2
/**
 * Solution 2
 *
 * Sort
 *
 * Complexities:
 *   N - Size of `nums`
 *   K - `k`
 *   - Time Complexity: O(N * logᴺ)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
function solution2(nums, k) {
  nums.sort((a, b) => a - b);

  for (let i = 0; i < nums.length - 1; i++) {
    if (nums[i] === nums[i + 1]) {
      return true;
    }
  }

  return false;
}
