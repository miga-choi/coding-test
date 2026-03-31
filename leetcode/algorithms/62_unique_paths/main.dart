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
  int uniquePaths(int m, int n) {
    List<int> dp = List.filled(n, 1);

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
  int solution1(int m, int n) {
    List<int> dp = List.filled(n, 1);

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
  int solution2(int m, int n) {
    int totalSteps = m + n - 2;
    int downSteps = m - 1;

    if (downSteps > n - 1) {
      downSteps = n - 1;
    }

    int result = 1;
    for (int i = 1; i <= downSteps; i++) {
      result = result * (totalSteps - downSteps + i) ~/ i;
    }

    return result;
  }
}
