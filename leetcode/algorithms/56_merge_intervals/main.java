import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class main {
    /**
     * Sorting
     *
     * Complexities:
     *   N - Length of in `intervals`
     *   - Time Complexity: O(N * logᴺ)
     *   - Space Complexity: O(N)
     */
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (int[] p, int[] n) -> p[0] - n[0]);

        List<int[]> result = new ArrayList<>();

        result.add(intervals[0]);

        for (int i = 1; i < intervals.length; i++) {
            int[] last = result.get(result.size() - 1);
            int[] curr = intervals[i];

            if (last[1] >= curr[0]) {
                if (last[1] < curr[1]) {
                    last[1] = curr[1];
                }
            } else {
                result.add(intervals[i]);
            }
        }

        return result.toArray(new int[result.size()][2]);
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
    public int[][] solution(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));

        List<int[]> merged = new ArrayList<>();

        for (int[] interval : intervals) {
            if (merged.isEmpty() || merged.get(merged.size() - 1)[1] < interval[0]) {
                merged.add(interval);
            } else {
                merged.get(merged.size() - 1)[1] = Math.max(merged.get(merged.size() - 1)[1], interval[1]);
            }
        }

        return merged.toArray(new int[merged.size()][]);
    }
}
