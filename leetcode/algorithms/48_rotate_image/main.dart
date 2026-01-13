class RotateImage {
  /**
   * Transpose & Reverse
   *
   * Complexities:
   *   N - Length of `matrix`
   *   - Time Complexity: O(N²)
   *   - Space Complexity: O(1)
   */
  void rotate(List<List<int>> matrix) {
    final int length = matrix.length;

    // Reverse rows
    for (int row = 0; row < length ~/ 2; row++) {
      for (int col = 0; col < length; col++) {
        final int temp = matrix[row][col];
        matrix[row][col] = matrix[length - 1 - row][col];
        matrix[length - 1 - row][col] = temp;
      }
    }

    // Transpose diagonally
    for (int row = 0; row < length; row++) {
      for (int col = row + 1; col < length; col++) {
        final int temp = matrix[row][col];
        matrix[row][col] = matrix[col][row];
        matrix[col][row] = temp;
      }
    }
  }


  // Solution
  /**
   * Transpose & Reverse
   *
   * Complexities:
   *   N - Length of `matrix`
   *   - Time Complexity: O(N²)
   *   - Space Complexity: O(1)
   */
  void solution1(List<List<int>> matrix) {
    int n = matrix.length;

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int temp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = temp;
      }
    }

    for (int i = 0; i < n; i++) {
      int left = 0;
      int right = n - 1;

      while (left < right) {
        int temp = matrix[i][left];
        matrix[i][left] = matrix[i][right];
        matrix[i][right] = temp;

        left++;
        right--;
      }
    }
  }
}
