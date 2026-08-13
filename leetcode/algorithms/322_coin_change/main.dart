import 'dart:math';

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
   * Solution 1
   * 
   * DP (Dynamic Programming)
   *
   * Complexities:
   *   N - The size of `coins`
   *   M - `amount`
   *   - Time Complexity: O(N * M)
   *   - Space Complexity: O(N)
   */
  int solution1(List<int> coins, int amount) {
    final unreachable = amount + 1;
    final dp = List<int>.filled(amount + 1, unreachable);
    dp[0] = 0;

    for (var i = 1; i <= amount; i++) {
      for (final c in coins) {
        if (c <= i && dp[i - c] + 1 < dp[i]) {
          dp[i] = dp[i - c] + 1;
        }
      }
    }

    return dp[amount] > amount ? -1 : dp[amount];
  }

  /**
   * Solution 2
   * 
   * BFS
   *
   * Complexities:
   *   N - The size of `coins`
   *   M - `amount`
   *   - Time Complexity: O(N * M)
   *   - Space Complexity: O(M)
   */
  int solution2(List<int> coins, int amount) {
    if (amount == 0) {
      return 0;
    }

    final visited = List<bool>.filled(amount + 1, false);
    var queue = <int>[amount];
    visited[amount] = true;
    var steps = 0;

    while (queue.isNotEmpty) {
      steps++;

      final next = <int>[];

      for (final cur in queue) {
        for (final c in coins) {
          final rest = cur - c;

          if (rest == 0) {
            return steps;
          }

          if (rest > 0 && !visited[rest]) {
            visited[rest] = true;
            next.add(rest);
          }
        }
      }

      queue = next;
    }

    return -1;
  }
}
