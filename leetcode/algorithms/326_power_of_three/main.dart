class PowerOfThree {
  /**
   * Complexities:
   *   N - `n`
   *   - Time Complexity: O(log₃ᴺ)
   *   - Space Complexity: O(1)
   */
  bool isPowerOfThree(int n) {
    if (n <= 0) {
      return false;
    }

    while (n % 3 == 0) {
      n ~/= 3;
    }

    return n == 1;
  }


  // Solution
  /**
   * Solution 1
   *
   * Complexities:
   *   N - `n`
   *   - Time Complexity: O(log₃ᴺ)
   *   - Space Complexity: O(1)
   */
  bool solution1(int n) {
    if (n <= 0) {
      return false;
    }

    while (n % 3 == 0) {
      n ~/= 3;
    }

    return n == 1;
  }

  /**
   * Solution 2
   *
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  bool solution2(int n) => n > 0 && 1162261467 % n == 0;
}
