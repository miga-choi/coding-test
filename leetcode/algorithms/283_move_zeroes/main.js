/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function (nums) {
  for (let i = 0; i < nums.length - 1; i++) {
    for (let j = 1; j < nums.length - i; j++) {
      if (nums[j - 1] === 0) {
        const temp = nums[j - 1];
        nums[j - 1] = nums[j];
        nums[j] = temp;
      }
    }
  }
  return nums;
};


// Best Solution
var bestSolution = function (nums) {
  //two pointers
  var pos = 0;
  for (var i = 0; i < nums.length; i++) {
    if (nums[i] !== 0) {
      nums[pos++] = nums[i];
    }
  }
  for (i = pos; i < nums.length; i++) {
    nums[i] = 0;
  }
};
