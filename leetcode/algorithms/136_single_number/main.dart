class SingleNumber {
  /**
   * Bit Manipulation
   * - Time Complexity: O(N)
   * - Space Complexity: O(1)
   */
  int singleNumber(List<int> nums) {
    int result = 0;

    for (final int num in nums) {
      result ^= num;
    }

    return result;
  }
}
