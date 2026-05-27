class ExcelSheetColumnNumber {
  /**
   * Complexities:
   *   N - Size of `columnTitle`
   *   - Time Complexity: O(N²)
   *   - Space Complexity: O(1)
   */
  public int titleToNumber(String columnTitle) {
    int result = 0;

    for (int i = columnTitle.length() - 1; i >= 0; i--) {
      result += Math.pow(26, columnTitle.length() - 1 - i) *
          ((int) columnTitle.charAt(i) - 64);
    }

    return result;
  }


  // Solution
  /**
   * Complexities:
   *   N - Size of `columnTitle`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  public int solution(String columnTitle) {
    int result = 0;
    int length = columnTitle.length();

    for (int i = 0; i < length; i++) {
      char c = columnTitle.charAt(i);

      int value = c - 'A' + 1;

      result = result * 26 + value;
    }

    return result;
  }
}
