class PascalsTriangleII {
  /**
   * DP
   *
   * Complexities:
   *   N - `rowIndex`
   *   - Time Complexity: O(N²)
   *   - Space Complexity: O(N)
   */
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


  // Solution
  /**
   * Solution 1
   *
   * DP
   *
   * Complexities:
   *   N - `rowIndex`
   *   - Time Complexity: O(N²)
   *   - Space Complexity: O(N)
   */
  List<int> solution(int rowIndex) {
    List<int> row = List.filled(rowIndex + 1, 1);

    for (int i = 2; i <= rowIndex; i++) {
      for (int j = i - 1; j > 0; j--) {
        row[j] = row[j] + row[j - 1];
      }
    }

    return row;
  }

  /**
   * Solution 2
   *
   * Binomial Coefficient
   *
   * Complexities:
   *   N - `rowIndex`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  List<int> solution2(int rowIndex) {
    List<int> result = List.filled(rowIndex + 1, 1);

    int prev = 1;

    for (int i = 1; i < rowIndex; i++) {
      prev = prev * (rowIndex - i + 1) ~/ i;

      result[i] = prev;
    }

    return result;
  }
}
