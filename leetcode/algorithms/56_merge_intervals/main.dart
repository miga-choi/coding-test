import 'dart:math';

class Solution {
  /**
   * Sorting
   *
   * Complexities:
   *   N - Length of in `intervals`
   *   - Time Complexity: O(N * logᴺ)
   *   - Space Complexity: O(N)
   */
  List<List<int>> merge(List<List<int>> intervals) {
    intervals.sort((p, n) => p[0] - n[0]);

    List<List<int>> result = List<List<int>>.empty(growable: true);
    result.add(intervals.first);

    for (List<int> interval in intervals) {
      List<int> last = result.last;
      List<int> curr = interval;

      if (last[1] >= curr[0]) {
        if (last[1] < curr[1]) {
          last[1] = curr[1];
        }
      } else {
        result.add(interval);
      }
    }

    return result;
  }


  // Solution
  /**
   * Sorting
   *
   * Complexities:
   *   N - Length of in `intervals`
   *   - Time Complexity: O(N * logᴺ)
   *   - Space Complexity: O(N)
   */
  List<List<int>> solution(List<List<int>> intervals) {
    intervals.sort((a, b) => a[0].compareTo(b[0]));

    List<List<int>> merged = [];

    for (var interval in intervals) {
      if (merged.isEmpty || interval[0] > merged.last[1]) {
        merged.add(interval);
      } else {
        merged.last[1] = max(merged.last[1], interval[1]);
      }
    }

    return merged;
  }
}
