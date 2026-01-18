#include <vector>
using namespace std;

class SetMatrixZeroes {
public:
    /**
     * Marking First Row and Column as Flag
     *
     * Complexities:
     *   M - Size of `matrix`
     *   N - Size of `matrix[0]`
     *   - Time Complexity: O(M * N)
     *   - Space Complexity: O(1)
     */
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int isFirstColZero = false;

        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                isFirstColZero = true;
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

            if (isFirstColZero) {
                matrix[i][0] = 0;
            }
        }
    }


    // Solution
    /**
     * Marking First Row and Column as Flag
     *
     * Complexities:
     *   M - Size of `matrix`
     *   N - Size of `matrix[0]`
     *   - Time Complexity: O(M * N)
     *   - Space Complexity: O(1)
     */
    void solution(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool col0 = false;

        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                col0 = true;
            }

            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 1; --j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }

            if (col0) {
                matrix[i][0] = 0;
            }
        }
    }
};