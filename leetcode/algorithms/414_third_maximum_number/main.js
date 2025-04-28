/**
 * @param {number[]} nums
 * @return {number}
 */
var thirdMax = function (nums) {
  nums = nums.filter((v, i) => i === nums.indexOf(v));

  if (nums.length >= 3) {
    for (let i = 0; i < 2; i++) {
      nums = nums.filter((v) => v < Math.max(...nums));
    }
  }

  return Math.max(...nums);
};


// Solution
var solution = function (nums) {
  let first = -Infinity;
  let second = -Infinity;
  let third = -Infinity;

  for (let i = 0; i < nums.length; i++) {
    if (nums[i] === first || nums[i] === second || nums[i] === third) continue;
    if (nums[i] > first) {
      [first, second, third] = [nums[i], first, second];
    } else if (nums[i] > second) {
      [second, third] = [nums[i], second];
    } else if (nums[i] > third) {
      third = nums[i];
    }
  }

  return third === -Infinity ? first : third;
};
