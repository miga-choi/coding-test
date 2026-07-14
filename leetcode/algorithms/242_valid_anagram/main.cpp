#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class ValidAnagram {
public:
    /**
     * Frequency Counting
     *
     * Complexities:
     *   N - The size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
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
            if (alphabetNumArray[i] != 0) {
                return false;
            }
        }

        return true;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Frequency Counting
     *
     * Complexities:
     *   N - The size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    bool solution1(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> count(26, 0);

        for (int i = 0; i < s.length(); ++i) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int val : count) {
            if (val != 0) {
                return false;
            }
        }

        return true;
    }

    /**
     * Solution 2
     *
     * Unicode
     * 
     * Complexities:
     *   N - The size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    bool solution2(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> count;

        for (int i = 0; i < s.length(); ++i) {
            count[s[i]]++;
            count[t[i]]--;
        }

        for (auto const& [key, val] : count) {
            if (val != 0) {
                return false;
            }
        }

        return true;
    }

    /**
     * Solution 3
     *
     * Sorting
     *
     * Complexities:
     *   N - The size of `s`
     *   - Time Complexity: O(N * logᴺ)
     *   - Space Complexity: O(N)
     */
    bool solution3(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};
