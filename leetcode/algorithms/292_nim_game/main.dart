class NimGame {
  /**
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  bool canWinNim(int n) {
    return n % 4 > 0;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  bool solution1(int n) => n % 4 != 0;

  /**
   * Solution 2
   * 
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  bool solution2(int n) => (n & 3) != 0;
}
