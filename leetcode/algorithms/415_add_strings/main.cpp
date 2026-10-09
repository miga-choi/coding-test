#include <algorithm> // std::max, std::reverse
#include <string>    // std::string
using namespace std;

class AddStrings {
public:
    /**
     * Complexities:
     *   N - The Size of `num1`
     *   M - The Size of `num2`
     *   - Time Complexity: O(max(N, M))
     *   - Space Complexity: O(1)
     */
    string addStrings(string num1, string num2) {
        string num = "";

        int num1Size = num1.size();
        int num2Size = num2.size();
        int numSize = num1Size > num2Size ? num1Size : num2Size;

        int up = 0;

        for (int i = 1; i <= numSize; i++) {
            int _num1 = num1Size - i >= 0 ? num1.at(num1Size - i) - '0' : 0;
            int _num2 = num2Size - i >= 0 ? num2.at(num2Size - i) - '0' : 0;

            int _num = _num1 + _num2 + up;

            if (_num > 9) {
                _num -= 10;
                up = 1;
            } else {
                up = 0;
            }

            num = to_string(_num) + num;
        }

        if (up > 0) {
            num = "1" + num;
        }

        return num;
    }


    // Solution
    /**
     * Solution 1
     *
     * Complexities:
     *   N - The Size of `num1`
     *   M - The Size of `num2`
     *   - Time Complexity: O(max(N, M))
     *   - Space Complexity: O(1)
     */
    string solution1(string num1, string num2) {
        int i = static_cast<int>(num1.size()) - 1;
        int j = static_cast<int>(num2.size()) - 1;
        int carry = 0;

        string res;
        res.reserve(max(num1.size(), num2.size()) + 1);

        while (i >= 0 || j >= 0 || carry) {
            int d = carry;
            if (i >= 0) {
                d += num1[i--] - '0';
            }
            if (j >= 0) {
                d += num2[j--] - '0';
            }

            res.push_back(static_cast<char>('0' + d % 10));
            carry = d / 10;
        }

        reverse(res.begin(), res.end());

        return res;
    }

    /**
     * Solution 2
     *
     * Complexities:
     *   N - The Size of `num1`
     *   M - The Size of `num2`
     *   - Time Complexity: O(max(N, M))
     *   - Space Complexity: O(1)
     */
    string solution2(string num1, string num2) {
        int i = static_cast<int>(num1.size()) - 1;
        int j = static_cast<int>(num2.size()) - 1;
        int len = max(i, j) + 2;

        string res(len, '0');
        int k = len - 1, carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int d = carry;
            if (i >= 0) {
                d += num1[i--] - '0';
            }
            if (j >= 0) {
                d += num2[j--] - '0';
            }
            res[k--] = static_cast<char>('0' + d % 10);
            carry = d / 10;
        }

        return res.substr(k + 1);
    }
};
