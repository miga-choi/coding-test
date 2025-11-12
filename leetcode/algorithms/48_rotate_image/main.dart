class RotateImage {
  /**
   * Reverse & Transpose
   * - Time Complexity: O(N²)
   * - Space Complexity: O(1)
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
   * Solution 1
   * 
   * Transpose & Reflect
   * - Time Complexity: O(N²)
   * - Space Complexity: O(1)
   */
  void solution1(List<List<int>> matrix) {
    int n = matrix.length;

    // Transpose
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        int temp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = temp;
      }
    }

    // Reflect
    for (int i = 0; i < n; i++) {
      matrix[i] = matrix[i].reversed.toList();
    }
  }

  /**
   * Solution 2
   * 
   * Rotate Layer by Layer
   * - Time Complexity: O(N²)
   * - Space Complexity: O(1)
   */
  void solution2(List<List<int>> matrix) {
    int n = matrix.length;
    int left = 0, right = n - 1;

    while (left < right) {
      for (int i = 0; i < right - left; i++) {
        int top = left, bottom = right;

        // top-left -> temp
        int topLeft = matrix[top][left + i];

        // bottom-left -> top-left
        matrix[top][left + i] = matrix[bottom - i][left];

        // bottom-right -> bottom-left
        matrix[bottom - i][left] = matrix[bottom][right - i];

        // top-right -> bottom-right
        matrix[bottom][right - i] = matrix[top + i][right];

        // top-left -> top-right
        matrix[top + i][right] = topLeft;
      }

      // next inner layer
      left++;
      right--;
    }
  }
}
