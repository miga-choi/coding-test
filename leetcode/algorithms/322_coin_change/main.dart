import 'dart:math';

class CoinChange {
  /**
   * DP (Dynamic Programming)
   * - Time Complexity: O(M * N)
   * - Space Complexity: O(N)
   */
  int coinChange(List<int> coins, int amount) {
    if (amount == 0) {
      return 0;
    }

    final List<int> dp = List<int>.filled(amount + 1, 10001);
    dp[0] = 0;

    for (int v = 0; v <= amount; v++) {
      for (final int coin in coins) {
        if (v >= coin) {
          dp[v] = min(dp[v], dp[v - coin] + 1);
        }
      }
    }

    return dp[amount] > amount ? -1 : dp[amount];
  }


  // Solution
  /**
   * DP (Dynamic Programming)
   * - Time Complexity: O(M * N)
   * - Space Complexity: O(N)
   */
  int solution(List<int> coins, int amount) {
    List<int> dp = List.filled(amount + 1, amount + 1);

    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
      for (final coin in coins) {
        if (i - coin >= 0) {
          dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
      }
    }

    return dp[amount] > amount ? -1 : dp[amount];
  }
}
