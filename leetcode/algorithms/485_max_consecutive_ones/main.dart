class MaxConsecutiveOnes {
  /**
   * Running Counter
   *
   * Complexities:
   *   n - The Size of `nums`
   *   - Time Complexity: O(n)
   *   - Space Complexity: O(1)
   */
  int findMaxConsecutiveOnes(List<int> nums) {
    int max = 0;
    int current = 0;

    for (int num in nums) {
      if (num > 0) {
        current++;
        if (current > max) {
          max = current;
        }
      } else {
        current = 0;
      }
    }

    return max;
  }


  // Solution
  /**
   * Solution 1
   *
   * Running Counter
   *
   * Complexities:
   *   n - The Size of `nums`
   *   - Time Complexity: O(n)
   *   - Space Complexity: O(1)
   */
  int solution1(List<int> nums) {
    var maxRun = 0;
    var current = 0;

    for (final x in nums) {
      if (x == 1) {
        current++;
        if (current > maxRun) maxRun = current;
      } else {
        current = 0;
      }
    }

    return maxRun;
  }

  /**
   * Solution 2
   *
   * Run Start Tracking
   *
   * Complexities:
   *   n - The Size of `nums`
   *   - Time Complexity: O(n)
   *   - Space Complexity: O(1)
   */
  int solution2(List<int> nums) {
    var maxRun = 0;
    var start = 0;

    for (var i = 0; i < nums.length; i++) {
      if (nums[i] == 0) {
        start = i + 1;
      } else if (i - start + 1 > maxRun) {
        maxRun = i - start + 1;
      }
    }

    return maxRun;
  }

  /**
   * Solution 3
   *
   * String Split
   *
   * Complexities:
   *   n - The Size of `nums`
   *   - Time Complexity: O(n)
   *   - Space Complexity: O(1)
   */
  int solution3(List<int> nums) => nums
      .join()
      .split('0')
      .fold(0, (best, run) => run.length > best ? run.length : best);
}
