#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * DP
 * 
 * Complexities:
 *   N - `numsSize`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
int rob(int* nums, int numsSize) {
    int* result = (int*)malloc(sizeof(int) * numsSize);

    if (numsSize == 1) {
        return nums[0];
    }

    if (numsSize == 2) {
        return MAX(nums[0], nums[1]);
    }

    result[0] = nums[0];
    result[1] = nums[1];
    result[2] = result[0] + nums[2];

    for (int i = 3; i < numsSize; i++) {
        result[i] = MAX(result[i - 2], result[i - 3]) + nums[i];
    }

    return MAX(result[numsSize - 1], result[numsSize - 2]);
}


// Solution
/**
 * DP
 * 
 * Complexities:
 *   N - `numsSize`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int solution(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    if (numsSize == 1) {
        return nums[0];
    }

    int prev2 = nums[0];
    int prev1 = MAX(nums[0], nums[1]);
    int current = prev1;

    for (int i = 2; i < numsSize; i++) {
        current = MAX(prev1, prev2 + nums[i]);

        prev2 = prev1;
        prev1 = current;
    }

    return current;
}
