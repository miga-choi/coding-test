class SingleNumber {
  /**
   * Bit Manipulation
   *
   * Complexities:
   *   N - Size of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  public int singleNumber(int[] nums) {
    int result = 0;

    for (int num : nums) {
      result = result ^ num;
    }

    return result;
  }


  // Solution
  /**
   * XOR
   *
   * Complexities:
   *   N - Size of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  public int solution1(int[] nums) {
    int result = 0;

    for (int num : nums) {
      result = result ^ num;
    }

    return result;
  }
}
