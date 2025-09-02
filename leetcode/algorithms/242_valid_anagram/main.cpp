#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class ValidAnagram {
public:
    /**
     * Frequency Counter
     * - Time Complexity: O(N)
     * - Space Complexity: O(1)
     */
    bool isAnagram(string s, string t) {
        int len = s.length();

        if (len != t.length()) {
            return false;
        }

        int alphabetNumArray[26] = {0};

        for (int i = 0; i < len; i++) {
            alphabetNumArray[s[i] - 'a']++;
            alphabetNumArray[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (alphabetNumArray[i] > 0) {
                return false;
            }
        }

        return true;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Frequency Counter
     * - Time Complexity: O(N)
     * - Space Complexity: O(1)
     */
    bool solution1(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> counts(26, 0);

        for (int i = 0; i < s.length(); ++i) {
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }

        for (int count : counts) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }

    /**
     * Solution 2
     *
     * Sort
     * - Time Complexity: O(N * logᴺ)
     * - Space Complexity: O(1) or O(logᴺ)
     */
    bool solution2(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};
