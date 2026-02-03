class ClimbingStairs {
  /**
   * DP (Dynamic Programming) with Array
   *
   * Complexities:
   *   N - Value of `n`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  int climbStairs(int n) {
    if (n < 3) {
      return n;
    }

    List<int> dp = List<int>.filled(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
  }


  // Solution
  /**
   * Solution 1
   *
   * DP (Dynamic Programming)
   *
   * Complexities:
   *   N - Value of `n`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int solution1(int n) {
    if (n <= 2) {
      return n;
    }

    int prev2 = 1;
    int prev1 = 2;

    for (int i = 3; i <= n; i++) {
      int current = prev1 + prev2;

      prev2 = prev1;
      prev1 = current;
    }

    return prev1;
  }

  /**
   * Solution 2
   *
   * DP (Dynamic Programming) with Array
   *
   * Complexities:
   *   N - Value of `n`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  int solution2(int n) {
    if (n <= 2) {
      return n;
    }

    List<int> dp = List.filled(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
  }
}
