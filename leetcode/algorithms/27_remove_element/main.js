/**
 * Two Pointers
 *
 * Complexities:
 *   N - Length of `nums`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function (nums, val) {
  const newNums = nums.filter((num) => num != val).sort((p, n) => n - p);

  for (let i = 0; i < newNums.length; i++) {
    nums[i] = newNums[i];
  }

  nums.length = newNums.length;

  return nums.length;
};


// Solution
/**
 * Two Pointers
 *
 * Complexities:
 *   N - Length of `nums`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var solution = function (nums, val) {
  let k = 0;

  for (let i = 0; i < nums.length; i++) {
    if (nums[i] !== val) {
      nums[k] = nums[i];
      k++;
    }
  }

  return k;
};
