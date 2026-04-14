#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * Complexities:
 *   M - matrixSize
 *   N - matrixColSize
 *   - Time Complexity: O(M * N)
 *   - Space Complexity: O(M * N)
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * matrixSize * matrixColSize[0]);

    if (matrixSize == 1) {
        *returnSize = matrixColSize[0];
        memcpy(result, matrix[0], sizeof(int) * matrixColSize[0]);
        return result;
    }

    // Initialize (*returnSize)
    *returnSize = 0;

    // Check if visited
    int** visited = (int**)malloc(sizeof(int*) * matrixSize);
    for (int i = 0; i < matrixSize; i++) {
        visited[i] = (int*)calloc(matrixColSize[i], sizeof(int));
    }

    int size = matrixSize * matrixColSize[0];

    // Right: 0, Down: 1, Left: 2, Up: 3
    int direction = 0;

    int row = 0;
    int col = 0;

    while (*returnSize < size) {
        result[(*returnSize)++] = matrix[row][col];
        visited[row][col] = 1;

        switch (direction % 4) {
        case 0:
            // Move right
            if (col < matrixColSize[row] - 1 && !visited[row][col + 1]) {
                col++;
                printf("col = %d\n", col);
            } else {
                direction++;
                row++;
            }
            break;
        case 1:
            // Move down
            if (row < matrixSize - 1 && !visited[row + 1][col]) {
                row++;
            } else {
                direction++;
                col--;
            }
            break;
        case 2:
            // Move left
            if (col > 0 && !visited[row][col - 1]) {
                col--;
            } else {
                direction++;
                row--;
            }
            break;
        default:
            // Move up
            if (row > 0 && !visited[row - 1][col]) {
                row--;
            } else {
                direction++;
                col++;
            }
            break;
        }
    }

    for (int i = 0; i < matrixSize; i++) {
        free(visited[i]);
    }
    free(visited);

    return result;
}


// Solution
/**
 * Layer Peeling
 *
 * Complexities:
 *   M - matrixSize
 *   N - matrixColSize
 *   - Time Complexity: O(M * N)
 *   - Space Complexity: O(M * N)
 */
int* solution(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m = matrixSize;
    int n = *matrixColSize;
    int total_elements = m * n;

    int* result = (int*)malloc(sizeof(int) * total_elements);
    *returnSize = total_elements;
    int idx = 0;

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        // left -> right
        for (int j = left; j <= right; j++) {
            result[idx++] = matrix[top][j];
        }
        top++;

        // top -> bottom
        for (int i = top; i <= bottom; i++) {
            result[idx++] = matrix[i][right];
        }
        right--;

        // right -> left
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                result[idx++] = matrix[bottom][j];
            }
            bottom--;
        }

        // bottom -> top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[idx++] = matrix[i][left];
            }
            left++;
        }
    }

    return result;
}
