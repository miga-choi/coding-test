class ClimbingStairs {
  /**
   * DP (Dynamic Programming)
   * - Time Complexity: O(N)
   * - Space Complexity: O(N)
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
   * Recursion (Time Limit Exceeded)
   * - Time Complexity: O(2ᴺ)
   * - Space Complexity: O(1)
   */
  int solution1(int n) {
    if (n <= 2) {
      return n;
    }
    return solution1(n - 1) + solution1(n - 2);
  }

  /**
   * Solution 2
   *
   * DP (Dynamic Programming): Top-down with Memoization
   * - Time Complexity: O(N)
   * - Space Complexity: O(N)
   */
  Map<int, int> memo = {1: 1, 2: 2};

  int solution2(int n) {
    if (memo.containsKey(n)) {
      return memo[n]!;
    }

    int result = solution2(n - 1) + solution2(n - 2);

    memo[n] = result;

    return result;
  }

  /**
   * Solution 3
   *
   * DP (Dynamic Programming): Bottom-up with Tabulation
   * - Time Complexity: O(N)
   * - Space Complexity: O(N)
   */
  int solution3(int n) {
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

  /**
   * Solution 4
   *
   * DP (Dynamic Programming): Space Optimization
   * - Time Complexity: O(N)
   * - Space Complexity: O(1)
   */
  int solution4(int n) {
    if (n <= 2) {
      return n;
    }

    int oneStepBefore = 2;
    int twoStepsBefore = 1;

    for (int i = 3; i <= n; i++) {
      final int allWays = oneStepBefore + twoStepsBefore;

      twoStepsBefore = oneStepBefore;
      oneStepBefore = allWays;
    }

    return oneStepBefore;
  }
}
