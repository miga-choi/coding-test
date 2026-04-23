class PascalsTriangle {
  /**
   * DP
   * 
   * Complexities:
   *   N - `numRows`
   *   - Time Complexity: O(N²)
   *   - Space Complexity: O(N²)
   */
  List<List<int>> generate(int numRows) {
    List<List<int>> result = List<List<int>>.empty(growable: true);

    for (var i = 0; i < numRows; i++) {
      List<int> row = List<int>.empty(growable: true);
      for (var j = 0; j <= i; j++) {
        if (j == 0 || j == i) {
          row.add(1);
        } else {
          row.add(result[i - 1][j - 1] + result[i - 1][j]);
        }
      }
      result.add(row);
    }

    return result;
  }


  // Solution
  /**
   * DP
   * 
   * Complexities:
   *   N - `numRows`
   *   - Time Complexity: O(N²)
   *   - Space Complexity: O(N²)
   */
  List<List<int>> solution(int numRows) {
    if (numRows <= 0) {
      return [];
    }

    List<List<int>> triangle = [];

    for (int i = 0; i < numRows; i++) {
      List<int> row = List.filled(i + 1, 1);

      for (int j = 1; j < i; j++) {
        row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
      }

      triangle.add(row);
    }

    return triangle;
  }
}
