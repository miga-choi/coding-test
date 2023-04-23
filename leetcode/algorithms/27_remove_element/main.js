/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function (nums, val) {
  const newNums = nums.filter((num) => num != val).sort((p, n) => n - p);
  for (let i = 0; i < newNums.length; i++) {
    nums[i] = newNums[i];
  }
  nums.length = newNums.length;
  return nums.length;
};

// Best Solution
var bestSolution = function (nums, val) {
  var zeroStartIdx = 0;
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] !== val) {
      nums[zeroStartIdx] = nums[i];
      zeroStartIdx++;
    }
  }
  return zeroStartIdx;
};
