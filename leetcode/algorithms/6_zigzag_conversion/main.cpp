#include <string>
#include <vector>
using namespace std;

class ZigzagConversion {
public:
    /**
     * - Time Complexity: O(N)
     * - Space Complexity: O(N)
     */
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        string result = "";

        int cycleLen = numRows * 2 - 2;
        for (int numRow = 0; numRow < numRows; numRow++) {
            for (int cycle = numRow; cycle < s.size(); cycle += cycleLen) {
                result += s[cycle];

                if (numRow > 0 && numRow < numRows - 1) {
                    int diag_idx = cycle + cycleLen - numRow * 2;
                    if (diag_idx < s.size()) {
                        result += s[diag_idx];
                    }
                }
            }
        }

        return result;
    }


    // Solution
    /**
     * Solution 1
     * 
     * - Time Complexity: O(N)
     * - Space Complexity: O(N)
     */
    string solution1(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        vector<string> rows(numRows);
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currentRow] += c;

            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }

            currentRow += goingDown ? 1 : -1;
        }

        string result;
        for (const string& row_str : rows) {
            result += row_str;
        }

        return result;
    }

    /**
     * Solution 2
     * 
     * - Time Complexity: O(N)
     * - Space Complexity: O(N)
     */
    string solution2(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        string result;
        int n = s.length();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                result += s[j + i];

                if (i != 0 && i != numRows - 1) {
                    int diag_idx = j + cycleLen - i;
                    if (diag_idx < n) {
                        result += s[diag_idx];
                    }
                }
            }
        }

        return result;
    }
};
