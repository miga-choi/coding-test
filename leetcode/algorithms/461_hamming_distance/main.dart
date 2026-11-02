class HammingDistance {
  /**
   * XOR + Bit Shifting
   *
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  int hammingDistance(int x, int y) {
    int cnt = 0, n = x ^ y;

    while (n > 0) {
      cnt += n & 1;
      n >>= 1;
    }

    return cnt;
  }


  // Solution
  /**
   * Solution 1
   *
   * XOR + Brian Kernighan’s Algorithm
   *
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  int solution1(int x, int y) {
    var diff = x ^ y;
    var count = 0;

    while (diff != 0) {
      diff &= diff - 1;
      count++;
    }

    return count;
  }

  /**
   * Solution 2
   *
   * XOR + Bit Shifting
   *
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  int solution2(int x, int y) {
    var diff = x ^ y;
    var count = 0;

    while (diff != 0) {
      count += diff & 1;
      diff >>= 1;
    }

    return count;
  }

  /**
   * Solution 3
   *
   * XOR + SWAR Popcount
   *
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  int solution3(int x, int y) {
    var v = x ^ y;
    v = v - ((v >> 1) & 0x55555555);
    v = (v & 0x33333333) + ((v >> 2) & 0x33333333);
    v = (v + (v >> 4)) & 0x0F0F0F0F;
    return ((v * 0x01010101) & 0xFFFFFFFF) >> 24;
  }
}
