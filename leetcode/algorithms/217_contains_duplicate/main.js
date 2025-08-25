/**
 * Set
 * - Time Complexity: O(N)
 * - Space Complexity: O(N)
 *
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function (nums) {
  if (nums.length < 2) {
    return false;
  }

  const set = new Set();

  for (const num of nums) {
    if (set.has(num)) {
      return true;
    } else {
      set.add(num);
    }
  }

  return false;
};


// Solution
/**
 * Set
 * - Time Complexity: O(N)
 * - Space Complexity: O(N)
 *
 * @param {number[]} nums
 * @return {boolean}
 */
var solution = function (nums) {
  const s = new Set(nums);
  return s.size !== nums.length;
};
