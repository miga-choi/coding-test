int min(int a, int b) {
    return a < b ? a : b;
}

/**
 * DP (Dynamic Programming)
 * - Time Complexity: O(M * N)
 * - Space Complexity: O(N)
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
 * - Time Complexity: O(M * N)
 * - Space Complexity: O(N)
 */
int solution(int* coins, int coinsSize, int amount) {
    if (amount == 0) {
        return 0;
    }

    long long dp[amount + 1];

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
        return (int)dp[amount];
    }
}
