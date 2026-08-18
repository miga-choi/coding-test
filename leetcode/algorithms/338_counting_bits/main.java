import java.util.ArrayList;
import java.util.List;

class CountingBits {
    /**
     * Time Complexity should <= O(N)
     *
     * Complexities:
     *   - Time Complexity: O(N * logᴺ)
     *   - Space Complexity: O(N * logᴺ)
     */
    public int[] countBits(int n) {
        List<Integer> result = new ArrayList<>();

        for (int i = 0; i <= n; i++) {
            int sum = 0;
            String bits = Integer.toBinaryString(i);
            for (int j = 0; j < bits.length(); j++) {
                sum += Integer.valueOf(String.valueOf(bits.charAt(j)));
            }
            result.add(sum);
        }

        return result.stream().mapToInt(value -> value).toArray();
    }


    // Solution
    /**
     * Solution 1
     *
     * DP (Dynamic programming)
     *
     * Complexities:
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    public int[] solution1(int n) {
        int[] dp = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i >> 1] + (i & 1);
        }

        return dp;
    }

    /**
     * Solution 2
     *
     * DP (Dynamic programming)
     *
     * Complexities:
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    public int[] solution2(int n) {
        int[] dp = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i & (i - 1)] + 1;
        }

        return dp;
    }
}
