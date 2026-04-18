class SpiralMatrix {
  /**
   * Layer Peeling
   *
   * Complexities:
   * M - matrixSize
   * N - matrixColSize
   * - Time Complexity: O(M * N)
   * - Space Complexity: O(M * N)
   */
  List<int> spiralOrder(List<List<int>> matrix) {
    int m = matrix.length;

    if (matrix.length == 1) {
      return matrix[0];
    }

    int n = matrix[0].length;

    List<int> result = new List.empty(growable: true);

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
      // [top][left -> right]
      for (int col = left; col <= right; col++) {
        result.add(matrix[top][col]);
      }
      top++;

      // [top -> bottom][right]
      for (int row = top; row <= bottom; row++) {
        result.add(matrix[row][right]);
      }
      right--;

      // [bottom][right -> left]
      if (top <= bottom) {
        for (int col = right; col >= left; col--) {
          result.add(matrix[bottom][col]);
        }
        bottom--;
      }

      // [bottom -> top][left]
      if (left <= right) {
        for (int row = bottom; row >= top; row--) {
          result.add(matrix[row][left]);
        }
        left++;
      }
    }

    return result;
  }


  // Solution
  /**
   * Layer Peeling
   *
   * Complexities:
   * M - matrixSize
   * N - matrixColSize
   * - Time Complexity: O(M * N)
   * - Space Complexity: O(M * N)
   */
  List<int> solution(List<List<int>> matrix) {
    int m = matrix.length;
    int n = matrix[0].length;
    List<int> result = [];

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
      // right -> left
      for (int i = left; i <= right; i++) {
        result.add(matrix[top][i]);
      }
      top++;

      // top -> bottom
      for (int i = top; i <= bottom; i++) {
        result.add(matrix[i][right]);
      }
      right--;

      // right -> left && check boundary
      if (top <= bottom) {
        for (int i = right; i >= left; i--) {
          result.add(matrix[bottom][i]);
        }
        bottom--;
      }

      // bottom -> top && check boundary
      if (left <= right) {
        for (int i = bottom; i >= top; i--) {
          result.add(matrix[i][left]);
        }
        left++;
      }
    }

    return result;
  }
}
