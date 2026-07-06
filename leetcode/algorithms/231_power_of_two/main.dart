class PowerOfTwo {
  /**
   * Complexities:
   *   N - `n`
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(1)
   */
  bool isPowerOfTwo(int n) {
    if (n <= 0) {
      return false;
    }

    while ((n / 2).floor() > 0) {
      if (n > 1 && (n % 2) != 0) {
        return false;
      }
      n = (n / 2).floor();
    }

    return true;
  }


  // Solution
  /**
   * Solution 1
   *
   * Bit Manipulation
   *
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  bool solution1(int n) {
    return n > 0 && (n & (n - 1)) == 0;
  }

  /**
   * Solution 2
   *
   * Complexities:
   *   N - `n`
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(1)
   */
  bool solution2(int n) {
    if (n <= 0) {
      return false;
    }

    while (n % 2 == 0) {
      n = n ~/ 2;
    }

    return n == 1;
  }
}
