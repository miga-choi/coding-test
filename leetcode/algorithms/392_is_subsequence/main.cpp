#include <algorithm> // std::find
#include <string>    // std::string
using namespace std;

class IsSubsequence {
public:
    /**
     * Complexities:
     *   N - The Size of `s`
     *   M - The Size of `t`
     *   - Time Complexity: O(M)
     *   - Space Complexity: O(1)
     */
    bool isSubsequence(string s, string t) {
        int i = 0;

        for (int j = 0; j < t.size(); j++) {
            if (t[j] == s[i]) {
                i++;
            }
        }

        return s[i] == '\0';
    }


    // Solution
    /**
     * Solution 1
     *
     * Complexities:
     *   N - The Size of `s`
     *   M - The Size of `t`
     *   - Time Complexity: O(M)
     *   - Space Complexity: O(1)
     */
    bool solution1(string s, string t) {
        size_t i = 0;

        for (char c : t) {
            if (i < s.size() && s[i] == c) {
                ++i;
            }
        }

        return i == s.size();
    }


    int isSubSequence(string &s1, string &s2, int i, int j) {
    }

    /**
     * Solution 2
     *
     * std::find
     * 
     * Complexities:
     *   N - The Size of `s`
     *   M - The Size of `t`
     *   - Time Complexity: O(M)
     *   - Space Complexity: O(1)
     */
    bool solution2(string s, string t) {
        auto it = t.begin();

        for (char c : s) {
            it = std::find(it, t.end(), c);

            if (it == t.end()) {
                return false;
            }

            ++it;
        }

        return true;
    }
};
