/**
 * Reverse & Transpose
 * - Time Complexity: O(N²)
 * - Space Complexity: O(1)
 */
void swapAddress(int** a, int** b) {
    int* temp = *a;
    *a = *b;
    *b = temp;
}

void swapValue(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    // Reverse rows
    for (int row = 0; row < matrixSize / 2; row++) {
        swapAddress(&matrix[row], &matrix[matrixSize - 1 - row]);
    }

    // Transpose diagonally
    for (int row = 0; row < matrixSize; row++) {
        for (int col = row + 1; col < matrixColSize[row]; col++) {
            swapValue(&matrix[row][col], &matrix[col][row]);
        }
    }
}


// Solution
/**
 * Reverse & Transpose
 * - Time Complexity: O(N²)
 * - Space Complexity: O(1)
 */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void solution(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;

    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n; j++) {
            swap(&matrix[i][j], &matrix[n - 1 - i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(&matrix[i][j], &matrix[j][i]);
        }
    }
}
