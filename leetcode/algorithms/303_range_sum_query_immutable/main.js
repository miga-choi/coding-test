/**
 * @param {number[]} nums
 */
var NumArray = function (nums) {
  this.nums = [];
  for (const num of nums) {
    this.nums.push(num);
  }
};

/**
 * @param {number} left
 * @param {number} right
 * @return {number}
 */
NumArray.prototype.sumRange = function (left, right) {
  let sum = 0;
  for (let i = left; i <= right; i++) {
    sum += this.nums[i];
  }
  return sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * var obj = new NumArray(nums)
 * var param_1 = obj.sumRange(left,right)
 */


// Best Solution
var bestSolution = function (nums) {
  this.sums = [];
  var sum = 0;
  for (var i = 0; i < nums.length; i++) {
    sum += nums[i];
    this.sums.push(sum);
  }
};

bestSolution.prototype.sumRange = function (i, j) {
  return this.sums[j] - (i > 0 ? this.sums[i - 1] : 0);
};
