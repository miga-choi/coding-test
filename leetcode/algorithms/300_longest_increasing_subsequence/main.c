#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Solution
/**
 * Solution 1
 * 
 * DP
 * 
 * Complexities:
 *   N - Size of `nums`
 *   - Time Complexity: O(N²)
 *   - Space Complexity: O(N)
 */
int solution1(int* nums, int numsSize) {
    int* dp = (int*)malloc(sizeof(int) * numsSize);
    int max_len = 1;

    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;

        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = MAX(dp[i], dp[j] + 1);
            }
        }

        max_len = MAX(max_len, dp[i]);
    }

    free(dp);

    return max_len;
}

/**
 * Solution 2
 * 
 * Binary Search
 * 
 * Complexities:
 *   N - Size of `nums`
 *   - Time Complexity: O(N * logᴺ)
 *   - Space Complexity: O(N)
 */
int solution2(int* nums, int numsSize) {
    int* tails = (int*)malloc(sizeof(int) * numsSize);
    int len = 0;

    for (int i = 0; i < numsSize; i++) {
        int left = 0;
        int right = len;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (tails[mid] < nums[i]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        tails[left] = nums[i];

        if (left == len) {
            len++;
        }
    }

    free(tails);

    return len;
}
