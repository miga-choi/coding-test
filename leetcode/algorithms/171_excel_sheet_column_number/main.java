class ExcelSheetColumnNumber {

  public int titleToNumber(String columnTitle) {
    int result = 0;

    for (int i = columnTitle.length() - 1; i >= 0; i--) {
      result +=
        Math.pow(26, columnTitle.length() - 1 - i) *
        ((int) columnTitle.charAt(i) - 64);
    }

    return result;
  }

  // Best Solution
  public int bestSolution(String s) {
    if (s == null) return -1;
    int sum = 0;
    // for each loop so we don't need to mess with index values.
    for (char c : s.toUpperCase().toCharArray()) {
      sum *= 26;
      sum += c - 'A' + 1;
    }
    return sum;
  }
}
