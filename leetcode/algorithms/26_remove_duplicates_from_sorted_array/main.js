/**
 * Two Pointers
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 *
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates1 = function (nums) {
  let left = 0;

  for (let right = 0; right < nums.length; right++) {
    if (nums[left] != nums[right]) {
      nums[++left] = nums[right];
    }
  }

  return left + 1;
};

/**
 * Set & Array
 * - Time Complexity: O(?)
 * - Space Complexity: O(?)
 *
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates2 = function (nums) {
  // return [...new Set(nums)].sort((p, n) => p - n).map((v, i) => (nums[i] = v)).length;
  return Array.from(new Set(nums))
    .sort((p, n) => p - n)
    .map((v, i) => (nums[i] = v)).length;
};


// Solution
var solution = function (nums) {
  let i = 0;

  for (let j = 0; j < nums.length; j++) {
    if (nums[j] != nums[i]) {
      nums[++i] = nums[j];
    }
  }

  return ++i;
};
