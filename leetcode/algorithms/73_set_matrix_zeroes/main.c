#include <stdlib.h>

/**
 * Complexities:
 *   M - matrixSize
 *   N - matrixColSize
 *   - Time Complexity: O(M * N)
 *   - Space Complexity: O(M + N)
 */
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int* zeroRows = (int*)calloc(matrixSize, sizeof(int*));
    int* zeroCols = (int*)calloc(matrixColSize[0], sizeof(int*));

    for (int row = 0; row < matrixSize; row++) {
        for (int col = 0; col < matrixColSize[row]; col++) {
            if (matrix[row][col] == 0) {
                zeroRows[row] = 1;
                zeroCols[col] = 1;
            }
        }
    }

    for (int row = 0; row < matrixSize; row++) {
        for (int col = 0; col < matrixColSize[row]; col++) {
            if (zeroRows[row] == 1 || zeroCols[col] == 1) {
                matrix[row][col] = 0;
            }
        }
    }
}


// Solution
/**
 * Marking First Row and Column as Flag
 * 
 * Complexities:
 *   M - matrixSize
 *   N - matrixColSize
 *   - Time Complexity: O(M * N)
 *   - Space Complexity: O(1)
 */
void solution(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize;
    int n = matrixColSize[0];
    int col0 = 1;

    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {
            col0 = 0;
        }
        
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 1; j--) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
        
        if (col0 == 0) {
            matrix[i][0] = 0;
        }
    }
}
