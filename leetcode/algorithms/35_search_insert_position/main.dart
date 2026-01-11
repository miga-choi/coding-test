class SearchInsertPosition {
  /**
   * Binary Search
   *
   * Complexities:
   *   N - Size of `nums`
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(1)
   */
  int searchInsert(List<int> nums, int target) {
    for (var i = 0; i < nums.length; i++) {
      if (nums[i] >= target) {
        return i;
      }
    }

    return nums.length;
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
  int solution(List<int> nums, int target) {
    int low = 0;
    int high = nums.length - 1;

    while (low <= high) {
      int mid = low + (high - low) ~/ 2;

      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    return low;
  }
}
