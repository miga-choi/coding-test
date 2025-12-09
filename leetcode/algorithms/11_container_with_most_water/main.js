/**
 * Two Pointers
 *
 * Complexities:
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function (height) {
  let left = 0;
  let right = height.length - 1;
  let maxStored = 0;

  while (left < right) {
    const leftHeight = height[left];
    const rightHeight = height[right];
    const h = Math.min(leftHeight, rightHeight);
    const store = (right - left) * h;

    maxStored = Math.max(maxStored, store);

    if (leftHeight < rightHeight) {
      left++;
    } else {
      right--;
    }
  }

  return maxStored;
};


// Solution
/**
 * Two Pointers
 *
 * Complexities:
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} height
 * @return {number}
 */
var solution = function (height) {
  let maxArea = 0;
  let left = 0;
  let right = height.length - 1;

  while (left < right) {
    const currentHeight = Math.min(height[left], height[right]);

    const width = right - left;

    const currentArea = width * currentHeight;
    maxArea = Math.max(maxArea, currentArea);

    if (height[left] < height[right]) {
      left++;
    } else {
      right--;
    }
  }

  return maxArea;
};
