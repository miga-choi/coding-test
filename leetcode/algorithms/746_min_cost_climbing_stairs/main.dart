import 'dart:math';

class MinCostClimbingStairs {
  int minCostClimbingStairs(List<int> cost) {
    int size = cost.length;

    List<int> dp = List<int>.filled(size, 0);

    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < size; i++) {
      dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }

    return min(dp[size - 1], dp[size - 2]);
  }


  // Solution
  int solution(List<int> cost) {
    int first = cost[0];
    int second = cost[1];

    for (int i = 2; i < cost.length; i++) {
      int curr = cost[i] + min(first, second);
      first = second;
      second = curr;
    }

    return min(first, second);
  }
}
