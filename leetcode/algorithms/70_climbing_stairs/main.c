int climbStairs(int n) {
    if (n < 2) {
        return 1;
    }

    int dp[n];
    dp[0] = 1;
    dp[1] = 2;

    for (int i = 2; i < n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n - 1];
}


// Solution
// Solution 1: Fibonacci sequence
int solution1(int n) {
    // base cases
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }

    int one_step_before = 2;
    int two_steps_before = 1;
    int all_ways = 0;

    for (int i = 2; i < n; i++) {
        all_ways = one_step_before + two_steps_before;
        two_steps_before = one_step_before;
        one_step_before = all_ways;
    }

    return all_ways;
}

// Solution 2: Recursion
int solution2(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return solution2(n - 1) + solution2(n - 2);
}

// Solution 3: Tabulation
int solution3(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    int dp[n + 1];
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// Solution 4: Space Optimization
int solution4(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    int prev = 1, curr = 1;

    for (int i = 2; i <= n; i++) {
        int temp = curr;
        curr = prev + curr;
        prev = temp;
    }

    return curr;
}
