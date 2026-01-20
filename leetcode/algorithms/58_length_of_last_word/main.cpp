#include <string>
using namespace std;

class LengthOfLastWord {
public:
    /**
     * Reverse Traversal
     *
     * Complexities:
     *   N - Length of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int lengthOfLastWord(string s) {
        int result = 0;

        for (int i = s.size(); i >= 0; i--) {
            if (s[i] != ' ' && s[i] != '\0') {
                result++;
            } else if (s[i] = ' ' && result > 0) {
                break;
            }
        }

        return result;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Reverse Traversal
     *
     * Complexities:
     *   N - Length of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int solution1(string s) {
        int length = 0;
        int i = s.length() - 1;

        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }

    /**
     * Solution 2
     * 
     * find_last_not_of
     *
     * Complexities:
     *   N - Length of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int solution2(string s) {
        size_t last_char_idx = s.find_last_not_of(' ');

        if (last_char_idx == string::npos) {
            return 0;
        }

        size_t last_space_idx = s.find_last_of(' ', last_char_idx);

        return last_char_idx - last_space_idx;
    }
};
