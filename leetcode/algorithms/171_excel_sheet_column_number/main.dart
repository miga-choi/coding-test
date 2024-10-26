import 'dart:math';

class ExcelSheetColumnNumber {
  int titleToNumber(String columnTitle) {
    int length = columnTitle.length;
    int result = 0;
    for (int i = 0; i < length; i++) {
      result +=
          (columnTitle[length - i - 1].codeUnitAt(0) - 64) * pow(26, i).toInt();
    }
    return result;
  }

  // Best Solution
  int bestSolution(String columnTitle) {
    int res = 0;
    for (int i = 0; i < columnTitle.length; i++) {
      // 64 = codeUnits['A'] -1
      int s = columnTitle.codeUnits[i] - 64;
      res = res * 26 + s;
    }
    return res;
  }
}
