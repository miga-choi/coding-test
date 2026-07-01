/**
 * Two Pointers
 *
 * Complexities:
 *   N - Size of `nums`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @return {string[]}
 */
var summaryRanges = function (nums) {
  const result = [];

  if (nums.length > 0) {
    let num = nums[0];
    let numArray = [num];
    for (let i = 1; i < nums.length; i++) {
      if (nums[i] - num === 1) {
        numArray.push(nums[i]);
      } else {
        if (numArray.length > 1) {
          result.push(`${numArray[0]}->${numArray[numArray.length - 1]}`);
        } else {
          result.push(`${numArray[0]}`);
        }
        numArray = [nums[i]];
      }

      num = nums[i];
    }

    if (numArray.length > 0) {
      if (numArray.length > 1) {
        result.push(`${numArray[0]}->${numArray[numArray.length - 1]}`);
      } else {
        result.push(`${numArray[0]}`);
      }
    }
  }

  return result;
};

// Solution
/**
 * Two Pointers
 *
 * Complexities:
 *   N - Size of `nums`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @return {string[]}
 */
var solution = function (nums) {
  const result = [];

  for (let i = 0; i < nums.length; i++) {
    const start = nums[i];

    while (i + 1 < nums.length && nums[i] + 1 === nums[i + 1]) {
      i++;
    }

    if (start !== nums[i]) {
      result.push(start + "->" + nums[i]);
    } else {
      result.push(start.toString());
    }
  }

  return result;
};
