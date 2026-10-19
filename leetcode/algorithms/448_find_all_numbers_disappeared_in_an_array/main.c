#include <stdbool.h> // bool
#include <stdlib.h>  // calloc, malloc, free

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * Auxiliary Array
 * 
 * Complexities:
 *   N - `numsSize`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int* numArray = (int*)calloc(numsSize, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        numArray[nums[i] - 1] = 1;
    }

    int* result = (int*)malloc(sizeof(int) * numsSize);
    int count = 0;

    for (int i = 1; i <= numsSize; i++) {
        if (!numArray[i - 1]) {
            result[count++] = i;
        }
    }

    *returnSize = count;
    return result;
}

// Solution
/**
 * Solution 1
 * 
 * Auxiliary Array
 * 
 * Complexities:
 *   N - `numsSize`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
int* solution1(int* nums, int numsSize, int* returnSize) {
    bool* seen = calloc(numsSize + 1, sizeof(bool));

    for (int i = 0; i < numsSize; i++) {
        seen[nums[i]] = true;
    }

    int* res = malloc(numsSize * sizeof(int));
    int k = 0;
    for (int v = 1; v <= numsSize; v++) {
        if (!seen[v]) {
            res[k++] = v;
        }
    }

    free(seen);
    *returnSize = k;
    return res;
}

/**
 * Solution 2
 * 
 * Negative Marking
 * 
 * Complexities:
 *   N - `numsSize`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int* solution2(int* nums, int numsSize, int* returnSize) {
    for (int i = 0; i < numsSize; i++) {
        int idx = abs(nums[i]) - 1;
        if (nums[idx] > 0) {
            nums[idx] = -nums[idx];
        }
    }

    int* res = malloc(numsSize * sizeof(int));
    int k = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            res[k++] = i + 1;
        } else {
            nums[i] = -nums[i];
        }
    }

    *returnSize = k;
    return res;
}

/**
 * Solution 3
 * 
 * Cyclic Sort
 * 
 * Complexities:
 *   N - `numsSize`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int* solution3(int* nums, int numsSize, int* returnSize) {
    for (int i = 0; i < numsSize; i++) {
        while (nums[i] != nums[nums[i] - 1]) {
            int j = nums[i] - 1;
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
    }

    int* res = malloc(numsSize * sizeof(int));
    int k = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != i + 1) {
            res[k++] = i + 1;
        }
    }

    *returnSize = k;
    return res;
}
