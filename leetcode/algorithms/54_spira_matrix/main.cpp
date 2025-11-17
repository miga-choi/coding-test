#include<vector>
using namespace std;

class SpiralMatrix {
public:
    /**
     * Layer Peeling
     *
     * Complexities:
     *   M - matrixSize
     *   N - matrixColSize
     *   - Time Complexity: O(M * N)
     *   - Space Complexity: O(M * N)
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 1) {
            return matrix[0];
        }

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> result;

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        while (top <= bottom && left <= right) {
            // [top][left -> right]
            for (int col = left; col <= right; col++) {
                result.push_back(matrix[top][col]);
            }
            top++;

            // [top -> bottom][right]
            for (int row = top; row <= bottom; row++) {
                result.push_back(matrix[row][right]);
            }
            right--;

            // [bottom][right -> left]
            if (top <= bottom) {
                for (int col = right; col >= left; col--) {
                    result.push_back(matrix[bottom][col]);
                }
                bottom--;
            }

            // [bottom -> top][left]
            if (left <= right) {
                for (int row = bottom; row >= top; row--) {
                    result.push_back(matrix[row][left]);
                }
                left++;
            }
        }

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
    vector<int> solution(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> result;

        // Pre-allocating for improving push_back performance
        result.reserve(m * n);

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        while (top <= bottom && left <= right) {
            // left -> right
            for (int j = left; j <= right; ++j) {
                result.push_back(matrix[top][j]);
            }
            top++;

            // top -> bottom
            for (int i = top; i <= bottom; ++i) {
                result.push_back(matrix[i][right]);
            }
            right--;

            // right -> left
            if (top <= bottom) {
                for (int j = right; j >= left; --j) {
                    result.push_back(matrix[bottom][j]);
                }
                bottom--;
            }

            // bottom -> top
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return result;
    }
};
