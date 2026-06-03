class NumberOf1Bits {
  /**
   * Bit Shift
   *
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  int hammingWeight(int n) {
    int count = 0;

    for (int i = 0; i < 32; i++) {
      if ((n & 1) != 0) {
        count++;
      }
      n = n >> 1;
    }

    return count;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Brian Kernighan's Algorithm
   *
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  int solution1(int n) {
    n = n & 0xFFFFFFFF;
    int count = 0;

    while (n > 0) {
      n &= (n - 1);
      count++;
    }

    return count;
  }

  /**
   * Solution 2
   * 
   * Bit Shift
   *
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  int solution2(int n) {
    n = n & 0xFFFFFFFF;
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
   * Solution 3
   * 
   * Built-in Function
   *
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  int solution3(int n) {
    return n.toRadixString(2).replaceAll('0', '').length;
  }
}
