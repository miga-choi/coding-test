/**
 * HashMap
 * 
 * Complexities:
 *   N - `numsSize`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
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
/**
 * Boyer-Moore Voting Algorithm
 *
 * Complexities:
 *   N - `numsSize`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @return {number}
 */
var solution = function (nums) {
  let candidate = null;
  let count = 0;

  for (let i = 0; i < nums.length; i++) {
    if (count === 0) {
      candidate = nums[i];
    }

    if (nums[i] === candidate) {
      count++;
    } else {
      count--;
    }
  }

  return candidate;
};
