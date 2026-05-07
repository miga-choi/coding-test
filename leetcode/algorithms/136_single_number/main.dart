class SingleNumber {
  /**
   * Bit Manipulation
   * 
   * Complexities:
   *   N - Size of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int singleNumber(List<int> nums) {
    int result = 0;

    for (final int num in nums) {
      result ^= num;
    }

    return result;
  }


  // Solution
  /**
   * Solution 1
   * 
   * XOR
   * 
   * Complexities:
   *   N - Size of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int solution1(List<int> nums) {
    int result = 0;

    for (int num in nums) {
      result ^= num;
    }

    return result;
  }

  /**
   * Solution 2
   * 
   * reduce()
   * 
   * Complexities:
   *   N - Size of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int solution2(List<int> nums) {
    return nums.reduce((a, b) => a ^ b);
  }
}
