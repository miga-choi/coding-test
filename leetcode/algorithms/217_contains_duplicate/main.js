/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function (nums) {
  const numsMap = {};
  for (let i = 0; i < nums.length; i++) {
    if (numsMap[nums[i]]) {
      return true;
    }
    numsMap[nums[i]] = true;
  }
  return false;
};


// Best Solution
var bestSolution = function (nums) {
  const s = new Set(nums);
  return s.size !== nums.length;
};
