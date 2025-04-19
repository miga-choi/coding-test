#include <vector>
using namespace std;

class PascalsTriangleII {
public:
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
    vector<int> solution(int rowIndex) {
        vector<int> res(1, 1);
        long long prev = 1;
        for (int k = 1; k <= rowIndex; k++) {
            long long next_val = prev * (rowIndex - k + 1) / k;
            res.push_back(next_val);
            prev = next_val;
        }
        return res;
    }
};
