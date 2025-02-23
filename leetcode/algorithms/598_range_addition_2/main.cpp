#include <vector>
using namespace std;

class RangeAdditionII {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minRow = m, minCol = n;
        for (vector<int> op : ops) {
            int row = op[0], col = op[1];
            if (row < minRow) {
                minRow = row;
            }
            if (col < minCol) {
                minCol = col;
            }
        }
        return minRow * minCol;
    }

    // Solution
    int solution(int m, int n, vector<vector<int>>& ops) {
        int min_row = m, min_col = n;
        for (int i = 0; i < ops.size(); i++) {
            if (ops[i][0] < min_row) {
                min_row = ops[i][0];
            }
            if (ops[i][1] < min_col) {
                min_col = ops[i][1];
            }
        }
        return min_row * min_col;
    }
};
