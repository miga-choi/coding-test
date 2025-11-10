#include <algorithm>
#include <vector>
using namespace std;

class RotateImage {
public:
    /**
     * Reverse & Transpose
     * - Time Complexity: O(N²)
     * - Space Complexity: O(1)
     */
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();

        // Reverse rows
        reverse(matrix.begin(), matrix.end());

        // Transpose diagonally
        for (int row = 0; row < size; row++) {
            for (int col = row + 1; col < size; col++) {
                int temp = matrix[row][col];
                matrix[row][col] = matrix[col][row];
                matrix[col][row] = temp;
            }
        }
    }


    // Solution
    /**
     * Transpose & Reverse
     * - Time Complexity: O(N²)
     * - Space Complexity: O(1)
     */
    void solution(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (vector<int>& row : matrix) {
            reverse(row.begin(), row.end());
        }
    }
};
