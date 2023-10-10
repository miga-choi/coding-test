/**
 * @param {number[]} nums
 * @return {boolean}
 */
// 1, 3, 2
var find132pattern = function (nums) {
  const stack = [];
  let third = -1 * 10 ** 9;
  while (nums.length > 0) {
    const num = nums.pop();
    if (num < third) {
      return true;
    }
    while (stack.length > 0 && stack[stack.length - 1] < num) {
      third = stack.pop();
    }
    stack.push(num);
  }
  return false;
};


// Best Solution
var bestSolution = function (nums) {
  let stack = [];
  let third = Number.MIN_SAFE_INTEGER;

  for (let i = nums.length - 1; i >= 0; i--) {
    if (nums[i] < third) return true;
    while (stack.length && stack[stack.length - 1] < nums[i]) {
      third = stack.pop();
    }
    stack.push(nums[i]);
  }
  return false;
};
