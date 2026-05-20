class ExcelSheetColumnTitle {
  /**
   * Complexities:
   *   N - `columnNumber`
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(logᴺ)
   */
  public String convertToTitle(int columnNumber) {
    String[] alphabet = {
        "A",
        "B",
        "C",
        "D",
        "E",
        "F",
        "G",
        "H",
        "I",
        "J",
        "K",
        "L",
        "M",
        "N",
        "O",
        "P",
        "Q",
        "R",
        "S",
        "T",
        "U",
        "V",
        "W",
        "X",
        "Y",
        "Z",
    };

    String result = "";

    while (columnNumber > 0) {
      result = alphabet[(columnNumber - 1) % 26] + result;
      columnNumber = (columnNumber - 1) / 26;
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
  public String solution(int columnNumber) {
    StringBuilder sb = new StringBuilder();

    while (columnNumber > 0) {
      columnNumber--;

      int remainder = columnNumber % 26;
      char currentChar = (char) ('A' + remainder);

      sb.append(currentChar);

      columnNumber /= 26;
    }

    return sb.reverse().toString();
  }
}
