#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

// Solution
/**
 * Backtracking
 *
 * Complexities:
 *   N - Size of `nums`
 *   - Time Complexity: O(N * 2ᴺ)
 *   - Space Complexity: O(N)
 */
void backtrack(int* nums, int numsSize, int start, int* path, int pathLen,
               int** result, int* returnSize, int** returnColumnSizes) {
    result[*returnSize] = (int*)malloc(sizeof(int) * pathLen);
    for (int i = 0; i < pathLen; i++) {
        result[*returnSize][i] = path[i];
    }

    (*returnColumnSizes)[*returnSize] = pathLen;
    (*returnSize)++;

    for (int i = start; i < numsSize; i++) {
        path[pathLen] = nums[i];

        backtrack(nums, numsSize, i + 1, path, pathLen + 1, result, returnSize,
                  returnColumnSizes);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize,
              int** returnColumnSizes) {
    int totalSubsets = 1 << numsSize;

    int** result = (int**)malloc(sizeof(int*) * totalSubsets);
    *returnColumnSizes = (int*)malloc(sizeof(int) * totalSubsets);
    *returnSize = 0;

    int* path = (int*)malloc(sizeof(int) * numsSize);

    backtrack(nums, numsSize, 0, path, 0, result, returnSize,
              returnColumnSizes);

    free(path);

    return result;
}
