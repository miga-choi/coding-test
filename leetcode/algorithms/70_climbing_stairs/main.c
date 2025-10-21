/**
 * DP (Dynamic Programming)
 * - Time Complexity: O(N)
 * - Space Complexity: O(N)
 */
int climbStairs(int n) {
    /**
     * dp[0] -> 0 stair -> 0 step -> 0 way
     * dp[1] -> 1 stair -> 1 step -> 1 way
     * dp[2] -> 2 stairs -> (1+1), 2 -> 2 ways
     * dp[3] -> 3 stairs -> (2+1), (1+2), (1+1+1) -> 3 ways
     * dp[4] -> 4 stairs -> (2+2), (2+1+1), (1+2+1), (1+1+2), (1+1+1+1) -> 5 ways
     * dp[5] -> 5 stairs -> (1+2+2), (2+1+2), (2+2+1),
     *                      (2+1+1+1), (1+2+1+1), (1+1+2+1), (1+1+1+2),
     *                      (1+1+1+1+1) -> 8 ways
     */
    if (n < 3) {
        return n;
    }

    int dp[n + 1];

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
int solution1(int n) {
    if (n <= 2) {
        return n;
    }
    return solution1(n - 1) + solution1(n - 2);
}

/**
 * Solution 2
 *
 * DP (Dynamic Programming)
 * - Time Complexity: O(N)
 * - Space Complexity: O(N)
 */
int solution2(int n) {
    if (n <= 2) {
        return n;
    }

    int dp[n + 1];

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

/**
 * Solution 3
 *
 * DP (Dynamic Programming)
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 */
int solution3(int n) {
    if (n <= 2) {
        return n;
    }

    int one_step_before = 2;
    int two_steps_before = 1;
    int current_ways = 0;

    for (int i = 3; i <= n; i++) {
        current_ways = one_step_before + two_steps_before;

        two_steps_before = one_step_before;
        one_step_before = current_ways;
    }

    return one_step_before;
}
