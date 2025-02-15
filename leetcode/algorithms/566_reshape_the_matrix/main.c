#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 int** matrixReshape(int** mat, int matSize, int* matColSize,
    int r, int c, int* returnSize, int** returnColumnSizes) {
    if (matSize * *matColSize != r * c) {
        *returnSize = matSize;
        *returnColumnSizes = matColSize;
        return mat;
    }

    *returnSize = r;
    *returnColumnSizes = (int*)malloc(sizeof(int) * r);

    int** result = (int**)malloc(sizeof(int*) * r);

    for (int i = 0; i < r; i++) {
        result[i] = (int*)malloc(sizeof(int) * c);
        (*returnColumnSizes)[i] = c;
    }

    int row = 0, col = 0;
    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matColSize[i]; j++) {
            result[row][col] = mat[i][j];
            col++;
            if (col >= c) {
                col = 0;
                row++;
            }
        }
    }

    return result;
}

// Solution
int** solution(int** mat, int matSize, int* matColSize,
    int r, int c, int* returnSize, int** returnColumnSizes) {
    int cols = *matColSize;

    if (matSize * cols != r * c) {
        *returnSize = matSize;
        *returnColumnSizes = matColSize;
        return mat;
    } else {
        *returnSize = r;
        *returnColumnSizes = (int*)malloc(r * sizeof(int));

        int** arr = (int**)malloc(r * sizeof(int*));
        for (int i = 0; i < r; i++) {
            arr[i] = (int*)malloc(c * sizeof(int));
            (*returnColumnSizes)[i] = c;
        }

        int n = 0, m = 0;
        for (int i = 0; i < matSize; i++) {
            for (int j = 0; j < cols; j++) {
                if (m >= c) {
                    m = 0;
                    n++;
                }
                arr[n][m] = mat[i][j];
                m++;
            }
        }

        return arr;
    }
}
