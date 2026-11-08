class NumberComplement {
  /**
   * Double Bit Reversal
   * 
   * Complexities:
   *   N - The Bit Length of `num`
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(1)
   */
  int findComplement(int num) {
    int startsWithZeroCount = 0;
    int zeroCountDone = 0;

    int reverseNum = 0;
    while (num > 0) {
      if (zeroCountDone == 0) {
        if ((num & 1) > 0) {
          startsWithZeroCount++;
        } else {
          zeroCountDone = 1;
        }
      }

      reverseNum = (reverseNum << 1) | (num & 1 ^ 1);
      num >>= 1;
    }

    int result = 0;
    while (reverseNum > 0) {
      result = (result << 1) | (reverseNum & 1);
      reverseNum >>= 1;
    }

    return result << startsWithZeroCount;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Bit Length Mask + XOR
   * 
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  int solution1(int num) {
    final mask = (1 << num.bitLength) - 1;
    return num ^ mask;
  }

  /**
   * Solution 2
   * 
   * Bit Smearing + XOR
   * 
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  int solution2(int num) {
    var mask = num;
    mask |= mask >> 1;
    mask |= mask >> 2;
    mask |= mask >> 4;
    mask |= mask >> 8;
    mask |= mask >> 16;
    return num ^ mask;
  }

  /**
   * Solution 3
   * 
   * Iterative Mask Building + XOR
   * 
   * Complexities:
   *   N - The Bit Length of `num`
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(1)
   */
  int solution3(int num) {
    var mask = 1;

    while (mask < num) {
      mask = (mask << 1) | 1;
    }

    return num ^ mask;
  }
}
