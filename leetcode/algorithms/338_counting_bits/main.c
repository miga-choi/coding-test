#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 /**
  * DP (Dynamic programming)
  * 
  * Complexities:
  *   - Time Complexity: O(N)
  *   - Space Complexity: O(N)
  */
int* countBits(int n, int* returnSize) {
    *returnSize = n + 1;

    int* result = (int*)malloc(sizeof(int) * (*returnSize));
    result[0] = 0;

    for (int i = 1; i < *returnSize; i++) {
        result[i] = (i & 1) ? result[i >> 1] + 1 : result[i >> 1];
    }

    return result;
}


// Solution
/**
 * Solution 1
 * 
 * DP (Dynamic programming)
 * 
 * Complexities:
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
int* solution1(int n, int* returnSize) {
    int* dp = malloc((n + 1) * sizeof(int));
    *returnSize = n + 1;

    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i >> 1] + (i & 1);
    }

    return dp;
}

/**
 * Solution 2
 * 
 * DP (Dynamic programming)
 * 
 * Complexities:
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
int* solution2(int n, int* returnSize) {
    int* dp = malloc((n + 1) * sizeof(int));
    *returnSize = n + 1;

    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i & (i - 1)] + 1;
    }

    return dp;
}
