/**
 * Sorting + Two Pointers
 *
 * Complexities:
 *   - Time Complexity: O(N²)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function (nums, target) {
  nums.sort((p, n) => p - n);

  let n = nums.length;
  let sum = nums[0] + nums[1] + nums[2];

  for (let flag = 0; flag < n - 2; flag++) {
    let left = flag + 1;
    let right = n - 1;

    while (left < right) {
      const currSum = nums[flag] + nums[left] + nums[right];

      if (Math.abs(currSum - target) < Math.abs(sum - target)) {
        sum = currSum;
      }

      if (currSum < target) {
        left++;
      } else if (currSum > target) {
        right--;
      } else {
        return currSum;
      }
    }
  }

  return sum;
};


// Solution
/**
 * Sorting + Two Pointers
 *
 * Complexities:
 *   - Time Complexity: O(N²)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var solution = function (nums, target) {
  nums.sort((a, b) => a - b);

  let closestSum = nums[0] + nums[1] + nums[2];

  for (let i = 0; i < nums.length - 2; i++) {
    let left = i + 1;
    let right = nums.length - 1;

    while (left < right) {
      const currentSum = nums[i] + nums[left] + nums[right];

      if (Math.abs(target - currentSum) < Math.abs(target - closestSum)) {
        closestSum = currentSum;
      }

      if (currentSum < target) {
        left++;
      } else if (currentSum > target) {
        right--;
      } else {
        return currentSum;
      }
    }
  }

  return closestSum;
};
