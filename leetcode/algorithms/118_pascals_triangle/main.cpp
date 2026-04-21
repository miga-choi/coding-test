#include <vector>
using namespace std;

class PascalsTriangle {
public:
    /**
     * DP
     * 
     * Complexities:
     *   N - `numRows`
     *   - Time Complexity: O(N²)
     *   - Space Complexity: O(N²)
     */
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        for (int i = 0; i < numRows; i++) {
            vector<int> row;
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    row.push_back(1);
                } else {
                    row.push_back(result[i - 1][j - 1] + result[i - 1][j]);
                }
            }
            result.push_back(row);
        }

        return result;
    }


    // Solution
    /**
     * DP
     * 
     * Complexities:
     *   N - `numRows`
     *   - Time Complexity: O(N²)
     *   - Space Complexity: O(N²)
     */
    vector<vector<int>> solution(int numRows) {
        vector<vector<int>> result(numRows);

        for (int i = 0; i < numRows; ++i) {
            result[i].resize(i + 1, 1);

            for (int j = 1; j < i; ++j) {
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
            }
        }

        return result;
    }
};
