/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumProduct = function (nums) {
  let max1 = -1000, max2 = -1000, max3 = -1000;
  let min1 = 1000, min2 = 1000;

  for (const num of nums) {
    console.log(num);
    if (num > max1) {
      max3 = max2;
      max2 = max1;
      max1 = num;
    } else if (num > max2) {
      max3 = max2;
      max2 = num;
    } else if (num > max3) {
      max3 = num;
    }

    if (num < min1) {
      min2 = min1;
      min1 = num;
    } else if (num < min2) {
      min2 = num;
    }
  }

  return Math.max(max1 * max2 * max3, min1 * min2 * max1);
};

// Solution
var maximumProduct = function (nums) {
  let max1 = -Infinity;
  let max2 = -Infinity;
  let max3 = -Infinity;
  let min2 = Infinity;
  let min1 = Infinity;

  for (let i = 0; i < nums.length; i++) {
    if (nums[i] > max1) {
      [max1, max2, max3] = [nums[i], max1, max2];
    } else if (nums[i] > max2) {
      [max2, max3] = [nums[i], max2];
    } else if (nums[i] > max3) {
      max3 = nums[i];
    }
    if (nums[i] < min1) {
      [min2, min1] = [min1, nums[i]];
    } else if (nums[i] < min2) {
      min2 = nums[i];
    }
  }

  return Math.max(max1 * max2 * max3, max1 * min1 * min2);
};
