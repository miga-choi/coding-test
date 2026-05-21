class ExcelSheetColumnTitle {
  /**
   * Complexities:
   *   N - `columnNumber`
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(logᴺ)
   */
  String convertToTitle(int columnNumber) {
    String result = "";

    while (columnNumber > 0) {
      columnNumber -= 1;

      result = String.fromCharCode(columnNumber % 26 + 65) + result;

      columnNumber = (columnNumber / 26).floor();
    }

    return result;
  }


  // Solution
  /**
   * Complexities:
   *   N - `columnNumber`
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(logᴺ)
   */
  String solution(int columnNumber) {
    StringBuffer result = StringBuffer();

    while (columnNumber > 0) {
      columnNumber--;

      int remainder = columnNumber % 26;

      result.write(String.fromCharCode(65 + remainder));

      columnNumber ~/= 26;
    }

    return result.toString().split('').reversed.join('');
  }
}
