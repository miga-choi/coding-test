#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * DP
 *
 * Complexities:
 *   N - `rowIndex`
 *   - Time Complexity: O(N²)
 *   - Space Complexity: O(N)
 */
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int** result = (int**)malloc(sizeof(int*) * (rowIndex + 1));

    for (int i = 0; i < rowIndex + 1; i++) {
        result[i] = (int*)malloc(sizeof(int) * (i + 1));
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                result[i][j] = 1;
            } else {
                result[i][j] = result[(i - 1)][(j - 1)] + result[(i - 1)][j];
            }
        }
    }
    return result[rowIndex];
}


// Solution
/**
 * Solution 1
 *
 * DP
 *
 * Complexities:
 *   N - `rowIndex`
 *   - Time Complexity: O(N²)
 *   - Space Complexity: O(N)
 */
int* solution1(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    
    int* row = (int*)calloc(*returnSize, sizeof(int));

    row[0] = 1;

    for (int i = 1; i <= rowIndex; i++) {
        for (int j = i; j >= 1; j--) {
            row[j] = row[j] + row[j - 1];
        }
    }

    return row;
}

/**
 * Solution 2
 *
 * Binomial Coefficient
 *
 * Complexities:
 *   N - `rowIndex`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
int* solution2(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* row = (int*)malloc(sizeof(int) * (*returnSize));

    row[0] = 1;
    
    long long prev = 1; 

    for (int k = 1; k <= rowIndex; k++) {
        long long current = prev * (rowIndex - k + 1) / k;
        
        row[k] = (int)current;
        prev = current;
    }

    return row;
}
