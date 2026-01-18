class SetMatrixZeroes {
    /**
     * Marking First Row and Column as Flag
     *
     * Complexities:
     *   M - Length of `matrix`
     *   N - Length of `matrix[0]`
     *   - Time Complexity: O(M * N)
     *   - Space Complexity: O(1)
     */
    public void setZeroes(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;

        boolean isFirstRowZero = false;
        boolean isFirstColZero = false;

        for (int row = 0; row < m; row++) {
            if (matrix[row][0] == 0) {
                isFirstColZero = true;
                break;
            }
        }

        for (int col = 0; col < n; col++) {
            if (matrix[0][col] == 0) {
                isFirstRowZero = true;
                break;
            }
        }

        for (int row = 1; row < m; row++) {
            for (int col = 1; col < n; col++) {
                if (matrix[row][col] == 0) {
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
            }
        }

        for (int row = 1; row < m; row++) {
            for (int col = 1; col < n; col++) {
                if (matrix[row][0] == 0 || matrix[0][col] == 0) {
                    matrix[row][col] = 0;
                }
            }
        }

        if (isFirstColZero) {
            for (int row = 0; row < m; row++) {
                matrix[row][0] = 0;
            }
        }

        if (isFirstRowZero) {
            for (int col = 0; col < n; col++) {
                matrix[0][col] = 0;
            }
        }
    }


    // Solution
    /**
     * Marking First Row and Column as Flag
     *
     * Complexities:
     *   M - Length of `matrix`
     *   N - Length of `matrix[0]`
     *   - Time Complexity: O(M * N)
     *   - Space Complexity: O(1)
     */
    public void solution(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        boolean isCol0 = false;

        for (int i = 0; i < rows; i++) {
            if (matrix[i][0] == 0) {
                isCol0 = true;
            }

            for (int j = 1; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (matrix[0][0] == 0) {
            for (int j = 0; j < cols; j++) {
                matrix[0][j] = 0;
            }
        }

        if (isCol0) {
            for (int i = 0; i < rows; i++) {
                matrix[i][0] = 0;
            }
        }
    }
}
