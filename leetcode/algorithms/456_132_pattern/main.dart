import 'dart:math';

class OneThreeTwoPattern {
  /**
   * Monotonic Stack (In-place)
   *
   * Complexities:
   *   N - The Size of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  bool find132pattern(List<int> nums) {
    int peak = nums.length;
    int min = pow(-10, 9).floor();

    for (int i = nums.length - 1; i >= 0; i--) {
      if (nums[i] < min) {
        return true;
      }

      while (peak < nums.length && nums[i] > nums[peak]) {
        min = nums[peak];
        peak++;
      }

      peak--;
      nums[peak] = nums[i];
    }

    return false;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Monotonic Stack
   *
   * Complexities:
   *   N - The Size of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  bool solution1(List<int> nums) {
    final stack = <int>[];
    int? third;

    for (var i = nums.length - 1; i >= 0; i--) {
      final x = nums[i];

      if (third != null && x < third) {
        return true;
      }

      while (stack.isNotEmpty && stack.last < x) {
        third = stack.removeLast();
      }

      stack.add(x);
    }

    return false;
  }

  /**
   * Solution 2
   *
   * Prefix Minimum + Monotonic Stack
   *
   * Complexities:
   *   N - The Size of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  bool solution2(List<int> nums) {
    final n = nums.length;

    if (n < 3) {
      return false;
    }

    final minLeft = List<int>.filled(n, 0);
    minLeft[0] = nums[0];

    for (var i = 1; i < n; i++) {
      minLeft[i] = nums[i] < minLeft[i - 1] ? nums[i] : minLeft[i - 1];
    }

    final stack = <int>[];

    for (var j = n - 1; j >= 1; j--) {
      if (nums[j] <= minLeft[j]) {
        continue;
      }

      while (stack.isNotEmpty && stack.last <= minLeft[j]) {
        stack.removeLast();
      }

      if (stack.isNotEmpty && stack.last < nums[j]) {
        return true;
      }

      stack.add(nums[j]);
    }

    return false;
  }

  /**
   * Solution 3
   *
   * Prefix Minimum + Brute Force
   *
   * Complexities:
   *   N - The Size of `nums`
   *   - Time Complexity: O(N²)
   *   - Space Complexity: O(1)
   */
  bool solution3(List<int> nums) {
    var minI = nums[0];

    for (var j = 1; j < nums.length; j++) {
      for (var k = j + 1; k < nums.length; k++) {
        if (minI < nums[k] && nums[k] < nums[j]) {
          return true;
        }
      }

      if (nums[j] < minI) {
        minI = nums[j];
      }
    }

    return false;
  }
}
