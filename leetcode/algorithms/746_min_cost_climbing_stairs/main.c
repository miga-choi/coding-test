int minCostClimbingStairs(int* cost, int costSize) {
    int dp[costSize];
    
    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < costSize; i++) {
        dp[i] = cost[i] + (dp[i - 1] < dp[i - 2] ? dp[i - 1] : dp[i - 2]);
    }

    return dp[costSize - 1] < dp[costSize - 2] ? dp[costSize - 1] : dp[costSize - 2];
}


// Solution
int solution(int* cost, int costSize) {
    int n = costSize;

    int first = cost[0];
    int second = cost[1];

    for (int i = 2; i < n; i++) {
        int curr = cost[i] + (first < second ? first : second);
        first = second;
        second = curr;
    }

    return first < second ? first : second;
}
