#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/**
 * DP
 * 
 * Complexities:
 *   N - `numRows`
 *   - Time Complexity: O(N²)
 *   - Space Complexity: O(N²)
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows;

    int** result = (int**)(malloc(numRows * sizeof(int*)));
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

    for (int i = 0; i < numRows; i++) {
        (*returnColumnSizes)[i] = i + 1;
        result[i] = (int*)malloc(numRows * sizeof(int));

        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                result[i][j] = 1;
            } else {
                result[i][j] = result[(i - 1)][(j - 1)] + result[(i - 1)][j];
            }
        }
    }

    return result;
}


// Solution
/**
 * DP
 * 
 * Complexities:
 *   N - `numRows`
 *   - Time Complexity: O(N²)
 *   - Space Complexity: O(N²)
 */
int** solution(int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows;
    
    int** result = (int**)malloc(sizeof(int*) * numRows);
    
    *returnColumnSizes = (int*)malloc(sizeof(int) * numRows);
    
    for (int i = 0; i < numRows; i++) {
        int colSize = i + 1;
        (*returnColumnSizes)[i] = colSize;
        
        result[i] = (int*)malloc(sizeof(int) * colSize);
        
        result[i][0] = 1;
        result[i][colSize - 1] = 1;
        
        for (int j = 1; j < i; j++) {
            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
    }
    
    return result;
}
