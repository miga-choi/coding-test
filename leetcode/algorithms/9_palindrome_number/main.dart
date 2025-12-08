class PalindromeNumber {
  /**
   * Complexities:
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(1)
   */
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }

    final List<String> xList = x.toString().split("");
    for (var i = 0; i < xList.length / 2; i++) {
      if (xList[i] != xList[xList.length - 1 - i]) return false;
    }

    return true;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Mathematical Reversion
   * 
   * Complexities:
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(1)
   */
  bool solution1(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) {
      return false;
    }

    int original = x;
    int reversed = 0;

    while (x > 0) {
      int digit = x % 10;
      reversed = reversed * 10 + digit;
      x = x ~/ 10;
    }

    return original == reversed;
  }

  /**
   * Solution 2
   * 
   * Revert Half of the Number
   * 
   * Complexities:
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(1)
   */
  bool solution2(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) {
      return false;
    }

    int reversed = 0;

    while (x > reversed) {
      reversed = reversed * 10 + x % 10;
      x = x ~/ 10;
    }

    return x == reversed || x == reversed ~/ 10;
  }
}
