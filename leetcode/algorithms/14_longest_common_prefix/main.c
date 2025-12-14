#include <string.h>

/**
 * Complexities:
 *   S = N * L
 *   N - `strsSize`
 *   L - Length of Shortest `str` in `strs
 *   - Time Complexity: O(S)
 *   - Space Complexity: O(1)
 */
char* longestCommonPrefix(char** strs, int strsSize) {
    for (int i = 0;; i++) {
        if (strs[0][i] == '\0') {
            return strs[0];
        }
        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] != strs[0][i]) {
                strs[0][i] = '\0';
                return strs[0];
            }
        }
    }
}


// Solution
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
char* solution(char** strs, int strsSize) {
    for (int i = 0; strs[0][i] != '\0'; i++) {
        char c = strs[0][i];

        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] == '\0' || strs[j][i] != c) {
                strs[0][i] = '\0';
                return strs[0];
            }
        }
    }

    return strs[0];
}
