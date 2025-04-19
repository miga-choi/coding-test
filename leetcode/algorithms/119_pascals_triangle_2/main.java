import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class PascalsRiangleII {
  public List<Integer> getRow(int rowIndex) {
    List<List<Integer>> rows = new ArrayList<List<Integer>>();
    for (int i = 0; i <= rowIndex; i++) {
      List<Integer> row = new ArrayList<Integer>();
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
  public List<Integer> solution(int k) {
    Integer[] arr = new Integer[k + 1];
    Arrays.fill(arr, 0);
    arr[0] = 1;

    for (int i = 1; i <= k; i++) {
      for (int j = i; j > 0; j--) {
        arr[j] = arr[j] + arr[j - 1];
      }
    }

    return Arrays.asList(arr);
  }
}
