class ClimbingStairs {
  int climbstairs(int n) {
    if (n < 2) {
      return 1;
    }

    List<int> dp = List<int>.filled(n, 0);
    dp[0] = 1;
    dp[1] = 2;

    for (int i = 2; i < n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n - 1];
  }


  // Solution
  int solution(int n) {
    int a = 1, b = 1;
    while (n-- > 0) {
      a = (b += a) - a;
    }
    return a;
  }
}
