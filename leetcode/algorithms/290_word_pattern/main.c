#include <stdbool.h>
#include <string.h>

/**
 * Complexities:
 *   N - The size of `pattern`
 *   M - The size of `s`
 *   L - The max size of word
 *   - Time Complexity: O(M + N * L)
 *   - Space Complexity: O(M)
 */
bool wordPattern(char* pattern, char* s) {
    int patternLen = strlen(pattern);

    char* sCopy = strdup(s);

    char* charToWord[26] = {NULL};

    int i = 0;
    char* token = strtok(sCopy, " ");

    while (token != NULL) {
        if (i >= patternLen) {
            return false;
        }

        int pIdx = pattern[i] - 'a';

        if (charToWord[pIdx] != NULL) {
            if (strcmp(charToWord[pIdx], token) != 0) {
                return false;
            }
        } else {
            for (int k = 0; k < 26; k++) {
                if (charToWord[k] != NULL && strcmp(charToWord[k], token) == 0) {
                    return false;
                }
            }
            charToWord[pIdx] = token;
        }

        i++;
        token = strtok(NULL, " ");
    }

    return i == patternLen;
}


// Solution
/**
 * Complexities:
 *   N - The size of `pattern`
 *   M - The size of `s`
 *   L - The max size of word
 *   - Time Complexity: O(M + N * L)
 *   - Space Complexity: O(M)
 */
bool solution(char* pattern, char* s) {
    int patternLen = strlen(pattern);

    char* sCopy = strdup(s);
    if (sCopy == NULL) {
        return false;
    }

    char* charToWord[26] = {NULL};

    int i = 0;
    char* token = strtok(sCopy, " ");

    while (token != NULL) {
        if (i >= patternLen) {
            free(sCopy);
            return false;
        }

        int pIdx = pattern[i] - 'a';

        if (charToWord[pIdx] != NULL) {
            if (strcmp(charToWord[pIdx], token) != 0) {
                free(sCopy);
                return false;
            }
        } else {
            for (int k = 0; k < 26; k++) {
                if (charToWord[k] != NULL && strcmp(charToWord[k], token) == 0) {
                    free(sCopy);
                    return false;
                }
            }
            charToWord[pIdx] = token;
        }

        i++;
        token = strtok(NULL, " ");
    }

    free(sCopy);

    return i == patternLen;
}
