#include <stdlib.h>

/**
 * DP
 * 
 * Complexities:
 *   M - `m`
 *   N - `n`
 *   - Time Complexity: O(M * N)
 *   - Space Complexity: O(M * N)
 */
int uniquePaths(int m, int n) {
    int** dp = (int**)malloc(sizeof(int*) * m);

    for (int i = 0; i < m; i++) {
        dp[i] = (int*)malloc(sizeof(int) * n);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 1;
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
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
    int* dp = (int*)malloc(n * sizeof(int));
    if (dp == NULL) {
        return 0;
    }

    for (int j = 0; j < n; j++) {
        dp[j] = 1;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[j] = dp[j] + dp[j - 1];
        }
    }

    int result = dp[n - 1];
    free(dp);

    return result;
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
    int total_moves = m + n - 2;
    int k = (m - 1 < n - 1) ? m - 1 : n - 1;
    
    long long result = 1;

    for (int i = 1; i <= k; i++) {
        result = result * (total_moves - i + 1) / i;
    }

    return (int)result;
}
