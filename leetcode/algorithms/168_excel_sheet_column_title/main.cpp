#include <string>
using namespace std;

class ExcelSheetColumnTitle {
public:
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
    // Solution 1: Iterative
    string solution1(int columnNumber) {
        string result = "";
        while (columnNumber) {
            columnNumber--;
            char c = 'A' + columnNumber % 26;
            result = c + result;
            columnNumber /= 26;
        }
        return result;
    }

    // Solution 2: Recusrive
    string solution2(int columnNumber) {
        if (columnNumber == 0) {
            return "";
        }
        columnNumber--;
        char c = 'A' + columnNumber % 26;
        return convertToTitle(columnNumber / 26) + c;
    }
};
