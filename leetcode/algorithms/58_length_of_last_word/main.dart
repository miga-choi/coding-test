class LengthOfLastWord {
  /**
   * Reverse Traversal
   * 
   * Complexities:
   *   N - Length of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int lengthOfLastWord(String s) {
    List<String> sArray = s.trim().split(" ");

    for (var i = sArray.length - 1; i >= 0; i--) {
      if (sArray[i].trim().length > 0) {
        return sArray[i].length;
      }
    }

    return 0;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Reverse Traversal
   * 
   * Complexities:
   *   N - Length of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int solution1(String s) {
    int length = 0;
    int i = s.length - 1;

    while (i >= 0 && s[i] == ' ') {
      i--;
    }

    while (i >= 0 && s[i] != ' ') {
      length++;
      i--;
    }

    return length;
  }

  /**
   * Solution 2
   * 
   * Built-in function
   * 
   * Complexities:
   *   N - Length of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  int solution2(String s) {
    return s.trim().split(RegExp(r'\s+')).last.length;
  }
}
