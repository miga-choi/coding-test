#include <string>
using namespace std;

class IsSubsequence {
public:
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
    // Solution 1: Two pointer
    bool solution1(string s, string t) {
        int n = s.length(), m = t.length();

        // For index of s (or subsequence)
        int j = 0;

        // Traverse s and t,
        // and compare current
        // character of s with
        // first unmatched char of t,
        // if matched then move ahead in s
        for (int i = 0; i < m and j < n; i++) {
            if (s[j] == t[i]) {
                j++;
            }
        }

        // If all characters of s were found in t
        return (j == n);
    }

    // Solution 2: Recursion
    int isSubSequence(string &s1, string &s2, int i, int j) {
        if (i == 0 || j == 0) {
            return 0;
        }

        if (s1[i - 1] == s2[j - 1]) {
            return 1 + isSubSequence(s1, s2, i - 1, j - 1);
        } else {
            return isSubSequence(s1, s2, i, j - 1);
        }
    }

    bool solution2(string s, string t) {
        int m = s.size();
        int n = t.size();

        if (m > n) {
            return false;
        }

        if (isSubSequence(s, t, m, n) == m) {
            return true;
        } else {
            return false;
        }
    }
};
