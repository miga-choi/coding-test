class Solution {

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

  // Best Solution
  public String bestSolution(int n) {
    return n == 0 ? "" : convertToTitle(--n / 26) + (char) ('A' + (n % 26));
  }
}
