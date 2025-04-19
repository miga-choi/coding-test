class SearchInsertPosition {
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
  // Solution 1:
  public int solution1(int[] nums, int target) {
    if (nums == null || nums.length == 0) {
      return 0;
    }

    int n = nums.length;
    int l = 0;
    int r = n - 1;
    while (l < r) {
      int m = l + (r - l) / 2;

      if (nums[m] == target) {
        return m;
      } else if (nums[m] > target) {
        r = m; // right could be the result
      } else {
        l = m + 1; // m + 1 could be the result
      }
    }

    // 1 element left at the end
    // post-processing
    return nums[l] < target ? l + 1 : l;
  }

  // Solution 2:
  public int solution2(int[] nums, int target) {
    int start = 0;
    int end = nums.length - 1;

    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }

    return start;
  }

  // Solution 3:
  public int solution3(int[] nums, int target) {
    int low = 0, high = nums.length - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return low;
  }
}
