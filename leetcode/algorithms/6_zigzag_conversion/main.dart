class ZigzagConversion {
  /**
   * Complexities:
   *   N - Length of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  String convert(String s, int numRows) {
    int sLen = s.length;

    if (numRows == 1 || numRows > sLen) {
      return s;
    }

    int cycleLen = numRows * 2 - 2;
    String result = "";

    for (int row = 0; row < numRows; row++) {
      for (int cycle = row; cycle < sLen; cycle += cycleLen) {
        result += s[cycle];

        if (row > 0 && row < numRows - 1) {
          int diag_idx = cycle + cycleLen - row * 2;
          if (diag_idx < sLen) {
            result += s[diag_idx];
          }
        }
      }
    }

    return result;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Complexities:
   *   N - Length of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  String solution1(String s, int numRows) {
    if (numRows == 1 || s.length <= numRows) {
      return s;
    }

    List<StringBuffer> rows = List.generate(numRows, (_) => StringBuffer());

    int currentRow = 0;
    bool goingDown = false;

    for (final char in s.runes) {
      rows[currentRow].writeCharCode(char);

      if (currentRow == 0 || currentRow == numRows - 1) {
        goingDown = !goingDown;
      }

      currentRow += goingDown ? 1 : -1;
    }

    return rows.map((sb) => sb.toString()).join('');
  }

  /**
   * Solution 2
   * 
   * Complexities:
   *   N - Length of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  String solution2(String s, int numRows) {
    if (numRows == 1 || s.length <= numRows) {
      return s;
    }

    final int n = s.length;
    final StringBuffer result = StringBuffer();
    final int cycleLen = 2 * numRows - 2;

    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j + i < n; j += cycleLen) {
        result.write(s[j + i]);

        if (i != 0 && i != numRows - 1) {
          int secondIndex = j + cycleLen - i;
          if (secondIndex < n) {
            result.write(s[secondIndex]);
          }
        }
      }
    }

    return result.toString();
  }
}
