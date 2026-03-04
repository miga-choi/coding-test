#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/**
 * Dynamic Programming
 *
 * Complexities:
 *   N - Size of `s`
 *   - Time Complexity: O(N³)
 *   - Space Complexity: O(N)
 */
bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int s_len = strlen(s);

    bool* dp = (bool*)calloc(s_len + 1, sizeof(bool));

    dp[0] = true;

    for (int i = 1; i <= s_len; i++) {
        for (int j = 0; j < wordDictSize; j++) {
            char *word = wordDict[j];
            int w_len = strlen(word);

            if (i >= w_len && dp[i - w_len]) {
                if (strncmp(s + (i - w_len), word, w_len) == 0) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }

    return dp[s_len];
}


// Solution
/**
 * Dynamic Programming
 *
 * Complexities:
 *   N - Size of `s`
 *   - Time Complexity: O(N³)
 *   - Space Complexity: O(N)
 */
bool solution(char* s, char** wordDict, int wordDictSize) {
    int n = strlen(s);

    bool* dp = (bool*)calloc(n + 1, sizeof(bool));

    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < wordDictSize; j++) {
            int wordLen = strlen(wordDict[j]);

            if (i >= wordLen && dp[i - wordLen] == true) {
                if (strncmp(s + (i - wordLen), wordDict[j], wordLen) == 0) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }

    bool result = dp[n];
    free(dp);

    return result;
}
