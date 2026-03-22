import 'dart:math';

class LongestIncreasingSubsequence {
  /**
   * DP
   *
   * Complexities:
   *   N - Size of `nums`
   *   - Time Complexity: O(N²)
   *   - Space Complexity: O(N)
   */
  int lengthOfLIS(List<int> nums) {
    final int n = nums.length;
    List<int> dp = List.filled(n, 1);

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }

    return dp.reduce((value, element) => max(value, element));
  }


  // Solution
  /**
   * Solution 1
   *
   * DP
   *
   * Complexities:
   *   N - Size of `nums`
   *   - Time Complexity: O(N²)
   *   - Space Complexity: O(N)
   */
  int solution1(List<int> nums) {
    int n = nums.length;
    List<int> dp = List.filled(n, 1);
    int maxLength = 1;

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }

      maxLength = max(maxLength, dp[i]);
    }

    return maxLength;
  }

  /**
   * Solution 2
   *
   * Binary Search
   *
   * Complexities:
   *   N - Size of `nums`
   *   - Time Complexity: O(N * logᴺ)
   *   - Space Complexity: O(N)
   */
  int solution2(List<int> nums) {
    List<int> tails = [];

    for (int num in nums) {
      int left = 0;
      int right = tails.length;

      while (left < right) {
        int mid = left + (right - left) ~/ 2;
        if (tails[mid] < num) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }

      if (left == tails.length) {
        tails.add(num);
      } else {
        tails[left] = num;
      }
    }

    return tails.length;
  }
}
