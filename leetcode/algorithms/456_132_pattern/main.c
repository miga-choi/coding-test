#include <limits.h>  // INT_MIN
#include <stdbool.h> // bool
#include <stdlib.h>  // malloc, free

bool find132pattern(int* nums, int numsSize) {
}


// Solution
/**
 * Solution 1
 *
 * Monotonic Stack
 *
 * Complexities:
 *   N - `numsSize`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
bool solution1(int* nums, int numsSize) {
    int* st = malloc(numsSize * sizeof(int));
    int top = 0;
    int third = INT_MIN;
    bool found = false;

    for (int i = numsSize - 1; i >= 0; i--) {
        if (nums[i] < third) {
            found = true;
            break;
        }

        while (top > 0 && st[top - 1] < nums[i]) {
            third = st[--top];
        }

        st[top++] = nums[i];
    }

    free(st);
    return found;
}

/**
 * Solution 2
 *
 * Monotonic Stack (In-place)
 *
 * Complexities:
 *   N - `numsSize`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
bool solution2(int* nums, int numsSize) {
    int k = numsSize;
    int third = INT_MIN;

    for (int i = numsSize - 1; i >= 0; i--) {
        if (nums[i] < third) {
            return true;
        }

        while (k < numsSize && nums[k] < nums[i]) {
            third = nums[k++];
        }

        nums[--k] = nums[i];
    }

    return false;
}

/**
 * Solution 3
 *
 * Prefix Minimum + Brute Force
 *
 * Complexities:
 *   N - `numsSize`
 *   - Time Complexity: O(N²)
 *   - Space Complexity: O(1)
 */
bool solution3(int* nums, int numsSize) {
    int minLeft = nums[0];

    for (int j = 1; j < numsSize; j++) {
        for (int k = j + 1; k < numsSize; k++) {
            if (minLeft < nums[k] && nums[k] < nums[j]) {
                return true;
            }
        }

        if (nums[j] < minLeft) {
            minLeft = nums[j];
        }
    }

    return false;
}
