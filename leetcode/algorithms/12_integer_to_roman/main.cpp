#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    string intToRoman(int num) {
        string result = "";
        unordered_map<int, char> charMap;
        charMap[1] = 'I';
        charMap[5] = 'V';
        charMap[10] = 'X';
        charMap[50] = 'L';
        charMap[100] = 'C';
        charMap[500] = 'D';
        charMap[1000] = 'M';

        while (num > 0) {
            if (num / 1000 > 0) {
                for (int i = 0; i < num / 1000; i++) {
                    result += charMap[1000];
                }
                num %= 1000;
            } else if (num / 100 > 0) {
                if (num >= 900) {
                    result += charMap[100];
                    result += charMap[1000];
                } else if (num >= 500) {
                    result += charMap[500];
                    for (int i = 0; i < (num - 500) / 100; i++) {
                        result += charMap[100];
                    }
                } else if (num >= 400) {
                    result += charMap[100];
                    result += charMap[500];
                } else {
                    for (int i = 0; i < num / 100; i++) {
                        result += charMap[100];
                    }
                }
                num %= 100;
            } else if (num / 10 > 0) {
                if (num >= 90) {
                    result += charMap[10];
                    result += charMap[100];
                } else if (num >= 50) {
                    result += charMap[50];
                    for (int i = 0; i < (num - 50) / 10; i++) {
                        result += charMap[10];
                    }
                } else if (num >= 40) {
                    result += charMap[10];
                    result += charMap[50];
                } else {
                    for (int i = 0; i < num / 10; i++) {
                        result += charMap[10];
                    }
                }
                num %= 10;
            } else if (num / 1 > 0) {
                if (num >= 9) {
                    result += charMap[1];
                    result += charMap[10];
                } else if (num >= 5) {
                    result += charMap[5];
                    for (int i = 0; i < num - 5; i++) {
                        result += charMap[1];
                    }
                } else if (num >= 4) {
                    result += charMap[1];
                    result += charMap[5];
                } else {
                    for (int i = 0; i < num; i++) {
                        result += charMap[1];
                    }
                }
                num = 0;
            }
        }

        return result;
    }

    // Solution
    /**
     * Solution 1
     *
     * Greedy
     *
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    string solution1(int num) {
        const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string result = "";

        for (int i = 0; i < 13; ++i) {
            while (num >= values[i]) {
                num -= values[i];
                result += symbols[i];
            }
        }

        return result;
    }

    /**
     * Solution 2
     * 
     * Hard Coding
     * ∵ 1 <= num <= 3999
     * 
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    string solution2(int num) {
        const string M[] = {"", "M", "MM", "MMM"};
        const string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        const string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        const string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

        return M[num / 1000] + C[(num % 1000) / 100] + X[(num % 100) / 10] + I[num % 10];
    }
};
