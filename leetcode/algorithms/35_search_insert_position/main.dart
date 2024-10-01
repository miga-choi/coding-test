class SearchInsertPosition {
  int searchInsert(List<int> nums, int target) {
    for (var i = 0; i < nums.length; i++) {
      if (nums[i] >= target) {
        return i;
      }
    }
    return nums.length;
  }

  // Best Solution
  int bestSolution(List<int> nums, int target) {
    int left = 0;
    int right = nums.length - 1;

    while (right >= left) {
      int mid = left + (right - left) ~/ 2;

      if (nums[mid] == target)
        return mid;
      else if (nums[mid] > target)
        right = mid - 1;
      else
        left = mid + 1;
    }

    return left;
  }
}
