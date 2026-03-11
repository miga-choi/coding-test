#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

//  Solution
/**
 * Backtracking
 *
 * Complexities:
 *   N - Size of `nums`
 *   - Time Complexity: O(N * N!)
 *   - Space Complexity: O(N)
 */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

void backtrack(int* nums, int numsSize, int start, int** result, int* count) {
    if (start == numsSize) {
        result[*count] = (int*)malloc(sizeof(int) * numsSize);
        for (int i = 0; i < numsSize; i++) {
            result[*count][i] = nums[i];
        }
        (*count)++;
        return;
    }

    for (int i = start; i < numsSize; i++) {
        swap(&nums[start], &nums[i]);

        backtrack(nums, numsSize, start + 1, result, count);

        swap(&nums[start], &nums[i]);
    }
}

int** solution(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int total_permutations = factorial(numsSize);
    *returnSize = total_permutations;

    int** result = (int**)malloc(sizeof(int*) * total_permutations);

    *returnColumnSizes = (int*)malloc(sizeof(int) * total_permutations);
    for (int i = 0; i < total_permutations; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }

    int count = 0;
    backtrack(nums, numsSize, 0, result, &count);

    return result;
}
