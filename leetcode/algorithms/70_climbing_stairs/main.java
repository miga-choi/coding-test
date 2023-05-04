import java.util.HashMap;
import java.util.Map;

class ClimbingStairs {

  public int climbStairs(int n) {
    if (n < 2) {
      return 1;
    }

    // Fibonacci numbers
    int[] dp = new int[n];
    dp[0] = 1;
    dp[1] = 2;

    for (int i = 2; i < n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n - 1];
  }

  // Best Solution
  // Recustion (Top Down Approach)
  public int bestSolution1(int n) {
    if (n == 0) {
      return 0;
    }
    if (n == 1) {
      return 1;
    }
    if (n == 2) {
      return 2;
    }
    return climbStairs(n - 1) + climbStairs(n - 2);
  }

  // Recustion + Memorization (Top Down Approach)
  public int bestSolution2(int n) {
    Map<Integer, Integer> memo = new HashMap<>();
    memo.put(1, 1);
    memo.put(2, 2);
    return climbStairs(n, memo);
  }

  private int climbStairs(int n, Map<Integer, Integer> memo) {
    if (memo.containsKey(n)) {
      return memo.get(n);
    }
    memo.put(n, climbStairs(n - 1, memo) + climbStairs(n - 2, memo));
    return memo.get(n);
  }

  // DP (Bottom Up Approach)
  public int bestSolution3(int n) {
    if (n <= 1) {
      return 1;
    }

    int[] dp = new int[n + 1];
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
  }

  // DP + Optimization (Bottom Up Approach)
  //   To calculate the new value we only leverage the previous two values.
  //   So we don't need to use an array to store all the previous values.
  public int bestSolution4(int n) {
    if (n <= 1) {
      return 1;
    }

    int prev1 = 1;
    int prev2 = 2;

    for (int i = 3; i <= n; i++) {
      int newValue = prev1 + prev2;
      prev1 = prev2;
      prev2 = newValue;
    }

    return prev2;
  }
}
