#include <vector>
using namespace std;

class ReshapeTheMatrix {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (mat.size() * mat.at(0).size() != r * c) {
            return mat;
        }

        vector<vector<int>> result(r, vector<int>(c));

        int row = 0, col = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat.at(i).size(); j++) {
                result.at(row).at(col) = mat.at(i).at(j);
                col++;
                if (col >= c) {
                    col = 0;
                    row++;
                }
            }
        }

        return result;
    }

    // Solution 1: Row-First Approach
    vector<vector<int>> solution1(vector<vector<int>>& mat, int r, int c) {
        int m = size(mat), n = size(mat[0]), total = m * n;

        if (r * c != total) {
            return mat;
        }

        vector<vector<int>> ans(r, vector<int>(c));

        for (int i = 0; i < total; i++) {
            ans[i / c][i % c] = mat[i / n][i % n];
        }

        return ans;
    }

    // Solution 2: Column-First Appraoch
    vector<vector<int>> solution2(vector<vector<int>>& mat, int r, int c) {
        int m = size(mat), n = size(mat[0]), total = m * n;

        if (r * c != total) {
            return mat;
        }

        vector<vector<int>> ans(r, vector<int>(c));

        for (int col = 0; col < n; col++) {
            for (int row = 0; row < m; row++) {
                int new_row = (n * row + col) / c;
                int new_col = (n * row + col) % c;
                ans[new_row][new_col] = mat[row][col];
            }
        }

        return ans;
    }
};
