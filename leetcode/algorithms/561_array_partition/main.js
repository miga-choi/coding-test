/**
 * @param {number[]} nums
 * @return {number}
 */
var arrayPairSum = function (nums) {
  let result = 0;

  nums.sort((a, b) => a - b);

  for (let i = 0; i < nums.length; i++) {
    if (i % 2 === 0) {
      result += nums[i];
    }
  }

  return result;
};


// Solution
var solution = function (nums) {
  // sort and sum up the minimum of the pairs
  return nums
    .sort((a, b) => a - b)
    .reduce((sum, cur, i) => (i % 2 === 0 ? (sum += cur) : sum), 0);
};
