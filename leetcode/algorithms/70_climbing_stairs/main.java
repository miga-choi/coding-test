class ClimbingStairs {
  /**
   * DP (Dynamic Programming)
   * - Time Complexity: O(N)
   * - Space Complexity: O(N)
   */
  public int climbStairs(int n) {
    if (n < 3) {
      return n;
    }

    int[] dp = new int[n + 1];
    dp[0] = 0;
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
   * Recursion (Time Limit Exceeded)
   * - Time Complexity: O(2ᴺ)
   * - Space Complexity: O(1)
   */
  public int solution1(int n) {
    if (n <= 2) {
      return n;
    }
    return climbStairs(n - 1) + climbStairs(n - 2);
  }

  /**
   * Solution 2
   *
   * DP (Dynamic Programming): Top-down with Memoization
   * - Time Complexity: O(N)
   * - Space Complexity: O(N)
   */
  private int climbStairsMemo(int n, int[] memo) {
    if (n <= 2) {
      return n;
    }

    if (memo[n] > 0) {
      return memo[n];
    }

    memo[n] = climbStairsMemo(n - 1, memo) + climbStairsMemo(n - 2, memo);

    return memo[n];
  }

  public int solution2(int n) {
    int[] memo = new int[n + 1];
    return climbStairsMemo(n, memo);
  }

  /**
   * Solution 3
   *
   * DP (Dynamic Programming): Bottom-up with Tabulation
   * - Time Complexity: O(N)
   * - Space Complexity: O(N)
   */
  public int solution3(int n) {
    if (n <= 2) {
      return n;
    }

    int[] dp = new int[n + 1];
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
  }

  /**
   * Solution 4
   *
   * DP (Dynamic Programming): Space Optimization
   * - Time Complexity: O(N)
   * - Space Complexity: O(1)
   */
  public int solution4(int n) {
    if (n <= 2) {
      return n;
    }

    int twoStepsBack = 1;
    int oneStepBack = 2;

    for (int i = 3; i <= n; i++) {
      int currentWays = twoStepsBack + oneStepBack;

      twoStepsBack = oneStepBack;
      oneStepBack = currentWays;
    }

    return oneStepBack;
  }
}
