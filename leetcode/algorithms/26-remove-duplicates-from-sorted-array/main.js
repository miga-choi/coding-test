/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function (nums) {
  return [...new Set(nums)]
    .sort((p, n) => p - n)
    .map((v, i) => {
      nums[i] = v;
    }).length;
};

// Best Solution
var bestSolution = function (nums) {
  let i = 0;
  for (let j = 0; j < nums.length; j++) {
    if (nums[j] != nums[i]) {
      nums[++i] = nums[j];
    }
  }
  return ++i;
};
