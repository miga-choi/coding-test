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
// Solution 1
function solution1(nums, k) {
  // Create an empty object to store the last index of each number in nums
  let map = {};

  // Iterate through each number in nums
  for (let i = 0; i < nums.length; i++) {
    // If the current number is already in map and its last index is within k distance from current index, return true
    if (map[nums[i]] !== undefined && i - map[nums[i]] <= k) {
      return true;
    }

    // Update the last index of the current number to its current index
    map[nums[i]] = i;
  }

  // Return false if no such pair exists
  return false;
}

// Solution 2
function solution2(nums, k) {
  const hasmap = new Map();
  for (let idx = 0; idx < nums.length; idx++) {
    // Check if the difference betweend duplicates is less than k
    if (idx - hasmap.get(nums[idx]) <= k) {
      return true;
    }
    hasmap.set(nums[idx], idx);
  }
  return false;
}
