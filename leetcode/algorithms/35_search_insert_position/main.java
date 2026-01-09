class SearchInsertPosition {
  /**
   * Binary Search
   *
   * Complexities:
   *   N - Size of `nums`
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(1)
   */
  public int searchInsert(int[] nums, int target) {
    int lo = 0;
    int hi = nums.length;
    while (lo < hi) {
      int mid = (lo + hi) / 2;
      if (target > nums[mid]) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }
    return lo;
  }


  // Solution
  /**
   * Binary Search
   *
   * Complexities:
   *   N - Size of `nums`
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(1)
   */
  public int solution(int[] nums, int target) {
    int left = 0;
    int right = nums.length - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return left;
  }
}
