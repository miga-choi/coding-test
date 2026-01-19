class SetMatrixZeroes {
  /**
   * Marking First Row and Column as Flag
   *
   * Complexities:
   *   M - Length of `matrix`
   *   N - Length of `matrix[0]`
   *   - Time Complexity: O(M * N)
   *   - Space Complexity: O(1)
   */
  void setZeroes(List<List<int>> matrix) {
    bool isFirstRowZero = false;
    bool isFirstColZero = false;

    int m = matrix.length;
    int n = matrix.first.length;

    for (int row = 0; row < m; row++) {
      if (matrix[row][0] == 0) {
        isFirstColZero = true;
        break;
      }
    }

    for (int col = 0; col < n; col++) {
      if (matrix[0][col] == 0) {
        isFirstRowZero = true;
        break;
      }
    }

    for (var row = 1; row < m; row++) {
      for (var col = 1; col < n; col++) {
        if (matrix[row][col] == 0) {
          matrix[row][0] = 0;
          matrix[0][col] = 0;
        }
      }
    }

    for (var row = 1; row < m; row++) {
      for (var col = 1; col < n; col++) {
        if (matrix[row][0] == 0 || matrix[0][col] == 0) {
          matrix[row][col] = 0;
        }
      }
    }

    if (isFirstColZero) {
      for (int row = 0; row < m; row++) {
        matrix[row][0] = 0;
      }
    }

    if (isFirstRowZero) {
      for (int col = 0; col < n; col++) {
        matrix[0][col] = 0;
      }
    }
  }


  // Solution
  /**
   * Marking First Row and Column as Flag
   *
   * Complexities:
   *   M - Length of `matrix`
   *   N - Length of `matrix[0]`
   *   - Time Complexity: O(M * N)
   *   - Space Complexity: O(1)
   */
  void solution(List<List<int>> matrix) {
    int m = matrix.length;
    int n = matrix[0].length;

    bool isCol0Zero = false;

    for (int i = 0; i < m; i++) {
      if (matrix[i][0] == 0) {
        isCol0Zero = true;
      }

      for (int j = 1; j < n; j++) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }

    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 1; j--) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }

      if (isCol0Zero) {
        matrix[i][0] = 0;
      }
    }
  }
}
