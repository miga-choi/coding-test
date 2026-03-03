class ThreeSumClosest {
  /**
   * Sorting + Two Pointers
   *
   * Complexities:
   *   - Time Complexity: O(N²)
   *   - Space Complexity: O(1)
   */
  int threeSumClosest(List<int> nums, int target) {
    nums.sort();

    int n = nums.length;
    int sum = nums[0] + nums[1] + nums[2];

    for (int flag = 0; flag < n - 2; flag++) {
      int left = flag + 1;
      int right = n - 1;

      while (left < right) {
        final int currSum = nums[flag] + nums[left] + nums[right];

        if ((currSum - target).abs() < (sum - target).abs()) {
          sum = currSum;
        }

        if (currSum < target) {
          left++;
        } else if (currSum > target) {
          right--;
        } else {
          return currSum;
        }
      }
    }

    return sum;
  }


  // Solution
  /**
   * Sorting + Two Pointers
   *
   * Complexities:
   *   - Time Complexity: O(N²)
   *   - Space Complexity: O(1)
   */
  int solution(List<int> nums, int target) {
    nums.sort();

    int closestSum = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < nums.length - 2; i++) {
      int left = i + 1;
      int right = nums.length - 1;

      while (left < right) {
        int currentSum = nums[i] + nums[left] + nums[right];

        if (currentSum == target) {
          return currentSum;
        }

        if ((target - currentSum).abs() < (target - closestSum).abs()) {
          closestSum = currentSum;
        }

        if (currentSum < target) {
          left++;
        } else {
          right--;
        }
      }
    }

    return closestSum;
  }
}
