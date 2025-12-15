#include <string>
#include <vector>
using namespace std;

class LongestCommonPrefix {
public:
    /**
     * Vertical Scanning
     * 
     * Complexities:
     *   S = N * L
     *   N - `strsSize`
     *   L - Length of Shortest `str` in `strs
     *   - Time Complexity: O(S)
     *   - Space Complexity: O(1)
     */
    string longestCommonPrefix(vector<string>& strs) {
        for (int i = 0;; i++) {
            if (strs[0][i] == '\0') {
                return strs[0];
            }

            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
    }


    // Solution
    /**
     * Solution 1
     * 
     * Sorting
     * 
     * Complexities:
     *   S = N * L
     *   N - Size of `strs`
     *   L - Length of Shortest `str` in `strs
     *   - Time Complexity: O(N * Logᴺ + M)
     *   - Space Complexity: O(1)
     */
    string solution1(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        string first = strs.front();
        string last = strs.back();

        string commonPrefix = "";

        for (int i = 0; i < min(first.length(), last.length()); ++i) {
            if (first[i] != last[i]) {
                return commonPrefix;
            }
            commonPrefix += first[i];
        }

        return commonPrefix;
    }

    /**
     * Solution 2
     * 
     * Vertical Scanning
     * 
     * Complexities:
     *   S = N * L
     *   N - Size of `strs`
     *   L - Length of Shortest `str` in `strs
     *   - Time Complexity: O(S)
     *   - Space Complexity: O(1)
     */
    string solution(vector<string>& strs) {
        for (int i = 0; i < strs[0].length(); ++i) {
            char c = strs[0][i];

            for (int j = 1; j < strs.size(); ++j) {
                if (i >= strs[j].length() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0];
    }
};
