class SolutionReshapeTheMatrix {
    public int[][] matrixReshape(int[][] mat, int r, int c) {
        if (mat.length * mat[0].length != r * c) {
            return mat;
        }

        int[] numArray = new int[mat.length * mat[0].length];
        int count = 0;
        for (int[] row : mat) {
            for (int col : row) {
                numArray[count] = col;
                count++;
            }
        }

        int[][] result = new int[r][c];
        count = 0;
        for (int rowNum = 0; rowNum < r; rowNum++) {
            for (int colNum = 0; colNum < c; colNum++) {
                result[rowNum][colNum] = numArray[count];
                count++;
            }
        }

        return result;
    }


    // Best Solution
    public int[][] bestSolution1(int[][] mat, int r, int c) {
        int n = mat.length, m = mat[0].length;
        if (r * c != n * m) {
            return mat;
        }
        int[][] res = new int[r][c];
        for (int i = 0; i < r * c; i++) {
            res[i / c][i % c] = mat[i / m][i % m];
        }
        return res;
    }

    public int[][] bestSolution2(int[][] mat, int r, int c) {
        // Storing the values of mat matrix
        // i.e m = rows & n = cols
        int rows = mat.length;
        int cols = mat[0].length;

        // if the product of rows & cols of mat matrix and the new matrix are not same
        // then return original matrix
        if ((rows * cols) != (r * c)) {
            return mat;
        }

        // Creating the new matrix
        int[][] output = new int[r][c];
        int output_rows = 0;
        int output_cols = 0;

        // Traversing the mat matrix and storing the its values in new matrix output
        // cols wise
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                output[output_rows][output_cols] = mat[i][j];
                output_cols++;

                // if the cols value reached then change the row and set the cols value to 0.
                if (output_cols == c) {
                    output_cols = 0;
                    output_rows++;
                }
            }
        }

        return output;
    }
}