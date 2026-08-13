import java.util.Arrays;

class CoinChange {
    /**
     * DP (Dynamic Programming)
     *
     * Complexities:
     *   N - The size of `coins`
     *   M - `amount`
     *   - Time Complexity: O(N * M)
     *   - Space Complexity: O(N)
     */
    public int coinChange(int[] coins, int amount) {
        if (amount == 0) {
            return 0;
        }

        int[] dp = new int[amount + 1];
        for (int i = 0; i <= amount; i++) {
            dp[i] = amount + 1;
        }

        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.length; j++) {
                int coin = coins[j];
                if (i >= coin) {
                    dp[i] = Math.min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }


    // Solution
    /**
     * DP (Dynamic Programming)
     *
     * Complexities:
     *   N - The size of `coins`
     *   M - `amount`
     *   - Time Complexity: O(N * M)
     *   - Space Complexity: O(N)
     */
    public int solution(int[] coins, int amount) {
        int INF = amount + 1;
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, INF);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i && dp[i - coin] != INF) {
                    dp[i] = Math.min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] == INF ? -1 : dp[amount];
    }
}
