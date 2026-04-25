#include <vector>
using namespace std;

class PascalsTriangleII {
public:
    /**
     * DP
     *
     * Complexities:
     *   N - `rowIndex`
     *   - Time Complexity: O(N²)
     *   - Space Complexity: O(N)
     */
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> result;

        for (int i = 0; i <= rowIndex; i++) {
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

        return result[rowIndex];
    }


    // Solution
    /**
     * Solution 1
     *
     * DP
     *
     * Complexities:
     *   N - `rowIndex`
     *   - Time Complexity: O(N²)
     *   - Space Complexity: O(N)
     */
    vector<int> solution1(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);

        for (int i = 2; i <= rowIndex; ++i) {
            for (int j = i - 1; j >= 1; --j) {
                row[j] = row[j] + row[j - 1];
            }
        }

        return row;
    }

    /**
     * Solution 2
     *
     * Binomial Coefficient
     *
     * Complexities:
     *   N - `rowIndex`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    vector<int> solution2(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);
        
        long long prev = 1; 

        for (int k = 1; k < rowIndex; ++k) {
            long long current = prev * (rowIndex - k + 1) / k;
            
            row[k] = static_cast<int>(current);
            prev = current;
        }

        return row;
    }
};
