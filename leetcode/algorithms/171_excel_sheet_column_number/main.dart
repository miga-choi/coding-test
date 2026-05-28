import 'dart:math';

class ExcelSheetColumnNumber {
  /**
   * Complexities:
   *   N - Size of `columnTitle`
   *   - Time Complexity: O(N²)
   *   - Space Complexity: O(1)
   */
  int titleToNumber(String columnTitle) {
    int length = columnTitle.length;
    int result = 0;

    for (int i = 0; i < length; i++) {
      result += (columnTitle[length - i - 1].codeUnitAt(0) - 64) * pow(26, i).toInt();
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
  int solution(String columnTitle) {
    int result = 0;
    int n = columnTitle.length;

    final int asciiA = 'A'.codeUnitAt(0);

    for (int i = 0; i < n; i++) {
      int charCode = columnTitle.codeUnitAt(i);

      int charValue = charCode - asciiA + 1;

      result = result * 26 + charValue;
    }

    return result;
  }
}
