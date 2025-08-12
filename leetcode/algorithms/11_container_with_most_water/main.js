/**
 * Two Pointers
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 *
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
