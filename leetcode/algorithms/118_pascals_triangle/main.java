import java.util.ArrayList;
import java.util.List;

class PascalsTriangle {
  /**
   * DP
   * 
   * Complexities:
   *   N - `numRows`
   *   - Time Complexity: O(N²)
   *   - Space Complexity: O(N²)
   */
  public List<List<Integer>> generate(int numRows) {
    List<List<Integer>> result = new ArrayList<>();

    for (int i = 0; i < numRows; i++) {
      List<Integer> row = new ArrayList<>();

      for (int j = 0; j <= i; j++) {
        if (j == 0 || j == i) {
          row.add(1);
        } else {
          row.add(result.get(i - 1).get(j - 1) + result.get(i - 1).get(j));
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
  public List<List<Integer>> solution(int numRows) {
        List<List<Integer>> triangle = new ArrayList<>();

        if (numRows == 0) {
            return triangle;
        }

        for (int i = 0; i < numRows; i++) {
            List<Integer> row = new ArrayList<>();

            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    row.add(1);
                } else {
                    List<Integer> prevRow = triangle.get(i - 1);
                    int sum = prevRow.get(j - 1) + prevRow.get(j);
                    row.add(sum);
                }
            }

            triangle.add(row);
        }

        return triangle;
  }
}
