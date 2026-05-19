#include <string>
using namespace std;

class ExcelSheetColumnTitle {
public:
    /**
     * Complexities:
     *   N - `columnNumber`
     *   - Time Complexity: O(logᴺ)
     *   - Space Complexity: O(1)
     */
    string convertToTitle(int columnNumber) {
        string result = "";
        
        while (columnNumber > 0) {
            columnNumber -= 1;

            result = (char)(columnNumber % 26 + 65) + result;

            columnNumber /= 26;
        }

        return result;
    }


    // Solution
    /**
     * Complexities:
     *   N - `columnNumber`
     *   - Time Complexity: O(logᴺ)
     *   - Space Complexity: O(1)
     */
    string solution(int columnNumber) {
        string result = "";

        while (columnNumber > 0) {
            columnNumber--; 

            char currentChar = 'A' + (columnNumber % 26);
            result += currentChar;

            columnNumber /= 26;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
