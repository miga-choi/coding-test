#include <algorithm>
#include <stdlib.h>
#include <string>
using namespace std;

class AddBinary {
public:
    /**
     * Reverse Iteration
     *
     * Complexities:
     *   N - Size of `a`
     *   M - Size of `b`
     *   - Time Complexity: O(max(N, M))
     *   - Space Complexity: O(max(N, M))
     */
    string addBinary(string a, string b) {
        int size_a = a.size();
        int size_b = b.size();
        int size = size_a > size_b ? size_a : size_b;
        char *result = (char*)malloc(sizeof(char) * (size + 2));
        int up = 0;
        result[size + 1] = '\0';

        for (int i = 0; i < size; i++) {
            int num = up;
            up = 0;

            if (i < size_a) {
                num += a[size_a - i - 1] - '0';
            }
            if (i < size_b) {
                num += b[size_b - i - 1] - '0';
            }

            if (num > 1) {
                num -= 2, up = 1;
            }

            result[size - i] = num + '0';
        }

        if (up > 0) {
            result[0] = '1';
            up = -1;
        }

        return result + up + 1;
    }


    // Solution
    /**
     * Reverse
     * 
     * Complexities:
     *   N - Size of `a`
     *   M - Size of `b`
     *   - Time Complexity: O(max(N, M))
     *   - Space Complexity: O(max(N, M))
     */
    string solution(string a, string b) {
        string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            
            if (i >= 0) {
                sum += a[i--] - '0';
            }
            
            if (j >= 0) {
                sum += b[j--] - '0';
            }

            result += to_string(sum % 2); 

            carry = sum / 2;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
