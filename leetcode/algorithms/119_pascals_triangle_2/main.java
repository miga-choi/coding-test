import java.util.ArrayList;
import java.util.List;

class PascalsRiangleII {
  /**
   * DP
   *
   * Complexities:
   *   N - `rowIndex`
   *   - Time Complexity: O(N²)
   *   - Space Complexity: O(N)
   */
  public List<Integer> getRow(int rowIndex) {
    List<List<Integer>> rows = new ArrayList<>();

    for (int i = 0; i <= rowIndex; i++) {
      List<Integer> row = new ArrayList<>();

      for (int j = 0; j <= i; j++) {
        if (j == 0 || j == i) {
          row.add(1);
        } else {
          row.add(rows.get(i - 1).get(j - 1) + rows.get(i - 1).get(j));
        }
      }

      rows.add(row);
    }

    return rows.get(rowIndex);
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
  public List<Integer> solution1(int rowIndex) {
    List<Integer> row = new ArrayList<>();

    row.add(1);

    for (int i = 1; i <= rowIndex; i++) {
      for (int j = i - 1; j > 0; j--) {
        row.set(j, row.get(j) + row.get(j - 1));
      }

      row.add(1);
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
  public List<Integer> solution2(int rowIndex) {
    List<Integer> row = new ArrayList<>();

    long val = 1;

    for (int j = 0; j <= rowIndex; j++) {
      row.add((int) val);

      val = val * (rowIndex - j) / (j + 1);
    }

    return row;
  }
}
