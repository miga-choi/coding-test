/**
 * @param {number[]} nums
 * @return {number}
 */
var findLengthOfLCIS = function (nums) {
  let res = 1, count = 1;
  for (let i = 1; i < nums.length; i++) {
    if (nums.at(i) > nums.at(i - 1)) {
      count++;
      if (count > res) {
        res = count;
      }
    } else {
      count = 1;
    }
  }
  return res;
};

// Solution 1
var solution1 = function (nums) {
  let len = 1, maxLen = 0;
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] < nums[i + 1]) {
      len++;
    } else {
      len = 1;
    }
    maxLen = Math.max(len, maxLen);
  }
  return maxLen;
};

// Solution 2
var solution2 = function (nums) {
  if (nums.length < 2) {
    return nums.length;
  }

  let left = 0, right = 1, maxLen = 0;

  while (right < nums.length) {
    if (nums[right - 1] >= nums[right]) {
      left = right;
    }
    right++;
    maxLen = Math.max(right - left, maxLen);
  }

  return maxLen;
};
