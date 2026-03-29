import 'dart:math';

class HouseRobber {
  /**
   * DP
   *
   * Complexities:
   *   N - Size of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int rob(List<int> nums) {
    int prev1 = 0;
    int prev2 = 0;

    for (int num in nums) {
      final int currentMax = max(prev1, prev2 + num);

      prev2 = prev1;
      prev1 = currentMax;
    }

    return prev1;
  }


  // Solution
  /**
   * DP
   *
   * Complexities:
   *   N - Size of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int solution(List<int> nums) {
    if (nums.isEmpty) {
      return 0;
    }

    if (nums.length == 1) {
      return nums[0];
    }

    int prev2 = 0;
    int prev1 = 0;

    for (int num in nums) {
      int current = max(prev1, prev2 + num);

      prev2 = prev1;
      prev1 = current;
    }

    return prev1;
  }
}
