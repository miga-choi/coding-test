#include <string>
using namespace std;

class ExcelSheetColumnNumber {
public:
    /**
     * Complexities:
     *   N - Size of `columnTitle`
     *   - Time Complexity: O(N²)
     *   - Space Complexity: O(1)
     */
    int titleToNumber(string columnTitle) {
        int length = columnTitle.size();
        int result = 0;

        for (int i = 0; i < length; i++) {
            result += ((int)columnTitle[length - i - 1] - 64) * pow(26, i);
        }

        return result;
    }


    // Solution
    /**
     * Complexities:
     *   N - Size of `columnTitle`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int solution(string columnTitle) {
        int result = 0;

        for (char c : columnTitle) {
            int d = c - 'A' + 1;
            result = result * 26 + d;
        }

        return result;
    }
};
