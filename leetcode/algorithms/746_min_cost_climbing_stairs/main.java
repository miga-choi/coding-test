class MinCostClimbingStairs {
    public int minCostClimbingStairs(int[] cost) {
        int size = cost.length;

        int[] dp = new int[size];

        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < size; i++) {
            dp[i] = cost[i] + Math.min(dp[i - 1], dp[i - 2]);
        }

        return Math.min(dp[size - 1], dp[size - 2]);
    }


    // Solution
    public int solution(int[] cost) {
        int first = cost[0];
        int second = cost[1];

        for (int i = 2; i < cost.length; i++) {
            int curr = cost[i] + Math.min(first, second);
            first = second;
            second = curr;
        }

        return Math.min(first, second);
    }
}
