/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function (nums) {
  const numsMap = {};
  const length = nums.length / 2;
  while (nums) {
    const num = nums.pop();
    numsMap[num] = numsMap[num] ? numsMap[num] + 1 : 1;
    if (numsMap[num] >= length) {
      return num;
    }
  }
};


// Solution
var solution = function (nums) {
  // Initialize sol and cnt to store the solution and its frequency for respective iterations...
  let sol = 0, cnt = 0;

  // For every element i in the array...
  for (let i = 0; i < nums.length; i++) {
    if (cnt == 0) {
      // If cnt is equal to zero, update sol as sol = i
      sol = nums[i];
      cnt = 1;
    } else if (sol == nums[i]) {
      // If i is equal to candidate, increment cnt...
      cnt++;
    } else {
      // Otherwise, decrement cnt...
      cnt--;
    }
  }

  // Return & print the solution...
  return sol;
};
