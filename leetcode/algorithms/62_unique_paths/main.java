import java.util.Arrays;

class UniquePaths {
    /**
     * DP
     *
     * Complexities:
     *   M - `m`
     *   N - `n`
     *   - Time Complexity: O(M * N)
     *   - Space Complexity: O(N)
     */
    public int uniquePaths(int m, int n) {
        int[] dp = new int[n];
        Arrays.fill(dp, 1);

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] = dp[j] + dp[j - 1];
            }
        }

        return dp[n - 1];
    }


    // Solution
    /**
     * Solution 1
     * 
     * DP
     *
     * Complexities:
     *   M - `m`
     *   N - `n`
     *   - Time Complexity: O(M * N)
     *   - Space Complexity: O(N)
     */
    public int solution1(int m, int n) {
        int[] dp = new int[n];

        for (int i = 0; i < n; i++) {
            dp[i] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] = dp[j] + dp[j - 1];
            }
        }

        return dp[n - 1];
    }

    /**
     * Solution 2
     * 
     * Combinatorics
     *
     * Complexities:
     *   M - `m`
     *   N - `n`
     *   - Time Complexity: O(min(M, N))
     *   - Space Complexity: O(1)
     */
    public int solution2(int m, int n) {
        int totalMoves = m + n - 2;
        int k = Math.min(m - 1, n - 1);

        long result = 1;

        for (int i = 1; i <= k; i++) {
            result = result * (totalMoves - i + 1) / i;
        }

        return (int) result;
    }
}
