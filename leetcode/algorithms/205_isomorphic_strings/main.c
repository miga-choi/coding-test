#include <stdbool.h>

/**
 * Complexities:
 *   N - Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
bool isIsomorphic(char* s, char* t) {
    char sCharArray[256] = {0};
    char tCharArray[256] = {0};

    for (int i = 0; s[i] != '\0' && t[i] != '\0'; i++) {
        if (sCharArray[s[i]] == 0 && tCharArray[t[i]] == 0) {
            sCharArray[s[i]] = t[i];
            tCharArray[t[i]] = s[i];
        } else if (sCharArray[s[i]] != t[i] || tCharArray[t[i]] != s[i]) {
            return false;
        }
    }

    return true;
}


// Solution
/**
 * Complexities:
 *   N - Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
bool solution(char* s, char* t) {
    int posS[256] = {0};
    int posT[256] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char charS = (unsigned char)s[i];
        unsigned char charT = (unsigned char)t[i];

        if (posS[charS] != posT[charT]) {
            return false;
        }

        posS[charS] = i + 1;
        posT[charT] = i + 1;
    }

    return true;
}
