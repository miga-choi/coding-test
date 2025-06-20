/**
 * @param {number[]} nums
 * @return {number}
 */
var dominantIndex = function (nums) {
  let max = -1;
  let second = -1;
  let index = -1;

  for (let i = 0; i < nums.length; i++) {
    if (nums[i] > max) {
      second = max;
      max = nums[i];
      index = i;
    } else if (nums[i] > second) {
      second = nums[i];
    }
  }

  return max >= second * 2 ? index : -1;
};


// Solution
var dominantIndex = function (nums) {
  let max = -1, index = -1, second = -1;

  for (let i = 0; i < nums.length; i++) {
    if (nums[i] > max) {
      second = max;
      max = nums[i];
      index = i;
    } else if (nums[i] > second) {
      second = nums[i];
    }
  }

  return second * 2 <= max ? index : -1;
};
