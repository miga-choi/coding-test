import 'dart:math';

class Solution {
  int maxCount(int m, int n, List<List<int>> ops) {
    int minRow = m, minCol = n;
    for (List<int> op in ops) {
      int row = op.first, col = op.last;
      if (row < minRow) {
        minRow = row;
      }
      if (col < minCol) {
        minCol = col;
      }
    }
    return minRow * minCol;
  }

  // Solution
  int solution(int m, int n, List<List<int>> ops) {
    int minM = m, minN = n;
    for (var op in ops) {
      minM = min(op[0], minM);
      minN = min(op[1], minN);
    }
    return minN * minM;
  }
}
