class RotateImage {
    /**
     * Transpose & Reverse
     *
     * Complexities:
     *   N - Length of `matrix`
     *   - Time Complexity: O(N²)
     *   - Space Complexity: O(1)
     */
    public void rotate(int[][] matrix) {
        int length = matrix.length;

        // Reverse rows
        for (int row = 0; row < length / 2; row++) {
            int[] temp = matrix[row];
            matrix[row] = matrix[length - 1 - row];
            matrix[length - 1 - row] = temp;
        }

        // Transpose diagonally
        for (int row = 0; row < length; row++) {
            for (int col = row + 1; col < length; col++) {
                int temp = matrix[row][col];
                matrix[row][col] = matrix[col][row];
                matrix[col][row] = temp;
            }
        }
    }


    // Solution
    /**
     * Transpose & Reverse
     *
     * Complexities:
     *   N - Length of `matrix`
     *   - Time Complexity: O(N²)
     *   - Space Complexity: O(1)
     */
    public void solution(int[][] matrix) {
        int n = matrix.length;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n - 1 - j];
                matrix[i][n - 1 - j] = temp;
            }
        }
    }
}
