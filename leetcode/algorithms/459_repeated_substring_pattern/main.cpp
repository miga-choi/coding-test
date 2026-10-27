#include <string> // std::string
#include <vector> // std::vector
using namespace std;

class RepeatedSubstringPattern {
public:
    bool repeatedSubstringPattern(string s) {}


    // Solution
    /**
     * Solution 1
     *
     * Brute Force
     *
     * Complexities:
     *   N - The Size of `s`
     *   d(N) - The Number of Divisors of N
     *   - Time Complexity: O(N * d(N))
     *   - Space Complexity: O(1)
     */
    bool solution1(string s) {
        int n = static_cast<int>(s.size());

        for (int len = 1; len <= n / 2; ++len) {
            if (n % len != 0) {
                continue;
            }

            int i = len;
            while (i < n && s[i] == s[i - len]) {
                ++i;
            }

            if (i == n) {
                return true;
            }
        }

        return false;
    }

    /**
     * Solution 2
     *
     * String Concatenation
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N) ~ O(N²)
     *   - Space Complexity: O(N)
     */
    bool solution2(string s) {
        string ss = s + s;
        return ss.find(s, 1) < s.size();
    }

    /**
     * Solution 3
     *
     * KMP Prefix Function
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    bool solution3(string s) {
        int n = static_cast<int>(s.size());
        vector<int> lps(n, 0);

        for (int i = 1, len = 0; i < n; ++i) {
            while (len > 0 && s[i] != s[len]) {
                len = lps[len - 1];
            }

            if (s[i] == s[len]) {
                ++len;
            }

            lps[i] = len;
        }

        int l = lps[n - 1];
        return l > 0 && n % (n - l) == 0;
    }
};
