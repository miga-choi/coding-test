class MissingNumber {
  /**
   * Complexities:
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int missingNumber(List<int> nums) {
    int result = 0;

    for (int i = 0; i < nums.length; i++) {
      result = result ^ (i + 1) ^ nums[i];
    }

    return result;
  }


  // Solution
  /**
   * Solution 1
   *
   * Complexities:
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int solution1(List<int> nums) {
    int n = nums.length;

    int expectedSum = n * (n + 1) ~/ 2;

    int actualSum = 0;
    for (int num in nums) {
      actualSum += num;
    }

    return expectedSum - actualSum;
  }

  /**
   * Solution 2
   * 
   * XOR
   *
   * Complexities:
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int solution2(List<int> nums) {
    int missing = nums.length;

    for (int i = 0; i < nums.length; i++) {
      missing ^= i ^ nums[i];
    }

    return missing;
  }
}
