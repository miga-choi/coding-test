int min(int a, int b) {
    return a < b ? a : b;
}

/**
 * DP (Dynamic Programming)
 * 
 * Complexities:
 *   N - `amounta
 *   M - The types of coins
 *   - Time Complexity: O(M * N)
 *   - Space Complexity: O(N)
 */
int coinChange(int* coins, int coinsSize, int amount) {
    if (amount == 0) {
        return 0;
    }

    int dp[amount + 1];
    for (int i = 0; i <= amount; i++) {
        dp[i] = amount + 1;
    }

    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coinsSize; j++) {
            int coin = coins[j];

            if (i >= coin) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    if (dp[amount] > amount) {
        return -1;
    } else {
        return dp[amount];
    }
}


// Solution
/**
 * DP (Dynamic Programming)
 * 
 * Complexities:
 *   N - `amounta
 *   M - The types of coins
 *   - Time Complexity: O(M * N)
 *   - Space Complexity: O(N)
 */
int solution(int* coins, int coinsSize, int amount) {
    int INF = amount + 1;
    int* dp = malloc((amount + 1) * sizeof(int));

    dp[0] = 0;
    for (int a = 1; a <= amount; a++) dp[a] = INF;

    for (int a = 1; a <= amount; a++) {
        for (int i = 0; i < coinsSize; i++) {
            int c = coins[i];

            if (c <= a && dp[a - c] + 1 < dp[a]) {
                dp[a] = dp[a - c] + 1;
            }
        }
    }

    int ans = (dp[amount] > amount) ? -1 : dp[amount];

    free(dp);

    return ans;
}
