class ReverseBits {
  /**
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  int reverseBits(int n) {
    List<String> biString = n.toRadixString(2).split("").reversed.toList();

    while (biString.length < 32) {
      biString.add("0");
    }

    return int.parse(biString.join(""), radix: 2);
  }


  // Solution
  /**
   * Solution 1
   * 
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  int solution1(int n) {
    n = n & 0xFFFFFFFF;

    int result = 0;

    for (int i = 0; i < 32; i++) {
      result = (result << 1) | (n & 1);

      n >>>= 1;
    }

    return result & 0xFFFFFFFF;
  }

  /**
   * Solution 2
   * 
   * Divide & Conquer
   * 
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  int solution2(int n) {
    n = n & 0xFFFFFFFF;

    n = ((n & 0xFFFF0000) >>> 16) | ((n & 0x0000FFFF) << 16);

    n = ((n & 0xFF00FF00) >>> 8) | ((n & 0x00FF00FF) << 8);

    n = ((n & 0xF0F0F0F0) >>> 4) | ((n & 0x0F0F0F0F) << 4);

    n = ((n & 0xCCCCCCCC) >>> 2) | ((n & 0x33333333) << 2);

    n = ((n & 0xAAAAAAAA) >>> 1) | ((n & 0x55555555) << 1);

    return n & 0xFFFFFFFF;
  }
}
