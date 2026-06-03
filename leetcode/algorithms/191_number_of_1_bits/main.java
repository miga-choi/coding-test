class NumberOf1Bits {
  /**
   * Built-in Function
   *
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  public int hammingWeight(int n) {
    return Integer.toBinaryString(n).replaceAll("0", "").length();
  }


  // Solution
  /**
   * Solution 1
   *
   * Bit Shift
   *
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  public static int solution1(int n) {
    int count = 0;

    for (int i = 0; i < 32; i++) {
      if ((n & 1) == 1) {
        count++;
      }
      n >>>= 1;
    }

    return count;
  }

  /**
   * Solution 2
   *
   * Brian Kernighan's Algorithm
   *
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  public static int solution2(int n) {
    int count = 0;

    while (n != 0) {
      n = n & (n - 1);
      count++;
    }

    return count;
  }
}
