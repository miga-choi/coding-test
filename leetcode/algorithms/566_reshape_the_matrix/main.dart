class ReshapeTheMatrix {
  List<List<int>> matrixReshape(List<List<int>> mat, int r, int c) {
    if (mat.length * mat.first.length != r * c) {
      return mat;
    }

    List<List<int>> result = List<List<int>>.generate(r, (int v) => List<int>.filled(c, 0));

    int row = 0, col = 0;

    for (int i = 0; i < mat.length; i++) {
      for (int j = 0; j < mat[i].length; j++) {
        result[row][col] = mat[i][j];
        col++;
        if (col >= c) {
          col = 0;
          row++;
        }
      }
    }

    return result;
  }

  // Solution
  List<List<int>> solution(List<List<int>> mat, int r, int c) {
    int m = mat.length, n = mat[0].length, total = m * n;

    if (r * c != total) {
      return mat;
    }

    List<List<int>> ans = List.generate(r, (i) => List.filled(c, 0));
    for (int i = 0; i < total; i++) {
      ans[i ~/ c][i % c] = mat[i ~/ n][i % n];
    }

    return ans;
  }
}
