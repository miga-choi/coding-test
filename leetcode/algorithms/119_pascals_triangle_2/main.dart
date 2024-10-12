class PascalsTriangle2 {
  List<int> getRow(int rowIndex) {
    final List<List<int>> result = List<List<int>>.empty(growable: true);
    for (int i = 0; i <= rowIndex; i++) {
      final List<int> row = List<int>.empty(growable: true);
      for (int j = 0; j <= i; j++) {
        if (j == 0 || j == i) {
          row.add(1);
        } else {
          row.add(result[i - 1][j - 1] + result[i - 1][j]);
        }
      }
      result.add(row);
    }
    return result[rowIndex];
  }

  // Best Solution
  List<int> bestSolution(int rowIndex) {
    List<int> result = [];
    int value = 1;

    for (int i = 0; i <= rowIndex; i++) {
      result.add(value);
      value = (value * (rowIndex - i)) ~/ (i + 1);
    }

    return result;
  }
}
