#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

/**
 * Backtracking
 *
 * Complexities:
 *   N - Size of `candidates`
 *   T - Value of `target`
 *   M - Minimum value of `candidates`
 *   - Time Complexity: O(Nᵀ/ᴹ)
 *   - Space Complexity: O(Nᵀ/ᴹ)
 */
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int* candidates, int candidatesSize, int target, int startIndex,
               int* currentCombo, int currentLen, int currentSum, int*** result,
               int* returnSize, int** returnColumnSizes, int* capacity) {
    if (currentSum == target) {
        if (*returnSize >= *capacity) {
            *capacity *= 2;
            *result = (int**)realloc(*result, sizeof(int*) * (*capacity));
            *returnColumnSizes =
                (int*)realloc(*returnColumnSizes, sizeof(int) * (*capacity));
        }

        (*result)[*returnSize] = (int*)malloc(sizeof(int) * currentLen);
        for (int i = 0; i < currentLen; i++) {
            (*result)[*returnSize][i] = currentCombo[i];
        }
        (*returnColumnSizes)[*returnSize] = currentLen;
        (*returnSize)++;
        return;
    }

    for (int i = startIndex; i < candidatesSize; i++) {
        if (currentSum + candidates[i] > target) {
            break;
        }

        currentCombo[currentLen] = candidates[i];

        backtrack(candidates, candidatesSize, target, i, currentCombo,
                  currentLen + 1, currentSum + candidates[i], result,
                  returnSize, returnColumnSizes, capacity);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target,
                     int* returnSize, int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), compare);

    int capacity = 100;
    int** result = (int**)malloc(sizeof(int*) * capacity);
    *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);
    *returnSize = 0;

    int currentCombo[50];

    backtrack(candidates, candidatesSize, target, 0, currentCombo, 0, 0,
              &result, returnSize, returnColumnSizes, &capacity);

    return result;
}
