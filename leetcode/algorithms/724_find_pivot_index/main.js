/**
 * @param {number[]} nums
 * @return {number}
 */
var pivotIndex = function (nums) {
  let leftSum = 0;
  let rightSum = nums.reduce(
    (previousValue, currentValue) => previousValue + currentValue,
    0
  );

  for (let i = 0; i < nums.length; i++) {
    rightSum -= nums[i];

    if (leftSum == rightSum) {
      return i;
    }

    leftSum += nums[i];
  }

  return -1;
};


// Solution
var solution = function (nums) {
  // Initialize total sum of the given array
  let totalSum = 0;

  // Traverse the elements and add them to store the totalSum
  for (let i = 0; i < nums.length; i++) {
    totalSum += nums[i];
  }

  // Initialize 'leftsum' as sum of first i numbers,
  // not including nums[i]
  let leftSum = 0;

  // Again traverse all the elements through the for loop
  // and store the sum of i numbers from left to right
  for (let i = 0; i < nums.length; i++) {
    // sum to the left == leftsum
    // sum to the right === totalSum - leftsum - nums[i]
    // check if leftsum == totalSum - leftsum - nums[i]
    if (leftSum * 2 == totalSum - nums[i]) {
      // Return the pivot index...
      return i;
    }

    leftSum += nums[i];
  }

  // If there is no index that satisfies the conditions
  // in the problem statement
  return -1;
};
