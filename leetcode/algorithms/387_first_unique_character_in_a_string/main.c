#include <string.h>

/**
 * Two-Pass
 * 
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int firstUniqChar(char* s) {
    int alphabetNumArray[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        alphabetNumArray[s[i] - 'a']++;
    }

    for (int i = 0; s[i] != '\0'; i++) {
        if (alphabetNumArray[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1;
}


// Solution
/**
 * Solution 1
 * 
 * Two-Pass
 * 
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int solution1(char* s) {
    int cnt[26] = {0};

    for (int i = 0; s[i]; i++) {
        cnt[s[i] - 'a']++;
    }

    for (int i = 0; s[i]; i++) {
        if (cnt[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1;
}

/**
 * Solution 2
 * 
 * Indexing + 1.5-Pass
 * 
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int solution2(char* s) {
    int first[26];
    int cnt[26] = {0};

    for (int i = 0; i < 26; i++) {
        first[i] = -1;
    }

    for (int i = 0; s[i]; i++) {
        int c = s[i] - 'a';

        if (cnt[c] == 0) {
            first[c] = i;
        }

        cnt[c]++;
    }

    int ans = -1;
    for (int c = 0; c < 26; c++) {
        if (cnt[c] == 1 && (ans == -1 || first[c] < ans)) {
            ans = first[c];
        }
    }

    return ans;
}
