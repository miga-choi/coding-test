import 'dart:math';

class ContainerWithMostWater {
  /**
   * Two Pointers
   *
   * Complexities:
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int maxArea(List<int> height) {
    int left = 0;
    int right = height.length - 1;
    int maxStored = 0;

    while (left < right) {
      int leftHeight = height[left];
      int rightHeight = height[right];
      int h = min(leftHeight, rightHeight);
      int store = (right - left) * h;

      maxStored = max(maxStored, store);

      if (leftHeight < rightHeight) {
        left++;
      } else {
        right--;
      }
    }

    return maxStored;
  }


  // Solution
  /**
   * Two Pointers
   *
   * Complexities:
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int solution(List<int> height) {
    int left = 0;
    int right = height.length - 1;
    int maxWater = 0;

    while (left < right) {
      int currentHeight = min(height[left], height[right]);
      int currentWidth = right - left;
      int currentArea = currentWidth * currentHeight;

      maxWater = max(maxWater, currentArea);

      if (height[left] < height[right]) {
        left++;
      } else {
        right--;
      }
    }

    return maxWater;
  }
}
