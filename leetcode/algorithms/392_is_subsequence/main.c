#include <stdbool.h>

/**
 * Complexities:
 *   N - The Size of `s`
 *   M - The Size of `t`
 *   - Time Complexity: O(M)
 *   - Space Complexity: O(1)
 */
bool isSubsequence(char* s, char* t) {
    int i = 0;

    for (int j = 0; t[j] != '\0'; j++) {
        if (s[i] == t[j]) {
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
bool solution1(char* s, char* t) {
    int i = 0;

    for (int j = 0; t[j]; j++) {
        if (s[i] == t[j]) {
            i++;
        }
    }

    return s[i] == '\0';
}

/**
 * Solution 2
 * 
 * Complexities:
 *   N - The Size of `s`
 *   M - The Size of `t`
 *   - Time Complexity: O(M)
 *   - Space Complexity: O(1)
 */
bool solution2(char* s, char* t) {
    int i = 0, j = 0;

    while (s[i] && t[j]) {
        if (s[i] == t[j]) {
            i++;
        }

        j++;
    }

    return s[i] == '\0';
}
